//	XLCTextEx_1.0x	:	Test

//	TestPRegEx01.cpp
//
#include "stdafx.h"
#ifdef	PDEBUG

//======================================================================
//	TestPRegEx01a
//======================================================================
typedef	T_PCSTR_U	(TR01a)[4];

TR01a	DR01a[]	=
{
	/*
	TQU(""),
	TQU(""),
	TQU(""),
	TQU(""),
	*/

	TQU(")("),
	TQU("<$&>"),
	TQU("-"),
	TQU("i"),
};
int	nDR01a	= sizeof(DR01a) / sizeof(TR01a);

void TestPRegEx01a()
{
	PLib::Debug::ClearLog<T_CHAR_U>();

	PLib::PCRegEx				ciRegEx;
	PLib::PCRegExReplacement	ciReplace;
	PLib::PCRegExText			ciText;

	T_PCSTR_U	pPat, pRep, pTxt, pOpt;
	bool		br;
	int			i, ib, ie;
	int			iTemp;
	T_STRING_U	strOutput, strDebug, strError;

	T_STRING_U	strTest, strLog;
	T_PCSTR_U	pLF		= TQU("\r\n");
	T_PCSTR_U	pLF2	= TQU("\r\n\r\n");
	T_PCSTR_U	pHT		= TQU("\t");
	T_PCSTR_U	pHR		= TQU("----------------------------------------\r\n");

	ib	= 0;
	ie	= nDR01a;
	//ie	= 1;

	for (i = ib; i < ie; ++i)
	{
		ciRegEx.Init();
		ciReplace.Init();
		ciText.Init();

		pPat	= DR01a[i][0];
		pRep	= DR01a[i][1];
		pTxt	= DR01a[i][2];
		pOpt	= DR01a[i][3];

		strTest.append(pHR);
		strTest.append(TQU("Pat :\t"));
		strTest.append(pPat);
		strTest.append(pLF);
		strTest.append(TQU("Rep :\t"));
		strTest.append(pRep);
		strTest.append(pLF);
		strTest.append(TQU("Txt :\t"));
		strTest.append(pTxt);
		strTest.append(pLF);
		strTest.append(TQU("Opt :\t"));
		strTest.append(pOpt);
		strTest.append(pLF);

		ciRegEx.Options()->Set(pOpt);
		ciText.SetOptions(ciRegEx.Options());
		ciReplace.SetOptions(ciRegEx.Options());

		br	= ciRegEx.SetPattern(pPat);
		if (br)
		{
			br	= ciRegEx.BuildNFA(&strError);
		}
		if (!br)	return;
		strDebug.clear();
		ciRegEx.Debug(&strDebug);

		br	= ciText.SetText(pTxt);
		if (!br)	return;

		br	= ciReplace.SetReplacement(pRep);
		strDebug.clear();
		ciReplace.Debug(&strDebug);
		if (!br)	return;

		//strOutput.clear();
		//ciText.Begin();
		//ciText.InitReferences();

		//br	= ciRegEx.Match(&ciText);
		//br	= ciReplace.Format(&strOutput, &ciText);

		strOutput.clear();
		ciText.Begin();
		ciText.InitReferences();

		br	= PLib::PRegExReplace(
			&strOutput, &ciRegEx, &ciReplace, &ciText, &strDebug, &iTemp);

		PLib::Debug::GetLog<T_CHAR_U>(&strLog);
		strTest.append(strOutput);
		strTest.append(pLF2);
	}
}

//======================================================================
//	TestPRegEx01b	DataRegEx01 �ɂ��e�X�g
//======================================================================
//----------------------------------------------------------------------
//	SubPRegEx01b
//----------------------------------------------------------------------
void SubPRegEx01b(T_STRING_U* pstrTest, TDataRegEx01* pData, int nData, T_PCSTR_U pTitle = NULL)
{
	PLib::PCRegEx				ciRegEx;
	PLib::PCRegExReplacement	ciReplace;
	PLib::PCRegExText			ciText;

	T_PCSTR_U		pDsc, pPat, pRep, pTxt, pOpt;
	bool			br;
	TDataRegEx01*	pDataE;
	int				ib, ie;
	int				iMatch;
	T_STRING_U		strOutput, strDebug, strError;

	T_PCSTR_U	pLF		= TQU("\r\n");
	T_PCSTR_U	pLF2	= TQU("\r\n\r\n");
	T_PCSTR_U	pHT		= TQU("\t");
	T_PCSTR_U	pHRs	= TQU("----------------------------------------\r\n");
	T_PCSTR_U	pHRd	= TQU("========================================\r\n");

	if (pTitle != NULL)
	{
		pstrTest->append(pHRd);
		pstrTest->append(pTitle);
		pstrTest->append(pLF);
		pstrTest->append(pHRd);
	}

	ib	= 0;
	ie	= nData;
	//ie	= 1;
	pData	+= ib;
	pDataE	= pData + ie;

	for ( ; pData < pDataE; ++pData)
	{
		ciRegEx.Init();
		ciReplace.Init();
		ciText.Init();

		pDsc	= pData->dsc;
		pPat	= pData->pat;
		pRep	= pData->rep;
		pTxt	= pData->txt;
		pOpt	= pData->opt;

		pstrTest->append(pHRs);
		pstrTest->append(pDsc);
		pstrTest->append(pLF);
		pstrTest->append(TQU("Pat \t: "));
		pstrTest->append(pPat);
		pstrTest->append(pLF);
		pstrTest->append(TQU("Rep \t: "));
		pstrTest->append(pRep);
		pstrTest->append(pLF);
		pstrTest->append(TQU("Txt \t: "));
		pstrTest->append(pTxt);
		pstrTest->append(pLF);
		pstrTest->append(TQU("Opt \t: "));
		pstrTest->append(pOpt);
		pstrTest->append(pLF);

		ciRegEx.Options()->Set(pOpt);
		ciText.SetOptions(ciRegEx.Options());
		ciReplace.SetOptions(ciRegEx.Options());

		br	= ciRegEx.SetPattern(pPat);
		if (!br)
		{
			pstrTest->append(TQU("Error\t: �p�^�[����ݒ�ł��܂���ł����B"));
			pstrTest->append(pLF2);
			continue;
		}

		strError.clear();
		br	= ciRegEx.BuildNFA(&strError);
		if (!br)
		{
			pstrTest->append(TQU("Error\t: NFA ���쐬�ł��܂���ł����B:\t"));
			pstrTest->append(strError);
			pstrTest->append(pLF2);
			continue;
		}
		//strDebug.clear();
		//ciRegEx.Debug(&strDebug);

		br	= ciText.SetText(pTxt);
		if (!br)
		{
			pstrTest->append(TQU("Error\t: �����Ώۂ̃e�L�X�g��ݒ�ł��܂���ł����B"));
			pstrTest->append(pLF2);
			continue;
		}

		br	= ciReplace.SetReplacement(pRep);
		if (!br)
		{
			pstrTest->append(TQU("Error\t: �u���������ݒ�ł��܂���ł����B"));
			pstrTest->append(pLF2);
			continue;
		}

		ciText.Begin();
		ciText.InitReferences();
		br	= ciRegEx.Match(&ciText);
		pstrTest->append(TQU("Match\t: "));
		if (br)
		{
			pstrTest->append(TQU("��"));
		}
		else
		{
			pstrTest->append(TQU("�~"));
		}
		pstrTest->append(pLF);

		//ciText.Begin();
		//ciText.InitReferences();
		strOutput.clear();
		br	= ciReplace.Format(&strOutput, &ciText);
		pstrTest->append(TQU("Format\t: "));
		pstrTest->append(strOutput);
		pstrTest->append(pLF);

		ciText.Begin();
		ciText.InitReferences();
		strOutput.clear();
		br	= PLib::PRegExReplace(
			&strOutput, &ciRegEx, &ciReplace, &ciText, &strDebug, &iMatch);
		pstrTest->append(TQU("Replace\t: "));
		pstrTest->append(strOutput);

		pstrTest->append(pLF2);
	}
}

//----------------------------------------------------------------------
//	TestPRegEx01b
//----------------------------------------------------------------------
void TestPRegEx01b()
{
	T_STRING_U	strTest;

	//	00	�󕶎���̏���
	SubPRegEx01b(&strTest, DataRegEx01_00, nDataRegEx01_00, TQU("�󕶎���̏���"));

	//	01	�I�v�V����
	SubPRegEx01b(&strTest, DataRegEx01_01, nDataRegEx01_01, TQU("�I�v�V����"));

	//	02	�G�X�P�[�v�V�[�P���X
	SubPRegEx01b(&strTest, DataRegEx01_02, nDataRegEx01_02, TQU("�G�X�P�[�v�V�[�P���X"));

	//	03	�����N���X
	SubPRegEx01b(&strTest, DataRegEx01_03, nDataRegEx01_03, TQU("�����N���X"));

	//	04	�ʒu�ɂ��ƍ�
	SubPRegEx01b(&strTest, DataRegEx01_04, nDataRegEx01_04, TQU("�ʒu�ɂ��ƍ�"));

	//	05	����Q��
	SubPRegEx01b(&strTest, DataRegEx01_05, nDataRegEx01_05, TQU("����Q��"));

	//	06	�O����v��
	SubPRegEx01b(&strTest, DataRegEx01_06, nDataRegEx01_06, TQU("�O����v��"));

	//	07	�ʎw��q
	SubPRegEx01b(&strTest, DataRegEx01_07, nDataRegEx01_07, TQU("�ʎw��q"));

	//	08	�I��
	SubPRegEx01b(&strTest, DataRegEx01_08, nDataRegEx01_08, TQU("�I��"));

	//	09	�u���P�b�g�\��
	SubPRegEx01b(&strTest, DataRegEx01_09, nDataRegEx01_09, TQU("�u���P�b�g�\��"));

	//	10	�u��������
	SubPRegEx01b(&strTest, DataRegEx01_10, nDataRegEx01_10, TQU("�u��������"));

	//	11	�G���[�΍�
	SubPRegEx01b(&strTest, DataRegEx01_11, nDataRegEx01_11, TQU("�G���[�΍�"));
}


//======================================================================
//	TestPRegEx01bToExcel	DataRegEx01 �̃f�[�^���^�u��؂�ŏo��
//======================================================================
//----------------------------------------------------------------------
//	SubPRegEx01bToExcel
//----------------------------------------------------------------------
void SubPRegEx01bToExcel(T_STRING_U* pstrTest, TDataRegEx01* pData, int nData)
{
	TDataRegEx01*	pDataE	= pData + nData;
	T_STRING_U		strTemp;
	T_PCSTR_U		pc;
	T_PCSTR_U		pLF		= TQU("\r\n");
	T_PCSTR_U		pHT		= TQU("\t");

	for ( ; pData < pDataE; ++pData)
	{
		strTemp.clear();
		for (pc = pData->dsc; *pc; ++pc)
		{
			if ((UINT)*pc == (UINT)TQU('\t'))
			{
				strTemp.append(1, TQU(' '));
			}
			else
			{
				strTemp.append(1, *pc);
			}
		}

		pstrTest->append(strTemp);
		pstrTest->append(pHT);

		strTemp.clear();
		for (pc = pData->pat; *pc; ++pc)
		{
			if ((T_CHAR_U)*pc == (T_CHAR_U)TQU('\t'))
			{
				strTemp.append(TQU("\\t"));
			}
			else if ((T_CHAR_U)*pc == (T_CHAR_U)TQU('\r'))
			{
				strTemp.append(TQU("\\r"));
			}
			else if ((T_CHAR_U)*pc == (T_CHAR_U)TQU('\n'))
			{
				strTemp.append(TQU("\\n"));
			}
			else
			{
				strTemp.append(1, *pc);
			}
		}
		pstrTest->append(strTemp);
		pstrTest->append(pHT);

		pstrTest->append(pData->rep);
		pstrTest->append(pHT);

		strTemp.clear();
		for (pc = pData->txt; *pc; ++pc)
		{
			if ((T_CHAR_U)*pc == (T_CHAR_U)TQU('\t'))
			{
				strTemp.append(TQU("\\t"));
			}
			else if ((T_CHAR_U)*pc == (T_CHAR_U)TQU('\r'))
			{
				strTemp.append(TQU("\\r"));
			}
			else if ((T_CHAR_U)*pc == (T_CHAR_U)TQU('\n'))
			{
				strTemp.append(TQU("\\n"));
			}
			else
			{
				strTemp.append(1, *pc);
			}
		}
		pstrTest->append(strTemp);
		pstrTest->append(pHT);

		pstrTest->append(pData->opt);
		pstrTest->append(pLF);
	}
	pstrTest->append(pLF);
}

//----------------------------------------------------------------------
//	TestPRegEx01bToExcel
//----------------------------------------------------------------------
void TestPRegEx01bToExcel()
{
	T_STRING_U	strTest;

	//	00	�󕶎���̏���
	SubPRegEx01bToExcel(&strTest, DataRegEx01_00, nDataRegEx01_00);

	//	01	�I�v�V����
	SubPRegEx01bToExcel(&strTest, DataRegEx01_01, nDataRegEx01_01);

	//	02	�G�X�P�[�v�V�[�P���X
	SubPRegEx01bToExcel(&strTest, DataRegEx01_02, nDataRegEx01_02);

	//	03	�����N���X
	SubPRegEx01bToExcel(&strTest, DataRegEx01_03, nDataRegEx01_03);

	//	04	�ʒu�ɂ��ƍ�
	SubPRegEx01bToExcel(&strTest, DataRegEx01_04, nDataRegEx01_04);

	//	05	����Q��
	SubPRegEx01bToExcel(&strTest, DataRegEx01_05, nDataRegEx01_05);

	//	06	�O����v��
	SubPRegEx01bToExcel(&strTest, DataRegEx01_06, nDataRegEx01_06);

	//	07	�ʎw��q
	SubPRegEx01bToExcel(&strTest, DataRegEx01_07, nDataRegEx01_07);

	//	08	�I��
	SubPRegEx01bToExcel(&strTest, DataRegEx01_08, nDataRegEx01_08);

	//	09	�u���P�b�g�\��
	SubPRegEx01bToExcel(&strTest, DataRegEx01_09, nDataRegEx01_09);

	//	10	�u��������
	SubPRegEx01bToExcel(&strTest, DataRegEx01_10, nDataRegEx01_10);

	//	11	�G���[�΍�
	SubPRegEx01bToExcel(&strTest, DataRegEx01_11, nDataRegEx01_11);
}

#endif

//======================================================================
//	TestPRegEx01
//======================================================================
void TestPRegEx01()
{
#ifdef	PDEBUG

	TestPRegEx01a();
	//TestPRegEx01b();
	//TestPRegEx01bToExcel();
	//TestPRegEx01c();

#endif
}
