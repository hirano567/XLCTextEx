///***************************************************************************
// File:        MemoryManager.cpp
//
// Purpose:     The memory manager class is an update to the memory manager
//              in the previous release of the framework.  This class provides
//              each thread with an array of bytes to use as temporary memory.
//              The size of the array, and the methods for dealing with the
//              memory explicitly, is in the class MemoryPool.  
//
//              MemoryManager handles assigning of threads to pools, and the
//              creation of new pools when a thread asks for memory the first
//              time.  Using a singleton class, the manager provides an interface
//              to C code into the manager.  The number of unique pools starts
//              as MEMORYPOOLS, defined in MemoryManager.h.  When a new thread
//              needs a pool, and the current set of pools are all assigned,
//              the number of pools increases by a factor of two.
// 
// Platform:    Microsoft Windows
//
///***************************************************************************

//#include "MemoryManager.h"
#include "stdafx.h"
#ifndef	NOT_USE_MEMORYMANAGER

NS_PLIB_BEGIN

//======================================================================
// Singleton instance of the class
//======================================================================
MemoryManager* pMemoryManager	= NULL;


//======================================================================
//	MemoryManager::GetManager
//
//	Returns the singleton class, or creates one if it doesn't exit
//======================================================================
MemoryManager* MemoryManager::GetManager()
{
	if (!pMemoryManager)
	{
		pMemoryManager = new MemoryManager();
	}
	return pMemoryManager;
}


//======================================================================
//	MemoryManager::MemoryManager
//
//	Default constructor
//======================================================================
MemoryManager::MemoryManager(void)
{
	MemoryPool*	p;
	int			i;

	for (i = 0; i < MEMORYPOOLS; ++i)
	{
		try
		{
			p	= NULL;
			p	= new MemoryPool();
			MemoryPools.push_back(p);
		}
		catch(...)
		{
			delete	p;
		}
	}
}


//======================================================================
//	MemoryManager::~MemoryManager
//
//	Destructor.  Because of the way memory pools get copied,
//	this function needs to call an additional function to clear
//	up the MemoryPool memory - the deconstructor on MemoryPool
//	does not actually delete its memory
//======================================================================
MemoryManager::~MemoryManager(void)
{
	ITR_MEMORYPOOLLIST	itr;

	for (itr = MemoryPools.begin(); itr != MemoryPools.end(); ++itr)
	{
		DeleteMemoryPool(*itr);
	}
	MemoryPools.clear();

	for (itr = MemoryPoolsTemp.begin(); itr != MemoryPoolsTemp.end(); ++itr)
	{
		DeleteMemoryPool(*itr);
	}
	MemoryPoolsTemp.clear();
}


//======================================================================
//	MemoryManager::DeleteMemoryPool
//======================================================================
void MemoryManager::DeleteMemoryPool(MemoryPool* pmp)
{
	pmp->ClearPool();
	delete	pmp;
}


//======================================================================
//	MemoryManager::GetTempMemory
//
//	Method that will query the correct memory pool of the calling
//	thread for a set number of bytes.  Returns 0 if there was a
//	failure in getting the memory.
//======================================================================
LPSTR MemoryManager::GetTempMemory(size_t zBytes)
{
	ITR_MEMORYPOOLLIST	itr;
	DWORD				dwThreadID	= GetCurrentThreadId();
	LPSTR				pMemory		= NULL;

	MemoryPool*			pmp	= NULL;

	for (itr = MemoryPools.begin();itr != MemoryPools.end(); ++itr)
	{
		pMemory	= (*itr)->GetTempMemory(dwThreadID, zBytes);
		if (pMemory)
		{
			return pMemory;
		}
	}

	for (itr = MemoryPoolsTemp.begin();itr != MemoryPoolsTemp.end(); ++itr)
	{
		pMemory	= (*itr)->GetTempMemory(dwThreadID, zBytes);
		if (pMemory)
		{
			return pMemory;
		}
	}

	try
	{
		pmp	= new MemoryPool(zBytes);
		MemoryPoolsTemp.push_back(pmp);
	}
	catch (...)
	{
		delete	pmp;
		return NULL;
	}

	return pmp->GetTempMemory(dwThreadID, zBytes);
}


//======================================================================
//	MemoryManager::FreeAllTempMemory
//
//	Method that tells the pool owned by the calling thread that
//	it is free to reuse all of its memory
//======================================================================
void MemoryManager::FreeAllTempMemory()
{
	DWORD	dwThreadID	= GetCurrentThreadId();
	ITR_MEMORYPOOLLIST	itr;

	for (itr = MemoryPools.begin(); itr != MemoryPools.end(); ++itr)
	{
		if ((*itr)->GetThreadID() == dwThreadID)
		{
			(*itr)->FreeAllTempMemory();
		}
	}

	for (itr = MemoryPoolsTemp.begin(); itr != MemoryPoolsTemp.end(); ++itr)
	{
		if ((*itr)->GetThreadID() == dwThreadID)
		{
			DeleteMemoryPool(*itr);
			*itr	= NULL;
		}
	}
	CleanupMemoryPools();
}


//======================================================================
//	MemoryManager::CleanupMemoryPools
//======================================================================
void MemoryManager::CleanupMemoryPools()
{
	ITR_MEMORYPOOLLIST	itr1, itr2;

	for (itr1 = MemoryPoolsTemp.begin(); itr1 != MemoryPoolsTemp.end(); )
	{
		itr2	= itr1;
		++itr1;
		if (*itr2 == NULL)
		{
			MemoryPoolsTemp.erase(itr2);
		}
	}
}

NS_PLIB_END


//======================================================================
//	GetTempMemory
//
//	Interface for C callers to ask for memory
//	See MemoryPool.h for more details
//======================================================================
LPSTR GetTempMemory(size_t zByte)
{
	return NS_PLIB::MemoryManager::GetManager()->GetTempMemory(zByte);
}

//======================================================================
//	FreeAllTempMemory
//
//	Interface for C callers to allow their memory to be reused
//	See MemoryPool.h for more details
//======================================================================
void FreeAllTempMemory()
{
	NS_PLIB::MemoryManager::GetManager()->FreeAllTempMemory();
}


NS_PLIB_MEMORY_BEGIN

//======================================================================
//	NS_PLIB::Memory::Init
//======================================================================
bool Init()
{
	try
	{
		pMemoryManager = new MemoryManager();
	}
	catch (...)
	{
		pMemoryManager = NULL;
		return false;
	}
	return true;
}

//======================================================================
//	NS_PLIB::Memory::Cleanup
//======================================================================
void Cleanup()
{
	delete pMemoryManager;
}

//======================================================================
//	NS_PLIB::Memory::Debug
//======================================================================
void Debug(std::string* pstrDebug)
{
	if (pMemoryManager)
	{
		pMemoryManager->Debug<char>(pstrDebug);
	}
}

void Debug(MemoryManager** ppmm)
{
	*ppmm	= MemoryManager::GetManager();
}

NS_PLIB_MEMORY_END
#endif	//	NOT_USE_MEMORYMANAGER
