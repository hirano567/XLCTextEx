//	XLCTextEx_1.0x	:	Test

//	TestPUCD01.cpp
//
#include "stdafx.h"
#ifdef	PDEBUG

//======================================================================
//	TestPUCD01a
//======================================================================
void TestPUCD01a()
{
	const size_t	zBuf	= 256;
	char			IBufa[zBuf];
	T_CHAR_U		IBufw[zBuf];
	T_CHAR_U		OBufw[zBuf];
	T_PCSTR_U		pFmtw	= L"%f\t: %s";
	T_PCSTR_U		pbuf;
	double			dVal;
	size_t			zt;

	while (true)
	{
		std::cin	>> IBufa;
		if (_stricmp(IBufa, "quit") == 0)	break;
		if (!PLib::ConvertMBtoWC(IBufw, zBuf, &zt, IBufa, strlen(IBufa)))	continue;

		pbuf	= IBufw;
		if (PLib::Unicode::StrToDouble(&dVal, &pbuf))
		{
			std::cout	<< dVal;
			std::wcout	<< L"\t: "	<< pbuf	<< std::endl;
			std::cout	<< std::endl;
			swprintf(OBufw, zBuf, pFmtw, dVal, pbuf);
			std::wcout	<< OBufw	<< std::endl;
		}
		else
		{
			std::cout	<< "not converted\t: "	<< pbuf	<< std::endl;
			std::cout	<< std::endl;
		}
	}
}

//======================================================================
//	TestPUCD01b
//======================================================================
void TestPUCD01b()
{
	wchar_t	buf[256];
	LPCWSTR	ps;
	double	dv;

	while (true)
	{
		std::wcin	>> buf;
		if (_wcsicmp(buf, L"quit") == 0)	break;
		ps	= buf;
		if (PLib::Unicode::StrToDouble(&dv, &ps))
		{
			if (dv == std::numeric_limits<double>::infinity())
			{
				std::cout	<< "+ infinity"	<< std::endl;
			}
			else if (dv == -std::numeric_limits<double>::infinity())
			{
				std::cout	<< "- infinity"	<< std::endl;
			}
			else
			{
				std::cout	<< dv	<< std::endl;
			}
		}
		else
		{
			std::cout	<< "not converted."	<< std::endl;
		}
	}
}

void TestPUCD01b2()
{
	double	x, y;
	int		i;

	while (true)
	{
		std::cout	<< "x = ";
		std::cin	>> x;
		std::cout	<< "i = ";
		std::cin	>> i;
		if ( x == 0 && i <= 0)	break;
		y	= x * pow(10.0, i);
		std::cout	<< "y = "	<< y	<< std::endl;
	}
}

#endif

//======================================================================
//	TestPUCD01
//======================================================================
void TestPUCD01()
{
#ifdef	PDEBUG

	//TestPUCD01a();
	TestPUCD01b();
	//TestPUCD01c();
	//TestPUCD01d();

#endif
}
