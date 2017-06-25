//	XLCTextEx_1.0x	:	PLibTextEx

//	PGClassesText.cpp
//
#include "stdafx.h"

NS_PLIB_BEGIN

//======================================================================
//	class PCTextUR
//======================================================================
//----------------------------------------------------------------------
//	PCTextUR	コンストラクタ
//----------------------------------------------------------------------
CLASS_PCTEXTUR::PCTextUR()
:	pTextB(NULL),
	pTextE(NULL),
	zText(0),
	iDecodeFlags(PCTEXT_FLAG_DECODE_ALL),
	pciCSOptions(NULL),
	dwCSFlagsDefault(0),
	pszLocaleDefault(NULL),
	pfDecodeEscCntrl(NULL)
{
	pitrCurrentPos	= ciIteratorStack.pIterator();
	*pitrCurrentPos	= ciCpString.end();
}

//----------------------------------------------------------------------
//	PCTextUR	デストラクタ
//----------------------------------------------------------------------
CLASS_PCTEXTUR::~PCTextUR()
{
	Clear();
}

//----------------------------------------------------------------------
//	PCTextUR::Clear
//	保持していたデータは消去されるので、本当に必要なときだけ使用すること。
//----------------------------------------------------------------------
void CLASS_PCTEXTUR::Clear()
{
	ciCpString.clear();
	ciIteratorStack.Init();
	pitrCurrentPos	= ciIteratorStack.pIterator();
	*pitrCurrentPos	= ciCpString.end();

	pTextB		= NULL;
	pTextE		= NULL;
	zText		= 0;
}

//----------------------------------------------------------------------
//	PCTextUR::Init
//	文字列を先頭から処理するための準備をする。
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::Init()
{
	if (ciCpString.empty())
	{
		Clear();
		return false;
	}
	ciIteratorStack.Init();
	pitrCurrentPos	= ciIteratorStack.pIterator();
	Begin();
	return true;
}

//----------------------------------------------------------------------
//	PCTextUR::GetCompareStringOptions
//----------------------------------------------------------------------
void CLASS_PCTEXTUR::GetCompareStringOptions(DWORD* pdwFlags, T_PCSTR_U* ppszLocale)
{
	if (pciCSOptions != NULL)
	{
		*pdwFlags	= pciCSOptions->GetCompareStringUCDFlags();
		*ppszLocale	= pciCSOptions->GetLocaleString();
	}
	else
	{
		*pdwFlags	= dwCSFlagsDefault;
		*ppszLocale	= pszLocaleDefault;
	}
}

//----------------------------------------------------------------------
//	PCTextUR::SetText	(1)
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::SetText(T_PCSTR pSrcB, T_PCSTR pSrcE)
{
	if (pSrcB == NULL || pSrcB > pSrcE)	return false;
	Init();

	pTextB	= pSrcB;
	pTextE	= pSrcE;
	zText	= (size_t)(pTextE - pTextB);
	ConvertToCpList();
	return true;
}

//----------------------------------------------------------------------
//	PCTextUR::SetText	(2)
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::SetText(T_PCSTR pSrc, size_t zSrc)
{
	if (pSrc == NULL)	return false;
	Init();

	pTextB	= pSrc;
	pTextE	= pSrc + zSrc;
	zText	= zSrc;
	ConvertToCpList();
	return true;
}

//----------------------------------------------------------------------
//	PCTextUR::SetText	(3)
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::SetText(T_PCSTR pszSrc)
{
	T_PCSTR	pe;

	if (pszSrc == NULL)	return false;
	pe	= pszSrc;
	while (*pe)	++pe;
	return SetText(pszSrc , pe);
}

//----------------------------------------------------------------------
//	PCTextUR::GetSourceText	(2)
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::GetSourceText(UCPSTRING* puisText)
{
	ITR_UCPSTRING	itr;

	if (puisText == NULL)	return false;
	for (itr = ciCpString.begin(); itr != ciCpString.end(); ++itr)
	{
		puisText->append(1, ItrToCp(itr));
	}
	return true;
}

//----------------------------------------------------------------------
//	PCTextUR::GetSourceText	(2)
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::GetSourceText(T_STRING* pstrText)
{
	ITR_UCPSTRING	itr;
	T_CHAR		Buf[3];

	if (pstrText == NULL)	return false;
	for (itr = ciCpString.begin(); itr != ciCpString.end(); ++itr)
	{
		if (!PLib::Unicode::ConvertFromCodepoint(Buf, *itr))
		{
			THROWPE_RUNTIME_ERROR("PCTextUR::GetSourceText");
		}
		pstrText->append(Buf);
	}
	return true;
}

//----------------------------------------------------------------------
//	補助関数	IsEscape
//----------------------------------------------------------------------
static bool IsEscape(T_UCP uiCp, DWORD dwFlags)
{
	if (uiCp == 0x005C)	return true;
	if (COMPARESTRING_IS_NORM_IGNORENONSPACE(dwFlags) || COMPARESTRING_IS_NORM_IGNOREWIDTH(dwFlags))
	{
		if ((uiCp == (T_UCP)0xFE68) || (uiCp == (T_UCP)0xFF3C))	return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCTextUR::GetDecodedCodepoint
//
//	複数の文字を組み合わせて扱う場合があるが、pCurrent は先頭の文字を指しているとして処理を行う。
//	*itrNext には、次に処理すべき文字（を表すコードグループの先頭）の位置が格納されている。
//
//	入力チェックは行わない。呼び出し側でチェックしておくこと。
//	エラーの場合は例外をスローする。呼び出し側で処理すること。
//----------------------------------------------------------------------
#define	GETDECODEDCODEPOINT_TRUE	1
#define	GETDECODEDCODEPOINT_FALSE	0
#define	GETDECODEDCP_UNICODEMODE	-1

#define	IS_GETDECODEDCODEPOINT_TRUE(ir)		((ir) > 0)
#define	IS_GETDECODEDCODEPOINT_FALSE(ir)	((ir) == 0)
#define	IS_GETDECODEDCP_UNICODEMODE(ir)		((ir) < 0)

bool CLASS_PCTEXTUR::GetDecodedCodepoint(UCPSTRING*	puisBuf,
										 T_PCSTR*	ppCurrent,
										 int		iDecFlags,
										 DWORD		dwFlagsC,
										 bool		bNormalize,
										 T_PCSTR	pszLocale)
{
	const int	FOLLOW_MAX	= 2;	//	後で使用する可能性があるのは \ とその次の文字
	T_UCP		cpFollow[FOLLOW_MAX];
	T_PCSTR		pFollow[FOLLOW_MAX];
	T_PCSTR		pc, pt;
	T_UCP		cpTemp1 ,cpTemp2;

	//------------------------------------------------------------
	//	1 文字取り出す。
	//------------------------------------------------------------
	pFollow[0]	= *ppCurrent;
	if (PLib::Unicode::ConvertToCodepoint(&cpFollow[0], &pFollow[0], pTextE) < 1)	return false;

	//------------------------------------------------------------
	//	デコードが指定されていない場合、\ でない場合はそのまま格納すればよい。
	//------------------------------------------------------------
	if (iDecFlags == 0 || !IsEscape(cpFollow[0], dwFlagsC))
	{
		puisBuf->push_back(cpFollow[0]);
		*ppCurrent	= pFollow[0];
		return true;
	}

	//------------------------------------------------------------
	//	\ が最後の文字の場合はフラグによって処理が異なる。
	//------------------------------------------------------------
	if (pFollow[0] >= pTextE)
	{
		/*	2013/06/13 00:56	comment out
		if (PCTEXT_DECODE_ITSELF(iDecFlags))
		{
			cpFollow[1]	= 0;
			pFollow[1]	= pTextE;
			goto DECODE_ITSELF;
		}
		goto NO_DECODE;
		*/

		//	2013/06/13 00:56
		cpFollow[1]	= 0;
		pFollow[1]	= pTextE;
		goto DECODE_ITSELF;
	}

	//------------------------------------------------------------
	//	次の文字を取り出す。
	//	ConvertToCodepoint 関数内でエラーが発生した場合は、例外がスローされる。
	//------------------------------------------------------------
	pFollow[1]	= pFollow[0];
	PLib::Unicode::ConvertToCodepoint(&cpFollow[1], &pFollow[1], pTextE);
	pc	= pFollow[1];

	//------------------------------------------------------------
	//	\x の場合、16 進数としてでコードする（最大 4 文字まで）
	//------------------------------------------------------------
	if (PCTEXT_DECODE_HEX(iDecFlags) &&
		(PLib::Unicode::CompareCodepointUCD(cpFollow[1], TQU('x'), dwFlagsC, NULL) == CSTR_EQUAL))
	{
		if (!PLib::Unicode::StrToIntHex<UINT>(&cpTemp1, &pc, pTextE, 4, bNormalize))	goto DECODE_ITSELF;
		puisBuf->push_back(cpTemp1);
		*ppCurrent	= pc;
		return true;
	}
	//------------------------------------------------------------
	//	\u の場合、Unicode コードポイントとしてデコードする。
	//------------------------------------------------------------
	else if (PCTEXT_DECODE_UNICODE(iDecFlags) &&
		(PLib::Unicode::CompareCodepointUCD(cpFollow[1], TQU('u'), dwFlagsC, NULL) == CSTR_EQUAL))
	{
		//	\u の後に 16 進数が直接続いている場合
		if (PLib::Unicode::StrToIntHex<UINT>(&cpTemp1, &pc, pTextE, 6, bNormalize))
		{
			puisBuf->push_back(cpTemp1);
			*ppCurrent	= pc;
			return true;
		}

		//	\u のあとに {　がある場合。
		if (PLib::Unicode::CompareCodepointUCD(*pc, TQU('{'), dwFlagsC, NULL) != CSTR_EQUAL)	goto DECODE_ITSELF;
		++pc;
		while (true)
		{
			while (ISSPACE_U(*pc))	++pc;
			if (PLib::Unicode::StrToIntHex<UINT>(&cpTemp1, &pc, pTextE, 6, bNormalize))
			{
				puisBuf->push_back(cpTemp1);
				continue;
			}
			//----------------------------------------
			//	} で終了する。
			//----------------------------------------
			else if (PLib::Unicode::CompareCodepointUCD(*pc, TQU('}'), dwFlagsC, NULL) == CSTR_EQUAL)
			{
				++pc;
				*ppCurrent	= pc;
				return true;
			}
			//	16 進数でも閉じカッコでもない場合にここへ来る。
			goto DECODE_ITSELF;
		}
	}
	//------------------------------------------------------------
	//	\c の場合、コントロール文字としてデコードする。
	//------------------------------------------------------------
	else if (PCTEXT_DECODE_CTRLCHAR(iDecFlags) &&
		(PLib::Unicode::CompareCodepointUCD(cpFollow[1], TQU('c'), dwFlagsC, NULL) == CSTR_EQUAL))
	{
		if (!PLib::Unicode::ConvertToCodepoint(&cpTemp1, &pc, pTextE))	goto DECODE_ITSELF;
		if (!PLib::Unicode::DecodeControlChar(&cpTemp2, cpTemp1, dwFlagsC, NULL))	goto DECODE_ITSELF;
		puisBuf->push_back(cpTemp2);
		*ppCurrent	= pc;
		return true;
	}

	//------------------------------------------------------------
	//	エスケープシーケンスのデコードが指定されている場合、
	//------------------------------------------------------------
	if (PCTEXT_DECODE_ESCCTRL(iDecFlags) && pfDecodeEscCntrl != NULL)
	{
		if ((*pfDecodeEscCntrl)(&cpTemp1, cpFollow[1], dwFlagsC, NULL))
		{
			puisBuf->push_back(cpTemp1);
			*ppCurrent	= pFollow[1];
			return true;
		}
	}

	//------------------------------------------------------------
	//	8 進数デコードが指定されている場合
	//------------------------------------------------------------
	if (PCTEXT_DECODE_OCTAL(iDecFlags))
	{
		pt	= pFollow[0];
		if (PLib::Unicode::StrToIntOct<UINT>(&cpTemp1, &pt, pTextE, 2, 3, bNormalize))
		{
			puisBuf->push_back(cpTemp1);
			*ppCurrent	= pt;
			return true;
		}
	}

	//------------------------------------------------------------
	//	それ以外の場合
	//	PCTEXT_FLAG_DECODE_ITSELF が設定されている
	//		\ が最後の文字でない	次の文字を格納する。
	//		\ が最後の文字なら		なにもしない。
	//	PCTEXT_FLAG_DECODE_ITSELF が設定されていない
	//		\ が最後の文字でない	現在の文字と次の文字を格納する。
	//		\ が最後の文字なら		現在の文字を格納する。
	//------------------------------------------------------------
DECODE_ITSELF:
	/*	2013/06/13 00:46 comment out
	if (!PCTEXT_DECODE_ITSELF(iDecFlags))	goto NO_DECODE;

	puisBuf->clear();
	puisBuf->push_back(cpFollow[1]);
	*ppCurrent	= pFollow[1];
	return true;
	*/

	puisBuf->clear();
	if (!PCTEXT_DECODE_ITSELF(iDecFlags))
	{
		puisBuf->push_back(cpFollow[0]);
	}
	if (cpFollow[1] != 0)
	{
		puisBuf->push_back(cpFollow[1]);
	}
	*ppCurrent	= pFollow[1];
	return true;

	//------------------------------------------------------------
	//	以上に当てはまらない場合は何もせずに、最初に取得した文字を返す。
	//------------------------------------------------------------
	/*	2013/06/13	00:57	comment out
NO_DECODE:
	puisBuf->clear();
	puisBuf->push_back(cpFollow[0]);
	*ppCurrent	= pFollow[0];
	return true;
	*/
}


//----------------------------------------------------------------------
//	PCTextUR::ConvertToCpList
//	テキストを PCMulticodeChar のリストに変換する。
//----------------------------------------------------------------------
void CLASS_PCTEXTUR::ConvertToCpList()
{
	DWORD		dwFlags, dwFlagsC;
	LCID		dwLocale;
	bool		bNormalize;

	UCPSTRING	uisBuf;
	const UINT*	pcu;
	UINT		uic;
	T_PCSTR		pc;

	T_CHAR_U	SgBuf[3]	= { 0, 0, 0, };
	T_PCSTR_U	pSgBuf;

	//------------------------------------------------------------
	//	初期設定
	//------------------------------------------------------------
	if (pTextB == NULL || pTextB > pTextE)	return;

	ciCpString.clear();
	//ciIPMcChar.Init();

	//	CompareString 関数に指定するオプションを定める。
	if (pciCSOptions != NULL)
	{
		dwFlags		= pciCSOptions->GetCompareStringUCDFlags();
		dwLocale	= pciCSOptions->GetLocaleId();
	}
	else
	{
		dwFlags		= dwCSFlagsDefault;
		dwLocale	= LOCALE_USER_DEFAULT;
		if (COMPARESTRING_IS_IGNORECASE_INVALID(dwFlags))
			COMPARESTRING_SET_NORM_IGNORECASE(dwFlags);
	}

	dwFlagsC	= dwFlags;
	COMPARESTRING_UNSET_LINGUISTIC_IGNORECASE(dwFlagsC);
	COMPARESTRING_UNSET_NORM_IGNORECASE(dwFlagsC);

	if (COMPARESTRING_IS_NORM_IGNORENONSPACE(dwFlags) || COMPARESTRING_IS_NORM_IGNOREWIDTH(dwFlags))
	{
		bNormalize	= true;
	}
	else
	{
		bNormalize	= false;
	}

	//------------------------------------------------------------
	//	実際の処理はここから
	//------------------------------------------------------------
	for (pc = pTextB; pc < pTextE;)
	{
		//	デコードしたコードポイントを取り出す。
		uisBuf.clear();
		if (!GetDecodedCodepoint(&uisBuf, &pc, GetDecodeFlags(), dwFlagsC, bNormalize, NULL))
		{
			break;
		}

		for (pcu = uisBuf.c_str(); *pcu; ++pcu)
		{
			//----------------------------------------
			//	上位サロゲートの場合
			//	上位サロゲートが格納されている場合は例外をスローする。
			//----------------------------------------
			if (IS_16BIT(*pcu) && IS_HIGH_SURROGATE(*pcu))
			{
				if (SgBuf[0] != 0)
				{
					THROWPE_RUNTIME_ERROR("PCTextUR::ConvertToCpList data collapsed.");
				}
				SgBuf[0]	= (T_CHAR_U)*pcu;
			}
			//----------------------------------------
			//	下位サロゲートの場合
			//	上位サロゲートが格納されていない場合は例外をスローする。
			//----------------------------------------
			else if (IS_16BIT(*pcu) && IS_LOW_SURROGATE(*pcu))
			{
				if (SgBuf[0] == 0)
				{
					THROWPE_RUNTIME_ERROR("PCTextUR::ConvertToCpList data collapsed.");
				}
				SgBuf[1]	= (T_CHAR_U)*pcu;
				SgBuf[2]	= (T_CHAR_U)0;
				pSgBuf	= SgBuf;
				if (PLib::Unicode::ConvertToCodepoint(&uic, &pSgBuf) < 1)
				{
					THROWPE_RUNTIME_ERROR("PCTextUR::ConvertToCpList data collapsed.");
				}
				PushBackCp(uic);
				SgBuf[0]	= (T_CHAR_U)0;
				SgBuf[1]	= (T_CHAR_U)0;
			}
			//----------------------------------------
			//	それ以外の場合
			//	上位サロゲートが格納されている場合は例外をスローする。
			//----------------------------------------
			else
			{
				if (SgBuf[0] != 0)
				{
					THROWPE_RUNTIME_ERROR("PCTextUR::ConvertToCpList data collapsed.");
				}
				PushBackCp(*pcu);
			}
		}
	}
}

//----------------------------------------------------------------------
//	PCTextUR::Begin
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::Begin()
{
	if (ciCpString.empty())
	{
		*pitrCurrentPos	= ciCpString.end();
		return false;
	}
	*pitrCurrentPos	= ciCpString.begin();
	return true;
}

//----------------------------------------------------------------------
//	PCTextUR::Next
//	すでに終端に達している場合は何もせずに false を返す。
//	まだ終端に達していない場合は 1 文字進め（end であっても） true を返す。
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::Next()
{
	//	テキストがセットされていない場合、終端に達している場合は false を返す。
	if (ciCpString.empty() || *pitrCurrentPos == ciCpString.end())	return false;

	//	終端に達していない場合は 1 文字ずつ進める。
	++(*pitrCurrentPos);
	return true;
}

//----------------------------------------------------------------------
//	PCTextUR::Previous
//	既に先頭に達している場合は、移動せずに false を返す。
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::Previous()
{
	//	テキストがセットされていない場合、終端に達している場合は false を返す。
	if (ciCpString.empty() || *pitrCurrentPos == ciCpString.begin())	return false;

	//	終端に達していない場合は 1 文字ずつ進める。
	--(*pitrCurrentPos);
	return true;
}

//----------------------------------------------------------------------
//	PCTextUR::End
//	テキストがセットされていない場合は true を返す。
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::End()
{
	if (ciCpString.empty() || *pitrCurrentPos == ciCpString.end())	return true;
	return false;
}
//----------------------------------------------------------------------
//	PCTextUR::Back
//	反復子を最後のデータにセットする。
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::Back()
{
	if (ciCpString.empty())
	{
		*pitrCurrentPos	= ciCpString.end();
		return false;
	}

	*pitrCurrentPos	= ciCpString.end();
	--(*pitrCurrentPos);
	return true;
}

//----------------------------------------------------------------------
//	PCTextUR::MoveTo
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::MoveTo(T_UCP uiCp, DWORD dwFlags, T_PCSTR_U pszLocale)
{
	ITR_UCPSTRING	itrTemp;

	if (ciCpString.empty() || *pitrCurrentPos == ciCpString.end())	return false;

	for (itrTemp = *pitrCurrentPos; itrTemp != ciCpString.end(); ++itrTemp)
	{
		if (PLib::Unicode::CompareCodepointUCD(ItrToCp(itrTemp), uiCp, dwFlags, NULL) == CSTR_EQUAL)
		{
			*pitrCurrentPos	= itrTemp;
			return true;
		}
	}
	return false;
}

//----------------------------------------------------------------------
//	PCTextUR::GetPreviousItr
//----------------------------------------------------------------------
int CLASS_PCTEXTUR::GetPreviousItr(ITR_UCPSTRING& itr)
{
	if (pitrCurrentPos == NULL)	THROWPE_LOGIC_ERROR("PCTextUR: null iteraotr.");
	if (ciCpString.empty())	return PCTEXT_POS_EMPTY;
	if (*pitrCurrentPos == ciCpString.begin())	return PCTEXT_POS_UNDER;
	itr	= *pitrCurrentPos;
	--itr;
	return PCTEXT_POS_VALID;
}

//----------------------------------------------------------------------
//	PCTextUR::GetNextItr
//----------------------------------------------------------------------
int CLASS_PCTEXTUR::GetNextItr(ITR_UCPSTRING& itr)
{
	if (pitrCurrentPos == NULL)	THROWPE_LOGIC_ERROR("PCTextUR: null iteraotr.");
	if (ciCpString.empty())	return PCTEXT_POS_EMPTY;
	if (*pitrCurrentPos == ciCpString.end())	return PCTEXT_POS_OVER;
	itr	= *pitrCurrentPos;
	++itr;
	if (itr == ciCpString.end())	return PCTEXT_POS_OVER;
	return PCTEXT_POS_VALID;
}

//----------------------------------------------------------------------
//	PCTextUR::GetCurrentCp
//----------------------------------------------------------------------
int CLASS_PCTEXTUR::GetCurrentCp(T_UCP* pCp)
{
	if (pitrCurrentPos == NULL)	return PCTEXT_POS_ERROR;
	if (*pitrCurrentPos == ciCpString.end())
	{
		*pCp	= (T_UCP)0;
		return PCTEXT_POS_OVER;
	}
	*pCp	= ItrToCp(*pitrCurrentPos);
	return PCTEXT_POS_VALID;
}

//----------------------------------------------------------------------
//	PCTextUR::GetPreviousCp
//----------------------------------------------------------------------
int CLASS_PCTEXTUR::GetPreviousCp(T_UCP* pCp)
{
	ITR_UCPSTRING	itrPreviousPos;
	int			ir;
	
	ir	= GetPreviousItr(itrPreviousPos);
	if (ir <= 0)
	{
		*pCp	= (T_UCP)0;
		return ir;
	}
	*pCp	= ItrToCp(itrPreviousPos);
	return PCTEXT_POS_VALID;
}

//----------------------------------------------------------------------
//	PCTextUR::GetNextCp
//----------------------------------------------------------------------
int CLASS_PCTEXTUR::GetNextCp(T_UCP* pCp)
{
	ITR_UCPSTRING	itrNextPos;
	int			ir;

	ir	= GetNextItr(itrNextPos);
	if (ir <= 0)	return ir;
	*pCp	= ItrToCp(itrNextPos);
	return PCTEXT_POS_VALID;
}

//----------------------------------------------------------------------
//	PCTextUR::GetSubString	(1)	コードポイント列を取り出す。
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::GetSubString(UCPSTRING* pucsBuffer, ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd)
{
	ITR_UCPSTRING	itr;

	if (pucsBuffer == NULL || itrBegin >= itrEnd)	return false;
	for (itr = itrBegin; itr != itrEnd; ++itr)
	{
		pucsBuffer->append(1, ItrToCp(itr));
	}
	return true;
}

//----------------------------------------------------------------------
//	PCTextUR::GetSubString	(2)	Unicode 文字列を取り出す。
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::GetSubString(T_STRING_U* pstrBuffer, ITR_UCPSTRING& itrBegin, ITR_UCPSTRING& itrEnd)
{
	UCPSTRING	ucsTemp;

	if (!GetSubString(&ucsTemp, itrBegin, itrEnd))	return false;
	return PLib::Unicode::ConvertFromCodepoint(pstrBuffer, &ucsTemp);
}

//----------------------------------------------------------------------
//	PCTextUR::GetSubStringPreceding	(1)	指定位置より前の部分。
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::GetSubStringPreceding(UCPSTRING* pucsBuffer, ITR_UCPSTRING& itrPos)
{
	return GetSubString(pucsBuffer, ciCpString.begin(), itrPos);
}

bool CLASS_PCTEXTUR::GetSubStringPreceding(T_STRING_U* pstrBuffer, ITR_UCPSTRING& itrPos)
{
	UCPSTRING	ucsTemp;

	if (!GetSubStringPreceding(&ucsTemp, itrPos))	return false;
	return PLib::Unicode::ConvertFromCodepoint(pstrBuffer, &ucsTemp);
}

//----------------------------------------------------------------------
//	PCTextUR::GetSubStringPreceding	(2)	現在位置より前の部分。
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::GetSubStringPreceding(UCPSTRING* pucsBuffer)
{
	return GetSubStringPreceding(pucsBuffer, *pitrCurrentPos);
}

bool CLASS_PCTEXTUR::GetSubStringPreceding(T_STRING_U* pstrBuffer)
{
	return GetSubStringPreceding(pstrBuffer, *pitrCurrentPos);
}

//----------------------------------------------------------------------
//	PCTextUR::GetSubStringFollowing	(1)	指定位置以降の部分。
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::GetSubStringFollowing(UCPSTRING* pucsBuffer, ITR_UCPSTRING& itrPos)
{
	return GetSubString(pucsBuffer, itrPos, ciCpString.end());
}

bool CLASS_PCTEXTUR::GetSubStringFollowing(T_STRING_U* pstrBuffer, ITR_UCPSTRING& itrPos)
{
	UCPSTRING	ucsTemp;

	if (!GetSubStringFollowing(&ucsTemp, itrPos))	return false;
	return PLib::Unicode::ConvertFromCodepoint(pstrBuffer, &ucsTemp);
}

//----------------------------------------------------------------------
//	PCTextUR::GetSubStringFollowing	(2)	現在位置以降の部分。
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::GetSubStringFollowing(UCPSTRING* pucsBuffer)
{
	return GetSubString(pucsBuffer, *pitrCurrentPos, ciCpString.end());
}

bool CLASS_PCTEXTUR::GetSubStringFollowing(T_STRING_U* pstrBuffer)
{
	return GetSubStringFollowing(pstrBuffer, *pitrCurrentPos);
}

//----------------------------------------------------------------------
//	PCTextUR::GetString
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::GetString(UCPSTRING* pucsBuffer)
{
	return GetSubString(pucsBuffer, ciCpString.begin(), ciCpString.end());
}

bool CLASS_PCTEXTUR::GetString(T_STRING_U* pstrBuffer)
{
	UCPSTRING	ucsTemp;

	if (!GetSubString(&ucsTemp, ciCpString.begin(), ciCpString.end()))	return false;
	return PLib::Unicode::ConvertFromCodepoint(pstrBuffer, &ucsTemp);
}

//----------------------------------------------------------------------
//	PCTextUR::PushNewIterator
//----------------------------------------------------------------------
void CLASS_PCTEXTUR::PushNewIterator()
{
	ciIteratorStack.PushNew();
	pitrCurrentPos	= ciIteratorStack.pIterator();
}

//----------------------------------------------------------------------
//	PCTextUR::PopIterator
//----------------------------------------------------------------------
void CLASS_PCTEXTUR::PopIterator()
{
	ciIteratorStack.Pop();
	pitrCurrentPos	= ciIteratorStack.pIterator();
}

//----------------------------------------------------------------------
//	PCTextUR::PopIterator
//----------------------------------------------------------------------
void CLASS_PCTEXTUR::PopAndUpdateIterator()
{
	ciIteratorStack.PopAndUpdate();
	pitrCurrentPos	= ciIteratorStack.pIterator();
}


//----------------------------------------------------------------------
//	PCTextUR::MatchSubString
//----------------------------------------------------------------------
bool CLASS_PCTEXTUR::MatchSubString(T_UCP*		pCpB1,
									T_UCP*		pCpE1,
									T_UCP*		pCpB2,
									T_UCP*		pCpE2,
									DWORD		dwFlags,
									T_PCSTR_U	pszLocale)
{
	PLib::Unicode::PCCodepointSegmentBuffer	ciBuf1, ciBuf2;

	ciBuf1.Set(pCpB1, pCpE1);
	ciBuf2.Set(pCpB2, pCpE2);
	return (PLib::Unicode::CompareStringUCD(&ciBuf1, &ciBuf2, dwFlags, pszLocale) == CSTR_EQUAL);
}

#ifdef	PDEBUG
//----------------------------------------------------------------------
//	PCTextUR::DebugCurrentState
//----------------------------------------------------------------------
void CLASS_PCTEXTUR::DebugCurrentState(T_STRING_U* pstrDebug, T_STRING_U* pstrOutput)
{
	T_UCP		cpc;

	T_PCSTR_U	pfmt_d		= TQU("%d");
	T_PCSTR_U	pfmt_dp		= TQU("(%d)");
	T_PCSTR_U	pfmt_04X	= TQU("%04X");
	T_PCSTR_U	pfmt_04Xps	= TQU("(%04X) ");
	T_PCSTR_U	pLF			= TQU("\r\n");

	//------------------------------------------------------------
	//	Previous
	//------------------------------------------------------------
	pstrDebug->append(TQU("GetPreviousCp   : "));
	if (PCTEXT_GETVALIDCP(GetPreviousCp(&cpc)))
	{
		PLib::Unicode::AppendCodepointToString(pstrDebug, cpc);
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
	pstrDebug->append(pLF);

	return;
}

//----------------------------------------------------------------------
//	PCTextUR::Debug
//----------------------------------------------------------------------
void CLASS_PCTEXTUR::Debug(T_STRING_U* pstrDebug, T_STRING_U* pstrOutput)
{
	T_STRING_U	strOutput;
	T_PCSTR_U	pLF	= TQU("\r\n");
	T_PCSTR_U	pHR	= TQU("--------------------------------------------------\r\n");

	if (pTextB == NULL || pTextB >= pTextE)
	{
		pstrDebug->append(TQU("No Debug Text."));
		return;
	}
	if (pstrOutput == NULL)	pstrOutput = &strOutput;

	//------------------------------------------------------------
	//	Whole Text
	//------------------------------------------------------------
	pstrDebug->append(pHR);
	GetString(pstrDebug);
	pstrDebug->append(pLF);

	//------------------------------------------------------------
	//	Characters
	//------------------------------------------------------------
	for (Begin(); !End(); Next())
	{
		pstrDebug->append(pHR);
		DebugCurrentState(pstrDebug, pstrOutput);
		pstrDebug->append(pLF);
	}
	pstrDebug->append(pHR);
	DebugCurrentState(pstrDebug, pstrOutput);
	pstrDebug->append(pLF);
	Begin();
}

//----------------------------------------------------------------------
//	PCTextUR::Debug_GetText
//----------------------------------------------------------------------
void CLASS_PCTEXTUR::Debug_GetText(T_STRING_U* pstrDebug)
{
	GetString(pstrDebug);
}

#endif

//======================================================================
//	PCTextUR_SkipBlank
//======================================================================
bool PCTextUR_SkipBlank(PCTextUR* pciTextUR)
{
	T_UCP	cp;

	if (pciTextUR == NULL)
	{
		THROWPE_LOGIC_ERROR("PCTextUR_SkipSpace");
		return false;
	}

	while (!pciTextUR->End())
	{
		if (!PCTEXT_GETVALIDCP(pciTextUR->GetCurrentCp(&cp)))	break;
		if (!PLib::Unicode::IsBlank(cp, true))	break;
		pciTextUR->Next();
	}
	return true;
}

//======================================================================
//	PCTextUR_SkipSpace
//======================================================================
bool PCTextUR_SkipSpace(PCTextUR* pciTextUR)
{
	T_UCP	cp;

	if (pciTextUR == NULL)
	{
		THROWPE_LOGIC_ERROR("PCTextUR_SkipSpace");
		return false;
	}

	while (!pciTextUR->End())
	{
		if (!PCTEXT_GETVALIDCP(pciTextUR->GetCurrentCp(&cp)))	break;
		if (!PLib::t_IsSpace<T_UCP>(cp))	break;
		pciTextUR->Next();
	}
	return true;
}

//======================================================================
//	PCTextUR_NextLine
//
//	現在の処理対象文字が改行でないときは、何もせずに true を返す。
//	\r\n の場合は \n の次へ移動させる。それ以外の場合は 1 文字だけ進める。
//======================================================================
bool PCTextUR_NextLine(PCTextUR* pciTextUR)
{
	T_UCP	cp1, cp2;

	if (!PCTEXT_GETVALIDCP(pciTextUR->GetCurrentCp(&cp1)))	return false;
	if (!PLib::Unicode::IsCRLF(cp1, true))	return true;
	if (cp1 == (T_UCP)L'\r')
	{
		if (PCTEXT_GETVALIDCP(pciTextUR->GetNextCp(&cp2)) && cp2 == (T_UCP)L'\n')
		{
			pciTextUR->Next();
		}
	}
	return pciTextUR->Next();
}

/*
//======================================================================
//	PCTextUR_RemoveQuote
//======================================================================
bool PCTextUR_RemoveQuote(const T_CHAR** ppUnquotedB, const T_CHAR** ppUnquotedE,
						 const T_CHAR* pSrcB, const T_CHAR* pSrcE,
						 DWORD dwFlags = 0, LCID dwLocale = LOCALE_USER_DEFAULT)
{
	typedef	const T_CHAR*			T_PCSTR;
	typedef	PCTextUR<T_CHAR, 0>		CTEXTR;
	typedef	PCMulticodeChar<T_CHAR>	CMCCHAR;

	CTEXTR		ciText;
	CMCCHAR*	pMcChar;
	T_PCSTR		pTemp;
	T_PCSTR		pszDQuote	= t_Str<T_CHAR>(TEXTAW("\""));

	if (!ciText.Set(pSrcB, pSrcE))	return false;

	//------------------------------------------------------------
	//	テキストの先頭の空白文字をスキップする。
	//------------------------------------------------------------
	for (ciText.Begin(); !ciText.End(); ciText.Next())
	{
		pMcChar = ciText.GetCurrentMcChar();
		if (pMcChar != NULL && !IsSpaceMC<T_CHAR>(pMcChar, dwFlags, dwLocale))	break;
	}

	//------------------------------------------------------------
	//	空、または空白のみのテキストの場合、
	//	空白の次の文字が引用符でない場合、
	//	空白の次の引用符がテキストの最後の文字の場合は終了
	//------------------------------------------------------------
	if (ciText.End())	return false;
	if (pMcChar == NULL || !pMcChar->MatchCS(pszDQuote, dwFlags, dwLocale))	return false;
	ciText.Next();
	if (ciText.End())	return false;
	*ppUnquotedB	= ciText.GetCurrentPos();	//	引用符の次の位置を記録しておく。

	//------------------------------------------------------------
	//	テキストの終端の空白文字をスキップする。
	//------------------------------------------------------------
	for (ciText.RBegin(); !ciText.REnd(); ciText.RNext())
	{
		if (ciText.RGetCurrentMcChar(pMcChar))
		{
			if (pMcChar != NULL && !IsSpaceMC<T_CHAR>(pMcChar, dwFlags, dwLocale))	break;
		}
	}

	//------------------------------------------------------------
	//	空、または空白のみのテキストの場合、
	//	空白の次の文字が引用符でない場合、
	//	空白の次の引用符がテキストの最後の文字の場合は終了
	//------------------------------------------------------------
	if (pMcChar == NULL)	THROWPE_LOGIC_ERROR("PCTextUR_RemoveQuote");
	if (!pMcChar->MatchCS(pszDQuote, dwFlags, dwLocale))	return false;
	ciText.RGetCurrentMcChar(ppUnquotedE, &pTemp);

	return (*ppUnquotedB < *ppUnquotedE);
}
*/

//======================================================================
//	PCTextUR_GetInt	(1)	1 文字分だけ。
//======================================================================
bool PCTextUR_GetInt(int* piVal, PCTextUR* pciText, DWORD dwFlags, T_PCSTR_U pszLocale)
{
	T_UCP	cp;
	bool	bNormalize	= false;

	if (piVal == NULL || pciText == NULL)
	{
		THROWPE_LOGIC_ERROR("PCTextUR_GetInt: Invalid parameters.");
	}
	if (IS_CSFLAG_NORM_IGNOREWIDTH_SET(dwFlags)	||
		IS_CSFLAG_NORM_IGNORENONSPACE_SET(dwFlags)	||
		COMPARESTRINGUCD_IS_NORMALIZE(dwFlags))
	{
		bNormalize	= true;
	}

	if (!PCTEXT_GETVALIDCP(pciText->GetCurrentCp(&cp)))	return false;

	return PLib::Unicode::IsDigit(piVal, cp, bNormalize);
}

//======================================================================
//	PCTextUR_GetInt	(2)	複数桁可、最大桁数を指定する。
//======================================================================
bool PCTextUR_GetInt(int* piVal, int iMaxDigits, PCTextUR* pciText, DWORD dwFlags, T_PCSTR_U pszLocale)
{
	T_UCP	cp;
	int		i, v, d;
	bool	bNormalize	= false;
	bool	br	= false;

	if (piVal == NULL || pciText == NULL)
	{
		THROWPE_LOGIC_ERROR("PCTextUR_GetInt: Invalid parameters.");
	}
	if (IS_CSFLAG_NORM_IGNOREWIDTH_SET(dwFlags)	||
		IS_CSFLAG_NORM_IGNORENONSPACE_SET(dwFlags)	||
		COMPARESTRINGUCD_IS_NORMALIZE(dwFlags))
	{
		bNormalize	= true;
	}

	for (d = 0, v = 0; !pciText->End(); pciText->Next(), ++d)
	{
		if (iMaxDigits > 0 && d > iMaxDigits)	break;
		if (!PCTEXT_GETVALIDCP(pciText->GetCurrentCp(&cp)))	break;
		if (!PLib::Unicode::IsDigit(&i, cp, bNormalize))	break;
		v	= v * 10 + i;
		br	= true;
	}
	if (br)
	{
		*piVal	= v;
		return true;
	}
	return false;
}

NS_PLIB_END
