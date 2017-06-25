//	XLCTextEx_1.0x	:	Test

//	TestPRegEx03.cpp
//
#include "stdafx.h"
#ifdef	PDEBUG

//======================================================================
//	TestPRegEx03a
//======================================================================
void TestPRegEx03a()
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
	ie	= nDataRegEx03a;
	//ie	= 800;

	for (i = ib; i < ie; ++i)
	{
		ciRegEx.Init();
		ciReplace.Init();
		ciText.Init();

		pPat	= DataRegEx03a[i].pat;
		pRep	= DataRegEx03a[i].rep;
		pTxt	= DataRegEx03a[i].txt;
		pOpt	= DataRegEx03a[i].opt;

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

//======================================================================
//	TestPRegEx03b
//======================================================================
void TestPRegEx03b()
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
	T_PCSTR_U	pFmt	= TQU("%8d\r\n");
	T_PCSTR_U	pLF		= TQU("\r\n");
	T_PCSTR_U	pLF2	= TQU("\r\n\r\n");
	T_PCSTR_U	pHT		= TQU("\t");
	T_PCSTR_U	pHR		= TQU("----------------------------------------\r\n");

	PROFILER_RESET(0);
	PROFILER_RESET(1);
	PROFILER_RESET(2);
	PROFILER_SETDESC(0, TQU("全体          \t"));
	PROFILER_SETDESC(1, TQU("初期化        \t"));
	PROFILER_SETDESC(2, TQU("オプション設定\t"));
	PROFILER_SETDESC(3, TQU("NFA の作成    \t"));
	PROFILER_SETDESC(4, TQU("置換          \t"));

	ib	= 0;
	ie	= nDataRegEx03a;
	//ie	= 10;

	for (i = ib; i < ie; ++i)
	{
		pPat	= DataRegEx03a[i].pat;
		pRep	= DataRegEx03a[i].rep;
		pTxt	= DataRegEx03a[i].txt;
		pOpt	= DataRegEx03a[i].opt;

		PROFILER_START(0);

		PROFILER_START(1);
		ciRegEx.Init();
		ciReplace.Init();
		ciText.Init();
		PROFILER_STOP(1);

		PROFILER_START(2);
		ciRegEx.Options()->Set(pOpt);
		ciText.SetOptions(ciRegEx.Options());
		ciReplace.SetOptions(ciRegEx.Options());
		PROFILER_STOP(2);

		br	= ciRegEx.SetPattern(pPat);
		if (!br)	goto OP_END;

		strError.clear();
		PROFILER_START(3);
		br	= ciRegEx.BuildNFA(&strError);
		PROFILER_STOP(3);
		if (!br)	goto OP_END;
		//strDebug.clear();
		//ciRegEx.Debug(&strDebug);

		br	= ciText.SetText(pTxt);
		if (!br)	goto OP_END;

		br	= ciReplace.SetReplacement(pRep);
		if (!br)	goto OP_END;

		ciText.Begin();
		ciText.InitReferences();
		strOutput.clear();
		PROFILER_START(4);
		br	= PLib::PRegExReplace(
			&strOutput, &ciRegEx, &ciReplace, &ciText, &strDebug, &iMatch);
		PROFILER_STOP(4);
		PROFILER_STOP(0);

OP_END:
		PROFILER_STOP(0);
	}

	PROFILER_GETTOTAL(&strTest, pFmt);
}

//======================================================================
//	TestPRegEx03c
//======================================================================
void SubTestPRegEx03c(T_PCSTR_U		pPat,
					  T_PCSTR_U		pRep,
					  T_PCSTR_U		pTxt,
					  T_PCSTR_U		pOpt)
{
	PROFILER_START(1);
	PLib::PCRegEx				ciRegEx;
	PLib::PCRegExReplacement	ciReplace;
	PLib::PCRegExText			ciText;
	PROFILER_STOP(1);

	bool		br;
	int			iMatch;
	T_STRING_U	strOutput, strDebug, strError;

	PROFILER_START(2);
	ciRegEx.Init();
	ciRegEx.Options()->Set(pOpt);
	br	= ciRegEx.SetPattern(pPat);
	PROFILER_STOP(2);

	PROFILER_START(3);
	ciReplace.Init();
	ciReplace.SetOptions(ciRegEx.Options());
	br	= ciReplace.SetReplacement(pRep);
	PROFILER_STOP(3);

	PROFILER_START(4);
	ciText.Init();
	ciText.SetOptions(ciRegEx.Options());
	br	= ciText.SetText(pTxt);
	ciText.Begin();
	ciText.InitReferences();
	PROFILER_STOP(4);

	strError.clear();
	PROFILER_START(5);
	br	= ciRegEx.BuildNFA(&strError);
	PROFILER_STOP(5);
	if (!br)	goto OP_END;

	strOutput.clear();
	PROFILER_START(6);
	br	= PLib::PRegExReplace(
		&strOutput, &ciRegEx, &ciReplace, &ciText, &strDebug, &iMatch);
	PROFILER_STOP(6);

OP_END:
	return;
}

void TestPRegEx03c()
{
	int			i, ib, ie;
	T_STRING_U	strTest;
	T_PCSTR_U	pFmt	= TQU("%8d");

	PROFILER_RESET(0);
	PROFILER_RESET(1);
	PROFILER_RESET(2);
	PROFILER_SETDESC(0,		TQU("全体              \t"));
	PROFILER_SETDESC(1,		TQU("宣言              \t"));
	PROFILER_SETDESC(2,		TQU("正規表現の初期化  \t"));
	PROFILER_SETDESC(3,		TQU("置換文字列の初期化\t"));
	PROFILER_SETDESC(4,		TQU("対象文字列の初期化\t"));
	PROFILER_SETDESC(5,		TQU("NFA の作成        \t"));
	PROFILER_SETDESC(6,		TQU("置換              \t"));

	ib	= 0;
	ie	= nDataRegEx03a;

	PROFILER_START(0);

	for (i = ib; i < ie; ++i)
	{
		SubTestPRegEx03c(
			DataRegEx03a[i].pat,
			DataRegEx03a[i].rep,
			DataRegEx03a[i].txt,
			DataRegEx03a[i].opt);
	}

	PROFILER_STOP(0);

	PROFILER_GETTOTAL(&strTest, pFmt);
}

#endif

//======================================================================
//	TestPRegEx03
//======================================================================
void TestPRegEx03()
{
#ifdef	PDEBUG

	//TestPRegEx03a();
	//TestPRegEx03b();
	TestPRegEx03c();
	//TestPRegEx03d();

#endif
}
