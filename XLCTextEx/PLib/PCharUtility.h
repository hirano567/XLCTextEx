//	XLCTextEx_1.0x	:	PLib

//	PCharUtility.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	StrToInt
//
//	T_INT に符号なし整数を指定した場合、負の整数値の扱いは不定
//======================================================================

extern	int	iDecChar[128];
extern	int	iHexChar[128];
extern	int	iOctChar[128];

#define	C_TO_N_DEC(c)	(IS_7BIT(c) ? NS_PLIB::iDecChar[c] : -1)
#define	C_TO_N_HEX(c)	(IS_7BIT(c) ? NS_PLIB::iHexChar[c] : -1)
#define	C_TO_N_OCT(c)	(IS_7BIT(c) ? NS_PLIB::iOctChar[c] : -1)

//----------------------------------------------------------------------
//	t_StrToIntDec
//
//	数値が得られない場合は false を返す。
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_INT>
bool t_StrToIntDec(T_INT* piNum, const T_CHAR** ppSrc, const T_CHAR* pEnd)
{
	const T_CHAR*	pSrc;
	T_INT			iNum	= 0;
	int				i;
	bool			bNegative	= false;
	T_CHAR			cMinus		= t_Char<T_CHAR>(TEXTAW('-'));

	if (piNum == NULL || ppSrc == NULL || *ppSrc >= pEnd)	return false;
	pSrc	= *ppSrc;

	if (*pSrc == cMinus)
	{
		bNegative	= true;
		++pSrc;
		if (!(pSrc < pEnd))	return false;
	}

	//	最初の文字が数値を表すものでない場合は false を返す。
	if (IS_7BIT(*pSrc))
	{
		i	= iDecChar[(int)*pSrc];
		if (i< 0)
		{
			return false;
		}
		iNum	= (T_INT)i;
	}
	else
	{
		return false;
	}

	while (++pSrc < pEnd)
	{
		if (!IS_7BIT(*pSrc))
		{
			break;
		}
		i	= iDecChar[(int)*pSrc];
		if (i < 0)
		{
			break;
		}
		iNum	= iNum * 10 + (T_INT)i;
	}

	*ppSrc	= pSrc;
	if (bNegative)
	{
		*piNum	= (T_INT)((-1)*iNum);
	}
	else
	{
		*piNum	= iNum;
	}
	return true;
}

//----------------------------------------------------------------------
//	t_StrToIntDec
//
//	数値が得られない場合は false を返す。
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_INT>
bool t_StrToIntDec(T_INT* piNum, const T_CHAR** ppSrc)
{
	const T_CHAR*	pSrc	= *ppSrc;
	T_INT			iNum	= 0;
	int				i;
	bool			bNegative	= false;
	T_CHAR			cMinus		= t_Char<T_CHAR>(TEXTAW('-'));

	if (piNum == NULL || ppSrc == NULL)	return false;

	if (*pSrc == cMinus)
	{
		bNegative	= true;
		++pSrc;
		if (*pSrc == NULL)	return false;
	}

	//	最初の文字が数値を表すものでない場合は false を返す。
	if (IS_7BIT(*pSrc))
	{
		i	= iDecChar[(int)*pSrc];
		if (i < 0)
		{
			return false;
		}
		iNum	= (T_INT)i;
	}
	else
	{
		return false;
	}

	do
	{
		++pSrc;
		if (!IS_7BIT(*pSrc))
		{
			break;
		}
		i	= iDecChar[(int)*pSrc];
		if (i < 0)
		{
			break;
		}
		iNum	= iNum * 10 + (T_INT)i;
	}
	while (true);

	*ppSrc	= pSrc;
	if (bNegative)
	{
		*piNum	= (T_INT)((-1)*iNum);
	}
	else
	{
		*piNum	= iNum;
	}
	return true;
}

NS_PLIB_END
