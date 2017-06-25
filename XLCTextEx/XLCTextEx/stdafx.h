//	XLCTextEx_1.0x	:	XLCTextEx

//	XLCTextEx_1.01	2013/06/02
//	XLCTextEx_1.02	2013/06/14

// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーから使用されていない部分を除外します。
// Windows ヘッダー ファイル:
#include <windows.h>

// TODO: プログラムに必要な追加ヘッダーをここで参照してください。

//#define	XLL_AVAILABLE_TO_EXCEL11
#undef	XLL_AVAILABLE_TO_EXCEL11

#include "PLib.h"
#include "PLibUCD.h"
#include "PLibTextEx.h"
#include "PLibXLL.h"

#ifndef	NS_XLCTEXTEX
#define	NS_XLCTEXTEX		XLCTextEx
#define	NS_XLCTEXTEX_BEGIN	namespace NS_XLCTEXTEX {
#define	NS_XLCTEXTEX_END	}
#endif

#ifndef	NS_XLCREGEX
#define	NS_XLCREGEX	XLCRegEx
#define	NS_XLCREGEX_BEGIN	namespace NS_XLCREGEX {
#define	NS_XLCREGEX_END		}
#endif

#ifndef	NS_XLCTR
#define	NS_XLCTR		XLCTr
#define	NS_XLCTR_BEGIN	namespace NS_XLCTR {
#define	NS_XLCTR_END	}
#endif

typedef	PLib::PCTransChar	CTRANSCHAR;

#include "XLCRegExError.h"
#include "XLCRegExUtility.h"
#include "XLCRegEx.h"

#include "XLCTrUtility.h"
#include "XLCTr.h"
#include "XLCGrep.h"

#include "XLCTextEx.h"
#include "dllmain.h"
#include "XLLMain.h"
#include "XLLTest.h"
