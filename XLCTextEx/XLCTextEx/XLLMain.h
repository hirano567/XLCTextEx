//	XLCTextEx_1.0x	:	XLCTextEx

//	XLLMain.h
//
#pragma once

int WINAPI	xlAutoOpen();
int WINAPI	xlAutoClose();

void WINAPI	xlAutoFree(LPXLOPER pxFree);
void WINAPI	xlAutoFree12(LPXLOPER12 pxFree);

//extern PCSTRAW		awXLLTitle;

BOOL	GetExcelVersion(int* pmajor, int* pminor);
BOOL	IsExcel12();
