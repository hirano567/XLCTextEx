//	XLCTextEx_1.0x	:	PLibXLL

//	XLLSystem.cpp
//
#include "stdafx.h"
NS_XLL_BEGIN

//======================================================================
//	�e��̏��
//
//	Excel �� XLL �Ɋւ�����́A���ɗ��R���Ȃ����肱���ɏW�߂�B
//======================================================================
//----------------------------------------------------------------------
//	Excel �Ɋւ�����
//----------------------------------------------------------------------
//	Excel �̃o�[�W����
static PSVERSION	siExcelVersion;

//	Excel �̃C���X�^���X�n���h��
HINSTANCE	hExcelInstance	= NULL;

//	Excel �̃E�B���h�E�n���h��
HWND	hExcelWindow	= NULL;

//	Excel �̃E�B���h�E�v���V�[�W��
WNDPROC pExcelWndProc	= NULL;

//	Excel �̃p�X
XLL_DTSTRING	xdsExcelPath;
XLL_DTSTRING	xdsExcelDir;
XLL_DTSTRING	xdsExcelFile;

//----------------------------------------------------------------------
//	XLL �Ɋւ�����
//----------------------------------------------------------------------
//	XLL �̃o�[�W����
PSVERSION	siXLLVersion;

//	XLL �̃C���X�^���X�n���h��
HINSTANCE	hXLLInstance	= NULL;

//	XLL �̃p�X
XLL_DTSTRING	xdsXLLPath;
XLL_DTSTRING	xdsXLLDir;
XLL_DTSTRING	xdsXLLFile;


//----------------------------------------------------------------------
//	���̑��̏��
//----------------------------------------------------------------------
//	���j���[��c�[���o�[�̃^�C�g���B
PCSTRAW		awXLLTitle	= { TEXTAW("XLHttp") };	//	�^�C�g���Ɏg�p���閼�O


//======================================================================
//	Excel �̏��
//
//	�o�[�W�������̊Ǘ�
//======================================================================
//----------------------------------------------------------------------
//	SetExcelVersion	(1)
//
//	Excel4 �֐��̌��ʂ��i�[���Ă��� XLOPER ����o�[�W�������擾����B
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
//	��̊֐����g�p���� Excel �̃o�[�W�������擾���Astatic �ϐ��Ɋi�[���Ă����B
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
	//	Excel �ɂ���Ċ��蓖�Ă�ꂽ���������������B
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
//	�擾�ς݂̃o�[�W������Ԃ��B
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
//	Excel 2007 �ȍ~���B
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
//	Excel �̃C���X�^���X�n���h��
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
//	Excel �̃��C���E�B���h�E�̃n���h�����擾����B�iExcel12 �Łj
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
//	Excel �̃��C���E�B���h�E�̃n���h�����擾����B�iExcel4 �Łj
//
//	�E�B���h�E�n���h���� 32 �r�b�g�l�ł��邪�A
//	Excel4 �o�[�W�����ł̏ꍇ�A���� 16 �r�b�g�l�݂̂�������B
//	���������āA���̎��_�ŊJ����Ă��邷�ׂẴE�B���h�E�̃n���h����
//	���� 16 �r�b�g���r���Č��肵�Ȃ���΂Ȃ�Ȃ��B
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

	//	���� 16 �r�b�g����v������N���X���𒲂ׂ�B
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

	//	Excel ���C���E�B���h�E�̃n���h���̉��� 16 �r�b�g���擾����B
	if (Excel(xlGetHwnd, &xRet, 0) != xlretSuccess)
	{
		*phWnd	= NULL;
		return FALSE;
	}

	//	���݊J����Ă���E�B���h�E�̃n���h���Ɣ�r����B
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
//	Excel �̃E�B���h�E�v���V�[�W��
//======================================================================
//----------------------------------------------------------------------
//	SaveExcelWindowProcedure
//	�E�B���h�E�v���V�[�W���̃n���h��������̕ϐ��Ɋi�[����B
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
//	�E�B���h�E�v���V�[�W���̃n���h�����i�[���Ă�����̂ɏ����߂��B
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
//	�E�B���h�E�v���V�[�W���̃n���h�����擾����B
//----------------------------------------------------------------------
WNDPROC	GetExcelWindowProcedure()
{
	return pExcelWndProc;
}

//======================================================================
//	Excel �̃p�X
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
//	Excel �̃_�C�A���O�{�b�N�X
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
//	EnumWindows �֐�����Ăяo�����R�[���o�b�N�֐�
//----------------------------------------------------------------------
BOOL CALLBACK XLDlgEnumProc(HWND hWnd, PSXLDlgEnum* pParam)
{
	static const size_t	zClassNameBufSize	= 15;
	TCHAR szClassName[zClassNameBufSize + 1];
	LPTSTR	pszWindowTitle;
	size_t	zWindowTitle;

	//	�e�E�B���h�E�� Excel �ł��邩�ǂ������ׂ�B
	//	GetParent �֐��́AWS_POPUP �X�^�C���̃g�b�v���x���E�B���h�E�̏ꍇ�A
	//	�I�[�i�[�̃n���h����Ԃ��B
	if(GetParent(hWnd) != pParam->hExcelWnd)	return TRUE; // keep iterating

	//	GetClassName �֐��́A�o�b�t�@������Ȃ��ꍇ�͎��s�Ƃ����ɁA�؂�̂ĂĕԂ��B
	GetClassName(hWnd, szClassName, (int)zClassNameBufSize);

	//	Excel �̃_�C�A���O�{�b�N�X�̃N���X���� "bosa_sdm_xl" �Ŏn�܂��Ă���B
	//	���̕�����Ɠ���ꂽ�N���X�����r����i�啶������������ʂ��Ȃ��j�B
	//size_t len; // The length of the window's title text
	if(PLib::t_StrNCmp<TCHAR, FALSE>(szClassName, TEXT("bosa_sdm_xl"), 11) == 0)
	{
		//	����ɃE�B���h�E�^�C�g�����w�肳��Ă���ꍇ�͔�r����B
		if(pParam->pszTitleString) 
		{
			if (!PLib::t_GetWindowTextMa<TCHAR>(hWnd, &pszWindowTitle, &zWindowTitle))
				return TRUE;	//	�G���[���N�������ꍇ�͂Ƃ肠�������̃E�B���h�E��

			//	�E�B���h�E�^�C�g�����������ɕϊ����Ă����B
			CharLower(pszWindowTitle);

			//	�^�C�g�����󕶎���̏ꍇ
			if(zWindowTitle == 0) // No title
			{
				if(pParam->pszTitleString[0] != 0)	return TRUE;
				//	���������񂪋�łȂ��ꍇ�͎��̃E�B���h�E�𒲂ׂ�B
				//	��̏ꍇ�́A���������Ƃ݂Ȃ��ďI������B
			}
			//	�^�C�g�����󕶎���ł͂Ȃ��ꍇ
			else
			{
				//	���������񂪋�Ȃ�A���̃E�B���h�E�𒲂ׂ�B
				if(*(pParam->pszTitleString) == NULL)	return TRUE;

				//	�����񂪌�����Ȃ��ꍇ���A���̃E�B���h�E�𒲂ׂ�B
				if (PLib::t_StrStr<TCHAR>(pszWindowTitle, pParam->pszTitleString) == NULL)
					return TRUE;
				//	���������ꍇ�͏I������B
			}
		}
		pParam->bIsDialog	= TRUE;
		return FALSE; //EnumWindows ���I��������B
	}
	return TRUE; // Tells Windows to continue iterating.
}

//----------------------------------------------------------------------
//	CalledFromExcelDialog
//	pszTitleString �͏������ɕϊ����Ă������ƁB
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
//	XLL �ݒ�p�̕ϐ��Ɗ֐�
//======================================================================
//----------------------------------------------------------------------
//	XLL �̃C���X�^���X�n���h��
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
//	XLL �̃p�X��ݒ肷��
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
//	�����ݒ�ƏI������
//======================================================================
//----------------------------------------------------------------------
//	XLL::Init
//----------------------------------------------------------------------
BOOL Init()
{
	BOOL bInit	= TRUE;

	//	Excel �̃o�[�W�������擾���A�i�[���Ă����B
	SetExcelVersion();

	//	Excel �� XLL �̃C���X�^���X�n���h�����擾����B
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

