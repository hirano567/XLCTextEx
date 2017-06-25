//	XLCTextEx_1.0x	:	PLibUCD

//	PLibUCD:	PScripts.h
//
#pragma once

NS_PLIB_UNICODE_BEGIN

#define	PUCD_SCRIPT_UNKNOWN					0
#define	PUCD_SCRIPT_COMMON					1
#define	PUCD_SCRIPT_LATIN					2
#define	PUCD_SCRIPT_BOPOMOFO				3
#define	PUCD_SCRIPT_INHERITED				4
#define	PUCD_SCRIPT_GREEK					5
#define	PUCD_SCRIPT_COPTIC					6
#define	PUCD_SCRIPT_CYRILLIC				7
#define	PUCD_SCRIPT_ARMENIAN				8
#define	PUCD_SCRIPT_HEBREW					9
#define	PUCD_SCRIPT_ARABIC					10
#define	PUCD_SCRIPT_SYRIAC					11
#define	PUCD_SCRIPT_THAANA					12
#define	PUCD_SCRIPT_NKO						13
#define	PUCD_SCRIPT_SAMARITAN				14
#define	PUCD_SCRIPT_MANDAIC					15
#define	PUCD_SCRIPT_DEVANAGARI				16
#define	PUCD_SCRIPT_BENGALI					17
#define	PUCD_SCRIPT_GURMUKHI				18
#define	PUCD_SCRIPT_GUJARATI				19
#define	PUCD_SCRIPT_ORIYA					20
#define	PUCD_SCRIPT_TAMIL					21
#define	PUCD_SCRIPT_TELUGU					22
#define	PUCD_SCRIPT_KANNADA					23
#define	PUCD_SCRIPT_MALAYALAM				24
#define	PUCD_SCRIPT_SINHALA					25
#define	PUCD_SCRIPT_THAI					26
#define	PUCD_SCRIPT_LAO						27
#define	PUCD_SCRIPT_TIBETAN					28
#define	PUCD_SCRIPT_MYANMAR					29
#define	PUCD_SCRIPT_GEORGIAN				30
#define	PUCD_SCRIPT_HANGUL					31
#define	PUCD_SCRIPT_ETHIOPIC				32
#define	PUCD_SCRIPT_CHEROKEE				33
#define	PUCD_SCRIPT_CANADIAN_ABORIGINAL		34
#define	PUCD_SCRIPT_OGHAM					35
#define	PUCD_SCRIPT_RUNIC					36
#define	PUCD_SCRIPT_TAGALOG					37
#define	PUCD_SCRIPT_HANUNOO					38
#define	PUCD_SCRIPT_BUHID					39
#define	PUCD_SCRIPT_TAGBANWA				40
#define	PUCD_SCRIPT_KHMER					41
#define	PUCD_SCRIPT_MONGOLIAN				42
#define	PUCD_SCRIPT_LIMBU					43
#define	PUCD_SCRIPT_TAI_LE					44
#define	PUCD_SCRIPT_NEW_TAI_LUE				45
#define	PUCD_SCRIPT_BUGINESE				46
#define	PUCD_SCRIPT_TAI_THAM				47
#define	PUCD_SCRIPT_BALINESE				48
#define	PUCD_SCRIPT_SUNDANESE				49
#define	PUCD_SCRIPT_BATAK					50
#define	PUCD_SCRIPT_LEPCHA					51
#define	PUCD_SCRIPT_OL_CHIKI				52
#define	PUCD_SCRIPT_BRAILLE					53
#define	PUCD_SCRIPT_GLAGOLITIC				54
#define	PUCD_SCRIPT_TIFINAGH				55
#define	PUCD_SCRIPT_HAN						56
#define	PUCD_SCRIPT_HIRAGANA				57
#define	PUCD_SCRIPT_KATAKANA				58
#define	PUCD_SCRIPT_YI						59
#define	PUCD_SCRIPT_LISU					60
#define	PUCD_SCRIPT_VAI						61
#define	PUCD_SCRIPT_BAMUM					62
#define	PUCD_SCRIPT_SYLOTI_NAGRI			63
#define	PUCD_SCRIPT_PHAGS_PA				64
#define	PUCD_SCRIPT_SAURASHTRA				65
#define	PUCD_SCRIPT_KAYAH_LI				66
#define	PUCD_SCRIPT_REJANG					67
#define	PUCD_SCRIPT_JAVANESE				68
#define	PUCD_SCRIPT_CHAM					69
#define	PUCD_SCRIPT_TAI_VIET				70
#define	PUCD_SCRIPT_MEETEI_MAYEK			71
#define	PUCD_SCRIPT_LINEAR_B				72
#define	PUCD_SCRIPT_LYCIAN					73
#define	PUCD_SCRIPT_CARIAN					74
#define	PUCD_SCRIPT_OLD_ITALIC				75
#define	PUCD_SCRIPT_GOTHIC					76
#define	PUCD_SCRIPT_UGARITIC				77
#define	PUCD_SCRIPT_OLD_PERSIAN				78
#define	PUCD_SCRIPT_DESERET					79
#define	PUCD_SCRIPT_SHAVIAN					80
#define	PUCD_SCRIPT_OSMANYA					81
#define	PUCD_SCRIPT_CYPRIOT					82
#define	PUCD_SCRIPT_IMPERIAL_ARAMAIC		83
#define	PUCD_SCRIPT_PHOENICIAN				84
#define	PUCD_SCRIPT_LYDIAN					85
#define	PUCD_SCRIPT_MEROITIC_HIEROGLYPHS	86
#define	PUCD_SCRIPT_MEROITIC_CURSIVE		87
#define	PUCD_SCRIPT_KHAROSHTHI				88
#define	PUCD_SCRIPT_OLD_SOUTH_ARABIAN		89
#define	PUCD_SCRIPT_AVESTAN					90
#define	PUCD_SCRIPT_INSCRIPTIONAL_PARTHIAN	91
#define	PUCD_SCRIPT_INSCRIPTIONAL_PAHLAVI	92
#define	PUCD_SCRIPT_OLD_TURKIC				93
#define	PUCD_SCRIPT_BRAHMI					94
#define	PUCD_SCRIPT_KAITHI					95
#define	PUCD_SCRIPT_SORA_SOMPENG			96
#define	PUCD_SCRIPT_CHAKMA					97
#define	PUCD_SCRIPT_SHARADA					98
#define	PUCD_SCRIPT_TAKRI					99
#define	PUCD_SCRIPT_CUNEIFORM				100
#define	PUCD_SCRIPT_EGYPTIAN_HIEROGLYPHS	101
#define	PUCD_SCRIPT_MIAO					102

//======================================================================
//	GetScriptValue
//======================================================================
//	Script 属性値名から属性値 ID を取得する。
bool	GetScriptIdByName(int* pid, UCPSTRING* pucsName);

//bool	GetScriptIdByName(int* pid, const T_UCP* pNameB, const T_UCP* pNameE);
//bool	GetScriptIdByName(int* pid, const T_UCP* pName, size_t zName);

//	指定された文字のコードポイントから Script 属性値 ID を取得する。
bool	GetScriptValue(int* pid, UINT uiCp);
bool	GetScriptValue(int* pid, const T_UCP* pStr, const T_UCP* pEnd);

//======================================================================
//	デバッグ用
//======================================================================
T_PCSTR_U	Debug_GetScriptValue(int iId);

NS_PLIB_UNICODE_END
