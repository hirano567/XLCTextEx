//	XLCTextEx_1.0x	:	PLib

//	PUnicode.h
//
#pragma once

#ifndef NS_PLIB
#define NS_PLIB			PLib
#define NS_PLIB_BEGIN	namespace NS_PLIB {
#define NS_PLIB_END		}
#endif

#ifndef NS_UNICODE
#define NS_UNICODE	Unicode
#define NS_PLIB_UNICODE_BEGIN	namespace NS_PLIB {	namespace NS_UNICODE {
#define NS_PLIB_UNICODE_END	}}
#endif

NS_PLIB_UNICODE_BEGIN

#define	INVALID_CODEPOINT	((T_UCP)-1)


//======================================================================
//	コードポイントと実際の文字コード間の変換
//======================================================================
//	21 ビットコードポイント値を実際の文字コードに変換する。
//	pBuf には、サロゲートの場合の 2 文字分、終端の NULL 1 文字分が必要なので、
//	最小でも wchar_t 3 文字分割り当てておくこと。
BOOL	ConvertFromCodepoint(LPWSTR pBuf, UINT uiCodepoint);

//	実際の文字コードを 21 ビットのコードポイント値に変換する。
size_t	ConvertToCodepoint(UINT* puiCodepoint, LPCWSTR* ppSrc, LPCWSTR pEnd);
size_t	ConvertToCodepoint(UINT* puiCodepoint, LPCWSTR* ppszSrc);
size_t	ConvertToCodepoint(UINT* puiCodepoint, PIFStrBuffer<wchar_t>* pciBuf);

//======================================================================
//	コードポイント列と実際のユニコード文字列間の変換
//======================================================================
bool	ConvertFromCodepoint(T_STRING_U* pstrDst, UINT uiCodepoint);
bool	ConvertFromCodepoint(T_STRING_U* pstrDst, UCPSTRING* puisSrc);

bool	ConvertToCodepoint(UCPSTRING* puisDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE);
bool	ConvertToCodepoint(UCPSTRING* puisDst, T_PCSTR_U pszSrc);


//======================================================================
//	PIFUnicodeBuffer とその派生クラス
//
//	変換元となる文字列からコードポイントを１個ずつ取り出すためのクラス。
//======================================================================
//----------------------------------------------------------------------
//	PIFUnicodeBuffer	インターフェース
//----------------------------------------------------------------------
class PIFUnicodeBuffer
{
public:
	virtual bool Set()	= 0;	//	データがセットされているかどうかを返す。

	virtual bool Begin()	= 0;
	virtual bool End()		= 0;
	virtual bool Next()		= 0;

	virtual bool GetCp(UINT* puiCp)	= 0;

	virtual bool GetCpString(UCPSTRING* puisBuffer)
	{
		T_UCP	cp;

		if (puisBuffer == NULL)	return false;

		for ( ; !End(); Next())
		{
			if (!GetCp(&cp))	return false;
			puisBuffer->append(1, cp);
		}
		return true;
	}

	virtual int Compare(PIFUnicodeBuffer* pOther)
	{
		T_UCP	cp1, cp2;

		if (!Begin())	return 0;
		if (pOther == NULL || !pOther->Begin())	return 0;

		for ( ; !End() && !(pOther->End()); Next(), pOther->Next())
		{
			if (!GetCp(&cp1))	return 0;
			if (!(pOther->GetCp(&cp2)))	return 0;
			if (cp1 < cp2)	return CSTR_LESS_THAN;
			if (cp1 > cp2)	return CSTR_GREATER_THAN;
		}
		if (End() && pOther->End())	return CSTR_EQUAL;	//	空列同士も等しいとみなす。
		if (End())	return CSTR_LESS_THAN;
		return CSTR_GREATER_THAN;
	}
};

//----------------------------------------------------------------------
//	PBCUnicodeStrBuffer	基底クラス
//	文字列のまま（ポインタを）格納する。
//----------------------------------------------------------------------
class PBCUnicodeStrBuffer	: public PIFUnicodeBuffer
{
protected:
	T_PCSTR_U	pStr;
	T_PCSTR_U	pCurrent;
	T_PCSTR_U	pNext;

public:
	PBCUnicodeStrBuffer()	: pStr(NULL), pCurrent(NULL), pNext(NULL)	{}

	virtual bool Set()	{ return (pStr != NULL); }	//	データがセットされているかどうかを返す。

	//------------------------------------------------------------
	//	Begin, End, Next, GetCurrentPos
	//------------------------------------------------------------
	virtual bool Begin()
	{
		if (!Set())	return false;
		pCurrent	= pStr;
		return true;
	}
	virtual bool End()				= 0;
	virtual bool End(T_PCSTR_U ps)	= 0;
	virtual bool Next()
	{
		if (End())	return false;
		if (pCurrent < pNext)
		{
			pCurrent = pNext;
			return true;
		}
		++pCurrent;
		return true;
	}
	virtual T_PCSTR_U	GetCurrentPos()	{ return pCurrent; }

	//------------------------------------------------------------
	//	GetChar
	//------------------------------------------------------------
	virtual bool GetChar(T_CHAR_U* pc)
	{
		if (End())	return false;
		*pc	= *pCurrent;
		return true;
	}

	//------------------------------------------------------------
	//	GetCp
	//------------------------------------------------------------
	virtual bool GetCp(UINT* puiCp)
	{
		T_PCSTR_U	pc;
		UINT			uiHigh, uiLow;

		if (End())	return false;

		//	サロゲートの２文字目なら、データに異常があるので例外をスローする。
		if (IS_LOW_SURROGATE(*pCurrent))
		{
			THROWPE_RUNTIME_ERROR("PCUnicodeBuffer: no high surrogate");
		}

		//	サロゲートの１文字目なら、次の文字と合わせてコードポイントを計算する。
		if (IS_HIGH_SURROGATE(*pCurrent))
		{
			pc	= pCurrent;
			uiHigh	= (UINT)(*pc) - (UINT)(0xD800);
			++pc;
			//	サロゲートの２文字目がないなら例外をスローする。
			if (End(pc) || !IS_LOW_SURROGATE(*pc))
			{
				THROWPE_RUNTIME_ERROR("PCUnicodeBuffer: no low surrogate");
			}
			uiLow	= (UINT)(*pc) - (UINT)(0xDC00);
			*puiCp	= (UINT)((uiHigh << 10) | uiLow) + (UINT)0x10000;
			++pc;
			pNext	= pc;
			return true;
		}

		//	以上に当てはまらない場合は、現在の文字をコードポイントとして返す。
		*puiCp	= (UINT)(*pCurrent);
		pNext	= pCurrent;
		++pNext;
		return true;
	}
};

//----------------------------------------------------------------------
//	PBCCodepointBuffer	基底クラス
//	Codepoint 列を操作する。
//----------------------------------------------------------------------
class PBCCodepointBuffer	: public PIFUnicodeBuffer
{
protected:
	const T_UCP*	puiStr;
	const T_UCP*	pCurrent;

public:
	PBCCodepointBuffer()	: puiStr(NULL), pCurrent(NULL)	{}

	virtual bool Set()	{ return (puiStr != NULL); }	//	データがセットされているかどうかを返す。

	//------------------------------------------------------------
	//	Begin, End, Next, GetCurrentPos
	//------------------------------------------------------------
	virtual bool Begin()
	{
		if (!Set())	return false;
		pCurrent	= puiStr;
		return true;
	}
	virtual bool End()	= 0;
	virtual bool Next()
	{
		if (pCurrent == NULL || End())	return false;
		++pCurrent;
		return true;
	}
	virtual const T_UCP*	GetCurrentPos()	{ return pCurrent; }

	//------------------------------------------------------------
	//	GetCp
	//------------------------------------------------------------
	virtual bool GetCp(T_UCP* puiCp)
	{
		if (pCurrent != NULL)
		{
			*puiCp	= *pCurrent;
			return true;
		}
		return false;
	}
};

//----------------------------------------------------------------------
//	PCUnicodeSegmentBuffer
//	部分文字列を扱うためのクラス。
//----------------------------------------------------------------------
class PCUnicodeSegmentBuffer	: public PBCUnicodeStrBuffer
{
protected:
	T_PCSTR_U	pEnd;

public:
	PCUnicodeSegmentBuffer()	: PBCUnicodeStrBuffer(), pEnd(NULL)	{}

	virtual bool Set()
	{
		if(!PBCUnicodeStrBuffer::Set()) return false;
		return (pStr < pEnd);
	}
	virtual bool End()	{ return (pCurrent >= pEnd); }
	virtual bool End(T_PCSTR_U ps)	{ return (ps >= pEnd); }

	bool Set(T_PCSTR_U pb, T_PCSTR_U pe)
	{
		if (pb == NULL || pb > pe)	return false;
		pStr = pb;
		pEnd = pe;
		pCurrent = pStr;
		return true;
	}
	bool Set(T_PCSTR_U ps, size_t zs)
	{
		if (ps == NULL)	return false;
		pStr = ps;
		pEnd = ps + zs;
		pCurrent = pStr;
		return true;
	}
};

//----------------------------------------------------------------------
//	PCUnicodeSzBuffer
//	NULL 終了文字列を扱うためのクラス。
//----------------------------------------------------------------------
class PCUnicodeSzBuffer	: public PBCUnicodeStrBuffer
{
protected:

public:
	PCUnicodeSzBuffer()	: PBCUnicodeStrBuffer()	{}

	//	virtual bool Set() は基底クラスのものを使用する。

	//	文字列がセットされていないとエラーになる。
	//	Set() や Begin() を呼び出してから使用すること。
	virtual bool End()	{ return (*pCurrent == NULL); }
	virtual bool End(T_PCSTR_U ps)	{ return (*ps == NULL); }

	bool Set(T_PCSTR_U ps)
	{
		if (ps == NULL)	return false;
		pStr = ps;
		pCurrent = pStr;
		return true;
	}
};

//----------------------------------------------------------------------
//	PCCodepointSegmentBuffer
//	部分 Codepoint 列を扱うためのクラス。
//----------------------------------------------------------------------
class PCCodepointSegmentBuffer	: public PBCCodepointBuffer
{
protected:
	const T_UCP*	puiEnd;

public:
	PCCodepointSegmentBuffer()	: PBCCodepointBuffer(), puiEnd(NULL)	{}

	virtual bool Set()
	{
		if(!PBCCodepointBuffer::Set()) return false;
		return (puiStr < puiEnd);
	}
	virtual bool End()	{ return (pCurrent >= puiEnd); }
	virtual bool End(const T_UCP* ps)	{ return (ps >= puiEnd); }

	bool Set(const T_UCP* pb, const T_UCP* pe)
	{
		if (pb == NULL || pb > pe)	return false;
		puiStr = pb;
		puiEnd = pe;
		pCurrent = puiStr;
		return true;
	}
	bool Set(const T_UCP* ps, size_t zs)
	{
		if (ps == NULL)	return false;
		puiStr = ps;
		puiEnd = ps + zs;
		pCurrent = puiStr;
		return true;
	}
};

//----------------------------------------------------------------------
//	PCCodepointSzBuffer
//	NULL 終了 Codepoint 列を扱うためのクラス。
//----------------------------------------------------------------------
class PCCodepointSzBuffer	: public PBCCodepointBuffer
{
protected:

public:
	PCCodepointSzBuffer()	: PBCCodepointBuffer()	{}

	virtual bool Set()
	{
		return PBCCodepointBuffer::Set();
	}
	virtual bool End()	{ return (*pCurrent == 0); }
	virtual bool End(T_UCP* ps)	{ return (*ps == 0); }

	bool Set(const T_UCP* ps)
	{
		if (ps == NULL)	return false;
		puiStr		= ps;
		pCurrent	= ps;
		return true;
	}
};

//----------------------------------------------------------------------
//	PCUIStringBuffer
//	UCPSTRING からコードポイントを取り出す。
//----------------------------------------------------------------------
class PCUIStringBuffer	: public PIFUnicodeBuffer
{
protected:
	UCPSTRING*	puisBuffer;
	const UINT*	pCurrent;

public:
	PCUIStringBuffer()	: pCurrent(NULL)	{}

	UCPSTRING* GetBuffer()	{ return puisBuffer; }

	virtual bool Set()	{ return (puisBuffer != NULL); }

	bool Set(UCPSTRING* puisSrc)
	{
		puisBuffer	= puisSrc;
		if (puisBuffer != NULL)
		{
			pCurrent	= puisBuffer->c_str();
			return true;
		}
		return false;
	}

	virtual bool Begin()
	{
		if (puisBuffer == NULL || puisBuffer->empty())
		{
			pCurrent	= NULL;
			return false;
		}
		pCurrent	= puisBuffer->c_str();
		return true;
	}

	virtual bool End()	{ return (pCurrent == NULL || *pCurrent == NULL); }

	virtual bool Next()
	{
		if (pCurrent == NULL || *pCurrent == NULL)	return false;
		++pCurrent;
		return true;
	}

	virtual bool GetCp(UINT* puiCp)
	{
		if (pCurrent == NULL || *pCurrent == NULL)	return false;
		*puiCp	= *pCurrent;
		return true;
	}
};

//----------------------------------------------------------------------
//	PCUnicodeCpBuffer
//	コードポイントに変換して格納する。
//----------------------------------------------------------------------
class PCUnicodeCpBuffer	: public PIFUnicodeBuffer
{
protected:
	UCPSTRING	uisBuffer;
	const UINT*	pCurrent;

public:
	PCUnicodeCpBuffer()	: pCurrent(NULL)	{}

	UCPSTRING* GetBuffer()	{ return &uisBuffer; }

	virtual bool Set()	{ return !(uisBuffer.empty()); }

	bool Set(T_PCSTR_U pb, T_PCSTR_U pe)
	{
		if (pb == NULL || pb > pe)	return false;
		uisBuffer.clear();
		pCurrent	= NULL;
		return ConvertToCodepoint(&uisBuffer, pb, pe);
	}

	bool Set(T_PCSTR_U psz)
	{
		if (psz == NULL)	return false;
		uisBuffer.clear();
		pCurrent	= NULL;
		return ConvertToCodepoint(&uisBuffer, psz);
	}

	virtual bool Begin()
	{
		if (uisBuffer.empty())
		{
			pCurrent	= NULL;
			return false;
		}
		pCurrent	= uisBuffer.c_str();
		return true;
	}

	virtual bool End()	{ return (pCurrent == NULL || *pCurrent == NULL); }

	virtual bool Next()
	{
		if (pCurrent == NULL || *pCurrent == NULL)	return false;
		++pCurrent;
		return true;
	}

	virtual bool GetCp(UINT* puiCp)
	{
		if (pCurrent == NULL || *pCurrent == NULL)	return false;
		*puiCp	= *pCurrent;
		return true;
	}
};

NS_PLIB_UNICODE_END
