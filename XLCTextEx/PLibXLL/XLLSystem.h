//	XLCTextEx_1.0x	:	PLibXLL

//	XLLSystem.h
//
#pragma once

NS_XLL_BEGIN

//======================================================================
//	Excel �̏��
//======================================================================
//----------------------------------------------------------------------
//	�o�[�W����
//----------------------------------------------------------------------
//	�o�[�W���������i�[���邽�߂̍\����
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
//	Excel �̃n���h���ƃv���V�[�W��
//----------------------------------------------------------------------
//	�C���X�^���X�n���h��
void		SetExcelInstanceHandle();
HINSTANCE	GetExcelInstanceHandle();

//	�E�B���h�E�n���h��
HWND	GetExcelWindowHandle();

//	�E�B���h�E�v���V�[�W��
BOOL	SaveExcelWindowProcedure();
BOOL	RestoreExcelWindowProcedure(WNDPROC* ppOld = NULL);
WNDPROC	GetExcelWindowProcedure();

//----------------------------------------------------------------------
//	GetExcelPath
//	Excel �̎��s�t�@�C���̃t���p�X���擾����
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
//	Excel �̎��s�t�@�C��������f�B���N�g�������擾����
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
//	Excel �̎��s�t�@�C�������擾����
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
//	XLL �֐��� Excel �̃_�C�A���O����Ăяo���ꂽ���ǂ������ׂ�B
//----------------------------------------------------------------------
BOOL CalledFromExcelDialog(LPCTSTR pszTitleString = NULL);


//======================================================================
//	XLL �ݒ�p�̕ϐ��Ɗ֐�
//======================================================================
//----------------------------------------------------------------------
//	XLL �̃n���h��
//----------------------------------------------------------------------
//	�C���X�^���X�n���h��
void		SetXLLInstanceHandle(HINSTANCE hXLL);
HINSTANCE	GetXLLInstanceHandle();

//	XLL �̃t�@�C�����A�f�B���N�g�������擾����B
//	XLL �̃p�X�A�t�@�C�����ƃf�B���N�g��

extern XLL_DTSTRING	xdsXLLPath;
extern XLL_DTSTRING	xdsXLLName;
extern XLL_DTSTRING	xdsXLLDirectory;

//----------------------------------------------------------------------
//	GetXLLPath
//	XLL �̃t���p�X���擾����B
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
//	XLL �̃t���p�X�� C �`���̕�����ŏo�͂���B
//----------------------------------------------------------------------
template<typename T_CHAR>
const T_CHAR* GetXLLPathCS()
{
	return xdsXLLPath.CStr<T_CHAR>();
}

//----------------------------------------------------------------------
//	GetXLLPathXS
//	XLL �̃t���p�X�� XLL �`���̕�����ŏo�͂���B
//----------------------------------------------------------------------
template<typename T_CHAR>
const T_CHAR* GetXLLPathXS()
{
	return xdsXLLPath.XStr<T_CHAR>();
}

//----------------------------------------------------------------------
//	GetXLLDir
//	XLL �̎��s�t�@�C��������f�B���N�g�������擾����
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
//	XLL �̎��s�t�@�C�������擾����
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
//	XLL �̏����ݒ�ƏI������
//======================================================================
//	XLL �̏����ݒ�
BOOL	Init();

//	XLL �̏I������
void	Cleanup();

NS_XLL_END
