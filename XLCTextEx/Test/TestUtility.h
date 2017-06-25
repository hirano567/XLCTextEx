//	XLCTextEx_1.0x	:	Test

//	TestUtility.h
//
#pragma once

NS_TEST_BEGIN

//======================================================================
//
//======================================================================
void	AppendTF(T_STRING_U* pstrBuf, bool br, T_PCSTR_U pszPre = NULL, T_PCSTR_U pszPost = NULL);
void	GetCStrOptDesc(T_STRING_U* pstrOpt, DWORD dwFlags);
void	CreateTestData();

NS_TEST_END
