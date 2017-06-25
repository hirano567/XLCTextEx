//	XLCTextEx_1.0x	:	PLibUCD

//	PLibUCD:	PPropList.cpp
//
#include "stdafx.h"

NS_PLIB_UNICODE_BEGIN

//======================================================================
//	Noncharacter_Code_Point
//======================================================================
PSCpIdMap	NoncharacterCodePointCpIdMap[]	=
{
	0xFDD0,	0xFDEF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0xFFFE,	0xFFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0x1FFFE,	0x1FFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0x2FFFE,	0x2FFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0x3FFFE,	0x3FFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0x4FFFE,	0x4FFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0x5FFFE,	0x5FFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0x6FFFE,	0x6FFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0x7FFFE,	0x7FFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0x8FFFE,	0x8FFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0x9FFFE,	0x9FFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0xAFFFE,	0xAFFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0xBFFFE,	0xBFFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0xCFFFE,	0xCFFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0xDFFFE,	0xDFFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0xEFFFE,	0xEFFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0xFFFFE,	0xFFFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
	0x10FFFE,	0x10FFFF,	PUCD_PROPLIST_NONCHARACTER_CODE_POINT,
};
int	nNoncharacterCodePointCpIdMap	= sizeof(NoncharacterCodePointCpIdMap) / sizeof(PSCpIdMap);

//----------------------------------------------------------------------
//	IsNoncharacterCodePoint
//----------------------------------------------------------------------
bool IsNoncharacterCodePoint(UINT uiCp)
{
	int	i;
	return GetPropertyValue(&i, NoncharacterCodePointCpIdMap, nNoncharacterCodePointCpIdMap, uiCp);
}

/*
bool IsNoncharacterCodePoint(const T_UCP* pStr, const T_UCP* pEnd)
{
	int	i;
	return GetPropertyValue(&i, NoncharacterCodePointCpIdMap, nNoncharacterCodePointCpIdMap, pStr, pEnd);
}
*/

//======================================================================
//	White_Space
//======================================================================
PSCpIdMap	WhiteSpaceCpIdMap[]	=
{
	0x0009,	0x000D,	PUCD_PROPLIST_WHITE_SPACE,
	0x0020,	0x0020,	PUCD_PROPLIST_WHITE_SPACE,
	0x0085,	0x0085,	PUCD_PROPLIST_WHITE_SPACE,
	0x00A0,	0x00A0,	PUCD_PROPLIST_WHITE_SPACE,
	0x1680,	0x1680,	PUCD_PROPLIST_WHITE_SPACE,
	0x180E,	0x180E,	PUCD_PROPLIST_WHITE_SPACE,
	0x2000,	0x200A,	PUCD_PROPLIST_WHITE_SPACE,
	0x2028,	0x2029,	PUCD_PROPLIST_WHITE_SPACE,
	0x202F,	0x202F,	PUCD_PROPLIST_WHITE_SPACE,
	0x205F,	0x205F,	PUCD_PROPLIST_WHITE_SPACE,
	0x3000,	0x3000,	PUCD_PROPLIST_WHITE_SPACE,
};
int	nWhiteSpaceCpIdMap	= sizeof(WhiteSpaceCpIdMap) / sizeof(PSCpIdMap);

//----------------------------------------------------------------------
//	IsWhiteSpace
//----------------------------------------------------------------------
bool IsWhiteSpace(UINT uiCp)
{
	int	i;
	return GetPropertyValue(&i, WhiteSpaceCpIdMap, nWhiteSpaceCpIdMap, uiCp);
}

/*
bool IsWhiteSpace(const T_UCP* pStr, const T_UCP* pEnd)
{
	int	i;
	return GetPropertyValue(&i, WhiteSpaceCpIdMap, nWhiteSpaceCpIdMap, pStr, pEnd);
}
*/

NS_PLIB_UNICODE_END
