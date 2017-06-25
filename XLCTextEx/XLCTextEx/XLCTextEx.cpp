//	XLCTextEx_1.0x	:	XLCTextEx

// XLCTextEx.cpp
//
#include "stdafx.h"

XLOPER* XLCTextExSet4(XLOPER* pxCom, XLOPER* pxProp, XLOPER* pxVal)
{
	return NULL;
}

XLOPER12* XLCTextExSet12(XLOPER12* pxCom, XLOPER12* pxProp, XLOPER12* pxVal)
{
	return NULL;
}


NS_XLCTEXTEX_BEGIN

//======================================================================
//	Init
//======================================================================
BOOL Init()
{
	if (!XLCRegEx::Init())	return FALSE;
	if (!XLCTr::Init())		return FALSE;
	return TRUE;
}

//======================================================================
//	Cleanup
//======================================================================
void Cleanup()
{
	XLCRegEx::Cleanup();
	XLCTr::Cleanup();
}

NS_XLCTEXTEX_END
