//	XLCTextEx_1.0x	:	PLibTextEx

//	PRegExText.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	PCTextUR では Unicode 文字列を UINT 型 codepoint の列に変換して保持しているが、
//	PBCRegExText では、各 codepoint を次のように利用する。
//
//	下位 24 ビットに Unicode codepoint（21 ビット必要）を格納する。 
//	上位  8 ビットに オプションデータ（ここでは token ID）を格納する。
//======================================================================
#define	PREGEX_CPEX_CPMASK			0x00FFFFFF
#define	PREGEX_CPEX_OPTSHIFT		24
#define	PREGEX_CPEX_GETCP(cx)		((cx) & PREGEX_CPEX_CPMASK)
#define	PREGEX_CPEX_GETOPT(cx)		((cx) >> PREGEX_CPEX_OPTSHIFT)
#define	PREGEX_CPEX_MAKE(cp, opt)	((cp) | ((opt) << PREGEX_CPEX_OPTSHIFT))


//======================================================================
//	class PBCRegExText
//
//	PRegEx で使用するテキスト処理クラスの基底クラス。
//	PCTextR クラスに Token ID のによる処理を追加している。
//======================================================================
class PBCRegExText	:	public PCTextUR, public PCBRegEx
{
protected:

public:
	PBCRegExText()	: PCTextUR()	{}
	~PBCRegExText()	{}

	virtual void	Clear();
	virtual bool	Init();

	virtual void	ConvertToCpList();

	virtual T_UCP	ItrToCp(ITR_UCPSTRING& itr)		{ return PREGEX_CPEX_GETCP(*itr); }
	virtual int		ItrToOpt(ITR_UCPSTRING& itr)	{ return (int)PREGEX_CPEX_GETOPT(*itr); }

	virtual bool	SetCurrentToken(int iToken);
	virtual int		GetPreviousToken();
	virtual int		GetCurrentToken();
	virtual int		GetNextToken();

	virtual bool	MoveTo(int iToken);

#ifdef	PDEBUG
	virtual void	DebugCurrentState(T_PSTRING_U pstrDebug, T_PSTRING_U pstrOutput = NULL);
	//void	Debug(T_STRING_U* pstrDebug);
	virtual void	DebugUCPString(T_PSTRING_U pstrDebug);
#endif
};

#define CLASS_PREGEX_BTEXT		PBCRegExText


//======================================================================
//	class PCRegExPattern
//
//	指定されたパターンからトークンを読み出すためのクラス。
//	以下の処理が追加されている。
//		コメントグループ (# ) を読み飛ばす。
//		x オプション指定時に、空白と # から行末までを読み飛ばす。
//		文法エラーの情報を通知する。
//======================================================================
#define	PREGEX_PATTERN_DECODE	(PCTEXT_FLAG_DECODE_OCTAL_HEX_ESCCTRL_CTRLCHAR_UNICODE)

class PCRegExPattern	:	public PBCRegExText
{
public:
	//------------------------------------------------------------
	//	データメンバ
	//------------------------------------------------------------
protected:

	//------------------------------------------------------------
	//	メンバ関数
	//------------------------------------------------------------
public:
	PCRegExPattern();
	~PCRegExPattern();

	bool	SkipCommentGroup();
	bool	SkipCommentLine();
	bool	SkipBlankAndComment();
	bool	ReportCurrentPos(T_STRING_U* pstrReport, T_PCSTR_U pszPos = TQU("CURRENT"));
};

#define CLASS_PREGEX_PATTERN	PCRegExPattern


//======================================================================
//	class PCRegExText
//
//	正規表現の処理対象となるテキストと処理情報を格納するためのクラス
//======================================================================
#define	PREGEX_TEXT_DECODE	(PCTEXT_FLAG_DECODE_ALL)

class PCRegExText	:	public PCTextUR, public PCBRegEx
{
protected:

private:
	//------------------------------------------------------------
	//	struct SReference	後方参照
	//------------------------------------------------------------
	struct	SReference
	{
		ITR_UCPSTRING	itrBegin;
		ITR_UCPSTRING	itrEnd;
	};

	typedef	std::vector<SReference*>	CREFARRAY;
	typedef	CREFARRAY::size_type		SIZE_REFARRAY;

	//------------------------------------------------------------
	//	struct SNamedReference	名前による後方参照
	//------------------------------------------------------------
	struct	SNamedReference
	{
		UCPSTRING		ucsName;
		ITR_UCPSTRING	itrBegin;
		ITR_UCPSTRING	itrEnd;
	};

	typedef	std::list<SNamedReference*>	CNAMEDREFLIST;
	typedef	CNAMEDREFLIST::iterator		ITR_NAMEDREFLIST;

	//------------------------------------------------------------
	//	PCRegExText	データメンバ
	//------------------------------------------------------------
	CMATCHINGHISTORY	ciHistory;
	CREFARRAY			ciRefArray;
	CNAMEDREFLIST		ciNamedRefList;

	PCInstanceList<SReference>		ciIPRef;
	PCInstanceList<SNamedReference>	ciIPNamedRef;

	COPTIONSSTACK	ciOptionsStack;		//	照合処理中のオプションを管理するためのスタック
	SGLOBALMATCHING	siGlobalMatching;	//	グローバルマッチングの情報
	SMATCHTIMES		siMatchTimes;		//	照合処理の回数を記録するための構造体
	LPVOID			pOptional;

public:
	//------------------------------------------------------------
	//	PCRegExText	メンバ関数
	//------------------------------------------------------------
	PCRegExText();
	~PCRegExText();

	void	ClearReferences();
	void	Clear();
	bool	InitReferences();
	bool	Init();

	//	照合用の関数

	bool	Match(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd);
	bool	HeadOfLine(bool bMultiLine);
	bool	EndOfLine(bool bMultiLine);

	//	照合処理のオプションを操作するための関数

	COPTIONS*	Options()						{ return ciOptionsStack.Options(); }
	bool		IsGlobalMatching()				{ return Options()->IsGlobalMatching(); }

	void	SetOptions(COPTIONS* pSrc)			{ (ciOptionsStack.Options())->CopyFrom(pSrc); }
	void	InitOptionsStack()					{ ciOptionsStack.Init(); }
	void	InitOptionsStack(COPTIONS* pSrc)	{ InitOptionsStack(); SetOptions(pSrc); }

	void	PushNewOptions()					{ ciOptionsStack.PushNewOptions(); }
	void	PopOptions()						{ ciOptionsStack.PopOptions(); }
	void	SetOptions(DWORD dwOn, DWORD dwOff)	{ ciOptionsStack.Set(dwOn, dwOff); }
	void	UndoPushOptions()					{ ciOptionsStack.UndoPush(); }
	void	UndoPopOptions()					{ ciOptionsStack.UndoPop(); }
	void	UndoSetOptions()					{ ciOptionsStack.UndoSet(); }
	void	RestoreOptions()					{ ciOptionsStack.Restore(); }

	//	照合の履歴を記録・取得するための関数

	void	ClearHistory()	{ ciHistory.Clear(); }
	void	InitHistory()	{ ciHistory.Init(); }

	void	PushHistory(CNSTATE* pciNState)
	{
		ciHistory.Push(pciNState, *pitrCurrentPos);
	}
	void	PushHistory(CNSTATE* pciNState, ITR_UCPSTRING& itr)
	{
		ciHistory.Push(pciNState, itr);
	}

	void	PopHistory()	{ ciHistory.Pop(); }

	bool	FindHistory(CNSTATE* pNState, ITR_UCPSTRING& itr)
	{
		return ciHistory.Find(pNState, itr);
	}
	bool	FindHistory(CNSTATE* pNState)
	{
		return ciHistory.Find(pNState, *pitrCurrentPos);
	}

	bool	ParseBackRef();

	//	後方参照を取得する関数

	bool	GetCurrentBackRef(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd, T_INDEX iRef);
	bool	GetCurrentNamedBackRef(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd, UCPSTRING* pName);

	//	グローバルマッチングの管理

	SGLOBALMATCHING*	GlobalMatching()		{ return &siGlobalMatching; }
	void	InitGlobalMatching()	{ siGlobalMatching.Init(); }
	bool	GlobalMatchingNotMove()	{ return (siGlobalMatching.itrMatch == *pitrCurrentPos); }

	//	照合処理の回数を操作するための関数

	SMATCHTIMES*	MatchTimes()			{ return &siMatchTimes; }
	void			InitMatchTimes()		{ siMatchTimes.Init(); }
	void			IncrementMatchTimes()	{ siMatchTimes.Increment(); }


	//	インデックスによる参照の管理

	void	SetupReferences(size_t i);
	bool	AppendReferenceBegin(T_PREGEX_INDEX i, ITR_UCPSTRING& itrBegin);
	bool	AppendReferenceEnd(T_PREGEX_INDEX i, ITR_UCPSTRING& itrEnd);

	bool	GetReference(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd, T_PREGEX_INDEX i);
	bool	GetReference(UCPSTRING* puisBuffer, T_PREGEX_INDEX i);
	bool	GetReference(T_STRING_U* pstrBuffer, T_PREGEX_INDEX i);

	//	名前による参照の管理

	SNamedReference*	GetNamedReference(UCPSTRING* pName);
	SNamedReference*	CreateNamedReference(UCPSTRING* pName);

	bool	AppendNamedReferenceBegin(UCPSTRING* pName, ITR_UCPSTRING& itrBegin);
	bool	AppendNamedReferenceEnd(UCPSTRING* pName, ITR_UCPSTRING& itrEnd);

	bool	GetNamedReference(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd, UCPSTRING* pName);
	bool	GetNamedReference(UCPSTRING* puisBuffer, UCPSTRING* pName);
	bool	GetNamedReference(T_STRING_U* pstrBuffer, UCPSTRING* pName);

	//	部分列の取得
	bool	GetPreMatch(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd);
	bool	GetPreMatch(UCPSTRING* puisBuffer);
	bool	GetPreMatch(T_STRING_U* pstrBuffer);

	bool	GetPostMatch(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd);
	bool	GetPostMatch(UCPSTRING* puisBuffer);
	bool	GetPostMatch(T_STRING_U* pstrBuffer);

	bool	GetLastParenMatch(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd);
	bool	GetLastParenMatch(UCPSTRING* puisBuffer);
	bool	GetLastParenMatch(T_STRING_U* pstrBuffer);

	void	SetOptional(LPVOID p)	{ pOptional = p; }
	void	ClearOptional()			{ SetOptional((LPVOID)NULL); }
	LPVOID	GetOptional()			{ return pOptional; }

	//	デバッグ用
#ifdef	PDEBUG
	void	Debug(T_STRING_U* pstrDebug);
	void	DebugHistory(T_STRING_U* pstrDebug);
#endif
};

#define CLASS_PREGEX_TEXT	PCRegExText


//======================================================================
//	class PCRegExReplacement
//
//	置換文字列を作成・適用するためのクラス。
//======================================================================
#define	PREGEX_REPLACEMENT_DECODE	(PCTEXT_FLAG_DECODE_OCTAL_HEX_ESCCTRL_CTRLCHAR_UNICODE)

#define	PREGEX_PEPLACEMENT_COMPONENT_UNDEFINED			0
#define	PREGEX_PEPLACEMENT_COMPONENT_STRING				1
#define	PREGEX_PEPLACEMENT_COMPONENT_BACKREF			2
#define	PREGEX_PEPLACEMENT_COMPONENT_BACKREF_BYNAME		3
#define	PREGEX_PEPLACEMENT_COMPONENT_MATCH				4
#define	PREGEX_PEPLACEMENT_COMPONENT_PREMATCH			5
#define	PREGEX_PEPLACEMENT_COMPONENT_POSTMATCH			6
#define	PREGEX_PEPLACEMENT_COMPONENT_LAST_PAREN_MATCH	7
#define	PREGEX_PEPLACEMENT_COMPONENT_ENTIRE_INPUT		8

//#define	PREGEX_PEPLACEMENT_PROCESSING_FORMAT	1
//#define	PREGEX_PEPLACEMENT_PROCESSING_REPLACE	2

//----------------------------------------------------------------------
//	class PCRegExReplacement
//----------------------------------------------------------------------
class PCRegExReplacement	:	public PBCRegExText
{
public:
	typedef	PBCRegExText	CBTEXT;
	typedef PCRegExText		CTEXT;

private:
	//------------------------------------------------------------
	//	struct SComponent
	//------------------------------------------------------------
	struct SComponent
	{
		//--------------------------------------------------
		//	データメンバ
		//--------------------------------------------------
		int				iType;
		UCPSTRING		ucsBuf;
		T_PREGEX_INDEX	iRef;

		//--------------------------------------------------
		//	コンストラクタ
		//--------------------------------------------------
		SComponent()
			:	iType(PREGEX_PEPLACEMENT_COMPONENT_UNDEFINED),
				iRef(PREGEX_INVALID_INDEX)
		{}

		//--------------------------------------------------
		//	Compare
		//--------------------------------------------------
		int	Compare(SComponent* pComp, DWORD dwFlags = 0, T_PCSTR_U pszLocale = NULL)
		{
			int	ic;
			PLib::Unicode::PCUIStringBuffer	ciBuf1, ciBuf2;

			if (iType < pComp->iType)	return -1;
			if (iType > pComp->iType)	return 1;
			if (iType == PREGEX_PEPLACEMENT_COMPONENT_STRING)
			{
				ciBuf1.Set(&ucsBuf);
				ciBuf2.Set(&(pComp->ucsBuf));

				ic	= PLib::Unicode::CompareStringUCD(&ciBuf1, &ciBuf2, dwFlags, pszLocale);

				if (ic == CSTR_LESS_THAN)		return -1;
				if (ic == CSTR_EQUAL)			return 0;
				if (ic == CSTR_GREATER_THAN)	return -1;
				THROWPE_RUNTIME_ERROR("PCRegExReplacement::SComponent::Compare");
			}
			else if (iType == PREGEX_PEPLACEMENT_COMPONENT_BACKREF)
			{
				return (int)(iRef - pComp->iRef);
			}
			return 0;	//	文字列と参照以外は付随するデータがないので、調べる必要がない。
		}
	};

	typedef	std::list<SComponent*>		CCOMPONENTSLIST;
	typedef	CCOMPONENTSLIST::iterator	ITR_COMPONENTSLIST;

	//------------------------------------------------------------
	//	データメンバ
	//------------------------------------------------------------
	CCOMPONENTSLIST	ciComponentList;	//	置換文字列を構成する要素
	COPTIONS		ciOptions;			//	置換文字列を解釈する方法を指定する
	SComponent*		pComponent;			//	処理中の要素を指すポインタ

	PCInstanceList<SComponent>	ciIPComponent;

	//------------------------------------------------------------
	//	メンバ関数
	//------------------------------------------------------------
public:
	PCRegExReplacement();
	~PCRegExReplacement();

	void		Clear();
	bool		Init();

	PCOPTIONS	Options()								{ return &ciOptions; }
	void		SetOptions(PCRegExOptions* pOptions)	{ ciOptions.CopyFrom(pOptions); }

	SComponent*	CreateComponent(int iType = PREGEX_PEPLACEMENT_COMPONENT_UNDEFINED);
	void		AppendStringComponent(const T_UCP* pStr, size_t zStr);
	void		AppendBackRefComponent(T_PREGEX_INDEX iRef);
	void		AppendNamedBackRefComponent(UCPSTRING* pName);

	bool	SetReplacement(T_PCSTR_U pReplacementB, T_PCSTR_U pReplacementE, DWORD dwCSFlags = 0, T_PCSTR_U pszLocale = NULL);
	bool	SetReplacement(T_PCSTR_U pReplacement, size_t zReplacement, DWORD dwCSFlags = 0, T_PCSTR_U pszLocale = NULL);
	bool	SetReplacement(T_PCSTR_U pszReplacement, DWORD dwCSFlags = 0, T_PCSTR_U pszLocale = NULL);

	bool	Format(T_STRING_U* pstrOutput, CTEXT* pciText);

	int		Compare(PCRegExReplacement* pOther, DWORD dwFlags = 0, T_PCSTR_U pszLocale = NULL);

	//	デバッグ用
#ifdef	PDEBUG
	void	Debug(T_STRING_U* pstrDebug);
#endif
};

#define CLASS_PREGEX_REPLACEMENT	PCRegExReplacement


NS_PLIB_END
