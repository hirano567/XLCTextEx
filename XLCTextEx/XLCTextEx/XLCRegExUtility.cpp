//	XLCTextEx_1.0x	:	XLCTextEx

//	XLCRegExUtility.cpp
//
#include "stdafx.h"

//======================================================================
//	インスタンスの管理
//======================================================================
PCXLRegExManager*	pciXLRegExManager	= NULL;

PCXLRegExManager* GetXLRegExManager()
{
	return pciXLRegExManager;
}

NS_XLCREGEX_BEGIN

//======================================================================
//	Init
//======================================================================
BOOL Init()
{
	try
	{
		if (pciXLRegExManager == NULL)
		{
			pciXLRegExManager	= new PCXLRegExManager;
		}
	}
	catch (...)
	{
		return FALSE;
	}
	return TRUE;
}

//======================================================================
//	Cleanup
//======================================================================
void Cleanup()
{
	CleanupErrorLog();

	delete pciXLRegExManager;
}

NS_XLCREGEX_END
