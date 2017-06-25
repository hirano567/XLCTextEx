//	XLCTextEx_1.0x	:	Test

//	Prototype01.cpp
//
#include "stdafx.h"
#ifdef	PDEBUG
NS_TEST_BEGIN

//======================================================================
//	Prototype01a
//======================================================================
//======================================================================
//	class PCGrepOptions
//======================================================================
class PCGrepOptions
{
private:
	bool		bRowNumber;
	bool		bSheetName;
	bool		bNonMatching;
	T_STRING_U	strMatchingDelimiter;
	T_STRING_U	strOutputDelimiter;

public:
	bool	IsRowNumber()			{ return bRowNumber; }
	bool	IsSheetName()			{ return bSheetName; }
	bool	IsNonMatching()			{ return bNonMatching; }

	void	SetRowNumber()			{ bRowNumber = true; }
	void	SetSheetName()			{ bSheetName = true; }
	void	SetNonMatching()		{ bNonMatching = true; }

	void		SetMatchingDelimiter()					{ strMatchingDelimiter.clear(); }
	void		SetMatchingDelimiter(T_UCP cp)			{ PLib::Unicode::ConvertFromCodepoint(&strMatchingDelimiter, cp); }
	void		SetMatchingDelimiter(T_PCSTR_U psz)		{ strMatchingDelimiter.assign(psz); }
	T_STRING_U*	GetMatchingDelimiter()					{ return &strMatchingDelimiter; }

	void		SetOutputDelimiter()					{ strOutputDelimiter.assign(1, (T_UCP)0x09); }
	void		SetOutputDelimiter(T_UCP c)				{ PLib::Unicode::ConvertFromCodepoint(&strOutputDelimiter, c); }
	void		SetOutputDelimiter(T_PCSTR_U psz)		{ strOutputDelimiter.assign(psz); }
	T_STRING_U*	GetOutputDelimiter()					{ return &strOutputDelimiter; }

	void	UnsetRowNumber()			{ bRowNumber = false; }
	void	UnsetSheetName()			{ bSheetName = false; }
	void	UnsetNonMatching()			{ bNonMatching = false; }
	void	UnsetMatchingDelimiter()	{ strMatchingDelimiter.clear(); }
	void	UnsetOutputDelimiter()		{ strOutputDelimiter.assign(1, TQU('\t')); }

	void	Reset()
	{
		UnsetRowNumber();
		UnsetSheetName();
		UnsetNonMatching();
		UnsetMatchingDelimiter();
		UnsetOutputDelimiter();
	}

	PCGrepOptions()
	{
		Reset();
	}

	void	Set(T_PCSTR_U pStr, size_t zStr);

#ifdef	PDEBUG
	void	Debug(T_STRING_U* pstrDebug);
#endif
};

//----------------------------------------------------------------------
//	PCGrepOptions::Set
//----------------------------------------------------------------------
void PCGrepOptions::Set(T_PCSTR_U pStr, size_t zStr)
{
#define	XLCGREP_FLAG_DECODE	0		\
	| PCTEXT_FLAG_DECODE_OCTAL		\
	| PCTEXT_FLAG_DECODE_HEX		\
	| PCTEXT_FLAG_DECODE_ESCCTRL	\
	| PCTEXT_FLAG_DECODE_UNICODE	\
	| PCTEXT_FLAG_DECODE_ITSELF
//	| PCTEXT_FLAG_DECODE_CTRLCHAR

	PLib::PCTextUR	ciSrc;
	T_UCP			cpSrc;
	int				ir;
	T_PCSTR_U		pszCRLF	= TQU("\r\n");

#ifdef	PDEBUG
	T_STRING_U	strDebug;
#endif

	Reset();
	if (pStr == NULL || zStr < 1)	return;

	ciSrc.SetDecodeFlags(XLCGREP_FLAG_DECODE);
	ciSrc.SetDecodeControlFunction(PLib::RegEx::DecodeEscapedControl);
	ciSrc.SetText(pStr, zStr);

#ifdef	PDEBUG
	ciSrc.Debug(&strDebug);
#endif

	for (ciSrc.Begin(); !ciSrc.End(); ciSrc.Next())
	{
		ir	= ciSrc.GetCurrentCp(&cpSrc);
		if (!PCTEXT_GETVALIDCP(ir))	continue;

		switch (cpSrc)
		{
		case (T_UCP)'n':
		case (T_UCP)0xFF4E:
			SetRowNumber();
			break;

		case (T_UCP)'v':
		case (T_UCP)0xFF56:
			SetNonMatching();
			break;

		case (T_UCP)'h':
		case (T_UCP)0xFF48:
			SetSheetName();
			break;

		case (T_UCP)'c':
		case (T_UCP)0xFF43:
			ciSrc.Next();
			ir	= ciSrc.GetCurrentCp(&cpSrc);
			if (!PCTEXT_GETVALIDCP(ir))
			{
				SetMatchingDelimiter();
			}
			else if (cpSrc == (T_UCP)'N' || cpSrc == (T_UCP)0xFF2E)
			{
				strMatchingDelimiter.clear();
			}
			else
			{
				strMatchingDelimiter.clear();
				SetMatchingDelimiter(cpSrc);
			}
			break;

		case (T_UCP)'d':
		case (T_UCP)0xFF44:
			ciSrc.Next();
			ir	= ciSrc.GetCurrentCp(&cpSrc);
			if (!PCTEXT_GETVALIDCP(ir))
			{
				SetOutputDelimiter();
			}
			else if (cpSrc == (T_UCP)'N' || cpSrc == (T_UCP)0xFF2E)
			{
				strOutputDelimiter.clear();
			}
			else if (cpSrc == (T_UCP)'L' || cpSrc == (T_UCP)0xFF2C)
			{
				strOutputDelimiter.clear();
				SetOutputDelimiter(pszCRLF);
			}
			else
			{
				strOutputDelimiter.clear();
				SetOutputDelimiter(cpSrc);
			}
			break;

		default:
			break;
		}
	}
}

//----------------------------------------------------------------------
//	PCGrepOptions::Debug
//----------------------------------------------------------------------
#ifdef	PDEBUG
void PCGrepOptions::Debug(T_STRING_U* pstrDebug)
{
	T_STRING_U::iterator	itr;
	T_PCSTR_U				pFmt	= TQU(" 0x%04X");
	T_PCSTR_U				pLF		= TQU("\r\n");

	pstrDebug->append(TQU("RowNumber\t: "));
	if (this->IsRowNumber())
	{
		pstrDebug->append(TQU("True"));
	}
	else
	{
		pstrDebug->append(TQU("False"));
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("NonMatching\t: "));
	if (this->IsNonMatching())
	{
		pstrDebug->append(TQU("True"));
	}
	else
	{
		pstrDebug->append(TQU("False"));
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("SheetName\t: "));
	if (this->IsSheetName())
	{
		pstrDebug->append(TQU("True"));
	}
	else
	{
		pstrDebug->append(TQU("False"));
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("MatchingDelimiter\t:"));
	for (itr = strMatchingDelimiter.begin(); itr != strMatchingDelimiter.end(); ++itr)
	{
		PLib::AppendNumToString<T_CHAR_U, UINT>(pstrDebug, pFmt, (UINT)*itr);
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("OutputDelimiter\t:"));
	for (itr = strOutputDelimiter.begin(); itr != strOutputDelimiter.end(); ++itr)
	{
		PLib::AppendNumToString<T_CHAR_U, UINT>(pstrDebug, pFmt, (UINT)*itr);
	}
	pstrDebug->append(pLF);
}
#endif


//----------------------------------------------------------------------
//	Prototype01a
//----------------------------------------------------------------------
T_PCSTR_U	DPt01a[]	=
{
	TQU("n"),
	TQU("v"),
	TQU("h"),
	TQU("c"),
	TQU("d"),
	TQU("vhcd"),
	TQU("nhdc"),
	TQU("nvcd"),
	TQU("nvhd"),
	TQU("nvhc"),
	TQU("c\x0a"),
	TQU("d\x0d"),
	TQU("ncNdN"),
	TQU("vcadb"),
	TQU("hc\\11dL"),

	TQU("nvhc\\11d\\x09"),
};
int	nDPt01a	= sizeof(DPt01a) / sizeof(T_PCSTR_U);

void Prototype01a()
{
	PCGrepOptions	ciOpt;
	T_STRING_U		strDebug;
	T_PCSTR_U		pTest;
	int				i;
	T_PCSTR_U		pHR	= TQU("------------------------------\r\n");
	T_PCSTR_U		pLF	= TQU("\r\n");

	for (i = 0; i < nDPt01a; ++i)
	{
		pTest	= DPt01a[i];
		strDebug.append(pHR);
		strDebug.append(pTest);
		strDebug.append(pLF);
		ciOpt.Reset();
		ciOpt.Set(pTest, wcslen(pTest));
		ciOpt.Debug(&strDebug);
	}
}

NS_TEST_END
#endif

//======================================================================
//	Prototype01
//======================================================================
void Prototype01()
{
#ifdef	PDEBUG

	PTest::Prototype01a();

#endif
}
