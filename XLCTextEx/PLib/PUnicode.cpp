//	XLCTextEx_1.0x	:	PLib

//	PLib:	PUnicode.cpp
//
#include "stdafx.h"

NS_PLIB_UNICODE_BEGIN

//======================================================================
//	コードポイントと実際の文字コード間の変換
//======================================================================
//----------------------------------------------------------------------
//	21 ビットコードポイント値を実際の文字コードに変換する。
//	pBuf には、サロゲートの場合の 2 文字分、終端の NULL 1 文字分が必要なので、
//	最小でも wchar_t 3 文字分割り当てておくこと。
//----------------------------------------------------------------------
BOOL ConvertFromCodepoint(LPWSTR pBuf, UINT uiCodepoint)
{
	//	Codepoint が 0xFFFF 以内ならその値を返す。
	if (uiCodepoint <= 0xFFFF)
	{
		pBuf[0]	= (wchar_t)uiCodepoint;
		pBuf[1]	= (wchar_t)0;
		return TRUE;
	}
	//	Codepoint が 0x10FFFF 以内ならサロゲートである。
	else if (uiCodepoint <= 0x10FFFF)
	{
		pBuf[0]	= (wchar_t)0xD7C0 + (wchar_t)(uiCodepoint >> 10);
		pBuf[1]	= (wchar_t)0xDC00 + (wchar_t)(0x3FF & uiCodepoint);
		pBuf[2]	= (wchar_t)0;
		return TRUE;
	}
	//	以上に当てはまらない場合は適切な Codepoint ではない。
	return FALSE;
}

//----------------------------------------------------------------------
//	ConvertToCodepoint	(1-1)
//	実際の文字コードを 21 ビットのコードポイント値に変換し、変換した文字数を返す。
//	引数のチェックはしないので、呼び出し側で確認しておくこと。
//----------------------------------------------------------------------
size_t ConvertToCodepoint(UINT* puiCodepoint, LPCWSTR* ppSrc, LPCWSTR pEnd)
{
	LPCWSTR pSrc	= *ppSrc;;
	UINT	uiHigh, uiLow;
	size_t	zr;

	//	指定された文字がサロゲートの 2 文字目なら 0 を返す。
	if (IS_LOW_SURROGATE(*pSrc))
	{
		THROWPE_RUNTIME_ERROR("ConvertToCodepoint: no high surrogate");
		return (size_t)0;
	}
	//	指定された文字がサロゲートの 1 文字目なら 次の文字と合わせて、
	//	コードポイントに変換する。
	else if (IS_HIGH_SURROGATE(*pSrc))
	{
		uiHigh	= (UINT)(*pSrc) - (UINT)(0xD800);
		++pSrc;
		if (pSrc >= pEnd || !IS_LOW_SURROGATE(*pSrc))
		{
			THROWPE_RUNTIME_ERROR("ConvertToCodepoint: no low surrogate");
			return 0;
		}
		uiLow	= (UINT)(*pSrc) - (UINT)(0xDC00);
		*puiCodepoint	= (UINT)((uiHigh << 10) | uiLow) + (UINT)0x10000;
		++pSrc;
		zr	= 2;
	}
	//	それ以外の場合は、そのままコードポイントとする。
	else
	{
		*puiCodepoint	= (UINT)*pSrc;
		++pSrc;
		zr	= 1;
	}
	*ppSrc	= pSrc;
	return zr;
}

//----------------------------------------------------------------------
//	ConvertToCodepoint	(1-2)
//	実際の文字コードを 21 ビットのコードポイント値に変換し、変換した文字数を返す。
//	引数のチェックはしないので、呼び出し側で確認しておくこと。
//----------------------------------------------------------------------
size_t ConvertToCodepoint(UINT* puiCodepoint, LPCWSTR* ppszSrc)
{
	LPCWSTR pSrc	= *ppszSrc;;
	UINT	uiHigh, uiLow;
	size_t	zr;

	//	指定された文字がサロゲートの 2 文字目なら 0 を返す。
	if (IS_LOW_SURROGATE(*pSrc))
	{
		return (size_t)0;
	}
	//	指定された文字がサロゲートの 1 文字目なら 次の文字と合わせて、
	//	コードポイントに変換する。
	else if (IS_HIGH_SURROGATE(*pSrc))
	{
		uiHigh	= (UINT)(*pSrc) - (UINT)(0xD800);
		++pSrc;
		uiLow	= (UINT)(*pSrc) - (UINT)(0xDC00);
		*puiCodepoint	= (UINT)((uiHigh << 10) | uiLow) + (UINT)0x10000;
		++pSrc;
		zr	= 2;
	}
	//	それ以外の場合は、そのままコードポイントとする。
	else
	{
		*puiCodepoint	= (UINT)*pSrc;
		++pSrc;
		zr	= 1;
	}
	*ppszSrc	= pSrc;
	return zr;
}

//----------------------------------------------------------------------
//	ConvertToCodepoint	(1-3)
//	引数のチェックはしないので、呼び出し側で確認しておくこと。
//----------------------------------------------------------------------
size_t ConvertToCodepoint(UINT* puiCodepoint, PIFStrBuffer<wchar_t>* pciBuf)
{
	wchar_t	wc;
	UINT	uiHigh, uiLow;
	size_t	zr;

	if (!pciBuf->GetChar(&wc))	return (size_t)0;

	//	指定された文字がサロゲートの 2 文字目なら 0 を返す。
	if (IS_LOW_SURROGATE(wc))
	{
		return (size_t)0;
	}
	//	指定された文字がサロゲートの 1 文字目なら 次の文字と合わせて、
	//	コードポイントに変換する。
	else if (IS_HIGH_SURROGATE(wc))
	{
		uiHigh	= (UINT)(wc) - (UINT)(0xD800);
		if (!pciBuf->Next())		return (size_t)0;
		if (!pciBuf->GetChar(&wc))	return (size_t)0;
		uiLow	= (UINT)(wc) - (UINT)(0xDC00);
		*puiCodepoint	= (UINT)((uiHigh << 10) | uiLow) + (UINT)0x10000;
		pciBuf->Next();
		zr	= 2;
	}
	//	それ以外の場合は、そのままコードポイントとする。
	else
	{
		*puiCodepoint	= (UINT)wc;
		pciBuf->Next();
		zr	= 1;
	}
	return zr;
}


//======================================================================
//	コードポイント列と実際のユニコード文字列間の変換
//======================================================================
//----------------------------------------------------------------------
//	ConvertFromCodepoint	(1)
//----------------------------------------------------------------------
bool ConvertFromCodepoint(T_STRING_U* pstrDst, UINT uiCodepoint)
{
	T_CHAR_U	Buf[3];

	if (pstrDst == NULL)	return false;

	if (PLib::Unicode::ConvertFromCodepoint(Buf, uiCodepoint))
	{
		pstrDst->append(Buf);
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	ConvertFromCodepoint	(2)
//----------------------------------------------------------------------
bool ConvertFromCodepoint(T_STRING_U* pstrDst, UCPSTRING* puisSrc)
{
	const UINT*		pc;
	T_CHAR_U	Buf[3];

	if (pstrDst == NULL || puisSrc == NULL)	return false;

	for(pc = puisSrc->c_str(); *pc; ++pc)
	{
		if (PLib::Unicode::ConvertFromCodepoint(Buf, *pc))
		{
			pstrDst->append(Buf);
		}
	}
	return true;
}

//----------------------------------------------------------------------
//	ConvertToCodepoint	(2-1)
//----------------------------------------------------------------------
bool ConvertToCodepoint(UCPSTRING* puisDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE)
{
	T_PCSTR_U	pc;
	UINT			uic;

	if (puisDst == NULL || pSrcB == NULL || pSrcB > pSrcE)	return false;

	pc	= pSrcB;
	while (pc < pSrcE)
	{
		if (!PLib::Unicode::ConvertToCodepoint(&uic, &pc, pSrcE))
		{
			THROWPE_RUNTIME_ERROR("ConvertToCodepoint");
		}
		puisDst->append(1, uic);
	}
	return true;
}

//----------------------------------------------------------------------
//	ConvertToCodepoint	(2-2)
//----------------------------------------------------------------------
bool ConvertToCodepoint(UCPSTRING* puisDst, T_PCSTR_U pszSrc)
{
	T_PCSTR_U	pc;
	UINT			uic;

	if (puisDst == NULL || pszSrc == NULL)	return false;

	pc	= pszSrc;
	while (*pc)
	{
		if (!PLib::Unicode::ConvertToCodepoint(&uic, &pc))
		{
			THROWPE_RUNTIME_ERROR("ConvertToCodepoint");
		}
		puisDst->append(1, uic);
	}
	return true;
}

NS_PLIB_UNICODE_END
