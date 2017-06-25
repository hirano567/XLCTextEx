//	XLCTextEx_1.0x	:	PLibUCD

//	XLCTextEx_1.01	2013/06/02
//	XLCTextEx_1.02

//	PLibUCD.h
//
#pragma once

#include "PLib.h"

#ifndef NS_PLIB
#define NS_PLIB			PLib
#define NS_PLIB_BEGIN	namespace NS_PLIB {
#define NS_PLIB_END		}
#endif

#ifndef NS_UNICODE
#define NS_UNICODE	Unicode
#define NS_PLIB_UNICODE_BEGIN	namespace NS_PLIB {	namespace NS_UNICODE {
#define NS_PLIB_UNICODE_END	}}
#endif

#ifndef NS_UCD
#define NS_UCD	UCD
#define NS_PLIB_UCD_BEGIN	namespace NS_PLIB {	namespace NS_UNICODE {	namespace NS_UCD {
#define NS_PLIB_UCD_END	}}}
#endif

NS_PLIB_UNICODE_BEGIN

//======================================================================
//	Unicode Property データ
//	Unicode の Property データは 32 ビット値で表す。
//	上位 16 ビットでどの Property かを示し、
//	下位 16 ビットでその値を示す。
//======================================================================
#define	UNICODE_PROPERTY_BASE								16
#define	UNICODE_PROPERTY_GENERAL_CATEGORY					(1 << (UNICODE_PROPERTY_BASE + 0))
#define	UNICODE_PROPERTY_SCRIPT								(1 << (UNICODE_PROPERTY_BASE + 1))
#define	UNICODE_PROPERTY_ALPHABETIC							(1 << (UNICODE_PROPERTY_BASE + 2))
#define	UNICODE_PROPERTY_UPPERCASE							(1 << (UNICODE_PROPERTY_BASE + 3))
#define	UNICODE_PROPERTY_LOWERCASE							(1 << (UNICODE_PROPERTY_BASE + 4))
#define	UNICODE_PROPERTY_WHITE_SPACE						(1 << (UNICODE_PROPERTY_BASE + 5))
#define	UNICODE_PROPERTY_NONCHARACTER_CODE_POINT			(1 << (UNICODE_PROPERTY_BASE + 6))
#define	UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT		(1 << (UNICODE_PROPERTY_BASE + 7))
#define	UNICODE_PROPERTY_NAMED_BLOCK						(1 << (UNICODE_PROPERTY_BASE + 8))

#define	IS_UNICODE_PROPERTY_GENERAL_CATEGORY(p)	\
	(((p) & UNICODE_PROPERTY_GENERAL_CATEGORY) != 0)
#define	IS_UNICODE_PROPERTY_SCRIPT(p)	\
	(((p) & UNICODE_PROPERTY_SCRIPT) != 0)
#define	IS_UNICODE_PROPERTY_ALPHABETIC(p)	\
	(((p) & UNICODE_PROPERTY_ALPHABETIC) != 0)
#define	IS_UNICODE_PROPERTY_UPPERCASE(p)	\
	(((p) & UNICODE_PROPERTY_UPPERCASE) != 0)
#define	IS_UNICODE_PROPERTY_LOWERCASE(p)	\
	(((p) & UNICODE_PROPERTY_LOWERCASE) != 0)
#define	IS_UNICODE_PROPERTY_WHITE_SPACE(p)	\
	(((p) & UNICODE_PROPERTY_WHITE_SPACE) != 0)
#define	IS_UNICODE_PROPERTY_NONCHARACTER_CODE_POINT(p)	\
	(((p) & UNICODE_PROPERTY_NONCHARACTER_CODE_POINT) != 0)
#define	IS_UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT(p)	\
	(((p) & UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT) != 0)
#define	IS_UNICODE_PROPERTY_NAMED_BLOCK(p)	\
	(((p) & UNICODE_PROPERTY_NAMED_BLOCK) != 0)


//======================================================================
//	Unicode Named Block
//======================================================================
#define	UNICODE_NAMEDBLOCK_ISBASICLATIN								1
#define	UNICODE_NAMEDBLOCK_ISLATIN_1SUPPLEMENT						2
#define	UNICODE_NAMEDBLOCK_ISLATINEXTENDED_A						3
#define	UNICODE_NAMEDBLOCK_ISLATINEXTENDED_B						4
#define	UNICODE_NAMEDBLOCK_ISIPAEXTENSIONS							5
#define	UNICODE_NAMEDBLOCK_ISSPACINGMODIFIERLETTERS					6
#define	UNICODE_NAMEDBLOCK_ISCOMBININGDIACRITICALMARKS				7
#define	UNICODE_NAMEDBLOCK_ISGREEK									8
#define	UNICODE_NAMEDBLOCK_ISGREEKANDCOPTIC							9
#define	UNICODE_NAMEDBLOCK_ISCYRILLIC								10
#define	UNICODE_NAMEDBLOCK_ISCYRILLICSUPPLEMENT						11
#define	UNICODE_NAMEDBLOCK_ISARMENIAN								12
#define	UNICODE_NAMEDBLOCK_ISHEBREW									13
#define	UNICODE_NAMEDBLOCK_ISARABIC									14
#define	UNICODE_NAMEDBLOCK_ISSYRIAC									15
#define	UNICODE_NAMEDBLOCK_ISTHAANA									16
#define	UNICODE_NAMEDBLOCK_ISDEVANAGARI								17
#define	UNICODE_NAMEDBLOCK_ISBENGALI								18
#define	UNICODE_NAMEDBLOCK_ISGURMUKHI								19
#define	UNICODE_NAMEDBLOCK_ISGUJARATI								20
#define	UNICODE_NAMEDBLOCK_ISORIYA									21
#define	UNICODE_NAMEDBLOCK_ISTAMIL									22
#define	UNICODE_NAMEDBLOCK_ISTELUGU									23
#define	UNICODE_NAMEDBLOCK_ISKANNADA								24
#define	UNICODE_NAMEDBLOCK_ISMALAYALAM								25
#define	UNICODE_NAMEDBLOCK_ISSINHALA								26
#define	UNICODE_NAMEDBLOCK_ISTHAI									27
#define	UNICODE_NAMEDBLOCK_ISLAO									28
#define	UNICODE_NAMEDBLOCK_ISTIBETAN								29
#define	UNICODE_NAMEDBLOCK_ISMYANMAR								30
#define	UNICODE_NAMEDBLOCK_ISGEORGIAN								31
#define	UNICODE_NAMEDBLOCK_ISHANGULJAMO								32
#define	UNICODE_NAMEDBLOCK_ISETHIOPIC								33
#define	UNICODE_NAMEDBLOCK_ISCHEROKEE								34
#define	UNICODE_NAMEDBLOCK_ISUNIFIEDCANADIANABORIGINALSYLLABICS		35
#define	UNICODE_NAMEDBLOCK_ISOGHAM									36
#define	UNICODE_NAMEDBLOCK_ISRUNIC									37
#define	UNICODE_NAMEDBLOCK_ISTAGALOG								38
#define	UNICODE_NAMEDBLOCK_ISHANUNOO								39
#define	UNICODE_NAMEDBLOCK_ISBUHID									40
#define	UNICODE_NAMEDBLOCK_ISTAGBANWA								41
#define	UNICODE_NAMEDBLOCK_ISKHMER									42
#define	UNICODE_NAMEDBLOCK_ISMONGOLIAN								43
#define	UNICODE_NAMEDBLOCK_ISLIMBU									44
#define	UNICODE_NAMEDBLOCK_ISTAILE									45
#define	UNICODE_NAMEDBLOCK_ISKHMERSYMBOLS							46
#define	UNICODE_NAMEDBLOCK_ISPHONETICEXTENSIONS						47
#define	UNICODE_NAMEDBLOCK_ISLATINEXTENDEDADDITIONAL				48
#define	UNICODE_NAMEDBLOCK_ISGREEKEXTENDED							49
#define	UNICODE_NAMEDBLOCK_ISGENERALPUNCTUATION						50
#define	UNICODE_NAMEDBLOCK_ISSUPERSCRIPTSANDSUBSCRIPTS				51
#define	UNICODE_NAMEDBLOCK_ISCURRENCYSYMBOLS						52
#define	UNICODE_NAMEDBLOCK_ISCOMBININGDIACRITICALMARKSFORSYMBOLS	53
#define	UNICODE_NAMEDBLOCK_ISCOMBININGMARKSFORSYMBOLS				54
#define	UNICODE_NAMEDBLOCK_ISLETTERLIKESYMBOLS						55
#define	UNICODE_NAMEDBLOCK_ISNUMBERFORMS							56
#define	UNICODE_NAMEDBLOCK_ISARROWS									57
#define	UNICODE_NAMEDBLOCK_ISMATHEMATICALOPERATORS					58
#define	UNICODE_NAMEDBLOCK_ISMISCELLANEOUSTECHNICAL					59
#define	UNICODE_NAMEDBLOCK_ISCONTROLPICTURES						60
#define	UNICODE_NAMEDBLOCK_ISOPTICALCHARACTERRECOGNITION			61
#define	UNICODE_NAMEDBLOCK_ISENCLOSEDALPHANUMERICS					62
#define	UNICODE_NAMEDBLOCK_ISBOXDRAWING								63
#define	UNICODE_NAMEDBLOCK_ISBLOCKELEMENTS							64
#define	UNICODE_NAMEDBLOCK_ISGEOMETRICSHAPES						65
#define	UNICODE_NAMEDBLOCK_ISMISCELLANEOUSSYMBOLS					66
#define	UNICODE_NAMEDBLOCK_ISDINGBATS								67
#define	UNICODE_NAMEDBLOCK_ISMISCELLANEOUSMATHEMATICALSYMBOLS_A		68
#define	UNICODE_NAMEDBLOCK_ISSUPPLEMENTALARROWS_A					69
#define	UNICODE_NAMEDBLOCK_ISBRAILLEPATTERNS						70
#define	UNICODE_NAMEDBLOCK_ISSUPPLEMENTALARROWS_B					71
#define	UNICODE_NAMEDBLOCK_ISMISCELLANEOUSMATHEMATICALSYMBOLS_B		72
#define	UNICODE_NAMEDBLOCK_ISSUPPLEMENTALMATHEMATICALOPERATORS		73
#define	UNICODE_NAMEDBLOCK_ISMISCELLANEOUSSYMBOLSANDARROWS			74
#define	UNICODE_NAMEDBLOCK_ISCJKRADICALSSUPPLEMENT					75
#define	UNICODE_NAMEDBLOCK_ISKANGXIRADICALS							76
#define	UNICODE_NAMEDBLOCK_ISIDEOGRAPHICDESCRIPTIONCHARACTERS		77
#define	UNICODE_NAMEDBLOCK_ISCJKSYMBOLSANDPUNCTUATION				78
#define	UNICODE_NAMEDBLOCK_ISHIRAGANA								79
#define	UNICODE_NAMEDBLOCK_ISKATAKANA								80
#define	UNICODE_NAMEDBLOCK_ISBOPOMOFO								81
#define	UNICODE_NAMEDBLOCK_ISHANGULCOMPATIBILITYJAMO				82
#define	UNICODE_NAMEDBLOCK_ISKANBUN									83
#define	UNICODE_NAMEDBLOCK_ISBOPOMOFOEXTENDED						84
#define	UNICODE_NAMEDBLOCK_ISKATAKANAPHONETICEXTENSIONS				85
#define	UNICODE_NAMEDBLOCK_ISENCLOSEDCJKLETTERSANDMONTHS			86
#define	UNICODE_NAMEDBLOCK_ISCJKCOMPATIBILITY						87
#define	UNICODE_NAMEDBLOCK_ISCJKUNIFIEDIDEOGRAPHSEXTENSIONA			88
#define	UNICODE_NAMEDBLOCK_ISYIJINGHEXAGRAMSYMBOLS					89
#define	UNICODE_NAMEDBLOCK_ISCJKUNIFIEDIDEOGRAPHS					90
#define	UNICODE_NAMEDBLOCK_ISYISYLLABLES							91
#define	UNICODE_NAMEDBLOCK_ISYIRADICALS								92
#define	UNICODE_NAMEDBLOCK_ISHANGULSYLLABLES						93
#define	UNICODE_NAMEDBLOCK_ISHIGHSURROGATES							94
#define	UNICODE_NAMEDBLOCK_ISHIGHPRIVATEUSESURROGATES				95
#define	UNICODE_NAMEDBLOCK_ISLOWSURROGATES							96
#define	UNICODE_NAMEDBLOCK_ISPRIVATEUSE								97
#define	UNICODE_NAMEDBLOCK_ISPRIVATEUSEAREA							98
#define	UNICODE_NAMEDBLOCK_ISCJKCOMPATIBILITYIDEOGRAPHS				99
#define	UNICODE_NAMEDBLOCK_ISALPHABETICPRESENTATIONFORMS			100
#define	UNICODE_NAMEDBLOCK_ISARABICPRESENTATIONFORMS_A				101
#define	UNICODE_NAMEDBLOCK_ISVARIATIONSELECTORS						102
#define	UNICODE_NAMEDBLOCK_ISCOMBININGHALFMARKS						103
#define	UNICODE_NAMEDBLOCK_ISCJKCOMPATIBILITYFORMS					104
#define	UNICODE_NAMEDBLOCK_ISSMALLFORMVARIANTS						105
#define	UNICODE_NAMEDBLOCK_ISARABICPRESENTATIONFORMS_B				106
#define	UNICODE_NAMEDBLOCK_ISHALFWIDTHANDFULLWIDTHFORMS				107


//======================================================================
//	このプロジェクトで使用するデータ型
//======================================================================
//	UCD は UTF-8 で記述されている。（コメント以外は ASCII）
typedef char							T_CHAR_UCD_T;
typedef	const T_CHAR_UCD_T				T_CCHAR_UCD_T;
typedef	T_CHAR_UCD_T*					T_PSTR_UCD_T;
typedef	const T_CHAR_UCD_T*				T_PCSTR_UCD_T;
typedef	std::basic_string<T_CHAR_UCD_T>	T_STRING_UCD_T, T_PSTRING_UCD_T;

#define	TQ_UCD_T(quote)	quote


//======================================================================
//	関数の宣言とマクロ
//	PLib::PSSearch 系の構造体は PLib 内の PSearch.h で定義されている。
//======================================================================
#define	CSTR_UCD_FLAGS	(NORM_IGNORECASE | NORM_IGNOREWIDTH)

#define	CSTRZ_UCD(ps1, ps2)	\
	PLib::Unicode::CompareStringUCD((ps1), -1, (ps2), -1, CSTR_UCD_FLAGS, NULL)
#define	CSTRZEQ_UCD(ps1, ps2)	(CSTRZ_UCD(ps1, ps2) == CSTR_EQUAL)

#define	CSTRZ_UCD_BUF(pb1, pb2)	\
	PLib::Unicode::CompareStringUCD((pb1), (pb2), CSTR_UCD_FLAGS, NULL)
#define	CSTRZEQ_UCD_BUF(pb1, pb2)	(CSTRZ_UCD_BUF(pb1, pb2) == CSTR_EQUAL)

//======================================================================
//	BinarySearch 関数用のデータ構造体
//======================================================================
//----------------------------------------------------------------------
//	PSPSzIdMap
//----------------------------------------------------------------------
typedef	PLib::PSSearchPSzKey<T_CHAR_U, int>		PSPSzIdMap;

//----------------------------------------------------------------------
//	PSIdPSzMap
//----------------------------------------------------------------------
typedef	PLib::PSSearchNumKey<int, T_PCSTR_U>	PSIdPSzMap;

//----------------------------------------------------------------------
//	PSCpIdMap	コードポイントから属性値 ID を取得するための構造体
//----------------------------------------------------------------------
typedef	PLib::PSSearchNumRangeKey<T_UCP, int>	PSCpIdMap;

//----------------------------------------------------------------------
//	struct	PSSearchPSzKey
//	NULL 終了 Unicode 文字列をキーとする検索用構造体
//	検索文字列は PIFUnicodeBuffer で指定する。
//----------------------------------------------------------------------
template<typename T_DATA, DWORD DWFLAGS, T_PCSTR_U PSZLOCALE>
struct	PSSearchPSzKeyBufArg
{
	T_PCSTR_U	pszKey;
	T_DATA		Data;

	//------------------------------------------------------------
	//	メンバ関数
	//------------------------------------------------------------
	int	Compare(PIFUnicodeBuffer* pciBufCmp)
	{
		PCUnicodeSzBuffer	ciUBufKey;

		ciUBufKey.Set(pszKey);
		ciUBufKey.Begin();
		pciBufCmp->Begin();
		return PLib::Unicode::CompareStringUCD(&ciUBufKey, pciBufCmp, DWFLAGS, PSZLOCALE);
	}

	bool LessThan(PIFUnicodeBuffer* pciBufCmp)
	{
		return (Compare(pciBufCmp) == CSTR_LESS_THAN);
	}

	bool GreaterThan(PIFUnicodeBuffer* pciBufCmp)
	{
		return (Compare(pciBufCmp) == CSTR_GREATER_THAN);
	}

	bool Match(PIFUnicodeBuffer* pciBufCmp)
	{
		return (Compare(pciBufCmp) == CSTR_EQUAL);
	}
};

//======================================================================
//	struct PSPropertyValueIdMap
//	属性値を表す文字列から ID を取り出すための構造体
//======================================================================
struct PSPropertyValueIdMap
{
	const T_UCP*	pcpKey;
	T_PCSTR_U		pszName;
	int				iId;

	int		Compare(UCPSTRING* pucsOther);

	bool	LessThan(UCPSTRING* pucsOther)
	{
		return (Compare(pucsOther) == CSTR_LESS_THAN);
	}

	bool	Match(UCPSTRING* pucsOther)
	{
		return (Compare(pucsOther) == CSTR_EQUAL);
	}
};

//======================================================================
//	NormalizeName
//	名前の空白、-、_ を取り除き、すべての文字を大文字に変換する。
//	バッファが足りない（終端の NULL も含めて）場合は FALSE を返す。
//======================================================================
//bool	NormalizeName(LPWSTR pBuf, size_t zBuf, LPCWSTR pName, LPCWSTR pEnd);
//bool	NormalizeName(T_UCP* pBuf, size_t zBuf, const T_UCP* pName, const T_UCP* pEnd);
bool	NormalizeName(UCPSTRING* pucsBuf, const T_UCP* pName, const T_UCP* pEnd);

//======================================================================
//	GetPropertyValue
//======================================================================
//	(1)	属性値名から属性値 ID を取得する。
bool	GetPropertyValueByName(int*			pid,
							   PSPSzIdMap*	pMaps,
							   int			nMaps,
							   const T_UCP*	pNameB,
							   const T_UCP*	pNameE);

//	(2-1)	Codepoint からその文字の属性値 ID を取得する。
bool	GetPropertyValue(int* pid, PSCpIdMap* pMaps, int nMaps, UINT uiCodepoint);

//	(2-2)	文字列中の指定した位置にある文字の属性値 ID を取得する。
bool	GetPropertyValue(int* pid, PSCpIdMap* pMaps, int nMaps,
					  const T_UCP* pStr, const T_UCP* pEnd);


//======================================================================
//	GetPropertyName
//======================================================================
T_PCSTR_U	GetPropertyName(PSIdPSzMap* pMaps, int nMaps, int iId);

//======================================================================
//	GetBooleanValueByStr
//======================================================================
bool	GetBooleanValueByStr(bool* pb, const T_UCP* pszName);

NS_PLIB_UNICODE_END

//======================================================================
//	プロジェクト内のインクルードファイル
//======================================================================
//#include "PFoldTable.h"
#include "PBMPTable.h"
#include "PUnicodeData.h"
#include "PBlocks.h"
#include "PScripts.h"
#include "PDerivedCoreProperties.h"
#include "PPropList.h"
#include "PCaseConversion.h"
#include "PNormalization.h"
#include "PKanaConversion.h"
#include "PCompareStringUCD.h"
#include "PUCDUtility.h"
#include "PUCDClassFunctions.h"
#include "PStrToNum.h"

//======================================================================
//	初期化と終了処理
//======================================================================
NS_PLIB_UCD_BEGIN

BOOL	Init();
void	Cleanup();

NS_PLIB_UCD_END
