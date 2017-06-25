//	XLCTextEx_1.0x	:	Test

//	TestUtility.cpp
//
#include "stdafx.h"

NS_TEST_BEGIN

//======================================================================
//	AppendTF
//======================================================================
void AppendTF(T_STRING_U* pstrBuf, bool br, T_PCSTR_U pszPre, T_PCSTR_U pszPost)
{
	if (pszPre != NULL)	pstrBuf->append(pszPre);

	if (br)
	{
		pstrBuf->append(TQU("›"));
	}
	else
	{
		pstrBuf->append(TQU("~"));
	}

	if (pszPost != NULL)	pstrBuf->append(pszPost);
}

//======================================================================
//	GetCStrOptDesc
//======================================================================
struct PSCSTROPT
{
	DWORD		opt;
	T_PCSTR_U	name;
};

PSCSTROPT	siCStrOpt[]	=
{
	0,	TQU("no option"),
	NORM_IGNORECASE,		TQU("ICase"),
	NORM_IGNOREKANATYPE,	TQU("IKanaType"),
	NORM_IGNORENONSPACE,	TQU("IDiacritical"),
	NORM_IGNOREWIDTH,		TQU("IKanaWidth"),
	CSTRUCD_NORMALIZE,		TQU("Normalize"),
	CSTRUCD_IGNOREKANACASE,	TQU("IKanaCase"),
};
int	nCStrOpt	= sizeof(siCStrOpt) / sizeof(PSCSTROPT);

void GetCStrOptDesc(T_STRING_U* pstrOpt, DWORD dwFlags)
{
	int	i;
	T_STRING_U	strTemp;
	T_PCSTR_U	pComma	= TQU(",");

	strTemp.clear();
	for (i = 1; i < nCStrOpt; ++i)
	{
		if ((dwFlags & siCStrOpt[i].opt) != 0)
		{
			if (!strTemp.empty())	strTemp.append(pComma);
			strTemp.append(siCStrOpt[i].name);
		}
	}
	if (strTemp.empty())	strTemp.assign(siCStrOpt[0].name);
	pstrOpt->append(strTemp);
}

//======================================================================
//	CreateTestData
//======================================================================
//----------------------------------------------------------------------
//	AppendChar
//----------------------------------------------------------------------
void AppendChar(std::wstring* pstr, wchar_t c1, wchar_t c2)
{
	wchar_t	c;
	LPCWSTR	pfmt_04X	= L"\\x%04X";


	pstr->append(L"\tTQ_TEST(\"");
	for (c = (UINT)c1; c <= (UINT)c2; ++c)
	{
		pstr->append(1, c);
	}
	pstr->append(L"\"),\r\n");

	pstr->append(L"\tTQ_TEST(\"");
	for (c = (UINT)c1; c <= (UINT)c2; ++c)
	{
		PLib::AppendNumToString<wchar_t, UINT>(pstr, pfmt_04X, c);
	}
	pstr->append(L"\"),\r\n");
	pstr->append(L"\r\n");
}

void CreateTestData()
{
	std::wstring	strTest;

	AppendChar(&strTest, 0x0020, 0x002F);
	AppendChar(&strTest, 0x0031, 0x0039);
	AppendChar(&strTest, 0x003A, 0x0040);
	AppendChar(&strTest, 0x0041, 0x004D);
	AppendChar(&strTest, 0x004E, 0x005A);
	AppendChar(&strTest, 0x005B, 0x0060);
	AppendChar(&strTest, 0x0061, 0x006D);
	AppendChar(&strTest, 0x006E, 0x007A);
	AppendChar(&strTest, 0x007B, 0x007E);
	AppendChar(&strTest, 0x00C0, 0x00C6);
	AppendChar(&strTest, 0x00E0, 0x00E6);
	AppendChar(&strTest, 0x3041, 0x304F);
	AppendChar(&strTest, 0x3050, 0x305F);
	AppendChar(&strTest, 0x3060, 0x306F);
	AppendChar(&strTest, 0x3070, 0x307F);
	AppendChar(&strTest, 0x3080, 0x308F);
	AppendChar(&strTest, 0x3090, 0x3096);
	AppendChar(&strTest, 0x309B, 0x30A0);
	AppendChar(&strTest, 0x30A1, 0x30AF);
	AppendChar(&strTest, 0x30B0, 0x30BF);
	AppendChar(&strTest, 0x30C0, 0x30CF);
	AppendChar(&strTest, 0x30D0, 0x30DF);
	AppendChar(&strTest, 0x30E0, 0x30EF);
	AppendChar(&strTest, 0x30F0, 0x30FA);
	AppendChar(&strTest, 0x30FC, 0x30FF);
	AppendChar(&strTest, 0x31F0, 0x31FF);
	AppendChar(&strTest, 0xFF01, 0xFF0F);
	AppendChar(&strTest, 0xFF10, 0xFF19);
	AppendChar(&strTest, 0xFF1A, 0xFF20);
	AppendChar(&strTest, 0xFF21, 0xFF2D);
	AppendChar(&strTest, 0xFF2E, 0xFF3A);
	AppendChar(&strTest, 0xFF3B, 0xFF40);
	AppendChar(&strTest, 0xFF41, 0xFF4D);
	AppendChar(&strTest, 0xFF4E, 0xFF5A);
	AppendChar(&strTest, 0xFF5B, 0xFF5E);
	AppendChar(&strTest, 0xFF5F, 0xFF64);
	AppendChar(&strTest, 0xFF66, 0xFF70);
	AppendChar(&strTest, 0xFF71, 0xFF7F);
	AppendChar(&strTest, 0xFF80, 0xFF8F);
	AppendChar(&strTest, 0xFF90, 0xFF9F);
	//AppendChar(&strTest, 0x, 0x);
}

NS_TEST_END
