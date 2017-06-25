//	XLCTextEx_1.0x	:	PLibXLL

//	XLLRegister.h
//
#pragma once


//======================================================================
//	XLL ä÷êîÇÃìoò^Ç∆ìoò^âèú
//======================================================================
//----------------------------------------------------------------------
//	t_RegisterFunctions_base
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER, int ITEMS_MAX, typename T_XLL_STRING>
BOOL t_RegisterFunctions_base(PCSTRAW* pFunctions, int iFunctions, int iParams)
{
	typedef	T_XLOPER*		T_PXLOPER;
	typedef	const T_CHAR*	T_PCSTR;

	T_PXLOPER	pxParams	= NULL;
	T_PXLOPER*	ppxParams	= NULL;
	T_PXLOPER	px;
	T_PXLOPER*	ppx;
	PCSTRAW*	pawFunctins;
	T_PCSTR		pszParam;
	T_PCSTR		pxsXLLPath;

	T_XLOPER	xRet;
	int			iRet;
	int			i, j;

	if (pFunctions == NULL || iFunctions < 1 || iParams < 1)	return FALSE;
	if (iParams > ITEMS_MAX)	iParams	= ITEMS_MAX;
	pawFunctins	= pFunctions;

	//	à¯êîÇÃéQè∆å≥Ç∆Ç»ÇÈ XLOPER ÇÃîzóÒ
	pxParams	= (T_PXLOPER)GetTempMemory(TO_MULTIPLE_NUMBER(sizeof(T_XLOPER), 4) * (iParams + 1));
	if (pxParams == NULL)	goto ERROR_HANDLING;

	//	à¯êîÇ∆Ç»ÇÈ LPXLOPER ÇÃîzóÒ
	ppxParams	= (T_PXLOPER*)GetTempMemory(TO_MULTIPLE_NUMBER(sizeof(T_XLOPER*), 4) * (iParams + 1));
	if (pxParams == NULL)	goto ERROR_HANDLING;

	//	ppxParams Ç… pxParams ÇÃÉAÉhÉåÉXÇäiî[ÇµÇƒÇ®Ç≠ÅB
	px	= pxParams;
	ppx	= ppxParams;
	*ppx	= px;
	for (++ppx, ++px, i = 0; i < iParams; ++ppx, ++px, ++i)
	{
		*ppx	= px;
	}

	pxsXLLPath	= XLL::GetXLLPathXS<T_CHAR>();

	for (i = 0; i < iFunctions; ++i)
	{
		px		= pxParams;

		if (!XLL::SetXLOPER_XStr<T_CHAR, T_XLOPER>(px, pxsXLLPath, FALSE))	goto ERROR_HANDLING; 
		++px;

		for (j = 0; j < iParams; ++j)
		{
			pszParam	= t_Str<T_CHAR>(pawFunctins);
			if ((int)*pszParam == 0)
			{
				if (!XLL::SetXLOPER_Missing<T_XLOPER>(px, FALSE))	goto ERROR_HANDLING;
			}
			else
			{
				if (!XLL::SetXLOPER_Str_Temp<T_CHAR, T_XLOPER>(px, pszParam, FALSE))	goto ERROR_HANDLING;
			}
			++px;
			++pawFunctins;
		}

#ifdef	PDEBUG
		std::basic_string<T_CHAR>	strDebug;
		XLL::DebugXLOPERArray<T_CHAR, T_XLOPER>(&strDebug, iParams, pxParams);
#endif

//#define NOT_REGISTER
#if !defined(PDEBUG) || !defined(NOT_REGISTER)

		iRet	= t_Excelv<T_XLOPER>(xlfRegister, &xRet, iParams + 1, ppxParams);
		if (iRet != xlretSuccess)	goto ERROR_HANDLING;

#endif
	}

	FreeAllTempMemory();
	return TRUE;

ERROR_HANDLING:
	FreeAllTempMemory();
	return FALSE;
}

//----------------------------------------------------------------------
//	t_RegisterFunctions
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline BOOL t_RegisterFunctions(PCSTRAW* pFunctions, int iFunctions, int iParams)
{
	UNREFERENCED_PARAMETER(pFunctions);
	UNREFERENCED_PARAMETER(iFunctions);
	UNREFERENCED_PARAMETER(iParams);
	return FALSE;
}
template<>
inline BOOL t_RegisterFunctions<XLOPER>(PCSTRAW* pFunctions, int iFunctions, int iParams)
{
	return t_RegisterFunctions_base<char, XLOPER, 30, XLL_STRINGA_TEMP>(
		pFunctions, iFunctions, iParams);
}
template<>
inline BOOL t_RegisterFunctions<XLOPER12>(PCSTRAW* pFunctions, int iFunctions, int iParams)
{
	return t_RegisterFunctions_base<wchar_t, XLOPER12, 255, XLL_STRINGW_TEMP>(
		pFunctions, iFunctions, iParams);
}

//----------------------------------------------------------------------
//	t_UnRegisterFunctions_base
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER>
BOOL t_UnRegisterFunctions_base(PCSTRAW* pFunctions, int iFunctions, int iParams)
{
	const T_CHAR*	pName;
	T_XLOPER		xRet;
	int				i;
	int				iRet;

	for (i = 0; i < iFunctions; ++i)
	{
		pName	= t_Str<T_CHAR>((pFunctions + iParams * i + 2));
		iRet	= t_Excel<T_XLOPER, TRUE>(xlfSetName, &xRet, t_TempStr<T_CHAR, T_XLOPER>(pName));
		if (iRet != xlretSuccess)	return FALSE;
	}
	return TRUE;
}

//----------------------------------------------------------------------
//	t_UnRegisterFunctions
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline BOOL t_UnRegisterFunctions(PCSTRAW* pFunctions, int iFunctions, int iParams)
{
	UNREFERENCED_PARAMETER(pFunctions);
	UNREFERENCED_PARAMETER(iFunctions);
	UNREFERENCED_PARAMETER(iParams);
	return FALSE;
}
template<>
inline BOOL t_UnRegisterFunctions<XLOPER>(PCSTRAW* pFunctions, int iFunctions, int iParams)
{
	return t_UnRegisterFunctions_base<char, XLOPER>(pFunctions, iFunctions, iParams);
}
template<>
inline BOOL t_UnRegisterFunctions<XLOPER12>(PCSTRAW* pFunctions, int iFunctions, int iParams)
{
	return t_UnRegisterFunctions_base<wchar_t, XLOPER12>(pFunctions, iFunctions, iParams);
}
