//	XLCTextEx_1.1x	:	Utility

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
#include <string>

// TODO: �v���O�����ɕK�v�Ȓǉ��w�b�_�[�������ŎQ�Ƃ��Ă��������B
#include "PLib.h"
#include "PLibUCD.h"
#include "PLibTextEx.h"

#ifndef	NS_UTILITY
#define	NS_UTILITY			PUtility
#define	NS_UTILITY_BEGIN	namespace NS_UTILITY	{
#define	NS_UTILITY_END		}
#endif

void	UtilityUCD01();
