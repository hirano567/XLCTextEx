//	XLCTextEx_1.0x	:	PLibXLL

//	XLLStringUtility.h
//
#pragma once

NS_XLL_BEGIN

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

//======================================================================
//	GetXLOPERString	(1)
//=====================================================================
template<typename T_CHAR, typename T_XLOPER>
bool GetXLOPERString(const T_CHAR** ppStrB, size_t* pzSize, T_XLOPER* pxOper)
{
	const T_CHAR*	pb;
	size_t			zs;

	if (pxOper->xltype != xltypeStr)	return false;
	zs	= GetStringSize(pxOper->val.str);
	if (zs < 1)	return false;

	pb	= pxOper->val.str + 1;
	*ppStrB	= pb;
	*pzSize	= zs;
	return true;
}

//======================================================================
//	GetXLOPERString	(2)
//=====================================================================
template<typename T_CHAR, typename T_XLOPER>
bool GetXLOPERString(const T_CHAR** ppStrB, const T_CHAR** ppStrE, T_XLOPER* pxOper)
{
	const T_CHAR*	pb;
	size_t			zs;

	if (GetXLOPERString<T_CHAR, T_XLOPER>(&pb, &zs, pxOper))
	{
		*ppStrB	= pb;
		*ppStrE	= pb + zs;
		return true;
	}
	return false;
}

//======================================================================
//	GetXLOPERString	(3)
//=====================================================================
template<typename T_CHAR, typename T_XLOPER>
bool GetXLOPERString(std::basic_string<T_CHAR>* pstrBuf, T_XLOPER* pxOper)
{
	const T_CHAR*	pb;
	size_t			zs;

	if (GetXLOPERString<T_CHAR, T_XLOPER>(&pb, &zs, pxOper))
	{
		pstrBuf->append(pb, zs);
		return true;
	}
	return false;
}

//======================================================================
//	XLStrCopy	(1-1)
//	c 形式の文字列を XL 形式の文字列にコピーする。
//	最初の T_CHAR には文字列長、最後の T_CHAR には NULL を入れる。
//	コピー先のメモリは呼び出し側で確保しておくこと。（コピーする文字列長 + 2 必要）
//======================================================================
template<typename T_CHAR>
bool XLStrCopyEx(T_CHAR* pDst, size_t zDst, const T_CHAR* pSrc, size_t zSrc, size_t zMaxSize = 255)
{
	typedef	T_CHAR*			T_PSTR;
	typedef	const T_CHAR*	T_PCSTR;

	T_PSTR	pdc, pds, pde;
	T_PSTR	pEnd;
	T_PCSTR	psc;

	if (pDst == NULL || zDst < 2 || pSrc == NULL)	return false;
	if (zDst == 2 || zSrc < 1)
	{
		*pDst		= NULL;
		*(pDst + 1)	= NULL;
		return true;
	}

	zDst	-= 2;
	if (zDst > zMaxSize)	zDst = zMaxSize;
	if (zSrc < zDst)	zDst = zSrc;
	pds	= pDst + 1;
	pde	= pds + zDst;
	pdc	= pds;
	psc	= pSrc;
	while (pdc < pde)
	{
		*pdc	= *psc;
		++pdc;
		++psc;
	}

	//	終端に不適切な文字がある場合は終端を調整し、
	//	先頭に文字数、終端に NULL を入れる。
	if (!PLib::FindValidEnd<T_CHAR>((T_PCSTR*)&pEnd, (T_PCSTR)pds, (T_PCSTR)pde))	return false;
	*pDst	= (T_CHAR)(pEnd - pds);
	*pEnd	= (T_CHAR)0;
	return true;
}

template<typename T_CHAR>
inline bool XLStrCopy(T_CHAR* pDst, size_t zDst, const T_CHAR* pSrc, size_t zSrc)
{
	THROWPE_LOGIC_ERROR("XLL::XLStrCopy");
	return false;
}
template<>
inline bool XLStrCopy<char>(LPSTR pDst, size_t zDst, LPCSTR pSrc, size_t zSrc)
{
	return XLStrCopyEx<char>(pDst, zDst, pSrc, zSrc, 255);
}
template<>
inline bool XLStrCopy<wchar_t>(LPWSTR pDst, size_t zDst, LPCWSTR pSrc, size_t zSrc)
{
	return XLStrCopyEx<wchar_t>(pDst, zDst, pSrc, zSrc, 32767);
}

//======================================================================
//	XLStrCopy	(1-2)
//	c 形式の文字列を XL 形式の文字列にコピーする。関数内でメモリを確保する。
//======================================================================
template<typename T_CHAR, class C_MALLOC>
bool t_XLStrCopyMa(T_CHAR** ppDst, const T_CHAR* pSrc, size_t zSrc, size_t zMaxSize = 255)
{
	C_MALLOC	ciMAlloc;

	if (zSrc > zMaxSize)	zSrc = zMaxSize;
	*ppDst	= ciMAlloc.Allocate<T_CHAR>(zSrc + 2);
	return XLStrCopyEx<T_CHAR>(*ppDst, zSrc + 2, pSrc, zSrc, zMaxSize);
}

template<typename T_CHAR>
inline bool XLStrCopyMa(T_CHAR** ppDst, const T_CHAR* pSrc, size_t zSrc)
{
	THROWPE_LOGIC_ERROR("XLL::XLStrCopyMa");
	return false;
}
template<>
inline bool XLStrCopyMa<char>(LPSTR* ppDst, LPCSTR pSrc, size_t zSrc)
{
	return t_XLStrCopyMa<char, PLib::PCMAlloc>(ppDst, pSrc, zSrc, 255);
}
template<>
inline bool XLStrCopyMa<wchar_t>(LPWSTR* ppDst, LPCWSTR pSrc, size_t zSrc)
{
	return t_XLStrCopyMa<wchar_t, PLib::PCMAlloc>(ppDst, pSrc, zSrc, 32767);
}

//======================================================================
//	XLStrCopy	(2)
//	XL 形式の文字列を XL 形式の文字列にコピーする
//======================================================================
template<typename T_CHAR, class C_MALLOC>
bool t_XLStrCopyMa(T_CHAR** ppDst, const T_CHAR* pSrc)
{
	C_MALLOC	ciMAlloc;
	size_t		zSrc;

	zSrc	= GetStringSize<T_CHAR>(pSrc);
	*ppDst	= ciMAlloc.Allocate<T_CHAR>(zSrc + 2);
	return XLStrCopy<T_CHAR>(*ppDst, pSrc + 1, zSrc);
}

template<typename T_CHAR>
inline bool XLStrCopyMa(T_CHAR** ppDst, const T_CHAR* pSrc)
{
	return XLStrCopyMa<T_CHAR>(ppDst, pSrc, GetStringSize<T_CHAR>(pSrc));
}

//======================================================================
//	XLStrConvert4to12Ma
//======================================================================
template<class C_MALLOC>
bool t_XLStrConvert4to12Ma(LPWSTR* ppDst, LPCSTR pSrc)
{
	C_MALLOC	ciMAlloc;
	int			iSrc;
	size_t		zDst, zTemp;

	if (ppDst == NULL || pSrc == NULL)	return false;
	iSrc	= (int)GetStringSize<char>(pSrc);
	if (iSrc > 0)
	{
		if (!PLib::GetSizeMBtoWC(&zTemp, pSrc + 1, iSrc))	return false;
	}
	else
	{
		zTemp	= 0;
	}
	*ppDst	= ciMAlloc.Allocate<wchar_t>(zTemp + 2);
	if (zTemp > 0)
	{
		if (!PLib::ConvertMBtoWC((*ppDst) + 1, zTemp + 1, &zDst, pSrc + 1, iSrc))
		{
			ciMAlloc.Deallocate(*ppDst);
			return false;
		}
	}
	else
	{
		*((*ppDst) + 1)	= NULL;
		zDst	= 0;
	}
	**ppDst	= (wchar_t)zDst;
	return true;
}

inline bool XLStrConvert4to12Ma(LPWSTR* ppDst, LPCSTR pSrc)
{
	return t_XLStrConvert4to12Ma<PLib::PCMAlloc>(ppDst, pSrc);
}

//======================================================================
//	XLStrConvert12to4Ma
//======================================================================
template<class C_MALLOC>
bool t_XLStrConvert12to4Ma(LPSTR* ppDst, LPCWSTR pSrc)
{
	C_MALLOC	ciMAlloc;
	int			iSrc;
	size_t		zDst;
	size_t		zTemp1	= 0, zTemp2;
	LPSTR		pBuf	= NULL;
	//LPSTR		pb, pe, pEnd;

	if (ppDst == NULL || pSrc == NULL)	return false;
	*ppDst	= NULL;

	iSrc	= (int)GetStringSize<wchar_t>(pSrc);
	if (iSrc > 0)
	{
		if (!PLib::GetSizeWCtoMB(&zTemp1, pSrc + 1, iSrc))	return false;
	}
	else
	{
		zTemp1	= 0;
	}

	//------------------------------------------------------------
	//	変換後の文字列長が制限を超える場合
	//------------------------------------------------------------
	if (zTemp1 > MAX_XL4_STR_LEN)
	{
		pBuf	= ciMAlloc.Allocate<char>(zTemp1 + 1);
		if (!PLib::ConvertWCtoMB(pBuf, zTemp1 + 1, &zTemp2, pSrc + 1, iSrc))
		{
			ciMAlloc.Deallocate(pBuf);
			return false;
		}

		*ppDst	= ciMAlloc.Allocate<char>(MAX_XL4_STR_LEN + 2);
		if (XLStrCopy<char>(*ppDst, MAX_XL4_STR_LEN + 2, pBuf, zTemp2))
		{
			return true;
		}
		ciMAlloc.Deallocate(pBuf);
		return false;
	}
	//------------------------------------------------------------
	//	変換後の文字列長が制限内の場合
	//------------------------------------------------------------
	else if (zTemp1 > 0)
	{
		*ppDst	= ciMAlloc.Allocate<char>(zTemp1 + 2);
		if (!PLib::ConvertWCtoMB((*ppDst) + 1, zTemp1 + 1, &zDst, pSrc + 1, iSrc))
		{
			ciMAlloc.Deallocate(*ppDst);
			return false;
		}
		**ppDst	= (char)(unsigned char)zDst;
		return true;
	}
	//------------------------------------------------------------
	//	空文字列の場合
	//------------------------------------------------------------
	else
	{
		*ppDst	= ciMAlloc.Allocate<char>(2);
		*((*ppDst) + 1)	= NULL;
		**ppDst	= (wchar_t)0;
		return true;
	}
	return false;
}

inline bool XLStrConvert12to4Ma(LPSTR* ppDst, LPCWSTR pSrc)
{
	return t_XLStrConvert12to4Ma<PLib::PCMAlloc>(ppDst, pSrc);
}


//======================================================================
//	XLRemoveQuote
//	xltypeStr 型の pxSrc からデータのテキストを取り出す。その際、
//	先頭と終端が " の場合、それらを外す。
//======================================================================
template<typename T_CHAR, typename T_XLOPER>
bool XLRemoveQuote(const T_CHAR**	ppBegin,
				   const T_CHAR**	ppEnd,
				   T_XLOPER*		pxSrc,
				   DWORD			dwFlags,
				   const T_CHAR*	pszLocale)
{
	typedef	const T_CHAR*	T_PCSTR;
	T_PCSTR	pb, pe, pt;
	size_t	zs;
	//int		ir;
	T_PCSTR	cDQuote	= t_Str<T_CHAR>(TEXTAW("\""));
	T_CHAR	Buf[2]	= {0, 0};

	if (pxSrc == NULL				||
		pxSrc->xltype != xltypeStr	||
		pxSrc->val.str == NULL		||
		*(pxSrc->val.str) == 0)	return false;

	pb	= pxSrc->val.str + 1;
	zs	= XLL::GetStringSize<T_CHAR>(pxSrc->val.str);
	pe	= pb + zs;

	//------------------------------------------------------------
	//	先頭の文字が " でない、文字列長が 1 の場合は
	//	現在の文字列の先頭と終端を設定して返す。
	//------------------------------------------------------------
	if (zs < 2 || !PLib::IsDoubleQuote<T_CHAR>(*pb))
	{
		*ppBegin	= pb;
		*ppEnd		= pe;
		return true;
	}

	//------------------------------------------------------------
	//	最後の文字が " なら最初と最後の " をはずして返す。
	//	そうでない場合はそのまま返す。
	//------------------------------------------------------------
	pt	= pe;
	--pt;
	if (PLib::IsDoubleQuote<T_CHAR>(*pt))
	{
		++pb;
		*ppBegin	= pb;
		*ppEnd		= pt;
	}
	else
	{
		*ppBegin	= pb;
		*ppEnd		= pe;
	}
	return true;
}

//======================================================================
//	XLGetString
//======================================================================
template<typename T_CHAR, typename T_XLOPER>
bool XLGetString(const T_CHAR**	ppStrB,
				 const T_CHAR**	ppStrE,
				 T_XLOPER*		pxStr,
				 const T_CHAR*	pNull,
				 bool			bQuoted)
{
	size_t		zStr;
	DWORD		dwCSFlags	= NORM_IGNOREWIDTH;
	T_PCSTR_U	pszLocale	= NULL;

	switch (pxStr->xltype)
	{
	case xltypeStr:
		if (pxStr->val.str == NULL || *(pxStr->val.str) == 0)
		{
			*ppStrB	= pNull;
			*ppStrE	= pNull;
		}
		else
		{
			if (bQuoted)
			{
				if (!XLL::XLRemoveQuote<T_CHAR>(ppStrB, ppStrE, pxStr, dwCSFlags, pszLocale))
				{
					return false;
				}
			}
			else
			{
				zStr	= XLL::GetXLOPER_StrSize<T_XLOPER>(pxStr);
				*ppStrB	= pxStr->val.str + 1;
				*ppStrE	= *ppStrB + zStr;
			}
		}
		return true;
		break;

	case xltypeMissing:
	case xltypeNil:
		*ppStrB	= pNull;
		*ppStrE	= pNull;
		return true;
		break;

	default:
		break;
	}
	return false;
}

//======================================================================
//	XLIsOptionSet
//
//	XLOPER にオプション文字列が格納されているとみなし、
//	指定されたオプションが記述されているか調べる。
//======================================================================
template<typename T_CHAR, typename T_XLOPER>
bool XLIsOptionSet(T_XLOPER* pxSrc, const T_CHAR* pszOpt)
{
	typedef	const T_CHAR*	T_PCSTR;

	//T_PCSTR	pSrc;
	size_t	zSrc, zOpt;
	T_PCSTR	pc, pe;

	if (pxSrc == NULL || pszOpt == NULL)	return false;
	if (pxSrc->xltype != xltypeStr || pxSrc->val.str == NULL || *(pxSrc->val.str) == 0) return false;

	zSrc	= XLL::GetStringSize(pxSrc->val.str);
	if (!PLib::t_StrLen<T_CHAR>(&zOpt, pszOpt))	return false;
	pc	= pxSrc->val.str + 1;
	pe	= pc + zSrc - zOpt + 1;
	if (pc >= pe)	return false;

	for (; pc < pe; ++pc)
	{
		//	- 以降は取り消しの指定なので false を返す。
		//if (PLib::t_CompareString<T_CHAR>(LOCALE_USER_DEFAULT, NORM_IGNOREWIDTH,
		//	pc, zOpt, t_Str<T_CHAR>(TEXTAW("-")), zOpt) == CSTR_EQUAL)
		//{
		//	return false;
		//}
		if (PLib::t_CompareString<T_CHAR_U>(LOCALE_USER_DEFAULT, NORM_IGNOREWIDTH,
			pc, zOpt, pszOpt, zOpt) == CSTR_EQUAL)
		{
			return true;
		}
	}
	return false;
}

NS_XLL_END
