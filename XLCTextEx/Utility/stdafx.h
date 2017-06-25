//	XLCTextEx_1.1x	:	Utility

// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

#define	_CRTDBG_MAP_ALLOC
#include "targetver.h"

#include <windows.h>
#include <cstdlib>
#include <crtdbg.h>	//	メモリ リーク検出
#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <tchar.h>
#include <string>

// TODO: プログラムに必要な追加ヘッダーをここで参照してください。
#include "PLib.h"
#include "PLibUCD.h"
#include "PLibTextEx.h"

#ifndef	NS_UTILITY
#define	NS_UTILITY			PUtility
#define	NS_UTILITY_BEGIN	namespace NS_UTILITY	{
#define	NS_UTILITY_END		}
#endif

void	UtilityUCD01();
