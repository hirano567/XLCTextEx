//	XLCTextEx_1.0x	:	PLibTextEx

//	PRegExDebug.cpp
//
#pragma once

NS_PLIB_BEGIN
#ifdef	PDEBUG

//======================================================================
//	�f�o�b�O����\�����邽�߂̕�������o�͂���֐�
//======================================================================
T_PCSTR_U	PRegExDebug_GetToken(int iToken);
T_PCSTR_U	PRegExDebug_GetPosixCharClass(int iClass);

/*
//======================================================================
//	Profile
//======================================================================
#ifdef	PDEBUG_PROFILE

size_t	PRegExProfiler_Size();
void	PRegExProfiler_Reset();
void	PRegExProfiler_Reset(UINT i);
void	PRegExProfiler_Start(UINT i);
void	PRegExProfiler_Stop(UINT i);
DWORD	PRegExProfiler_GetInterval(UINT i);
DWORD	PRegExProfiler_GetTotal(UINT i);

#endif
*/
#endif
NS_PLIB_END
