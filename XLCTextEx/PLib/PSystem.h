//	XLCTextEx_1.0x	:	PLib

//	PSystem.h
//
#pragma once
#ifndef	NOT_USE_SYSTEM

#ifndef NS_PLIB
#define NS_PLIB	PLib
#endif

#ifndef	NS_SYSTEM
#define	NS_SYSTEM	System
#define NS_PLIB_SYSTEM_BEGIN	namespace NS_PLIB {	namespace NS_SYSTEM {
#define NS_PLIB_SYSTEM_END		}}
#endif

NS_PLIB_BEGIN

#define	TEXT_PCSYSTEM(quote)	L##quote

typedef	wchar_t							TC_PCSYSTEM;
typedef	TC_PCSYSTEM*					T_PSTR_PCSYSTEM;
typedef	const TC_PCSYSTEM*				T_PCSTR_PCSYSTEM;
typedef	std::basic_string<TC_PCSYSTEM>	T_STRING_PCSYSTEM, *T_PSTRING_PCSYSTEM;


//======================================================================
//	�֐��e���v���[�g
//======================================================================
//----------------------------------------------------------------------
//	t_OSVERSIONINFO
//----------------------------------------------------------------------
template<typename T_CHAR>
struct t_OSVERSIONINFO
{
	DWORD	dwOSVersionInfoSize;

public:
	void Init()
	{
		size_t	zSize	= sizeof(t_OSVERSIONINFO<T_CHAR>);
		memset(this, 0, zSize);
		dwOSVersionInfoSize	= (DWORD)zSize;
	}
};
template<>
struct t_OSVERSIONINFO<char>	:	public OSVERSIONINFOA
{
public:
	void Init()
	{
		size_t	zSize	= sizeof(t_OSVERSIONINFO<char>);
		memset(this, 0, zSize);
		dwOSVersionInfoSize	= (DWORD)zSize;
	}
};
template<>
struct t_OSVERSIONINFO<wchar_t>	:	public OSVERSIONINFOW
{
public:
	void Init()
	{
		size_t	zSize	= sizeof(t_OSVERSIONINFO<wchar_t>);
		memset(this, 0, zSize);
		dwOSVersionInfoSize	= (DWORD)zSize;
	}
};

//----------------------------------------------------------------------
//	t_OSVERSIONINFOEX
//----------------------------------------------------------------------
template<typename T_CHAR>
struct t_OSVERSIONINFOEX
{
	DWORD	dwOSVersionInfoSize;
};
template<>
struct t_OSVERSIONINFOEX<char>	:	public OSVERSIONINFOEXA
{
public:
	void Init()
	{
		size_t	zSize	= sizeof(t_OSVERSIONINFOEX<char>);
		memset(this, 0, zSize);
		dwOSVersionInfoSize	= (DWORD)zSize;
	}
};
template<>
struct t_OSVERSIONINFOEX<wchar_t>	:	public OSVERSIONINFOEXW
{
public:
	void Init()
	{
		size_t	zSize	= sizeof(t_OSVERSIONINFOEX<wchar_t>);
		memset(this, 0, zSize);
		dwOSVersionInfoSize	= (DWORD)zSize;
	}
};

//----------------------------------------------------------------------
//	t_GetVersionEx
//
//	BOOL WINAPI GetVersionEx(
//		__inout  LPOSVERSIONINFO lpVersionInfo
//	);
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL t_GetVersionEx(t_OSVERSIONINFOEX<T_CHAR>* pVersionInfo)
{
	throw std::logic_error("t_GetVersionEx");
	return FALSE;
}
template<>
inline BOOL t_GetVersionEx<char>(t_OSVERSIONINFOEX<char>* pVersionInfo)
{
	pVersionInfo->Init();
	return GetVersionExA((OSVERSIONINFOA*)pVersionInfo);
}
template<>
inline BOOL t_GetVersionEx<wchar_t>(t_OSVERSIONINFOEX<wchar_t>* pVersionInfo)
{
	pVersionInfo->Init();
	return GetVersionExW((OSVERSIONINFOW*)pVersionInfo);
}

//----------------------------------------------------------------------
//	t_VerifyVersionInfo
//
//	BOOL WINAPI VerifyVersionInfo(
//		__in  LPOSVERSIONINFOEX lpVersionInfo,
//		__in  DWORD dwTypeMask,
//		__in  DWORDLONG dwlConditionMask
//	);
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL t_VerifyVersionInfo(t_OSVERSIONINFOEX<T_CHAR>* pVersionInfo,
								DWORD dwTypeMask,
								DWORDLONG dwlConditionMask)
{
	throw std::logic_error("t_VerifyVersionInfo");
	return FALSE;
}
template<>
inline BOOL t_VerifyVersionInfo<char>(t_OSVERSIONINFOEX<char>* pVersionInfo,
									  DWORD dwTypeMask,
									  DWORDLONG dwlConditionMask)
{
	return VerifyVersionInfoA((OSVERSIONINFOEXA*)pVersionInfo, dwTypeMask, dwlConditionMask);
}
template<>
inline BOOL t_VerifyVersionInfo<wchar_t>(t_OSVERSIONINFOEX<wchar_t>* pVersionInfo,
										 DWORD dwTypeMask,
										 DWORDLONG dwlConditionMask)
{
	return VerifyVersionInfoW((OSVERSIONINFOEXW*)pVersionInfo, dwTypeMask, dwlConditionMask);
}


//----------------------------------------------------------------------
//	t_GetModuleHandle
//----------------------------------------------------------------------
template<typename T_CHAR>
inline HMODULE t_GetModuleHandle(const T_CHAR* pszName)
{
	throw std::logic_error("t_GetModuleHandle");
	return NULL;
}
template<>
inline HMODULE t_GetModuleHandle<char>(LPCSTR pszName)
{
	return GetModuleHandleA(pszName);
}
template<>
inline HMODULE t_GetModuleHandle<wchar_t>(LPCWSTR pszName)
{
	return GetModuleHandleW(pszName);
}

//----------------------------------------------------------------------
//	t_GetModuleFileName
//----------------------------------------------------------------------
template<typename T_CHAR>
inline DWORD t_GetModuleFileName(HINSTANCE hInstance, T_CHAR* pName, DWORD dwSize)
{
	throw std::logic_error("t_GetModuleFileName");
	return 0;
}
template<>
inline DWORD t_GetModuleFileName<char>(HINSTANCE hInstance, LPSTR pName, DWORD dwSize)
{
	return GetModuleFileNameA((HMODULE)hInstance, pName, dwSize);
}
template<>
inline DWORD t_GetModuleFileName<wchar_t>(HINSTANCE hInstance, LPWSTR pName, DWORD dwSize)
{
	return GetModuleFileNameW((HMODULE)hInstance, pName, dwSize);
}

//----------------------------------------------------------------------
//	t_GetModuleFileName
//
//	���W���[���n���h���ɑΉ�����t�@�C���̃t���p�X���A
//	std::basic_string �̃C���X�^���X�Ɋi�[����B
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL t_GetModuleFileName(std::basic_string<T_CHAR>* pstrFile, HINSTANCE hInstance = NULL)
{
	typedef	T_CHAR*	T_PSTR;

	const DWORD	PATH_LENGTH		= 256;		//	MAX_PATH �́A�h���C�u��I�[���l������ 260 �����B
	const DWORD	PATH_LENGTH_MAX	= 32768;	//	Unicode �łł� 32767 �����܂ŉ\

	T_PSTR	pBuf	= NULL;
	DWORD	dwPath	= PATH_LENGTH;
	DWORD	dwBuf	= dwPath + 8;
	//	XP �́A�o�b�t�@�s���ł� ERROR_SUCCESS ��Ԃ��B
	//	���̂Ƃ��̖߂�l�͋L�������������A���Ȃ킿�o�b�t�@���ƂȂ邪�A
	//	���ꂾ���ł͐��ۂ����f�ł��Ȃ��i�p�X�̒������o�b�t�@���Ɉ�v����\��������j�B
	//	���������邽�߂ɁA�o�b�t�@���͍ő�p�X����蒷���Ȃ�悤�ɗ]�T���������Ă����B
	DWORD	dwRet	= 0;
	DWORD	dwError	= 0;
	//T_PSTR	pe, pc, px;
	BOOL	bGetModuleFileName	= FALSE;

	if (pstrFile == NULL)	return FALSE;
	if (hInstance == NULL)	hInstance	= t_GetModuleHandle<T_CHAR>(NULL);
	if (hInstance == NULL)	return FALSE;

	while (!(dwPath > PATH_LENGTH_MAX))
	{
		try
		{
			pBuf	= new T_CHAR[dwBuf];
		}
		CATCH_AND_GOTO_BAD_ALLOC(END_PROCESSING, "");

		if (pBuf == NULL)	goto END_PROCESSING;

		dwRet	= t_GetModuleFileName<T_CHAR>(hInstance, pBuf, dwBuf);

		dwError	= GetLastError();
		if (dwError != ERROR_SUCCESS && dwError != ERROR_INSUFFICIENT_BUFFER)
		{
			//	�o�b�t�@�s���ȊO�̃G���[���N�������ꍇ�͏I������B
			goto END_PROCESSING;
		}

		//	�o�b�t�@���s�����Ă���ꍇ�A
		//		Vista �ȍ~�ł� ERROR_INSUFFICIENT_BUFFER ���Z�b�g�����B
		//		XP �̏ꍇ�A�o�b�t�@�����Ԃ���A�G���[�R�[�h�� ERROR_SUCCESS ���Z�b�g�����B
		//	�ȏ���R�[�h���ȒP�ɂ��邽�߁A
		//		ERROR_SUCCESS ���Z�b�g����Ă���A
		//		�������܂ꂽ�o�C�g�����o�b�t�@�T�C�Y��菬�����A
		//	�ꍇ�Ƀ��W���[���t�@�C�������擾�ł����Ƃ݂Ȃ��B
		if (dwError == ERROR_SUCCESS && dwRet < dwBuf)
		{
			break;
		}
		dwPath	*= 2;	//	�o�b�t�@�̃T�C�Y�� 2 �{�ɂ��čĎ��s����B
		dwBuf	= dwPath + 8;
	}
	if (dwPath > PATH_LENGTH_MAX || pBuf == NULL || dwRet < 1)	goto END_PROCESSING;

	try
	{
		pstrFile->assign(pBuf, (std::basic_string<TCHAR>::size_type)dwRet);
	}
	CATCH_AND_GOTO_BAD_ALLOC(END_PROCESSING, "");
	bGetModuleFileName	= TRUE;

END_PROCESSING:
	delete[]	pBuf;
	return	bGetModuleFileName;
}


//======================================================================
//	�V�X�e�����֐��𗘗p���邽�߂̕⏕�֐�
//======================================================================


//======================================================================
//	�o�[�W�������
//======================================================================
#define	WINDOWS_7								10
#define	WINDOWS_SERVER_2008_R2					9
#define	WINDOWS_SERVER_2008						8
#define	WINDOWS_VISTA							7
#define	WINDOWS_SERVER_2003_R2					6
#define	WINDOWS_HOME_SERVER						5
#define	WINDOWS_SERVER_2003						4
#define	WINDOWS_XP_PROFESSIONAL_X64_EDITION		3
#define	WINDOWS_XP								2
#define	WINDOWS_2000							1

//----------------------------------------------------------------------
//	CheckOSVersion
//
//	OS �̃o�[�W�������w�肳�ꂽ���̈ȍ~�ł��邩�𒲂ׂ�B
//----------------------------------------------------------------------
BOOL	CheckOSVersion(DWORD dwMajor, DWORD dwMinor, WORD wSPMajor = 0, WORD wSPMinor = 0);

//----------------------------------------------------------------------
//	t_GetOSVersionStr
//
//	OS �̃o�[�W������������������쐬����B
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL t_GetOSVersionStr(std::basic_string<T_CHAR>* pstrVersion)
{
	t_OSVERSIONINFOEX<T_CHAR>	siVersion;
	const T_CHAR*				pszVersion;
	int							iMetircs;

	siVersion.Init();
	if (!t_GetVersionEx<T_CHAR>(&siVersion))	return FALSE;

	//------------------------------------------------------------
	//	6.1
	//------------------------------------------------------------
	if (siVersion.dwMajorVersion == 6 && siVersion.dwMinorVersion == 1)
	{
		if (siVersion.wProductType == VER_NT_WORKSTATION)
		{
			pszVersion	= t_Str<T_CHAR>(TEXTAW("Windows 7"));
		}
		else
		{
			pszVersion	= t_Str<T_CHAR>(TEXTAW("Windows Server 2008 R2"));
		}
	}
	//------------------------------------------------------------
	//	6.0
	//------------------------------------------------------------
	else if (siVersion.dwMajorVersion == 6 && siVersion.dwMinorVersion == 0)
	{
		if (siVersion.wProductType == VER_NT_WORKSTATION)
		{
			pszVersion	= t_Str<T_CHAR>(TEXTAW("Windows Vista"));
		}
		else
		{
			pszVersion	= t_Str<T_CHAR>(TEXTAW("Windows Server 2008"));
		}
	}
	//------------------------------------------------------------
	//	5.2
	//------------------------------------------------------------
	else if (siVersion.dwMajorVersion == 5 && siVersion.dwMinorVersion == 2)
	{
		if (GetSystemMetrics(SM_SERVERR2) != 0)
		{
			pszVersion	= t_Str<T_CHAR>(TEXTAW("Windows Server 2003 R2"));
		}
		else
		{
			if (siVersion.wSuiteMask & 0x00008000)	//	VER_SUITE_WH_SERVER
			{
				pszVersion	= t_Str<T_CHAR>(TEXTAW("Windows Home Server"));
			}
			else
			{
				SYSTEM_INFO	si;
				GetSystemInfo(&si);

				if ((siVersion.wProductType == VER_NT_WORKSTATION) &&
					(si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64))
				{
					pszVersion	= t_Str<T_CHAR>(TEXTAW("Windows XP Professional x64 Edition"));
				}
				else
				{
					pszVersion	= t_Str<T_CHAR>(TEXTAW("Windows Server 2003"));
				}
			}
		}
	}
	//------------------------------------------------------------
	//	5.1
	//------------------------------------------------------------
	else if (siVersion.dwMajorVersion == 5 && siVersion.dwMinorVersion == 1)
	{
		pszVersion	= t_Str<T_CHAR>(TEXTAW("Windows XP"));
	}
	//------------------------------------------------------------
	//	5.0
	//------------------------------------------------------------
	else if (siVersion.dwMajorVersion == 5 && siVersion.dwMinorVersion == 0)
	{
		pszVersion	= t_Str<T_CHAR>(TEXTAW("Windows 2000"));
	}
	//------------------------------------------------------------
	//
	//------------------------------------------------------------
	else
	{
		pszVersion	= NULL;
		//pszVersion	= t_Str<T_CHAR>(TEXTAW(""));
	}

	try
	{
		if (pszVersion != NULL)
		{
			pstrVersion->assign(pszVersion);
		}
		if (siVersion.szCSDVersion[0] != NULL)
		{
			pstrVersion->append(t_Str<T_CHAR>(TEXTAW(" (")));
			pstrVersion->append(siVersion.szCSDVersion);
			pstrVersion->append(t_Str<T_CHAR>(TEXTAW(")")));
		}
	}
	CATCH_AND_RETURN_BAD_ALLOC(FALSE, "");

	return TRUE;
}


//======================================================================
//	���W���[����
//======================================================================
//----------------------------------------------------------------------
//	t_GetApplicationName
//
//	���W���[���t�@�C�����i�g���q�������j���A�v���P�[�V�������Ƃ݂Ȃ��B
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL t_GetApplicationName(std::basic_string<T_CHAR>* pstrName, HINSTANCE hInstance = NULL)
{
	typedef	const T_CHAR*				T_PCSTR;
	typedef	std::basic_string<T_CHAR>	T_STRING, *T_PSTRING;

	T_STRING	strPath;
	T_PCSTR		pb, pe, pc, px;

	const T_CHAR	cSlash		= t_Char<T_CHAR>(TEXTAW('/'));
	const T_CHAR	cBackSlash	= t_Char<T_CHAR>(TEXTAW('\\'));
	const T_CHAR	cDot		= t_Char<T_CHAR>(TEXTAW('.'));
	const T_CHAR	cColon		= t_Char<T_CHAR>(TEXTAW(':'));

	if (hInstance == NULL)	hInstance	= GetModuleHandle(NULL);
	if (hInstance == NULL)	return FALSE;

	//	���W���[���t�@�C���̃p�X���擾����B
	if (!t_GetModuleFileName<T_CHAR>(&strPath, hInstance))	return FALSE;

	//	�p�X����A�t�@�C�����i�g���q�����j������T���B
	pb	= strPath.c_str();
	pe	= pb + strPath.size();
	pc	= pe;
	px	= pe;

	while (pb < pc && *pc != cBackSlash && *pc != cDot && *pc != cColon && *pc != cSlash)
		--pc;

	//	. ������������A�������̕������g���q�ł���Ƃ���B
	if (*pc == cDot)
	{
		pe	= pc;
		--pc;
		while (pb < pc && *pc != cBackSlash && *pc != cColon && *pc != cSlash)
			--pc;
	}
	if (*pc == cBackSlash || *pc == cColon || *pc == cSlash)	++pc;

	try
	{
		if (pc < pe)
		{
			pstrName->assign(pc, (T_STRING::size_type)(pe - pc));
		}
		else
		{
			pstrName->clear();
		}
	}
	CATCH_AND_RETURN_BAD_ALLOC(FALSE, "");
	return TRUE;
}


//======================================================================
//	�������̏��
//======================================================================
//----------------------------------------------------------------------
//	SystemInfo
//----------------------------------------------------------------------
SYSTEM_INFO*	GetPSystemInfo();
BOOL			IsInUserModePartition(LPVOID pAddress);

//----------------------------------------------------------------------
//	VirtualQuery
//----------------------------------------------------------------------
BOOL	IsPageReadWrite(LPVOID pAddress);

NS_PLIB_END

//======================================================================
//	�������ƏI������
//======================================================================
NS_PLIB_SYSTEM_BEGIN

BOOL	Init();
void	Cleanup();

NS_PLIB_SYSTEM_END
#endif	//	NOT_USE_SYSTEM
