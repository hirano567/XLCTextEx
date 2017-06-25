//	XLCTextEx_1.0x	:	XLCTextEx

// dllmain.cpp : DLL �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
#include "stdafx.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
#ifdef PDEBUG
		//_CrtSetBreakAlloc(589);
#endif

		XLL::SetXLLInstanceHandle((HINSTANCE)hModule);
		PLib::Init();
		PLib::TextEx::Init();
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		XLCTextEx::Cleanup();
		XLL::Cleanup();
		PLib::TextEx::Cleanup();
		PLib::Cleanup();

#ifdef PDEBUG
		_CrtDumpMemoryLeaks();
#endif
		break;
	}
	return TRUE;
}

