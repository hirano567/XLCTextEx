//	XLCTextEx_1.0x	:	PLibTextEx

//	PTransChar.h
//
#pragma once

NS_PLIB_BEGIN

class	PCTransChar;

//======================================================================
//	class PCTrBuffer
//======================================================================
#define	PTRANSCHAR_DECODEFLAGS	(	\
	PCTEXT_FLAG_DECODE_OCTAL	|	\
	PCTEXT_FLAG_DECODE_HEX		|	\
	PCTEXT_FLAG_DECODE_ESCCTRL	|	\
	PCTEXT_FLAG_DECODE_CTRLCHAR	|	\
	PCTEXT_FLAG_DECODE_UNICODE	)
//	PCTEXT_FLAG_DECODE_ITSELF はつけない。


#define	PTRANSCHAR_ELEMENT_END			0
#define	PTRANSCHAR_ELEMENT_CODEPOINT	1
#define	PTRANSCHAR_ELEMENT_STRING		2

class PCTrBuffer
{
private:
	PCTransChar*	pciBase;
	PLib::PCTextUR	ciBuffer;

	T_UCP			cpRangeC;
	T_UCP			cpRangeE;
	bool			bDescend;
	bool			bIgnoreWidth;

public:
	//------------------------------------------------------------
	//	PCTrBuffer	コンストラクタとデストラクタ
	//------------------------------------------------------------
	PCTrBuffer(PCTransChar* pb = NULL);
	~PCTrBuffer();

	void	Clear();
	void	SetBase(PCTransChar* pb)	{ pciBase = pb; }
	void	InitState()	{ cpRangeC = INVALID_CODEPOINT; cpRangeE = INVALID_CODEPOINT; }

	//------------------------------------------------------------
	//	オプションの設定
	//------------------------------------------------------------
	void	SetOptIgnoreWidth(bool bw = true);

	//------------------------------------------------------------
	//	Set
	//------------------------------------------------------------
	bool Set(T_PCSTR_U pb, T_PCSTR_U pe)	{ return ciBuffer.SetText(pb, pe); }
	bool Set(T_PCSTR_U ps, size_t zs)		{ return ciBuffer.SetText(ps, zs); }
	bool Set(T_PCSTR_U psz)					{ return ciBuffer.SetText(psz); }

	//------------------------------------------------------------
	//	Begin, End, Next
	//------------------------------------------------------------
	bool Begin()	{ return ciBuffer.Begin(); }
	bool End()		{ return ciBuffer.End(); }
	bool Next()		{ return ciBuffer.Next(); }

	//------------------------------------------------------------
	//	GetElement
	//------------------------------------------------------------
	int GetElement(LPVOID* ppElement, bool bNormalize);
};


//======================================================================
//	class PCTransChar
//======================================================================
//----------------------------------------------------------------------
//	class PCCompareTrStr	PCTransChar クラス内の Codepoint 列を比較するためのクラス
//----------------------------------------------------------------------
class PCCompareTrStr
{
public:
	bool operator()(UCPSTRING* ps1, const UCPSTRING* ps2)	const
	{
		return (ps1->compare(*ps2) < 0);
	}
};

//----------------------------------------------------------------------
//	class PCTransChar
//----------------------------------------------------------------------
class PCTransChar
{
private:
	typedef	std::map<T_UCP, T_UCP>	CCPMAP;
	typedef	CCPMAP::iterator		ITR_CPMAP;
	typedef	std::pair<T_UCP, T_UCP>	PAIR_CPMAP;

	typedef	std::map<UCPSTRING*, UCPSTRING*, PCCompareTrStr>	CSTRMAP;
	typedef	CSTRMAP::iterator									ITR_STRMAP;
	typedef	std::pair<UCPSTRING*, UCPSTRING*>					PAIR_STRMAP;

	typedef	std::set<T_UCP>		CCPSET;
	typedef	CCPSET::iterator	ITR_CPSET;


	CCPMAP	ciCpMap;
	CSTRMAP	ciStrMap;
	CCPSET	ciFCpSet;	//	Codepointo 列の最初の Codepoint。検索用
	size_t	zMaxStrLength;

	PLib::PCInstanceAllocator<UCPSTRING>	ciAllocString;

	bool	bNormalize;		//	[. .] では、正規分解してから照合する。
	bool	bComplement;	//	補集合を処理の対象とする。
	bool	bDelete;		//	指定された文字を削除する。
	bool	bIgnoreWidth;	//	メタキャラクタの幅を無視する。

public:
	PCTransChar();
	~PCTransChar();

	void	Clear();
	void	ClearMap();
	bool	SetOpt(T_PCSTR_U pSrc, size_t zSrc);

	UCPSTRING*	AllocateUCPString()					{ return ciAllocString.Allocate(); }
	void		DeallocateUCPString(UCPSTRING* p)	{ ciAllocString.Deallocate(p); }

	bool	AppendCpTrans(T_UCP cSrc, T_UCP cDst);
	bool	AppendStrTrans(UCPSTRING* pcpsSrc, UCPSTRING* pcpsDst);
	bool	AppendStrTrans(const T_UCP* pczSrc, const T_UCP* pczDst);

	bool	SetTrans(PCTrBuffer* pciSrcBuf, PCTrBuffer* pciDstBuf);
	bool	SetTrans(T_PCSTR_U pSrcB, T_PCSTR_U pSrcE, T_PCSTR_U pDstB, T_PCSTR_U pDstE);
	bool	SetTrans(T_PCSTR_U pSrc, size_t zSrc, T_PCSTR_U pDst, size_t zDst);
	bool	SetTrans(T_PCSTR_U pszSrc, T_PCSTR_U pszDst);

	T_UCP	Translate(T_UCP cSrc);
	bool	Translate(UCPSTRING* pucsDst, UCPSTRING* pucsSrc);
	bool	Translate(T_STRING_U* pstrDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE);
	bool	Translate(T_STRING_U* pstrDst, T_PCSTR_U pSrc, size_t zStr);
	bool	Translate(T_STRING_U* pstrDst, T_PCSTR_U pszSrc);

#ifdef	PDEBUG
	void	Debug(T_STRING_U* pstrDebug);
#endif
};

NS_PLIB_END
