//	XLCTextEx_1.0x	:	PLibXLL

//	XLCTextEx_1.01	2013/06/02
//	XLCTextEx_1.02

//	PLibXLL.h
//
#pragma once

// Windows ヘッダー ファイル:
#include <windows.h>

#include <cstdlib>
#include <malloc.h>
#include <cstdio>
#include <tchar.h>
#include <memory.h>
#include <cstring>
#include <cwchar>
#include <string>
#include <exception>
#include <stdexcept>
#include <list>
#include <vector>
#include <strsafe.h>

#include <xlcall.h>
#include "FRAMEWRK.H"

#include "PLib.h"


//======================================================================
//	XLL で使用する定数
//======================================================================
// 表のサイズ
#define MAX_XL4_ROWS		65536
#define MAX_XL4_COLS		256
#define MAX_XL11_ROWS		65536
#define MAX_XL11_COLS		256
#define MAX_XL12_ROWS		1048576
#define MAX_XL12_COLS		16384

// 引数の最大個数
#define MAX_XL4_UDF_ARGS	30
#define MAX_XL11_UDF_ARGS	30
#define MAX_XL12_UDF_ARGS	255

// 文字列長の最大値
#define MAX_XL4_STR_LEN		255u
#define MAX_XL11_STR_LEN	255u
#define MAX_XL12_STR_LEN	32767u


//======================================================================
//	XLL で使用するデータ型
//======================================================================
//	内部では wchar_t で処理を行う。
typedef	wchar_t							T_CHAR_XLL;	//	XLL 内部の処理で使用する文字型
typedef	T_CHAR_XLL*						T_PSTR_XLL;
typedef	const T_CHAR_XLL*				T_PCSTR_XLL;
typedef	std::basic_string<T_CHAR_XLL>	T_STRING_XLL, *T_PSTRING_XLL;

typedef	XLREF	XLREF4, *LPXLREF4;
typedef	XLMREF	XLMREF4, *LPXLMREF4;
typedef	XLOPER	XLOPER4, *LPXLOPER4;

//	強制的に Excel4 として使用させる。
//#define	FORCE_EXCEL4

//	Excel4、Excel11 両方で使用する場合
#define	XLL_AVAILABLE_TO_EXCEL11
//#undef	XLL_AVAILABLE_TO_EXCEL11

#ifdef	XLL_AVAILABLE_TO_EXCEL11
#define	TEXTXLL(quote)	TEXTAW(quote)
#else
#define	TEXTXLL(quote)	L##quote
#endif

//======================================================================
//	namespace
//======================================================================
#define	NS_XLL	XLL
#define	NS_XLL_BEGIN	namespace NS_XLL {
#define	NS_XLL_END		}


//======================================================================
//	PLibXLL のインクルードファイル
//======================================================================
#include "XLLMemory.h"
#include "XLLStringUtility.h"
#include "XLLString.h"
#include "XLLFWUtility.h"
#include "XLLUtility.h"
#include "XLREFUtility.h"
#include "XLOPERUtility.h"
#include "XLOPERUtilityMulti.h"
#include "XLLSystem.h"
#include "XLLRegister.h"
#include "XLLError.h"
#include "XLLException.h"
#include "XLCAPIFunctions.h"
#include "XLInformation.h"
#include "XLCustomizing.h"
#include "XLWorkSheetFunctions.h"
#include "XLInstanceManager.h"
#include "XLLDebug.h"
