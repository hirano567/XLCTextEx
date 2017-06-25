//	XLCTextEx_1.0x	:	PLib

//	PLib.cpp
//
#include "stdafx.h"

NS_PLIB_BEGIN

//======================================================================
//	Init
//======================================================================
bool Init()
{
	if (!NS_PLIB::Memory::Init())		return false;
	if (!NS_PLIB::System::Init())		return false;

#ifdef	PDEBUG
	PLib::Debug::Init();
#endif
	return true;
}

//======================================================================
//	Cleanup
//======================================================================
void Cleanup()
{
#ifdef	PDEBUG
	PLib::Debug::Cleanup();
#endif

	NS_PLIB::System::Cleanup();
	NS_PLIB::Memory::Cleanup();
}

NS_PLIB_END
