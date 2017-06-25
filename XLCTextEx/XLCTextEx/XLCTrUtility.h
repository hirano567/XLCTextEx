//	XLCTextEx_1.0x	:	XLCTextEx

//	XLCTrUtility.h
//
#pragma once

typedef	XLL::PCXLInstanceManager<T_CHAR_U, CTRANSCHAR>	XLTRMANANGER;

extern XLTRMANANGER*	pciTrManager;

NS_XLCTR_BEGIN

//======================================================================
//	システムの初期化と終了処理
//======================================================================
bool	Init();
void	Cleanup();

NS_XLCTR_END
