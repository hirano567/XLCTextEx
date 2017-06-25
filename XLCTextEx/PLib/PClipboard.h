//	XLCTextEx_1.0x	:	PLib

//	PClipboard.h
//
#pragma once

#ifndef	NOT_USE_CLIPBOARD
NS_PLIB_BEGIN

bool	CopyToClipboard(HWND hWnd, UINT uiFormat, LPVOID pData, size_t zData);

NS_PLIB_END
#endif	//	NOT_USE_CLIPBOARD
