//	XLCTextEx_1.0x	:	PLibUCD

//	PLibUCD:	PCompareStringUCD.cpp
//
#include "stdafx.h"

NS_PLIB_UNICODE_BEGIN

//======================================================================
//	StrFoldingUCD
//======================================================================
bool StrFoldingUCD(UCPSTRING*	pucsFolded,
				   UCPSTRING*	pucsSrc,
				   DWORD		dwFlags,
				   T_PCSTR_U	pszLocale)
{
	UCPSTRING	ucsKanaCase;
	UCPSTRING	ucsKanaWidth;
	UCPSTRING	ucsKanaType;
	UCPSTRING	ucsNormalize;
	UCPSTRING	ucsCase;

	UCPSTRING*	pucsTemp	= pucsSrc;

	if (pucsFolded == NULL || pucsSrc == NULL)	return false;

	//------------------------------------------------------------
	//	�Ђ炪�ȁE�J�^�J�i�̏�����
	//------------------------------------------------------------
	if (COMPARESTRINGUCD_IS_IGNOREKANACASE(dwFlags))
	{
		if (!PLib::Unicode::CaseFoldingKana(&ucsKanaCase, pucsTemp))	return false;
		pucsTemp	= &ucsKanaCase;
	}

	//------------------------------------------------------------
	//	�S�p�E���p
	//------------------------------------------------------------
	if (COMPARESTRING_IS_NORM_IGNOREWIDTH(dwFlags))
	{
		if(!PLib::Unicode::KanaWidthFolding(&ucsKanaWidth, pucsTemp))	return false;
		pucsTemp	= &ucsKanaWidth;
	}

	//------------------------------------------------------------
	//	�Ђ炪�ȁE�J�^�J�i
	//------------------------------------------------------------
	if (COMPARESTRING_IS_NORM_IGNOREKANATYPE(dwFlags))
	{
		if (!PLib::Unicode::KanaTypeFolding(&ucsKanaType, pucsTemp))	return false;
		pucsTemp	= &ucsKanaType;
	}

	//------------------------------------------------------------
	//	�_�C�A�N���e�B�J���}�[�N�A���K��
	//------------------------------------------------------------
	if (COMPARESTRING_IS_NORM_IGNORENONSPACE(dwFlags))
	{
		if (!PLib::Unicode::GetStarter(&ucsNormalize, pucsTemp))	return false;
		pucsTemp	= &ucsNormalize;
	}
	else if (COMPARESTRINGUCD_IS_NORMALIZE(dwFlags))
	{
		if (!PLib::Unicode::GetDecomposition(&ucsNormalize, pucsTemp))	return false;
		pucsTemp	= &ucsNormalize;
	}

	//------------------------------------------------------------
	//	�啶���E������
	//------------------------------------------------------------
	if (COMPARESTRING_IS_NORM_IGNORECASE(dwFlags))
	{
		if (!PLib::Unicode::CaseFoldingSimple(&ucsCase, pucsTemp))	return false;
		pucsTemp	= &ucsCase;
	}

	pucsFolded->append(pucsTemp->c_str(), pucsTemp->size());
	return true;
}

//======================================================================
//	CompareConvertedStringUCD	(1)	PIFUnicodeBuffer �������Ƃ���B
//======================================================================
int CompareConvertedStringUCD(PIFUnicodeBuffer*	pUBuf1,
							  PIFUnicodeBuffer*	pUBuf2,
							  DWORD				dwFlags,
							  T_PCSTR_U			pszLocale)
{
	UCPSTRING	ucsSrc1, ucsSrc2;
	UCPSTRING	ucsFolded1, ucsFolded2;
	int			ir;

	//------------------------------------------------------------
	//	�R�[�h�|�C���g������o���B�B
	//------------------------------------------------------------
	if (!pUBuf1->GetCpString(&ucsSrc1))	return false;
	if (!pUBuf2->GetCpString(&ucsSrc2))	return false;

	//------------------------------------------------------------
	//	�w�肳�ꂽ�ʒu�ȍ~��ϊ�����r����B
	//------------------------------------------------------------
	if (!PLib::Unicode::StrFoldingUCD(&ucsFolded1, &ucsSrc1, dwFlags, pszLocale))	return 0;
	if (!PLib::Unicode::StrFoldingUCD(&ucsFolded2, &ucsSrc2, dwFlags, pszLocale))	return 0;

	ir	= ucsFolded1.compare(ucsFolded2);
	if (ir < 0)
	{
		return CSTR_LESS_THAN;
	}
	else if (ir > 0)
	{
		return CSTR_GREATER_THAN;
	}
	return CSTR_EQUAL;
}

//======================================================================
//	CompareConvertedStringUCD	(2)	Codepoint ��������Ƃ���B
//======================================================================
int CompareConvertedStringUCD(const T_UCP*	pStr1,
							  int			izStr1,
							  const T_UCP*	pStr2,
							  int			izStr2,
							  DWORD			dwFlags,
							  T_PCSTR_U		pszLocale)
{
	PCCodepointSegmentBuffer	ciUSeg1, ciUSeg2;
	PCCodepointSzBuffer			ciUSz1, ciUSz2;
	PBCUnicodeStrBuffer			*pUBuf1, *pUBuf2;

	if (pStr1 == NULL || pStr2 == NULL || izStr1 == 0 || izStr2 == 0)	return 0;

	//------------------------------------------------------------
	//	�w�肳�ꂽ��������o�b�t�@�����O�p�̃N���X�ɃZ�b�g����B
	//------------------------------------------------------------
	if (izStr1 < 0)
	{
		ciUSz1.Set(pStr1);
		pUBuf1	= (PBCUnicodeStrBuffer*)&ciUSz1;
	}
	else
	{
		ciUSeg1.Set(pStr1, (size_t)izStr1);
		pUBuf1	= (PBCUnicodeStrBuffer*)&ciUSeg1;
	}

	if (izStr2 < 0)
	{
		ciUSz2.Set(pStr2);
		pUBuf2	= (PBCUnicodeStrBuffer*)&ciUSz2;
	}
	else
	{
		ciUSeg2.Set(pStr2, (size_t)izStr2);
		pUBuf2	= (PBCUnicodeStrBuffer*)&ciUSeg2;
	}

	//------------------------------------------------------------
	//	�I�v�V�������w�肳��Ă��Ȃ��ꍇ�͂��̂܂ܔ�r����B
	//------------------------------------------------------------
	if (dwFlags == 0)
	{
		return pUBuf1->Compare(pUBuf2);
	}

	//------------------------------------------------------------
	//	����ȊO�̏ꍇ�� CompareConvertedStringUCD �֐��ŏ�������B
	//------------------------------------------------------------
	return CompareConvertedStringUCD(pUBuf1, pUBuf2, dwFlags, pszLocale);
}

//======================================================================
//	CompareConvertedStringUCD	(3)	Unicode ��������Ƃ���B
//======================================================================
int		CompareConvertedStringUCD(T_PCSTR_U	pStr1,
								  int		izStr1,
								  T_PCSTR_U	pStr2,
								  int		izStr2,
								  DWORD		dwFlags,
								  T_PCSTR_U	pszLocale)
{
	PCUnicodeSegmentBuffer	ciUSeg1, ciUSeg2;
	PCUnicodeSzBuffer		ciUSz1, ciUSz2;
	PBCUnicodeStrBuffer	*pUBuf1, *pUBuf2;

	if (pStr1 == NULL || pStr2 == NULL || izStr1 == 0 || izStr2 == 0)	return 0;

	//------------------------------------------------------------
	//	�w�肳�ꂽ��������o�b�t�@�����O�p�̃N���X�ɃZ�b�g����B
	//------------------------------------------------------------
	if (izStr1 < 0)
	{
		ciUSz1.Set(pStr1);
		pUBuf1	= (PBCUnicodeStrBuffer*)&ciUSz1;
	}
	else
	{
		ciUSeg1.Set(pStr1, (size_t)izStr1);
		pUBuf1	= (PBCUnicodeStrBuffer*)&ciUSeg1;
	}

	if (izStr2 < 0)
	{
		ciUSz2.Set(pStr2);
		pUBuf2	= (PBCUnicodeStrBuffer*)&ciUSz2;
	}
	else
	{
		ciUSeg2.Set(pStr2, (size_t)izStr2);
		pUBuf2	= (PBCUnicodeStrBuffer*)&ciUSeg2;
	}

	//------------------------------------------------------------
	//	�I�v�V�������w�肳��Ă��Ȃ��ꍇ�͂��̂܂ܔ�r����B
	//------------------------------------------------------------
	if (dwFlags == 0)
	{
		return pUBuf1->Compare(pUBuf2);
	}

	//------------------------------------------------------------
	//	����ȊO�̏ꍇ�� CompareCpStringUCD �֐��ŏ�������B
	//------------------------------------------------------------
	return CompareConvertedStringUCD(pUBuf1, pUBuf2, dwFlags, pszLocale);
}

//======================================================================
//	CompareConvertedStringUCD_Z	�󕶎��������̑ΏۂƂ���B
//
//	PIFUnicodeBuffer �������Ƃ���B
//======================================================================
int CompareConvertedStringUCD_Z(PIFUnicodeBuffer*	pUBuf1,
								PIFUnicodeBuffer*	pUBuf2,
								DWORD				dwFlags,
								T_PCSTR_U			pszLocale)
{
	UCPSTRING	ucsSrc1, ucsSrc2;
	UCPSTRING	ucsFolded1, ucsFolded2;
	int			ir;

	//------------------------------------------------------------
	//	�R�[�h�|�C���g�����肾���A�w�肳�ꂽ�ʒu�ȍ~��ϊ�����B
	//------------------------------------------------------------
	if (pUBuf1->GetCpString(&ucsSrc1) && !ucsSrc1.empty())
	{
		if (!PLib::Unicode::StrFoldingUCD(&ucsFolded1, &ucsSrc1, dwFlags, pszLocale))	return 0;
	}
	else
	{
		ucsFolded1.clear();
	}

	if (pUBuf2->GetCpString(&ucsSrc2) && !ucsSrc2.empty())
	{
		if (!PLib::Unicode::StrFoldingUCD(&ucsFolded2, &ucsSrc2, dwFlags, pszLocale))	return 0;
	}
	else
	{
		ucsFolded2.clear();
	}

	//------------------------------------------------------------
	//	��r����B���̍ہA
	//	�ǂ�����󕶎���Ȃ瓙�����Ƃ���B
	//	����������󕶎���Ȃ�A�����炪�������Ƃ���B
	//------------------------------------------------------------

	if (ucsFolded1.empty() && ucsFolded2.empty())	return CSTR_EQUAL;
	if (ucsFolded1.empty())	return CSTR_LESS_THAN;
	if (ucsFolded2.empty())	return CSTR_GREATER_THAN;

	ir	= ucsFolded1.compare(ucsFolded2);
	if (ir < 0)
	{
		return CSTR_LESS_THAN;
	}
	else if (ir > 0)
	{
		return CSTR_GREATER_THAN;
	}
	return CSTR_EQUAL;
}


//======================================================================
//	CompareCodepointUCD_Sub1
//
//	ignore diacritical �ȊO�̃I�v�V������K�p���Ĕ��肷��B
//	�ϊ����ɓ��� Codepoint �ɂȂ����炻���ŏI������B
//======================================================================
int CompareCodepointUCD_Sub1(T_UCP cpSrc1, T_UCP cpSrc2,
							 bool bIKanaCase, bool bIKanaType, bool bIKanaWidth, bool bICase, bool bNormalize, bool bDiacritical)
{
	T_UCP		cps1, cps2;
	T_UCP		*pcpt1, *pcpt2;
	const T_UCP	*pccpt;
	int			n1, n2;
	T_BMPINFO	usFlags1, usFlags2;
	UCPSTRING	ucsICase1, ucsICase2;
	UCPSTRING	ucsNormalize1, ucsNormalize2;
	UCPSTRING	ucsDiacritical1, ucsDiacritical2;
	UCPSTRING	*pucsTemp1, *pucsTemp2;
	int			ic, iRet;

	ic	= cpSrc1 - cpSrc2;
	if (ic == 0)	return CSTR_EQUAL;
	iRet	=  (ic < 0 ? CSTR_LESS_THAN : CSTR_GREATER_THAN);

	cps1		= cpSrc1;
	cps2		= cpSrc2;
	usFlags1	= GetInfoFromBMPTable(cpSrc1);
	usFlags2	= GetInfoFromBMPTable(cpSrc2);

	//------------------------------------------------------------
	//	Fold kana case
	//------------------------------------------------------------
	if (bIKanaCase)
	{
		cps1	= PLib::Unicode::CaseFoldingKana(cps1);
		cps2	= PLib::Unicode::CaseFoldingKana(cps2);

		ic	= cps1 - cps2;
		if (ic == 0)	return CSTR_EQUAL;
		iRet	= (ic < 0 ? CSTR_LESS_THAN : CSTR_GREATER_THAN);
	}

	//------------------------------------------------------------
	//	Fold kana type
	//------------------------------------------------------------
	if (bIKanaType)
	{
		cps1	= PLib::Unicode::KanaTypeFolding(cps1);
		cps2	= PLib::Unicode::KanaTypeFolding(cps2);

		ic	= cps1 - cps2;
		if (ic == 0)	return CSTR_EQUAL;
		iRet	= (ic < 0 ? CSTR_LESS_THAN : CSTR_GREATER_THAN);
	}

	//------------------------------------------------------------
	//	Fold kana width
	//------------------------------------------------------------
	if (bIKanaWidth)
	{
		cps1	= PLib::Unicode::KanaWidthFolding(cps1);
		cps2	= PLib::Unicode::KanaWidthFolding(cps2);

		ic	= cps1 - cps2;
		if (ic == 0)	return CSTR_EQUAL;
		iRet	= (ic < 0 ? CSTR_LESS_THAN : CSTR_GREATER_THAN);
	}

	//------------------------------------------------------------
	//	Fold case
	//	CaseFolding �ɂ����ẮA1 �̃R�[�h�y�[�W�������̃R�[�h�y�[�W�ɕϊ�����邱�Ƃ�����B
	//------------------------------------------------------------
	if (bICase)
	{
		n1	= 0;
		n2	= 0;

		if (PLib::Unicode::CaseFoldingSimple(&pcpt1, &n1, cps1))
		{
			ucsICase1.assign(pcpt1);
		}
		else
		{
			ucsICase1.assign(1, cps1);
		}

		if (PLib::Unicode::CaseFoldingSimple(&pcpt2, &n2, cps2))
		{
			ucsICase2.assign(pcpt2);
		}
		else
		{
			ucsICase2.assign(1, cps2);
		}

		ic	= ucsICase1.compare(ucsICase2);
		if (ic == 0)	return CSTR_EQUAL;
		iRet	= (ic < 0 ? CSTR_LESS_THAN : CSTR_GREATER_THAN);
		pucsTemp1	= &ucsICase1;
		pucsTemp2	= &ucsICase2;
	}
	else
	{
		ucsICase1.assign(1, cps1);
		ucsICase2.assign(1, cps2);
		pucsTemp1	= &ucsICase1;
		pucsTemp2	= &ucsICase2;
	}

	//------------------------------------------------------------
	//	Normalize, Diacritical	�������Ĕ�r����B
	//------------------------------------------------------------
	if (bNormalize || bDiacritical)
	{
		ucsNormalize1.clear();
		for (pccpt = pucsTemp1->c_str(); *pccpt; ++pccpt)
		{
			PLib::Unicode::GetDecomposition(&ucsNormalize1, *pccpt);
		}

		ucsNormalize2.clear();
		for (pccpt = pucsTemp2->c_str(); *pccpt; ++pccpt)
		{
			PLib::Unicode::GetDecomposition(&ucsNormalize2, *pccpt);
		}

		ic = ucsNormalize1.compare(ucsNormalize2);
		if (ic == 0)	return CSTR_EQUAL;
		iRet	= (ic < 0 ? CSTR_LESS_THAN : CSTR_GREATER_THAN);
		pucsTemp1	= &ucsNormalize1;
		pucsTemp2	= &ucsNormalize2;
	}

	//------------------------------------------------------------
	//	Diacritical	non starter ����菜���Ĕ�r����B
	//------------------------------------------------------------
	if (bDiacritical)
	{
		ucsDiacritical1.clear();
		for (pccpt = pucsTemp1->c_str(); *pccpt; ++pccpt)
		{
			if (PLib::Unicode::IsNonStarter(*pccpt))	continue;
			ucsDiacritical1.append(1, *pccpt);
		}

		ucsDiacritical2.clear();
		for (pccpt = pucsTemp2->c_str(); *pccpt; ++pccpt)
		{
			if (PLib::Unicode::IsNonStarter(*pccpt))	continue;
			ucsDiacritical2.append(1, *pccpt);
		}

		ic = ucsDiacritical1.compare(ucsDiacritical2);
		if (ic == 0)	return CSTR_EQUAL;
		iRet	= (ic < 0 ? CSTR_LESS_THAN : CSTR_GREATER_THAN);
		pucsTemp1	= &ucsDiacritical1;
		pucsTemp2	= &ucsDiacritical2;
	}

	//	�����̃R�[�h�|�C���g�ɕϊ����ꂽ�ꍇ�A�����قȂ�Ɣ�r�ł��Ȃ��B
	//	���̏ꍇ�́ACompareConvertedString �֐����g�p����悤�ɓ`����K�v������B
	//	�����ł́A��r�̌��ʂ� -1 ���|�������̂�߂�l�Ƃ��邱�ƂŒʒm����B
	if (pucsTemp1->size() != pucsTemp2->size())
	{
		iRet	*= -1;
	}
	return iRet;
}

//======================================================================
//	CompareCodepointUCD
//
//	���ʂ� CSTR_LESS_THAN�ACSTR_EQUAL�ACSTR_GREATER_THAN �ŕԂ��B
//	�G���[�i�������s�K���Ȃǁj������� 0 ��Ԃ��B
//======================================================================
int CompareCodepointUCD(T_UCP cpSrc1, T_UCP cpSrc2, DWORD dwFlags, T_PCSTR_U pszLocale)
{
	//T_UCP	cpt1, cpt2;
	//bool	br1, br2;
	int		ic;

	bool	bIKanaCase		= COMPARESTRINGUCD_IS_IGNOREKANACASE(dwFlags);
	bool	bIKanaType		= COMPARESTRING_IS_NORM_IGNOREKANATYPE(dwFlags);
	bool	bIKanaWidth		= COMPARESTRING_IS_NORM_IGNOREWIDTH(dwFlags);
	bool	bICase			= COMPARESTRING_IS_NORM_IGNORECASE(dwFlags);
	bool	bNormalize		= COMPARESTRINGUCD_IS_NORMALIZE(dwFlags);
	bool	bIDiacritical	= COMPARESTRING_IS_NORM_IGNORENONSPACE(dwFlags);

	if (cpSrc1 == cpSrc2)	return CSTR_EQUAL;

	ic	= CompareCodepointUCD_Sub1(cpSrc1, cpSrc2, 
		bIKanaCase, bIKanaType, bIKanaWidth, bICase, bNormalize, bIDiacritical);
	if (ic < 0)	ic *= -1;	//	CompareConvertedString �֐��͎g�킸�A���ʂ����̂܂ܕԂ��B
	return ic;
}

//======================================================================
//	CompareStringUCD	(1)	PIFUnicodeBuffer �������Ƃ���
//
//	���̌^�������Ƃ��� CompareStringUCD �֐��́A
//	�����̃f�[�^���� PIFUnicodeBuffer ���쐬���āA���̊֐����Ăяo���B
//
//	CompareSting() �Ɠ��l��
//		CSTR_LESS_THAN, CSTR_EQUAL, CSTR_GREATER_THAN
//	��Ԃ��B�G���[�̏ꍇ�� 0 ��Ԃ��B
//======================================================================
#define	CSUCD_ABORT_MULTICODEPOINTS	-1

int CompareStringUCD(PIFUnicodeBuffer*	pUBuf1,
					 PIFUnicodeBuffer*	pUBuf2,
					 DWORD				dwFlags,
					 T_PCSTR_U			pszLocale)
{
	T_UCP	cp1, cp2;
	int		ic;

	bool	bNormalize, bIDiacritical, bIKanaCase, bIKanaType, bIKanaWidth, bICase;
	bool	bCStrSub1;

	//------------------------------------------------------------
	//	�I�v�V�������w�肳��Ă��Ȃ��ꍇ
	//------------------------------------------------------------
	if (dwFlags == 0)
	{
		return pUBuf1->Compare(pUBuf2);
	}

	bNormalize		= COMPARESTRINGUCD_IS_NORMALIZE(dwFlags);
	bIDiacritical	= COMPARESTRING_IS_NORM_IGNORENONSPACE(dwFlags);
	bIKanaCase		= COMPARESTRINGUCD_IS_IGNOREKANACASE(dwFlags);
	bIKanaType		= COMPARESTRING_IS_NORM_IGNOREKANATYPE(dwFlags);
	bIKanaWidth		= COMPARESTRING_IS_NORM_IGNOREWIDTH(dwFlags);
	bICase			= COMPARESTRING_IS_NORM_IGNORECASE(dwFlags);

	bCStrSub1	= bNormalize || bIKanaCase || bIKanaType || bIKanaWidth || bICase;

	//------------------------------------------------------------
	//	�����ꂩ�̃I�v�V�������w�肳��Ă���ꍇ�B
	//------------------------------------------------------------
	while (!pUBuf1->End() && !pUBuf2->End())
	{
		if (!pUBuf1->GetCp(&cp1))	break;
		if (!pUBuf2->GetCp(&cp2))	break;

		ic	= CompareCodepointUCD_Sub1(cp1, cp2,
			bIKanaCase, bIKanaType, bIKanaWidth, bICase, bNormalize, bIDiacritical);

		if (ic == CSTR_LESS_THAN)
		{
			return CSTR_LESS_THAN;
		}
		else if (ic == CSTR_GREATER_THAN)
		{
			return CSTR_GREATER_THAN;
		}
		else if (ic == CSTR_EQUAL)
		{
			pUBuf1->Next();
			pUBuf2->Next();
			continue;
		}
		else if (ic < 0)
		{
			return CompareConvertedStringUCD(pUBuf1, pUBuf2, dwFlags, pszLocale);
		}
		else
		{
			THROWPE_LOGIC_ERROR("CompareStringUCD");
		}
	}

	//	�ǂ�����I�[�ɒB���Ă���ꍇ�͓������Ɣ��肷��B
	if (pUBuf1->End() && pUBuf2->End())	return CSTR_EQUAL;

	//	Ignore Diacritical ���w�肳��Ă���ꍇ�A�c�����������܂Ƃ߂ĕϊ�����B
	if (bIDiacritical)
	{
		return CompareConvertedStringUCD_Z(pUBuf1, pUBuf2, dwFlags, pszLocale);
	}
	if (!pUBuf2->End())	return CSTR_LESS_THAN;
	return CSTR_GREATER_THAN;
}

//======================================================================
//	CompareStringUCD	(2)	Unicode ������������Ƃ���B
//======================================================================
int CompareStringUCD(T_PCSTR_U	pStr1,
					 int		izStr1,
					 T_PCSTR_U	pStr2,
					 int		izStr2,
					 DWORD		dwFlags,
					 T_PCSTR_U	pszLocale)
{
	PCUnicodeSegmentBuffer	ciUSeg1, ciUSeg2;
	PCUnicodeSzBuffer		ciUSz1, ciUSz2;
	PBCUnicodeStrBuffer	*pUBuf1, *pUBuf2;

	if (pStr1 == NULL || pStr2 == NULL || izStr1 == 0 || izStr2 == 0)	return 0;

	//------------------------------------------------------------
	//	�w�肳�ꂽ��������o�b�t�@�����O�p�̃N���X�ɃZ�b�g����B
	//------------------------------------------------------------
	if (izStr1 < 0)
	{
		ciUSz1.Set(pStr1);
		pUBuf1	= (PBCUnicodeStrBuffer*)&ciUSz1;
	}
	else
	{
		ciUSeg1.Set(pStr1, (size_t)izStr1);
		pUBuf1	= (PBCUnicodeStrBuffer*)&ciUSeg1;
	}

	if (izStr2 < 0)
	{
		ciUSz2.Set(pStr2);
		pUBuf2	= (PBCUnicodeStrBuffer*)&ciUSz2;
	}
	else
	{
		ciUSeg2.Set(pStr2, (size_t)izStr2);
		pUBuf2	= (PBCUnicodeStrBuffer*)&ciUSeg2;
	}

	//------------------------------------------------------------
	//	�I�v�V�������w�肳��Ă��Ȃ��ꍇ�͂��̂܂ܔ�r����B
	//------------------------------------------------------------
	if (dwFlags == 0)
	{
		return pUBuf1->Compare(pUBuf2);
	}

	//------------------------------------------------------------
	//	����ȊO�̏ꍇ�� CompareCpStringUCD �֐��ŏ�������B
	//------------------------------------------------------------
	return CompareStringUCD(pUBuf1, pUBuf2, dwFlags, pszLocale);
}

//======================================================================
//	CompareStringUCD	(3)	Codepoint ��������Ƃ���B
//======================================================================
int CompareStringUCD(const T_UCP*	pStr1,
					 int			izStr1,
					 const T_UCP*	pStr2,
					 int			izStr2,
					 DWORD			dwFlags,
					 T_PCSTR_U		pszLocale)
{
	PCCodepointSegmentBuffer	ciUSeg1, ciUSeg2;
	PCCodepointSzBuffer			ciUSz1, ciUSz2;
	PBCUnicodeStrBuffer			*pUBuf1, *pUBuf2;

	if (pStr1 == NULL || pStr2 == NULL || izStr1 == 0 || izStr2 == 0)	return 0;

	//------------------------------------------------------------
	//	�w�肳�ꂽ��������o�b�t�@�����O�p�̃N���X�ɃZ�b�g����B
	//------------------------------------------------------------
	if (izStr1 < 0)
	{
		ciUSz1.Set(pStr1);
		pUBuf1	= (PBCUnicodeStrBuffer*)&ciUSz1;
	}
	else
	{
		ciUSeg1.Set(pStr1, (size_t)izStr1);
		pUBuf1	= (PBCUnicodeStrBuffer*)&ciUSeg1;
	}

	if (izStr2 < 0)
	{
		ciUSz2.Set(pStr2);
		pUBuf2	= (PBCUnicodeStrBuffer*)&ciUSz2;
	}
	else
	{
		ciUSeg2.Set(pStr2, (size_t)izStr2);
		pUBuf2	= (PBCUnicodeStrBuffer*)&ciUSeg2;
	}

	//------------------------------------------------------------
	//	�I�v�V�������w�肳��Ă��Ȃ��ꍇ�͂��̂܂ܔ�r����B
	//------------------------------------------------------------
	if (dwFlags == 0)
	{
		return pUBuf1->Compare(pUBuf2);
	}

	//------------------------------------------------------------
	//	����ȊO�̏ꍇ�� CompareCpStringUCD �֐��ŏ�������B
	//------------------------------------------------------------
	return CompareStringUCD(pUBuf1, pUBuf2, dwFlags, pszLocale);
}

//======================================================================
//	CompareStringUCD	(4)	UIString �����Ƃ���B
//======================================================================
int		CompareStringUCD(UCPSTRING*	puisStr1,
						 UCPSTRING*	puisStr2,
						 DWORD		dwFlags,
						 T_PCSTR_U	pszLocale)
{
	PCUIStringBuffer	ciBuf1, ciBuf2;

	ciBuf1.Set(puisStr1);
	ciBuf2.Set(puisStr2);
	return CompareStringUCD(&ciBuf1, &ciBuf2, dwFlags, pszLocale);
}


//======================================================================
//	class PCCompareStringUCDOptions
//======================================================================
#ifdef	PDEBUG
//----------------------------------------------------------------------
//	Debug
//----------------------------------------------------------------------
void PCCompareStringUCDOptions::Debug(T_STRING_U* pstrDebug)
{
	T_PCSTR_U	pszTRUE1	= TQU(": ��\r\n");
	T_PCSTR_U	pszFALSE1	= TQU(": �~\r\n");
	T_PCSTR_U	pszTF;

#define	SELECT_TF(b)	((b) ? pszTRUE1 : pszFALSE1)

	PLib::PCCompareStringOptions::Debug<T_CHAR_U>(pstrDebug);

	pstrDebug->append(TQU("Normalize"));
	pszTF	= SELECT_TF(this->IsNormalize());
	pstrDebug->append(pszTF);

	pstrDebug->append(TQU("IgnoreKanaCase"));
	pszTF	= SELECT_TF(this->IsIgnoreKanaCase());
	pstrDebug->append(pszTF);
}

//----------------------------------------------------------------------
//	DebugSimple
//----------------------------------------------------------------------
bool PCCompareStringUCDOptions::DebugSimple(T_STRING_U* pstrDebug)
{
	T_STRING_U	strTemp;
	bool		br1	= false;
	bool		br2	= false;

	br1	= PLib::PCCompareStringOptions::DebugSimple<T_CHAR_U>(&strTemp);

	if (IsNormalize())
	{
		if (!strTemp.empty())	strTemp.append(TQU(","));
		strTemp.append(TQU("n"));
		br2	= true;
	}

	if (IsIgnoreKanaCase())
	{
		if (!strTemp.empty())	strTemp.append(TQU(","));
		strTemp.append(TQU("l"));
		br2	= true;
	}

	//if (br1)	pstrDebug->append(TQU(","));
	pstrDebug->append(strTemp);
	return (br1 == true || br2 == true);
}

#endif

NS_PLIB_UNICODE_END
