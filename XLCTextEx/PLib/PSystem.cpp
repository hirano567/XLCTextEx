//	XLCTextEx_1.0x	:	PLib

//	PSystem.cpp
//
#include "stdafx.h"
#ifndef	NOT_USE_SYSTEM

NS_PLIB_BEGIN

//======================================================================
//	バージョン情報
//======================================================================
//	Windows 7
//	Windows Server 2008 R2
//	Windows Server 2008
//	Windows Vista
//	Windows Server 2003 R2
//	Windows Home Server
//	Windows Server 2003
//	Windows XP Professional x64 Edition
//	Windows XP
//	Windows 2000
//	
//	VerifyVersionInfo で使用
//	struct OSVERSIONNUMBER
//	{
//		DWORD	dwOS;
//		DWORD	dwMajorVersion;
//		DWORD	dwMinorVersion;
//	};
//	
//	OSVERSIONNUMBER	OSVersion[] =
//	{
//		WINDOWS_7,								6,	1,
//		WINDOWS_SERVER_2008_R2,					6,	1,
//		WINDOWS_SERVER_2008,					6,	0,
//		WINDOWS_VISTA,							6,	0,
//		WINDOWS_SERVER_2003_R2,					5,	2,
//		WINDOWS_HOME_SERVER,					5,	2,
//		WINDOWS_SERVER_2003,					5,	2,
//		WINDOWS_XP_PROFESSIONAL_X64_EDITION,	5,	2,
//		WINDOWS_XP,								5,	1,
//		WINDOWS_2000,							5,	0,
//	};
//	
//	int	nOSVersions	= sizeof(OSVersion) / sizeof(OSVERSIONNUMBER);
//	
//	//	VerifyVersionInfo を使用する。
//	static BOOL	bValidOS	= FALSE;
//	

//----------------------------------------------------------------------
//	CheckOSVersion
//	指定したバージョン以上である場合に TRUE を返す。
//----------------------------------------------------------------------
BOOL CheckOSVersion(DWORD dwMajor, DWORD dwMinor, WORD wSPMajor, WORD wSPMinor)
{
	OSVERSIONINFOEX	osvi;
	DWORDLONG		dwlConditionMask	= 0;
	BYTE			cond	= VER_GREATER_EQUAL;

	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize	= sizeof(OSVERSIONINFOEX);
	osvi.dwMajorVersion			= dwMajor;
	osvi.dwMinorVersion			= dwMinor;
	osvi.wServicePackMajor		= wSPMajor;
	osvi.wServicePackMinor		= wSPMinor;

	VER_SET_CONDITION(dwlConditionMask, VER_MAJORVERSION, cond);
	VER_SET_CONDITION(dwlConditionMask, VER_MINORVERSION, cond);
	VER_SET_CONDITION(dwlConditionMask, VER_SERVICEPACKMAJOR, cond);
	VER_SET_CONDITION(dwlConditionMask, VER_SERVICEPACKMINOR, cond);

	return VerifyVersionInfo(&osvi, VER_MAJORVERSION | VER_MINORVERSION, dwlConditionMask);
}


//======================================================================
//	メモリの情報
//======================================================================
//----------------------------------------------------------------------
//	SystemInfo
//
//	typedef struct _SYSTEM_INFO {
//	  union {
//	    DWORD  dwOemId;
//	    struct {
//	      WORD wProcessorArchitecture;
//	      WORD wReserved;
//	    };
//	  };
//	  DWORD     dwPageSize;
//	  LPVOID    lpMinimumApplicationAddress;
//	  LPVOID    lpMaximumApplicationAddress;
//	  DWORD_PTR dwActiveProcessorMask;
//	  DWORD     dwNumberOfProcessors;
//	  DWORD     dwProcessorType;
//	  DWORD     dwAllocationGranularity;
//	  WORD      wProcessorLevel;
//	  WORD      wProcessorRevision;
//	} SYSTEM_INFO;
//----------------------------------------------------------------------
SYSTEM_INFO	siSystemInfo;

SYSTEM_INFO* GetPSystemInfo()
{
	return &siSystemInfo;
}

BOOL IsInUserModePartition(LPVOID pAddress)
{
	return (
		((int)pAddress >= (int)siSystemInfo.lpMinimumApplicationAddress)	&&
		((int)pAddress <= (int)siSystemInfo.lpMaximumApplicationAddress)
		);
}

//----------------------------------------------------------------------
//	VirtualQuery
//
//	typedef struct _MEMORY_BASIC_INFORMATION {
//	  PVOID  BaseAddress;
//	  PVOID  AllocationBase;
//	  DWORD  AllocationProtect;
//	  SIZE_T RegionSize;
//	  DWORD  State;
//	  DWORD  Protect;
//	  DWORD  Type;
//	} MEMORY_BASIC_INFORMATION, *PMEMORY_BASIC_INFORMATION;
//----------------------------------------------------------------------
BOOL IsPageReadWrite(LPVOID pAddress)
{
	MEMORY_BASIC_INFORMATION	mbi;
	size_t						zr;

	zr	= VirtualQuery((LPCVOID)pAddress, &mbi, sizeof(MEMORY_BASIC_INFORMATION));
	if (zr > 0)
	{
		return (mbi.Protect == PAGE_READWRITE);
	}
	return FALSE;
}


NS_PLIB_END

NS_PLIB_SYSTEM_BEGIN

//======================================================================
//	Init
//======================================================================
BOOL Init()
{
	GetSystemInfo(&siSystemInfo);
	return TRUE;
}

//======================================================================
//	Cleanup
//======================================================================
void Cleanup()
{
}

NS_PLIB_SYSTEM_END
#endif	//	NOT_USE_SYSTEM
