//	XLCTextEx_1.0x	:	PLibTextEx

//	PRegExDebug.cpp
//
#include "stdafx.h"

NS_PLIB_BEGIN
#ifdef	PDEBUG

//======================================================================
//	ƒfƒoƒbƒO—pƒf[ƒ^
//======================================================================
//----------------------------------------------------------------------
//	token
//----------------------------------------------------------------------
T_PCSTR_U	PRegExDebug_Token[]	=
{
	TQU("TOKEN_ERROR"),			//	0
	TQU("TOKEN_END"),			//	1
	TQU("TOKEN_CHAR"),			//	2
	TQU("TOKEN_ESCAPE"),		//	3
	TQU("TOKEN_PERIOD"),		//	4
	TQU("TOKEN_CIRCUMFLEX"),	//	5
	TQU("TOKEN_DOLLAR"),		//	6
	TQU("TOKEN_LPARENTHESIS"),	//	7
	TQU("TOKEN_RPARENTHESIS"),	//	8
	TQU("TOKEN_LBRACKET"),		//	9
	TQU("TOKEN_RBRACKET"),		//	10
	TQU("TOKEN_HYPHEN"),		//	11
	TQU("TOKEN_COLON"),			//	12
	TQU("TOKEN_EQUAL"),			//	13
	TQU("TOKEN_ASTERISK"),		//	14
	TQU("TOKEN_PLUS"),			//	15
	TQU("TOKEN_QUESTION"),		//	16
	TQU("TOKEN_LBRACE"),		//	17
	TQU("TOKEN_RBRACE"),		//	18
	TQU("TOKEN_COMMA"),			//	19
	TQU("TOKEN_VERTICALBAR"),	//	20
	TQU("TOKEN_NUMBERSIGN"),	//	21
	TQU("TOKEN_EXCLAMATION"),	//	22
	TQU("TOKEN_LESSTHAN"),		//	23
	TQU("TOKEN_GREATERTHAN"),	//	24
	TQU("TOKEN_AMPERSAND"),		//	25
	TQU("TOKEN_GRAVE"),			//	26
	TQU("TOKEN_APOSTROPHE"),	//	27
	TQU("TOKEN_UNDERSCORE"),	//	28
	TQU("TOKEN_TILDE"),			//	29
	TQU("TOKEN_CR"),			//	30
	TQU("TOKEN_LF"),			//	31
};
const int	nPRegExDebug_Token	= sizeof(PRegExDebug_Token) / sizeof(T_PCSTR_U);

T_PCSTR_U PRegExDebug_GetToken(int iToken)
{
	if (iToken >= 0 && iToken < nPRegExDebug_Token)
	{
		return PRegExDebug_Token[iToken];
	}
	return TQU("(invalid token id)");
}

//----------------------------------------------------------------------
//	POSIX char class
//----------------------------------------------------------------------
T_PCSTR_U	PRegExDebug_PosixCClass[]	=
{
	TQU("error"),		//	0
	TQU("alnum"),		//	1
	TQU("alpha"),		//	2
	TQU("ascii"),		//	3
	TQU("blank"),		//	4
	TQU("cntrl"),		//	5
	TQU("digit"),		//	6
	TQU("graph"),		//	7
	TQU("lower"),		//	8
	TQU("print"),		//	9
	TQU("punct"),		//	10
	TQU("space"),		//	11
	TQU("upper"),		//	12
	TQU("word"),		//	13
	TQU("xdigit"),		//	14
	TQU("nondigit"),	//	15
	TQU("nonspace"),	//	16
	TQU("nonword"),		//	17
};
const int	nPRegExDebug_PosixCClass	= sizeof(PRegExDebug_PosixCClass) / sizeof(T_PCSTR_U);

T_PCSTR_U PRegExDebug_GetPosixCharClass(int iClass)
{
	if (iClass >= 0 && iClass < nPRegExDebug_PosixCClass)
	{
		return PRegExDebug_PosixCClass[iClass];
	}
	return TQU("(invalid token id)");
}

//======================================================================
//	PCRegExOptions
//======================================================================
#define	GET_BOOLEAN_STRING(b)	((b) ? pszTRUE : pszFALSE) 

//-----------------------------------------------------------------
//	PCRegExOptions::DebugFlags
//-----------------------------------------------------------------
void CLASS_PREGEX_OPTIONS::DebugFlags(T_STRING_U* pstrDebug, DWORD dwFlags, bool bFullName)
{
	T_PCSTR_U				pszComma	= TQU(",");
	T_STRING_U	strTemp;

	strTemp.clear();
	if (dwFlags & PREGEX_FLAG_GLOBALMATCHING)
	{
		if (!strTemp.empty())	strTemp.append(pszComma);
		if (bFullName)
		{
			strTemp.append(TQU("GlobalMatching"));
		}
		else
		{
			strTemp.append(TQU("g"));
		}
	}
	if (dwFlags & PREGEX_FLAG_MULTILINEMODE)
	{
		if (!strTemp.empty())	strTemp.append(pszComma);
		if (bFullName)
		{
			strTemp.append(TQU("MultilineMode"));
		}
		else
		{
			strTemp.append(TQU("m"));
		}
	}
	if (dwFlags & PREGEX_FLAG_LEGIBLE_PATTERN)
	{
		if (!strTemp.empty())	strTemp.append(pszComma);
		if (bFullName)
		{
			strTemp.append(TQU("LegiblePattern"));
		}
		else
		{
			strTemp.append(TQU("x"));
		}
	}
	if (dwFlags & PREGEX_FLAG_SINGLELINEMODE)
	{
		if (!strTemp.empty())	strTemp.append(pszComma);
		if (bFullName)
		{
			strTemp.append(TQU("SinglelineMode"));
		}
		else
		{
			strTemp.append(TQU("s"));
		}
	}
	if (dwFlags & PREGEX_FLAG_NORM_IGNORECASE)
	{
		if (!strTemp.empty())	strTemp.append(pszComma);
		if (bFullName)
		{
			strTemp.append(TQU("NormIgnoreCase"));
		}
		else
		{
			strTemp.append(TQU("i"));
		}
	}
	if (dwFlags & PREGEX_FLAG_NORM_IGNORENONSPACE)
	{
		if (!strTemp.empty())	strTemp.append(pszComma);
		if (bFullName)
		{
			strTemp.append(TQU("NormIgnoreNonSpace"));
		}
		else
		{
			strTemp.append(TQU("d"));
		}
	}
	if (dwFlags & PREGEX_FLAG_NORM_IGNOREWIDTH)
	{
		if (!strTemp.empty())	strTemp.append(pszComma);
		if (bFullName)
		{
			strTemp.append(TQU("NormIgnoreWidth"));
		}
		else
		{
			strTemp.append(TQU("w"));
		}
	}
	if (dwFlags & PREGEX_FLAG_NORM_IGNOREKANATYPE)
	{
		if (!strTemp.empty())	strTemp.append(pszComma);
		if (bFullName)
		{
			strTemp.append(TQU("NormIgnoreKanaType"));
		}
		else
		{
			strTemp.append(TQU("k"));
		}
	}

	//	ˆÈ‰º‚Í PCCompareStringUCDOptions

	if (dwFlags & PREGEX_FLAG_CSTRUCD_NORMALIZE)
	{
		if (!strTemp.empty())	strTemp.append(pszComma);
		if (bFullName)
		{
			strTemp.append(TQU("Normalize"));
		}
		else
		{
			strTemp.append(TQU("n"));
		}
	}
	if (dwFlags & PREGEX_FLAG_CSTRUCD_IGNOREKANACASE)
	{
		if (!strTemp.empty())	strTemp.append(pszComma);
		if (bFullName)
		{
			strTemp.append(TQU("IgnoreKanaCase"));
		}
		else
		{
			strTemp.append(TQU("l"));
		}
	}

	/*	ˆÈ‰º‚Í”pŽ~—\’è

	if (dwFlags & PREGEX_FLAG_LINGUISTIC_IGNORECASE)
	{
		if (!strTemp.empty())	strTemp.append(pszComma);
		if (bFullName)
		{
			strTemp.append(TQU("LinguisticIgnoreCase"));
		}
		else
		{
			strTemp.append(TQU("li")));
		}
	}
	if (dwFlags & PREGEX_FLAG_LINGUISTIC_IGNOREDIACRITIC)
	{
		if (!strTemp.empty())	strTemp.append(pszComma);
		if (bFullName)
		{
			strTemp.append(TQU("LinguisticIgnoreDiacritic"));
		}
		else
		{
			strTemp.append(TQU("ld")));
		}
	}
	*/

	pstrDebug->append(strTemp);
}


//----------------------------------------------------------------------
//	PCRegExOptions::Debug
//----------------------------------------------------------------------
void PCRegExOptions::Debug(T_STRING_U* pstrDebug)
{
	T_PCSTR_U	pszBool;
	T_PCSTR_U	pszCRLF		= TQU("\r\n");
	T_PCSTR_U	pszTRUE		= TQU(": ›\r\n");
	T_PCSTR_U	pszFALSE	= TQU(": ~\r\n");

	CCSOPTIONS::Debug(pstrDebug);
	pstrDebug->append(pszCRLF);

	pstrDebug->append(TQU("GlobalMatching  "));
	pszBool	= GET_BOOLEAN_STRING(IsGlobalMatching());
	pstrDebug->append(pszBool);

	pstrDebug->append(TQU("MultilineMode   "));
	pszBool	= GET_BOOLEAN_STRING(IsMultilineMode());
	pstrDebug->append(pszBool);

	pstrDebug->append(TQU("SinglelineMode  "));
	pszBool	= GET_BOOLEAN_STRING(IsSinglelineMode());
	pstrDebug->append(pszBool);

	pstrDebug->append(TQU("LegiblePattern  "));
	pszBool	= GET_BOOLEAN_STRING(IsLegiblePattern());
	pstrDebug->append(pszBool);

	pstrDebug->append(TQU("CollateNormalize"));
	pszBool	= GET_BOOLEAN_STRING(this->IsCollateNormalize());
	pstrDebug->append(pszBool);
}

//----------------------------------------------------------------------
//	PCRegExOptions::DebugSimple
//----------------------------------------------------------------------
void PCRegExOptions::DebugSimple(T_STRING_U* pstrDebug)
{
	T_STRING_U	strTemp;
	bool		br	= false;

	//br	= CCSOPTIONS::DebugSimple(pstrDebug);
	br	= CCSOPTIONS::DebugSimple(&strTemp);

	if (IsGlobalMatching())
	{
		if (!strTemp.empty())	strTemp.append(TQU(","));
		strTemp.append(TQU("g"));
	}

	if (IsMultilineMode())
	{
		if (!strTemp.empty())	strTemp.append(TQU(","));
		strTemp.append(TQU("m"));
	}

	if (IsSinglelineMode())
	{
		if (!strTemp.empty())	strTemp.append(TQU(","));
		strTemp.append(TQU("s"));
	}

	if (IsLegiblePattern())
	{
		if (!strTemp.empty())	strTemp.append(TQU(","));
		strTemp.append(TQU("x"));
	}

	if (!IsCollateNormalize())
	{
		if (!strTemp.empty())	strTemp.append(TQU(","));
		strTemp.append(TQU("-n"));
	}

	//if (br)	pstrDebug->append(TQU(","));
	pstrDebug->append(strTemp);
}


//======================================================================
//	PSBERange::Debug
//======================================================================
void PSBERange::Debug(T_STRING_U* pstrDebug)
{
	T_CHAR_U	Buf[3];
	T_STRING_U	strTemp;

	pstrDebug->append(TQU("First:"));
	switch (this->iTypeF)
	{
	case PREGEX_BE_ELEMENT_CODEPAGE:
		if (PLib::Unicode::ConvertFromCodepoint(Buf, (T_UCP)pRangeF))
		{
			pstrDebug->append(Buf);
		}
		else
		{
			pstrDebug->append(TQU("(error occured)"));
		}
		break;

	case PREGEX_BE_ELEMENT_COLLATING_ELEMENT:
		strTemp.clear();
		if (PLib::Unicode::ConvertFromCodepoint(&strTemp, (UCPSTRING*)pRangeF))
		{
			pstrDebug->append(strTemp);
		}
		else
		{
			pstrDebug->append(TQU("(error occured)"));
		}
		break;

	default:
		pstrDebug->append(TQU("(invalid)"));
		break;
	}

	pstrDebug->append(TQU(",\tLast:"));
	switch (this->iTypeL)
	{
	case PREGEX_BE_ELEMENT_CODEPAGE:
		if (PLib::Unicode::ConvertFromCodepoint(Buf, (T_UCP)pRangeL))
		{
			pstrDebug->append(Buf);
		}
		else
		{
			pstrDebug->append(TQU("(error occured)"));
		}
		break;

	case PREGEX_BE_ELEMENT_COLLATING_ELEMENT:
		strTemp.clear();
		if (PLib::Unicode::ConvertFromCodepoint(&strTemp, (UCPSTRING*)pRangeL))
		{
			pstrDebug->append(strTemp);
		}
		else
		{
			pstrDebug->append(TQU("(error occured)"));
		}
		break;

	default:
		pstrDebug->append(TQU("(invalid)"));
		break;
	}
	pstrDebug->append(TQU("\r\n"));
}

//======================================================================
//	PCBETerm::Debug
//======================================================================
void CLASS_PREGEX_BETERM::Debug(T_STRING_U* pstrDebug)
{
#ifdef	PDEBUG
	ITR_CPSET			itr_cp;
	ITR_RANGELIST		itr_rg;
	ITR_COLLLIST		itr_cl;
	ITR_EQUIVLIST		itr_ec;
	ITR_CCLASSSET		itr_cc;
	ITR_UPROPSET		itr_up;
	ITR_BRACKETEXLIST	itr_be;

	size_t		zi;
	bool		ba;

	int		iMatching;
	int		iValue1;
	bool	bNegative;

	T_CHAR_U	WcBuf[3];
	T_STRING_U	strTemp;
	T_PCSTR_U	pLF			= TQU("\r\n");
	T_PCSTR_U	pfmt_d		= TQU("%d");
	T_PCSTR_U	pfmt_02X	= TQU("0x%02X");
	T_PCSTR_U	pfmt_08X	= TQU("0x%08X");
	T_PCSTR_U	pTrue		= TQU("true");
	T_PCSTR_U	pFalse		= TQU("false");

	/*
	if (bAffirmative)
	{
		pstrDebug->append(TQU("Match when included, "));
	}
	else
	{
		pstrDebug->append(TQU("Match when NOT included, "));
	}
	*/

	if (((pciParentBE->GetBase())->Options())->IsNormIgnoreCase())
	{
		pstrDebug->append(TQU("Not Case-Sensitive"));
	}
	else
	{
		pstrDebug->append(TQU("Case-Sensitive"));
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("Ascii (case sensitive): "));
	if (!ciAsciiBits.none())
	{
		ba	= false;
		for (zi = 0; zi < 128; ++zi)
		{
			if (ciAsciiBits.test(zi))
			{
				if (ba)	pstrDebug->append(TQU(", "));
				if (ISCNTRL_U(zi))
				{
					NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_02X, (int)zi);
				}
				else
				{
					pstrDebug->append(1, (T_CHAR_U)zi);
				}
				ba	= true;
			}
		}
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("Ascii (ignore case)   : "));
	if (!ciAsciiBitsIC.none())
	{
		ba	= false;
		for (zi = 0; zi < 128; ++zi)
		{
			if (ciAsciiBitsIC.test(zi))
			{
				if (ba)	pstrDebug->append(TQU(", "));
				if (ISCNTRL_U(zi))
				{
					NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_02X, (int)zi);
				}
				else
				{
					pstrDebug->append(1, (T_CHAR_U)zi);
				}
				ba	= true;
			}
		}
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("Character             : "));
	if (!ciCpSet.empty())
	{
		for (itr_cp = ciCpSet.begin(); itr_cp != ciCpSet.end(); ++itr_cp)
		{
			if (itr_cp != ciCpSet.begin())	pstrDebug->append(TQU(", "));
			if (!PLib::Unicode::ConvertFromCodepoint(WcBuf, *itr_cp))	THROWPE_RUNTIME_ERROR("PCBETerm::Debug");
			pstrDebug->append(WcBuf);
		}
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("Character Range       : "));
	if (!ciRangeList.empty())
	{
		for (itr_rg = ciRangeList.begin(); itr_rg != ciRangeList.end(); ++itr_rg)
		{
			(*itr_rg)->Debug(pstrDebug);
		}
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("Collating Element     : "));
	if (!ciCollList.empty())
	{
		for (itr_cl = ciCollList.begin(); itr_cl != ciCollList.end(); ++itr_cl)
		{
			if (itr_cl != ciCollList.begin())	pstrDebug->append(TQU(", "));
			strTemp.clear();
			if (PLib::Unicode::ConvertFromCodepoint(&strTemp, *itr_cl))
			{
				pstrDebug->append(strTemp);
			}
			else
			{
				pstrDebug->append(TQU("(error occured)"));
			}
		}
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("Equivalence Set       : "));
	if (!ciEquivList.empty())
	{
		for (itr_ec = ciEquivList.begin(); itr_ec != ciEquivList.end(); ++itr_ec)
		{
			if (itr_ec != ciEquivList.begin())	pstrDebug->append(TQU(", "));
			strTemp.clear();
			if (PLib::Unicode::ConvertFromCodepoint(&strTemp, *itr_ec))
			{
				pstrDebug->append(strTemp);
			}
			else
			{
				pstrDebug->append(TQU("(error occured)"));
			}
		}
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("POSIX Character Class : "));
	if (!ciPOSIXCClasses.empty())
	{
		for (itr_cc = ciPOSIXCClasses.begin(); itr_cc != ciPOSIXCClasses.end(); ++itr_cc)
		{
			if (itr_cc != ciPOSIXCClasses.begin())	pstrDebug->append(TQU(", "));
			pstrDebug->append(PRegExDebug_GetPosixCharClass(*itr_cc));
		}
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("Unicode Property      :"));
	if (!ciUProperties.empty())
	{
		for (itr_up = ciUProperties.begin(); itr_up != ciUProperties.end(); ++itr_up)
		{
			iMatching	= *itr_up;
			bNegative	= IS_PTEXTEX_UNICODE_PROPERTY_NEGATIVE(iMatching);

			switch (GET_PTEXTEX_UNICODE_PROPERTY_TYPE(iMatching))
			{
			case PTEXTEX_UNICODE_PROPERTY_GENERAL_CATEGORY:
				pstrDebug->append(TQU("  General_Category, "));
				iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
				pstrDebug->append(PLib::Unicode::Debug_GetGeneralCategoryValue(iValue1));
				break;

			case PTEXTEX_UNICODE_PROPERTY_SCRIPT:
				pstrDebug->append(TQU("  Script, "));
				iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
				pstrDebug->append(PLib::Unicode::Debug_GetScriptValue(iValue1));
				break;

			case PTEXTEX_UNICODE_PROPERTY_ALPHABETIC:
				pstrDebug->append(TQU("  Alphabetic, "));
				iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
				if (iValue1 != 0)
				{
					pstrDebug->append(pTrue);
				}
				else
				{
					pstrDebug->append(pFalse);
				}
				break;

			case PTEXTEX_UNICODE_PROPERTY_UPPERCASE:
				pstrDebug->append(TQU("  Uppercase, "));
				iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
				if (iValue1 != 0)
				{
					pstrDebug->append(pTrue);
				}
				else
				{
					pstrDebug->append(pFalse);
				}
				break;

			case PTEXTEX_UNICODE_PROPERTY_LOWERCASE:
				pstrDebug->append(TQU("  Lowercase, "));
				iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
				if (iValue1 != 0)
				{
					pstrDebug->append(pTrue);
				}
				else
				{
					pstrDebug->append(pFalse);
				}
				break;

			case PTEXTEX_UNICODE_PROPERTY_WHITE_SPACE:
				pstrDebug->append(TQU("  White_Space, "));
				iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
				if (iValue1 != 0)
				{
					pstrDebug->append(pTrue);
				}
				else
				{
					pstrDebug->append(pFalse);
				}
				break;

			case PTEXTEX_UNICODE_PROPERTY_NONCHARACTER_CODE_POINT:
				pstrDebug->append(TQU("  Noncharacter_Code_Point, "));
				iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
				if (iValue1 != 0)
				{
					pstrDebug->append(pTrue);
				}
				else
				{
					pstrDebug->append(pFalse);
				}
				break;

			case PTEXTEX_UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT:
				pstrDebug->append(TQU("  Default_Ignorable_Code_Point, "));
				iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
				if (iValue1 != 0)
				{
					pstrDebug->append(pTrue);
				}
				else
				{
					pstrDebug->append(pFalse);
				}
				break;

			case PTEXTEX_UNICODE_PROPERTY_NAMED_BLOCK:
				iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
				pstrDebug->append(TQU("  Block, "));
				pstrDebug->append(PLib::Unicode::Debug_GetBlockValue(iValue1));
				break;

			default:
				//THROWPE_LOGICAL_ERROR("");
				break;
			}
			if (IS_PTEXTEX_UNICODE_PROPERTY_NEGATIVE(iMatching))
			{
				pstrDebug->append(TQU("(Negative)"));
			}
			pstrDebug->append(pLF);
		}
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("SubBracketEx          :"));
	if (!ciSubBracketEx.empty())
	{
		ba	= false;
		for (itr_be = ciSubBracketEx.begin(); itr_be != ciSubBracketEx.end(); ++itr_be)
		{
			if (ba)	pstrDebug->append(TQU(", "));
			PLib::AppendNumToString<T_CHAR_U, UINT>(pstrDebug, pfmt_08X, (UINT)(*itr_be));
		}
	}
	pstrDebug->append(pLF);

#else
	pstrDebug->append(TQU("No debug infomation.")));
#endif
}

//======================================================================
//	PCBracketEx::Debug
//======================================================================
void CLASS_PREGEX_BRACKETEX::Debug(T_STRING_U* pstrDebug)
{
	ITR_BETERMLIST	itr_tm;
	T_PCSTR	pf1		= TQU("Max Coll Length = %d\r\n");
	T_PCSTR	pLF		= TQU("\r\n");
	T_PCSTR	pTrue	= TQU("›\r\n");
	T_PCSTR	pFalse	= TQU("~\r\n");

	if (bAffirmative)
	{
		pstrDebug->append(TQU("Affirmative Match\r\n"));
	}
	else
	{
		pstrDebug->append(TQU("Negative Match\r\n"));
	}

	PLib::AppendNumToString<T_CHAR_U, size_t>(pstrDebug, pf1, zMaxColl);
	pstrDebug->append(TQU("Permit MultiCodepoint\t"));
	if (bPermitMultiCp)
	{
		pstrDebug->append(pTrue);
	}
	else
	{
		pstrDebug->append(pFalse);
	}
	pstrDebug->append(pLF);

	for (itr_tm = ciBETermList.begin(); itr_tm != ciBETermList.end(); ++itr_tm)
	{
		switch ((*itr_tm)->GetType())
		{
		case PREGEX_BE_TYPE_NORMAL:
			pstrDebug->append(TQU("Normal BETerm    :\r\n"));
			break;
		case PREGEX_BE_TYPE_OPERATION_UNION:
			pstrDebug->append(TQU("Unicode Operation: Union\r\n"));
			break;
		case PREGEX_BE_TYPE_OPERATION_INTERSECTION:
			pstrDebug->append(TQU("Unicode Operation: Intersection\r\n"));
			break;
		case PREGEX_BE_TYPE_OPERATION_DIFFERENCE:
			pstrDebug->append(TQU("Unicode Operation: Difference\r\n"));
			break;
		case PREGEX_BE_TYPE_OPERATION_SYMMETRIC_DIFFERENCE:
			pstrDebug->append(TQU("Unicode Operation: Symmetric Difference\r\n"));
			break;
		default:
			return;
			break;
		}
		(*itr_tm)->Debug(pstrDebug);
		pstrDebug->append(pLF);
	}
}

//======================================================================
//	PCRegExNode::Debug
//======================================================================
void PCRegExNode::Debug(T_STRING_U* pstrDebug, T_STRING_U* pstrIndentBase)
{
	ITR_NODELIST	itr_nl;
	int				iMatching;
	int				iValue1;
	T_STRING		strIndent1, strIndent2;
	T_CHAR_U		wcBuf[3];
	T_STRING_U		strBuf;

	T_PCSTR_U	pLF			= TQU("\r\n");
	T_PCSTR_U	pfmt_d		= TQU("%d");
	T_PCSTR_U	pfmt_dp		= TQU("(%d)");
	T_PCSTR_U	pfmt_02Xp	= TQU("(%02X)");
	T_PCSTR_U	pfmt_08Xp	= TQU("(0x%08X)");
	T_PCSTR_U	pComma		= TQU(", ");
	T_PCSTR_U	pIndentInc	= TQU("  ");
	T_PCSTR_U	pTrue		= TQU("True");
	T_PCSTR_U	pFalse	= TQU("False");

	strIndent1.assign(*pstrIndentBase);
	strIndent2.assign(strIndent1);
	strIndent2.append(pIndentInc);
	pstrDebug->append(strIndent1);

	pstrDebug->append(TQU("Node["));
	NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)GetNodeIndex());
	pstrDebug->append(TQU("]"));
	NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)this);
	pstrDebug->append(TQU("\t"));

	switch (iNodeType)
	{
	case PREGEX_NODE_ERROR:
		pstrDebug->append(TQU("INVALID"));
		break;

	case PREGEX_NODE_ATOM_CHAR:
		pstrDebug->append(TQU("Atom: Char "));
		if (!PLib::Unicode::ConvertFromCodepoint(wcBuf, GetOptionalCp()))	THROWPE_LOGIC_ERROR("");
		pstrDebug->append(wcBuf);
		break;

	case PREGEX_NODE_ATOM_ANY_CHAR:
		pstrDebug->append(TQU("Atom: Any Char"));
		break;

	case PREGEX_NODE_ATOM_CHAR_UNICODE_PROPERTY:
		pstrDebug->append(TQU("Atom: Unicode Property : "));
		iMatching	= GetOptionalInt();
		iValue1		= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
		switch (GET_PTEXTEX_UNICODE_PROPERTY_TYPE(iMatching))
		{
		case PTEXTEX_UNICODE_PROPERTY_GENERAL_CATEGORY:
			pstrDebug->append(TQU("General_Category, "));
			pstrDebug->append(PLib::Unicode::Debug_GetGeneralCategoryValue(iValue1));
			break;

		case PTEXTEX_UNICODE_PROPERTY_SCRIPT:
			pstrDebug->append(TQU("Script, "));
			pstrDebug->append(PLib::Unicode::Debug_GetScriptValue(iValue1));
			break;

		case PTEXTEX_UNICODE_PROPERTY_ALPHABETIC:
			pstrDebug->append(TQU("Alphabetic, "));
			iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
			if (iValue1 != 0)
			{
				pstrDebug->append(pTrue);
			}
			else
			{
				pstrDebug->append(pFalse);
			}
			break;

		case PTEXTEX_UNICODE_PROPERTY_UPPERCASE:
			pstrDebug->append(TQU("Uppercase, "));
			iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
			if (iValue1 != 0)
			{
				pstrDebug->append(pTrue);
			}
			else
			{
				pstrDebug->append(pFalse);
			}
			break;

		case PTEXTEX_UNICODE_PROPERTY_LOWERCASE:
			pstrDebug->append(TQU("Lowercase, "));
			iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
			if (iValue1 != 0)
			{
				pstrDebug->append(pTrue);
			}
			else
			{
				pstrDebug->append(pFalse);
			}
			break;

		case PTEXTEX_UNICODE_PROPERTY_WHITE_SPACE:
			pstrDebug->append(TQU("White_Space, "));
			iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
			if (iValue1 != 0)
			{
				pstrDebug->append(pTrue);
			}
			else
			{
				pstrDebug->append(pFalse);
			}
			break;

		case PTEXTEX_UNICODE_PROPERTY_NONCHARACTER_CODE_POINT:
			pstrDebug->append(TQU("Noncharacter_Code_Point, "));
			iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
			if (iValue1 != 0)
			{
				pstrDebug->append(pTrue);
			}
			else
			{
				pstrDebug->append(pFalse);
			}
			break;

		case PTEXTEX_UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT:
			pstrDebug->append(TQU("Default_Ignorable_Code_Point, "));
			iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
			if (iValue1 != 0)
			{
				pstrDebug->append(pTrue);
			}
			else
			{
				pstrDebug->append(pFalse);
			}
			break;

		case PTEXTEX_UNICODE_PROPERTY_NAMED_BLOCK:
			pstrDebug->append(TQU("Block, "));
			pstrDebug->append(PLib::Unicode::Debug_GetBlockValue(iValue1));
			break;

		default:
			break;
		}
		if (IS_PTEXTEX_UNICODE_PROPERTY_NEGATIVE(iMatching))
		{
			pstrDebug->append(TQU(" Negative"));
		}
		break;

	case PREGEX_NODE_ATOM_CHAR_DIGIT:
		pstrDebug->append(TQU("Atom: Digit"));
		break;

	case PREGEX_NODE_ATOM_CHAR_NON_DIGIT:
		pstrDebug->append(TQU("Atom: Non-Digit"));
		break;

	case PREGEX_NODE_ATOM_CHAR_WORD:
		pstrDebug->append(TQU("Atom: Word Char"));
		break;

	case PREGEX_NODE_ATOM_CHAR_NON_WORD:
		pstrDebug->append(TQU("Atom: Not Word Char"));
		break;

	case PREGEX_NODE_ATOM_CHAR_SPACE:
		pstrDebug->append(TQU("Atom: Space"));
		break;

	case PREGEX_NODE_ATOM_CHAR_NON_SPACE:
		pstrDebug->append(TQU("Atom: Non-Space"));
		break;

	case PREGEX_NODE_ATOM_WORD_BOUNDARY:
		pstrDebug->append(TQU("Atom: Word Boundary"));
		break;

	case PREGEX_NODE_ATOM_NOT_WORD_BOUNDARY:
		pstrDebug->append(TQU("Atom: Boundary Not Delimit Word"));
		break;

	case PREGEX_NODE_ATOM_LAST_MATCH:
		pstrDebug->append(TQU("Atom: Last Match"));
		break;

	case PREGEX_NODE_ATOM_START_MULTI:
		pstrDebug->append(TQU("Atom: Start Multi"));
		break;

	case PREGEX_NODE_ATOM_END_MULTI:
		pstrDebug->append(TQU("Atom: End Multi"));
		break;

	case PREGEX_NODE_ATOM_START_SINGLE:
		pstrDebug->append(TQU("Atom: Start Single"));
		break;

	case PREGEX_NODE_ATOM_END_SINGLE:
		pstrDebug->append(TQU("Atom: End Single"));
		break;

	case PREGEX_NODE_ATOM_BRACKETEX:
		pstrDebug->append(TQU("Atom: BracketExpression "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)GetOptionalData(0));
		break;

	case PREGEX_NODE_ATOM_REGEX:
		pstrDebug->append(TQU("Atom: SubRegularExpression "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)GetOptionalData(0));
		break;

	case PREGEX_NODE_ATOM_BACKREF:
		pstrDebug->append(TQU("Atom: BackReference["));
		NS_PLIB::AppendNumToString<T_CHAR_U, T_PREGEX_INDEX>(
			pstrDebug, pfmt_d, (int)GetOptionalIndex());
		pstrDebug->append(TQU("]"));
		break;

	case PREGEX_NODE_ATOM_BACKREF_BYNAME:
		strBuf.clear();
		PLib::Unicode::ConvertFromCodepoint(&strBuf, GetOptionalName());
		pstrDebug->append(TQU("Atom: BackReference by Name \""));
		pstrDebug->append(strBuf);
		pstrDebug->append(TQU("\""));
		break;

	case PREGEX_NODE_PIECE_ONE_ATOM:
	case PREGEX_NODE_PIECE_ZERO_OR_MORE:
	case PREGEX_NODE_PIECE_ONE_OR_MORE:
	case PREGEX_NODE_PIECE_ZERO_OR_ONE:
	case PREGEX_NODE_PIECE_BOUND:
	case PREGEX_NODE_PIECE_ZERO_OR_MORE_NG:
	case PREGEX_NODE_PIECE_ONE_OR_MORE_NG:
	case PREGEX_NODE_PIECE_ZERO_OR_ONE_NG:
	case PREGEX_NODE_PIECE_BOUND_NG:
		pstrDebug->append(TQU("Piece: "));
		switch (iNodeType)
		{
		case PREGEX_NODE_PIECE_ZERO_OR_MORE:
			pstrDebug->append(TQU("*"));
			if (iNodeType == PREGEX_NODE_PIECE_ZERO_OR_MORE_NG)
				pstrDebug->append(TQU(" Not Greedy"));
			break;
		case PREGEX_NODE_PIECE_ONE_OR_MORE:
			pstrDebug->append(TQU("+"));
			if (iNodeType == PREGEX_NODE_PIECE_ONE_OR_MORE_NG)
				pstrDebug->append(TQU(" Not Greedy"));
			break;
		case PREGEX_NODE_PIECE_ZERO_OR_ONE:
			pstrDebug->append(TQU("?"));
			if (iNodeType == PREGEX_NODE_PIECE_ZERO_OR_ONE_NG)
				pstrDebug->append(TQU(" Not Greedy"));
			break;
		case PREGEX_NODE_PIECE_BOUND:
			pstrDebug->append(TQU("{"));
			NS_PLIB::AppendNumToString<T_CHAR_U, T_PREGEX_INDEX>(pstrDebug, pfmt_d, GetBoundMin());
			pstrDebug->append(TQU(","));
			NS_PLIB::AppendNumToString<T_CHAR_U, T_PREGEX_INDEX>(pstrDebug, pfmt_d, GetBoundMax());
			pstrDebug->append(TQU("}"));
			if (iNodeType == PREGEX_NODE_PIECE_BOUND_NG)
				pstrDebug->append(TQU(" Not Greedy"));
			break;
		default:
			break;
		}
		if (ciNodeList.empty())
		{
			pstrDebug->append(pLF);
			pstrDebug->append(strIndent2);
			pstrDebug->append(TQU("(Error:No atom)"));
		}
		else
		{
			pstrDebug->append(pLF);
			(*ciNodeList.begin())->Debug(pstrDebug, &strIndent2);
		}
		return;
		break;

	case PREGEX_NODE_BRANCH:
	case PREGEX_NODE_EXPRESSION:
		switch (iNodeType)
		{
		case PREGEX_NODE_BRANCH:
			pstrDebug->append(TQU("Branch:"));
			break;
		case PREGEX_NODE_EXPRESSION:
			pstrDebug->append(TQU("Expression:"));
			break;
		}
		pstrDebug->append(pLF);
		for (itr_nl = ciNodeList.begin(); itr_nl != ciNodeList.end(); ++itr_nl)
		{
			(*itr_nl)->Debug(pstrDebug, &strIndent2);
		}
		return;
		break;

	default:
		break;
	}
	pstrDebug->append(pLF);
}

//======================================================================
//	PCRegExNState::Debug
//======================================================================
void PCRegExNState::Debug(T_STRING_U* pstrDebug)
{
	CNTRANSITION*	ptrCurrent;
	T_INDEX			iTemp;
	CSREGEX*		pSRegEx;
	UCPSTRING*		pName;
	T_STRING_U		strTemp;

	T_PCSTR_U	pfmt_d		= TQU("%d");
	T_PCSTR_U	pfmt_c		= TQU("%c");
	T_PCSTR_U	pfmt_08Xp	= TQU("(0x%08X)");
	T_PCSTR_U	pszIndent1	= TQU("  ");
	T_PCSTR_U	pszIndent2	= TQU("    ");
	T_PCSTR_U	pszComma	= TQU(",");
	T_PCSTR_U	pszLBrace	= TQU("{");
	T_PCSTR_U	pszRBrace	= TQU("}");
	T_PCSTR_U	pszCRLF		= TQU("\r\n");

	pstrDebug->append(pszIndent1);
	switch (iType)
	{
	case PREGEX_NSTATE_TYPE_CTRL_SETOPTIONS:
		pstrDebug->append(TQU("Set Options\r\n"));
		pstrDebug->append(pszIndent2);
		pstrDebug->append(TQU("On : "));
		pciBaseRegEx->Options()->DebugFlags(pstrDebug, (DWORD)pOptional[0], FALSE);
		pstrDebug->append(pszCRLF);
		pstrDebug->append(pszIndent2);
		pstrDebug->append(TQU("Off: "));
		pciBaseRegEx->Options()->DebugFlags(pstrDebug, (DWORD)pOptional[1], FALSE);
		pstrDebug->append(pszCRLF);
		break;

	case PREGEX_NSTATE_TYPE_EX_CAP_BEGIN:
		iTemp	= GetOptionalIndex();
		pstrDebug->append(TQU("SubEx Captured["));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)iTemp);
		pstrDebug->append(TQU("] "));
		if (pciBaseRegEx->GetSRegEx(&pSRegEx, iTemp))
		{
			NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pSRegEx);
		}
		else
		{
			pstrDebug->append(TQU("(Invalid Index)"));
		}
		pstrDebug->append(TQU(" Begin\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_CAP_END:
		iTemp	= GetOptionalIndex();
		pstrDebug->append(TQU("SubEx Captured["));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)iTemp);
		pstrDebug->append(TQU("] "));
		if (pciBaseRegEx->GetSRegEx(&pSRegEx, iTemp))
		{
			NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pSRegEx);
		}
		else
		{
			pstrDebug->append(TQU("(Invalid Index)"));
		}
		pstrDebug->append(TQU(" End\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_CAP_NAMED_BEGIN:
		pName	= GetOptionalName();
		strTemp.clear();
		PLib::Unicode::ConvertFromCodepoint(&strTemp, pName);
		pstrDebug->append(TQU("SubEx Captured Name \""));
		pstrDebug->append(strTemp);
		pstrDebug->append(TQU("\" "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pName);
		pstrDebug->append(TQU(" Begin\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_CAP_NAMED_END:
		pName	= GetOptionalName();
		strTemp.clear();
		PLib::Unicode::ConvertFromCodepoint(&strTemp, pName);
		pstrDebug->append(TQU("SubEx Captured Name \""));
		pstrDebug->append(strTemp);
		pstrDebug->append(TQU("\" "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pName);
		pstrDebug->append(TQU(" End\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_NCAP_BEGIN:
		pSRegEx	= GetOptionalSRegEx();
		pstrDebug->append(TQU("SubEx Not Captured "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pSRegEx);
		pstrDebug->append(TQU(" Begin\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_NCAP_END:
		pSRegEx	= GetOptionalSRegEx();
		pstrDebug->append(TQU("SubEx Not Captured "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pSRegEx);
		pstrDebug->append(TQU(" End\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKAHEAD_BEGIN:
		pstrDebug->append(TQU("SubEx Positive LookAhead"));
		pstrDebug->append(TQU(" Begin\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKAHEAD_END:
		pstrDebug->append(TQU("SubEx Positive LookAhead"));
		pstrDebug->append(TQU(" End\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKAHEAD_BEGIN:
		pstrDebug->append(TQU("SubEx Negative LookAhead"));
		pstrDebug->append(TQU(" Begin\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKAHEAD_END:
		pstrDebug->append(TQU("SubEx Negative LookAhead"));
		pstrDebug->append(TQU(" End\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKBEHIND_BEGIN:
		pstrDebug->append(TQU("SubEx Positive LookBehind "));
		pstrDebug->append(pszLBrace);
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)GetOptionalData(0));
		pstrDebug->append(pszComma);
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)GetOptionalData(1));
		pstrDebug->append(pszRBrace);
		pstrDebug->append(TQU(" Begin\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKBEHIND_END:
		pstrDebug->append(TQU("SubEx Positive LookBehind"));
		pstrDebug->append(TQU(" End\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKBEHIND_BEGIN:
		pstrDebug->append(TQU("SubEx Negative LookBehind "));
		pstrDebug->append(pszLBrace);
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)GetOptionalData(0));
		pstrDebug->append(pszComma);
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)GetOptionalData(1));
		pstrDebug->append(pszRBrace);
		pstrDebug->append(TQU(" Begin\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKBEHIND_END:
		pstrDebug->append(TQU("SubEx Negative LookBehind"));
		pstrDebug->append(TQU(" End\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_INDEPENDENT_BEGIN:
		pSRegEx	= GetOptionalSRegEx();
		pstrDebug->append(TQU("SubEx Independent "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pSRegEx);
		pstrDebug->append(TQU(" Begin\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_INDEPENDENT_END:
		pSRegEx	= GetOptionalSRegEx();
		pstrDebug->append(TQU("SubEx Independent "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pSRegEx);
		pstrDebug->append(TQU(" End\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_SETOPTIONS_BEGIN:
		pSRegEx	= GetOptionalSRegEx();
		pstrDebug->append(TQU("SubEx Set Options "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pSRegEx);
		pstrDebug->append(TQU(" Begin\r\n    On : "));
		pciBaseRegEx->Options()->DebugFlags(pstrDebug, (DWORD)pOptional[0], FALSE);
		pstrDebug->append(TQU("\r\n    Off: "));
		pciBaseRegEx->Options()->DebugFlags(pstrDebug, (DWORD)pOptional[1], FALSE);
		pstrDebug->append(pszCRLF);
		break;

	case PREGEX_NSTATE_TYPE_EX_SETOPTIONS_END:
		pSRegEx	= GetOptionalSRegEx();
		pstrDebug->append(TQU("SubEx Set Options "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pSRegEx);
		pstrDebug->append(TQU(" End\r\n"));
		break;

	case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_INDEX:
		pstrDebug->append(TQU("SubEx Conditional: Index "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)GetOptionalIndex());
		pstrDebug->append(pszCRLF);
		break;

	case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NAME:
		pName	= GetOptionalName();
		strTemp.clear();
		PLib::Unicode::ConvertFromCodepoint(&strTemp, pName);
		pstrDebug->append(TQU("SubEx Conditional: Name \""));
		pstrDebug->append(strTemp);
		pstrDebug->append(TQU("\" "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pName);
		pstrDebug->append(pszCRLF);
		break;

	case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_POSITIVE_LOOKAHEAD:
		pstrDebug->append(TQU("SubEx Conditional: Positive Look Ahead"));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)GetOptionalData(0));
		pstrDebug->append(pszCRLF);
		break;

	case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NEGATIVE_LOOKAHEAD:
		pstrDebug->append(TQU("SubEx Conditional: Negative Look Ahead"));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)GetOptionalData(0));
		pstrDebug->append(pszCRLF);
		break;

	case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_POSITIVE_LOOKBEHIND:
		pstrDebug->append(TQU("SubEx Conditional: Positive Look Behind"));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)GetOptionalData(0));
		pstrDebug->append(pszCRLF);
		break;

	case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NEGATIVE_LOOKBEHIND:
		pstrDebug->append(TQU("SubEx Conditional: Negative Look Behind"));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)GetOptionalData(0));
		pstrDebug->append(pszCRLF);
		break;

	case PREGEX_NSTATE_TYPE_UNUSED:
		pstrDebug->append(TQU("Unused\r\n"));
		break;

	default:
		pstrDebug->append(TQU("Normal\r\n"));
		break;
	}

	for (ptrCurrent = pNTransition; ptrCurrent != NULL; ptrCurrent = ptrCurrent->GetNextTransition())
	{
		pstrDebug->append(pszIndent1);
		ptrCurrent->Debug(pstrDebug);
		pstrDebug->append(pszCRLF);
	}

	pstrDebug->append(pszIndent1);
	pstrDebug->append(TQU("Final St\t: "));
	if (IsFinal())
	{
		pstrDebug->append(TQU("Yes"));
	}
	else
	{
		pstrDebug->append(TQU("No"));
	}
	pstrDebug->append(pszCRLF);
}

//======================================================================
//	PCRegExNTransition::Debug
//======================================================================
void PCRegExNTransition::Debug(T_STRING_U* pstrDebug)
{
	CNSTATE*	pNState;
	UCPSTRING*	pSubStr;
	int			iMatching;
	int			iValue1;
	T_CHAR_U	wcBuf[3];
	T_STRING_U	strTemp;

	T_PCSTR_U	pfmt_d		= TQU("%d");
	T_PCSTR_U	pfmt_c		= TQU("%c");
	T_PCSTR_U	pfmt_08Xp	= TQU("(0x%08X)");
	T_PCSTR_U	pTrue		= TQU("TRUE");
	T_PCSTR_U	pFalse		= TQU("FALSE");

	pstrDebug->append(TQU("Transition"));
	NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)this);
	pstrDebug->append(TQU("\t: "));

	switch (GetMatchingType())
	{
	case PREGEX_TRANSITION_MATCH_EPSILON:
		pstrDebug->append(TQU("Epsilon"));
		break;

	case PREGEX_TRANSITION_MATCH_CHAR:
		pstrDebug->append(TQU("Char, "));
		PLib::Unicode::ConvertFromCodepoint(wcBuf, (T_UCP)GetMatchingValue());
		pstrDebug->append(wcBuf);
		break;

	case PREGEX_TRANSITION_MATCH_ANY_CHAR:
		pstrDebug->append(TQU("Any Char"));
		break;

	case PREGEX_TRANSITION_MATCH_UNICODE_PROPERTY:
		pstrDebug->append(TQU("Unicode Property: "));
		iMatching	= (int)GetMatchingValue();
		iValue1		= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
		switch (GET_PTEXTEX_UNICODE_PROPERTY_TYPE(iMatching))
		{
		case PTEXTEX_UNICODE_PROPERTY_GENERAL_CATEGORY:
			pstrDebug->append(TQU("General_Category, "));
			pstrDebug->append(PLib::Unicode::Debug_GetGeneralCategoryValue(iValue1));
			break;

		case PTEXTEX_UNICODE_PROPERTY_SCRIPT:
			pstrDebug->append(TQU("Script, "));
			pstrDebug->append(PLib::Unicode::Debug_GetScriptValue(iValue1));
			break;

		case PTEXTEX_UNICODE_PROPERTY_ALPHABETIC:
			pstrDebug->append(TQU("Alphabetic, "));
			if (iValue1 != 0)
			{
				pstrDebug->append(pTrue);
			}
			else
			{
				pstrDebug->append(pFalse);
			}
			break;

		case PTEXTEX_UNICODE_PROPERTY_UPPERCASE:
			pstrDebug->append(TQU("Uppercase, "));
			if (iValue1 != 0)
			{
				pstrDebug->append(pTrue);
			}
			else
			{
				pstrDebug->append(pFalse);
			}
			break;

		case PTEXTEX_UNICODE_PROPERTY_LOWERCASE:
			pstrDebug->append(TQU("Lowercase, "));
			if (iValue1 != 0)
			{
				pstrDebug->append(pTrue);
			}
			else
			{
				pstrDebug->append(pFalse);
			}
			break;

		case PTEXTEX_UNICODE_PROPERTY_WHITE_SPACE:
			pstrDebug->append(TQU("White_Space, "));
			if (iValue1 != 0)
			{
				pstrDebug->append(pTrue);
			}
			else
			{
				pstrDebug->append(pFalse);
			}
			break;

		case PTEXTEX_UNICODE_PROPERTY_NONCHARACTER_CODE_POINT:
			pstrDebug->append(TQU("Noncharacter_Code_Point, "));
			if (iValue1 != 0)
			{
				pstrDebug->append(pTrue);
			}
			else
			{
				pstrDebug->append(pFalse);
			}
			break;

		case PTEXTEX_UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT:
			pstrDebug->append(TQU("Default_Ignorable_Code_Point, "));
			if (iValue1 != 0)
			{
				pstrDebug->append(pTrue);
			}
			else
			{
				pstrDebug->append(pFalse);
			}
			break;

		case PTEXTEX_UNICODE_PROPERTY_NAMED_BLOCK:
			pstrDebug->append(TQU("Block, "));
			pstrDebug->append(PLib::Unicode::Debug_GetBlockValue(iValue1));
			break;

		default:
			break;
		}
		if (IS_PTEXTEX_UNICODE_PROPERTY_NEGATIVE(iMatching))
		{
			pstrDebug->append(TQU(" Negative"));
		}
		break;

	case PREGEX_TRANSITION_MATCH_CHAR_DIGIT:
		pstrDebug->append(TQU("Digit"));
		break;

	case PREGEX_TRANSITION_MATCH_CHAR_NON_DIGIT:
		pstrDebug->append(TQU("Non-Digit"));
		break;

	case PREGEX_TRANSITION_MATCH_CHAR_WORD:
		pstrDebug->append(TQU("Word"));
		break;

	case PREGEX_TRANSITION_MATCH_CHAR_NON_WORD:
		pstrDebug->append(TQU("Non-Word"));
		break;

	case PREGEX_TRANSITION_MATCH_CHAR_SPACE:
		pstrDebug->append(TQU("Space"));
		break;

	case PREGEX_TRANSITION_MATCH_CHAR_NON_SPACE:
		pstrDebug->append(TQU("Non-Space"));
		break;

	case PREGEX_TRANSITION_MATCH_WORD_BOUNDARY:
		pstrDebug->append(TQU("Word Boundary"));
		break;

	case PREGEX_TRANSITION_MATCH_NOT_WORD_BOUNDARY:
		pstrDebug->append(TQU("Not Word Boundary"));
		break;

	case PREGEX_TRANSITION_MATCH_LAST_MATCH:
		pstrDebug->append(TQU("Last Match"));
		break;

	case PREGEX_TRANSITION_MATCH_START_MULTI:
		pstrDebug->append(TQU("Start Multi"));
		break;

	case PREGEX_TRANSITION_MATCH_END_MULTI:
		pstrDebug->append(TQU("End Multi"));
		break;

	case PREGEX_TRANSITION_MATCH_START_SINGLE:
		pstrDebug->append(TQU("Start Single"));
		break;

	case PREGEX_TRANSITION_MATCH_END_SINGLE:
		pstrDebug->append(TQU("End Single"));
		break;

	case PREGEX_TRANSITION_MATCH_ENDLF_SINGLE:
		pstrDebug->append(TQU("End Single or Last LF"));
		break;

	case PREGEX_TRANSITION_MATCH_BRACKETEX:
		pstrDebug->append(TQU("BracketEx "));
		AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)GetMatchingValue());
		break;

	case PREGEX_TRANSITION_MATCH_REGEX:
		pstrDebug->append(TQU("SubRegEx "));
		AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)GetMatchingValue());
		break;

	case PREGEX_TRANSITION_MATCH_EX_POSITIVE_LOOKAHEAD:
		pNState	= (CNSTATE*)GetMatchingValue();
		pstrDebug->append(TQU("SubRegEx Positive LookAhead, "));
		AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)pNState->GetStateIndex());
		AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pNState);
		break;

	case PREGEX_TRANSITION_MATCH_EX_NEGATIVE_LOOKAHEAD:
		pNState	= (CNSTATE*)GetMatchingValue();
		pstrDebug->append(TQU("SubRegEx Negative LookAhead, "));
		AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)pNState->GetStateIndex());
		AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pNState);
		break;

	case PREGEX_TRANSITION_MATCH_EX_POSITIVE_LOOKBEHIND:
		pNState	= (CNSTATE*)GetMatchingValue();
		pstrDebug->append(TQU("SubRegEx Positive LookBehind, "));
		AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)pNState->GetStateIndex());
		AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pNState);
		break;

	case PREGEX_TRANSITION_MATCH_EX_NEGATIVE_LOOKBEHIND:
		pNState	= (CNSTATE*)GetMatchingValue();
		pstrDebug->append(TQU("SubRegEx Negative LookBehind, "));
		AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)pNState->GetStateIndex());
		AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pNState);
		break;

	case PREGEX_TRANSITION_MATCH_EX_INDEPENDENT:
		pNState	= (CNSTATE*)GetMatchingValue();
		pstrDebug->append(TQU("SubRegEx Independent, "));
		AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)pNState->GetStateIndex());
		AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pNState);
		break;

	case PREGEX_TRANSITION_MATCH_BACKREF:
		pstrDebug->append(TQU("Back Reference, "));
		AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)this->GetMatchingIndex());
		break;

	case PREGEX_TRANSITION_MATCH_BACKREF_BYNAME:
		pSubStr	= this->GetMatchingName();
		PLib::Unicode::ConvertFromCodepoint(&strTemp, pSubStr);
		pstrDebug->append(TQU("Back Reference by Name \""));
		pstrDebug->append(strTemp);
		pstrDebug->append(TQU("\" "));
		AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pSubStr);
		break;

	default:
		pstrDebug->append(TQU("Undefined"));
		break;
	}

	pstrDebug->append(TQU(" -> "));
	NS_PLIB::AppendNumToString<T_CHAR_U, T_PREGEX_INDEX>(
		pstrDebug, pfmt_d, (int)(GetDestination()->GetStateIndex()));
	NS_PLIB::AppendNumToString<T_CHAR_U, T_PREGEX_INDEX>(
		pstrDebug, pfmt_08Xp, (int)GetDestination());
}

//======================================================================
//	class PCSRegEx::Debug
//======================================================================
void CLASS_SREGEX::Debug(T_STRING_U* pstrDebug)
{
	int			i;
	T_STRING	strIndent;

	T_PCSTR_U	pLF			= TQU("\r\n");
	T_PCSTR_U	pfmt_d		= TQU("%d");
	T_PCSTR_U	pfmt_08Xp	= TQU("(0x%08X)");

	//------------------------------------------------------------
	//	iType
	//------------------------------------------------------------
	pstrDebug->append(TQU("Type: "));
	switch (iType)
	{
	case PREGEX_EX_TYPE_CAP:
		pstrDebug->append(TQU("Captured"));
		break;

	case PREGEX_EX_TYPE_CAP_NAMED:
		pstrDebug->append(TQU("Captured Named"));
		break;

	case PREGEX_EX_TYPE_NCAP:
		pstrDebug->append(TQU("Not Captured"));
		break;

	case PREGEX_EX_TYPE_SETOPTIONS:
		pstrDebug->append(TQU("Set Options (SubRegEx)"));
		break;

	case PREGEX_EX_TYPE_POSITIVE_LOOKAHEAD:
		pstrDebug->append(TQU("Positive Look Ahead"));
		break;

	case PREGEX_EX_TYPE_NEGATIVE_LOOKAHEAD:
		pstrDebug->append(TQU("Negative Look Ahead"));
		break;

	case PREGEX_EX_TYPE_POSITIVE_LOOKBEHIND:
		pstrDebug->append(TQU("Positive Look Behind"));
		break;

	case PREGEX_EX_TYPE_NEGATIVE_LOOKBEHIND:
		pstrDebug->append(TQU("Negative Look Behind"));
		break;

	case PREGEX_EX_TYPE_INDEPENDENT:
		pstrDebug->append(TQU("Independent"));
		break;

	case PREGEX_EX_TYPE_CTRL_SETOPTIONS:
		pstrDebug->append(TQU("Set Options (Control)"));
		break;

	case PREGEX_EX_TYPE_CONDITIONAL_INDEX:
		pstrDebug->append(TQU("Conditional: Index"));
		break;

	case PREGEX_EX_TYPE_CONDITIONAL_NAME:
		pstrDebug->append(TQU("Conditional: Name"));
		break;

	case PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKAHEAD:
		pstrDebug->append(TQU("Conditional: Positive Look Ahead"));
		break;

	case PREGEX_EX_TYPE_CONDITIONAL_NEGATIVE_LOOKAHEAD:
		pstrDebug->append(TQU("Conditional: Negative Look Ahead"));
		break;

	case PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKBEHIND:
		pstrDebug->append(TQU("Conditional: Positive Look Behind"));
		break;

	case PREGEX_EX_TYPE_CONDITIONAL_NEGATIVE_LOOKBEHIND:
		pstrDebug->append(TQU("Conditional: Positive Look Behind"));
		break;

	default:
		break;
	}
	pstrDebug->append(pLF);
	pstrDebug->append(pLF);

	//------------------------------------------------------------
	//	pOptional
	//------------------------------------------------------------
	for (i = 0; i < PREGEX_OPTIONALDATA_NUM; ++i)
	{
		pstrDebug->append(TQU("Optional["));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, i);
		pstrDebug->append(TQU("] = "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)pOptional[i]);
		pstrDebug->append(pLF);
	}
	pstrDebug->append(pLF);

	//------------------------------------------------------------
	//	siNode
	//------------------------------------------------------------
	strIndent.clear();
	pciRootNode->Debug(pstrDebug, &strIndent);
	pstrDebug->append(pLF);
}

//======================================================================
//	PCSRegExNFA::Debug
//======================================================================
void CLASS_PREGEX_SREGEXDFA::Debug(T_STRING_U* pstrDebug)
{
	T_PCSTR_U	pLF			= TQU("\r\n");
	T_PCSTR_U	pfmt_d		= TQU("%d");
	T_PCSTR_U	pfmt_08Xp	= TQU("(0x%08X)");

	pstrDebug->append(TQU("SRegEx    \t: "));
	NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pciSRegEx);
	pstrDebug->append(pLF);
	pstrDebug->append(TQU("NFA Start\t: "));
	NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)iNFAStartIndex);
	NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pciNFAStartState);
	pstrDebug->append(pLF);
	pstrDebug->append(TQU("NFA End  \t: "));
	NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)iNFAEndIndex);
	NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pciNFAEndState);
	pstrDebug->append(pLF);
}

//======================================================================
//	PCRegEx
//======================================================================
/*
//----------------------------------------------------------------------
//	PCRegEx::PSRegExMatchingState::Debug
//----------------------------------------------------------------------
void PSRegExMatchingState::Debug(T_STRING_U* pstrDebug, CRETEXT* pciText)
{
	T_UCP		cpt;

	T_CHAR_U	wcBuf[3];
	T_PCSTR_U	pfmt_d		= TQU("%d");
	T_PCSTR_U	pfmt_dp		= TQU("(%d)");
	T_PCSTR_U	pfmt_02X	= TQU("0x%02X");
	T_PCSTR_U	pfmt_08Xp	= TQU("(0x%08X)");
	T_PCSTR_U	pHT			= TQU("\t");

	if (pciNState != NULL)
	{
		pstrDebug->append(TQU("NFA State["));
		PLib::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)pciNState->GetOptionalIndex());
		pstrDebug->append(TQU("] "));
		PLib::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pciNState);
		pstrDebug->append(TQU("\t:"));
	}
	else
	{
		pstrDebug->append(TQU("NFA State[?] (0x????????)\t:"));
	}

	if (pciText != NULL && !pciText->AtEnd(itrText))
	{
		cpt	= *itrText;
		//PLib::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_dp, (int)(pMcChar->GetOptional()));
		if (PLib::t_IsCntrl<T_UCP>(cpt))
		{
			PLib::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_02X, (int)cpt);
		}
		else
		{
			if (PLib::Unicode::ConvertFromCodepoint(wcBuf, cpt))
			{
				pstrDebug->append(wcBuf);
			}
		}
	}
	else
	{
		pstrDebug->append(TQU("(?)\t?"));
	}
}
*/

//----------------------------------------------------------------------
//	PCRegEx::Debug
//----------------------------------------------------------------------
void PCRegEx::Debug(T_STRING_U* pstrDebug)
{
	CNSTATE*	pNState;
	CNSTATE*	pStartState;
	UINT		uiNStateSize;
	UINT		i;
	T_STRING_U	strTemp;

	CIPSREGEX::ITR_INSTANCELIST		itr_sre;
	CIPSREGEXNFA::ITR_INSTANCELIST	itr_sra;
	CIPBRACKETEX::ITR_INSTANCELIST	itr_be;
	ITR_NAMEDSREGEXMAP				itr_nm;

	T_PCSTR_U	pHR			= TQU("----------------------------------------\r\n");
	T_PCSTR_U	pHRD		= TQU("========================================\r\n");
	T_PCSTR_U	pLF			= TQU("\r\n");
	T_PCSTR_U	pfmt_d		= TQU("%d");
	T_PCSTR_U	pfmt_08Xp	= TQU("(0x%08X)");

	pstrDebug->append(pHRD);
	pstrDebug->append(strPattern);
	pstrDebug->append(pLF);
	pstrDebug->append(pHRD);

	//------------------------------------------------------------
	//	NFA
	//------------------------------------------------------------
	pstrDebug->append(pHR);
	pstrDebug->append(TQU(" NFA\r\n"));
	pstrDebug->append(pHR);
	pstrDebug->append(pLF);

	uiNStateSize	= ciNStateArray.size();
	for (i = 0; i < uiNStateSize; ++i)
	{
		pNState	= ciNStateArray.at(i);
		pstrDebug->append(TQU("NFA State["));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)i);
		pstrDebug->append(TQU("] "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pNState);
		pstrDebug->append(pLF);
		pNState->Debug(pstrDebug);
		pstrDebug->append(pLF);
	}
	pstrDebug->append(TQU("StartState : "));
	pStartState	= ciMainSRegExNFA.GetNFAStartState();
	if (pStartState == NULL)
	{
		pstrDebug->append(TQU("(Undefined)"));
	}
	else
	{
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(
			pstrDebug, pfmt_d, (int)pStartState->GetStateIndex());
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)pStartState);
	}
	pstrDebug->append(pLF);
	pstrDebug->append(pLF);

	//------------------------------------------------------------
	//	Bracket Expression
	//------------------------------------------------------------
	for (ciIPBracketEx.BeginInUse(itr_be); !ciIPBracketEx.EndInUse(itr_be); ++itr_be)
	{
		pstrDebug->append(pHR);
		pstrDebug->append(TQU(" BracketExpression ("));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)(*itr_be));
		pstrDebug->append(TQU(")\r\n"));
		pstrDebug->append(pHR);

		(*itr_be)->Debug(pstrDebug);
		pstrDebug->append(pLF);
	}

	//------------------------------------------------------------
	//	SRegExDFA
	//------------------------------------------------------------
	for (ciIPSRegExDFA.BeginInUse(itr_sra); !ciIPSRegExDFA.EndInUse(itr_sra); ++itr_sra)
	{
		pstrDebug->append(pLF);
		pstrDebug->append(pHR);
		pstrDebug->append(TQU(" SubRegularExpression DFA ("));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)(*itr_sra));
		pstrDebug->append(TQU(")\r\n"));
		pstrDebug->append(pHR);

		(*itr_sra)->Debug(pstrDebug);
	}
	pstrDebug->append(pLF);

	//------------------------------------------------------------
	//	SRegEx
	//------------------------------------------------------------
	pstrDebug->append(pLF);
	pstrDebug->append(pHR);
	pstrDebug->append(TQU(" Main SubRegularExpression ("));
	NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)(&ciMainSRegEx));
	pstrDebug->append(TQU(")\r\n"));
	pstrDebug->append(pHR);

	ciMainSRegEx.Debug(pstrDebug);

	for (ciIPSRegEx.BeginInUse(itr_sre); !ciIPSRegEx.EndInUse(itr_sre); ++itr_sre)
	{
		pstrDebug->append(pLF);
		pstrDebug->append(pHR);
		pstrDebug->append(TQU(" SubRegularExpression ("));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)(*itr_sre));
		pstrDebug->append(TQU(")\r\n"));
		pstrDebug->append(pHR);

		(*itr_sre)->Debug(pstrDebug);
	}
	pstrDebug->append(pLF);

	pstrDebug->append(pHR);
	pstrDebug->append(TQU(" Captured SubRegularExpressions\r\n"));
	pstrDebug->append(pHR);
	for (i = 0; i < ciCaptureArray.size(); ++i)
	{
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)i);
		pstrDebug->append(TQU("\t: "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)(ciCaptureArray.at(i)));
		pstrDebug->append(TQU("\r\n"));
	}
	pstrDebug->append(pLF);

	pstrDebug->append(pHR);
	pstrDebug->append(TQU(" Named SubRegularExpressions\r\n"));
	pstrDebug->append(pHR);
	for (itr_nm = ciNamedSRegExMap.begin(); itr_nm != ciNamedSRegExMap.end(); ++itr_nm)
	{
		strTemp.clear();
		PLib::Unicode::ConvertFromCodepoint(&strTemp, itr_nm->first);
		pstrDebug->append(strTemp);
		pstrDebug->append(TQU("\t: "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_08Xp, (int)itr_nm->second);
		pstrDebug->append(TQU("\r\n"));
	}
	pstrDebug->append(pLF);
}

/*
//----------------------------------------------------------------------
//	PCRegExMatchingHistory::Debug
//----------------------------------------------------------------------
void PCRegExMatchingHistory::Debug(T_STRING_U* pstrDebug, CRETEXT* pciText)
{
	PSRegExMatchingState*	pMState;
	CNSTATE*		pNState;
	ITR_UCPSTRING	itrText;

	T_PCSTR_U		pfmt_d	= TQU("%d");
	T_PCSTR_U		pLF	= TQU("\r\n");

	//for (itrPath = ciHistory.rbegin(); itrPath != ciHistory.rend(); ++itrPath)
	for (ciHistory.RBegin(); !ciHistory.REnd(); ciHistory.RNext())
	{
		if (!ciHistory.RGetCurrent(&pMState))	continue;
		//pNState	= (*itrPath)->pciNState;
		pNState	= pMState->pciNState;
		NS_PLIB::AppendNumToString<T_CHAR_U, T_PREGEX_INDEX>(
			pstrDebug, pfmt_d, pNState->GetStateIndex());
		pstrDebug->append(TQU("\t: "));
		//pciText	= (*itrPath)->pciText;
		//itrText	= (*itrPath)->itrText;
		//pciText	= pMState->pciText;
		itrText	= pMState->itrText;
		if (!pciText->AtEnd(itrText))
		{
			pciText->GetSubStringFollowing(pstrDebug, itrText);
		}
		switch (pNState->GetType())
		{
		case PREGEX_NSTATE_TYPE_EX_CAP_BEGIN:
			pstrDebug->append(TQU(", Enter SubRegEx["));
			NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)pNState->GetOptionalData(0));
			pstrDebug->append(TQU("]"));
			break;
		case PREGEX_NSTATE_TYPE_EX_CAP_END:
			pstrDebug->append(TQU(", Exit SubRegEx["));
			NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)pNState->GetOptionalData(0));
			pstrDebug->append(TQU("]"));
			break;

		case PREGEX_NSTATE_TYPE_EX_CAP_NAMED_BEGIN:
			pstrDebug->append(TQU(", Enter SubRegEx Named["));
			NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)pNState->GetOptionalData(0));
			pstrDebug->append(TQU("]"));
			break;

		case PREGEX_NSTATE_TYPE_EX_CAP_NAMED_END:
			pstrDebug->append(TQU(", End SubRegEx Named["));
			NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_d, (int)pNState->GetOptionalData(0));
			pstrDebug->append(TQU("]"));
			break;
		}
		pstrDebug->append(pLF);
	}
}
*/
/*
//======================================================================
//	Profile
//======================================================================
#ifdef	PDEBUG_PROFILE

PLib::Debug::PCTickCounters	ciRegExProfiler;

size_t PRegExProfiler_Size()
{
	return ciRegExProfiler.Size();
}

void PRegExProfiler_Reset()
{
	ciRegExProfiler.Reset();
}

void PRegExProfiler_Reset(UINT i)
{
	ciRegExProfiler.Reset(i);
}

void PRegExProfiler_Start(UINT i)
{
	ciRegExProfiler.Start(i);
}

void PRegExProfiler_Stop(UINT i)
{
	ciRegExProfiler.Stop(i);
}

DWORD PRegExProfiler_GetInterval(UINT i)
{
	return ciRegExProfiler.GetInterval(i);
}

DWORD PRegExProfiler_GetTotal(UINT i)
{
	return ciRegExProfiler.GetTotal(i);
}

#endif
*/
#endif
NS_PLIB_END

