//	XLCTextEx_1.0x	:	PLibXLL

//	XLOPERUtility.h
//
#pragma once

NS_XLL_BEGIN

//======================================================================
//	GetXLOPER_Multi
//======================================================================
//----------------------------------------------------------------------
//	t_GetXLOPER_Multi
//----------------------------------------------------------------------
template<typename T_XLOPER, typename T_ROW, typename T_COL>
BOOL t_GetXLOPER_Multi(T_XLOPER** ppxElement, T_XLOPER* pxMulti, T_ROW iRow, T_COL iCol)
{
	if (pxMulti->xltype != xltypeMulti)	return FALSE;
	if (iRow < 0 || iRow >= pxMulti->val.array.rows)	return FALSE;
	if (iCol < 0 || iCol >= pxMulti->val.array.columns)	return FALSE;
	*ppxElement = pxMulti->val.array.lparray + iRow * pxMulti->val.array.columns + iCol;
	return TRUE;
}

//----------------------------------------------------------------------
//	GetXLOPER_Multi
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline BOOL GetXLOPER_Multi(T_XLOPER** ppxElement, T_XLOPER* pxMulti, int iRow, int iCol)
{
	THROWPE_LOGIC_ERROR("GetXLOPER_Multi");
	return FALSE;
}
template<>
inline BOOL GetXLOPER_Multi<XLOPER>(XLOPER** ppxElement, XLOPER* pxMulti, int iRow, int iCol)
{
	return t_GetXLOPER_Multi<XLOPER, WORD, WORD>(ppxElement, pxMulti, iRow, iCol);
}
template<>
inline BOOL GetXLOPER_Multi<XLOPER12>(XLOPER12** ppxElement, XLOPER12* pxMulti, int iRow, int iCol)
{
	return t_GetXLOPER_Multi<XLOPER12, RW, COL>(ppxElement, pxMulti, iRow, iCol);
}

//======================================================================
//	GetXLOPER_Multi_Row
//======================================================================
template<typename T_CHAR, typename T_XLOPER>
bool GetXLOPER_Multi_Row(std::basic_string<T_CHAR>* pstrBuffer, T_XLOPER* pxMultiT, UINT uiIndex)
{
	XLOPER*	pxMulti;
	XLOPER*	pxCell, pxEnd;
	UINT	uiRows, uiCols;

	if (pxMulti == NULL || pxMulti->xltype != xltypeMulti)	return false;
	uiRows	= (UINT)(pxMulti->val.array.rows);
	uiCols	= (UINT)(pxMulti->val.array.columns);
	if (uiRows == 0 || uiCols == 0)	return false;
	if (uiRows < uiIndex)	return false;

	pxCell	= pxMulti->val.array.lparray + (uiIndex * uiCols);
	pxEnd	= pxCell + uiCols;
}

NS_XLL_END
