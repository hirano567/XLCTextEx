//	XLCTextEx_1.0x	:	PLibXLL

//	XLLUtility.h
//
#pragma once

NS_XLL_BEGIN

//======================================================================
//	xlCoerce
//======================================================================
//----------------------------------------------------------------------
//	CoerceToString
//----------------------------------------------------------------------
template<typename T_XLOPER, typename T_XLMREF>
bool CoerceToString(T_XLOPER* pxRet, UINT uiRow, UINT uiCol)
{
	T_XLOPER	xSrc, xType;
	T_XLMREF	xmr;

	if (t_Excel<T_XLOPER>(xlSheetId, &xSrc) != xlretSuccess)	return false;

	xSrc.xltype					= xltypeRef;
	xSrc.val.mref.lpmref		= &xmr;
	xSrc.val.mref.lpmref->count	= 1;

	xSrc.val.mref.lpmref->reftbl[0].rwFirst		= uiRow;
	xSrc.val.mref.lpmref->reftbl[0].rwLast		= uiRow;
	xSrc.val.mref.lpmref->reftbl[0].colFirst	= uiCol;
	xSrc.val.mref.lpmref->reftbl[0].colLast		= uiCol;

	xType.xltype	= xltypeInt;
	xType.val.w		= xltypeStr;

	ir	= XLL::t_Excel<T_XLOPER>(xlCoerce, pxRet, &xSrc, &xType);
}

//======================================================================
//	xlfGetDocument
//======================================================================
//----------------------------------------------------------------------
//	GetUsedRegion	(1)	行、列の範囲を求める
//----------------------------------------------------------------------
template<typename T_XLOPER>
bool GetUsedRegion(double* pdRowF, double* pdRowL, double* pdColF, double* pdColL)
{
	T_XLOPER	xRet, xNum;
	int			ir;

	xNum.xltype		= xltypeNum;

	xNum.val.num	= 9;
	ir	= t_Excel<T_XLOPER, false>(xlfGetDocument, &xRet, &xNum);
	if (ir != xlretSuccess)	return false;
	if (xRet.val.num <= 0)	goto EMPTY_WORKSHEET;
	*pdRowF	= xRet.val.num;

	xNum.val.num	= 10;
	ir	= t_Excel<T_XLOPER, false>(xlfGetDocument, &xRet, &xNum);
	if (ir != xlretSuccess)	return false;
	if (xRet.val.num <= 0)	goto EMPTY_WORKSHEET;
	*pdRowL	= xRet.val.num;

	xNum.val.num	= 11;
	ir	= t_Excel<T_XLOPER, false>(xlfGetDocument, &xRet, &xNum);
	if (ir != xlretSuccess)	return false;
	if (xRet.val.num <= 0)	goto EMPTY_WORKSHEET;
	*pdColF	= xRet.val.num;

	xNum.val.num	= 12;
	ir	= t_Excel<T_XLOPER, false>(xlfGetDocument, &xRet, &xNum);
	if (ir != xlretSuccess)	return false;
	if (xRet.val.num <= 0)	goto EMPTY_WORKSHEET;
	*pdColL	= xRet.val.num;
	return true;

EMPTY_WORKSHEET:
	*pdRowF	= 0;
	*pdRowL	= 0;
	*pdColF	= 0;
	*pdColL	= 0;
	return true;
}

//----------------------------------------------------------------------
//	GetUsedRegion	(2)	XLOPER に xltypeRef 型のデータとして格納する。
//----------------------------------------------------------------------
template<typename T_XLOPER, typename T_XLMREF, typename T_XLREF, typename T_ROW, typename T_COL>
bool t_GetUsedRegion(T_XLOPER* pxRef)
{
	double dRowF, dRowL, dColF, dColL;

	if (!GetUsedRegion<T_XLOPER>(&dRowF, &dRowL, &dColF, &dColL))	return false;

	//	未使用のシートの場合は Nil を返すことにする。
	if (dRowF == 0)
	{
		pxRef->xltype	= xltypeNil;
		return true;
	}

	//	xltypeRef 型にセットする。
	if (!XLL::t_CreateXLOPER_Ref<T_XLOPER, T_XLMREF, T_XLREF, 1>(pxRef))	return false;

	//	範囲をセットする。
	pxRef->val.mref.lpmref->reftbl[0].rwFirst	= (T_ROW)dRowF;
	pxRef->val.mref.lpmref->reftbl[0].rwLast	= (T_ROW)dRowL;
	pxRef->val.mref.lpmref->reftbl[0].colFirst	= (T_COL)dColF;
	pxRef->val.mref.lpmref->reftbl[0].colLast	= (T_COL)dColL;

	return true;
}

template<typename T_XLOPER>
inline bool GetUsedRegion(T_XLOPER* pxRef)
{
	THROWPE_LOGIC_ERROR("GetUsedRegion (2)");
	return false;
}
template<>
inline bool GetUsedRegion<XLOPER>(XLOPER* pxRef)
{
	return t_GetUsedRegion<XLOPER, XLMREF, XLREF, WORD, BYTE>(pxRef);
}
template<>
inline bool GetUsedRegion<XLOPER12>(XLOPER12* pxRef)
{
	return t_GetUsedRegion<XLOPER12, XLMREF12, XLREF12, RW, COL>(pxRef);
}

//----------------------------------------------------------------------
//	GetActiveSheetName	アクティブなブックとシートの名前を求める
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER>
bool t_GetActiveSheetName(std::basic_string<T_CHAR>* pstrName)
{
	T_XLOPER	xRet, xNum;
	int			ir;
	size_t		zs;

	xNum.xltype		= xltypeNum;
	xNum.val.num	= 76;
	xRet.xltype		= xltypeNil;

	ir	= t_Excel<T_XLOPER, false>(xlfGetDocument, &xRet, &xNum);
	if (ir != xlretSuccess || xRet.xltype != xltypeStr)	goto ERROR_HANDLING;
	zs	= GetStringSize<T_CHAR>(xRet.val.str);
	if (zs < 1)	goto ERROR_HANDLING;
	pstrName->append(xRet.val.str + 1, zs);
	XLL::FreeXLOPER<T_XLOPER>(&xRet);
	return true;

ERROR_HANDLING:
	XLL::FreeXLOPER<T_XLOPER>(&xRet);
	return false;
}

NS_XLL_END
