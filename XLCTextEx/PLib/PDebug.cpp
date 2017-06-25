//	XLCTextEx_1.0x	:	PLib

//	PDebug.h
//
#include "stdafx.h"

NS_PLIB_DEBUG_BEGIN
#ifdef	PDEBUG

//======================================================================
//	std::basic_string 用の Debug ユーティリティ
//======================================================================
//----------------------------------------------------------------------
//	AppendCodepointToString
//----------------------------------------------------------------------
bool AppendCodepointToString(std::wstring* pString, T_UCP cpSrc)
{
	T_CHAR_U	Buf[3];

	if (pString == NULL)	return false;
	if (IS_16BIT(cpSrc) && PLib::t_IsCntrl<T_CHAR_U>(cpSrc))
	{
		PLib::AppendNumToString<T_CHAR_U, UINT>(pString, t_Str<T_CHAR_U>("(%02X)", L"(%04X)"), (UINT)cpSrc);
	}
	else
	{
		if (PLib::Unicode::ConvertFromCodepoint(Buf, cpSrc))
		{
			pString->append(Buf);
		}
		else
		{
			THROWPE_RUNTIME_ERROR("AppendCodepointToString");
		}
	}
	return true;
}

//======================================================================
//	Profile
//======================================================================
//----------------------------------------------------------------------
//	PCTickCounters のインスタンス
//----------------------------------------------------------------------
PCTickCounters*	pciRegExProfiler	= NULL;

//----------------------------------------------------------------------
//
//----------------------------------------------------------------------
size_t Profiler_Size()
{
	return pciRegExProfiler->Size();
}

void Profiler_Reset()
{
	pciRegExProfiler->Reset();
}

void Profiler_Reset(UINT i)
{
	pciRegExProfiler->Reset(i);
}

void Profiler_Start(UINT i)
{
	pciRegExProfiler->Start(i);
}

void Profiler_Stop(UINT i)
{
	pciRegExProfiler->Stop(i);
}

DWORD Profiler_GetInterval(UINT i)
{
	return pciRegExProfiler->GetInterval(i);
}

DWORD Profiler_GetTotal(UINT i)
{
	return pciRegExProfiler->GetTotal(i);
}

void Profiler_SetDesc(UINT i, T_PCSTR_U pszDesc)
{
	pciRegExProfiler->SetDesc(i, pszDesc);
}

void Profiler_GetTotal(T_STRING_U* pstrBuf, T_PCSTR_U pszFmt)
{
	pciRegExProfiler->GetTotal(pstrBuf, pszFmt);
}


//======================================================================
//	デバッグ用のログ
//======================================================================
LPCSTR			pszEmptyA	= "";
LPCWSTR			pszEmptyW	= L"";

//----------------------------------------------------------------------
//	class PCLogManager
//	デバッグ用のログを管理するためのクラス
//----------------------------------------------------------------------
template<typename T_CHAR>
class PCLogManager
{
private:
	typedef	const T_CHAR*					T_PCSTR;
	typedef	std::basic_string<T_CHAR>		T_STRING, *T_PSTRING;
	typedef	std::vector<T_PSTRING>			CLOGARRAY;
	typedef	typename CLOGARRAY::iterator	ITR_CLOGARRAY;

	CLOGARRAY	ciLogArray;

public:
	PCLogManager()	{};
	~PCLogManager();

	void		Clear();
	void		AppendLogString(int i);
	T_PSTRING	GetLogString(int i);
};

#define	TEMPLATE_HEADER_PCLOGMANAGER	template<typename T_CHAR>
#define	PCLASS_LOGMANAGER				PCLogManager<T_CHAR>

TEMPLATE_HEADER_PCLOGMANAGER
PCLASS_LOGMANAGER::~PCLogManager()
{
	Clear();
}

TEMPLATE_HEADER_PCLOGMANAGER
void PCLASS_LOGMANAGER::Clear()
{
	ITR_CLOGARRAY	itr;

	for (itr = ciLogArray.begin(); itr != ciLogArray.end(); ++itr)
	{
		delete (*itr);
	}
}

TEMPLATE_HEADER_PCLOGMANAGER
void PCLASS_LOGMANAGER::AppendLogString(int i)
{
	T_PSTRING	ps;

	while (ciLogArray.size() <= (UINT)i)
	{
		ps	= new T_STRING;
		ciLogArray.push_back(ps);
	}
}

TEMPLATE_HEADER_PCLOGMANAGER
std::basic_string<T_CHAR>* PCLASS_LOGMANAGER::GetLogString(int i)
{
	AppendLogString(i);
	return ciLogArray.at(i);
}

//----------------------------------------------------------------------
//	PCLogManager のインスタンス
//----------------------------------------------------------------------
PCLogManager<char>*		pciLogManagerA	= NULL;
PCLogManager<wchar_t>*	pciLogManagerW	= NULL;

CRITICAL_SECTION	csLogA;
CRITICAL_SECTION	csLogW;

//----------------------------------------------------------------------
//	ClearLog
//----------------------------------------------------------------------
void ClearLogA(int i)
{
	EnterCriticalSection(&csLogA);
	try
	{
		if (pciLogManagerA != NULL)
		{
			pciLogManagerA->GetLogString(i)->clear();
		}
	}
	catch (...)
	{
	}
	LeaveCriticalSection(&csLogA);
	return;
}

void ClearLogW(int i)
{
	EnterCriticalSection(&csLogW);
	try
	{
		if (pciLogManagerW != NULL)
		{
			pciLogManagerW->GetLogString(i)->clear();
		}
	}
	catch (...)
	{
	}
	LeaveCriticalSection(&csLogW);
	return;
}

//----------------------------------------------------------------------
//	Log
//----------------------------------------------------------------------
void LogA(LPCSTR pStr, int i)
{
	EnterCriticalSection(&csLogA);
	try
	{
		if (pciLogManagerA != NULL)
		{
			pciLogManagerA->GetLogString(i)->append(pStr);
			pciLogManagerA->GetLogString(i)->append("\r\n");
		}
	}
	catch (...)
	{
	}
	LeaveCriticalSection(&csLogA);
	return;
}

void LogW(LPCWSTR pStr, int i)
{
	EnterCriticalSection(&csLogW);
	try
	{
		if (pciLogManagerW != NULL)
		{
			pciLogManagerW->GetLogString(i)->append(pStr);
			pciLogManagerW->GetLogString(i)->append(L"\r\n");
		}
	}
	catch (...)
	{
	}
	LeaveCriticalSection(&csLogW);
	return;
}

//----------------------------------------------------------------------
//	GetLog
//----------------------------------------------------------------------
void GetLogA(std::string* pBuf, int i)
{
	EnterCriticalSection(&csLogA);
	try
	{
		if (pciLogManagerA != NULL)
		{
			pBuf->append(*(pciLogManagerA->GetLogString(i)));
		}
	}
	catch (...)
	{
	}
	LeaveCriticalSection(&csLogA);
	return;
}

void GetLogW(std::wstring* pBuf, int i)
{
	EnterCriticalSection(&csLogW);
	try
	{
		if (pciLogManagerW != NULL)
		{
			pBuf->append(*(pciLogManagerW->GetLogString(i)));
		}
	}
	catch (...)
	{
	}
	LeaveCriticalSection(&csLogW);
	return;
}


//======================================================================
//	初期化と終了処理
//======================================================================
void Init()
{
	pciRegExProfiler	= new PCTickCounters;	

	InitializeCriticalSection(&csLogA);
	InitializeCriticalSection(&csLogW);

	pciLogManagerA	= new PCLogManager<char>;
	pciLogManagerW	= new PCLogManager<wchar_t>;
}

void Cleanup()
{
	delete	pciLogManagerA;
	delete	pciLogManagerW;

	delete	pciRegExProfiler;
}

//----------------------------------------------------------------------
//	GetLogString
//----------------------------------------------------------------------
std::string* GetLogStringA(int i)
{
	return pciLogManagerA->GetLogString(i);
}

std::wstring* GetLogStringW(int i)
{
	return pciLogManagerW->GetLogString(i);
}

#else
//======================================================================
//	デバッグ用のログ	（Release 版用 dummy）
//======================================================================
void	Init()		{}
void	Cleanup()	{}

#endif	//	PDEBUG
NS_PLIB_DEBUG_END
