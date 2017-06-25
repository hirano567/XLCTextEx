///***************************************************************************
// File:        MemoryManager.h
//
// Purpose:     Class definition for the memory manager used in the framework
//              library.  Includes exported methods for accessing the class
//              in C.
// 
// Platform:    Microsoft Windows
//
///***************************************************************************
#pragma once
#ifndef	NOT_USE_MEMORYMANAGER

#include <list>
#include "MemoryPool.h"

#ifndef NS_PLIB
#define NS_PLIB	PLib
#define NS_PLIB_BEGIN	namespace NS_PLIB {
#define NS_PLIB_END		}
#endif

#ifndef	NS_MEMORY
#define	NS_MEMORY	Memory
#define	NS_PLIB_MEMORY_BEGIN	namespace NS_PLIB{ namespace NS_MEMORY {
#define	NS_PLIB_MEMORY_END		}}
#endif


NS_PLIB_BEGIN

//
// Total number of memory allocation pools to manage
//

#define MEMORYPOOLS 4

//======================================================================
//	class MemoryManager
//======================================================================
class MemoryManager
{
private:
	typedef	std::list<MemoryPool*>		MEMORYPOOLLIST;
	typedef	MEMORYPOOLLIST::iterator	ITR_MEMORYPOOLLIST;

	MEMORYPOOLLIST	MemoryPools;
	MEMORYPOOLLIST	MemoryPoolsTemp;

//	MemoryPool*	CreateNewPool(DWORD dwThreadID, size_t zBytes = FW_DEFAULT_MEMORYSIZE);
//	MemoryPool*	GetMemoryPool(DWORD dwThreadID, size_t zBytes);
	void		DeleteMemoryPool(MemoryPool* pmp);

public:
	MemoryManager(void);
	~MemoryManager(void);

	static MemoryManager*	GetManager();

	LPSTR	GetTempMemory(size_t zByte);
	void	FreeAllTempMemory();
	void	CleanupMemoryPools();

	template<typename T_CHAR>
	void	Debug(std::basic_string<T_CHAR>* pstrDebug);
};

//----------------------------------------------------------------------
//	MemoryManager::Debug
//----------------------------------------------------------------------
template<typename T_CHAR>
inline void MemoryManager::Debug(std::basic_string<T_CHAR>* pstrDebug)
{
	throw std::logic_error("MemoryPool::Debug");
}
template<>
inline void MemoryManager::Debug<char>(std::string* pstrDebug)
{
#ifdef	PDEBUG

	ITR_MEMORYPOOLLIST	itr;

	pstrDebug->clear();
	pstrDebug->append("[Regular Memory Pool]\r\n\r\n");

	for (itr = MemoryPools.begin(); itr != MemoryPools.end(); ++itr)
	{
		(*itr)->Debug<char>(pstrDebug);
		pstrDebug->append("\r\n");
	}

	if (MemoryPoolsTemp.empty())
	{
		pstrDebug->append("[Temporary Memory Pool]\tnone\r\n\r\n");
	}
	else
	{
		pstrDebug->append("[Temporary Memory Pool]\r\n\r\n");

		for (itr = MemoryPoolsTemp.begin(); itr != MemoryPoolsTemp.end(); ++itr)
		{
			(*itr)->Debug(pstrDebug);
			pstrDebug->append("\n");
		}
	}

#endif
}

NS_PLIB_END

//======================================================================
// Defines functions for accessing class from a C projects
//======================================================================
//LPSTR	MGetTempMemory(size_t zByte);
//void	MFreeAllTempMemory();

LPSTR	GetTempMemory(size_t zBytes);
void	FreeAllTempMemory();

NS_PLIB_MEMORY_BEGIN

bool	Init();
void	Cleanup();

void	Debug(std::string* pstrDebug);
void	Debug(MemoryManager** ppmm);

NS_PLIB_MEMORY_END
#endif	//	NOT_USE_MEMORYMANAGER
