//	XLCTextEx_1.0x	:	PLibTextEx

//	PBracketEx.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	PSBERange
//	ブラケット表現による文字クラスで範囲を表すための構造体
//======================================================================
struct PSBERange	: public PCBRegEx
{
	int		iTypeF;
	LPVOID	pRangeF;
	int		iTypeL;
	LPVOID	pRangeL;

	//------------------------------------------------------------
	//	コンストラクタ
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
	//	有効なデータがセットされているかを返す。
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
	//	デバッグ用
	//------------------------------------------------------------
#ifdef	PDEBUG
	 void Debug(T_STRING_U* pstrDebug);
#endif
};


//======================================================================
//	class PCBETerm
//
//	Bracket Expression の項を表すクラス。
//======================================================================
#define	PREGEX_BE_EQUIVALENCE_CLASS_CSFLAGS	\
	(0 | NORM_IGNORECASE | NORM_IGNORENONSPACE | NORM_IGNOREWIDTH | NORM_IGNOREKANATYPE)

class PCBETerm	: public PCBRegEx
{
private:
	//------------------------------------------------------------
	//	型の定義
	//------------------------------------------------------------
	//	codepage
	typedef	std::set<T_UCP>				CCPSET;
	typedef	CCPSET::iterator			ITR_CPSET;

	//	文字範囲
	typedef	std::list<PSBERange*>		CRANGELIST;
	typedef	CRANGELIST::iterator		ITR_RANGELIST;
	
	//	collating element
	typedef	std::list<UCPSTRING*>		CCOLLLIST;
	typedef	CCOLLLIST::iterator			ITR_COLLLIST;

	//	等価クラス
	typedef	std::list<UCPSTRING*>		CEQUIVLIST;
	typedef	CEQUIVLIST::iterator		ITR_EQUIVLIST;

	//	POSIX 文字クラス
	typedef	std::set<int>				CCCLASSSET;
	typedef	CCCLASSSET::iterator		ITR_CCLASSSET;

	//	Unicode Property
	typedef	std::set<int>				CUPROPSET;
	typedef	CUPROPSET::iterator			ITR_UPROPSET;

	//	BracketEx
	typedef	std::list<CBRACKETEX*>		CBRACKETEXLIST;
	typedef	CBRACKETEXLIST::iterator	ITR_BRACKETEXLIST;

	//------------------------------------------------------------
	//	PCBETerm	データメンバ
	//------------------------------------------------------------
	CBRACKETEX*	pciParentBE;
	int			iType;

	std::bitset<128>		ciAsciiBits;	//	0x00 - 0x7F はここにも記録しておく。
	std::bitset<128>		ciAsciiBitsIC;	//	0x00 - 0x7F はここにも記録しておく（IgnoreCase 用）。

	CCPSET			ciCpSet;
	CRANGELIST		ciRangeList;
	CCOLLLIST		ciCollList;
	CEQUIVLIST		ciEquivList;
	CCCLASSSET		ciPOSIXCClasses;
	CUPROPSET		ciUProperties;
	CBRACKETEXLIST	ciSubBracketEx;

	//	メモリ管理用のインスタンス
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
//	Bracket Expression を解析し、マッチしているかを調べるためのクラス。
//======================================================================
class PCBracketEx	: public PCBRegEx
{
private:
	//	PCBETerm
	typedef	std::list<PCBETerm*>	CBETERMLIST;
	typedef	CBETERMLIST::iterator	ITR_BETERMLIST;

	//------------------------------------------------------------
	//	PCBracketEx	データメンバ
	//------------------------------------------------------------
	CREGEX*		pciBaseRegEx;
	CBETERMLIST	ciBETermList;
	bool		bAffirmative;	//	Negated class でないなら true。
	size_t		zMaxColl;
	bool		bPermitMultiCp;	//	複数の文字を一文字とみなして判定できる。

	PLib::PCInstanceAllocator<PCBETerm>	ciAllocBETerm;

public:
	//------------------------------------------------------------
	//	PCBracketEx	コンストラクタ、デストラクタ、Clear、Init
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
