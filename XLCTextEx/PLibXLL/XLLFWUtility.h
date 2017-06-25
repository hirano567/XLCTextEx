//	XLCTextEx_1.0x	:	PLibXLL

//	XLLFWUtility.h
//
#pragma once

//======================================================================
//	Excel4 と Excel、Excel12 と Excel12f 用の関数テンプレート
//======================================================================
//----------------------------------------------------------------------
//	iCount = 0
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline int t_Excel(int iFn, T_XLOPER* pxRet)
{
	UNREFERENCED_PARAMETER(iFn);
	UNREFERENCED_PARAMETER(pxRet);

	return xlretInvXloper;
}
template<>
inline int t_Excel<XLOPER>(int iFn, XLOPER* pxRet)
{
	return Excel4(iFn, pxRet, 0);
}
template<>
inline int t_Excel<XLOPER12>(int iFn, XLOPER12* pxRet)
{
	return Excel12(iFn, pxRet, 0);
}

//----------------------------------------------------------------------
//	iCount = 1
//----------------------------------------------------------------------
template<typename T_XLOPER, bool B_FRAMEWORK>
inline int t_Excel(int iFn, T_XLOPER* pxRet, T_XLOPER* pxOper1)
{
	UNREFERENCED_PARAMETER(iFn);
	UNREFERENCED_PARAMETER(pxRet);
	UNREFERENCED_PARAMETER(pxOper1);

	return xlretInvXloper;
}
template<>
inline int t_Excel<XLOPER, false>(int iFn, XLOPER* pxRet, XLOPER* pXLOper1)
{
	return Excel4(iFn, pxRet, 1, pXLOper1);
}
template<>
inline int t_Excel<XLOPER, true>(int iFn, XLOPER* pxRet, XLOPER* pXLOper1)
{
	return Excel(iFn, pxRet, 1, pXLOper1);
}
template<>
inline int t_Excel<XLOPER12, false>(int iFn, XLOPER12* pxRet, XLOPER12* pxOper1)
{
	return Excel12(iFn, pxRet, 1, pxOper1);
}
template<>
inline int t_Excel<XLOPER12, true>(int iFn, XLOPER12* pxRet, XLOPER12* pxOper1)
{
	return Excel12f(iFn, pxRet, 1, pxOper1);
}

//----------------------------------------------------------------------
//	iCount = 2
//----------------------------------------------------------------------
template<typename T_XLOPER, bool B_FRAMEWORK>
inline int t_Excel(int iFn, T_XLOPER* pxRet, T_XLOPER* pxOper1, T_XLOPER* pxOper2)
{
	UNREFERENCED_PARAMETER(iFn);
	UNREFERENCED_PARAMETER(pxOper1);
	UNREFERENCED_PARAMETER(pxOper2);

	return xlretInvXloper;
}
template<>
inline int t_Excel<XLOPER, false>(int iFn, XLOPER* pxRet, XLOPER* pxOper1, XLOPER* pxOper2)
{
	return Excel4(iFn, pxRet, 2, pxOper1, pxOper2);
}
template<>
inline int t_Excel<XLOPER, true>(int iFn, XLOPER* pxRet, XLOPER* pxOper1, XLOPER* pxOper2)
{
	return Excel(iFn, pxRet, 2, pxOper1, pxOper2);
}
template<>
inline int t_Excel<XLOPER12, false>(int iFn, XLOPER12* pxRet, XLOPER12* pxOper1, XLOPER12* pxOper2)
{
	return Excel12(iFn, pxRet, 2, pxOper1, pxOper2);
}
template<>
inline int t_Excel<XLOPER12, true>(int iFn, XLOPER12* pxRet, XLOPER12* pxOper1, XLOPER12* pxOper2)
{
	return Excel12f(iFn, pxRet, 2, pxOper1, pxOper2);
}

//----------------------------------------------------------------------
//	iCount = 3
//----------------------------------------------------------------------
template<typename T_XLOPER, bool B_FRAMEWORK>
inline int t_Excel(int iFn, T_XLOPER* pxRet, T_XLOPER* pxOper1, T_XLOPER* pxOper2, T_XLOPER* pxOper3)
{
	UNREFERENCED_PARAMETER(iFn);
	UNREFERENCED_PARAMETER(pxOper1);
	UNREFERENCED_PARAMETER(pxOper2);
	UNREFERENCED_PARAMETER(pxOper3);

	return xlretInvXloper;
}
template<>
inline int t_Excel<XLOPER, false>(int iFn, XLOPER* pxRet,
								  XLOPER* pxOper1, XLOPER* pxOper2, XLOPER* pxOper3)
{
	return Excel4(iFn, pxRet, 3, pxOper1, pxOper2, pxOper3);
}
template<>
inline int t_Excel<XLOPER, true>(int iFn, XLOPER* pxRet,
								 XLOPER* pxOper1, XLOPER* pxOper2, XLOPER* pxOper3)
{
	return Excel(iFn, pxRet, 3, pxOper1, pxOper2, pxOper3);
}
template<>
inline int t_Excel<XLOPER12, false>(int iFn, XLOPER12* pxRet,
									XLOPER12* pxOper1, XLOPER12* pxOper2, XLOPER12* pxOper3)
{
	return Excel12(iFn, pxRet, 3, pxOper1, pxOper2, pxOper3);
}
template<>
inline int t_Excel<XLOPER12, true>(int iFn, XLOPER12* pxRet,
								   XLOPER12* pxOper1, XLOPER12* pxOper2, XLOPER12* pxOper3)
{
	return Excel12f(iFn, pxRet, 3, pxOper1, pxOper2, pxOper3);
}

//----------------------------------------------------------------------
//	iCount = 4
//----------------------------------------------------------------------
template<typename T_XLOPER, bool B_FRAMEWORK>
inline int t_Excel(int iFn, T_XLOPER* pxRet,
				   T_XLOPER* pxOper1, T_XLOPER* pxOper2, T_XLOPER* pxOper3, T_XLOPER* pxOper4)
{
	UNREFERENCED_PARAMETER(iFn);
	UNREFERENCED_PARAMETER(pxOper1);
	UNREFERENCED_PARAMETER(pxOper2);
	UNREFERENCED_PARAMETER(pxOper3);
	UNREFERENCED_PARAMETER(pxOper4);

	return xlretInvXloper;
}
template<>
inline int t_Excel<XLOPER, false>(int iFn, XLOPER* pxRet,
								  XLOPER* pxOper1, XLOPER* pxOper2, XLOPER* pxOper3, XLOPER* pxOper4)
{
	return Excel4(iFn, pxRet, 3, pxOper1, pxOper2, pxOper3, pxOper4);
}
template<>
inline int t_Excel<XLOPER, true>(int iFn, XLOPER* pxRet,
								 XLOPER* pxOper1, XLOPER* pxOper2, XLOPER* pxOper3, XLOPER* pxOper4)
{
	return Excel(iFn, pxRet, 3, pxOper1, pxOper2, pxOper3, pxOper4);
}
template<>
inline int t_Excel<XLOPER12, false>(int iFn, XLOPER12* pxRet,
									XLOPER12* pxOper1, XLOPER12* pxOper2,
									XLOPER12* pxOper3, XLOPER12* pxOper4)
{
	return Excel12(iFn, pxRet, 3, pxOper1, pxOper2, pxOper3, pxOper4);
}
template<>
inline int t_Excel<XLOPER12, true>(int iFn, XLOPER12* pxRet,
								   XLOPER12* pxOper1, XLOPER12* pxOper2,
								   XLOPER12* pxOper3, XLOPER12* pxOper4)
{
	return Excel12f(iFn, pxRet, 3, pxOper1, pxOper2, pxOper3, pxOper4);
}


//======================================================================
//	Excel4v, Excel12v 用の関数テンプレート
//======================================================================
template<typename T_XLOPER>
inline int	t_Excelv(int iFn, T_XLOPER* pxRet, int iCount, T_XLOPER** ppxOper)
{
	UNREFERENCED_PARAMETER(iFn);
	UNREFERENCED_PARAMETER(iCount);
	UNREFERENCED_PARAMETER(pXLOper);

	return xlretInvXloper;
}
template<>
inline int t_Excelv<XLOPER>(int iFn, XLOPER* pxRet, int iCount, XLOPER** ppxOper)
{
	return Excel4v(iFn, pxRet, iCount, ppxOper);
}
template<>
inline int t_Excelv<XLOPER12>(int iFn, XLOPER12* pxRet, int iCount, XLOPER12** ppxOper)
{
	return Excel12v(iFn, pxRet, iCount, ppxOper);
}

//======================================================================
//	Framework 関数用のテンプレート
//======================================================================
//----------------------------------------------------------------------
//	TempBool, TempBool12
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline T_XLOPER* t_TempBool(BOOL b)
{
	UNREFERENCED_PARAMETER(b);
	return NULL;
}
template<>
inline XLOPER* t_TempBool<XLOPER>(BOOL b)
{
	return TempBool((int)b);
}
template<>
inline XLOPER12* t_TempBool<XLOPER12>(BOOL b)
{
	return TempBool12((int)b);
}

//----------------------------------------------------------------------
//	TempNum, TempNum12
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline T_XLOPER* t_TempNum(double d)
{
	UNREFERENCED_PARAMETER(d);
	return NULL;
}
template<>
inline XLOPER* t_TempNum<XLOPER>(double d)
{
	return TempNum(d);
}
template<>
inline XLOPER12* t_TempNum<XLOPER12>(double d)
{
	return TempNum12(d);
}

//----------------------------------------------------------------------
//	TempInt, TempInt12
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline T_XLOPER* t_TempInt(int i)
{
	UNREFERENCED_PARAMETER(i);
	return NULL;
}
template<>
inline XLOPER* t_TempInt<XLOPER>(int i)
{
	return TempInt((short int)i);
}
template<>
inline XLOPER12* t_TempInt<XLOPER12>(int i)
{
	return TempInt12(i);
}

//----------------------------------------------------------------------
//	TempStrConst, TempStr12	(1)
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER>
inline T_XLOPER* t_TempStr(const T_CHAR* psz)
{
	UNREFERENCED_PARAMETER(psz);
	return NULL;
}
template<>
inline XLOPER* t_TempStr<char, XLOPER>(LPCSTR psz)
{
	return TempStrConst((const LPSTR)psz);
}
template<>
inline XLOPER12* t_TempStr<wchar_t, XLOPER12>(LPCWSTR psz)
{
	return TempStr12(psz);
}

//----------------------------------------------------------------------
//	TempStrConst, TempStr12	(2)
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER>
T_XLOPER* t_TempStr_base(const T_CHAR* pStr, size_t zStr)
{
	T_XLOPER*		pxOper;
	const T_CHAR*	ps;
	const T_CHAR*	pe;
	T_CHAR*			pd;
	size_t			zStrByte	= 0;

	zStrByte	= sizeof(T_CHAR) * (zStr + 2);
	pxOper		= (T_XLOPER*)GetTempMemory(sizeof(T_XLOPER) + zStrByte);
	if (!pxOper)
	{
		return NULL;
	}

	pd = (T_CHAR*)((char*)pxOper + sizeof(T_XLOPER));
	pxOper->val.str	= pd;
	pxOper->xltype	= xltypeStr;

	*pd	= (T_CHAR)zStr;
	++pd;
	pe	= pStr + zStr;
	for (ps = pStr; ps < pe; ++ps, ++pd)
	{
		*pd	= *ps;
	}
	*pd	= (T_CHAR)0;

	return pxOper;
}

template<typename T_CHAR, typename T_XLOPER>
inline T_XLOPER* t_TempStr(const T_CHAR* pstr, size_t zstr)
{
	UNREFERENCED_PARAMETER(pstr);
	UNREFERENCED_PARAMETER(zstr);
	return NULL;
}
template<>
inline XLOPER* t_TempStr<char, XLOPER>(LPCSTR pstr, size_t zstr)
{
	return t_TempStr_base<char, XLOPER>(pstr, zstr);
}
template<>
inline XLOPER12* t_TempStr<wchar_t, XLOPER12>(LPCWSTR pstr, size_t zstr)
{
	return t_TempStr_base<wchar_t, XLOPER12>(pstr, zstr);
}

//----------------------------------------------------------------------
//	TempMissing, TempMissing12
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline T_XLOPER* t_TempMissing()
{
	return NULL;
}
template<>
inline XLOPER* t_TempMissing<XLOPER>()
{
	return TempMissing();
}
template<>
inline XLOPER12* t_TempMissing<XLOPER12>()
{
	return TempMissing12();
}


NS_XLL_BEGIN

NS_XLL_END
