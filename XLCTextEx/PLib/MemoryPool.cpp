///***************************************************************************
// File:        MemoryPool.cpp
//
// Purpose:     A memory pool is an array of characters that is pre-allocated,
//              and used as temporary memory by the caller. The allocation
//              algorithm is very simple. When a thread asks for some memory,
//              the index into the array moves forward by that many bytes, and
//              a pointer is returned to the previous index before the pointer
//              was advanced. When a call comes to free all of the memory, the
//              pointer is set back to the beginning of the array.
//
//              Each pool has MEMORYSIZE bytes of storage space available to it
// 
// Platform:    Microsoft Windows
//
///***************************************************************************

//#include "MemoryPool.h"

#include "stdafx.h"
#ifndef	NOT_USE_MEMORYMANAGER

NS_PLIB_BEGIN

#define	MEMORY_POOL_MAX_SIZE	INT_MAX

//======================================================================
//	MemoryPool::MemoryPool
//
//	Constructor creates the memory to be used by the pool
//	and starts the index at the beginning.
//======================================================================
MemoryPool::MemoryPool(size_t zBytes)
:	pMemoryBlock(NULL),
	zMemoryBlock(0),
	zOffset(0),
	dwOwnerThread(NO_OWNER_THREAD)
{
	if (zBytes > MEMORY_POOL_MAX_SIZE)	return;

	zMemoryBlock	= FW_DEFAULT_MEMORYSIZE;
	while(zMemoryBlock < zBytes)	zMemoryBlock *= 2;

	try
	{
		pMemoryBlock	= new char[zMemoryBlock];
	}
	catch (...)
	{
		pMemoryBlock	= NULL;
		zMemoryBlock	= 0;
	}
}

//======================================================================
//	MemoryPool::~MemoryPool
//
//	An empty destructor - see reasoning below
//======================================================================
MemoryPool::~MemoryPool(void)
{
}

//======================================================================
//	MemoryPool::ClearPool
//
//	Unable to delete the memory block when we delete the pool,
//	as it may be still be in use due to a GrowPools() call; this
//	method will actually delete the pool's memory
//======================================================================
void MemoryPool::ClearPool(void)
{
	delete[]	pMemoryBlock;
}

//======================================================================
//	MemoryPool::GetTempMemory
//	Advances the index forward by the given number of bytes.
//	Should there not be enough memory, or the number of bytes
//	is not allowed, this method will return 0. Can be called
//	and used exactly as malloc().
//======================================================================
LPSTR MemoryPool::GetTempMemory(DWORD dwId, size_t zBytes)
{
	LPSTR pMemory;

	if (!Unused() && GetThreadID() != dwId)	return NULL;

	if (zBytes > 0 && zOffset + zBytes <= zMemoryBlock)
	{
		pMemory	= (LPSTR)(pMemoryBlock + zOffset);
		zOffset	+= zBytes;
		SetThreadID(dwId);

		return pMemory;
	}
	return NULL;
}

//======================================================================
// Frees all the temporary memory by setting the index for
// available memory back to the beginning
//======================================================================
void MemoryPool::FreeAllTempMemory()
{
	zOffset	= 0;
	ResetThreadId();
}

NS_PLIB_END
#endif	//	NOT_USE_MEMORYMANAGER
