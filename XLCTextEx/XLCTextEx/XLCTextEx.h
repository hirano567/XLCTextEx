//	XLCTextEx_1.0x	:	XLCTextEx

// XLCTextEx.h
//
#pragma once

XLOPER*		XLCTextExSet4(XLOPER* pxCom, XLOPER* pxProp, XLOPER* pxVal);
XLOPER12*	XLCTextExSet12(XLOPER12* pxCom, XLOPER12* pxProp, XLOPER12* pxVal);

NS_XLCTEXTEX_BEGIN

//======================================================================
//	�V�X�e���̏������ƏI������
//======================================================================
BOOL	Init();
void	Cleanup();

NS_XLCTEXTEX_END
