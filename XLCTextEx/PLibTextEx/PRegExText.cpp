//	XLCTextEx_1.0x	:	PLibTextEx

//	PRegExText.cpp
//
#include "stdafx.h"

NS_PLIB_BEGIN

//======================================================================
//	class PBCRegExText
//
//	PRegEx で使用するテキスト処理クラスの基底クラス。
//	PCTextR クラスに Token ID の処理機能を追加している。
//======================================================================
//----------------------------------------------------------------------
//	PBCRegExText::Clear
//----------------------------------------------------------------------
void CLASS_PREGEX_BTEXT::Clear()
{
	return CTEXTR::Clear();
}

//----------------------------------------------------------------------
//	PBCRegExText::Init
//----------------------------------------------------------------------
bool CLASS_PREGEX_BTEXT::Init()
{
	return CTEXTR::Init();
}

//----------------------------------------------------------------------
//	PBCRegExText::MoveTo
//----------------------------------------------------------------------
bool CLASS_PREGEX_BTEXT::MoveTo(int iToken)
{
	ITR_UCPSTRING	itr;

	if (pitrCurrentPos == NULL || *pitrCurrentPos == ciCpString.end())	return false;

	for (itr = *pitrCurrentPos; itr != ciCpString.end(); ++itr)
	{
		if (ItrToOpt(itr) == iToken)
		{
			*pitrCurrentPos	= itr;
			return true;
		}
	}
	return false;
}

//----------------------------------------------------------------------
//	PBCRegExText::ConvertToCpList
//----------------------------------------------------------------------
void CLASS_PREGEX_BTEXT::ConvertToCpList()
{
	ITR_UCPSTRING	itr;
	DWORD		dwFlags;
	T_PCSTR_U	pszLocale;

	T_UCP	cp;

	CTEXTR::ConvertToCpList();
	GetCompareStringOptions(&dwFlags, &pszLocale);

	for (itr = ciCpString.begin(); itr != ciCpString.end(); ++itr)
	{
		cp	= PREGEX_CPEX_GETCP(*itr);
		*itr	= (T_UCP)PREGEX_CPEX_MAKE(cp, PLib::RegEx::GetTokenId(cp, dwFlags, pszLocale));
		//int		opt	= PLib::RegEx::GetTokenId(cp, dwFlags, pszLocale);
		//int		cx	= (int)PREGEX_CPEX_MAKE(cp, opt);
		//*itr	= (UINT)cx;

		//*itr	= PREGEX_CPEX_MAKE(PREGEX_CPEX_GETCP(*itr), PLib::RegEx::GetTokenId(PREGEX_CPEX_GETCP(*itr), dwFlags, pszLocale));
	}

#ifdef	PDEBUG
	T_STRING_U	strDebug;
	this->DebugUCPString(&strDebug);
#endif
}

//----------------------------------------------------------------------
//	PBCRegExText::SetCurrentToken
//----------------------------------------------------------------------
bool CLASS_PREGEX_BTEXT::SetCurrentToken(int iToken)
{
	if (End())	false;

	**pitrCurrentPos	= PREGEX_CPEX_MAKE(ItrToCp(*pitrCurrentPos), iToken);
	return true;
}

//----------------------------------------------------------------------
//	PBCRegExText::GetPreviousToken
//----------------------------------------------------------------------
int CLASS_PREGEX_BTEXT::GetPreviousToken()
{
	ITR_UCPSTRING	itr;
	
	if (GetPreviousItr(itr) <= 0)	return PREGEX_TOKEN_ERROR;
	return ItrToOpt(itr);
}

//----------------------------------------------------------------------
//	PBCRegExText::GetCurrentToken
//----------------------------------------------------------------------
int CLASS_PREGEX_BTEXT::GetCurrentToken()
{
	if (pitrCurrentPos == NULL)	return PREGEX_TOKEN_ERROR;
	if (End())	return PREGEX_TOKEN_END;
	return (int)ItrToOpt(*pitrCurrentPos);
}

//----------------------------------------------------------------------
//	PBCRegExText::GetNextToken
//----------------------------------------------------------------------
int CLASS_PREGEX_BTEXT::GetNextToken()
{
	ITR_UCPSTRING	itr;
	int				ir;

	ir	= GetNextItr(itr);
	if (ir == PCTEXT_POS_OVER)	return PREGEX_TOKEN_END;
	if (ir <= 0)	return PREGEX_TOKEN_ERROR;
	return ItrToOpt(itr);
}

#ifdef	PDEBUG
//----------------------------------------------------------------------
//	PBCRegExText::DebugCurrentState
//----------------------------------------------------------------------
void CLASS_PREGEX_BTEXT::DebugCurrentState(T_STRING_U* pstrDebug, T_STRING_U* pstrOutput)
{
	T_UCP		cpc;
	int			itok;

	T_PCSTR_U	pfmt_d		= TQU("%d");
	T_PCSTR_U	pfmt_dp		= TQU("(%d)");
	T_PCSTR_U	pfmt_04X	= TQU("%04X");
	T_PCSTR_U	pfmt_04Xps	= TQU("(%04X) ");
	T_PCSTR_U	pLF			= TQU("\r\n");
	T_PCSTR_U	pHT			= TQU("\t");

	//------------------------------------------------------------
	//	Previous
	//------------------------------------------------------------
	pstrDebug->append(TQU("GetPreviousCp   : "));
	if (PCTEXT_GETVALIDCP(GetPreviousCp(&cpc)))
	{
		PLib::Unicode::AppendCodepointToString(pstrDebug, cpc);
	}
	itok	= GetPreviousToken();
	if (itok != PREGEX_TOKEN_ERROR)
	{
		pstrDebug->append(pHT);
		pstrDebug->append(PRegExDebug_GetToken(itok));
	}
	pstrDebug->append(pLF);

	//------------------------------------------------------------
	//	Current
	//------------------------------------------------------------
	pstrDebug->append(TQU("GetCurrentCp    : "));
	if (PCTEXT_GETVALIDCP(GetCurrentCp(&cpc)))
	{
		PLib::Unicode::AppendCodepointToString(pstrDebug, cpc);
	}
	itok	= GetCurrentToken();
	if (itok != PREGEX_TOKEN_ERROR)
	{
		pstrDebug->append(pHT);
		pstrDebug->append(PRegExDebug_GetToken(itok));
	}

	if (AtBeginning(*pitrCurrentPos))
	{
		pstrDebug->append(TQU("\tat Begginning"));
	}
	if (End())
	{
		pstrDebug->append(TQU("\tat End"));
	}
	pstrDebug->append(pLF);

	//------------------------------------------------------------
	//	Next
	//------------------------------------------------------------
	pstrDebug->append(TQU("GetNexCp        : "));
	if (PCTEXT_GETVALIDCP(GetNextCp(&cpc)))
	{
		PLib::Unicode::AppendCodepointToString(pstrDebug, cpc);
	}
	itok	= GetNextToken();
	if (itok != PREGEX_TOKEN_ERROR)
	{
		pstrDebug->append(pHT);
		pstrDebug->append(PRegExDebug_GetToken(itok));
	}
	pstrDebug->append(pLF);

	return;
}

//----------------------------------------------------------------------
//	PBCRegExText::DebugUCPString
//----------------------------------------------------------------------
void CLASS_PREGEX_BTEXT::DebugUCPString(T_PSTRING_U pstrDebug)
{
	ITR_UCPSTRING	itr;
	T_UCP			cp;
	int				it;
	const size_t	zOpBuf	= 64;
	T_CHAR_U		OpBuf[zOpBuf];
	T_CHAR_U		wcBuf[3];
	T_PCSTR_U		pf	= TQU("%s\t%s\r\n");

	for (itr = ciCpString.begin(); itr != ciCpString.end(); ++itr)
	{
		cp	= ItrToCp(itr);
		it	= ItrToOpt(itr);
		PLib::Unicode::ConvertFromCodepoint(wcBuf, cp);
		SPRINTF_U(OpBuf, zOpBuf, pf, wcBuf, PRegExDebug_GetToken(it));
		pstrDebug->append(OpBuf);
	}
}

#endif


//======================================================================
//	class PCRegExPattern
//
//	指定されたパターンからトークンを読み出すためのクラス。
//======================================================================
//----------------------------------------------------------------------
//	PCRegExPattern	コンストラクタ
//----------------------------------------------------------------------
CLASS_PREGEX_PATTERN::PCRegExPattern()
:	PBCRegExText()
{
	SetDecodeControlFunction(PLib::RegEx::DecodeEscapedControl);
	SetDecodeFlags(PREGEX_PATTERN_DECODE);
}

//----------------------------------------------------------------------
//	PCRegExPattern	デストラクタ
//----------------------------------------------------------------------
CLASS_PREGEX_PATTERN::~PCRegExPattern()
{
}

//----------------------------------------------------------------------
//	PCRegExPattern::SkipCommentGroup
//
//	処理対象文字が # でない場合は true を返して終了する。
//----------------------------------------------------------------------
bool CLASS_PREGEX_PATTERN::SkipCommentGroup()
{
	int		iToken;

	//	# でない場合はコメントがないので true を返す。
	if (GetCurrentToken() != PREGEX_TOKEN_NUMBERSIGN)	return true;
	Next();

	//	) まで読み飛ばす。
	iToken	= GetCurrentToken();
	while(iToken != PREGEX_TOKEN_END	&&
		iToken != PREGEX_TOKEN_ERROR	&&
		iToken != PREGEX_TOKEN_RPARENTHESIS)
	{
		Next();
		iToken	= GetCurrentToken();
	}
	if (iToken == PREGEX_TOKEN_RPARENTHESIS)
	{
		//	) の次に移動させておく。
		Next();
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCRegExPattern::SkipCommentLine
//	# から改行までを読み飛ばす。
//	処理対象文字が # 出ない場合は true を返す。
//----------------------------------------------------------------------
bool CLASS_PREGEX_PATTERN::SkipCommentLine()
{
	int		iToken;

	//	# でない場合はコメントがないので true を返す。
	if (GetCurrentToken() != PREGEX_TOKEN_NUMBERSIGN)	return true;
	Next();

	//	次の行まで読み飛ばす。
	iToken	= GetCurrentToken();
	while(iToken != PREGEX_TOKEN_END	&&
		iToken != PREGEX_TOKEN_ERROR	&&
		iToken != PREGEX_TOKEN_LF		&&
		iToken != PREGEX_TOKEN_CR)
	{
		Next();
		iToken	= GetCurrentToken();
	}
	if (iToken == PREGEX_TOKEN_END || iToken == PREGEX_TOKEN_ERROR)
	{
		return false;
	}
	return PLib::PCTextUR_NextLine(this);
}

//----------------------------------------------------------------------
//	PCRegExPattern::SkipBlankAndComment
//----------------------------------------------------------------------
bool CLASS_PREGEX_PATTERN::SkipBlankAndComment()
{
	int			iToken;
	T_UCP		cpCurrent;

	while (true)
	{
		iToken	= GetCurrentToken();
		if (iToken == PREGEX_TOKEN_END || iToken == PREGEX_TOKEN_ERROR)	break;
		if (!PCTEXT_GETVALIDCP(GetCurrentCp(&cpCurrent)))	THROWPE_LOGIC_ERROR("");

		//	space の場合、それに続く space も読み飛ばす。
		if (PLib::t_IsSpace<T_UCP>(cpCurrent))
		{
			PCTextUR_SkipSpace(this);
			continue;
		}
		//	# の場合
		if (iToken == PREGEX_TOKEN_NUMBERSIGN)
		{
			//	改行の前まで読み飛ばす。
			while (!End())
			{
				if (PCTEXT_GETVALIDCP(GetCurrentCp(&cpCurrent)))
				{
					if (PLib::Unicode::IsCRLF(cpCurrent, true))	break;
				}
				Next();
			}
			//	続いている改行をすべて読み飛ばす。
			PCTextUR_SkipSpace(this);
			continue;
		}
		break;
	}
	return true;
}

//----------------------------------------------------------------------
//	PCRegExPattern::ReportCurrentPos
//	処理状況（特にエラーが発生した場所）の情報
//----------------------------------------------------------------------
bool CLASS_PREGEX_PATTERN::ReportCurrentPos(T_STRING_U* pstrReport, T_PCSTR_U pszPos)
{
	ITR_UCPSTRING	itrCurrent;

	T_CHAR_U	cSP	= TQU(' ');
	T_CHAR_U	cDQ	= TQU('"');
	T_CHAR_U	cGT	= TQU('>');
	T_CHAR_U	cLT	= TQU('<');

	if (pTextB == NULL || pTextB >= pTextE || pstrReport == NULL)	return false;
	if (!GetCurrentPos(itrCurrent))	THROWPE_LOGIC_ERROR("");
	if (AtBeginning(itrCurrent))
	{
		pstrReport->append(pszPos);
		pstrReport->append(1, cGT);
		pstrReport->append(1, cSP);
		pstrReport->append(1, cDQ);
		GetString(pstrReport);
		pstrReport->append(1, cDQ);
	}
	else if (AtEnd(itrCurrent))
	{
		pstrReport->append(1, cDQ);
		GetString(pstrReport);
		pstrReport->append(1, cDQ);
		pstrReport->append(1, cSP);
		pstrReport->append(1, cLT);
		pstrReport->append(pszPos);
	}
	else
	{
		pstrReport->append(1, cDQ);
		GetSubStringPreceding(pstrReport, itrCurrent);
		pstrReport->append(1, cDQ);
		pstrReport->append(1, cSP);
		pstrReport->append(pszPos);
		pstrReport->append(1, cGT);
		pstrReport->append(1, cSP);
		pstrReport->append(1, cDQ);
		GetSubStringFollowing(pstrReport, itrCurrent);
		pstrReport->append(1, cDQ);
	}

	return true;
}


//======================================================================
//	class PCRegExText
//
//	テキスト読み出し専用バッファを作成するためのクラス
//======================================================================
//----------------------------------------------------------------------
//	PCRegExText	コンストラクタ
//----------------------------------------------------------------------
CLASS_PREGEX_TEXT::PCRegExText()
:	PCTextUR(),
	pOptional(NULL)
{
	SetDecodeControlFunction(PLib::RegEx::DecodeEscapedControl);
	SetDecodeFlags(PREGEX_TEXT_DECODE);
}

//----------------------------------------------------------------------
//	PCRegExText	デストラクタ
//----------------------------------------------------------------------
CLASS_PREGEX_TEXT::~PCRegExText()
{
	Clear();
}

//----------------------------------------------------------------------
//	PCRegExText::ClearReferences
//----------------------------------------------------------------------
void CLASS_PREGEX_TEXT::ClearReferences()
{
	ciRefArray.clear();
	ciNamedRefList.clear();
	ciIPRef.Clear();
	ciIPNamedRef.Clear();
}

//----------------------------------------------------------------------
//	PCRegExText::Clear
//----------------------------------------------------------------------
void CLASS_PREGEX_TEXT::Clear()
{
	PCTextUR::Clear();
	ClearHistory();
	ClearReferences();
	InitGlobalMatching();
	InitMatchTimes();
	ClearOptional();
}

//----------------------------------------------------------------------
//	PCRegExText::InitReferences
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::InitReferences()
{
	ciRefArray.clear();
	ciNamedRefList.clear();
	ciIPRef.Init();
	ciIPNamedRef.Init();
	return true;
}

//----------------------------------------------------------------------
//	PCRegExText::Init
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::Init()
{
	PCTextUR::Init();
	InitHistory();
	InitReferences();
	InitGlobalMatching();
	InitMatchTimes();
	return true;
}


//----------------------------------------------------------------------
//	PCRegExText::Match
//	指定された文字列が現在の位置からの部分文字列と一致しているか調べる。
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::Match(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd)
{
	ITR_UCPSTRING	itrPos;
	T_UCP			cpCurrent;
	DWORD			dwFlags		= ciOptionsStack.Options()->GetCompareStringUCDFlags();
	T_PCSTR_U		pszLocale	= ciOptionsStack.Options()->GetLocaleString();

	PushNewIterator();

	for (itrPos = itrBegin; (itrPos != itrEnd && !End()); Next(), ++itrPos)
	{
		if (!PCTEXT_GETVALIDCP(GetCurrentCp(&cpCurrent)))	break;
		if (PLib::Unicode::CompareCodepointUCD(*itrPos, cpCurrent, dwFlags, pszLocale) != CSTR_EQUAL)
		{
			break;
		}
	}
	if (itrPos == itrEnd)
	{
		PopAndUpdateIterator();
		return true;
	}
	PopIterator();

	return false;
}

//----------------------------------------------------------------------
//	PCRegExText::HeadOfLine
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::HeadOfLine(bool bMultiLine)
{
	T_UCP	cpPrev, cpCurrent;
	int		ir;

	//	文字列の先頭の場合、空文字列の場合はモードに関係なく true
	ir	= GetPreviousCp(&cpPrev);
	if (ir == PCTEXT_POS_UNDER || ir == PCTEXT_POS_EMPTY)	return true;

	//	マルチラインモードでない場合、上に当てはまらないなら false
	if (bMultiLine == false)	return false;

	if (ir == PCTEXT_POS_ERROR)
	{
		THROWPE_RUNTIME_ERROR("PCRegExText::HeadOfLine");
		return false;
	}

	//	マルチラインモードの場合、前の文字が CR または LF でも true とする。
	//	ただし、前後が \r と \n の場合は当てはまらない。
	if (PLib::Unicode::IsLF(cpPrev, true))	return true;
	if (PLib::Unicode::IsCR(cpPrev, true))
	{
		ir	= GetCurrentCp(&cpCurrent);
		if (PCTEXT_GETVALIDCP(ir) && PLib::Unicode::IsLF(cpCurrent, true))	return false;
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCRegExText::EndOfLine
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::EndOfLine(bool bMultiLine)
{
	T_UCP	cpPrevious, cpCurrent;
	int		ir;

	//	テキスト終端の場合はモードに関係なく true
	if (End())	return true;

	//	マルチラインモードでない場合、上に当てはまらないなら false。
	if (bMultiLine == false)	return false;

	if (!PCTEXT_GETVALIDCP(GetCurrentCp(&cpCurrent)))
	{
		//	現在の文字に NULL が返されるのは文字列の末尾の場合だけである。
		THROWPE_LOGIC_ERROR("PCRegExText::EndOfLine");
		return false;
	}
	if (PLib::Unicode::IsCR(cpCurrent, true))	return true;
	if (PLib::Unicode::IsLF(cpCurrent, true))
	{
		ir	= GetPreviousCp(&cpPrevious);
		if (PCTEXT_GETVALIDCP(ir) && PLib::Unicode::IsCR(cpPrevious, true))	return false;
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCRegExText::ParseBackRef
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::ParseBackRef()
{
	SMATCHINGSTATE*	pMState;
	CNSTATE*		pNState;
	UCPSTRING*		pName;

	InitReferences();
	for (ciHistory.RBegin(); !ciHistory.REnd(); ciHistory.RNext())
	{
		if (!ciHistory.RGetCurrent(&pMState))	continue;
		pNState	= pMState->pciNState;
		if (pNState == NULL)	continue;
		switch (pNState->GetType())
		{
		case PREGEX_NSTATE_TYPE_EX_CAP_BEGIN:
			AppendReferenceBegin(pNState->GetOptionalIndex(), pMState->itrText);
			break;

		case PREGEX_NSTATE_TYPE_EX_CAP_END:
			AppendReferenceEnd(pNState->GetOptionalIndex(), pMState->itrText);
			break;

		case PREGEX_NSTATE_TYPE_EX_CAP_NAMED_BEGIN:
			pName	= pNState->GetOptionalName();
			if (pName == NULL)
			{
				THROWPE_LOGIC_ERROR("PCRegEx::Match (2) : Invalid name.");
			}
			AppendNamedReferenceBegin(pName, pMState->itrText);
			break;

		case PREGEX_NSTATE_TYPE_EX_CAP_NAMED_END:
			pName	= pNState->GetOptionalName();
			if (pName == NULL)
			{
				THROWPE_LOGIC_ERROR("PCRegEx::Match (2) : Invalid name.");
			}
			AppendNamedReferenceEnd(pName, pMState->itrText);
			break;

		default:
			break;
		}
	}
	return true;
}

//----------------------------------------------------------------------
//	PCRegEx::GetCurrentBackRef
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetCurrentBackRef(ITR_UCPSTRING&	itrBegin,
										  ITR_UCPSTRING&	itrEnd,
										  T_INDEX			iRef)
{
	SMATCHINGSTATE*	pMatch;
	CNSTATE*		pNState;

	//	ciHistory には、マッチしたときの状態遷移が逆順に格納されている。

	for (ciHistory.Begin(); !ciHistory.End(); ciHistory.Next())
	{
		if (!ciHistory.GetCurrent(&pMatch))	continue;
		pNState	= pMatch->pciNState;
		if (pNState == NULL)	continue;
		if (pNState->GetType() != PREGEX_NSTATE_TYPE_EX_CAP_END)	continue;
		if (pNState->GetOptionalIndex() != iRef)	continue;

		itrEnd	= pMatch->itrText;
		for ( ; !ciHistory.End(); ciHistory.Next())
		{
			if (!ciHistory.GetCurrent(&pMatch))	continue;
			pNState	= pMatch->pciNState;
			if (pNState == NULL)	continue;
			if (pNState->GetType() != PREGEX_NSTATE_TYPE_EX_CAP_BEGIN)	continue;
			if (pNState->GetOptionalIndex() != iRef)	continue;
			itrBegin	= pMatch->itrText;
			return true;
		}
		return false;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCRegEx::GetCurrentNamedBackRef
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetCurrentNamedBackRef(ITR_UCPSTRING&	itrBegin,
											   ITR_UCPSTRING&	itrEnd,
											   UCPSTRING*		pName)
{
	SMATCHINGSTATE*	pMatch;
	CNSTATE*		pNState;

	//	ciHistory には、マッチしたときの状態遷移が逆順に格納されている。

	for (ciHistory.Begin(); !ciHistory.End(); ciHistory.Next())
	{
		if (!ciHistory.GetCurrent(&pMatch))	continue;
		pNState	= pMatch->pciNState;
		if (pNState == NULL)	continue;
		if (pNState->GetType() != PREGEX_NSTATE_TYPE_EX_CAP_NAMED_END)	continue;
		if (pNState->GetOptionalName() != pName)	continue;

		itrEnd	= pMatch->itrText;
		for ( ; !ciHistory.End(); ciHistory.Next())
		{
			if (!ciHistory.GetCurrent(&pMatch))	continue;
			pNState	= pMatch->pciNState;
			if (pNState == NULL)	continue;
			if (pNState->GetType() != PREGEX_NSTATE_TYPE_EX_CAP_NAMED_BEGIN)	continue;
			if (pNState->GetOptionalName() != pName)	continue;
			itrBegin	= pMatch->itrText;
			return true;
		}
		return false;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCRegExText::SetupReferences
//	指定された個数まで SSReference 構造体を作成・登録する。
//----------------------------------------------------------------------
void CLASS_PREGEX_TEXT::SetupReferences(size_t i)
{
	SReference*	pRef;

	while (ciRefArray.size() < i)
	{
		pRef	= ciIPRef.Allocate();
		pRef->itrBegin	= ciCpString.end();
		pRef->itrEnd	= ciCpString.end();
		ciRefArray.push_back(pRef);
	}
	return;
}

//----------------------------------------------------------------------
//	PCRegExText::AppendReferenceBegin
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::AppendReferenceBegin(T_PREGEX_INDEX i, ITR_UCPSTRING& itrBegin)
{
	SReference*	pRef;

	SetupReferences((size_t)(i + 1));
	try
	{
		pRef	= ciRefArray.at(i);
	}
	catch (std::out_of_range&)
	{
		THROWPE_RUNTIME_ERROR("PCRegExText::AppendReferenceBegin");
	}

	pRef->itrBegin	= itrBegin;
	return true;
}

//----------------------------------------------------------------------
//	PCRegExText::AppendReferenceEnd
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::AppendReferenceEnd(T_PREGEX_INDEX i, ITR_UCPSTRING& itrEnd)
{
	SReference*	pRef;

	SetupReferences((size_t)(i + 1));
	try
	{
		pRef	= ciRefArray.at(i);
	}
	catch (std::out_of_range&)
	{
		THROWPE_RUNTIME_ERROR("PCRegExText::AppendReferenceEnd");
	}

	pRef->itrEnd	= itrEnd;
	return true;
}

//----------------------------------------------------------------------
//	PCRegExText::GetNamedReference	(1)	参照を表す構造体を取得する。
//----------------------------------------------------------------------
PCRegExText::SNamedReference* CLASS_PREGEX_TEXT::GetNamedReference(UCPSTRING* pName)
{
	ITR_NAMEDREFLIST	itr;
	DWORD				dwFlags;
	T_PCSTR_U			pszLocale;

	GetCompareStringOptions(&dwFlags, &pszLocale);

	//	同じ名前を持つ参照が登録されている場合は、そのポインタを返す。
	for (itr = ciNamedRefList.begin(); itr != ciNamedRefList.end(); ++itr)
	{
		if (PLib::Unicode::CompareStringUCD(&((*itr)->ucsName), pName, dwFlags, pszLocale) == CSTR_EQUAL)
		{
			return *itr;
		}
	}

	//	見つからない場合は NULL を返す。
	return NULL;
}

//----------------------------------------------------------------------
//	PCRegExText::CreateNamedReference	未登録の場合は作成する。
//----------------------------------------------------------------------
PCRegExText::SNamedReference* CLASS_PREGEX_TEXT::CreateNamedReference(UCPSTRING* pName)
{
	SNamedReference*	pSRef;

	pSRef	= GetNamedReference(pName);
	if (pSRef != NULL)	return pSRef;

	//	また登録されていない場合は、参照を作成し、名前を設定する。

	pSRef	= ciIPNamedRef.Allocate();
	pSRef->ucsName.assign(pName->c_str(), pName->size());
	ciNamedRefList.push_back(pSRef);
	return pSRef;
}

//----------------------------------------------------------------------
//	PCRegExText::AppendNamedReferenceBegin
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::AppendNamedReferenceBegin(UCPSTRING* pName, ITR_UCPSTRING& itrBegin)
{
	SNamedReference*	pSRef;

	pSRef	= CreateNamedReference(pName);
	pSRef->itrBegin	= itrBegin;
	return true;
}

//----------------------------------------------------------------------
//	PCRegExText::AppendNamedReferenceEnd
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::AppendNamedReferenceEnd(UCPSTRING* pName, ITR_UCPSTRING& itrEnd)
{
	SNamedReference*	pSRef;

	pSRef	= CreateNamedReference(pName);
	pSRef->itrEnd	= itrEnd;
	return true;
}

//----------------------------------------------------------------------
//	PCRegExText::GetNamedReference	(2)	反復子を取得する。
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetNamedReference(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd, UCPSTRING* pName)
{
	SNamedReference*	pSRef;

	pSRef	= GetNamedReference(pName);
	if (pSRef != NULL)
	{
		itrBegin	= pSRef->itrBegin;
		itrEnd		= pSRef->itrEnd;
		return true;
	}
	return false;
}
//----------------------------------------------------------------------
//	PCRegExText::GetNamedReference	(3)	コードポイント列を取得する
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetNamedReference(UCPSTRING* puisBuffer, UCPSTRING* pszName)
{
	ITR_UCPSTRING	itrBegin;
	ITR_UCPSTRING	itrEnd;

	if (GetNamedReference(itrBegin, itrEnd, pszName))
	{
		GetSubString(puisBuffer, itrBegin, itrEnd);
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCRegExText::GetNamedReference	(4)
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetNamedReference(T_STRING_U* pstrBuffer, UCPSTRING* pszName)
{
	ITR_UCPSTRING	itrBegin;
	ITR_UCPSTRING	itrEnd;

	if (GetNamedReference(itrBegin, itrEnd, pszName))
	{
		GetSubString(pstrBuffer, itrBegin, itrEnd);
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCRegExText::GetReference	(1)
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetReference(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd, T_PREGEX_INDEX i)
{
	SReference*	pRef;

	try
	{
		pRef	= ciRefArray.at((SIZE_REFARRAY)i);
	}
	catch (std::out_of_range&)
	{
		return false;
	}
	if (pRef == NULL)	return false;

	itrBegin	= pRef->itrBegin;
	itrEnd		= pRef->itrEnd;
	return true;
}

//----------------------------------------------------------------------
//	PCRegExText::GetReference	(2-1)
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetReference(UCPSTRING* puisBuffer, T_PREGEX_INDEX i)
{
	ITR_UCPSTRING	itrBegin, itrEnd;

	if (puisBuffer == NULL)	return false;
	if (GetReference(itrBegin, itrEnd, i))
	{
		for ( ; itrBegin != itrEnd && itrBegin != ciCpString.end(); ++itrBegin)
		{
			puisBuffer->append(1, *itrBegin);
		}
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCRegExText::GetReference	(2-2)
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetReference(T_STRING_U* pstrBuffer, T_PREGEX_INDEX i)
{
	ITR_UCPSTRING	itrBegin, itrEnd;
	T_CHAR_U	WCBuf[3];

	if (pstrBuffer == NULL)	return false;
	if (GetReference(itrBegin, itrEnd, i))
	{
		for ( ; itrBegin != itrEnd && itrBegin != ciCpString.end(); ++itrBegin)
		{
			if (PLib::Unicode::ConvertFromCodepoint(WCBuf, *itrBegin))
			{
				pstrBuffer->append(WCBuf);
			}
		}
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCRegExText::GetPreMatch	(1)
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetPreMatch(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd)
{
	SReference*	pRef;

	if (ciRefArray.size() < 1)	return false;
	pRef	= ciRefArray.at(0);
	if (pRef == NULL)	return false;

	itrBegin	= ciCpString.begin();
	itrEnd		= pRef->itrBegin;
	return true;
}

//----------------------------------------------------------------------
//	PCRegExText::GetPreMatch	(2-1)
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetPreMatch(UCPSTRING* puisBuffer)
{
	ITR_UCPSTRING	itrBegin, itrEnd;

	if (puisBuffer == NULL)	return false;
	if (GetPreMatch(itrBegin, itrEnd))
	{
		for ( ; itrBegin != itrEnd && itrBegin != ciCpString.end(); ++itrBegin)
		{
			puisBuffer->append(1, *itrBegin);
		}
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCRegExText::GetPreMatch	(2-1)
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetPreMatch(T_STRING_U* pstrBuffer)
{
	ITR_UCPSTRING	itrBegin, itrEnd;
	T_CHAR_U	WCBuf[3];

	if (pstrBuffer == NULL)	return false;
	if (GetPreMatch(itrBegin, itrEnd))
	{
		for ( ; itrBegin != itrEnd && itrBegin != ciCpString.end(); ++itrBegin)
		{
			if (PLib::Unicode::ConvertFromCodepoint(WCBuf, *itrBegin))
			{
				pstrBuffer->append(WCBuf);
			}
		}
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCRegExText::GetPostMatch	(1)
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetPostMatch(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd)
{
	SReference*	pRef;

	if (ciRefArray.size() < 1)	return false;
	pRef	= ciRefArray.at(0);
	if (pRef == NULL)	return false;

	itrBegin	= pRef->itrEnd;
	itrEnd		= ciCpString.end();
	return true;
}

//----------------------------------------------------------------------
//	PCRegExText::GetPostMatch	(2-1)
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetPostMatch(UCPSTRING* puisBuffer)
{
	ITR_UCPSTRING	itrBegin, itrEnd;

	if (puisBuffer == NULL)	return false;
	if (GetPostMatch(itrBegin, itrEnd))
	{
		for ( ; itrBegin != itrEnd && itrBegin != ciCpString.end(); ++itrBegin)
		{
			puisBuffer->append(1, *itrBegin);
		}
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCRegExText::GetPostMatch	(2-2)
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetPostMatch(T_STRING_U* pstrBuffer)
{
	ITR_UCPSTRING	itrBegin, itrEnd;
	T_CHAR_U	WCBuf[3];

	if (pstrBuffer == NULL)	return false;
	if (GetPostMatch(itrBegin, itrEnd))
	{
		for ( ; itrBegin != itrEnd && itrBegin != ciCpString.end(); ++itrBegin)
		{
			if (PLib::Unicode::ConvertFromCodepoint(WCBuf, *itrBegin))
			{
				pstrBuffer->append(WCBuf);
			}
		}
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCRegExText::GetLastParenMatch	(1)
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetLastParenMatch(ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd)
{
	SReference*		pRef;
	SIZE_REFARRAY	i;

	if ((i = ciRefArray.size()) < 1)	return false;

	pRef	= ciRefArray.at(i - 1);
	if (pRef == NULL)	return false;

	itrBegin	= pRef->itrBegin;
	itrEnd		= pRef->itrEnd;
	return true;
}

//----------------------------------------------------------------------
//	PCRegExText::GetLastParenMatch	(2-1)
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetLastParenMatch(UCPSTRING* puisBuffer)
{
	ITR_UCPSTRING	itrBegin, itrEnd;

	if (puisBuffer == NULL)	return false;
	if (GetLastParenMatch(itrBegin, itrEnd))
	{
		for ( ; itrBegin != itrEnd && itrBegin != ciCpString.end(); ++itrBegin)
		{
			puisBuffer->append(1, *itrBegin);
		}
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCRegExText::GetLastParenMatch	(2-2)
//----------------------------------------------------------------------
bool CLASS_PREGEX_TEXT::GetLastParenMatch(T_STRING_U* pstrBuffer)
{
	ITR_UCPSTRING	itrBegin, itrEnd;
	T_CHAR_U	WCBuf[3];

	if (pstrBuffer == NULL)	return false;
	if (GetLastParenMatch(itrBegin, itrEnd))
	{
		for ( ; itrBegin != itrEnd && itrBegin != ciCpString.end(); ++itrBegin)
		{
			if (PLib::Unicode::ConvertFromCodepoint(WCBuf, *itrBegin))
			{
				pstrBuffer->append(WCBuf);
			}
		}
		return true;
	}
	return false;
}

#ifdef	PDEBUG
//----------------------------------------------------------------------
//	PCRegExText::Debug
//----------------------------------------------------------------------
void CLASS_PREGEX_TEXT::Debug(T_STRING_U* pstrDebug)
{
	SIZE_REFARRAY		i;
	ITR_NAMEDREFLIST	itrn;

	T_PCSTR_U	pLF		= TQU("\r\n");
	T_PCSTR_U	pColon	= TQU("\t: ");
	T_PCSTR_U	pfmt	= TQU("%d\t: ");

	if (ciRefArray.empty())
	{
		pstrDebug->append(TQU("No numbered reference."));
	}
	else
	{
		for (i = 0; i < ciRefArray.size(); ++i)
		{
			NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt, (int)i);
			GetReference(pstrDebug, i);
			pstrDebug->append(pLF);
		}
	}
	pstrDebug->append(pLF);

	if (ciNamedRefList.empty())
	{
		pstrDebug->append(TQU("No named reference."));
	}
	else
	{
		for (itrn = ciNamedRefList.begin(); itrn != ciNamedRefList.end(); ++itrn)
		{
			PLib::Unicode::ConvertFromCodepoint(pstrDebug, &((*itrn)->ucsName));
			pstrDebug->append(pColon);
			GetNamedReference(pstrDebug, &((*itrn)->ucsName));
			pstrDebug->append(pLF);
		}
	}
	pstrDebug->append(pLF);
}

//----------------------------------------------------------------------
//	PCRegExText::DebugHistory
//----------------------------------------------------------------------
void CLASS_PREGEX_TEXT::DebugHistory(T_STRING_U* pstrDebug)
{
	ciHistory.Debug(pstrDebug, this);
}
#endif


//======================================================================
//	class PCRegExReplacement
//
//	置換文字列を作成・適用するためのクラス。
//======================================================================
//----------------------------------------------------------------------
//	PCRegExReplacement	コンストラクタ
//----------------------------------------------------------------------
CLASS_PREGEX_REPLACEMENT::PCRegExReplacement()
:	PBCRegExText(),
	pComponent(NULL)
{
	SetDecodeControlFunction(PLib::RegEx::DecodeEscapedControl);
	SetDecodeFlags(PREGEX_REPLACEMENT_DECODE);
	SetCompareStringOptions(&ciOptions);
	ciIPComponent.Init();
}

//----------------------------------------------------------------------
//	PCRegExReplacement	デストラクタ
//----------------------------------------------------------------------
CLASS_PREGEX_REPLACEMENT::~PCRegExReplacement()
{
	Clear();
}

//----------------------------------------------------------------------
//	PCRegExReplacement::Clear
//----------------------------------------------------------------------
void CLASS_PREGEX_REPLACEMENT::Clear()
{
	CBTEXT::Clear();

	ciIPComponent.Clear();
	ciComponentList.clear();
	pComponent	= NULL;
}

//----------------------------------------------------------------------
//	PCRegExReplacement::Init
//----------------------------------------------------------------------
bool CLASS_PREGEX_REPLACEMENT::Init()
{
	if (!CBTEXT::Init())	return false;
	ciIPComponent.Init();
	ciComponentList.clear();
	pComponent	= NULL;
	return true;
}

//----------------------------------------------------------------------
//	PCRegExReplacement::AppendComponent
//----------------------------------------------------------------------
CLASS_PREGEX_REPLACEMENT::SComponent* CLASS_PREGEX_REPLACEMENT::CreateComponent(int iType)
{
	SComponent*	pCompo;

	pCompo	= ciIPComponent.Allocate();
	ciComponentList.push_back(pCompo);
	pCompo->iType	= iType;
	return pCompo;
}

//----------------------------------------------------------------------
//	PCRegExReplacement::AppendStringComponent
//----------------------------------------------------------------------
void CLASS_PREGEX_REPLACEMENT::AppendStringComponent(const T_UCP* pStr, size_t zStr)
{
	if (pComponent == NULL || pComponent->iType != PREGEX_PEPLACEMENT_COMPONENT_STRING)
	{
		pComponent	= CreateComponent(PREGEX_PEPLACEMENT_COMPONENT_STRING);
	}

	if (pStr != NULL && zStr > 0)
	{
		pComponent->ucsBuf.append(pStr, zStr);
	}
	return;
}

//----------------------------------------------------------------------
//	PCRegExReplacement::AppendBackRefComponent
//----------------------------------------------------------------------
void CLASS_PREGEX_REPLACEMENT::AppendBackRefComponent(T_PREGEX_INDEX iRef)
{
	SComponent*	pNew;

	pNew		= CreateComponent(PREGEX_PEPLACEMENT_COMPONENT_BACKREF);
	pNew->iRef	= iRef;
	pComponent	= NULL;	//	処理中の Component はなしとする。
	return;
}

//----------------------------------------------------------------------
//	PCRegExReplacement::AppendNamedBackRefComponent
//----------------------------------------------------------------------
void CLASS_PREGEX_REPLACEMENT::AppendNamedBackRefComponent(UCPSTRING* pName)
{
	SComponent*	pNew;

	if (pName == NULL)	return ;
	pNew		= CreateComponent(PREGEX_PEPLACEMENT_COMPONENT_BACKREF_BYNAME);
	pNew->ucsBuf.assign(pName->c_str(), pName->size());
	pComponent	= NULL;	//	処理中の Component はなしとする。
	return;
}

//----------------------------------------------------------------------
//	PCRegExReplacement::SetReplacement	(1)
//----------------------------------------------------------------------
bool CLASS_PREGEX_REPLACEMENT::SetReplacement(T_PCSTR_U	pReplacementB,
											  T_PCSTR_U	pReplacementE,
											  DWORD		dwCSFlags,
											  T_PCSTR_U	pszLocale)
{
	ITR_UCPSTRING	itr, itrT1, itrT2;
	UCPSTRING		ucsBuffer;
	int				iToken;
	T_UCP			cp;
	int				it1, it2;
	bool			bNormalize;
	T_UCP			cpDollar	= (T_UCP)TQU('$');
	T_UCP			cpEscape	= (T_UCP)TQU('\\');

	//	各コードページに Token ID をセットしておく。
	if (!SetText(pReplacementB, pReplacementE))	return false;

	if (dwCSFlags == 0)		dwCSFlags	= ciOptions.GetCompareStringUCDFlags();
	if (pszLocale == NULL)	pszLocale	= ciOptions.GetLocaleString();
	if (IS_CSFLAG_NORM_IGNOREWIDTH_SET(dwCSFlags)		||
		IS_CSFLAG_NORM_IGNORENONSPACE_SET(dwCSFlags)	||
		COMPARESTRINGUCD_IS_NORMALIZE(dwCSFlags))
	{
		bNormalize	= true;
	}
	ucsBuffer.clear();

	Begin();
	while (!End())
	{
		iToken	= GetCurrentToken();
		//--------------------------------------------------
		//	エスケープシーケンスの場合
		//--------------------------------------------------
		if (iToken == PREGEX_TOKEN_ESCAPE)
		{
			if (!PCTEXT_GETVALIDCP(GetCurrentCp(&cp)))	break;
			Next();
			if (End())
			{
				ucsBuffer.append(1, cp);
				break;
			}
			if (PCTEXT_GETVALIDCP(GetCurrentCp(&cp)))
			{
				ucsBuffer.append(1, cp);
			}
			Next();
			continue;
		}
		//--------------------------------------------------
		//	$ の場合
		//--------------------------------------------------
		if (iToken == PREGEX_TOKEN_DOLLAR)
		{
			Next();
			PushNewIterator();
			iToken	= GetCurrentToken();
			if (iToken == PREGEX_TOKEN_END)	goto REGARD_AS_NORMALSTRING;

			//----------------------------------------
			//	整数値が続いている場合は参照として登録する。
			//----------------------------------------
			if (PCTextUR_GetInt(&it1, this, dwCSFlags, pszLocale))
			{
				//	未処理の文字列があれば登録する。
				if (!ucsBuffer.empty())
				{
					AppendStringComponent(ucsBuffer.c_str(), ucsBuffer.size());
					ucsBuffer.clear();
				}
				AppendBackRefComponent((T_PREGEX_INDEX)it1);
				Next();
				PopAndUpdateIterator();
				continue;
			}

			//----------------------------------------
			//	${ の場合は
			//----------------------------------------
			if (iToken == PREGEX_TOKEN_LBRACE)
			{
				Next();
				if (!GetCurrentPos(itrT1))	THROWPE_LOGIC_ERROR("");
				if (GetCurrentToken() == PREGEX_TOKEN_RBRACE || !MoveTo(PREGEX_TOKEN_RBRACE))
					goto REGARD_AS_NORMALSTRING;

				//	未処理の文字列があれば登録する。
				if (!ucsBuffer.empty())
				{
					AppendStringComponent(ucsBuffer.c_str(), ucsBuffer.size());
					ucsBuffer.clear();
				}
				if (!GetCurrentPos(itrT2))	THROWPE_LOGIC_ERROR("");

				//	{} 内の文字がすべて 10 進数を表す文字であるか調べる。
				for (itr = itrT1, it1 = 0; itr != itrT2; ++itr)
				{
					if (!PLib::Unicode::IsDigit(&it2, *itr, bNormalize))	break;
					it1	= 10 * it1 + it2;
				}

				//	{} 内の文字がすべて 10 進数の場合は整数値として扱う。
				if (itr == itrT2)
				{
					AppendBackRefComponent((T_PREGEX_INDEX)it1);
					PopAndUpdateIterator();
				}
				//	そうでない場合は文字列として扱う。
				else
				{
					if (!GetSubString(&ucsBuffer, itrT1, itrT2))
						THROWPE_LOGIC_ERROR("PCRegExReplacement::Set (1) : Failed to get substring.");
					AppendNamedBackRefComponent(&ucsBuffer);
					ucsBuffer.clear();
					PopAndUpdateIterator();
				}
				Next();
				continue;
			}

			//----------------------------------------
			//	$&、$`、$' 、$+ の場合は
			//----------------------------------------
			if (iToken == PREGEX_TOKEN_AMPERSAND	||
				iToken == PREGEX_TOKEN_GRAVE		||
				iToken == PREGEX_TOKEN_APOSTROPHE	||
				iToken == PREGEX_TOKEN_PLUS			||
				iToken == PREGEX_TOKEN_UNDERSCORE)
			{
				//	未処理の文字列があれば登録する。
				if (!ucsBuffer.empty())
				{
					AppendStringComponent(ucsBuffer.c_str(), ucsBuffer.size());
					ucsBuffer.clear();
				}

				switch (iToken)
				{
				case PREGEX_TOKEN_AMPERSAND:
					AppendBackRefComponent((T_PREGEX_INDEX)0);
					break;

				case PREGEX_TOKEN_GRAVE:
					CreateComponent(PREGEX_PEPLACEMENT_COMPONENT_PREMATCH);
					break;

				case PREGEX_TOKEN_APOSTROPHE:
					CreateComponent(PREGEX_PEPLACEMENT_COMPONENT_POSTMATCH);
					break;

				case PREGEX_TOKEN_PLUS:
					CreateComponent(PREGEX_PEPLACEMENT_COMPONENT_LAST_PAREN_MATCH);
					break;

				case PREGEX_TOKEN_UNDERSCORE:
					CreateComponent(PREGEX_PEPLACEMENT_COMPONENT_ENTIRE_INPUT);
					break;

				default:
					break;
				}
				pComponent	= NULL;	//	処理中の Component はなしとする。
				Next();
				continue;
			}

			//----------------------------------------
			//	以上に当てはまらなかった場合は、$ を通常の文字として追加し、
			//	次の文字から処理を再開する。
			//----------------------------------------
REGARD_AS_NORMALSTRING:
			PopIterator();
			ucsBuffer.append(1, cpDollar);
			continue;
		}
		//--------------------------------------------------
		//	それ以外は通常の文字として扱う。
		//--------------------------------------------------
		if (PCTEXT_GETVALIDCP(GetCurrentCp(&cp)))
		{
			ucsBuffer.append(1, cp);
		}
		Next();
	}

	if (!ucsBuffer.empty())
	{
		AppendStringComponent(ucsBuffer.c_str(), ucsBuffer.size());
	}
	return true;
}

//----------------------------------------------------------------------
//	PCRegExReplacement::SetReplacement	(2)
//----------------------------------------------------------------------
bool CLASS_PREGEX_REPLACEMENT::SetReplacement(T_PCSTR_U	pReplacement,
											  size_t	zReplacement,
											  DWORD		dwCSFlags,
											  T_PCSTR_U	pszLocale)
{
	return SetReplacement(pReplacement, pReplacement + zReplacement);
}

//----------------------------------------------------------------------
//	PCRegExReplacement::Set	(3)
//----------------------------------------------------------------------
bool CLASS_PREGEX_REPLACEMENT::SetReplacement(T_PCSTR_U	pszReplacement,
											  DWORD		dwCSFlags,
											  T_PCSTR_U	pszLocale)
{
	T_PCSTR_U	pe;

	if (pszReplacement == NULL)	return false;
	pe	= pszReplacement;
	while (*pe != NULL)	++pe;
	return SetReplacement(pszReplacement, pe);
}

//----------------------------------------------------------------------
//	PCRegExReplacement::Compare
//----------------------------------------------------------------------
int CLASS_PREGEX_REPLACEMENT::Compare(PCRegExReplacement* pOther, DWORD dwFlags, T_PCSTR_U pszLocale)
{
	ITR_COMPONENTSLIST	itr1, itr2;
	int	ic;

	if (pOther == NULL)	THROWPE_LOGIC_ERROR("PCRegExReplacement::Compare");
	for (itr1 = ciComponentList.begin(), itr2 = pOther->ciComponentList.begin();
		itr1 != ciComponentList.end(),itr2 != pOther->ciComponentList.end();
		++itr1, ++itr2)
	{
		ic	= (*itr1)->Compare(*itr2, dwFlags, pszLocale);
		if (ic != 0)	return ic;
	}
	if (itr1 != ciComponentList.end())			return 1;
	if (itr2 != pOther->ciComponentList.end())	return -1;
	return 0;
}

//----------------------------------------------------------------------
//	PCRegExReplacement::Format
//----------------------------------------------------------------------
bool CLASS_PREGEX_REPLACEMENT::Format(T_STRING_U* pstrOutput, CTEXT* pciText)
{
	ITR_COMPONENTSLIST	itr;
	UCPSTRING			uisOutput;

	for (itr = ciComponentList.begin(); itr != ciComponentList.end(); ++itr)
	{
		switch ((*itr)->iType)
		{
		case PREGEX_PEPLACEMENT_COMPONENT_STRING:
			uisOutput.append((*itr)->ucsBuf);
			break;

		case PREGEX_PEPLACEMENT_COMPONENT_BACKREF:
			if (pciText != NULL)
			{
				pciText->GetReference(&uisOutput, (*itr)->iRef);
			}
			break;

		case PREGEX_PEPLACEMENT_COMPONENT_BACKREF_BYNAME:
			if (pciText != NULL)
			{
				pciText->GetNamedReference(&uisOutput, &((*itr)->ucsBuf));
			}
			break;

		case PREGEX_PEPLACEMENT_COMPONENT_MATCH:
			if (pciText != NULL)
			{
				pciText->GetReference(&uisOutput, 0);
			}
			break;

		case PREGEX_PEPLACEMENT_COMPONENT_PREMATCH:
			if (pciText != NULL)
			{
				pciText->GetPreMatch(&uisOutput);
			}
			break;

		case PREGEX_PEPLACEMENT_COMPONENT_POSTMATCH:
			if (pciText != NULL)
			{
				pciText->GetPostMatch(&uisOutput);
			}
			break;

		case PREGEX_PEPLACEMENT_COMPONENT_LAST_PAREN_MATCH:
			if (pciText != NULL)
			{
				pciText->GetLastParenMatch(&uisOutput);
			}
			break;

		case PREGEX_PEPLACEMENT_COMPONENT_ENTIRE_INPUT:
			if (pciText != NULL)
			{
				pciText->GetSourceText(&uisOutput);
			}
			break;

		default:
			break;
		}
	}

	return PLib::Unicode::ConvertFromCodepoint(pstrOutput, &uisOutput);
}

#ifdef	PDEBUG
//----------------------------------------------------------------------
//	PCRegExReplacement::Debug
//----------------------------------------------------------------------
void CLASS_PREGEX_REPLACEMENT::Debug(T_STRING_U* pstrDebug)
{
	ITR_COMPONENTSLIST	itr;
	T_STRING_U	strBuf;
	T_PCSTR_U	pLF		= TQU("\r\n");
	T_PCSTR_U	pfmt	= TQU("%d\r\n");

	for (itr = ciComponentList.begin(); itr != ciComponentList.end(); ++itr)
	{
		switch ((*itr)->iType)
		{
		case PREGEX_PEPLACEMENT_COMPONENT_STRING:
			PLib::Unicode::ConvertFromCodepoint(pstrDebug, &((*itr)->ucsBuf));
			pstrDebug->append(pLF);
			break;

		case PREGEX_PEPLACEMENT_COMPONENT_BACKREF:
			pstrDebug->append(TQU("BackRef\t: "));
			NS_PLIB::AppendNumToString<T_CHAR_U, int>(pstrDebug, pfmt, (*itr)->iRef);
			break;

		case PREGEX_PEPLACEMENT_COMPONENT_BACKREF_BYNAME:
			pstrDebug->append(TQU("BackRef\t: "));
			PLib::Unicode::ConvertFromCodepoint(pstrDebug, &((*itr)->ucsBuf));
			pstrDebug->append(pLF);
			break;

		case PREGEX_PEPLACEMENT_COMPONENT_PREMATCH:
			pstrDebug->append(TQU("PreMatch\r\n"));
			break;

		case PREGEX_PEPLACEMENT_COMPONENT_POSTMATCH:
			pstrDebug->append(TQU("PostMatch\r\n"));
			break;

		case PREGEX_PEPLACEMENT_COMPONENT_LAST_PAREN_MATCH:
			pstrDebug->append(TQU("LastMatch\r\n"));
			break;

		case PREGEX_PEPLACEMENT_COMPONENT_ENTIRE_INPUT:
			pstrDebug->append(TQU("EntireInput\r\n"));
			break;

		default:
			break;
		}
	}
}
#endif

NS_PLIB_END
