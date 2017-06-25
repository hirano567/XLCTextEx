//	XLCTextEx_1.0x	:	PLibTextEx

//	PTransCharPreset.h
//
#pragma once

NS_PLIB_TEXTEX_BEGIN

//======================================================================
//	文字変換
//======================================================================
bool	ToHiragana(T_STRING_U* pstrBuf, T_PCSTR_U pSrc, T_PCSTR_U pSrcE);
bool	ToKatakana(T_STRING_U* pstrBuf, T_PCSTR_U pSrc, T_PCSTR_U pSrcE);
bool	ToZenkaku(T_STRING_U* pstrBuf, T_PCSTR_U pSrc, T_PCSTR_U pSrcE);
bool	ToZenkakuKana(T_STRING_U* pstrBuf, T_PCSTR_U pSrc, T_PCSTR_U pSrcE);
bool	ToHankaku(T_STRING_U* pstrBuf, T_PCSTR_U pSrc, T_PCSTR_U pSrcE);
bool	WidthFolding(T_STRING_U* pstrBuf, T_PCSTR_U pSrc, T_PCSTR_U pSrcE);

//======================================================================
//	初期化と終了処理
//======================================================================
bool	InitTrPreset();
void	CleanupTrPreset();

NS_PLIB_TEXTEX_END
