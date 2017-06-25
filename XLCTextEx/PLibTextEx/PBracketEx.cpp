//	XLCTextEx_1.0x	:	PLibTextEx

//	PBracketEx.cpp
//
#include "stdafx.h"

NS_PLIB_BEGIN

//======================================================================
//	PSBERange
//	ブラケット表現による文字クラスで範囲を表すための構造体
//======================================================================
//----------------------------------------------------------------------
//	Match 用の補助関数
//----------------------------------------------------------------------
static int CompareRangeElement(T_UCP cp1, T_UCP cp2, DWORD dwFlags, T_PCSTR_U pszLocale)
{
	return PLib::Unicode::CompareCodepointUCD(cp1, cp2, dwFlags, pszLocale);
}

static int CompareRangeElement(T_UCP cp1, UCPSTRING* pcoll2, DWORD dwFlags, T_PCSTR_U pszLocale)
{
	UCPSTRING	ucsTemp;

	ucsTemp.assign(1, cp1);
	return PLib::Unicode::CompareStringUCD(&ucsTemp, pcoll2, dwFlags, pszLocale);
}

static int CompareRangeElement(UCPSTRING* pcoll1, T_UCP cp2, DWORD dwFlags, T_PCSTR_U pszLocale)
{
	UCPSTRING	ucsTemp;

	ucsTemp.assign(1, cp2);
	return PLib::Unicode::CompareStringUCD(pcoll1, &ucsTemp, dwFlags, pszLocale);
}

static int CompareRangeElement(UCPSTRING* pcoll1, UCPSTRING* pcoll2, DWORD dwFlags, T_PCSTR_U pszLocale)
{
	return PLib::Unicode::CompareStringUCD(pcoll1, pcoll2, dwFlags, pszLocale);
}

//----------------------------------------------------------------------
//	Match	(1)	codepoint
//----------------------------------------------------------------------
bool PSBERange::Match(T_UCP cpOther, DWORD dwFlags, DWORD dwFlagsColl, T_PCSTR_U pszLocale)
{
	int		ir1, ir2;

	switch (iTypeF)
	{
	case PREGEX_BE_ELEMENT_CODEPAGE:
		ir1	= CompareRangeElement((T_UCP)pRangeF, cpOther, dwFlags, pszLocale);
		break;
	case PREGEX_BE_ELEMENT_COLLATING_ELEMENT:
		ir1	= CompareRangeElement((UCPSTRING*)pRangeF, cpOther, dwFlagsColl, pszLocale);
		break;
	default:
		THROWPE_LOGIC_ERROR("");
		break;
	}

	switch (iTypeL)
	{
	case PREGEX_BE_ELEMENT_CODEPAGE:
		ir2	= CompareRangeElement((T_UCP)pRangeL, cpOther, dwFlags, pszLocale);
		break;
	case PREGEX_BE_ELEMENT_COLLATING_ELEMENT:
		ir2	= CompareRangeElement((UCPSTRING*)pRangeL, cpOther, dwFlagsColl, pszLocale);
		break;
	default:
		THROWPE_LOGIC_ERROR("");
		break;
	}

	return (
		(ir1 == CSTR_EQUAL)	||
		(ir2 == CSTR_EQUAL)	||
		(ir1 == CSTR_LESS_THAN && ir2 == CSTR_GREATER_THAN)
		);
}

//----------------------------------------------------------------------
//	Match	(2)	collating element
//----------------------------------------------------------------------
bool PSBERange::Match(UCPSTRING* pColl, DWORD dwFlags, DWORD dwFlagsColl, T_PCSTR_U pszLocale)
{
	int		ir1, ir2;

	switch (iTypeF)
	{
	case PREGEX_BE_ELEMENT_CODEPAGE:
		ir1	= CompareRangeElement((T_UCP)pRangeF, pColl, dwFlagsColl, pszLocale);
		break;
	case PREGEX_BE_ELEMENT_COLLATING_ELEMENT:
		ir1	= CompareRangeElement((UCPSTRING*)pRangeF, pColl, dwFlagsColl, pszLocale);
		break;
	default:
		THROWPE_LOGIC_ERROR("");
		break;
	}

	switch (iTypeL)
	{
	case PREGEX_BE_ELEMENT_CODEPAGE:
		ir2	= CompareRangeElement((T_UCP)pRangeL, pColl, dwFlagsColl, pszLocale);
		break;
	case PREGEX_BE_ELEMENT_COLLATING_ELEMENT:
		ir2	= CompareRangeElement((UCPSTRING*)pRangeL, pColl, dwFlagsColl, pszLocale);
		break;
	default:
		THROWPE_LOGIC_ERROR("");
		break;
	}

	return ((ir1 == CSTR_LESS_THAN || ir1 == CSTR_EQUAL) && (ir2 == CSTR_GREATER_THAN || ir2 == CSTR_EQUAL));
}


//======================================================================
//	class PCBETerm
//
//	Bracket Expression の項を表すクラス。
//======================================================================
//----------------------------------------------------------------------
//	PCBETerm::Clear
//----------------------------------------------------------------------
void CLASS_PREGEX_BETERM::Clear()
{
	ITR_RANGELIST		itr_rg;
	ITR_COLLLIST		itr_cl;
	ITR_EQUIVLIST		itr_eq;
	ITR_BRACKETEXLIST	itr_be;

	//	codepage (ascii)
	ciAsciiBits.reset();
	ciAsciiBitsIC.reset();

	//	codepage (all)
	ciCpSet.clear();

	//	文字範囲
	for (itr_rg = ciRangeList.begin(); itr_rg != ciRangeList.end(); ++itr_rg)
	{
		ciAllocRange.Deallocate(*itr_rg);
	}
	ciRangeList.clear();

	//	collating element
	for (itr_cl = ciCollList.begin(); itr_cl != ciCollList.end(); ++itr_cl)
	{
		ciAllocUCPString.Deallocate(*itr_cl);
	}
	ciCollList.clear();

	//	等価クラス
	for (itr_eq = ciEquivList.begin(); itr_eq != ciEquivList.end(); ++itr_eq)
	{
		ciAllocUCPString.Deallocate(*itr_eq);
	}
	ciEquivList.clear();

	//	POSIX 文字クラス
	ciPOSIXCClasses.clear();

	//	Unicode Property
	ciUProperties.clear();

	//	BracketEx
	for (itr_be = ciSubBracketEx.begin(); itr_be != ciSubBracketEx.end(); ++itr_be)
	{
		ciAllocBracketEx.Deallocate(*itr_be);
	}
	ciSubBracketEx.clear();
}

//----------------------------------------------------------------------
//	PCBETerm::Init
//----------------------------------------------------------------------
void CLASS_PREGEX_BETERM::Init()
{
	Clear();
}

//----------------------------------------------------------------------
//	PCBETerm::RegisterCodepage
//----------------------------------------------------------------------
void CLASS_PREGEX_BETERM::RegisterCodepage(T_UCP cpReg)
{
	//	7 ビット文字の場合は、bitset にも登録しておく。
	if (IS_7BIT(cpReg))
	{
		Register7BitCodepage(cpReg);
	}

	//	マルチコード文字として登録しておく。
	ciCpSet.insert(cpReg);
	return;
}

//----------------------------------------------------------------------
//	PCBETerm::Register7BitCodepage
//----------------------------------------------------------------------
void CLASS_PREGEX_BETERM::Register7BitCodepage(T_UCP cpReg)
{
	T_CHAR	cTemp;

	if (!IS_7BIT(cpReg))	return;

	//	bitset に登録する。
	ciAsciiBits.set(cpReg);

	//	大文字小文字を区別しない場合用。
	cTemp = TOUPPER_U(cpReg);
	ciAsciiBitsIC.set(cTemp);
	cTemp = TOLOWER_U(cpReg);
	ciAsciiBitsIC.set(cTemp);

	return;
}

//----------------------------------------------------------------------
//	PCBETerm::Register7BitCodepages
//----------------------------------------------------------------------
void CLASS_PREGEX_BETERM::Register7BitCodepages(T_UCP cpMin, T_UCP cpMax)
{
	T_UCP	c;

	if (!IS_7BIT(cpMin))	return;
	if (cpMax > 0x7F)	cpMax = 0x7F;

	for (c = cpMin; c <= cpMax; ++c)
	{
		Register7BitCodepage(c);
	}
	return;
}

//----------------------------------------------------------------------
//	PCBETerm::RegisterRange
//----------------------------------------------------------------------
void CLASS_PREGEX_BETERM::RegisterRange(PSBERange* pSrcRange)
{
	T_UCP		cpF, cpL;
	UCPSTRING	*pCollF, *pCollL;
	T_UCP		cpMin, cpMax;
	UCPSTRING	ucsTemp;
	PSBERange	ciRangeTemp;
	PSBERange*	pciRange;
	DWORD		dwFlags	= 0;

	//------------------------------------------------------------
	//	終端より先頭が大きい場合は入れ替える。
	//	bitset に登録する準備として、コードポイントの範囲を求めておく。
	//------------------------------------------------------------
	if (pSrcRange->GetFirstType()	== PREGEX_BE_ELEMENT_CODEPAGE &&
		pSrcRange->GetLastType()	== PREGEX_BE_ELEMENT_CODEPAGE)
	{
		cpF	= pSrcRange->GetFirstCp();
		cpL	= pSrcRange->GetLastCp();
		if (cpF > cpL)
		{
			ciRangeTemp.SetFirstCp(cpL);
			ciRangeTemp.SetLastCp(cpF);
			cpMin	= cpL;
			cpMax	= cpF;
		}
		else
		{
			ciRangeTemp.SetFirstCp(cpF);
			ciRangeTemp.SetLastCp(cpL);
			cpMin	= cpF;
			cpMax	= cpL;
		}
	}
	else if (
		pSrcRange->GetFirstType()	== PREGEX_BE_ELEMENT_CODEPAGE	&&
		pSrcRange->GetLastType()	== PREGEX_BE_ELEMENT_COLLATING_ELEMENT
		)
	{
		cpF		= pSrcRange->GetFirstCp();
		pCollL	= pSrcRange->GetLastColl();
		ucsTemp.assign(1, pSrcRange->GetFirstCp());
		if (ucsTemp.compare(*(pSrcRange->GetLastColl())) > 0)
		{
			ciRangeTemp.SetFirstColl(pCollL);
			ciRangeTemp.SetLastCp(cpF);
			cpMin	= ((pCollL->size() > 1) ? (*(pCollL->begin()) + 1) : *(pCollL->begin()));
			cpMax	= cpF;
		}
		else
		{
			ciRangeTemp.SetFirstCp(cpF);
			ciRangeTemp.SetLastColl(pCollL);
			cpMin	= cpF;
			cpMax	= *(pCollL->begin());
		}
	}
	else if (
		pSrcRange->GetFirstType()	== PREGEX_BE_ELEMENT_COLLATING_ELEMENT	&&
		pSrcRange->GetLastType()	== PREGEX_BE_ELEMENT_CODEPAGE
		)
	{
		pCollF	= pSrcRange->GetFirstColl();
		cpL		= pSrcRange->GetLastCp();
		ucsTemp.assign(1, cpL);
		if (pCollF->compare(ucsTemp) > 0)
		{
			ciRangeTemp.SetFirstCp(cpL);
			ciRangeTemp.SetLastColl(pCollF);
			cpMin	= cpL;
			cpMax	= *(pCollF->begin());
		}
		else
		{
			ciRangeTemp.SetFirstColl(pCollF);
			ciRangeTemp.SetLastCp(cpL);
			cpMin	= ((pCollF->size() > 1) ? (*(pCollF->begin()) + 1) : *(pCollF->begin()));
			cpMax	= cpL;
		}
	}
	else if (
		pSrcRange->GetFirstType()	== PREGEX_BE_ELEMENT_COLLATING_ELEMENT	&&
		pSrcRange->GetLastType()	== PREGEX_BE_ELEMENT_COLLATING_ELEMENT
		)
	{
		pCollF	= pSrcRange->GetFirstColl();
		pCollL	= pSrcRange->GetLastColl();
		if (pCollF->compare(*pCollL) > 0)
		{
			ciRangeTemp.SetFirstColl(pCollL);
			ciRangeTemp.SetLastColl(pCollF);
			cpMin	= ((pCollL->size() > 1) ? (*(pCollL->begin()) + 1) : *(pCollL->begin()));
			cpMax	= *(pCollF->begin());
		}
		else
		{
			ciRangeTemp.SetFirstColl(pCollF);
			ciRangeTemp.SetLastColl(pCollL);
			cpMin	= ((pCollF->size() > 1) ? (*(pCollF->begin()) + 1) : *(pCollF->begin()));
			cpMax	= *(pCollL->begin());
		}
	}
	else
	{
		return;
	}

	//------------------------------------------------------------
	//	指定された範囲内に 0x7F までの文字がある場合は bitset にも登録しておく。
	//------------------------------------------------------------
	if (IS_7BIT(cpMin))
	{
		if (IS_7BIT(cpMax))
		{
			Register7BitCodepages(cpMin, cpMax);
		}
		//	指定された範囲が 0x7F を跨いでいる場合は 0x7F までを登録する。
		else
		{
			Register7BitCodepages(cpMin, 0x7F);
		}
	}

	//------------------------------------------------------------
	//	指定された範囲をコピーして ciRangeList に登録する。
	//------------------------------------------------------------
	pciRange	= ciAllocRange.Allocate();
	pciRange->Set(&ciRangeTemp);
	ciRangeList.push_back(pciRange);
	return;
}

//----------------------------------------------------------------------
//	PCBETerm::RegisterCollatingSequence	(1)
//----------------------------------------------------------------------
void CLASS_PREGEX_BETERM::RegisterCollatingSequence(UCPSTRING* pColl)
{
	if (pColl != NULL)
	{
		ciCollList.push_back(pColl);
	}
}

//----------------------------------------------------------------------
//	PCBETerm::RegisterCollatingSequence	(2)
//----------------------------------------------------------------------
void CLASS_PREGEX_BETERM::RegisterCollatingSequence(const T_UCP* pCollB, const T_UCP* pCollE)
{
	UCPSTRING* pColl;

	pColl	= ciAllocUCPString.Allocate();
	pColl->assign(pCollB, (size_t)(pCollE - pCollB));
	ciCollList.push_back(pColl);
}

//----------------------------------------------------------------------
//	PCBETerm::RegisterEquivalenceClass	(1)
//----------------------------------------------------------------------
void CLASS_PREGEX_BETERM::RegisterEquivalenceClass(UCPSTRING* pClass)
{
	if (pClass != NULL)	ciEquivList.push_back(pClass);
}

//----------------------------------------------------------------------
//	PCBETerm::RegisterEquivalenceClass	(2)
//----------------------------------------------------------------------
void CLASS_PREGEX_BETERM::RegisterEquivalenceClass(const T_UCP* pClassB, const T_UCP* pClassE)
{
	UCPSTRING*	pClass;

	if (pClassB == NULL || pClassB >= pClassE)	return;

	pClass	= ciAllocUCPString.Allocate();
	pClass->assign(pClassB, (size_t)(pClassE - pClassB));
	ciEquivList.push_back(pClass);
	return;
}

//----------------------------------------------------------------------
//	PCBETerm::RegisterPOSIXCharClass	(1)
//----------------------------------------------------------------------
void CLASS_PREGEX_BETERM::RegisterPOSIXCharClass(int iClass)
{
	size_t	c;

	if (iClass <= 0)	return;
	ciPOSIXCClasses.insert(iClass);

	//------------------------------------------------------------
	//	クラスに属する 7 bit 文字を bitset に登録する。
	//------------------------------------------------------------
	switch (iClass)
	{
	case PTEXTEX_CHARCLASS_POSIX_ALNUM:
		for (c = 0x30; c < 0x3A; ++c)	ciAsciiBits.set(c);		//	0 - 9
		for (c = 0x41; c < 0x5B; ++c)	ciAsciiBits.set(c);		//	A - Z
		for (c = 0x61; c < 0x7B; ++c)	ciAsciiBits.set(c);		//	a - z
		for (c = 0x30; c < 0x3A; ++c)	ciAsciiBitsIC.set(c);	//	0 - 9
		for (c = 0x41; c < 0x5B; ++c)	ciAsciiBitsIC.set(c);	//	A - Z
		for (c = 0x61; c < 0x7B; ++c)	ciAsciiBitsIC.set(c);	//	a - z
		break;

	case PTEXTEX_CHARCLASS_POSIX_ALPHA:
		for (c = 0x41; c < 0x5B; ++c)	ciAsciiBits.set(c);		//	A - Z
		for (c = 0x61; c < 0x7B; ++c)	ciAsciiBits.set(c);		//	a - z
		for (c = 0x41; c < 0x5B; ++c)	ciAsciiBitsIC.set(c);	//	A - Z
		for (c = 0x61; c < 0x7B; ++c)	ciAsciiBitsIC.set(c);	//	a - z
		break;

	case PTEXTEX_CHARCLASS_POSIX_ASCII:
		for (c = 0x00; c <= 0x7F; ++c)	ciAsciiBits.set(c);		//	ascii
		for (c = 0x00; c <= 0x7F; ++c)	ciAsciiBitsIC.set(c);	//	ascii
		break;

	case PTEXTEX_CHARCLASS_POSIX_BLANK:
		ciAsciiBits.set(0x09);		//	HT
		ciAsciiBits.set(0x20);		//	SP
		ciAsciiBitsIC.set(0x09);	//	HT
		ciAsciiBitsIC.set(0x20);	//	SP
		break;

	case PTEXTEX_CHARCLASS_POSIX_CNTRL:
		for (c = 0x00; c < 0x20; ++c)	ciAsciiBits.set(c);		//	制御文字
		ciAsciiBits.set(0x7F);		//	DEL
		for (c = 0x00; c < 0x20; ++c)	ciAsciiBitsIC.set(c);	//	制御文字
		ciAsciiBitsIC.set(0x7F);	//	DEL
		break;

	case PTEXTEX_CHARCLASS_POSIX_DIGIT:
		for (c = 0x30; c < 0x3A; ++c)	ciAsciiBits.set(c);		//	0 - 9
		for (c = 0x30; c < 0x3A; ++c)	ciAsciiBitsIC.set(c);	//	0 - 9
		break;

	case PTEXTEX_CHARCLASS_POSIX_GRAPH:
		for (c = 0x21; c < 0x7F; ++c)	ciAsciiBits.set(c);
		for (c = 0x21; c < 0x7F; ++c)	ciAsciiBitsIC.set(c);
		break;

	case PTEXTEX_CHARCLASS_POSIX_LOWER:
		for (c = 0x61; c < 0x7B; ++c)	ciAsciiBits.set(c);		//	a - z
		for (c = 0x41; c < 0x5B; ++c)	ciAsciiBitsIC.set(c);	//	A - Z
		for (c = 0x61; c < 0x7B; ++c)	ciAsciiBitsIC.set(c);	//	a - z
		break;

	case PTEXTEX_CHARCLASS_POSIX_PRINT:
		for (c = 0x20; c < 0x7F; ++c)	ciAsciiBits.set(c);
		for (c = 0x20; c < 0x7F; ++c)	ciAsciiBitsIC.set(c);
		break;

	case PTEXTEX_CHARCLASS_POSIX_PUNCT:
		for (c = 0x21; c < 0x30; ++c)	ciAsciiBits.set(c);		//	! - /
		for (c = 0x3A; c < 0x41; ++c)	ciAsciiBits.set(c);		//	: - @
		for (c = 0x5B; c < 0x61; ++c)	ciAsciiBits.set(c);		//	[ - `
		for (c = 0x7B; c < 0x7F; ++c)	ciAsciiBits.set(c);		//	{ - ~
		for (c = 0x21; c < 0x30; ++c)	ciAsciiBitsIC.set(c);	//	! - /
		for (c = 0x3A; c < 0x41; ++c)	ciAsciiBitsIC.set(c);	//	: - @
		for (c = 0x5B; c < 0x61; ++c)	ciAsciiBitsIC.set(c);	//	[ - `
		for (c = 0x7B; c < 0x7F; ++c)	ciAsciiBitsIC.set(c);	//	{ - ~
		break;

	case PTEXTEX_CHARCLASS_POSIX_SPACE:
		ciAsciiBits.set(0x09);		//	HT
		ciAsciiBits.set(0x0A);		//	LF
		ciAsciiBits.set(0x0B);		//	VT
		ciAsciiBits.set(0x0C);		//	FF
		ciAsciiBits.set(0x0D);		//	CR
		ciAsciiBits.set(0x20);		//	SP
		ciAsciiBitsIC.set(0x09);	//	HT
		ciAsciiBitsIC.set(0x0A);	//	LF
		ciAsciiBitsIC.set(0x0B);	//	VT
		ciAsciiBitsIC.set(0x0C);	//	FF
		ciAsciiBitsIC.set(0x0D);	//	CR
		ciAsciiBitsIC.set(0x20);	//	SP
		break;

	case PTEXTEX_CHARCLASS_POSIX_UPPER:
		for (c = 0x41; c < 0x5B; ++c)	ciAsciiBits.set(c);		//	A - Z
		for (c = 0x41; c < 0x5B; ++c)	ciAsciiBitsIC.set(c);	//	A - Z
		for (c = 0x61; c < 0x7B; ++c)	ciAsciiBitsIC.set(c);	//	a - z
		break;

	case PTEXTEX_CHARCLASS_POSIX_WORD:
		for (c = 0x30; c < 0x3A; ++c)	ciAsciiBits.set(c);		//	0 - 9
		for (c = 0x41; c < 0x5B; ++c)	ciAsciiBits.set(c);		//	A - Z
		for (c = 0x61; c < 0x7B; ++c)	ciAsciiBits.set(c);		//	a - z
		ciAsciiBits.set(0x5F);									//	_
		for (c = 0x30; c < 0x3A; ++c)	ciAsciiBitsIC.set(c);	//	0 - 9
		for (c = 0x41; c < 0x5B; ++c)	ciAsciiBitsIC.set(c);	//	A - Z
		for (c = 0x61; c < 0x7B; ++c)	ciAsciiBitsIC.set(c);	//	a - z
		ciAsciiBitsIC.set(0x5F);								//	_
		break;


	case PTEXTEX_CHARCLASS_POSIX_XDIGIT:
		for (c = 0x30; c < 0x3A; ++c)	ciAsciiBits.set(c);		//	0 - 9
		for (c = 0x41; c < 0x47; ++c)	ciAsciiBits.set(c);		//	A - F
		for (c = 0x61; c < 0x67; ++c)	ciAsciiBits.set(c);		//	a - f
		for (c = 0x30; c < 0x3A; ++c)	ciAsciiBitsIC.set(c);	//	0 - 9
		for (c = 0x41; c < 0x47; ++c)	ciAsciiBitsIC.set(c);	//	A - F
		for (c = 0x61; c < 0x67; ++c)	ciAsciiBitsIC.set(c);	//	a - f
		break;

	case PTEXTEX_CHARCLASS_POSIX_NONDIGIT:
		for (c = 0x00; c < 0x30; ++c)	ciAsciiBits.set(c);		//	0 - 9
		for (c = 0x3A; c <= 0x7F; ++c)	ciAsciiBits.set(c);		//	0 - 9
		for (c = 0x00; c < 0x30; ++c)	ciAsciiBitsIC.set(c);	//	0 - 9
		for (c = 0x3A; c <= 0x7F; ++c)	ciAsciiBitsIC.set(c);	//	0 - 9
		break;

	case PTEXTEX_CHARCLASS_POSIX_NONSPACE:
		for (c = 0x00; c <= 0x7F; ++c)	ciAsciiBits.set(c);		//	ascii
		ciAsciiBits.reset(0x09);	//	HT
		ciAsciiBits.reset(0x0A);	//	LF
		ciAsciiBits.reset(0x0B);	//	VT
		ciAsciiBits.reset(0x0C);	//	FF
		ciAsciiBits.reset(0x0D);	//	CR
		ciAsciiBits.reset(0x20);	//	SP
		for (c = 0x00; c <= 0x7F; ++c)	ciAsciiBitsIC.set(c);	//	ascii
		ciAsciiBitsIC.reset(0x09);	//	HT
		ciAsciiBitsIC.reset(0x0A);	//	LF
		ciAsciiBitsIC.reset(0x0B);	//	VT
		ciAsciiBitsIC.reset(0x0C);	//	FF
		ciAsciiBitsIC.reset(0x0D);	//	CR
		ciAsciiBitsIC.reset(0x20);	//	SP
		break;

	case PTEXTEX_CHARCLASS_POSIX_NONWORD:
		for (c = 0x00; c < 0x30; ++c)	ciAsciiBits.set(c);
		for (c = 0x3A; c < 0x41; ++c)	ciAsciiBits.set(c);
		for (c = 0x5B; c < 0x61; ++c)	ciAsciiBits.set(c);
		for (c = 0x7B; c <= 0x7F; ++c)	ciAsciiBits.set(c);
		ciAsciiBits.reset(0x5F);
		for (c = 0x00; c < 0x30; ++c)	ciAsciiBitsIC.set(c);
		for (c = 0x3A; c < 0x41; ++c)	ciAsciiBitsIC.set(c);
		for (c = 0x5B; c < 0x61; ++c)	ciAsciiBitsIC.set(c);
		for (c = 0x7B; c <= 0x7F; ++c)	ciAsciiBitsIC.set(c);
		ciAsciiBitsIC.reset(0x5F);

	default:
		break;
	}
}

//----------------------------------------------------------------------
//	PCBETerm::RegisterPOSIXCharClass	(2)
//----------------------------------------------------------------------
void CLASS_PREGEX_BETERM::RegisterPOSIXCharClass(const T_UCP* pClassB, const T_UCP* pClassE)
{
	int		iClass;
	
	iClass	= PLib::GetUnicodePropertyId(pClassB, pClassE);
	if (iClass > 0)
	{
		RegisterPOSIXCharClass(iClass);
	}
}

//----------------------------------------------------------------------
//	PCBETerm::RegisterUnicodeProperty
//----------------------------------------------------------------------
void CLASS_PREGEX_BETERM::RegisterUnicodeProperty(int iProp)
{
	ciUProperties.insert(iProp);
}

//----------------------------------------------------------------------
//	PCBETerm::RegisterSubBracketEx
//----------------------------------------------------------------------
void CLASS_PREGEX_BETERM::RegisterSubBracketEx(CBRACKETEX* pBracketEx)
{
	ciSubBracketEx.push_back(pBracketEx);
}

//----------------------------------------------------------------------
//	CreateUCPString
//	引数のチェックは呼び出し側で行っておくこと。
//----------------------------------------------------------------------
bool CLASS_PREGEX_BETERM::CreateUCPString(UCPSTRING** ppucStr)
{
	if (pciParentBE == NULL)	return false;
	*ppucStr	= ciAllocUCPString.Allocate();
	return (*ppucStr != NULL);
}

bool CLASS_PREGEX_BETERM::CreateUCPString(UCPSTRING** ppucStr, ITR_UCPSTRING& itr1, ITR_UCPSTRING& itr2, PCTextUR* pciText)
{
	UCPSTRING*	pStr	= NULL;

	pStr	= ciAllocUCPString.Allocate();
	if (pStr == NULL)	return false;
	pciText->GetSubString(pStr, itr1, itr2);
	*ppucStr	= pStr;
	return true;
}

//----------------------------------------------------------------------
//	PCBETerm::Parse	の補助関数	BEMatchCp
//----------------------------------------------------------------------
static inline bool BEMatchCp(T_UCP cp1, T_UCP cp2, DWORD dwFlags, T_PCSTR_U pszLocale)
{
	return (PLib::Unicode::CompareCodepointUCD(cp1, cp2, dwFlags, pszLocale) == CSTR_EQUAL);
}

//----------------------------------------------------------------------
//	PCBETerm::Parse
//
//	pciPattern は、最初の文字にセットされていなければならない。
//	[. .] については、暫定的な処置として以下のように扱うこととする。
//	1 文字の場合は通常の文字として扱う。
//	2 文字以上の場合は無視する。範囲指定で使用されている場合は、その範囲指定を無視する。
//----------------------------------------------------------------------
bool CLASS_PREGEX_BETERM::Parse(CPATTERN* pciPattern)
{
	DWORD		dwCSFlags	= 0;	//	| NORM_IGNORECASE;
	DWORD		dwCSFlagsC	= 0;	//	大文字小文字を区別する必要がある場合用
	DWORD		dwCSFlagsIC	= 0;	//	大文字小文字を区別しない場合用
	T_PCSTR_U	pszLocale	= NULL;
	ITR_UCPSTRING	itr1, itr2;
	int			tok1, tok2;
	T_UCP		cp1;	//, cp2;
	int			iCharClass;
	int			iProperty;
	CBRACKETEX*	pBracketEx;
	UCPSTRING*	pucStr;
	UCPSTRING	ucsTemp;
	T_STRING	strTemp;

	if (pciParentBE == NULL)
	{
		THROWPE_LOGIC_ERROR("PCBETerm::Parse no parent.");
	}
	dwCSFlags	|= ((pciParentBE->GetBase())->Options())->GetCompareStringUCDFlags();
	dwCSFlagsC	= dwCSFlags;
	COMPARESTRING_UNSET_NORM_IGNORECASE(dwCSFlagsC);
	COMPARESTRING_UNSET_LINGUISTIC_IGNORECASE(dwCSFlagsC);
	dwCSFlagsIC	= (dwCSFlagsC | NORM_IGNORECASE);

	//------------------------------------------------------------
	//	struct SRangeTemp
	//	Range を取得・設定するための構造体
	//------------------------------------------------------------
	struct SRangeTemp	: public PSBERange
	{
#define	PREGEX_BE_STATUS_RANGE_NONE			0
#define	PREGEX_BE_STATUS_RANGE_FIRSTSET		1
#define	PREGEX_BE_STATUS_RANGE_HYPHENSET	2
#define	PREGEX_BE_STATUS_RANGE_COMPLETED	3

		//typedef	PSBERange<T_CHAR>	PSBERange;

		T_UCP		cpHyphen;
		int			iStatus;
		PCBETerm*	pciBaseTerm;

		//--------------------------------------------------
		//	コンストラクタ
		//--------------------------------------------------
		SRangeTemp(PCBETerm* pBase = NULL)
			:	PSBERange(),
				pciBaseTerm(pBase),
				cpHyphen(0x002D),
				iStatus(PREGEX_BE_STATUS_RANGE_NONE)
		{}

		void	SetBase(PCBETerm* pBase)	{ pciBaseTerm = pBase; }
		void	SetStatus(int i)		{ iStatus = i; }
		int		GetStatus()				{ return iStatus; }

		//--------------------------------------------------
		//	Empty, Completed, LastPos
		//--------------------------------------------------
		bool Empty()
		{
			return (iStatus == PREGEX_BE_STATUS_RANGE_NONE);
		}

		bool Completed()
		{
			return (
				iTypeF != PREGEX_BE_ELEMENT_NONE	&&
				iTypeL != PREGEX_BE_ELEMENT_NONE	&&
				iStatus == PREGEX_BE_STATUS_RANGE_COMPLETED
				);
		}

		bool LastPos()
		{
			return (iStatus == PREGEX_BE_STATUS_RANGE_HYPHENSET);
		}

		//--------------------------------------------------
		//	Flush()
		//	現在保持しているデータを処理し、初期状態に戻す。
		//--------------------------------------------------
		bool Flush()
		{
			switch (iStatus)
			{
			case PREGEX_BE_STATUS_RANGE_NONE:
				//	書き出すデータはない。
				break;

			case PREGEX_BE_STATUS_RANGE_FIRSTSET:
			case PREGEX_BE_STATUS_RANGE_HYPHENSET:
				//	開始データだけ保持している場合は、通常の処理をする。
				//	ハイフンも得られている場合は、コードページに登録する。
				switch (iTypeF)
				{
				case PREGEX_BE_ELEMENT_CODEPAGE:
					pciBaseTerm->RegisterCodepage(GetFirstCp());
					break;
				case PREGEX_BE_ELEMENT_COLLATING_ELEMENT:
					pciBaseTerm->RegisterCollatingSequence(GetFirstColl());
					break;
				default:
					break;
				}
				if (iStatus == PREGEX_BE_STATUS_RANGE_FIRSTSET)	break;
				if (cpHyphen != 0)
				{
					pciBaseTerm->RegisterCodepage(cpHyphen);
				}
				break;

			case PREGEX_BE_STATUS_RANGE_COMPLETED:
				Register();
				break;

			default:
				THROWPE_LOGIC_ERROR("");
				return false;
				break;
			}
			Clear();
			return true;
		}

		//--------------------------------------------------
		//	Clear()
		//--------------------------------------------------
		void Clear()
		{
			PSBERange::Clear();
			cpHyphen = (T_UCP)0;
			iStatus = PREGEX_BE_STATUS_RANGE_NONE;
		}

		//--------------------------------------------------
		//	SetHyphen
		//	- を範囲の先頭にすることはできないので、この場合 false を返す。
		//	範囲の終端に指定することはできる。
		//--------------------------------------------------
		bool SetHyphen(T_UCP cpReg)
		{
			switch (iStatus)
			{
			case PREGEX_BE_STATUS_RANGE_NONE:
				THROWPE_SYNTAX_ERROR("");
				break;

			case PREGEX_BE_STATUS_RANGE_FIRSTSET:
				cpHyphen = cpReg;
				SetStatus(PREGEX_BE_STATUS_RANGE_HYPHENSET);
				return true;
				break;

			case PREGEX_BE_STATUS_RANGE_HYPHENSET:
				SetLast((LPVOID)cpReg, PREGEX_BE_ELEMENT_CODEPAGE);
				SetStatus(PREGEX_BE_STATUS_RANGE_COMPLETED);
				return true;
				break;

			case PREGEX_BE_STATUS_RANGE_COMPLETED:
				THROWPE_LOGIC_ERROR("");
				break;

			default:
				THROWPE_LOGIC_ERROR("");
				break;
			}
			return false;
		}

		//--------------------------------------------------
		//	Register
		//--------------------------------------------------
		bool Register()
		{
			if (Completed())
			{
				pciBaseTerm->RegisterRange(this);
				Clear();
				return true;
			}
			return false;
		}

		//--------------------------------------------------
		//	Destroy
		//	範囲を破棄し、先頭の文字とハイフンを通常の文字として登録する。
		//--------------------------------------------------
		void Destroy()
		{
			Flush();
		}

		//--------------------------------------------------
		//	SetTemp
		//	未設定か先頭のみが設定されている場合は、先頭の要素を登録し、入れ替える。
		//	ハイフンまで設定されている場合は末尾とし、範囲設定が完了したとする。
		//	完了の場合は範囲を登録してから、未設定の場合と同様に処理する。。
		//--------------------------------------------------
		bool SetTemp(LPVOID pReg, int iType)
		{
			switch (iStatus)
			{
			case PREGEX_BE_STATUS_RANGE_FIRSTSET:
				Flush();
				//	未設定の場合と同様に引数を登録するので、処理は次へ継続する。

			case PREGEX_BE_STATUS_RANGE_NONE:
				SetFirst(pReg, iType);
				SetStatus(PREGEX_BE_STATUS_RANGE_FIRSTSET);
				break;

			case PREGEX_BE_STATUS_RANGE_HYPHENSET:
				SetLast(pReg, iType);
				SetStatus(PREGEX_BE_STATUS_RANGE_COMPLETED);
				break;

			case PREGEX_BE_STATUS_RANGE_COMPLETED:
				if (!Register())	THROWPE_LOGIC_ERROR("");
				SetFirst(pReg, iType);
				SetStatus(PREGEX_BE_STATUS_RANGE_FIRSTSET);
				break;
			}
			return true;
		}
	};

	SRangeTemp	siRangeTemp(this);

	//------------------------------------------------------------
	//	文字列先頭の ] と - は文字として登録する。
	//	それ以外の文字の場合はループに入り通常の処理を行う。
	//------------------------------------------------------------
	tok1 = pciPattern->GetCurrentToken();
	tok2 = pciPattern->GetNextToken();

	if (tok1 == PREGEX_TOKEN_RBRACKET || tok1 == PREGEX_TOKEN_HYPHEN)
	{
		pciPattern->SetCurrentToken(PREGEX_TOKEN_CODEPAGE);
		tok1 = pciPattern->GetCurrentToken();
	}

	//------------------------------------------------------------
	//	ループ処理
	//
	//	]、||、&&、--、~~ および、テキスト終端の場合に処理を終了する。
	//	pciPattern は上記の位置を指したままにしておく。
	//	Block Expression 内で特別な意味を持つのは
	//		-、[. .]、[= =]、[: :]
	//	である。
	//------------------------------------------------------------
	while(tok1 != PREGEX_TOKEN_ERROR && tok1 != PREGEX_TOKEN_END && tok1 != PREGEX_TOKEN_RBRACKET)
	{
		//--------------------------------------------------
		//	(1)	1 文字目が -、2 文字目が - でない場合
		//	範囲を示す - である。
		//	前後が適切な要素でないなら文法エラーとして例外をスローする。
		//	t2 が PREGEX_TOKEN_END の場合の処理はループから抜けた後で行う。
		//--------------------------------------------------
		if ((tok1 == PREGEX_TOKEN_HYPHEN) && (tok2 != PREGEX_TOKEN_HYPHEN))
		{
			if (!PCTEXT_GETVALIDCP(pciPattern->GetCurrentCp(&cp1)))	THROWPE_LOGIC_ERROR("");
			//	前の文字が範囲に使用できず、設定されていない場合は文法エラーである。
			if (!siRangeTemp.SetHyphen(cp1))
			{
				THROWPE_SYNTAX_ERROR("hyphen");
				return false;
			}
			pciPattern->Next();
		}
		//--------------------------------------------------
		//	(2)	\ の場合
		//--------------------------------------------------
		else if (tok1 == PREGEX_TOKEN_ESCAPE)
		{
			//	次の文字に進め、その文字を取得しておく。
			pciPattern->Next();
			if (pciPattern->End())
			{
				THROWPE_SYNTAX_ERROR("No ].");
				return false;
			}
			if (!PCTEXT_GETVALIDCP(pciPattern->GetCurrentCp(&cp1)))
			{
				THROWPE_SYNTAX_ERROR("No character.");
				return false;
			}

			//----------------------------------------
			//	(2-1)	\w、\W、\d、\D、\s、\S の場合
			//	文字クラスのインデックスを登録する。
			//----------------------------------------
			if (BEMatchCp(cp1, TQ_UCP('w'), dwCSFlagsC, NULL))
			{
				RegisterPOSIXCharClass(PTEXTEX_CHARCLASS_POSIX_WORD);
				pciPattern->Next();
			}
			else if (BEMatchCp(cp1, TQ_UCP('d'), dwCSFlagsC, NULL))
			{
				RegisterPOSIXCharClass(PTEXTEX_CHARCLASS_POSIX_DIGIT);
				pciPattern->Next();
			}
			else if (BEMatchCp(cp1, TQ_UCP('s'), dwCSFlagsC, NULL))
			{
				RegisterPOSIXCharClass(PTEXTEX_CHARCLASS_POSIX_SPACE);
				pciPattern->Next();
			}
			else if (BEMatchCp(cp1, TQ_UCP('W'), dwCSFlagsC, NULL))
			{
				RegisterPOSIXCharClass(PTEXTEX_CHARCLASS_POSIX_NONWORD);
				pciPattern->Next();
			}
			else if (BEMatchCp(cp1, TQ_UCP('D'), dwCSFlagsC, NULL))
			{
				RegisterPOSIXCharClass(PTEXTEX_CHARCLASS_POSIX_NONDIGIT);
				pciPattern->Next();
			}
			else if (BEMatchCp(cp1, TQ_UCP('S'), dwCSFlagsC, NULL))
			{
				RegisterPOSIXCharClass(PTEXTEX_CHARCLASS_POSIX_NONSPACE);
				pciPattern->Next();
			}
			//----------------------------------------
			//	(2-2)	\p{ }、\P{ } の場合
			//----------------------------------------
			else if (BEMatchCp(cp1, TQ_UCP('p'), dwCSFlagsIC, NULL))
			{
				if (!ParseUnicodePropertyMatching(&iProperty, pciPattern, dwCSFlagsIC, pszLocale))
				{
					THROWPE_SYNTAX_ERROR("Invalid unicode property.");
				}

				//	\P の場合は Negative を示すフラグをセットする。
				if (BEMatchCp(cp1, TQ_UCP('P'), dwCSFlagsC, NULL))
					SET_PTEXTEX_UNICODE_PROPERTY_NEGATIVE(iProperty);

				RegisterUnicodeProperty(iProperty);
				//	ParseUnicodePropertyMatching 終了後は } の次の文字を指している。
			}
			//----------------------------------------
			//	(2-3)	文字クラスではない場合、\ の次の文字を登録する。
			//----------------------------------------
			else
			{
				//	[] 内の \b は BS とみなすので、\ の次の文字を 0x08 にしておく。
				if (BEMatchCp(cp1, TQ_UCP('b'), dwCSFlagsIC, NULL))
				{
					cp1	= (T_UCP)0x0008;
				}
				//	以上に当てはまらない場合は、\ の次の文字をそのまま登録する。
				else
				{
				}
				tok1 = pciPattern->GetCurrentToken();
				tok2 = pciPattern->GetNextToken();
				goto NORMAL_CHARACTER;
			}
		}
		//--------------------------------------------------
		//	(3)	[ の場合
		//--------------------------------------------------
		else if (tok1 == PREGEX_TOKEN_LBRACKET)
		{
			//----------------------------------------
			//	(3-1)	[. .]
			//	[. .] は collating element（照合順序の要素）を表す。
			//	この場合、囲まれている文字列を UCPSTRING に格納し、
			//	一文字として扱えるようにする。
			//----------------------------------------
			if (tok2 == PREGEX_TOKEN_PERIOD)
			{
				//------------------------------
				//	[. の次にポインタを進め、.] を探す。
				//------------------------------

				//	終端に達している場合は PREGEX_TOKEN_END が設定される。

				pciPattern->Next();
				pciPattern->Next();
				tok1	= pciPattern->GetCurrentToken();
				tok2	= pciPattern->GetNextToken();

				if (tok2 == PREGEX_TOKEN_END || tok2 == PREGEX_TOKEN_ERROR)
				{
					THROWPE_SYNTAX_ERROR("Not found .].");
					return false;
				}

				//	[. の直後に .] がある場合は文法エラーとする。

				if (tok1 == PREGEX_TOKEN_PERIOD && tok2 == PREGEX_TOKEN_RBRACKET)
				{
					THROWPE_SYNTAX_ERROR("No collating element in [..].");
					return false;
				}

				//	そうでない場合は .] の位置を求め、[. .] 間のコード列を登録する。

				if (!pciPattern->GetCurrentPos(itr1))	THROWPE_LOGIC_ERROR("");
				pciPattern->Next();

				//	.] を探す。
				while ((tok1 = pciPattern->GetNextToken()) != PREGEX_TOKEN_END)
				{
					if (!pciPattern->MoveTo(PREGEX_TOKEN_PERIOD))
					{
						THROWPE_SYNTAX_ERROR("Not found .].");
						return false;
					}
					if (pciPattern->GetNextToken() == PREGEX_TOKEN_RBRACKET)	break;
					pciPattern->Next();
				}
				//	.] が見つからなかった場合は例外をスローする。
				if (tok1 == PREGEX_TOKEN_END)
				{
					THROWPE_SYNTAX_ERROR("Not found .].");
					return false;
				}

				//------------------------------
				//	.] が見つからなかった場合は例外がスローされるのここに来ることはない。
				//	この時点で Current が . Next が ] である。
				//	[..] 間のコード列を UCPSTRING に格納し、処理する。
				//	UCPSTRING の処理は siRangeTemp が行う。
				//	.] の次の文字に移動させておく。
				//------------------------------
				if (!pciPattern->GetCurrentPos(itr2))	THROWPE_LOGIC_ERROR("");
				if ((pciParentBE->GetBase())->Options()->IsCollateNormalize())
				{
					if (!pciPattern->GetSubString(&ucsTemp, itr1, itr2))
						THROWPE_RUNTIME_ERROR("Create Collating Element");
					if (!CreateUCPString(&pucStr))
						THROWPE_RUNTIME_ERROR("Create Collating Element");
					if (!PLib::Unicode::GetDecomposition(pucStr, &ucsTemp))
						THROWPE_RUNTIME_ERROR("Create Collating Element");
				}
				else
				{
					if (!CreateUCPString(&pucStr, itr1, itr2, pciPattern))
						THROWPE_RUNTIME_ERROR("Create Collating Element");
				}
				siRangeTemp.SetTemp((LPVOID)pucStr, PREGEX_BE_ELEMENT_COLLATING_ELEMENT);
				pciParentBE->SetMaxColl(pucStr->size());
				pciPattern->Next();
				pciPattern->Next();
			}
			//----------------------------------------
			//	(3-2)	[= =]
			//	[= =] は equivalent class を表す。
			//	この場合も、囲まれている文字列を UCPSTRING に格納し、ciEquivClass に登録する。
			//----------------------------------------
			else if (tok2 == PREGEX_TOKEN_EQUAL)
			{
				//	範囲指定の両端に使用することはできない。
				//	ここでの場合、範囲終端の位置にあるなら文法エラーとする。
				if (siRangeTemp.LastPos())
				{
					THROWPE_SYNTAX_ERROR("Cannot use [= =].");
					return false;
				}

				//	[= の次にポインタを進め、=] を探す。
				pciPattern->Next();
				pciPattern->Next();
				tok1	= pciPattern->GetCurrentToken();
				tok2	= pciPattern->GetNextToken();
				if (tok2 == PREGEX_TOKEN_END || tok2 == PREGEX_TOKEN_ERROR)
				{
					THROWPE_SYNTAX_ERROR("Not found =].");
					return false;
				}

				//------------------------------
				//	[= の直後に =] がある場合は文法エラーとする。
				//------------------------------
				if (tok1 == PREGEX_TOKEN_EQUAL && tok2 == PREGEX_TOKEN_RBRACKET)
				{
					THROWPE_SYNTAX_ERROR("No equivalent class in [==].");
					return false;
				}

				//------------------------------
				//	そうでない場合は =] の位置を求め、
				//	[= =] 間のコード列を登録する。
				//------------------------------
				if (!pciPattern->GetCurrentPos(itr1))	THROWPE_LOGIC_ERROR("");
				pciPattern->Next();

				//	=] を探す。
				while ((tok1 = pciPattern->GetNextToken()) != PREGEX_TOKEN_END)
				{
					if (!pciPattern->MoveTo(PREGEX_TOKEN_EQUAL))
					{
						THROWPE_SYNTAX_ERROR("Not found =].");
						return false;
					}
					if (pciPattern->GetNextToken() == PREGEX_TOKEN_RBRACKET)	break;
					pciPattern->Next();
				}
				//	=] が見つからなかった場合は例外をスローする。
				if (tok1 == PREGEX_TOKEN_END)
				{
					THROWPE_SYNTAX_ERROR("Not found =].");
					return false;
				}

				//------------------------------
				//	=] が見つからなかった場合は例外がスローされるのここに来ることはない。
				//	この時点で Current が = Next が ] である。
				//	[= =] 間のコード列を UCPSTRING に格納する。
				//------------------------------
				if (!pciPattern->GetCurrentPos(itr2))	THROWPE_LOGIC_ERROR("");
				if (!CreateUCPString(&pucStr, itr1, itr2, pciPattern))	THROWPE_RUNTIME_ERROR("Create Equivalent Class");

				//------------------------------
				//	UCPSTRING を登録する。
				//------------------------------
				pciPattern->Next();
				pciPattern->Next();
				//	Current は =] の次の文字。
				siRangeTemp.Flush();
				RegisterEquivalenceClass(pucStr);
			}
			//----------------------------------------
			//	(3-3)	[: :]
			//	[: :] は character class を表す。
			//	クラス名が適切ならクラスのインデックスを登録する。
			//----------------------------------------
			else if (tok2 == PREGEX_TOKEN_COLON)
			{
				//	範囲指定の両端で使用することはできないので、
				//	範囲指定中の場合、範囲を解除し文字として登録する。
				if (siRangeTemp.LastPos())
				{
					THROWPE_SYNTAX_ERROR("Cannot use [: :].");
					return false;
				}

				//	[: の次にポインタを進める。現在は [
				pciPattern->Next();
				pciPattern->Next();
				tok1	= pciPattern->GetCurrentToken();
				tok2	= pciPattern->GetNextToken();
				if (tok2 == PREGEX_TOKEN_END || tok2 == PREGEX_TOKEN_ERROR)
				{
					THROWPE_SYNTAX_ERROR("Not found :].");
					return false;
				}

				//------------------------------
				//	[: の直後に :] がある場合は文法エラーとする。
				//------------------------------
				if (tok1 == PREGEX_TOKEN_COLON && tok2 == PREGEX_TOKEN_RBRACKET)
				{
					THROWPE_SYNTAX_ERROR("No character class in [::].");
					return false;
				}

				//------------------------------
				//	そうでない場合は :] を探し、
				//	[: :] 間のコード列を登録する。
				//------------------------------
				if (!pciPattern->GetCurrentPos(itr1))	THROWPE_LOGIC_ERROR("");	//	charcter class 名の開始点

				while (!pciPattern->End())
				{
					if (!pciPattern->MoveTo(PREGEX_TOKEN_COLON))
					{
						THROWPE_SYNTAX_ERROR("Not found :].");
						return false;
					}
					if (pciPattern->GetNextToken() == PREGEX_TOKEN_RBRACKET)	break;
					pciPattern->Next();
				}
				if (pciPattern->End())
				{
					THROWPE_SYNTAX_ERROR("Not found :].");
					return false;
				}

				if (!pciPattern->GetCurrentPos(itr2))	THROWPE_LOGIC_ERROR("");	//	charcter class 名の終端

				//	:] の次の文字に進める。
				pciPattern->Next();
				pciPattern->Next();

				//------------------------------
				//	character class として適切なら登録する。
				//------------------------------
				ucsTemp.clear();
				pciPattern->GetSubString(&ucsTemp, itr1, itr2);
				iCharClass	= PLib::GetPosixCharClassId(&ucsTemp);
				if (iCharClass <= 0)
				{
					THROWPE_SYNTAX_ERROR("Invalid character class name.");
					return false;
				}
				siRangeTemp.Flush();
				RegisterPOSIXCharClass(iCharClass);
			}
			//----------------------------------------
			//	以上に当てはまらない場合、[ は部分ブラケット表現の開始とみなす。
			//----------------------------------------
			else
			{
				pciPattern->Next();
				pBracketEx	= ciAllocBracketEx.Allocate();
				pBracketEx->SetBase(pciParentBE->GetBase());
				pBracketEx->Parse(pciPattern);
				RegisterSubBracketEx(pBracketEx);
			}
		}
		//--------------------------------------------------
		//	(4)	||、&&、--、~~ の場合
		//--------------------------------------------------
		else if (	(tok1 == tok2) &&
					(	tok1 == PREGEX_TOKEN_VERTICALBAR	||
						tok1 == PREGEX_TOKEN_AMPERSAND		||
						tok1 == PREGEX_TOKEN_HYPHEN			||
						tok1 == PREGEX_TOKEN_TILDE			)
						)
		{
			break;
		}
		//--------------------------------------------------
		//	(5)	それ以外の場合は通常の文字として扱う。
		//--------------------------------------------------
		else
		{
			if (!PCTEXT_GETVALIDCP(pciPattern->GetCurrentCp(&cp1)))
			{
				THROWPE_SYNTAX_ERROR("No character in Bracket Expression.");
				return false;
			}

NORMAL_CHARACTER:
			siRangeTemp.SetTemp((LPVOID)cp1, PREGEX_BE_ELEMENT_CODEPAGE);
			pciPattern->Next();
		}

		//--------------------------------------------------
		//	すべての場合でのループ内終了処理
		//	current は次の文字を指していなければならない。
		//--------------------------------------------------
		//	範囲指定が完了している場合は登録する。
		if (siRangeTemp.Completed())
		{
			siRangeTemp.Register();
		}

		tok1 = pciPattern->GetCurrentToken();
		tok2 = pciPattern->GetNextToken();
	}
	//------------------------------------------------------------
	//	ループはここまで。以下は終了処理。
	//------------------------------------------------------------

	//	]、|、&、-、~ でない場合はエラー。
	if (	tok1 != PREGEX_TOKEN_RBRACKET		&&
			tok1 != PREGEX_TOKEN_VERTICALBAR	&&
			tok1 != PREGEX_TOKEN_AMPERSAND		&&
			tok1 != PREGEX_TOKEN_HYPHEN			&&
			tok1 != PREGEX_TOKEN_TILDE	)
	{
		THROWPE_SYNTAX_ERROR("PCBracketEx::Parse");
	}

	//	範囲指定データを登録する。
	//	Flush() は、不適切な状態の場合なら例外をスローする。
	siRangeTemp.Flush();
	return true;
}

//----------------------------------------------------------------------
//	PCBETerm::Match
//----------------------------------------------------------------------
bool CLASS_PREGEX_BETERM::Match(T_UCP			cpSrc,
								const T_UCP*	pszColl,
								DWORD			dwFlags,
								DWORD			dwFlagsColl,
								bool			bICase,
								T_PCSTR_U		pszLocale,
								bool			bMultiCp)
{
	ITR_CPSET			itr_cp;
	ITR_RANGELIST		itr_cr;
	ITR_COLLLIST		itr_cl;
	ITR_EQUIVLIST		itr_ec;
	ITR_CCLASSSET		itr_cc;
	ITR_UPROPSET		itr_up;
	ITR_BRACKETEXLIST	itr_be;

	//------------------------------------------------------------
	//	7-bit Character
	//------------------------------------------------------------
	if (!bMultiCp && IS_7BIT(cpSrc))
	{
		if (bICase)
		{
			if (ciAsciiBitsIC.test(cpSrc))	return true;
		}
		else
		{
			if (ciAsciiBits.test(cpSrc))	return true;
		}
	}

	//	以下は PLib::Unicode::CompareStringUCD 関数を使って比較する。

	//------------------------------------------------------------
	//	Codepage
	//------------------------------------------------------------
	if (!bMultiCp && !ciCpSet.empty())
	{
		for (itr_cp = ciCpSet.begin(); itr_cp != ciCpSet.end(); ++itr_cp)
		{
			if (PLib::Unicode::CompareCodepointUCD(*itr_cp, cpSrc, dwFlags, pszLocale) == CSTR_EQUAL)
			{
				return true;
			}
		}
	}

	//------------------------------------------------------------
	//	Range
	//------------------------------------------------------------
	if (!bMultiCp && !ciRangeList.empty())
	{
		for (itr_cr = ciRangeList.begin(); itr_cr != ciRangeList.end(); ++itr_cr)
		{
			if ((*itr_cr)->Match(cpSrc, dwFlags, dwFlagsColl, pszLocale))	return true;
		}
	}

	//------------------------------------------------------------
	//	Collating Element
	//------------------------------------------------------------
	if (!ciCollList.empty())
	{
		for (itr_cl = ciCollList.begin(); itr_cl != ciCollList.end(); ++itr_cl)
		{
			if (PLib::Unicode::CompareConvertedStringUCD(
				(*itr_cl)->c_str(), -1, pszColl, -1, dwFlagsColl, pszLocale) == CSTR_EQUAL)
			{
				return true;
			}
		}
	}

	//------------------------------------------------------------
	//	Equivalence Class
	//------------------------------------------------------------
	if (ciEquivList.size() > 0)
	{
		for (itr_ec = ciEquivList.begin(); itr_ec != ciEquivList.end(); ++itr_ec)
		{
			if (PLib::Unicode::CompareStringUCD(
				(*itr_ec)->c_str(), -1, pszColl, -1, dwFlagsColl, pszLocale) == CSTR_EQUAL)
			{
				return true;
			}
		}
	}

	//------------------------------------------------------------
	//	Character Class
	//------------------------------------------------------------
	if (!bMultiCp && ciPOSIXCClasses.size() > 0)
	{
		for (itr_cc = ciPOSIXCClasses.begin(); itr_cc != ciPOSIXCClasses.end(); ++itr_cc)
		{
			switch (*itr_cc)
			{
			case PTEXTEX_CHARCLASS_POSIX_WORD:
				if (PLib::Unicode::IsWord_GC(cpSrc))	return true;
				break;

			case PTEXTEX_CHARCLASS_POSIX_NONWORD:
				if (!PLib::Unicode::IsWord_GC(cpSrc))	return true;
				break;

			default:
				if (PLib::MatchPOSIXCharClass(cpSrc, *itr_cc, dwFlags, pszLocale))	return true;
				break;
			}
		}
	}

	//------------------------------------------------------------
	//	Unicode Property
	//------------------------------------------------------------
	if (!bMultiCp && ciUProperties.size() > 0)
	{
		for (itr_up = ciUProperties.begin(); itr_up != ciUProperties.end(); ++itr_up)
		{
			if (MatchUnicodeProperty(*itr_up, cpSrc))	return true;
		}
	}

	//------------------------------------------------------------
	//	SubBracketEx
	//------------------------------------------------------------
	if (ciSubBracketEx.size() > 0)
	{
		for (itr_be = ciSubBracketEx.begin(); itr_be != ciSubBracketEx.end(); ++itr_be)
		{
			if ((*itr_be)->Match(cpSrc, pszColl, dwFlags, dwFlagsColl, bICase, pszLocale, bMultiCp))
				return true;
		}
	}

	return false;
}


//======================================================================
//	class PCBracketEx
//
//	Bracket Expression を解析し、マッチしているかを調べるためのクラス。
//======================================================================
//----------------------------------------------------------------------
//	PCBracketEx	コンストラクタ
//----------------------------------------------------------------------
CLASS_PREGEX_BRACKETEX::PCBracketEx()
:	pciBaseRegEx(NULL),
	bAffirmative(true),
	zMaxColl(1),
	bPermitMultiCp(false)
{
}

//----------------------------------------------------------------------
//	PCBracketEx	デストラクタ
//----------------------------------------------------------------------
CLASS_PREGEX_BRACKETEX::~PCBracketEx()
{
	Clear();
}

//----------------------------------------------------------------------
//	PCBracketEx::Clear
//----------------------------------------------------------------------
void CLASS_PREGEX_BRACKETEX::Clear()
{
	ITR_BETERMLIST	itr_be;

	for (itr_be = ciBETermList.begin(); itr_be != ciBETermList.end(); ++itr_be)
	{
		ciAllocBETerm.Deallocate(*itr_be);
	}
	ciBETermList.clear();

	bAffirmative			= true;
	bPermitMultiCp	= false;
}

//----------------------------------------------------------------------
//	PCBracketEx::Init
//----------------------------------------------------------------------
void CLASS_PREGEX_BRACKETEX::Init()
{
	Clear();
}

//----------------------------------------------------------------------
//	PCBracketEx::AllocateBETerm
//----------------------------------------------------------------------
PCBETerm* CLASS_PREGEX_BRACKETEX::AllocateBETerm()
{
	PCBETerm*	pt;

	pt	= ciAllocBETerm.Allocate();
	pt->SetParent(this);
	ciBETermList.push_back(pt);
	return pt;
}

//----------------------------------------------------------------------
//	PCBracketEx::Parse
//----------------------------------------------------------------------
bool CLASS_PREGEX_BRACKETEX::Parse(CPATTERN* pciPattern)
{
	DWORD		dwCSFlags	= 0;	//	| NORM_IGNORECASE;
	T_PCSTR_U	pszLocale	= NULL;
	PCBETerm*	pBETerm;
	int			it1, it2;

	if (pciBaseRegEx == NULL)
	{
		THROWPE_LOGIC_ERROR("PCBracketEx::Parse");
	}
	dwCSFlags	= (pciBaseRegEx->Options())->GetCompareStringUCDFlags();
	pszLocale	= (pciBaseRegEx->Options())->GetLocaleString();

	Init();

	//------------------------------------------------------------
	//	1 番目の BETerm
	//------------------------------------------------------------
	//	ブラケット表現開始の [ なら、一文字進めておく。
	//	前の文字も [ の場合（[[ の後の文字の場合）はそのまま。
	if (pciPattern->GetPreviousToken() != PREGEX_TOKEN_LBRACKET &&
		pciPattern->GetCurrentToken() == PREGEX_TOKEN_LBRACKET)
	{
		if (!(pciPattern->Next()))	return false;
	}

	//	先頭にある場合に異なる解釈が必要な文字がある。
	//	[ の直後に ^ がある場合
	if (pciPattern->GetCurrentToken() == PREGEX_TOKEN_CIRCUMFLEX)
	{
		bAffirmative	= false;
		pciPattern->Next();
	}
	else
	{
		bAffirmative	= true;
	}

	pBETerm	= AllocateBETerm();
	pBETerm->Parse(pciPattern);
	if (pBETerm->PermitMultichar())	bPermitMultiCp = true;

	//------------------------------------------------------------
	//	2 番目以降の BETerm
	//------------------------------------------------------------
	while (true)
	{
		it1	= pciPattern->GetCurrentToken();
		if (it1 == PREGEX_TOKEN_RBRACKET)	break;

		it2	= pciPattern->GetNextToken();
		if (it1 != it2)
		{
			THROWPE_LOGIC_ERROR("");
			return false;
		}

		pBETerm	= AllocateBETerm();
		switch (it1)
		{
		case PREGEX_TOKEN_VERTICALBAR:
			pBETerm->SetType(PREGEX_BE_TYPE_OPERATION_UNION);
			break;

		case PREGEX_TOKEN_AMPERSAND:
			pBETerm->SetType(PREGEX_BE_TYPE_OPERATION_INTERSECTION);
			break;

		case PREGEX_TOKEN_HYPHEN:
			pBETerm->SetType(PREGEX_BE_TYPE_OPERATION_DIFFERENCE);
			break;

		case PREGEX_TOKEN_TILDE:
			pBETerm->SetType(PREGEX_BE_TYPE_OPERATION_SYMMETRIC_DIFFERENCE);
			break;

		default:
			THROWPE_SYNTAX_ERROR("");
			return false;
			break;
		}
		pciPattern->Next();
		pciPattern->Next();
		pBETerm->Parse(pciPattern);
		if (pBETerm->PermitMultichar())	bPermitMultiCp = true;
	}
	//	] の次の文字に移動させておく。
	pciPattern->Next();
	return true;
}

//----------------------------------------------------------------------
//	PCBracketEx::Match	(1)
//----------------------------------------------------------------------
bool CLASS_PREGEX_BRACKETEX::Match(T_UCP		cpSrc,
								   const T_UCP*	pszColl,
								   DWORD		dwFlags,
								   DWORD		dwFlagsColl,
								   bool			bICase,
								   T_PCSTR_U	pszLocale,
								   bool			bMultiCp)
{
	ITR_BETERMLIST	itr_tm;
	bool			br, br1;

	if (ciBETermList.empty())
	{
		THROWPE_LOGIC_ERROR("BracketEx is empty.");
	}

	//------------------------------------------------------------
	//	1 番目の BETerm
	//------------------------------------------------------------
	itr_tm	= ciBETermList.begin();
	br	= (*itr_tm)->Match(cpSrc, pszColl, dwFlags, dwFlagsColl, bICase, pszLocale, bMultiCp);

	//------------------------------------------------------------
	//	2 番目以降の BETerm はクラスの演算として処理する。
	//------------------------------------------------------------
	for (++itr_tm; itr_tm != ciBETermList.end(); ++itr_tm)
	{
		br1	= (*itr_tm)->Match(cpSrc, pszColl, dwFlags, dwFlagsColl, bICase, pszLocale, bMultiCp);
		switch ((*itr_tm)->GetType())
		{
		case PREGEX_BE_TYPE_NORMAL:
		case PREGEX_BE_TYPE_OPERATION_UNION:
			br	= ((br == true) || (br1 == true));
			break;

		case PREGEX_BE_TYPE_OPERATION_INTERSECTION:
			br	= ((br == true) && (br1 == true));
			break;

		case PREGEX_BE_TYPE_OPERATION_DIFFERENCE:
			br	= ((br == true) && (br1 == false));
			break;

		case PREGEX_BE_TYPE_OPERATION_SYMMETRIC_DIFFERENCE:
			br	= (((br == true) && (br1 == false)) || ((br == false) && (br1 == true)));
			break;

		default:
			THROWPE_LOGIC_ERROR("PCBracketEx::Match");
			break;
		}
	}
	return (bAffirmative == br);
}

//----------------------------------------------------------------------
//	PCBracketEx::Match	(2)
//----------------------------------------------------------------------
bool CLASS_PREGEX_BRACKETEX::Match(CRETEXT* pciText)
{
	T_UCP			cps, cpc;
	UCPSTRING		ucsBuf1, ucsBuf2;
	const T_UCP*	pColl;
	size_t			zColl;
	//int				i;

	DWORD		dwFlags;
	DWORD		dwFlagsColl;
	bool		bICase;
	T_PCSTR_U	pszLocale;
	bool		bMultiCp	= false;

	dwFlags		= pciText->Options()->GetCompareStringUCDFlags();
	pszLocale	= pciText->Options()->GetLocaleString();
	bICase		= pciText->Options()->IsIgnoreCase();
	
	if (GetBase()->Options()->IsCollateNormalize())
	{
		dwFlagsColl	= (dwFlags | CSTRUCD_NORMALIZE);
	}
	else
	{
		dwFlagsColl	= dwFlags;
	}

	if (!PCTEXT_GETVALIDCP(pciText->GetCurrentCp(&cps)))	return false;

	pciText->PushNewIterator();
	ucsBuf1.clear();
	while (!pciText->End())
	{
		if (bPermitMultiCp)
		{
			if (!PCTEXT_GETVALIDCP(pciText->GetCurrentCp(&cpc)))	break;
			ucsBuf1.append(1, cpc);
			if (GetBase()->Options()->IsCollateNormalize())
			{
				ucsBuf2.clear();
				//if (!PLib::Unicode::GetDecomposition(&ucsBuf2, &ucsBuf1))
				if (!PLib::Unicode::StrFoldingUCD(&ucsBuf2, &ucsBuf1, dwFlagsColl, pszLocale))
					THROWPE_RUNTIME_ERROR("");
				pColl	= ucsBuf2.c_str();
				zColl	= ucsBuf2.size();
			}
			else
			{
				pColl	= ucsBuf1.c_str();
				zColl	= ucsBuf1.size();
			}
		}
		else
		{
			pColl	= NULL;
			zColl	= 0;
		}

		if (zColl > zMaxColl)	break;
		if (Match(cps, pColl, dwFlags, dwFlagsColl, bICase, pszLocale, bMultiCp))
		{
			pciText->PopAndUpdateIterator();
			pciText->Next();
			return true;
		}
		if (!bPermitMultiCp)	break;
		pciText->Next();
		bMultiCp	= true;
	}
	pciText->PopIterator();
	return false;
}

NS_PLIB_END
