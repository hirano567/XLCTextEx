//	XLCTextEx_1.0x	:	PLibXLL

//	XLLSystem.h
//
#pragma once

NS_XLL_BEGIN

//======================================================================
//	Excel の情報
//======================================================================
//----------------------------------------------------------------------
//	バージョン
//----------------------------------------------------------------------
//	バージョン情報を格納するための構造体
struct PSVERSION
{
	int Major;
	int	minor;

	PSVERSION()	: Major(0), minor(0)	{}
	void Set(int vMajor, int vminor)	{ Major = vMajor; minor = vminor; }
};

BOOL	SetExcelVersion(PSVERSION* pVersion, LPXLOPER pXLOper);
BOOL	SetExcelVersion(PSVERSION* pVersion);
BOOL	SetExcelVersion();

BOOL	GetExcelVersion(int* pmajor, int* pminor);
BOOL	IsExcel12();


//----------------------------------------------------------------------
//	Excel のハンドルとプロシージャ
//----------------------------------------------------------------------
//	インスタンスハンドル
void		SetExcelInstanceHandle();
HINSTANCE	GetExcelInstanceHandle();

//	ウィンドウハンドル
HWND	GetExcelWindowHandle();

//	ウィンドウプロシージャ
BOOL	SaveExcelWindowProcedure();
BOOL	RestoreExcelWindowProcedure(WNDPROC* ppOld = NULL);
WNDPROC	GetExcelWindowProcedure();

//----------------------------------------------------------------------
//	GetExcelPath
//	Excel の実行ファイルのフルパスを取得する
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL GetExcelPath(const T_CHAR** ppPath, size_t* pzPath)
{
	extern XLL_DTSTRING	xdsExcelPath;

	if (ppPath == NULL || pzPath == NULL)	return FALSE;

	*ppPath	= xdsExcelPath.CStr<T_CHAR>();
	*pzPath	= xdsExcelPath.Size<T_CHAR>();
	return TRUE;
}

//----------------------------------------------------------------------
//	GetExcelDir
//	Excel の実行ファイルがあるディレクトリ名を取得する
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL GetExcelDir(const T_CHAR** ppDir, size_t* pzDir)
{
	extern XLL_DTSTRING	xdsExcelDir;

	if (ppDir == NULL || pzDir == NULL)	return FALSE;

	*ppDir	= xdsExcelDir.CStr<T_CHAR>();
	*pzDir	= xdsExcelDir.Size<T_CHAR>();
	return TRUE;
}

//----------------------------------------------------------------------
//	GetExcelFile
//	Excel の実行ファイル名を取得する
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL GetExcelFile(const T_CHAR** ppFile, size_t* pzFile)
{
	extern XLL_DTSTRING	xdsExcelFile;

	if (ppFile == NULL || pzFile == NULL)	return FALSE;

	*ppFile	= xdsExcelFile.CStr<T_CHAR>();
	*pzFile	= xdsExcelFile.Size<T_CHAR>();
	return TRUE;
}

//----------------------------------------------------------------------
//	CalledFromExcelDialog
//	XLL 関数が Excel のダイアログから呼び出されたかどうか調べる。
//----------------------------------------------------------------------
BOOL CalledFromExcelDialog(LPCTSTR pszTitleString = NULL);


//======================================================================
//	XLL 設定用の変数と関数
//======================================================================
//----------------------------------------------------------------------
//	XLL のハンドル
//----------------------------------------------------------------------
//	インスタンスハンドル
void		SetXLLInstanceHandle(HINSTANCE hXLL);
HINSTANCE	GetXLLInstanceHandle();

//	XLL のファイル名、ディレクトリ名を取得する。
//	XLL のパス、ファイル名とディレクトリ

extern XLL_DTSTRING	xdsXLLPath;
extern XLL_DTSTRING	xdsXLLName;
extern XLL_DTSTRING	xdsXLLDirectory;

//----------------------------------------------------------------------
//	GetXLLPath
//	XLL のフルパスを取得する。
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL GetXLLPath(const T_CHAR** ppPath, size_t* pzPath)
{
	extern XLL_DTSTRING	xdsXLLPath;

	if (ppPath == NULL || pzPath == NULL)	return FALSE;

	*ppPath	= xdsXLLPath.CStr<T_CHAR>();
	*pzPath	= xdsXLLPath.Size<T_CHAR>();
	return TRUE;
}

//----------------------------------------------------------------------
//	GetXLLPathCS
//	XLL のフルパスを C 形式の文字列で出力する。
//----------------------------------------------------------------------
template<typename T_CHAR>
const T_CHAR* GetXLLPathCS()
{
	return xdsXLLPath.CStr<T_CHAR>();
}

//----------------------------------------------------------------------
//	GetXLLPathXS
//	XLL のフルパスを XLL 形式の文字列で出力する。
//----------------------------------------------------------------------
template<typename T_CHAR>
const T_CHAR* GetXLLPathXS()
{
	return xdsXLLPath.XStr<T_CHAR>();
}

//----------------------------------------------------------------------
//	GetXLLDir
//	XLL の実行ファイルがあるディレクトリ名を取得する
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL GetXLLDir(const T_CHAR** ppDir, size_t* pzDir)
{
	extern XLL_DTSTRING	xdsXLLDir;

	if (ppDir == NULL || pzDir == NULL)	return FALSE;

	*ppDir	= xdsXLLDir.CStr<T_CHAR>();
	*pzDir	= xdsXLLDir.Size<T_CHAR>();
	return TRUE;
}

//----------------------------------------------------------------------
//	GetXLLFile
//	XLL の実行ファイル名を取得する
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL GetXLLFile(const T_CHAR** ppFile, size_t* pzFile)
{
	extern XLL_DTSTRING	xdsXLLFile;

	if (ppFile == NULL || pzFile == NULL)	return FALSE;

	*ppFile	= xdsXLLFile.CStr<T_CHAR>();
	*pzFile	= xdsXLLFile.Size<T_CHAR>();
	return TRUE;
}


//======================================================================
//	XLL の初期設定と終了処理
//======================================================================
//	XLL の初期設定
BOOL	Init();

//	XLL の終了処理
void	Cleanup();

NS_XLL_END
