//	XLCTextEx_1.0x	:	Test

//	XLCTextEx_1.01	2013/06/02
//	XLCTextEx_1.02

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
#include <math.h>
#include <string>
#include <iostream>

// TODO: プログラムに必要な追加ヘッダーをここで参照してください。
#include "PLib.h"
#include "PLibUCD.h"
#include "PLibTextEx.h"

#ifndef	NS_TEST
#define	NS_TEST			PTest
#define	NS_TEST_BEGIN	namespace NS_TEST	{
#define	NS_TEST_END		}
#endif

#include "TestUtility.h"
#include "DataRegEx01.h"
#include "DataRegEx02.h"
#include "DataRegEx03.h"
#include "DataRegEx05.h"

void	TestPLib01();
void	TestPUCD01();
void	TestPRegEx01();
void	TestPRegEx02();
void	TestPRegEx03();
void	TestPRegEx05();
void	TestPTr01();

void	Prototype01();

