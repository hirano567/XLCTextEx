//	XLCTextEx_1.0x	:	PLibTextEx

//	PGClassesText.h
//
#pragma once

NS_PLIB_BEGIN

#ifndef MAX_STR_LENGTH
#define	MAX_STR_LENGTH	INT_MAX
#endif

//======================================================================
//	PGClassesText で使用する型、クラスの定義
//======================================================================
//----------------------------------------------------------------------
//	PInvalidTrailCode 例外クラス
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
//	定数
//======================================================================
//----------------------------------------------------------------------
//	デコードのフラグ
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
//	処理位置の情報
//----------------------------------------------------------------------
#define	PCTEXT_POS_VALID	1
#define	PCTEXT_POS_ERROR	0
#define	PCTEXT_POS_EMPTY	-1
#define	PCTEXT_POS_UNDER	-2
#define	PCTEXT_POS_OVER		-3

#define	PCTEXT_GETVALIDCP(r)	(r > 0)

//======================================================================
//	class PITextUR
//	テキストを操作するためのクラスの型とインターフェースを定義する。
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
//	読み取り専用のテキストを操作するためのテキスト。
//	エスケープシーケンスをデコードする。
//======================================================================
class PCTextUR	:	public PITextUR
{
public:
	typedef	PLib::PCIteratorStack<UCPSTRING>	CITRSTACK;

	//------------------------------------------------------------
	//	関数型の定義
	//------------------------------------------------------------
	//	デコード用の関数
	typedef	bool (*PF_DECODE_ESCCNTRL)(T_UCP*, T_UCP, DWORD, T_PCSTR);

	//	pOptional を解放するための関数
	typedef	void (*DELETEOPTIONAL)(PVOID p);

protected:
	//------------------------------------------------------------
	//	PCTextUR のデータメンバ
	//------------------------------------------------------------
	//	入力データ
	T_PCSTR	pTextB;
	T_PCSTR	pTextE;
	size_t	zText;

	//	指定された文字列は iDecodeFlags に従ってデコードを行い、リストとして格納する。
	UCPSTRING		ciCpString;

	CITRSTACK		ciIteratorStack;
	ITR_UCPSTRING*	pitrCurrentPos;

	//	文字情報を処理するためのインスタンスと変数
	int			iDecodeFlags;		//	入力文字列をデコードする際のオプションを指定するフラグ
	PCCSOPTIONS	pciCSOptions;		//	CompareStringUCD 関数のオプション
	DWORD		dwCSFlagsDefault;	//	pciCSOptions が指定されていない場合に使用する。
	T_PCSTR		pszLocaleDefault;	//	pciCSOptions が指定されていない場合に使用する。

	PF_DECODE_ESCCNTRL	pfDecodeEscCntrl;	//	コントロール文字を表すエスケープシーケンスをデコードする関数
	
	//------------------------------------------------------------
	//	PCTextUR のメンバ関数
	//------------------------------------------------------------
public:
	PCTextUR();
	~PCTextUR();

	virtual	void	Clear();
	virtual	bool	Init();

	//	各オプションの設定

	void	SetDefaultCSFlags(DWORD dwFlags)				{ dwCSFlagsDefault = dwFlags; }
	void	SetDefaultLocale(T_PCSTR_U pLocale)				{ pszLocaleDefault = pLocale; }
	void	SetCompareStringOptions(PCCSOPTIONS pOptions)	{ pciCSOptions = pOptions; }
	void	GetCompareStringOptions(DWORD* pdwFlags, T_PCSTR_U* ppszLocale);

	void	SetDecodeControlFunction(PF_DECODE_ESCCNTRL pfDec)	{ pfDecodeEscCntrl = pfDec; }
	void	SetDecodeFlags(int iFlags)	{ iDecodeFlags = iFlags; }
	int		GetDecodeFlags()			{ return iDecodeFlags; }

	//	内部処理用のメソッド

	virtual void	PushBackCp(T_UCP cpNew)	{ ciCpString.push_back(cpNew); }
	virtual T_UCP	ItrToCp(ITR_UCPSTRING& itr)	{ return *itr; }

	//	テキストの設定と取得

	virtual	bool	SetText(T_PCSTR pTextB, T_PCSTR pTextE);
	virtual	bool	SetText(T_PCSTR pText, size_t zText);
	virtual	bool	SetText(T_PCSTR pszText);

	virtual bool	GetSourceText(UCPSTRING* pstrText);
	virtual bool	GetSourceText(T_STRING* pstrText);

	//	テキストをデコードし、マルチコード文字のリストに格納する。
	virtual bool	GetDecodedCodepoint(	UCPSTRING*	puisBuf,
											T_PCSTR*	ppCurrent,
											int			iDecFlags,
											DWORD		dwFlagsC,
											bool		bNormalize,
											T_PCSTR		pszLocale);

	virtual void	ConvertToCpList();

	//	位置の情報と移動
	virtual	bool	Begin();
	virtual	bool	Next();
	virtual	bool	Previous();
	virtual	bool	End();
	virtual	bool	Back();	//	最後の文字を処理位置とする。
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

	//	部分文字列を取り出す。
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

	//	iterator スタックの操作
	void	PushNewIterator();
	void	PopIterator();
	void	PopAndUpdateIterator();

	//	照合
	bool	MatchSubString(	T_UCP*		pCpB1,
							T_UCP*		pCpE1,
							T_UCP*		pCpB2,
							T_UCP*		pCpE2,
							DWORD		dwFlags,
							T_PCSTR_U	pszLocale);

	//	デバッグ用
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
//	PCTextUR を操作するための関数
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
//	PCTextUR の部分文字列を CompareStringUCD 系の関数で使用するためのクラス。
//	データチェックはしないので、確認してから使用すること。
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
	//	Set	(1)	データがセットされているかどうかを返す。
	//------------------------------------------------------------
	virtual bool Set()	{ return true; }

	//------------------------------------------------------------
	//	Set	(2)	データをセットする。
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
