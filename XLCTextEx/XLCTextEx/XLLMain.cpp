//	XLCTextEx_1.0x	:	XLCTextEx

//	XLLMain.cpp
//
#include "stdafx.h"

#undef	REGISTER_XLLFUNCTIONS
#undef	REGISTER_COMMANDFUNCTIONS
#undef	REGISTER_MENUITEMS
#undef	REGISTER_TOOLBARITEMS

#define	REGISTER_XLLFUNCTIONS
//#define	REGISTER_COMMANDFUNCTIONS
//#define	REGISTER_MENUITEMS
//#define	REGISTER_TOOLBARITEMS


//======================================================================
//	XLL �֐���o�^�E�������邽�߂̃f�[�^�Ɗ֐�
//======================================================================
#ifdef REGISTER_XLLFUNCTIONS

const int	nParamsRgXLLFunc	= 15;

typedef	PCSTRAW PAW_RGXLLFUNCTION[nParamsRgXLLFunc];

static PAW_RGXLLFUNCTION	pawRgXLLFunctions[] =
{
//	TEXTAW(""),	//	DLL �̃R�[�h���Ɍ����֐����B
//	TEXTAW(""),	//	�����̌^�Ɩ߂�l�̌^���w�肷�镶����B
//	TEXTAW(""),	//	�֐��E�B�U�[�h�ŕ\�������֐����B
//	TEXTAW(""),	//	�ȗ��\�B������������镶����B
//	TEXTAW(""),	//	XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
//	TEXTAW(""),	//	�֐���������J�e�S���B�ȗ��\�B
//	TEXTAW(""),	//	�V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
//	TEXTAW(""),	//	�w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
//	TEXTAW(""),	//	�֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
//	TEXTAW(""),	//	1 �Ԗڂ̈����̐����B�ȗ��\�B
//	TEXTAW(""),	//	2 �Ԗڂ̈����̐����B�ȗ��\�B
//	TEXTAW(""),	//	3 �Ԗڂ̈����̐����B�ȗ��\�B
//	TEXTAW(""),	//	4 �Ԗڂ̈����̐����B�ȗ��\�B
//	TEXTAW(""),	//	5 �Ԗڂ̈����̐����B�ȗ��\�B
//	TEXTAW(""),	//	6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//
	//------------------------------------------------------------
	/*
	"XLCRegExCreateA",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCRegExCreate",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	"PP",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"QQ",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	"XLCRegExCreateA",	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	L"XLCRegExCreate",	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B

	TEXTAW("������ �C���f�b�N�X�� URL"),		//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("���\�[�X�擾�̏���������B"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("���蓖�Ă�C���f�b�N�X�i�����l�j"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("URL"),				//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B
	*/

	//------------------------------------------------------------
	//
	//------------------------------------------------------------
	/*
	"XLCRegExReplaceA",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCRegExReplace",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	"PPPPP",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"QQQQQ",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	"XLCRegExReplaceA",	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	L"XLCRegExReplace",	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B

	TEXTAW("������ �C���f�b�N�X�� ID"),		//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("ID �ɑΉ����镔�����擾����B"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("���K�\��"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�o�͏���"),				//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�Ώۃe�L�X�g"),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�啶��������"),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B
	*/

	//------------------------------------------------------------
	//	XLCRegExCreate
	//------------------------------------------------------------
	"XLCRegExCreate4",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCRegExCreate12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PPPP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQQQ",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RPPP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQQ",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCRegExCreate"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("������ �p�^�[���ƃI�v�V����"),		//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�p�^�[����o�^����"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("���蓖�Ă�ԍ�"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�p�^�[��"),		//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�I�v�V����"),	//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCRegExDelete
	//------------------------------------------------------------
	"XLCRegExDelete4",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCRegExDelete12",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQ",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQ",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCRegExDelete"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�����͔ԍ�"),	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�p�^�[�����폜����"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�폜����ԍ�"),			//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCRegExClear
	//------------------------------------------------------------
	"XLCRegExClear4",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCRegExClear12",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQ",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQ",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCRegExClear"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�����͍폜�Ώۂ����� BOOL �l"),	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�p�^�[�������ׂč폜����"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("TRUE �Ȃ炷�ׂāAFALSE �Ȃ猻�V�[�g�̂�"),	//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCRegExCreateReplacement
	//------------------------------------------------------------
	"XLCRegExCreateReplacement4",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCRegExCreateReplacement12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PPPP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQQQ",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RPPP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQQ",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCRegExCreateReplacement"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�����͒u��������ƃI�v�V����"),		//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�u���������o�^����"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("���蓖�Ă�ԍ�"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�o�͏���"),		//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�I�v�V����"),	//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCRegExDeleteReplacement
	//------------------------------------------------------------
	"XLCRegExDeleteReplacement4",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCRegExDeleteReplacement12",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQ",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQ",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCRegExDeleteReplacement"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�����͔ԍ�"),	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�u����������폜����"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�폜����ԍ�"),			//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCRegExClearReplacement
	//------------------------------------------------------------
	"XLCRegExClearReplacement4",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCRegExClearReplacement12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQ",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQ",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCRegExClearReplacement"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�����͍폜�Ώۂ����� BOOL �l"),	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�u������������ׂč폜����"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("TRUE �Ȃ炷�ׂāAFALSE �Ȃ猻�V�[�g�̂�"),	//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCRegExMatch
	//------------------------------------------------------------
	"XLCRegExMatch4",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCRegExMatch12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PPPPP",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQQQQ",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RPPP",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQQ$",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCRegExMatch"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�p�^�[���i�̔ԍ��j�A�Ώۃe�L�X�g�A�I�v�V����"),
	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�p�^�[���Ƀe�L�X�g���}�b�`���Ă��邩���ׂ�"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�p�^�[��"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�Ώۃe�L�X�g"),	//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�I�v�V����"),	//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCRegExFormat
	//------------------------------------------------------------
	"XLCRegExFormat4",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCRegExFormat12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PPPPP",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQQQQ",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RPPPP",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQQQ$",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCRegExFormat"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�p�^�[���i�̔ԍ��j�A�����i�̔ԍ��j�A�Ώۃe�L�X�g�A�I�v�V����"),
	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�p�^�[���Ə����ɏ]���ăe�L�X�g�𐮌`����"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�p�^�[��"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�o�͏���"),		//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�Ώۃe�L�X�g"),	//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�I�v�V����"),	//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCRegExFormatIf
	//------------------------------------------------------------
	"XLCRegExFormatIf4",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCRegExFormatIf12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PPPPP",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQQQQ",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RPPPPP",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQQQQ$",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCRegExFormatIf"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�p�^�[���i�̔ԍ��j�A�����i�̔ԍ��j�A�Ώۃe�L�X�g�A�I�v�V����"),
	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�p�^�[���Ə����ɏ]���ăe�L�X�g�𐮌`����"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�p�^�[��"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�}�b�`�����ꍇ�̏o�͏���")	,		//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�}�b�`���Ȃ������ꍇ�̏o�͕�����"),	//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�Ώۃe�L�X�g"),	//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�I�v�V����"),	//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCRegExReplace
	//------------------------------------------------------------
	"XLCRegExReplace4",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCRegExReplace12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PPPPP",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQQQQ",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RPPPP",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQQQ$",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCRegExReplace"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�p�^�[���i�̔ԍ��j�A�����i�̔ԍ��j�A�Ώۃe�L�X�g�A�I�v�V����"),
	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�p�^�[���Ə����ɏ]���ăe�L�X�g�𐮌`����"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�p�^�[��"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�o�͏���"),		//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�Ώۃe�L�X�g"),			//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�p�^�[���̃I�v�V����"),	//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCRegExValue
	//------------------------------------------------------------
	"XLCRegExValue4",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCRegExValue12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PPPPP",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQQQQ",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RPPPPP",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQQQQ$",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCRegExValue"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�p�^�[���i�̔ԍ��j�A�����i�̔ԍ��j�A�Ώۃe�L�X�g�A�I�v�V�����A��֒l"),
	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�p�^�[���Ə����ɏ]���ăe�L�X�g���琔�l�����o��"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�p�^�[��"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�o�͏���"),		//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�Ώۃe�L�X�g"),			//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�p�^�[���̃I�v�V����"),	//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�G���[���ɏo�͂���l"),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCRegExError
	//------------------------------------------------------------
	"XLCRegExError4",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCRegExError12",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQ",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQ",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCRegExError"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B

	TEXTAW(""),				//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�G���[���b�Z�[�W���擾����B"),		//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("���b�Z�[�W�ԍ��i�ŐV�� 0�j"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCTrCreate
	//------------------------------------------------------------
	"XLCTrCreate4",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCTrCreate12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PPPPP",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQQQQ",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RPPPP",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQQQ",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCTrCreate"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("ID�A�ϊ��������A�ϊ��敶���A�I�v�V����"),
	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW(""),				//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�����ϊ���o�^����B"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("ID �ƂȂ鐮���l"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�ϊ���̕�������ׂ�������"),		//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�ϊ���̕�������ׂ�������"),	//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�I�v�V����"),	//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCTrDelete
	//------------------------------------------------------------
	"XLCTrDelete4",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCTrDelete12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PPPPP",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQQQQ",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RP",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQ",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCTrDelete"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("ID"),
	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW(""),				//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�o�^���������ϊ����폜����B"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("���蓖�Ă� ID"),	//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),					//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),					//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),					//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),					//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),					//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCTr
	//------------------------------------------------------------
	"XLCTr4",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCTr12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	"RPPPP",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQQQ$",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCTr"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�ϊ��������A�ϊ��敶���A�Ώۃe�L�X�g�A�I�v�V����"),
	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�Z�����̕�����Ή����镶���ɒu��������֐�"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�ϊ���̕�������ׂ�������"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�ϊ���̕�������ׂ�������"),		//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�Ώۃe�L�X�g"),	//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("�I�v�V����"),	//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCToHiragana
	//------------------------------------------------------------
	"XLCToHiragana4",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCToHiragana12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	"RPP",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQ$",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCToHiragana"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�Ώۃe�L�X�g"),	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�Z�����̕������Ђ炪�Ȃɒu������֐�"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�Ώۃe�L�X�g"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCToKatakana
	//------------------------------------------------------------
	"XLCToKatakana4",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCToKatakana12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	"RPP",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQ$",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCToKatakana"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�Ώۃe�L�X�g"),	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�Z�����̕������J�^�J�i�ɒu������֐�"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�Ώۃe�L�X�g"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCToZenkaku
	//------------------------------------------------------------
	"XLCToZenkaku4",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCToZenkaku12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	"RPP",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQ$",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCToZenkaku"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�Ώۃe�L�X�g"),	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�Z�����̕�����S�p�ɒu������֐�"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�Ώۃe�L�X�g"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCToZenkakuKana
	//------------------------------------------------------------
	"XLCToZenkakuKana4",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCToZenkakuKana12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	"RPP",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQ$",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCToZenkakuKana"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�Ώۃe�L�X�g"),		//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),				//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),			//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),					//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),					//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�Z�����̃J�i������S�p�ɒu������֐�"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�Ώۃe�L�X�g"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCToHankaku
	//------------------------------------------------------------
	"XLCToHankaku4",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCToHankaku12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	"RPP",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQ$",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCToHankaku"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�Ώۃe�L�X�g"),	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�Z�����̕�����S�p�ɒu������֐�"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�Ώۃe�L�X�g"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCNormalizeWidth
	//------------------------------------------------------------
	"XLCNormalizeWidth4",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCNormalizeWidth12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	"RPP",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQ$",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCNormalizeWidth"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�Ώۃe�L�X�g"),	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�p���𔼊p�ɁA�J�^�J�i��S�p�ɕϊ�����֐�"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�Ώۃe�L�X�g"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCGrep
	//------------------------------------------------------------
	"XLCGrep4",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCGrep12",	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PPPPP",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQQQQ",			//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"JDDD",				//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"JD%D%D%$",		//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCGrep"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
	TEXTAW("�p�^�[���A�I�v�V����1�A�I�v�V����2"),
	//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("2"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�p�^�[���Ƀ}�b�`����s�����o���B"), //	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�p�^�[��"),		//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("���K�\���̃I�v�V����"),		//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW("���̑��̃I�v�V����"),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

	//------------------------------------------------------------
	//	XLCTextExSet
	//------------------------------------------------------------
	"XLCTextExSet4",			//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCTextExSet12",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQ",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RPPP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQQQ",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCTextExSet"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B

	TEXTAW(""),				//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("TextEx �ݒ�"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B

#ifdef	PDEBUG
	//------------------------------------------------------------
	//	XLCTextExTest
	//------------------------------------------------------------
	"XLCTextExTest4",			//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
	L"XLCTextExTest12",		//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B

	//"PP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	//L"QQ",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	"RP",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
	L"UQ",					//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B

	TEXTAW("XLCTextExTest"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B

	TEXTAW(""),				//	(xltypeStr) �ȗ��\�B������������镶����B
	TEXTAW("1"),			//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
	TEXTAW("TextEx"),		//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
	TEXTAW(""),				//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
	TEXTAW("�쐬�⏕�A�e�X�g�p�B"),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
	TEXTAW("�����ɐ����͂Ȃ��B"),	//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
	TEXTAW(""),				//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B
#endif
};

static int	nRgXLLFunctions		= sizeof(pawRgXLLFunctions) / sizeof(PAW_RGXLLFUNCTION);
static BOOL	bRegisterXLLFunctions	= FALSE;

#endif


//======================================================================
//	�R�}���h�֐��̓o�^�E���������邽�߂̃f�[�^�Ɗ֐�
//======================================================================
#ifdef REGISTER_COMMANDFUNCTIONS

const int	irgCommandArgs	= 15;

//static RGFUNCTIONARGS rgCommandFunctions[] =
static PCSTRAW rgCommands[][irgCommandArgs] =
{
//	7,
//	TEXTAW(""),	//	(xltypeStr) DLL �̃R�[�h���Ɍ����֐����B
//	TEXTAW(""),	//	(xltypeStr) �����̌^�Ɩ߂�l�̌^���w�肷�镶����B
//	TEXTAW(""),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������֐����B
//	TEXTAW(""),	//	(xltypeStr) �ȗ��\�B������������镶����B
//	TEXTAW(""),	//	(xltypeNum) XLL �̃G���g���|�C���g�̃^�C�v�B�ȗ��\(����l�� 1)�B
//	TEXTAW(""),	//	(xltypeStr) �֐���������J�e�S���B�ȗ��\�B
//	TEXTAW(""),	//	(xltypeStr) �V���[�g�J�b�g�L�[�B�P�����B�啶���������͋�ʂ����B
//	TEXTAW(""),	//	(xltypeStr) �w���v�t�@�C���ւ̎Q�Ɓi�p�X���܂ށj�B�ȗ��\�B
//	TEXTAW(""),	//	(xltypeStr) �֐��E�B�U�[�h�ŕ\�������e�L�X�g�B�ȗ��\�B
//	TEXTAW(""),	//	(xltypeStr) 1 �Ԗڂ̈����̐����B�ȗ��\�B
//	TEXTAW(""),	//	(xltypeStr) 2 �Ԗڂ̈����̐����B�ȗ��\�B
//	TEXTAW(""),	//	(xltypeStr) 3 �Ԗڂ̈����̐����B�ȗ��\�B
//	TEXTAW(""),	//	(xltypeStr) 4 �Ԗڂ̈����̐����B�ȗ��\�B
//	TEXTAW(""),	//	(xltypeStr) 5 �Ԗڂ̈����̐����B�ȗ��\�B
//	TEXTAW(""),	//	(xltypeStr) 6 �Ԗڂ̈����̐����B�ȗ��\�B
};

static int	irgCommands			= sizeof(rgCommands) / (sizeof(PCSTRAW) * irgCommandArgs);
static BOOL	bRegisterCommands	= FALSE;

//----------------------------------------------------------------------
//	RegisterCommandFunctions
//----------------------------------------------------------------------
static BOOL RegisterCommandFunctions()
{
	BOOL	bRet;

	if (XLL::IsExcel12())
	{
		//	Excel12
		bRet	= t_RegisterFunctions<XLOPER12>((PCSTRAW*)rgCommands, irgCommands, irgCommandArgs);
	}
	else
	{
		//	Excel4
		bRet	= t_RegisterFunctions<XLOPER>((PCSTRAW*)rgCommands, irgCommands, irgCommandArgs);
	}

	bRegisterCommands	= TRUE;
	return TRUE;
}

//----------------------------------------------------------------------
//	UnregisterCommandFunctions
//----------------------------------------------------------------------
static BOOL UnregisterCommandFunctions()
{
	BOOL	bRet;

	if (!bRegisterCommands)	return TRUE;

	if (XLL::IsExcel12())
	{
		//	Excel12
		bRet	= t_UnRegisterFunctions<XLOPER12>((PCSTRAW*)rgCommands, irgCommands, irgCommandArgs);
	}
	else
	{
		//	Excel4
		bRet	= t_UnRegisterFunctions<XLOPER>((PCSTRAW*)rgCommands, irgCommands, irgCommandArgs);
	}

	return TRUE;
}

#endif


//======================================================================
//	���j���[���ڂ�o�^�E���������邽�߂̃f�[�^�Ɗ֐�
//======================================================================
#ifdef	REGISTER_MENUITEMS

PCSTRAW rgMenus[][NUM_MENUARGS] =
{
//	TEXTAW(""),	//	�R�}���h�̖��O
//	TEXTAW(""),	//	���s�����}�N��
//	TEXTAW(""),	//	�V���[�g�J�b�g�L�[�iMacintosh �ł̂݁j
//	TEXTAW(""),	//	�X�e�[�^�X�o�[�ɕ\�������e�L�X�g
//	TEXTAW(""),	//	�w���v�p�̃e�L�X�g
};

int			irgMenus	= sizeof(rgMenus) / (sizeof(PCSTRAW) * NUM_MENUARGS);

static BOOL	bRegisterMenuItems	= FALSE;

//----------------------------------------------------------------------
//	RegisterMenuItems
//----------------------------------------------------------------------
static BOOL RegisterMenuItems()
{
#ifndef	NOT_REGISTER_MENUITEMS

	BOOL	bRet;

	if (XLL::IsExcel12())
	{
		//	Excel12
		bRet	= t_AddMenu<XLOPER12>((PCSTRAW*)rgMenus, irgMenus);
	}
	else
	{
		//	Excel4
		bRet	= t_AddMenu<XLOPER>((PCSTRAW*)rgMenus, irgMenus);
	}

	bRegisterMenuItems	= TRUE;
	return TRUE;
}

//----------------------------------------------------------------------
//	UnregisterMenuItems
//----------------------------------------------------------------------
static BOOL UnregisterMenuItems()
{
	BOOL	bRet;

	if (!bRegisterMenuItems)	return TRUE;

	if (XLL::IsExcel12())
	{
		//	Excel12
		bRet	= t_DeleteMenu<XLOPER12>();
	}
	else
	{
		//	Excel4
		bRet	= t_DeleteMenu<XLOPER>();
	}
	return TRUE;
}

#endif


//======================================================================
//	�c�[���o�[���ڂ�o�^�E���������邽�߂̃f�[�^�Ɗ֐�
//======================================================================
#ifdef	REGISTER_TOOLBARITEMS

const int	nrgToolArgs	= 9;
typedef	PCSTRAW	RGTOOLARGS[nrgToolArgs];

static RGTOOLARGS rgTools[] =
{
//	TEXTAW(""),			//	xltypeStr	�c�[���Ɋ֘A�����ԍ������O�B
//	TEXTAW(""),			//	xltypeStr	���s�����}�N��
//	TEXTAW("FALSE"),	//	xltypeBOOL	Down
//	TEXTAW("TRUE"),	//	Enabled
//	TEXTAW(""),	//	Face
//	TEXTAW(""),	//	Status_text
//	TEXTAW(""),	//	Ballon_text
//	TEXTAW(""),	//	Help_topic
//	TEXTAW(""),	//	Tip_text
};

static RGTOOLARGS rgTools[] =
{
//	TEXTAW(""),	//	xltypeStr	�c�[���̖��O�B�i�ԍ����B�j
//	TEXTAW(""),	//	xltypeStr	�}�N���̖��O�B
//	FALSE,		//	xltypeBool	�����ꂽ��Ԃŕ\������B
//	TRUE,		//	xltypeBool	�g�p�\�B
//	TEXTAW(""),	//	xltypeStr	�摜�ւ̎Q�ƁB
//	TEXTAW(""),	//	xltypeStr	�X�e�[�^�X�o�[�ɕ\������e�L�X�g�B
//	TEXTAW(""),	//	xltypeStr	�o���[���p�̃e�L�X�g�B
//	TEXTAW(""),	//	xltypeStr	�w���v�t�@�C���̃g�s�b�N�ւ̎Q��
//	TEXTAW(""),	//	xltypeStr	�c�[���`�b�v�p�̃e�L�X�g�B
};

static int	nrgTools				= sizeof(rgTools) / sizeof(RGTOOLARGS);
static BOOL	bRegisterToolbarItems	= FALSE;

#endif

//----------------------------------------------------------------------
//	RegisterToolbarItems
//----------------------------------------------------------------------
static BOOL RegisterToolbarItems()
{
	XLOPER4		xRes4;
	XLOPER12	xRes12;

	HGLOBAL		hGlobal;
	LPXLOPER	pxGlobal4;
	LPXLOPER12	pxGlobal12;
	LPXLOPER	px4;
	LPXLOPER12	px12;

	int			i;
	int			iRet;

	if (nrgTools < 1)	return TRUE;

	//------------------------------------------------------------
	//	Excel12
	//------------------------------------------------------------
	if (XLL::IsExcel12())
	{
		hGlobal	= GlobalAlloc(GMEM_MOVEABLE, sizeof(XLOPER12) * nrgToolArgs * nrgTools);
		pxGlobal12	= (LPXLOPER12)GlobalLock(hGlobal);
		px12		= pxGlobal12;
		for (i = 0; i < nrgTools; ++i)
		{
			SET_XLOPER_STR_12(px12, rgTools[i].pszToolId.w);			++px12;
			SET_XLOPER_STR_12(px12, rgTools[i].pszMacro.w);			++px12;
			SET_XLOPER_BOOL_12(px12, rgTools[i].bDown);				++px12;
			SET_XLOPER_BOOL_12(px12, rgTools[i].bEnabled);			++px12;
			SET_XLOPER_STR_12(px12, rgTools[i].pszFace.w);			++px12;
			SET_XLOPER_STR_12(px12, rgTools[i].pszStatusTtext.w);	++px12;
			SET_XLOPER_STR_12(px12, rgTools[i].pszBallonTtext.w);	++px12;
			SET_XLOPER_STR_12(px12, rgTools[i].pszHelpTopic.w);		++px12;
			SET_XLOPER_STR_12(px12, rgTools[i].pszTipText.w);		++px12;
			for (j = 0; j < nrgToolArgs; ++j)
			{
				SET_XLOPER_STR_12(px12, rgTools[i][j].w);
				++px12;
			}
		}

		xTemp12.xltype	= xltypeMulti;
		xTemp12.val.array.lparray	= pxGlobal12;
		xTemp12.val.array.rows		= nrgTools;
		xTemp12.val.array.columns	= nrgToolArgs;

#ifdef PDEBUG
		WSTRING	strDebug;
		XLL::ShowXLOPER12(strDebug, &xTemp12);
#endif

		//Excel12f(xlfAddToolbar, &xRes12, 2, cxXLLTitle12.px(), (LPXLOPER12)&xTemp12);
		Excel12f(xlfAddToolbar, &xRes12, 1, cxXLLTitle12.px());
		//Excel12f(xlfAddToolbar, &xRes12, 2, (LPXLOPER12)&xXLLTitle12, &xMissing12);

		iRet = Excel12f(xlcShowToolbar, &xRes12, 10,
			cxXLLTitle12.px(),				//	xltypeStr	�c�[���o�[�̖��O�B
			(LPXLOPER12)TempBool12(TRUE),	//	xltypeBOOL	�\���E�\����؂�ւ���B
			(LPXLOPER12)TempInt12(5),		//	xltypeInt	�h�b�N����ʒu���w�肷��B
			(LPXLOPER12)TempMissing12(),	//	xltypeInt	�c�[���o�[�̐��������̈ʒu�B
			(LPXLOPER12)TempMissing12(),	//	xltypeInt	�c�[���o�[�̐��������̈ʒu�B
			//(LPXLOPER12)TempMissing12(),	//	xltypeInt	�c�[���o�[�̕��B�ȗ��B
			(LPXLOPER12)TempInt12(72),	//	xltypeInt	�c�[���o�[�̕��B�ȗ��B
			(LPXLOPER12)TempInt12(0),		//	xltypeInt	�c�[���o�[�̕ی�̒��x���������l�B
			(LPXLOPER12)TempBool12(TRUE),	//	xltypeBOOL	�c�[���`�b�v��\�����邩���w������_���l�B
			(LPXLOPER12)TempBool12(FALSE),	//	xltypeBOOL	�傫�ȃ{�^�����g�p���邩���w������_���l�B
			(LPXLOPER12)TempBool12(TRUE)	//	xltypeBOOL	�{�^���ŐF���g�p���邩���w������_���l�B
			);

		GlobalUnlock(hGlobal);
		GlobalFree(hGlobal);
	}
	//------------------------------------------------------------
	//	Excel4
	//------------------------------------------------------------
	else
	{
		hGlobal	= GlobalAlloc(GMEM_MOVEABLE, sizeof(XLOPER4) * nrgToolArgs * nrgTools);
		pxGlobal4	= (LPXLOPER)GlobalLock(hGlobal);
		px4		= pxGlobal4;
		for (i = 0; i < nrgTools; ++i)
		{
			SET_XLOPER_STR_4(px4, rgTools[i].pszToolId.a);		++px4;
			SET_XLOPER_STR_4(px4, rgTools[i].pszMacro.a);			++px4;
			SET_XLOPER_BOOL_4(px4, rgTools[i].bDown);				++px4;
			SET_XLOPER_BOOL_4(px4, rgTools[i].bEnabled);			++px4;
			SET_XLOPER_STR_4(px4, rgTools[i].pszFace.a);			++px4;
			SET_XLOPER_STR_4(px4, rgTools[i].pszStatusTtext.a);	++px4;
			SET_XLOPER_STR_4(px4, rgTools[i].pszBallonTtext.a);	++px4;
			SET_XLOPER_STR_4(px4, rgTools[i].pszHelpTopic.a);		++px4;
			SET_XLOPER_STR_4(px4, rgTools[i].pszTipText.a);		++px4;
			for (j = 0; j < nrgToolArgs; ++j)
			{
				SET_XLOPER_STR_4(px4, rgTools[i][j].w);
				++px4;
			}
		}

		xTemp4.xltype	= xltypeMulti;
		xTemp4.val.array.lparray	= pxGlobal4;
		xTemp4.val.array.rows		= nrgTools;
		xTemp4.val.array.columns	= nrgToolArgs;

		//Excel(xlfAddToolbar, &xRes4, 2, (LPXLOPER)&xXLLTitle4, (LPXLOPER)&xTemp4);
		Excel(xlfAddToolbar, &xRes4, 1, (LPXLOPER)&xXLLTitle4);

		iRet = Excel(xlcShowToolbar, &xRes4, 10,
			(LPXLOPER)&xXLLTitle4,	//	xltypeStr	�c�[���o�[�̖��O�B
			(LPXLOPER)TempBool4(TRUE),	//	xltypeBOOL	�\���E�\����؂�ւ���B
			(LPXLOPER)TempInt4(5),		//	xltypeInt	�h�b�N����ʒu���w�肷��B
			(LPXLOPER)TempMissing4(),	//	xltypeInt	�c�[���o�[�̐��������̈ʒu�B
			(LPXLOPER)TempMissing4(),	//	xltypeInt	�c�[���o�[�̐��������̈ʒu�B
			(LPXLOPER)TempMissing4(),	//	xltypeInt	�c�[���o�[�̕��B�ȗ��B
			(LPXLOPER)TempInt4(0),		//	xltypeInt	�c�[���o�[�̕ی�̒��x���������l�B
			(LPXLOPER)TempBool4(TRUE),	//	xltypeBOOL	�c�[���`�b�v��\�����邩���w������_���l�B
			(LPXLOPER)TempBool4(FALSE),	//	xltypeBOOL	�傫�ȃ{�^�����g�p���邩���w������_���l�B
			(LPXLOPER)TempBool4(TRUE)	//	xltypeBOOL	�{�^���ŐF���g�p���邩���w������_���l�B
			);
		GlobalUnlock(hGlobal);
		GlobalFree(hGlobal);
	}
	bRegisterToolbarItems	= TRUE;
	return TRUE;
}

//----------------------------------------------------------------------
//	UnregisterToolbarItems
//----------------------------------------------------------------------
static BOOL UnregisterToolbarItems()
{
	XLOPER4		xRes4;
	XLOPER12	xRes12;

	if (!bRegisterToolbarItems)	return TRUE;

	//------------------------------------------------------------
	//	Excel12
	//------------------------------------------------------------
	if (XLL::IsExcel12())
	{
		Excel12f(xlfGetToolbar, &xRes12, 2, TempInt12(7), cxXLLTitle12.px());

		if (xRes12.xltype != xltypeErr)
		{
			Excel12f(xlfDeleteToolbar, 0, 1, cxXLLTitle12.px());
			Excel12f(xlFree, 0, 1, (LPXLOPER12)&xRes12);
		}
	}
	//------------------------------------------------------------
	//	Excel4
	//------------------------------------------------------------
	else
	{
	}
	return TRUE;
}

#endif


//======================================================================
//	xlAutoOpen
//======================================================================
int WINAPI xlAutoOpen()
{
	//	�����ݒ�� dllmain() �ł��s���B
	//	OS �̃o�[�W�������`�F�b�N����B
	if (!(PLib::CheckOSVersion(5, 1)))	return 0;	//	Windows XP �ȏ�

	//	Excel �̏����擾���AXLL �̏����ݒ���s���B
	if (!XLL::Init())		return 0;
	if (!XLCTextEx::Init())	return 0;

	//	���[�N�V�[�g�֐���o�^����B
#ifdef	REGISTER_XLLFUNCTIONS
	if (XLL::IsExcel12())
	{
		if (!t_RegisterFunctions<XLOPER12>((PCSTRAW*)pawRgXLLFunctions, nRgXLLFunctions, nParamsRgXLLFunc))
			return 0;
	}
	else
	{
		if (!t_RegisterFunctions<XLOPER>((PCSTRAW*)pawRgXLLFunctions, nRgXLLFunctions, nParamsRgXLLFunc))
			return 0;
	}

#endif

	//	�R�}���h�֐���o�^����B
#ifdef	REGISTER_COMMANDFUNCTIONS
	RegisterCommandFunctions();
#endif

	//	���j���[���ڂ�o�^����B
#ifdef	REGISTER_MENUITEMS
	RegisterMenuItems();
#endif

	//	�c�[���o�[���ڂ�o�^����B
#ifdef	REGISTER_TOOLBARITEMS
	RegisterToolbarItems();
#endif

#ifdef	PDEBUG
	//XLCRegExTest01();
#endif

	return 1;
}


//======================================================================
//	xlAutoClose
//======================================================================
int WINAPI xlAutoClose()
{
	//	�o�^�������[�N�V�[�g�֐�����������B
#ifdef	REGISTER_XLLFUNCTIONS
	if (XLL::IsExcel12())
	{
		if (!t_UnRegisterFunctions<XLOPER12>((PCSTRAW*)pawRgXLLFunctions, nRgXLLFunctions, nParamsRgXLLFunc))
		{
		}
	}
	else
	{
		if (!t_UnRegisterFunctions<XLOPER>((PCSTRAW*)pawRgXLLFunctions, nRgXLLFunctions, nParamsRgXLLFunc))
		{
		}
	}
#endif

	//	�o�^�����R�}���h����������B
#ifdef	REGISTER_COMMANDFUNCTIONS
	UnregisterCommandFunctions();
#endif

	//	�o�^�������j���[����������B
#ifdef	REGISTER_MENUITEMS
	UnregisterMenuItems();
#endif

	//	�o�^�����c�[���o�[����������B
#ifdef	REGISTER_TOOLBARITEMS
	UnregisterToolbarItems();
#endif

	//	�I�������� dllmain() �ōs���B
	return 1;
}


//======================================================================
//	xlAutoFree, xlAutoFree12
//======================================================================
void WINAPI	xlAutoFree(XLOPER* pxFree)
{
	if (pxFree->xltype & xlbitDLLFree)
	{
		XLL::DeallocateXLOPER4(pxFree);
	}
}

void WINAPI	xlAutoFree12(XLOPER12* pxFree)
{
	if (pxFree->xltype & xlbitDLLFree)
	{
		XLL::DeallocateXLOPER12(pxFree);
	}
}

