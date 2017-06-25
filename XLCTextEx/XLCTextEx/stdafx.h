//	XLCTextEx_1.0x	:	XLCTextEx

//	XLCTextEx_1.01	2013/06/02
//	XLCTextEx_1.02	2013/06/14

// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���̃C���N���[�h �t�@�C���A�܂���
// �Q�Ɖ񐔂������A�����܂�ύX����Ȃ��A�v���W�F�N�g��p�̃C���N���[�h �t�@�C��
// ���L�q���܂��B
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Windows �w�b�_�[����g�p����Ă��Ȃ����������O���܂��B
// Windows �w�b�_�[ �t�@�C��:
#include <windows.h>

// TODO: �v���O�����ɕK�v�Ȓǉ��w�b�_�[�������ŎQ�Ƃ��Ă��������B

//#define	XLL_AVAILABLE_TO_EXCEL11
#undef	XLL_AVAILABLE_TO_EXCEL11

#include "PLib.h"
#include "PLibUCD.h"
#include "PLibTextEx.h"
#include "PLibXLL.h"

#ifndef	NS_XLCTEXTEX
#define	NS_XLCTEXTEX		XLCTextEx
#define	NS_XLCTEXTEX_BEGIN	namespace NS_XLCTEXTEX {
#define	NS_XLCTEXTEX_END	}
#endif

#ifndef	NS_XLCREGEX
#define	NS_XLCREGEX	XLCRegEx
#define	NS_XLCREGEX_BEGIN	namespace NS_XLCREGEX {
#define	NS_XLCREGEX_END		}
#endif

#ifndef	NS_XLCTR
#define	NS_XLCTR		XLCTr
#define	NS_XLCTR_BEGIN	namespace NS_XLCTR {
#define	NS_XLCTR_END	}
#endif

typedef	PLib::PCTransChar	CTRANSCHAR;

#include "XLCRegExError.h"
#include "XLCRegExUtility.h"
#include "XLCRegEx.h"

#include "XLCTrUtility.h"
#include "XLCTr.h"
#include "XLCGrep.h"

#include "XLCTextEx.h"
#include "dllmain.h"
#include "XLLMain.h"
#include "XLLTest.h"
