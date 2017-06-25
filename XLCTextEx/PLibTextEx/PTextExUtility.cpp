//	XLCTextEx_1.0x	:	PLibTextEx

//	PTextExUtility.cpp
//
#include "stdafx.h"

NS_PLIB_BEGIN

//======================================================================
//	POSIX Char Class
//======================================================================
T_UCP	cpaPosixCharClassNonDigit[]	= { 0x005E, 0x0064, 0x0069, 0x0067, 0x0069, 0x0074, 0, };
T_UCP	cpaPosixCharClassNonSpace[]	= { 0x005E, 0x0073, 0x0070, 0x0061, 0x0063, 0x0065, 0, };
T_UCP	cpaPosixCharClassNonWord[]	= { 0x005E, 0x0077, 0x006F, 0x0072, 0x0064, 0, };
T_UCP	cpaPosixCharClassAlnum[]	= { 0x0061, 0x006C, 0x006E, 0x0075, 0x006D, 0, };
T_UCP	cpaPosixCharClassAlpha[]	= { 0x0061, 0x006C, 0x0070, 0x0068, 0x0061, 0, };
T_UCP	cpaPosixCharClassAscii[]	= { 0x0061, 0x0073, 0x0063, 0x0069, 0x0069, 0, };
T_UCP	cpaPosixCharClassBlank[]	= { 0x0062, 0x006C, 0x0061, 0x006E, 0x006B, 0, };
T_UCP	cpaPosixCharClassCntrl[]	= { 0x0063, 0x006E, 0x0074, 0x0072, 0x006C, 0, };
T_UCP	cpaPosixCharClassDigit[]	= { 0x0064, 0x0069, 0x0067, 0x0069, 0x0074, 0, };
T_UCP	cpaPosixCharClassGraph[]	= { 0x0067, 0x0072, 0x0061, 0x0070, 0x0068, 0, };
T_UCP	cpaPosixCharClassLower[]	= { 0x006C, 0x006F, 0x0077, 0x0065, 0x0072, 0, };
T_UCP	cpaPosixCharClassPrint[]	= { 0x0070, 0x0072, 0x0069, 0x006E, 0x0074, 0, };
T_UCP	cpaPosixCharClassPunct[]	= { 0x0070, 0x0075, 0x006E, 0x0063, 0x0074, 0, };
T_UCP	cpaPosixCharClassSpace[]	= { 0x0073, 0x0070, 0x0061, 0x0063, 0x0065, 0, };
T_UCP	cpaPosixCharClassUpper[]	= { 0x0075, 0x0070, 0x0070, 0x0065, 0x0072, 0, };
T_UCP	cpaPosixCharClassWord[]		= { 0x0077, 0x006F, 0x0072, 0x0064, 0, };
T_UCP	cpaPosixCharClassXdigit[]	= { 0x0078, 0x0064, 0x0069, 0x0067, 0x0069, 0x0074, 0, };

PSPosixCharclassInfo	siPosixCharclassInfo[]	=
{
	cpaPosixCharClassNonDigit,	TQU("^digit"),	PTEXTEX_CHARCLASS_POSIX_NONDIGIT,
	cpaPosixCharClassNonSpace,	TQU("^space"),	PTEXTEX_CHARCLASS_POSIX_NONSPACE,
	cpaPosixCharClassNonWord,	TQU("^word"),	PTEXTEX_CHARCLASS_POSIX_NONWORD,
	cpaPosixCharClassAlnum,		TQU("alnum"),	PTEXTEX_CHARCLASS_POSIX_ALNUM,
	cpaPosixCharClassAlpha,		TQU("alpha"),	PTEXTEX_CHARCLASS_POSIX_ALPHA,
	cpaPosixCharClassAscii,		TQU("ascii"),	PTEXTEX_CHARCLASS_POSIX_ASCII,
	cpaPosixCharClassBlank,		TQU("blank"),	PTEXTEX_CHARCLASS_POSIX_BLANK,
	cpaPosixCharClassCntrl,		TQU("cntrl"),	PTEXTEX_CHARCLASS_POSIX_CNTRL,
	cpaPosixCharClassDigit,		TQU("digit"),	PTEXTEX_CHARCLASS_POSIX_DIGIT,
	cpaPosixCharClassGraph,		TQU("graph"),	PTEXTEX_CHARCLASS_POSIX_GRAPH,
	cpaPosixCharClassLower,		TQU("lower"),	PTEXTEX_CHARCLASS_POSIX_LOWER,
	cpaPosixCharClassPrint,		TQU("print"),	PTEXTEX_CHARCLASS_POSIX_PRINT,
	cpaPosixCharClassPunct,		TQU("punct"),	PTEXTEX_CHARCLASS_POSIX_PUNCT,
	cpaPosixCharClassSpace,		TQU("space"),	PTEXTEX_CHARCLASS_POSIX_SPACE,
	cpaPosixCharClassUpper,		TQU("upper"),	PTEXTEX_CHARCLASS_POSIX_UPPER,
	cpaPosixCharClassWord,		TQU("word"),	PTEXTEX_CHARCLASS_POSIX_WORD,
	cpaPosixCharClassXdigit,	TQU("xdigit"),	PTEXTEX_CHARCLASS_POSIX_XDIGIT,
};

int	nPosixCharclassInfo	= sizeof(siPosixCharclassInfo) / sizeof(PSPosixCharclassInfo);

//----------------------------------------------------------------------
//	GetPosixCharClassId	(1)
//----------------------------------------------------------------------
int	GetPosixCharClassId(UCPSTRING* pucsCName)
{
	UINT	uiFound;

	if (PLib::BinarySearch<PSPosixCharclassInfo, UCPSTRING*>(
		&uiFound, siPosixCharclassInfo, nPosixCharclassInfo, pucsCName))
	{
		return siPosixCharclassInfo[uiFound].iId;
	}
	return PTEXTEX_CHARCLASS_POSIX_ERROR;
}

/*
//----------------------------------------------------------------------
//	GetPosixCharClassId	(2)
//----------------------------------------------------------------------
int	GetPosixCharClassId(const T_UCP* pNameB, const T_UCP* pNameE)
{
	UCPSTRING	ucsName;
	UINT		uiFound;

	ucsName.assign(pNameB, (size_t)(pNameE - pNameB));
	if (PLib::BinarySearch<PSPosixCharclassInfo, UCPSTRING*>(
		&uiFound, siPosixCharclassInfo, nPosixCharclassInfo, &ucsName))
	{
		return siPosixCharclassInfo[uiFound].iId;
	}
	return PTEXTEX_CHARCLASS_POSIX_ERROR;
}
*/

//======================================================================
//	Unicode Property
//======================================================================
T_UCP	cpaUnicodePropertyNameAlpha[]	= { 0x0061, 0x006C, 0x0070, 0x0068, 0x0061, 0, };

T_UCP	cpaUnicodePropertyNameAlphabetic[]	= { 0x0061, 0x006C, 0x0070, 0x0068, 0x0061, 0x0062, 0x0065, 0x0074, 0x0069, 0x0063, 0, };

T_UCP	cpaUnicodePropertyNameBlk[]	= { 0x0062, 0x006C, 0x006B, 0, };

T_UCP	cpaUnicodePropertyNameBlock[]	= { 0x0062, 0x006C, 0x006F, 0x0063, 0x006B, 0, };

T_UCP	cpaUnicodePropertyNameDefaultIgnorableCodepoint[]	= {
	0x0064, 0x0065, 0x0066, 0x0061, 0x0075, 0x006C, 0x0074, 0x0069, 0x0067, 0x006E, 0x006F, 0x0072, 0x0061, 0x0062, 0x006C, 0x0065,
	0x0063, 0x006F, 0x0064, 0x0065, 0x0070, 0x006F, 0x0069, 0x006E, 0x0074, 0,
};

T_UCP	cpaUnicodePropertyNameDi[]	= { 0x0064, 0x0069, 0, };

T_UCP	cpaUnicodePropertyNameGc[]	= { 0x0067, 0x0063, 0, };

T_UCP	cpaUnicodePropertyNameGeneralCategory[]	= {
	0x0067, 0x0065, 0x006E, 0x0065, 0x0072, 0x0061, 0x006C, 0x0063, 0x0061, 0x0074, 0x0065, 0x0067, 0x006F, 0x0072, 0x0079, 0,
};
T_UCP	cpaUnicodePropertyNameLower[]	= { 0x006C, 0x006F, 0x0077, 0x0065, 0x0072, 0, };

T_UCP	cpaUnicodePropertyNameLowercase[]	= { 0x006C, 0x006F, 0x0077, 0x0065, 0x0072, 0x0063, 0x0061, 0x0073, 0x0065, 0, };

T_UCP	cpaUnicodePropertyNameNchar[]	= { 0x006E, 0x0063, 0x0068, 0x0061, 0x0072, 0, };

T_UCP	cpaUnicodePropertyNameNoncharacterCodepoint[]	= {
	0x006E, 0x006F, 0x006E, 0x0063, 0x0068, 0x0061, 0x0072, 0x0061, 0x0063, 0x0074, 0x0065, 0x0072, 0x0063, 0x006F, 0x0064,
	0x0065, 0x0070, 0x006F, 0x0069, 0x006E, 0x0074, 0,
};

T_UCP	cpaUnicodePropertyNameSc[]	= { 0x0073, 0x0063, 0, };

T_UCP	cpaUnicodePropertyNameScript[]	= { 0x0073, 0x0063, 0x0072, 0x0069, 0x0070, 0x0074, 0, };

T_UCP	cpaUnicodePropertyNameSpace[]	= { 0x0073, 0x0070, 0x0061, 0x0063, 0x0065, 0, };

T_UCP	cpaUnicodePropertyNameUpper[]	= { 0x0075, 0x0070, 0x0070, 0x0065, 0x0072, 0, };

T_UCP	cpaUnicodePropertyNameUppercase[]	= { 0x0075, 0x0070, 0x0070, 0x0065, 0x0072, 0x0063, 0x0061, 0x0073, 0x0065, 0, };

T_UCP	cpaUnicodePropertyNameWhitespace[]	= { 0x0077, 0x0068, 0x0069, 0x0074, 0x0065, 0x0073, 0x0070, 0x0061, 0x0063, 0x0065, 0, };

T_UCP	cpaUnicodePropertyNameWspace[]	= { 0x0077, 0x0073, 0x0070, 0x0061, 0x0063, 0x0065, 0, };

PSUnicodePropertyName	siUnicodePropertyName[]	=
{
	cpaUnicodePropertyNameAlpha,	TQU("alpha"),
	PTEXTEX_UNICODE_PROPERTY_ALPHABETIC,

	cpaUnicodePropertyNameAlphabetic,	TQU("alphabetic"),
	PTEXTEX_UNICODE_PROPERTY_ALPHABETIC,

	cpaUnicodePropertyNameBlk,	TQU("blk"),
	PTEXTEX_UNICODE_PROPERTY_NAMED_BLOCK,

	cpaUnicodePropertyNameBlock,	TQU("block"),
	PTEXTEX_UNICODE_PROPERTY_NAMED_BLOCK,

	cpaUnicodePropertyNameDefaultIgnorableCodepoint,	TQU("defaultignorablecodepoint"),
	PTEXTEX_UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT,

	cpaUnicodePropertyNameDi,	TQU("di"),
	PTEXTEX_UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT,

	cpaUnicodePropertyNameGc,	TQU("gc"),
	PTEXTEX_UNICODE_PROPERTY_GENERAL_CATEGORY,

	cpaUnicodePropertyNameGeneralCategory,	TQU("generalcategory"),
	PTEXTEX_UNICODE_PROPERTY_GENERAL_CATEGORY,

	cpaUnicodePropertyNameLower,	TQU("lower"),
	PTEXTEX_UNICODE_PROPERTY_LOWERCASE,

	cpaUnicodePropertyNameLowercase,	TQU("lowercase"),
	PTEXTEX_UNICODE_PROPERTY_LOWERCASE,

	cpaUnicodePropertyNameNchar,	TQU("nchar"),
	PTEXTEX_UNICODE_PROPERTY_NONCHARACTER_CODE_POINT,

	cpaUnicodePropertyNameNoncharacterCodepoint,	TQU("noncharactercodepoint"),
	PTEXTEX_UNICODE_PROPERTY_NONCHARACTER_CODE_POINT,

	cpaUnicodePropertyNameSc,	TQU("sc"),
	PTEXTEX_UNICODE_PROPERTY_SCRIPT,

	cpaUnicodePropertyNameScript,	TQU("script"),
	PTEXTEX_UNICODE_PROPERTY_SCRIPT,

	cpaUnicodePropertyNameSpace,	TQU("space"),
	PTEXTEX_UNICODE_PROPERTY_WHITE_SPACE,

	cpaUnicodePropertyNameUpper,	TQU("upper"),
	PTEXTEX_UNICODE_PROPERTY_UPPERCASE,

	cpaUnicodePropertyNameUppercase,	TQU("uppercase"),
	PTEXTEX_UNICODE_PROPERTY_UPPERCASE,

	cpaUnicodePropertyNameWhitespace,	TQU("whitespace"),
	PTEXTEX_UNICODE_PROPERTY_WHITE_SPACE,

	cpaUnicodePropertyNameWspace,	TQU("wspace"),
	PTEXTEX_UNICODE_PROPERTY_WHITE_SPACE,
};

int	nUnicodePropertyName	= sizeof(siUnicodePropertyName) / sizeof(PSUnicodePropertyName);

//----------------------------------------------------------------------
//	GetUnicodePropertyId
//----------------------------------------------------------------------
int	GetUnicodePropertyId(UCPSTRING* pucsName)
{
	UINT		uiFound;

	if (pucsName == NULL || pucsName->empty())	return PTEXTEX_UNICODE_PROPERTY_ERROR;

	if (PLib::BinarySearch<PSUnicodePropertyName, UCPSTRING*>(
		&uiFound, siUnicodePropertyName, nUnicodePropertyName, pucsName))
	{
		return siUnicodePropertyName[uiFound].iId;
	}
	return PTEXTEX_UNICODE_PROPERTY_ERROR;
}

int	GetUnicodePropertyId(const T_UCP* pName, size_t zName)
{
	UCPSTRING	ucsName;

	if (pName == NULL || zName < 1)	return PTEXTEX_CHARCLASS_POSIX_ERROR;
	ucsName.assign(pName, zName);
	return GetUnicodePropertyId(&ucsName);
}


//======================================================================
//	MatchPOSIXCharClass
//======================================================================
BOOL MatchPOSIXCharClass(T_UCP cpSrc, int iClass, DWORD dwFlags, T_PCSTR_U pszLocale)
{
	switch (iClass)
	{
	case PTEXTEX_CHARCLASS_POSIX_ALNUM:
		if (PLib::Unicode::IsAlNum_GC(cpSrc))	return TRUE;
		break;

	case PTEXTEX_CHARCLASS_POSIX_ALPHA:
		if (PLib::Unicode::IsAlpha_GC(cpSrc))	return TRUE;
		break;

	case PTEXTEX_CHARCLASS_POSIX_ASCII:
		if (IS_7BIT(cpSrc))	return TRUE;
		break;

	case PTEXTEX_CHARCLASS_POSIX_BLANK:
		if (PLib::Unicode::IsBlank(cpSrc, true))	return TRUE;
		break;

	case PTEXTEX_CHARCLASS_POSIX_CNTRL:
		if (PLib::Unicode::IsCntrl_GC(cpSrc))	return TRUE;
		break;

	case PTEXTEX_CHARCLASS_POSIX_DIGIT:
		if (PLib::Unicode::IsDigit_GC(cpSrc))	return TRUE;
		break;

	case PTEXTEX_CHARCLASS_POSIX_GRAPH:
		if (PLib::Unicode::IsGraph_GC(cpSrc))	return TRUE;
		break;

	case PTEXTEX_CHARCLASS_POSIX_LOWER:
		if (PLib::Unicode::IsLower_GC(cpSrc))	return TRUE;
		break;

	case PTEXTEX_CHARCLASS_POSIX_PRINT:
		if (PLib::Unicode::IsPrint_GC(cpSrc))	return TRUE;
		break;

	case PTEXTEX_CHARCLASS_POSIX_PUNCT:
		if (PLib::Unicode::IsPunct_GC(cpSrc))	return TRUE;
		break;

	case PTEXTEX_CHARCLASS_POSIX_SPACE:
		if (PLib::Unicode::IsSpace_GC(cpSrc))	return TRUE;
		break;

	case PTEXTEX_CHARCLASS_POSIX_UPPER:
		if (PLib::Unicode::IsUpper_GC(cpSrc))	return TRUE;
		break;

	//case PTEXTEX_CHARCLASS_POSIX_WORD:
	//	if (NS_PLIB::TextEx::IsWordChar(pszStr, dwFlags, dwLocale))	return TRUE;
	//	break;

	case PTEXTEX_CHARCLASS_POSIX_XDIGIT:
		if (ISXDIGIT_U(cpSrc))	return TRUE;
		break;

	case PTEXTEX_CHARCLASS_POSIX_NONDIGIT:
		if (!PLib::Unicode::IsDigit_GC(cpSrc))	return TRUE;
		break;

	case PTEXTEX_CHARCLASS_POSIX_NONSPACE:
		if (!PLib::Unicode::IsSpace_GC(cpSrc))	return TRUE;
		break;

	//case PTEXTEX_CHARCLASS_POSIX_NONWORD:
	//	if (!NS_PLIB::TextEx::IsWordChar(pszStr, dwFlags, dwLocale))	return TRUE;
	//	break;

	default:
		break;
	}
	return FALSE;
}

//======================================================================
//	テキスト処理関数
//	q オプションが指定されているとき、両端が引用符ならそれを外す。
//======================================================================
#define	IS_q(c)	((c) == (T_CHAR_U)0x0071 || (c) == (T_CHAR_U)0x33C3)
#define	IS_HYPHEN(c)	\
	((c) == (T_CHAR_U)0x002D || (c) == (T_CHAR_U)0xFE63 || (c) == (T_CHAR_U)0xFF0D)

bool RemoveQuote(T_PCSTR_U*	ppOffB,
				 T_PCSTR_U*	ppOffE,
				 T_PCSTR_U	pSrcB,
				 T_PCSTR_U	pSrcE,
				 T_PCSTR_U	pOptB,
				 T_PCSTR_U	pOptE)
{
	T_PCSTR_U	pc;
	bool	bRemove	= false;

	if (ppOffB == NULL || ppOffE == NULL	||
		pSrcB == NULL || pSrcB > pSrcE		||
		pOptB == NULL || pOptB > pOptE)
	{
		return false;
	}

	//	q オプションが指定されているかを調べる。
	for ( ; pOptB < pOptE; ++pOptB)
	{
		if (IS_q(*pOptB))
		{
			bRemove	= true;
			break;
		}
		if (IS_HYPHEN(*pOptB))
		{
			break;
		}
	}
	if (!bRemove)	goto NOT_REMOVE;

	//	文字列長が 2 未満の場合は何もせずに返す。
	if ( pSrcB + 2 > pSrcE)	goto NOT_REMOVE;

	//	先頭が " でない場合は何もせずに返す。
	if (!PLib::IsDoubleQuote<T_CHAR_U>(*pSrcB))	goto NOT_REMOVE;

	//	最後の文字を調べる。
	pc	= pSrcE;
	--pc;
	if (!PLib::IsDoubleQuote<T_CHAR_U>(*pc))	goto NOT_REMOVE;
	++pSrcB;
	*ppOffB	= pSrcB;
	*ppOffE	= pc;
	return true;

NOT_REMOVE:
	*ppOffB	= pSrcB;
	*ppOffE	= pSrcE;
	return true;
}

NS_PLIB_END
