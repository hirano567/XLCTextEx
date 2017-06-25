//	XLCTextEx_1.0x	:	Test

//	Main.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
#ifdef	PDEBUG
	//_CrtSetBreakAlloc(323);
#endif

	PLib::Init();
	PLib::TextEx::Init();

	//TestPLib01();
	//TestPUCD01();
	//TestPRegEx01();
	//TestPRegEx02();
	//TestPRegEx03();
	TestPRegEx05();
	//TestPTr01();

	//Prototype01();

	PLib::TextEx::Cleanup();
	PLib::Cleanup();

#ifdef	PDEBUG
	_CrtDumpMemoryLeaks();
#endif
	return 0;
}
