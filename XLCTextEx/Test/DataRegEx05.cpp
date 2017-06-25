//	XLCTextEx_1.0x	:	Test

//	DataRegEx05.cpp
//
#include "stdafx.h"

//======================================================================
//	DataRegEx05a
//======================================================================
TDataRegEx05a	DataRegEx05a[]	=
{
	L"abc",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"abc",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"abc",
	L"",
	L"xbc",
	PERL_MATCH_NO,

	L"abc",
	L"",
	L"axc",
	PERL_MATCH_NO,

	L"abc",
	L"",
	L"abx",
	PERL_MATCH_NO,

	L"abc",
	L"",
	L"xabcy",
	PERL_MATCH_YES,

	L"abc",
	L"",
	L"xabcy",
	PERL_MATCH_YES,

	L"abc",
	L"",
	L"xabcy",
	PERL_MATCH_YES,

	L"abc",
	L"",
	L"ababc",
	PERL_MATCH_YES,

	L"abc",
	L"",
	L"ababc",
	PERL_MATCH_YES,

	L"abc",
	L"",
	L"ababc",
	PERL_MATCH_YES,

	L"ab*c",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"ab*c",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"ab*c",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"ab*bc",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"ab*bc",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"ab*bc",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"ab*bc",
	L"",
	L"abbc",
	PERL_MATCH_YES,

	L"ab*bc",
	L"",
	L"abbc",
	PERL_MATCH_YES,

	L"ab*bc",
	L"",
	L"abbc",
	PERL_MATCH_YES,

	L"ab*bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab*bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab*bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L".{1}",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L".{1}",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L".{1}",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L".{3,4}",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L".{3,4}",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L".{3,4}",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"\\N{1}",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"\\N{1}",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"\\N{1}",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"\\N {1}",
	L"x",
	L"abbbbc",
	PERL_MATCH_YES,

	L"\\N {1}",
	L"x",
	L"abbbbc",
	PERL_MATCH_YES,

	L"\\N {1}",
	L"x",
	L"abbbbc",
	PERL_MATCH_YES,

	L"\\N{3,4}",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"\\N{3,4}",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"\\N{3,4}",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"\\N {3,4}",
	L"x",
	L"abbbbc",
	PERL_MATCH_YES,

	L"\\N {3,4}",
	L"x",
	L"abbbbc",
	PERL_MATCH_YES,

	L"\\N {3,4}",
	L"x",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab{0,}bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab{0,}bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab{0,}bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab+bc",
	L"",
	L"abbc",
	PERL_MATCH_YES,

	L"ab+bc",
	L"",
	L"abbc",
	PERL_MATCH_YES,

	L"ab+bc",
	L"",
	L"abbc",
	PERL_MATCH_YES,

	L"ab+bc",
	L"",
	L"abc",
	PERL_MATCH_NO,

	L"ab+bc",
	L"",
	L"abq",
	PERL_MATCH_NO,

	L"ab{1,}bc",
	L"",
	L"abq",
	PERL_MATCH_NO,

	L"ab+bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab+bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab+bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab{1,}bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab{1,}bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab{1,}bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab{1,3}bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab{1,3}bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab{1,3}bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab{3,4}bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab{3,4}bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab{3,4}bc",
	L"",
	L"abbbbc",
	PERL_MATCH_YES,

	L"ab{4,5}bc",
	L"",
	L"abbbbc",
	PERL_MATCH_NO,

	L"ab?bc",
	L"",
	L"abbc",
	PERL_MATCH_YES,

	L"ab?bc",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"ab{0,1}bc",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"ab?bc",
	L"",
	L"abbbbc",
	PERL_MATCH_NO,

	L"ab?c",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"ab{0,1}c",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"^abc$",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"^abc$",
	L"",
	L"abcc",
	PERL_MATCH_NO,

	L"^abc",
	L"",
	L"abcc",
	PERL_MATCH_YES,

	L"^abc$",
	L"",
	L"aabc",
	PERL_MATCH_NO,

	L"abc$",
	L"",
	L"aabc",
	PERL_MATCH_YES,

	L"abc$",
	L"",
	L"aabcd",
	PERL_MATCH_NO,

	L"^",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"$",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"a.c",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"a.c",
	L"",
	L"axc",
	PERL_MATCH_YES,

	L"a\\Nc",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"a\\N c",
	L"x",
	L"abc",
	PERL_MATCH_YES,

	L"a.*c",
	L"",
	L"axyzc",
	PERL_MATCH_YES,

	L"a\\N*c",
	L"",
	L"axyzc",
	PERL_MATCH_YES,

	L"a\\N *c",
	L"x",
	L"axyzc",
	PERL_MATCH_YES,

	L"a.*c",
	L"",
	L"axyzd",
	PERL_MATCH_NO,

	L"a\\N*c",
	L"",
	L"axyzd",
	PERL_MATCH_NO,

	L"a\\N *c",
	L"x",
	L"axyzd",
	PERL_MATCH_NO,

	L"a[bc]d",
	L"",
	L"abc",
	PERL_MATCH_NO,

	L"a[bc]d",
	L"",
	L"abd",
	PERL_MATCH_YES,

	L"a[b]d",
	L"",
	L"abd",
	PERL_MATCH_YES,

	L"[a][b][d]",
	L"",
	L"abd",
	PERL_MATCH_YES,

	L".[b].",
	L"",
	L"abd",
	PERL_MATCH_YES,

	L".[b].",
	L"",
	L"aBd",
	PERL_MATCH_NO,

	L"(?i:.[b].)",
	L"",
	L"abd",
	PERL_MATCH_YES,

	L"(?i:\\N[b]\\N)",
	L"",
	L"abd",
	PERL_MATCH_YES,

	L"a[b-d]e",
	L"",
	L"abd",
	PERL_MATCH_NO,

	L"a[b-d]e",
	L"",
	L"ace",
	PERL_MATCH_YES,

	L"a[b-d]",
	L"",
	L"aac",
	PERL_MATCH_YES,

	L"a[-b]",
	L"",
	L"a-",
	PERL_MATCH_YES,

	L"a[b-]",
	L"",
	L"a-",
	PERL_MATCH_YES,

	L"a[b-a]",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"a[]b",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"a[",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"a]",
	L"",
	L"a]",
	PERL_MATCH_YES,

	L"a[]]b",
	L"",
	L"a]b",
	PERL_MATCH_YES,

	L"a[^bc]d",
	L"",
	L"aed",
	PERL_MATCH_YES,

	L"a[^bc]d",
	L"",
	L"abd",
	PERL_MATCH_NO,

	L"a[^-b]c",
	L"",
	L"adc",
	PERL_MATCH_YES,

	L"a[^-b]c",
	L"",
	L"a-c",
	PERL_MATCH_NO,

	L"a[^]b]c",
	L"",
	L"a]c",
	PERL_MATCH_NO,

	L"a[^]b]c",
	L"",
	L"adc",
	PERL_MATCH_YES,

	L"\\ba\\b",
	L"",
	L"a-",
	PERL_MATCH_YES,

	L"\\ba\\b",
	L"",
	L"=-a",
	PERL_MATCH_YES,

	L"\\ba\\b",
	L"",
	L"-a-",
	PERL_MATCH_YES,

	L"\\by\\b",
	L"",
	L"xy",
	PERL_MATCH_NO,

	L"\\by\\b",
	L"",
	L"yz",
	PERL_MATCH_NO,

	L"\\by\\b",
	L"",
	L"xyz",
	PERL_MATCH_NO,

	L"\\Ba\\B",
	L"",
	L"a-",
	PERL_MATCH_NO,

	L"\\Ba\\B",
	L"",
	L"=-a",
	PERL_MATCH_NO,

	L"\\Ba\\B",
	L"",
	L"-a-",
	PERL_MATCH_NO,

	L"\\By\\b",
	L"",
	L"xy",
	PERL_MATCH_YES,

	L"\\By\\b",
	L"",
	L"xy",
	PERL_MATCH_YES,

	L"\\By\\b",
	L"",
	L"xy",
	PERL_MATCH_YES,

	L"\\By\\b",
	L"",
	L"xy",
	PERL_MATCH_YES,

	L"\\by\\B",
	L"",
	L"yz",
	PERL_MATCH_YES,

	L"\\By\\B",
	L"",
	L"xyz",
	PERL_MATCH_YES,

	L"\\w",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"\\w",
	L"",
	L"-",
	PERL_MATCH_NO,

	L"\\W",
	L"",
	L"a",
	PERL_MATCH_NO,

	L"\\W",
	L"",
	L"-",
	PERL_MATCH_YES,

	L"a\\sb",
	L"",
	L"a b",
	PERL_MATCH_YES,

	L"a\\sb",
	L"",
	L"a-b",
	PERL_MATCH_NO,

	L"a\\Sb",
	L"",
	L"a b",
	PERL_MATCH_NO,

	L"a\\Sb",
	L"",
	L"a-b",
	PERL_MATCH_YES,

	L"\\d",
	L"",
	L"1",
	PERL_MATCH_YES,

	L"\\d",
	L"",
	L"-",
	PERL_MATCH_NO,

	L"\\D",
	L"",
	L"1",
	PERL_MATCH_NO,

	L"\\D",
	L"",
	L"-",
	PERL_MATCH_YES,

	L"[\\w]",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"[\\w]",
	L"",
	L"-",
	PERL_MATCH_NO,

	L"[\\W]",
	L"",
	L"a",
	PERL_MATCH_NO,

	L"[\\W]",
	L"",
	L"-",
	PERL_MATCH_YES,

	L"a[\\s]b",
	L"",
	L"a b",
	PERL_MATCH_YES,

	L"a[\\s]b",
	L"",
	L"a-b",
	PERL_MATCH_NO,

	L"a[\\S]b",
	L"",
	L"a b",
	PERL_MATCH_NO,

	L"a[\\S]b",
	L"",
	L"a-b",
	PERL_MATCH_YES,

	L"[\\d]",
	L"",
	L"1",
	PERL_MATCH_YES,

	L"[\\d]",
	L"",
	L"-",
	PERL_MATCH_NO,

	L"[\\D]",
	L"",
	L"1",
	PERL_MATCH_NO,

	L"[\\D]",
	L"",
	L"-",
	PERL_MATCH_YES,

	L"ab|cd",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"ab|cd",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"()ef",
	L"",
	L"def",
	PERL_MATCH_YES,

	L"()ef",
	L"",
	L"def",
	PERL_MATCH_YES,

	L"()ef",
	L"",
	L"def",
	PERL_MATCH_YES,

	L"()\\x{100}\\x{1000}",
	L"",
	L"d\x100\x1000",
	PERL_MATCH_YES,

	L"()ef",
	L"",
	L"def",
	PERL_MATCH_YES,

	L"()ef",
	L"",
	L"def",
	PERL_MATCH_YES,

	L"*a",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(|*)b",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(*)b",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"$b",
	L"",
	L"b",
	PERL_MATCH_NO,

	L"a\\",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"a\\(b",
	L"",
	L"a(b",
	PERL_MATCH_YES,

	L"a\\(*b",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"a\\(*b",
	L"",
	L"a((b",
	PERL_MATCH_YES,

	L"a\\\\b",
	L"",
	L"a\\b",
	PERL_MATCH_YES,

	L"abc)",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(abc",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"((a))",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"((a))",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"((a))",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"((a))",
	L"",
	L"abc",
	PERL_MATCH_BUG,

	L"((a))",
	L"",
	L"abc",
	PERL_MATCH_BUG,

	L"(a)b(c)",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"(a)b(c)",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"(a)b(c)",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"a+b+c",
	L"",
	L"aabbabc",
	PERL_MATCH_YES,

	L"a{1,}b{1,}c",
	L"",
	L"aabbabc",
	PERL_MATCH_YES,

	L"a**",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"a.+?c",
	L"",
	L"abcabc",
	PERL_MATCH_YES,

	L"(a+|b)*",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"(a+|b)*",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"(a+|b)*",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"(a+|b)*",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"(a+|b)*",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"(a+|b){0,}",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"(a+|b)+",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"(a+|b){1,}",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"(a+|b)?",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"(a+|b){0,1}",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L")(",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"[^ab]*",
	L"",
	L"cde",
	PERL_MATCH_YES,

	L"abc",
	L"",
	L"",
	PERL_MATCH_NO,

	L"a*",
	L"",
	L"",
	PERL_MATCH_YES,

	L"([abc])*d",
	L"",
	L"abbbcd",
	PERL_MATCH_YES,

	L"([abc])*bcd",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a|b|c|d|e",
	L"",
	L"e",
	PERL_MATCH_YES,

	L"(a|b|c|d|e)f",
	L"",
	L"ef",
	PERL_MATCH_YES,

	L"(a|b|c|d|e)f",
	L"",
	L"ef",
	PERL_MATCH_YES,

	L"(a|b|c|d|e)f",
	L"",
	L"ef",
	PERL_MATCH_YES,

	L"(a|b|c|d|e)f",
	L"",
	L"ef",
	PERL_MATCH_YES,

	L"(a|b|c|d|e)f",
	L"",
	L"ef",
	PERL_MATCH_YES,

	L"abcd*efg",
	L"",
	L"abcdefg",
	PERL_MATCH_YES,

	L"ab*",
	L"",
	L"xabyabbbz",
	PERL_MATCH_YES,

	L"ab*",
	L"",
	L"xayabbbz",
	PERL_MATCH_YES,

	L"(ab|cd)e",
	L"",
	L"abcde",
	PERL_MATCH_YES,

	L"[abhgefdc]ij",
	L"",
	L"hij",
	PERL_MATCH_YES,

	L"^(ab|cd)e",
	L"",
	L"abcde",
	PERL_MATCH_NO,

	L"(abc|)ef",
	L"",
	L"abcdef",
	PERL_MATCH_YES,

	L"(a|b)c*d",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(ab|ab*)bc",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"a([bc]*)c*",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"a([bc]*)(c*d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a([bc]*)(c*d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a([bc]*)(c*d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a([bc]*)(c*d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a([bc]*)(c*d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a([bc]*)(c*d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a([bc]*)(c*d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a([bc]+)(c*d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a([bc]*)(c+d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a([bc]*)(c+d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a([bc]*)(c+d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a([bc]*)(c+d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a([bc]*)(c+d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a([bc]*)(c+d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a([bc]*)(c+d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a[bcd]*dcdcde",
	L"",
	L"adcdcde",
	PERL_MATCH_YES,

	L"a[bcd]+dcdcde",
	L"",
	L"adcdcde",
	PERL_MATCH_NO,

	L"(ab|a)b*c",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"(ab|a)b*c",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"(ab|a)b*c",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"(ab|a)b*c",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"(ab|a)b*c",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"((a)(b)c)(d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"((a)(b)c)(d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"((a)(b)c)(d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"((a)(b)c)(d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"((a)(b)c)(d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"((a)(b)c)(d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"((a)(b)c)(d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"((a)(b)c)(d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"((a)(b)c)(d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"((a)(b)c)(d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"((a)(b)c)(d)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"[a-zA-Z_][a-zA-Z0-9_]*",
	L"",
	L"alpha",
	PERL_MATCH_YES,

	L"^a(bc+|b[eh])g|.h$",
	L"",
	L"abh",
	PERL_MATCH_YES,

	L"(bc+d$|ef*g.|h?i(j|k))",
	L"",
	L"effgz",
	PERL_MATCH_YES,

	L"(bc+d$|ef*g.|h?i(j|k))",
	L"",
	L"ij",
	PERL_MATCH_YES,

	L"(bc+d$|ef*g.|h?i(j|k))",
	L"",
	L"effg",
	PERL_MATCH_NO,

	L"(bc+d$|ef*g.|h?i(j|k))",
	L"",
	L"bcdd",
	PERL_MATCH_NO,

	L"(bc+d$|ef*g.|h?i(j|k))",
	L"",
	L"reffgz",
	PERL_MATCH_YES,

	L"((((((((((a))))))))))",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"((((((((((a))))))))))",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"((((((((((a))))))))))",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"((((((((((a))))))))))",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"((((((((((a))))))))))",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"((((((((((a))))))))))\\10",
	L"",
	L"aa",
	PERL_MATCH_YES,

	L"((((((((((a))))))))))${bang}",
	L"",
	L"aa",
	PERL_MATCH_NO,

	L"((((((((((a))))))))))${bang}",
	L"",
	L"a!",
	PERL_MATCH_YES,

	L"(((((((((a)))))))))",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"multiple words of text",
	L"",
	L"uh-uh",
	PERL_MATCH_NO,

	L"multiple words",
	L"",
	L"multiple words, yeah",
	PERL_MATCH_YES,

	L"(.*)c(.*)",
	L"",
	L"abcde",
	PERL_MATCH_YES,

	L"\\((.*), (.*)\\)",
	L"",
	L"(a, b)",
	PERL_MATCH_YES,

	L"[k]",
	L"",
	L"ab",
	PERL_MATCH_NO,

	L"abcd",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a(bc)d",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"a[-]?c",
	L"",
	L"ac",
	PERL_MATCH_YES,

	L"(abc)\\1",
	L"",
	L"abcabc",
	PERL_MATCH_YES,

	L"([a-c]*)\\1",
	L"",
	L"abcabc",
	PERL_MATCH_YES,

	L"\\1",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\2",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\g1",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\g-1",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\g{1}",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\g{-1}",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\g0",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\g-0",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\g{0}",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\g{-0}",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(a)|\\1",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"(a)|\\1",
	L"",
	L"x",
	PERL_MATCH_NO,

	L"(?:(b)?a)\\1",
	L"",
	L"a",
	PERL_MATCH_NO,

	L"(a)|\\2",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(([a-c])b*?\\2)*",
	L"",
	L"ababbbcbc",
	PERL_MATCH_YES,

	L"(([a-c])b*?\\2){3}",
	L"",
	L"ababbbcbc",
	PERL_MATCH_YES,

	L"((\\3|b)\\2(a)x)+",
	L"",
	L"aaxabxbaxbbx",
	PERL_MATCH_NO,

	L"((\\3|b)\\2(a)x)+",
	L"",
	L"aaaxabaxbaaxbbax",
	PERL_MATCH_YES,

	L"((\\3|b)\\2(a)){2,}",
	L"",
	L"bbaababbabaaaaabbaaaabba",
	PERL_MATCH_YES,

	L"^((.)?a\\2)+$",
	L"",
	L"babadad",
	PERL_MATCH_NO,

	L"(a)|(b)",
	L"",
	L"b",
	PERL_MATCH_YES,

	L"(a)|(b)",
	L"",
	L"b",
	PERL_MATCH_YES,

	L"(a)|(b)",
	L"",
	L"b",
	PERL_MATCH_YES,

	L"(a)|(b)",
	L"",
	L"b",
	PERL_MATCH_YES,

	L"(a)|(b)",
	L"",
	L"b",
	PERL_MATCH_YES,

	L"(a)|(b)",
	L"",
	L"b",
	PERL_MATCH_YES,

	L"abc",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"abc",
	L"i",
	L"XBC",
	PERL_MATCH_NO,

	L"abc",
	L"i",
	L"AXC",
	PERL_MATCH_NO,

	L"abc",
	L"i",
	L"ABX",
	PERL_MATCH_NO,

	L"abc",
	L"i",
	L"XABCY",
	PERL_MATCH_YES,

	L"abc",
	L"i",
	L"ABABC",
	PERL_MATCH_YES,

	L"ab*c",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"ab*bc",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"ab*bc",
	L"i",
	L"ABBC",
	PERL_MATCH_YES,

	L"ab*?bc",
	L"i",
	L"ABBBBC",
	PERL_MATCH_YES,

	L"ab{0,}?bc",
	L"i",
	L"ABBBBC",
	PERL_MATCH_YES,

	L"ab+?bc",
	L"i",
	L"ABBC",
	PERL_MATCH_YES,

	L"ab+bc",
	L"i",
	L"ABC",
	PERL_MATCH_NO,

	L"ab+bc",
	L"i",
	L"ABQ",
	PERL_MATCH_NO,

	L"ab{1,}bc",
	L"i",
	L"ABQ",
	PERL_MATCH_NO,

	L"ab+bc",
	L"i",
	L"ABBBBC",
	PERL_MATCH_YES,

	L"ab{1,}?bc",
	L"i",
	L"ABBBBC",
	PERL_MATCH_YES,

	L"ab{1,3}?bc",
	L"i",
	L"ABBBBC",
	PERL_MATCH_YES,

	L"ab{3,4}?bc",
	L"i",
	L"ABBBBC",
	PERL_MATCH_YES,

	L"ab{4,5}?bc",
	L"i",
	L"ABBBBC",
	PERL_MATCH_NO,

	L"ab??bc",
	L"i",
	L"ABBC",
	PERL_MATCH_YES,

	L"ab??bc",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"ab{0,1}?bc",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"ab??bc",
	L"i",
	L"ABBBBC",
	PERL_MATCH_NO,

	L"ab??c",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"ab{0,1}?c",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"^abc$",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"^abc$",
	L"i",
	L"ABCC",
	PERL_MATCH_NO,

	L"^abc",
	L"i",
	L"ABCC",
	PERL_MATCH_YES,

	L"^abc$",
	L"i",
	L"AABC",
	PERL_MATCH_NO,

	L"abc$",
	L"i",
	L"AABC",
	PERL_MATCH_YES,

	L"^",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"$",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"a.c",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"a.c",
	L"i",
	L"AXC",
	PERL_MATCH_YES,

	L"a\\Nc",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"a.*?c",
	L"i",
	L"AXYZC",
	PERL_MATCH_YES,

	L"a.*c",
	L"i",
	L"AXYZD",
	PERL_MATCH_NO,

	L"a[bc]d",
	L"i",
	L"ABC",
	PERL_MATCH_NO,

	L"a[bc]d",
	L"i",
	L"ABD",
	PERL_MATCH_YES,

	L"a[b-d]e",
	L"i",
	L"ABD",
	PERL_MATCH_NO,

	L"a[b-d]e",
	L"i",
	L"ACE",
	PERL_MATCH_YES,

	L"a[b-d]",
	L"i",
	L"AAC",
	PERL_MATCH_YES,

	L"a[-b]",
	L"i",
	L"A-",
	PERL_MATCH_YES,

	L"a[b-]",
	L"i",
	L"A-",
	PERL_MATCH_YES,

	L"a[b-a]",
	L"i",
	L"-",
	PERL_MATCH_ERROR,

	L"a[]b",
	L"i",
	L"-",
	PERL_MATCH_ERROR,

	L"a[",
	L"i",
	L"-",
	PERL_MATCH_ERROR,

	L"a]",
	L"i",
	L"A]",
	PERL_MATCH_YES,

	L"a[]]b",
	L"i",
	L"A]B",
	PERL_MATCH_YES,

	L"a[^bc]d",
	L"i",
	L"AED",
	PERL_MATCH_YES,

	L"a[^bc]d",
	L"i",
	L"ABD",
	PERL_MATCH_NO,

	L"a[^-b]c",
	L"i",
	L"ADC",
	PERL_MATCH_YES,

	L"a[^-b]c",
	L"i",
	L"A-C",
	PERL_MATCH_NO,

	L"a[^]b]c",
	L"i",
	L"A]C",
	PERL_MATCH_NO,

	L"a[^]b]c",
	L"i",
	L"ADC",
	PERL_MATCH_YES,

	L"ab|cd",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"ab|cd",
	L"i",
	L"ABCD",
	PERL_MATCH_YES,

	L"()ef",
	L"i",
	L"DEF",
	PERL_MATCH_YES,

	L"*a",
	L"i",
	L"-",
	PERL_MATCH_ERROR,

	L"(|*)b",
	L"i",
	L"-",
	PERL_MATCH_ERROR,

	L"(*)b",
	L"i",
	L"-",
	PERL_MATCH_ERROR,

	L"$b",
	L"i",
	L"B",
	PERL_MATCH_NO,

	L"a\\",
	L"i",
	L"-",
	PERL_MATCH_ERROR,

	L"a\\(b",
	L"i",
	L"A(B",
	PERL_MATCH_YES,

	L"a\\(*b",
	L"i",
	L"AB",
	PERL_MATCH_YES,

	L"a\\(*b",
	L"i",
	L"A((B",
	PERL_MATCH_YES,

	L"a\\\\b",
	L"i",
	L"A\\B",
	PERL_MATCH_YES,

	L"abc)",
	L"i",
	L"-",
	PERL_MATCH_ERROR,

	L"(abc",
	L"i",
	L"-",
	PERL_MATCH_ERROR,

	L"((a))",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"(a)b(c)",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"a+b+c",
	L"i",
	L"AABBABC",
	PERL_MATCH_YES,

	L"a{1,}b{1,}c",
	L"i",
	L"AABBABC",
	PERL_MATCH_YES,

	L"a**",
	L"i",
	L"-",
	PERL_MATCH_ERROR,

	L"a.+?c",
	L"i",
	L"ABCABC",
	PERL_MATCH_YES,

	L"a.*?c",
	L"i",
	L"ABCABC",
	PERL_MATCH_YES,

	L"a.{0,5}?c",
	L"i",
	L"ABCABC",
	PERL_MATCH_YES,

	L"(a+|b)*",
	L"i",
	L"AB",
	PERL_MATCH_YES,

	L"(a+|b){0,}",
	L"i",
	L"AB",
	PERL_MATCH_YES,

	L"(a+|b)+",
	L"i",
	L"AB",
	PERL_MATCH_YES,

	L"(a+|b){1,}",
	L"i",
	L"AB",
	PERL_MATCH_YES,

	L"(a+|b)?",
	L"i",
	L"AB",
	PERL_MATCH_YES,

	L"(a+|b){0,1}",
	L"i",
	L"AB",
	PERL_MATCH_YES,

	L"(a+|b){0,1}?",
	L"i",
	L"AB",
	PERL_MATCH_YES,

	L")(",
	L"i",
	L"-",
	PERL_MATCH_ERROR,

	L"[^ab]*",
	L"i",
	L"CDE",
	PERL_MATCH_YES,

	L"abc",
	L"i",
	L"",
	PERL_MATCH_NO,

	L"a*",
	L"i",
	L"",
	PERL_MATCH_YES,

	L"([abc])*d",
	L"i",
	L"ABBBCD",
	PERL_MATCH_YES,

	L"([abc])*bcd",
	L"i",
	L"ABCD",
	PERL_MATCH_YES,

	L"a|b|c|d|e",
	L"i",
	L"E",
	PERL_MATCH_YES,

	L"(a|b|c|d|e)f",
	L"i",
	L"EF",
	PERL_MATCH_YES,

	L"abcd*efg",
	L"i",
	L"ABCDEFG",
	PERL_MATCH_YES,

	L"ab*",
	L"i",
	L"XABYABBBZ",
	PERL_MATCH_YES,

	L"ab*",
	L"i",
	L"XAYABBBZ",
	PERL_MATCH_YES,

	L"(ab|cd)e",
	L"i",
	L"ABCDE",
	PERL_MATCH_YES,

	L"[abhgefdc]ij",
	L"i",
	L"HIJ",
	PERL_MATCH_YES,

	L"^(ab|cd)e",
	L"i",
	L"ABCDE",
	PERL_MATCH_NO,

	L"(abc|)ef",
	L"i",
	L"ABCDEF",
	PERL_MATCH_YES,

	L"(a|b)c*d",
	L"i",
	L"ABCD",
	PERL_MATCH_YES,

	L"(ab|ab*)bc",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"a([bc]*)c*",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"a([bc]*)(c*d)",
	L"i",
	L"ABCD",
	PERL_MATCH_YES,

	L"a([bc]+)(c*d)",
	L"i",
	L"ABCD",
	PERL_MATCH_YES,

	L"a([bc]*)(c+d)",
	L"i",
	L"ABCD",
	PERL_MATCH_YES,

	L"a[bcd]*dcdcde",
	L"i",
	L"ADCDCDE",
	PERL_MATCH_YES,

	L"a[bcd]+dcdcde",
	L"i",
	L"ADCDCDE",
	PERL_MATCH_NO,

	L"(ab|a)b*c",
	L"i",
	L"ABC",
	PERL_MATCH_YES,

	L"((a)(b)c)(d)",
	L"i",
	L"ABCD",
	PERL_MATCH_YES,

	L"[a-zA-Z_][a-zA-Z0-9_]*",
	L"i",
	L"ALPHA",
	PERL_MATCH_YES,

	L"^a(bc+|b[eh])g|.h$",
	L"i",
	L"ABH",
	PERL_MATCH_YES,

	L"(bc+d$|ef*g.|h?i(j|k))",
	L"i",
	L"EFFGZ",
	PERL_MATCH_YES,

	L"(bc+d$|ef*g.|h?i(j|k))",
	L"i",
	L"IJ",
	PERL_MATCH_YES,

	L"(bc+d$|ef*g.|h?i(j|k))",
	L"i",
	L"EFFG",
	PERL_MATCH_NO,

	L"(bc+d$|ef*g.|h?i(j|k))",
	L"i",
	L"BCDD",
	PERL_MATCH_NO,

	L"(bc+d$|ef*g.|h?i(j|k))",
	L"i",
	L"REFFGZ",
	PERL_MATCH_YES,

	L"((((((((((a))))))))))",
	L"i",
	L"A",
	PERL_MATCH_YES,

	L"((((((((((a))))))))))\\10",
	L"i",
	L"AA",
	PERL_MATCH_YES,

	L"((((((((((a))))))))))${bang}",
	L"i",
	L"AA",
	PERL_MATCH_NO,

	L"((((((((((a))))))))))${bang}",
	L"i",
	L"A!",
	PERL_MATCH_YES,

	L"(((((((((a)))))))))",
	L"i",
	L"A",
	PERL_MATCH_YES,

	L"(?:(?:(?:(?:(?:(?:(?:(?:(?:(a))))))))))",
	L"i",
	L"A",
	PERL_MATCH_YES,

	L"(?:(?:(?:(?:(?:(?:(?:(?:(?:(a|b|c))))))))))",
	L"i",
	L"C",
	PERL_MATCH_YES,

	L"multiple words of text",
	L"i",
	L"UH-UH",
	PERL_MATCH_NO,

	L"multiple words",
	L"i",
	L"MULTIPLE WORDS, YEAH",
	PERL_MATCH_YES,

	L"(.*)c(.*)",
	L"i",
	L"ABCDE",
	PERL_MATCH_YES,

	L"\\((.*), (.*)\\)",
	L"i",
	L"(A, B)",
	PERL_MATCH_YES,

	L"[k]",
	L"i",
	L"AB",
	PERL_MATCH_NO,

	L"abcd",
	L"i",
	L"ABCD",
	PERL_MATCH_YES,

	L"a(bc)d",
	L"i",
	L"ABCD",
	PERL_MATCH_YES,

	L"a[-]?c",
	L"i",
	L"AC",
	PERL_MATCH_YES,

	L"(abc)\\1",
	L"i",
	L"ABCABC",
	PERL_MATCH_YES,

	L"([a-c]*)\\1",
	L"i",
	L"ABCABC",
	PERL_MATCH_YES,

	L"a(?!b).",
	L"",
	L"abad",
	PERL_MATCH_YES,

	L"(?=)a",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"a(?=d).",
	L"",
	L"abad",
	PERL_MATCH_YES,

	L"a(?=c|d).",
	L"",
	L"abad",
	PERL_MATCH_YES,

	L"a(?:b|c|d)(.)",
	L"",
	L"ace",
	PERL_MATCH_YES,

	L"a(?:b|c|d)*(.)",
	L"",
	L"ace",
	PERL_MATCH_YES,

	L"a(?:b|c|d)+?(.)",
	L"",
	L"ace",
	PERL_MATCH_YES,

	L"a(?:b|c|d)+?(.)",
	L"",
	L"acdbcdbe",
	PERL_MATCH_YES,

	L"a(?:b|c|d)+(.)",
	L"",
	L"acdbcdbe",
	PERL_MATCH_YES,

	L"a(?:b|c|d){2}(.)",
	L"",
	L"acdbcdbe",
	PERL_MATCH_YES,

	L"a(?:b|c|d){4,5}(.)",
	L"",
	L"acdbcdbe",
	PERL_MATCH_YES,

	L"a(?:b|c|d){4,5}?(.)",
	L"",
	L"acdbcdbe",
	PERL_MATCH_YES,

	L"((foo)|(bar))*",
	L"",
	L"foobar",
	PERL_MATCH_YES,

	L":(?:",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"a(?:b|c|d){6,7}(.)",
	L"",
	L"acdbcdbe",
	PERL_MATCH_YES,

	L"a(?:b|c|d){6,7}?(.)",
	L"",
	L"acdbcdbe",
	PERL_MATCH_YES,

	L"a(?:b|c|d){5,6}(.)",
	L"",
	L"acdbcdbe",
	PERL_MATCH_YES,

	L"a(?:b|c|d){5,6}?(.)",
	L"",
	L"acdbcdbe",
	PERL_MATCH_YES,

	L"a(?:b|c|d){5,7}(.)",
	L"",
	L"acdbcdbe",
	PERL_MATCH_YES,

	L"a(?:b|c|d){5,7}?(.)",
	L"",
	L"acdbcdbe",
	PERL_MATCH_YES,

	L"a(?:b|(c|e){1,2}?|d)+?(.)",
	L"",
	L"ace",
	PERL_MATCH_YES,

	L"^(.+)?B",
	L"",
	L"AB",
	PERL_MATCH_YES,

	L"^([^a-z])|(\\^)$",
	L"",
	L".",
	PERL_MATCH_YES,

	L"^[<>]&",
	L"",
	L"<&OUT",
	PERL_MATCH_YES,

	L"^(a\\1?){4}$",
	L"",
	L"aaaaaaaaaa",
	PERL_MATCH_YES,

	L"^(a\\1?){4}$",
	L"",
	L"aaaaaaaaa",
	PERL_MATCH_NO,

	L"^(a\\1?){4}$",
	L"",
	L"aaaaaaaaaaa",
	PERL_MATCH_NO,

	L"^(a(?(1)\\1)){4}$",
	L"",
	L"aaaaaaaaaa",
	PERL_MATCH_YES,

	L"^(a(?(1)\\1)){4}$",
	L"",
	L"aaaaaaaaa",
	PERL_MATCH_NO,

	L"^(a(?(1)\\1)){4}$",
	L"",
	L"aaaaaaaaaaa",
	PERL_MATCH_NO,

	L"((a{4})+)",
	L"",
	L"aaaaaaaaa",
	PERL_MATCH_YES,

	L"(((aa){2})+)",
	L"",
	L"aaaaaaaaaa",
	PERL_MATCH_YES,

	L"(((a{2}){2})+)",
	L"",
	L"aaaaaaaaaa",
	PERL_MATCH_YES,

	L"(?:(f)(o)(o)|(b)(a)(r))*",
	L"",
	L"foobar",
	PERL_MATCH_YES,

	L"(?<=a)b",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"(?<=a)b",
	L"",
	L"cb",
	PERL_MATCH_NO,

	L"(?<=a)b",
	L"",
	L"b",
	PERL_MATCH_NO,

	L"(?<!c)b",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"(?<!c)b",
	L"",
	L"cb",
	PERL_MATCH_NO,

	L"(?<!c)b",
	L"",
	L"b",
	PERL_MATCH_YES,

	L"(?<!c)b",
	L"",
	L"b",
	PERL_MATCH_YES,

	L"(?<%)b",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(?:..)*a",
	L"",
	L"aba",
	PERL_MATCH_YES,

	L"(?:..)*?a",
	L"",
	L"aba",
	PERL_MATCH_YES,

	L"^(?:b|a(?=(.)))*\\1",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"^(){3,5}",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"^(a+)*ax",
	L"",
	L"aax",
	PERL_MATCH_YES,

	L"^((a|b)+)*ax",
	L"",
	L"aax",
	PERL_MATCH_YES,

	L"^((a|bc)+)*ax",
	L"",
	L"aax",
	PERL_MATCH_YES,

	L"(a|x)*ab",
	L"",
	L"cab",
	PERL_MATCH_YES,

	L"(a)*ab",
	L"",
	L"cab",
	PERL_MATCH_YES,

	L"(?:(?i)a)b",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"((?i)a)b",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"(?:(?i)a)b",
	L"",
	L"Ab",
	PERL_MATCH_YES,

	L"((?i)a)b",
	L"",
	L"Ab",
	PERL_MATCH_YES,

	L"(?:(?i)a)b",
	L"",
	L"aB",
	PERL_MATCH_NO,

	L"((?i)a)b",
	L"",
	L"aB",
	PERL_MATCH_NO,

	L"(?i:a)b",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"((?i:a))b",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"(?i:a)b",
	L"",
	L"Ab",
	PERL_MATCH_YES,

	L"((?i:a))b",
	L"",
	L"Ab",
	PERL_MATCH_YES,

	L"(?i:a)b",
	L"",
	L"aB",
	PERL_MATCH_NO,

	L"((?i:a))b",
	L"",
	L"aB",
	PERL_MATCH_NO,

	L"(?:(?-i)a)b",
	L"i",
	L"ab",
	PERL_MATCH_YES,

	L"((?-i)a)b",
	L"i",
	L"ab",
	PERL_MATCH_YES,

	L"(?:(?-i)a)b",
	L"i",
	L"aB",
	PERL_MATCH_YES,

	L"((?-i)a)b",
	L"i",
	L"aB",
	PERL_MATCH_YES,

	L"(?:(?-i)a)b",
	L"i",
	L"Ab",
	PERL_MATCH_NO,

	L"((?-i)a)b",
	L"i",
	L"Ab",
	PERL_MATCH_NO,

	L"(?:(?-i)a)b",
	L"i",
	L"aB",
	PERL_MATCH_YES,

	L"((?-i)a)b",
	L"i",
	L"aB",
	PERL_MATCH_YES,

	L"(?:(?-i)a)b",
	L"i",
	L"AB",
	PERL_MATCH_NO,

	L"((?-i)a)b",
	L"i",
	L"AB",
	PERL_MATCH_NO,

	L"(?-i:a)b",
	L"i",
	L"ab",
	PERL_MATCH_YES,

	L"((?-i:a))b",
	L"i",
	L"ab",
	PERL_MATCH_YES,

	L"(?-i:a)b",
	L"i",
	L"aB",
	PERL_MATCH_YES,

	L"((?-i:a))b",
	L"i",
	L"aB",
	PERL_MATCH_YES,

	L"(?-i:a)b",
	L"i",
	L"Ab",
	PERL_MATCH_NO,

	L"((?-i:a))b",
	L"i",
	L"Ab",
	PERL_MATCH_NO,

	L"(?-i:a)b",
	L"i",
	L"aB",
	PERL_MATCH_YES,

	L"((?-i:a))b",
	L"i",
	L"aB",
	PERL_MATCH_YES,

	L"(?-i:a)b",
	L"i",
	L"AB",
	PERL_MATCH_NO,

	L"((?-i:a))b",
	L"i",
	L"AB",
	PERL_MATCH_NO,

	L"((?-i:a.))b",
	L"i",
	L"a\nB",
	PERL_MATCH_NO,

	L"((?-i:a\\N))b",
	L"i",
	L"a\nB",
	PERL_MATCH_NO,

	L"((?s-i:a.))b",
	L"i",
	L"a\nB",
	PERL_MATCH_YES,

	L"((?s-i:a\\N))b",
	L"i",
	L"a\nB",
	PERL_MATCH_NO,

	L"((?s-i:a.))b",
	L"i",
	L"B\nB",
	PERL_MATCH_NO,

	L"((?s-i:a\\N))b",
	L"i",
	L"B\nB",
	PERL_MATCH_NO,

	L"(?:c|d)(?:)(?:a(?:)(?:b)(?:b(?:))(?:b(?:)(?:b)))",
	L"",
	L"cabbbb",
	PERL_MATCH_YES,

	L"(?:c|d)(?:)(?:aaaaaaaa(?:)(?:bbbbbbbb)(?:bbbbbbbb(?:))(?:bbbbbbbb(?:)(?:bbbbbbbb)))",
	L"",
	L"caaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	PERL_MATCH_YES,

	L"(ab)\\d\\1",
	L"i",
	L"Ab4ab",
	PERL_MATCH_YES,

	L"(ab)\\d\\1",
	L"i",
	L"ab4Ab",
	PERL_MATCH_YES,

	L"foo\\w*\\d{4}baz",
	L"",
	L"foobar1234baz",
	PERL_MATCH_YES,

	L"a(?{})b",
	L"",
	L"cabd",
	PERL_MATCH_YES,

	L"a(?{f()+",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"a(?{{1}+",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"a(?{}})b",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"a(?{\"{\"})b",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"a(?{\"\\{\"})b",
	L"",
	L"cabd",
	PERL_MATCH_YES,

	L"a(?{\"{\"}})b",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"a(?{$::bl=\"\\{\"}).b",
	L"",
	L"caxbd",
	PERL_MATCH_YES,

	L"x(~~)*(?:(?:F)?)?",
	L"",
	L"x~~",
	PERL_MATCH_YES,

	L"^a(?#xxx){3}c",
	L"",
	L"aaac",
	PERL_MATCH_YES,

	L"^a (?#xxx) (?#yyy) {3}c",
	L"x",
	L"aaac",
	PERL_MATCH_YES,

	L"(?<![cd])b",
	L"",
	L"dbcb",
	PERL_MATCH_NO,

	L"(?<![cd])[ab]",
	L"",
	L"dbaacb",
	PERL_MATCH_YES,

	L"(?<!(c|d))b",
	L"",
	L"dbcb",
	PERL_MATCH_NO,

	L"(?<!(c|d))[ab]",
	L"",
	L"dbaacb",
	PERL_MATCH_YES,

	L"(?<!cd)[ab]",
	L"",
	L"cdaccb",
	PERL_MATCH_YES,

	L"^(?:a?b?)*$",
	L"",
	L"a--",
	PERL_MATCH_NO,

	L"((?s)^a(.))((?m)^b$)",
	L"",
	L"a\nb\nc\n",
	PERL_MATCH_YES,

	L"((?m)^b$)",
	L"",
	L"a\nb\nc\n",
	PERL_MATCH_YES,

	L"(?m)^b",
	L"",
	L"a\nb\n",
	PERL_MATCH_YES,

	L"(?m)^(b)",
	L"",
	L"a\nb\n",
	PERL_MATCH_YES,

	L"((?m)^b)",
	L"",
	L"a\nb\n",
	PERL_MATCH_YES,

	L"\\n((?m)^b)",
	L"",
	L"a\nb\n",
	PERL_MATCH_YES,

	L"((?s).)c(?!.)",
	L"",
	L"a\nb\nc\n",
	PERL_MATCH_YES,

	L"((?s).)c(?!.)",
	L"",
	L"a\nb\nc\n",
	PERL_MATCH_YES,

	L"((?s)b.)c(?!.)",
	L"",
	L"a\nb\nc\n",
	PERL_MATCH_YES,

	L"((?s)b.)c(?!.)",
	L"",
	L"a\nb\nc\n",
	PERL_MATCH_YES,

	L"((?s)b.)c(?!\\N)",
	L"",
	L"a\nb\nc\n",
	PERL_MATCH_YES,

	L"(b.)c(?!\\N)",
	L"s",
	L"a\nb\nc\n",
	PERL_MATCH_YES,

	L"^b",
	L"",
	L"a\nb\nc\n",
	PERL_MATCH_NO,

	L"()^b",
	L"",
	L"a\nb\nc\n",
	PERL_MATCH_NO,

	L"((?m)^b)",
	L"",
	L"a\nb\nc\n",
	PERL_MATCH_YES,

	L"(?(1)a|b)",
	L"",
	L"a",
	PERL_MATCH_NO,

	L"(?(1)b|a)",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"(x)?(?(1)a|b)",
	L"",
	L"a",
	PERL_MATCH_NO,

	L"(x)?(?(1)b|a)",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"()?(?(1)b|a)",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"()(?(1)b|a)",
	L"",
	L"a",
	PERL_MATCH_NO,

	L"()?(?(1)a|b)",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"^(\\()?blah(?(1)(\\)))$",
	L"",
	L"(blah)",
	PERL_MATCH_YES,

	L"^(\\()?blah(?(1)(\\)))$",
	L"",
	L"blah",
	PERL_MATCH_YES,

	L"^(\\()?blah(?(1)(\\)))$",
	L"",
	L"blah)",
	PERL_MATCH_NO,

	L"^(\\()?blah(?(1)(\\)))$",
	L"",
	L"(blah",
	PERL_MATCH_NO,

	L"^(\\(+)?blah(?(1)(\\)))$",
	L"",
	L"(blah)",
	PERL_MATCH_YES,

	L"^(\\(+)?blah(?(1)(\\)))$",
	L"",
	L"blah",
	PERL_MATCH_YES,

	L"^(\\(+)?blah(?(1)(\\)))$",
	L"",
	L"blah)",
	PERL_MATCH_NO,

	L"^(\\(+)?blah(?(1)(\\)))$",
	L"",
	L"(blah",
	PERL_MATCH_NO,

	L"(?(1?)a|b)",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(?(1)a|b|c)",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(?(?{0})a|b)",
	L"",
	L"a",
	PERL_MATCH_NO,

	L"(?(?{0})b|a)",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"(?(?{1})b|a)",
	L"",
	L"a",
	PERL_MATCH_NO,

	L"(?(?{1})a|b)",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"(?(?!a)a|b)",
	L"",
	L"a",
	PERL_MATCH_NO,

	L"(?(?!a)b|a)",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"(?(?=a)b|a)",
	L"",
	L"a",
	PERL_MATCH_NO,

	L"(?(?=a)a|b)",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"(?(?!\\x{100})\\x{100}|b)",
	L"",
	L"\x100",
	PERL_MATCH_NO,

	L"(?(?!\\x{100})b|\\x{100})",
	L"",
	L"\x100",
	PERL_MATCH_YES,

	L"(?(?=\\x{100})b|\\x{100})",
	L"",
	L"\x100",
	PERL_MATCH_NO,

	L"(?(?=\\x{100})\\x{100}|b)",
	L"",
	L"\x100",
	PERL_MATCH_YES,

	L"(?=(a+?))(\\1ab)",
	L"",
	L"aaab",
	PERL_MATCH_YES,

	L"^(?=(a+?))\\1ab",
	L"",
	L"aaab",
	PERL_MATCH_NO,

	L"(\\w+:)+",
	L"",
	L"one:",
	PERL_MATCH_YES,

	L"$(?<=^(a))",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"(?=(a+?))(\\1ab)",
	L"",
	L"aaab",
	PERL_MATCH_YES,

	L"^(?=(a+?))\\1ab",
	L"",
	L"aaab",
	PERL_MATCH_NO,

	L"([\\w:]+::)?(\\w+)$",
	L"",
	L"abcd:",
	PERL_MATCH_NO,

	L"([\\w:]+::)?(\\w+)$",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"([\\w:]+::)?(\\w+)$",
	L"",
	L"xy:z:::abcd",
	PERL_MATCH_YES,

	L"^[^bcd]*(c+)",
	L"",
	L"aexycd",
	PERL_MATCH_YES,

	L"(a*)b+",
	L"",
	L"caab",
	PERL_MATCH_YES,

	L"([\\w:]+::)?(\\w+)$",
	L"",
	L"abcd:",
	PERL_MATCH_NO,

	L"([\\w:]+::)?(\\w+)$",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"([\\w:]+::)?(\\w+)$",
	L"",
	L"xy:z:::abcd",
	PERL_MATCH_YES,

	L"^[^bcd]*(c+)",
	L"",
	L"aexycd",
	PERL_MATCH_YES,

	L"(?{$a=2})a*aa(?{local$a=$a+1})k*c(?{$b=$a})",
	L"",
	L"yaaxxaaaacd",
	PERL_MATCH_YES,

	L"(?{$a=2})(a(?{local$a=$a+1}))*aak*c(?{$b=$a})",
	L"",
	L"yaaxxaaaacd",
	PERL_MATCH_YES,

	L"(>a+)ab",
	L"",
	L"aaab",
	PERL_MATCH_NO,

	L"(?>a+)b",
	L"",
	L"aaab",
	PERL_MATCH_YES,

	L"([[:]+)",
	L"",
	L"a:[b]:",
	PERL_MATCH_YES,

	L"([[=]+)",
	L"",
	L"a=[b]=",
	PERL_MATCH_YES,

	L"([[.]+)",
	L"",
	L"a.[b].",
	PERL_MATCH_YES,

	L"[a[:xyz:",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"[a[:xyz:]",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"[a[:]b[:c]",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"([a[:xyz:]b]+)",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"([[:alpha:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:alnum:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:ascii:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:cntrl:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:digit:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:graph:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:lower:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:print:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:punct:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:space:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:word:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:upper:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:xdigit:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:^alpha:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"((?a)[[:^alnum:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:^ascii:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:^cntrl:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:^digit:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:^lower:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"((?a)[[:^print:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:^punct:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:^space:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"((?a)[[:^word:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:^upper:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"([[:^xdigit:]]+)",
	L"",
	L"ABcd01Xy__--  ${nulnul}${ffff}",
	PERL_MATCH_YES,

	L"[[:foo:]]",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"[[:^foo:]]",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"((?>a+)b)",
	L"",
	L"aaab",
	PERL_MATCH_YES,

	L"(?>(a+))b",
	L"",
	L"aaab",
	PERL_MATCH_YES,

	L"((?>[^()]+)|\\([^()]*\\))+",
	L"",
	L"((abc(ade)ufh()()x",
	PERL_MATCH_YES,

	L"(?<=x+)y",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"((def){37,17})?ABC",
	L"",
	L"ABC",
	PERL_MATCH_YES,

	L"\\Z",
	L"",
	L"a\nb\n",
	PERL_MATCH_YES,

	L"\\z",
	L"",
	L"a\nb\n",
	PERL_MATCH_YES,

	L"$",
	L"",
	L"a\nb\n",
	PERL_MATCH_YES,

	L"\\Z",
	L"",
	L"b\na\n",
	PERL_MATCH_YES,

	L"\\z",
	L"",
	L"b\na\n",
	PERL_MATCH_YES,

	L"$",
	L"",
	L"b\na\n",
	PERL_MATCH_YES,

	L"\\Z",
	L"",
	L"b\na",
	PERL_MATCH_YES,

	L"\\z",
	L"",
	L"b\na",
	PERL_MATCH_YES,

	L"$",
	L"",
	L"b\na",
	PERL_MATCH_YES,

	L"\\Z",
	L"m",
	L"a\nb\n",
	PERL_MATCH_YES,

	L"\\z",
	L"m",
	L"a\nb\n",
	PERL_MATCH_YES,

	L"$",
	L"m",
	L"a\nb\n",
	PERL_MATCH_YES,

	L"\\Z",
	L"m",
	L"b\na\n",
	PERL_MATCH_YES,

	L"\\z",
	L"m",
	L"b\na\n",
	PERL_MATCH_YES,

	L"$",
	L"m",
	L"b\na\n",
	PERL_MATCH_YES,

	L"\\Z",
	L"m",
	L"b\na",
	PERL_MATCH_YES,

	L"\\z",
	L"m",
	L"b\na",
	PERL_MATCH_YES,

	L"$",
	L"m",
	L"b\na",
	PERL_MATCH_YES,

	L"a\\Z",
	L"",
	L"a\nb\n",
	PERL_MATCH_NO,

	L"a\\z",
	L"",
	L"a\nb\n",
	PERL_MATCH_NO,

	L"a$",
	L"",
	L"a\nb\n",
	PERL_MATCH_NO,

	L"a\\Z",
	L"",
	L"b\na\n",
	PERL_MATCH_YES,

	L"a\\z",
	L"",
	L"b\na\n",
	PERL_MATCH_NO,

	L"a$",
	L"",
	L"b\na\n",
	PERL_MATCH_YES,

	L"a\\Z",
	L"",
	L"b\na",
	PERL_MATCH_YES,

	L"a\\z",
	L"",
	L"b\na",
	PERL_MATCH_YES,

	L"a$",
	L"",
	L"b\na",
	PERL_MATCH_YES,

	L"a\\Z",
	L"m",
	L"a\nb\n",
	PERL_MATCH_NO,

	L"a\\z",
	L"m",
	L"a\nb\n",
	PERL_MATCH_NO,

	L"a$",
	L"m",
	L"a\nb\n",
	PERL_MATCH_YES,

	L"a\\Z",
	L"m",
	L"b\na\n",
	PERL_MATCH_YES,

	L"a\\z",
	L"m",
	L"b\na\n",
	PERL_MATCH_NO,

	L"a$",
	L"m",
	L"b\na\n",
	PERL_MATCH_YES,

	L"a\\Z",
	L"m",
	L"b\na",
	PERL_MATCH_YES,

	L"a\\z",
	L"m",
	L"b\na",
	PERL_MATCH_YES,

	L"a$",
	L"m",
	L"b\na",
	PERL_MATCH_YES,

	L"aa\\Z",
	L"",
	L"aa\nb\n",
	PERL_MATCH_NO,

	L"aa\\z",
	L"",
	L"aa\nb\n",
	PERL_MATCH_NO,

	L"aa$",
	L"",
	L"aa\nb\n",
	PERL_MATCH_NO,

	L"aa\\Z",
	L"",
	L"b\naa\n",
	PERL_MATCH_YES,

	L"aa\\z",
	L"",
	L"b\naa\n",
	PERL_MATCH_NO,

	L"aa$",
	L"",
	L"b\naa\n",
	PERL_MATCH_YES,

	L"aa\\Z",
	L"",
	L"b\naa",
	PERL_MATCH_YES,

	L"aa\\z",
	L"",
	L"b\naa",
	PERL_MATCH_YES,

	L"aa$",
	L"",
	L"b\naa",
	PERL_MATCH_YES,

	L"aa\\Z",
	L"m",
	L"aa\nb\n",
	PERL_MATCH_NO,

	L"aa\\z",
	L"m",
	L"aa\nb\n",
	PERL_MATCH_NO,

	L"aa$",
	L"m",
	L"aa\nb\n",
	PERL_MATCH_YES,

	L"aa\\Z",
	L"m",
	L"b\naa\n",
	PERL_MATCH_YES,

	L"aa\\z",
	L"m",
	L"b\naa\n",
	PERL_MATCH_NO,

	L"aa$",
	L"m",
	L"b\naa\n",
	PERL_MATCH_YES,

	L"aa\\Z",
	L"m",
	L"b\naa",
	PERL_MATCH_YES,

	L"aa\\z",
	L"m",
	L"b\naa",
	PERL_MATCH_YES,

	L"aa$",
	L"m",
	L"b\naa",
	PERL_MATCH_YES,

	L"aa\\Z",
	L"",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"aa\\z",
	L"",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"aa$",
	L"",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"aa\\Z",
	L"",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"aa\\z",
	L"",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"aa$",
	L"",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"aa\\Z",
	L"",
	L"b\nac",
	PERL_MATCH_NO,

	L"aa\\z",
	L"",
	L"b\nac",
	PERL_MATCH_NO,

	L"aa$",
	L"",
	L"b\nac",
	PERL_MATCH_NO,

	L"aa\\Z",
	L"m",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"aa\\z",
	L"m",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"aa$",
	L"m",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"aa\\Z",
	L"m",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"aa\\z",
	L"m",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"aa$",
	L"m",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"aa\\Z",
	L"m",
	L"b\nac",
	PERL_MATCH_NO,

	L"aa\\z",
	L"m",
	L"b\nac",
	PERL_MATCH_NO,

	L"aa$",
	L"m",
	L"b\nac",
	PERL_MATCH_NO,

	L"aa\\Z",
	L"",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"aa\\z",
	L"",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"aa$",
	L"",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"aa\\Z",
	L"",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"aa\\z",
	L"",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"aa$",
	L"",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"aa\\Z",
	L"",
	L"b\nca",
	PERL_MATCH_NO,

	L"aa\\z",
	L"",
	L"b\nca",
	PERL_MATCH_NO,

	L"aa$",
	L"",
	L"b\nca",
	PERL_MATCH_NO,

	L"aa\\Z",
	L"m",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"aa\\z",
	L"m",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"aa$",
	L"m",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"aa\\Z",
	L"m",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"aa\\z",
	L"m",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"aa$",
	L"m",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"aa\\Z",
	L"m",
	L"b\nca",
	PERL_MATCH_NO,

	L"aa\\z",
	L"m",
	L"b\nca",
	PERL_MATCH_NO,

	L"aa$",
	L"m",
	L"b\nca",
	PERL_MATCH_NO,

	L"ab\\Z",
	L"",
	L"ab\nb\n",
	PERL_MATCH_NO,

	L"ab\\z",
	L"",
	L"ab\nb\n",
	PERL_MATCH_NO,

	L"ab$",
	L"",
	L"ab\nb\n",
	PERL_MATCH_NO,

	L"ab\\Z",
	L"",
	L"b\nab\n",
	PERL_MATCH_YES,

	L"ab\\z",
	L"",
	L"b\nab\n",
	PERL_MATCH_NO,

	L"ab$",
	L"",
	L"b\nab\n",
	PERL_MATCH_YES,

	L"ab\\Z",
	L"",
	L"b\nab",
	PERL_MATCH_YES,

	L"ab\\z",
	L"",
	L"b\nab",
	PERL_MATCH_YES,

	L"ab$",
	L"",
	L"b\nab",
	PERL_MATCH_YES,

	L"ab\\Z",
	L"m",
	L"ab\nb\n",
	PERL_MATCH_NO,

	L"ab\\z",
	L"m",
	L"ab\nb\n",
	PERL_MATCH_NO,

	L"ab$",
	L"m",
	L"ab\nb\n",
	PERL_MATCH_YES,

	L"ab\\Z",
	L"m",
	L"b\nab\n",
	PERL_MATCH_YES,

	L"ab\\z",
	L"m",
	L"b\nab\n",
	PERL_MATCH_NO,

	L"ab$",
	L"m",
	L"b\nab\n",
	PERL_MATCH_YES,

	L"ab\\Z",
	L"m",
	L"b\nab",
	PERL_MATCH_YES,

	L"ab\\z",
	L"m",
	L"b\nab",
	PERL_MATCH_YES,

	L"ab$",
	L"m",
	L"b\nab",
	PERL_MATCH_YES,

	L"ab\\Z",
	L"",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"ab\\z",
	L"",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"ab$",
	L"",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"ab\\Z",
	L"",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"ab\\z",
	L"",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"ab$",
	L"",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"ab\\Z",
	L"",
	L"b\nac",
	PERL_MATCH_NO,

	L"ab\\z",
	L"",
	L"b\nac",
	PERL_MATCH_NO,

	L"ab$",
	L"",
	L"b\nac",
	PERL_MATCH_NO,

	L"ab\\Z",
	L"m",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"ab\\z",
	L"m",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"ab$",
	L"m",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"ab\\Z",
	L"m",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"ab\\z",
	L"m",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"ab$",
	L"m",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"ab\\Z",
	L"m",
	L"b\nac",
	PERL_MATCH_NO,

	L"ab\\z",
	L"m",
	L"b\nac",
	PERL_MATCH_NO,

	L"ab$",
	L"m",
	L"b\nac",
	PERL_MATCH_NO,

	L"ab\\Z",
	L"",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"ab\\z",
	L"",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"ab$",
	L"",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"ab\\Z",
	L"",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"ab\\z",
	L"",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"ab$",
	L"",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"ab\\Z",
	L"",
	L"b\nca",
	PERL_MATCH_NO,

	L"ab\\z",
	L"",
	L"b\nca",
	PERL_MATCH_NO,

	L"ab$",
	L"",
	L"b\nca",
	PERL_MATCH_NO,

	L"ab\\Z",
	L"m",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"ab\\z",
	L"m",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"ab$",
	L"m",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"ab\\Z",
	L"m",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"ab\\z",
	L"m",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"ab$",
	L"m",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"ab\\Z",
	L"m",
	L"b\nca",
	PERL_MATCH_NO,

	L"ab\\z",
	L"m",
	L"b\nca",
	PERL_MATCH_NO,

	L"ab$",
	L"m",
	L"b\nca",
	PERL_MATCH_NO,

	L"abb\\Z",
	L"",
	L"abb\nb\n",
	PERL_MATCH_NO,

	L"abb\\z",
	L"",
	L"abb\nb\n",
	PERL_MATCH_NO,

	L"abb$",
	L"",
	L"abb\nb\n",
	PERL_MATCH_NO,

	L"abb\\Z",
	L"",
	L"b\nabb\n",
	PERL_MATCH_YES,

	L"abb\\z",
	L"",
	L"b\nabb\n",
	PERL_MATCH_NO,

	L"abb$",
	L"",
	L"b\nabb\n",
	PERL_MATCH_YES,

	L"abb\\Z",
	L"",
	L"b\nabb",
	PERL_MATCH_YES,

	L"abb\\z",
	L"",
	L"b\nabb",
	PERL_MATCH_YES,

	L"abb$",
	L"",
	L"b\nabb",
	PERL_MATCH_YES,

	L"abb\\Z",
	L"m",
	L"abb\nb\n",
	PERL_MATCH_NO,

	L"abb\\z",
	L"m",
	L"abb\nb\n",
	PERL_MATCH_NO,

	L"abb$",
	L"m",
	L"abb\nb\n",
	PERL_MATCH_YES,

	L"abb\\Z",
	L"m",
	L"b\nabb\n",
	PERL_MATCH_YES,

	L"abb\\z",
	L"m",
	L"b\nabb\n",
	PERL_MATCH_NO,

	L"abb$",
	L"m",
	L"b\nabb\n",
	PERL_MATCH_YES,

	L"abb\\Z",
	L"m",
	L"b\nabb",
	PERL_MATCH_YES,

	L"abb\\z",
	L"m",
	L"b\nabb",
	PERL_MATCH_YES,

	L"abb$",
	L"m",
	L"b\nabb",
	PERL_MATCH_YES,

	L"abb\\Z",
	L"",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"abb\\z",
	L"",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"abb$",
	L"",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"abb\\Z",
	L"",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"abb\\z",
	L"",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"abb$",
	L"",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"abb\\Z",
	L"",
	L"b\nac",
	PERL_MATCH_NO,

	L"abb\\z",
	L"",
	L"b\nac",
	PERL_MATCH_NO,

	L"abb$",
	L"",
	L"b\nac",
	PERL_MATCH_NO,

	L"abb\\Z",
	L"m",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"abb\\z",
	L"m",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"abb$",
	L"m",
	L"ac\nb\n",
	PERL_MATCH_NO,

	L"abb\\Z",
	L"m",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"abb\\z",
	L"m",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"abb$",
	L"m",
	L"b\nac\n",
	PERL_MATCH_NO,

	L"abb\\Z",
	L"m",
	L"b\nac",
	PERL_MATCH_NO,

	L"abb\\z",
	L"m",
	L"b\nac",
	PERL_MATCH_NO,

	L"abb$",
	L"m",
	L"b\nac",
	PERL_MATCH_NO,

	L"abb\\Z",
	L"",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"abb\\z",
	L"",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"abb$",
	L"",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"abb\\Z",
	L"",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"abb\\z",
	L"",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"abb$",
	L"",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"abb\\Z",
	L"",
	L"b\nca",
	PERL_MATCH_NO,

	L"abb\\z",
	L"",
	L"b\nca",
	PERL_MATCH_NO,

	L"abb$",
	L"",
	L"b\nca",
	PERL_MATCH_NO,

	L"abb\\Z",
	L"m",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"abb\\z",
	L"m",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"abb$",
	L"m",
	L"ca\nb\n",
	PERL_MATCH_NO,

	L"abb\\Z",
	L"m",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"abb\\z",
	L"m",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"abb$",
	L"m",
	L"b\nca\n",
	PERL_MATCH_NO,

	L"abb\\Z",
	L"m",
	L"b\nca",
	PERL_MATCH_NO,

	L"abb\\z",
	L"m",
	L"b\nca",
	PERL_MATCH_NO,

	L"abb$",
	L"m",
	L"b\nca",
	PERL_MATCH_NO,

	L"\\Aa$",
	L"m",
	L"a\n\n",
	PERL_MATCH_YES,

	L"(^|x)(c)",
	L"",
	L"ca",
	PERL_MATCH_YES,

	L"a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz",
	L"",
	L"x",
	PERL_MATCH_NO,

	L"a(?{$a=2;$b=3;($b)=$a})b",
	L"",
	L"yabz",
	PERL_MATCH_YES,

	L"round\\(((?>[^()]+))\\)",
	L"",
	L"_I(round(xs * sz),1)",
	PERL_MATCH_YES,

	L"((?x:.) )",
	L"",
	L"x ",
	PERL_MATCH_YES,

	L"((?-x:.) )",
	L"x",
	L"x ",
	PERL_MATCH_YES,

	L"foo.bart",
	L"",
	L"foo.bart",
	PERL_MATCH_YES,

	L"^d[x][x][x]",
	L"m",
	L"abcd\ndxxx",
	PERL_MATCH_YES,

	L".X(.+)+X",
	L"",
	L"bbbbXcXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_YES,

	L".X(.+)+XX",
	L"",
	L"bbbbXcXXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_YES,

	L".XX(.+)+X",
	L"",
	L"bbbbXXcXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_YES,

	L".X(.+)+X",
	L"",
	L"bbbbXXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_NO,

	L".X(.+)+XX",
	L"",
	L"bbbbXXXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_NO,

	L".XX(.+)+X",
	L"",
	L"bbbbXXXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_NO,

	L".X(.+)+[X]",
	L"",
	L"bbbbXcXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_YES,

	L".X(.+)+[X][X]",
	L"",
	L"bbbbXcXXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_YES,

	L".XX(.+)+[X]",
	L"",
	L"bbbbXXcXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_YES,

	L".X(.+)+[X]",
	L"",
	L"bbbbXXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_NO,

	L".X(.+)+[X][X]",
	L"",
	L"bbbbXXXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_NO,

	L".XX(.+)+[X]",
	L"",
	L"bbbbXXXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_NO,

	L".[X](.+)+[X]",
	L"",
	L"bbbbXcXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_YES,

	L".[X](.+)+[X][X]",
	L"",
	L"bbbbXcXXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_YES,

	L".[X][X](.+)+[X]",
	L"",
	L"bbbbXXcXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_YES,

	L".[X](.+)+[X]",
	L"",
	L"bbbbXXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_NO,

	L".[X](.+)+[X][X]",
	L"",
	L"bbbbXXXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_NO,

	L".[X][X](.+)+[X]",
	L"",
	L"bbbbXXXaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_NO,

	L"tt+$",
	L"",
	L"xxxtt",
	PERL_MATCH_YES,

	L"([a-\\d]+)",
	L"",
	L"za-9z",
	PERL_MATCH_YES,

	L"([a-\\d]+)",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"([\\d-z]+)",
	L"",
	L"a0-za",
	PERL_MATCH_YES,

	L"([\\d-z]+)",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"([\\d-\\s]+)",
	L"",
	L"a0- z",
	PERL_MATCH_YES,

	L"([\\d-\\s]+)",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"([a-[:digit:]]+)",
	L"",
	L"za-9z",
	PERL_MATCH_YES,

	L"([a-[:digit:]]+)",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"([[:digit:]-z]+)",
	L"",
	L"=0-z=",
	PERL_MATCH_YES,

	L"([[:digit:]-z]+)",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"([[:digit:]-[:alpha:]]+)",
	L"",
	L"=0-z=",
	PERL_MATCH_YES,

	L"([[:digit:]-[:alpha:]]+)",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\GX.*X",
	L"",
	L"aaaXbX",
	PERL_MATCH_NO,

	L"(\\d+\\.\\d+)",
	L"",
	L"3.1415926",
	PERL_MATCH_YES,

	L"(\\ba.{0,10}br)",
	L"",
	L"have a web browser",
	PERL_MATCH_YES,

	L"\\.c(pp|xx|c)?$",
	L"i",
	L"Changes",
	PERL_MATCH_NO,

	L"\\.c(pp|xx|c)?$",
	L"i",
	L"IO.c",
	PERL_MATCH_YES,

	L"(\\.c(pp|xx|c)?$)",
	L"i",
	L"IO.c",
	PERL_MATCH_YES,

	L"^([a-z]:)",
	L"",
	L"C:/",
	PERL_MATCH_NO,

	L"^\\S\\s+aa$",
	L"m",
	L"\nx aa",
	PERL_MATCH_YES,

	L"(^|a)b",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"^([ab]*?)(b)?(c)$",
	L"",
	L"abac",
	PERL_MATCH_YES,

	L"(\\w)?(abc)\\1b",
	L"",
	L"abcab",
	PERL_MATCH_NO,

	L"^(?:.,){2}c",
	L"",
	L"a,b,c",
	PERL_MATCH_YES,

	L"^(.,){2}c",
	L"",
	L"a,b,c",
	PERL_MATCH_YES,

	L"^(?:[^,]*,){2}c",
	L"",
	L"a,b,c",
	PERL_MATCH_YES,

	L"^([^,]*,){2}c",
	L"",
	L"a,b,c",
	PERL_MATCH_YES,

	L"^([^,]*,){3}d",
	L"",
	L"aaa,b,c,d",
	PERL_MATCH_YES,

	L"^([^,]*,){3,}d",
	L"",
	L"aaa,b,c,d",
	PERL_MATCH_YES,

	L"^([^,]*,){0,3}d",
	L"",
	L"aaa,b,c,d",
	PERL_MATCH_YES,

	L"^([^,]{1,3},){3}d",
	L"",
	L"aaa,b,c,d",
	PERL_MATCH_YES,

	L"^([^,]{1,3},){3,}d",
	L"",
	L"aaa,b,c,d",
	PERL_MATCH_YES,

	L"^([^,]{1,3},){0,3}d",
	L"",
	L"aaa,b,c,d",
	PERL_MATCH_YES,

	L"^([^,]{1,},){3}d",
	L"",
	L"aaa,b,c,d",
	PERL_MATCH_YES,

	L"^([^,]{1,},){3,}d",
	L"",
	L"aaa,b,c,d",
	PERL_MATCH_YES,

	L"^([^,]{1,},){0,3}d",
	L"",
	L"aaa,b,c,d",
	PERL_MATCH_YES,

	L"^([^,]{0,3},){3}d",
	L"",
	L"aaa,b,c,d",
	PERL_MATCH_YES,

	L"^([^,]{0,3},){3,}d",
	L"",
	L"aaa,b,c,d",
	PERL_MATCH_YES,

	L"^([^,]{0,3},){0,3}d",
	L"",
	L"aaa,b,c,d",
	PERL_MATCH_YES,

	L"(?i)",
	L"",
	L"",
	PERL_MATCH_YES,

	L"(?a:((?u)\\w)\\W)",
	L"",
	L"\xC0\xC0",
	PERL_MATCH_YES,

	L"(?!\\A)x",
	L"m",
	L"a\nxb\n",
	PERL_MATCH_YES,

	L"^(a(b)?)+$",
	L"",
	L"aba",
	PERL_MATCH_YES,

	L"^(aa(bb)?)+$",
	L"",
	L"aabbaa",
	PERL_MATCH_YES,

	L"^.{9}abc.*\\n",
	L"m",
	L"123\nabcabcabcabc\n",
	PERL_MATCH_YES,

	L"^(a)?a$",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"^(a)?(?(1)a|b)+$",
	L"",
	L"a",
	PERL_MATCH_NO,

	L"^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$",
	L"",
	L"aaaaaa",
	PERL_MATCH_YES,

	L"^(a\\1?){4}$",
	L"",
	L"aaaaaa",
	PERL_MATCH_YES,

	L"^(0+)?(?:x(1))?",
	L"",
	L"x1",
	PERL_MATCH_YES,

	L"^([0-9a-fA-F]+)(?:x([0-9a-fA-F]+)?)(?:x([0-9a-fA-F]+))?",
	L"",
	L"012cxx0190",
	PERL_MATCH_YES,

	L"^(b+?|a){1,2}c",
	L"",
	L"bbbac",
	PERL_MATCH_YES,

	L"^(b+?|a){1,2}c",
	L"",
	L"bbbbac",
	PERL_MATCH_YES,

	L"\\((\\w\\. \\w+)\\)",
	L"",
	L"cd. (A. Tw)",
	PERL_MATCH_YES,

	L"((?:aaaa|bbbb)cccc)?",
	L"",
	L"aaaacccc",
	PERL_MATCH_YES,

	L"((?:aaaa|bbbb)cccc)?",
	L"",
	L"bbbbcccc",
	PERL_MATCH_YES,

	L"(a)?(a)+",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"(ab)?(ab)+",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"(abc)?(abc)+",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"b\\s^",
	L"m",
	L"a\nb\n",
	PERL_MATCH_NO,

	L"\\ba",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"^(a(??{\"(?!)\"})|(a)(?{1}))b",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"ab(?i)cd",
	L"",
	L"AbCd",
	PERL_MATCH_NO,

	L"ab(?i)cd",
	L"",
	L"abCd",
	PERL_MATCH_YES,

	L"(A|B)*(?(1)(CD)|(CD))",
	L"",
	L"CD",
	PERL_MATCH_YES,

	L"(A|B)*(?(1)(CD)|(CD))",
	L"",
	L"ABCD",
	PERL_MATCH_YES,

	L"(A|B)*?(?(1)(CD)|(CD))",
	L"",
	L"CD",
	PERL_MATCH_YES,

	L"(A|B)*?(?(1)(CD)|(CD))",
	L"",
	L"ABCD",
	PERL_MATCH_YES,

	L"^(o)(?!.*\\1)",
	L"i",
	L"Oo",
	PERL_MATCH_NO,

	L"(.*)\\d+\\1",
	L"",
	L"abc12bc",
	PERL_MATCH_YES,

	L"(?m:(foo\\s*$))",
	L"",
	L"foo\n bar",
	PERL_MATCH_YES,

	L"(.*)c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?=c)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?=c)c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?=b|c)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?=b|c)c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?=c|b)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?=c|b)c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?=[bc])",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?=[bc])c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?<=b)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?<=b)c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?<=b|c)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?<=b|c)c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?<=c|b)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?<=c|b)c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?<=[bc])",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*)(?<=[bc])c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?=c)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?=c)c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?=b|c)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?=b|c)c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?=c|b)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?=c|b)c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?=[bc])",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?=[bc])c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?<=b)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?<=b)c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?<=b|c)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?<=b|c)c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?<=c|b)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?<=c|b)c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?<=[bc])",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"(.*?)(?<=[bc])c",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"2(]*)?$\\1",
	L"",
	L"2",
	PERL_MATCH_YES,

	L"(??{})",
	L"",
	L"x",
	PERL_MATCH_YES,

	L"a(b)??",
	L"",
	L"abc",
	PERL_MATCH_YES,

	L"(\\d{1,3}\\.){3,}",
	L"",
	L"128.134.142.8",
	PERL_MATCH_YES,

	L"^.{3,4}(.+)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L"^(?:f|o|b){3,4}(.+)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L"^.{3,4}((?:b|a|r)+)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L"^(?:f|o|b){3,4}((?:b|a|r)+)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L"^.{3,4}(.+?)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L"^(?:f|o|b){3,4}(.+?)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L"^.{3,4}((?:b|a|r)+?)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L"^(?:f|o|b){3,4}((?:b|a|r)+?)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L"^.{2,3}?(.+)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L"^(?:f|o|b){2,3}?(.+)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L"^.{2,3}?((?:b|a|r)+)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L"^(?:f|o|b){2,3}?((?:b|a|r)+)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L"^.{2,3}?(.+?)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L"^(?:f|o|b){2,3}?(.+?)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L"^.{2,3}?((?:b|a|r)+?)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L"^(?:f|o|b){2,3}?((?:b|a|r)+?)\\1\\z",
	L"",
	L"foobarbar",
	PERL_MATCH_YES,

	L".*a(?!(b|cd)*e).*f",
	L"",
	L"......abef",
	PERL_MATCH_NO,

	L"x(?#",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L":x(?#:",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(WORDS|WORD)S",
	L"",
	L"WORDS",
	PERL_MATCH_YES,

	L"(X.|WORDS|X.|WORD)S",
	L"",
	L"WORDS",
	PERL_MATCH_YES,

	L"(WORDS|WORLD|WORD)S",
	L"",
	L"WORDS",
	PERL_MATCH_YES,

	L"(X.|WORDS|WORD|Y.)S",
	L"",
	L"WORDS",
	PERL_MATCH_YES,

	L"(foo|fool|x.|money|parted)$",
	L"",
	L"fool",
	PERL_MATCH_YES,

	L"(x.|foo|fool|x.|money|parted|y.)$",
	L"",
	L"fool",
	PERL_MATCH_YES,

	L"(foo|fool|money|parted)$",
	L"",
	L"fool",
	PERL_MATCH_YES,

	L"(foo|fool|x.|money|parted)$",
	L"",
	L"fools",
	PERL_MATCH_NO,

	L"(x.|foo|fool|x.|money|parted|y.)$",
	L"",
	L"fools",
	PERL_MATCH_NO,

	L"(foo|fool|money|parted)$",
	L"",
	L"fools",
	PERL_MATCH_NO,

	L"(a|aa|aaa||aaaa|aaaaa|aaaaaa)(b|c)",
	L"",
	L"aaaaaaaaaaaaaaab",
	PERL_MATCH_YES,

	L"(a|aa|aaa||aaaa|aaaaa|aaaaaa)(??{$1&&\"\"})(b|c)",
	L"",
	L"aaaaaaaaaaaaaaab",
	PERL_MATCH_YES,

	L"(a|aa|aaa|aaaa|aaaaa|aaaaaa)(??{$1&&\"foo\"})(b|c)",
	L"",
	L"aaaaaaaaaaaaaaab",
	PERL_MATCH_NO,

	L"^(a*?)(?!(aa|aaaa)*$)",
	L"",
	L"aaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_YES,

	L"^(a*?)(?!(aa|aaaa)*$)(?=a\\z)",
	L"",
	L"aaaaaaaa",
	PERL_MATCH_YES,

	L"^(.)\\s+.$(?(1))",
	L"",
	L"A B",
	PERL_MATCH_YES,

	L"(?:r?)*?r|(.{2,4})",
	L"",
	L"abcde",
	PERL_MATCH_YES,

	L"(?!)+?|(.{2,4})",
	L"",
	L"abcde",
	PERL_MATCH_YES,

	L"^(a*?)(?!(a{6}|a{5})*$)",
	L"",
	L"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
	PERL_MATCH_YES,

	L"^((?>(?:aa)?b)?)",
	L"",
	L"aab",
	PERL_MATCH_YES,

	L"^((?:aa)*)(?:X+((?:\\d+|-)(?:X+(.+))?))?$",
	L"",
	L"aaaaX5",
	PERL_MATCH_YES,

	L"X(A|B||C|D)Y",
	L"",
	L"XXXYYY",
	PERL_MATCH_YES,

	L"(?i:X([A]|[B]|y[Y]y|[D]|)Y)",
	L"",
	L"XXXYYYB",
	PERL_MATCH_YES,

	L"^([a]{1})*$",
	L"",
	L"aa",
	PERL_MATCH_YES,

	L"a(?!b(?!c))(..)",
	L"",
	L"abababc",
	PERL_MATCH_YES,

	L"a(?!b(?=a))(..)",
	L"",
	L"abababc",
	PERL_MATCH_YES,

	L"a(?!b(?!c(?!d(?!e))))...(.)",
	L"",
	L"abxabcdxabcde",
	PERL_MATCH_YES,

	L"X(?!b+(?!(c+)*(?!(c+)*d))).*X",
	L"",
	L"aXbbbbbbbcccccccccccccaaaX",
	PERL_MATCH_YES,

	L"^(XXXXXXXXXX|YYYYYYYYYY|Z.Q*X|Z[TE]Q*P):",
	L"",
	L"ZEQQQQQQQQQQQQQQQQQQP:",
	PERL_MATCH_YES,

	L"^(XXXXXXXXXX|YYYYYYYYYY|Z.Q*X|Z[TE]Q*P):",
	L"",
	L"ZEQQQX:",
	PERL_MATCH_YES,

	L"^([TUV]+|XXXXXXXXXX|YYYYYYYYYY|Z.Q*X|Z[TE]Q*P):",
	L"",
	L"ZEQQQQQQQQQQQQQQQQQQP:",
	PERL_MATCH_YES,

	L"^([TUV]+|XXXXXXXXXX|YYYYYYYYYY|Z.Q*X|Z[TE]Q*P):",
	L"",
	L"ZEQQQX:",
	PERL_MATCH_YES,

	L"^([TUV]+|XXXXXXXXXX|YYYYYYYYYY|Z.Q*X|Z[TE]Q*P|[MKJ]):",
	L"",
	L"ZEQQQQQQQQQQQQQQQQQQP:",
	PERL_MATCH_YES,

	L"^([TUV]+|XXXXXXXXXX|YYYYYYYYYY|Z.Q*X|Z[TE]Q*P|[MKJ]):",
	L"",
	L"ZEQQQX:",
	PERL_MATCH_YES,

	L"^(XXX|YYY|Z.Q*X|Z[TE]Q*P):",
	L"",
	L"ZEQQQQQQQQQQQQQQQQQQP:",
	PERL_MATCH_YES,

	L"^(XXX|YYY|Z.Q*X|Z[TE]Q*P):",
	L"",
	L"ZEQQQX:",
	PERL_MATCH_YES,

	L"^([TUV]+|XXX|YYY|Z.Q*X|Z[TE]Q*P):",
	L"",
	L"ZEQQQQQQQQQQQQQQQQQQP:",
	PERL_MATCH_YES,

	L"^([TUV]+|XXX|YYY|Z.Q*X|Z[TE]Q*P):",
	L"",
	L"ZEQQQX:",
	PERL_MATCH_YES,

	L"^([TUV]+|XXX|YYY|Z.Q*X|Z[TE]Q*P|[MKJ]):",
	L"",
	L"ZEQQQQQQQQQQQQQQQQQQP:",
	PERL_MATCH_YES,

	L"^([TUV]+|XXX|YYY|Z.Q*X|Z[TE]Q*P|[MKJ]):",
	L"",
	L"ZEQQQX:",
	PERL_MATCH_YES,

	L"X(?:ABCF[cC]x*|ABCD|ABCF):(?:DIT|DID|DIM)",
	L"",
	L"XABCFCxxxxxxxxxx:DIM",
	PERL_MATCH_YES,

	L"(((ABCD|ABCE|ABCF)))(A|B|C[xy]*):",
	L"",
	L"ABCFCxxxxxxxxxx:DIM",
	PERL_MATCH_YES,

	L"(?=foo)",
	L"",
	L"foo",
	PERL_MATCH_YES,

	L"(?=foo)",
	L"",
	L"XfooY",
	PERL_MATCH_YES,

	L".*(?=foo)",
	L"",
	L"XfooY",
	PERL_MATCH_YES,

	L"(?<=foo)",
	L"",
	L"foo",
	PERL_MATCH_YES,

	L"(?<=foo)",
	L"",
	L"XfooY",
	PERL_MATCH_YES,

	L".*(?<=foo)",
	L"",
	L"foo",
	PERL_MATCH_YES,

	L".*(?<=foo)",
	L"",
	L"XfooY",
	PERL_MATCH_YES,

	L"(?<=foo)Y",
	L"",
	L"XfooY",
	PERL_MATCH_YES,

	L"o(?<=foo)Y",
	L"",
	L"..XfooY..",
	PERL_MATCH_YES,

	L"X(?=foo)f",
	L"",
	L"..XfooY..",
	PERL_MATCH_YES,

	L"X(?=foo)",
	L"",
	L"..XfooY..",
	PERL_MATCH_YES,

	L"X(?<=foo.)[YZ]",
	L"",
	L"..XfooXY..",
	PERL_MATCH_YES,

	L"(?=XY*foo)",
	L"",
	L"Xfoo",
	PERL_MATCH_YES,

	L"^(?=XY*foo)",
	L"",
	L"Xfoo",
	PERL_MATCH_YES,

	L"^(??{\"a+\"})a",
	L"",
	L"aa",
	PERL_MATCH_YES,

	L"^(?:(??{\"a+\"})|b)a",
	L"",
	L"aa",
	PERL_MATCH_YES,

	L"^(??{chr 0x100}).$",
	L"",
	L"\x100\x100",
	PERL_MATCH_YES,

	L"^(??{q(\\x{100})}).",
	L"",
	L"\x100\x100",
	PERL_MATCH_YES,

	L"^(??{q(.+)})\\x{100}",
	L"",
	L"\x100\x100",
	PERL_MATCH_YES,

	L"^(??{q(.)})\\x{100}",
	L"",
	L"\x100\x100",
	PERL_MATCH_YES,

	L"^(??{chr 0x100})\\xbb",
	L"",
	L"\x100\xbb",
	PERL_MATCH_YES,

	L"^(.)(??{\"(.)(.)\"})(.)$",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"^(.)(??{\"(bz+|.)(.)\"})(.)$",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"^(.)((??{\"(.)(cz+)\"})|.)",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"^a(?>(??{q(b)}))(??{q(c)})d",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"^x(??{\"\"})+$",
	L"",
	L"x",
	PERL_MATCH_YES,

	L"^(<(?:[^<>]+|(?3)|(?1))*>)()(!>!>!>)$",
	L"",
	L"<<!>!>!>><>>!>!>!>",
	PERL_MATCH_YES,

	L"^(<(?:[^<>]+|(?1))*>)$",
	L"",
	L"<<><<<><>>>>",
	PERL_MATCH_YES,

	L"((?2)*)([fF]o+)",
	L"",
	L"fooFoFoo",
	PERL_MATCH_YES,

	L"(<(?:[^<>]+|(?R))*>)",
	L"",
	L"<<><<<><>>>>",
	PERL_MATCH_YES,

	L"(?<n>foo|bar|baz)",
	L"",
	L"snofooewa",
	PERL_MATCH_YES,

	L"(?<n>foo|bar|baz)",
	L"",
	L"snofooewa",
	PERL_MATCH_YES,

	L"(?<n>foo|bar|baz)(?<m>[ew]+)",
	L"",
	L"snofooewa",
	PERL_MATCH_YES,

	L"(?<n>foo|bar|baz)(?<m>[ew]+)",
	L"",
	L"snofooewa",
	PERL_MATCH_YES,

	L"(?<n>foo)|(?<n>bar)|(?<n>baz)",
	L"",
	L"snofooewa",
	PERL_MATCH_YES,

	L"(?<n>foo)(??{ $+{n} })",
	L"",
	L"snofooefoofoowaa",
	PERL_MATCH_YES,

	L"(?P<n>foo|bar|baz)",
	L"",
	L"snofooewa",
	PERL_MATCH_YES,

	L"(?P<n>foo|bar|baz)",
	L"",
	L"snofooewa",
	PERL_MATCH_YES,

	L"(?P<n>foo|bar|baz)(?P<m>[ew]+)",
	L"",
	L"snofooewa",
	PERL_MATCH_YES,

	L"(?P<n>foo|bar|baz)(?P<m>[ew]+)",
	L"",
	L"snofooewa",
	PERL_MATCH_YES,

	L"(?P<n>foo)|(?P<n>bar)|(?P<n>baz)",
	L"",
	L"snofooewa",
	PERL_MATCH_YES,

	L"(?P<n>foo)(??{ $+{n} })",
	L"",
	L"snofooefoofoowaa",
	PERL_MATCH_YES,

	L"(?P<=n>foo|bar|baz)",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(?P<!n>foo|bar|baz)",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(?PX<n>foo|bar|baz)",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(?'n'foo|bar|baz)",
	L"",
	L"snofooewa",
	PERL_MATCH_YES,

	L"(?'n'foo|bar|baz)",
	L"",
	L"snofooewa",
	PERL_MATCH_YES,

	L"(?'n'foo|bar|baz)(?'m'[ew]+)",
	L"",
	L"snofooewa",
	PERL_MATCH_YES,

	L"(?'n'foo|bar|baz)(?'m'[ew]+)",
	L"",
	L"snofooewa",
	PERL_MATCH_YES,

	L"(?'n'foo)|(?'n'bar)|(?<n>baz)",
	L"",
	L"snobazewa",
	PERL_MATCH_YES,

	L"(?'n'foo)(??{ $+{n} })",
	L"",
	L"snofooefoofoowaa",
	PERL_MATCH_YES,

	L"(?'n'foo)\\k<n>",
	L"",
	L"..foofoo..",
	PERL_MATCH_YES,

	L"(?'n'foo)\\k<n>",
	L"",
	L"..foofoo..",
	PERL_MATCH_YES,

	L"(?<n>foo)\\k'n'",
	L"",
	L"..foofoo..",
	PERL_MATCH_YES,

	L"(?<n>foo)\\k'n'",
	L"",
	L"..foofoo..",
	PERL_MATCH_YES,

	L"(?:(?<n>foo)|(?<n>bar))\\k<n>",
	L"",
	L"..barbar..",
	PERL_MATCH_YES,

	L"^(?'main'<(?:[^<>]+|(?&crap)|(?&main))*>)(?'empty')(?'crap'!>!>!>)$",
	L"",
	L"<<!>!>!>><>>!>!>!>",
	PERL_MATCH_YES,

	L"^(?'main'<(?:[^<>]+|(?&main))*>)$",
	L"",
	L"<<><<<><>>>>",
	PERL_MATCH_YES,

	L"(?'first'(?&second)*)(?'second'[fF]o+)",
	L"",
	L"fooFoFoo",
	PERL_MATCH_YES,

	L"(?<A>foo)?(?(<A>)bar|nada)",
	L"",
	L"foobar",
	PERL_MATCH_YES,

	L"(?<A>foo)?(?(<A>)bar|nada)",
	L"",
	L"foo-barnada",
	PERL_MATCH_YES,

	L"(?<A>foo)?(?(1)bar|nada)",
	L"",
	L"foo-barnada",
	PERL_MATCH_YES,

	L"(?<A>foo(?(R)bar))?(?1)",
	L"",
	L"foofoobar",
	PERL_MATCH_YES,

	L"(?<A>foo(?(R)bar))?(?1)",
	L"",
	L"foofoobar",
	PERL_MATCH_YES,

	L"(x)(?<A>foo(?(R&A)bar))?(?&A)",
	L"",
	L"xfoofoobar",
	PERL_MATCH_YES,

	L"(x)(?<A>foo(?(R&A)bar))?(?&A)",
	L"",
	L"xfoofoobar",
	PERL_MATCH_YES,

	L"(x)(?<A>foo(?(R2)bar))?(?&A)",
	L"",
	L"xfoofoobar",
	PERL_MATCH_YES,

	L"(x)(?<A>foo(?(R2)bar))?(?&A)",
	L"",
	L"xfoofoobar",
	PERL_MATCH_YES,

	L"(?1)(?(DEFINE)(blah))",
	L"",
	L"blah",
	PERL_MATCH_YES,

	L"^(?<PAL>(?<CHAR>.)((?&PAL)|.?)\\k<CHAR>)$",
	L"",
	L"madamimadam",
	PERL_MATCH_YES,

	L"^(?<PAL>(?<CHAR>.)((?&PAL)|.?)\\k<CHAR>)$",
	L"",
	L"madamiamadam",
	PERL_MATCH_NO,

	L"(a)?((?1))(fox)",
	L"",
	L"aafox",
	PERL_MATCH_YES,

	L"(a)*((?1))(fox)",
	L"",
	L"aafox",
	PERL_MATCH_YES,

	L"(a)+((?1))(fox)",
	L"",
	L"aafox",
	PERL_MATCH_YES,

	L"(a){1,100}((?1))(fox)",
	L"",
	L"aafox",
	PERL_MATCH_YES,

	L"(a){0,100}((?1))(fox)",
	L"",
	L"aafox",
	PERL_MATCH_YES,

	L"(ab)?((?1))(fox)",
	L"",
	L"ababfox",
	PERL_MATCH_YES,

	L"(ab)*((?1))(fox)",
	L"",
	L"ababfox",
	PERL_MATCH_YES,

	L"(ab)+((?1))(fox)",
	L"",
	L"ababfox",
	PERL_MATCH_YES,

	L"(ab){1,100}((?1))(fox)",
	L"",
	L"ababfox",
	PERL_MATCH_YES,

	L"(ab){0,100}((?1))(fox)",
	L"",
	L"ababfox",
	PERL_MATCH_YES,

	L"a++a",
	L"",
	L"aaaaa",
	PERL_MATCH_NO,

	L"a*+a",
	L"",
	L"aaaaa",
	PERL_MATCH_NO,

	L"a{1,5}+a",
	L"",
	L"aaaaa",
	PERL_MATCH_NO,

	L"a?+a",
	L"",
	L"ab",
	PERL_MATCH_NO,

	L"a++b",
	L"",
	L"aaaaab",
	PERL_MATCH_YES,

	L"a*+b",
	L"",
	L"aaaaab",
	PERL_MATCH_YES,

	L"a{1,5}+b",
	L"",
	L"aaaaab",
	PERL_MATCH_YES,

	L"a?+b",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"fooa++a",
	L"",
	L"fooaaaaa",
	PERL_MATCH_NO,

	L"fooa*+a",
	L"",
	L"fooaaaaa",
	PERL_MATCH_NO,

	L"fooa{1,5}+a",
	L"",
	L"fooaaaaa",
	PERL_MATCH_NO,

	L"fooa?+a",
	L"",
	L"fooab",
	PERL_MATCH_NO,

	L"fooa++b",
	L"",
	L"fooaaaaab",
	PERL_MATCH_YES,

	L"fooa*+b",
	L"",
	L"fooaaaaab",
	PERL_MATCH_YES,

	L"fooa{1,5}+b",
	L"",
	L"fooaaaaab",
	PERL_MATCH_YES,

	L"fooa?+b",
	L"",
	L"fooab",
	PERL_MATCH_YES,

	L"(?:aA)++(?:aA)",
	L"",
	L"aAaAaAaAaA",
	PERL_MATCH_NO,

	L"(aA)++(aA)",
	L"",
	L"aAaAaAaAaA",
	PERL_MATCH_NO,

	L"(aA|bB)++(aA|bB)",
	L"",
	L"aAaAbBaAbB",
	PERL_MATCH_NO,

	L"(?:aA|bB)++(?:aA|bB)",
	L"",
	L"aAbBbBbBaA",
	PERL_MATCH_NO,

	L"(?:aA)*+(?:aA)",
	L"",
	L"aAaAaAaAaA",
	PERL_MATCH_NO,

	L"(aA)*+(aA)",
	L"",
	L"aAaAaAaAaA",
	PERL_MATCH_NO,

	L"(aA|bB)*+(aA|bB)",
	L"",
	L"aAaAbBaAaA",
	PERL_MATCH_NO,

	L"(?:aA|bB)*+(?:aA|bB)",
	L"",
	L"aAaAaAbBaA",
	PERL_MATCH_NO,

	L"(?:aA){1,5}+(?:aA)",
	L"",
	L"aAaAaAaAaA",
	PERL_MATCH_NO,

	L"(aA){1,5}+(aA)",
	L"",
	L"aAaAaAaAaA",
	PERL_MATCH_NO,

	L"(aA|bB){1,5}+(aA|bB)",
	L"",
	L"aAaAbBaAaA",
	PERL_MATCH_NO,

	L"(?:aA|bB){1,5}+(?:aA|bB)",
	L"",
	L"bBbBbBbBbB",
	PERL_MATCH_NO,

	L"(?:aA)?+(?:aA)",
	L"",
	L"aAb",
	PERL_MATCH_NO,

	L"(aA)?+(aA)",
	L"",
	L"aAb",
	PERL_MATCH_NO,

	L"(aA|bB)?+(aA|bB)",
	L"",
	L"bBb",
	PERL_MATCH_NO,

	L"(?:aA|bB)?+(?:aA|bB)",
	L"",
	L"aAb",
	PERL_MATCH_NO,

	L"(?:aA)++b",
	L"",
	L"aAaAaAaAaAb",
	PERL_MATCH_YES,

	L"(aA)++b",
	L"",
	L"aAaAaAaAaAb",
	PERL_MATCH_YES,

	L"(aA|bB)++b",
	L"",
	L"aAbBaAaAbBb",
	PERL_MATCH_YES,

	L"(?:aA|bB)++b",
	L"",
	L"aAbBbBaAaAb",
	PERL_MATCH_YES,

	L"(?:aA)*+b",
	L"",
	L"aAaAaAaAaAb",
	PERL_MATCH_YES,

	L"(aA)*+b",
	L"",
	L"aAaAaAaAaAb",
	PERL_MATCH_YES,

	L"(aA|bB)*+b",
	L"",
	L"bBbBbBbBbBb",
	PERL_MATCH_YES,

	L"(?:aA|bB)*+b",
	L"",
	L"bBaAbBbBaAb",
	PERL_MATCH_YES,

	L"(?:aA){1,5}+b",
	L"",
	L"aAaAaAaAaAb",
	PERL_MATCH_YES,

	L"(aA){1,5}+b",
	L"",
	L"aAaAaAaAaAb",
	PERL_MATCH_YES,

	L"(aA|bB){1,5}+b",
	L"",
	L"bBaAbBaAbBb",
	PERL_MATCH_YES,

	L"(?:aA|bB){1,5}+b",
	L"",
	L"aAbBaAbBbBb",
	PERL_MATCH_YES,

	L"(?:aA)?+b",
	L"",
	L"aAb",
	PERL_MATCH_YES,

	L"(aA)?+b",
	L"",
	L"aAb",
	PERL_MATCH_YES,

	L"(aA|bB)?+b",
	L"",
	L"bBb",
	PERL_MATCH_YES,

	L"(?:aA|bB)?+b",
	L"",
	L"bBb",
	PERL_MATCH_YES,

	L"foo(?:aA)++(?:aA)",
	L"",
	L"fooaAaAaAaAaA",
	PERL_MATCH_NO,

	L"foo(aA)++(aA)",
	L"",
	L"fooaAaAaAaAaA",
	PERL_MATCH_NO,

	L"foo(aA|bB)++(aA|bB)",
	L"",
	L"foobBbBbBaAaA",
	PERL_MATCH_NO,

	L"foo(?:aA|bB)++(?:aA|bB)",
	L"",
	L"fooaAaAaAaAaA",
	PERL_MATCH_NO,

	L"foo(?:aA)*+(?:aA)",
	L"",
	L"fooaAaAaAaAaA",
	PERL_MATCH_NO,

	L"foo(aA)*+(aA)",
	L"",
	L"fooaAaAaAaAaA",
	PERL_MATCH_NO,

	L"foo(aA|bB)*+(aA|bB)",
	L"",
	L"foobBaAbBaAaA",
	PERL_MATCH_NO,

	L"foo(?:aA|bB)*+(?:aA|bB)",
	L"",
	L"fooaAaAbBbBaA",
	PERL_MATCH_NO,

	L"foo(?:aA){1,5}+(?:aA)",
	L"",
	L"fooaAaAaAaAaA",
	PERL_MATCH_NO,

	L"foo(aA){1,5}+(aA)",
	L"",
	L"fooaAaAaAaAaA",
	PERL_MATCH_NO,

	L"foo(aA|bB){1,5}+(aA|bB)",
	L"",
	L"fooaAbBbBaAaA",
	PERL_MATCH_NO,

	L"foo(?:aA|bB){1,5}+(?:aA|bB)",
	L"",
	L"fooaAbBbBaAbB",
	PERL_MATCH_NO,

	L"foo(?:aA)?+(?:aA)",
	L"",
	L"fooaAb",
	PERL_MATCH_NO,

	L"foo(aA)?+(aA)",
	L"",
	L"fooaAb",
	PERL_MATCH_NO,

	L"foo(aA|bB)?+(aA|bB)",
	L"",
	L"foobBb",
	PERL_MATCH_NO,

	L"foo(?:aA|bB)?+(?:aA|bB)",
	L"",
	L"fooaAb",
	PERL_MATCH_NO,

	L"foo(?:aA)++b",
	L"",
	L"fooaAaAaAaAaAb",
	PERL_MATCH_YES,

	L"foo(aA)++b",
	L"",
	L"fooaAaAaAaAaAb",
	PERL_MATCH_YES,

	L"foo(aA|bB)++b",
	L"",
	L"foobBaAbBaAbBb",
	PERL_MATCH_YES,

	L"foo(?:aA|bB)++b",
	L"",
	L"fooaAaAbBaAaAb",
	PERL_MATCH_YES,

	L"foo(?:aA)*+b",
	L"",
	L"fooaAaAaAaAaAb",
	PERL_MATCH_YES,

	L"foo(aA)*+b",
	L"",
	L"fooaAaAaAaAaAb",
	PERL_MATCH_YES,

	L"foo(aA|bB)*+b",
	L"",
	L"foobBbBaAaAaAb",
	PERL_MATCH_YES,

	L"foo(?:aA|bB)*+b",
	L"",
	L"foobBaAaAbBaAb",
	PERL_MATCH_YES,

	L"foo(?:aA){1,5}+b",
	L"",
	L"fooaAaAaAaAaAb",
	PERL_MATCH_YES,

	L"foo(aA){1,5}+b",
	L"",
	L"fooaAaAaAaAaAb",
	PERL_MATCH_YES,

	L"foo(aA|bB){1,5}+b",
	L"",
	L"foobBaAaAaAaAb",
	PERL_MATCH_YES,

	L"foo(?:aA|bB){1,5}+b",
	L"",
	L"fooaAbBaAbBbBb",
	PERL_MATCH_YES,

	L"foo(?:aA)?+b",
	L"",
	L"fooaAb",
	PERL_MATCH_YES,

	L"foo(aA)?+b",
	L"",
	L"fooaAb",
	PERL_MATCH_YES,

	L"foo(aA|bB)?+b",
	L"",
	L"foobBb",
	PERL_MATCH_YES,

	L"foo(?:aA|bB)?+b",
	L"",
	L"foobBb",
	PERL_MATCH_YES,

	L"([^()]++|\\([^()]*\\))+",
	L"",
	L"((abc(ade)ufh()()x",
	PERL_MATCH_YES,

	L"round\\(([^()]++)\\)",
	L"",
	L"_I(round(xs * sz),1)",
	PERL_MATCH_YES,

	L"(foo[1x]|bar[2x]|baz[3x])+y",
	L"",
	L"foo1bar2baz3y",
	PERL_MATCH_YES,

	L"(foo[1x]|bar[2x]|baz[3x])+y",
	L"",
	L"foo1bar2baz3y",
	PERL_MATCH_YES,

	L"(foo[1x]|bar[2x]|baz[3x])*y",
	L"",
	L"foo1bar2baz3y",
	PERL_MATCH_YES,

	L"(foo[1x]|bar[2x]|baz[3x])*y",
	L"",
	L"foo1bar2baz3y",
	PERL_MATCH_YES,

	L"([yX].|WORDS|[yX].|WORD)S",
	L"",
	L"WORDS",
	PERL_MATCH_YES,

	L"(WORDS|WORLD|WORD)S",
	L"",
	L"WORDS",
	PERL_MATCH_YES,

	L"([yX].|WORDS|WORD|[xY].)S",
	L"",
	L"WORDS",
	PERL_MATCH_YES,

	L"(foo|fool|[zx].|money|parted)$",
	L"",
	L"fool",
	PERL_MATCH_YES,

	L"([zx].|foo|fool|[zq].|money|parted|[yx].)$",
	L"",
	L"fool",
	PERL_MATCH_YES,

	L"(foo|fool|[zx].|money|parted)$",
	L"",
	L"fools",
	PERL_MATCH_NO,

	L"([zx].|foo|fool|[qx].|money|parted|[py].)$",
	L"",
	L"fools",
	PERL_MATCH_NO,

	L"([yX].|WORDS|[yX].|WORD)+S",
	L"",
	L"WORDS",
	PERL_MATCH_YES,

	L"(WORDS|WORLD|WORD)+S",
	L"",
	L"WORDS",
	PERL_MATCH_YES,

	L"([yX].|WORDS|WORD|[xY].)+S",
	L"",
	L"WORDS",
	PERL_MATCH_YES,

	L"(foo|fool|[zx].|money|parted)+$",
	L"",
	L"fool",
	PERL_MATCH_YES,

	L"([zx].|foo|fool|[zq].|money|parted|[yx].)+$",
	L"",
	L"fool",
	PERL_MATCH_YES,

	L"(foo|fool|[zx].|money|parted)+$",
	L"",
	L"fools",
	PERL_MATCH_NO,

	L"([zx].|foo|fool|[qx].|money|parted|[py].)+$",
	L"",
	L"fools",
	PERL_MATCH_NO,

	L"(x|y|z[QW])+(longish|loquatious|excessive|overblown[QW])+",
	L"",
	L"xyzQzWlongishoverblownW",
	PERL_MATCH_YES,

	L"(x|y|z[QW])*(longish|loquatious|excessive|overblown[QW])*",
	L"",
	L"xyzQzWlongishoverblownW",
	PERL_MATCH_YES,

	L"(x|y|z[QW]){1,5}(longish|loquatious|excessive|overblown[QW]){1,5}",
	L"",
	L"xyzQzWlongishoverblownW",
	PERL_MATCH_YES,

	L"(x|y|z[QW])++(longish|loquatious|excessive|overblown[QW])++",
	L"",
	L"xyzQzWlongishoverblownW",
	PERL_MATCH_YES,

	L"(x|y|z[QW])*+(longish|loquatious|excessive|overblown[QW])*+",
	L"",
	L"xyzQzWlongishoverblownW",
	PERL_MATCH_YES,

	L"(x|y|z[QW]){1,5}+(longish|loquatious|excessive|overblown[QW]){1,5}+",
	L"",
	L"xyzQzWlongishoverblownW",
	PERL_MATCH_YES,

	L"a*(?!)",
	L"",
	L"aaaab",
	PERL_MATCH_NO,

	L"a*(*FAIL)",
	L"",
	L"aaaab",
	PERL_MATCH_NO,

	L"a*(*F)",
	L"",
	L"aaaab",
	PERL_MATCH_NO,

	L"(A(A|B(*ACCEPT)|C)D)(E)",
	L"",
	L"AB",
	PERL_MATCH_YES,

	L"(A(A|B(*ACCEPT)|C)D)(E)",
	L"",
	L"ACDE",
	PERL_MATCH_YES,

	L"(a)(?:(?-1)|(?+1))(b)",
	L"",
	L"aab",
	PERL_MATCH_YES,

	L"(a)(?:(?-1)|(?+1))(b)",
	L"",
	L"abb",
	PERL_MATCH_YES,

	L"(a)(?:(?-1)|(?+1))(b)",
	L"",
	L"acb",
	PERL_MATCH_NO,

	L"(foo)(\\g-2)",
	L"",
	L"foofoo",
	PERL_MATCH_YES,

	L"(foo)(\\g-2)(foo)(\\g-2)",
	L"",
	L"foofoofoofoo",
	PERL_MATCH_YES,

	L"(([abc]+) \\g-1)(([abc]+) \\g{-1})",
	L"",
	L"abc abccba cba",
	PERL_MATCH_YES,

	L"(a)(b)(c)\\g1\\g2\\g3",
	L"",
	L"abcabc",
	PERL_MATCH_YES,

	L"(?'n'foo) \\k<n>",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?'n'foo) \\k<n>",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?<n>foo) \\k'n'",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?<n>foo) \\k'n'",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?'a1'foo) \\k'a1'",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?<a1>foo) \\k<a1>",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?'_'foo) \\k'_'",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?<_>foo) \\k<_>",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?'_0_'foo) \\k'_0_'",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?<_0_>foo) \\k<_0_>",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?'0'foo) bar",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(?<0>foo) bar",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(?'12'foo) bar",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(?<12>foo) bar",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(?'1a'foo) bar",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(?<1a>foo) bar",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(?''foo) bar",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(?<>foo) bar",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k'n'",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k<n>",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k'a1'",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k<a1>",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k'_'",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k<_>",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k'_0_'",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k<_0_>",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k'0'",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k<0>",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k'12'",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k<12>",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k'1a'",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k<1a>",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k''",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"foo \\k<>",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"(?<as>as) (\\w+) \\k<as> (\\w+)",
	L"",
	L"as easy as pie",
	PERL_MATCH_YES,

	L"(?'n'foo) \\g{n}",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?'n'foo) \\g{n}",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?<n>foo) \\g{n}",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?<n>foo) \\g{n}",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?<as>as) (\\w+) \\g{as} (\\w+)",
	L"",
	L"as easy as pie",
	PERL_MATCH_YES,

	L"(?P<n>foo)(?P=n)",
	L"",
	L"..foofoo..",
	PERL_MATCH_YES,

	L"(?P<n>foo)(?P=n)",
	L"",
	L"..foofoo..",
	PERL_MATCH_YES,

	L"(?:(?P<n>foo)|(?P<n>bar))(?P=n)",
	L"",
	L"..barbar..",
	PERL_MATCH_YES,

	L"^(?P<PAL>(?P<CHAR>.)((?P>PAL)|.?)(?P=CHAR))$",
	L"",
	L"madamimadam",
	PERL_MATCH_YES,

	L"^(?P<PAL>(?P<CHAR>.)((?P>PAL)|.?)(?P=CHAR))$",
	L"",
	L"madamiamadam",
	PERL_MATCH_NO,

	L"(?P<n>foo) (?P=n)",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?P<n>foo) (?P=n)",
	L"",
	L"..foo foo..",
	PERL_MATCH_YES,

	L"(?P<as>as) (\\w+) (?P=as) (\\w+)",
	L"",
	L"as easy as pie",
	PERL_MATCH_YES,

	L"(?<=bar>)foo",
	L"",
	L"bar>foo",
	PERL_MATCH_YES,

	L"(?<!bar>)foo",
	L"",
	L"bar>foo",
	PERL_MATCH_NO,

	L"(?<=bar>ABC)foo",
	L"",
	L"bar>ABCfoo",
	PERL_MATCH_YES,

	L"(?<!bar>ABC)foo",
	L"",
	L"bar>ABCfoo",
	PERL_MATCH_NO,

	L"(?<bar>)foo",
	L"",
	L"bar>ABCfoo",
	PERL_MATCH_YES,

	L"(?<bar>ABC)foo",
	L"",
	L"bar>ABCfoo",
	PERL_MATCH_YES,

	L"(?<=abcd(?<=(aaaabcd)))",
	L"",
	L"..aaaabcd..",
	PERL_MATCH_YES,

	L"(?=xy(?<=(aaxy)))",
	L"",
	L"..aaxy..",
	PERL_MATCH_YES,

	L"X(\\w+)(?=\\s)|X(\\w+)",
	L"",
	L"Xab",
	PERL_MATCH_YES,

	L"(?|(a))",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"(?|a(.)b|d(.(o).)d|i(.)(.)j)(.)",
	L"",
	L"d!o!da",
	PERL_MATCH_YES,

	L"(?|a(.)b|d(.(o).)d|i(.)(.)j)(.)",
	L"",
	L"aabc",
	PERL_MATCH_YES,

	L"(?|a(.)b|d(.(o).)d|i(.)(.)j)(.)",
	L"",
	L"ixyjp",
	PERL_MATCH_YES,

	L"(?|(?|(a)|(b))|(?|(c)|(d)))",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"(?|(?|(a)|(b))|(?|(c)|(d)))",
	L"",
	L"b",
	PERL_MATCH_YES,

	L"(?|(?|(a)|(b))|(?|(c)|(d)))",
	L"",
	L"c",
	PERL_MATCH_YES,

	L"(?|(?|(a)|(b))|(?|(c)|(d)))",
	L"",
	L"d",
	PERL_MATCH_YES,

	L"(.)(?|(.)(.)x|(.)d)(.)",
	L"",
	L"abcde",
	PERL_MATCH_YES,

	L"(\\N)(?|(\\N)(\\N)x|(\\N)d)(\\N)",
	L"",
	L"abcde",
	PERL_MATCH_YES,

	L"(?|(?<foo>x))",
	L"",
	L"x",
	PERL_MATCH_YES,

	L"(?|(?<foo>x)|(?<bar>y))",
	L"",
	L"x",
	PERL_MATCH_YES,

	L"(?|(?<bar>y)|(?<foo>x))",
	L"",
	L"x",
	PERL_MATCH_YES,

	L"(?<bar>)(?|(?<foo>x))",
	L"",
	L"x",
	PERL_MATCH_YES,

	L"(?|(b)|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()(a))",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"(?(DEFINE)(?<A>(?&B)+)(?<B>a))(?&A)",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"(?(DEFINE)(?<A>(?&B)+)(?<B>a))(?&A)",
	L"",
	L"aa",
	PERL_MATCH_YES,

	L"\\x{100}?(??{\"\"})xxx",
	L"",
	L"xxx",
	PERL_MATCH_YES,

	L"foo(\\R)bar",
	L"",
	L"foo\r\nbar",
	PERL_MATCH_YES,

	L"foo(\\R)bar",
	L"",
	L"foo\nbar",
	PERL_MATCH_YES,

	L"foo(\\R)bar",
	L"",
	L"foo\rbar",
	PERL_MATCH_YES,

	L"foo(\\R+)bar",
	L"",
	L"foo\r\n\x85\r\n\nbar",
	PERL_MATCH_YES,

	L"(\\V+)(\\R)",
	L"",
	L"foo\r\n\x85\r\n\nbar",
	PERL_MATCH_YES,

	L"(\\R+)(\\V)",
	L"",
	L"foo\r\n\x85\r\n\nbar",
	PERL_MATCH_YES,

	L"foo(\\R)bar",
	L"",
	L"foo\x85bar",
	PERL_MATCH_YES,

	L"(\\V)(\\R)",
	L"",
	L"foo\x85bar",
	PERL_MATCH_YES,

	L"(\\R)(\\V)",
	L"",
	L"foo\x85bar",
	PERL_MATCH_YES,

	L"foo(\\R)bar",
	L"",
	L"foo\r\nbar",
	PERL_MATCH_YES,

	L"(\\V)(\\R)",
	L"",
	L"foo\r\nbar",
	PERL_MATCH_YES,

	L"(\\R)(\\V)",
	L"",
	L"foo\r\nbar",
	PERL_MATCH_YES,

	L"foo(\\R)bar",
	L"",
	L"foo\r\nbar",
	PERL_MATCH_YES,

	L"(\\V)(\\R)",
	L"",
	L"foo\r\nbar",
	PERL_MATCH_YES,

	L"(\\R)(\\V)",
	L"",
	L"foo\r\nbar",
	PERL_MATCH_YES,

	L"foo(\\R)bar",
	L"",
	L"foo\rbar",
	PERL_MATCH_YES,

	L"(\\V)(\\R)",
	L"",
	L"foo\rbar",
	PERL_MATCH_YES,

	L"(\\R)(\\V)",
	L"",
	L"foo\rbar",
	PERL_MATCH_YES,

	L"foo(\\v+)bar",
	L"",
	L"foo\r\n\x85\r\n\nbar",
	PERL_MATCH_YES,

	L"(\\V+)(\\v)",
	L"",
	L"foo\r\n\x85\r\n\nbar",
	PERL_MATCH_YES,

	L"(\\v+)(\\V)",
	L"",
	L"foo\r\n\x85\r\n\nbar",
	PERL_MATCH_YES,

	L"foo(\\v)bar",
	L"",
	L"foo\x85bar",
	PERL_MATCH_YES,

	L"(\\V)(\\v)",
	L"",
	L"foo\x85bar",
	PERL_MATCH_YES,

	L"(\\v)(\\V)",
	L"",
	L"foo\x85bar",
	PERL_MATCH_YES,

	L"foo(\\v)bar",
	L"",
	L"foo\rbar",
	PERL_MATCH_YES,

	L"(\\V)(\\v)",
	L"",
	L"foo\rbar",
	PERL_MATCH_YES,

	L"(\\v)(\\V)",
	L"",
	L"foo\rbar",
	PERL_MATCH_YES,

	L"foo(\\h+)bar",
	L"",
	L"foo\t\xA0bar",
	PERL_MATCH_YES,

	L"(\\H+)(\\h)",
	L"",
	L"foo\t\xA0bar",
	PERL_MATCH_YES,

	L"(\\h+)(\\H)",
	L"",
	L"foo\t\xA0bar",
	PERL_MATCH_YES,

	L"foo(\\h)bar",
	L"",
	L"foo\xA0bar",
	PERL_MATCH_YES,

	L"(\\H)(\\h)",
	L"",
	L"foo\xA0bar",
	PERL_MATCH_YES,

	L"(\\h)(\\H)",
	L"",
	L"foo\xA0bar",
	PERL_MATCH_YES,

	L"foo(\\h)bar",
	L"",
	L"foo\tbar",
	PERL_MATCH_YES,

	L"(\\H)(\\h)",
	L"",
	L"foo\tbar",
	PERL_MATCH_YES,

	L"(\\h)(\\H)",
	L"",
	L"foo\tbar",
	PERL_MATCH_YES,

	L".*\\z",
	L"",
	L"foo\n",
	PERL_MATCH_YES,

	L"\\N*\\z",
	L"",
	L"foo\n",
	PERL_MATCH_YES,

	L".*\\Z",
	L"",
	L"foo\n",
	PERL_MATCH_YES,

	L"\\N*\\Z",
	L"",
	L"foo\n",
	PERL_MATCH_YES,

	L"^(?:(\\d)x)?\\d$",
	L"",
	L"1",
	PERL_MATCH_YES,

	L".*?(?:(\\w)|(\\w))x",
	L"",
	L"abx",
	PERL_MATCH_YES,

	L"0{50}",
	L"",
	L"000000000000000000000000000000000000000000000000000",
	PERL_MATCH_YES,

	L"^a?(?=b)b",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L"^a*(?=b)b",
	L"",
	L"ab",
	PERL_MATCH_YES,

	L">\\d+$ \\n",
	L"ix",
	L">10\n",
	PERL_MATCH_YES,

	L">\\d+$ \\n",
	L"ix",
	L">1\n",
	PERL_MATCH_YES,

	L"\\d+$ \\n",
	L"ix",
	L">10\n",
	PERL_MATCH_YES,

	L">\\d\\d$ \\n",
	L"ix",
	L">10\n",
	PERL_MATCH_YES,

	L">\\d+$ \\n",
	L"x",
	L">10\n",
	PERL_MATCH_YES,

	L"^\\s*i.*?o\\s*$",
	L"s",
	L"io\n io",
	PERL_MATCH_YES,

	L"(.*?)a(?!(a+)b\\2c)",
	L"",
	L"baaabaac",
	PERL_MATCH_YES,

	L"\\A(?(?=db2)db2|\\D+)(?<!processed)\\.csv\\z",
	L"xms",
	L"sql_processed.csv",
	PERL_MATCH_NO,

	L"\\N{U+0100}",
	L"",
	L"\x100",
	PERL_MATCH_YES,

	L"[a\\N{U+0100}]",
	L"",
	L"\x100",
	PERL_MATCH_YES,

	L"[a\\N{U+0100}]",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"\\N{U+41}\\x{c1}",
	L"i",
	L"a\xe1",
	PERL_MATCH_YES,

	L"[\\N{U+41}\\x{c1}]",
	L"i",
	L"\xe1",
	PERL_MATCH_YES,

	L"[\\s][\\S]",
	L"",
	L"\xa0\xa0",
	PERL_MATCH_NO,

	L"[\\x{100}\\xff]",
	L"i",
	L"\xff",
	PERL_MATCH_YES,

	L"((??{ \"(?:|)\" }))\\s",
	L"",
	L"C\x20 ",
	PERL_MATCH_YES,

	L"abc\\N\\{U+BEEF}",
	L"",
	L"abc\n{UBEEF}",
	PERL_MATCH_NO,

	L"abc\\N\\{U+BEEF}",
	L"",
	L"abc.{UBEEF}",
	PERL_MATCH_YES,

	L"[abc\\N\\{U+BEEF}]",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"abc\\N",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"abc\\N",
	L"",
	L"abc\n",
	PERL_MATCH_NO,

	L"\\N{U+}",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"[\\N{U+}]",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"[\\N{U+}]",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"abc\\N{def",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\N{U+4AG3}",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"[\\N{U+4AG3}]",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\N{U+}",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"[\\N{U+}]",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\N{U+4AG3}",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"[\\N{U+4AG3}]",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"abc\\N{def",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"abc\\N {U+41}",
	L"x",
	L"-",
	PERL_MATCH_ERROR,

	L"abc\\N {SPACE}",
	L"x",
	L"-",
	PERL_MATCH_ERROR,

	L"\\N{U+0xBEEF}",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\N{U+BEEF.BEAD}",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\N{U+0xBEEF}",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\c`",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\c1",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"\\cA",
	L"",
	L"\001",
	PERL_MATCH_YES,

	L"\\400",
	L"",
	L"\x100",
	PERL_MATCH_YES,

	L"\\600",
	L"",
	L"\x180",
	PERL_MATCH_YES,

	L"\\777",
	L"",
	L"\x1FF",
	PERL_MATCH_YES,

	L"[a\\400]",
	L"",
	L"\x100",
	PERL_MATCH_YES,

	L"[b\\600]",
	L"",
	L"\x180",
	PERL_MATCH_YES,

	L"[c\\777]",
	L"",
	L"\x1FF",
	PERL_MATCH_YES,

	L"\\o{120}",
	L"",
	L"\x50",
	PERL_MATCH_YES,

	L"\\o{400}",
	L"",
	L"\x100",
	PERL_MATCH_YES,

	L"\\o{1000}",
	L"",
	L"\x200",
	PERL_MATCH_YES,

	L"[a\\o{120}]",
	L"",
	L"\x50",
	PERL_MATCH_YES,

	L"[a\\o{400}]",
	L"",
	L"\x100",
	PERL_MATCH_YES,

	L"[a\\o{1000}]",
	L"",
	L"\x200",
	PERL_MATCH_YES,

	L"\\87",
	L"",
	L"87",
	PERL_MATCH_YES,

	L"a\\87",
	L"",
	L"a87",
	PERL_MATCH_YES,

	L"a\\97",
	L"",
	L"a97",
	PERL_MATCH_YES,

	L"[\\8\\9]",
	L"",
	L"\000",
	PERL_MATCH_NO,

	L"[\\8\\9]",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"[\\8\\9]",
	L"",
	L"8",
	PERL_MATCH_YES,

	L"[\\8\\9]",
	L"",
	L"9",
	PERL_MATCH_YES,

	L"[\\0]",
	L"",
	L"\000",
	PERL_MATCH_YES,

	L"[\\0]",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"[\\07]",
	L"",
	L"\007",
	PERL_MATCH_YES,

	L"[\\07]",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"[\\07]",
	L"",
	L"7\000",
	PERL_MATCH_NO,

	L"[\\07]",
	L"",
	L"-",
	PERL_MATCH_ERROR,

	L"[\\006]",
	L"",
	L"\006",
	PERL_MATCH_YES,

	L"[\\006]",
	L"",
	L"6\000",
	PERL_MATCH_NO,

	L"[\\0005]",
	L"",
	L"\0005",
	PERL_MATCH_YES,

	L"[\\0005]",
	L"",
	L"5\000",
	PERL_MATCH_YES,

	L"[\\_]",
	L"",
	L"_",
	PERL_MATCH_YES,

	L"(q1|.)*(q2|.)*(x(a|bc)*y){2,}",
	L"",
	L"xayxay",
	PERL_MATCH_YES,

	L"(q1|.)*(q2|.)*(x(a|bc)*y){2,3}",
	L"",
	L"xayxay",
	PERL_MATCH_YES,

	L"(q1|z)*(q2|z)*z{15}-.*?(x(a|bc)*y){2,3}Z",
	L"",
	L"zzzzzzzzzzzzzzzz-xayxayxayxayZ",
	PERL_MATCH_YES,

	L"(?:(?:)foo|bar|zot|rt78356)",
	L"",
	L"foo",
	PERL_MATCH_YES,

	L"\\xe0\\pL",
	L"i",
	L"\xc0a",
	PERL_MATCH_YES,

	L"(?{})[\\x{100}]",
	L"",
	L"\x100",
	PERL_MATCH_YES,

	L"^m?(\\S)(.*)\\1$",
	L"",
	L"aba",
	PERL_MATCH_YES,

	L"^m?(\\S)(.*)\\1$",
	L"",
	L"\tb\t",
	PERL_MATCH_NO,

	L"^m?(\\s)(.*)\\1$",
	L"",
	L"\tb\t",
	PERL_MATCH_YES,

	L"^m?(\\s)(.*)\\1$",
	L"",
	L"aba",
	PERL_MATCH_NO,

	L"^m?(\\W)(.*)\\1$",
	L"",
	L":b:",
	PERL_MATCH_YES,

	L"^m?(\\W)(.*)\\1$",
	L"",
	L"aba",
	PERL_MATCH_NO,

	L"^m?(\\w)(.*)\\1$",
	L"",
	L"aba",
	PERL_MATCH_YES,

	L"^m?(\\w)(.*)\\1$",
	L"",
	L":b:",
	PERL_MATCH_NO,

	L"^m?(\\D)(.*)\\1$",
	L"",
	L"aba",
	PERL_MATCH_YES,

	L"^m?(\\D)(.*)\\1$",
	L"",
	L"5b5",
	PERL_MATCH_NO,

	L"^m?(\\d)(.*)\\1$",
	L"",
	L"5b5",
	PERL_MATCH_YES,

	L"^m?(\\d)(.*)\\1$",
	L"",
	L"aba",
	PERL_MATCH_NO,

	L"s",
	L"ai",
	L"\x17F",
	PERL_MATCH_YES,

	L"s",
	L"aia",
	L"\x17F",
	PERL_MATCH_NO,

	L"s",
	L"aia",
	L"S",
	PERL_MATCH_YES,

	L"(?aia:s)",
	L"",
	L"\x17F",
	PERL_MATCH_NO,

	L"(?aia:s)",
	L"",
	L"S",
	PERL_MATCH_YES,

	L"[^\\x{1E9E}]",
	L"i",
	L"\xDF",
	PERL_MATCH_NO,

	L"^.*\\d\\H",
	L"",
	L"X1",
	PERL_MATCH_NO,

	L"^.*\\d\\V",
	L"",
	L"X1",
	PERL_MATCH_NO,

	L"^\\p{L_}",
	L"",
	L"\x3400",
	PERL_MATCH_NO,

	L"^\\p{L}",
	L"",
	L"\x3400",
	PERL_MATCH_YES,

	L"[s\\xDF]a",
	L"ui",
	L"ssa",
	PERL_MATCH_YES,

	L"[s\\xDF]a",
	L"ui",
	L"sa",
	PERL_MATCH_YES,

	L"^\\R\\x0A$",
	L"",
	L"\x0D\x0A",
	PERL_MATCH_NO,

	L"ff",
	L"i",
	L"\xFB00\xFB01",
	PERL_MATCH_YES,

	L"ff",
	L"i",
	L"\xFB01\xFB00",
	PERL_MATCH_YES,

	L"fi",
	L"i",
	L"\xFB01\xFB00",
	PERL_MATCH_YES,

	L"fi",
	L"i",
	L"\xFB00\xFB01",
	PERL_MATCH_YES,

	L"(?#( (?{1+)a",
	L"",
	L"a",
	PERL_MATCH_YES,

	L"a# (?{1+",
	L"x",
	L"a",
	PERL_MATCH_YES,

	L"ab[(?{1]",
	L"",
	L"ab1",
	PERL_MATCH_YES,

	L"ab[(?{1\\](?{2]",
	L"",
	L"ab2",
	PERL_MATCH_YES,

	L"ab(?{\"[\"})cd",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"ab(??{\"[x]\"})cd",
	L"",
	L"abxcd",
	PERL_MATCH_YES,

	L"ab\\[(??{1})c",
	L"",
	L"ab[1c",
	PERL_MATCH_YES,

	L"ab\\\\[(??{1;})]c",
	L"",
	L"ab\\;c",
	PERL_MATCH_YES,

	L"ab\\\\\\[(??{1})c",
	L"",
	L"ab\\[1c",
	PERL_MATCH_YES,

	L"ab[c\\](??{\"]d",
	L"",
	L"abcd",
	PERL_MATCH_YES,

	L"ab[c\\\\](??{\"[x]\"})d",
	L"",
	L"ab\\xd",
	PERL_MATCH_YES,

	L"ab[c\\\\\\](??{\"x\"})]{3}d",
	L"",
	L"ab\\](d",
	PERL_MATCH_YES,

	L"ffiffl",
	L"i",
	L"abcdef\xFB03\xFB04",
	PERL_MATCH_YES,

	L"\\xdf\\xdf",
	L"ui",
	L"abcdefssss",
	PERL_MATCH_YES,

	L"st",
	L"i",
	L"\xDF\xFB05",
	PERL_MATCH_YES,

	L"ssst",
	L"i",
	L"\xDF\xFB05",
	PERL_MATCH_YES,

	L"[[:lower:]]",
	L"i",
	L"\x100",
	PERL_MATCH_YES,

	L"[[:upper:]]",
	L"i",
	L"\x101",
	PERL_MATCH_YES,

	L"s\\xDF",
	L"ui",
	L"\xDFs",
	PERL_MATCH_YES,

	L"sst",
	L"ui",
	L"s\\N{LATIN SMALL LIGATURE ST}",
	PERL_MATCH_YES,

	L"sst",
	L"ui",
	L"s\\N{LATIN SMALL LIGATURE LONG S T}",
	PERL_MATCH_YES,

	L"[[:ascii:]]",
	L"i",
	L"\\N{KELVIN SIGN}",
	PERL_MATCH_NO,

	L"[[:lower:]]",
	L"i",
	L"\\N{U+3400}",
	PERL_MATCH_NO,

	L"[[:upper:]]",
	L"i",
	L"\\N{U+01BB}",
	PERL_MATCH_NO,

	L"[^\\p{Alphabetic}]",
	L"",
	L"\x100",
	PERL_MATCH_NO,

	L"[[:alnum:]]",
	L"",
	L"\x2c1",
	PERL_MATCH_YES,

	L"[[:alnum:]]",
	L"",
	L"\x2c2",
	PERL_MATCH_NO,

	L"[[:alpha:]]",
	L"",
	L"\x2c1",
	PERL_MATCH_YES,

	L"[[:alpha:]]",
	L"",
	L"\x2c2",
	PERL_MATCH_NO,

	L"[[:graph:]]",
	L"",
	L"\x377",
	PERL_MATCH_YES,

	L"[[:graph:]]",
	L"",
	L"\x378",
	PERL_MATCH_NO,

	L"[[:lower:]]",
	L"",
	L"\x100",
	PERL_MATCH_NO,

	L"[[:lower:]]",
	L"",
	L"\x101",
	PERL_MATCH_YES,

	L"[[:lower:]]",
	L"",
	L"\x102",
	PERL_MATCH_NO,

	L"[[:print:]]",
	L"",
	L"\x377",
	PERL_MATCH_YES,

	L"[[:print:]]",
	L"",
	L"\x378",
	PERL_MATCH_NO,

	L"[[:punct:]]",
	L"",
	L"\x37D",
	PERL_MATCH_NO,

	L"[[:punct:]]",
	L"",
	L"\x37E",
	PERL_MATCH_YES,

	L"[[:punct:]]",
	L"",
	L"\x388",
	PERL_MATCH_NO,

	L"[[:upper:]]",
	L"",
	L"\x100",
	PERL_MATCH_YES,

	L"[[:upper:]]",
	L"",
	L"\x101",
	PERL_MATCH_NO,

	L"[[:word:]]",
	L"",
	L"\x2c1",
	PERL_MATCH_YES,

	L"[[:word:]]",
	L"",
	L"\x2c2",
	PERL_MATCH_NO,

	L"syntax OK\\s+\\z",
	L"si",
	L"t/bin/good.pl syntax OK\n",
	PERL_MATCH_YES,

	L"^(.*?)\\s*\\|\\s*(?:\\/\\s*|)'(.+)'$/",
	L"",
	L"text|'sec'",
	PERL_MATCH_YES,

	L"^(foo|)bar$",
	L"",
	L"bar",
	PERL_MATCH_YES,

	L"^(foo||baz)bar$",
	L"",
	L"bar",
	PERL_MATCH_YES,

	L"^(foo||baz)bar$",
	L"",
	L"bazbar",
	PERL_MATCH_YES,

	L"^(foo||baz)bar$",
	L"",
	L"foobar",
	PERL_MATCH_YES,

	L"^(?:foo|)bar$",
	L"",
	L"bar",
	PERL_MATCH_YES,

	L"^(?:foo||baz)bar$",
	L"",
	L"bar",
	PERL_MATCH_YES,

	L"^(?:foo||baz)bar$",
	L"",
	L"bazbar",
	PERL_MATCH_YES,

	L"^(?:foo||baz)bar$",
	L"",
	L"foobar",
	PERL_MATCH_YES,

	L"^(?i:foo|)bar$",
	L"",
	L"bar",
	PERL_MATCH_YES,

	L"^(?i:foo||baz)bar$",
	L"",
	L"bar",
	PERL_MATCH_YES,

	L"^(?i:foo||baz)bar$",
	L"",
	L"bazbar",
	PERL_MATCH_YES,

	L"^(?i:foo||baz)bar$",
	L"",
	L"foobar",
	PERL_MATCH_YES,

	L"^(.)(?:(..)|B)[CX]",
	L"",
	L"ABCDE",
	PERL_MATCH_YES,

	L"^(.)(?:BC(.)|B)[CX]",
	L"",
	L"ABCDE",
	PERL_MATCH_YES,

	L"^(.)(?:(.)+)*[BX]",
	L"",
	L"ABCDE",
	PERL_MATCH_YES,

	L"^(.)(BC)*",
	L"",
	L"ABCDE",
	PERL_MATCH_YES,

	L"^(.)(BC)*[BX]",
	L"",
	L"ABCDE",
	PERL_MATCH_YES,

	L"^(.)(B)*.[DX]",
	L"",
	L"ABCDE",
	PERL_MATCH_YES,

	L"^(.)(B)*.[CX]",
	L"",
	L"ABCDE",
	PERL_MATCH_YES,

	L"^(A)(?{\"xyz\"})B$",
	L"",
	L"AB",
	PERL_MATCH_YES,

	L"^(A)(?{return \"xyz\"})B$",
	L"",
	L"AB",
	PERL_MATCH_YES,

	L"^(A)((??{\"xyz\"}))$",
	L"",
	L"Axyz",
	PERL_MATCH_YES,

	L"^(A)((??{return \"xyz\"}))$",
	L"",
	L"Axyz",
	PERL_MATCH_YES,

	L"^(A)((?(?{1})abc|xyz))$",
	L"",
	L"Aabc",
	PERL_MATCH_YES,

	L"^(A)((?(?{0})abc|xyz))$",
	L"",
	L"Axyz",
	PERL_MATCH_YES,

	L"^(A)((?(?{return 1})abc|xyz))$",
	L"",
	L"Aabc",
	PERL_MATCH_YES,

	L"^(A)((?(?{return 0})abc|xyz))$",
	L"",
	L"Axyz",
	PERL_MATCH_YES,

	L"^(a)((??{\"b\"}))$",
	L"i",
	L"AB",
	PERL_MATCH_YES,

	L"^(A)((??{'B$'}))(\\nC)$",
	L"m",
	L"AB\nC",
	PERL_MATCH_YES,

	L"^(A)((??{'.'}))(B)$",
	L"s",
	L"A\nB",
	PERL_MATCH_YES,

	L"^(A) ((??{' .'}))(B)$",
	L"x",
	L"A B",
	PERL_MATCH_YES,

	L"^((??{'\\d'}))$",
	L"a",
	L"\x660",
	PERL_MATCH_NO,

	L"^(??{\"s\"})$",
	L"i",
	L"\x17F",
	PERL_MATCH_YES,

	L"^(??{\"s\"})$",
	L"ia",
	L"\x17F",
	PERL_MATCH_YES,

	L"^(??{\"s\"})$",
	L"iaa",
	L"\x17F",
	PERL_MATCH_NO,

	L"^(??{'\\w'})$",
	L"u",
	L"\xAA",
	PERL_MATCH_YES,

	L"^(?:(X)?(\\d)|(X)?(\\d\\d))$",
	L"",
	L"X12",
	PERL_MATCH_YES,

	L"^(?:(XX)?(\\d)|(XX)?(\\d\\d))$",
	L"",
	L"XX12",
	PERL_MATCH_YES,

	L"\\A(?>\\[(?:(?:)(?:R){1}|T|V?|A)\\])\\z",
	L"",
	L"[A]",
	PERL_MATCH_YES,

	L"( [^z] $ [^z]+)",
	L"xm",
	L"aa\nbb\ncc\n",
	PERL_MATCH_YES,

	L"[\\h]",
	L"",
	L"\xA0",
	PERL_MATCH_YES,

	L"[\\H]",
	L"",
	L"\xBF",
	PERL_MATCH_YES,

	L"[\\H]",
	L"",
	L"\xA0",
	PERL_MATCH_NO,

	L"[\\H]",
	L"",
	L"\xA1",
	PERL_MATCH_YES,

	L"[^\\n]+",
	L"",
	L"\nb",
	PERL_MATCH_YES,

	L"[^\\n]+",
	L"",
	L"a\n",
	PERL_MATCH_YES,

	L"(?a:\\p{Any})",
	L"",
	L"\x100",
	PERL_MATCH_YES,

	L"(?aa:\\p{Any})",
	L"",
	L"\x100",
	PERL_MATCH_YES,

	L"\\w",
	L"",
	L"\x200C",
	PERL_MATCH_YES,

	L"\\W",
	L"",
	L"\x200C",
	PERL_MATCH_NO,

	L"\\w",
	L"",
	L"\x200D",
	PERL_MATCH_YES,

	L"\\W",
	L"",
	L"\x200D",
	PERL_MATCH_NO,

	L"^(?d:\\xdf|_)*_",
	L"i",
	L"\x17f\x17f_",
	PERL_MATCH_YES,

	L"(\\x{100})",
	L"",
	L"\x2000\x2000\x2000\x100",
	PERL_MATCH_YES,

	L"^\\R{2}$",
	L"",
	L"\r\n\r\n",
	PERL_MATCH_YES,

	L"^\\D{11}",
	L"a",
	//L"\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF",
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF",
	PERL_MATCH_NO,

	L"^\\S{11}",
	L"a",
	//L"\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF",
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF",
	PERL_MATCH_NO,

	L"^\\W{11}",
	L"a",
	//L"\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF\x10FFFF",
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF"
	L"\xDBFF\xDFFF",
	PERL_MATCH_NO,

	L"\\Vn",
	L"",
	L"\xFFn/",
	PERL_MATCH_YES,

	L"(?l:a?\\w)",
	L"",
	L"b",
	PERL_MATCH_YES,

	L"m?^xy\\?$?",
	L"",
	L"xy?",
	PERL_MATCH_YES,

	L"[#]",
	L"",
	L"a#b",
	PERL_MATCH_YES,

	L"[#]b",
	L"",
	L"a#b",
	PERL_MATCH_YES,

	L"[#]",
	L"x",
	L"a#b",
	PERL_MATCH_YES,

	L"[#]b",
	L"x",
	L"a#b",
	PERL_MATCH_YES,

	L"[#](?{})",
	L"x",
	L"a#b",
	PERL_MATCH_YES,

	L"[#](??{'b'})",
	L"x",
	L"a#b",
	PERL_MATCH_YES,

	L"(?#)(?{})b",
	L"",
	L"a#b",
	PERL_MATCH_YES,

	L"(?#)(??{'b'})",
	L"",
	L"a#b",
	PERL_MATCH_YES,

	L"[(?#](?{})b",
	L"",
	L"a#b",
	PERL_MATCH_YES,

	L"[(?#](??{'b'})",
	L"",
	L"a#b",
	PERL_MATCH_YES,

	L"(?#)(?{})b",
	L"x",
	L"a#b",
	PERL_MATCH_YES,

	L"(?#)(??{'b'})",
	L"x",
	L"a#b",
	PERL_MATCH_YES,
};
int	nDataRegEx05a	= sizeof(DataRegEx05a) / sizeof(TDataRegEx05a);
