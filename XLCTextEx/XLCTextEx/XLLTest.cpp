//	XLCTextEx_1.0x	:	XLCTextEx

//	XLLTest.cpp
//
#include "stdafx.h"

//======================================================================
//	XLCRegExTest4
//======================================================================
XLOPER4* WINAPI XLCRegExTest4(XLOPER4* pxArg)
{
	return NULL;
}

//======================================================================
//	XLCRegExTest12
//======================================================================
XLOPER12* WINAPI XLCRegExTest12(XLOPER12* pxArg)
{
	return NULL;
}

#ifdef	PDEBUG

//======================================================================
//	Test01_01a
//======================================================================
LPCWSTR	Data01_01a[]	=
{
	L"\001\"",
	L"\002\"\"",
	L"\003\"a\"",
	L"\002\"a",
	L"\003ÅhaÅh",
	L"\005\"ABC\"",
	L"\004\"ABC",
	L"\005ÅhABCÅh",
};
int	nData01_01a	= sizeof(Data01_01a) / sizeof(LPCWSTR);

void Test01_01a()
{
	XLOPER12		xSrc;
	LPCWSTR			pBegin, pEnd;
	int				i;
	BOOL			br;
	std::wstring	wsTemp;

	xSrc.xltype	= xltypeStr;
	for (i = 0; i < nData01_01a; ++i)
	{
		xSrc.val.str	= (XCHAR*)Data01_01a[i];
		br	= XLL::XLRemoveQuote<wchar_t>(&pBegin, &pEnd, &xSrc, NORM_IGNOREWIDTH, NULL);
		if (br)
		{
			wsTemp.assign(pBegin, (size_t)(pEnd - pBegin));
		}
	}
}

//======================================================================
//	XLCRegExTest01
//======================================================================
void XLCRegExTest01()
{
	Test01_01a();
}

#endif
