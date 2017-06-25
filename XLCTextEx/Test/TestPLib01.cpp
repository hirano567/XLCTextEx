//	XLCTextEx_1.0x	:	Test

//	TestPLib01.cpp
//
#include "stdafx.h"
#ifdef	PDEBUG

//======================================================================
//	TestPLib01a
//======================================================================
struct TL01a
{
	char	buf[32];
};

void TestPLib01a()
{
	typedef	TL01a*				PTL01a;
	typedef	std::list<TL01a*>	TLIST;
	typedef	TLIST::iterator	ILIST;
	TLIST	ciList;
	ILIST	itrl;

	typedef	std::set<TL01a*>	TSET;
	typedef	TSET::iterator		ISET;
	TSET	ciSet;
	ISET	itrs;

	const int	nIns	= 4;
	TL01a	si[nIns];
	PTL01a	p, p0, p1, p2, p3;
	int		i, iLoop;
	T_STRING_U	strTest;
	T_PCSTR_U	pFmt	= TQU("%8d");

	PROFILER_SETDESC(0, TQU("new 1 Š„“–\t"));
	PROFILER_SETDESC(1, TQU("new 1 ‰ð•ú\t"));
	PROFILER_SETDESC(2, TQU("new 2 Š„“–\t"));
	PROFILER_SETDESC(3, TQU("new 2 ‰ð•ú\t"));
	PROFILER_SETDESC(4, TQU("list  Š„“–\t"));
	PROFILER_SETDESC(5, TQU("list  ‰ð•ú\t"));
	PROFILER_SETDESC(6, TQU("set   Š„“–\t"));
	PROFILER_SETDESC(7, TQU("set   ‰ð•ú\t"));

	iLoop	= 10000;

	for (i = 0; i < iLoop; ++i)
	{
		PROFILER_START(0);
		p0	= new TL01a;
		p1	= new TL01a;
		p2	= new TL01a;
		p3	= new TL01a;
		PROFILER_STOP(0);

		PROFILER_START(1);
		delete	p0;
		delete	p1;
		delete	p2;
		delete	p3;
		PROFILER_STOP(1);
	}

	for (i = 0; i < iLoop; ++i)
	{
		ciList.clear();

		PROFILER_START(2);
		p	= new TL01a;
		ciList.push_back(p);
		p	= new TL01a;
		ciList.push_back(p);
		p	= new TL01a;
		ciList.push_back(p);
		p	= new TL01a;
		ciList.push_back(p);
		PROFILER_STOP(2);

		PROFILER_START(3);
		for (itrl = ciList.begin(); itrl != ciList.end(); ++itrl)
		{
			delete	*itrl;
		}
		PROFILER_STOP(3);
	}

	p0	= &si[0];
	p1	= &si[1];
	p2	= &si[2];
	p3	= &si[3];
	ciList.clear();
	ciSet.clear();

	for (i = 0; i < iLoop * nIns; ++i)
	{
		PROFILER_START(4);
		ciList.push_back(p0);
		ciList.push_back(p1);
		ciList.push_back(p2);
		ciList.push_back(p3);
		PROFILER_STOP(4);

		PROFILER_START(5);
		p0	= *ciList.begin();
		ciList.pop_front();
		p1	= *ciList.begin();
		ciList.pop_front();
		p2	= *ciList.begin();
		ciList.pop_front();
		p3	= *ciList.begin();
		ciList.pop_front();
		PROFILER_STOP(5);
	}

	for (i = 0; i < iLoop * nIns; ++i)
	{
		PROFILER_START(6);
		ciSet.insert(p0);
		ciSet.insert(p1);
		ciSet.insert(p2);
		ciSet.insert(p3);
		PROFILER_STOP(6);

		PROFILER_START(7);
		ciSet.erase(p0);
		ciSet.erase(p1);
		ciSet.erase(p2);
		ciSet.erase(p3);
		PROFILER_STOP(7);
	}

	PROFILER_GETTOTAL(&strTest, pFmt);
}

//======================================================================
//	TestPLib01b
//======================================================================
void TestPLib01b()
{
}

#endif

//======================================================================
//	TestPLib01
//======================================================================
void TestPLib01()
{
#ifdef	PDEBUG

	//TestPLib01a();
	TestPLib01b();
	//TestPLib01c();
	//TestPLib01d();

#endif
}
