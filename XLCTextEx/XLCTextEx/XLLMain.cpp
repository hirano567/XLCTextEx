//	XLCTextEx_1.0x	:	XLCTextEx

//	XLLMain.cpp
//
#include "stdafx.h"

#undef	REGISTER_XLLFUNCTIONS
#undef	REGISTER_COMMANDFUNCTIONS
#undef	REGISTER_MENUITEMS
#undef	REGISTER_TOOLBARITEMS

#define	REGISTER_XLLFUNCTIONS
//#define	REGISTER_COMMANDFUNCTIONS
//#define	REGISTER_MENUITEMS
//#define	REGISTER_TOOLBARITEMS


//======================================================================
//	XLL 関数を登録・解除するためのデータと関数
//======================================================================
#ifdef REGISTER_XLLFUNCTIONS

const int	nParamsRgXLLFunc	= 15;

typedef	PCSTRAW PAW_RGXLLFUNCTION[nParamsRgXLLFunc];

static PAW_RGXLLFUNCTION	pawRgXLLFunctions[] =
{
//	TEXTAW(""),	//	DLL のコード中に現れる関数名。
//	TEXTAW(""),	//	引数の型と戻り値の型を指定する文字列。
//	TEXTAW(""),	//	関数ウィザードで表示される関数名。
//	TEXTAW(""),	//	省略可能。引数を説明する文字列。
//	TEXTAW(""),	//	XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
//	TEXTAW(""),	//	関数が属するカテゴリ。省略可能。
//	TEXTAW(""),	//	ショートカットキー。１文字。大文字小文字は区別される。
//	TEXTAW(""),	//	ヘルプファイルへの参照（パスも含む）。省略可能。
//	TEXTAW(""),	//	関数ウィザードで表示されるテキスト。省略可能。
//	TEXTAW(""),	//	1 番目の引数の説明。省略可能。
//	TEXTAW(""),	//	2 番目の引数の説明。省略可能。
//	TEXTAW(""),	//	3 番目の引数の説明。省略可能。
//	TEXTAW(""),	//	4 番目の引数の説明。省略可能。
//	TEXTAW(""),	//	5 番目の引数の説明。省略可能。
//	TEXTAW(""),	//	6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//
	//------------------------------------------------------------
	/*
	"XLCRegExCreateA",	//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCRegExCreate",	//	(xltypeStr) DLL のコード中に現れる関数名。

	"PP",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"QQ",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	"XLCRegExCreateA",	//	(xltypeStr) 関数ウィザードで表示される関数名。
	L"XLCRegExCreate",	//	(xltypeStr) 関数ウィザードで表示される関数名。

	TEXTAW("引数は インデックスと URL"),		//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("リソース取得の準備をする。"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("割り当てるインデックス（整数値）"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW("URL"),				//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。
	*/

	//------------------------------------------------------------
	//
	//------------------------------------------------------------
	/*
	"XLCRegExReplaceA",	//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCRegExReplace",	//	(xltypeStr) DLL のコード中に現れる関数名。

	"PPPPP",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"QQQQQ",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	"XLCRegExReplaceA",	//	(xltypeStr) 関数ウィザードで表示される関数名。
	L"XLCRegExReplace",	//	(xltypeStr) 関数ウィザードで表示される関数名。

	TEXTAW("引数は インデックスと ID"),		//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("ID に対応する部分を取得する。"),	//	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("正規表現"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW("出力書式"),				//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW("対象テキスト"),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW("大文字小文字"),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。
	*/

	//------------------------------------------------------------
	//	XLCRegExCreate
	//------------------------------------------------------------
	"XLCRegExCreate4",		//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCRegExCreate12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PPPP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQQQ",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RPPP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQQ",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCRegExCreate"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("引数は パターンとオプション"),		//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("パターンを登録する"),	//	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("割り当てる番号"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW("パターン"),		//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW("オプション"),	//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCRegExDelete
	//------------------------------------------------------------
	"XLCRegExDelete4",		//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCRegExDelete12",		//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQ",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQ",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCRegExDelete"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("引数は番号"),	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("パターンを削除する"),	//	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("削除する番号"),			//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCRegExClear
	//------------------------------------------------------------
	"XLCRegExClear4",		//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCRegExClear12",		//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQ",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQ",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCRegExClear"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("引数は削除対象を示す BOOL 値"),	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("パターンをすべて削除する"),	//	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("TRUE ならすべて、FALSE なら現シートのみ"),	//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCRegExCreateReplacement
	//------------------------------------------------------------
	"XLCRegExCreateReplacement4",		//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCRegExCreateReplacement12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PPPP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQQQ",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RPPP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQQ",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCRegExCreateReplacement"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("引数は置換文字列とオプション"),		//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("置換文字列を登録する"),	//	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("割り当てる番号"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW("出力書式"),		//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW("オプション"),	//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCRegExDeleteReplacement
	//------------------------------------------------------------
	"XLCRegExDeleteReplacement4",		//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCRegExDeleteReplacement12",		//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQ",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQ",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCRegExDeleteReplacement"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("引数は番号"),	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("置換文字列を削除する"),	//	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("削除する番号"),			//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCRegExClearReplacement
	//------------------------------------------------------------
	"XLCRegExClearReplacement4",		//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCRegExClearReplacement12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQ",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQ",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCRegExClearReplacement"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("引数は削除対象を示す BOOL 値"),	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("置換文字列をすべて削除する"),	//	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("TRUE ならすべて、FALSE なら現シートのみ"),	//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCRegExMatch
	//------------------------------------------------------------
	"XLCRegExMatch4",	//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCRegExMatch12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PPPPP",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQQQQ",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RPPP",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQQ$",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCRegExMatch"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("パターン（の番号）、対象テキスト、オプション"),
	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("パターンにテキストがマッチしているか調べる"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("パターン"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW("対象テキスト"),	//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW("オプション"),	//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCRegExFormat
	//------------------------------------------------------------
	"XLCRegExFormat4",	//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCRegExFormat12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PPPPP",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQQQQ",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RPPPP",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQQQ$",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCRegExFormat"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("パターン（の番号）、書式（の番号）、対象テキスト、オプション"),
	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("パターンと書式に従ってテキストを整形する"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("パターン"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW("出力書式"),		//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW("対象テキスト"),	//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW("オプション"),	//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCRegExFormatIf
	//------------------------------------------------------------
	"XLCRegExFormatIf4",	//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCRegExFormatIf12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PPPPP",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQQQQ",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RPPPPP",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQQQQ$",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCRegExFormatIf"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("パターン（の番号）、書式（の番号）、対象テキスト、オプション"),
	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("パターンと書式に従ってテキストを整形する"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("パターン"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW("マッチした場合の出力書式")	,		//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW("マッチしなかった場合の出力文字列"),	//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW("対象テキスト"),	//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW("オプション"),	//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCRegExReplace
	//------------------------------------------------------------
	"XLCRegExReplace4",		//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCRegExReplace12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PPPPP",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQQQQ",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RPPPP",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQQQ$",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCRegExReplace"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("パターン（の番号）、書式（の番号）、対象テキスト、オプション"),
	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("パターンと書式に従ってテキストを整形する"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("パターン"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW("出力書式"),		//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW("対象テキスト"),			//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW("パターンのオプション"),	//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCRegExValue
	//------------------------------------------------------------
	"XLCRegExValue4",		//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCRegExValue12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PPPPP",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQQQQ",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RPPPPP",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQQQQ$",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCRegExValue"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("パターン（の番号）、書式（の番号）、対象テキスト、オプション、代替値"),
	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("パターンと書式に従ってテキストから数値を取り出す"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("パターン"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW("出力書式"),		//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW("対象テキスト"),			//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW("パターンのオプション"),	//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW("エラー時に出力する値"),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCRegExError
	//------------------------------------------------------------
	"XLCRegExError4",		//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCRegExError12",		//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQ",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQ",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCRegExError"),	//	(xltypeStr) 関数ウィザードで表示される関数名。

	TEXTAW(""),				//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("エラーメッセージを取得する。"),		//	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("メッセージ番号（最新が 0）"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCTrCreate
	//------------------------------------------------------------
	"XLCTrCreate4",	//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCTrCreate12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PPPPP",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQQQQ",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RPPPP",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQQQ",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCTrCreate"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("ID、変換元文字、変換先文字、オプション"),
	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW(""),				//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("文字変換を登録する。"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("ID となる整数値"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW("変換先の文字を並べた文字列"),		//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW("変換先の文字を並べた文字列"),	//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW("オプション"),	//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCTrDelete
	//------------------------------------------------------------
	"XLCTrDelete4",	//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCTrDelete12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PPPPP",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQQQQ",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RP",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQ",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCTrDelete"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("ID"),
	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW(""),				//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("登録した文字変換を削除する。"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("割り当てた ID"),	//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW(""),					//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW(""),					//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),					//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),					//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),					//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCTr
	//------------------------------------------------------------
	"XLCTr4",	//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCTr12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	"RPPPP",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQQQ$",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCTr"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("変換元文字、変換先文字、対象テキスト、オプション"),
	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("セル内の文字を対応する文字に置き換える関数"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("変換先の文字を並べた文字列"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW("変換先の文字を並べた文字列"),		//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW("対象テキスト"),	//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW("オプション"),	//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCToHiragana
	//------------------------------------------------------------
	"XLCToHiragana4",	//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCToHiragana12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	"RPP",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQ$",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCToHiragana"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("対象テキスト"),	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("セル内の文字をひらがなに置換する関数"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("対象テキスト"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCToKatakana
	//------------------------------------------------------------
	"XLCToKatakana4",	//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCToKatakana12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	"RPP",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQ$",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCToKatakana"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("対象テキスト"),	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("セル内の文字をカタカナに置換する関数"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("対象テキスト"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCToZenkaku
	//------------------------------------------------------------
	"XLCToZenkaku4",	//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCToZenkaku12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	"RPP",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQ$",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCToZenkaku"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("対象テキスト"),	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("セル内の文字を全角に置換する関数"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("対象テキスト"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCToZenkakuKana
	//------------------------------------------------------------
	"XLCToZenkakuKana4",	//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCToZenkakuKana12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	"RPP",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQ$",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCToZenkakuKana"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("対象テキスト"),		//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),				//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),			//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),					//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),					//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("セル内のカナ文字を全角に置換する関数"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("対象テキスト"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCToHankaku
	//------------------------------------------------------------
	"XLCToHankaku4",	//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCToHankaku12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	"RPP",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQ$",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCToHankaku"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("対象テキスト"),	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("セル内の文字を全角に置換する関数"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("対象テキスト"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCNormalizeWidth
	//------------------------------------------------------------
	"XLCNormalizeWidth4",	//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCNormalizeWidth12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	"RPP",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQ$",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCNormalizeWidth"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("対象テキスト"),	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("英数を半角に、カタカナを全角に変換する関数"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("対象テキスト"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCGrep
	//------------------------------------------------------------
	"XLCGrep4",		//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCGrep12",	//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PPPPP",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQQQQ",			//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"JDDD",				//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"JD%D%D%$",		//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCGrep"),	//	(xltypeStr) 関数ウィザードで表示される関数名。
	TEXTAW("パターン、オプション1、オプション2"),
	//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("2"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("パターンにマッチする行を取り出す。"), //	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("パターン"),		//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW("正規表現のオプション"),		//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW("その他のオプション"),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

	//------------------------------------------------------------
	//	XLCTextExSet
	//------------------------------------------------------------
	"XLCTextExSet4",			//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCTextExSet12",		//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQ",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RPPP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQQQ",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCTextExSet"),	//	(xltypeStr) 関数ウィザードで表示される関数名。

	TEXTAW(""),				//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("TextEx 設定"),	//	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW(""),				//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。

#ifdef	PDEBUG
	//------------------------------------------------------------
	//	XLCTextExTest
	//------------------------------------------------------------
	"XLCTextExTest4",			//	(xltypeStr) DLL のコード中に現れる関数名。
	L"XLCTextExTest12",		//	(xltypeStr) DLL のコード中に現れる関数名。

	//"PP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	//L"QQ",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	"RP",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
	L"UQ",					//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。

	TEXTAW("XLCTextExTest"),	//	(xltypeStr) 関数ウィザードで表示される関数名。

	TEXTAW(""),				//	(xltypeStr) 省略可能。引数を説明する文字列。
	TEXTAW("1"),			//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
	TEXTAW("TextEx"),		//	(xltypeStr) 関数が属するカテゴリ。省略可能。
	TEXTAW(""),				//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
	TEXTAW(""),				//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
	TEXTAW("作成補助、テスト用。"),	//	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
	TEXTAW("引数に制限はない。"),	//	(xltypeStr) 1 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 2 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 3 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 4 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 5 番目の引数の説明。省略可能。
	TEXTAW(""),				//	(xltypeStr) 6 番目の引数の説明。省略可能。
#endif
};

static int	nRgXLLFunctions		= sizeof(pawRgXLLFunctions) / sizeof(PAW_RGXLLFUNCTION);
static BOOL	bRegisterXLLFunctions	= FALSE;

#endif


//======================================================================
//	コマンド関数の登録・解除をするためのデータと関数
//======================================================================
#ifdef REGISTER_COMMANDFUNCTIONS

const int	irgCommandArgs	= 15;

//static RGFUNCTIONARGS rgCommandFunctions[] =
static PCSTRAW rgCommands[][irgCommandArgs] =
{
//	7,
//	TEXTAW(""),	//	(xltypeStr) DLL のコード中に現れる関数名。
//	TEXTAW(""),	//	(xltypeStr) 引数の型と戻り値の型を指定する文字列。
//	TEXTAW(""),	//	(xltypeStr) 関数ウィザードで表示される関数名。
//	TEXTAW(""),	//	(xltypeStr) 省略可能。引数を説明する文字列。
//	TEXTAW(""),	//	(xltypeNum) XLL のエントリポイントのタイプ。省略可能(既定値は 1)。
//	TEXTAW(""),	//	(xltypeStr) 関数が属するカテゴリ。省略可能。
//	TEXTAW(""),	//	(xltypeStr) ショートカットキー。１文字。大文字小文字は区別される。
//	TEXTAW(""),	//	(xltypeStr) ヘルプファイルへの参照（パスも含む）。省略可能。
//	TEXTAW(""),	//	(xltypeStr) 関数ウィザードで表示されるテキスト。省略可能。
//	TEXTAW(""),	//	(xltypeStr) 1 番目の引数の説明。省略可能。
//	TEXTAW(""),	//	(xltypeStr) 2 番目の引数の説明。省略可能。
//	TEXTAW(""),	//	(xltypeStr) 3 番目の引数の説明。省略可能。
//	TEXTAW(""),	//	(xltypeStr) 4 番目の引数の説明。省略可能。
//	TEXTAW(""),	//	(xltypeStr) 5 番目の引数の説明。省略可能。
//	TEXTAW(""),	//	(xltypeStr) 6 番目の引数の説明。省略可能。
};

static int	irgCommands			= sizeof(rgCommands) / (sizeof(PCSTRAW) * irgCommandArgs);
static BOOL	bRegisterCommands	= FALSE;

//----------------------------------------------------------------------
//	RegisterCommandFunctions
//----------------------------------------------------------------------
static BOOL RegisterCommandFunctions()
{
	BOOL	bRet;

	if (XLL::IsExcel12())
	{
		//	Excel12
		bRet	= t_RegisterFunctions<XLOPER12>((PCSTRAW*)rgCommands, irgCommands, irgCommandArgs);
	}
	else
	{
		//	Excel4
		bRet	= t_RegisterFunctions<XLOPER>((PCSTRAW*)rgCommands, irgCommands, irgCommandArgs);
	}

	bRegisterCommands	= TRUE;
	return TRUE;
}

//----------------------------------------------------------------------
//	UnregisterCommandFunctions
//----------------------------------------------------------------------
static BOOL UnregisterCommandFunctions()
{
	BOOL	bRet;

	if (!bRegisterCommands)	return TRUE;

	if (XLL::IsExcel12())
	{
		//	Excel12
		bRet	= t_UnRegisterFunctions<XLOPER12>((PCSTRAW*)rgCommands, irgCommands, irgCommandArgs);
	}
	else
	{
		//	Excel4
		bRet	= t_UnRegisterFunctions<XLOPER>((PCSTRAW*)rgCommands, irgCommands, irgCommandArgs);
	}

	return TRUE;
}

#endif


//======================================================================
//	メニュー項目を登録・解除をするためのデータと関数
//======================================================================
#ifdef	REGISTER_MENUITEMS

PCSTRAW rgMenus[][NUM_MENUARGS] =
{
//	TEXTAW(""),	//	コマンドの名前
//	TEXTAW(""),	//	実行されるマクロ
//	TEXTAW(""),	//	ショートカットキー（Macintosh 版のみ）
//	TEXTAW(""),	//	ステータスバーに表示されるテキスト
//	TEXTAW(""),	//	ヘルプ用のテキスト
};

int			irgMenus	= sizeof(rgMenus) / (sizeof(PCSTRAW) * NUM_MENUARGS);

static BOOL	bRegisterMenuItems	= FALSE;

//----------------------------------------------------------------------
//	RegisterMenuItems
//----------------------------------------------------------------------
static BOOL RegisterMenuItems()
{
#ifndef	NOT_REGISTER_MENUITEMS

	BOOL	bRet;

	if (XLL::IsExcel12())
	{
		//	Excel12
		bRet	= t_AddMenu<XLOPER12>((PCSTRAW*)rgMenus, irgMenus);
	}
	else
	{
		//	Excel4
		bRet	= t_AddMenu<XLOPER>((PCSTRAW*)rgMenus, irgMenus);
	}

	bRegisterMenuItems	= TRUE;
	return TRUE;
}

//----------------------------------------------------------------------
//	UnregisterMenuItems
//----------------------------------------------------------------------
static BOOL UnregisterMenuItems()
{
	BOOL	bRet;

	if (!bRegisterMenuItems)	return TRUE;

	if (XLL::IsExcel12())
	{
		//	Excel12
		bRet	= t_DeleteMenu<XLOPER12>();
	}
	else
	{
		//	Excel4
		bRet	= t_DeleteMenu<XLOPER>();
	}
	return TRUE;
}

#endif


//======================================================================
//	ツールバー項目を登録・解除をするためのデータと関数
//======================================================================
#ifdef	REGISTER_TOOLBARITEMS

const int	nrgToolArgs	= 9;
typedef	PCSTRAW	RGTOOLARGS[nrgToolArgs];

static RGTOOLARGS rgTools[] =
{
//	TEXTAW(""),			//	xltypeStr	ツールに関連した番号か名前。
//	TEXTAW(""),			//	xltypeStr	実行されるマクロ
//	TEXTAW("FALSE"),	//	xltypeBOOL	Down
//	TEXTAW("TRUE"),	//	Enabled
//	TEXTAW(""),	//	Face
//	TEXTAW(""),	//	Status_text
//	TEXTAW(""),	//	Ballon_text
//	TEXTAW(""),	//	Help_topic
//	TEXTAW(""),	//	Tip_text
};

static RGTOOLARGS rgTools[] =
{
//	TEXTAW(""),	//	xltypeStr	ツールの名前。（番号も可。）
//	TEXTAW(""),	//	xltypeStr	マクロの名前。
//	FALSE,		//	xltypeBool	押された状態で表示する。
//	TRUE,		//	xltypeBool	使用可能。
//	TEXTAW(""),	//	xltypeStr	画像への参照。
//	TEXTAW(""),	//	xltypeStr	ステータスバーに表示するテキスト。
//	TEXTAW(""),	//	xltypeStr	バルーン用のテキスト。
//	TEXTAW(""),	//	xltypeStr	ヘルプファイルのトピックへの参照
//	TEXTAW(""),	//	xltypeStr	ツールチップ用のテキスト。
};

static int	nrgTools				= sizeof(rgTools) / sizeof(RGTOOLARGS);
static BOOL	bRegisterToolbarItems	= FALSE;

#endif

//----------------------------------------------------------------------
//	RegisterToolbarItems
//----------------------------------------------------------------------
static BOOL RegisterToolbarItems()
{
	XLOPER4		xRes4;
	XLOPER12	xRes12;

	HGLOBAL		hGlobal;
	LPXLOPER	pxGlobal4;
	LPXLOPER12	pxGlobal12;
	LPXLOPER	px4;
	LPXLOPER12	px12;

	int			i;
	int			iRet;

	if (nrgTools < 1)	return TRUE;

	//------------------------------------------------------------
	//	Excel12
	//------------------------------------------------------------
	if (XLL::IsExcel12())
	{
		hGlobal	= GlobalAlloc(GMEM_MOVEABLE, sizeof(XLOPER12) * nrgToolArgs * nrgTools);
		pxGlobal12	= (LPXLOPER12)GlobalLock(hGlobal);
		px12		= pxGlobal12;
		for (i = 0; i < nrgTools; ++i)
		{
			SET_XLOPER_STR_12(px12, rgTools[i].pszToolId.w);			++px12;
			SET_XLOPER_STR_12(px12, rgTools[i].pszMacro.w);			++px12;
			SET_XLOPER_BOOL_12(px12, rgTools[i].bDown);				++px12;
			SET_XLOPER_BOOL_12(px12, rgTools[i].bEnabled);			++px12;
			SET_XLOPER_STR_12(px12, rgTools[i].pszFace.w);			++px12;
			SET_XLOPER_STR_12(px12, rgTools[i].pszStatusTtext.w);	++px12;
			SET_XLOPER_STR_12(px12, rgTools[i].pszBallonTtext.w);	++px12;
			SET_XLOPER_STR_12(px12, rgTools[i].pszHelpTopic.w);		++px12;
			SET_XLOPER_STR_12(px12, rgTools[i].pszTipText.w);		++px12;
			for (j = 0; j < nrgToolArgs; ++j)
			{
				SET_XLOPER_STR_12(px12, rgTools[i][j].w);
				++px12;
			}
		}

		xTemp12.xltype	= xltypeMulti;
		xTemp12.val.array.lparray	= pxGlobal12;
		xTemp12.val.array.rows		= nrgTools;
		xTemp12.val.array.columns	= nrgToolArgs;

#ifdef PDEBUG
		WSTRING	strDebug;
		XLL::ShowXLOPER12(strDebug, &xTemp12);
#endif

		//Excel12f(xlfAddToolbar, &xRes12, 2, cxXLLTitle12.px(), (LPXLOPER12)&xTemp12);
		Excel12f(xlfAddToolbar, &xRes12, 1, cxXLLTitle12.px());
		//Excel12f(xlfAddToolbar, &xRes12, 2, (LPXLOPER12)&xXLLTitle12, &xMissing12);

		iRet = Excel12f(xlcShowToolbar, &xRes12, 10,
			cxXLLTitle12.px(),				//	xltypeStr	ツールバーの名前。
			(LPXLOPER12)TempBool12(TRUE),	//	xltypeBOOL	表示・表示を切り替える。
			(LPXLOPER12)TempInt12(5),		//	xltypeInt	ドックする位置を指定する。
			(LPXLOPER12)TempMissing12(),	//	xltypeInt	ツールバーの水平方向の位置。
			(LPXLOPER12)TempMissing12(),	//	xltypeInt	ツールバーの水平方向の位置。
			//(LPXLOPER12)TempMissing12(),	//	xltypeInt	ツールバーの幅。省略可。
			(LPXLOPER12)TempInt12(72),	//	xltypeInt	ツールバーの幅。省略可。
			(LPXLOPER12)TempInt12(0),		//	xltypeInt	ツールバーの保護の程度を示す数値。
			(LPXLOPER12)TempBool12(TRUE),	//	xltypeBOOL	ツールチップを表示するかを指示する論理値。
			(LPXLOPER12)TempBool12(FALSE),	//	xltypeBOOL	大きなボタンを使用するかを指示する論理値。
			(LPXLOPER12)TempBool12(TRUE)	//	xltypeBOOL	ボタンで色を使用するかを指示する論理値。
			);

		GlobalUnlock(hGlobal);
		GlobalFree(hGlobal);
	}
	//------------------------------------------------------------
	//	Excel4
	//------------------------------------------------------------
	else
	{
		hGlobal	= GlobalAlloc(GMEM_MOVEABLE, sizeof(XLOPER4) * nrgToolArgs * nrgTools);
		pxGlobal4	= (LPXLOPER)GlobalLock(hGlobal);
		px4		= pxGlobal4;
		for (i = 0; i < nrgTools; ++i)
		{
			SET_XLOPER_STR_4(px4, rgTools[i].pszToolId.a);		++px4;
			SET_XLOPER_STR_4(px4, rgTools[i].pszMacro.a);			++px4;
			SET_XLOPER_BOOL_4(px4, rgTools[i].bDown);				++px4;
			SET_XLOPER_BOOL_4(px4, rgTools[i].bEnabled);			++px4;
			SET_XLOPER_STR_4(px4, rgTools[i].pszFace.a);			++px4;
			SET_XLOPER_STR_4(px4, rgTools[i].pszStatusTtext.a);	++px4;
			SET_XLOPER_STR_4(px4, rgTools[i].pszBallonTtext.a);	++px4;
			SET_XLOPER_STR_4(px4, rgTools[i].pszHelpTopic.a);		++px4;
			SET_XLOPER_STR_4(px4, rgTools[i].pszTipText.a);		++px4;
			for (j = 0; j < nrgToolArgs; ++j)
			{
				SET_XLOPER_STR_4(px4, rgTools[i][j].w);
				++px4;
			}
		}

		xTemp4.xltype	= xltypeMulti;
		xTemp4.val.array.lparray	= pxGlobal4;
		xTemp4.val.array.rows		= nrgTools;
		xTemp4.val.array.columns	= nrgToolArgs;

		//Excel(xlfAddToolbar, &xRes4, 2, (LPXLOPER)&xXLLTitle4, (LPXLOPER)&xTemp4);
		Excel(xlfAddToolbar, &xRes4, 1, (LPXLOPER)&xXLLTitle4);

		iRet = Excel(xlcShowToolbar, &xRes4, 10,
			(LPXLOPER)&xXLLTitle4,	//	xltypeStr	ツールバーの名前。
			(LPXLOPER)TempBool4(TRUE),	//	xltypeBOOL	表示・表示を切り替える。
			(LPXLOPER)TempInt4(5),		//	xltypeInt	ドックする位置を指定する。
			(LPXLOPER)TempMissing4(),	//	xltypeInt	ツールバーの水平方向の位置。
			(LPXLOPER)TempMissing4(),	//	xltypeInt	ツールバーの水平方向の位置。
			(LPXLOPER)TempMissing4(),	//	xltypeInt	ツールバーの幅。省略可。
			(LPXLOPER)TempInt4(0),		//	xltypeInt	ツールバーの保護の程度を示す数値。
			(LPXLOPER)TempBool4(TRUE),	//	xltypeBOOL	ツールチップを表示するかを指示する論理値。
			(LPXLOPER)TempBool4(FALSE),	//	xltypeBOOL	大きなボタンを使用するかを指示する論理値。
			(LPXLOPER)TempBool4(TRUE)	//	xltypeBOOL	ボタンで色を使用するかを指示する論理値。
			);
		GlobalUnlock(hGlobal);
		GlobalFree(hGlobal);
	}
	bRegisterToolbarItems	= TRUE;
	return TRUE;
}

//----------------------------------------------------------------------
//	UnregisterToolbarItems
//----------------------------------------------------------------------
static BOOL UnregisterToolbarItems()
{
	XLOPER4		xRes4;
	XLOPER12	xRes12;

	if (!bRegisterToolbarItems)	return TRUE;

	//------------------------------------------------------------
	//	Excel12
	//------------------------------------------------------------
	if (XLL::IsExcel12())
	{
		Excel12f(xlfGetToolbar, &xRes12, 2, TempInt12(7), cxXLLTitle12.px());

		if (xRes12.xltype != xltypeErr)
		{
			Excel12f(xlfDeleteToolbar, 0, 1, cxXLLTitle12.px());
			Excel12f(xlFree, 0, 1, (LPXLOPER12)&xRes12);
		}
	}
	//------------------------------------------------------------
	//	Excel4
	//------------------------------------------------------------
	else
	{
	}
	return TRUE;
}

#endif


//======================================================================
//	xlAutoOpen
//======================================================================
int WINAPI xlAutoOpen()
{
	//	初期設定は dllmain() でも行う。
	//	OS のバージョンをチェックする。
	if (!(PLib::CheckOSVersion(5, 1)))	return 0;	//	Windows XP 以上

	//	Excel の情報を取得し、XLL の初期設定を行う。
	if (!XLL::Init())		return 0;
	if (!XLCTextEx::Init())	return 0;

	//	ワークシート関数を登録する。
#ifdef	REGISTER_XLLFUNCTIONS
	if (XLL::IsExcel12())
	{
		if (!t_RegisterFunctions<XLOPER12>((PCSTRAW*)pawRgXLLFunctions, nRgXLLFunctions, nParamsRgXLLFunc))
			return 0;
	}
	else
	{
		if (!t_RegisterFunctions<XLOPER>((PCSTRAW*)pawRgXLLFunctions, nRgXLLFunctions, nParamsRgXLLFunc))
			return 0;
	}

#endif

	//	コマンド関数を登録する。
#ifdef	REGISTER_COMMANDFUNCTIONS
	RegisterCommandFunctions();
#endif

	//	メニュー項目を登録する。
#ifdef	REGISTER_MENUITEMS
	RegisterMenuItems();
#endif

	//	ツールバー項目を登録する。
#ifdef	REGISTER_TOOLBARITEMS
	RegisterToolbarItems();
#endif

#ifdef	PDEBUG
	//XLCRegExTest01();
#endif

	return 1;
}


//======================================================================
//	xlAutoClose
//======================================================================
int WINAPI xlAutoClose()
{
	//	登録したワークシート関数を解除する。
#ifdef	REGISTER_XLLFUNCTIONS
	if (XLL::IsExcel12())
	{
		if (!t_UnRegisterFunctions<XLOPER12>((PCSTRAW*)pawRgXLLFunctions, nRgXLLFunctions, nParamsRgXLLFunc))
		{
		}
	}
	else
	{
		if (!t_UnRegisterFunctions<XLOPER>((PCSTRAW*)pawRgXLLFunctions, nRgXLLFunctions, nParamsRgXLLFunc))
		{
		}
	}
#endif

	//	登録したコマンドを解除する。
#ifdef	REGISTER_COMMANDFUNCTIONS
	UnregisterCommandFunctions();
#endif

	//	登録したメニューを解除する。
#ifdef	REGISTER_MENUITEMS
	UnregisterMenuItems();
#endif

	//	登録したツールバーを解除する。
#ifdef	REGISTER_TOOLBARITEMS
	UnregisterToolbarItems();
#endif

	//	終了処理は dllmain() で行う。
	return 1;
}


//======================================================================
//	xlAutoFree, xlAutoFree12
//======================================================================
void WINAPI	xlAutoFree(XLOPER* pxFree)
{
	if (pxFree->xltype & xlbitDLLFree)
	{
		XLL::DeallocateXLOPER4(pxFree);
	}
}

void WINAPI	xlAutoFree12(XLOPER12* pxFree)
{
	if (pxFree->xltype & xlbitDLLFree)
	{
		XLL::DeallocateXLOPER12(pxFree);
	}
}

