//	XLCTextEx_1.0x	:	Test

//	TestPRegEx05.cpp
//
#include "stdafx.h"
#ifdef	PDEBUG

T_PCSTR_U	pMatch[]	=
{
	TQU("○"),
	TQU("×"),
	TQU("Ｅ"),
	TQU("Ｂ"),
};

//======================================================================
//	TestPRegEx05a
//======================================================================
void TestPRegEx05a()
{
	PLib::PCRegEx				ciRegEx;
	PLib::PCRegExReplacement	ciReplace;
	PLib::PCRegExText			ciText;

	//T_PCSTR_U	pDsc;
	T_PCSTR_U	pPat, pRep, pTxt, pOpt;
	bool		br;
	int			i, ib, ie;
	int			iRes;
	int			iMatch;
	T_STRING_U	strOutput, strDebug, strError;
	T_CHAR_U	BufTemp[128];

	ciText.SetDecodeFlags(PCTEXT_FLAG_DECODE_NONE);

	T_STRING_U	strTest;
	//T_PCSTR_U	pLog;
	T_PCSTR_U	pLF		= TQU("\r\n");
	T_PCSTR_U	pLF2	= TQU("\r\n\r\n");
	T_PCSTR_U	pHT		= TQU("\t");
	T_PCSTR_U	pHR		= TQU("----------------------------------------\r\n");

	ib	= 400;
	//ie	= nDataRegEx05a;
	ie	= 600;
	if (ib < 0)	ib = 0;
	if (ie > nDataRegEx05a) ie = nDataRegEx05a;

	for (i = ib; i < ie; ++i)
	{
		ciRegEx.Init();
		ciReplace.Init();
		ciText.Init();

		pPat	= DataRegEx05a[i].pat;
		pTxt	= DataRegEx05a[i].txt;
		pOpt	= DataRegEx05a[i].opt;
		iRes	= PERL_MATCH_ERROR;

		swprintf_s(BufTemp, 128, TQU("%04d ----------------------------------------\r\n"), i);
		strTest.append(BufTemp);
		strTest.append(TQU("Pat \t: "));
		strTest.append(pPat);
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
			strTest.append(TQU("Bug \t: パターンを設定できませんでした。"));
			iRes	= PERL_MATCH_BUG;
			goto NEXT_TEST;
		}

		br	= ciText.SetText(pTxt);
		if (!br)
		{
			strTest.append(TQU("Bug \t: 処理対象のテキストを設定できませんでした。"));
			iRes	= PERL_MATCH_BUG;
			goto NEXT_TEST;
		}

		strError.clear();
		br	= ciRegEx.BuildNFA(&strError);
		if (!br)
		{
			//strTest.append(TQU("Error\t: NFA を作成できませんでした。:\t"));
			//strTest.append(strError);
			iRes	= PERL_MATCH_ERROR;
			goto SHOW_RESULT;
		}
		//strDebug.clear();
		//ciRegEx.Debug(&strDebug);

		ciText.Begin();
		ciText.InitReferences();
		br	= ciRegEx.Match(&ciText);
		if (br)
		{
			iRes	= PERL_MATCH_YES;
		}
		else
		{
			iRes	= PERL_MATCH_NO;
		}

SHOW_RESULT:
		//strTest.append(TQU("Match\t: "));
		if (iRes == DataRegEx05a[i].res)
		{
			strTest.append(TQU("○  \t: "));
		}
		else
		{
			switch (DataRegEx05a[i].res)
			{
			case PERL_MATCH_YES:
			case PERL_MATCH_NO:
				strTest.append(TQU("×  \t: "));
				break;
			case PERL_MATCH_ERROR:
				strTest.append(TQU("△  \t: "));
				break;
			case PERL_MATCH_PERLBUG:
			default:
				strTest.append(TQU("▲  \t: "));
				break;
			}
		}
		switch (iRes)
		{
		case PERL_MATCH_YES:
			strTest.append(TQU("Match"));
			break;
		case PERL_MATCH_NO:
			strTest.append(TQU("Not Match"));
			break;
		case PERL_MATCH_ERROR:
			strTest.append(strError);
			break;
		default:
			strTest.append(TQU("Unknown Error"));
			break;
		}

NEXT_TEST:
		strTest.append(pLF2);
	}
}

#endif

//======================================================================
//	TestPRegEx05
//======================================================================
void TestPRegEx05()
{
#ifdef	PDEBUG

	TestPRegEx05a();

#endif
}
