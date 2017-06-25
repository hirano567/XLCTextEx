//	XLCTextEx_1.0x	:	XLCTextEx

//	XLCRegExUtility.h
//
#pragma once

//======================================================================
//	class PCXLRegExManager	インスタンスの管理
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
	//	データメンバ
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
	//	コンストラクタとデストラクタ
	//------------------------------------------------------------
	PCXLRegExManager()
	{
	}

	~PCXLRegExManager()
	{
		Clear();
	}

	//------------------------------------------------------------
	//	メンバ関数
	//------------------------------------------------------------
	CREGEXMANAGER*		RegEx()			{ return &ciRegExManager; }
	CREPLACEMANAGER*	Replacement()	{ return &ciReplaceManager; }
};

//----------------------------------------------------------------------
//	pXLCRegExManager	PCXLRegExManager のインスタンスを取得する
//----------------------------------------------------------------------
PCXLRegExManager*	GetXLRegExManager();

//======================================================================
//	システムの初期化と終了処理
//======================================================================
NS_XLCREGEX_BEGIN

BOOL	Init();
void	Cleanup();

NS_XLCREGEX_END

