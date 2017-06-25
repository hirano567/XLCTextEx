//	XLCTextEx_1.0x	:	Test

//	TestPRegEx02.cpp
//
#include "stdafx.h"
#ifdef	PDEBUG

//======================================================================
//	TestPRegEx02a
//======================================================================
void TestPRegEx02a()
{
	PLib::PCRegEx				ciRegEx;
	PLib::PCRegExReplacement	ciReplace;
	PLib::PCRegExText			ciText;

	//T_PCSTR_U	pDsc;
	T_PCSTR_U	pPat, pRep, pTxt, pOpt;
	bool		br;
	int			i, ib, ie;
	int			iMatch;
	T_STRING_U	strOutput, strDebug, strError;

	T_STRING_U	strTest;
	//T_PCSTR_U	pLog;
	T_PCSTR_U	pLF		= TQU("\r\n");
	T_PCSTR_U	pLF2	= TQU("\r\n\r\n");
	T_PCSTR_U	pHT		= TQU("\t");
	T_PCSTR_U	pHR		= TQU("----------------------------------------\r\n");

	ib	= 0;
	ie	= nDataRegEx02a;
	//ie	= 1;

	for (i = ib; i < ie; ++i)
	{
		ciRegEx.Init();
		ciReplace.Init();
		ciText.Init();

		pPat	= DataRegEx02a[i].pat;
		pRep	= DataRegEx02a[i].rep;
		pTxt	= DataRegEx02a[i].txt;
		pOpt	= DataRegEx02a[i].opt;

		strTest.append(pHR);
		strTest.append(TQU("Pat \t: "));
		strTest.append(pPat);
		strTest.append(pLF);
		strTest.append(TQU("Rep \t: "));
		strTest.append(pRep);
		strTest.append(pLF);
		strTest.append(TQU("Txt \t: "));
		strTest.append(pTxt);
		strTest.append(pLF);
		strTest.append(TQU("Opt \t: "));
		strTest.append(pOpt);
		strTest.append(pLF);

		ciRegEx.Options()->Set(pOpt);
		ciText.SetOptions(ciRegEx.Options());
		ciReplace.SetOptions(ciRegEx.Options());

		br	= ciRegEx.SetPattern(pPat);
		if (!br)
		{
			strTest.append(TQU("Error\t: パターンを設定できませんでした。"));
			strTest.append(pLF2);
			continue;
		}

		strError.clear();
		br	= ciRegEx.BuildNFA(&strError);
		if (!br)
		{
			strTest.append(TQU("Error\t: NFA を作成できませんでした。:\t"));
			strTest.append(strError);
			strTest.append(pLF2);
			continue;
		}
		//strDebug.clear();
		//ciRegEx.Debug(&strDebug);

		br	= ciText.SetText(pTxt);
		if (!br)
		{
			strTest.append(TQU("Error\t: 処理対象のテキストを設定できませんでした。"));
			strTest.append(pLF2);
			continue;
		}

		br	= ciReplace.SetReplacement(pRep);
		if (!br)
		{
			strTest.append(TQU("Error\t: 置換文字列を設定できませんでした。"));
			strTest.append(pLF2);
			continue;
		}

		ciText.Begin();
		ciText.InitReferences();
		br	= ciRegEx.Match(&ciText);
		strTest.append(TQU("Match\t: "));
		if (br)
		{
			strTest.append(TQU("○"));
		}
		else
		{
			strTest.append(TQU("×"));
		}
		strTest.append(pLF);

		//ciText.Begin();
		//ciText.InitReferences();
		strOutput.clear();
		br	= ciReplace.Format(&strOutput, &ciText);
		strTest.append(TQU("Format\t: "));
		strTest.append(strOutput);
		strTest.append(pLF);

		ciText.Begin();
		ciText.InitReferences();
		strOutput.clear();
		br	= PLib::PRegExReplace(
			&strOutput, &ciRegEx, &ciReplace, &ciText, &strDebug, &iMatch);
		strTest.append(TQU("Replace\t: "));
		strTest.append(strOutput);

		strTest.append(pLF2);
	}
}

#endif

//======================================================================
//	TestPRegEx02
//======================================================================
void TestPRegEx02()
{
#ifdef	PDEBUG

	TestPRegEx02a();
	//TestPRegEx02b();
	//TestPRegEx02c();
	//TestPRegEx02d();

#endif
}
