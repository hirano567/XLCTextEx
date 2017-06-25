//	XLCTextEx_1.0x	:	PLibTextEx

//	PRegEx.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	PRegEx 内で使用する例外
//======================================================================
//----------------------------------------------------------------------
//	PRegExException
//----------------------------------------------------------------------
class PRegExException	: public NS_PLIB::PException
{
public:
	PRegExException()								: PException()							{}
	PRegExException(const char *const& pszMsgA)		: PException(pszMsgA)					{}
	PRegExException(const PRegExException& ciSrc)	: PException((const PException&)ciSrc)	{}
};

#define	THROWPE_PREGEX_EXCEPTION(msg)	throw NS_PLIB::PRegExException(msg)

//----------------------------------------------------------------------
//	PRegExNotMatch
//----------------------------------------------------------------------
class PRegExNotMatch	: public NS_PLIB::PRegExException
{
public:
	PRegExNotMatch()								: PRegExException()									{}
	PRegExNotMatch(const char *const& pszMsgA)		: PRegExException(pszMsgA)							{}
	PRegExNotMatch(const PRegExNotMatch& ciSrc)		: PRegExException((const PRegExException&)ciSrc)	{}
};

#define	THROWPE_PREGEX_NOT_MATCH(msg)	throw NS_PLIB::PRegExNotMatch(msg)

//----------------------------------------------------------------------
//	PRegExTimeOut
//----------------------------------------------------------------------
class PRegExTimeOut	: public NS_PLIB::PRegExException
{
public:
	PRegExTimeOut()									: PRegExException()									{}
	PRegExTimeOut(const char *const& pszMsgA)		: PRegExException(pszMsgA)							{}
	PRegExTimeOut(const PRegExTimeOut& ciSrc)		: PRegExException((const PRegExException&)ciSrc)	{}
};

#define	THROWPE_PREGEX_TIMEOUT(msg)	throw NS_PLIB::PRegExTimeOut(msg)


//======================================================================
//	型と定数の定義
//======================================================================

typedef	int	T_PREGEX_INDEX;

#define	PREGEX_INVALID_INDEX		((T_PREGEX_INDEX)-1)

//----------------------------------------------------------------------
//	各種の値
//----------------------------------------------------------------------
#define	PREGEX_INDEX_MAX			(INT_MAX - 1)
#define	PREGEX_NODE_MAX				INT_MAX
#define	PREGEX_STATE_MAX			INT_MAX
#define	PREGEX_TRANSITION_MAX		INT_MAX
#define	PREGEX_SREGEX_MAX			INT_MAX
#define	PREGEX_BACKREF_INDEX_MAX	INT_MAX

#define	PREGEX_INVALID_INDEX		((T_PREGEX_INDEX)-1)
#define	PREGEX_IS_INVALID_INDEX(i)	((i) < 0)

#define	PREGEX_CHAR_EPSILON	NULL

#define	PREGEX_COLLATING_ELEMENT_MAX_LENGTH	2

//----------------------------------------------------------------------
//	token
//----------------------------------------------------------------------
#define	PREGEX_TOKEN_ERROR			0
//#define	PREGEX_TOKEN_UNDEFINED	0
#define	PREGEX_TOKEN_END			1
#define	PREGEX_TOKEN_CODEPAGE		2
#define	PREGEX_TOKEN_ESCAPE			3
#define	PREGEX_TOKEN_PERIOD			4
#define	PREGEX_TOKEN_CIRCUMFLEX		5
#define	PREGEX_TOKEN_DOLLAR			6
#define	PREGEX_TOKEN_LPARENTHESIS	7
#define	PREGEX_TOKEN_RPARENTHESIS	8
#define	PREGEX_TOKEN_LBRACKET		9
#define	PREGEX_TOKEN_RBRACKET		10
#define	PREGEX_TOKEN_HYPHEN			11
#define	PREGEX_TOKEN_COLON			12
#define	PREGEX_TOKEN_EQUAL			13
#define	PREGEX_TOKEN_ASTERISK		14
#define	PREGEX_TOKEN_PLUS			15
#define	PREGEX_TOKEN_QUESTION		16
#define	PREGEX_TOKEN_LBRACE			17
#define	PREGEX_TOKEN_RBRACE			18
#define	PREGEX_TOKEN_COMMA			19
#define	PREGEX_TOKEN_VERTICALBAR	20
#define	PREGEX_TOKEN_NUMBERSIGN		21
#define	PREGEX_TOKEN_EXCLAMATION	22
#define	PREGEX_TOKEN_LESSTHAN		23
#define	PREGEX_TOKEN_GREATERTHAN	24

#define	PREGEX_TOKEN_AMPERSAND		25
#define	PREGEX_TOKEN_GRAVE			26
#define	PREGEX_TOKEN_APOSTROPHE		27
#define	PREGEX_TOKEN_UNDERSCORE		28
#define	PREGEX_TOKEN_TILDE			29

#define	PREGEX_TOKEN_CR				30
#define	PREGEX_TOKEN_LF				31

//#define	PREGEX_TOKEN_

//----------------------------------------------------------------------
//	node
//----------------------------------------------------------------------
#define	PREGEX_NODE_SHIFT		4
#define	PREGEX_NODE_MAJOR(t)	((t) & 0xF0)
#define	PREGEX_NODE_MINOR(t)	((t) & 0x0F)

#define	PREGEX_NODE_ERROR		0
#define	PREGEX_NODE_NONE		0
#define	PREGEX_NODE_UNDEFINED	0

//	ATOM		0001 XXXX
//#define	PREGEX_NODE					(1 << (PREGEX_NODE_SHIFT + 0))
#define	PREGEX_NODE	0

#define	PREGEX_NODE_ATOM								(PREGEX_NODE + 0)
#define	PREGEX_NODE_ATOM_CHAR							(PREGEX_NODE_ATOM + 1)
#define	PREGEX_NODE_ATOM_ANY_CHAR						(PREGEX_NODE_ATOM + 2)
#define	PREGEX_NODE_ATOM_CHAR_UNICODE_PROPERTY			(PREGEX_NODE_ATOM + 3)
#define	PREGEX_NODE_ATOM_CHAR_DIGIT						(PREGEX_NODE_ATOM + 4)
#define	PREGEX_NODE_ATOM_CHAR_NON_DIGIT					(PREGEX_NODE_ATOM + 5)
#define	PREGEX_NODE_ATOM_CHAR_WORD						(PREGEX_NODE_ATOM + 6)
#define	PREGEX_NODE_ATOM_CHAR_NON_WORD					(PREGEX_NODE_ATOM + 7)
#define	PREGEX_NODE_ATOM_CHAR_SPACE						(PREGEX_NODE_ATOM + 8)
#define	PREGEX_NODE_ATOM_CHAR_NON_SPACE					(PREGEX_NODE_ATOM + 9)
#define	PREGEX_NODE_ATOM_WORD_BOUNDARY					(PREGEX_NODE_ATOM + 10)
#define	PREGEX_NODE_ATOM_NOT_WORD_BOUNDARY				(PREGEX_NODE_ATOM + 11)
#define	PREGEX_NODE_ATOM_LAST_MATCH						(PREGEX_NODE_ATOM + 12)
#define	PREGEX_NODE_ATOM_START_MULTI					(PREGEX_NODE_ATOM + 13)
#define	PREGEX_NODE_ATOM_END_MULTI						(PREGEX_NODE_ATOM + 14)
#define	PREGEX_NODE_ATOM_START_SINGLE					(PREGEX_NODE_ATOM + 15)
#define	PREGEX_NODE_ATOM_END_SINGLE						(PREGEX_NODE_ATOM + 16)
#define	PREGEX_NODE_ATOM_ENDLF_SINGLE					(PREGEX_NODE_ATOM + 17)
#define	PREGEX_NODE_ATOM_BRACKETEX						(PREGEX_NODE_ATOM + 18)
#define	PREGEX_NODE_ATOM_REGEX							(PREGEX_NODE_ATOM + 19)
#define	PREGEX_NODE_ATOM_BACKREF						(PREGEX_NODE_ATOM + 20)
#define	PREGEX_NODE_ATOM_BACKREF_BYNAME					(PREGEX_NODE_ATOM + 21)

#define	PREGEX_NODE_ATOM_CTRL_SETOPTIONS				(PREGEX_NODE_ATOM + 22)
#define	PREGEX_NODE_ATOM_CTRL_COMMENT					(PREGEX_NODE_ATOM + 23)

#define	PREGEX_NODE_IS_ATOM(a)	(((a) | 0x1F) == 0x1F)

//	PIECE	（NG は not greedy の略）

#define	PREGEX_NODE_PIECE					(PREGEX_NODE + (1 << 5))
#define	PREGEX_NODE_PIECE_ONE_ATOM			(PREGEX_NODE_PIECE + 0)
#define	PREGEX_NODE_PIECE_ZERO_OR_MORE		(PREGEX_NODE_PIECE + 1)
#define	PREGEX_NODE_PIECE_ZERO_OR_MORE_NG	(PREGEX_NODE_PIECE + 2)
#define	PREGEX_NODE_PIECE_ONE_OR_MORE		(PREGEX_NODE_PIECE + 3)
#define	PREGEX_NODE_PIECE_ONE_OR_MORE_NG	(PREGEX_NODE_PIECE + 4)
#define	PREGEX_NODE_PIECE_ZERO_OR_ONE		(PREGEX_NODE_PIECE + 5)
#define	PREGEX_NODE_PIECE_ZERO_OR_ONE_NG	(PREGEX_NODE_PIECE + 6)
#define	PREGEX_NODE_PIECE_BOUND				(PREGEX_NODE_PIECE + 7)
#define	PREGEX_NODE_PIECE_BOUND_NG			(PREGEX_NODE_PIECE + 8)

#define	PREGEX_NODE_IS_PIECE(a)	(((a) & PREGEX_NODE_PIECE) == PREGEX_NODE_PIECE)

//	BRANCE
#define	PREGEX_NODE_BRANCH			(PREGEX_NODE + (1 << 6))
#define	PREGEX_NODE_BRANCH_EMPTY	(PREGEX_NODE_BRANCH + 1)

#define	PREGEX_NODE_IS_BRANCH(a)	(((a) & PREGEX_NODE_BRANCH) == PREGEX_NODE_BRANCH)

//	EXPRESSION
#define	PREGEX_NODE_EXPRESSION			(PREGEX_NODE + (1 << 7))
#define	PREGEX_NODE_EXPRESSION_EMPTY	(PREGEX_NODE_EXPRESSION + 1)

//	Conditional Expression
#define	PREGEX_NODE_EXPRESSION_CONDITIONAL_INDEX				(PREGEX_NODE_EXPRESSION + 2)
#define	PREGEX_NODE_EXPRESSION_CONDITIONAL_NAME					(PREGEX_NODE_EXPRESSION + 3)
#define	PREGEX_NODE_EXPRESSION_CONDITIONAL_POSITIVE_LOOKAHEAD	(PREGEX_NODE_EXPRESSION + 4)
#define	PREGEX_NODE_EXPRESSION_CONDITIONAL_NEGATIVE_LOOKAHEAD	(PREGEX_NODE_EXPRESSION + 5)
#define	PREGEX_NODE_EXPRESSION_CONDITIONAL_POSITIVE_LOOKBEHIND	(PREGEX_NODE_EXPRESSION + 6)
#define	PREGEX_NODE_EXPRESSION_CONDITIONAL_NEGATIVE_LOOKBEHIND	(PREGEX_NODE_EXPRESSION + 7)

#define	PREGEX_NODE_IS_EXPRESSION(a)	(((a) & PREGEX_NODE_EXPRESSION) == PREGEX_NODE_EXPRESSION)

//	EXPRESSIONEX
#define	PREGEX_NODE_EXPRESSIONEX	(PREGEX_NODE + (1 << 8))

#define	PREGEX_NODE_IS_EXPRESSIONEX(a)	(((a) & PREGEX_NODE_EXPRESSIONEX) == PREGEX_NODE_EXPRESSIONEX)

//	繰り返しの上限
#define	PREGEX_BOUND_MAX		256

//----------------------------------------------------------------------
//	transition
//----------------------------------------------------------------------
//#define	PREGEX_TRANSITION_MATCH_SHIFT	0
//#define	PREGEX_TRANSITION_MATCH			(1 << (PREGEX_TRANSITION_MATCH_SHIFT + 0))
#define	PREGEX_TRANSITION_MATCH							0
#define	PREGEX_TRANSITION_MATCH_UNDEFINED				(PREGEX_TRANSITION_MATCH + 0)
#define	PREGEX_TRANSITION_MATCH_EPSILON					(PREGEX_TRANSITION_MATCH + 1)
#define	PREGEX_TRANSITION_MATCH_CHAR					(PREGEX_TRANSITION_MATCH + 2)
#define	PREGEX_TRANSITION_MATCH_ANY_CHAR				(PREGEX_TRANSITION_MATCH + 3)
#define	PREGEX_TRANSITION_MATCH_UNICODE_PROPERTY		(PREGEX_TRANSITION_MATCH + 4)
#define	PREGEX_TRANSITION_MATCH_CHAR_DIGIT				(PREGEX_TRANSITION_MATCH + 5)
#define	PREGEX_TRANSITION_MATCH_CHAR_NON_DIGIT			(PREGEX_TRANSITION_MATCH + 6)
#define	PREGEX_TRANSITION_MATCH_CHAR_WORD				(PREGEX_TRANSITION_MATCH + 7)
#define	PREGEX_TRANSITION_MATCH_CHAR_NON_WORD			(PREGEX_TRANSITION_MATCH + 8)
#define	PREGEX_TRANSITION_MATCH_CHAR_SPACE				(PREGEX_TRANSITION_MATCH + 9)
#define	PREGEX_TRANSITION_MATCH_CHAR_NON_SPACE			(PREGEX_TRANSITION_MATCH + 10)
#define	PREGEX_TRANSITION_MATCH_WORD_BOUNDARY			(PREGEX_TRANSITION_MATCH + 11)
#define	PREGEX_TRANSITION_MATCH_NOT_WORD_BOUNDARY		(PREGEX_TRANSITION_MATCH + 12)
#define	PREGEX_TRANSITION_MATCH_LAST_MATCH				(PREGEX_TRANSITION_MATCH + 13)
#define	PREGEX_TRANSITION_MATCH_START_MULTI				(PREGEX_TRANSITION_MATCH + 14)
#define	PREGEX_TRANSITION_MATCH_END_MULTI				(PREGEX_TRANSITION_MATCH + 15)
#define	PREGEX_TRANSITION_MATCH_START_SINGLE			(PREGEX_TRANSITION_MATCH + 16)
#define	PREGEX_TRANSITION_MATCH_END_SINGLE				(PREGEX_TRANSITION_MATCH + 17)
#define	PREGEX_TRANSITION_MATCH_ENDLF_SINGLE			(PREGEX_TRANSITION_MATCH + 18)
#define	PREGEX_TRANSITION_MATCH_BRACKETEX				(PREGEX_TRANSITION_MATCH + 19)
#define	PREGEX_TRANSITION_MATCH_REGEX					(PREGEX_TRANSITION_MATCH + 20)
#define	PREGEX_TRANSITION_MATCH_EX_POSITIVE_LOOKAHEAD	(PREGEX_TRANSITION_MATCH + 21)
#define	PREGEX_TRANSITION_MATCH_EX_NEGATIVE_LOOKAHEAD	(PREGEX_TRANSITION_MATCH + 22)
#define	PREGEX_TRANSITION_MATCH_EX_POSITIVE_LOOKBEHIND	(PREGEX_TRANSITION_MATCH + 23)
#define	PREGEX_TRANSITION_MATCH_EX_NEGATIVE_LOOKBEHIND	(PREGEX_TRANSITION_MATCH + 24)
#define	PREGEX_TRANSITION_MATCH_EX_INDEPENDENT			(PREGEX_TRANSITION_MATCH + 25)
#define	PREGEX_TRANSITION_MATCH_BACKREF					(PREGEX_TRANSITION_MATCH + 26)
#define	PREGEX_TRANSITION_MATCH_BACKREF_BYNAME			(PREGEX_TRANSITION_MATCH + 27)

//----------------------------------------------------------------------
//	NFA State
//----------------------------------------------------------------------
#define	PREGEX_NSTATE_TYPE_NORMAL								0
#define	PREGEX_NSTATE_TYPE_EX_CAP_BEGIN						1
#define	PREGEX_NSTATE_TYPE_EX_CAP_END							2
#define	PREGEX_NSTATE_TYPE_EX_CAP_NAMED_BEGIN					3
#define	PREGEX_NSTATE_TYPE_EX_CAP_NAMED_END					4
#define	PREGEX_NSTATE_TYPE_EX_NCAP_BEGIN						5
#define	PREGEX_NSTATE_TYPE_EX_NCAP_END							6
#define	PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKAHEAD_BEGIN			7
#define	PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKAHEAD_END			8
#define	PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKAHEAD_BEGIN			9
#define	PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKAHEAD_END			10
#define	PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKBEHIND_BEGIN		11
#define	PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKBEHIND_END			12
#define	PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKBEHIND_BEGIN		13
#define	PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKBEHIND_END			14
#define	PREGEX_NSTATE_TYPE_EX_INDEPENDENT_BEGIN				15
#define	PREGEX_NSTATE_TYPE_EX_INDEPENDENT_END					16
#define	PREGEX_NSTATE_TYPE_EX_SETOPTIONS_BEGIN					17
#define	PREGEX_NSTATE_TYPE_EX_SETOPTIONS_END					18
#define	PREGEX_NSTATE_TYPE_CTRL_SETOPTIONS						19
#define	PREGEX_NSTATE_TYPE_EX_CONDITIONAL_INDEX				20
#define	PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NAME					21
#define	PREGEX_NSTATE_TYPE_EX_CONDITIONAL_POSITIVE_LOOKAHEAD	22
#define	PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NEGATIVE_LOOKAHEAD	23
#define	PREGEX_NSTATE_TYPE_EX_CONDITIONAL_POSITIVE_LOOKBEHIND	24
#define	PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NEGATIVE_LOOKBEHIND	25

#define	PREGEX_NSTATE_TYPE_UNUSED								-1

//----------------------------------------------------------------------
//	PCSRetEx
//----------------------------------------------------------------------
#define	PREGEX_EX_TYPE_CAP								0
#define	PREGEX_EX_TYPE_CAP_NAMED						1
#define	PREGEX_EX_TYPE_NCAP								2
#define	PREGEX_EX_TYPE_SETOPTIONS						3
#define	PREGEX_EX_TYPE_POSITIVE_LOOKAHEAD				4
#define	PREGEX_EX_TYPE_NEGATIVE_LOOKAHEAD				5
#define	PREGEX_EX_TYPE_POSITIVE_LOOKBEHIND				6
#define	PREGEX_EX_TYPE_NEGATIVE_LOOKBEHIND				7
#define	PREGEX_EX_TYPE_INDEPENDENT						8
#define	PREGEX_EX_TYPE_CTRL_SETOPTIONS					9
#define	PREGEX_EX_TYPE_CONDITIONAL_INDEX				10
#define	PREGEX_EX_TYPE_CONDITIONAL_NAME					11
#define	PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKAHEAD	12
#define	PREGEX_EX_TYPE_CONDITIONAL_NEGATIVE_LOOKAHEAD	13
#define	PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKBEHIND	14
#define	PREGEX_EX_TYPE_CONDITIONAL_NEGATIVE_LOOKBEHIND	15

//----------------------------------------------------------------------
//	PCBracketEx
//----------------------------------------------------------------------
#define	PREGEX_BE_TYPE_NORMAL							0
#define	PREGEX_BE_TYPE_OPERATION_UNION					1
#define	PREGEX_BE_TYPE_OPERATION_INTERSECTION			2
#define	PREGEX_BE_TYPE_OPERATION_DIFFERENCE				3
#define	PREGEX_BE_TYPE_OPERATION_SYMMETRIC_DIFFERENCE	4

#define	PREGEX_BE_ELEMENT_NONE				0
#define	PREGEX_BE_ELEMENT_CODEPAGE			1
#define	PREGEX_BE_ELEMENT_COLLATING_ELEMENT	2
#define	PREGEX_BE_ELEMENT_EQUIVALENCE_CLASS	3
#define	PREGEX_BE_ELEMENT_POSIX_CHARCLASS	4
#define	PREGEX_BE_ELEMENT_BRACKETEX			5

//----------------------------------------------------------------------
//	その他の定数
//----------------------------------------------------------------------
#define	PREGEX_OPTIONALDATA_NUM	2
#define	PREGEX_COLLATING_ELEMENT_MAX_LENGTH	2

//======================================================================
//	クラスの宣言と定義
//======================================================================
class PCRegExOptions;

class PCRegExOptionsStack;

class PBCRegExText;

class PCRegExPattern;

class PCRegExReplacement;

class PCRegExText;

class PCBracketEx;

class PCRegExNode;

class PCRegExNState;

class PCRegExNTransition;

class PCSRegEx;

class PCSRegExNFA;

class PCRegEx;

struct PSRegExMatchingState;

class PCRegExMatchingHistory;

//----------------------------------------------------------------------
//	成立条件を指定するための型
//----------------------------------------------------------------------
struct	PSRegExMatching
{
	typedef	T_PREGEX_INDEX	T_TYPE, T_INDEX;

	//	データメンバ

	T_TYPE	iType;
	LPVOID	pValue;

	//	メンバ関数

	PSRegExMatching()	: iType(0), pValue(NULL)	{}
	void	Clear()	{ iType = 0; pValue = NULL; }

	void	SetType(T_TYPE t)		{ iType = t; }
	T_TYPE	GetType()				{ return iType; }
	void	SetValue(LPVOID v)		{ pValue = v; }
	LPVOID	GetValue()				{ return pValue; }
	void	SetIndex(T_INDEX i)		{ pValue = (LPVOID)i; }
	T_INDEX	GetIndex()				{ return (T_INDEX)pValue; }
	void	SetInt(int i)			{ pValue = (LPVOID)i; }
	int		GetInt()				{ return (int)pValue; }
	void	SetName(UCPSTRING* pn)	{ pValue = (LPVOID)pn; }
	UCPSTRING*	GetName()			{ return (UCPSTRING*)pValue; }
	void	SetSRegEx(LPVOID p)		{ pValue = (LPVOID)p; }
	PCSRegEx*	GetSRegEx()			{ return (PCSRegEx*)pValue;}

	void	Set(T_TYPE t, LPVOID v)		{ SetType(t); SetValue(v); }
	void	Set(T_TYPE t, T_INDEX i)	{ SetType(t); SetIndex(i); }

	void	CopyFrom(PSRegExMatching* pSrc)
	{
		if (pSrc == NULL)	return;
		iType	= pSrc->GetType();
		pValue	= pSrc->GetValue();
	}

	BOOL	EqualTo(PSRegExMatching* pAnother)
	{
		if (pAnother == NULL)	return FALSE;
		if (iType != pAnother->GetType())	return FALSE;
		if (pValue != pAnother->GetValue())	return FALSE;
		return TRUE;
	}
};

//----------------------------------------------------------------------
//	PSRegExMatchTimes
//	マッチングを調べる際の処理回数を調べるための構造体
//----------------------------------------------------------------------
#define	REGEX_MATCH_MAXTIMES	(1 << 16)

struct PSRegExMatchTimes
{
	int	iTimes;
	int	iMaxTimes;

	PSRegExMatchTimes()	: iTimes(0), iMaxTimes(REGEX_MATCH_MAXTIMES)	{}

	void SetMaxTimes(int iMax)	{ if (iMax > 1) iMaxTimes = iMax; }
	void Init()					{ iTimes = 0; }

	int Increment()
	{
		++iTimes;
		if (iTimes > iMaxTimes)	THROWPE_PREGEX_TIMEOUT("");
		return iTimes;
	}

	int operator ++()
	{
		return Increment();
	}
};

//----------------------------------------------------------------------
//	PSRegExGlobalMatingStatus
//	グローバルマッチング処理において、状況を記録するための構造体
//----------------------------------------------------------------------
struct PSRegExGlobalMatingStatus
{
	bool			bMatchZeroLength;
	ITR_UCPSTRING	itrMatch;

	PSRegExGlobalMatingStatus()	: bMatchZeroLength(false)	{}
	void	Init()	{ bMatchZeroLength = false; }
};

//----------------------------------------------------------------------
//	LookBehind を処理するための構造体
//----------------------------------------------------------------------
struct PSRegExLookBehindState
{
	ITR_UCPSTRING	itrEnd;
	bool			bAtEnd;

	PSRegExLookBehindState()	: bAtEnd(false)	{}
	void	Init()	{ bAtEnd = false; }
};


//======================================================================
//	class PCBRegEx
//	共通して使用する型を定義する。
//======================================================================
class PCBRegEx
{
public:
	typedef	T_PREGEX_INDEX				T_TYPE, T_INDEX;

	typedef	wchar_t						T_CHAR;
	typedef	const T_CHAR*				T_PCSTR;
	typedef	std::basic_string<T_CHAR>	T_STRING,		*T_PSTRING;
	typedef	T_STRING::size_type			T_STRING_SIZE_T;
	typedef	PCTextUR					CTEXTR,			*PCTEXTR;

	typedef	PCRegExOptions				COPTIONS,		*PCOPTIONS;
	typedef	PCRegExOptionsStack			COPTIONSSTACK,	*PCOPTIONSSTACK;

	typedef	PBCRegExText				CBTEXT,			*PCBTEXT;
	typedef	PCRegExPattern				CPATTERN,		*PCPATTERN;
	typedef PCRegExText					CRETEXT,		*PCRETEXT;

	typedef	PCBracketEx					CBRACKETEX,		*PCBRACKETEX;
	typedef	PCSRegEx					CSREGEX,		*PCSREGEX;
	typedef	PCSRegExNFA					CSREGEXNFA,	*PCSREGEXNFA;
	typedef	PCRegEx						CREGEX,			*PCREGEX;

	typedef	PCRegExNode					CNODE,			*PCNODE;
	typedef	PCRegExNState				CNSTATE,		*PCNSTATE;
	typedef	PCRegExNTransition			CNTRANSITION,	*PCNTRANSITION;

	typedef	std::list<CNODE*>			CNODELIST;
	typedef	CNODELIST::iterator			ITR_NODELIST;
	typedef	CNODELIST::reverse_iterator	RIT_NODELIST;

	typedef	PSRegExMatching				SMATCHING,		*PSMATCHING;
	typedef	PSRegExMatchingState		SMATCHINGSTATE;
	typedef	PCRegExMatchingHistory		CMATCHINGHISTORY;
	typedef	PSRegExGlobalMatingStatus	SGLOBALMATCHING;
	typedef	PSRegExMatchTimes			SMATCHTIMES,	*PSMATCHTIMES;
	typedef	PSRegExLookBehindState		SLOOKBEHIND;
};

NS_PLIB_END
