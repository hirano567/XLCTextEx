//	XLCTextEx_1.0x	:	PLibUCD

//	PLibUCD:	PUnicodeData.h
//
#pragma once

NS_PLIB_UNICODE_BEGIN

#define	PUCD_GENERAL_CATEGORY_ERROR						0

#define	PUCD_GENERAL_CATEGORY_LU_UPPERCASE_LETTER		1
#define	PUCD_GENERAL_CATEGORY_LL_LOWERCASE_LETTER		2
#define	PUCD_GENERAL_CATEGORY_LT_TITLECASE_LETTER		3
#define	PUCD_GENERAL_CATEGORY_LC_CASED_LETTER			4
#define	PUCD_GENERAL_CATEGORY_LM_MODIFIER_LETTER		5
#define	PUCD_GENERAL_CATEGORY_LO_OTHER_LETTER			6
#define	PUCD_GENERAL_CATEGORY_L_LETTER					7
#define	PUCD_GENERAL_CATEGORY_MN_NONSPACING_MARK		8
#define	PUCD_GENERAL_CATEGORY_MC_SPACING_MARK			9
#define	PUCD_GENERAL_CATEGORY_ME_ENCLOSING_MARK			10
#define	PUCD_GENERAL_CATEGORY_M_MARK					11
#define	PUCD_GENERAL_CATEGORY_ND_DECIMAL_NUMBER			12
#define	PUCD_GENERAL_CATEGORY_NL_LETTER_NUMBER			13
#define	PUCD_GENERAL_CATEGORY_NO_OTHER_NUMBER			14
#define	PUCD_GENERAL_CATEGORY_N_NUMBER					15
#define	PUCD_GENERAL_CATEGORY_PC_CONNECTOR_PUNCTUATION	16
#define	PUCD_GENERAL_CATEGORY_PD_DASH_PUNCTUATION		17
#define	PUCD_GENERAL_CATEGORY_PS_OPEN_PUNCTUATION		18
#define	PUCD_GENERAL_CATEGORY_PE_CLOSE_PUNCTUATION		19
#define	PUCD_GENERAL_CATEGORY_PI_INITIAL_PUNCTUATION	20
#define	PUCD_GENERAL_CATEGORY_PF_FINAL_PUNCTUATION		21
#define	PUCD_GENERAL_CATEGORY_PO_OTHER_PUNCTUATION		22
#define	PUCD_GENERAL_CATEGORY_P_PUNCTUATION				23
#define	PUCD_GENERAL_CATEGORY_SM_MATH_SYMBOL			24
#define	PUCD_GENERAL_CATEGORY_SC_CURRENCY_SYMBOL		25
#define	PUCD_GENERAL_CATEGORY_SK_MODIFIER_SYMBOL		26
#define	PUCD_GENERAL_CATEGORY_SO_OTHER_SYMBOL			27
#define	PUCD_GENERAL_CATEGORY_S_SYMBOL					28
#define	PUCD_GENERAL_CATEGORY_ZS_SPACE_SEPARATOR		29
#define	PUCD_GENERAL_CATEGORY_ZL_LINE_SEPARATOR			30
#define	PUCD_GENERAL_CATEGORY_ZP_PARAGRAPH_SEPARATOR	31
#define	PUCD_GENERAL_CATEGORY_Z_SEPARATOR				32
#define	PUCD_GENERAL_CATEGORY_CC_CONTROL				33
#define	PUCD_GENERAL_CATEGORY_CF_FORMAT					34
#define	PUCD_GENERAL_CATEGORY_CS_SURROGATE				35
#define	PUCD_GENERAL_CATEGORY_CO_PRIVATE_USE			36
#define	PUCD_GENERAL_CATEGORY_CN_UNASSIGNED				37
#define	PUCD_GENERAL_CATEGORY_C_OTHER					38

//======================================================================
//	GetGeneralCategoryValue
//	属性値名から属性値 ID を取得する。
//======================================================================
bool	GetGeneralCategoryValueIdByName(int* pid, UCPSTRING* pucsName);

//======================================================================
//	GetGeneralCategoryValue
//	Codepoint からその文字の General_Category の属性値 ID を取得する。
//======================================================================
bool	GetGeneralCategoryValue(int* pid, T_UCP cpSrc);

//======================================================================
//	MatchGeneralCategory
//	処理を正常に行えなかった場合は例外をスローする。
//======================================================================
bool	MatchGeneralCategory(T_UCP cpSrc, int iGC);

//======================================================================
//	デバッグ用
//======================================================================
#ifdef	PDEBUG
T_PCSTR_U	Debug_GetGeneralCategoryValue(int iId);
#endif

NS_PLIB_UNICODE_END
