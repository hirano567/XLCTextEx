//	XLCTextEx_1.0x	:	PLibTextEx

//	PRegExUtility.cpp
//
#include "stdafx.h"


NS_PLIB_REGEX_BEGIN

//======================================================================
//	Token ID �̎擾
//======================================================================
struct PSTOKENCHAR
{
	UINT	uiCp;
	int		iTokenId;

	bool LessThan(UINT uiCmp)		{ return (uiCp < uiCmp); }
	bool GreaterThan(UINT uiCmp)	{ return (uiCp > uiCmp); }
	bool Match(UINT uiCmp)			{ return (uiCp == uiCmp); }
};

PSTOKENCHAR	siTokenChar[]	=
{
	0x000A,	PREGEX_TOKEN_LF,
	0x000D,	PREGEX_TOKEN_CR,
	0x0021,	PREGEX_TOKEN_EXCLAMATION,	//	'!'
	0x0023,	PREGEX_TOKEN_NUMBERSIGN,	//	'#'
	0x0024,	PREGEX_TOKEN_DOLLAR,		//	'$'
	0x0026,	PREGEX_TOKEN_AMPERSAND,		//	'&'
	0x0027,	PREGEX_TOKEN_APOSTROPHE,	//	'''
	0x0028,	PREGEX_TOKEN_LPARENTHESIS,	//	'('
	0x0029,	PREGEX_TOKEN_RPARENTHESIS,	//	')'
	0x002A,	PREGEX_TOKEN_ASTERISK,		//	'*'
	0x002B,	PREGEX_TOKEN_PLUS,			//	'+'
	0x002C,	PREGEX_TOKEN_COMMA,			//	','
	0x002D,	PREGEX_TOKEN_HYPHEN,		//	'-'
	0x002E,	PREGEX_TOKEN_PERIOD,		//	'.'
	0x003A,	PREGEX_TOKEN_COLON,			//	':'
	0x003C,	PREGEX_TOKEN_LESSTHAN,		//	'<'
	0x003D,	PREGEX_TOKEN_EQUAL,			//	'='
	0x003E,	PREGEX_TOKEN_GREATERTHAN,	//	'>'
	0x003F,	PREGEX_TOKEN_QUESTION,		//	'?'
	0x005B,	PREGEX_TOKEN_LBRACKET,		//	'['
	0x005C,	PREGEX_TOKEN_ESCAPE,		//	'\'
	0x005D,	PREGEX_TOKEN_RBRACKET,		//	']'
	0x005E,	PREGEX_TOKEN_CIRCUMFLEX,	//	'^'
	0x005F,	PREGEX_TOKEN_UNDERSCORE,	//	'_'
	0x0060,	PREGEX_TOKEN_GRAVE,			//	'`'
	0x007B,	PREGEX_TOKEN_LBRACE,		//	'{'
	0x007C,	PREGEX_TOKEN_VERTICALBAR,	//	'|'
	0x007D,	PREGEX_TOKEN_RBRACE,		//	'}'
	0x007E,	PREGEX_TOKEN_TILDE,			//	'~'
	0x0085,	PREGEX_TOKEN_LF,			//	NEXT LINE (NEL)
	0x2028,	PREGEX_TOKEN_LF,			//	LINE SEPARATOR
	0x2029,	PREGEX_TOKEN_LF,			//	PARAGRAPH SEPARATOR
};
const int	nTokenChars	= sizeof(siTokenChar) / sizeof(PSTOKENCHAR);

//----------------------------------------------------------------------
//	GetTokenId
//	�w�肳�ꂽ�R�[�h�y�[�W���L�����ǂ����̓`�F�b�N���Ȃ��B
//----------------------------------------------------------------------
int GetTokenId(T_UCP cpSrc, DWORD dwFlags, T_PCSTR_U pszLocale)
{
	UINT	uiFound;
	T_UCP*	pcp;
	int		ncp;

	if (PLib::BinarySearch<PSTOKENCHAR, UINT>(
		&uiFound, siTokenChar, nTokenChars, cpSrc))
	{
		return siTokenChar[uiFound].iTokenId;
	}

	if (!COMPARESTRING_IS_NORM_IGNOREWIDTH(dwFlags) &&
		!COMPARESTRING_IS_NORM_IGNORENONSPACE(dwFlags))	return PREGEX_TOKEN_CODEPAGE;
	if (PUCD_BMPTABLE_NOT_DECOMP_SET(cpSrc))	return PREGEX_TOKEN_CODEPAGE;
	if (!PLib::Unicode::GetStarter(&pcp, &ncp, cpSrc))	return PREGEX_TOKEN_CODEPAGE;
	if (ncp != 1)	return PREGEX_TOKEN_CODEPAGE;

	if (PLib::BinarySearch<PSTOKENCHAR, UINT>(
		&uiFound, siTokenChar, nTokenChars, *pcp))
	{
		return siTokenChar[uiFound].iTokenId;
	}
	return PREGEX_TOKEN_CODEPAGE;
}

//======================================================================
//	PCTextUR �f�R�[�h�p�̊֐�
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
	TQU("b"),	-1,	//	���K�\���ɂ����� \b �̓o�b�N�X�y�[�X�ł͂Ȃ��P�ꋫ�E��\���̂ŏ��O����B
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

NS_PLIB_REGEX_END

NS_PLIB_BEGIN

//======================================================================
//	PRegExOptions_StrToDWord
//
//	�������
//		[gmsxidwk(li)(ld)]*-[gmsidwk(li)(ld)]*	�i�p�~�j
//		[gmsxidwkl]*-[gmsidwkl]*
//	�̌`���ł���Ɖ��肵�ĉ�͂���B
//	- �ȑO�̃t���O��ݒ肵�A�ȍ~�̃t���O����������
//	�A���t�@�x�b�g�A�󔒕����A�n�C�t���ȊO�̕��������ꂽ��I������B
//======================================================================
void PRegExOptions_StrToDWord(DWORD* pdwOn, DWORD* pdwOff, PITextUR* pciText)
{
	DWORD	dwCSFlags	= NORM_IGNOREWIDTH;
	bool	bUnsetFlag	= false;

	T_UCP	cpc;

#ifdef	PDEBUG
	T_STRING_U	strDebug;
#endif

	if (pdwOn == NULL || pdwOff == NULL)	THROWPE_LOGIC_ERROR("PRegExOptions_StrToDWord");
	*pdwOn	= 0;
	*pdwOff	= 0;
	if (pciText == NULL)	return;

	for ( ; !pciText->End(); pciText->Next())
	{
		if (!PCTEXT_GETVALIDCP(pciText->GetCurrentCp(&cpc)))	break;
		if (PLib::Unicode::CompareCodepointUCD(cpc, (T_UCP)TQU('g'), dwCSFlags, NULL) == CSTR_EQUAL)
		{
			if (bUnsetFlag == true)
			{
				*pdwOff	|= PREGEX_FLAG_GLOBALMATCHING;
			}
			else
			{
				*pdwOn	|= PREGEX_FLAG_GLOBALMATCHING;
			}
			continue;
		}
		else if (PLib::Unicode::CompareCodepointUCD(cpc, (T_UCP)TQU('m'), dwCSFlags, NULL) == CSTR_EQUAL)
		{
			if (bUnsetFlag == true)
			{
				*pdwOff	|= PREGEX_FLAG_MULTILINEMODE;
			}
			else
			{
				*pdwOn	|= PREGEX_FLAG_MULTILINEMODE;
			}
			continue;
		}
		else if (PLib::Unicode::CompareCodepointUCD(cpc, (T_UCP)TQU('s'), dwCSFlags, NULL) == CSTR_EQUAL)
		{
			if (bUnsetFlag == true)
			{
				*pdwOff	|= PREGEX_FLAG_SINGLELINEMODE;
			}
			else
			{
				*pdwOn	|= PREGEX_FLAG_SINGLELINEMODE;
			}
			continue;
		}
		else if (PLib::Unicode::CompareCodepointUCD(cpc, (T_UCP)TQU('x'), dwCSFlags, NULL) == CSTR_EQUAL)
		{
			if (bUnsetFlag == true)
			{
				*pdwOff	|= PREGEX_FLAG_LEGIBLE_PATTERN;
			}
			else
			{
				*pdwOn	|= PREGEX_FLAG_LEGIBLE_PATTERN;
			}
			continue;
		}
		else if (PLib::Unicode::CompareCodepointUCD(cpc, (T_UCP)TQU('i'), dwCSFlags, NULL) == CSTR_EQUAL)
		{
			if (bUnsetFlag == true)
			{
				*pdwOff	|= PREGEX_FLAG_NORM_IGNORECASE;
			}
			else
			{
				*pdwOn	|= PREGEX_FLAG_NORM_IGNORECASE;
			}
			continue;
		}
		else if (PLib::Unicode::CompareCodepointUCD(cpc, (T_UCP)TQU('d'), dwCSFlags, NULL) == CSTR_EQUAL)
		{
			if (bUnsetFlag == true)
			{
				*pdwOff	|= PREGEX_FLAG_NORM_IGNORENONSPACE;
			}
			else
			{
				*pdwOn	|= PREGEX_FLAG_NORM_IGNORENONSPACE;
			}
			continue;
		}
		else if (PLib::Unicode::CompareCodepointUCD(cpc, (T_UCP)TQU('w'), dwCSFlags, NULL) == CSTR_EQUAL)
		{
			if (bUnsetFlag == true)
			{
				*pdwOff	|= PREGEX_FLAG_NORM_IGNOREWIDTH;
			}
			else
			{
				*pdwOn	|= PREGEX_FLAG_NORM_IGNOREWIDTH;
			}
			continue;
		}
		else if (PLib::Unicode::CompareCodepointUCD(cpc, (T_UCP)TQU('k'), dwCSFlags, NULL) == CSTR_EQUAL)
		{
			if (bUnsetFlag == true)
			{
				*pdwOff	|= PREGEX_FLAG_NORM_IGNOREKANATYPE;
			}
			else
			{
				*pdwOn	|= PREGEX_FLAG_NORM_IGNOREKANATYPE;
			}
			continue;
		}
		else if (PLib::Unicode::CompareCodepointUCD(cpc, (T_UCP)TQU('n'), dwCSFlags, NULL) == CSTR_EQUAL)
		{
			if (bUnsetFlag == true)
			{
				*pdwOff	|= PREGEX_FLAG_CSTRUCD_NORMALIZE;
			}
			else
			{
				*pdwOn	|= PREGEX_FLAG_CSTRUCD_NORMALIZE;
			}
			continue;
		}
		else if (PLib::Unicode::CompareCodepointUCD(cpc, (T_UCP)TQU('l'), dwCSFlags, NULL) == CSTR_EQUAL)
		{
			if (bUnsetFlag == true)
			{
				*pdwOff	|= PREGEX_FLAG_CSTRUCD_IGNOREKANACASE;
			}
			else
			{
				*pdwOn	|= PREGEX_FLAG_CSTRUCD_IGNOREKANACASE;
			}
			continue;
		}
		else if (PLib::Unicode::CompareCodepointUCD(cpc, (T_UCP)TQU('-'), dwCSFlags, NULL) == CSTR_EQUAL)
		{
			bUnsetFlag = true;
			continue;
		}
		//--------------------------------------------------
		//	�����ł͐ݒ肵�Ȃ��I�v�V�����Ɠǂݔ�΂�����
		//--------------------------------------------------
		else if (PLib::Unicode::IsDoubleQuote(cpc, true))
		{
			continue;
		}
		else if (PLib::Unicode::CompareCodepointUCD(cpc, (T_UCP)TQU('q'), dwCSFlags, NULL) == CSTR_EQUAL)
		{
			continue;
		}
		//--------------------------------------------------
		//	�ȏ�ɓ��Ă͂܂�Ȃ����������ꂽ��I������B
		//--------------------------------------------------
		else
		{
			break;
		}
	}
	return;
}


//======================================================================
//	class PCRegExOptions
//
//	�}�b�`�������̂��ׂĂ�u������B	g	(1 << 0)
//	�}���`���C�����[�h					m	(1 << 1)	�Ώۃe�L�X�g�� \r\n �ŋ�؂��Ă���Ƃ���B
//	�V���O�����C�����[�h				s	(1 << 2)	. �� \r\n �ɂ��}�b�`����B
//	�󔒂𖳎����A# ���R�����g�Ƃ���B	x	(1 << 3)
//	�啶������������ʂ��Ȃ��B			i	(1 << 4)	NORM_IGNORECASE
//	�t���L�����̗L������ʂ��Ȃ��B		d	(1 << 5)	NORM_IGNORENONSPACE
//	�S�p�A���p����ʂ��Ȃ��B			w	(1 << 6)	NORM_IGNOREWIDTH
//	�Ђ炪�ȁA�J�^�J�i����ʂ��Ȃ��B	k	(1 << 7)	NORM_IGNOREKANATYPE
//	���ȏ���������ʂ��Ȃ��B			l	(1 << 8)	CSTRUCD_IGNOREKANACASE
//
//	�i�ȉ��͔p�~�\��j
//
//	�啶������������ʂ��Ȃ��B			li	(1 << 9)	LINGUISTIC_IGNORECASE
//	�t���L�����̗L������ʂ��Ȃ��B		ld	(1 << 10)	LINGUISTIC_IGNOREDIACRITIC
//======================================================================
//-----------------------------------------------------------------
//	PCRegExOptions::Set(�r�b�g�Z�b�g��\�������l)
//
//	���ݐݒ肵�Ă���t���O�ɒǉ�����B
//	�ŏ�����Z�b�g�������ꍇ�́A��� Reset() ���ĂԂ��ƁB
//-----------------------------------------------------------------
void CLASS_PREGEX_OPTIONS::Set(DWORD dwFlags)
{
	if (dwFlags & PREGEX_FLAG_GLOBALMATCHING)				SetGlobalMatching();
	if (dwFlags & PREGEX_FLAG_MULTILINEMODE)				SetMultilineMode();
	if (dwFlags & PREGEX_FLAG_SINGLELINEMODE)				SetSinglelineMode();
	if (dwFlags & PREGEX_FLAG_LEGIBLE_PATTERN)				SetLegiblePattern();
	if (dwFlags & PREGEX_FLAG_NORM_IGNORECASE)				SetNormIgnoreCase();
	if (dwFlags & PREGEX_FLAG_NORM_IGNORENONSPACE)			SetNormIgnoreNonSpace();
	if (dwFlags & PREGEX_FLAG_NORM_IGNOREWIDTH)				SetNormIgnoreWidth();
	if (dwFlags & PREGEX_FLAG_NORM_IGNOREKANATYPE)			SetNormIgnoreKanaType();
	if (dwFlags & PREGEX_FLAG_CSTRUCD_NORMALIZE)
	{
		SetNormalize();
		SetCollateNormalize();
	}
	if (dwFlags & PREGEX_FLAG_CSTRUCD_IGNOREKANACASE)		SetIgnoreKanaCase();

	//	�ȉ��͔p�~�\��

	if (dwFlags & PREGEX_FLAG_LINGUISTIC_IGNORECASE)		SetLinguisticIgnoreCase();
	if (dwFlags & PREGEX_FLAG_LINGUISTIC_IGNOREDIACRITIC)	SetLinguisticIgnoreDiacritic();
}

//-----------------------------------------------------------------
//	PCRegExOptions::Unset(�r�b�g�Z�b�g��\�������l)
//	
//-----------------------------------------------------------------
void CLASS_PREGEX_OPTIONS::Unset(DWORD dwFlags)
{
	if (dwFlags & PREGEX_FLAG_GLOBALMATCHING)				UnsetGlobalMatching();
	if (dwFlags & PREGEX_FLAG_MULTILINEMODE)				UnsetMultilineMode();
	if (dwFlags & PREGEX_FLAG_SINGLELINEMODE)				UnsetSinglelineMode();
	if (dwFlags & PREGEX_FLAG_LEGIBLE_PATTERN)				UnsetLegiblePattern();
	if (dwFlags & PREGEX_FLAG_NORM_IGNORECASE)				UnsetNormIgnoreCase();
	if (dwFlags & PREGEX_FLAG_NORM_IGNORENONSPACE)			UnsetNormIgnoreNonSpace();
	if (dwFlags & PREGEX_FLAG_NORM_IGNOREWIDTH)				UnsetNormIgnoreWidth();
	if (dwFlags & PREGEX_FLAG_NORM_IGNOREKANATYPE)			UnsetNormIgnoreKanaType();
	if (dwFlags & PREGEX_FLAG_CSTRUCD_NORMALIZE)
	{
		UnsetNormalize();
		UnsetCollateNormalize();
	}
	if (dwFlags & PREGEX_FLAG_CSTRUCD_IGNOREKANACASE)		UnsetIgnoreKanaCase();

	//	�ȉ��͔p�~�\��

	if (dwFlags & PREGEX_FLAG_LINGUISTIC_IGNORECASE)		UnsetLinguisticIgnoreCase();
	if (dwFlags & PREGEX_FLAG_LINGUISTIC_IGNOREDIACRITIC)	UnsetLinguisticIgnoreDiacritic();
}
//-----------------------------------------------------------------
//	PCRegExOptions::Set(������)
//
//	�������
//		[gmsidwk(li)(ld)]*-[gmsidwk(li)(ld)]*
//	�̌`���ł���Ɖ��肵�ĉ�͂���B
///	- �ȑO�̃t���O��ݒ肵�A�ȍ~�̃t���O����������
//	���ݐݒ肵�Ă���t���O�ɒǉ�����B
//	�ŏ�����Z�b�g�������ꍇ�́A��� Reset() ���ĂԂ��ƁB
//-----------------------------------------------------------------
bool CLASS_PREGEX_OPTIONS::Set(PCTextUR* pciText)
{
	DWORD	dwOn, dwOff;

	PRegExOptions_StrToDWord(&dwOn, &dwOff, pciText);
	Set(dwOn);
	Unset(dwOff);
	return true;
}

//-----------------------------------------------------------------
//	PCRegExOptions::Set	(2)
//-----------------------------------------------------------------
bool CLASS_PREGEX_OPTIONS::Set(T_PCSTR_U pOpts, size_t zOpts)
{
	PCTextUR	ciText;

	if (pOpts == NULL)	return false;
	if (!ciText.SetText(pOpts, zOpts))	return false;
	ciText.Begin();
	return Set(&ciText);
}

//-----------------------------------------------------------------
//	PCRegExOptions::Set	(3)
//-----------------------------------------------------------------
bool CLASS_PREGEX_OPTIONS::Set(T_PCSTR_U pStrB, T_PCSTR_U pStrE)
{
	PCTextUR	ciText;

	if (pStrB == NULL || pStrB > pStrE)	return false;
	if (!ciText.SetText(pStrB, pStrE))	return false;
	ciText.Begin();
	return Set(&ciText);
}

//-----------------------------------------------------------------
//	PCRegExOptions::Set	(4)
//-----------------------------------------------------------------
bool CLASS_PREGEX_OPTIONS::Set(T_PCSTR_U pszStr)
{
	PCTextUR	ciText;

	if (pszStr == NULL)					return false;
	if (!ciText.SetText(pszStr))	return false;
	ciText.Begin();
	return Set(&ciText);
}


//-----------------------------------------------------------------
//	PCRegExOptions::CopyFrom
//-----------------------------------------------------------------
void CLASS_PREGEX_OPTIONS::CopyFrom(PCRegExOptions* pSrc)
{
	if (pSrc == NULL)	return;

	CCSOPTIONS::CopyFrom(pSrc);
	bGlobalMatching		= pSrc->IsGlobalMatching();
	bMultilineMode		= pSrc->IsMultilineMode();
	bSinglelineMode		= pSrc->IsSinglelineMode();
	bLegiblePattern		= pSrc->IsLegiblePattern();
	bCollateNormalize	= pSrc->bCollateNormalize;
}

//-----------------------------------------------------------------
//	PCRegExOptions::GetFlagsDW
//-----------------------------------------------------------------
DWORD CLASS_PREGEX_OPTIONS::GetDW()
{
	DWORD dwFlags	= 0;

	if (IsGlobalMatching())				dwFlags |= PREGEX_FLAG_GLOBALMATCHING;
	if (IsMultilineMode())				dwFlags |= PREGEX_FLAG_MULTILINEMODE;
	if (IsSinglelineMode())				dwFlags |= PREGEX_FLAG_SINGLELINEMODE;
	if (IsLegiblePattern())				dwFlags	|= PREGEX_FLAG_LEGIBLE_PATTERN;
	if (IsNormIgnoreCase())				dwFlags |= PREGEX_FLAG_NORM_IGNORECASE;
	if (IsNormIgnoreNonSpace())			dwFlags |= PREGEX_FLAG_NORM_IGNORENONSPACE;
	if (IsNormIgnoreWidth())			dwFlags |= PREGEX_FLAG_NORM_IGNOREWIDTH;
	if (IsNormIgnoreKanaType())			dwFlags |= PREGEX_FLAG_NORM_IGNOREKANATYPE;
	if (IsNormalize())					dwFlags |= PREGEX_FLAG_CSTRUCD_NORMALIZE;
	if (IsIgnoreKanaCase())				dwFlags |= PREGEX_FLAG_CSTRUCD_IGNOREKANACASE;

	//	�ȉ��͔p�~�\��

	if (IsLinguisticIgnoreCase())		dwFlags |= PREGEX_FLAG_LINGUISTIC_IGNORECASE;
	if (IsLinguisticIgnoreDiacritic())	dwFlags |= PREGEX_FLAG_LINGUISTIC_IGNOREDIACRITIC;

	return dwFlags;
}


//======================================================================
//	PSRegExMatchingState::Debug
//======================================================================
#ifdef	PDEBUG
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
#endif

//======================================================================
//	PCRegExMatchingHistory::Debug
//======================================================================
#ifdef	PDEBUG
void PCRegExMatchingHistory::Debug(T_STRING_U* pstrDebug, CRETEXT* pciText)
{
	PSRegExMatchingState*	pMState;
	CNSTATE*				pNState;
	ITR_UCPSTRING			itrText;

	T_PCSTR_U	pfmt_d	= TQU("%d");
	T_PCSTR_U	pLF		= TQU("\r\n");

	for (ciHistory.RBegin(); !ciHistory.REnd(); ciHistory.RNext())
	{
		if (!ciHistory.RGetCurrent(&pMState))	continue;
		pNState	= pMState->pciNState;
		NS_PLIB::AppendNumToString<T_CHAR_U, T_PREGEX_INDEX>(pstrDebug, pfmt_d, pNState->GetStateIndex());
		pstrDebug->append(TQU("\t: "));
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
#endif


//======================================================================
//	GetUnicodePropertyMatching
//	�p�^�[�������񂩂� Unicode �������g�p�����������������o���B
//======================================================================
bool GetUnicodePropertyMatching(int*		piMatching,
								UCPSTRING*	pucsArg1,
								UCPSTRING*	pucsArg2)
{
	int			iProperty	= 0;
	UCPSTRING*	pucsValue;
	int			iValue	= 0;
	bool		bValue	= true;
	DWORD		dwCSFlags	= (NORM_IGNORECASE | NORM_IGNOREWIDTH);
	T_PCSTR_U	pszLocale	= NULL;

	T_UCP	puczIs[]	= { (T_UCP)L'i', (T_UCP)L's', (T_UCP)0, };

	if (piMatching == NULL || pucsArg1 == NULL || pucsArg1->empty())	return FALSE;
	iProperty	= GetUnicodePropertyId(pucsArg1);
	if (iProperty == 0)
	{
		//	Arg1 �ɕs���ȑ������w�肳��Ă���ꍇ�A
		//	Arg2 ���w�肳��Ă��Ȃ��Ȃ�AArg1 �������l�ł���݂Ȃ��B
		//	Arg2 ���w�肳��Ă���ꍇ�̓G���[�Ƃ���B
		if (pucsArg2 != NULL && !pucsArg2->empty())
		{
			return false;
		}
		pucsValue	= pucsArg1;
	}
	else
	{
		//	Sc �̏ꍇ�A�����l���w�肳��Ă���Ȃ� Script�A
		//	�����łȂ��Ȃ� General_Category �� Sc ���w�肳��Ă���Ƃ݂Ȃ��B
		if ((iProperty == PTEXTEX_UNICODE_PROPERTY_SCRIPT) && pucsArg2->empty())
		{
			iProperty	= PTEXTEX_UNICODE_PROPERTY_GENERAL_CATEGORY;
			pucsValue	= pucsArg1;
		}
		else
		{
			pucsValue	= pucsArg2;
		}
	}

	//------------------------------------------------------------
	//	General_Category
	//------------------------------------------------------------
	if (iProperty == 0 || IS_PTEXTEX_UNICODE_PROPERTY_GENERAL_CATEGORY(iProperty))
	{
		if (PLib::Unicode::GetGeneralCategoryValueIdByName(&iValue, pucsValue))
		{
			if ((iValue & 0xFFFF) != iValue)
			{
				THROWPE_LOGIC_ERROR("GetUnicodePropertyMatching: General_Category");
			}
			*piMatching	= (PTEXTEX_UNICODE_PROPERTY_GENERAL_CATEGORY | iValue);
			return true;
		}
	}
	//------------------------------------------------------------
	//	Script
	//------------------------------------------------------------
	if (iProperty == 0 || IS_PTEXTEX_UNICODE_PROPERTY_SCRIPT(iProperty))
	{
		if (PLib::Unicode::GetScriptIdByName(&iValue, pucsValue))
		{
			if ((iValue & 0xFFFF) != iValue)
			{
				THROWPE_LOGIC_ERROR("GetUnicodePropertyMatching: Script");
			}
			*piMatching	= (PTEXTEX_UNICODE_PROPERTY_SCRIPT | iValue);
			return true;
		}
	}
	//------------------------------------------------------------
	//	Alphabetic
	//------------------------------------------------------------
	if (IS_PTEXTEX_UNICODE_PROPERTY_ALPHABETIC(iProperty))
	{
		if (pucsValue->empty())
		{
			iValue	= 1;
		}
		else
		{
			if (!PLib::Unicode::GetBooleanValueByStr(&bValue, pucsValue->c_str()))
			{
				return false;
			}
			iValue	= (bValue ? 1 : 0);
		}
		*piMatching	= (PTEXTEX_UNICODE_PROPERTY_ALPHABETIC | iValue);
		return true;
	}
	//------------------------------------------------------------
	//	Uppercase
	//------------------------------------------------------------
	if (IS_PTEXTEX_UNICODE_PROPERTY_UPPERCASE(iProperty))
	{
		if (pucsValue->empty())
		{
			iValue	= 1;
		}
		else
		{
			if (!PLib::Unicode::GetBooleanValueByStr(&bValue, pucsValue->c_str()))
			{
				return false;
			}
			iValue	= (bValue ? 1 : 0);
		}
		*piMatching	= (PTEXTEX_UNICODE_PROPERTY_UPPERCASE | iValue);
		return true;
	}
	//------------------------------------------------------------
	//	Lowercase
	//------------------------------------------------------------
	if (IS_PTEXTEX_UNICODE_PROPERTY_LOWERCASE(iProperty))
	{
		if (pucsValue->empty())
		{
			iValue	= 1;
		}
		else
		{
			if (!PLib::Unicode::GetBooleanValueByStr(&bValue, pucsValue->c_str()))
			{
				return false;
			}
			iValue	= (bValue ? 1 : 0);
		}
		*piMatching	= (PTEXTEX_UNICODE_PROPERTY_LOWERCASE | iValue);
		return true;
	}
	//------------------------------------------------------------
	//	White_Space
	//------------------------------------------------------------
	if (IS_PTEXTEX_UNICODE_PROPERTY_WHITE_SPACE(iProperty))
	{
		if (pucsValue->empty())
		{
			iValue	= 1;
		}
		else
		{
			if (!PLib::Unicode::GetBooleanValueByStr(&bValue, pucsValue->c_str()))
			{
				return false;
			}
			iValue	= (bValue ? 1 : 0);
		}
		*piMatching	= (PTEXTEX_UNICODE_PROPERTY_WHITE_SPACE | iValue);
		return true;
	}
	//------------------------------------------------------------
	//	Noncharacter_Code_Point
	//------------------------------------------------------------
	if (IS_PTEXTEX_UNICODE_PROPERTY_NONCHARACTER_CODE_POINT(iProperty))
	{
		if (pucsValue->empty())
		{
			iValue	= 1;
		}
		else
		{
			if (!PLib::Unicode::GetBooleanValueByStr(&bValue, pucsValue->c_str()))
			{
				return false;
			}
			iValue	= (bValue ? 1 : 0);
		}
		*piMatching	= (PTEXTEX_UNICODE_PROPERTY_NONCHARACTER_CODE_POINT | iValue);
		return true;
	}
	//------------------------------------------------------------
	//	Default_Ignorable_Code_Point
	//------------------------------------------------------------
	if (IS_PTEXTEX_UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT(iProperty))
	{
		if (pucsValue->empty())
		{
			iValue	= 1;
		}
		else
		{
			if (!PLib::Unicode::GetBooleanValueByStr(&bValue, pucsValue->c_str()))
			{
				return false;
			}
			iValue	= (bValue ? 1 : 0);
		}
		*piMatching	= (PTEXTEX_UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT | iValue);
		return true;
	}
	//------------------------------------------------------------
	//	Block
	//------------------------------------------------------------
	if (iProperty == 0 || IS_PTEXTEX_UNICODE_PROPERTY_NAMED_BLOCK(iProperty))
	{
		if (PLib::Unicode::GetBlockIdByName(&iValue, pucsValue))
		{
			if ((iValue & 0xFFFF) != iValue)
			{
				THROWPE_LOGIC_ERROR("GetUnicodePropertyMatching: Block");
			}
			*piMatching	= (PTEXTEX_UNICODE_PROPERTY_NAMED_BLOCK | iValue);
			return true;
		}
		//	Is �Ŏn�܂��Ă���ꍇ�͂�����O���Č�������B
		if ((pucsValue->size() > 2) &&
			(PLib::Unicode::CompareConvertedStringUCD(pucsValue->c_str(), 2, puczIs, -1, dwCSFlags, pszLocale)
			== CSTR_EQUAL))
		{
			if (PLib::Unicode::GetBlockIdByName(&iValue, pucsValue->c_str() + 2))
			{
				if ((iValue & 0xFFFF) != iValue)
				{
					THROWPE_LOGIC_ERROR("GetUnicodePropertyMatching: Block");
				}
				*piMatching	= (PTEXTEX_UNICODE_PROPERTY_NAMED_BLOCK | iValue);
				return true;
			}
		}
	}

	return false;
}


//======================================================================
//	ParseUnicodePropertyMatching
//
//	�����I����ApciText �� } �̎��̕������w���Ă���B
//======================================================================
bool ParseUnicodePropertyMatching(int*			piMatching,
								  PBCRegExText*	pciText,
								  DWORD			dwFlags,
								  T_PCSTR_U		pszLocale)
{
	int			iToken;
	int			iMatching	= 0;
	bool		bNegative	= false;
	ITR_UCPSTRING	itrPos1, itrPos2, itr;
	T_UCP		cpc;	//, cpt;
	UCPSTRING	ucsBuf1, ucsBuf2;
	UCPSTRING*	pucsBuf;

	//T_UCP			cpEqual			= TQ_UCP('=');
	//T_UCP			cpHyphen		= TQ_UCP('-');
	//T_UCP			cpUnderscore	= TQ_UCP('_');
	//T_UCP			cpDoubleQuote	= TQ_UCP('\"');
	//T_UCP			cpCircumflex	= TQ_UCP('^');

	//------------------------------------------------------------
	//	{ ��T���B���݂܂��͎��̃R�[�h�|�C���g�� { �łȂ��ꍇ�͏I������B
	//------------------------------------------------------------
	iToken	= pciText->GetCurrentToken();
	if (iToken == PREGEX_TOKEN_LBRACE)
	{
		pciText->Next();
	}
	else
	{
		iToken	= pciText->GetNextToken();
		if (iToken != PREGEX_TOKEN_LBRACE)	return false;
		pciText->Next();
		pciText->Next();
	}
	if (!pciText->GetCurrentPos(itrPos1)) THROWPE_LOGIC_ERROR("");

	//	} ��T���B
	while (!pciText->End())
	{
		iToken	= pciText->GetCurrentToken();
		if (iToken == PREGEX_TOKEN_RBRACE)	break;
		pciText->Next();
	}
	if (iToken != PREGEX_TOKEN_RBRACE)	return false;
	if (!pciText->GetCurrentPos(itrPos2))	THROWPE_LOGIC_ERROR("");
	ucsBuf1.clear();

	ucsBuf1.clear();
	ucsBuf2.clear();
	pucsBuf	= &ucsBuf1;

	//	��������������o���B
	for (itr = itrPos1; itr != itrPos2; ++itr)
	{
		iToken	= (int)PREGEX_CPEX_GETOPT(*itr);
		//	{ } ���̍ŏ��� 1 ������ ^ �Ȃ� Negative �Ƃ���B
		if (ucsBuf1.empty() && iToken == PREGEX_TOKEN_CIRCUMFLEX)
		{
			bNegative	= true;
			continue;
		}
		//	= �̏ꍇ
		if (iToken == PREGEX_TOKEN_EQUAL)
		{
			//	ucsBuf1 ����łȂ��Ȃ�A�o�b�t�@�� ucsBuf2 �ɕς���B
			if (!ucsBuf1.empty())	pucsBuf	= &ucsBuf2;
			continue;
		}
		cpc	= PREGEX_CPEX_GETCP(*itr);
		if (PLib::Unicode::IsAlNum_GC(cpc))
		{
			pucsBuf->append(1, cpc);
		}
	}

	//	���������o���B
	if (GetUnicodePropertyMatching(&iMatching, &ucsBuf1, &ucsBuf2))
	{
		if (bNegative)
		{
			iMatching	|= PTEXTEX_UNICODE_PROPERTY_NEGATIVE;
		}
		*piMatching	= iMatching;
		pciText->Next();
		return true;
	}
	return false;
}

//======================================================================
//	MatchUnicodeProperty
//======================================================================
bool MatchUnicodeProperty(int iMatching, T_UCP cpSrc)
{
	int		iValue1, iValue2;
	bool	bValue1, bValue2;
	bool	bNegative;
	bool	bt;	//,br;

	bNegative	= IS_PTEXTEX_UNICODE_PROPERTY_NEGATIVE(iMatching);

	switch (GET_PTEXTEX_UNICODE_PROPERTY_TYPE(iMatching))
	{
	case PTEXTEX_UNICODE_PROPERTY_GENERAL_CATEGORY:
		iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
		bt	= PLib::Unicode::MatchGeneralCategory(cpSrc, iValue1);
		break;

	case PTEXTEX_UNICODE_PROPERTY_SCRIPT:
		iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
		if (PLib::Unicode::GetScriptValue(&iValue2, cpSrc))
		{
			bt	= (iValue1 == iValue2);
		}
		else
		{
			bt	= false;
		}
		break;

	case PTEXTEX_UNICODE_PROPERTY_ALPHABETIC:
		bValue1	= (GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching) != 0);
		bValue2	= PLib::Unicode::IsAlphabetic(cpSrc);
		bt	= (bValue1 == bValue2);
		break;

	case PTEXTEX_UNICODE_PROPERTY_UPPERCASE:
		bValue1	= (GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching) != 0);
		bValue2	= PLib::Unicode::IsUppercase(cpSrc);
		bt	= (bValue1 == bValue2);
		break;

	case PTEXTEX_UNICODE_PROPERTY_LOWERCASE:
		bValue1	= (GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching) != 0);
		bValue2	= PLib::Unicode::IsLowercase(cpSrc);
		bt	= (bValue1 == bValue2);
		break;

	case PTEXTEX_UNICODE_PROPERTY_WHITE_SPACE:
		bValue1	= (GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching) != 0);
		bValue2	= PLib::Unicode::IsWhiteSpace(cpSrc);
		bt	= (bValue1 == bValue2);
		break;

	case PTEXTEX_UNICODE_PROPERTY_NONCHARACTER_CODE_POINT:
		bValue1	= (GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching) != 0);
		bValue2	= PLib::Unicode::IsNoncharacterCodePoint(cpSrc);
		bt	= (bValue1 == bValue2);
		break;

	case PTEXTEX_UNICODE_PROPERTY_DEFAULT_IGNOREABLE_CODEPOINT:
		bValue1	= (GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching) != 0);
		bValue2	= PLib::Unicode::IsDefaultIgnorableCodePoint(cpSrc);
		bt	= (bValue1 == bValue2);
		break;

	case PTEXTEX_UNICODE_PROPERTY_NAMED_BLOCK:
		iValue1	= GET_PTEXTEX_UNICODE_PROPERTY_VALUE(iMatching);
		bt	= PLib::Unicode::IsInBlock(iValue1, cpSrc);
		break;

	default:
		//THROWPE_LOGICAL_ERROR("");
		return false;
		break;
	}

	if (bt && !bNegative)
	{
		return true;
	}
	else if (!bt && bNegative)	//	bNegative �Ȃ瑮���Ă��Ȃ��ꍇ�ɐ���
	{
		return true;
	}
	return false;
}

//======================================================================
//	IsWordBoundary
//
//	Unicode TR18
//		Nonspacing marks are never divided from their base characters,
//		and otherwise ignored in locating boundaries.
//======================================================================
bool IsWordBoundary(PITextUR* pciText)
{
	T_UCP	cpCurrent, cpPrevious;
	int		irc, irp;

	if (pciText == NULL)
	{
		THROWPE_INVALID_PARAMETER("IsWordBoundary");
	}
	irc	= pciText->GetCurrentCp(&cpCurrent);
	irp	= pciText->GetPreviousCp(&cpPrevious);

	//	���݂̕����� word �̏ꍇ�B
	if (PCTEXT_GETVALIDCP(irc))
	{
		if (PLib::Unicode::IsWord_GC(cpCurrent))
		{
			//	�擪�̏ꍇ�� true
			if (irp == PCTEXT_POS_UNDER)	return true;
			//	�擪�łȂ��ꍇ�A���O�̕����� word �łȂ��A���ANM �łȂ��B
			if (PCTEXT_GETVALIDCP(irp)					&&
				!PLib::Unicode::IsWord_GC(cpPrevious)	&&
				!PLib::Unicode::MatchGeneralCategory(
				cpPrevious, PUCD_GENERAL_CATEGORY_MN_NONSPACING_MARK))
			{
				return true;
			}
		}
	}
	//	���O�̕����� word �̏ꍇ�B
	if (PCTEXT_GETVALIDCP(irp))
	{
		if (PLib::Unicode::IsWord_GC(cpPrevious))
		{
			if (irc == PCTEXT_POS_OVER)	return true;	//	�I�[�̏ꍇ true;
			//	�I�[�łȂ��ꍇ�A���݂̕����� word �łȂ��A���ANM �łȂ��B
			if (!PLib::Unicode::IsWord_GC(cpCurrent)	&&
				!PLib::Unicode::MatchGeneralCategory(
				cpCurrent, PUCD_GENERAL_CATEGORY_MN_NONSPACING_MARK))
			{
				return true;
			}
		}
	}
	return false;
}

NS_PLIB_END
