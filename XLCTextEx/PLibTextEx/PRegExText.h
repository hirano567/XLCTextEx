//	XLCTextEx_1.0x	:	PLibTextEx

//	PRegExText.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	PCTextUR �ł� Unicode ������� UINT �^ codepoint �̗�ɕϊ����ĕێ����Ă��邪�A
//	PBCRegExText �ł́A�e codepoint �����̂悤�ɗ��p����B
//
//	���� 24 �r�b�g�� Unicode codepoint�i21 �r�b�g�K�v�j���i�[����B 
//	���  8 �r�b�g�� �I�v�V�����f�[�^�i�����ł� token ID�j���i�[����B
//======================================================================
#define	PREGEX_CPEX_CPMASK			0x00FFFFFF
#define	PREGEX_CPEX_OPTSHIFT		24
#define	PREGEX_CPEX_GETCP(cx)		((cx) & PREGEX_CPEX_CPMASK)
#define	PREGEX_CPEX_GETOPT(cx)		((cx) >> PREGEX_CPEX_OPTSHIFT)
#define	PREGEX_CPEX_MAKE(cp, opt)	((cp) | ((opt) << PREGEX_CPEX_OPTSHIFT))


//======================================================================
//	class PBCRegExText
//
//	PRegEx �Ŏg�p����e�L�X�g�����N���X�̊��N���X�B
//	PCTextR �N���X�� Token ID �̂ɂ�鏈����ǉ����Ă���B
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
//	�w�肳�ꂽ�p�^�[������g�[�N����ǂݏo�����߂̃N���X�B
//	�ȉ��̏������ǉ�����Ă���B
//		�R�����g�O���[�v (# ) ��ǂݔ�΂��B
//		x �I�v�V�����w�莞�ɁA�󔒂� # ����s���܂ł�ǂݔ�΂��B
//		���@�G���[�̏���ʒm����B
//======================================================================
#define	PREGEX_PATTERN_DECODE	(PCTEXT_FLAG_DECODE_OCTAL_HEX_ESCCTRL_CTRLCHAR_UNICODE)

class PCRegExPattern	:	public PBCRegExText
{
public:
	//------------------------------------------------------------
	//	�f�[�^�����o
	//------------------------------------------------------------
protected:

	//------------------------------------------------------------
	//	�����o�֐�
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
//	���K�\���̏����ΏۂƂȂ�e�L�X�g�Ə��������i�[���邽�߂̃N���X
//======================================================================
#define	PREGEX_TEXT_DECODE	(PCTEXT_FLAG_DECODE_ALL)

class PCRegExText	:	public PCTextUR, public PCBRegEx
{
protected:

private:
	//------------------------------------------------------------
	//	struct SReference	����Q��
	//------------------------------------------------------------
	struct	SReference
	{
		ITR_UCPSTRING	itrBegin;
		ITR_UCPSTRING	itrEnd;
	};

	typedef	std::vector<SReference*>	CREFARRAY;
	typedef	CREFARRAY::size_type		SIZE_REFARRAY;

	//------------------------------------------------------------
	//	struct SNamedReference	���O�ɂ�����Q��
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
	//	PCRegExText	�f�[�^�����o
	//------------------------------------------------------------
	CMATCHINGHISTORY	ciHistory;
	CREFARRAY			ciRefArray;
	CNAMEDREFLIST		ciNamedRefList;

	PCInstanceList<SReference>		ciIPRef;
	PCInstanceList<SNamedReference>	ciIPNamedRef;

	COPTIONSSTACK	ciOptionsStack;		//	�ƍ��������̃I�v�V�������Ǘ����邽�߂̃X�^�b�N
	SGLOBALMATCHING	siGlobalMatching;	//	�O���[�o���}�b�`���O�̏��
	SMATCHTIMES		siMatchTimes;		//	�ƍ������̉񐔂��L�^���邽�߂̍\����
	LPVOID			pOptional;

public:
	//------------------------------------------------------------
	//	PCRegExText	�����o�֐�
	//------------------------------------------------------------
	PCRegExText();
	~PCRegExText();

	void	ClearReferences();
	void	Clear();
	bool	InitReferences();
	bool	Init();

	//	�ƍ��p�̊֐�

	bool	Match(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd);
	bool	HeadOfLine(bool bMultiLine);
	bool	EndOfLine(bool bMultiLine);

	//	�ƍ������̃I�v�V�����𑀍삷�邽�߂̊֐�

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

	//	�ƍ��̗������L�^�E�擾���邽�߂̊֐�

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

	//	����Q�Ƃ��擾����֐�

	bool	GetCurrentBackRef(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd, T_INDEX iRef);
	bool	GetCurrentNamedBackRef(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd, UCPSTRING* pName);

	//	�O���[�o���}�b�`���O�̊Ǘ�

	SGLOBALMATCHING*	GlobalMatching()		{ return &siGlobalMatching; }
	void	InitGlobalMatching()	{ siGlobalMatching.Init(); }
	bool	GlobalMatchingNotMove()	{ return (siGlobalMatching.itrMatch == *pitrCurrentPos); }

	//	�ƍ������̉񐔂𑀍삷�邽�߂̊֐�

	SMATCHTIMES*	MatchTimes()			{ return &siMatchTimes; }
	void			InitMatchTimes()		{ siMatchTimes.Init(); }
	void			IncrementMatchTimes()	{ siMatchTimes.Increment(); }


	//	�C���f�b�N�X�ɂ��Q�Ƃ̊Ǘ�

	void	SetupReferences(size_t i);
	bool	AppendReferenceBegin(T_PREGEX_INDEX i, ITR_UCPSTRING& itrBegin);
	bool	AppendReferenceEnd(T_PREGEX_INDEX i, ITR_UCPSTRING& itrEnd);

	bool	GetReference(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd, T_PREGEX_INDEX i);
	bool	GetReference(UCPSTRING* puisBuffer, T_PREGEX_INDEX i);
	bool	GetReference(T_STRING_U* pstrBuffer, T_PREGEX_INDEX i);

	//	���O�ɂ��Q�Ƃ̊Ǘ�

	SNamedReference*	GetNamedReference(UCPSTRING* pName);
	SNamedReference*	CreateNamedReference(UCPSTRING* pName);

	bool	AppendNamedReferenceBegin(UCPSTRING* pName, ITR_UCPSTRING& itrBegin);
	bool	AppendNamedReferenceEnd(UCPSTRING* pName, ITR_UCPSTRING& itrEnd);

	bool	GetNamedReference(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd, UCPSTRING* pName);
	bool	GetNamedReference(UCPSTRING* puisBuffer, UCPSTRING* pName);
	bool	GetNamedReference(T_STRING_U* pstrBuffer, UCPSTRING* pName);

	//	������̎擾
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

	//	�f�o�b�O�p
#ifdef	PDEBUG
	void	Debug(T_STRING_U* pstrDebug);
	void	DebugHistory(T_STRING_U* pstrDebug);
#endif
};

#define CLASS_PREGEX_TEXT	PCRegExText


//======================================================================
//	class PCRegExReplacement
//
//	�u����������쐬�E�K�p���邽�߂̃N���X�B
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
		//	�f�[�^�����o
		//--------------------------------------------------
		int				iType;
		UCPSTRING		ucsBuf;
		T_PREGEX_INDEX	iRef;

		//--------------------------------------------------
		//	�R���X�g���N�^
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
			return 0;	//	������ƎQ�ƈȊO�͕t������f�[�^���Ȃ��̂ŁA���ׂ�K�v���Ȃ��B
		}
	};

	typedef	std::list<SComponent*>		CCOMPONENTSLIST;
	typedef	CCOMPONENTSLIST::iterator	ITR_COMPONENTSLIST;

	//------------------------------------------------------------
	//	�f�[�^�����o
	//------------------------------------------------------------
	CCOMPONENTSLIST	ciComponentList;	//	�u����������\������v�f
	COPTIONS		ciOptions;			//	�u������������߂�����@���w�肷��
	SComponent*		pComponent;			//	�������̗v�f���w���|�C���^

	PCInstanceList<SComponent>	ciIPComponent;

	//------------------------------------------------------------
	//	�����o�֐�
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

	//	�f�o�b�O�p
#ifdef	PDEBUG
	void	Debug(T_STRING_U* pstrDebug);
#endif
};

#define CLASS_PREGEX_REPLACEMENT	PCRegExReplacement


NS_PLIB_END
