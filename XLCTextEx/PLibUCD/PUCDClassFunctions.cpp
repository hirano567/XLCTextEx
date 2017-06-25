//	XLCTextEx_1.0x	:	PLibUCD

//	PUCDClassFunctions.cpp
//
#include "stdafx.h"

NS_PLIB_UNICODE_BEGIN
//======================================================================
//	General Category による is 系関数
//======================================================================
//----------------------------------------------------------------------
//	IsAlNum_GC
//----------------------------------------------------------------------
bool IsAlNum_GC(T_UCP cp)
{
	return (PLib::Unicode::IsAlpha_GC(cp) || PLib::Unicode::IsDigit_GC(cp));
}

//----------------------------------------------------------------------
//	IsCntrl_GC
//----------------------------------------------------------------------
bool IsCntrl_GC(T_UCP cp)
{
	int	igc;

	if (PLib::Unicode::GetGeneralCategoryValue(&igc, cp))
	{
		return (
				igc == PUCD_GENERAL_CATEGORY_CC_CONTROL
			||	igc == PUCD_GENERAL_CATEGORY_CF_FORMAT
			);
	}
	return false;
}

//----------------------------------------------------------------------
//	IsDigit_GC
//----------------------------------------------------------------------
bool IsDigit_GC(T_UCP cp)
{
	int	igc;

	if (PLib::Unicode::GetGeneralCategoryValue(&igc, cp))
	{
		return (igc == PUCD_GENERAL_CATEGORY_ND_DECIMAL_NUMBER);
	}
	return false;
}

//----------------------------------------------------------------------
//	IsGraph_GC
//----------------------------------------------------------------------
bool IsGraph_GC(T_UCP cp)
{
	int	igc;

	if (PLib::Unicode::GetGeneralCategoryValue(&igc, cp))
	{
		return (
				igc != PUCD_GENERAL_CATEGORY_CC_CONTROL
			&&	igc != PUCD_GENERAL_CATEGORY_CF_FORMAT
			&&	igc != PUCD_GENERAL_CATEGORY_CS_SURROGATE
			&&	igc != PUCD_GENERAL_CATEGORY_CO_PRIVATE_USE
			&&	igc != PUCD_GENERAL_CATEGORY_CN_UNASSIGNED
			&&	igc != PUCD_GENERAL_CATEGORY_C_OTHER
			&&	igc != PUCD_GENERAL_CATEGORY_ZS_SPACE_SEPARATOR
			&&	igc != PUCD_GENERAL_CATEGORY_ZL_LINE_SEPARATOR
			&&	igc != PUCD_GENERAL_CATEGORY_ZP_PARAGRAPH_SEPARATOR
			);
	}
	return false;
}

//----------------------------------------------------------------------
//	IsPrint_GC
//----------------------------------------------------------------------
bool IsPrint_GC(T_UCP cp)
{
	int	igc;

	if (PLib::Unicode::GetGeneralCategoryValue(&igc, cp))
	{
		return (
				igc != PUCD_GENERAL_CATEGORY_CC_CONTROL
			&&	igc != PUCD_GENERAL_CATEGORY_CF_FORMAT
			&&	igc != PUCD_GENERAL_CATEGORY_CS_SURROGATE
			&&	igc != PUCD_GENERAL_CATEGORY_CO_PRIVATE_USE
			&&	igc != PUCD_GENERAL_CATEGORY_CN_UNASSIGNED
			&&	igc != PUCD_GENERAL_CATEGORY_C_OTHER
			);
	}
	return false;
}

//----------------------------------------------------------------------
//	IsPunct_GC
//----------------------------------------------------------------------
bool IsPunct_GC(T_UCP cp)
{
	if (!PLib::Unicode::IsPrint_GC(cp))	return false;
	if (PLib::Unicode::IsSpace_GC(cp))	return false;
	if (PLib::Unicode::IsAlNum_GC(cp))	return false;
	return true;
}

//----------------------------------------------------------------------
//	IsSpace_GC
//----------------------------------------------------------------------
T_UCP	CpSpaceArray[]	=
{
	0x0009,
	0x000A,
	0x000B,
	0x000C,
	0x000D,
	0x0020,
	0x0085,
	0x00A0,
	0x1680,
	0x180E,
	0x2000,
	0x2001,
	0x2002,
	0x2003,
	0x2004,
	0x2005,
	0x2006,
	0x2007,
	0x2008,
	0x2009,
	0x200A,
	0x2028,
	0x2029,
	0x202F,
	0x205F,
	0x3000,
};
const size_t	zCpSpaceArray	= sizeof(CpSpaceArray) / sizeof(T_UCP);
T_UCP			nCpSpaceMin	= CpSpaceArray[0];
T_UCP			nCpSpaceMax	= CpSpaceArray[zCpSpaceArray - 1];

bool IsSpace_GC(T_UCP cp)
{
	UINT	uif;
	if (cp == (T_UCP)0x20 || cp == (T_UCP)0x09)	return true;
	return (PLib::SearchNumSet<T_UCP>(&uif, CpSpaceArray, zCpSpaceArray, nCpSpaceMin, nCpSpaceMax, cp));
}

//----------------------------------------------------------------------
//	IsWord_GC
//
//	Microsoft の定義
//		Ll	Letter, Lowercase
//		Lu	Letter, Uppercase
//		Lt	Letter, Titlecase
//		Lo	Letter, Other
//		Lm	Letter, Modifier
//		Nd	Number, Decimal Digit
//		Pc	Punctuation, Connector. 
//
//	Unicode TR18 の要請 1
//		Alphabetic	(= Lu + Ll + Lt + Lm + Lo + Nl + Other_Alphabetic)
//		Decimal_Number
//		U+200C ZERO WIDTH NON-JOINER and U+200D ZERO WIDTH JOINER (Join_Control=True)
//
//	ここでは Unicode TR18 に Pc を加えたものを word 用の文字とみなすことにする。
//----------------------------------------------------------------------
bool IsWord_GC(T_UCP cp)
{
	int	igc;

	if (PLib::Unicode::IsAlphabetic(cp))	return true;
	if (PLib::Unicode::GetGeneralCategoryValue(&igc, cp))
	{
		return (
				igc == PUCD_GENERAL_CATEGORY_ND_DECIMAL_NUMBER
			||	igc == PUCD_GENERAL_CATEGORY_PC_CONNECTOR_PUNCTUATION
			);
	}
	return false;
}

//======================================================================
//	そのほかの is 関数
//======================================================================
//----------------------------------------------------------------------
//	IsBlank
//----------------------------------------------------------------------
T_UCP	CpBlankArray[]	=
{
	0x0009,
	0x000B,
	0x000C,
	0x0020,
	0x00A0,
	0x1680,
	0x180E,
	0x2000,
	0x2001,
	0x2002,
	0x2003,
	0x2004,
	0x2005,
	0x2006,
	0x2007,
	0x2008,
	0x2009,
	0x200A,
	0x202F,
	0x205F,
	0x3000,
};
const size_t	zCpBlankArray	= sizeof(CpBlankArray) / sizeof(T_UCP);
T_UCP			nCpBlankMin	= CpBlankArray[0];
T_UCP			nCpBlankMax	= CpBlankArray[zCpBlankArray - 1];

bool IsBlank(T_UCP cp, bool bNormalize)
{
	UINT	uif;
	if (cp == (T_UCP)0x20 || cp == (T_UCP)0x09)	return true;
	if (((cp | (T_UCP)0x0F) == (T_UCP)0x0F) && (cp == (T_UCP)0x0B || cp == (T_UCP)0x0C))
		return true;
	return (bNormalize	&&
		PLib::SearchNumSet<T_UCP>(&uif, CpBlankArray, zCpBlankArray, nCpBlankMin, nCpBlankMax, cp));
}

//----------------------------------------------------------------------
//	IsDigit
//----------------------------------------------------------------------
bool IsDigit(int* piv, T_UCP cp, bool bNormalize)
{
	int		ic;
	T_UCP*	pcp;
	int		ncp;

	if (IS_7BIT(cp))
	{
		ic	= C_TO_N_DEC(cp);
		if (ic >= 0)
		{
			*piv	= ic;
			return true;
		}
		return false;
	}
	if (!bNormalize)	return false;

	if (!PLib::Unicode::GetStarter(&pcp, &ncp, cp))	return false;
	if (ncp == 1 && IS_7BIT(*pcp))
	{
		ic	= C_TO_N_DEC(*pcp);
		if (ic >= 0)
		{
			*piv	= ic;
			return true;
		}
	}
	return false;
}

//----------------------------------------------------------------------
//	IsCRLF
//----------------------------------------------------------------------
bool IsCRLF(T_UCP cp, bool bNormalize)
{
	if (cp == (T_UCP)L'\r' || cp == (T_UCP)L'\n')	return true;
	return (bNormalize && (cp == (T_UCP)0x0085 || cp == (T_UCP)0x2029 || cp == (T_UCP)0x2028));
}

//----------------------------------------------------------------------
//	IsCR
//----------------------------------------------------------------------
bool IsCR(T_UCP cp, bool bNormalize)
{
	return (cp == (T_UCP)L'\r');
}

//----------------------------------------------------------------------
//	IsLF
//----------------------------------------------------------------------
bool IsLF(T_UCP cp, bool bNormalize)
{
	if (cp == (T_UCP)L'\n')	return true;
	return (bNormalize && (cp == (T_UCP)0x0085 || cp == (T_UCP)0x2029 || cp == (T_UCP)0x2028));
}

//----------------------------------------------------------------------
//	IsBackslash
//----------------------------------------------------------------------
bool IsBackslash(T_UCP cp, bool bNormalize)
{
	if (cp == (T_UCP)L'\\')	return true;
	return (bNormalize && (cp == (T_UCP)0xFE68 || cp == (T_UCP)0xFF3C));
}

//----------------------------------------------------------------------
//	IsHyphen
//----------------------------------------------------------------------
bool IsHyphen(T_UCP cp, bool bNormalize)
{
	if (cp == (T_UCP)L'-')	return true;
	return (bNormalize && (cp == (T_UCP)0xFE63 || cp == (T_UCP)0xFF0D));
}

//----------------------------------------------------------------------
//	IsDoubleQuote
//----------------------------------------------------------------------
bool IsDoubleQuote(T_UCP cp, bool bNormalize)
{
	if (cp == (T_UCP)L'"')	return true;
	return (bNormalize && cp == (T_UCP)0xFF02);
}

//----------------------------------------------------------------------
//	IsPeriod
//----------------------------------------------------------------------
bool IsPeriod(T_UCP cp, bool bNormalize)
{
	if (cp == (T_UCP)L'.')	return true;
	return (bNormalize && (cp == (T_UCP)0x2024 || cp == (T_UCP)0xFE52 || cp == (T_UCP)0xFF0E));
}

//----------------------------------------------------------------------
//	IsLBracket
//----------------------------------------------------------------------
bool IsLBracket(T_UCP cp, bool bNormalize)
{
	if (cp == (T_UCP)L'[')	return true;
	return (bNormalize && (cp == (T_UCP)0xFE47 || cp == (T_UCP)0xFF3B));
}

//----------------------------------------------------------------------
//	IsRBracket
//----------------------------------------------------------------------
bool IsRBracket(T_UCP cp, bool bNormalize)
{
	if (cp == (T_UCP)L']')	return true;
	return (bNormalize && (cp == (T_UCP)0xFE48 || cp == (T_UCP)0xFF3D));
}

NS_PLIB_UNICODE_END
