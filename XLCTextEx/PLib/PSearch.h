//	XLCTextEx_1.0x	:	PLib

//	PLib.h	:	PSearch.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	BinarySearch	�񕪒T��
//
//	C_ELEMENT �̓N���X�ŁA�ȉ��̃����o����`����Ă��Ȃ���΂Ȃ�Ȃ��B
//		�C���X�^���X�̏��������߂邽�߂� T_KEY �^�̃f�[�^�����o�B
//		LessThan(T_KEY k)	���\�b�h�B�C���X�^���X�� k ��菬�����Ȃ� true ��Ԃ��B
//		Match(T_KEY k)	���\�b�h�B�C���X�^���X�� k �Ɠ������Ƃ݂Ȃ���Ȃ� true ��Ԃ��B
//======================================================================
template<class C_ELEMENT, typename T_KEY>
bool BinarySearch(UINT* puiFound, C_ELEMENT* pEArray, UINT uiNum, T_KEY kSearch)
{
	UINT	uiLow, uiHigh, uiMid;

	if (pEArray == NULL || uiNum < 1)	return false;

	uiLow	= 0;
	uiHigh	= uiNum - 1;

	while (uiLow < uiHigh)
	{
		uiMid	= (UINT)((uiLow + uiHigh) / 2);
		if (pEArray[uiMid].LessThan(kSearch))
		{
			uiLow	= uiMid + 1;
		}
		else
		{
			uiHigh	= uiMid;
		}
	}
	if (pEArray[uiLow].Match(kSearch))
	{
		*puiFound	= uiLow;
		return true;
	}
	return false;
}


//======================================================================
//	BinarySearch �֐��p�̃f�[�^�\����
//======================================================================
//----------------------------------------------------------------------
//	struct	PSSearchPSzKey
//	NULL �I����������L�[�Ƃ��錟���p�\����
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_DATA>
struct	PSSearchPSzKey
{
	typedef	const T_CHAR*	T_PCSTR;

	T_PCSTR	pszKey;
	T_DATA	Data;

	//------------------------------------------------------------
	//	�����o�֐�
	//------------------------------------------------------------
	int	Compare(T_PCSTR pszCmp, DWORD dwFlags = 0, LCID dwLocale = LOCALE_USER_DEFAULT)
	{
		return PLib::t_StrCmp<T_CHAR, TRUE>(pszKey, pszCmp);
	}

	bool LessThan(T_PCSTR pszCmp, DWORD dwFlags = 0, LCID dwLocale = LOCALE_USER_DEFAULT)
	{
		return (Compare(pszCmp, dwFlags, dwLocale) < 0);
	}

	bool GreaterThan(T_PCSTR pszCmp, DWORD dwFlags = 0, LCID dwLocale = LOCALE_USER_DEFAULT)
	{
		return (Compare(pszCmp, dwFlags, dwLocale) > 0);
	}

	bool Match(T_PCSTR pszCmp, DWORD dwFlags = 0, LCID dwLocale = LOCALE_USER_DEFAULT)
	{
		return (Compare(pszCmp, dwFlags, dwLocale) == 0);
	}
};

//----------------------------------------------------------------------
//	struct	PSSearchNumKey
//	���l���L�[�Ƃ��錟���p�\����
//----------------------------------------------------------------------
template<typename T_NUM, typename T_DATA>
struct	PSSearchNumKey
{
	T_NUM	nKey;
	T_DATA	Data;

	bool LessThan(T_NUM nCmp)		{ return (nCmp > nKey); }
	bool GreaterThan(T_NUM nCmp)	{ return (nCmp < nKey); }
	bool Match(T_NUM nCmp)			{ return (nCmp == nKey); }
};

//----------------------------------------------------------------------
//	struct	PSSearchNumRangeKey
//	���l�͈͂��L�[�Ƃ��錟���p�\����
//----------------------------------------------------------------------
template<typename T_NUM, typename T_DATA>
struct	PSSearchNumRangeKey
{
	//------------------------------------------------------------
	//	�f�[�^�����o
	//------------------------------------------------------------
	T_NUM	nKeyF;
	T_NUM	nKeyL;

	T_DATA	Data;

	//------------------------------------------------------------
	//	�����o�֐�
	//------------------------------------------------------------
	bool LessThan(T_NUM nCmp)
	{
		return (nCmp > nKeyL);
	}

	bool GreaterThan(T_NUM nCmp)
	{
		return (nCmp < nKeyF);
	}

	int	Compare(T_NUM nCmp)
	{
		if (nCmp < nKeyF)
			return -1;
		else if (nCmp > nKeyL)
			return 1;
		else
			return 0;
	}

	bool Match(T_NUM nCmp)
	{
		return (Compare(nCmp) == 0);
	}
};

//======================================================================
//	SearchNumSet	(1)
//
//	�����ɕ��ׂ�ꂽ���l�z�����������
//======================================================================
template<typename T_NUM>
bool SearchNumSet(UINT* puiFound, T_NUM* pNArray, UINT uiNum, T_NUM nSearch)
{
	UINT	uiLow, uiHigh, uiMid;

	if (pNArray == NULL || uiNum < 1)	return false;

	uiLow	= 0;
	uiHigh	= uiNum - 1;

	while (uiLow < uiHigh)
	{
		uiMid	= (UINT)((uiLow + uiHigh) / 2);
		if (pNArray[uiMid] < nSearch)
		{
			uiLow	= uiMid + 1;
		}
		else
		{
			uiHigh	= uiMid;
		}
	}
	if (pNArray[uiLow] == nSearch)
	{
		*puiFound	= uiLow;
		return true;
	}
	return false;
}

//======================================================================
//	SearchNumSet	(2)
//
//	�����ɕ��ׂ�ꂽ���l�z�����������
//	�ő�l�ƍŏ��l���w�肵�Ă����B
//======================================================================
template<typename T_NUM>
bool SearchNumSet(UINT* puiFound, T_NUM* pNArray, UINT uiNum, T_NUM nMin, T_NUM nMax, T_NUM nSearch)
{
	UINT	uiLow, uiHigh, uiMid;

	if (nSearch < nMin || nSearch > nMax)	return false;
	if (pNArray == NULL || uiNum < 1)	return false;

	uiLow	= 0;
	uiHigh	= uiNum - 1;

	while (uiLow < uiHigh)
	{
		uiMid	= (UINT)((uiLow + uiHigh) / 2);
		if (pNArray[uiMid] < nSearch)
		{
			uiLow	= uiMid + 1;
		}
		else
		{
			uiHigh	= uiMid;
		}
	}
	if (pNArray[uiLow] == nSearch)
	{
		*puiFound	= uiLow;
		return true;
	}
	return false;
}

NS_PLIB_END
