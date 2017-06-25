//	XLCTextEx_1.0x	:	PLibTextEx

//	PGClassesText.h
//
#pragma once

NS_PLIB_BEGIN

#ifndef MAX_STR_LENGTH
#define	MAX_STR_LENGTH	INT_MAX
#endif

//======================================================================
//	PGClassesText �Ŏg�p����^�A�N���X�̒�`
//======================================================================
//----------------------------------------------------------------------
//	PInvalidTrailCode ��O�N���X
//----------------------------------------------------------------------
class PInvalidTrailCode	: public NS_PLIB::PSyntaxError
{
public:
	PInvalidTrailCode()									: PSyntaxError()							{}
	PInvalidTrailCode(const char *const& pszMsgA)		: PSyntaxError(pszMsgA)						{}
	PInvalidTrailCode(const PInvalidTrailCode& ciSrc)	: PSyntaxError((const PSyntaxError&)ciSrc)	{}
};

#define	THROWPE_INVALID_TRAIL_CODE(msg)	throw NS_PLIB::PInvalidTrailCode(msg)

class PCTextURBuffer;

//======================================================================
//	�萔
//======================================================================
//----------------------------------------------------------------------
//	�f�R�[�h�̃t���O
//----------------------------------------------------------------------
#define	PCTEXT_FLAG_DECODE_NONE		0
#define	PCTEXT_FLAG_DECODE_OCTAL	(1 << 0)
#define	PCTEXT_FLAG_DECODE_HEX		(1 << 1)
#define	PCTEXT_FLAG_DECODE_ESCCTRL	(1 << 2)
#define	PCTEXT_FLAG_DECODE_CTRLCHAR	(1 << 3)
#define	PCTEXT_FLAG_DECODE_UNICODE	(1 << 4)
#define	PCTEXT_FLAG_DECODE_ITSELF	(1 << 5)

#define	PCTEXT_FLAG_DECODE_OCTAL_HEX	\
	(PCTEXT_FLAG_DECODE_OCTAL |	PCTEXT_FLAG_DECODE_HEX)

#define	PCTEXT_FLAG_DECODE_OCTAL_HEX_ESCCTRL	\
	(PCTEXT_FLAG_DECODE_OCTAL_HEX | PCTEXT_FLAG_DECODE_ESCCTRL)

#define	PCTEXT_FLAG_DECODE_OCTAL_HEX_ESCCTRL_CTRLCHAR	\
	(PCTEXT_FLAG_DECODE_OCTAL_HEX_ESCCTRL | PCTEXT_FLAG_DECODE_CTRLCHAR)

#define	PCTEXT_FLAG_DECODE_OCTAL_HEX_ESCCTRL_CTRLCHAR_UNICODE	\
	(PCTEXT_FLAG_DECODE_OCTAL_HEX_ESCCTRL_CTRLCHAR | PCTEXT_FLAG_DECODE_UNICODE)

#define	PCTEXT_FLAG_DECODE_ALL	\
	(PCTEXT_FLAG_DECODE_OCTAL_HEX_ESCCTRL_CTRLCHAR_UNICODE | PCTEXT_FLAG_DECODE_ITSELF)

#define	PCTEXT_FLAG_DECODE_EXCEPT_CTRLCHAR	\
	(PCTEXT_FLAG_DECODE_OCTAL_HEX_ESCCTRL | PCTEXT_FLAG_DECODE_ITSELF)

//#define	PCTEXT_FLAG_DECODE_DEFAULT	PCTEXT_FLAG_DECODE_OCTAL_HEX_ESCCTRL

#define	PCTEXT_DECODE_OCTAL(flags)		(((flags) & PCTEXT_FLAG_DECODE_OCTAL) != 0)
#define	PCTEXT_DECODE_HEX(flags)		(((flags) & PCTEXT_FLAG_DECODE_HEX) != 0)
#define	PCTEXT_DECODE_ESCCTRL(flags)	(((flags) & PCTEXT_FLAG_DECODE_ESCCTRL) != 0)
#define	PCTEXT_DECODE_CTRLCHAR(flags)	(((flags) & PCTEXT_FLAG_DECODE_CTRLCHAR) != 0)
#define	PCTEXT_DECODE_UNICODE(flags)	(((flags) & PCTEXT_FLAG_DECODE_UNICODE) != 0)
#define	PCTEXT_DECODE_ITSELF(flags)		(((flags) & PCTEXT_FLAG_DECODE_ITSELF) != 0)

//----------------------------------------------------------------------
//	�����ʒu�̏��
//----------------------------------------------------------------------
#define	PCTEXT_POS_VALID	1
#define	PCTEXT_POS_ERROR	0
#define	PCTEXT_POS_EMPTY	-1
#define	PCTEXT_POS_UNDER	-2
#define	PCTEXT_POS_OVER		-3

#define	PCTEXT_GETVALIDCP(r)	(r > 0)

//======================================================================
//	class PITextUR
//	�e�L�X�g�𑀍삷�邽�߂̃N���X�̌^�ƃC���^�[�t�F�[�X���`����B
//======================================================================
class PITextUR
{
public:
	typedef	wchar_t										T_CHAR;
	typedef	T_CHAR*										T_PSTR;
	typedef	const T_CHAR*								T_PCSTR;
	typedef	std::basic_string<T_CHAR>					T_STRING,	*T_PSTRING;
	typedef	T_STRING::size_type							T_STRING_SIZE;
	typedef	PLib::Unicode::PCCompareStringUCDOptions	CCSOPTIONS,	*PCCSOPTIONS;

protected:

public:
	virtual	bool	Begin()	= 0;
	virtual	bool	Next()	= 0;
	virtual	bool	End()	= 0;

	virtual	int		GetCurrentCp(T_UCP* puiCp)	= 0;
	virtual	int		GetPreviousCp(T_UCP* puiCp)	= 0;
	virtual	int		GetNextCp(T_UCP* puiCp)		= 0;
};

//======================================================================
//	class PCTextUR
//
//	�ǂݎ���p�̃e�L�X�g�𑀍삷�邽�߂̃e�L�X�g�B
//	�G�X�P�[�v�V�[�P���X���f�R�[�h����B
//======================================================================
class PCTextUR	:	public PITextUR
{
public:
	typedef	PLib::PCIteratorStack<UCPSTRING>	CITRSTACK;

	//------------------------------------------------------------
	//	�֐��^�̒�`
	//------------------------------------------------------------
	//	�f�R�[�h�p�̊֐�
	typedef	bool (*PF_DECODE_ESCCNTRL)(T_UCP*, T_UCP, DWORD, T_PCSTR);

	//	pOptional ��������邽�߂̊֐�
	typedef	void (*DELETEOPTIONAL)(PVOID p);

protected:
	//------------------------------------------------------------
	//	PCTextUR �̃f�[�^�����o
	//------------------------------------------------------------
	//	���̓f�[�^
	T_PCSTR	pTextB;
	T_PCSTR	pTextE;
	size_t	zText;

	//	�w�肳�ꂽ������� iDecodeFlags �ɏ]���ăf�R�[�h���s���A���X�g�Ƃ��Ċi�[����B
	UCPSTRING		ciCpString;

	CITRSTACK		ciIteratorStack;
	ITR_UCPSTRING*	pitrCurrentPos;

	//	���������������邽�߂̃C���X�^���X�ƕϐ�
	int			iDecodeFlags;		//	���͕�������f�R�[�h����ۂ̃I�v�V�������w�肷��t���O
	PCCSOPTIONS	pciCSOptions;		//	CompareStringUCD �֐��̃I�v�V����
	DWORD		dwCSFlagsDefault;	//	pciCSOptions ���w�肳��Ă��Ȃ��ꍇ�Ɏg�p����B
	T_PCSTR		pszLocaleDefault;	//	pciCSOptions ���w�肳��Ă��Ȃ��ꍇ�Ɏg�p����B

	PF_DECODE_ESCCNTRL	pfDecodeEscCntrl;	//	�R���g���[��������\���G�X�P�[�v�V�[�P���X���f�R�[�h����֐�
	
	//------------------------------------------------------------
	//	PCTextUR �̃����o�֐�
	//------------------------------------------------------------
public:
	PCTextUR();
	~PCTextUR();

	virtual	void	Clear();
	virtual	bool	Init();

	//	�e�I�v�V�����̐ݒ�

	void	SetDefaultCSFlags(DWORD dwFlags)				{ dwCSFlagsDefault = dwFlags; }
	void	SetDefaultLocale(T_PCSTR_U pLocale)				{ pszLocaleDefault = pLocale; }
	void	SetCompareStringOptions(PCCSOPTIONS pOptions)	{ pciCSOptions = pOptions; }
	void	GetCompareStringOptions(DWORD* pdwFlags, T_PCSTR_U* ppszLocale);

	void	SetDecodeControlFunction(PF_DECODE_ESCCNTRL pfDec)	{ pfDecodeEscCntrl = pfDec; }
	void	SetDecodeFlags(int iFlags)	{ iDecodeFlags = iFlags; }
	int		GetDecodeFlags()			{ return iDecodeFlags; }

	//	���������p�̃��\�b�h

	virtual void	PushBackCp(T_UCP cpNew)	{ ciCpString.push_back(cpNew); }
	virtual T_UCP	ItrToCp(ITR_UCPSTRING& itr)	{ return *itr; }

	//	�e�L�X�g�̐ݒ�Ǝ擾

	virtual	bool	SetText(T_PCSTR pTextB, T_PCSTR pTextE);
	virtual	bool	SetText(T_PCSTR pText, size_t zText);
	virtual	bool	SetText(T_PCSTR pszText);

	virtual bool	GetSourceText(UCPSTRING* pstrText);
	virtual bool	GetSourceText(T_STRING* pstrText);

	//	�e�L�X�g���f�R�[�h���A�}���`�R�[�h�����̃��X�g�Ɋi�[����B
	virtual bool	GetDecodedCodepoint(	UCPSTRING*	puisBuf,
											T_PCSTR*	ppCurrent,
											int			iDecFlags,
											DWORD		dwFlagsC,
											bool		bNormalize,
											T_PCSTR		pszLocale);

	virtual void	ConvertToCpList();

	//	�ʒu�̏��ƈړ�
	virtual	bool	Begin();
	virtual	bool	Next();
	virtual	bool	Previous();
	virtual	bool	End();
	virtual	bool	Back();	//	�Ō�̕����������ʒu�Ƃ���B
	virtual bool	End(ITR_UCPSTRING& itr)		{ return (itr == ciCpString.end()); }
	virtual void	GetBegin(ITR_UCPSTRING& itr)	{ itr = ciCpString.begin(); }
	virtual void	GetEnd(ITR_UCPSTRING& itr)		{ itr = ciCpString.end(); }

	virtual bool	MoveTo(T_UCP uiCp, DWORD dwFlags, T_PCSTR_U pszLocale);

	bool	AtBeginning(ITR_UCPSTRING& itr)	{ return (itr == ciCpString.begin()); }
	bool	AtEnd(ITR_UCPSTRING& itr)			{ return (itr == ciCpString.end()); }

	bool	GetBeginPos(ITR_UCPSTRING& itr)	{ return ((itr = ciCpString.begin()) != ciCpString.end()); }
	void	GetEndPos(ITR_UCPSTRING& itr)		{ itr = ciCpString.end(); }

	bool	GetCurrentPos(ITR_UCPSTRING& itr)
	{
		if (pitrCurrentPos != NULL)
		{
			itr = *pitrCurrentPos;
			return true;
		}
		return false;
	}

	int	GetPreviousItr(ITR_UCPSTRING& itr);
	int	GetNextItr(ITR_UCPSTRING& itr);

	virtual	int	GetCurrentCp(T_UCP* pCp);
	virtual	int	GetPreviousCp(T_UCP* pCp);
	virtual	int	GetNextCp(T_UCP* pCp);

	//	��������������o���B
	bool	GetSubString(UCPSTRING* pucsBuffer, ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd);
	bool	GetSubString(T_STRING* pstrBuffer, ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd);

	bool	GetSubStringPreceding(UCPSTRING* pucsBuffer, ITR_UCPSTRING& itrPos);
	bool	GetSubStringPreceding(T_STRING_U* pucsBuffer, ITR_UCPSTRING& itrPos);
	bool	GetSubStringPreceding(UCPSTRING* pucsBuffer);
	bool	GetSubStringPreceding(T_STRING_U* pstrBuffer);

	bool	GetSubStringFollowing(UCPSTRING* pucsBuffer, ITR_UCPSTRING& itrPos);
	bool	GetSubStringFollowing(T_STRING_U* pucsBuffer, ITR_UCPSTRING& itrPos);
	bool	GetSubStringFollowing(UCPSTRING* pucsBuffer);
	bool	GetSubStringFollowing(T_STRING_U* pucsBuffer);

	bool	GetString(UCPSTRING* pucsBuffer);
	bool	GetString(T_STRING_U* pstrBuffer);

	//	iterator �X�^�b�N�̑���
	void	PushNewIterator();
	void	PopIterator();
	void	PopAndUpdateIterator();

	//	�ƍ�
	bool	MatchSubString(	T_UCP*		pCpB1,
							T_UCP*		pCpE1,
							T_UCP*		pCpB2,
							T_UCP*		pCpE2,
							DWORD		dwFlags,
							T_PCSTR_U	pszLocale);

	//	�f�o�b�O�p
#ifdef	PDEBUG
	virtual void	DebugCurrentState(T_STRING_U* pstrDebug, T_STRING_U* pstrOutput = NULL);
	virtual void	Debug(T_STRING_U* pstrDebug, T_STRING_U* pstrOutput = NULL);
	virtual void	Debug_GetText(T_STRING_U* pstrDebug);
#endif

	//------------------------------------------------------------
	//	friend
	//------------------------------------------------------------
	friend class PCTextURBuffer;
};

#define CLASS_PCTEXTUR	PCTextUR


//======================================================================
//	PCTextUR �𑀍삷�邽�߂̊֐�
//======================================================================
bool	PCTextUR_SkipBlank(PCTextUR* pciTextUR);
bool	PCTextUR_SkipSpace(PCTextUR* pciTextUR);
bool	PCTextUR_NextLine(PCTextUR* pciTextUR);

/*
bool	PCTextUR_RemoveQuote(T_PCSTR_U* ppUnquotedB, T_PCSTR_U* ppUnquotedE,
							 T_PCSTR_U pSrcB, T_PCSTR_U pSrcE,
							 DWORD dwFlags, T_PCSTR_U pszLocale);
*/
bool	PCTextUR_GetInt(int*		piVal,
						PCTextUR*	pciText,
						DWORD		dwFlags,
						T_PCSTR_U	pszLocale);

bool	PCTextUR_GetInt(int*		piVal,
						int			iMaxDigits,
						PCTextUR*	pciText,
						DWORD		dwFlags,
						T_PCSTR_U	pszLocale);


//======================================================================
//	PCTextURBuffer
//	PCTextUR �̕���������� CompareStringUCD �n�̊֐��Ŏg�p���邽�߂̃N���X�B
//	�f�[�^�`�F�b�N�͂��Ȃ��̂ŁA�m�F���Ă���g�p���邱�ƁB
//======================================================================
class PCTextURBuffer	: public PLib::Unicode::PIFUnicodeBuffer
{
public:

protected:
	ITR_UCPSTRING	itrBegin;
	ITR_UCPSTRING	itrEnd;
	ITR_UCPSTRING	itrCurrent;

public:
	PCTextURBuffer()	{}

	//------------------------------------------------------------
	//	Set	(1)	�f�[�^���Z�b�g����Ă��邩�ǂ�����Ԃ��B
	//------------------------------------------------------------
	virtual bool Set()	{ return true; }

	//------------------------------------------------------------
	//	Set	(2)	�f�[�^���Z�b�g����B
	//------------------------------------------------------------
	void Set(ITR_UCPSTRING& itrB, ITR_UCPSTRING& itrE)
	{
		itrBegin	= itrB;
		itrEnd		= itrE;
		itrCurrent	= itrBegin;
	}

	//------------------------------------------------------------
	//	Begin, End, Next, GetCurrentPos
	//------------------------------------------------------------
	virtual bool Begin()
	{
		itrCurrent	= itrBegin;
		return true;
	}

	virtual bool End()
	{
		return (itrCurrent == itrEnd);
	}

	virtual bool Next()
	{
		if (End())	return false;
		++itrCurrent;
		return true;
	}

	//------------------------------------------------------------
	//	GetCp
	//------------------------------------------------------------
	virtual bool GetCp(UINT* puiCp)
	{
		if (End())	return false;
		*puiCp	= *itrCurrent;
		return true;
	}
};


NS_PLIB_END
