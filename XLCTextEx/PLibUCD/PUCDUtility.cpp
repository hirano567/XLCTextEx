//	XLCTextEx_1.0x	:	PLibUCD

//	PUCDUtility.cpp
//
#include "stdafx.h"

NS_PLIB_UNICODE_BEGIN

/*
//======================================================================
//	is 系の関数とそれらに関連する関数
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
*/

//======================================================================
//	エスケープシーケンスをデコードする関数
//======================================================================
struct PSControlChar
{
	LPCWSTR	pszChar;
	int		iCode;

	LPCWSTR GetChar()	{ return pszChar; }
};

PSControlChar	siEscapedCntrl[]	=
{
	TQU("a"),	7,
	TQU("b"),	8,
	TQU("c"),	-1,
	TQU("d"),	-1,
	TQU("e"),	27,
	TQU("f"),	12,
	TQU("g"),	-1,
	TQU("h"),	-1,
	TQU("i"),	-1,
	TQU("j"),	-1,
	TQU("k"),	-1,
	TQU("l"),	-1,
	TQU("m"),	-1,
	TQU("n"),	10,
	TQU("o"),	-1,
	TQU("p"),	-1,
	TQU("q"),	-1,
	TQU("r"),	13,
	TQU("s"),	-1,
	TQU("t"),	9,
	TQU("u"),	-1,
	TQU("v"),	11,
};
int	nEscapedCntrls	= sizeof(siEscapedCntrl) / sizeof(PSControlChar);

//----------------------------------------------------------------------
//	DecodeEscapedControl
//----------------------------------------------------------------------
bool DecodeEscapedControl(T_UCP* pcpDst, T_UCP cpSrc, DWORD dwFlags, T_PCSTR_U pszLocale)
{
	//T_UCP	cpt;
	T_UCP*	pcp;
	int		ncp;
	int		i;

	if (COMPARESTRING_IS_NORM_IGNORENONSPACE(dwFlags) || COMPARESTRING_IS_NORM_IGNOREWIDTH(dwFlags))
	{
		if (PLib::Unicode::GetStarter(&pcp, &ncp, cpSrc) && ncp == 1)
		{
			cpSrc	= *pcp;
		}
	}

	if (cpSrc >= (T_UCP)TQU('a') && cpSrc <= (T_UCP)TQU('v'))
	{
		cpSrc	-= (T_UCP)TQU('a');
		i	= siEscapedCntrl[cpSrc].iCode;
		if (i >= 0)
		{
			*pcpDst	= (T_UCP)i;
			return true;
		}
	}
	return false;
}

//======================================================================
//	DecodeControlChar
//
//	コントロール文字 0x00 から 0x1F および 0x7F を \c@ から \c_ および \c? で表す。
//======================================================================
bool DecodeControlChar(UINT* puiDst, UINT uiSrc, DWORD dwFlags, LPCWSTR pszLocale)
{
	T_UCP*	pcp;
	int		ncp;

	if ((COMPARESTRING_IS_NORM_IGNOREWIDTH(dwFlags) || COMPARESTRINGUCD_IS_NORMALIZE(dwFlags)) &&
		(uiSrc >= (UINT)0x7F))
	{
		if (!GetStarter(&pcp, &ncp, uiSrc))	return false;
		if (ncp != 1)	return false;
		uiSrc	= *pcp;
	}

	if ((uiSrc <= (UINT)0x20) || (uiSrc >= (UINT)0x7F))	return false;

	if (uiSrc >= (UINT)0x61 && uiSrc <= (UINT)0x7A)	// a から z は　0x01 から 0x1A に変換する。
	{
		*puiDst	= uiSrc - (UINT)0x60;
	}
	else if (uiSrc >= (UINT)0x40)
	{
		*puiDst	= uiSrc - (UINT)0x40;
	}
	else
	{
		*puiDst	= uiSrc + (UINT)0x40;
	}
	return true;
}


//======================================================================
//	AppendCodepointToString
//======================================================================
bool AppendCodepointToString(T_STRING_U* pstrBuffer, T_UCP cpSrc)
{
	T_CHAR_U	WCBuf[3];

	T_PCSTR_U	pfmt_04X	= TQU("%04X");
	T_PCSTR_U	pfmt_04Xps	= TQU("(%04X) ");
	T_PCSTR_U	pComma		= TQU(",");

	PLib::AppendNumToString<T_CHAR_U, T_UCP>(pstrBuffer, pfmt_04Xps, cpSrc);
	if (PLib::Unicode::ConvertFromCodepoint(WCBuf, cpSrc))
	{
		if (ISCNTRL_U(WCBuf[0]))
		{
			PLib::AppendNumToString<T_CHAR_U, T_UCP>(pstrBuffer, pfmt_04X, (T_UCP)WCBuf[0]);
		}
		else
		{
			pstrBuffer->append(WCBuf);
		}
	}
	else
	{
		pstrBuffer->append(TQU("??"));
	}

	return true;
}

NS_PLIB_UNICODE_END
