//	XLCTextEx_1.0x	:	PLibTextEx

//	PRegEx.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	class PCRegExNode
//
//	���K�\������͖؂Ƃ��ĕ\�����Ƃ��̌��ߓ_�ƂȂ�\����
//
//	Atom �̏ꍇ
//		����		PREGEX_NODE_ATOM_CHAR		iValue ���g�p�i�}���`�R�[�h�����̃C���f�b�N�X�j
//		�s��		PREGEX_NODE_ATOM_START_MULTI		�t������f�[�^�Ȃ�
//		�s��		PREGEX_NODE_ATOM_END_MULTI		�t������f�[�^�Ȃ�
//		[]			PREGEX_NODE_ATOM_BRACKETEX	pBracketEx ���g�p
//		(���K�\��)	PREGEX_NODE_ATOM_REGEX		iValue ���g�p�i����Q�Ƃ̃C���f�b�N�X�j
//	piece
//		Node		PREGEX_NODE_PIECE_*			iValue ���g�p�i�q�m�[�h�̃C���f�b�N�X�j
//	branch
//		Node		PREGEX_NODE_BRANCH			pNodeList ���g�p
//	Expression
//		Node		PREGEX_NODE_EXPRESSION		pNodeList ���g�p
//======================================================================
class PCRegExNode	: public PCBRegEx
{
public:
	//------------------------------------------------------------
	//	�f�[�^�����o
	//------------------------------------------------------------
	PCREGEX	pciBaseRegEx;	//	��ƂȂ� PCRegEx �C���X�^���X�B
	T_INDEX	iIndex;
	T_TYPE	iNodeType;

	//	�q�m�[�h�̃��X�g�Bpiece �� expression�Abranch �Ŏg�p�B
	CNODELIST	ciNodeList;	

	//	�^�C�v�ʂ̃f�[�^
	LPVOID	pOptional[PREGEX_OPTIONALDATA_NUM];

public:
	//------------------------------------------------------------
	//	�����o�֐�
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
	LPVOID	GetOptionalData(int iIndex);	//	iIndex ���s�K�؂ȏꍇ�� NULL ��Ԃ��B

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
//	�񌈒萫�I�[�g�}�g���̏�Ԃ�\���\����
//======================================================================
#define	PREGEX_NSTATE_FLAG_NORMAL	0
#define	PREGEX_NSTATE_FLAG_START	(1 << 0)
#define	PREGEX_NSTATE_FLAG_FINAL	(1 << 1)

class PCRegExNState	: public PCBRegEx
{
	//------------------------------------------------------------
	//	PCRegExNState	�f�[�^�����o	(1)
	//------------------------------------------------------------
private:
	T_INDEX			iIndex;
	T_TYPE			iType;
	CREGEX*			pciBaseRegEx;
	CNTRANSITION*	pNTransition;
	int				iFlags;

	//------------------------------------------------------------
	//	PCRegExNState	�f�[�^�����o	(2)	�^�C�v�ʂ̃f�[�^
	//
	//	PREGEX_DSTATE_TYPE_* �̒l�ɉ����Ĉȉ��̂悤�Ɏg�p����B
	//	NORMAL				�g�p���Ȃ��B
	//	CTRL_SETOPTIONS		0:ON �ɂ���I�v�V�����A1:OFF �ɂ���I�v�V����
	//
	//	EX_CAP_BEGIN		Caputure �̃C���f�b�N�X
	//	EX_CAP_END
	//	EX_NCAP_BEGIN		�g�p���Ȃ��B
	//	EX_NCAP_END
	//	EX_SETOPTIONS_BEGIN	0:ON �ɂ���I�v�V�����A1:OFF �ɂ���I�v�V����
	//	EX_SETOPTIONS_END
	//	EX_NBACK_BEGIN
	//	EX_NBACK_END
	//
	//	�Ȃ��A_BEGIN �ł̓I�v�V������ Push�A_END �ł� Pop ���s����B
	//------------------------------------------------------------
	LPVOID		pOptional[PREGEX_OPTIONALDATA_NUM];

	//------------------------------------------------------------
	//	PCRegExNState	�����o�֐�
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
	LPVOID	GetOptionalData(int iIndex);	//	�G���[�̏ꍇ�� NULL ��Ԃ��B

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
//	�񌈒萫�I�[�g�}�g���̏�ԑJ�ڂ�\�����߂̍\����
//======================================================================
class PCRegExNTransition	: PCBRegEx
{
	//------------------------------------------------------------
	//	PCRegExNTransition	�f�[�^�����o
	//------------------------------------------------------------
private:
	T_INDEX			iIndex;				//	�f�o�b�O�p
	PCREGEX			pBaseRegEx;			//	��ƂȂ� PCRegEx �C���X�^���X
	CNSTATE*		pDestination;		//	�J�ڐ�̏��
	CNTRANSITION*	pNextTransition;	//	���̑J��
	SMATCHING		siMatching;			//	�}�b�`�̔�����@�ƃf�[�^

	//------------------------------------------------------------
	//	PCRegExNTransition	�����o�֐�
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
//	�i�����j���K�\���Ƃ��̉�͖؂��i�[����N���X
//======================================================================
class PCSRegEx	: public PCBRegEx
{
private:
	//------------------------------------------------------------
	//	PCSRegEx	�f�[�^�����o
	//------------------------------------------------------------
	T_TYPE		iType;
	CREGEX*		pciBaseRegEx;
	CPATTERN*	pciPattern;

	//	�^�C�v�ʂ̃f�[�^
	LPVOID		pOptional[PREGEX_OPTIONALDATA_NUM];

	//	��͖؂��쐬���邽�߂̕ϐ�
	typedef	std::vector<PCNODE>	NODEARRAY, *PNODEARRAY;
	typedef	NODEARRAY::iterator	ITR_NODEARRAY;

	NODEARRAY	ciNodeArray;
	CNODE*		pciRootNode;

	//------------------------------------------------------------
	//	PCSRegEx�����o�֐�
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
	LPVOID	GetOptionalData(int iIndex);	//	�G���[�̏ꍇ�� NULL ��Ԃ��B

	void		SetOptionalIndex(T_INDEX i)			{ SetOptionalData(0, (LPVOID)i); }
	T_INDEX		GetOptionalIndex()					{ return (T_INDEX)GetOptionalData(0); }

	void		SetOptionalName(UCPSTRING* pn)		{ SetOptionalData(0, (LPVOID)pn); }
	UCPSTRING*	GetOptionalName()					{ return (UCPSTRING*)GetOptionalData(0); }

	void		SetOptionalNState(CNSTATE* ps)	{ SetOptionalData(0, (LPVOID)ps); }
	CNSTATE*	GetOptionalNState()				{ return (CNSTATE*)GetOptionalData(0); }

	void		SetOptionalSRegEx(CSREGEX* pr)		{ SetOptionalData(0, (LPVOID)pr); }
	CSREGEX*	GetOptionalSRegEx()					{ return (CSREGEX*)GetOptionalData(0); }

	//------------------------------------------------------------
	//	��͖؂��쐬���邽�߂̊֐�
	//------------------------------------------------------------
	CNODE*	CreateNode(T_TYPE iType);
	CNODE*	Atom();
	CNODE*	Piece();
	CNODE*	Branch();
	CNODE*	Expression();

	void	Parse();

	//------------------------------------------------------------
	//	��͖؂ɃA�N�Z�X���邽�߂̊֐�
	//------------------------------------------------------------
	CNODE*	GetRootNode()	{ return pciRootNode; }

#ifdef	PDEBUG
	void	Debug(T_STRING_U* pstrDebug);
#endif
};

#define CLASS_SREGEX	PCSRegEx


//======================================================================
//	class PCSRegExNFA
//	PCSRegEx �N���X����񌈒萫�I�[�g�}�g�����쐬���邽�߂̃N���X
//======================================================================
class PCSRegExNFA	:	public PCBRegEx
{
protected:
	CREGEX*		pciBaseRegEx;
	CSREGEX*	pciSRegEx;

	//	�J�n��ԂƏI�����
	CNSTATE*	pciNFAStartState;
	CNSTATE*	pciNFAEndState;

	//	�f�o�b�O�p�ɃC���f�b�N�X���L�^���Ă����B
	T_INDEX		iNFAStartIndex;	//	�񌈒萫�I�[�g�}�g���̊J�n��Ԃ̃C���f�b�N�X
	T_INDEX		iNFAEndIndex;		//	�񌈒萫�I�[�g�}�g���̏I����Ԃ̃C���f�b�N�X

public:
	PCSRegExNFA();
	~PCSRegExNFA()	{}

	void	Clear();
	bool	Init();

	void		SetSRegEx(CSREGEX* p);
	CSREGEX*	SRegEx()				{ return pciSRegEx; }

	CNSTATE*	GetNFAStartState()		{ return pciNFAStartState; }
	CNSTATE*	GetNFAEndState()		{ return pciNFAEndState; }

	//	�񌈒萫�I�[�g�}�g�����쐬�E���삷�邽�߂̊֐�

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
//	�p�^�[������ NFA ���쐬�E�ێ�����B
//	NFA �ɂ��p�^�[���}�b�`���s���B
//======================================================================
class PCRegEx	: public PCBRegEx
{
private:
	//------------------------------------------------------------
	//	PCRegEx	�f�[�^�����o
	//------------------------------------------------------------
	//	��͒��ɕ������K�\�����ƂɃI�v�V�������Ǘ����邽�߂̃X�^�b�N

	COPTIONSSTACK	ciOptionsStack;

	//	�p�^�[�����i�[���A�g�[�N�������o�����߂̃N���X�C���X�^���X�B

	T_STRING	strPattern;
	CPATTERN	ciPattern;

	//	���K�\������͂��A�p�^�[���}�b�`�𒲂ׂ�ۂɎ�ƂȂ�N���X�C���X�^���X��
	//	������g�p���邽�߂̃N���X�C���X�^���X�B

	CSREGEX		ciMainSRegEx;
	CSREGEXNFA	ciMainSRegExNFA;

	//	�ԍ��t���������K�\�����Ǘ����邽�߂̃R���e�i

	typedef	std::vector<CSREGEX*>	CSREGEXARRAY;
	CSREGEXARRAY					ciCaptureArray;	//	����Q�Ɨp�̃C���f�b�N�X�ƕ������K�\����Ή�������B

	//	���O�t������Q�Ƃ��Ǘ����邽�߂̃R���e�i

	typedef	PLib::Unicode::PCCompareUCPString<NORM_IGNOREWIDTH>	CCOMPAREUCPSTRING;

	typedef	std::map<UCPSTRING*, CSREGEX*, CCOMPAREUCPSTRING>	NAMEDSREGEXMAP;
	typedef NAMEDSREGEXMAP::iterator							ITR_NAMEDSREGEXMAP;
	typedef	std::pair<UCPSTRING*, CSREGEX*>						PAIR_NAMEDSREGEXMAP;

	NAMEDSREGEXMAP	ciNamedSRegExMap;

	//	�񌈒萫�I�[�g�}�g�����f�o�b�O���邽�߂̕ϐ�

	typedef	std::vector<CNSTATE*>		NSTATEARRAY;
	typedef	NSTATEARRAY::iterator		ITR_NSTATEARRAY;

	typedef	std::vector<PCNTRANSITION>	TRANSITIONARRAY;
	typedef	TRANSITIONARRAY::iterator	ITR_TRANSITION;

	NSTATEARRAY	ciNStateArray;
	TRANSITIONARRAY	ciNTransitionArray;

	//	�������Ǘ��N���X�̃C���X�^���X

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
	//	PCRegEx	�����o�֐�
	//------------------------------------------------------------
protected:
	void	Clear();

public:
	PCRegEx();
	~PCRegEx();

	void	ClearTemporary();
	bool	Init();

	//	�p�����[�^�̑���

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

	//	�p�^�[���̑���

	CPATTERN*	Pattern()		{ return &ciPattern; }
	T_PSTRING	PatternString()	{ return &strPattern; }
	T_PCSTR		PatternPCStr()	{ return strPattern.c_str(); }

	bool	SetPattern(T_PCSTR_U pPatternB, T_PCSTR_U pPatternE);
	bool	SetPattern(T_PCSTR_U pPatternB, size_t zPattern);
	bool	SetPattern(T_PCSTR_U pszPattern);

	//	Atom �̍쐬

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

	//	�񌈒萫�I�[�g�}�g�����쐬�E���삷�邽�߂̊֐�

	void			CreateNState(T_INDEX* piNState, PCNSTATE* ppNState);
	void			CreateNState(T_INDEX* piNState, PCNSTATE* ppNState, int iType);
	CNTRANSITION*	CreateNTransition(CNSTATE* pSrcSt, CNSTATE* pDstSt);

	void	OptimizeNFA();
	bool	BuildNFA(T_PSTRING pstrError);

	//	����Q�Ƃ𑀍삷�邽�߂̊֐�

	//bool	GetBackRef(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd, T_INDEX iRef);
	//bool	GetNamedBackRef(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd, UCPSTRING* pName);

	//	�p�^�[���}�b�`�𒲂ׂ邽�߂̊֐�

	bool	Match(SMATCHING* pMatching, PCRETEXT pciText, SLOOKBEHIND* pLookBehind);
	bool	Match(PCRETEXT pciText);

	//	�����������蓖�Ă邽�߂̃����o�֐�

	UCPSTRING*				AllocateString();
	PCRegExNode*			AllocateNode();
	PCBracketEx*			AllocateBracketEx();
	CNODELIST*				AllocateNodeList();
	PCRegExNState*			AllocateNState();
	PCRegExNTransition*	AllocateNTransition();
	PCSRegEx*				AllocateSRegEx();
	PCSRegExNFA*			AllocateSRegExDFA();

	//	�f�o�b�O�p
	void	Debug(T_STRING_U* pstrDebug);
};

#define CLASS_PREGEX_REGEX	PCRegEx


NS_PLIB_END
