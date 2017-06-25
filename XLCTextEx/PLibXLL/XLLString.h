//	XLCTextEx_1.0x	:	PLibXLL

//	XLLString.h
//
#pragma once
#include <exception>
#include <stdexcept>
#include <new>

typedef	std::basic_string<T_CHAR_XLL>	XLLSTRING, *PXLLSTRING;

#define	XLL_STRING_INITIAL_SIZE		32
#define	XLL_STRING_BUFFER_SIZE_INIT	32
#define	XLL_STRING_BUFFER_SIZE_MAX	INT_MAX

NS_XLL_BEGIN
/*
//======================================================================
//	GetStringSize
//======================================================================
template<typename T_CHAR>
inline size_t GetStringSize(const T_CHAR* pXStr)
{
	THROWPE_LOGIC_ERROR("XLL::GetStringSize");
	return 0;
}
template<>
inline size_t GetStringSize<char>(LPCSTR pXStr)
{
	return (size_t)(unsigned char)*pXStr;
}
template<>
inline size_t GetStringSize<wchar_t>(LPCWSTR pXStr)
{
	return (size_t)*pXStr;
}
*/

//======================================================================
//	XLL::IString
//======================================================================
template<typename T_CHAR>
class IString
{
protected:
	typedef	T_CHAR			*T_PSTR;
	typedef	const T_CHAR	*T_PCSTR;

public:
	virtual T_PCSTR	CStr()	= 0;
	virtual T_PSTR	XStr()	= 0;
	virtual size_t	Size()	= 0;
	virtual BOOL	Empty(BOOL* pbNull)	= 0;
};


//======================================================================
//	XLL::BString
//
//	XLL 用の文字列を表すクラスの基となるクラス。先頭に文字数を格納する。
//	C 形式の文字列としても使えるように、終端に NULL を追加する。
//	MAX_STRING_SIZE に終端の NULL は含めない。
//======================================================================
template<typename T_CHAR, size_t MAX_STRING_SIZE, class C_MALLOC = PLib::PCMAlloc>
class BString
	:	public IString<T_CHAR>
{
protected:
	//------------------------------------------------------------
	//	XLL::BString	データメンバ
	//------------------------------------------------------------
	T_PSTR		pBuffer;
	size_t		zStrBufferSize;		//	バッファのうち文字用のサイズ。実際のバッファサイズ - 2。
	size_t		zIncriment;			//	バッファの増分

	C_MALLOC	ciMAlloc;

	//------------------------------------------------------------
	//	XLL::BString::IsLeadChar
	//------------------------------------------------------------
	template<typename T>
	inline BOOL IsLeadChar(T c)
	{
		throw std::logic_error("BString::IsLeadChar");
		return FALSE;
	}
	template<>
	inline BOOL IsLeadChar<char>(char c)
	{
		return IsDBCSLeadByte((BYTE)c);
	}
	template<>
	inline BOOL IsLeadChar<wchar_t>(wchar_t c)
	{
		return IS_HIGH_SURROGATE(c);
	}

	//------------------------------------------------------------
	//	XLL::BString::DropWrongLastChar
	//	XLL 文字列の最後の文字がマルチコード文字の 1 文字目なら、
	//	消去して文字数から 1 を引く。
	//------------------------------------------------------------
	void DropWrongLastChar(T_PSTR pXStr)
	{
		T_PSTR	pe;

		if (pXStr == NULL || *pXStr == 0)	return;
		pe	= pXStr + XLL::GetStringSize<T_CHAR>(pXStr);
		if (PLib::IsLastCharWrong<T_CHAR>(pXStr + 1, pe + 1))
		{
			*pe	= NULL;
			(size_t)(*pXStr)--;
		}
	}

	//------------------------------------------------------------
	//	XLL::BString::FreeSpace
	//	未使用領域のアドレスとサイズを取得する。
	//	バッファの拡張等は行わない。
	//------------------------------------------------------------
	void FreeSpace(T_PSTR* ppFree, size_t* pzFree)
	{
		size_t	zUsed;

		if (ppFree == NULL || pzFree == NULL)
		{
			THROWPE_LOGIC_ERROR("XLL::BString::FreeSpace");
		}
		if (pBuffer == NULL)
		{
			*ppFree	= NULL;
			*pzFree	= 0;
		}
		zUsed	= GetStringSize<T_CHAR>(pBuffer);
		if (zStrBufferSize <= zUsed)
		{
			*ppFree	= NULL;
			*pzFree	= 0;
		}
		*ppFree	= pBuffer + zUsed + 1;
		*pzFree	= zStrBufferSize - zUsed;
		return;
	}

public:
	//------------------------------------------------------------
	//	XLL::BString::CStr
	//------------------------------------------------------------
	T_PCSTR CStr()
	{
		if (pBuffer != NULL)	return (T_PCSTR)(pBuffer + 1);
		return NULL;
	}

	//------------------------------------------------------------
	//	XLL::BString::GetBuffer
	//------------------------------------------------------------
	T_PSTR GetBuffer()
	{
		if (pBuffer != NULL)	return (pBuffer + 1);
		return NULL;
	}

	//------------------------------------------------------------
	//	XLL::BString::XStr
	//------------------------------------------------------------
	T_PSTR XStr()
	{
		if (pBuffer != NULL)	return (T_PSTR)pBuffer;
		return NULL;
	}

	//------------------------------------------------------------
	//	XLL::BString::SetSize
	//------------------------------------------------------------
	void SetSize(size_t zSize)
	{
		if (pBuffer != NULL)	*pBuffer = (T_CHAR)zSize;
	}

	//------------------------------------------------------------
	//	XLL::BString::Size
	//------------------------------------------------------------
	size_t Size()
	{
		if (pBuffer != NULL)	return GetStringSize<T_CHAR>(pBuffer);
		return 0;
	}

	//------------------------------------------------------------
	//	XLL::BString::Empty
	//------------------------------------------------------------
	BOOL Empty(BOOL* pbNull = NULL)
	{
		if (pBuffer == NULL)
		{
			if (pbNull != NULL)	*pbNull = TRUE;
			return TRUE;
		}
		if (pbNull != NULL)	*pbNull = FALSE;
		return (*pBuffer == (T_CHAR)0);
	}

	//------------------------------------------------------------
	//	XLL::BString::Clear
	//	バッファの解放は行わない。
	//------------------------------------------------------------
	void Clear()
	{
		if (pBuffer != NULL)
		{
			*pBuffer		= (T_CHAR)0;
			*(pBuffer + 1)	= (T_CHAR)0;
		}
	}

	//------------------------------------------------------------
	//	XLL::BString::Free
	//	バッファを解放する。
	//------------------------------------------------------------
	void Free()
	{
		ciMAlloc.Deallocate<T_CHAR>(pBuffer);
		pBuffer		= NULL;
		zStrBufferSize	= 0;
	}

	//------------------------------------------------------------
	//	RemoveXStr
	//
	//	バッファを呼び出し側に移動させる。メモリは呼び出し側で解放すること。
	//------------------------------------------------------------
	BOOL RemoveXStr(T_PSTR* ppBuf, size_t* pzBuf)
	{
		if (pBuffer == NULL)	return FALSE;

		*ppBuf	= pBuffer;
		*pzBuf	= zStrBufferSize;

		pBuffer			= NULL;
		zStrBufferSize	= 0;
		return TRUE;
	}

	//------------------------------------------------------------
	//	XLL::BString::ExtendBuffer
	//
	//	zReq には文字用に必要なバッファのサイズを指定する。
	//	実際には zReq + 2 文字分が割り当てられる。
	//------------------------------------------------------------
	void ExtendBuffer(size_t zReq, BOOL bCopy)
	{
		T_PSTR	pTemp		= NULL;
		T_PSTR	ps, pd, pEnd;
		size_t	zNewSize	= 0;
		size_t	zCopy;

		if (zReq > MAX_STRING_SIZE)	zReq = MAX_STRING_SIZE;
		if (zStrBufferSize >= zReq)	return;	//	すでに必要量が確保されている場合は終了する。
		zNewSize	= (zStrBufferSize > 0 ? zStrBufferSize : zIncriment);

		//	新しいバッファのサイズを決めてメモリを割り当てる。
		while (zNewSize < zReq)	zNewSize += zIncriment;
		if (zNewSize > MAX_STRING_SIZE)	zNewSize = MAX_STRING_SIZE;
		pTemp	= ciMAlloc.Allocate<T_CHAR>(zNewSize + 2);

		//	元の文字列を新しいバッファにコピーする。
		if (bCopy == TRUE)
		{
			zCopy	= GetStringSize<T_CHAR>(pBuffer);
			pEnd	= pBuffer + zCopy + 1;
			for (ps = pBuffer, pd = pTemp; ps < pEnd; ++ps, ++pd)
			{
				*pd	= *ps;
			}
			*pEnd	= (T_CHAR)0;
		}

		//	元のバッファを削除し、新しいものを設定する。
		ciMAlloc.Deallocate(pBuffer);
		pBuffer			= pTemp;
		zStrBufferSize	= zNewSize;
	}

	//------------------------------------------------------------
	//	XLL::BString::CopyToPStr
	//	指定された文字列を pBuf 以降の領域にコピーし、終端に NULL を付ける。
	//	zChar にはバッファに格納できる文字数（終端の NULL を除く）を指定する。
	//	したがって、pBuf は zChar + 1 文字以上のサイズでなければならない。
	//	終端が適切かどうかの確認と訂正は呼び出し側で処理すること。
	//	エラーが発生した場合は例外をスローする。
	//	元の文字列をすべてコピーで着なかった場合に FALSE を返す。
	//	*ppBuf には、未使用領域の先頭の位置が格納される。
	//------------------------------------------------------------
	//------------------------------------------------------------
	//	XLL::BString::CopyToPStr	(1)
	//	文字列 pSrcB から pSrcE の前の文字までコピーする。
	//	すべてコピーできたら TRUE を返す。
	//	*ppSrc には、コピーできなかった文字の先頭の位置が格納される。
	//------------------------------------------------------------
	BOOL CopyToPStr(T_PSTR* ppBuf, size_t zChar, T_PCSTR* ppSrc, T_PCSTR pSrcE)
	{
		T_PCSTR	ps;
		T_PSTR	pd, pde;

		if (ppBuf == NULL || zChar < 1 || ppSrc == NULL || *ppSrc >= pSrcE)
		{
			THROWPE_LOGIC_ERROR("XLL::BString::CopyToPStr (1)");
		}

		pde	= *ppBuf + zChar;
		for (ps = *ppSrc, pd = *ppBuf; ps < pSrcE && pd < pde; ++ps, ++pd)
		{
			*pd	= *ps;
		}
		*pd		= NULL;
		*ppBuf	= pd;
		*ppSrc	= ps;
		return (ps >= pSrcE);
	}

	//------------------------------------------------------------
	//	XLL::BString::CopyToPStr	(2)
	//	NULL 終了文字列 pszSrc をコピーする。
	//	すべてコピーできたら TRUE を返す。
	//	*ppszSrc には、コピーできなかった文字の先頭の位置が格納される。
	//------------------------------------------------------------
	BOOL CopyToPStr(T_PSTR* ppBuf, size_t zChar, T_PCSTR* ppszSrc)
	{
		T_PCSTR	ps;
		T_PSTR	pd, pde;

		if (ppBuf == NULL || zBuf < 1 || ppszSrc == NULL)
		{
			THROWPE_LOGIC_ERROR("XLL::BString::CopyToPStr (2)");
		}

		pde	= *ppBuf + zChar;
		for (ps = *ppszSrc, pd = *ppBuf; *ps != NULL && pd < pde; ++ps, ++pd)
		{
			*pd	= *ps;
		}
		*pd			= NULL;
		*ppBuf		= pd;
		*ppszSrc	= ps;
		return (*ps == NULL);
	}

	//------------------------------------------------------------
	//	XLL::BString::CopyToXStr
	//	指定された文字列を pBuf + 1 以降の領域にコピーする。
	//	先頭の *pBuf にはコピーした文字数が格納される。
	//	zChar にはバッファに格納できる文字数（終端の NULL を除く）を指定する。
	//	したがって、pBuf は文字数を収める先頭、終端の NULL 文字を含めて
	//	zChar + 2 文字以上格納できるようにしておかなければならない。
	//	エラーが発生した場合は例外をスローする。
	//	元の文字列をすべてコピーできなかった場合に FALSE を返す。
	//	*ppBuf には、未使用領域の先頭の位置が格納される。
	//------------------------------------------------------------
#define	XLL_BSTRING_COPYTOXSTR_END_PROCESSING	\
	*pb	= (T_CHAR)(pd - pb - 1);	\
	DropWrongLastChar(pb);	\
	*ppBuf	= pd;

	//------------------------------------------------------------
	//	XLL::BString::CopyToXStr	(1)
	//	文字列 pSrcB から pSrcE の前の文字までコピーする。
	//	すべてコピーできたら TRUE を返す。
	//	*ppSrc には、コピーできなかった文字の先頭の位置が格納される。
	//------------------------------------------------------------
	BOOL CopyToXStr(T_PSTR* ppBuf, size_t zChar, T_PCSTR* ppSrc, T_PCSTR pSrcE)
	{
		T_PSTR	pb, pd;
		BOOL	br;

		if (ppBuf == NULL || zChar < 2 || ppSrc == NULL || *ppSrc >= pSrcE)
		{
			THROWPE_LOGIC_ERROR("XLL::BString::Copy (1)");
		}

		pb	= *ppBuf;
		pd	= pb + 1;
		br	= CopyToPStr(&pd, zChar, ppSrc, pSrcE);
		XLL_BSTRING_COPYTOXSTR_END_PROCESSING;
		return br;
	}

	//------------------------------------------------------------
	//	XLL::BString::CopyToXStr	(2)
	//	NULL 終了文字列 pszSrc をコピーする。
	//	すべてコピーできたら TRUE を返す。
	//	*ppszSrc には、コピーできなかった文字の先頭の位置が格納される。
	//------------------------------------------------------------
	BOOL CopyToXStr(T_PSTR* ppBuf, size_t zChar, T_PCSTR* ppszSrc)
	{
		T_PSTR	pb, pd;
		BOOL	br;

		if (pBuf == NULL || zBuf < 2 || ppszSrc == NULL)
		{
			THROWPE_LOGIC_ERROR("XLL::BString::Copy (2)");
		}

		pb	= *ppBuf;
		pd	= pb + 1;
		br	= CopyToPStr(&pd, zChar, ppszSrc)
		XLL_BSTRING_COPYTOXSTR_END_PROCESSING;
		return br;
	}

	//------------------------------------------------------------
	//	XLL::BString	コンストラクタ
	//------------------------------------------------------------
	BString(size_t zChars = XLL_STRING_INITIAL_SIZE)
		:	pBuffer(NULL),
			zStrBufferSize(0),
			zIncriment(XLL_STRING_INITIAL_SIZE)
	{
		if (zChars > 0)
		{
			//zStrBufferSize	= zChars;
			zIncriment		= zChars;
		}
		//ciMAlloc.Allocate<T_CHAR>(&pBuffer, zStrBufferSize + 2);
		//Clear();	//	null 文字列を設定しておく。
	}

	//------------------------------------------------------------
	//	XLL::BString	デストラクタ
	//------------------------------------------------------------
	~BString()
	{
		ciMAlloc.Deallocate<T_CHAR>(pBuffer);
	}

	//------------------------------------------------------------
	//	XLL::BString::Assign	(1)	始点と終点を引数とする。
	//	格納できない文字があったら FALSE を返す。
	//	*ppSrcB には、格納できなかった文字の先頭の位置が格納される。
	//------------------------------------------------------------
	BOOL Assign(T_PCSTR* ppSrcB, T_PCSTR pSrcE)
	{
		T_PSTR	pb;
		size_t	zSize;

		if (ppSrcB == NULL || *ppSrcB > pSrcE)	THROWPE_LOGIC_ERROR("XLL::BString::Assign");

		zSize	= pSrcE - *ppSrcB;
		if (zSize > MAX_STRING_SIZE)	zSize = MAX_STRING_SIZE;

		if (zSize > zStrBufferSize)	ExtendBuffer(zSize, FALSE);	//	バッファは zSize + 2 以上に拡張される。
		pb	= pBuffer;
		return CopyToXStr(&pb, zStrBufferSize, ppSrcB, pSrcE);
	}

	BOOL Assign(T_PCSTR pSrcB, T_PCSTR pSrcE)
	{
		T_PCSTR	psb;

		if (pSrcB == NULL)	THROWPE_LOGIC_ERROR("XLL::BString::Assign");
		psb	= pSrcB;
		return Assign(&psb, pSrcE);
	}

	//------------------------------------------------------------
	//	XLL::BString::Assign	(2)	始点と文字数を引数とする。
	//	格納できない文字があったら FALSE を返す。
	//	*ppSrc には、格納できなかった文字の先頭の位置が格納される。
	//------------------------------------------------------------
	BOOL Assign(T_PCSTR* ppSrc, size_t zSize)
	{
		if (ppSrc == NULL)	THROWPE_LOGIC_ERROR("XLL::BString::Assign");
		return Assign(ppSrc, *ppSrc + zSize);
	}

	BOOL Assign(T_PCSTR pSrc, size_t zSize)
	{
		T_PCSTR	psb;

		if (pSrc == NULL)	THROWPE_LOGIC_ERROR("XLL::BString::Assign");
		psb	= pSrc;
		return Assign(psb, psb + zSize);
	}

	//------------------------------------------------------------
	//	XLL::BString::Assign	(3) 始点のみを引数とする。（NULL までを格納する。）
	//	格納できない文字があったら FALSE を返す。
	//	*ppszSrc には、格納できなかった文字の先頭の位置が格納される。
	//------------------------------------------------------------
	BOOL Assign(T_PCSTR* ppszSrc)
	{
		T_PCSTR	pc, pe;

		if (ppszSrc == NULL || *ppszSrc == NULL)
			THROWPE_LOGIC_ERROR("XLL::BString::Assign");

		pc	= *ppszSrc;
		pe	= pc + XLL::MaxStrSize<T_CHAR>();
		while (pc < pe && *pc != NULL)	++pc;
		return Assign(ppszSrc, pc);
	}

	BOOL Assign(T_PCSTR pszSrc)
	{
		T_PCSTR	psb;

		if (pszSrc == NULL)	THROWPE_LOGIC_ERROR("XLL::BString::Assign");
		psb	= pszSrc;
		return Assign(&psb);
	}

	//------------------------------------------------------------
	//	XLL::BString::AssignXS
	//	*ppXStr には、格納できなかった文字の先頭の位置が格納される。
	//------------------------------------------------------------
	BOOL AssignXS(T_PCSTR* ppXStr)
	{
		T_PCSTR	pb;
		BOOL	br;

		if (ppXStr == NULL || *ppXStr == NULL)
			THROWPE_LOGIC_ERROR("XLL::BString::Assign");
		pb	= *ppXStr + 1;
		br	= Assign(&pb, (size_t)**ppXStr);
		*ppXStr	= pb;
		return br;
	}

	BOOL AssignXS(T_PCSTR pXSrc)
	{
		T_PCSTR	pxs;

		if (pXSrc == NULL)	return FALSE;
		pxs	= pXSrc;
		return AssignXS(&pxs);
	}

	BOOL AssignXS(XLL::IString<T_CHAR>* pXString)
	{
		BOOL	bNull = FALSE;

		if (pXString == NULL || (pXString->Empty(&bNull) && bNull == TRUE))
			THROWPE_LOGIC_ERROR("XLL::BString::Assign");
		return Assign(pXString->CStr(), pXString->Size());
	}

	//------------------------------------------------------------
	//	XLL::BString::Append	(1)	始点と終点を引数とする。
	//	追加できない文字があったら FALSE を返す。
	//	*ppSrcB には、追加できなかった文字の先頭の位置が格納される。
	//------------------------------------------------------------
	BOOL Append(T_PCSTR* ppSrcB, T_PCSTR pSrcE)
	{
		//T_PCSTR	ps;
		T_PSTR	pFree;
		size_t	zFree, zOld, zTotal;
		BOOL	br;

		if (ppSrcB == NULL)	return TRUE;
		if (*ppSrcB > pSrcE)	THROWPE_LOGIC_ERROR("XLL::BString::Append");

		//	すでに最大長に達している場合は追加しない。
		if (GetStringSize<T_CHAR>(pBuffer) >= MAX_STRING_SIZE)	return FALSE;

		//	バッファを拡大する。元の XLL 文字列は新しいバッファにコピーしておく。
		zOld	= GetStringSize<T_CHAR>(pBuffer);
		zTotal	= zOld + (size_t)(pSrcE - *ppSrcB);
		ExtendBuffer(zTotal, TRUE);
		FreeSpace(&pFree, &zFree);

		br	= CopyToPStr(&pFree, zFree, ppSrcB, pSrcE);
		*pBuffer	= (T_CHAR)(size_t)(pFree - pBuffer - 1);
		DropWrongLastChar(pBuffer);
		return br;
	}

	BOOL Append(T_PCSTR pSrcB, T_PCSTR pSrcE)
	{
		T_PCSTR	psb;

		if (pSrcB == NULL)	THROWPE_LOGIC_ERROR("XLL::BString::Append");
		psb	= pSrcB;
		return Append(&psb, pSrcE);
	}

	//------------------------------------------------------------
	//	XLL::BString::Append	(2)	始点と文字数を引数とする。
	//	追加できない文字があったら FALSE を返す。
	//------------------------------------------------------------
	BOOL Append(T_PCSTR* ppStr, size_t zSize)
	{
		if (ppStr == NULL || zSize < 1)	return TRUE;
		return Append(ppStr, *ppStr + zSize);
	}

	BOOL Append(T_PCSTR pStr, size_t zSize)
	{
		T_PCSTR	ps;

		if (pStr == NULL)	return TRUE;
		ps	= pStr;
		return Append(&ps, ps + zSize);
	}

	//------------------------------------------------------------
	//	XLL::BString::Append	(3) 始点のみを引数とする。（NULL までを格納する。）
	//	追加できない文字があったら FALSE を返す。
	//------------------------------------------------------------
	BOOL Append(T_PCSTR* ppszStr)
	{
		T_PCSTR	pe;

		if (ppszStr == NULL)	return TRUE;
		pe	= *ppszStr;
		while (*pe)	++pe;
		return Append(ppszStr, pe);
	}

	BOOL Append(T_PCSTR pszStr)
	{
		T_PCSTR	ps;

		if (pszStr == NULL)	return TRUE;
		ps	= pszStr;
		return Append(&ps);
	}

	//------------------------------------------------------------
	//	XLL::BString::AppendXS
	//
	//	処理が正常に行われなかった場合にのみ FALSE を返す。
	//	*pzStored には格納した文字数を返す。
	//	引数のチェックは呼び出し側で行うこと。
	//------------------------------------------------------------
	BOOL AppendXS(T_PCSTR* ppXStr)
	{
		T_PCSTR	pb;
		BOOL	br;

		if (ppXStr == NULL || *ppXStr == NULL)	return TRUE;
		pb	= *ppXStr + 1;
		br	= Append(&pb, (size_t)**ppXStr);
		*ppXStr	= pb;
		return br;
	}

	BOOL AppendXS(T_PCSTR pXSrc)
	{
		T_PCSTR	pxs;

		if (pXSrc == NULL)	return TRUE;
		pxs	= pXSrc;
		return AppendXS(&pxs);
	}

	BOOL AppendXS(XLL::IString<T_CHAR>* pXString)
	{
		if (pXString == NULL || pXString->Empty())	return TRUE;
		return Append(pXString->CStr(), pXString->Size());
	}

	//------------------------------------------------------------
	//	XLL::BString::CopyPStrTo
	//------------------------------------------------------------
	BOOL CopyPStrTo(T_PSTR pDst, size_t zDst)
	{
		T_PCSTR	ps;

		if (pBuffer == NULL || zDst < GetStringSize<T_CHAR>(pBuffer) + 1)
			return FALSE;
		for (ps = pBuffer + 1; *ps != NULL; ++ps, ++pDst)
		{
			*pDst	= *ps;
		}
		*pDst	= NULL;
		return TRUE;
	}

	//------------------------------------------------------------
	//	XLL::BString::CopyXStrTo
	//------------------------------------------------------------
	BOOL CopyXStrTo(T_PSTR pDst, size_t zDst)
	{
		T_PCSTR	ps;

		if (pBuffer == NULL || zDst < GetStringSize<T_CHAR>(pBuffer) + 2)	return FALSE;
		*pDst	= *pBuffer;
		++pDst;
		for (ps = pBuffer + 1; *ps != NULL; ++ps, ++pDst)
		{
			*pDst	= *ps;
		}
		*pDst	= NULL;
		return TRUE;
	}
};


//======================================================================
//	XLL::NString	:	XLL 文字列用の標準クラス
//======================================================================
template<typename T_CHAR>
class NString
{
public:
	NString()
	{
		throw std::logic_error("XLL::NString");
	}
};
template<>
class NString<char>	: public BString<char, 255, PLib::PCMAlloc>
{
};
template<>
class NString<wchar_t>	: public BString<wchar_t, 65535, PLib::PCMAlloc>
{
};

//======================================================================
//	XLL::TString	:	一時的に使用する XLL 文字列用のクラス
//======================================================================
template<typename T_CHAR>
class TString
{
public:
	TString()
	{
		throw std::logic_error("XLL::TString");
	}
};
template<>
class TString<char>	: public BString<char, 255, PLib::PCMAllocTemp>
{
};
template<>
class TString<wchar_t>	: public BString<wchar_t, 65535, PLib::PCMAllocTemp>
{
};


//======================================================================
//	class PIDTStringIn
//	class PIDTStringOut
//
//	DTString のインターフェース
//======================================================================
class PIDTStringIn
{
public:
	virtual BOOL	Assign(LPCSTR pBegin, LPCSTR pEnd)	= 0;
	virtual BOOL	Assign(LPCWSTR pBegin, LPCWSTR pEnd)	= 0;
	virtual BOOL	Assign(LPCSTR pStr, size_t zSize)		= 0;
	virtual BOOL	Assign(LPCWSTR pStr, size_t zSize)	= 0;

	virtual BOOL	Append(LPCSTR pBegin, LPCSTR pEnd)	= 0;
	virtual BOOL	Append(LPCWSTR pBegin, LPCWSTR pEnd)	= 0;
	virtual BOOL	Append(LPCSTR pStr, size_t zSize)		= 0;
	virtual BOOL	Append(LPCWSTR pStr, size_t zSize)	= 0;
};

class PIDTStringOut
{
public:
};


//======================================================================
//	class DTString
//
//	XLL::NString、XLL::TString を char、wchar_t いずれでも
//	利用できるようにするためのクラス
//======================================================================
template<class C_MALLOC = PLib::PCMAlloc>
class DTString
	:	public PIDTStringIn
{
private:
	XLL::BString<char, MAX_XL4_STR_LEN, C_MALLOC>		xStrA;
	XLL::BString<wchar_t, MAX_XL12_STR_LEN, C_MALLOC>	xStrW;

	DWORD	dwCreateTickA;
	DWORD	dwCreateTickW;

public:
	//------------------------------------------------------------
	//	DTString::DTString
	//------------------------------------------------------------
	DTString()
		:	dwCreateTickA(0),
			dwCreateTickW(0)
	{
	}

	//------------------------------------------------------------
	//	DTString::Clear
	//------------------------------------------------------------
	void ClearA()
	{
		xStrA.Clear();
		dwCreateTickA	= 0;
	}

	void ClearW()
	{
		xStrW.Clear();
		dwCreateTickW	= 0;
	}

	void Clear()
	{
		ClearA();
		ClearW();
	}

	//------------------------------------------------------------
	//	DTString::Free
	//------------------------------------------------------------
	void FreeA()
	{
		xStrA.Free();
		dwCreateTickA	= 0;
	}

	void FreeW()
	{
		xStrW.Free();
		dwCreateTickW	= 0;
	}

	void Free()
	{
		FreeA();
		FreeW();
	}

	//------------------------------------------------------------
	//	DTString::~DTString
	//------------------------------------------------------------
	~DTString()
	{
		Free();
	}

	//------------------------------------------------------------
	//	RemoveXStr
	//
	//	バッファを呼び出し側に移動させる。メモリは呼び出し側で解放すること。
	//------------------------------------------------------------
	BOOL RemoveXStrA(LPSTR* ppBuf, size_t* pzBuf)
	{
		if (ppBuf == NULL || pzBuf == NULL)	return FALSE;

		if (xStrA.RemoveXStr(ppBuf, pzBuf))
		{
			dwCreateTickA	= 0;
			return TRUE;
		}
		return FALSE;
	}

	BOOL RemoveXStrW(LPWSTR* ppBuf, size_t* pzBuf)
	{
		if (ppBuf == NULL || pzBuf == NULL)	return FALSE;

		if (xStrW.RemoveXStr(ppBuf, pzBuf))
		{
			dwCreateTickW	= 0;
			return TRUE;
		}
		return FALSE;
	}

	template<typename T_CHAR>
	BOOL RemoveXStr(T_CHAR** ppBuf, size_t* pzBuf)
	{
		THROWPE_LOGIC_ERROR("DTString::RemoveXStr");
		return FALSE;
	}
	template<>
	BOOL RemoveXStr<char>(LPSTR* ppBuf, size_t* pzBuf)
	{
		return RemoveXStrA(ppBuf, pzBuf);
	}
	template<>
	BOOL RemoveXStr<wchar_t>(LPWSTR* ppBuf, size_t* pzBuf)
	{
		return RemoveXStrW(ppBuf, pzBuf);
	}

	//------------------------------------------------------------
	//	DTString::Assign	(1)	始点と終点を引数とする。
	//------------------------------------------------------------
	BOOL Assign(LPCSTR pBegin, LPCSTR pEnd)
	{
		if (xStrA.Assign(pBegin, pEnd))
		{
			dwCreateTickA	= GetTickCount();
			return TRUE;
		}
		return FALSE;
	}

	BOOL Assign(LPCWSTR pBegin, LPCWSTR pEnd)
	{
		if (xStrW.Assign(pBegin, pEnd))
		{
			dwCreateTickW	= GetTickCount();
			return TRUE;
		}
		return FALSE;
	}

	//------------------------------------------------------------
	//	DTString::Assign
	//	(2)	始点と文字数を引数とする。
	//------------------------------------------------------------
	BOOL Assign(LPCSTR pStr, size_t zSize)
	{
		if (xStrA.Assign(pStr, zSize))
		{
			dwCreateTickA	= GetTickCount();
			return TRUE;
		}
		return FALSE;
	}

	BOOL Assign(LPCWSTR pStr, size_t zSize)
	{
		if (xStrW.Assign(pStr, zSize))
		{
			dwCreateTickW	= GetTickCount();
			return TRUE;
		}
		return FALSE;
	}

	//------------------------------------------------------------
	//	DTString::Assign
	//	(3) 始点のみを引数とする。（NULL までを格納する。）
	//------------------------------------------------------------
	BOOL Assign(LPCSTR pszStr)
	{
		if (xStrA.Assign(pszStr))
		{
			dwCreateTickA	= GetTickCount();
			return TRUE;
		}
		return FALSE;
	}

	BOOL Assign(LPCWSTR pszStr)
	{
		if (xStrW.Assign(pszStr))
		{
			dwCreateTickW	= GetTickCount();
			return TRUE;
		}
		return FALSE;
	}

	//------------------------------------------------------------
	//	DTString::AssignXS
	//
	//	処理が正常に行われなかった場合にのみ FALSE を返す。
	//	*pzStored には格納した文字数を返す。
	//	引数のチェックは呼び出し側で行うこと。
	//------------------------------------------------------------
	BOOL AssignXS(LPCSTR pStr)
	{
		if (xStrA.AssignXS(pStr))
		{
			dwCreateTickA	= GetTickCount();
			return TRUE;
		}
		return FALSE;
	}

	BOOL AssignXS(LPCWSTR pStr)
	{
		if (xStrW.AssignXS(pStr))
		{
			dwCreateTickW	= GetTickCount();
			return TRUE;
		}
		return FALSE;
	}

	//------------------------------------------------------------
	//	DTString::Append
	//
	//	処理が正常に行われなかった場合にのみ FALSE を返す。
	//	*pzStored には格納した文字数を返す。
	//	引数のチェックは呼び出し側で行うこと。
	//
	//	(1)	始点と終点を引数とする。
	//------------------------------------------------------------
	BOOL Append(LPCSTR pBegin, LPCSTR pEnd)
	{
		if (xStrA.Append(pBegin, pEnd))
		{
			dwCreateTickA	= GetTickCount();
			return TRUE;
		}
		return FALSE;
	}

	BOOL Append(LPCWSTR pBegin, LPCWSTR pEnd)
	{
		if (xStrW.Append(pBegin, pEnd))
		{
			dwCreateTickW	= GetTickCount();
			return TRUE;
		}
		return FALSE;
	}

	//------------------------------------------------------------
	//	DTString::Append
	//	(2)	始点と文字数を引数とする。
	//------------------------------------------------------------
	BOOL Append(LPCSTR pStr, size_t zSize)
	{
		if (xStrA.Append(pStr, zSize))
		{
			dwCreateTickA	= GetTickCount();
			return TRUE;
		}
		return FALSE;
	}

	BOOL Append(LPCWSTR pStr, size_t zSize)
	{
		if (xStrW.Append(pStr, zSize))
		{
			dwCreateTickW	= GetTickCount();
			return TRUE;
		}
		return FALSE;
	}

	//------------------------------------------------------------
	//	DTString::Append
	//	(3) 始点のみを引数とする。（NULL までを格納する。）
	//------------------------------------------------------------
	BOOL Append(LPCSTR pszStr)
	{
		if (xStrA.Append(pszStr))
		{
			dwCreateTickA	= GetTickCount();
			return TRUE;
		}
		return FALSE;
	}

	BOOL Append(LPCWSTR pszStr)
	{
		if (xStrW.Append(pszStr))
		{
			dwCreateTickW	= GetTickCount();
			return TRUE;
		}
		return FALSE;
	}

	//------------------------------------------------------------
	//	DTString::AppendXS
	//
	//	処理が正常に行われなかった場合にのみ FALSE を返す。
	//	*pzStored には格納した文字数を返す。
	//	引数のチェックは呼び出し側で行うこと。
	//------------------------------------------------------------
	BOOL AppendXS(LPCSTR pStr)
	{
		return xStrA.AppendXS(pStr);
	}

	BOOL AppendXS(LPCWSTR pStr)
	{
		return xStrW.AppendXS(pStr);
	}

	//------------------------------------------------------------
	//	DTString::CStr
	//------------------------------------------------------------
	template<typename T_CHAR>
	const T_CHAR* CStr()
	{
		throw std::logic_error("XLL::DTString::CStr");
		return NULL;
	}
	template<>
	LPCSTR CStr()
	{
		return xStrA.CStr();
	}
	template<>
	LPCWSTR CStr()
	{
		return xStrW.CStr();
	}

	//------------------------------------------------------------
	//	DTString::XStr
	//------------------------------------------------------------
	template<typename T_CHAR>
	const T_CHAR* XStr()
	{
		throw std::logic_error("XLL::DTString::XStr");
		return NULL;
	}
	template<>
	LPCSTR XStr()
	{
		return xStrA.XStr();
	}
	template<>
	LPCWSTR XStr()
	{
		return xStrW.XStr();
	}

	//------------------------------------------------------------
	//	DTString::Size
	//------------------------------------------------------------
	template<typename T_CHAR>
	size_t	Size()
	{
		throw std::logic_error("PCXLLStringDP::Size");
		return FALSE;
	}
	template<>
	size_t	Size<char>()
	{
		return xStrA.Size();
	}
	template<>
	size_t	Size<wchar_t>()
	{
		return xStrW.Size();
	}

	//------------------------------------------------------------
	//	DTString::Empty
	//------------------------------------------------------------
	template<typename T_CHAR>
	BOOL Empty()
	{
		throw std::logic_error("PCXLLStringDP::Empty");
		return FALSE;
	}
	template<>
	BOOL Empty<char>()
	{
		return xStrA.Empty();
	}
	template<>
	BOOL Empty<wchar_t>()
	{
		return xStrW.Empty();
	}

	//------------------------------------------------------------
	//	DTString::ConvertAtoW	(1)	変換元文字列を指定する
	//------------------------------------------------------------
	BOOL ConvertAtoW(LPCSTR pSrc, size_t zSrc)
	{
		LPWSTR	pConverted	= NULL;
		size_t	zConverted;

		if (pSrc == NULL || zSrc < 1)	return FALSE;
		if (!PLib::ConvertMBtoWCMa(&pConverted, &zConverted, pSrc, (int)zSrc))
			return FALSE;
		Assign(pConverted, zConverted);
		dwCreateTickW	= GetTickCount();
		delete[] pConverted;
		return TRUE;
	}

	//------------------------------------------------------------
	//	DTString::ConvertAtoW	(2)	xStrA を変換する
	//------------------------------------------------------------
	BOOL ConvertAtoW()
	{
		if (xStrA.Empty())	return FALSE;
		if (ConvertAtoW(xStrA.CStr(), xStrA.Size()))
		{
			dwCreateTickW	= dwCreateTickA;
			return TRUE;
		}
		return FALSE;
	}

	//------------------------------------------------------------
	//	DTString::ConvertWtoA	(1)	変換元文字列を指定する
	//------------------------------------------------------------
	BOOL ConvertWtoA(LPCWSTR pSrc, size_t zSrc)
	{
		LPSTR	pConverted	= NULL;
		size_t	zConverted;

		if (pSrc == NULL || zSrc < 1)	return FALSE;
		if (!PLib::ConvertWCtoMBMa(&pConverted, &zConverted, pSrc, (int)zSrc))
			return FALSE;
		xStrA.Assign(pConverted, zConverted);
		dwCreateTickA	= GetTickCount();
		delete[] pConverted;
		return TRUE;
	}

	//------------------------------------------------------------
	//	DTString::ConvertWtoA	(2)	xStrW を変換する
	//------------------------------------------------------------
	BOOL ConvertWtoA()
	{
		if (xStrW.Empty())	return FALSE;
		if (ConvertWtoA(xStrW.CStr(), xStrW.Size()))
		{
			dwCreateTickA	= dwCreateTickW;
			return TRUE;
		}
		return FALSE;
	}

	//------------------------------------------------------------
	//	Convert	(1)	変換元文字列を指定する
	//------------------------------------------------------------
	template<typename TC_DST, typename TC_SRC>
	inline BOOL Convert(const TC_SRC* pSrc, size_t zSrc)
	{
		THROWPE_LOGIC_ERROR("XLL::DTString::Convert");
		return FALSE;
	}
	template<>
	inline BOOL Convert<char, char>(LPCSTR pSrc, size_t zSrc)
	{
		return xStrA.Assign(pSrc, zSrc);
	}
	template<>
	inline BOOL Convert<wchar_t, char>(LPCSTR pSrc, size_t zSrc)
	{
		return ConvertAtoW(pSrc, zSrc);
	}
	template<>
	inline BOOL Convert<char, wchar_t>(LPCWSTR pSrc, size_t zSrc)
	{
		return ConvertWtoA(pSrc, zSrc);
	}
	template<>
	inline BOOL Convert<wchar_t, wchar_t>(LPCWSTR pSrc, size_t zSrc)
	{
		return xStrW.Assign(pSrc, zSrc);
	}

	//------------------------------------------------------------
	//	Convert
	//------------------------------------------------------------
	template<typename TC_DST, typename TC_SRC>
	inline BOOL Convert()
	{
		THROWPE_LOGIC_ERROR("XLL::DTString::Convert");
		return FALSE;
	}
	template<>
	inline BOOL Convert<char, char>()
	{
		return TRUE;
	}
	template<>
	inline BOOL Convert<wchar_t, char>()
	{
		return ConvertAtoW();
	}
	template<>
	inline BOOL Convert<char, wchar_t>()
	{
		return ConvertWtoA();
	}
	template<>
	inline BOOL Convert<wchar_t, wchar_t>()
	{
		return TRUE;
	}
};

NS_XLL_END


//======================================================================
//	型の定義
//======================================================================
typedef	XLL::NString<T_CHAR_XLL>	XLL_STRING, *XLL_PSTRING;
typedef	XLL::NString<char>			XLL_STRINGA, *XLL_PSTRINGA;
typedef	XLL::NString<wchar_t>		XLL_STRINGW, *XLL_PSTRINGW;

typedef	XLL::TString<T_CHAR_XLL>	XLL_STRING_TEMP, *XLL_PSTRING_TEMP;
typedef	XLL::TString<char>			XLL_STRINGA_TEMP, *XLL_PSTRINGA_TEMP;
typedef	XLL::TString<wchar_t>		XLL_STRINGW_TEMP, *XLL_PSTRINGW_TEMP;

typedef	XLL::DTString<PLib::PCMAlloc>		XLL_DTSTRING;
typedef	XLL::DTString<PLib::PCMAllocTemp>	XLL_DTSTRING_TEMP;
