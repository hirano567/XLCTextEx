//	XLCTextEx_1.0x	:	PLib

//	PClipboard.cpp
//
#include "stdafx.h"
#ifndef	NOT_USE_CLIPBOARD

NS_PLIB_BEGIN

//======================================================================
//	CopyToClipboard
//======================================================================
bool CopyToClipboard(HWND hWnd, UINT uiFormat, LPVOID pData, size_t zData)
{
	HGLOBAL	hGMem	= NULL;
	LPVOID	pMem	= NULL;
	HANDLE	hRet	= NULL;

	if (!OpenClipboard(hWnd))	return false;
	EmptyClipboard();

	hGMem	= GlobalAlloc(GMEM_MOVEABLE, zData);
	if (hGMem == NULL)
	{
		CloseClipboard();
		return false;
	}
	pMem	= GlobalLock(hGMem);
	if (pMem == NULL)	goto ERROR_HANDLING;
	memcpy_s(pMem, zData, pData, zData);
	GlobalUnlock(hGMem);

	hRet	= SetClipboardData(uiFormat, hGMem);
	if (hRet == NULL)	goto ERROR_HANDLING;
	CloseClipboard();
	return true;

ERROR_HANDLING:
	GlobalFree(hGMem);
	CloseClipboard();
	return false;
}


NS_PLIB_END
#endif	//	NOT_USE_CLIPBOARD
