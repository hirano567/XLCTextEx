//	XLCTextEx_1.0x	:	XLCTextEx

//	XLCTrUtility.h
//
#include "stdafx.h"

//======================================================================
//	�C���X�^���X�̊Ǘ�
//======================================================================
XLTRMANANGER*	pciTrManager	= NULL;

NS_XLCTR_BEGIN

//======================================================================
//	Init
//======================================================================
bool Init()
{
	try
	{
		if (pciTrManager == NULL)
		{
			pciTrManager	= new XLTRMANANGER;
		}
	}
	catch (...)
	{
		return false;
	}
	return true;
}

//======================================================================
//	Cleanup
//======================================================================
void Cleanup()
{
	delete pciTrManager;
}

NS_XLCTR_END
