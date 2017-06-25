//	XLCTextEx_1.0x	:	PLibUCD

//	PLibUCD:	PScripts.cpp
//
#include "stdafx.h"

NS_PLIB_UNICODE_BEGIN

//======================================================================
//	Script の属性値名から ID を取得するためのデータ
//======================================================================
/*
PSPSzIdMap	ScriptNameIdMap[]	=
{
	TQU("ARAB"),	PUCD_SCRIPT_ARABIC,
	TQU("ARABIC"),	PUCD_SCRIPT_ARABIC,
	TQU("ARMENIAN"),	PUCD_SCRIPT_ARMENIAN,
	TQU("ARMI"),	PUCD_SCRIPT_IMPERIAL_ARAMAIC,
	TQU("ARMN"),	PUCD_SCRIPT_ARMENIAN,
	TQU("AVESTAN"),	PUCD_SCRIPT_AVESTAN,
	TQU("AVST"),	PUCD_SCRIPT_AVESTAN,
	TQU("BALI"),	PUCD_SCRIPT_BALINESE,
	TQU("BALINESE"),	PUCD_SCRIPT_BALINESE,
	TQU("BAMU"),	PUCD_SCRIPT_BAMUM,
	TQU("BAMUM"),	PUCD_SCRIPT_BAMUM,
	TQU("BATAK"),	PUCD_SCRIPT_BATAK,
	TQU("BATK"),	PUCD_SCRIPT_BATAK,
	TQU("BENG"),	PUCD_SCRIPT_BENGALI,
	TQU("BENGALI"),	PUCD_SCRIPT_BENGALI,
	TQU("BOPO"),	PUCD_SCRIPT_BOPOMOFO,
	TQU("BOPOMOFO"),	PUCD_SCRIPT_BOPOMOFO,
	TQU("BRAH"),	PUCD_SCRIPT_BRAHMI,
	TQU("BRAHMI"),	PUCD_SCRIPT_BRAHMI,
	TQU("BRAI"),	PUCD_SCRIPT_BRAILLE,
	TQU("BRAILLE"),	PUCD_SCRIPT_BRAILLE,
	TQU("BUGI"),	PUCD_SCRIPT_BUGINESE,
	TQU("BUGINESE"),	PUCD_SCRIPT_BUGINESE,
	TQU("BUHD"),	PUCD_SCRIPT_BUHID,
	TQU("BUHID"),	PUCD_SCRIPT_BUHID,
	TQU("CAKM"),	PUCD_SCRIPT_CHAKMA,
	TQU("CANADIANABORIGINAL"),	PUCD_SCRIPT_CANADIAN_ABORIGINAL,
	TQU("CANS"),	PUCD_SCRIPT_CANADIAN_ABORIGINAL,
	TQU("CARI"),	PUCD_SCRIPT_CARIAN,
	TQU("CARIAN"),	PUCD_SCRIPT_CARIAN,
	TQU("CHAKMA"),	PUCD_SCRIPT_CHAKMA,
	TQU("CHAM"),	PUCD_SCRIPT_CHAM,
	TQU("CHER"),	PUCD_SCRIPT_CHEROKEE,
	TQU("CHEROKEE"),	PUCD_SCRIPT_CHEROKEE,
	TQU("COMMON"),	PUCD_SCRIPT_COMMON,
	TQU("COPT"),	PUCD_SCRIPT_COPTIC,
	TQU("COPTIC"),	PUCD_SCRIPT_COPTIC,
	TQU("CPRT"),	PUCD_SCRIPT_CYPRIOT,
	TQU("CUNEIFORM"),	PUCD_SCRIPT_CUNEIFORM,
	TQU("CYPRIOT"),	PUCD_SCRIPT_CYPRIOT,
	TQU("CYRILLIC"),	PUCD_SCRIPT_CYRILLIC,
	TQU("CYRL"),	PUCD_SCRIPT_CYRILLIC,
	TQU("DESERET"),	PUCD_SCRIPT_DESERET,
	TQU("DEVA"),	PUCD_SCRIPT_DEVANAGARI,
	TQU("DEVANAGARI"),	PUCD_SCRIPT_DEVANAGARI,
	TQU("DSRT"),	PUCD_SCRIPT_DESERET,
	TQU("EGYP"),	PUCD_SCRIPT_EGYPTIAN_HIEROGLYPHS,
	TQU("EGYPTIANHIEROGLYPHS"),	PUCD_SCRIPT_EGYPTIAN_HIEROGLYPHS,
	TQU("ETHI"),	PUCD_SCRIPT_ETHIOPIC,
	TQU("ETHIOPIC"),	PUCD_SCRIPT_ETHIOPIC,
	TQU("GEOR"),	PUCD_SCRIPT_GEORGIAN,
	TQU("GEORGIAN"),	PUCD_SCRIPT_GEORGIAN,
	TQU("GLAG"),	PUCD_SCRIPT_GLAGOLITIC,
	TQU("GLAGOLITIC"),	PUCD_SCRIPT_GLAGOLITIC,
	TQU("GOTH"),	PUCD_SCRIPT_GOTHIC,
	TQU("GOTHIC"),	PUCD_SCRIPT_GOTHIC,
	TQU("GREEK"),	PUCD_SCRIPT_GREEK,
	TQU("GREK"),	PUCD_SCRIPT_GREEK,
	TQU("GUJARATI"),	PUCD_SCRIPT_GUJARATI,
	TQU("GUJR"),	PUCD_SCRIPT_GUJARATI,
	TQU("GURMUKHI"),	PUCD_SCRIPT_GURMUKHI,
	TQU("GURU"),	PUCD_SCRIPT_GURMUKHI,
	TQU("HAN"),	PUCD_SCRIPT_HAN,
	TQU("HANG"),	PUCD_SCRIPT_HANGUL,
	TQU("HANGUL"),	PUCD_SCRIPT_HANGUL,
	TQU("HANI"),	PUCD_SCRIPT_HAN,
	TQU("HANO"),	PUCD_SCRIPT_HANUNOO,
	TQU("HANUNOO"),	PUCD_SCRIPT_HANUNOO,
	TQU("HEBR"),	PUCD_SCRIPT_HEBREW,
	TQU("HEBREW"),	PUCD_SCRIPT_HEBREW,
	TQU("HIRA"),	PUCD_SCRIPT_HIRAGANA,
	TQU("HIRAGANA"),	PUCD_SCRIPT_HIRAGANA,
	TQU("IMPERIALARAMAIC"),	PUCD_SCRIPT_IMPERIAL_ARAMAIC,
	TQU("INHERITED"),	PUCD_SCRIPT_INHERITED,
	TQU("INSCRIPTIONALPAHLAVI"),	PUCD_SCRIPT_INSCRIPTIONAL_PAHLAVI,
	TQU("INSCRIPTIONALPARTHIAN"),	PUCD_SCRIPT_INSCRIPTIONAL_PARTHIAN,
	TQU("ITAL"),	PUCD_SCRIPT_OLD_ITALIC,
	TQU("JAVA"),	PUCD_SCRIPT_JAVANESE,
	TQU("JAVANESE"),	PUCD_SCRIPT_JAVANESE,
	TQU("KAITHI"),	PUCD_SCRIPT_KAITHI,
	TQU("KALI"),	PUCD_SCRIPT_KAYAH_LI,
	TQU("KANA"),	PUCD_SCRIPT_KATAKANA,
	TQU("KANNADA"),	PUCD_SCRIPT_KANNADA,
	TQU("KATAKANA"),	PUCD_SCRIPT_KATAKANA,
	TQU("KAYAHLI"),	PUCD_SCRIPT_KAYAH_LI,
	TQU("KHAR"),	PUCD_SCRIPT_KHAROSHTHI,
	TQU("KHAROSHTHI"),	PUCD_SCRIPT_KHAROSHTHI,
	TQU("KHMER"),	PUCD_SCRIPT_KHMER,
	TQU("KHMR"),	PUCD_SCRIPT_KHMER,
	TQU("KNDA"),	PUCD_SCRIPT_KANNADA,
	TQU("KTHI"),	PUCD_SCRIPT_KAITHI,
	TQU("LANA"),	PUCD_SCRIPT_TAI_THAM,
	TQU("LAO"),	PUCD_SCRIPT_LAO,
	TQU("LAOO"),	PUCD_SCRIPT_LAO,
	TQU("LATIN"),	PUCD_SCRIPT_LATIN,
	TQU("LATN"),	PUCD_SCRIPT_LATIN,
	TQU("LEPC"),	PUCD_SCRIPT_LEPCHA,
	TQU("LEPCHA"),	PUCD_SCRIPT_LEPCHA,
	TQU("LIMB"),	PUCD_SCRIPT_LIMBU,
	TQU("LIMBU"),	PUCD_SCRIPT_LIMBU,
	TQU("LINB"),	PUCD_SCRIPT_LINEAR_B,
	TQU("LINEARB"),	PUCD_SCRIPT_LINEAR_B,
	TQU("LISU"),	PUCD_SCRIPT_LISU,
	TQU("LYCI"),	PUCD_SCRIPT_LYCIAN,
	TQU("LYCIAN"),	PUCD_SCRIPT_LYCIAN,
	TQU("LYDI"),	PUCD_SCRIPT_LYDIAN,
	TQU("LYDIAN"),	PUCD_SCRIPT_LYDIAN,
	TQU("MALAYALAM"),	PUCD_SCRIPT_MALAYALAM,
	TQU("MAND"),	PUCD_SCRIPT_MANDAIC,
	TQU("MANDAIC"),	PUCD_SCRIPT_MANDAIC,
	TQU("MEETEIMAYEK"),	PUCD_SCRIPT_MEETEI_MAYEK,
	TQU("MERC"),	PUCD_SCRIPT_MEROITIC_CURSIVE,
	TQU("MERO"),	PUCD_SCRIPT_MEROITIC_HIEROGLYPHS,
	TQU("MEROITICCURSIVE"),	PUCD_SCRIPT_MEROITIC_CURSIVE,
	TQU("MEROITICHIEROGLYPHS"),	PUCD_SCRIPT_MEROITIC_HIEROGLYPHS,
	TQU("MIAO"),	PUCD_SCRIPT_MIAO,
	TQU("MLYM"),	PUCD_SCRIPT_MALAYALAM,
	TQU("MONG"),	PUCD_SCRIPT_MONGOLIAN,
	TQU("MONGOLIAN"),	PUCD_SCRIPT_MONGOLIAN,
	TQU("MTEI"),	PUCD_SCRIPT_MEETEI_MAYEK,
	TQU("MYANMAR"),	PUCD_SCRIPT_MYANMAR,
	TQU("MYMR"),	PUCD_SCRIPT_MYANMAR,
	TQU("NEWTAILUE"),	PUCD_SCRIPT_NEW_TAI_LUE,
	TQU("NKO"),	PUCD_SCRIPT_NKO,
	TQU("NKOO"),	PUCD_SCRIPT_NKO,
	TQU("OGAM"),	PUCD_SCRIPT_OGHAM,
	TQU("OGHAM"),	PUCD_SCRIPT_OGHAM,
	TQU("OLCHIKI"),	PUCD_SCRIPT_OL_CHIKI,
	TQU("OLCK"),	PUCD_SCRIPT_OL_CHIKI,
	TQU("OLDITALIC"),	PUCD_SCRIPT_OLD_ITALIC,
	TQU("OLDPERSIAN"),	PUCD_SCRIPT_OLD_PERSIAN,
	TQU("OLDSOUTHARABIAN"),	PUCD_SCRIPT_OLD_SOUTH_ARABIAN,
	TQU("OLDTURKIC"),	PUCD_SCRIPT_OLD_TURKIC,
	TQU("ORIYA"),	PUCD_SCRIPT_ORIYA,
	TQU("ORKH"),	PUCD_SCRIPT_OLD_TURKIC,
	TQU("ORYA"),	PUCD_SCRIPT_ORIYA,
	TQU("OSMA"),	PUCD_SCRIPT_OSMANYA,
	TQU("OSMANYA"),	PUCD_SCRIPT_OSMANYA,
	TQU("PHAG"),	PUCD_SCRIPT_PHAGS_PA,
	TQU("PHAGSPA"),	PUCD_SCRIPT_PHAGS_PA,
	TQU("PHLI"),	PUCD_SCRIPT_INSCRIPTIONAL_PAHLAVI,
	TQU("PHNX"),	PUCD_SCRIPT_PHOENICIAN,
	TQU("PHOENICIAN"),	PUCD_SCRIPT_PHOENICIAN,
	TQU("PLRD"),	PUCD_SCRIPT_MIAO,
	TQU("PRTI"),	PUCD_SCRIPT_INSCRIPTIONAL_PARTHIAN,
	TQU("QAAC"),	PUCD_SCRIPT_COPTIC,
	TQU("QAAI"),	PUCD_SCRIPT_INHERITED,
	TQU("REJANG"),	PUCD_SCRIPT_REJANG,
	TQU("RJNG"),	PUCD_SCRIPT_REJANG,
	TQU("RUNIC"),	PUCD_SCRIPT_RUNIC,
	TQU("RUNR"),	PUCD_SCRIPT_RUNIC,
	TQU("SAMARITAN"),	PUCD_SCRIPT_SAMARITAN,
	TQU("SAMR"),	PUCD_SCRIPT_SAMARITAN,
	TQU("SARB"),	PUCD_SCRIPT_OLD_SOUTH_ARABIAN,
	TQU("SAUR"),	PUCD_SCRIPT_SAURASHTRA,
	TQU("SAURASHTRA"),	PUCD_SCRIPT_SAURASHTRA,
	TQU("SHARADA"),	PUCD_SCRIPT_SHARADA,
	TQU("SHAVIAN"),	PUCD_SCRIPT_SHAVIAN,
	TQU("SHAW"),	PUCD_SCRIPT_SHAVIAN,
	TQU("SHRD"),	PUCD_SCRIPT_SHARADA,
	TQU("SINH"),	PUCD_SCRIPT_SINHALA,
	TQU("SINHALA"),	PUCD_SCRIPT_SINHALA,
	TQU("SORA"),	PUCD_SCRIPT_SORA_SOMPENG,
	TQU("SORASOMPENG"),	PUCD_SCRIPT_SORA_SOMPENG,
	TQU("SUND"),	PUCD_SCRIPT_SUNDANESE,
	TQU("SUNDANESE"),	PUCD_SCRIPT_SUNDANESE,
	TQU("SYLO"),	PUCD_SCRIPT_SYLOTI_NAGRI,
	TQU("SYLOTINAGRI"),	PUCD_SCRIPT_SYLOTI_NAGRI,
	TQU("SYRC"),	PUCD_SCRIPT_SYRIAC,
	TQU("SYRIAC"),	PUCD_SCRIPT_SYRIAC,
	TQU("TAGALOG"),	PUCD_SCRIPT_TAGALOG,
	TQU("TAGB"),	PUCD_SCRIPT_TAGBANWA,
	TQU("TAGBANWA"),	PUCD_SCRIPT_TAGBANWA,
	TQU("TAILE"),	PUCD_SCRIPT_TAI_LE,
	TQU("TAITHAM"),	PUCD_SCRIPT_TAI_THAM,
	TQU("TAIVIET"),	PUCD_SCRIPT_TAI_VIET,
	TQU("TAKR"),	PUCD_SCRIPT_TAKRI,
	TQU("TAKRI"),	PUCD_SCRIPT_TAKRI,
	TQU("TALE"),	PUCD_SCRIPT_TAI_LE,
	TQU("TALU"),	PUCD_SCRIPT_NEW_TAI_LUE,
	TQU("TAMIL"),	PUCD_SCRIPT_TAMIL,
	TQU("TAML"),	PUCD_SCRIPT_TAMIL,
	TQU("TAVT"),	PUCD_SCRIPT_TAI_VIET,
	TQU("TELU"),	PUCD_SCRIPT_TELUGU,
	TQU("TELUGU"),	PUCD_SCRIPT_TELUGU,
	TQU("TFNG"),	PUCD_SCRIPT_TIFINAGH,
	TQU("TGLG"),	PUCD_SCRIPT_TAGALOG,
	TQU("THAA"),	PUCD_SCRIPT_THAANA,
	TQU("THAANA"),	PUCD_SCRIPT_THAANA,
	TQU("THAI"),	PUCD_SCRIPT_THAI,
	TQU("TIBETAN"),	PUCD_SCRIPT_TIBETAN,
	TQU("TIBT"),	PUCD_SCRIPT_TIBETAN,
	TQU("TIFINAGH"),	PUCD_SCRIPT_TIFINAGH,
	TQU("UGAR"),	PUCD_SCRIPT_UGARITIC,
	TQU("UGARITIC"),	PUCD_SCRIPT_UGARITIC,
	TQU("UNKNOWN"),	PUCD_SCRIPT_UNKNOWN,
	TQU("VAI"),	PUCD_SCRIPT_VAI,
	TQU("VAII"),	PUCD_SCRIPT_VAI,
	TQU("XPEO"),	PUCD_SCRIPT_OLD_PERSIAN,
	TQU("XSUX"),	PUCD_SCRIPT_CUNEIFORM,
	TQU("YI"),	PUCD_SCRIPT_YI,
	TQU("YIII"),	PUCD_SCRIPT_YI,
	TQU("ZINH"),	PUCD_SCRIPT_INHERITED,
	TQU("ZYYY"),	PUCD_SCRIPT_COMMON,
	TQU("ZZZZ"),	PUCD_SCRIPT_UNKNOWN,
};
int	nScriptNameIdMap	= sizeof(ScriptNameIdMap) / sizeof(PSPSzIdMap);
*/
T_UCP	cpaScriptNameArab[]	= { 0x0061, 0x0072, 0x0061, 0x0062, 0, };
T_UCP	cpaScriptNameArabic[]	= { 0x0061, 0x0072, 0x0061, 0x0062, 0x0069, 0x0063, 0, };
T_UCP	cpaScriptNameArmenian[]	= { 0x0061, 0x0072, 0x006D, 0x0065, 0x006E, 0x0069, 0x0061, 0x006E, 0, };
T_UCP	cpaScriptNameArmi[]	= { 0x0061, 0x0072, 0x006D, 0x0069, 0, };
T_UCP	cpaScriptNameArmn[]	= { 0x0061, 0x0072, 0x006D, 0x006E, 0, };
T_UCP	cpaScriptNameAvestan[]	= { 0x0061, 0x0076, 0x0065, 0x0073, 0x0074, 0x0061, 0x006E, 0, };
T_UCP	cpaScriptNameAvst[]	= { 0x0061, 0x0076, 0x0073, 0x0074, 0, };
T_UCP	cpaScriptNameBali[]	= { 0x0062, 0x0061, 0x006C, 0x0069, 0, };
T_UCP	cpaScriptNameBalinese[]	= { 0x0062, 0x0061, 0x006C, 0x0069, 0x006E, 0x0065, 0x0073, 0x0065, 0, };
T_UCP	cpaScriptNameBamu[]	= { 0x0062, 0x0061, 0x006D, 0x0075, 0, };
T_UCP	cpaScriptNameBamum[]	= { 0x0062, 0x0061, 0x006D, 0x0075, 0x006D, 0, };
T_UCP	cpaScriptNameBatak[]	= { 0x0062, 0x0061, 0x0074, 0x0061, 0x006B, 0, };
T_UCP	cpaScriptNameBatk[]	= { 0x0062, 0x0061, 0x0074, 0x006B, 0, };
T_UCP	cpaScriptNameBeng[]	= { 0x0062, 0x0065, 0x006E, 0x0067, 0, };
T_UCP	cpaScriptNameBengali[]	= { 0x0062, 0x0065, 0x006E, 0x0067, 0x0061, 0x006C, 0x0069, 0, };
T_UCP	cpaScriptNameBopo[]	= { 0x0062, 0x006F, 0x0070, 0x006F, 0, };
T_UCP	cpaScriptNameBopomofo[]	= { 0x0062, 0x006F, 0x0070, 0x006F, 0x006D, 0x006F, 0x0066, 0x006F, 0, };
T_UCP	cpaScriptNameBrah[]	= { 0x0062, 0x0072, 0x0061, 0x0068, 0, };
T_UCP	cpaScriptNameBrahmi[]	= { 0x0062, 0x0072, 0x0061, 0x0068, 0x006D, 0x0069, 0, };
T_UCP	cpaScriptNameBrai[]	= { 0x0062, 0x0072, 0x0061, 0x0069, 0, };
T_UCP	cpaScriptNameBraille[]	= { 0x0062, 0x0072, 0x0061, 0x0069, 0x006C, 0x006C, 0x0065, 0, };
T_UCP	cpaScriptNameBugi[]	= { 0x0062, 0x0075, 0x0067, 0x0069, 0, };
T_UCP	cpaScriptNameBuginese[]	= { 0x0062, 0x0075, 0x0067, 0x0069, 0x006E, 0x0065, 0x0073, 0x0065, 0, };
T_UCP	cpaScriptNameBuhd[]	= { 0x0062, 0x0075, 0x0068, 0x0064, 0, };
T_UCP	cpaScriptNameBuhid[]	= { 0x0062, 0x0075, 0x0068, 0x0069, 0x0064, 0, };
T_UCP	cpaScriptNameCakm[]	= { 0x0063, 0x0061, 0x006B, 0x006D, 0, };
T_UCP	cpaScriptNameCanadianaboriginal[]	= { 0x0063, 0x0061, 0x006E, 0x0061, 0x0064, 0x0069, 0x0061, 0x006E, 0x0061, 0x0062, 0x006F, 0x0072, 0x0069, 0x0067, 0x0069, 0x006E, 0x0061, 0x006C, 0, };
T_UCP	cpaScriptNameCans[]	= { 0x0063, 0x0061, 0x006E, 0x0073, 0, };
T_UCP	cpaScriptNameCari[]	= { 0x0063, 0x0061, 0x0072, 0x0069, 0, };
T_UCP	cpaScriptNameCarian[]	= { 0x0063, 0x0061, 0x0072, 0x0069, 0x0061, 0x006E, 0, };
T_UCP	cpaScriptNameChakma[]	= { 0x0063, 0x0068, 0x0061, 0x006B, 0x006D, 0x0061, 0, };
T_UCP	cpaScriptNameCham[]	= { 0x0063, 0x0068, 0x0061, 0x006D, 0, };
T_UCP	cpaScriptNameCher[]	= { 0x0063, 0x0068, 0x0065, 0x0072, 0, };
T_UCP	cpaScriptNameCherokee[]	= { 0x0063, 0x0068, 0x0065, 0x0072, 0x006F, 0x006B, 0x0065, 0x0065, 0, };
T_UCP	cpaScriptNameCommon[]	= { 0x0063, 0x006F, 0x006D, 0x006D, 0x006F, 0x006E, 0, };
T_UCP	cpaScriptNameCopt[]	= { 0x0063, 0x006F, 0x0070, 0x0074, 0, };
T_UCP	cpaScriptNameCoptic[]	= { 0x0063, 0x006F, 0x0070, 0x0074, 0x0069, 0x0063, 0, };
T_UCP	cpaScriptNameCprt[]	= { 0x0063, 0x0070, 0x0072, 0x0074, 0, };
T_UCP	cpaScriptNameCuneiform[]	= { 0x0063, 0x0075, 0x006E, 0x0065, 0x0069, 0x0066, 0x006F, 0x0072, 0x006D, 0, };
T_UCP	cpaScriptNameCypriot[]	= { 0x0063, 0x0079, 0x0070, 0x0072, 0x0069, 0x006F, 0x0074, 0, };
T_UCP	cpaScriptNameCyrillic[]	= { 0x0063, 0x0079, 0x0072, 0x0069, 0x006C, 0x006C, 0x0069, 0x0063, 0, };
T_UCP	cpaScriptNameCyrl[]	= { 0x0063, 0x0079, 0x0072, 0x006C, 0, };
T_UCP	cpaScriptNameDeseret[]	= { 0x0064, 0x0065, 0x0073, 0x0065, 0x0072, 0x0065, 0x0074, 0, };
T_UCP	cpaScriptNameDeva[]	= { 0x0064, 0x0065, 0x0076, 0x0061, 0, };
T_UCP	cpaScriptNameDevanagari[]	= { 0x0064, 0x0065, 0x0076, 0x0061, 0x006E, 0x0061, 0x0067, 0x0061, 0x0072, 0x0069, 0, };
T_UCP	cpaScriptNameDsrt[]	= { 0x0064, 0x0073, 0x0072, 0x0074, 0, };
T_UCP	cpaScriptNameEgyp[]	= { 0x0065, 0x0067, 0x0079, 0x0070, 0, };
T_UCP	cpaScriptNameEgyptianhieroglyphs[]	= { 0x0065, 0x0067, 0x0079, 0x0070, 0x0074, 0x0069, 0x0061, 0x006E, 0x0068, 0x0069, 0x0065, 0x0072, 0x006F, 0x0067, 0x006C, 0x0079, 0x0070, 0x0068, 0x0073, 0, };
T_UCP	cpaScriptNameEthi[]	= { 0x0065, 0x0074, 0x0068, 0x0069, 0, };
T_UCP	cpaScriptNameEthiopic[]	= { 0x0065, 0x0074, 0x0068, 0x0069, 0x006F, 0x0070, 0x0069, 0x0063, 0, };
T_UCP	cpaScriptNameGeor[]	= { 0x0067, 0x0065, 0x006F, 0x0072, 0, };
T_UCP	cpaScriptNameGeorgian[]	= { 0x0067, 0x0065, 0x006F, 0x0072, 0x0067, 0x0069, 0x0061, 0x006E, 0, };
T_UCP	cpaScriptNameGlag[]	= { 0x0067, 0x006C, 0x0061, 0x0067, 0, };
T_UCP	cpaScriptNameGlagolitic[]	= { 0x0067, 0x006C, 0x0061, 0x0067, 0x006F, 0x006C, 0x0069, 0x0074, 0x0069, 0x0063, 0, };
T_UCP	cpaScriptNameGoth[]	= { 0x0067, 0x006F, 0x0074, 0x0068, 0, };
T_UCP	cpaScriptNameGothic[]	= { 0x0067, 0x006F, 0x0074, 0x0068, 0x0069, 0x0063, 0, };
T_UCP	cpaScriptNameGreek[]	= { 0x0067, 0x0072, 0x0065, 0x0065, 0x006B, 0, };
T_UCP	cpaScriptNameGrek[]	= { 0x0067, 0x0072, 0x0065, 0x006B, 0, };
T_UCP	cpaScriptNameGujarati[]	= { 0x0067, 0x0075, 0x006A, 0x0061, 0x0072, 0x0061, 0x0074, 0x0069, 0, };
T_UCP	cpaScriptNameGujr[]	= { 0x0067, 0x0075, 0x006A, 0x0072, 0, };
T_UCP	cpaScriptNameGurmukhi[]	= { 0x0067, 0x0075, 0x0072, 0x006D, 0x0075, 0x006B, 0x0068, 0x0069, 0, };
T_UCP	cpaScriptNameGuru[]	= { 0x0067, 0x0075, 0x0072, 0x0075, 0, };
T_UCP	cpaScriptNameHan[]	= { 0x0068, 0x0061, 0x006E, 0, };
T_UCP	cpaScriptNameHang[]	= { 0x0068, 0x0061, 0x006E, 0x0067, 0, };
T_UCP	cpaScriptNameHangul[]	= { 0x0068, 0x0061, 0x006E, 0x0067, 0x0075, 0x006C, 0, };
T_UCP	cpaScriptNameHani[]	= { 0x0068, 0x0061, 0x006E, 0x0069, 0, };
T_UCP	cpaScriptNameHano[]	= { 0x0068, 0x0061, 0x006E, 0x006F, 0, };
T_UCP	cpaScriptNameHanunoo[]	= { 0x0068, 0x0061, 0x006E, 0x0075, 0x006E, 0x006F, 0x006F, 0, };
T_UCP	cpaScriptNameHebr[]	= { 0x0068, 0x0065, 0x0062, 0x0072, 0, };
T_UCP	cpaScriptNameHebrew[]	= { 0x0068, 0x0065, 0x0062, 0x0072, 0x0065, 0x0077, 0, };
T_UCP	cpaScriptNameHira[]	= { 0x0068, 0x0069, 0x0072, 0x0061, 0, };
T_UCP	cpaScriptNameHiragana[]	= { 0x0068, 0x0069, 0x0072, 0x0061, 0x0067, 0x0061, 0x006E, 0x0061, 0, };
T_UCP	cpaScriptNameImperialaramaic[]	= { 0x0069, 0x006D, 0x0070, 0x0065, 0x0072, 0x0069, 0x0061, 0x006C, 0x0061, 0x0072, 0x0061, 0x006D, 0x0061, 0x0069, 0x0063, 0, };
T_UCP	cpaScriptNameInherited[]	= { 0x0069, 0x006E, 0x0068, 0x0065, 0x0072, 0x0069, 0x0074, 0x0065, 0x0064, 0, };
T_UCP	cpaScriptNameInscriptionalpahlavi[]	= { 0x0069, 0x006E, 0x0073, 0x0063, 0x0072, 0x0069, 0x0070, 0x0074, 0x0069, 0x006F, 0x006E, 0x0061, 0x006C, 0x0070, 0x0061, 0x0068, 0x006C, 0x0061, 0x0076, 0x0069, 0, };
T_UCP	cpaScriptNameInscriptionalparthian[]	= { 0x0069, 0x006E, 0x0073, 0x0063, 0x0072, 0x0069, 0x0070, 0x0074, 0x0069, 0x006F, 0x006E, 0x0061, 0x006C, 0x0070, 0x0061, 0x0072, 0x0074, 0x0068, 0x0069, 0x0061, 0x006E, 0, };
T_UCP	cpaScriptNameItal[]	= { 0x0069, 0x0074, 0x0061, 0x006C, 0, };
T_UCP	cpaScriptNameJava[]	= { 0x006A, 0x0061, 0x0076, 0x0061, 0, };
T_UCP	cpaScriptNameJavanese[]	= { 0x006A, 0x0061, 0x0076, 0x0061, 0x006E, 0x0065, 0x0073, 0x0065, 0, };
T_UCP	cpaScriptNameKaithi[]	= { 0x006B, 0x0061, 0x0069, 0x0074, 0x0068, 0x0069, 0, };
T_UCP	cpaScriptNameKali[]	= { 0x006B, 0x0061, 0x006C, 0x0069, 0, };
T_UCP	cpaScriptNameKana[]	= { 0x006B, 0x0061, 0x006E, 0x0061, 0, };
T_UCP	cpaScriptNameKannada[]	= { 0x006B, 0x0061, 0x006E, 0x006E, 0x0061, 0x0064, 0x0061, 0, };
T_UCP	cpaScriptNameKatakana[]	= { 0x006B, 0x0061, 0x0074, 0x0061, 0x006B, 0x0061, 0x006E, 0x0061, 0, };
T_UCP	cpaScriptNameKayahli[]	= { 0x006B, 0x0061, 0x0079, 0x0061, 0x0068, 0x006C, 0x0069, 0, };
T_UCP	cpaScriptNameKhar[]	= { 0x006B, 0x0068, 0x0061, 0x0072, 0, };
T_UCP	cpaScriptNameKharoshthi[]	= { 0x006B, 0x0068, 0x0061, 0x0072, 0x006F, 0x0073, 0x0068, 0x0074, 0x0068, 0x0069, 0, };
T_UCP	cpaScriptNameKhmer[]	= { 0x006B, 0x0068, 0x006D, 0x0065, 0x0072, 0, };
T_UCP	cpaScriptNameKhmr[]	= { 0x006B, 0x0068, 0x006D, 0x0072, 0, };
T_UCP	cpaScriptNameKnda[]	= { 0x006B, 0x006E, 0x0064, 0x0061, 0, };
T_UCP	cpaScriptNameKthi[]	= { 0x006B, 0x0074, 0x0068, 0x0069, 0, };
T_UCP	cpaScriptNameLana[]	= { 0x006C, 0x0061, 0x006E, 0x0061, 0, };
T_UCP	cpaScriptNameLao[]	= { 0x006C, 0x0061, 0x006F, 0, };
T_UCP	cpaScriptNameLaoo[]	= { 0x006C, 0x0061, 0x006F, 0x006F, 0, };
T_UCP	cpaScriptNameLatin[]	= { 0x006C, 0x0061, 0x0074, 0x0069, 0x006E, 0, };
T_UCP	cpaScriptNameLatn[]	= { 0x006C, 0x0061, 0x0074, 0x006E, 0, };
T_UCP	cpaScriptNameLepc[]	= { 0x006C, 0x0065, 0x0070, 0x0063, 0, };
T_UCP	cpaScriptNameLepcha[]	= { 0x006C, 0x0065, 0x0070, 0x0063, 0x0068, 0x0061, 0, };
T_UCP	cpaScriptNameLimb[]	= { 0x006C, 0x0069, 0x006D, 0x0062, 0, };
T_UCP	cpaScriptNameLimbu[]	= { 0x006C, 0x0069, 0x006D, 0x0062, 0x0075, 0, };
T_UCP	cpaScriptNameLinb[]	= { 0x006C, 0x0069, 0x006E, 0x0062, 0, };
T_UCP	cpaScriptNameLinearb[]	= { 0x006C, 0x0069, 0x006E, 0x0065, 0x0061, 0x0072, 0x0062, 0, };
T_UCP	cpaScriptNameLisu[]	= { 0x006C, 0x0069, 0x0073, 0x0075, 0, };
T_UCP	cpaScriptNameLyci[]	= { 0x006C, 0x0079, 0x0063, 0x0069, 0, };
T_UCP	cpaScriptNameLycian[]	= { 0x006C, 0x0079, 0x0063, 0x0069, 0x0061, 0x006E, 0, };
T_UCP	cpaScriptNameLydi[]	= { 0x006C, 0x0079, 0x0064, 0x0069, 0, };
T_UCP	cpaScriptNameLydian[]	= { 0x006C, 0x0079, 0x0064, 0x0069, 0x0061, 0x006E, 0, };
T_UCP	cpaScriptNameMalayalam[]	= { 0x006D, 0x0061, 0x006C, 0x0061, 0x0079, 0x0061, 0x006C, 0x0061, 0x006D, 0, };
T_UCP	cpaScriptNameMand[]	= { 0x006D, 0x0061, 0x006E, 0x0064, 0, };
T_UCP	cpaScriptNameMandaic[]	= { 0x006D, 0x0061, 0x006E, 0x0064, 0x0061, 0x0069, 0x0063, 0, };
T_UCP	cpaScriptNameMeeteimayek[]	= { 0x006D, 0x0065, 0x0065, 0x0074, 0x0065, 0x0069, 0x006D, 0x0061, 0x0079, 0x0065, 0x006B, 0, };
T_UCP	cpaScriptNameMerc[]	= { 0x006D, 0x0065, 0x0072, 0x0063, 0, };
T_UCP	cpaScriptNameMero[]	= { 0x006D, 0x0065, 0x0072, 0x006F, 0, };
T_UCP	cpaScriptNameMeroiticcursive[]	= { 0x006D, 0x0065, 0x0072, 0x006F, 0x0069, 0x0074, 0x0069, 0x0063, 0x0063, 0x0075, 0x0072, 0x0073, 0x0069, 0x0076, 0x0065, 0, };
T_UCP	cpaScriptNameMeroitichieroglyphs[]	= { 0x006D, 0x0065, 0x0072, 0x006F, 0x0069, 0x0074, 0x0069, 0x0063, 0x0068, 0x0069, 0x0065, 0x0072, 0x006F, 0x0067, 0x006C, 0x0079, 0x0070, 0x0068, 0x0073, 0, };
T_UCP	cpaScriptNameMiao[]	= { 0x006D, 0x0069, 0x0061, 0x006F, 0, };
T_UCP	cpaScriptNameMlym[]	= { 0x006D, 0x006C, 0x0079, 0x006D, 0, };
T_UCP	cpaScriptNameMong[]	= { 0x006D, 0x006F, 0x006E, 0x0067, 0, };
T_UCP	cpaScriptNameMongolian[]	= { 0x006D, 0x006F, 0x006E, 0x0067, 0x006F, 0x006C, 0x0069, 0x0061, 0x006E, 0, };
T_UCP	cpaScriptNameMtei[]	= { 0x006D, 0x0074, 0x0065, 0x0069, 0, };
T_UCP	cpaScriptNameMyanmar[]	= { 0x006D, 0x0079, 0x0061, 0x006E, 0x006D, 0x0061, 0x0072, 0, };
T_UCP	cpaScriptNameMymr[]	= { 0x006D, 0x0079, 0x006D, 0x0072, 0, };
T_UCP	cpaScriptNameNewtailue[]	= { 0x006E, 0x0065, 0x0077, 0x0074, 0x0061, 0x0069, 0x006C, 0x0075, 0x0065, 0, };
T_UCP	cpaScriptNameNko[]	= { 0x006E, 0x006B, 0x006F, 0, };
T_UCP	cpaScriptNameNkoo[]	= { 0x006E, 0x006B, 0x006F, 0x006F, 0, };
T_UCP	cpaScriptNameOgam[]	= { 0x006F, 0x0067, 0x0061, 0x006D, 0, };
T_UCP	cpaScriptNameOgham[]	= { 0x006F, 0x0067, 0x0068, 0x0061, 0x006D, 0, };
T_UCP	cpaScriptNameOlchiki[]	= { 0x006F, 0x006C, 0x0063, 0x0068, 0x0069, 0x006B, 0x0069, 0, };
T_UCP	cpaScriptNameOlck[]	= { 0x006F, 0x006C, 0x0063, 0x006B, 0, };
T_UCP	cpaScriptNameOlditalic[]	= { 0x006F, 0x006C, 0x0064, 0x0069, 0x0074, 0x0061, 0x006C, 0x0069, 0x0063, 0, };
T_UCP	cpaScriptNameOldpersian[]	= { 0x006F, 0x006C, 0x0064, 0x0070, 0x0065, 0x0072, 0x0073, 0x0069, 0x0061, 0x006E, 0, };
T_UCP	cpaScriptNameOldsoutharabian[]	= { 0x006F, 0x006C, 0x0064, 0x0073, 0x006F, 0x0075, 0x0074, 0x0068, 0x0061, 0x0072, 0x0061, 0x0062, 0x0069, 0x0061, 0x006E, 0, };
T_UCP	cpaScriptNameOldturkic[]	= { 0x006F, 0x006C, 0x0064, 0x0074, 0x0075, 0x0072, 0x006B, 0x0069, 0x0063, 0, };
T_UCP	cpaScriptNameOriya[]	= { 0x006F, 0x0072, 0x0069, 0x0079, 0x0061, 0, };
T_UCP	cpaScriptNameOrkh[]	= { 0x006F, 0x0072, 0x006B, 0x0068, 0, };
T_UCP	cpaScriptNameOrya[]	= { 0x006F, 0x0072, 0x0079, 0x0061, 0, };
T_UCP	cpaScriptNameOsma[]	= { 0x006F, 0x0073, 0x006D, 0x0061, 0, };
T_UCP	cpaScriptNameOsmanya[]	= { 0x006F, 0x0073, 0x006D, 0x0061, 0x006E, 0x0079, 0x0061, 0, };
T_UCP	cpaScriptNamePhag[]	= { 0x0070, 0x0068, 0x0061, 0x0067, 0, };
T_UCP	cpaScriptNamePhagspa[]	= { 0x0070, 0x0068, 0x0061, 0x0067, 0x0073, 0x0070, 0x0061, 0, };
T_UCP	cpaScriptNamePhli[]	= { 0x0070, 0x0068, 0x006C, 0x0069, 0, };
T_UCP	cpaScriptNamePhnx[]	= { 0x0070, 0x0068, 0x006E, 0x0078, 0, };
T_UCP	cpaScriptNamePhoenician[]	= { 0x0070, 0x0068, 0x006F, 0x0065, 0x006E, 0x0069, 0x0063, 0x0069, 0x0061, 0x006E, 0, };
T_UCP	cpaScriptNamePlrd[]	= { 0x0070, 0x006C, 0x0072, 0x0064, 0, };
T_UCP	cpaScriptNamePrti[]	= { 0x0070, 0x0072, 0x0074, 0x0069, 0, };
T_UCP	cpaScriptNameQaac[]	= { 0x0071, 0x0061, 0x0061, 0x0063, 0, };
T_UCP	cpaScriptNameQaai[]	= { 0x0071, 0x0061, 0x0061, 0x0069, 0, };
T_UCP	cpaScriptNameRejang[]	= { 0x0072, 0x0065, 0x006A, 0x0061, 0x006E, 0x0067, 0, };
T_UCP	cpaScriptNameRjng[]	= { 0x0072, 0x006A, 0x006E, 0x0067, 0, };
T_UCP	cpaScriptNameRunic[]	= { 0x0072, 0x0075, 0x006E, 0x0069, 0x0063, 0, };
T_UCP	cpaScriptNameRunr[]	= { 0x0072, 0x0075, 0x006E, 0x0072, 0, };
T_UCP	cpaScriptNameSamaritan[]	= { 0x0073, 0x0061, 0x006D, 0x0061, 0x0072, 0x0069, 0x0074, 0x0061, 0x006E, 0, };
T_UCP	cpaScriptNameSamr[]	= { 0x0073, 0x0061, 0x006D, 0x0072, 0, };
T_UCP	cpaScriptNameSarb[]	= { 0x0073, 0x0061, 0x0072, 0x0062, 0, };
T_UCP	cpaScriptNameSaur[]	= { 0x0073, 0x0061, 0x0075, 0x0072, 0, };
T_UCP	cpaScriptNameSaurashtra[]	= { 0x0073, 0x0061, 0x0075, 0x0072, 0x0061, 0x0073, 0x0068, 0x0074, 0x0072, 0x0061, 0, };
T_UCP	cpaScriptNameSharada[]	= { 0x0073, 0x0068, 0x0061, 0x0072, 0x0061, 0x0064, 0x0061, 0, };
T_UCP	cpaScriptNameShavian[]	= { 0x0073, 0x0068, 0x0061, 0x0076, 0x0069, 0x0061, 0x006E, 0, };
T_UCP	cpaScriptNameShaw[]	= { 0x0073, 0x0068, 0x0061, 0x0077, 0, };
T_UCP	cpaScriptNameShrd[]	= { 0x0073, 0x0068, 0x0072, 0x0064, 0, };
T_UCP	cpaScriptNameSinh[]	= { 0x0073, 0x0069, 0x006E, 0x0068, 0, };
T_UCP	cpaScriptNameSinhala[]	= { 0x0073, 0x0069, 0x006E, 0x0068, 0x0061, 0x006C, 0x0061, 0, };
T_UCP	cpaScriptNameSora[]	= { 0x0073, 0x006F, 0x0072, 0x0061, 0, };
T_UCP	cpaScriptNameSorasompeng[]	= { 0x0073, 0x006F, 0x0072, 0x0061, 0x0073, 0x006F, 0x006D, 0x0070, 0x0065, 0x006E, 0x0067, 0, };
T_UCP	cpaScriptNameSund[]	= { 0x0073, 0x0075, 0x006E, 0x0064, 0, };
T_UCP	cpaScriptNameSundanese[]	= { 0x0073, 0x0075, 0x006E, 0x0064, 0x0061, 0x006E, 0x0065, 0x0073, 0x0065, 0, };
T_UCP	cpaScriptNameSylo[]	= { 0x0073, 0x0079, 0x006C, 0x006F, 0, };
T_UCP	cpaScriptNameSylotinagri[]	= { 0x0073, 0x0079, 0x006C, 0x006F, 0x0074, 0x0069, 0x006E, 0x0061, 0x0067, 0x0072, 0x0069, 0, };
T_UCP	cpaScriptNameSyrc[]	= { 0x0073, 0x0079, 0x0072, 0x0063, 0, };
T_UCP	cpaScriptNameSyriac[]	= { 0x0073, 0x0079, 0x0072, 0x0069, 0x0061, 0x0063, 0, };
T_UCP	cpaScriptNameTagalog[]	= { 0x0074, 0x0061, 0x0067, 0x0061, 0x006C, 0x006F, 0x0067, 0, };
T_UCP	cpaScriptNameTagb[]	= { 0x0074, 0x0061, 0x0067, 0x0062, 0, };
T_UCP	cpaScriptNameTagbanwa[]	= { 0x0074, 0x0061, 0x0067, 0x0062, 0x0061, 0x006E, 0x0077, 0x0061, 0, };
T_UCP	cpaScriptNameTaile[]	= { 0x0074, 0x0061, 0x0069, 0x006C, 0x0065, 0, };
T_UCP	cpaScriptNameTaitham[]	= { 0x0074, 0x0061, 0x0069, 0x0074, 0x0068, 0x0061, 0x006D, 0, };
T_UCP	cpaScriptNameTaiviet[]	= { 0x0074, 0x0061, 0x0069, 0x0076, 0x0069, 0x0065, 0x0074, 0, };
T_UCP	cpaScriptNameTakr[]	= { 0x0074, 0x0061, 0x006B, 0x0072, 0, };
T_UCP	cpaScriptNameTakri[]	= { 0x0074, 0x0061, 0x006B, 0x0072, 0x0069, 0, };
T_UCP	cpaScriptNameTale[]	= { 0x0074, 0x0061, 0x006C, 0x0065, 0, };
T_UCP	cpaScriptNameTalu[]	= { 0x0074, 0x0061, 0x006C, 0x0075, 0, };
T_UCP	cpaScriptNameTamil[]	= { 0x0074, 0x0061, 0x006D, 0x0069, 0x006C, 0, };
T_UCP	cpaScriptNameTaml[]	= { 0x0074, 0x0061, 0x006D, 0x006C, 0, };
T_UCP	cpaScriptNameTavt[]	= { 0x0074, 0x0061, 0x0076, 0x0074, 0, };
T_UCP	cpaScriptNameTelu[]	= { 0x0074, 0x0065, 0x006C, 0x0075, 0, };
T_UCP	cpaScriptNameTelugu[]	= { 0x0074, 0x0065, 0x006C, 0x0075, 0x0067, 0x0075, 0, };
T_UCP	cpaScriptNameTfng[]	= { 0x0074, 0x0066, 0x006E, 0x0067, 0, };
T_UCP	cpaScriptNameTglg[]	= { 0x0074, 0x0067, 0x006C, 0x0067, 0, };
T_UCP	cpaScriptNameThaa[]	= { 0x0074, 0x0068, 0x0061, 0x0061, 0, };
T_UCP	cpaScriptNameThaana[]	= { 0x0074, 0x0068, 0x0061, 0x0061, 0x006E, 0x0061, 0, };
T_UCP	cpaScriptNameThai[]	= { 0x0074, 0x0068, 0x0061, 0x0069, 0, };
T_UCP	cpaScriptNameTibetan[]	= { 0x0074, 0x0069, 0x0062, 0x0065, 0x0074, 0x0061, 0x006E, 0, };
T_UCP	cpaScriptNameTibt[]	= { 0x0074, 0x0069, 0x0062, 0x0074, 0, };
T_UCP	cpaScriptNameTifinagh[]	= { 0x0074, 0x0069, 0x0066, 0x0069, 0x006E, 0x0061, 0x0067, 0x0068, 0, };
T_UCP	cpaScriptNameUgar[]	= { 0x0075, 0x0067, 0x0061, 0x0072, 0, };
T_UCP	cpaScriptNameUgaritic[]	= { 0x0075, 0x0067, 0x0061, 0x0072, 0x0069, 0x0074, 0x0069, 0x0063, 0, };
T_UCP	cpaScriptNameUnknown[]	= { 0x0075, 0x006E, 0x006B, 0x006E, 0x006F, 0x0077, 0x006E, 0, };
T_UCP	cpaScriptNameVai[]	= { 0x0076, 0x0061, 0x0069, 0, };
T_UCP	cpaScriptNameVaii[]	= { 0x0076, 0x0061, 0x0069, 0x0069, 0, };
T_UCP	cpaScriptNameXpeo[]	= { 0x0078, 0x0070, 0x0065, 0x006F, 0, };
T_UCP	cpaScriptNameXsux[]	= { 0x0078, 0x0073, 0x0075, 0x0078, 0, };
T_UCP	cpaScriptNameYi[]	= { 0x0079, 0x0069, 0, };
T_UCP	cpaScriptNameYiii[]	= { 0x0079, 0x0069, 0x0069, 0x0069, 0, };
T_UCP	cpaScriptNameZinh[]	= { 0x007A, 0x0069, 0x006E, 0x0068, 0, };
T_UCP	cpaScriptNameZyyy[]	= { 0x007A, 0x0079, 0x0079, 0x0079, 0, };
T_UCP	cpaScriptNameZzzz[]	= { 0x007A, 0x007A, 0x007A, 0x007A, 0, };

PSPropertyValueIdMap	siScriptIdMap[]	=
{
	cpaScriptNameArab,	TQU("arab"),	PUCD_SCRIPT_ARABIC,
	cpaScriptNameArabic,	TQU("arabic"),	PUCD_SCRIPT_ARABIC,
	cpaScriptNameArmenian,	TQU("armenian"),	PUCD_SCRIPT_ARMENIAN,
	cpaScriptNameArmi,	TQU("armi"),	PUCD_SCRIPT_IMPERIAL_ARAMAIC,
	cpaScriptNameArmn,	TQU("armn"),	PUCD_SCRIPT_ARMENIAN,
	cpaScriptNameAvestan,	TQU("avestan"),	PUCD_SCRIPT_AVESTAN,
	cpaScriptNameAvst,	TQU("avst"),	PUCD_SCRIPT_AVESTAN,
	cpaScriptNameBali,	TQU("bali"),	PUCD_SCRIPT_BALINESE,
	cpaScriptNameBalinese,	TQU("balinese"),	PUCD_SCRIPT_BALINESE,
	cpaScriptNameBamu,	TQU("bamu"),	PUCD_SCRIPT_BAMUM,
	cpaScriptNameBamum,	TQU("bamum"),	PUCD_SCRIPT_BAMUM,
	cpaScriptNameBatak,	TQU("batak"),	PUCD_SCRIPT_BATAK,
	cpaScriptNameBatk,	TQU("batk"),	PUCD_SCRIPT_BATAK,
	cpaScriptNameBeng,	TQU("beng"),	PUCD_SCRIPT_BENGALI,
	cpaScriptNameBengali,	TQU("bengali"),	PUCD_SCRIPT_BENGALI,
	cpaScriptNameBopo,	TQU("bopo"),	PUCD_SCRIPT_BOPOMOFO,
	cpaScriptNameBopomofo,	TQU("bopomofo"),	PUCD_SCRIPT_BOPOMOFO,
	cpaScriptNameBrah,	TQU("brah"),	PUCD_SCRIPT_BRAHMI,
	cpaScriptNameBrahmi,	TQU("brahmi"),	PUCD_SCRIPT_BRAHMI,
	cpaScriptNameBrai,	TQU("brai"),	PUCD_SCRIPT_BRAILLE,
	cpaScriptNameBraille,	TQU("braille"),	PUCD_SCRIPT_BRAILLE,
	cpaScriptNameBugi,	TQU("bugi"),	PUCD_SCRIPT_BUGINESE,
	cpaScriptNameBuginese,	TQU("buginese"),	PUCD_SCRIPT_BUGINESE,
	cpaScriptNameBuhd,	TQU("buhd"),	PUCD_SCRIPT_BUHID,
	cpaScriptNameBuhid,	TQU("buhid"),	PUCD_SCRIPT_BUHID,
	cpaScriptNameCakm,	TQU("cakm"),	PUCD_SCRIPT_CHAKMA,
	cpaScriptNameCanadianaboriginal,	TQU("canadianaboriginal"),	PUCD_SCRIPT_CANADIAN_ABORIGINAL,
	cpaScriptNameCans,	TQU("cans"),	PUCD_SCRIPT_CANADIAN_ABORIGINAL,
	cpaScriptNameCari,	TQU("cari"),	PUCD_SCRIPT_CARIAN,
	cpaScriptNameCarian,	TQU("carian"),	PUCD_SCRIPT_CARIAN,
	cpaScriptNameChakma,	TQU("chakma"),	PUCD_SCRIPT_CHAKMA,
	cpaScriptNameCham,	TQU("cham"),	PUCD_SCRIPT_CHAM,
	cpaScriptNameCher,	TQU("cher"),	PUCD_SCRIPT_CHEROKEE,
	cpaScriptNameCherokee,	TQU("cherokee"),	PUCD_SCRIPT_CHEROKEE,
	cpaScriptNameCommon,	TQU("common"),	PUCD_SCRIPT_COMMON,
	cpaScriptNameCopt,	TQU("copt"),	PUCD_SCRIPT_COPTIC,
	cpaScriptNameCoptic,	TQU("coptic"),	PUCD_SCRIPT_COPTIC,
	cpaScriptNameCprt,	TQU("cprt"),	PUCD_SCRIPT_CYPRIOT,
	cpaScriptNameCuneiform,	TQU("cuneiform"),	PUCD_SCRIPT_CUNEIFORM,
	cpaScriptNameCypriot,	TQU("cypriot"),	PUCD_SCRIPT_CYPRIOT,
	cpaScriptNameCyrillic,	TQU("cyrillic"),	PUCD_SCRIPT_CYRILLIC,
	cpaScriptNameCyrl,	TQU("cyrl"),	PUCD_SCRIPT_CYRILLIC,
	cpaScriptNameDeseret,	TQU("deseret"),	PUCD_SCRIPT_DESERET,
	cpaScriptNameDeva,	TQU("deva"),	PUCD_SCRIPT_DEVANAGARI,
	cpaScriptNameDevanagari,	TQU("devanagari"),	PUCD_SCRIPT_DEVANAGARI,
	cpaScriptNameDsrt,	TQU("dsrt"),	PUCD_SCRIPT_DESERET,
	cpaScriptNameEgyp,	TQU("egyp"),	PUCD_SCRIPT_EGYPTIAN_HIEROGLYPHS,
	cpaScriptNameEgyptianhieroglyphs,	TQU("egyptianhieroglyphs"),	PUCD_SCRIPT_EGYPTIAN_HIEROGLYPHS,
	cpaScriptNameEthi,	TQU("ethi"),	PUCD_SCRIPT_ETHIOPIC,
	cpaScriptNameEthiopic,	TQU("ethiopic"),	PUCD_SCRIPT_ETHIOPIC,
	cpaScriptNameGeor,	TQU("geor"),	PUCD_SCRIPT_GEORGIAN,
	cpaScriptNameGeorgian,	TQU("georgian"),	PUCD_SCRIPT_GEORGIAN,
	cpaScriptNameGlag,	TQU("glag"),	PUCD_SCRIPT_GLAGOLITIC,
	cpaScriptNameGlagolitic,	TQU("glagolitic"),	PUCD_SCRIPT_GLAGOLITIC,
	cpaScriptNameGoth,	TQU("goth"),	PUCD_SCRIPT_GOTHIC,
	cpaScriptNameGothic,	TQU("gothic"),	PUCD_SCRIPT_GOTHIC,
	cpaScriptNameGreek,	TQU("greek"),	PUCD_SCRIPT_GREEK,
	cpaScriptNameGrek,	TQU("grek"),	PUCD_SCRIPT_GREEK,
	cpaScriptNameGujarati,	TQU("gujarati"),	PUCD_SCRIPT_GUJARATI,
	cpaScriptNameGujr,	TQU("gujr"),	PUCD_SCRIPT_GUJARATI,
	cpaScriptNameGurmukhi,	TQU("gurmukhi"),	PUCD_SCRIPT_GURMUKHI,
	cpaScriptNameGuru,	TQU("guru"),	PUCD_SCRIPT_GURMUKHI,
	cpaScriptNameHan,	TQU("han"),	PUCD_SCRIPT_HAN,
	cpaScriptNameHang,	TQU("hang"),	PUCD_SCRIPT_HANGUL,
	cpaScriptNameHangul,	TQU("hangul"),	PUCD_SCRIPT_HANGUL,
	cpaScriptNameHani,	TQU("hani"),	PUCD_SCRIPT_HAN,
	cpaScriptNameHano,	TQU("hano"),	PUCD_SCRIPT_HANUNOO,
	cpaScriptNameHanunoo,	TQU("hanunoo"),	PUCD_SCRIPT_HANUNOO,
	cpaScriptNameHebr,	TQU("hebr"),	PUCD_SCRIPT_HEBREW,
	cpaScriptNameHebrew,	TQU("hebrew"),	PUCD_SCRIPT_HEBREW,
	cpaScriptNameHira,	TQU("hira"),	PUCD_SCRIPT_HIRAGANA,
	cpaScriptNameHiragana,	TQU("hiragana"),	PUCD_SCRIPT_HIRAGANA,
	cpaScriptNameImperialaramaic,	TQU("imperialaramaic"),	PUCD_SCRIPT_IMPERIAL_ARAMAIC,
	cpaScriptNameInherited,	TQU("inherited"),	PUCD_SCRIPT_INHERITED,
	cpaScriptNameInscriptionalpahlavi,	TQU("inscriptionalpahlavi"),	PUCD_SCRIPT_INSCRIPTIONAL_PAHLAVI,
	cpaScriptNameInscriptionalparthian,	TQU("inscriptionalparthian"),	PUCD_SCRIPT_INSCRIPTIONAL_PARTHIAN,
	cpaScriptNameItal,	TQU("ital"),	PUCD_SCRIPT_OLD_ITALIC,
	cpaScriptNameJava,	TQU("java"),	PUCD_SCRIPT_JAVANESE,
	cpaScriptNameJavanese,	TQU("javanese"),	PUCD_SCRIPT_JAVANESE,
	cpaScriptNameKaithi,	TQU("kaithi"),	PUCD_SCRIPT_KAITHI,
	cpaScriptNameKali,	TQU("kali"),	PUCD_SCRIPT_KAYAH_LI,
	cpaScriptNameKana,	TQU("kana"),	PUCD_SCRIPT_KATAKANA,
	cpaScriptNameKannada,	TQU("kannada"),	PUCD_SCRIPT_KANNADA,
	cpaScriptNameKatakana,	TQU("katakana"),	PUCD_SCRIPT_KATAKANA,
	cpaScriptNameKayahli,	TQU("kayahli"),	PUCD_SCRIPT_KAYAH_LI,
	cpaScriptNameKhar,	TQU("khar"),	PUCD_SCRIPT_KHAROSHTHI,
	cpaScriptNameKharoshthi,	TQU("kharoshthi"),	PUCD_SCRIPT_KHAROSHTHI,
	cpaScriptNameKhmer,	TQU("khmer"),	PUCD_SCRIPT_KHMER,
	cpaScriptNameKhmr,	TQU("khmr"),	PUCD_SCRIPT_KHMER,
	cpaScriptNameKnda,	TQU("knda"),	PUCD_SCRIPT_KANNADA,
	cpaScriptNameKthi,	TQU("kthi"),	PUCD_SCRIPT_KAITHI,
	cpaScriptNameLana,	TQU("lana"),	PUCD_SCRIPT_TAI_THAM,
	cpaScriptNameLao,	TQU("lao"),	PUCD_SCRIPT_LAO,
	cpaScriptNameLaoo,	TQU("laoo"),	PUCD_SCRIPT_LAO,
	cpaScriptNameLatin,	TQU("latin"),	PUCD_SCRIPT_LATIN,
	cpaScriptNameLatn,	TQU("latn"),	PUCD_SCRIPT_LATIN,
	cpaScriptNameLepc,	TQU("lepc"),	PUCD_SCRIPT_LEPCHA,
	cpaScriptNameLepcha,	TQU("lepcha"),	PUCD_SCRIPT_LEPCHA,
	cpaScriptNameLimb,	TQU("limb"),	PUCD_SCRIPT_LIMBU,
	cpaScriptNameLimbu,	TQU("limbu"),	PUCD_SCRIPT_LIMBU,
	cpaScriptNameLinb,	TQU("linb"),	PUCD_SCRIPT_LINEAR_B,
	cpaScriptNameLinearb,	TQU("linearb"),	PUCD_SCRIPT_LINEAR_B,
	cpaScriptNameLisu,	TQU("lisu"),	PUCD_SCRIPT_LISU,
	cpaScriptNameLyci,	TQU("lyci"),	PUCD_SCRIPT_LYCIAN,
	cpaScriptNameLycian,	TQU("lycian"),	PUCD_SCRIPT_LYCIAN,
	cpaScriptNameLydi,	TQU("lydi"),	PUCD_SCRIPT_LYDIAN,
	cpaScriptNameLydian,	TQU("lydian"),	PUCD_SCRIPT_LYDIAN,
	cpaScriptNameMalayalam,	TQU("malayalam"),	PUCD_SCRIPT_MALAYALAM,
	cpaScriptNameMand,	TQU("mand"),	PUCD_SCRIPT_MANDAIC,
	cpaScriptNameMandaic,	TQU("mandaic"),	PUCD_SCRIPT_MANDAIC,
	cpaScriptNameMeeteimayek,	TQU("meeteimayek"),	PUCD_SCRIPT_MEETEI_MAYEK,
	cpaScriptNameMerc,	TQU("merc"),	PUCD_SCRIPT_MEROITIC_CURSIVE,
	cpaScriptNameMero,	TQU("mero"),	PUCD_SCRIPT_MEROITIC_HIEROGLYPHS,
	cpaScriptNameMeroiticcursive,	TQU("meroiticcursive"),	PUCD_SCRIPT_MEROITIC_CURSIVE,
	cpaScriptNameMeroitichieroglyphs,	TQU("meroitichieroglyphs"),	PUCD_SCRIPT_MEROITIC_HIEROGLYPHS,
	cpaScriptNameMiao,	TQU("miao"),	PUCD_SCRIPT_MIAO,
	cpaScriptNameMlym,	TQU("mlym"),	PUCD_SCRIPT_MALAYALAM,
	cpaScriptNameMong,	TQU("mong"),	PUCD_SCRIPT_MONGOLIAN,
	cpaScriptNameMongolian,	TQU("mongolian"),	PUCD_SCRIPT_MONGOLIAN,
	cpaScriptNameMtei,	TQU("mtei"),	PUCD_SCRIPT_MEETEI_MAYEK,
	cpaScriptNameMyanmar,	TQU("myanmar"),	PUCD_SCRIPT_MYANMAR,
	cpaScriptNameMymr,	TQU("mymr"),	PUCD_SCRIPT_MYANMAR,
	cpaScriptNameNewtailue,	TQU("newtailue"),	PUCD_SCRIPT_NEW_TAI_LUE,
	cpaScriptNameNko,	TQU("nko"),	PUCD_SCRIPT_NKO,
	cpaScriptNameNkoo,	TQU("nkoo"),	PUCD_SCRIPT_NKO,
	cpaScriptNameOgam,	TQU("ogam"),	PUCD_SCRIPT_OGHAM,
	cpaScriptNameOgham,	TQU("ogham"),	PUCD_SCRIPT_OGHAM,
	cpaScriptNameOlchiki,	TQU("olchiki"),	PUCD_SCRIPT_OL_CHIKI,
	cpaScriptNameOlck,	TQU("olck"),	PUCD_SCRIPT_OL_CHIKI,
	cpaScriptNameOlditalic,	TQU("olditalic"),	PUCD_SCRIPT_OLD_ITALIC,
	cpaScriptNameOldpersian,	TQU("oldpersian"),	PUCD_SCRIPT_OLD_PERSIAN,
	cpaScriptNameOldsoutharabian,	TQU("oldsoutharabian"),	PUCD_SCRIPT_OLD_SOUTH_ARABIAN,
	cpaScriptNameOldturkic,	TQU("oldturkic"),	PUCD_SCRIPT_OLD_TURKIC,
	cpaScriptNameOriya,	TQU("oriya"),	PUCD_SCRIPT_ORIYA,
	cpaScriptNameOrkh,	TQU("orkh"),	PUCD_SCRIPT_OLD_TURKIC,
	cpaScriptNameOrya,	TQU("orya"),	PUCD_SCRIPT_ORIYA,
	cpaScriptNameOsma,	TQU("osma"),	PUCD_SCRIPT_OSMANYA,
	cpaScriptNameOsmanya,	TQU("osmanya"),	PUCD_SCRIPT_OSMANYA,
	cpaScriptNamePhag,	TQU("phag"),	PUCD_SCRIPT_PHAGS_PA,
	cpaScriptNamePhagspa,	TQU("phagspa"),	PUCD_SCRIPT_PHAGS_PA,
	cpaScriptNamePhli,	TQU("phli"),	PUCD_SCRIPT_INSCRIPTIONAL_PAHLAVI,
	cpaScriptNamePhnx,	TQU("phnx"),	PUCD_SCRIPT_PHOENICIAN,
	cpaScriptNamePhoenician,	TQU("phoenician"),	PUCD_SCRIPT_PHOENICIAN,
	cpaScriptNamePlrd,	TQU("plrd"),	PUCD_SCRIPT_MIAO,
	cpaScriptNamePrti,	TQU("prti"),	PUCD_SCRIPT_INSCRIPTIONAL_PARTHIAN,
	cpaScriptNameQaac,	TQU("qaac"),	PUCD_SCRIPT_COPTIC,
	cpaScriptNameQaai,	TQU("qaai"),	PUCD_SCRIPT_INHERITED,
	cpaScriptNameRejang,	TQU("rejang"),	PUCD_SCRIPT_REJANG,
	cpaScriptNameRjng,	TQU("rjng"),	PUCD_SCRIPT_REJANG,
	cpaScriptNameRunic,	TQU("runic"),	PUCD_SCRIPT_RUNIC,
	cpaScriptNameRunr,	TQU("runr"),	PUCD_SCRIPT_RUNIC,
	cpaScriptNameSamaritan,	TQU("samaritan"),	PUCD_SCRIPT_SAMARITAN,
	cpaScriptNameSamr,	TQU("samr"),	PUCD_SCRIPT_SAMARITAN,
	cpaScriptNameSarb,	TQU("sarb"),	PUCD_SCRIPT_OLD_SOUTH_ARABIAN,
	cpaScriptNameSaur,	TQU("saur"),	PUCD_SCRIPT_SAURASHTRA,
	cpaScriptNameSaurashtra,	TQU("saurashtra"),	PUCD_SCRIPT_SAURASHTRA,
	cpaScriptNameSharada,	TQU("sharada"),	PUCD_SCRIPT_SHARADA,
	cpaScriptNameShavian,	TQU("shavian"),	PUCD_SCRIPT_SHAVIAN,
	cpaScriptNameShaw,	TQU("shaw"),	PUCD_SCRIPT_SHAVIAN,
	cpaScriptNameShrd,	TQU("shrd"),	PUCD_SCRIPT_SHARADA,
	cpaScriptNameSinh,	TQU("sinh"),	PUCD_SCRIPT_SINHALA,
	cpaScriptNameSinhala,	TQU("sinhala"),	PUCD_SCRIPT_SINHALA,
	cpaScriptNameSora,	TQU("sora"),	PUCD_SCRIPT_SORA_SOMPENG,
	cpaScriptNameSorasompeng,	TQU("sorasompeng"),	PUCD_SCRIPT_SORA_SOMPENG,
	cpaScriptNameSund,	TQU("sund"),	PUCD_SCRIPT_SUNDANESE,
	cpaScriptNameSundanese,	TQU("sundanese"),	PUCD_SCRIPT_SUNDANESE,
	cpaScriptNameSylo,	TQU("sylo"),	PUCD_SCRIPT_SYLOTI_NAGRI,
	cpaScriptNameSylotinagri,	TQU("sylotinagri"),	PUCD_SCRIPT_SYLOTI_NAGRI,
	cpaScriptNameSyrc,	TQU("syrc"),	PUCD_SCRIPT_SYRIAC,
	cpaScriptNameSyriac,	TQU("syriac"),	PUCD_SCRIPT_SYRIAC,
	cpaScriptNameTagalog,	TQU("tagalog"),	PUCD_SCRIPT_TAGALOG,
	cpaScriptNameTagb,	TQU("tagb"),	PUCD_SCRIPT_TAGBANWA,
	cpaScriptNameTagbanwa,	TQU("tagbanwa"),	PUCD_SCRIPT_TAGBANWA,
	cpaScriptNameTaile,	TQU("taile"),	PUCD_SCRIPT_TAI_LE,
	cpaScriptNameTaitham,	TQU("taitham"),	PUCD_SCRIPT_TAI_THAM,
	cpaScriptNameTaiviet,	TQU("taiviet"),	PUCD_SCRIPT_TAI_VIET,
	cpaScriptNameTakr,	TQU("takr"),	PUCD_SCRIPT_TAKRI,
	cpaScriptNameTakri,	TQU("takri"),	PUCD_SCRIPT_TAKRI,
	cpaScriptNameTale,	TQU("tale"),	PUCD_SCRIPT_TAI_LE,
	cpaScriptNameTalu,	TQU("talu"),	PUCD_SCRIPT_NEW_TAI_LUE,
	cpaScriptNameTamil,	TQU("tamil"),	PUCD_SCRIPT_TAMIL,
	cpaScriptNameTaml,	TQU("taml"),	PUCD_SCRIPT_TAMIL,
	cpaScriptNameTavt,	TQU("tavt"),	PUCD_SCRIPT_TAI_VIET,
	cpaScriptNameTelu,	TQU("telu"),	PUCD_SCRIPT_TELUGU,
	cpaScriptNameTelugu,	TQU("telugu"),	PUCD_SCRIPT_TELUGU,
	cpaScriptNameTfng,	TQU("tfng"),	PUCD_SCRIPT_TIFINAGH,
	cpaScriptNameTglg,	TQU("tglg"),	PUCD_SCRIPT_TAGALOG,
	cpaScriptNameThaa,	TQU("thaa"),	PUCD_SCRIPT_THAANA,
	cpaScriptNameThaana,	TQU("thaana"),	PUCD_SCRIPT_THAANA,
	cpaScriptNameThai,	TQU("thai"),	PUCD_SCRIPT_THAI,
	cpaScriptNameTibetan,	TQU("tibetan"),	PUCD_SCRIPT_TIBETAN,
	cpaScriptNameTibt,	TQU("tibt"),	PUCD_SCRIPT_TIBETAN,
	cpaScriptNameTifinagh,	TQU("tifinagh"),	PUCD_SCRIPT_TIFINAGH,
	cpaScriptNameUgar,	TQU("ugar"),	PUCD_SCRIPT_UGARITIC,
	cpaScriptNameUgaritic,	TQU("ugaritic"),	PUCD_SCRIPT_UGARITIC,
	cpaScriptNameUnknown,	TQU("unknown"),	PUCD_SCRIPT_UNKNOWN,
	cpaScriptNameVai,	TQU("vai"),	PUCD_SCRIPT_VAI,
	cpaScriptNameVaii,	TQU("vaii"),	PUCD_SCRIPT_VAI,
	cpaScriptNameXpeo,	TQU("xpeo"),	PUCD_SCRIPT_OLD_PERSIAN,
	cpaScriptNameXsux,	TQU("xsux"),	PUCD_SCRIPT_CUNEIFORM,
	cpaScriptNameYi,	TQU("yi"),	PUCD_SCRIPT_YI,
	cpaScriptNameYiii,	TQU("yiii"),	PUCD_SCRIPT_YI,
	cpaScriptNameZinh,	TQU("zinh"),	PUCD_SCRIPT_INHERITED,
	cpaScriptNameZyyy,	TQU("zyyy"),	PUCD_SCRIPT_COMMON,
	cpaScriptNameZzzz,	TQU("zzzz"),	PUCD_SCRIPT_UNKNOWN,
};
int	nScriptIdMap	= sizeof(siScriptIdMap) / sizeof(PSPropertyValueIdMap);

//======================================================================
//	コードポイントから属性 ID を求めるためのデータ
//======================================================================
PSCpIdMap	ScriptCpIdMap[]	=
{
	0x0000,	0x0040,	PUCD_SCRIPT_COMMON,
	0x0041,	0x005A,	PUCD_SCRIPT_LATIN,
	0x005B,	0x0060,	PUCD_SCRIPT_COMMON,
	0x0061,	0x007A,	PUCD_SCRIPT_LATIN,
	0x007B,	0x00A9,	PUCD_SCRIPT_COMMON,
	0x00AA,	0x00AA,	PUCD_SCRIPT_LATIN,
	0x00AB,	0x00B9,	PUCD_SCRIPT_COMMON,
	0x00BA,	0x00BA,	PUCD_SCRIPT_LATIN,
	0x00BB,	0x00BF,	PUCD_SCRIPT_COMMON,
	0x00C0,	0x00D6,	PUCD_SCRIPT_LATIN,
	0x00D7,	0x00D7,	PUCD_SCRIPT_COMMON,
	0x00D8,	0x00F6,	PUCD_SCRIPT_LATIN,
	0x00F7,	0x00F7,	PUCD_SCRIPT_COMMON,
	0x00F8,	0x02B8,	PUCD_SCRIPT_LATIN,
	0x02B9,	0x02DF,	PUCD_SCRIPT_COMMON,
	0x02E0,	0x02E4,	PUCD_SCRIPT_LATIN,
	0x02E5,	0x02E9,	PUCD_SCRIPT_COMMON,
	0x02EA,	0x02EB,	PUCD_SCRIPT_BOPOMOFO,
	0x02EC,	0x02FF,	PUCD_SCRIPT_COMMON,
	0x0300,	0x036F,	PUCD_SCRIPT_INHERITED,
	0x0370,	0x0373,	PUCD_SCRIPT_GREEK,
	0x0374,	0x0374,	PUCD_SCRIPT_COMMON,
	0x0375,	0x0377,	PUCD_SCRIPT_GREEK,
	0x037A,	0x037D,	PUCD_SCRIPT_GREEK,
	0x037E,	0x037E,	PUCD_SCRIPT_COMMON,
	0x0384,	0x0384,	PUCD_SCRIPT_GREEK,
	0x0385,	0x0385,	PUCD_SCRIPT_COMMON,
	0x0386,	0x0386,	PUCD_SCRIPT_GREEK,
	0x0387,	0x0387,	PUCD_SCRIPT_COMMON,
	0x0388,	0x038A,	PUCD_SCRIPT_GREEK,
	0x038C,	0x038C,	PUCD_SCRIPT_GREEK,
	0x038E,	0x03A1,	PUCD_SCRIPT_GREEK,
	0x03A3,	0x03E1,	PUCD_SCRIPT_GREEK,
	0x03E2,	0x03EF,	PUCD_SCRIPT_COPTIC,
	0x03F0,	0x03FF,	PUCD_SCRIPT_GREEK,
	0x0400,	0x0484,	PUCD_SCRIPT_CYRILLIC,
	0x0485,	0x0486,	PUCD_SCRIPT_INHERITED,
	0x0487,	0x0527,	PUCD_SCRIPT_CYRILLIC,
	0x0531,	0x0556,	PUCD_SCRIPT_ARMENIAN,
	0x0559,	0x055F,	PUCD_SCRIPT_ARMENIAN,
	0x0561,	0x0587,	PUCD_SCRIPT_ARMENIAN,
	0x0589,	0x0589,	PUCD_SCRIPT_COMMON,
	0x058A,	0x058A,	PUCD_SCRIPT_ARMENIAN,
	0x058F,	0x058F,	PUCD_SCRIPT_ARMENIAN,
	0x0591,	0x05C7,	PUCD_SCRIPT_HEBREW,
	0x05D0,	0x05EA,	PUCD_SCRIPT_HEBREW,
	0x05F0,	0x05F4,	PUCD_SCRIPT_HEBREW,
	0x0600,	0x0604,	PUCD_SCRIPT_ARABIC,
	0x0606,	0x060B,	PUCD_SCRIPT_ARABIC,
	0x060C,	0x060C,	PUCD_SCRIPT_COMMON,
	0x060D,	0x061A,	PUCD_SCRIPT_ARABIC,
	0x061B,	0x061B,	PUCD_SCRIPT_COMMON,
	0x061E,	0x061E,	PUCD_SCRIPT_ARABIC,
	0x061F,	0x061F,	PUCD_SCRIPT_COMMON,
	0x0620,	0x063F,	PUCD_SCRIPT_ARABIC,
	0x0640,	0x0640,	PUCD_SCRIPT_COMMON,
	0x0641,	0x064A,	PUCD_SCRIPT_ARABIC,
	0x064B,	0x0655,	PUCD_SCRIPT_INHERITED,
	0x0656,	0x065F,	PUCD_SCRIPT_ARABIC,
	0x0660,	0x0669,	PUCD_SCRIPT_COMMON,
	0x066A,	0x066F,	PUCD_SCRIPT_ARABIC,
	0x0670,	0x0670,	PUCD_SCRIPT_INHERITED,
	0x0671,	0x06DC,	PUCD_SCRIPT_ARABIC,
	0x06DD,	0x06DD,	PUCD_SCRIPT_COMMON,
	0x06DE,	0x06FF,	PUCD_SCRIPT_ARABIC,
	0x0700,	0x070D,	PUCD_SCRIPT_SYRIAC,
	0x070F,	0x074A,	PUCD_SCRIPT_SYRIAC,
	0x074D,	0x074F,	PUCD_SCRIPT_SYRIAC,
	0x0750,	0x077F,	PUCD_SCRIPT_ARABIC,
	0x0780,	0x07B1,	PUCD_SCRIPT_THAANA,
	0x07C0,	0x07FA,	PUCD_SCRIPT_NKO,
	0x0800,	0x082D,	PUCD_SCRIPT_SAMARITAN,
	0x0830,	0x083E,	PUCD_SCRIPT_SAMARITAN,
	0x0840,	0x085B,	PUCD_SCRIPT_MANDAIC,
	0x085E,	0x085E,	PUCD_SCRIPT_MANDAIC,
	0x08A0,	0x08A0,	PUCD_SCRIPT_ARABIC,
	0x08A2,	0x08AC,	PUCD_SCRIPT_ARABIC,
	0x08E4,	0x08FE,	PUCD_SCRIPT_ARABIC,
	0x0900,	0x0950,	PUCD_SCRIPT_DEVANAGARI,
	0x0951,	0x0952,	PUCD_SCRIPT_INHERITED,
	0x0953,	0x0963,	PUCD_SCRIPT_DEVANAGARI,
	0x0964,	0x0965,	PUCD_SCRIPT_COMMON,
	0x0966,	0x0977,	PUCD_SCRIPT_DEVANAGARI,
	0x0979,	0x097F,	PUCD_SCRIPT_DEVANAGARI,
	0x0981,	0x0983,	PUCD_SCRIPT_BENGALI,
	0x0985,	0x098C,	PUCD_SCRIPT_BENGALI,
	0x098F,	0x0990,	PUCD_SCRIPT_BENGALI,
	0x0993,	0x09A8,	PUCD_SCRIPT_BENGALI,
	0x09AA,	0x09B0,	PUCD_SCRIPT_BENGALI,
	0x09B2,	0x09B2,	PUCD_SCRIPT_BENGALI,
	0x09B6,	0x09B9,	PUCD_SCRIPT_BENGALI,
	0x09BC,	0x09C4,	PUCD_SCRIPT_BENGALI,
	0x09C7,	0x09C8,	PUCD_SCRIPT_BENGALI,
	0x09CB,	0x09CE,	PUCD_SCRIPT_BENGALI,
	0x09D7,	0x09D7,	PUCD_SCRIPT_BENGALI,
	0x09DC,	0x09DD,	PUCD_SCRIPT_BENGALI,
	0x09DF,	0x09E3,	PUCD_SCRIPT_BENGALI,
	0x09E6,	0x09FB,	PUCD_SCRIPT_BENGALI,
	0x0A01,	0x0A03,	PUCD_SCRIPT_GURMUKHI,
	0x0A05,	0x0A0A,	PUCD_SCRIPT_GURMUKHI,
	0x0A0F,	0x0A10,	PUCD_SCRIPT_GURMUKHI,
	0x0A13,	0x0A28,	PUCD_SCRIPT_GURMUKHI,
	0x0A2A,	0x0A30,	PUCD_SCRIPT_GURMUKHI,
	0x0A32,	0x0A33,	PUCD_SCRIPT_GURMUKHI,
	0x0A35,	0x0A36,	PUCD_SCRIPT_GURMUKHI,
	0x0A38,	0x0A39,	PUCD_SCRIPT_GURMUKHI,
	0x0A3C,	0x0A3C,	PUCD_SCRIPT_GURMUKHI,
	0x0A3E,	0x0A42,	PUCD_SCRIPT_GURMUKHI,
	0x0A47,	0x0A48,	PUCD_SCRIPT_GURMUKHI,
	0x0A4B,	0x0A4D,	PUCD_SCRIPT_GURMUKHI,
	0x0A51,	0x0A51,	PUCD_SCRIPT_GURMUKHI,
	0x0A59,	0x0A5C,	PUCD_SCRIPT_GURMUKHI,
	0x0A5E,	0x0A5E,	PUCD_SCRIPT_GURMUKHI,
	0x0A66,	0x0A75,	PUCD_SCRIPT_GURMUKHI,
	0x0A81,	0x0A83,	PUCD_SCRIPT_GUJARATI,
	0x0A85,	0x0A8D,	PUCD_SCRIPT_GUJARATI,
	0x0A8F,	0x0A91,	PUCD_SCRIPT_GUJARATI,
	0x0A93,	0x0AA8,	PUCD_SCRIPT_GUJARATI,
	0x0AAA,	0x0AB0,	PUCD_SCRIPT_GUJARATI,
	0x0AB2,	0x0AB3,	PUCD_SCRIPT_GUJARATI,
	0x0AB5,	0x0AB9,	PUCD_SCRIPT_GUJARATI,
	0x0ABC,	0x0AC5,	PUCD_SCRIPT_GUJARATI,
	0x0AC7,	0x0AC9,	PUCD_SCRIPT_GUJARATI,
	0x0ACB,	0x0ACD,	PUCD_SCRIPT_GUJARATI,
	0x0AD0,	0x0AD0,	PUCD_SCRIPT_GUJARATI,
	0x0AE0,	0x0AE3,	PUCD_SCRIPT_GUJARATI,
	0x0AE6,	0x0AF1,	PUCD_SCRIPT_GUJARATI,
	0x0B01,	0x0B03,	PUCD_SCRIPT_ORIYA,
	0x0B05,	0x0B0C,	PUCD_SCRIPT_ORIYA,
	0x0B0F,	0x0B10,	PUCD_SCRIPT_ORIYA,
	0x0B13,	0x0B28,	PUCD_SCRIPT_ORIYA,
	0x0B2A,	0x0B30,	PUCD_SCRIPT_ORIYA,
	0x0B32,	0x0B33,	PUCD_SCRIPT_ORIYA,
	0x0B35,	0x0B39,	PUCD_SCRIPT_ORIYA,
	0x0B3C,	0x0B44,	PUCD_SCRIPT_ORIYA,
	0x0B47,	0x0B48,	PUCD_SCRIPT_ORIYA,
	0x0B4B,	0x0B4D,	PUCD_SCRIPT_ORIYA,
	0x0B56,	0x0B57,	PUCD_SCRIPT_ORIYA,
	0x0B5C,	0x0B5D,	PUCD_SCRIPT_ORIYA,
	0x0B5F,	0x0B63,	PUCD_SCRIPT_ORIYA,
	0x0B66,	0x0B77,	PUCD_SCRIPT_ORIYA,
	0x0B82,	0x0B83,	PUCD_SCRIPT_TAMIL,
	0x0B85,	0x0B8A,	PUCD_SCRIPT_TAMIL,
	0x0B8E,	0x0B90,	PUCD_SCRIPT_TAMIL,
	0x0B92,	0x0B95,	PUCD_SCRIPT_TAMIL,
	0x0B99,	0x0B9A,	PUCD_SCRIPT_TAMIL,
	0x0B9C,	0x0B9C,	PUCD_SCRIPT_TAMIL,
	0x0B9E,	0x0B9F,	PUCD_SCRIPT_TAMIL,
	0x0BA3,	0x0BA4,	PUCD_SCRIPT_TAMIL,
	0x0BA8,	0x0BAA,	PUCD_SCRIPT_TAMIL,
	0x0BAE,	0x0BB9,	PUCD_SCRIPT_TAMIL,
	0x0BBE,	0x0BC2,	PUCD_SCRIPT_TAMIL,
	0x0BC6,	0x0BC8,	PUCD_SCRIPT_TAMIL,
	0x0BCA,	0x0BCD,	PUCD_SCRIPT_TAMIL,
	0x0BD0,	0x0BD0,	PUCD_SCRIPT_TAMIL,
	0x0BD7,	0x0BD7,	PUCD_SCRIPT_TAMIL,
	0x0BE6,	0x0BFA,	PUCD_SCRIPT_TAMIL,
	0x0C01,	0x0C03,	PUCD_SCRIPT_TELUGU,
	0x0C05,	0x0C0C,	PUCD_SCRIPT_TELUGU,
	0x0C0E,	0x0C10,	PUCD_SCRIPT_TELUGU,
	0x0C12,	0x0C28,	PUCD_SCRIPT_TELUGU,
	0x0C2A,	0x0C33,	PUCD_SCRIPT_TELUGU,
	0x0C35,	0x0C39,	PUCD_SCRIPT_TELUGU,
	0x0C3D,	0x0C44,	PUCD_SCRIPT_TELUGU,
	0x0C46,	0x0C48,	PUCD_SCRIPT_TELUGU,
	0x0C4A,	0x0C4D,	PUCD_SCRIPT_TELUGU,
	0x0C55,	0x0C56,	PUCD_SCRIPT_TELUGU,
	0x0C58,	0x0C59,	PUCD_SCRIPT_TELUGU,
	0x0C60,	0x0C63,	PUCD_SCRIPT_TELUGU,
	0x0C66,	0x0C6F,	PUCD_SCRIPT_TELUGU,
	0x0C78,	0x0C7F,	PUCD_SCRIPT_TELUGU,
	0x0C82,	0x0C83,	PUCD_SCRIPT_KANNADA,
	0x0C85,	0x0C8C,	PUCD_SCRIPT_KANNADA,
	0x0C8E,	0x0C90,	PUCD_SCRIPT_KANNADA,
	0x0C92,	0x0CA8,	PUCD_SCRIPT_KANNADA,
	0x0CAA,	0x0CB3,	PUCD_SCRIPT_KANNADA,
	0x0CB5,	0x0CB9,	PUCD_SCRIPT_KANNADA,
	0x0CBC,	0x0CC4,	PUCD_SCRIPT_KANNADA,
	0x0CC6,	0x0CC8,	PUCD_SCRIPT_KANNADA,
	0x0CCA,	0x0CCD,	PUCD_SCRIPT_KANNADA,
	0x0CD5,	0x0CD6,	PUCD_SCRIPT_KANNADA,
	0x0CDE,	0x0CDE,	PUCD_SCRIPT_KANNADA,
	0x0CE0,	0x0CE3,	PUCD_SCRIPT_KANNADA,
	0x0CE6,	0x0CEF,	PUCD_SCRIPT_KANNADA,
	0x0CF1,	0x0CF2,	PUCD_SCRIPT_KANNADA,
	0x0D02,	0x0D03,	PUCD_SCRIPT_MALAYALAM,
	0x0D05,	0x0D0C,	PUCD_SCRIPT_MALAYALAM,
	0x0D0E,	0x0D10,	PUCD_SCRIPT_MALAYALAM,
	0x0D12,	0x0D3A,	PUCD_SCRIPT_MALAYALAM,
	0x0D3D,	0x0D44,	PUCD_SCRIPT_MALAYALAM,
	0x0D46,	0x0D48,	PUCD_SCRIPT_MALAYALAM,
	0x0D4A,	0x0D4E,	PUCD_SCRIPT_MALAYALAM,
	0x0D57,	0x0D57,	PUCD_SCRIPT_MALAYALAM,
	0x0D60,	0x0D63,	PUCD_SCRIPT_MALAYALAM,
	0x0D66,	0x0D75,	PUCD_SCRIPT_MALAYALAM,
	0x0D79,	0x0D7F,	PUCD_SCRIPT_MALAYALAM,
	0x0D82,	0x0D83,	PUCD_SCRIPT_SINHALA,
	0x0D85,	0x0D96,	PUCD_SCRIPT_SINHALA,
	0x0D9A,	0x0DB1,	PUCD_SCRIPT_SINHALA,
	0x0DB3,	0x0DBB,	PUCD_SCRIPT_SINHALA,
	0x0DBD,	0x0DBD,	PUCD_SCRIPT_SINHALA,
	0x0DC0,	0x0DC6,	PUCD_SCRIPT_SINHALA,
	0x0DCA,	0x0DCA,	PUCD_SCRIPT_SINHALA,
	0x0DCF,	0x0DD4,	PUCD_SCRIPT_SINHALA,
	0x0DD6,	0x0DD6,	PUCD_SCRIPT_SINHALA,
	0x0DD8,	0x0DDF,	PUCD_SCRIPT_SINHALA,
	0x0DF2,	0x0DF4,	PUCD_SCRIPT_SINHALA,
	0x0E01,	0x0E3A,	PUCD_SCRIPT_THAI,
	0x0E3F,	0x0E3F,	PUCD_SCRIPT_COMMON,
	0x0E40,	0x0E5B,	PUCD_SCRIPT_THAI,
	0x0E81,	0x0E82,	PUCD_SCRIPT_LAO,
	0x0E84,	0x0E84,	PUCD_SCRIPT_LAO,
	0x0E87,	0x0E88,	PUCD_SCRIPT_LAO,
	0x0E8A,	0x0E8A,	PUCD_SCRIPT_LAO,
	0x0E8D,	0x0E8D,	PUCD_SCRIPT_LAO,
	0x0E94,	0x0E97,	PUCD_SCRIPT_LAO,
	0x0E99,	0x0E9F,	PUCD_SCRIPT_LAO,
	0x0EA1,	0x0EA3,	PUCD_SCRIPT_LAO,
	0x0EA5,	0x0EA5,	PUCD_SCRIPT_LAO,
	0x0EA7,	0x0EA7,	PUCD_SCRIPT_LAO,
	0x0EAA,	0x0EAB,	PUCD_SCRIPT_LAO,
	0x0EAD,	0x0EB9,	PUCD_SCRIPT_LAO,
	0x0EBB,	0x0EBD,	PUCD_SCRIPT_LAO,
	0x0EC0,	0x0EC4,	PUCD_SCRIPT_LAO,
	0x0EC6,	0x0EC6,	PUCD_SCRIPT_LAO,
	0x0EC8,	0x0ECD,	PUCD_SCRIPT_LAO,
	0x0ED0,	0x0ED9,	PUCD_SCRIPT_LAO,
	0x0EDC,	0x0EDF,	PUCD_SCRIPT_LAO,
	0x0F00,	0x0F47,	PUCD_SCRIPT_TIBETAN,
	0x0F49,	0x0F6C,	PUCD_SCRIPT_TIBETAN,
	0x0F71,	0x0F97,	PUCD_SCRIPT_TIBETAN,
	0x0F99,	0x0FBC,	PUCD_SCRIPT_TIBETAN,
	0x0FBE,	0x0FCC,	PUCD_SCRIPT_TIBETAN,
	0x0FCE,	0x0FD4,	PUCD_SCRIPT_TIBETAN,
	0x0FD5,	0x0FD8,	PUCD_SCRIPT_COMMON,
	0x0FD9,	0x0FDA,	PUCD_SCRIPT_TIBETAN,
	0x1000,	0x109F,	PUCD_SCRIPT_MYANMAR,
	0x10A0,	0x10C5,	PUCD_SCRIPT_GEORGIAN,
	0x10C7,	0x10C7,	PUCD_SCRIPT_GEORGIAN,
	0x10CD,	0x10CD,	PUCD_SCRIPT_GEORGIAN,
	0x10D0,	0x10FA,	PUCD_SCRIPT_GEORGIAN,
	0x10FB,	0x10FB,	PUCD_SCRIPT_COMMON,
	0x10FC,	0x10FF,	PUCD_SCRIPT_GEORGIAN,
	0x1100,	0x11FF,	PUCD_SCRIPT_HANGUL,
	0x1200,	0x1248,	PUCD_SCRIPT_ETHIOPIC,
	0x124A,	0x124D,	PUCD_SCRIPT_ETHIOPIC,
	0x1250,	0x1256,	PUCD_SCRIPT_ETHIOPIC,
	0x1258,	0x1258,	PUCD_SCRIPT_ETHIOPIC,
	0x125A,	0x125D,	PUCD_SCRIPT_ETHIOPIC,
	0x1260,	0x1288,	PUCD_SCRIPT_ETHIOPIC,
	0x128A,	0x128D,	PUCD_SCRIPT_ETHIOPIC,
	0x1290,	0x12B0,	PUCD_SCRIPT_ETHIOPIC,
	0x12B2,	0x12B5,	PUCD_SCRIPT_ETHIOPIC,
	0x12B8,	0x12BE,	PUCD_SCRIPT_ETHIOPIC,
	0x12C0,	0x12C0,	PUCD_SCRIPT_ETHIOPIC,
	0x12C2,	0x12C5,	PUCD_SCRIPT_ETHIOPIC,
	0x12C8,	0x12D6,	PUCD_SCRIPT_ETHIOPIC,
	0x12D8,	0x1310,	PUCD_SCRIPT_ETHIOPIC,
	0x1312,	0x1315,	PUCD_SCRIPT_ETHIOPIC,
	0x1318,	0x135A,	PUCD_SCRIPT_ETHIOPIC,
	0x135D,	0x137C,	PUCD_SCRIPT_ETHIOPIC,
	0x1380,	0x1399,	PUCD_SCRIPT_ETHIOPIC,
	0x13A0,	0x13F4,	PUCD_SCRIPT_CHEROKEE,
	0x1400,	0x167F,	PUCD_SCRIPT_CANADIAN_ABORIGINAL,
	0x1680,	0x169C,	PUCD_SCRIPT_OGHAM,
	0x16A0,	0x16EA,	PUCD_SCRIPT_RUNIC,
	0x16EB,	0x16ED,	PUCD_SCRIPT_COMMON,
	0x16EE,	0x16F0,	PUCD_SCRIPT_RUNIC,
	0x1700,	0x170C,	PUCD_SCRIPT_TAGALOG,
	0x170E,	0x1714,	PUCD_SCRIPT_TAGALOG,
	0x1720,	0x1734,	PUCD_SCRIPT_HANUNOO,
	0x1735,	0x1736,	PUCD_SCRIPT_COMMON,
	0x1740,	0x1753,	PUCD_SCRIPT_BUHID,
	0x1760,	0x176C,	PUCD_SCRIPT_TAGBANWA,
	0x176E,	0x1770,	PUCD_SCRIPT_TAGBANWA,
	0x1772,	0x1773,	PUCD_SCRIPT_TAGBANWA,
	0x1780,	0x17DD,	PUCD_SCRIPT_KHMER,
	0x17E0,	0x17E9,	PUCD_SCRIPT_KHMER,
	0x17F0,	0x17F9,	PUCD_SCRIPT_KHMER,
	0x1800,	0x1801,	PUCD_SCRIPT_MONGOLIAN,
	0x1802,	0x1803,	PUCD_SCRIPT_COMMON,
	0x1804,	0x1804,	PUCD_SCRIPT_MONGOLIAN,
	0x1805,	0x1805,	PUCD_SCRIPT_COMMON,
	0x1806,	0x180E,	PUCD_SCRIPT_MONGOLIAN,
	0x1810,	0x1819,	PUCD_SCRIPT_MONGOLIAN,
	0x1820,	0x1877,	PUCD_SCRIPT_MONGOLIAN,
	0x1880,	0x18AA,	PUCD_SCRIPT_MONGOLIAN,
	0x18B0,	0x18F5,	PUCD_SCRIPT_CANADIAN_ABORIGINAL,
	0x1900,	0x191C,	PUCD_SCRIPT_LIMBU,
	0x1920,	0x192B,	PUCD_SCRIPT_LIMBU,
	0x1930,	0x193B,	PUCD_SCRIPT_LIMBU,
	0x1940,	0x1940,	PUCD_SCRIPT_LIMBU,
	0x1944,	0x194F,	PUCD_SCRIPT_LIMBU,
	0x1950,	0x196D,	PUCD_SCRIPT_TAI_LE,
	0x1970,	0x1974,	PUCD_SCRIPT_TAI_LE,
	0x1980,	0x19AB,	PUCD_SCRIPT_NEW_TAI_LUE,
	0x19B0,	0x19C9,	PUCD_SCRIPT_NEW_TAI_LUE,
	0x19D0,	0x19DA,	PUCD_SCRIPT_NEW_TAI_LUE,
	0x19DE,	0x19DF,	PUCD_SCRIPT_NEW_TAI_LUE,
	0x19E0,	0x19FF,	PUCD_SCRIPT_KHMER,
	0x1A00,	0x1A1B,	PUCD_SCRIPT_BUGINESE,
	0x1A1E,	0x1A1F,	PUCD_SCRIPT_BUGINESE,
	0x1A20,	0x1A5E,	PUCD_SCRIPT_TAI_THAM,
	0x1A60,	0x1A7C,	PUCD_SCRIPT_TAI_THAM,
	0x1A7F,	0x1A89,	PUCD_SCRIPT_TAI_THAM,
	0x1A90,	0x1A99,	PUCD_SCRIPT_TAI_THAM,
	0x1AA0,	0x1AAD,	PUCD_SCRIPT_TAI_THAM,
	0x1B00,	0x1B4B,	PUCD_SCRIPT_BALINESE,
	0x1B50,	0x1B7C,	PUCD_SCRIPT_BALINESE,
	0x1B80,	0x1BBF,	PUCD_SCRIPT_SUNDANESE,
	0x1BC0,	0x1BF3,	PUCD_SCRIPT_BATAK,
	0x1BFC,	0x1BFF,	PUCD_SCRIPT_BATAK,
	0x1C00,	0x1C37,	PUCD_SCRIPT_LEPCHA,
	0x1C3B,	0x1C49,	PUCD_SCRIPT_LEPCHA,
	0x1C4D,	0x1C4F,	PUCD_SCRIPT_LEPCHA,
	0x1C50,	0x1C7F,	PUCD_SCRIPT_OL_CHIKI,
	0x1CC0,	0x1CC7,	PUCD_SCRIPT_SUNDANESE,
	0x1CD0,	0x1CD2,	PUCD_SCRIPT_INHERITED,
	0x1CD3,	0x1CD3,	PUCD_SCRIPT_COMMON,
	0x1CD4,	0x1CE0,	PUCD_SCRIPT_INHERITED,
	0x1CE1,	0x1CE1,	PUCD_SCRIPT_COMMON,
	0x1CE2,	0x1CE8,	PUCD_SCRIPT_INHERITED,
	0x1CE9,	0x1CEC,	PUCD_SCRIPT_COMMON,
	0x1CED,	0x1CED,	PUCD_SCRIPT_INHERITED,
	0x1CEE,	0x1CF3,	PUCD_SCRIPT_COMMON,
	0x1CF4,	0x1CF4,	PUCD_SCRIPT_INHERITED,
	0x1CF5,	0x1CF6,	PUCD_SCRIPT_COMMON,
	0x1D00,	0x1D25,	PUCD_SCRIPT_LATIN,
	0x1D26,	0x1D2A,	PUCD_SCRIPT_GREEK,
	0x1D2B,	0x1D2B,	PUCD_SCRIPT_CYRILLIC,
	0x1D2C,	0x1D5C,	PUCD_SCRIPT_LATIN,
	0x1D5D,	0x1D61,	PUCD_SCRIPT_GREEK,
	0x1D62,	0x1D65,	PUCD_SCRIPT_LATIN,
	0x1D66,	0x1D6A,	PUCD_SCRIPT_GREEK,
	0x1D6B,	0x1D77,	PUCD_SCRIPT_LATIN,
	0x1D78,	0x1D78,	PUCD_SCRIPT_CYRILLIC,
	0x1D79,	0x1DBE,	PUCD_SCRIPT_LATIN,
	0x1DBF,	0x1DBF,	PUCD_SCRIPT_GREEK,
	0x1DC0,	0x1DE6,	PUCD_SCRIPT_INHERITED,
	0x1DFC,	0x1DFF,	PUCD_SCRIPT_INHERITED,
	0x1E00,	0x1EFF,	PUCD_SCRIPT_LATIN,
	0x1F00,	0x1F15,	PUCD_SCRIPT_GREEK,
	0x1F18,	0x1F1D,	PUCD_SCRIPT_GREEK,
	0x1F20,	0x1F45,	PUCD_SCRIPT_GREEK,
	0x1F48,	0x1F4D,	PUCD_SCRIPT_GREEK,
	0x1F50,	0x1F57,	PUCD_SCRIPT_GREEK,
	0x1F59,	0x1F59,	PUCD_SCRIPT_GREEK,
	0x1F5B,	0x1F5B,	PUCD_SCRIPT_GREEK,
	0x1F5D,	0x1F5D,	PUCD_SCRIPT_GREEK,
	0x1F5F,	0x1F7D,	PUCD_SCRIPT_GREEK,
	0x1F80,	0x1FB4,	PUCD_SCRIPT_GREEK,
	0x1FB6,	0x1FC4,	PUCD_SCRIPT_GREEK,
	0x1FC6,	0x1FD3,	PUCD_SCRIPT_GREEK,
	0x1FD6,	0x1FDB,	PUCD_SCRIPT_GREEK,
	0x1FDD,	0x1FEF,	PUCD_SCRIPT_GREEK,
	0x1FF2,	0x1FF4,	PUCD_SCRIPT_GREEK,
	0x1FF6,	0x1FFE,	PUCD_SCRIPT_GREEK,
	0x2000,	0x200B,	PUCD_SCRIPT_COMMON,
	0x200C,	0x200D,	PUCD_SCRIPT_INHERITED,
	0x200E,	0x2064,	PUCD_SCRIPT_COMMON,
	0x206A,	0x2070,	PUCD_SCRIPT_COMMON,
	0x2071,	0x2071,	PUCD_SCRIPT_LATIN,
	0x2074,	0x207E,	PUCD_SCRIPT_COMMON,
	0x207F,	0x207F,	PUCD_SCRIPT_LATIN,
	0x2080,	0x208E,	PUCD_SCRIPT_COMMON,
	0x2090,	0x209C,	PUCD_SCRIPT_LATIN,
	0x20A0,	0x20BA,	PUCD_SCRIPT_COMMON,
	0x20D0,	0x20F0,	PUCD_SCRIPT_INHERITED,
	0x2100,	0x2125,	PUCD_SCRIPT_COMMON,
	0x2126,	0x2126,	PUCD_SCRIPT_GREEK,
	0x2127,	0x2129,	PUCD_SCRIPT_COMMON,
	0x212A,	0x212B,	PUCD_SCRIPT_LATIN,
	0x212C,	0x2131,	PUCD_SCRIPT_COMMON,
	0x2132,	0x2132,	PUCD_SCRIPT_LATIN,
	0x2133,	0x214D,	PUCD_SCRIPT_COMMON,
	0x214E,	0x214E,	PUCD_SCRIPT_LATIN,
	0x214F,	0x215F,	PUCD_SCRIPT_COMMON,
	0x2160,	0x2188,	PUCD_SCRIPT_LATIN,
	0x2189,	0x2189,	PUCD_SCRIPT_COMMON,
	0x2190,	0x23F3,	PUCD_SCRIPT_COMMON,
	0x2400,	0x2426,	PUCD_SCRIPT_COMMON,
	0x2440,	0x244A,	PUCD_SCRIPT_COMMON,
	0x2460,	0x26FF,	PUCD_SCRIPT_COMMON,
	0x2701,	0x27FF,	PUCD_SCRIPT_COMMON,
	0x2800,	0x28FF,	PUCD_SCRIPT_BRAILLE,
	0x2900,	0x2B4C,	PUCD_SCRIPT_COMMON,
	0x2B50,	0x2B59,	PUCD_SCRIPT_COMMON,
	0x2C00,	0x2C2E,	PUCD_SCRIPT_GLAGOLITIC,
	0x2C30,	0x2C5E,	PUCD_SCRIPT_GLAGOLITIC,
	0x2C60,	0x2C7F,	PUCD_SCRIPT_LATIN,
	0x2C80,	0x2CF3,	PUCD_SCRIPT_COPTIC,
	0x2CF9,	0x2CFF,	PUCD_SCRIPT_COPTIC,
	0x2D00,	0x2D25,	PUCD_SCRIPT_GEORGIAN,
	0x2D27,	0x2D27,	PUCD_SCRIPT_GEORGIAN,
	0x2D2D,	0x2D2D,	PUCD_SCRIPT_GEORGIAN,
	0x2D30,	0x2D67,	PUCD_SCRIPT_TIFINAGH,
	0x2D6F,	0x2D70,	PUCD_SCRIPT_TIFINAGH,
	0x2D7F,	0x2D7F,	PUCD_SCRIPT_TIFINAGH,
	0x2D80,	0x2D96,	PUCD_SCRIPT_ETHIOPIC,
	0x2DA0,	0x2DA6,	PUCD_SCRIPT_ETHIOPIC,
	0x2DA8,	0x2DAE,	PUCD_SCRIPT_ETHIOPIC,
	0x2DB0,	0x2DB6,	PUCD_SCRIPT_ETHIOPIC,
	0x2DB8,	0x2DBE,	PUCD_SCRIPT_ETHIOPIC,
	0x2DC0,	0x2DC6,	PUCD_SCRIPT_ETHIOPIC,
	0x2DC8,	0x2DCE,	PUCD_SCRIPT_ETHIOPIC,
	0x2DD0,	0x2DD6,	PUCD_SCRIPT_ETHIOPIC,
	0x2DD8,	0x2DDE,	PUCD_SCRIPT_ETHIOPIC,
	0x2DE0,	0x2DFF,	PUCD_SCRIPT_CYRILLIC,
	0x2E00,	0x2E3B,	PUCD_SCRIPT_COMMON,
	0x2E80,	0x2E99,	PUCD_SCRIPT_HAN,
	0x2E9B,	0x2EF3,	PUCD_SCRIPT_HAN,
	0x2F00,	0x2FD5,	PUCD_SCRIPT_HAN,
	0x2FF0,	0x2FFB,	PUCD_SCRIPT_COMMON,
	0x3000,	0x3004,	PUCD_SCRIPT_COMMON,
	0x3005,	0x3005,	PUCD_SCRIPT_HAN,
	0x3006,	0x3006,	PUCD_SCRIPT_COMMON,
	0x3007,	0x3007,	PUCD_SCRIPT_HAN,
	0x3008,	0x3020,	PUCD_SCRIPT_COMMON,
	0x3021,	0x3029,	PUCD_SCRIPT_HAN,
	0x302A,	0x302D,	PUCD_SCRIPT_INHERITED,
	0x302E,	0x302F,	PUCD_SCRIPT_HANGUL,
	0x3030,	0x3037,	PUCD_SCRIPT_COMMON,
	0x3038,	0x303B,	PUCD_SCRIPT_HAN,
	0x303C,	0x303F,	PUCD_SCRIPT_COMMON,
	0x3041,	0x3096,	PUCD_SCRIPT_HIRAGANA,
	0x3099,	0x309A,	PUCD_SCRIPT_INHERITED,
	0x309B,	0x309C,	PUCD_SCRIPT_COMMON,
	0x309D,	0x309F,	PUCD_SCRIPT_HIRAGANA,
	0x30A0,	0x30A0,	PUCD_SCRIPT_COMMON,
	0x30A1,	0x30FA,	PUCD_SCRIPT_KATAKANA,
	0x30FB,	0x30FC,	PUCD_SCRIPT_COMMON,
	0x30FD,	0x30FF,	PUCD_SCRIPT_KATAKANA,
	0x3105,	0x312D,	PUCD_SCRIPT_BOPOMOFO,
	0x3131,	0x318E,	PUCD_SCRIPT_HANGUL,
	0x3190,	0x319F,	PUCD_SCRIPT_COMMON,
	0x31A0,	0x31BA,	PUCD_SCRIPT_BOPOMOFO,
	0x31C0,	0x31E3,	PUCD_SCRIPT_COMMON,
	0x31F0,	0x31FF,	PUCD_SCRIPT_KATAKANA,
	0x3200,	0x321E,	PUCD_SCRIPT_HANGUL,
	0x3220,	0x325F,	PUCD_SCRIPT_COMMON,
	0x3260,	0x327E,	PUCD_SCRIPT_HANGUL,
	0x327F,	0x32CF,	PUCD_SCRIPT_COMMON,
	0x32D0,	0x32FE,	PUCD_SCRIPT_KATAKANA,
	0x3300,	0x3357,	PUCD_SCRIPT_KATAKANA,
	0x3358,	0x33FF,	PUCD_SCRIPT_COMMON,
	0x3400,	0x4DB5,	PUCD_SCRIPT_HAN,
	0x4DC0,	0x4DFF,	PUCD_SCRIPT_COMMON,
	0x4E00,	0x9FCC,	PUCD_SCRIPT_HAN,
	0xA000,	0xA48C,	PUCD_SCRIPT_YI,
	0xA490,	0xA4C6,	PUCD_SCRIPT_YI,
	0xA4D0,	0xA4FF,	PUCD_SCRIPT_LISU,
	0xA500,	0xA62B,	PUCD_SCRIPT_VAI,
	0xA640,	0xA697,	PUCD_SCRIPT_CYRILLIC,
	0xA69F,	0xA69F,	PUCD_SCRIPT_CYRILLIC,
	0xA6A0,	0xA6F7,	PUCD_SCRIPT_BAMUM,
	0xA700,	0xA721,	PUCD_SCRIPT_COMMON,
	0xA722,	0xA787,	PUCD_SCRIPT_LATIN,
	0xA788,	0xA78A,	PUCD_SCRIPT_COMMON,
	0xA78B,	0xA78E,	PUCD_SCRIPT_LATIN,
	0xA790,	0xA793,	PUCD_SCRIPT_LATIN,
	0xA7A0,	0xA7AA,	PUCD_SCRIPT_LATIN,
	0xA7F8,	0xA7FF,	PUCD_SCRIPT_LATIN,
	0xA800,	0xA82B,	PUCD_SCRIPT_SYLOTI_NAGRI,
	0xA830,	0xA839,	PUCD_SCRIPT_COMMON,
	0xA840,	0xA877,	PUCD_SCRIPT_PHAGS_PA,
	0xA880,	0xA8C4,	PUCD_SCRIPT_SAURASHTRA,
	0xA8CE,	0xA8D9,	PUCD_SCRIPT_SAURASHTRA,
	0xA8E0,	0xA8FB,	PUCD_SCRIPT_DEVANAGARI,
	0xA900,	0xA92F,	PUCD_SCRIPT_KAYAH_LI,
	0xA930,	0xA953,	PUCD_SCRIPT_REJANG,
	0xA95F,	0xA95F,	PUCD_SCRIPT_REJANG,
	0xA960,	0xA97C,	PUCD_SCRIPT_HANGUL,
	0xA980,	0xA9CD,	PUCD_SCRIPT_JAVANESE,
	0xA9CF,	0xA9D9,	PUCD_SCRIPT_JAVANESE,
	0xA9DE,	0xA9DF,	PUCD_SCRIPT_JAVANESE,
	0xAA00,	0xAA36,	PUCD_SCRIPT_CHAM,
	0xAA40,	0xAA4D,	PUCD_SCRIPT_CHAM,
	0xAA50,	0xAA59,	PUCD_SCRIPT_CHAM,
	0xAA5C,	0xAA5F,	PUCD_SCRIPT_CHAM,
	0xAA60,	0xAA7B,	PUCD_SCRIPT_MYANMAR,
	0xAA80,	0xAAC2,	PUCD_SCRIPT_TAI_VIET,
	0xAADB,	0xAADF,	PUCD_SCRIPT_TAI_VIET,
	0xAAE0,	0xAAF6,	PUCD_SCRIPT_MEETEI_MAYEK,
	0xAB01,	0xAB06,	PUCD_SCRIPT_ETHIOPIC,
	0xAB09,	0xAB0E,	PUCD_SCRIPT_ETHIOPIC,
	0xAB11,	0xAB16,	PUCD_SCRIPT_ETHIOPIC,
	0xAB20,	0xAB26,	PUCD_SCRIPT_ETHIOPIC,
	0xAB28,	0xAB2E,	PUCD_SCRIPT_ETHIOPIC,
	0xABC0,	0xABED,	PUCD_SCRIPT_MEETEI_MAYEK,
	0xABF0,	0xABF9,	PUCD_SCRIPT_MEETEI_MAYEK,
	0xAC00,	0xD7A3,	PUCD_SCRIPT_HANGUL,
	0xD7B0,	0xD7C6,	PUCD_SCRIPT_HANGUL,
	0xD7CB,	0xD7FB,	PUCD_SCRIPT_HANGUL,
	0xF900,	0xFA6D,	PUCD_SCRIPT_HAN,
	0xFA70,	0xFAD9,	PUCD_SCRIPT_HAN,
	0xFB00,	0xFB06,	PUCD_SCRIPT_LATIN,
	0xFB13,	0xFB17,	PUCD_SCRIPT_ARMENIAN,
	0xFB1D,	0xFB36,	PUCD_SCRIPT_HEBREW,
	0xFB38,	0xFB3C,	PUCD_SCRIPT_HEBREW,
	0xFB3E,	0xFB3E,	PUCD_SCRIPT_HEBREW,
	0xFB40,	0xFB41,	PUCD_SCRIPT_HEBREW,
	0xFB43,	0xFB44,	PUCD_SCRIPT_HEBREW,
	0xFB46,	0xFB4F,	PUCD_SCRIPT_HEBREW,
	0xFB50,	0xFBC1,	PUCD_SCRIPT_ARABIC,
	0xFBD3,	0xFD3D,	PUCD_SCRIPT_ARABIC,
	0xFD3E,	0xFD3F,	PUCD_SCRIPT_COMMON,
	0xFD50,	0xFD8F,	PUCD_SCRIPT_ARABIC,
	0xFD92,	0xFDC7,	PUCD_SCRIPT_ARABIC,
	0xFDF0,	0xFDFC,	PUCD_SCRIPT_ARABIC,
	0xFDFD,	0xFDFD,	PUCD_SCRIPT_COMMON,
	0xFE00,	0xFE0F,	PUCD_SCRIPT_INHERITED,
	0xFE10,	0xFE19,	PUCD_SCRIPT_COMMON,
	0xFE20,	0xFE26,	PUCD_SCRIPT_INHERITED,
	0xFE30,	0xFE52,	PUCD_SCRIPT_COMMON,
	0xFE54,	0xFE66,	PUCD_SCRIPT_COMMON,
	0xFE68,	0xFE6B,	PUCD_SCRIPT_COMMON,
	0xFE70,	0xFE74,	PUCD_SCRIPT_ARABIC,
	0xFE76,	0xFEFC,	PUCD_SCRIPT_ARABIC,
	0xFEFF,	0xFEFF,	PUCD_SCRIPT_COMMON,
	0xFF01,	0xFF20,	PUCD_SCRIPT_COMMON,
	0xFF21,	0xFF3A,	PUCD_SCRIPT_LATIN,
	0xFF3B,	0xFF40,	PUCD_SCRIPT_COMMON,
	0xFF41,	0xFF5A,	PUCD_SCRIPT_LATIN,
	0xFF5B,	0xFF65,	PUCD_SCRIPT_COMMON,
	0xFF66,	0xFF6F,	PUCD_SCRIPT_KATAKANA,
	0xFF70,	0xFF70,	PUCD_SCRIPT_COMMON,
	0xFF71,	0xFF9D,	PUCD_SCRIPT_KATAKANA,
	0xFF9E,	0xFF9F,	PUCD_SCRIPT_COMMON,
	0xFFA0,	0xFFBE,	PUCD_SCRIPT_HANGUL,
	0xFFC2,	0xFFC7,	PUCD_SCRIPT_HANGUL,
	0xFFCA,	0xFFCF,	PUCD_SCRIPT_HANGUL,
	0xFFD2,	0xFFD7,	PUCD_SCRIPT_HANGUL,
	0xFFDA,	0xFFDC,	PUCD_SCRIPT_HANGUL,
	0xFFE0,	0xFFE6,	PUCD_SCRIPT_COMMON,
	0xFFE8,	0xFFEE,	PUCD_SCRIPT_COMMON,
	0xFFF9,	0xFFFD,	PUCD_SCRIPT_COMMON,
	0x10000,	0x1000B,	PUCD_SCRIPT_LINEAR_B,
	0x1000D,	0x10026,	PUCD_SCRIPT_LINEAR_B,
	0x10028,	0x1003A,	PUCD_SCRIPT_LINEAR_B,
	0x1003C,	0x1003D,	PUCD_SCRIPT_LINEAR_B,
	0x1003F,	0x1004D,	PUCD_SCRIPT_LINEAR_B,
	0x10050,	0x1005D,	PUCD_SCRIPT_LINEAR_B,
	0x10080,	0x100FA,	PUCD_SCRIPT_LINEAR_B,
	0x10100,	0x10102,	PUCD_SCRIPT_COMMON,
	0x10107,	0x10133,	PUCD_SCRIPT_COMMON,
	0x10137,	0x1013F,	PUCD_SCRIPT_COMMON,
	0x10140,	0x1018A,	PUCD_SCRIPT_GREEK,
	0x10190,	0x1019B,	PUCD_SCRIPT_COMMON,
	0x101D0,	0x101FC,	PUCD_SCRIPT_COMMON,
	0x101FD,	0x101FD,	PUCD_SCRIPT_INHERITED,
	0x10280,	0x1029C,	PUCD_SCRIPT_LYCIAN,
	0x102A0,	0x102D0,	PUCD_SCRIPT_CARIAN,
	0x10300,	0x1031E,	PUCD_SCRIPT_OLD_ITALIC,
	0x10320,	0x10323,	PUCD_SCRIPT_OLD_ITALIC,
	0x10330,	0x1034A,	PUCD_SCRIPT_GOTHIC,
	0x10380,	0x1039D,	PUCD_SCRIPT_UGARITIC,
	0x1039F,	0x1039F,	PUCD_SCRIPT_UGARITIC,
	0x103A0,	0x103C3,	PUCD_SCRIPT_OLD_PERSIAN,
	0x103C8,	0x103D5,	PUCD_SCRIPT_OLD_PERSIAN,
	0x10400,	0x1044F,	PUCD_SCRIPT_DESERET,
	0x10450,	0x1047F,	PUCD_SCRIPT_SHAVIAN,
	0x10480,	0x1049D,	PUCD_SCRIPT_OSMANYA,
	0x104A0,	0x104A9,	PUCD_SCRIPT_OSMANYA,
	0x10800,	0x10805,	PUCD_SCRIPT_CYPRIOT,
	0x10808,	0x10808,	PUCD_SCRIPT_CYPRIOT,
	0x1080A,	0x10835,	PUCD_SCRIPT_CYPRIOT,
	0x10837,	0x10838,	PUCD_SCRIPT_CYPRIOT,
	0x1083C,	0x1083C,	PUCD_SCRIPT_CYPRIOT,
	0x1083F,	0x1083F,	PUCD_SCRIPT_CYPRIOT,
	0x10840,	0x10855,	PUCD_SCRIPT_IMPERIAL_ARAMAIC,
	0x10857,	0x1085F,	PUCD_SCRIPT_IMPERIAL_ARAMAIC,
	0x10900,	0x1091B,	PUCD_SCRIPT_PHOENICIAN,
	0x1091F,	0x1091F,	PUCD_SCRIPT_PHOENICIAN,
	0x10920,	0x10939,	PUCD_SCRIPT_LYDIAN,
	0x1093F,	0x1093F,	PUCD_SCRIPT_LYDIAN,
	0x10980,	0x1099F,	PUCD_SCRIPT_MEROITIC_HIEROGLYPHS,
	0x109A0,	0x109B7,	PUCD_SCRIPT_MEROITIC_CURSIVE,
	0x109BE,	0x109BF,	PUCD_SCRIPT_MEROITIC_CURSIVE,
	0x10A00,	0x10A03,	PUCD_SCRIPT_KHAROSHTHI,
	0x10A05,	0x10A06,	PUCD_SCRIPT_KHAROSHTHI,
	0x10A0C,	0x10A13,	PUCD_SCRIPT_KHAROSHTHI,
	0x10A15,	0x10A17,	PUCD_SCRIPT_KHAROSHTHI,
	0x10A19,	0x10A33,	PUCD_SCRIPT_KHAROSHTHI,
	0x10A38,	0x10A3A,	PUCD_SCRIPT_KHAROSHTHI,
	0x10A3F,	0x10A47,	PUCD_SCRIPT_KHAROSHTHI,
	0x10A50,	0x10A58,	PUCD_SCRIPT_KHAROSHTHI,
	0x10A60,	0x10A7F,	PUCD_SCRIPT_OLD_SOUTH_ARABIAN,
	0x10B00,	0x10B35,	PUCD_SCRIPT_AVESTAN,
	0x10B39,	0x10B3F,	PUCD_SCRIPT_AVESTAN,
	0x10B40,	0x10B55,	PUCD_SCRIPT_INSCRIPTIONAL_PARTHIAN,
	0x10B58,	0x10B5F,	PUCD_SCRIPT_INSCRIPTIONAL_PARTHIAN,
	0x10B60,	0x10B72,	PUCD_SCRIPT_INSCRIPTIONAL_PAHLAVI,
	0x10B78,	0x10B7F,	PUCD_SCRIPT_INSCRIPTIONAL_PAHLAVI,
	0x10C00,	0x10C48,	PUCD_SCRIPT_OLD_TURKIC,
	0x10E60,	0x10E7E,	PUCD_SCRIPT_ARABIC,
	0x11000,	0x1104D,	PUCD_SCRIPT_BRAHMI,
	0x11052,	0x1106F,	PUCD_SCRIPT_BRAHMI,
	0x11080,	0x110C1,	PUCD_SCRIPT_KAITHI,
	0x110D0,	0x110E8,	PUCD_SCRIPT_SORA_SOMPENG,
	0x110F0,	0x110F9,	PUCD_SCRIPT_SORA_SOMPENG,
	0x11100,	0x11134,	PUCD_SCRIPT_CHAKMA,
	0x11136,	0x11143,	PUCD_SCRIPT_CHAKMA,
	0x11180,	0x111C8,	PUCD_SCRIPT_SHARADA,
	0x111D0,	0x111D9,	PUCD_SCRIPT_SHARADA,
	0x11680,	0x116B7,	PUCD_SCRIPT_TAKRI,
	0x116C0,	0x116C9,	PUCD_SCRIPT_TAKRI,
	0x12000,	0x1236E,	PUCD_SCRIPT_CUNEIFORM,
	0x12400,	0x12462,	PUCD_SCRIPT_CUNEIFORM,
	0x12470,	0x12473,	PUCD_SCRIPT_CUNEIFORM,
	0x13000,	0x1342E,	PUCD_SCRIPT_EGYPTIAN_HIEROGLYPHS,
	0x16800,	0x16A38,	PUCD_SCRIPT_BAMUM,
	0x16F00,	0x16F44,	PUCD_SCRIPT_MIAO,
	0x16F50,	0x16F7E,	PUCD_SCRIPT_MIAO,
	0x16F8F,	0x16F9F,	PUCD_SCRIPT_MIAO,
	0x1B000,	0x1B000,	PUCD_SCRIPT_KATAKANA,
	0x1B001,	0x1B001,	PUCD_SCRIPT_HIRAGANA,
	0x1D000,	0x1D0F5,	PUCD_SCRIPT_COMMON,
	0x1D100,	0x1D126,	PUCD_SCRIPT_COMMON,
	0x1D129,	0x1D166,	PUCD_SCRIPT_COMMON,
	0x1D167,	0x1D169,	PUCD_SCRIPT_INHERITED,
	0x1D16A,	0x1D17A,	PUCD_SCRIPT_COMMON,
	0x1D17B,	0x1D182,	PUCD_SCRIPT_INHERITED,
	0x1D183,	0x1D184,	PUCD_SCRIPT_COMMON,
	0x1D185,	0x1D18B,	PUCD_SCRIPT_INHERITED,
	0x1D18C,	0x1D1A9,	PUCD_SCRIPT_COMMON,
	0x1D1AA,	0x1D1AD,	PUCD_SCRIPT_INHERITED,
	0x1D1AE,	0x1D1DD,	PUCD_SCRIPT_COMMON,
	0x1D200,	0x1D245,	PUCD_SCRIPT_GREEK,
	0x1D300,	0x1D356,	PUCD_SCRIPT_COMMON,
	0x1D360,	0x1D371,	PUCD_SCRIPT_COMMON,
	0x1D400,	0x1D454,	PUCD_SCRIPT_COMMON,
	0x1D456,	0x1D49C,	PUCD_SCRIPT_COMMON,
	0x1D49E,	0x1D49F,	PUCD_SCRIPT_COMMON,
	0x1D4A2,	0x1D4A2,	PUCD_SCRIPT_COMMON,
	0x1D4A5,	0x1D4A6,	PUCD_SCRIPT_COMMON,
	0x1D4A9,	0x1D4AC,	PUCD_SCRIPT_COMMON,
	0x1D4AE,	0x1D4B9,	PUCD_SCRIPT_COMMON,
	0x1D4BB,	0x1D4BB,	PUCD_SCRIPT_COMMON,
	0x1D4BD,	0x1D4C3,	PUCD_SCRIPT_COMMON,
	0x1D4C5,	0x1D505,	PUCD_SCRIPT_COMMON,
	0x1D507,	0x1D50A,	PUCD_SCRIPT_COMMON,
	0x1D50D,	0x1D514,	PUCD_SCRIPT_COMMON,
	0x1D516,	0x1D51C,	PUCD_SCRIPT_COMMON,
	0x1D51E,	0x1D539,	PUCD_SCRIPT_COMMON,
	0x1D53B,	0x1D53E,	PUCD_SCRIPT_COMMON,
	0x1D540,	0x1D544,	PUCD_SCRIPT_COMMON,
	0x1D546,	0x1D546,	PUCD_SCRIPT_COMMON,
	0x1D54A,	0x1D550,	PUCD_SCRIPT_COMMON,
	0x1D552,	0x1D6A5,	PUCD_SCRIPT_COMMON,
	0x1D6A8,	0x1D7CB,	PUCD_SCRIPT_COMMON,
	0x1D7CE,	0x1D7FF,	PUCD_SCRIPT_COMMON,
	0x1EE00,	0x1EE03,	PUCD_SCRIPT_ARABIC,
	0x1EE05,	0x1EE1F,	PUCD_SCRIPT_ARABIC,
	0x1EE21,	0x1EE22,	PUCD_SCRIPT_ARABIC,
	0x1EE24,	0x1EE24,	PUCD_SCRIPT_ARABIC,
	0x1EE27,	0x1EE27,	PUCD_SCRIPT_ARABIC,
	0x1EE29,	0x1EE32,	PUCD_SCRIPT_ARABIC,
	0x1EE34,	0x1EE37,	PUCD_SCRIPT_ARABIC,
	0x1EE39,	0x1EE39,	PUCD_SCRIPT_ARABIC,
	0x1EE3B,	0x1EE3B,	PUCD_SCRIPT_ARABIC,
	0x1EE42,	0x1EE42,	PUCD_SCRIPT_ARABIC,
	0x1EE47,	0x1EE47,	PUCD_SCRIPT_ARABIC,
	0x1EE49,	0x1EE49,	PUCD_SCRIPT_ARABIC,
	0x1EE4B,	0x1EE4B,	PUCD_SCRIPT_ARABIC,
	0x1EE4D,	0x1EE4F,	PUCD_SCRIPT_ARABIC,
	0x1EE51,	0x1EE52,	PUCD_SCRIPT_ARABIC,
	0x1EE54,	0x1EE54,	PUCD_SCRIPT_ARABIC,
	0x1EE57,	0x1EE57,	PUCD_SCRIPT_ARABIC,
	0x1EE59,	0x1EE59,	PUCD_SCRIPT_ARABIC,
	0x1EE5B,	0x1EE5B,	PUCD_SCRIPT_ARABIC,
	0x1EE5D,	0x1EE5D,	PUCD_SCRIPT_ARABIC,
	0x1EE5F,	0x1EE5F,	PUCD_SCRIPT_ARABIC,
	0x1EE61,	0x1EE62,	PUCD_SCRIPT_ARABIC,
	0x1EE64,	0x1EE64,	PUCD_SCRIPT_ARABIC,
	0x1EE67,	0x1EE6A,	PUCD_SCRIPT_ARABIC,
	0x1EE6C,	0x1EE72,	PUCD_SCRIPT_ARABIC,
	0x1EE74,	0x1EE77,	PUCD_SCRIPT_ARABIC,
	0x1EE79,	0x1EE7C,	PUCD_SCRIPT_ARABIC,
	0x1EE7E,	0x1EE7E,	PUCD_SCRIPT_ARABIC,
	0x1EE80,	0x1EE89,	PUCD_SCRIPT_ARABIC,
	0x1EE8B,	0x1EE9B,	PUCD_SCRIPT_ARABIC,
	0x1EEA1,	0x1EEA3,	PUCD_SCRIPT_ARABIC,
	0x1EEA5,	0x1EEA9,	PUCD_SCRIPT_ARABIC,
	0x1EEAB,	0x1EEBB,	PUCD_SCRIPT_ARABIC,
	0x1EEF0,	0x1EEF1,	PUCD_SCRIPT_ARABIC,
	0x1F000,	0x1F02B,	PUCD_SCRIPT_COMMON,
	0x1F030,	0x1F093,	PUCD_SCRIPT_COMMON,
	0x1F0A0,	0x1F0AE,	PUCD_SCRIPT_COMMON,
	0x1F0B1,	0x1F0BE,	PUCD_SCRIPT_COMMON,
	0x1F0C1,	0x1F0CF,	PUCD_SCRIPT_COMMON,
	0x1F0D1,	0x1F0DF,	PUCD_SCRIPT_COMMON,
	0x1F100,	0x1F10A,	PUCD_SCRIPT_COMMON,
	0x1F110,	0x1F12E,	PUCD_SCRIPT_COMMON,
	0x1F130,	0x1F16B,	PUCD_SCRIPT_COMMON,
	0x1F170,	0x1F19A,	PUCD_SCRIPT_COMMON,
	0x1F1E6,	0x1F1FF,	PUCD_SCRIPT_COMMON,
	0x1F200,	0x1F200,	PUCD_SCRIPT_HIRAGANA,
	0x1F201,	0x1F202,	PUCD_SCRIPT_COMMON,
	0x1F210,	0x1F23A,	PUCD_SCRIPT_COMMON,
	0x1F240,	0x1F248,	PUCD_SCRIPT_COMMON,
	0x1F250,	0x1F251,	PUCD_SCRIPT_COMMON,
	0x1F300,	0x1F320,	PUCD_SCRIPT_COMMON,
	0x1F330,	0x1F335,	PUCD_SCRIPT_COMMON,
	0x1F337,	0x1F37C,	PUCD_SCRIPT_COMMON,
	0x1F380,	0x1F393,	PUCD_SCRIPT_COMMON,
	0x1F3A0,	0x1F3C4,	PUCD_SCRIPT_COMMON,
	0x1F3C6,	0x1F3CA,	PUCD_SCRIPT_COMMON,
	0x1F3E0,	0x1F3F0,	PUCD_SCRIPT_COMMON,
	0x1F400,	0x1F43E,	PUCD_SCRIPT_COMMON,
	0x1F440,	0x1F440,	PUCD_SCRIPT_COMMON,
	0x1F442,	0x1F4F7,	PUCD_SCRIPT_COMMON,
	0x1F4F9,	0x1F4FC,	PUCD_SCRIPT_COMMON,
	0x1F500,	0x1F53D,	PUCD_SCRIPT_COMMON,
	0x1F540,	0x1F543,	PUCD_SCRIPT_COMMON,
	0x1F550,	0x1F567,	PUCD_SCRIPT_COMMON,
	0x1F5FB,	0x1F640,	PUCD_SCRIPT_COMMON,
	0x1F645,	0x1F64F,	PUCD_SCRIPT_COMMON,
	0x1F680,	0x1F6C5,	PUCD_SCRIPT_COMMON,
	0x1F700,	0x1F773,	PUCD_SCRIPT_COMMON,
	0x20000,	0x2A6D6,	PUCD_SCRIPT_HAN,
	0x2A700,	0x2B734,	PUCD_SCRIPT_HAN,
	0x2B740,	0x2B81D,	PUCD_SCRIPT_HAN,
	0x2F800,	0x2FA1D,	PUCD_SCRIPT_HAN,
	0xE0001,	0xE0001,	PUCD_SCRIPT_COMMON,
	0xE0020,	0xE007F,	PUCD_SCRIPT_COMMON,
	0xE0100,	0xE01EF,	PUCD_SCRIPT_INHERITED,
};
int	nScriptCpIdMap	= sizeof(ScriptCpIdMap) / sizeof(PSCpIdMap);


//======================================================================
//	属性 ID から属性名を得るためのデータ
//======================================================================
#ifdef	PDEBUG

PSIdPSzMap	ScriptIdNameMap[]	=
{
	0,	TQU("UNKNOWN"),
	1,	TQU("COMMON"),
	2,	TQU("LATIN"),
	3,	TQU("BOPOMOFO"),
	4,	TQU("INHERITED"),
	5,	TQU("GREEK"),
	6,	TQU("COPTIC"),
	7,	TQU("CYRILLIC"),
	8,	TQU("ARMENIAN"),
	9,	TQU("HEBREW"),
	10,	TQU("ARABIC"),
	11,	TQU("SYRIAC"),
	12,	TQU("THAANA"),
	13,	TQU("NKO"),
	14,	TQU("SAMARITAN"),
	15,	TQU("MANDAIC"),
	16,	TQU("DEVANAGARI"),
	17,	TQU("BENGALI"),
	18,	TQU("GURMUKHI"),
	19,	TQU("GUJARATI"),
	20,	TQU("ORIYA"),
	21,	TQU("TAMIL"),
	22,	TQU("TELUGU"),
	23,	TQU("KANNADA"),
	24,	TQU("MALAYALAM"),
	25,	TQU("SINHALA"),
	26,	TQU("THAI"),
	27,	TQU("LAO"),
	28,	TQU("TIBETAN"),
	29,	TQU("MYANMAR"),
	30,	TQU("GEORGIAN"),
	31,	TQU("HANGUL"),
	32,	TQU("ETHIOPIC"),
	33,	TQU("CHEROKEE"),
	34,	TQU("CANADIANABORIGINAL"),
	35,	TQU("OGHAM"),
	36,	TQU("RUNIC"),
	37,	TQU("TAGALOG"),
	38,	TQU("HANUNOO"),
	39,	TQU("BUHID"),
	40,	TQU("TAGBANWA"),
	41,	TQU("KHMER"),
	42,	TQU("MONGOLIAN"),
	43,	TQU("LIMBU"),
	44,	TQU("TAILE"),
	45,	TQU("NEWTAILUE"),
	46,	TQU("BUGINESE"),
	47,	TQU("TAITHAM"),
	48,	TQU("BALINESE"),
	49,	TQU("SUNDANESE"),
	50,	TQU("BATAK"),
	51,	TQU("LEPCHA"),
	52,	TQU("OLCHIKI"),
	53,	TQU("BRAILLE"),
	54,	TQU("GLAGOLITIC"),
	55,	TQU("TIFINAGH"),
	56,	TQU("HAN"),
	57,	TQU("HIRAGANA"),
	58,	TQU("KATAKANA"),
	59,	TQU("YI"),
	60,	TQU("LISU"),
	61,	TQU("VAI"),
	62,	TQU("BAMUM"),
	63,	TQU("SYLOTINAGRI"),
	64,	TQU("PHAGSPA"),
	65,	TQU("SAURASHTRA"),
	66,	TQU("KAYAHLI"),
	67,	TQU("REJANG"),
	68,	TQU("JAVANESE"),
	69,	TQU("CHAM"),
	70,	TQU("TAIVIET"),
	71,	TQU("MEETEIMAYEK"),
	72,	TQU("LINEARB"),
	73,	TQU("LYCIAN"),
	74,	TQU("CARIAN"),
	75,	TQU("OLDITALIC"),
	76,	TQU("GOTHIC"),
	77,	TQU("UGARITIC"),
	78,	TQU("OLDPERSIAN"),
	79,	TQU("DESERET"),
	80,	TQU("SHAVIAN"),
	81,	TQU("OSMANYA"),
	82,	TQU("CYPRIOT"),
	83,	TQU("IMPERIALARAMAIC"),
	84,	TQU("PHOENICIAN"),
	85,	TQU("LYDIAN"),
	86,	TQU("MEROITICHIEROGLYPHS"),
	87,	TQU("MEROITICCURSIVE"),
	88,	TQU("KHAROSHTHI"),
	89,	TQU("OLDSOUTHARABIAN"),
	90,	TQU("AVESTAN"),
	91,	TQU("INSCRIPTIONALPARTHIAN"),
	92,	TQU("INSCRIPTIONALPAHLAVI"),
	93,	TQU("OLDTURKIC"),
	94,	TQU("BRAHMI"),
	95,	TQU("KAITHI"),
	96,	TQU("SORASOMPENG"),
	97,	TQU("CHAKMA"),
	98,	TQU("SHARADA"),
	99,	TQU("TAKRI"),
	100,	TQU("CUNEIFORM"),
	101,	TQU("EGYPTIANHIEROGLYPHS"),
	102,	TQU("MIAO"),
};
int	nScriptIdNameMap	= sizeof(ScriptIdNameMap) / sizeof(PSIdPSzMap);

#endif

//======================================================================
//	GetScriptIdByName
//	Script 属性値名から属性値 ID を取得する。
//======================================================================
bool GetScriptIdByName(int* pid, UCPSTRING* pucsName)
{
	UINT	uiIndex;

	if (PLib::BinarySearch<PSPropertyValueIdMap, UCPSTRING*>(
		&uiIndex, siScriptIdMap, nScriptIdMap, pucsName))
	{
		*pid	= siScriptIdMap[uiIndex].iId;
		return true;
	}
	return false;
}
/*
bool GetScriptIdByName(int* pid, const T_UCP* pNameB, const T_UCP* pNameE)
{
	return GetPropertyValueByName(pid, ScriptNameIdMap, nScriptNameIdMap, pNameB, pNameE);
}

bool GetScriptIdByName(int* pid, const T_UCP* pName, size_t zName)
{
	return GetPropertyValueByName(pid, ScriptNameIdMap, nScriptNameIdMap, pName, pName + zName);
}
*/

//======================================================================
//	GetScriptValue	(2-1)
//	指定された文字のコードポイントから Script 属性値 ID を取得する。
//======================================================================
bool GetScriptValue(int* pid, UINT uiCp)
{
	return GetPropertyValue(pid, ScriptCpIdMap, nScriptCpIdMap, uiCp);
}

//======================================================================
//	GetScriptValue	(2-2)
//	文字列中の指定した位置にある文字の Script 属性値 ID を取得する。
//======================================================================
bool GetScriptValue(int* pid, const T_UCP* pStr, const T_UCP* pEnd)
{
	//return GetPropertyValue(pid, ScriptCpIdMap, nScriptCpIdMap, pStr, pEnd);
	return false;
}

//======================================================================
//	デバッグ用
//======================================================================
#ifdef	PDEBUG
T_PCSTR_U	Debug_GetScriptValue(int iId)
{
	if (iId >= 0 && iId < nScriptIdNameMap)
	{
		return ScriptIdNameMap[iId].Data;
	}
	return TQU("(invalid id)");
}
#endif

NS_PLIB_UNICODE_END
