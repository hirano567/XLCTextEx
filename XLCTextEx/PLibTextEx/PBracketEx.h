//	XLCTextEx_1.0x	:	PLibTextEx

//	PBracketEx.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	PSBERange
//	�u���P�b�g�\���ɂ�镶���N���X�Ŕ͈͂�\�����߂̍\����
//======================================================================
struct PSBERange	: public PCBRegEx
{
	int		iTypeF;
	LPVOID	pRangeF;
	int		iTypeL;
	LPVOID	pRangeL;

	//------------------------------------------------------------
	//	�R���X�g���N�^
	//------------------------------------------------------------
	PSBERange()
		:	iTypeF(PREGEX_BE_ELEMENT_NONE),	pRangeF(NULL),
			iTypeL(PREGEX_BE_ELEMENT_NONE),	pRangeL(NULL)
	{}

	//------------------------------------------------------------
	//	Clear
	//------------------------------------------------------------
	virtual void Clear()
	{
		iTypeF	= PREGEX_BE_ELEMENT_NONE;
		pRangeF	= NULL;
		iTypeL	= PREGEX_BE_ELEMENT_NONE;
		pRangeL	= NULL;
	}

	//------------------------------------------------------------
	//	Get
	//------------------------------------------------------------
	int			GetFirstType()	{ return iTypeF; }
	LPVOID		GetFirst()		{ return pRangeF; }
	T_UCP		GetFirstCp()	{ return (T_UCP)pRangeF; }
	UCPSTRING*	GetFirstColl()	{ return (UCPSTRING*)pRangeF; }

	int			GetLastType()	{ return iTypeL; }
	LPVOID		GetLast()		{ return pRangeL; }
	T_UCP		GetLastCp()		{ return (T_UCP)pRangeL; }
	UCPSTRING*	GetLastColl()	{ return (UCPSTRING*)pRangeL; }

	//------------------------------------------------------------
	//	Set, SetFirst, SetLast
	//------------------------------------------------------------
	//	�L���ȃf�[�^���Z�b�g����Ă��邩��Ԃ��B
	bool Set()
	{
		return  (
			(iTypeF == PREGEX_BE_ELEMENT_CODEPAGE || iTypeF == PREGEX_BE_ELEMENT_COLLATING_ELEMENT) &&
			(iTypeL == PREGEX_BE_ELEMENT_CODEPAGE || iTypeL == PREGEX_BE_ELEMENT_COLLATING_ELEMENT)
			);
	}

	bool Set(PSBERange* pSrc)
	{
		pRangeF	= pSrc->pRangeF;
		iTypeF	= pSrc->iTypeF;
		pRangeL	= pSrc->pRangeL;
		iTypeL	= pSrc->iTypeL;
		return true;
	}

	bool SetFirst(LPVOID pRange, int iType)
	{
		pRangeF	= pRange;
		iTypeF	= iType;
		return true;
	}

	bool SetFirstCp(T_UCP cp)
	{
		pRangeF	= (LPVOID)cp;
		iTypeF	= PREGEX_BE_ELEMENT_CODEPAGE;
		return true;
	}

	bool SetFirstColl(UCPSTRING* pColl)
	{
		pRangeF	= (LPVOID)pColl;
		iTypeF	= PREGEX_BE_ELEMENT_COLLATING_ELEMENT;
		return true;
	}

	bool SetLast(LPVOID pRange, int iType)
	{
		pRangeL	= pRange;
		iTypeL	= iType;
		return true;
	}

	bool SetLastCp(T_UCP cp)
	{
		pRangeL	= (LPVOID)cp;
		iTypeL	= PREGEX_BE_ELEMENT_CODEPAGE;
		return true;
	}

	bool SetLastColl(UCPSTRING* pColl)
	{
		pRangeL	= (LPVOID)pColl;
		iTypeL	= PREGEX_BE_ELEMENT_COLLATING_ELEMENT;
		return true;
	}

	//------------------------------------------------------------
	//	Match
	//------------------------------------------------------------
	 bool Match(T_UCP cpOther, DWORD dwFlags, DWORD dwFlagsColl, T_PCSTR_U pszLocale);
	 bool Match(UCPSTRING* pColl, DWORD dwFlags, DWORD dwFlagsColl, T_PCSTR_U pszLocale);

	//------------------------------------------------------------
	//	�f�o�b�O�p
	//------------------------------------------------------------
#ifdef	PDEBUG
	 void Debug(T_STRING_U* pstrDebug);
#endif
};


//======================================================================
//	class PCBETerm
//
//	Bracket Expression �̍���\���N���X�B
//======================================================================
#define	PREGEX_BE_EQUIVALENCE_CLASS_CSFLAGS	\
	(0 | NORM_IGNORECASE | NORM_IGNORENONSPACE | NORM_IGNOREWIDTH | NORM_IGNOREKANATYPE)

class PCBETerm	: public PCBRegEx
{
private:
	//------------------------------------------------------------
	//	�^�̒�`
	//------------------------------------------------------------
	//	codepage
	typedef	std::set<T_UCP>				CCPSET;
	typedef	CCPSET::iterator			ITR_CPSET;

	//	�����͈�
	typedef	std::list<PSBERange*>		CRANGELIST;
	typedef	CRANGELIST::iterator		ITR_RANGELIST;
	
	//	collating element
	typedef	std::list<UCPSTRING*>		CCOLLLIST;
	typedef	CCOLLLIST::iterator			ITR_COLLLIST;

	//	�����N���X
	typedef	std::list<UCPSTRING*>		CEQUIVLIST;
	typedef	CEQUIVLIST::iterator		ITR_EQUIVLIST;

	//	POSIX �����N���X
	typedef	std::set<int>				CCCLASSSET;
	typedef	CCCLASSSET::iterator		ITR_CCLASSSET;

	//	Unicode Property
	typedef	std::set<int>				CUPROPSET;
	typedef	CUPROPSET::iterator			ITR_UPROPSET;

	//	BracketEx
	typedef	std::list<CBRACKETEX*>		CBRACKETEXLIST;
	typedef	CBRACKETEXLIST::iterator	ITR_BRACKETEXLIST;

	//------------------------------------------------------------
	//	PCBETerm	�f�[�^�����o
	//------------------------------------------------------------
	CBRACKETEX*	pciParentBE;
	int			iType;

	std::bitset<128>		ciAsciiBits;	//	0x00 - 0x7F �͂����ɂ��L�^���Ă����B
	std::bitset<128>		ciAsciiBitsIC;	//	0x00 - 0x7F �͂����ɂ��L�^���Ă����iIgnoreCase �p�j�B

	CCPSET			ciCpSet;
	CRANGELIST		ciRangeList;
	CCOLLLIST		ciCollList;
	CEQUIVLIST		ciEquivList;
	CCCLASSSET		ciPOSIXCClasses;
	CUPROPSET		ciUProperties;
	CBRACKETEXLIST	ciSubBracketEx;

	//	�������Ǘ��p�̃C���X�^���X
	PLib::PCInstanceAllocator<PSBERange>	ciAllocRange;
	PLib::PCInstanceAllocator<UCPSTRING>	ciAllocUCPString;
	PLib::PCInstanceAllocator<CBRACKETEX>	ciAllocBracketEx;

public:
	void	Clear();
	void	Init();

	PCBETerm()	: pciParentBE(NULL), iType(PREGEX_BE_TYPE_NORMAL)	{}
	~PCBETerm()	{ Clear(); }

	void		SetParent(CBRACKETEX* pParent)	{ pciParentBE = pParent; }
	CBRACKETEX* GetParent()						{ return pciParentBE; }
	void		SetType(int i)					{ iType = i; }
	int			GetType()						{ return iType; }
	bool		PermitMultichar()				{ return (!ciCollList.empty()); }

	//------------------------------------------------------------
	//	PCBETerm::Register
	//------------------------------------------------------------
	void	RegisterCodepage(T_UCP cpReg);
	void	Register7BitCodepage(T_UCP cpReg);
	void	Register7BitCodepages(T_UCP cpMin, T_UCP cpMax);
	void	RegisterRange(PSBERange* pRange);
	void	RegisterCollatingSequence(UCPSTRING* pColl);
	void	RegisterCollatingSequence(const T_UCP* pCollB, const T_UCP* pCollE);
	void	RegisterEquivalenceClass(UCPSTRING* pClass);
	void	RegisterEquivalenceClass(const T_UCP* pClassB, const T_UCP* pClassE);
	void	RegisterPOSIXCharClass(int iClass);
	void	RegisterPOSIXCharClass(const T_UCP* pClassB, const T_UCP* pClassE);
	void	RegisterUnicodeProperty(int iProp);
	void	RegisterSubBracketEx(CBRACKETEX* pBraketEx);

	bool	CreateUCPString(UCPSTRING** ppucStr);
	bool	CreateUCPString(UCPSTRING** ppucStr,
							ITR_UCPSTRING& itr1, ITR_UCPSTRING& itr2, PCTextUR* pciText);

	//------------------------------------------------------------
	//	PCBETerm::Parse
	//------------------------------------------------------------
	bool	Parse(CPATTERN* pciPattern);

	//------------------------------------------------------------
	//	PCBETerm::Match
	//------------------------------------------------------------
	bool	Match(	T_UCP			cpSrc,
					const T_UCP*	pszColl,
					DWORD			dwFlags,
					DWORD			dwFlagsColl,
					bool			bICase,
					T_PCSTR_U		pszLocale,
					bool			bMultiCp);

	//------------------------------------------------------------
	//	PCBETerm::Debug
	//------------------------------------------------------------
	void Debug(T_STRING_U* pstrDebug);
};

#define	CLASS_PREGEX_BETERM		PCBETerm


//======================================================================
//	class PCBracketEx
//
//	Bracket Expression ����͂��A�}�b�`���Ă��邩�𒲂ׂ邽�߂̃N���X�B
//======================================================================
class PCBracketEx	: public PCBRegEx
{
private:
	//	PCBETerm
	typedef	std::list<PCBETerm*>	CBETERMLIST;
	typedef	CBETERMLIST::iterator	ITR_BETERMLIST;

	//------------------------------------------------------------
	//	PCBracketEx	�f�[�^�����o
	//------------------------------------------------------------
	CREGEX*		pciBaseRegEx;
	CBETERMLIST	ciBETermList;
	bool		bAffirmative;	//	Negated class �łȂ��Ȃ� true�B
	size_t		zMaxColl;
	bool		bPermitMultiCp;	//	�����̕������ꕶ���Ƃ݂Ȃ��Ĕ���ł���B

	PLib::PCInstanceAllocator<PCBETerm>	ciAllocBETerm;

public:
	//------------------------------------------------------------
	//	PCBracketEx	�R���X�g���N�^�A�f�X�g���N�^�AClear�AInit
	//------------------------------------------------------------
	PCBracketEx();
	~PCBracketEx();

	void	Clear();
	void	Init();

	void	SetBase(CREGEX* pRegEx)	{ pciBaseRegEx = pRegEx; }
	CREGEX*	GetBase()				{ return pciBaseRegEx; }

	PCBETerm*	AllocateBETerm();

	//------------------------------------------------------------
	//	PCBracketEx::Parse
	//------------------------------------------------------------
	bool	Parse(CPATTERN* pciPattern);

	void	SetMaxColl(size_t zColl)	{ if (zColl > zMaxColl) zMaxColl = zColl; }

	//------------------------------------------------------------
	//	PCBracketEx::Match
	//------------------------------------------------------------
	bool	Match(	T_UCP			cpSrc,
					const T_UCP*	pszColl,
					DWORD			dwFlags,
					DWORD			dwFlagsColl,
					bool			bICase,
					T_PCSTR_U		pszLocale,
					bool			bMultiCp);
	bool	Match(CRETEXT* pciText);

	//------------------------------------------------------------
	//	PCBracketEx::Debug
	//------------------------------------------------------------
#ifdef	PDEBUG
	void Debug(T_PSTRING pstrDebug);
#endif
};

#define	CLASS_PREGEX_BRACKETEX		PCBracketEx

NS_PLIB_END
