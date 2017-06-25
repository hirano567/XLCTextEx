//	XLCTextEx_1.0x	:	PLibXLL

//	XLCAPIFunctions.cpp
//
#include "stdafx.h"

NS_XLL_BEGIN

//======================================================================
//	xlSheetId
//======================================================================
//----------------------------------------------------------------------
//	t_GetActiveSheetId
//----------------------------------------------------------------------
template<typename T_XLOPER>
BOOL t_GetActiveSheetId(DWORD* pdwId)
{
	T_XLOPER	xRes;
	int			ir;

	ir	= t_Excel<T_XLOPER>(xlSheetId, &xRes);
	if (pdwId == NULL || ir != xlretSuccess || xRes.xltype != xltypeRef)	return FALSE;
	*pdwId	= xRes.val.mref.idSheet;
	XLL::FreeXLOPER<T_XLOPER>(&xRes);
	return TRUE;
}

//----------------------------------------------------------------------
//	GetActiveSheetId
//----------------------------------------------------------------------
BOOL GetActiveSheetId(DWORD* pdwId)
{
	if (XLL::IsExcel12())
	{
		return t_GetActiveSheetId<XLOPER12>(pdwId);
	}
	return t_GetActiveSheetId<XLOPER>(pdwId);
}

NS_XLL_END
