//	XLCTextEx_1.0x	:	XLCTextEx

//	XLError.h
//
#pragma once

XLOPER* WINAPI		XLCRegExError4(XLOPER* pxOption);
XLOPER12* WINAPI	XLCRegExError12(XLOPER* pxOption);

NS_XLCREGEX_BEGIN

//----------------------------------------------------------------------
//	LogError
//----------------------------------------------------------------------
void	LogError4(LPCSTR pszError);
void	LogError12(LPCWSTR pszError);

template<typename T_CHAR>
inline void LogError(const T_CHAR* pszError)
{
	THROWPE_LOGIC_ERROR("XLCRegEx::LogError");
	return;
}
template<>
inline void LogError<char>(LPCSTR pszError)
{
	LogError4(pszError);
}
template<>
inline void LogError<wchar_t>(LPCWSTR pszError)
{
	LogError12(pszError);
}

//----------------------------------------------------------------------
//	GetErrorLog
//----------------------------------------------------------------------
std::string*	GetErrorLog4(int iIndex = 0);
std::wstring*	GetErrorLog12(int iIndex = 0);

template<typename T_CHAR>
inline std::basic_string<T_CHAR>* GetErrorLog(int iIndex)
{
	THROWPE_LOGIC_ERROR("XLCRegEx::GetErrorLog");
	return;
}
template<>
inline std::string* GetErrorLog<char>(int iIndex)
{
	return GetErrorLog4(iIndex);
}
template<>
inline std::wstring* GetErrorLog<wchar_t>(int iIndex)
{
	return GetErrorLog12(iIndex);
}

//----------------------------------------------------------------------
//	ClearErrorLog
//----------------------------------------------------------------------
void	ClearErrorLog4();
void	ClearErrorLog12();

template<typename T_CHAR>
inline void ClearErrorLog()
{
	THROWPE_LOGIC_ERROR("XLCRegEx::ClearErrorLog");
	return;
}
template<>
inline void ClearErrorLog<char>()
{
	ClearErrorLog4();
}
template<>
inline void ClearErrorLog<wchar_t>()
{
	ClearErrorLog12();
}

//----------------------------------------------------------------------
//	CleanupErrorLog
//----------------------------------------------------------------------
void CleanupErrorLog();


NS_XLCREGEX_END
