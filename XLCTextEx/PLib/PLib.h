//	XLCTextEx_1.0x	:	PLib

//	XLCTextEx_1.01	2013/06/02
//	XLCTextEx_1.02	2013/06/14

//	PLib.h
//
#pragma once

#include <windows.h>
#include <Winnls.h>
#include <tchar.h>
#include <string.h>
#include <wchar.h>
#include <math.h>
#include <limits>
#include <string>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <bitset>
#include <utility>
#include <exception>
#include <stdexcept>
#include <strsafe.h>

//======================================================================
//	プロジェクト内で使用するマクロと型
//======================================================================
//#define DEBUG_PROJECT
#undef	DEBUG_PROJECT
#if defined(_DEBUG) && defined(DEBUG_PROJECT)
#define	PDEBUG
#else
#undef	PDEBUG
#endif

//#define	PROFILE
#if defined(PDEBUG) && defined(PROFILE)
#define	PDEBUG_PROFILE
#else
#undef	PDEBUG_PROFILE
#endif


#ifndef NS_PLIB
#define NS_PLIB			PLib
#define NS_PLIB_BEGIN	namespace NS_PLIB {
#define NS_PLIB_END		}
#endif

#ifndef	MAX_STR_LENGTH
#define	MAX_STR_LENGTH	INT_MAX
#endif

typedef wchar_t						T_CHAR_U;
typedef	const T_CHAR_U				T_CCHAR_U;
typedef	T_CHAR_U*					T_PSTR_U;
typedef	const T_CHAR_U*				T_PCSTR_U;
typedef	std::basic_string<T_CHAR_U>	T_STRING_U, *T_PSTRING_U;

#define	TQU(quote)	L##quote

//	Unicode Codepoint を扱うための型

typedef	UINT						T_UCP;		//	Codepoint は unsigned int に格納する。
typedef	std::basic_string<T_UCP>	UCPSTRING;
typedef	UCPSTRING::iterator			ITR_UCPSTRING;

#define	TQ_UCP(quote)	((T_UCP)TQU(quote))
//	TQ_UCP の quote は ' ' のみ

#define	IS_7BIT(c)	(((c) | 0x7F) == 0x7F)
#define	IS_16BIT(c)	(((c) | 0xFFFF) == 0xFFFF)

#define	ISSPACE_U(c)	(IS_16BIT(c) && (iswspace((wint_t)(c)) != 0))
#define	ISCNTRL_U(c)	(IS_7BIT(c) && (iswcntrl((wint_t)(c)) != 0))
#define	ISGRAPH_U(c)	(IS_16BIT(c) && iswgraph((wint_t)(c)) != 0)
#define	ISPRINT_U(c)	(IS_16BIT(c) && iswprint((wint_t)(c)) != 0)
#define	ISPUNCT_U(c)	(IS_16BIT(c) && iswpunct((wint_t)(c)) != 0)
#define	ISXDIGIT_U(c)	(IS_16BIT(c) && iswxdigit((wint_t)(c)) != 0)

#define	TOUPPER_U(c)	towupper((wint_t)c)
#define	TOLOWER_U(c)	towlower((wint_t)c)

#define	STRLEN_U		wcslen
#define	CHARUPPER_U		CharUpperW
#define	SPRINTF_U		swprintf_s


//======================================================================
//	文字リテラル、文字列リテラルの型を処理するためのデータ型とマクロ
//======================================================================
struct PSTRAW
{
	LPSTR	a;
	LPWSTR	w;
};

struct PCSTRAW
{
	LPCSTR	a;
	LPCWSTR	w;
};

#ifndef TEXTAW
#define	TEXTAW(quote)	quote, L##quote
#endif

#define	TEXTAW_NULL		NULL, NULL
#define	TEXTAW_EMPTY	"",	L""
#define	TEXTAW_NOARG	TEXTAW_EMPTY

//----------------------------------------------------------------------
//	t_Char
//----------------------------------------------------------------------
template<typename T_CHAR>
inline T_CHAR t_Char(char a, wchar_t w)
{
	throw std::logic_error("t_Str: invalid parameter");
	return (T_CHAR)NULL;
}
template<>
inline char t_Char<char>(char a, wchar_t w)
{
	return a;
}
template<>
inline wchar_t t_Char<wchar_t>(char a, wchar_t w)
{
	return w;
}

//----------------------------------------------------------------------
//	t_Str	:	LPCSTR と LPCWSTR を引数とする。
//----------------------------------------------------------------------
template<typename T_CHAR>
inline const T_CHAR* t_Str(LPCSTR pa, LPCWSTR pw)
{
	throw std::logic_error("t_Str: invalid parameter");
	return NULL;
}
template<>
inline LPCSTR t_Str<char>(LPCSTR pa, LPCWSTR pw)
{
	return pa;
}
template<>
inline LPCWSTR t_Str<wchar_t>(LPCSTR pa, LPCWSTR pw)
{
	return pw;
}

//----------------------------------------------------------------------
//	t_Str	:	LPCSTR* または LPCWSTR* のいずれかを引数とする。
//----------------------------------------------------------------------
template<typename T_CHAR>
inline const T_CHAR* t_Str(const T_CHAR** pp)
{
	throw std::logic_error("t_Str: invalid parameter");
	return NULL;
}
template<>
inline LPCSTR t_Str<char>(LPCSTR* pp)
{
	return *pp;
}
template<>
inline LPCWSTR t_Str<wchar_t>(LPCWSTR* pp)
{
	return *pp;
}

//----------------------------------------------------------------------
//	t_Str	:	PCSTRAW を引数とする。
//----------------------------------------------------------------------
template<typename T_CHAR>
inline const T_CHAR* t_Str(PCSTRAW* ppaw)
{
	throw std::logic_error("t_Str: invalid parameter");
	return NULL;
}
template<>
inline LPCSTR t_Str<char>(PCSTRAW* ppaw)
{
	return ppaw->a;
}
template<>
inline LPCWSTR t_Str<wchar_t>(PCSTRAW* ppaw)
{
	return ppaw->w;
}

//======================================================================
//	そのほかのマクロ
//======================================================================
#define	TO_MULTIPLE_NUMBER(n, b)	((n + b - 1) / b) * b

//----------------------------------------------------------------------
//	t_MessageBox	: MessageBox のテンプレート
//----------------------------------------------------------------------
template<typename T_CHAR>
inline int t_MessageBox(HWND hWnd, const T_CHAR* pszMessage, const T_CHAR* pszTitle, UINT uType)
{
	throw std::logic_error("t_MessageBox");
	return 0;
}
template<>
inline int t_MessageBox<char>(HWND hWnd, LPCSTR pszMessage, LPCSTR pszTitle, UINT uType)
{
	return MessageBoxA(hWnd, pszMessage, pszTitle, uType);
}
template<>
inline int t_MessageBox<wchar_t>(HWND hWnd, LPCWSTR pszMessage, LPCWSTR pszTitle, UINT uType)
{
	return MessageBoxW(hWnd, pszMessage, pszTitle, uType);
}


//======================================================================
//	プロジェクト内のインクルードファイル
//======================================================================
#include "MemoryPool.h"
#include "MemoryManager.h"

#include "PDebug.h"

#include "PError.h"
#include "PException.h"
#include "PMemory.h"
#include "PCharUtility.h"
#include "PStringUtility.h"
#include "PFilePath.h"
#include "PCompareString.h"
#include "PUnicode.h"
#include "PGClass.h"
#include "PCodePage.h"
#include "PSearch.h"
#include "PSystem.h"
#include "PWindowUtility.h"
#include "PClipboard.h"

//======================================================================
//	PLib.cpp 用
//======================================================================
NS_PLIB_BEGIN

bool	Init();
void	Cleanup();

NS_PLIB_END
