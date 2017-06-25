//	XLCTextEx_1.0x	:	XLCTextEx

//	XLCRegExUtility.h
//
#pragma once

//======================================================================
//	class PCXLRegExManager	�C���X�^���X�̊Ǘ�
//======================================================================
class PCXLRegExManager
{
public:
	typedef	PLib::PCRegEx				CREGEX,		*PCREGEX;
	typedef	PLib::PCRegExReplacement	CREPLACE,	*PCREPLACE;
	typedef	PLib::PCRegExText			CTEXT,		*PCTEXT;
	typedef	PLib::PCRegExOptions		CPARAMS,	*PCPARAMS;

private:
	//------------------------------------------------------------
	//	�f�[�^�����o
	//------------------------------------------------------------
	typedef	XLL::PCXLInstanceManager<T_CHAR_U, CREGEX>		CREGEXMANAGER;
	typedef	XLL::PCXLInstanceManager<T_CHAR_U, CREPLACE>	CREPLACEMANAGER;

	CREGEXMANAGER	ciRegExManager;
	CREPLACEMANAGER	ciReplaceManager;

public:
	//------------------------------------------------------------
	//	Clear
	//------------------------------------------------------------
	void Clear()
	{
		ciRegExManager.Clear();
		ciReplaceManager.Clear();
	}

	//------------------------------------------------------------
	//	�R���X�g���N�^�ƃf�X�g���N�^
	//------------------------------------------------------------
	PCXLRegExManager()
	{
	}

	~PCXLRegExManager()
	{
		Clear();
	}

	//------------------------------------------------------------
	//	�����o�֐�
	//------------------------------------------------------------
	CREGEXMANAGER*		RegEx()			{ return &ciRegExManager; }
	CREPLACEMANAGER*	Replacement()	{ return &ciReplaceManager; }
};

//----------------------------------------------------------------------
//	pXLCRegExManager	PCXLRegExManager �̃C���X�^���X���擾����
//----------------------------------------------------------------------
PCXLRegExManager*	GetXLRegExManager();

//======================================================================
//	�V�X�e���̏������ƏI������
//======================================================================
NS_XLCREGEX_BEGIN

BOOL	Init();
void	Cleanup();

NS_XLCREGEX_END

