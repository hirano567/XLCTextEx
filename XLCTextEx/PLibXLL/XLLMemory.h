//	XLCTextEx_1.0x	:	PLibXLL

//	XLLMemory.h
//
#pragma once

NS_XLL_BEGIN

//======================================================================
//	XLOPER ç\ë¢ëÃÇ÷ÇÃÉÅÉÇÉääÑÇËìñÇƒ
//======================================================================

XLOPER*		AllocateXLOPER4();
XLOPER12*	AllocateXLOPER12();
void		DeallocateXLOPER4(XLOPER* px);
void		DeallocateXLOPER12(XLOPER12* px);
void		ClearIPXLOPER();
void		CleanupIPXLOPER();

void		InitXLLMemory();
void		CleanupXLLMemory();

//----------------------------------------------------------------------
//	AllocateXLOPER
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline T_XLOPER* AllocateXLOPER()
{
	THROWPE_LOGIC_ERROR("AllocateXLOPER");
	return NULL;
}
template<>
inline XLOPER* AllocateXLOPER<XLOPER>()
{
	return AllocateXLOPER4();
}
template<>
inline XLOPER12* AllocateXLOPER<XLOPER12>()
{
	return AllocateXLOPER12();
}

//----------------------------------------------------------------------
//	DeallocateXLOPER
//----------------------------------------------------------------------
template<typename T_XLOPER>
inline void DeallocateXLOPER(T_XLOPER* px)
{
	THROWPE_LOGIC_ERROR("DeallocateXLOPER");
	return NULL;
}
template<>
inline void DeallocateXLOPER<XLOPER>(XLOPER* px)
{
	DeallocateXLOPER4(px);
}
template<>
inline void DeallocateXLOPER<XLOPER12>(XLOPER12* px)
{
	DeallocateXLOPER12(px);
}

NS_XLL_END
