//	XLCTextEx_1.0x	:	PLibXLL

//	XLCustomizing.h
//
#pragma once

NS_XLL_BEGIN

//======================================================================
//	ステータスバーの操作
//======================================================================
template<typename T_CHAR, typename T_XLOPER>
void SetStatusBarText(BOOL bShow, const T_CHAR* pText, size_t zText)
{
	T_XLOPER	*pxArg1, *pxArg2;
	T_XLOPER	xRet;
	int			ir;

	pxArg1	= XLL::AllocateXLOPER<T_XLOPER>();
	pxArg2	= XLL::AllocateXLOPER<T_XLOPER>();

	if (bShow)
	{
		XLL::SetXLOPER_Bool<T_XLOPER>(pxArg1, TRUE, TRUE);
		XLL::SetXLOPER_Str<T_CHAR, T_XLOPER>(pxArg2, pText, zText, TRUE);
	}
	else
	{
		XLL::SetXLOPER_Bool<T_XLOPER>(pxArg1, FALSE, TRUE);
		XLL::SetXLOPER_Str<T_CHAR, T_XLOPER>(pxArg2, t_Str<T_CHAR>(TEXTAW("")), 0, TRUE);
	}
	ir	= t_Excel<T_XLOPER, FALSE>(xlcMessage, &xRet, pxArg1, pxArg2);
}

template<typename T_CHAR, typename T_XLOPER>
void SetStatusBarText(const T_CHAR* pText, size_t zText)
{
	SetStatusBarText<T_CHAR, T_XLOPER>(TRUE, pText, zText);
}

template<typename T_CHAR, typename T_XLOPER>
void ClearStatusBarText()
{
	SetStatusBarText<T_CHAR, T_XLOPER>(FALSE, NULL, 0);
}

NS_XLL_END
