//	XLCTextEx_1.0x	:	PLibUCD

//	PLibUCD:	PLibUCD.cpp
//
#include "stdafx.h"

NS_PLIB_UNICODE_BEGIN

//======================================================================
//	NormalizeName
//	名前の空白、-、_ を取り除き、すべての文字を大文字に変換する。
//	バッファが足りない（終端の NULL も含めて）場合は FALSE を返す。
//======================================================================
static T_UCP	NNElimination[]	=
{
	0x0022,
	0x002D,
	0x005F,
	0xFE33,
	0xFE34,
	0xFE4D,
	0xFE4E,
	0xFE4F,
	0xFE63,
	0xFF02,
	0xFF0D,
	0xFF3F,
};
static UINT	nNNElimination	= sizeof(NNElimination) / sizeof(T_UCP);

//bool	NormalizeName(LPWSTR pBuf, size_t zBuf, LPCWSTR pName, LPCWSTR pEnd);
//bool	NormalizeName(T_UCP* pBuf, size_t zBuf, const T_UCP* pName, const T_UCP* pEnd);

bool NormalizeName(UCPSTRING* pucsBuf, const T_UCP* pName, const T_UCP* pEnd)
{
	const T_UCP*	pc;
	UINT			ui;
	T_UCP*			pcp;
	int				ncp;

	for (pc = pName; pc < pEnd; ++pc)
	{
		if (PLib::t_IsSpace<T_UCP>(*pc))	continue;
		if (PLib::SearchNumSet<T_UCP>(&ui, NNElimination, nNNElimination, *pc))	continue;
		if (PLib::Unicode::CaseFoldingSimple(&pcp, &ncp, *pc))
		{
			pucsBuf->append(pcp, (size_t)ncp);
		}
		else
		{
			pucsBuf->append(1, *pc);
		}
	}
	return true;
}

/*
BOOL NormalizeName(T_CHAR* pBuf, size_t zBuf, const T_CHAR* pName, const T_CHAR* pEnd)
{
	typedef	T_CHAR*			T_PSTR;
	typedef	const T_CHAR*	T_PCSTR;

	T_PSTR			pdc, pde;
	const T_CHAR	cHyphen		= TQU('-');
	const T_CHAR	cUnderscore	= TQU('_');
	const T_CHAR	cDQuote		= TQU('"');

	if (pBuf == NULL || zBuf < 1 || pName == NULL || pEnd <= pName)	return FALSE;
	if ((size_t)(pEnd - pName) >= zBuf)	return FALSE;
	pdc	= pBuf;
	pde	= pBuf + zBuf;

	while (pName < pEnd)
	{
		if (!ISSPACE_U(*pName) && *pName != cHyphen &&
			*pName != cUnderscore && *pName != cDQuote)
		{
			*pdc	= *pName;
			++pdc;
		}
		++pName;
	}
	*pdc	= NULL;
	CHARUPPER_U(pBuf);
	return TRUE;
}
*/

//======================================================================
//	PSPropertyValueIdMap::Compare
//======================================================================
int PSPropertyValueIdMap::Compare(UCPSTRING *pucsOther)
{
	UCPSTRING		ucsAlNum, ucsFold;
	const T_UCP*	pc;
	DWORD			dwFlags	= (NORM_IGNORECASE | NORM_IGNORENONSPACE | NORM_IGNOREWIDTH);
	int				ir;

	for (pc = pucsOther->c_str(); *pc; ++pc)
	{
		if (PLib::Unicode::IsAlNum_GC(*pc))	ucsAlNum.append(1, *pc);
	}
	if (!PLib::Unicode::StrFoldingUCD(&ucsFold, &ucsAlNum, dwFlags, NULL))	return 0;
	ir	= ucsFold.compare(pcpKey);
	if (ir < 0)			return CSTR_GREATER_THAN;	//	pcpKey の方が大きい。
	else if (ir > 0)	return CSTR_LESS_THAN;		//	pcpKey の方が小さい。
	return CSTR_EQUAL;
}

//======================================================================
//	GetPropertyValue	(1)
//	属性名から属性 ID を取得する。
//======================================================================
bool GetPropertyValueByName(int*			pid,
							PSPSzIdMap*		pMaps,
							int				nMaps,
							const T_UCP*	pNameB,
							const T_UCP*	pNameE)
{
	size_t			zIndex;
	const size_t	zBuf	= 64;
	UCPSTRING		ucsBuf;
	T_STRING_U		strBuf;

	if (!PLib::Unicode::NormalizeName(&ucsBuf, pNameB, pNameE))	return false;
	if (!PLib::Unicode::ConvertFromCodepoint(&strBuf, &ucsBuf))	return false;
	if (PLib::BinarySearch<PSPSzIdMap, T_PCSTR_U>(&zIndex, pMaps, nMaps, strBuf.c_str()))
	{
		*pid	= pMaps[zIndex].Data;
		return true;
	}
	return false;
}

//======================================================================
//	GetPropertyValue	(2-1)
//	Codepoint からその文字の属性 ID を取得する。
//======================================================================
bool GetPropertyValue(int* pid, PSCpIdMap* pMaps, int nMaps, UINT uiCodepoint)
{
	UINT	uiIndex;

	if (PLib::BinarySearch<PSCpIdMap, UINT>(&uiIndex, pMaps, nMaps, uiCodepoint))
	{
		*pid	= pMaps[uiIndex].Data;
		return true;
	}
	return false;
}

//======================================================================
//	GetPropertyValue	(2-2)
//	文字列中の指定した位置にある文字の属性 ID を取得する。
//======================================================================
bool GetPropertyValue(int* pid, PSCpIdMap* pMaps, int nMaps, LPCWSTR pStr, LPCWSTR pEnd)
{
	LPCWSTR pt	= pStr;
	UINT	uiCodepoint;

	if (PLib::Unicode::ConvertToCodepoint(&uiCodepoint, &pt, pEnd))
	{
		return GetPropertyValue(pid, pMaps, nMaps, uiCodepoint);
	}
	return false;
}

//======================================================================
//	GetPropertyName
//======================================================================
T_PCSTR_U GetPropertyName(PSIdPSzMap* pMaps, int nMaps, int iId)
{
	UINT	uiIndex;

	if (PLib::BinarySearch<PSIdPSzMap, int>(&uiIndex, pMaps, nMaps, iId))
	{
		return pMaps[uiIndex].Data;
	}
	return NULL;
}

//======================================================================
//	GetBooleanValueByStr
//	"TRUE"、"T"、"YES"、"Y" なら true、
//	"FALSE"、"F"、"NO"、"N" なら false、
//======================================================================
typedef	PSSearchPSzKeyBufArg<bool, (NORM_IGNORECASE | NORM_IGNOREWIDTH), NULL>	TSEARCH_GETBOOLEANVALUEBYSTR;
static TSEARCH_GETBOOLEANVALUEBYSTR
BooleanValueMap[]	=
{
	TQU("f"),		false,
	TQU("false"),	false,
	TQU("n"),		false,
	TQU("no"),		false,
	TQU("t"),		true,
	TQU("true"),	true,
	TQU("y"),		true,
	TQU("yes"),		true,
};
static UINT	nBooleanValueMap	= sizeof(BooleanValueMap) / sizeof(TSEARCH_GETBOOLEANVALUEBYSTR);

bool GetBooleanValueByStr(bool* pb, const T_UCP* pszName)
{
	PLib::Unicode::PCCodepointSzBuffer	ciCpzBuf;
	UINT	uif;

	ciCpzBuf.Set(pszName);
	if (PLib::BinarySearch<TSEARCH_GETBOOLEANVALUEBYSTR,PIFUnicodeBuffer*>(
		&uif, BooleanValueMap, nBooleanValueMap, &ciCpzBuf))
	{
		*pb	= BooleanValueMap[uif].Data;
		return true;
	}
	return false;
}

NS_PLIB_UNICODE_END


//======================================================================
//	初期化と終了処理
//======================================================================
NS_PLIB_UCD_BEGIN

BOOL Init()
{
	BOOL	br	= TRUE;

	//if (!InitCaseFolding())		br = FALSE;
	return br;
}

void Cleanup()
{
	//CleanupCaseFolding();
}

NS_PLIB_UCD_END
