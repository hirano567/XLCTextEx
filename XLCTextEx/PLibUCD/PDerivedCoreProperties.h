//	XLCTextEx_1.0x	:	PLibUCD

//	PLibUCD:	PDerivedCoreProperties.h
//
#pragma once

NS_PLIB_UNICODE_BEGIN

#define	PUCD_DERIVEDCOREPROPERTY_UNDEFINED	0
#define	PUCD_DERIVEDCOREPROPERTY_GRAPHEME_BASE	1
#define	PUCD_DERIVEDCOREPROPERTY_CASE_IGNORABLE	2
#define	PUCD_DERIVEDCOREPROPERTY_MATH	3
#define	PUCD_DERIVEDCOREPROPERTY_ID_CONTINUE	4
#define	PUCD_DERIVEDCOREPROPERTY_ALPHABETIC	5
#define	PUCD_DERIVEDCOREPROPERTY_LOWERCASE	6
#define	PUCD_DERIVEDCOREPROPERTY_UPPERCASE	7
#define	PUCD_DERIVEDCOREPROPERTY_CHANGES_WHEN_CASEFOLDED	8
#define	PUCD_DERIVEDCOREPROPERTY_CHANGES_WHEN_UPPERCASED	9
#define	PUCD_DERIVEDCOREPROPERTY_DEFAULT_IGNORABLE_CODE_POINT	10
#define	PUCD_DERIVEDCOREPROPERTY_GRAPHEME_LINK	11
#define	PUCD_DERIVEDCOREPROPERTY_GRAPHEME_EXTEND	12
#define	PUCD_DERIVEDCOREPROPERTY_CHANGES_WHEN_LOWERCASED	13
#define	PUCD_DERIVEDCOREPROPERTY_ID_START	14
#define	PUCD_DERIVEDCOREPROPERTY_XID_START	15

//======================================================================
//	�֐��̐錾
//======================================================================

bool IsAlphabetic(UINT uiCp);
bool IsLowercase(UINT uiCp);
bool IsUppercase(UINT uiCp);
bool IsDefaultIgnorableCodePoint(UINT uiCp);

NS_PLIB_UNICODE_END
