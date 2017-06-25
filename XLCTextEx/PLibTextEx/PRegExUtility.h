//	XLCTextEx_1.0x	:	PLibTextEx

//	PRegExUtility.h
//
#pragma once

NS_PLIB_REGEX_BEGIN

//======================================================================
//	Token ID の取得
//======================================================================
int	GetTokenId(T_UCP cpSrc, DWORD dwFlags, T_PCSTR_U pszLocale);

//======================================================================
//	PCTextUR デコード用の関数
//======================================================================
bool	DecodeEscapedControl(T_UCP* pcpDst, T_UCP cpSrc, DWORD dwFlags, T_PCSTR_U pszLocale);

NS_PLIB_REGEX_END

NS_PLIB_BEGIN

//======================================================================
//	PRegEx のオプション
//======================================================================
#define	PREGEX_FLAG_GLOBALMATCHING				(1 << 0)
#define	PREGEX_FLAG_MULTILINEMODE				(1 << 1)
#define	PREGEX_FLAG_SINGLELINEMODE				(1 << 2)
#define	PREGEX_FLAG_LEGIBLE_PATTERN				(1 << 3)
#define	PREGEX_FLAG_NORM_IGNORECASE				(1 << 4)
#define	PREGEX_FLAG_NORM_IGNORENONSPACE			(1 << 5)
#define	PREGEX_FLAG_NORM_IGNOREWIDTH			(1 << 6)
#define	PREGEX_FLAG_NORM_IGNOREKANATYPE			(1 << 7)
#define	PREGEX_FLAG_CSTRUCD_NORMALIZE			(1 << 8)
#define	PREGEX_FLAG_CSTRUCD_IGNOREKANACASE		(1 << 9)

//	以下は廃止予定

#define	PREGEX_FLAG_LINGUISTIC_IGNORECASE		(1 << 10)
#define	PREGEX_FLAG_LINGUISTIC_IGNOREDIACRITIC	(1 << 11)


//======================================================================
//	PRegExOptions_StrToDWord
//
//	文字列は
//		[gmsxidwk(li)(ld)]*-[gmsidwk(li)(ld)]*	（廃止）
//		[gmsxidwkl]*-[gmsidwkl]*
//	の形式であると仮定して解析する。
//	- 以前のフラグを設定し、以降のフラグを解除する
//	アルファベット、空白文字、ハイフン以外の文字が現れたら終了する。
//======================================================================
void	PRegExOptions_StrToDWord(DWORD* pdwOn, DWORD* pdwOff, PITextUR* pciText);


//======================================================================
//	class PCRegExOptions
//
//	マッチしたものすべてを置換する。	g	(1 << 0)
//	マルチラインモード					m	(1 << 1)	対象テキストを \r\n で区切られているとする。
//	シングルラインモード				s	(1 << 2)	. は \r\n にもマッチする。
//	空白を無視し、# をコメントとする。	x	(1 << 3)
//	大文字小文字を区別しない。			i	(1 << 4)	NORM_IGNORECASE
//	付加記号等の有無を区別しない。		d	(1 << 5)	NORM_IGNORENONSPACE
//	全角、半角を区別しない。			w	(1 << 6)	NORM_IGNOREWIDTH
//	ひらがな、カタカナを区別しない。	k	(1 << 7)	NORM_IGNOREKANATYPE
//	正規化して比較する。				n	(1 << 8)	CSTRUCD_NORMALIZE
//	かな小文字を区別しない。			l	(1 << 9)	CSTRUCD_IGNOREKANACASE
//
//	（以下は廃止予定）
//
//	大文字小文字を区別しない。			li	(1 << 9)	LINGUISTIC_IGNORECASE
//	付加記号等の有無を区別しない。		ld	(1 << 10)	LINGUISTIC_IGNOREDIACRITIC
//======================================================================
class PCRegExOptions
	: public PLib::Unicode::PCCompareStringUCDOptions
{
public:
private:
	//------------------------------------------------------------
	//	PCRegExOptions:	データメンバ
	//------------------------------------------------------------
	typedef	PLib::Unicode::PCCompareStringUCDOptions	CCSOPTIONS;
	typedef	PCRegExOptions								CREOPTIONS;

	bool	bGlobalMatching;
	bool	bMultilineMode;
	bool	bSinglelineMode;
	bool	bLegiblePattern;

	bool	bCollateNormalize;	//	Collating Element は Normalize して照合する。

public:
	//------------------------------------------------------------
	//	PCRegExOptions:	コンストラクタ
	//------------------------------------------------------------
	PCRegExOptions()
		:	PLib::Unicode::PCCompareStringUCDOptions(),
			bGlobalMatching(false),
			bMultilineMode(false),
			bSinglelineMode(false),
			bLegiblePattern(false),
			bCollateNormalize(true)
	{
	}

	//------------------------------------------------------------
	//	PCRegExOptions::Reset
	//------------------------------------------------------------
	void Reset()
	{
		CCSOPTIONS::Reset();
		bGlobalMatching		= false;
		bMultilineMode		= false;
		bSinglelineMode		= false;
		bLegiblePattern		= false;
		bCollateNormalize	= true;
	}

	//------------------------------------------------------------
	//	PCRegExOptions:	各パラメータを設定する
	//------------------------------------------------------------
	void	SetGlobalMatching()		{ bGlobalMatching	= true; }
	void	UnsetGlobalMatching()	{ bGlobalMatching	= false; }

	void	SetMultilineMode()		{ bMultilineMode	= true; }
	void	UnsetMultilineMode()	{ bMultilineMode	= false; }

	void	SetSinglelineMode()		{ bSinglelineMode	= true; }
	void	UnsetSinglelineMode()	{ bSinglelineMode	= false; }

	void	SetLegiblePattern()		{ bLegiblePattern	= true; }
	void	UnsetLegiblePattern()	{ bLegiblePattern	= false; }

	void	SetCollateNormalize()	{ bCollateNormalize	= true; }
	void	UnsetCollateNormalize()	{ bCollateNormalize	= false; }

	//------------------------------------------------------------
	//	PCRegExOptions:	パラメータをまとめて設定する
	//------------------------------------------------------------
	void	Set(DWORD dwFlags);
	void	Unset(DWORD dwFlags);

	bool	Set(PCTextUR* pciText);
	bool	Set(T_PCSTR_U pStr, size_t zStr);
	bool	Set(T_PCSTR_U pStrB, T_PCSTR_U pStrE);
	bool	Set(T_PCSTR_U pszStr);

	void	CopyFrom(PCRegExOptions* pSrc);

	//------------------------------------------------------------
	//	PCRegExOptions:	各フラグを取得する
	//------------------------------------------------------------
	bool IsGlobalMatching()		{ return bGlobalMatching; }
	bool IsMultilineMode()		{ return bMultilineMode; }
	bool IsSinglelineMode()		{ return bSinglelineMode; }
	bool IsLegiblePattern()		{ return bLegiblePattern; }
	bool IsCollateNormalize()	{ return bCollateNormalize; }

	//------------------------------------------------------------
	//	PCRegExOptions:	フラグをまとめて取得する
	//------------------------------------------------------------
	DWORD	GetDW();

	//------------------------------------------------------------
	//	デバッグ用
	//------------------------------------------------------------
	void	DebugFlags(T_STRING_U* pstrDebug, DWORD dwFlags, bool bFullName);
	void	Debug(T_STRING_U* pstrDebug);
	void	DebugSimple(T_STRING_U* pstrDebug);
};

#define CLASS_PREGEX_OPTIONS				PCRegExOptions


//======================================================================
//	class PCRegExOptionsStack
//======================================================================
class PCRegExOptionsStack
{
private:
	typedef	PLib::PCRegExOptions				COPTIONS;
	typedef	PCInstanceStack<COPTIONS, true, 16>	COPTIONSSTACK;
	
	COPTIONSSTACK	ciOptionsStack;

public:
	//------------------------------------------------------------
	//	PCRegExOptionsStack::Init
	//------------------------------------------------------------
	void Init()
	{
		ciOptionsStack.Init();
	}

	//------------------------------------------------------------
	//	PCRegExOptionsStack::Clear
	//------------------------------------------------------------
	void Clear()
	{
		ciOptionsStack.Clear();
	}

	//------------------------------------------------------------
	//	PCRegExOptionsStack::ClearUndo
	//------------------------------------------------------------
	void ClearUndo()
	{
		ciOptionsStack.ClearUndo();
	}

	//------------------------------------------------------------
	//	コンストラクタ
	//------------------------------------------------------------
	PCRegExOptionsStack()
	{
		Init();
	}

	//------------------------------------------------------------
	//	デストラクタ
	//------------------------------------------------------------
	~PCRegExOptionsStack()
	{
		Clear();
	}

	//------------------------------------------------------------
	//	PushNewOptions
	//------------------------------------------------------------
	void PushNewOptions()
	{
		ciOptionsStack.PushNew();
	}

	//------------------------------------------------------------
	//	PopOptions
	//------------------------------------------------------------
	void PopOptions()
	{
		ciOptionsStack.Pop();
	}

	//------------------------------------------------------------
	//	Set
	//------------------------------------------------------------
	void Set(DWORD dwOn, DWORD dwOff)
	{
		//	現在の値を Undo スタックにプッシュしておく。
		ciOptionsStack.SaveUndoValue();

		//	新しい値をセットする。
		ciOptionsStack.GetStackTop()->Set(dwOn);
		ciOptionsStack.GetStackTop()->Unset(dwOff);
	}

	//------------------------------------------------------------
	//	UndoPush
	//------------------------------------------------------------
	void UndoPush()
	{
		ciOptionsStack.UndoPush();
	}

	//------------------------------------------------------------
	//	UndoPop
	//------------------------------------------------------------
	void UndoPop()
	{
		ciOptionsStack.UndoPop();
	}

	//------------------------------------------------------------
	//	UndoSet
	//------------------------------------------------------------
	void UndoSet()
	{
		ciOptionsStack.UndoValue();
	}

	//------------------------------------------------------------
	//	Restore
	//------------------------------------------------------------
	void Restore()
	{
		ciOptionsStack.Restore();
	}


	//------------------------------------------------------------
	//	Options
	//------------------------------------------------------------
	COPTIONS* Options()
	{
		return ciOptionsStack.GetStackTop();
	}

	//------------------------------------------------------------
	//	Debug
	//------------------------------------------------------------
#ifdef	PDEBUG
	void Debug(T_STRING_U* pstrDebug)
	{
		COPTIONS*	pOpt;
		int			i;

		T_PCSTR_U	pfmt_opi	= TQU("Opts[%d] \t: ");
		T_PCSTR_U	pIndent		= TQU("");
		T_PCSTR_U	pHR			= TQU("------------------------------\r\n");
		T_PCSTR_U	pLF			= TQU("\r\n");

		pstrDebug->append(pHR);
		pstrDebug->append(TQU("  Options Stack\r\n"));
		pstrDebug->append(pHR);
		for (ciOptionsStack.Begin(), i = 0; !ciOptionsStack.End(); ciOptionsStack.Next(), ++i)
		{
			if (ciOptionsStack.GetCurrent(&pOpt))
			{
				pstrDebug->append(pIndent);
				NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_opi, i);
				pOpt->DebugSimple(pstrDebug);
				pstrDebug->append(pLF);
			}
		}

		pstrDebug->append(pHR);
		pstrDebug->append(TQU("Undo Stack\r\n"));
		pstrDebug->append(pHR);
		for (ciOptionsStack.BeginUndo(), i = 0;
			!ciOptionsStack.EndUndo();
			ciOptionsStack.NextUndo(), ++i)
		{
			if (ciOptionsStack.GetCurrentUndo(&pOpt))
			{
				pstrDebug->append(pIndent);
				NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt_opi, i);
				pOpt->DebugSimple(pstrDebug);
				pstrDebug->append(pLF);
			}
		}
		
		pstrDebug->append(pLF);
	}
#endif
};


//======================================================================
//	class PCRegExMatchingHistory
//	照合の履歴を記録するためのクラス
//======================================================================
//----------------------------------------------------------------------
//	PSRegExMatchingState
//----------------------------------------------------------------------
struct PSRegExMatchingState
	:	public PCBRegEx
{
	CNSTATE*		pciNState;
	ITR_UCPSTRING	itrText;

	PSRegExMatchingState()	: pciNState(NULL)	{}
	void CopyFrom(PSRegExMatchingState* pSrc)
	{
		pciNState	= pSrc->pciNState;
		itrText		= pSrc->itrText;
	}

#ifdef	PDEBUG
	void Debug(T_STRING_U* pstrDebug, CRETEXT* pciText);
#endif
};

//----------------------------------------------------------------------
//	PCRegExMatchingHistory
//----------------------------------------------------------------------
class PCRegExMatchingHistory
	:	public PCBRegEx
{
private:
	typedef	PLib::PCInstanceStack<SMATCHINGSTATE, false, 32>	CHISTORY;

	CHISTORY	ciHistory;

public:
	void	Clear()				{ ciHistory.Clear(); }
	void	Init()				{ ciHistory.Init(); }
	PCRegExMatchingHistory()	{ Init(); }
	~PCRegExMatchingHistory()	{ Clear(); }

	//------------------------------------------------------------
	//	PCRegExMatchingHistory::Push
	//------------------------------------------------------------
	void Push(CNSTATE* pciNState, ITR_UCPSTRING& itr)
	{
		PSRegExMatchingState*	psiState;
		ITR_UCPSTRING			itrCurrent;

		ciHistory.PushNew(&psiState);
		psiState->pciNState	= pciNState;
		psiState->itrText		= itr;

		return;
	}

	//------------------------------------------------------------
	//	PCRegExMatchingHistory::Pop
	//------------------------------------------------------------
	void Pop()
	{
		ciHistory.UndoPush();
		return;
	}

	//------------------------------------------------------------
	//	PCRegExMatchingHistory::Find
	//	処理がループしていないか調べるための補助関数
	//	itrText が最新の位置で、これより前を調べればよいという状況を仮定している。
	//------------------------------------------------------------
	bool Find(CNSTATE* pNState, ITR_UCPSTRING& itrText)
	{
		PSRegExMatchingState*	pMState;

		for (ciHistory.Begin(); !ciHistory.End(); ciHistory.Next())
		{
			if (ciHistory.GetCurrent(&pMState) && pMState != NULL)
			{
				if (pMState->itrText == itrText)
				{
					if (pMState->pciNState == pNState)
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	//------------------------------------------------------------
	//	繰り返し処理	(1-1)
	//------------------------------------------------------------
	void	Begin()	{ ciHistory.Begin(); }
	bool	End()	{ return ciHistory.End(); }
	void	Next()	{ ciHistory.Next(); }
	bool	GetCurrent(SMATCHINGSTATE** pps)	{ return ciHistory.GetCurrent(pps); }

	//------------------------------------------------------------
	//	繰り返し処理	(1-2)
	//------------------------------------------------------------
	void	RBegin()	{ ciHistory.RBegin(); }
	bool	REnd()	{ return ciHistory.REnd(); }
	void	RNext()	{ ciHistory.RNext(); }
	bool	RGetCurrent(SMATCHINGSTATE** pps)	{ return ciHistory.RGetCurrent(pps); }

	//------------------------------------------------------------
	//	デバッグ用
	//------------------------------------------------------------
#ifdef	PDEBUG
	void	Debug(T_STRING_U* pstrDebug, CRETEXT* pciText);
#endif
};

//======================================================================
//	GetUnicodePropertyMatching
//	パターン文字列から Unicode 属性を使用した成功条件を取り出す。
//======================================================================
bool	GetUnicodePropertyMatching(int*			piMatching,
								   UCPSTRING*	pucsArg1,
								   UCPSTRING*	pucsArg2);


//======================================================================
//	ParseUnicodePropertyMatching
//
//	処理終了後、pciText は } の次の文字を指している。
//======================================================================
bool	ParseUnicodePropertyMatching(int*			piMatching,
									 PBCRegExText*	pciText,
									 DWORD			dwFlags,
									 T_PCSTR_U		pszLocale);

//======================================================================
//	MatchUnicodeProperty
//======================================================================
bool	MatchUnicodeProperty(int iMatching, T_UCP cpSrc);

//======================================================================
//	IsWordBoundary
//======================================================================
bool IsWordBoundary(PITextUR* pciText);


NS_PLIB_END

