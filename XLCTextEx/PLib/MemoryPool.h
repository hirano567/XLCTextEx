///***************************************************************************
// File:		MemoryPool.h
//
// Purpose:		Class definition for the memory pool class used by the
//				memory manager.  Each pool is a block of memory set
//				aside for a specific thread for use in creating temporary
//				XLOPER/XLOPER12's in the framework
// 
// Platform:    Microsoft Windows
//
///***************************************************************************
#pragma once
#ifndef	NOT_USE_MEMORYMANAGER

#include <windows.h>

#ifndef NS_PLIB
#define NS_PLIB	PLib
#define NS_PLIB_BEGIN	namespace NS_PLIB {
#define NS_PLIB_END		}
#endif

NS_PLIB_BEGIN

//
// Total amount of memory to allocate for all temporary XLOPERs
//

#define FW_DEFAULT_MEMORYSIZE	8192
#define	NO_OWNER_THREAD			(DWORD)(-1)

//======================================================================
//	class MemoryPool
//======================================================================
class MemoryPool
{
private:
	DWORD	dwOwnerThread;	// ID of ownning thread
	char*	pMemoryBlock;	// Memory for temporary XLOPERs
	size_t	zMemoryBlock;
	size_t	zOffset;		// Offset of next memory block to allocate

public:
	MemoryPool(size_t zBytes = FW_DEFAULT_MEMORYSIZE);
	~MemoryPool(void);

	DWORD	GetThreadID()			{ return dwOwnerThread; }
	void	SetThreadID(DWORD dwID)	{ dwOwnerThread = dwID; }
	void	ResetThreadId()			{ dwOwnerThread = NO_OWNER_THREAD; }
	BOOL	Unused()				{ return (dwOwnerThread == NO_OWNER_THREAD); }
	size_t	Capacity()				{ return (zMemoryBlock - zOffset); }

	void	ClearPool();
	LPSTR	GetTempMemory(DWORD dwId, size_t zBytes);
	void	FreeAllTempMemory();

	template<typename T_CHAR>
	void	Debug(std::basic_string<T_CHAR>* pstrDebug);
};

//----------------------------------------------------------------------
//	MemoryPool::Debug
//----------------------------------------------------------------------
template<typename T_CHAR>
inline void MemoryPool::Debug(std::basic_string<T_CHAR>* pstrDebug)
{
	throw std::logic_error("MemoryPool::Debug");
}
template<>
inline void MemoryPool::Debug<char>(std::string* pstrDebug)
{
#ifdef	PDEBUG

	const size_t	zBuf	= 256;
	char	Buf[zBuf];

	if (sprintf_s(Buf, zBuf, "dwOwnerThread: %d\r\n", dwOwnerThread) > 0)
		pstrDebug->append(Buf);
	if (sprintf_s(Buf, zBuf, "zMemoryBlock : %d\r\n", zMemoryBlock) > 0)
		pstrDebug->append(Buf);
	if (sprintf_s(Buf, zBuf, "zOffset      : %d\r\n", zOffset) > 0)
		pstrDebug->append(Buf);

#endif
}

NS_PLIB_END
#endif	//	NOT_USE_MEMORYMANAGER
