//	XLCTextEx_1.0x	:	PLibTextEx

//	PRegEx.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	class PCRegExNode
//
//	正規表現を解析木として表したときの結節点となる構造体
//
//	Atom の場合
//		文字		PREGEX_NODE_ATOM_CHAR		iValue を使用（マルチコード文字のインデックス）
//		行頭		PREGEX_NODE_ATOM_START_MULTI		付随するデータなし
//		行末		PREGEX_NODE_ATOM_END_MULTI		付随するデータなし
//		[]			PREGEX_NODE_ATOM_BRACKETEX	pBracketEx を使用
//		(正規表現)	PREGEX_NODE_ATOM_REGEX		iValue を使用（後方参照のインデックス）
//	piece
//		Node		PREGEX_NODE_PIECE_*			iValue を使用（子ノードのインデックス）
//	branch
//		Node		PREGEX_NODE_BRANCH			pNodeList を使用
//	Expression
//		Node		PREGEX_NODE_EXPRESSION		pNodeList を使用
//======================================================================
class PCRegExNode	: public PCBRegEx
{
public:
	//------------------------------------------------------------
	//	データメンバ
	//------------------------------------------------------------
	PCREGEX	pciBaseRegEx;	//	基となる PCRegEx インスタンス。
	T_INDEX	iIndex;
	T_TYPE	iNodeType;

	//	子ノードのリスト。piece と expression、branch で使用。
	CNODELIST	ciNodeList;	

	//	タイプ別のデータ
	LPVOID	pOptional[PREGEX_OPTIONALDATA_NUM];

public:
	//------------------------------------------------------------
	//	メンバ関数
	//------------------------------------------------------------
	PCRegExNode();
	PCRegExNode(PCREGEX pRegEx);
	PCRegExNode(T_TYPE iType);
	PCRegExNode(PCREGEX pRegEx, T_TYPE iType);
	~PCRegExNode()	{}

	void	Clear();
	void	SetBase(PCREGEX pBase)	{ pciBaseRegEx = pBase; }
	void	SetNodeIndex(T_INDEX i)	{ iIndex = i; }
	T_INDEX	GetNodeIndex()			{ return iIndex; }
	void	SetNodeType(T_TYPE t)	{ iNodeType = t; }
	T_TYPE	GetNodeType()			{ return iNodeType; }

	bool	SetOptionalData(int iIndex, LPVOID pData);
	bool	GetOptionalData(LPVOID* ppData, int iIndex);
	LPVOID	GetOptionalData(int iIndex);	//	iIndex が不適切な場合は NULL を返す。

	void		SetOptionalIndex(T_INDEX i)			{ SetOptionalData(0, (LPVOID)i); }
	T_INDEX		GetOptionalIndex()					{ return (T_INDEX)GetOptionalData(0); }

	void		SetOptionalCp(T_UCP c)				{ SetOptionalData(0, (LPVOID)c); }
	T_UCP		GetOptionalCp()						{ return (T_UCP)GetOptionalData(0); }

	void		SetOptionalNState(CNSTATE* pnd)	{ SetOptionalData(0, (LPVOID)pnd); }
	CNSTATE*	GetOptionalNState()				{ return (CNSTATE*)GetOptionalData(0); }

	void		SetOptionalSRegEx(CSREGEX* psr)		{ SetOptionalData(0, (LPVOID)psr); }
	CSREGEX*	GetOptionalSRegEx()					{ return (CSREGEX*)GetOptionalData(0); }

	void		SetOptionalName(UCPSTRING* pn)		{ SetOptionalData(0, (LPVOID)pn); }
	UCPSTRING*	GetOptionalName()					{ return (UCPSTRING*)GetOptionalData(0); }

	void		SetOptionalInt(int i)				{ SetOptionalData(0, (LPVOID)i); }
	int			GetOptionalInt()					{ return (int)GetOptionalData(0); }

	CNODELIST*	GetNodeList()						{ return &ciNodeList; }
	void		AppendNode(CNODE* pn)				{ ciNodeList.push_back(pn); }
	CNODE*		GetFirstNode()						{ return (ciNodeList.empty() ? NULL : *(ciNodeList.begin())); }

	void	SetBoundMin(int i)						{ SetOptionalData(0, (LPVOID)i); }
	void	SetBoundMax(int i)						{ SetOptionalData(1, (LPVOID)i); }
	int		GetBoundMin()							{ return (int)GetOptionalData(0); }
	int		GetBoundMax()							{ return (int)GetOptionalData(1); }

	bool	Size(int* piMin, int* piMax);

#ifdef	PDEBUG
	void	Debug(T_STRING_U* pstrDebug, T_STRING_U* pstrIndent);
#endif
};

#define	CLASS_PREGEX_NODE		PCRegExNode


//======================================================================
//	class PCRegExNState
//
//	非決定性オートマトンの状態を表す構造体
//======================================================================
#define	PREGEX_NSTATE_FLAG_NORMAL	0
#define	PREGEX_NSTATE_FLAG_START	(1 << 0)
#define	PREGEX_NSTATE_FLAG_FINAL	(1 << 1)

class PCRegExNState	: public PCBRegEx
{
	//------------------------------------------------------------
	//	PCRegExNState	データメンバ	(1)
	//------------------------------------------------------------
private:
	T_INDEX			iIndex;
	T_TYPE			iType;
	CREGEX*			pciBaseRegEx;
	CNTRANSITION*	pNTransition;
	int				iFlags;

	//------------------------------------------------------------
	//	PCRegExNState	データメンバ	(2)	タイプ別のデータ
	//
	//	PREGEX_DSTATE_TYPE_* の値に応じて以下のように使用する。
	//	NORMAL				使用しない。
	//	CTRL_SETOPTIONS		0:ON にするオプション、1:OFF にするオプション
	//
	//	EX_CAP_BEGIN		Caputure のインデックス
	//	EX_CAP_END
	//	EX_NCAP_BEGIN		使用しない。
	//	EX_NCAP_END
	//	EX_SETOPTIONS_BEGIN	0:ON にするオプション、1:OFF にするオプション
	//	EX_SETOPTIONS_END
	//	EX_NBACK_BEGIN
	//	EX_NBACK_END
	//
	//	なお、_BEGIN ではオプションの Push、_END では Pop も行われる。
	//------------------------------------------------------------
	LPVOID		pOptional[PREGEX_OPTIONALDATA_NUM];

	//------------------------------------------------------------
	//	PCRegExNState	メンバ関数
	//------------------------------------------------------------
public:
	PCRegExNState();
	~PCRegExNState()	{}

	void	SetStateIndex(T_INDEX i)	{ iIndex = i; }
	T_INDEX	GetStateIndex()				{ return iIndex; }
	void	SetType(T_TYPE t)			{ iType = t; }
	T_TYPE	GetType()					{ return iType; }
	void	SetBase(CREGEX* pb)			{ pciBaseRegEx = pb; }
	CREGEX*	GetBase()					{ return pciBaseRegEx; }

	void	Clear();
	bool	Init()			{ Clear(); return true; }

	void	SetFinal()		{ iFlags |= PREGEX_NSTATE_FLAG_FINAL; }
	void	UnsetFinal()	{ iFlags &= ~PREGEX_NSTATE_FLAG_FINAL; }
	bool	IsFinal()		{ return ((iFlags & PREGEX_NSTATE_FLAG_FINAL) != 0); }

	void	AppendTransition(CNTRANSITION* pNTr);
	void	AppendTransition(CNSTATE* pNDDst);
	void	AppendTransition(CNSTATE* pNDDst, T_INDEX iMatchingType);
	void	AppendTransition(CNSTATE* pNDDst, T_INDEX iMatchingType, LPVOID pMatchingValue);
	CNTRANSITION*	GetTransition()	{ return pNTransition; }

	bool	SetOptionalData(int iIndex, LPVOID pData);
	bool	GetOptionalData(LPVOID* ppData, int iIndex);
	LPVOID	GetOptionalData(int iIndex);	//	エラーの場合も NULL を返す。

	void		SetOptionalIndex(T_INDEX i)			{ SetOptionalData(0, (LPVOID)i); }
	T_INDEX		GetOptionalIndex()					{ return (T_INDEX)GetOptionalData(0); }

	void		SetOptionalCp(T_UCP c)				{ SetOptionalData(0, (LPVOID)c); }
	T_UCP		GetOptionalCp()						{ return (T_UCP)GetOptionalData(0); }

	void		SetOptionalSRegEx(CSREGEX* psr)		{ SetOptionalData(0, (LPVOID)psr); }
	CSREGEX*	GetOptionalSRegEx()					{ return (CSREGEX*)GetOptionalData(0); }

	void		SetOptionalSRegEx2(CSREGEX* psr)	{ SetOptionalData(1, (LPVOID)psr); }
	CSREGEX*	GetOptionalSRegEx2()				{ return (CSREGEX*)GetOptionalData(1); }

	void		SetOptionalName(UCPSTRING* pn)		{ SetOptionalData(0, (LPVOID)pn); }
	UCPSTRING*	GetOptionalName()					{ return (UCPSTRING*)GetOptionalData(0); }

	bool	NextState(CRETEXT* psiText, SLOOKBEHIND* pLookBehind);

#ifdef	PDEBUG
	void Debug(T_STRING_U* pstrDebug);
#endif
};

#define	CLASS_PREGEX_NSTATE	PCRegExNState


//======================================================================
//	class PCRegExNTransition
//	非決定性オートマトンの状態遷移を表すための構造体
//======================================================================
class PCRegExNTransition	: PCBRegEx
{
	//------------------------------------------------------------
	//	PCRegExNTransition	データメンバ
	//------------------------------------------------------------
private:
	T_INDEX			iIndex;				//	デバッグ用
	PCREGEX			pBaseRegEx;			//	基となる PCRegEx インスタンス
	CNSTATE*		pDestination;		//	遷移先の状態
	CNTRANSITION*	pNextTransition;	//	次の遷移
	SMATCHING		siMatching;			//	マッチの判定方法とデータ

	//------------------------------------------------------------
	//	PCRegExNTransition	メンバ関数
	//------------------------------------------------------------
public:
	PCRegExNTransition();
	~PCRegExNTransition()	{}

	void		Init();

	void		SetIndex(T_INDEX i)		{ iIndex = i; }
	T_INDEX		GetIndex()				{ return iIndex; }
	void		SetBase(PCREGEX pr)		{ pBaseRegEx = pr; }

	void		SetDestination(CNSTATE* ps)	{ pDestination = ps; }
	CNSTATE*	GetDestination()				{ return pDestination; }

	void			SetNextTransition(CNTRANSITION* pt)	{ pNextTransition = pt; }
	CNTRANSITION*	GetNextTransition()						{ return pNextTransition; }

	void	SetMatching(T_INDEX i, LPVOID pv)	{ siMatching.Set(i, pv); }
	void	SetMatching(T_INDEX i, T_INDEX iv)	{ siMatching.Set(i, (LPVOID)iv); }
	void	SetMatching(T_INDEX i)				{ siMatching.Set(i, (LPVOID)NULL); }

	SMATCHING*	GetMatching()					{ return &siMatching; }
	T_INDEX		GetMatchingType()				{ return (T_INDEX)siMatching.GetType(); }
	T_INDEX		GetMatchingIndex()				{ return (T_INDEX)siMatching.GetValue(); }
	UCPSTRING*	GetMatchingName()				{ return (UCPSTRING*)siMatching.GetValue(); }
	CSREGEX*	GetMatchingSRegEx()				{ return (CSREGEX*)siMatching.GetValue(); }
	LPVOID		GetMatchingValue()				{ return siMatching.GetValue(); }

	bool	Match(CRETEXT* pciText, SMATCHTIMES* psiMatchTimes, SLOOKBEHIND* pLookBehind);

#ifdef	PDEBUG
	void	Debug(T_STRING_U* pstrDebug);
#endif
};

#define	CLASS_PREGEX_NTRANSITION	PCRegExNTransition


//======================================================================
//	class PCSRegEx
//
//	（部分）正規表現とその解析木を格納するクラス
//======================================================================
class PCSRegEx	: public PCBRegEx
{
private:
	//------------------------------------------------------------
	//	PCSRegEx	データメンバ
	//------------------------------------------------------------
	T_TYPE		iType;
	CREGEX*		pciBaseRegEx;
	CPATTERN*	pciPattern;

	//	タイプ別のデータ
	LPVOID		pOptional[PREGEX_OPTIONALDATA_NUM];

	//	解析木を作成するための変数
	typedef	std::vector<PCNODE>	NODEARRAY, *PNODEARRAY;
	typedef	NODEARRAY::iterator	ITR_NODEARRAY;

	NODEARRAY	ciNodeArray;
	CNODE*		pciRootNode;

	//------------------------------------------------------------
	//	PCSRegExメンバ関数
	//------------------------------------------------------------
public:
	PCSRegEx(PCREGEX pBase = NULL);
	~PCSRegEx();

	void	Clear();
	bool	Init();

	void	SetType(int i)			{ iType = i; }
	int		GetType()				{ return iType; }
	void	SetBase(PCREGEX pBase);
	CREGEX*	GetBase()				{ return pciBaseRegEx; }
	void	SetPattern();

	bool	SetOptionalData(int iIndex, LPVOID pData);
	bool	GetOptionalData(LPVOID* ppData, int iIndex);
	LPVOID	GetOptionalData(int iIndex);	//	エラーの場合も NULL を返す。

	void		SetOptionalIndex(T_INDEX i)			{ SetOptionalData(0, (LPVOID)i); }
	T_INDEX		GetOptionalIndex()					{ return (T_INDEX)GetOptionalData(0); }

	void		SetOptionalName(UCPSTRING* pn)		{ SetOptionalData(0, (LPVOID)pn); }
	UCPSTRING*	GetOptionalName()					{ return (UCPSTRING*)GetOptionalData(0); }

	void		SetOptionalNState(CNSTATE* ps)	{ SetOptionalData(0, (LPVOID)ps); }
	CNSTATE*	GetOptionalNState()				{ return (CNSTATE*)GetOptionalData(0); }

	void		SetOptionalSRegEx(CSREGEX* pr)		{ SetOptionalData(0, (LPVOID)pr); }
	CSREGEX*	GetOptionalSRegEx()					{ return (CSREGEX*)GetOptionalData(0); }

	//------------------------------------------------------------
	//	解析木を作成するための関数
	//------------------------------------------------------------
	CNODE*	CreateNode(T_TYPE iType);
	CNODE*	Atom();
	CNODE*	Piece();
	CNODE*	Branch();
	CNODE*	Expression();

	void	Parse();

	//------------------------------------------------------------
	//	解析木にアクセスするための関数
	//------------------------------------------------------------
	CNODE*	GetRootNode()	{ return pciRootNode; }

#ifdef	PDEBUG
	void	Debug(T_STRING_U* pstrDebug);
#endif
};

#define CLASS_SREGEX	PCSRegEx


//======================================================================
//	class PCSRegExNFA
//	PCSRegEx クラスから非決定性オートマトンを作成するためのクラス
//======================================================================
class PCSRegExNFA	:	public PCBRegEx
{
protected:
	CREGEX*		pciBaseRegEx;
	CSREGEX*	pciSRegEx;

	//	開始状態と終了状態
	CNSTATE*	pciNFAStartState;
	CNSTATE*	pciNFAEndState;

	//	デバッグ用にインデックスも記録しておく。
	T_INDEX		iNFAStartIndex;	//	非決定性オートマトンの開始状態のインデックス
	T_INDEX		iNFAEndIndex;		//	非決定性オートマトンの終了状態のインデックス

public:
	PCSRegExNFA();
	~PCSRegExNFA()	{}

	void	Clear();
	bool	Init();

	void		SetSRegEx(CSREGEX* p);
	CSREGEX*	SRegEx()				{ return pciSRegEx; }

	CNSTATE*	GetNFAStartState()		{ return pciNFAStartState; }
	CNSTATE*	GetNFAEndState()		{ return pciNFAEndState; }

	//	非決定性オートマトンを作成・操作するための関数

	void	BuildNFA(CNODE* pNode, CNSTATE* pNDSrcState, CNSTATE* pNDDstState);
	void	BuildNFA();

#ifdef	PDEBUG
	void	Debug(T_STRING_U* pstrDebug);
#endif
};

#define CLASS_PREGEX_SREGEXDFA	PCSRegExNFA


//======================================================================
//	class PCRegEx
//
//	パターンから NFA を作成・保持する。
//	NFA によるパターンマッチを行う。
//======================================================================
class PCRegEx	: public PCBRegEx
{
private:
	//------------------------------------------------------------
	//	PCRegEx	データメンバ
	//------------------------------------------------------------
	//	解析中に部分正規表現ごとにオプションを管理するためのスタック

	COPTIONSSTACK	ciOptionsStack;

	//	パターンを格納し、トークンを取り出すためのクラスインスタンス。

	T_STRING	strPattern;
	CPATTERN	ciPattern;

	//	正規表現を解析し、パターンマッチを調べる際に主となるクラスインスタンスと
	//	それを使用するためのクラスインスタンス。

	CSREGEX		ciMainSRegEx;
	CSREGEXNFA	ciMainSRegExNFA;

	//	番号付き部分正規表現を管理するためのコンテナ

	typedef	std::vector<CSREGEX*>	CSREGEXARRAY;
	CSREGEXARRAY					ciCaptureArray;	//	後方参照用のインデックスと部分正規表現を対応させる。

	//	名前付き後方参照を管理するためのコンテナ

	typedef	PLib::Unicode::PCCompareUCPString<NORM_IGNOREWIDTH>	CCOMPAREUCPSTRING;

	typedef	std::map<UCPSTRING*, CSREGEX*, CCOMPAREUCPSTRING>	NAMEDSREGEXMAP;
	typedef NAMEDSREGEXMAP::iterator							ITR_NAMEDSREGEXMAP;
	typedef	std::pair<UCPSTRING*, CSREGEX*>						PAIR_NAMEDSREGEXMAP;

	NAMEDSREGEXMAP	ciNamedSRegExMap;

	//	非決定性オートマトンをデバッグするための変数

	typedef	std::vector<CNSTATE*>		NSTATEARRAY;
	typedef	NSTATEARRAY::iterator		ITR_NSTATEARRAY;

	typedef	std::vector<PCNTRANSITION>	TRANSITIONARRAY;
	typedef	TRANSITIONARRAY::iterator	ITR_TRANSITION;

	NSTATEARRAY	ciNStateArray;
	TRANSITIONARRAY	ciNTransitionArray;

	//	メモリ管理クラスのインスタンス

	typedef	PCInstanceList<CSREGEX>		CIPSREGEX;
	CIPSREGEX							ciIPSRegEx;

	typedef	PCInstanceList<CSREGEXNFA>	CIPSREGEXNFA;
	CIPSREGEXNFA						ciIPSRegExDFA;

	typedef	PCInstanceList<CBRACKETEX>	CIPBRACKETEX;
	CIPBRACKETEX						ciIPBracketEx;

	PCInstanceList<UCPSTRING>			ciIPUCPString;
	PCInstanceList<CNODE>				ciIPNode;
	PCInstanceList<CNODELIST>			ciIPNodeList;
	PCInstanceList<CNSTATE>			ciIPNState;
	PCInstanceList<CNTRANSITION>		ciIPNTransition;

	//------------------------------------------------------------
	//	PCRegEx	メンバ関数
	//------------------------------------------------------------
protected:
	void	Clear();

public:
	PCRegEx();
	~PCRegEx();

	void	ClearTemporary();
	bool	Init();

	//	パラメータの操作

	COPTIONS*	Options()	{ return ciOptionsStack.Options(); }

	bool	SetOptions(T_PCSTR_U pOptsB, T_PCSTR_U pOptsE)	{ return Options()->Set(pOptsB, pOptsE); }
	bool	SetOptions(T_PCSTR_U pOpts, size_t zOpts)		{ return Options()->Set(pOpts, zOpts); }
	bool	SetOptions(T_PCSTR_U pszOpts)					{ return Options()->Set(pszOpts); }

	DWORD		GetCompareStringFlags()	{ return Options()->GetCompareStringUCDFlags(); }
	T_PCSTR_U	GetLocale()				{ return Options()->GetLocaleString(); }

	void	PushNewOptions()					{ ciOptionsStack.PushNewOptions(); }
	void	PopOptions()						{ ciOptionsStack.PopOptions(); }
	void	SetOptions(DWORD dwOn, DWORD dwOff)	{ ciOptionsStack.Set(dwOn, dwOff); }
	void	UndoPushOptions()					{ ciOptionsStack.UndoPush(); }
	void	UndoPopOptions()					{ ciOptionsStack.UndoPop(); }
	void	UndoSetOptions()					{ ciOptionsStack.UndoSet(); }
	void	RestoreOptions()					{ ciOptionsStack.Restore(); }

	//	パターンの操作

	CPATTERN*	Pattern()		{ return &ciPattern; }
	T_PSTRING	PatternString()	{ return &strPattern; }
	T_PCSTR		PatternPCStr()	{ return strPattern.c_str(); }

	bool	SetPattern(T_PCSTR_U pPatternB, T_PCSTR_U pPatternE);
	bool	SetPattern(T_PCSTR_U pPatternB, size_t zPattern);
	bool	SetPattern(T_PCSTR_U pszPattern);

	//	Atom の作成

	PCBRACKETEX		CreateBracketEx();
	PCSREGEX		CreateSRegEx(int iType, LPVOID pOpt0, LPVOID pOpt1);
	PCSREGEX		CreateSRegEx(T_TYPE iType)	{ return CreateSRegEx(iType, (LPVOID)0, (LPVOID)0); }
	bool			GetSRegEx(PCSREGEX* ppSRegEx, T_INDEX iIndex);
	size_t			GetCapturesCount()	{ return (size_t)ciCaptureArray.size(); }
	PCSREGEX		CreateNamedSRegEx(ITR_UCPSTRING& itrNameB, ITR_UCPSTRING& itrNameE, CTEXTR* pciText);
	bool			FindNamedSRegEx(ITR_NAMEDSREGEXMAP& itr, ITR_UCPSTRING& itrB, ITR_UCPSTRING& itrE);
	bool			FindNamedSRegEx(CSREGEX** ppSRegEx, ITR_UCPSTRING& itrB, ITR_UCPSTRING& itrE);
	bool			FindNamedSRegEx(UCPSTRING** ppName, ITR_UCPSTRING& itrB, ITR_UCPSTRING& itrE);
	//bool			FindNamedSRegEx(CSREGEX** ppSRegEx, UCPSTRING* pStr);
	PCSREGEXNFA		CreateSRegExNFA(PCSREGEX pSRegEx);

	//	非決定性オートマトンを作成・操作するための関数

	void			CreateNState(T_INDEX* piNState, PCNSTATE* ppNState);
	void			CreateNState(T_INDEX* piNState, PCNSTATE* ppNState, int iType);
	CNTRANSITION*	CreateNTransition(CNSTATE* pSrcSt, CNSTATE* pDstSt);

	void	OptimizeNFA();
	bool	BuildNFA(T_PSTRING pstrError);

	//	後方参照を操作するための関数

	//bool	GetBackRef(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd, T_INDEX iRef);
	//bool	GetNamedBackRef(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd, UCPSTRING* pName);

	//	パターンマッチを調べるための関数

	bool	Match(SMATCHING* pMatching, PCRETEXT pciText, SLOOKBEHIND* pLookBehind);
	bool	Match(PCRETEXT pciText);

	//	メモリを割り当てるためのメンバ関数

	UCPSTRING*				AllocateString();
	PCRegExNode*			AllocateNode();
	PCBracketEx*			AllocateBracketEx();
	CNODELIST*				AllocateNodeList();
	PCRegExNState*			AllocateNState();
	PCRegExNTransition*	AllocateNTransition();
	PCSRegEx*				AllocateSRegEx();
	PCSRegExNFA*			AllocateSRegExDFA();

	//	デバッグ用
	void	Debug(T_STRING_U* pstrDebug);
};

#define CLASS_PREGEX_REGEX	PCRegEx


NS_PLIB_END
