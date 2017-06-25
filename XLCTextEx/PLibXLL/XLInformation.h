//	XLCTextEx_1.0x	:	PLibXLL

//	XLInformation.h
//
#pragma once

NS_XLL_BEGIN

//======================================================================
//	188	xlfGetDocument
//======================================================================
//----------------------------------------------------------------------
//	GetActiveWorkBook
//	88	アクティブなワークブックの名前を取得する。
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER>
BOOL t_GetActiveWorkBookName(std::basic_string<T_CHAR>* pstrBuffer)
{
	T_XLOPER	xRet, xType;
	size_t		zt	= 0;
	int			ir;
	BOOL		br	= FALSE;


	xType.xltype	= xltypeNum;
	xType.val.num	= 88;

	ir	= t_Excel<T_XLOPER, FALSE>(xlfGetDocument, &xRet, &xType);
	if (ir == xlretSuccess && xRet.xltype == xltypeStr)
	{
		zt	= GetXLOPER_StrSize(&xRet);
		if (zt > 0)
		{
			pstrBuffer->append(xRet.val.str + 1, zt);
			br	= TRUE;
		}
	}

	FreeXLOPER<T_XLOPER>(&xRet);
	return br;
}

template<typename T_CHAR>
inline BOOL GetActiveWorkBookName(std::basic_string<T_CHAR>* pstrBuffer)
{
	THROWPE_LOGIC_ERROR("XLL::GetActiveWorkBookName");
	return FALSE;
}
template<>
inline BOOL GetActiveWorkBookName<char>(std::string* pstrBuffer)
{
	return t_GetActiveWorkBookName<char, XLOPER>(pstrBuffer);
}
template<>
inline BOOL GetActiveWorkBookName<wchar_t>(std::wstring* pstrBuffer)
{
	return t_GetActiveWorkBookName<wchar_t, XLOPER12>(pstrBuffer);
}


NS_XLL_END
