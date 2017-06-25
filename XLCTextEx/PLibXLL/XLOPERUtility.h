//	XLCTextEx_1.0x	:	PLibXLL

//	XLOPERUtility.h
//
#pragma once

NS_XLL_BEGIN

//======================================================================
//	XLL で使用する定数
//======================================================================
//----------------------------------------------------------------------
//	XLL::MaxStrSize()
//----------------------------------------------------------------------
template<typename T>()
inline size_t MaxStrSize()
{
	return (size_t)MAX_XL4_STR_LEN;
}
template<>
inline size_t MaxStrSize<wchar_t>()
{
	return (size_t)MAX_XL12_STR_LEN;
}
template<>
inline size_t MaxStrSize<XLOPER12>()
{
	return (size_t)MAX_XL12_STR_LEN;
}


//======================================================================
//	CreateXLOPER
//======================================================================
template<typename T_XLOPER>
BOOL CreateXLOPER(T_XLOPER** ppxOper)
{
	PLib::PCMAlloc	ciMAlooc;
	return ciMalloc.Allocate<T_XLOPER>(ppxOper);
}

template<typename T_XLOPER>
BOOL CreateXLOPERTemp(T_XLOPER** ppxOper)
{
	PLib::PCMAllocTemp	ciMAlooc;
	return ciMalloc.Allocate<T_XLOPER>(ppxOper);
}


//======================================================================
//	CopyXLOPER
//	XLOPER を内容も含めてコピーする。
//	ただし、フラグはコピーしないので、必要なら呼び出し側で設定すること。
//	pxDst の処理は呼び出し側で行っておくこと。
//======================================================================
//----------------------------------------------------------------------
//	t_CopyXLOPER
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER>
bool t_CopyXLOPER(T_XLOPER* pxDst, T_XLOPER* pxSrc)
{
	typedef	T_CHAR*			T_PSTR;
	typedef	const T_CHAR*	T_PCSTR;

	PLib::PCMAlloc	ciMAlloc;
	DWORD			dwType;
	size_t			zStr;
	T_PCSTR			ps;
	T_PSTR			pd, pe;

	dwType	= (DWORD)(pxSrc->xltype);
	dwType	&=	~xlbitXLFree;
	dwType	&=	~xlbitDLLFree;

	switch (dwType)
	{
	case (DWORD)xltypeNum:
		pxDst->xltype	= xltypeNum;
		pxDst->val.num	= pxSrc->val.num;
		break;

	case (DWORD)xltypeStr:
		pxDst->xltype	= xltypeStr;
		zStr	= XLL::GetStringSize<T_CHAR>(pxSrc->val.str);
		pxDst->val.str	= ciMAlloc.Allocate<T_CHAR>(zStr + 2);
		*pxDst->val.str	= *(pxSrc->val.str);
		pd	= pxDst->val.str + 1;
		pe	= pd + zStr;
		ps	= pxSrc->val.str + 1;
		while (pd < pe)
		{
			*pd	= *ps;
			++ps;
			++pd;
		}
		*pe	= (T_CHAR)0;
		break;

	case (DWORD)xltypeBool:
		pxDst->xltype		= xltypeBool;
		pxDst->val.xbool	= pxSrc->val.xbool;
		break;

	case (DWORD)xltypeInt:
		pxDst->xltype	= xltypeInt;
		pxDst->val.w	= pxSrc->val.w;

	case (DWORD)xltypeMissing:
		pxDst->xltype	= xltypeMissing;
		break;

	case (DWORD)xltypeNil:
		pxDst->xltype	= xltypeNil;
		break;

	case (DWORD)xltypeErr:
		pxDst->xltype	= xltypeErr;
		pxDst->val.err	= pxSrc->val.err;
		break;

	case (DWORD)xltypeRef:
	case (DWORD)xltypeFlow:
	case (DWORD)xltypeMulti:
	case (DWORD)xltypeSRef:
	default:
		pxDst->xltype	= xltypeErr;
		pxDst->val.err	= xlerrValue;
		//throw std::logic_error("CopyXLOPER: not implemented.");
		break;
	}
	return true;
}

//----------------------------------------------------------------------
//	CopyXLOPER
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline bool CopyXLOPER(T_XLOPER* pxDst, T_XLOPER* pxSrc)
{
	throw std::logic_error("CopyXLOPER");
	return FALSE;
}
template<>
inline bool CopyXLOPER<XLOPER>(LPXLOPER pxDst, LPXLOPER pxSrc)
{
	return t_CopyXLOPER<char, XLOPER>(pxDst, pxSrc);
}
template<>
inline bool CopyXLOPER<XLOPER12>(LPXLOPER12 pxDst, LPXLOPER12 pxSrc)
{
	return t_CopyXLOPER<wchar_t, XLOPER12>(pxDst, pxSrc);
}

//======================================================================
//	DeleteXLOPER
//	xltype を調べ、必要なら内容を Delete で解放する。
//	xltypeMulti の場合、val.array.lparray は delete[] で削除する。
//======================================================================
//----------------------------------------------------------------------
//	t_DeleteXLOPER
//----------------------------------------------------------------------
template<typename T_XLOPER>
BOOL t_DeleteXLOPER(T_XLOPER* pxOper)
{
	T_XLOPER*	pxTemp;
	size_t		zIndex, zSize;

	if (pxOper == NULL)	return FALSE;

	switch (pxOper->xltype)
	{
	case xltypeStr:
	case xltypeStr | xlbitXLFree:
	case xltypeStr | xlbitDLLFree:
		delete[]	pxOper->val.str;
		break;

	case xltypeMulti:
	case xltypeMulti | xlbitXLFree:
	case xltypeMulti | xlbitDLLFree:
		zSize	= (pxOper->val.array.rows) * (pxOper->val.array.columns);
		pxTemp	= pxOper->val.array.lparray;
		for (zIndex = 0; zIndex < zSize; ++zIndex, ++pxTemp)
		{
			t_DeleteXLOPER<T_XLOPER>(pxTemp);
		}
		delete[]	pxOper->val.array.lparray;
		break;

	case xltypeRef:
	case xltypeRef | xlbitXLFree:
	case xltypeRef | xlbitDLLFree:
		delete[]	(pxOper->val.mref.lpmref);
		break;

	//case xltypeNum:
	//case xltypeBool:
	//case xltypeErr:
	//case xltypeFlow:
	//case xltypeMissing:
	//case xltypeNil:
	//case xltypeSRef:
	//case xltypeInt:
	default:
		break;
	}
	pxOper->xltype	= xltypeNil;

	return TRUE;
}

//----------------------------------------------------------------------
//	DeleteXLOPER
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline BOOL DeleteXLOPER(T_XLOPER* pxOper)
{
	throw std::logic_error("DeleteXLOPER");
	return FALSE;
}
template<>
inline BOOL DeleteXLOPER<XLOPER>(LPXLOPER pxOper)
{
	return t_DeleteXLOPER<XLOPER>(pxOper);
}
template<>
inline BOOL DeleteXLOPER<XLOPER12>(LPXLOPER12 pxOper)
{
	return t_DeleteXLOPER<XLOPER12>(pxOper);
}

//======================================================================
//	FreeXLOPER
//======================================================================
/*
template<typename T_XLOPER>
inline void FreeXLOPER(T_XLOPER* pxFree)
{
	t_Excel<T_XLOPER, false>(xlFree, NULL, pxFree);
	pxFree->xltype	= xltypeNil;
}
*/

//======================================================================
//	SetDLLFree
//	xlbitDLLFree ビットをセットする。
//	引数チェックは行わないので、確認してから使用すること。
//======================================================================
inline void SetDLLFree(XLOPER* pxOper)
{
	pxOper->xltype	|= xlbitDLLFree;
}

inline void SetDLLFree(XLOPER12* pxOper)
{
	pxOper->xltype	|= xlbitDLLFree;
}

//======================================================================
//	xltypeNum タイプの XLOPER の処理
//======================================================================
//----------------------------------------------------------------------
//	SetXLOPER_Num
//	引数チェックは行わないので、確認してから使用すること。
//----------------------------------------------------------------------
template<typename T_XLOPER>
T_XLOPER* SetXLOPER_Num(T_XLOPER* pxOper, double dNum, BOOL bDllFree)
{
	pxOper->xltype	= xltypeNum;
	pxOper->val.num	= dNum;
	if (bDllFree)	SetDLLFree(pxOper);
	return pxOper;
}


//======================================================================
//	xltypeStr タイプの XLOPER の処理
//	(1)	ユーティリティ
//======================================================================
//----------------------------------------------------------------------
//	GetXLOPER_StrSize	文字列長を取得する（size_t 型）。
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline size_t GetXLOPER_StrSize(T_XLOPER* pxOper)
{
	THROWPE_LOGIC_ERROR("GetXLOPER_StrSize");
	return FALSE;
}
template<>
inline size_t GetXLOPER_StrSize<XLOPER>(XLOPER* pxOper)
{
	if (pxOper != NULL && pxOper->xltype == xltypeStr)
	{
		return (size_t)(unsigned char)*(pxOper->val.str);
	}
	return 0;
}
template<>
inline size_t GetXLOPER_StrSize<XLOPER12>(XLOPER12* pxOper)
{
	if (pxOper != NULL && (pxOper->xltype & 0xFFF) == xltypeStr)
	{
		return (size_t)*(pxOper->val.str);
	}
	return 0;
}

//======================================================================
//	xltypeStr タイプの XLOPER の処理
//	(2-1)	文字列をセットする。（開始点と長さを指定）
//======================================================================
//----------------------------------------------------------------------
//	t_SetXLOPER_Str	(2-1)
//	引数チェックは行わないので、確認してから使用すること。
//	エラーがあった場合は例外をスローする。呼び出し側で処理すること。
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER, class C_MALLOC>
BOOL t_SetXLOPER_Str(T_XLOPER*		pxOper,
					 const T_CHAR*	pStr,
					 size_t			zStr,
					 BOOL			bDllFree,
					 size_t			zMaxSize)
{
	if (!t_XLStrCopyMa<T_CHAR, C_MALLOC>(&(pxOper->val.str), pStr, zStr, zMaxSize))
		return FALSE;
	pxOper->xltype	= xltypeStr;
	if (bDllFree)	SetDLLFree(pxOper);
	return TRUE;
}

//----------------------------------------------------------------------
//	SetXLOPER_Str	(2-1)
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER>
inline BOOL SetXLOPER_Str(T_XLOPER* pxOper, const T_CHAR* pStr, size_t zStr, BOOL bDllFree)
{
	THROWPE_LOGIC_ERROR("XLL::SetXLOPER_Str");
	return FALSE;
}
template<>
inline BOOL SetXLOPER_Str<char, XLOPER>(XLOPER* pxOper, LPCSTR pStr, size_t zStr, BOOL bDllFree)
{
	return t_SetXLOPER_Str<char, XLOPER, PLib::PCMAlloc>(pxOper, pStr, zStr, bDllFree, 255);
}
template<>
inline BOOL SetXLOPER_Str<wchar_t, XLOPER12>(XLOPER12* pxOper, LPCWSTR pStr, size_t zStr, BOOL bDllFree)
{
	return t_SetXLOPER_Str<wchar_t, XLOPER12, PLib::PCMAlloc>(pxOper, pStr, zStr, bDllFree, 32767);
}

//----------------------------------------------------------------------
//	SetXLOPER_Str_Temp	(2-1)
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER>
inline BOOL SetXLOPER_Str_Temp(T_XLOPER* pxOper, const T_CHAR* pStr, size_t zStr, BOOL bDllFree)
{
	THROWPE_LOGIC_ERROR("XLL::SetXLOPER_Str");
	return FALSE;
}
template<>
inline BOOL SetXLOPER_Str_Temp<char, XLOPER>(XLOPER* pxOper, LPCSTR pStr, size_t zStr, BOOL bDllFree)
{
	return t_SetXLOPER_Str<char, XLOPER, PLib::PCMAllocTemp>(pxOper, pStr, zStr, bDllFree, 255);
}
template<>
inline BOOL SetXLOPER_Str_Temp<wchar_t, XLOPER12>(XLOPER12* pxOper, LPCWSTR pStr, size_t zStr, BOOL bDllFree)
{
	return t_SetXLOPER_Str<wchar_t, XLOPER12, PLib::PCMAllocTemp>(pxOper, pStr, zStr, bDllFree, 32767);
}


//======================================================================
//	xltypeStr タイプの XLOPER の処理
//	(2-2)	文字列をセットする。（NULL 終端文字列）
//======================================================================
/*
//----------------------------------------------------------------------
//	t_SetXLOPER_Str	(2-2)
//	引数チェックは行わないので、確認してから使用すること。
//	エラーがあった場合は例外をスローする。呼び出し側で処理すること。
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER, class C_MALLOC>
BOOL t_SetXLOPER_Str(T_XLOPER* pxOper, const T_CHAR* pszStr, BOOL bDllFree)
{
	typedef	T_CHAR*			T_PSTR;
	typedef	const T_CHAR*	T_PCSTR;

	C_MALLOC	ciMAlloc;
	T_PSTR		pm	= NULL;
	T_PSTR		pc, pe;
	T_PCSTR		pd;
	size_t		zStr	= 0;

	if (!PLib::t_StrLen<T_CHAR>(&zStr, pszStr))	return FALSE;

	pm	= ciMAlloc.Allocate<T_CHAR>(zStr + 1);
	pc	= pm;
	*pc	= (T_CHAR)zStr;
	++pc;
	pe	= pc + zStr;
	for (pd = pszStr; pc < pe; ++pc, ++pd)	*pc	= *pd;

	pxOper->xltype	= xltypeStr;
	pxOper->val.str	= pm;
	if (bDllFree)	SetDLLFree(pxOper);
	return TRUE;
}
*/

//----------------------------------------------------------------------
//	SetXLOPER_Str, SetXLOPER_Str_Temp	(2-2)
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER>
BOOL SetXLOPER_Str(T_XLOPER* pxOper, const T_CHAR* pStr, BOOL bDllFree)
{
	size_t	zSrc;

	if (PLib::t_StrLen<T_CHAR>(&zSrc, pStr))
	{
		return SetXLOPER_Str<T_CHAR, T_XLOPER>(pxOper, pStr, zSrc, bDllFree);
	}
	return FALSE;
}

template<typename T_CHAR, typename T_XLOPER>
BOOL SetXLOPER_Str_Temp(T_XLOPER* pxOper, const T_CHAR* pStr, BOOL bDllFree)
{
	size_t	zSrc;

	if (PLib::t_StrLen<T_CHAR>(&zSrc, pStr))
	{
		return SetXLOPER_Str_Temp<T_CHAR, T_XLOPER>(pxOper, pStr, zSrc, bDllFree);
	}
	return FALSE;
}


//======================================================================
//	xltypeStr タイプの XLOPER の処理	(3)
//
//	XLL タイプの文字列で XLOPER 構造体を設定する。
//======================================================================
//----------------------------------------------------------------------
//	SetXLOPER_XStr
//
//	XLL タイプの文字列はそのまま val.str に指定できるので、文字列の複製は行わない。
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER>
BOOL SetXLOPER_XStr(T_XLOPER* pxOper, const T_CHAR* pXStr, BOOL bDllFree)
{
	if (pxOper == NULL || pXStr == NULL)	return FALSE;

	pxOper->xltype	= xltypeStr;
	pxOper->val.str	= (T_CHAR*)pXStr;
	if (bDllFree)	SetDLLFree(pxOper);

	return TRUE;
}

//----------------------------------------------------------------------
//	SetXLOPER_CopyXStr
//
//	文字列を複製する。
//	メモリの割り当ては C_MALLOC の Allocate メソッドで行う。
//	引数チェックは行わないので、確認してから使用すること。
//	エラーがあった場合は例外をスローする。呼び出し側で処理すること。
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER, class C_MALLOC>
BOOL SetXLOPER_CopyXStr(T_XLOPER* pxOper, const T_CHAR* pXStr, BOOL bDllFree)
{
	typedef	T_CHAR*			T_PSTR;
	typedef	const T_CHAR*	T_PCSTR;

	C_MALLOC	ciMAlloc;
	T_PSTR		pm	= NULL;
	T_PSTR		pd, pe;
	T_PCSTR		ps;
	size_t		zStr	= 0;

	pm	= ciMAlloc.AllocateArray<T_CHAR>(zStr + 1);
	zStr	= (size_t)*pXStr;

	pe	= pm + zStr + 1;
	for (pd	= pm, ps = pXStr; pd < pe; ++pd, ++ps)	*pd	= *ps;

	pxOper->xltype	= xltypeStr;
	pxOper->val.str	= pm;
	if (bDllFree)	SetDLLFree(pxOper);
	return TRUE;

ERROR_HANDLING:
	ciMAlloc.Deallocate(pm);
	return FALSE;
}


//======================================================================
//	xltypeBool タイプの XLOPER の処理
//======================================================================
//----------------------------------------------------------------------
//	SetXLOPER_Bool
//	引数チェックは行わないので、確認してから使用すること。
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline T_XLOPER* SetXLOPER_Bool(T_XLOPER* pxOper, BOOL bBool, BOOL bDllFree)
{
	throw std::logic_error("SetXLOPER_Bool");
	return NULL;
}
template<>
inline XLOPER* SetXLOPER_Bool<XLOPER>(XLOPER* pxOper, BOOL bBool, BOOL bDllFree)
{
	pxOper->xltype		= xltypeBool;
	pxOper->val.xbool	= (WORD)bBool;
	if (bDllFree)	SetDLLFree(pxOper);
	return pxOper;
}
template<>
inline XLOPER12* SetXLOPER_Bool<XLOPER12>(XLOPER12* pxOper, BOOL bBool, BOOL bDllFree)
{
	pxOper->xltype		= xltypeBool;
	pxOper->val.xbool	= bBool;	//	val.xbool は bool ではなく BOOL
	if (bDllFree)	SetDLLFree(pxOper);
	return pxOper;
}


//======================================================================
//	xltypeRef タイプの XLOPER の処理
//======================================================================

//	XLREFUtility.h で定義する。

//======================================================================
//	xltypeErr タイプの XLOPER の処理
//======================================================================
//----------------------------------------------------------------------
//	SetXLOPER_Err
//	引数チェックは行わないので、確認してから使用すること。
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline T_XLOPER* SetXLOPER_Err(T_XLOPER* pxOper, int iErr, BOOL bDllFree)
{
	throw std::logic_error("SetXLOPER_Int");
	return NULL;
}
template<>
inline XLOPER* SetXLOPER_Err<XLOPER>(XLOPER* pxOper, int iErr, BOOL bDllFree)
{
	pxOper->xltype	= xltypeErr;
	pxOper->val.err	= (WORD)iErr;
	if (bDllFree)	SetDLLFree(pxOper);
	return pxOper;
}
template<>
inline XLOPER12* SetXLOPER_Err<XLOPER12>(XLOPER12* pxOper, int iErr, BOOL bDllFree)
{
	pxOper->xltype	= xltypeErr;
	pxOper->val.err	= iErr;
	if (bDllFree)	SetDLLFree(pxOper);
	return pxOper;
}


//======================================================================
//	xltypeFlow タイプの XLOPER の処理
//======================================================================

/*
//======================================================================
//	xltypeMulti タイプの XLOPER の処理
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
*/

//======================================================================
//	xltypeMissing タイプの XLOPER の処理
//======================================================================
//----------------------------------------------------------------------
//	SetXLOPER_Missing
//	引数チェックは行わないので、確認してから使用すること。
//----------------------------------------------------------------------
template<typename T_XLOPER>
T_XLOPER* SetXLOPER_Missing(T_XLOPER* pxOper, BOOL bDllFree)
{
	pxOper->xltype	= xltypeMissing;
	if (bDllFree)	SetDLLFree(pxOper);
	return pxOper;
}


//======================================================================
//	xltypeNil タイプの XLOPER の処理
//======================================================================
//----------------------------------------------------------------------
//	SetXLOPER_Nil
//	引数チェックは行わないので、確認してから使用すること。
//----------------------------------------------------------------------
template<typename T_XLOPER>
T_XLOPER* SetXLOPER_Nil(T_XLOPER* pxOper, BOOL bDllFree)
{
	pxOper->xltype	= xltypeNil;
	if (bDllFree)	SetDLLFree(pxOper);
	return pxOper;
}


//======================================================================
//	xltypeSRef タイプの XLOPER の処理
//======================================================================

//	XLREFUtility.h で定義する。

//======================================================================
//	xltypeInt タイプの XLOPER の処理
//======================================================================
//----------------------------------------------------------------------
//	SetXLOPER_Int
//	引数チェックは行わないので、確認してから使用すること。
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline T_XLOPER* SetXLOPER_Int(T_XLOPER* pxOper, int iw, BOOL bDllFree)
{
	throw std::logic_error("SetXLOPER_Int");
	return NULL;
}
template<>
inline XLOPER* SetXLOPER_Int<XLOPER>(XLOPER* pxOper, int iw, BOOL bDllFree)
{
	pxOper->xltype	= xltypeInt;
	pxOper->val.w	= (short int)iw;
	if (bDllFree)	SetDLLFree(pxOper);
	return pxOper;
}
template<>
inline XLOPER12* SetXLOPER_Int<XLOPER12>(XLOPER12* pxOper, int iw, BOOL bDllFree)
{
	pxOper->xltype	= xltypeInt;
	pxOper->val.w	= iw;
	if (bDllFree)	SetDLLFree(pxOper);
	return pxOper;
}


//======================================================================
//	その他
//======================================================================
//----------------------------------------------------------------------
//	SetVolatile
//----------------------------------------------------------------------
template<typename T_XLOPER>
BOOL SetVolatile(BOOL bVolatile)
{
	T_XLOPER	xVolatile, xRet;
	int			ir;

	if (!SetXLOPER_Bool<T_XLOPER>(&xVolatile, bVolatile))	return FALSE;
	ir	= t_Excel<T_XLOPER, FALSE>(xlfVolatile, &xRet, &xVolatile);
	if (ir == 0)
	{
		if (xRet.xltype == xltypeBool && xRet.val.xbool == TRUE)	return TRUE;
	}
	return FALSE;
}


//======================================================================
//	XLOPERConverter
//======================================================================
template<class C_MALLOC = PLib::PCMAlloc>
class XLOPERConverter
{
private:
	//------------------------------------------------------------
	//	データメンバ
	//------------------------------------------------------------
	C_MALLOC	ciMAlloc;

public:
	//------------------------------------------------------------
	//	ConvertStr
	//------------------------------------------------------------
	template<typename TX_DST, typename TX_SRC>
	BOOL ConvertStr(TX_DST* pxDst, TX_SRC* pxSrc)
	{
		THROWPE_LOGIC_ERROR("XLOPERConverter::ConvertStr");
		return FALSE;
	}
	template<>
	BOOL ConvertStr<XLOPER, XLOPER>(XLOPER* pxDst, XLOPER* pxSrc)
	{
		if (XLL::XLStrCopyMa<char, C_MALLOC>(&(pxDst->val.str), pxSrc->val.str))
		{
			pxDst->xltype	= xltypeStr;
			return TRUE;
		}
		pxDst->xltype	= xltypeNil;
		return FALSE;
	}
	template<>
	BOOL ConvertStr<XLOPER12, XLOPER>(XLOPER12* pxDst, XLOPER* pxSrc)
	{
		if (XLL::t_XLStrConvert4to12Ma<C_MALLOC>(&(pxDst->val.str), pxSrc->val.str))
		{
			pxDst->xltype	= xltypeStr;
			return TRUE;
		}
		pxDst->xltype	= xltypeNil;
		return FALSE;
	}
	template<>
	BOOL ConvertStr<XLOPER, XLOPER12>(XLOPER* pxDst, XLOPER12* pxSrc)
	{
		if (XLL::t_XLStrConvert12to4Ma<C_MALLOC>(&(pxDst->val.str), pxSrc->val.str))
		{
			pxDst->xltype	= xltypeStr;
			return TRUE;
		}
		pxDst->xltype	= xltypeNil;
		return FALSE;
	}
	template<>
	BOOL ConvertStr<XLOPER12, XLOPER12>(XLOPER12* pxDst, XLOPER12* pxSrc)
	{
		if (XLL::XLStrCopyMa<wchar_t, C_MALLOC>(&(pxDst->val.str), pxSrc->val.str))
		{
			pxDst->xltype	= xltypeStr;
			return TRUE;
		}
		pxDst->xltype	= xltypeNil;
		return FALSE;
	}

	//------------------------------------------------------------
	//	ConvertBool
	//------------------------------------------------------------
	template<typename TX_DST, typename TX_SRC>
	BOOL ConvertBool(TX_DST* pxDst, TX_SRC* pxSrc)
	{
		THROWPE_LOGIC_ERROR("XLOPERConverter::ConvertBool");
		return FALSE;
	}
	template<>
	BOOL ConvertBool<XLOPER, XLOPER>(XLOPER* pxDst, XLOPER* pxSrc)
	{
		pxDst->val.xbool	= pxSrc->val.xbool;
		pxDst->xltype		= xltypeBool;
		return TRUE;
	}
	template<>
	BOOL ConvertBool<XLOPER12, XLOPER>(XLOPER12* pxDst, XLOPER* pxSrc)
	{
		pxDst->val.xbool	= (BOOL)pxSrc->val.xbool;
		pxDst->xltype		= xltypeBool;
		return TRUE;
	}
	template<>
	BOOL ConvertBool<XLOPER, XLOPER12>(XLOPER* pxDst, XLOPER12* pxSrc)
	{
		pxDst->val.xbool	= (WORD)pxSrc->val.xbool;
		pxDst->xltype		= xltypeBool;
		return TRUE;
	}
	template<>
	BOOL ConvertBool<XLOPER12, XLOPER12>(XLOPER12* pxDst, XLOPER12* pxSrc)
	{
		pxDst->val.xbool	= pxSrc->val.xbool;
		pxDst->xltype		= xltypeBool;
		return TRUE;
	}

	//------------------------------------------------------------
	//	ConvertErr
	//------------------------------------------------------------
	template<typename TX_DST, typename TX_SRC>
	BOOL ConvertErr(TX_DST* pxDst, TX_SRC* pxSrc)
	{
		THROWPE_LOGIC_ERROR("XLOPERConverter::ConvertErr");
		return FALSE;
	}
	template<>
	BOOL ConvertErr<XLOPER, XLOPER>(XLOPER* pxDst, XLOPER* pxSrc)
	{
		pxDst->val.err	= pxSrc->val.err;
		pxDst->xltype	= xltypeErr;
		return TRUE;
	}
	template<>
	BOOL ConvertErr<XLOPER12, XLOPER>(XLOPER12* pxDst, XLOPER* pxSrc)
	{
		pxDst->val.err	= (int)pxSrc->val.err;
		pxDst->xltype	= xltypeErr;
		return TRUE;
	}
	template<>
	BOOL ConvertErr<XLOPER, XLOPER12>(XLOPER* pxDst, XLOPER12* pxSrc)
	{
		pxDst->val.err	= (WORD)pxSrc->val.err;
		pxDst->xltype	= xltypeErr;
		return TRUE;
	}
	template<>
	BOOL ConvertErr<XLOPER12, XLOPER12>(XLOPER12* pxDst, XLOPER12* pxSrc)
	{
		pxDst->val.err	= pxSrc->val.err;
		pxDst->xltype	= xltypeErr;
		return TRUE;
	}

	//------------------------------------------------------------
	//	ConvertInt
	//------------------------------------------------------------
	template<typename TX_DST, typename TX_SRC>
	BOOL ConvertInt(TX_DST* pxDst, TX_SRC* pxSrc)
	{
		THROWPE_LOGIC_ERROR("XLOPERConverter::ConvertInt");
		return FALSE;
	}
	template<>
	BOOL ConvertInt<XLOPER, XLOPER>(XLOPER* pxDst, XLOPER* pxSrc)
	{
		pxDst->val.w	= pxSrc->val.w;
		pxDst->xltype	= xltypeInt;
		return TRUE;
	}
	template<>
	BOOL ConvertInt<XLOPER12, XLOPER>(XLOPER12* pxDst, XLOPER* pxSrc)
	{
		pxDst->val.w	= (int)pxSrc->val.w;
		pxDst->xltype	= xltypeInt;
		return TRUE;
	}
	template<>
	BOOL ConvertInt<XLOPER, XLOPER12>(XLOPER* pxDst, XLOPER12* pxSrc)
	{
		pxDst->val.w	= (short int)pxSrc->val.w;
		pxDst->xltype	= xltypeInt;
		return TRUE;
	}
	template<>
	BOOL ConvertInt<XLOPER12, XLOPER12>(XLOPER12* pxDst, XLOPER12* pxSrc)
	{
		pxDst->val.w	= pxSrc->val.w;
		pxDst->xltype	= xltypeInt;
		return TRUE;
	}

	//------------------------------------------------------------
	//	Convert
	//------------------------------------------------------------
	template<typename TX_DST, typename TX_SRC>
	BOOL Convert(TX_DST* pxDst, TX_SRC* pxSrc)
	{
		if (pxDst == NULL || pxSrc == NULL)	return FALSE;
		DeleteXLOPER<TX_DST>(pxDst);

		switch (pxSrc->xltype)
		{
		case xltypeNum:
		case xltypeNum | xlbitXLFree:
		case xltypeNum | xlbitDLLFree:
			pxDst->val.num	= pxSrc->val.num;
			pxDst->xltype	= xltypeNum;
			return TRUE;
			break;

		case xltypeStr:
		case xltypeStr | xlbitXLFree:
		case xltypeStr | xlbitDLLFree:
			return ConvertStr<TX_DST, TX_SRC>(pxDst, pxSrc);
			break;

		case xltypeBool:
		case xltypeBool | xlbitXLFree:
		case xltypeBool | xlbitDLLFree:
			return ConvertBool<TX_DST, TX_SRC>(pxDst, pxSrc);
			break;

		case xltypeRef:
		case xltypeRef | xlbitXLFree:
		case xltypeRef | xlbitDLLFree:
			//THROWPE_LOGIC_ERROR("XLOPERConverter::Convert xltypeRef not implemented.");
			break;

		case xltypeErr:
		case xltypeErr | xlbitXLFree:
		case xltypeErr | xlbitDLLFree:
			return ConvertErr<TX_DST, TX_SRC>(pxDst, pxSrc);
			break;

		case xltypeFlow:
		case xltypeFlow | xlbitXLFree:
		case xltypeFlow | xlbitDLLFree:
			//THROWPE_LOGIC_ERROR("XLOPERConverter::Convert xltypeFlow not implemented.");
			break;

		case xltypeMulti:
		case xltypeMulti | xlbitXLFree:
		case xltypeMulti | xlbitDLLFree:
			//THROWPE_LOGIC_ERROR("XLOPERConverter::Convert xltypeMulti not implemented.");
			break;

		case xltypeMissing:
		case xltypeMissing | xlbitXLFree:
		case xltypeMissing | xlbitDLLFree:
			pxDst->xltype	= xltypeMissing;
			return TRUE;
			break;

		case xltypeNil:
		case xltypeNil | xlbitXLFree:
		case xltypeNil | xlbitDLLFree:
			pxDst->xltype	= xltypeNil;
			return TRUE;
			break;

		case xltypeSRef:
		case xltypeSRef | xlbitXLFree:
		case xltypeSRef | xlbitDLLFree:
			break;

		case xltypeInt:
		case xltypeInt | xlbitXLFree:
		case xltypeInt | xlbitDLLFree:
			return ConvertInt<TX_DST, TX_SRC>(pxDst, pxSrc);
			break;

		default:
			break;
		}
		return FALSE;
	}
};


NS_XLL_END
