//	XLCTextEx_1.0x	:	Test

//	TestPTr01.cpp
//
#include "stdafx.h"
#ifdef	PDEBUG

//======================================================================
//	TestPTr01a
//======================================================================
typedef	T_PCSTR_U	(TTR01a)[4];

TTR01a	DTR01a[]	=
{
	/*
	TQU("あいう-せそ"),
	TQU("ア-アイ-ケ[.ko.]サ"),
	TQU("そせすしさこけくきかおえういあ"),
	TQU(""),

	TQU("[.ガ.][.ギ.][.グ.][.ゲ.][.ゴ.]"),
	TQU("[.GA.]ぎ[.GU.]げ[.GO.]"),
	TQU("ガギグゲゴカ゛キ゛ク゛ケ゛コ゛ｶﾞｷﾞｸﾞｹﾞｺﾞ"),
	TQU("n"),
	*/

	TQU("[.ガ.]"),
	TQU("[.GA.]"),
	TQU("ガカ\x3099カ゛ｶﾞギ"),
	TQU(""),

	TQU("[.ガ.]"),
	TQU("[.GA.]"),
	TQU("ガカ\x3099カ゛ｶﾞギ"),
	TQU("-n"),
};
int	nDTR01a	= sizeof(DTR01a) / sizeof(TTR01a);

void TestPTr01a()
{
	PLib::PCTransChar	ciTr;
	T_PCSTR_U	pss, psd, pst, pso;
	size_t		zso;
	int			i;
	bool		br;
	T_STRING_U	strOutput, strDebug;
	T_PCSTR_U	pLF		= TQU("\r\n");
	T_PCSTR_U	pLF2	= TQU("\r\n\r\n");
	T_PCSTR_U	pHR		= TQU("----------------------------------------\r\n");

	for (i = 0; i < nDTR01a; ++i)
	{
		pss	= DTR01a[i][0];
		psd	= DTR01a[i][1];
		pst	= DTR01a[i][2];
		pso	= DTR01a[i][3];
		zso	= wcslen(pso);
		strDebug.append(pHR);

		ciTr.Clear();
		if (zso > 0)	ciTr.SetOpt(pso, zso);
		br	= ciTr.SetTrans(pss, psd);
		if (!br)
		{
			strDebug.append(TQU("SetTrans failed.\r\n\r\n"));
			continue;
		}
		ciTr.Debug(&strDebug);
		strDebug.append(pLF);

		strDebug.append(pst);
		strDebug.append(pLF);
		strOutput.clear();

		br	= ciTr.Translate(&strOutput, pst);

		strDebug.append(strOutput);
		strDebug.append(pLF2);
	}
}

#endif

//======================================================================
//	TestPTr01
//======================================================================
void TestPTr01()
{
#ifdef	PDEBUG

	TestPTr01a();
	//TestPTr01b();
	//TestPTr01bToExcel();
	//TestPTr01c();

#endif
}
