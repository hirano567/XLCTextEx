//	XLCTextEx_1.0x	:	PLibXLL

//	XLLSystem.cpp
//
#include "stdafx.h"
NS_XLL_BEGIN

//======================================================================
//	各種の情報
//
//	Excel や XLL に関する情報は、特に理由がない限りここに集める。
//======================================================================
//----------------------------------------------------------------------
//	Excel に関する情報
//----------------------------------------------------------------------
//	Excel のバージョン
static PSVERSION	siExcelVersion;

//	Excel のインスタンスハンドル
HINSTANCE	hExcelInstance	= NULL;

//	Excel のウィンドウハンドル
HWND	hExcelWindow	= NULL;

//	Excel のウィンドウプロシージャ
WNDPROC pExcelWndProc	= NULL;

//	Excel のパス
XLL_DTSTRING	xdsExcelPath;
XLL_DTSTRING	xdsExcelDir;
XLL_DTSTRING	xdsExcelFile;

//----------------------------------------------------------------------
//	XLL に関する情報
//----------------------------------------------------------------------
//	XLL のバージョン
PSVERSION	siXLLVersion;

//	XLL のインスタンスハンドル
HINSTANCE	hXLLInstance	= NULL;

//	XLL のパス
XLL_DTSTRING	xdsXLLPath;
XLL_DTSTRING	xdsXLLDir;
XLL_DTSTRING	xdsXLLFile;


//----------------------------------------------------------------------
//	その他の情報
//----------------------------------------------------------------------
//	メニューやツールバーのタイトル。
PCSTRAW		awXLLTitle	= { TEXTAW("XLHttp") };	//	タイトルに使用する名前


//======================================================================
//	Excel の情報
//
//	バージョン情報の管理
//======================================================================
//----------------------------------------------------------------------
//	SetExcelVersion	(1)
//
//	Excel4 関数の結果を格納している XLOPER からバージョンを取得する。
//----------------------------------------------------------------------
BOOL SetExcelVersion(PSVERSION* pVersion, LPXLOPER pxOper)
{
	size_t	zLength;
	LPCSTR	pc, pe;
	int		vmajor	= 4;
	int		vminor	= 0;

	if (pxOper->xltype	!= xltypeStr)	return FALSE;

	zLength	= (size_t)(unsigned char)*(pxOper->val.str);
	pc	= pxOper->val.str + 1;
	pe	= pc + zLength;

	if (!PLib::t_StrToIntDec<char>(&vmajor, &pc, pe))
	{
		return FALSE;
	}
	if (pc < pe && *pc == '.')
	{
		++pc;
		if (!PLib::t_StrToIntDec<char>(&vminor, &pc, pe))
		{
			vminor	= 0;
		}
	}

	pVersion->Set(vmajor, vminor);
	return TRUE;
}

//----------------------------------------------------------------------
//	SetExcelVersion	(2)
//
//	上の関数を使用して Excel のバージョンを取得し、static 変数に格納しておく。
//----------------------------------------------------------------------
BOOL SetExcelVersion(PSVERSION* pVersion)
{
	XLOPER	xParam, xopVersion, xRet;
	int		iRet;
	BOOL	bRet;

	xParam.xltype	= xltypeInt;
	xParam.val.w	= 2;
	iRet	= Excel4(xlfGetWorkspace, &xopVersion, 1, &xParam);
	if (iRet > 0)
	{
		return FALSE;
	}

	bRet	= XLL::SetExcelVersion(pVersion, &xopVersion);
	//	Excel によって割り当てられたメモリを解放する。
	iRet	= Excel4(xlFree, &xRet, 1, &xopVersion);
	return bRet;
}

//----------------------------------------------------------------------
//	SetExcelVersion	(3)
//----------------------------------------------------------------------
BOOL SetExcelVersion()
{
#if defined(PDEBUG) && defined(FORCE_EXCEL4)

	siExcelVersion.Set(4, 0);
	return TRUE;

#else

	return SetExcelVersion(&siExcelVersion);

#endif
}


//----------------------------------------------------------------------
//	取得済みのバージョンを返す。
//----------------------------------------------------------------------
BOOL GetExcelVersion(int* pmajor, int* pminor)
{
	if (siExcelVersion.Major < 1)
	{
		if (!SetExcelVersion())
		{
			return FALSE;
		}
	}
	*pmajor	= siExcelVersion.Major;
	*pminor	= siExcelVersion.minor;
	return TRUE;
}

//----------------------------------------------------------------------
//	IsExcel12
//	Excel 2007 以降か。
//----------------------------------------------------------------------
BOOL IsExcel12()
{
#if defined(FORCE_EXCEL4) && defined(PDEBUG)
	return FALSE;
#else
	return (siExcelVersion.Major > 11);
#endif
}


//======================================================================
//	Excel のインスタンスハンドル
//======================================================================
//----------------------------------------------------------------------
//	SetExcelInstanceHandle
//----------------------------------------------------------------------
void SetExcelInstanceHandle()
{
	hExcelInstance	= GetModuleHandle(NULL);

#ifdef	PDEBUG
	TCHAR	szPath[MAX_PATH];
	DWORD	dw	= GetModuleFileName(hExcelInstance, szPath, MAX_PATH);
#endif
}

void SetExcelInstanceHandle(HINSTANCE hExcel)
{
	hExcelInstance	= hExcel;
}

//----------------------------------------------------------------------
//	GetExcelInstanceHandle
//----------------------------------------------------------------------
HINSTANCE GetExcelInstanceHandle()
{
	return hExcelInstance;
}


//======================================================================
//	GetExcelWindowHandle12
//	Excel のメインウィンドウのハンドルを取得する。（Excel12 版）
//======================================================================
BOOL GetExcelWindowHandle12(HWND* phWnd)
{
	XLOPER12	xRet;

	if (phWnd == NULL)	return FALSE;
	*phWnd = (HWND)NULL;

	if (Excel12(xlGetHwnd, &xRet, 0) == xlretSuccess)
	{
		*phWnd = (HWND)xRet.val.w;
		return TRUE;
	}
	return FALSE;
}

//======================================================================
//	GetExcelHandleWindow4
//	Excel のメインウィンドウのハンドルを取得する。（Excel4 版）
//
//	ウィンドウハンドルは 32 ビット値であるが、
//	Excel4 バージョンでの場合、下位 16 ビット値のみが得られる。
//	したがって、その時点で開かれているすべてのウィンドウのハンドルと
//	下位 16 ビットを比較して決定しなければならない。
//======================================================================
//----------------------------------------------------------------------
//	ENUMARG
//----------------------------------------------------------------------
struct XLGETHWND4_ENUMARG
{
	WORD	whWnd;
	HWND	hExcel;
};

//----------------------------------------------------------------------
//	GetExcelWindowHandle4_EnumProc
//----------------------------------------------------------------------
BOOL CALLBACK GetExcelWindowHandle4_EnumProc(HWND hWnd, LPARAM lParam)
{
	XLGETHWND4_ENUMARG*	pArg	= (XLGETHWND4_ENUMARG*)lParam;
	const int			iBuf	= 32;
	char				Buf[iBuf];
	LPCSTR				pszClassName	= "XLMAIN";

	//	下位 16 ビットが一致したらクラス名を調べる。
	if (LOWORD((DWORD)hWnd) == pArg->whWnd)
	{
		if (GetClassNameA(hWnd, Buf, iBuf) > 0)
		{
			if (!lstrcmpiA(pszClassName, Buf))
			{
				pArg->hExcel	= hWnd;
				return FALSE;
			}
		}
	}
	return TRUE;
}

//----------------------------------------------------------------------
//	GetExcelWindowHandle4
//----------------------------------------------------------------------
BOOL GetExcelWindowHandle4(HWND* phWnd)
{
	XLGETHWND4_ENUMARG	siEnumArg;
	XLOPER				xRet;

	if (phWnd == NULL)	return FALSE;

	//	Excel メインウィンドウのハンドルの下位 16 ビットを取得する。
	if (Excel(xlGetHwnd, &xRet, 0) != xlretSuccess)
	{
		*phWnd	= NULL;
		return FALSE;
	}

	//	現在開かれているウィンドウのハンドルと比較する。
	siEnumArg.hExcel	= NULL;
	siEnumArg.whWnd		= (WORD)(xRet.val.w);
	EnumWindows(&GetExcelWindowHandle4_EnumProc, (LPARAM)&siEnumArg);
	if (siEnumArg.hExcel != NULL)
	{
		*phWnd	= siEnumArg.hExcel;
		return TRUE;
	}
	*phWnd	= NULL;
	return FALSE;
}


//----------------------------------------------------------------------
//	GetExcelWindowHandle
//----------------------------------------------------------------------
inline HWND GetExcelWindowHandle()
{
	return hExcelWindow;
}


//======================================================================
//	Excel のウィンドウプロシージャ
//======================================================================
//----------------------------------------------------------------------
//	SaveExcelWindowProcedure
//	ウィンドウプロシージャのハンドルを既定の変数に格納する。
//----------------------------------------------------------------------
BOOL SaveExcelWindowProcedure()
{
	HWND	hExcel;

	if ((hExcel = GetExcelWindowHandle()))
	{
		pExcelWndProc	= (WNDPROC)GetWindowLongPtr(hExcel, GWLP_WNDPROC);
		return TRUE;
	}
	return FALSE;
}

//----------------------------------------------------------------------
//	RestoreExcelWindowProcedure
//	ウィンドウプロシージャのハンドルを格納してあるものに書き戻す。
//----------------------------------------------------------------------
BOOL RestoreExcelWindowProcedure(WNDPROC* ppOld)
{
	HWND	hExcel;
	WNDPROC	pOld;

	if (!(hExcel = GetExcelWindowHandle()))
	{
		return FALSE;
	}
	if (!pExcelWndProc)
	{
		return FALSE;
	}

	pOld	= (WNDPROC)SetWindowLongPtr(hExcel, GWLP_WNDPROC, (LONG_PTR)pExcelWndProc);
	if (pOld)
	{
		if (ppOld != NULL)
		{
			*ppOld	= pOld;
		}
		return TRUE;
	}
	return FALSE;
}

//----------------------------------------------------------------------
//	GetExcelWindowProcedure
//	ウィンドウプロシージャのハンドルを取得する。
//----------------------------------------------------------------------
WNDPROC	GetExcelWindowProcedure()
{
	return pExcelWndProc;
}

//======================================================================
//	Excel のパス
//======================================================================
//----------------------------------------------------------------------
//	SetExcelPath	(1)
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL SetExcelPath(const T_CHAR* pPath, size_t zPath)
{
	typedef	T_CHAR*						T_PSTR;
	typedef	const T_CHAR*				T_PCSTR;

	T_PCSTR	pDir, pFile;
	size_t	zDir, zFile;

	if (PLib::SplitPath<T_CHAR>(&pDir, &zDir, &pFile, &zFile, pPath, zPath))
	{
		if (!xdsExcelPath.Assign(pPath, zPath))	goto ERROR_HANDLING;
		if (!xdsExcelDir.Assign(pDir, zDir))	goto ERROR_HANDLING;
		if (!xdsExcelFile.Assign(pFile, zFile))	goto ERROR_HANDLING;
	}
	return TRUE;

ERROR_HANDLING:
	xdsExcelPath.Clear();
	xdsExcelDir.Clear();
	xdsExcelFile.Clear();
	return FALSE;
}

//----------------------------------------------------------------------
//	SetExcelPath	(2)
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL SetExcelPath(HINSTANCE hExcel = NULL)
{
	typedef	std::basic_string<T_CHAR>	T_STRING;

	T_STRING	strPath;

	if (!PLib::t_GetModuleFileName<T_CHAR>(&strPath, hExcel))
	{
		return FALSE;
	}

	if (SetExcelPath<T_CHAR>(strPath.c_str(), (size_t)strPath.size()))
	{
		return TRUE;
	}
	return FALSE;
}

//======================================================================
//	Excel のダイアログボックス
//======================================================================
//----------------------------------------------------------------------
//	struct PSXLDlgEnum
//----------------------------------------------------------------------
struct PSXLDlgEnum
{
	BOOL	bIsDialog;
	HWND	hExcelWnd;
	LPCTSTR	pszTitleString; // set to NULL if don't care
};

//----------------------------------------------------------------------
//	XLDlgEnumProc
//	EnumWindows 関数から呼び出されるコールバック関数
//----------------------------------------------------------------------
BOOL CALLBACK XLDlgEnumProc(HWND hWnd, PSXLDlgEnum* pParam)
{
	static const size_t	zClassNameBufSize	= 15;
	TCHAR szClassName[zClassNameBufSize + 1];
	LPTSTR	pszWindowTitle;
	size_t	zWindowTitle;

	//	親ウィンドウが Excel であるかどうか調べる。
	//	GetParent 関数は、WS_POPUP スタイルのトップレベルウィンドウの場合、
	//	オーナーのハンドルを返す。
	if(GetParent(hWnd) != pParam->hExcelWnd)	return TRUE; // keep iterating

	//	GetClassName 関数は、バッファが足りない場合は失敗とせずに、切り捨てて返す。
	GetClassName(hWnd, szClassName, (int)zClassNameBufSize);

	//	Excel のダイアログボックスのクラス名は "bosa_sdm_xl" で始まっている。
	//	この文字列と得られたクラス名を比較する（大文字小文字を区別しない）。
	//size_t len; // The length of the window's title text
	if(PLib::t_StrNCmp<TCHAR, FALSE>(szClassName, TEXT("bosa_sdm_xl"), 11) == 0)
	{
		//	さらにウィンドウタイトルが指定されている場合は比較する。
		if(pParam->pszTitleString) 
		{
			if (!PLib::t_GetWindowTextMa<TCHAR>(hWnd, &pszWindowTitle, &zWindowTitle))
				return TRUE;	//	エラーが起こった場合はとりあえず次のウィンドウへ

			//	ウィンドウタイトルを小文字に変換しておく。
			CharLower(pszWindowTitle);

			//	タイトルが空文字列の場合
			if(zWindowTitle == 0) // No title
			{
				if(pParam->pszTitleString[0] != 0)	return TRUE;
				//	検索文字列が空でない場合は次のウィンドウを調べる。
				//	空の場合は、見つかったとみなして終了する。
			}
			//	タイトルが空文字列ではない場合
			else
			{
				//	検索文字列が空なら、次のウィンドウを調べる。
				if(*(pParam->pszTitleString) == NULL)	return TRUE;

				//	文字列が見つからない場合も、次のウィンドウを調べる。
				if (PLib::t_StrStr<TCHAR>(pszWindowTitle, pParam->pszTitleString) == NULL)
					return TRUE;
				//	見つかった場合は終了する。
			}
		}
		pParam->bIsDialog	= TRUE;
		return FALSE; //EnumWindows を終了させる。
	}
	return TRUE; // Tells Windows to continue iterating.
}

//----------------------------------------------------------------------
//	CalledFromExcelDialog
//	pszTitleString は小文字に変換しておくこと。
//----------------------------------------------------------------------
BOOL CalledFromExcelDialog(LPCTSTR pszTitleString)
{
    PSXLDlgEnum siParam;

	siParam.bIsDialog	= FALSE;
	siParam.hExcelWnd	= GetExcelWindowHandle();
	if (pszTitleString)
		siParam.pszTitleString	= pszTitleString;
	else
		siParam.pszTitleString	= NULL;

    EnumWindows((WNDENUMPROC)XLDlgEnumProc, (LPARAM)&siParam);
    return siParam.bIsDialog;
}


//======================================================================
//	XLL 設定用の変数と関数
//======================================================================
//----------------------------------------------------------------------
//	XLL のインスタンスハンドル
//----------------------------------------------------------------------
void SetXLLInstanceHandle(HINSTANCE hXLL)
{
	hXLLInstance	= hXLL;
}

HINSTANCE GetXLLInstanceHandle()
{
	return hXLLInstance;
}


//----------------------------------------------------------------------
//	SetXLLPath
//
//	XLL のパスを設定する
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL SetXLLPath(const T_CHAR* pPath, size_t zPath)
{
	typedef	T_CHAR*						T_PSTR;
	typedef	const T_CHAR*				T_PCSTR;

	T_PCSTR	pDir, pFile;
	size_t	zDir, zFile;

	if (PLib::SplitPath<T_CHAR>(&pDir, &zDir, &pFile, &zFile, pPath, zPath))
	{
		if (!xdsXLLPath.Assign(pPath, zPath))	goto ERROR_HANDLING;
		if (!xdsXLLDir.Assign(pDir, zDir))		goto ERROR_HANDLING;
		if (!xdsXLLFile.Assign(pFile, zFile))	goto ERROR_HANDLING;
	}
	return TRUE;

ERROR_HANDLING:
	return FALSE;
}

//----------------------------------------------------------------------
//	SetXLLPath	(2)
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL SetXLLPath(HINSTANCE hXLL)
{
	typedef	std::basic_string<T_CHAR>	T_STRING;

	T_STRING	strPath;

	if (!PLib::t_GetModuleFileName<T_CHAR>(&strPath, hXLL))
	{
		return FALSE;
	}

	if (SetXLLPath<T_CHAR>(strPath.c_str(), (size_t)strPath.size()))
	{
		return TRUE;
	}
	goto ERROR_HANDLING;

ERROR_HANDLING:
	xdsXLLPath.Clear();
	xdsXLLDir.Clear();
	xdsXLLFile.Clear();
	return FALSE;
}


//======================================================================
//	初期設定と終了処理
//======================================================================
//----------------------------------------------------------------------
//	XLL::Init
//----------------------------------------------------------------------
BOOL Init()
{
	BOOL bInit	= TRUE;

	//	Excel のバージョンを取得し、格納しておく。
	SetExcelVersion();

	//	Excel と XLL のインスタンスハンドルを取得する。
	SetExcelInstanceHandle();

	if (XLL::IsExcel12())
	{
		if (!SetExcelPath<wchar_t>(GetExcelInstanceHandle()))	bInit	= FALSE; 
		if (!SetXLLPath<wchar_t>(GetXLLInstanceHandle()))		bInit	= FALSE;
		if (!GetExcelWindowHandle12(&hExcelWindow))				bInit	= FALSE;
	}
	else
	{
		if (!SetExcelPath<char>(hExcelInstance))	bInit	= FALSE;
		if (!SetXLLPath<char>(hXLLInstance))		bInit	= FALSE;
		if (!GetExcelWindowHandle4(&hExcelWindow))	bInit	= FALSE;
	}

	//
	/*
	XLL::SetXLOPER_Err<XLOPER>(&xOperST4_ErrNull, xlerrNull, FALSE);
	XLL::SetXLOPER_Err<XLOPER>(&xOperST4_ErrValue, xlerrValue, FALSE);
	XLL::SetXLOPER_Missing<XLOPER>(&xOperST4_Missing, FALSE);
	XLL::SetXLOPER_Nil<XLOPER>(&xOperST4_Nil, FALSE);

	XLL::SetXLOPER_Err<XLOPER12>(&xOperST12_ErrNull, xlerrNull, FALSE);
	XLL::SetXLOPER_Err<XLOPER12>(&xOperST12_ErrValue, xlerrValue, FALSE);
	XLL::SetXLOPER_Missing<XLOPER12>(&xOperST12_Missing, FALSE);
	XLL::SetXLOPER_Nil<XLOPER12>(&xOperST12_Nil, FALSE);
	*/

	XLL::InitXLLMemory();

	return bInit;
}

//----------------------------------------------------------------------
//	XLL::Cleanup
//----------------------------------------------------------------------
void Cleanup()
{
	XLL::CleanupXLLMemory();

	xdsExcelPath.Free();
	xdsExcelDir.Free();
	xdsExcelFile.Free();

	xdsXLLPath.Free();
	xdsXLLDir.Free();
	xdsXLLFile.Free();
}

NS_XLL_END

