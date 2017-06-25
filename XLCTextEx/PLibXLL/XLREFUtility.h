//	XLCTextEx_1.0x	:	PLibXLL

//	XLOPERUtility.h
//
#pragma once

NS_XLL_BEGIN

//======================================================================
//	SetXLREF
//======================================================================
//----------------------------------------------------------------------
//	t_SetXLREF
//----------------------------------------------------------------------
template<typename T_XLREF, typename T_ROW, typename T_COL, typename T_NUM>
inline void t_SetXLREF(T_XLREF* pxRef, T_NUM nRowF, T_NUM nRowL, T_NUM nColF, T_NUM nColL)
{
	pxRef->rwFirst	= (T_ROW)nRowF;
	pxRef->rwLast	= (T_ROW)nRowL;
	pxRef->colFirst	= (T_COL)nColF;
	pxRef->colLast	= (T_COL)nColL;
}

//----------------------------------------------------------------------
//	SetXLREF	（double 用）
//----------------------------------------------------------------------
template<typename T_XLREF>
inline bool SetXLREF(T_XLREF* pxRef, double dRowF, double dRowL, double dColF, double dColL)
{
	THROWPE_LOGIC_ERROR("SetXLREF");
	return false;
}
template<>
inline bool SetXLREF<XLREF>(XLREF* pxRef, double dRowF, double dRowL, double dColF, double dColL)
{
	t_SetXLREF<XLREF, WORD, BYTE, double>(pxRef, dRowF, dRowL, dColF, dColL);
	return true;
}
template<>
inline bool SetXLREF<XLREF12>(XLREF12* pxRef, double dRowF, double dRowL, double dColF, double dColL)
{
	t_SetXLREF<XLREF12, RW, COL, double>(pxRef, dRowF, dRowL, dColF, dColL);
	return true;
}

//======================================================================
//	AllocateXLMREF
//======================================================================
template<typename T_XLMREF, typename T_XLREF, WORD W_COUNT>
inline T_XLMREF* AllocateXLMREF()
{
	struct ALLOCMREF
	{
		WORD	count;
		T_XLREF	reftb[W_COUNT];
	};
	ALLOCMREF*	pmr;

	pmr	= new ALLOCMREF[1];
	pmr->count	= W_COUNT;
	return (T_XLMREF*)pmr;
}

//======================================================================
//	CreateXLOPER_Ref
//======================================================================
//----------------------------------------------------------------------
//	t_CreateXLOPER_Ref
//----------------------------------------------------------------------
template<typename T_XLOPER, typename T_XLMREF, typename T_XLREF, WORD W_COUNT>
bool t_CreateXLOPER_Ref(T_XLOPER* pxRef)
{
	//	シート ID を取得する。
	if (t_Excel<T_XLOPER>(xlSheetId, pxRef) != xlretSuccess)	return false;

	pxRef->val.mref.lpmref	= AllocateXLMREF<T_XLMREF, T_XLREF, W_COUNT>();
	return (pxRef->val.mref.lpmref != NULL);
}

//----------------------------------------------------------------------
//	XLOPER 用
//----------------------------------------------------------------------
template<WORD W_COUNT>
inline bool CreateXLOPER_Ref(XLOPER* pxRef)
{
	return t_CreateXLOPER_Ref<XLOPER, XLMREF, XLREF, W_COUNT>(pxRef);
}

//----------------------------------------------------------------------
//	XLOPER12 用
//----------------------------------------------------------------------
template<WORD W_COUNT>
inline bool CreateXLOPER_Ref(XLOPER12* pxRef)
{
	return t_CreateXLOPER_Ref<XLOPER12, XLMREF12, XLREF12, W_COUNT>(pxRef);
}

//======================================================================
//	SetXLOPER_Ref
//======================================================================
//----------------------------------------------------------------------
//	XLOPER 用
//----------------------------------------------------------------------
template<typename T_NUM>
inline bool SetXLOPER_Ref(XLOPER* pxRef, WORD wNum,T_NUM nRowF, T_NUM nRowL, T_NUM nColF, T_NUM nColL)
{
	if (pxRef == NULL || pxRef->xltype != xltypeRef)	return false;
	if (pxRef->val.mref.lpmref == NULL)	return false;
	if (pxRef->val.mref.lpmref->count < wNum)	return false;

	t_SetXLREF<XLREF, WORD, BYTE, T_NUM>(
		&(pxRef->val.mref.lpmref->reftbl[wNum]), nRowF, nRowL, nColF, nColL);
	return true;
}

//----------------------------------------------------------------------
//	XLOPER12 用
//----------------------------------------------------------------------
template<typename T_NUM>
inline bool SetXLOPER_Ref(XLOPER12* pxRef, WORD wNum,T_NUM nRowF, T_NUM nRowL, T_NUM nColF, T_NUM nColL)
{
	if (pxRef == NULL || pxRef->xltype != xltypeRef)	return false;
	if (pxRef->val.mref.lpmref == NULL)	return false;
	if (pxRef->val.mref.lpmref->count < wNum)	return false;

	t_SetXLREF<XLREF12, RW, COL, T_NUM>(
		&(pxRef->val.mref.lpmref->reftbl[wNum]), nRowF, nRowL, nColF, nColL);
	return true;
}

NS_XLL_END
