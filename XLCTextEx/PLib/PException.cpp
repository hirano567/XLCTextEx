//	XLCTextEx_1.0x	:	PLib

//	PException.cpp
//
#include "stdafx.h"

NS_PLIB_BEGIN

//======================================================================
//	PException
//======================================================================
//----------------------------------------------------------------------
//	SetMessage
//----------------------------------------------------------------------
BOOL PException::SetMessage(const char *const& pszMessageA)
{
	if (pszMessageA != NULL)
	{
		try
		{
			_Str.assign(pszMessageA);
		}
		catch (...)
		{
			return FALSE;
		}
		return NS_PLIB::ConvertStringToWString(&_StrW, &_Str);
	}
	else
	{
		_Str.clear();
		_StrW.clear();
	}
	return TRUE;
}

BOOL PException::SetMessage(const wchar_t *const& pszMessageW)
{
	if (pszMessageW != NULL)
	{
		try
		{
			_StrW.assign(pszMessageW);
		}
		catch (...)
		{
			return FALSE;
		}
		return NS_PLIB::ConvertWStringToString(&_Str, &_StrW);
	}
	else
	{
		_Str.clear();
		_StrW.clear();
	}
	return TRUE;
}

NS_PLIB_END
