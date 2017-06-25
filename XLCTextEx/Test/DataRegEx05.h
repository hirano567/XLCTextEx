//	XLCTextEx_1.0x	:	Test

//	DataRegEx05.h
//
#pragma once

#define	PERL_MATCH_YES		0
#define	PERL_MATCH_NO		1
#define	PERL_MATCH_ERROR	2
#define	PERL_MATCH_PERLBUG	3
#define	PERL_MATCH_BUG		-1

//======================================================================
//	DataRegEx05a
//======================================================================
struct TDataRegEx05a
{
	T_PCSTR_U	pat;
	T_PCSTR_U	opt;
	T_PCSTR_U	txt;
	int			res;
};

extern TDataRegEx05a	DataRegEx05a[];
extern int				nDataRegEx05a;

