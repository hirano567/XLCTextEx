//	XLCTextEx_1.0x	:	PLib

//	PLib:	PUnicode.cpp
//
#include "stdafx.h"

NS_PLIB_UNICODE_BEGIN

//======================================================================
//	�R�[�h�|�C���g�Ǝ��ۂ̕����R�[�h�Ԃ̕ϊ�
//======================================================================
//----------------------------------------------------------------------
//	21 �r�b�g�R�[�h�|�C���g�l�����ۂ̕����R�[�h�ɕϊ�����B
//	pBuf �ɂ́A�T���Q�[�g�̏ꍇ�� 2 �������A�I�[�� NULL 1 ���������K�v�Ȃ̂ŁA
//	�ŏ��ł� wchar_t 3 ���������蓖�ĂĂ������ƁB
//----------------------------------------------------------------------
BOOL ConvertFromCodepoint(LPWSTR pBuf, UINT uiCodepoint)
{
	//	Codepoint �� 0xFFFF �ȓ��Ȃ炻�̒l��Ԃ��B
	if (uiCodepoint <= 0xFFFF)
	{
		pBuf[0]	= (wchar_t)uiCodepoint;
		pBuf[1]	= (wchar_t)0;
		return TRUE;
	}
	//	Codepoint �� 0x10FFFF �ȓ��Ȃ�T���Q�[�g�ł���B
	else if (uiCodepoint <= 0x10FFFF)
	{
		pBuf[0]	= (wchar_t)0xD7C0 + (wchar_t)(uiCodepoint >> 10);
		pBuf[1]	= (wchar_t)0xDC00 + (wchar_t)(0x3FF & uiCodepoint);
		pBuf[2]	= (wchar_t)0;
		return TRUE;
	}
	//	�ȏ�ɓ��Ă͂܂�Ȃ��ꍇ�͓K�؂� Codepoint �ł͂Ȃ��B
	return FALSE;
}

//----------------------------------------------------------------------
//	ConvertToCodepoint	(1-1)
//	���ۂ̕����R�[�h�� 21 �r�b�g�̃R�[�h�|�C���g�l�ɕϊ����A�ϊ�������������Ԃ��B
//	�����̃`�F�b�N�͂��Ȃ��̂ŁA�Ăяo�����Ŋm�F���Ă������ƁB
//----------------------------------------------------------------------
size_t ConvertToCodepoint(UINT* puiCodepoint, LPCWSTR* ppSrc, LPCWSTR pEnd)
{
	LPCWSTR pSrc	= *ppSrc;;
	UINT	uiHigh, uiLow;
	size_t	zr;

	//	�w�肳�ꂽ�������T���Q�[�g�� 2 �����ڂȂ� 0 ��Ԃ��B
	if (IS_LOW_SURROGATE(*pSrc))
	{
		THROWPE_RUNTIME_ERROR("ConvertToCodepoint: no high surrogate");
		return (size_t)0;
	}
	//	�w�肳�ꂽ�������T���Q�[�g�� 1 �����ڂȂ� ���̕����ƍ��킹�āA
	//	�R�[�h�|�C���g�ɕϊ�����B
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
	//	����ȊO�̏ꍇ�́A���̂܂܃R�[�h�|�C���g�Ƃ���B
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
//	���ۂ̕����R�[�h�� 21 �r�b�g�̃R�[�h�|�C���g�l�ɕϊ����A�ϊ�������������Ԃ��B
//	�����̃`�F�b�N�͂��Ȃ��̂ŁA�Ăяo�����Ŋm�F���Ă������ƁB
//----------------------------------------------------------------------
size_t ConvertToCodepoint(UINT* puiCodepoint, LPCWSTR* ppszSrc)
{
	LPCWSTR pSrc	= *ppszSrc;;
	UINT	uiHigh, uiLow;
	size_t	zr;

	//	�w�肳�ꂽ�������T���Q�[�g�� 2 �����ڂȂ� 0 ��Ԃ��B
	if (IS_LOW_SURROGATE(*pSrc))
	{
		return (size_t)0;
	}
	//	�w�肳�ꂽ�������T���Q�[�g�� 1 �����ڂȂ� ���̕����ƍ��킹�āA
	//	�R�[�h�|�C���g�ɕϊ�����B
	else if (IS_HIGH_SURROGATE(*pSrc))
	{
		uiHigh	= (UINT)(*pSrc) - (UINT)(0xD800);
		++pSrc;
		uiLow	= (UINT)(*pSrc) - (UINT)(0xDC00);
		*puiCodepoint	= (UINT)((uiHigh << 10) | uiLow) + (UINT)0x10000;
		++pSrc;
		zr	= 2;
	}
	//	����ȊO�̏ꍇ�́A���̂܂܃R�[�h�|�C���g�Ƃ���B
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
//	�����̃`�F�b�N�͂��Ȃ��̂ŁA�Ăяo�����Ŋm�F���Ă������ƁB
//----------------------------------------------------------------------
size_t ConvertToCodepoint(UINT* puiCodepoint, PIFStrBuffer<wchar_t>* pciBuf)
{
	wchar_t	wc;
	UINT	uiHigh, uiLow;
	size_t	zr;

	if (!pciBuf->GetChar(&wc))	return (size_t)0;

	//	�w�肳�ꂽ�������T���Q�[�g�� 2 �����ڂȂ� 0 ��Ԃ��B
	if (IS_LOW_SURROGATE(wc))
	{
		return (size_t)0;
	}
	//	�w�肳�ꂽ�������T���Q�[�g�� 1 �����ڂȂ� ���̕����ƍ��킹�āA
	//	�R�[�h�|�C���g�ɕϊ�����B
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
	//	����ȊO�̏ꍇ�́A���̂܂܃R�[�h�|�C���g�Ƃ���B
	else
	{
		*puiCodepoint	= (UINT)wc;
		pciBuf->Next();
		zr	= 1;
	}
	return zr;
}


//======================================================================
//	�R�[�h�|�C���g��Ǝ��ۂ̃��j�R�[�h������Ԃ̕ϊ�
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
