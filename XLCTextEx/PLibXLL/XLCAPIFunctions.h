//	XLCTextEx_1.0x	:	PLibXLL

//	XLCAPIFunctions.h
//
#pragma once

NS_XLL_BEGIN

//======================================================================
//	xlFree
//======================================================================
template<typename T_XLOPER>
bool FreeXLOPER(T_XLOPER* px)
{
	int	ir;

	ir	= t_Excel<T_XLOPER, FALSE>(xlFree, NULL, px);
	return (ir == xlretSuccess);
}


//======================================================================
//	xlSheetId
//======================================================================
BOOL GetActiveSheetId(DWORD* pdwId);

NS_XLL_END
