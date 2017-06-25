//	XLCTextEx_1.0x	:	PLibTextEx

//	PRegExUtility.h
//
#pragma once

NS_PLIB_REGEX_BEGIN

//======================================================================
//	Token ID �̎擾
//======================================================================
int	GetTokenId(T_UCP cpSrc, DWORD dwFlags, T_PCSTR_U pszLocale);

//======================================================================
//	PCTextUR �f�R�[�h�p�̊֐�
//======================================================================
bool	DecodeEscapedControl(T_UCP* pcpDst, T_UCP cpSrc, DWORD dwFlags, T_PCSTR_U pszLocale);

NS_PLIB_REGEX_END

NS_PLIB_BEGIN

//======================================================================
//	PRegEx �̃I�v�V����
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

//	�ȉ��͔p�~�\��

#define	PREGEX_FLAG_LINGUISTIC_IGNORECASE		(1 << 10)
#define	PREGEX_FLAG_LINGUISTIC_IGNOREDIACRITIC	(1 << 11)


//======================================================================
//	PRegExOptions_StrToDWord
//
//	�������
//		[gmsxidwk(li)(ld)]*-[gmsidwk(li)(ld)]*	�i�p�~�j
//		[gmsxidwkl]*-[gmsidwkl]*
//	�̌`���ł���Ɖ��肵�ĉ�͂���B
//	- �ȑO�̃t���O��ݒ肵�A�ȍ~�̃t���O����������
//	�A���t�@�x�b�g�A�󔒕����A�n�C�t���ȊO�̕��������ꂽ��I������B
//======================================================================
void	PRegExOptions_StrToDWord(DWORD* pdwOn, DWORD* pdwOff, PITextUR* pciText);


//======================================================================
//	class PCRegExOptions
//
//	�}�b�`�������̂��ׂĂ�u������B	g	(1 << 0)
//	�}���`���C�����[�h					m	(1 << 1)	�Ώۃe�L�X�g�� \r\n �ŋ�؂��Ă���Ƃ���B
//	�V���O�����C�����[�h				s	(1 << 2)	. �� \r\n �ɂ��}�b�`����B
//	�󔒂𖳎����A# ���R�����g�Ƃ���B	x	(1 << 3)
//	�啶������������ʂ��Ȃ��B			i	(1 << 4)	NORM_IGNORECASE
//	�t���L�����̗L������ʂ��Ȃ��B		d	(1 << 5)	NORM_IGNORENONSPACE
//	�S�p�A���p����ʂ��Ȃ��B			w	(1 << 6)	NORM_IGNOREWIDTH
//	�Ђ炪�ȁA�J�^�J�i����ʂ��Ȃ��B	k	(1 << 7)	NORM_IGNOREKANATYPE
//	���K�����Ĕ�r����B				n	(1 << 8)	CSTRUCD_NORMALIZE
//	���ȏ���������ʂ��Ȃ��B			l	(1 << 9)	CSTRUCD_IGNOREKANACASE
//
//	�i�ȉ��͔p�~�\��j
//
//	�啶������������ʂ��Ȃ��B			li	(1 << 9)	LINGUISTIC_IGNORECASE
//	�t���L�����̗L������ʂ��Ȃ��B		ld	(1 << 10)	LINGUISTIC_IGNOREDIACRITIC
//======================================================================
class PCRegExOptions
	: public PLib::Unicode::PCCompareStringUCDOptions
{
public:
private:
	//------------------------------------------------------------
	//	PCRegExOptions:	�f�[�^�����o
	//------------------------------------------------------------
	typedef	PLib::Unicode::PCCompareStringUCDOptions	CCSOPTIONS;
	typedef	PCRegExOptions								CREOPTIONS;

	bool	bGlobalMatching;
	bool	bMultilineMode;
	bool	bSinglelineMode;
	bool	bLegiblePattern;

	bool	bCollateNormalize;	//	Collating Element �� Normalize ���ďƍ�����B

public:
	//------------------------------------------------------------
	//	PCRegExOptions:	�R���X�g���N�^
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
	//	PCRegExOptions:	�e�p�����[�^��ݒ肷��
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
	//	PCRegExOptions:	�p�����[�^���܂Ƃ߂Đݒ肷��
	//------------------------------------------------------------
	void	Set(DWORD dwFlags);
	void	Unset(DWORD dwFlags);

	bool	Set(PCTextUR* pciText);
	bool	Set(T_PCSTR_U pStr, size_t zStr);
	bool	Set(T_PCSTR_U pStrB, T_PCSTR_U pStrE);
	bool	Set(T_PCSTR_U pszStr);

	void	CopyFrom(PCRegExOptions* pSrc);

	//------------------------------------------------------------
	//	PCRegExOptions:	�e�t���O���擾����
	//------------------------------------------------------------
	bool IsGlobalMatching()		{ return bGlobalMatching; }
	bool IsMultilineMode()		{ return bMultilineMode; }
	bool IsSinglelineMode()		{ return bSinglelineMode; }
	bool IsLegiblePattern()		{ return bLegiblePattern; }
	bool IsCollateNormalize()	{ return bCollateNormalize; }

	//------------------------------------------------------------
	//	PCRegExOptions:	�t���O���܂Ƃ߂Ď擾����
	//------------------------------------------------------------
	DWORD	GetDW();

	//------------------------------------------------------------
	//	�f�o�b�O�p
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
	//	�R���X�g���N�^
	//------------------------------------------------------------
	PCRegExOptionsStack()
	{
		Init();
	}

	//------------------------------------------------------------
	//	�f�X�g���N�^
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
		//	���݂̒l�� Undo �X�^�b�N�Ƀv�b�V�����Ă����B
		ciOptionsStack.SaveUndoValue();

		//	�V�����l���Z�b�g����B
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
//	�ƍ��̗������L�^���邽�߂̃N���X
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
	//	���������[�v���Ă��Ȃ������ׂ邽�߂̕⏕�֐�
	//	itrText ���ŐV�̈ʒu�ŁA������O�𒲂ׂ�΂悢�Ƃ����󋵂����肵�Ă���B
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
	//	�J��Ԃ�����	(1-1)
	//------------------------------------------------------------
	void	Begin()	{ ciHistory.Begin(); }
	bool	End()	{ return ciHistory.End(); }
	void	Next()	{ ciHistory.Next(); }
	bool	GetCurrent(SMATCHINGSTATE** pps)	{ return ciHistory.GetCurrent(pps); }

	//------------------------------------------------------------
	//	�J��Ԃ�����	(1-2)
	//------------------------------------------------------------
	void	RBegin()	{ ciHistory.RBegin(); }
	bool	REnd()	{ return ciHistory.REnd(); }
	void	RNext()	{ ciHistory.RNext(); }
	bool	RGetCurrent(SMATCHINGSTATE** pps)	{ return ciHistory.RGetCurrent(pps); }

	//------------------------------------------------------------
	//	�f�o�b�O�p
	//------------------------------------------------------------
#ifdef	PDEBUG
	void	Debug(T_STRING_U* pstrDebug, CRETEXT* pciText);
#endif
};

//======================================================================
//	GetUnicodePropertyMatching
//	�p�^�[�������񂩂� Unicode �������g�p�����������������o���B
//======================================================================
bool	GetUnicodePropertyMatching(int*			piMatching,
								   UCPSTRING*	pucsArg1,
								   UCPSTRING*	pucsArg2);


//======================================================================
//	ParseUnicodePropertyMatching
//
//	�����I����ApciText �� } �̎��̕������w���Ă���B
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

