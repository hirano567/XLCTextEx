//	XLCTextEx_1.0x	:	PLibUCD

//	PUCDUtility.h
//
#pragma once

NS_PLIB_UNICODE_BEGIN

//======================================================================
//	UCPString ��r�p�̃N���X
//======================================================================
template<DWORD CSTRFLAGS>
class PCCompareUCPString
{
public:
	bool operator()(UCPSTRING* ps1, UCPSTRING* ps2)	const
	{
		return (PLib::Unicode::CompareStringUCD(ps1, ps2, CSTRFLAGS, NULL) == CSTR_LESS_THAN);
	}
};

//======================================================================
//	t_CharToInt_base
//	�����`�F�b�N�͌Ăяo�����ōs���Ă������ƁB
//======================================================================
//----------------------------------------------------------------------
//	t_CharToInt_base	(1)
//----------------------------------------------------------------------
template<int A_CONV[128], bool B_NORMALIZE>
bool t_CharToInt_base(int* piNum, UINT uiCp)
{
	UINT	uic;
	int		i;
	PLib::Unicode::PSDECOMPOSITION*	pDecmp	= NULL;

	//------------------------------------------------------------
	//	�R�[�h�� 0 ���� 128 �̏ꍇ
	//------------------------------------------------------------
	if (IS_7BIT(uiCp))
	{
		i	= A_CONV[uiCp];
		if (i >= 0)
		{
			*piNum	= i;
			return true;
		}
		return false;
	}

	//------------------------------------------------------------
	//	����ȊO�̏ꍇ�AB_NORMALIZE �� true ���ݒ肳��Ă���Ȃ�A
	//	�R�[�h�|�C���g�ɕϊ����A���K�����Ē��ׂ�B
	//------------------------------------------------------------
	if (!B_NORMALIZE)	return false;

	if (PUCD_BMPTABLE_NOT_DECOMP_SET(uiCp))	return false;
	if (PLib::Unicode::GetDecomposition(&pDecmp, uiCp))	return false;

	//	"0" �� "�_" �ȂǕ����̕����ɕ����������̂́A�ΏۊO�Ƃ���B
	if (pDecmp->nDecomposition != 1)	return false;

	//------------------------------------------------------------
	//	���K���������������l��\���Ă��邩���ׂ�B
	//------------------------------------------------------------
	uic	= *(pDecmp->pcpDecomposition);
	if (IS_7BIT(uic))
	{
		i	= A_CONV[uic];
		if (i >= 0)
		{
			*piNum	= i;
			return true;
		}
		return false;
	}
	return false;
}

//----------------------------------------------------------------------
//	t_CharToInt_base	(2-1)
//----------------------------------------------------------------------
template<int A_CONV[128], bool B_NORMALIZE>
inline bool t_CharToInt_base(int* piNum, T_PCSTR_U* ppSrcB, T_PCSTR_U pSrcE)
{
	UINT			uic;
	T_PCSTR_U	pc;

	pc	= *ppSrcB;
	if (!PLib::Unicode::ConvertToCodepoint(&uic, &pc, pSrcE))	return false;
	if (t_CharToInt_base<A_CONV, B_NORMALIZE>(piNum, uic))
	{
		*ppSrcB	= pc;
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	t_CharToInt_base	(2-2)
//----------------------------------------------------------------------
template<int A_CONV[128], bool B_NORMALIZE>
inline bool t_CharToInt_base(int* piNum, T_PCSTR_U* ppszSrc)
{
	UINT			uic;
	T_PCSTR_U	pc;

	pc	= *ppszSrc;
	if (!PLib::Unicode::ConvertToCodepoint(&uic, &pc))	return false;
	if (t_CharToInt_base<A_CONV, B_NORMALIZE>(piNum, uic))
	{
		*ppszSrc	= pc;
		return true;
	}
	return false;
}

//======================================================================
//	StrToInt
//======================================================================
//----------------------------------------------------------------------
//	t_StrToInt_base
//
//	I_BASE		�
//	CONVTABLE	ASCII �������琔�l�ւ̕ϊ��\
//	T_INT		���߂鐮���̌^
//	B_NEGATIVE	�ŏ��� - ������Ε��̒l�Ƃ���B
//	B_NORMALIZE	���K�����Ă��珈������B
//
//	�����̃`�F�b�N�͌Ăяo�����ł��Ă������ƁB
//----------------------------------------------------------------------
template<int I_BASE, int A_CONV[128], typename T_INT, bool B_NEGATIVE, bool B_NORMALIZE>
bool t_StrToInt_base(T_INT* piNum, T_PCSTR_U* ppNext, PIFStrBuffer<T_CHAR_U>* pciBuf, int iMinDigit, int iMaxDigit)
{
	UINT		uic;
	int			i, n, idg;
	T_PCSTR_U	pini;
	bool		bNegative	= false;

	pini	= pciBuf->GetCurrentPos();
	*ppNext	= pini;

	//------------------------------------------------------------
	//	�܂� 1 �������o���B
	//------------------------------------------------------------
	if (!PLib::Unicode::ConvertToCodepoint(&uic, pciBuf))	return false;

	//------------------------------------------------------------
	//	���l���̏ꍇ�A- ���ǂ������ׂ�B- �̏ꍇ�A���̕��������o���Ă����B
	//------------------------------------------------------------
	if (B_NEGATIVE)
	{
		if (uic == (UINT)(L'-'))
		{
			bNegative	= true;
			if (!PLib::Unicode::ConvertToCodepoint(&uic, pciBuf))	return false;
		}
		else if (B_NORMALIZE)
		{
			//	���K���� "-" ���܂ނ̂� 2 ���������Ȃ̂ŁA���ڒ��ׂ�B
			if (uic == (UINT)0xFE63 || uic == (UINT)0xFF0D)
			{
				bNegative	= true;
				if (!PLib::Unicode::ConvertToCodepoint(&uic, pciBuf))	return false;
			}
		}
	}

	//------------------------------------------------------------
	//	���������l�łȂ��ꍇ�� false ��Ԃ��B
	//------------------------------------------------------------
	if (!t_CharToInt_base<A_CONV, B_NORMALIZE>(&i, uic))	return false;
	n	= i;
	idg	= 1;
	*ppNext	= pciBuf->GetCurrentPos();

	//------------------------------------------------------------
	//	���l�������Ă�������o���B
	//------------------------------------------------------------
	while (!pciBuf->End())
	{
		if (iMaxDigit > 0 && idg >= iMaxDigit)	break;
		if (!PLib::Unicode::ConvertToCodepoint(&uic, pciBuf))	break;
		if (!t_CharToInt_base<A_CONV, B_NORMALIZE>(&i, uic))	break;
		n	= n * I_BASE + i;
		++idg;
		*ppNext	= pciBuf->GetCurrentPos();
	}

	if (B_NEGATIVE)
	{
		if (bNegative)	n	*= -1;
	}
	if (idg >= iMinDigit)
	{
		*piNum	= (T_INT)n;
		return true;
	}
	*ppNext	= pini;
	return false;
}

//----------------------------------------------------------------------
//	StrToIntDec, StrToIntDecN	(1)
//----------------------------------------------------------------------
template<typename T_INT>
bool StrToIntDec(T_INT* piNum, T_PCSTR_U* ppSrcB, T_PCSTR_U pSrcE, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSegmentBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppSrcB, pSrcE);
	if (bNormalize)
	{
		return t_StrToInt_base<10, PLib::iDecChar, T_INT, false, true>(piNum, ppSrcB, &ciBuf, 0, iMaxDigit);
	}
	return t_StrToInt_base<10, PLib::iDecChar, T_INT, false, false>(piNum, ppSrcB, &ciBuf, 0, iMaxDigit);
}

template<typename T_INT>
bool StrToIntDecN(T_INT* piNum, T_PCSTR_U* ppSrcB, T_PCSTR_U pSrcE, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSegmentBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppSrcB, pSrcE);
	if (bNormalize)
	{
		return t_StrToInt_base<10, PLib::iDecChar, T_INT, true, true>(piNum, ppSrcB, &ciBuf, 0, iMaxDigit);
	}
	return t_StrToInt_base<10, PLib::iDecChar, T_INT, true, false>(piNum, ppSrcB, &ciBuf, 0, iMaxDigit);
}

//----------------------------------------------------------------------
//	StrToIntDec, StrToIntDecN	(2)
//----------------------------------------------------------------------
template<typename T_INT>
bool StrToIntDec(T_INT* piNum, T_PCSTR_U* ppszSrc, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSzBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppszSrc);
	if (bNormalize)
	{
		return t_StrToInt_base<10, PLib::iDecChar, T_INT, false, true>(piNum, ppszSrc, &ciBuf, 0, iMaxDigit);
	}
	return t_StrToInt_base<10, PLib::iDecChar, T_INT, false, false>(piNum, ppszSrc, &ciBuf, 0, iMaxDigit);
}

template<typename T_INT>
bool StrToIntDecN(T_INT* piNum, T_PCSTR_U* ppszSrc, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSzBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppszSrc);
	if (bNormalize)
	{
		return t_StrToInt_base<10, PLib::iDecChar, T_INT, true, true>(piNum, ppszSrc, &ciBuf, 0, iMaxDigit);
	}
	return t_StrToInt_base<10, PLib::iDecChar, T_INT, true, false>(piNum, ppszSrc, &ciBuf, 0, iMaxDigit);
}

//----------------------------------------------------------------------
//	StrToIntHex	(1)
//----------------------------------------------------------------------
template<typename T_INT>
bool StrToIntHex(T_INT* piNum, T_PCSTR_U* ppSrcB, T_PCSTR_U pSrcE, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSegmentBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppSrcB, pSrcE);
	if (bNormalize)
	{
		return t_StrToInt_base<16, PLib::iHexChar, T_INT, false, true>(piNum, ppSrcB, &ciBuf, 0, iMaxDigit);
	}
	return t_StrToInt_base<16, PLib::iHexChar, T_INT, false, false>(piNum, ppSrcB, &ciBuf, 0, iMaxDigit);
}

//----------------------------------------------------------------------
//	StrToIntHex	(2)
//----------------------------------------------------------------------
template<typename T_INT>
bool StrToIntHex(T_INT* piNum, T_PCSTR_U* ppszSrc, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSzBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppszSrc);
	if (bNormalize)
	{
		return t_StrToInt_base<16, PLib::iHexChar, T_INT, false, true>(piNum, ppszSrc, &ciBuf, 0, iMaxDigit);
	}
	return t_StrToInt_base<16, PLib::iHexChar, T_INT, false, false>(piNum, ppszSrc, &ciBuf, 0, iMaxDigit);
}

//----------------------------------------------------------------------
//	StrToIntOct	(1)
//----------------------------------------------------------------------
template<typename T_INT>
bool StrToIntOct(T_INT* piNum, T_PCSTR_U* ppSrcB, T_PCSTR_U pSrcE, int iMinDigit, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSegmentBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppSrcB, pSrcE);
	if (bNormalize)
	{
		return t_StrToInt_base<8, PLib::iOctChar, T_INT, false, true>(piNum, ppSrcB, &ciBuf, iMinDigit, iMaxDigit);
	}
	return t_StrToInt_base<8, PLib::iOctChar, T_INT, false, false>(piNum, ppSrcB, &ciBuf, iMinDigit, iMaxDigit);
}

//----------------------------------------------------------------------
//	StrToIntOct	(2)
//----------------------------------------------------------------------
template<typename T_INT>
bool StrToIntOct(T_INT* piNum, T_PCSTR_U* ppszSrc, int iMinDigit, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSzBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppszSrc);
	if (bNormalize)
	{
		return t_StrToInt_base<8, PLib::iOctChar, T_INT, false, true>(piNum, ppszSrc, &ciBuf, iMinDigit, iMaxDigit);
	}
	return t_StrToInt_base<8, PLib::iOctChar, T_INT, false, false>(piNum, ppszSrc, &ciBuf, iMinDigit, iMaxDigit);
}

/*
//======================================================================
//	is �n�̊֐��Ƃ����Ɋ֘A����֐�
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

bool	IsHyphen(T_UCP cp, bool bNormalize);
inline bool	IsHyphen(T_CHAR_U c, bool bNormalize)	{ return IsHyphen((T_UCP)c, bNormalize); }

bool	IsDoubleQuote(T_UCP cp, bool bNormalize);
inline bool	IsDoubleQuote(T_CHAR_U c, bool bNormalize)	{ return IsDoubleQuote((T_UCP)c, bNormalize); }
*/

//======================================================================
//	�G�X�P�[�v�V�[�P���X�f�R�[�h�p�̊֐�
//======================================================================
bool	DecodeEscapedControl(T_UCP* pcpDst, T_UCP cpSrc, DWORD dwFlags, T_PCSTR_U pszLocale);

//======================================================================
//	DecodeControlChar
//======================================================================
bool	DecodeControlChar(UINT* puiDst, UINT uiSrc, DWORD dwFlags, LPCWSTR pszLocale);

//======================================================================
//	AppendCodepointToString
//======================================================================
bool	AppendCodepointToString(T_STRING_U* pstrBuffer, T_UCP cpSrc);

NS_PLIB_UNICODE_END
