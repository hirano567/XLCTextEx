//	XLCTextEx_1.0x	:	PLibUCD

//	PUCDUtility.h
//
#pragma once

NS_PLIB_UNICODE_BEGIN

//======================================================================
//	UCPString 比較用のクラス
//======================================================================
template<DWORD CSTRFLAGS>
class PCCompareUCPString
{
public:
	bool operator()(UCPSTRING* ps1, UCPSTRING* ps2)	const
	{
		return (PLib::Unicode::CompareStringUCD(ps1, ps2, CSTRFLAGS, NULL) == CSTR_LESS_THAN);
	}
};

//======================================================================
//	t_CharToInt_base
//	引数チェックは呼び出し側で行っておくこと。
//======================================================================
//----------------------------------------------------------------------
//	t_CharToInt_base	(1)
//----------------------------------------------------------------------
template<int A_CONV[128], bool B_NORMALIZE>
bool t_CharToInt_base(int* piNum, UINT uiCp)
{
	UINT	uic;
	int		i;
	PLib::Unicode::PSDECOMPOSITION*	pDecmp	= NULL;

	//------------------------------------------------------------
	//	コードが 0 から 128 の場合
	//------------------------------------------------------------
	if (IS_7BIT(uiCp))
	{
		i	= A_CONV[uiCp];
		if (i >= 0)
		{
			*piNum	= i;
			return true;
		}
		return false;
	}

	//------------------------------------------------------------
	//	それ以外の場合、B_NORMALIZE に true が設定されているなら、
	//	コードポイントに変換し、正規化して調べる。
	//------------------------------------------------------------
	if (!B_NORMALIZE)	return false;

	if (PUCD_BMPTABLE_NOT_DECOMP_SET(uiCp))	return false;
	if (PLib::Unicode::GetDecomposition(&pDecmp, uiCp))	return false;

	//	"0" と "点" など複数の文字に分解されるものは、対象外とする。
	if (pDecmp->nDecomposition != 1)	return false;

	//------------------------------------------------------------
	//	正規化した文字が数値を表しているか調べる。
	//------------------------------------------------------------
	uic	= *(pDecmp->pcpDecomposition);
	if (IS_7BIT(uic))
	{
		i	= A_CONV[uic];
		if (i >= 0)
		{
			*piNum	= i;
			return true;
		}
		return false;
	}
	return false;
}

//----------------------------------------------------------------------
//	t_CharToInt_base	(2-1)
//----------------------------------------------------------------------
template<int A_CONV[128], bool B_NORMALIZE>
inline bool t_CharToInt_base(int* piNum, T_PCSTR_U* ppSrcB, T_PCSTR_U pSrcE)
{
	UINT			uic;
	T_PCSTR_U	pc;

	pc	= *ppSrcB;
	if (!PLib::Unicode::ConvertToCodepoint(&uic, &pc, pSrcE))	return false;
	if (t_CharToInt_base<A_CONV, B_NORMALIZE>(piNum, uic))
	{
		*ppSrcB	= pc;
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	t_CharToInt_base	(2-2)
//----------------------------------------------------------------------
template<int A_CONV[128], bool B_NORMALIZE>
inline bool t_CharToInt_base(int* piNum, T_PCSTR_U* ppszSrc)
{
	UINT			uic;
	T_PCSTR_U	pc;

	pc	= *ppszSrc;
	if (!PLib::Unicode::ConvertToCodepoint(&uic, &pc))	return false;
	if (t_CharToInt_base<A_CONV, B_NORMALIZE>(piNum, uic))
	{
		*ppszSrc	= pc;
		return true;
	}
	return false;
}

//======================================================================
//	StrToInt
//======================================================================
//----------------------------------------------------------------------
//	t_StrToInt_base
//
//	I_BASE		基数
//	CONVTABLE	ASCII 文字から数値への変換表
//	T_INT		求める整数の型
//	B_NEGATIVE	最初に - があれば負の値とする。
//	B_NORMALIZE	正規化してから処理する。
//
//	引数のチェックは呼び出し側でしておくこと。
//----------------------------------------------------------------------
template<int I_BASE, int A_CONV[128], typename T_INT, bool B_NEGATIVE, bool B_NORMALIZE>
bool t_StrToInt_base(T_INT* piNum, T_PCSTR_U* ppNext, PIFStrBuffer<T_CHAR_U>* pciBuf, int iMinDigit, int iMaxDigit)
{
	UINT		uic;
	int			i, n, idg;
	T_PCSTR_U	pini;
	bool		bNegative	= false;

	pini	= pciBuf->GetCurrentPos();
	*ppNext	= pini;

	//------------------------------------------------------------
	//	まず 1 文字取り出す。
	//------------------------------------------------------------
	if (!PLib::Unicode::ConvertToCodepoint(&uic, pciBuf))	return false;

	//------------------------------------------------------------
	//	負値も可の場合、- かどうか調べる。- の場合、次の文字を取り出しておく。
	//------------------------------------------------------------
	if (B_NEGATIVE)
	{
		if (uic == (UINT)(L'-'))
		{
			bNegative	= true;
			if (!PLib::Unicode::ConvertToCodepoint(&uic, pciBuf))	return false;
		}
		else if (B_NORMALIZE)
		{
			//	正規化に "-" を含むのは 2 文字だけなので、直接調べる。
			if (uic == (UINT)0xFE63 || uic == (UINT)0xFF0D)
			{
				bNegative	= true;
				if (!PLib::Unicode::ConvertToCodepoint(&uic, pciBuf))	return false;
			}
		}
	}

	//------------------------------------------------------------
	//	文字が数値でない場合は false を返す。
	//------------------------------------------------------------
	if (!t_CharToInt_base<A_CONV, B_NORMALIZE>(&i, uic))	return false;
	n	= i;
	idg	= 1;
	*ppNext	= pciBuf->GetCurrentPos();

	//------------------------------------------------------------
	//	数値が続いていたら取り出す。
	//------------------------------------------------------------
	while (!pciBuf->End())
	{
		if (iMaxDigit > 0 && idg >= iMaxDigit)	break;
		if (!PLib::Unicode::ConvertToCodepoint(&uic, pciBuf))	break;
		if (!t_CharToInt_base<A_CONV, B_NORMALIZE>(&i, uic))	break;
		n	= n * I_BASE + i;
		++idg;
		*ppNext	= pciBuf->GetCurrentPos();
	}

	if (B_NEGATIVE)
	{
		if (bNegative)	n	*= -1;
	}
	if (idg >= iMinDigit)
	{
		*piNum	= (T_INT)n;
		return true;
	}
	*ppNext	= pini;
	return false;
}

//----------------------------------------------------------------------
//	StrToIntDec, StrToIntDecN	(1)
//----------------------------------------------------------------------
template<typename T_INT>
bool StrToIntDec(T_INT* piNum, T_PCSTR_U* ppSrcB, T_PCSTR_U pSrcE, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSegmentBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppSrcB, pSrcE);
	if (bNormalize)
	{
		return t_StrToInt_base<10, PLib::iDecChar, T_INT, false, true>(piNum, ppSrcB, &ciBuf, 0, iMaxDigit);
	}
	return t_StrToInt_base<10, PLib::iDecChar, T_INT, false, false>(piNum, ppSrcB, &ciBuf, 0, iMaxDigit);
}

template<typename T_INT>
bool StrToIntDecN(T_INT* piNum, T_PCSTR_U* ppSrcB, T_PCSTR_U pSrcE, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSegmentBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppSrcB, pSrcE);
	if (bNormalize)
	{
		return t_StrToInt_base<10, PLib::iDecChar, T_INT, true, true>(piNum, ppSrcB, &ciBuf, 0, iMaxDigit);
	}
	return t_StrToInt_base<10, PLib::iDecChar, T_INT, true, false>(piNum, ppSrcB, &ciBuf, 0, iMaxDigit);
}

//----------------------------------------------------------------------
//	StrToIntDec, StrToIntDecN	(2)
//----------------------------------------------------------------------
template<typename T_INT>
bool StrToIntDec(T_INT* piNum, T_PCSTR_U* ppszSrc, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSzBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppszSrc);
	if (bNormalize)
	{
		return t_StrToInt_base<10, PLib::iDecChar, T_INT, false, true>(piNum, ppszSrc, &ciBuf, 0, iMaxDigit);
	}
	return t_StrToInt_base<10, PLib::iDecChar, T_INT, false, false>(piNum, ppszSrc, &ciBuf, 0, iMaxDigit);
}

template<typename T_INT>
bool StrToIntDecN(T_INT* piNum, T_PCSTR_U* ppszSrc, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSzBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppszSrc);
	if (bNormalize)
	{
		return t_StrToInt_base<10, PLib::iDecChar, T_INT, true, true>(piNum, ppszSrc, &ciBuf, 0, iMaxDigit);
	}
	return t_StrToInt_base<10, PLib::iDecChar, T_INT, true, false>(piNum, ppszSrc, &ciBuf, 0, iMaxDigit);
}

//----------------------------------------------------------------------
//	StrToIntHex	(1)
//----------------------------------------------------------------------
template<typename T_INT>
bool StrToIntHex(T_INT* piNum, T_PCSTR_U* ppSrcB, T_PCSTR_U pSrcE, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSegmentBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppSrcB, pSrcE);
	if (bNormalize)
	{
		return t_StrToInt_base<16, PLib::iHexChar, T_INT, false, true>(piNum, ppSrcB, &ciBuf, 0, iMaxDigit);
	}
	return t_StrToInt_base<16, PLib::iHexChar, T_INT, false, false>(piNum, ppSrcB, &ciBuf, 0, iMaxDigit);
}

//----------------------------------------------------------------------
//	StrToIntHex	(2)
//----------------------------------------------------------------------
template<typename T_INT>
bool StrToIntHex(T_INT* piNum, T_PCSTR_U* ppszSrc, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSzBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppszSrc);
	if (bNormalize)
	{
		return t_StrToInt_base<16, PLib::iHexChar, T_INT, false, true>(piNum, ppszSrc, &ciBuf, 0, iMaxDigit);
	}
	return t_StrToInt_base<16, PLib::iHexChar, T_INT, false, false>(piNum, ppszSrc, &ciBuf, 0, iMaxDigit);
}

//----------------------------------------------------------------------
//	StrToIntOct	(1)
//----------------------------------------------------------------------
template<typename T_INT>
bool StrToIntOct(T_INT* piNum, T_PCSTR_U* ppSrcB, T_PCSTR_U pSrcE, int iMinDigit, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSegmentBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppSrcB, pSrcE);
	if (bNormalize)
	{
		return t_StrToInt_base<8, PLib::iOctChar, T_INT, false, true>(piNum, ppSrcB, &ciBuf, iMinDigit, iMaxDigit);
	}
	return t_StrToInt_base<8, PLib::iOctChar, T_INT, false, false>(piNum, ppSrcB, &ciBuf, iMinDigit, iMaxDigit);
}

//----------------------------------------------------------------------
//	StrToIntOct	(2)
//----------------------------------------------------------------------
template<typename T_INT>
bool StrToIntOct(T_INT* piNum, T_PCSTR_U* ppszSrc, int iMinDigit, int iMaxDigit, bool bNormalize)
{
	PLib::PCStrSzBuffer<T_CHAR_U>	ciBuf;

	ciBuf.Set(*ppszSrc);
	if (bNormalize)
	{
		return t_StrToInt_base<8, PLib::iOctChar, T_INT, false, true>(piNum, ppszSrc, &ciBuf, iMinDigit, iMaxDigit);
	}
	return t_StrToInt_base<8, PLib::iOctChar, T_INT, false, false>(piNum, ppszSrc, &ciBuf, iMinDigit, iMaxDigit);
}

/*
//======================================================================
//	is 系の関数とそれらに関連する関数
//======================================================================
bool	IsDigit(int* piv, T_UCP cp, bool bNormalize);
inline bool	IsDigit(int* piv, T_CHAR_U c, bool bNormalize)
{
	return IsDigit(piv, (T_UCP)c, bNormalize);
}

bool	IsCRLF(T_UCP cp, bool bNormalize);
inline bool	IsCRLF(T_CHAR_U c, bool bNormalize)	{ return IsCRLF((T_UCP)c, bNormalize); }

bool	IsCR(T_UCP cp, bool bNormalize);
inline bool	IsCR(T_CHAR_U c, bool bNormalize)	{ return IsCR((T_UCP)c, bNormalize); }

bool	IsLF(T_UCP cp, bool bNormalize);
inline bool	IsLF(T_CHAR_U c, bool bNormalize)	{ return IsLF((T_UCP)c, bNormalize); }

bool	IsBlank(T_UCP cp, bool bNormalize);
inline bool	IsBlank(T_CHAR_U c, bool bNormalize)	{ return IsBlank((T_UCP)c, bNormalize); }

bool	IsHyphen(T_UCP cp, bool bNormalize);
inline bool	IsHyphen(T_CHAR_U c, bool bNormalize)	{ return IsHyphen((T_UCP)c, bNormalize); }

bool	IsDoubleQuote(T_UCP cp, bool bNormalize);
inline bool	IsDoubleQuote(T_CHAR_U c, bool bNormalize)	{ return IsDoubleQuote((T_UCP)c, bNormalize); }
*/

//======================================================================
//	エスケープシーケンスデコード用の関数
//======================================================================
bool	DecodeEscapedControl(T_UCP* pcpDst, T_UCP cpSrc, DWORD dwFlags, T_PCSTR_U pszLocale);

//======================================================================
//	DecodeControlChar
//======================================================================
bool	DecodeControlChar(UINT* puiDst, UINT uiSrc, DWORD dwFlags, LPCWSTR pszLocale);

//======================================================================
//	AppendCodepointToString
//======================================================================
bool	AppendCodepointToString(T_STRING_U* pstrBuffer, T_UCP cpSrc);

NS_PLIB_UNICODE_END
