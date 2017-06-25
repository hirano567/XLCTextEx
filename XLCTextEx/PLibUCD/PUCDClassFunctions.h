//	XLCTextEx_1.0x	:	PLibUCD

//	PUCDClassFunctions.h
//
#pragma once

NS_PLIB_UNICODE_BEGIN

//======================================================================
//	General Category Ç…ÇÊÇÈ is ånä÷êî
//======================================================================
bool	IsAlNum_GC(T_UCP cp);
inline bool	IsAlpha_GC(T_UCP cp)	{ return PLib::Unicode::IsAlphabetic(cp); }
bool	IsCntrl_GC(T_UCP cp);
bool	IsDigit_GC(T_UCP cp);
bool	IsGraph_GC(T_UCP cp);
inline bool	IsLower_GC(T_UCP cp)	{ return PLib::Unicode::IsLowercase(cp); }
bool	IsPrint_GC(T_UCP cp);
bool	IsPunct_GC(T_UCP cp);
bool	IsSpace_GC(T_UCP cp);
inline bool	IsUpper_GC(T_UCP cp)	{ return PLib::Unicode::IsUppercase(cp); }

bool	IsWord_GC(T_UCP cp);

//======================================================================
//	ÇªÇÃÇŸÇ©ÇÃ is ä÷êî
//======================================================================
bool	IsDigit(int* piv, T_UCP cp, bool bNormalize);
inline bool	IsDigit(int* piv, T_CHAR_U c, bool bNormalize)
{
	return IsDigit(piv, (T_UCP)c, bNormalize);
}

bool	IsCRLF(T_UCP cp, bool bNormalize);
inline bool	IsCRLF(T_CHAR_U c, bool bNormalize)	{ return IsCRLF((T_UCP)c, bNormalize); }

bool	IsCR(T_UCP cp, bool bNormalize);
inline bool	IsCR(T_CHAR_U c, bool bNormalize)	{ return IsCR((T_UCP)c, bNormalize); }

bool	IsLF(T_UCP cp, bool bNormalize);
inline bool	IsLF(T_CHAR_U c, bool bNormalize)	{ return IsLF((T_UCP)c, bNormalize); }

bool	IsBlank(T_UCP cp, bool bNormalize);
inline bool	IsBlank(T_CHAR_U c, bool bNormalize)	{ return IsBlank((T_UCP)c, bNormalize); }

bool	IsBackslash(T_UCP cp, bool bNormalize);
inline bool	IsBackslash(T_CHAR_U c, bool bNormalize)	{ return IsBackslash((T_UCP)c, bNormalize); }

inline bool	IsEscape(T_UCP cp, bool bNormalize)		{ return IsBackslash(cp, bNormalize); }
inline bool	IsEscape(T_CHAR_U c, bool bNormalize)	{ return IsBackslash((T_UCP)c, bNormalize); }

bool	IsHyphen(T_UCP cp, bool bNormalize);
inline bool	IsHyphen(T_CHAR_U c, bool bNormalize)	{ return IsHyphen((T_UCP)c, bNormalize); }

bool	IsDoubleQuote(T_UCP cp, bool bNormalize);
inline bool	IsDoubleQuote(T_CHAR_U c, bool bNormalize)	{ return IsDoubleQuote((T_UCP)c, bNormalize); }

bool	IsPeriod(T_UCP cp, bool bNormalize);
inline bool	IsPeriod(T_CHAR_U c, bool bNormalize)	{ return IsPeriod((T_UCP)c, bNormalize); }

bool	IsLBracket(T_UCP cp, bool bNormalize);
inline bool	IsLBracket(T_CHAR_U c, bool bNormalize)	{ return IsLBracket((T_UCP)c, bNormalize); }

bool	IsRBracket(T_UCP cp, bool bNormalize);
inline bool	IsRBracket(T_CHAR_U c, bool bNormalize)	{ return IsRBracket((T_UCP)c, bNormalize); }

NS_PLIB_UNICODE_END
