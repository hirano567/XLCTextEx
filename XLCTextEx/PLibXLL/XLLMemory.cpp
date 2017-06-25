//	XLCTextEx_1.0x	:	PLibXLL

//	XLLMemory.cpp
//
#include "stdafx.h"

NS_XLL_BEGIN


#define	USE_CRITICALSECTION
//#undef	USE_CRITICALSECTION

#ifdef	USE_CRITICALSECTION
#define	ENTER_CRITICALSECTION(cs)	EnterCriticalSection(cs)
#define	LEAVE_CRITICALSECTION(cs)	LeaveCriticalSection(cs)
CRITICAL_SECTION	csXLOPER;
#else
#define	ENTER_CRITICALSECTION(cs)
#define	LEAVE_CRITICALSECTION(cs)
#endif

//======================================================================
//	XLOPER 構造体へのメモリ割り当て
//======================================================================
/*
typedef	PLib::PCInstanceAllocator<XLOPER>	CIPXLOPER4;
typedef	PLib::PCInstanceAllocator<XLOPER12>	CIPXLOPER12;

CIPXLOPER4*		pciIPXLOPER4	= NULL;
CIPXLOPER12*	pciIPXLOPER12	= NULL;
*/

//----------------------------------------------------------------------
//	AllocateXLOPER4, AllocateXLOPER12
//	例外は呼び出し側で処理すること。
//----------------------------------------------------------------------
XLOPER* AllocateXLOPER4()
{
	XLOPER*	px;

	ENTER_CRITICALSECTION(&csXLOPER);
	try
	{
		/*
		if (pciIPXLOPER4 == NULL)
		{
			pciIPXLOPER4	= new CIPXLOPER4;
		}
		px	= pciIPXLOPER4->Allocate();
		*/
		px	= new XLOPER;
	}
	catch (...)
	{
		LEAVE_CRITICALSECTION(&csXLOPER);
		throw;
	}
	LEAVE_CRITICALSECTION(&csXLOPER);
	return px;
}

XLOPER12* AllocateXLOPER12()
{
	XLOPER12*	px;

	ENTER_CRITICALSECTION(&csXLOPER);
	try
	{
		/*
		if (pciIPXLOPER12 == NULL)
		{
			pciIPXLOPER12	= new CIPXLOPER12;
		}
		px	= pciIPXLOPER12->Allocate();
		*/
		px	= new XLOPER12;
	}
	catch (...)
	{
		LEAVE_CRITICALSECTION(&csXLOPER);
		throw;
	}
	LEAVE_CRITICALSECTION(&csXLOPER);
	return px;
}

//----------------------------------------------------------------------
//	DeallocateXLOPER4, DeallocateXLOPER12
//----------------------------------------------------------------------
void DeallocateXLOPER4(XLOPER* px)
{
	ENTER_CRITICALSECTION(&csXLOPER);
	/*
	if (pciIPXLOPER4 != NULL && px != NULL)
	{
		try
		{
			DeleteXLOPER<XLOPER>(px);
			pciIPXLOPER4->Deallocate(px);
		}
		catch (...)
		{
			LEAVE_CRITICALSECTION(&csXLOPER);
			throw;
		}
	}
	*/
	DeleteXLOPER<XLOPER>(px);
	delete	px;
	LEAVE_CRITICALSECTION(&csXLOPER);
}

void DeallocateXLOPER12(XLOPER12* px)
{
	ENTER_CRITICALSECTION(&csXLOPER);
	/*
	if (pciIPXLOPER12 != NULL && px != NULL)
	{
		try
		{
			DeleteXLOPER<XLOPER12>(px);
			pciIPXLOPER12->Deallocate(px);
		}
		catch (...)
		{
			LEAVE_CRITICALSECTION(&csXLOPER);
			throw;
		}
	}
	*/
	DeleteXLOPER<XLOPER12>(px);
	delete	px;
	LEAVE_CRITICALSECTION(&csXLOPER);
}

//----------------------------------------------------------------------
//	ClearIPXLOPER
//----------------------------------------------------------------------
void ClearIPXLOPER()
{
	ENTER_CRITICALSECTION(&csXLOPER);
	try
	{
		/*
		if (pciIPXLOPER4 != NULL)
		{
			pciIPXLOPER4->Clear();
		}
		if (pciIPXLOPER12 != NULL)
		{
			pciIPXLOPER12->Clear();
		}
		*/
	}
	catch (...)
	{
		LEAVE_CRITICALSECTION(&csXLOPER);
		throw;
	}
	LEAVE_CRITICALSECTION(&csXLOPER);
}

//----------------------------------------------------------------------
//	CleanupIPXLOPER
//----------------------------------------------------------------------
void CleanupIPXLOPER()
{
	ENTER_CRITICALSECTION(&csXLOPER);
	try
	{
		//delete	pciIPXLOPER4;
		//delete	pciIPXLOPER12;
	}
	catch (...)
	{
	}
	LEAVE_CRITICALSECTION(&csXLOPER);
}

//======================================================================
//	初期設定と終了処理
//======================================================================
//----------------------------------------------------------------------
//	XLL::InitXLLMemory
//----------------------------------------------------------------------
void InitXLLMemory()
{
#ifdef	USE_CRITICALSECTION
	InitializeCriticalSection(&csXLOPER);
#endif
}

//----------------------------------------------------------------------
//	XLL::Cleanup
//----------------------------------------------------------------------
void CleanupXLLMemory()
{
	//CleanupIPXLOPER();
}

NS_XLL_END
