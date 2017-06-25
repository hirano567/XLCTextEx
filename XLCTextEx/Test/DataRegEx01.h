//	XLCTextEx_1.0x	:	Test

//	DataRegEx01.h
//
#pragma once

//======================================================================
//	DataRegEx01a
//======================================================================
struct TDataRegEx01
{
	T_PCSTR_U	dsc;
	T_PCSTR_U	pat;
	T_PCSTR_U	rep;
	T_PCSTR_U	txt;
	T_PCSTR_U	opt;
};

//	00	空文字列の処理
extern TDataRegEx01	DataRegEx01_00[];
extern int			nDataRegEx01_00;

//	01	オプション
extern TDataRegEx01	DataRegEx01_01[];
extern int			nDataRegEx01_01;

//	02	エスケープシーケンス
extern TDataRegEx01	DataRegEx01_02[];
extern int			nDataRegEx01_02;

//	03	文字クラス
extern TDataRegEx01	DataRegEx01_03[];
extern int			nDataRegEx01_03;

//	04	位置による照合
extern TDataRegEx01	DataRegEx01_04[];
extern int			nDataRegEx01_04;

//	05	後方参照
extern TDataRegEx01	DataRegEx01_05[];
extern int			nDataRegEx01_05;

//	06	前方一致等
extern TDataRegEx01	DataRegEx01_06[];
extern int			nDataRegEx01_06;

//	07	量指定子
extern TDataRegEx01	DataRegEx01_07[];
extern int			nDataRegEx01_07;

//	08	選択
extern TDataRegEx01	DataRegEx01_08[];
extern int			nDataRegEx01_08;

//	09	ブラケット表現
extern TDataRegEx01	DataRegEx01_09[];
extern int			nDataRegEx01_09;

//	10	置換文字列
extern TDataRegEx01	DataRegEx01_10[];
extern int			nDataRegEx01_10;

//	11	エラー対策
extern TDataRegEx01	DataRegEx01_11[];
extern int			nDataRegEx01_11;
