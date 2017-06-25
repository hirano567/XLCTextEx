//	XLCTextEx_1.0x	:	Test

//	XLCTextEx_1.01	2013/06/02
//	XLCTextEx_1.02

// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���̃C���N���[�h �t�@�C���A�܂���
// �Q�Ɖ񐔂������A�����܂�ύX����Ȃ��A�v���W�F�N�g��p�̃C���N���[�h �t�@�C��
// ���L�q���܂��B
//
#pragma once

#define	_CRTDBG_MAP_ALLOC
#include "targetver.h"

#include <windows.h>
#include <cstdlib>
#include <crtdbg.h>	//	������ ���[�N���o
#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include <string>
#include <iostream>

// TODO: �v���O�����ɕK�v�Ȓǉ��w�b�_�[�������ŎQ�Ƃ��Ă��������B
#include "PLib.h"
#include "PLibUCD.h"
#include "PLibTextEx.h"

#ifndef	NS_TEST
#define	NS_TEST			PTest
#define	NS_TEST_BEGIN	namespace NS_TEST	{
#define	NS_TEST_END		}
#endif

#include "TestUtility.h"
#include "DataRegEx01.h"
#include "DataRegEx02.h"
#include "DataRegEx03.h"
#include "DataRegEx05.h"

void	TestPLib01();
void	TestPUCD01();
void	TestPRegEx01();
void	TestPRegEx02();
void	TestPRegEx03();
void	TestPRegEx05();
void	TestPTr01();

void	Prototype01();

