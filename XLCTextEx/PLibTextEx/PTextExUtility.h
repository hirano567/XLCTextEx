//	XLCTextEx_1.0x	:	PLibTextEx

//	PTextExUtility.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	POSIX Char Class
//======================================================================
#define	PTEXTEX_CHARCLASS_POSIX_ERROR		0

#define	PTEXTEX_CHARCLASS_POSIX_ALNUM		1
#define	PTEXTEX_CHARCLASS_POSIX_ALPHA		2
#define	PTEXTEX_CHARCLASS_POSIX_ASCII		3
#define	PTEXTEX_CHARCLASS_POSIX_BLANK		4
#define	PTEXTEX_CHARCLASS_POSIX_CNTRL		5
#define	PTEXTEX_CHARCLASS_POSIX_DIGIT		6
#define	PTEXTEX_CHARCLASS_POSIX_GRAPH		7
#define	PTEXTEX_CHARCLASS_POSIX_LOWER		8
#define	PTEXTEX_CHARCLASS_POSIX_PRINT		9
#define	PTEXTEX_CHARCLASS_POSIX_PUNCT		10
#define	PTEXTEX_CHARCLASS_POSIX_SPACE		11
#define	PTEXTEX_CHARCLASS_POSIX_UPPER		12
#define	PTEXTEX_CHARCLASS_POSIX_WORD		13
#define	PTEXTEX_CHARCLASS_POSIX_XDIGIT		14

#define	PTEXTEX_CHARCLASS_POSIX_NONDIGIT	15
#define	PTEXTEX_CHARCLASS_POSIX_NONSPACE	16
#define	PTEXTEX_CHARCLASS_POSIX_NONWORD		17

//----------------------------------------------------------------------
//	struct PSPosixCharclassInfo
//----------------------------------------------------------------------
struct PSPosixCharclassInfo
{
	const T_UCP*	pcpKey;
	T_PCSTR_U		pszKey;
	int				iId;

	int Compare(UCPSTRING* pucsStr)
	{
		PLib::Unicode::PCCodepointSzBuffer	ciUB1;
		PLib::Unicode::PCUIStringBuffer		ciUB2;
		DWORD	dwFlags	= NORM_IGNORECASE | NORM_IGNORENONSPACE | NORM_IGNOREWIDTH;

		ciUB1.Set(pcpKey);
		ciUB2.Set(pucsStr);
		return PLib::Unicode::CompareStringUCD(&ciUB1, &ciUB2, dwFlags, NULL);
	}

	bool LessThan(UCPSTRING* pStr)
	{
		return (Compare(pStr) == CSTR_LESS_THAN);
	}

	bool Match(UCPSTRING* pStr)
	{
		return (Compare(pStr) == CSTR_EQUAL);
	}
};

//----------------------------------------------------------------------
//	GetPosixCharClassId
//----------------------------------------------------------------------
int	GetPosixCharClassId(UCPSTRING* pucsCName);
//int	GetPosixCharClassId(const T_UCP* pNameB, const T_UCP* pNameE);

//----------------------------------------------------------------------
//	MatchPOSIXCharClass
//----------------------------------------------------------------------
BOOL	MatchPOSIXCharClass(T_UCP cpSrc, int iClass, DWORD dwFlags, T_PCSTR_U pszLocale);


//======================================================================
//	Unicode Property
//======================================================================
#define	PTEXTEX_UNICODE_PROPERTY_ERROR							0

#define	PTEXTEX_UNICODE_PROPERTY_BASE							16
#define	PTEXTEX_UNICODE_PROPERTY_GENERAL_CATEGORY				(1 << (PTEXTEX_UNICODE_PROPERTY_BASE + 0))
#define	PTEXTEX_UNICODE_PROPERTY_SCRIPT							(1 << (PTEXTEX_UNICODE_PROPERTY_BASE + 1))
#define	PTEXTEX_UNICODE_PROPERTY_ALPHABETIC						(1 << (PTEXTEX_UNICODE_PROPERTY_BASE + 2))
#define	PTEXTEX_UNICODE_PROPERTY_UPPERCASE						(1 << (PTEXTEX_UNICODE_PROPERTY_BASE + 3))
#define	PTEXTEX_UNICODE_PROPERTY_LOWERCASE						(1 << (PTEXTEX_UNICODE_PROPERTY_BASE + 4))
#define	PTEXTEX_UNICODE_PROPERTY_WHITE_SPACE					(1 << (PTEXTEX_UNICODE_PROPERTY_BASE + 5))
#define	PTEXTEX_UNICODE_PROPERTY_NONCHARACTER_CODE_POINT		(1 << (PTEXTEX_UNICODE_PROPERTY_BASE + 6))
#define	PTEXTEX_UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT	(1 << (PTEXTEX_UNICODE_PROPERTY_BASE + 7))
#define	PTEXTEX_UNICODE_PROPERTY_NAMED_BLOCK					(1 << (PTEXTEX_UNICODE_PROPERTY_BASE + 8))

#define	SET_PTEXTEX_UNICODE_PROPERTY_GENERAL_CATEGORY(m)	\
	((m) |= PTEXTEX_UNICODE_PROPERTY_GENERAL_CATEGORY)
#define	SET_PTEXTEX_UNICODE_PROPERTY_SCRIPT(m)	\
	((m) |= PTEXTEX_UNICODE_PROPERTY_SCRIPT)
#define	SET_PTEXTEX_UNICODE_PROPERTY_ALPHABETIC(m)	\
	((m) |= PTEXTEX_UNICODE_PROPERTY_ALPHABETIC)
#define	SET_PTEXTEX_UNICODE_PROPERTY_UPPERCASE(m)	\
	((m) |= PTEXTEX_UNICODE_PROPERTY_UPPERCASE)
#define	SET_PTEXTEX_UNICODE_PROPERTY_LOWERCASE(m)	\
	((m) |= PTEXTEX_UNICODE_PROPERTY_LOWERCASE)
#define	SET_PTEXTEX_UNICODE_PROPERTY_WHITE_SPACE(m)	\
	((m) |= PTEXTEX_UNICODE_PROPERTY_WHITE_SPACE)
#define	SET_PTEXTEX_UNICODE_PROPERTY_NONCHARACTER_CODE_POINT(m)	\
	((m) |= PTEXTEX_UNICODE_PROPERTY_NONCHARACTER_CODE_POINT)
#define	SET_PTEXTEX_UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT(m)	\
	((m) |= PTEXTEX_UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT)
#define	SET_PTEXTEX_UNICODE_PROPERTY_NAMED_BLOCK(m)	\
	((m) |= PTEXTEX_UNICODE_PROPERTY_NAMED_BLOCK)

#define	IS_PTEXTEX_UNICODE_PROPERTY_GENERAL_CATEGORY(m)	\
	(((m) & PTEXTEX_UNICODE_PROPERTY_GENERAL_CATEGORY) != 0)
#define	IS_PTEXTEX_UNICODE_PROPERTY_SCRIPT(m)	\
	(((m) & PTEXTEX_UNICODE_PROPERTY_SCRIPT) != 0)
#define	IS_PTEXTEX_UNICODE_PROPERTY_ALPHABETIC(m)	\
	(((m) & PTEXTEX_UNICODE_PROPERTY_ALPHABETIC) != 0)
#define	IS_PTEXTEX_UNICODE_PROPERTY_UPPERCASE(m)	\
	(((m) & PTEXTEX_UNICODE_PROPERTY_UPPERCASE) != 0)
#define	IS_PTEXTEX_UNICODE_PROPERTY_LOWERCASE(m)	\
	(((m) & PTEXTEX_UNICODE_PROPERTY_LOWERCASE) != 0)
#define	IS_PTEXTEX_UNICODE_PROPERTY_WHITE_SPACE(m)	\
	(((m) & PTEXTEX_UNICODE_PROPERTY_WHITE_SPACE) != 0)
#define	IS_PTEXTEX_UNICODE_PROPERTY_NONCHARACTER_CODE_POINT(m)	\
	(((m) & PTEXTEX_UNICODE_PROPERTY_NONCHARACTER_CODE_POINT) != 0)
#define	IS_PTEXTEX_UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT(m)	\
	(((m) & PTEXTEX_UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT) != 0)
#define	IS_PTEXTEX_UNICODE_PROPERTY_NAMED_BLOCK(m)	\
	(((m) & PTEXTEX_UNICODE_PROPERTY_NAMED_BLOCK) != 0)

#define	PTEXTEX_UNICODE_PROPERTY_NEGATIVE	(1 << 31)
#define	SET_PTEXTEX_UNICODE_PROPERTY_NEGATIVE(m)	\
	((m) |= PTEXTEX_UNICODE_PROPERTY_NEGATIVE)
#define	IS_PTEXTEX_UNICODE_PROPERTY_NEGATIVE(m)	\
	(((m) & PTEXTEX_UNICODE_PROPERTY_NEGATIVE) != 0)

#define	GET_PTEXTEX_UNICODE_PROPERTY_TYPE(m)		((m) & 0x7FFF0000)
#define	GET_PTEXTEX_UNICODE_PROPERTY_VALUE(m)	((m) & 0xFFFF)

//----------------------------------------------------------------------
//	struct PSUnicodePropertyName
//----------------------------------------------------------------------
struct PSUnicodePropertyName
{
	const T_UCP*	pcpKey;
	T_PCSTR_U		pszKey;
	int				iId;

	int Compare(UCPSTRING* pucsStr)
	{
		PLib::Unicode::PCCodepointSzBuffer	ciUB1;
		PLib::Unicode::PCUIStringBuffer		ciUB2;
		DWORD	dwFlags	= NORM_IGNORECASE | NORM_IGNORENONSPACE | NORM_IGNOREWIDTH;

		ciUB1.Set(pcpKey);
		ciUB2.Set(pucsStr);
		return PLib::Unicode::CompareStringUCD(&ciUB1, &ciUB2, dwFlags, NULL);
	}

	bool LessThan(UCPSTRING* pStr)
	{
		return (Compare(pStr) == CSTR_LESS_THAN);
	}

	bool Match(UCPSTRING* pStr)
	{
		return (Compare(pStr) == CSTR_EQUAL);
	}
};

//----------------------------------------------------------------------
//	GetUnicodePropertyId
//----------------------------------------------------------------------
int GetUnicodePropertyId(UCPSTRING* pucsName);
int GetUnicodePropertyId(const T_UCP* pName, size_t zName);

inline int	GetUnicodePropertyId(const T_UCP* pNameB, const T_UCP* pNameE)
{
	if (pNameB == NULL || pNameB >= pNameE)	return PTEXTEX_UNICODE_PROPERTY_ERROR;
	return GetUnicodePropertyId(pNameB, (size_t)(pNameE - pNameB));
}

//======================================================================
//	テキスト処理関数
//======================================================================
bool	RemoveQuote(T_PCSTR_U*	ppOffB,
					T_PCSTR_U*	ppOffE,
					T_PCSTR_U	pSrcB,
					T_PCSTR_U	pSrcE,
					T_PCSTR_U	pOptB,
					T_PCSTR_U	pOptE);

NS_PLIB_END
