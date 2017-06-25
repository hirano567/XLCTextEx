//	XLCTextEx_1.0x	:	PLibTextEx

//	PRegEx.cpp
//
#include "stdafx.h"

NS_PLIB_BEGIN

//======================================================================
//	class PCRegExNode
//======================================================================
//----------------------------------------------------------------------
//	PCRegExNode	�R���X�g���N�^
//----------------------------------------------------------------------
CLASS_PREGEX_NODE::PCRegExNode()
:	pciBaseRegEx(NULL),
	iNodeType(PREGEX_NODE_UNDEFINED)
{
	int	i;
	for (i = 0; i < PREGEX_OPTIONALDATA_NUM; ++i)	pOptional[i]	= (LPVOID)NULL;
}

CLASS_PREGEX_NODE::PCRegExNode(PCREGEX pr)
:	pciBaseRegEx(pr),
	iNodeType(PREGEX_NODE_UNDEFINED)
{
	int	i;
	for (i = 0; i < PREGEX_OPTIONALDATA_NUM; ++i)	pOptional[i]	= (LPVOID)NULL;
}

CLASS_PREGEX_NODE::PCRegExNode(T_TYPE t)
:	pciBaseRegEx(NULL),
	iNodeType(t)
{
	int	i;
	for (i = 0; i < PREGEX_OPTIONALDATA_NUM; ++i)	pOptional[i]	= (LPVOID)NULL;
}

CLASS_PREGEX_NODE::PCRegExNode(PCREGEX pr, T_TYPE t)
:	pciBaseRegEx(pr),
	iNodeType(t)
{
	int	i;
	for (i = 0; i < PREGEX_OPTIONALDATA_NUM; ++i)	pOptional[i]	= (LPVOID)NULL;
}

//----------------------------------------------------------------------
//	PCRegExNode::Clear
//----------------------------------------------------------------------
void CLASS_PREGEX_NODE::Clear()
{
	int	i;

	iNodeType	= PREGEX_NODE_UNDEFINED;
	ciNodeList.clear();
	for (i = 0; i < PREGEX_OPTIONALDATA_NUM; ++i)	pOptional[i]	= (LPVOID)NULL;
}

//----------------------------------------------------------------------
//	PCRegExNode::SetOptionalData
//----------------------------------------------------------------------
bool CLASS_PREGEX_NODE::SetOptionalData(int iIndex, LPVOID pData)
{
	if (iIndex < 0 || iIndex >= PREGEX_OPTIONALDATA_NUM)	return false;
	pOptional[iIndex]	= pData;
	return true;
}

//----------------------------------------------------------------------
//	PCRegExNode::GetOptionalData
//----------------------------------------------------------------------
bool CLASS_PREGEX_NODE::GetOptionalData(LPVOID* ppData, int iIndex)
{
	if (iIndex < 0 || iIndex >= PREGEX_OPTIONALDATA_NUM)	return false;
	*ppData	= pOptional[iIndex];
	return true;
}

LPVOID CLASS_PREGEX_NODE::GetOptionalData(int iIndex)
{
	if (iIndex >= 0 && iIndex < PREGEX_OPTIONALDATA_NUM)	return pOptional[iIndex];
	return NULL;
}

//----------------------------------------------------------------------
//	PCRegExNode::Size
//----------------------------------------------------------------------
bool CLASS_PREGEX_NODE::Size(int* piMin, int* piMax)
{
	int				iMin, iMax;
	int				iMinT, iMaxT;
	ITR_NODELIST	itr;
	CSREGEX*		pSRegEx;
	CNODE*			pNode;

	switch (iNodeType)
	{
	case PREGEX_NODE_ATOM_CHAR:
	case PREGEX_NODE_ATOM_ANY_CHAR:
	case PREGEX_NODE_ATOM_CHAR_DIGIT:
	case PREGEX_NODE_ATOM_CHAR_NON_DIGIT:
	case PREGEX_NODE_ATOM_CHAR_WORD:
	case PREGEX_NODE_ATOM_CHAR_NON_WORD:
	case PREGEX_NODE_ATOM_CHAR_SPACE:
	case PREGEX_NODE_ATOM_CHAR_NON_SPACE:
	case PREGEX_NODE_ATOM_BRACKETEX:
		*piMin	= 1;
		*piMax	= 1;
		return true;
		break;

	case PREGEX_NODE_ATOM_WORD_BOUNDARY:
	case PREGEX_NODE_ATOM_NOT_WORD_BOUNDARY:
	case PREGEX_NODE_ATOM_LAST_MATCH:
	case PREGEX_NODE_ATOM_START_MULTI:
	case PREGEX_NODE_ATOM_END_MULTI:
	case PREGEX_NODE_ATOM_START_SINGLE:
	case PREGEX_NODE_ATOM_END_SINGLE:
	case PREGEX_NODE_ATOM_ENDLF_SINGLE:
		*piMin	= 0;
		*piMax	= 0;
		return true;
		break;

	case PREGEX_NODE_ATOM_REGEX:
		pSRegEx	= GetOptionalSRegEx();
		if ((pSRegEx = GetOptionalSRegEx()) == NULL	||
			(pNode = pSRegEx->GetRootNode()) == NULL)
		{
			*piMin	= -1;
			*piMax	= -1;
			return false;
		}
		switch (pSRegEx->GetType())
		{
		case PREGEX_EX_TYPE_CAP:
		case PREGEX_EX_TYPE_CAP_NAMED:
		case PREGEX_EX_TYPE_NCAP:
		case PREGEX_EX_TYPE_SETOPTIONS:
		case PREGEX_EX_TYPE_POSITIVE_LOOKAHEAD:
		case PREGEX_EX_TYPE_POSITIVE_LOOKBEHIND:
		case PREGEX_EX_TYPE_INDEPENDENT:
		case PREGEX_EX_TYPE_CONDITIONAL_INDEX:
		case PREGEX_EX_TYPE_CONDITIONAL_NAME:
			return pNode->Size(piMin, piMax);
			break;

		case PREGEX_EX_TYPE_NEGATIVE_LOOKAHEAD:
		case PREGEX_EX_TYPE_NEGATIVE_LOOKBEHIND:
			pNode->Size(&iMin, &iMax);
			*piMin	= 0;
			*piMax	= iMax;
			return true;
			break;

		case PREGEX_EX_TYPE_CTRL_SETOPTIONS:
			*piMin	= 0;
			*piMax	= 0;
			return true;
			break;

		case PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKAHEAD:
		case PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKBEHIND:
			pNode->Size(&iMin, &iMax);
			*piMin	= iMin;
			*piMax	= iMax;
			break;

		case PREGEX_EX_TYPE_CONDITIONAL_NEGATIVE_LOOKAHEAD:
		case PREGEX_EX_TYPE_CONDITIONAL_NEGATIVE_LOOKBEHIND:
			pNode->Size(&iMin, &iMax);
			*piMin	= iMin;
			*piMax	= iMax;
			break;
		}
		break;

	case PREGEX_NODE_ATOM_BACKREF:
	case PREGEX_NODE_ATOM_BACKREF_BYNAME:
		*piMin	= -1;
		*piMax	= -1;
		return false;
		break;

	case PREGEX_NODE_ATOM_CTRL_SETOPTIONS:
	case PREGEX_NODE_ATOM_CTRL_COMMENT:
		*piMin	= 0;
		*piMax	= 0;
		return true;
		break;

	//case PREGEX_NODE_PIECE:
	//	break;

	case PREGEX_NODE_PIECE_ONE_ATOM:
		if (!ciNodeList.empty())
			return (*(ciNodeList.begin()))->Size(piMin, piMax);
		return false;
		break;

	case PREGEX_NODE_PIECE_ZERO_OR_MORE:
	case PREGEX_NODE_PIECE_ZERO_OR_MORE_NG:
		*piMin	= 0;
		*piMax	= -1;
		return true;
		break;

	case PREGEX_NODE_PIECE_ONE_OR_MORE:
	case PREGEX_NODE_PIECE_ONE_OR_MORE_NG:
		if (!ciNodeList.empty() && (*(ciNodeList.begin()))->Size(piMin, piMax))
		{
			*piMax	= -1;
			return true;
		}
		return false;
		break;

	case PREGEX_NODE_PIECE_ZERO_OR_ONE:
	case PREGEX_NODE_PIECE_ZERO_OR_ONE_NG:
		if (!ciNodeList.empty() && (*(ciNodeList.begin()))->Size(piMin, piMax))
		{
			*piMin	= 0;
			return true;
		}
		return false;
		break;

	case PREGEX_NODE_PIECE_BOUND:
	case PREGEX_NODE_PIECE_BOUND_NG:
		if (ciNodeList.empty())	return false;
		(*(ciNodeList.begin()))->Size(&iMin, &iMax);
		iMinT	= GetBoundMin();
		iMaxT	= GetBoundMax();
		//	atom �̒������s��łȂ��ꍇ�B
		if (iMin >= 0)
		{
			*piMin	= iMin * iMinT;
			if (iMax >= 0 && iMaxT >= 0)
			{
				*piMax	= iMax * iMaxT;
			}
			else if (iMax == 0 || iMaxT == 0)
			{
				*piMax	= 0;
			}
			else
			{
				*piMax	= -1;
			}
			return true;
		}
		//	atom �̒������s��̏ꍇ
		else
		{
			if (iMinT == 0 && iMaxT == 0)
			{
				*piMin	= 0;
				*piMax	= 0;
				return true;
			}
			*piMin	= -1;
			*piMax	= -1;
			return false;
		}
		return false;
		break;

	case PREGEX_NODE_BRANCH:
		iMinT	= 0;
		iMaxT	= 0;
		for (itr = ciNodeList.begin(); itr != ciNodeList.end(); ++itr)
		{
			if (!(*itr)->Size(&iMin, &iMax))
			{
				*piMin	= -1;
				*piMax	= -1;
				return false;
			}
			iMinT	+= iMin;
			(iMaxT < 0 || iMax < 0) ? iMaxT = -1 : iMaxT += iMax;
		}
		*piMin	= iMinT;
		*piMax	= iMaxT;
		return true;
		break;

	case PREGEX_NODE_EXPRESSION:
		iMinT	= 0;
		iMaxT	= 0;
		for (itr = ciNodeList.begin(); itr != ciNodeList.end(); ++itr)
		{
			if (!(*itr)->Size(&iMin, &iMax))
			{
				*piMin	= -1;
				*piMax	= -1;
				return false;
			}
			if (itr == ciNodeList.begin())
			{
				iMinT	= iMin;
				iMaxT	= iMax;
			}
			else
			{
				if (iMin < iMinT)	iMinT = iMin;
				if (iMaxT < 0 || iMaxT < 0)
				{
					iMaxT	= -1;
				}
				else if (iMaxT < iMax)
				{
					iMaxT	= iMax;
				}
			}
		}
		*piMin	= iMinT;
		*piMax	= iMaxT;
		return true;
		break;

	case PREGEX_NODE_EXPRESSION_EMPTY:
		*piMin	= 0;
		*piMax	= 0;
		return true;
		break;

	case PREGEX_NODE_EXPRESSION_CONDITIONAL_INDEX:
	case PREGEX_NODE_EXPRESSION_CONDITIONAL_NAME:
	case PREGEX_NODE_EXPRESSION_CONDITIONAL_POSITIVE_LOOKAHEAD:
	case PREGEX_NODE_EXPRESSION_CONDITIONAL_NEGATIVE_LOOKAHEAD:
	case PREGEX_NODE_EXPRESSION_CONDITIONAL_POSITIVE_LOOKBEHIND:
	case PREGEX_NODE_EXPRESSION_CONDITIONAL_NEGATIVE_LOOKBEHIND:
		*piMin	= 0;
		*piMax	= 0;
		return true;
		break;

	default:
		break;
	}
	*piMin	= -1;
	*piMax	= -1;
	return false;
}


//======================================================================
//	class PCRegExNState
//======================================================================
//----------------------------------------------------------------------
//	PCRegExNState	�R���X�g���N�^
//----------------------------------------------------------------------
CLASS_PREGEX_NSTATE::PCRegExNState()
:	iIndex(PREGEX_INVALID_INDEX),
	iType(PREGEX_NSTATE_TYPE_NORMAL),
	pciBaseRegEx(NULL),
	pNTransition(NULL),
	iFlags(0)
{
	Clear();
}

//----------------------------------------------------------------------
//	PCRegExNState::Clear
//----------------------------------------------------------------------
void CLASS_PREGEX_NSTATE::Clear()
{
	int	i;

	iIndex			= PREGEX_INVALID_INDEX;
	iType			= PREGEX_NSTATE_TYPE_NORMAL;
	pciBaseRegEx	= NULL;
	pNTransition	= NULL;
	iFlags			= 0;

	for (i = 0; i < PREGEX_OPTIONALDATA_NUM; ++i)	pOptional[i] = (LPVOID)0;
}

//----------------------------------------------------------------------
//	PCRegExNState::AppendTransition	(1)
//----------------------------------------------------------------------
void CLASS_PREGEX_NSTATE::AppendTransition(CNTRANSITION* pNTr)
{
	if (pNTr == NULL)	return;
	pNTr->SetNextTransition(pNTransition);
	pNTransition	= pNTr;
}

//----------------------------------------------------------------------
//	PCRegExNState::AppendTransition	(2-1)
//----------------------------------------------------------------------
void CLASS_PREGEX_NSTATE::AppendTransition(CNSTATE* pNDDst)
{
	CNTRANSITION*	pTrans;

	pTrans	= pciBaseRegEx->CreateNTransition(this, pNDDst);
}

//----------------------------------------------------------------------
//	PCRegExNState::AppendTransition	(2-2)
//----------------------------------------------------------------------
void CLASS_PREGEX_NSTATE::AppendTransition(CNSTATE* pNDDst, T_INDEX iMatchingType)
{
	CNTRANSITION*	pTrans;

	pTrans	= pciBaseRegEx->CreateNTransition(this, pNDDst);
	pTrans->SetMatching(iMatchingType);
}

//----------------------------------------------------------------------
//	PCRegExNState::AppendTransition	(2-3)
//----------------------------------------------------------------------
void CLASS_PREGEX_NSTATE::AppendTransition(CNSTATE*	pNDDst,
											T_INDEX		iMatchingType,
											LPVOID		pMatchingValue)
{
	CNTRANSITION*	pTrans;

	pTrans	= pciBaseRegEx->CreateNTransition(this, pNDDst);
	pTrans->SetMatching(iMatchingType, pMatchingValue);
}

//----------------------------------------------------------------------
//	PCRegExNState::SetOptionalData()
//----------------------------------------------------------------------
bool CLASS_PREGEX_NSTATE::SetOptionalData(int iIndex, LPVOID pData)
{
	if (iIndex < 0 || iIndex >= PREGEX_OPTIONALDATA_NUM)	return false;
	pOptional[iIndex]	= pData;
	return true;
}

//----------------------------------------------------------------------
//	PCRegExNState::GetOptionalData()
//----------------------------------------------------------------------
bool CLASS_PREGEX_NSTATE::GetOptionalData(LPVOID* ppData, int iIndex)
{
	if (iIndex >= 0 && iIndex < PREGEX_OPTIONALDATA_NUM)
	{
		*ppData	= pOptional[iIndex];
		return true;
	}
	return false;
}

LPVOID CLASS_PREGEX_NSTATE::GetOptionalData(int iIndex)
{
	if (iIndex >= 0 && iIndex < PREGEX_OPTIONALDATA_NUM)
	{
		return pOptional[iIndex];
	}
	return NULL;
}

//----------------------------------------------------------------------
//	PCRegExNState::NextState
//----------------------------------------------------------------------
bool CLASS_PREGEX_NSTATE::NextState(CRETEXT* pciText, SLOOKBEHIND* pLookBehind)
{
	CNSTATE*					pNextState;
	CNTRANSITION*				ptrCurrent;
	ITR_UCPSTRING				itrBegin, itrEnd;
	ITR_UCPSTRING				itrCurrent;
	SMATCHING					siMatching;
	bool						bInLoop	= false;

	//	�}�b�`���O�̏����񐔂��J�E���g����B
	pciText->IncrementMatchTimes();

#ifdef	PDEBUG_PROFILE
	bool	bpf;
	PLib::Debug::Profiler_Start(0);
#endif


#if defined(PDEBUG) && defined(PDEBUG_MATCH)
	UCPSTRING*	pSubStr;
	T_PCSTR_U	pfmt_d		= TQU("%d");
	T_PCSTR_U	pfmt_08Xp	= TQU("(0x%08d)");
	T_PCSTR_U	pfmt_nsd	= TQU("NFA State[%d]\t");
	T_STRING_U	strDebug;

	strDebug.clear();
	NS_PLIB::AppendNumToString<T_CHAR_U, int>(&strDebug, pfmt_nsd, (int)iIndex);
	switch (iType)
	{
	case PREGEX_NSTATE_TYPE_EX_CAP_BEGIN:
		strDebug.append(TQU("Enter SubEx Captured["));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_d, (int)GetOptionalIndex());
		strDebug.append(TQU("]"));
		break;

	case PREGEX_NSTATE_TYPE_EX_CAP_END:
		strDebug.append(TQU("Exit SubEx Captured["));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_d, (int)GetOptionalIndex());
		strDebug.append(TQU("]"));
		break;

	case PREGEX_NSTATE_TYPE_EX_CAP_NAMED_BEGIN:
		pSubStr = GetOptionalName();
		strDebug.append(TQU("Enter SubEx Captured by Name \""));
		PLib::Unicode::ConvertFromCodepoint(&strDebug, pSubStr);
		strDebug.append(TQU("\" "));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)pSubStr);
		break;

	case PREGEX_NSTATE_TYPE_EX_CAP_NAMED_END:
		pSubStr = GetOptionalName();
		strDebug.append(TQU("Exit SubEx Captured by Name \""));
		PLib::Unicode::ConvertFromCodepoint(&strDebug, pSubStr);
		strDebug.append(TQU("\" "));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)pSubStr);
		break;

	case PREGEX_NSTATE_TYPE_EX_NCAP_BEGIN:
		strDebug.append(TQU("Enter SubEx "));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)GetOptionalSRegEx());
		strDebug.append(TQU(", Not Captured"));
		break;


	case PREGEX_NSTATE_TYPE_EX_NCAP_END:
		strDebug.append(TQU("Exit SubEx "));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)GetOptionalSRegEx());
		strDebug.append(TQU(", Not Captured"));
		break;

	case PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKAHEAD_BEGIN:
		strDebug.append(TQU("Enter SubEx "));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)GetOptionalSRegEx());
		strDebug.append(TQU(", Positive LookAhead"));
		break;

	case PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKAHEAD_END:
		strDebug.append(TQU("Exit SubEx "));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)GetOptionalSRegEx());
		strDebug.append(TQU(", Positive LookAhead"));
		break;

	case PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKAHEAD_BEGIN:
		strDebug.append(TQU("Enter SubEx "));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)GetOptionalSRegEx());
		strDebug.append(TQU(", Negative LookAhead"));
		break;

	case PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKAHEAD_END:
		strDebug.append(TQU("Exit SubEx "));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)GetOptionalSRegEx());
		strDebug.append(TQU(", Negative LookAhead"));
		break;

	case PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKBEHIND_BEGIN:
		strDebug.append(TQU("Enter SubEx "));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)GetOptionalSRegEx());
		strDebug.append(TQU(", Positive LookBehind"));
		break;

	case PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKBEHIND_END:
		strDebug.append(TQU("Exit SubEx "));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)GetOptionalSRegEx());
		strDebug.append(TQU(", Positive LookBehind"));
		break;

	case PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKBEHIND_BEGIN:
		strDebug.append(TQU("Enter SubEx "));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)GetOptionalSRegEx());
		strDebug.append(TQU(", Negative LookBehind"));
		break;

	case PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKBEHIND_END:
		strDebug.append(TQU("Exit SubEx "));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)GetOptionalSRegEx());
		strDebug.append(TQU(", Negative LookBehind"));
		break;

	case PREGEX_NSTATE_TYPE_EX_INDEPENDENT_BEGIN:
		strDebug.append(TQU("Enter Independent SubEx "));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)GetOptionalSRegEx());
		break;

	case PREGEX_NSTATE_TYPE_EX_INDEPENDENT_END:
		strDebug.append(TQU("Exit Independent SubEx "));
		NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)GetOptionalSRegEx());
		break;

	case PREGEX_NSTATE_TYPE_EX_SETOPTIONS_BEGIN:
		strDebug.append(TQU("Enter SubEx Set Options "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(&strDebug, pfmt_08Xp, (int)GetOptionalSRegEx());
		strDebug.append(TQU(" ON:"));
		pciBaseRegEx->Options()->DebugFlags(&strDebug, (DWORD)GetOptionalData(0), false);
		strDebug.append(TQU(" OFF:"));
		pciBaseRegEx->Options()->DebugFlags(&strDebug, (DWORD)GetOptionalData(1), false);
		break;

	case PREGEX_NSTATE_TYPE_EX_SETOPTIONS_END:
		strDebug.append(TQU("Exit SubEx Set Options "));
		NS_PLIB::AppendNumToString<T_CHAR_U, int>(&strDebug, pfmt_08Xp, (int)GetOptionalSRegEx());
		strDebug.append(TQU(" ON:"));
		pciBaseRegEx->Options()->DebugFlags(&strDebug, (DWORD)GetOptionalData(0), false);
		strDebug.append(TQU(" OFF:"));
		pciBaseRegEx->Options()->DebugFlags(&strDebug, (DWORD)GetOptionalData(1), false);
		break;

	case PREGEX_NSTATE_TYPE_CTRL_SETOPTIONS:
		strDebug.append(TQU("Set Options ON:"));
		pciBaseRegEx->Options()->DebugFlags(&strDebug, (DWORD)GetOptionalData(0), false);
		strDebug.append(TQU(" OFF:"));
		pciBaseRegEx->Options()->DebugFlags(&strDebug, (DWORD)GetOptionalData(1), false);
		break;
	}
	NS_PLIB::Debug::Log(strDebug.c_str());
#endif

	//------------------------------------------------------------
	//	�O����	�I�v�V�����̐ݒ�
	//------------------------------------------------------------
	switch (iType)
	{
	case PREGEX_NSTATE_TYPE_NORMAL:
		break;

	case PREGEX_NSTATE_TYPE_CTRL_SETOPTIONS:
		pciText->SetOptions((DWORD)GetOptionalData(0), (DWORD)GetOptionalData(1));
		break;

	case PREGEX_NSTATE_TYPE_EX_CAP_BEGIN:
	case PREGEX_NSTATE_TYPE_EX_CAP_NAMED_BEGIN:
	case PREGEX_NSTATE_TYPE_EX_NCAP_BEGIN:
		pciText->PushNewOptions();
		break;

	case PREGEX_NSTATE_TYPE_EX_CAP_END:
	case PREGEX_NSTATE_TYPE_EX_CAP_NAMED_END:
	case PREGEX_NSTATE_TYPE_EX_NCAP_END:
		pciText->PopOptions();
		break;

	case PREGEX_NSTATE_TYPE_EX_SETOPTIONS_BEGIN:
		pciText->PushNewOptions();
		pciText->SetOptions((DWORD)GetOptionalData(0), (DWORD)GetOptionalData(1));
		break;

	case PREGEX_NSTATE_TYPE_EX_SETOPTIONS_END:
		pciText->PopOptions();
		break;

	default:
		break;
	}

	//------------------------------------------------------------
	//	�{����	�J�ڐ�����߂�B
	//------------------------------------------------------------
	if (!pciText->GetCurrentPos(itrCurrent))	THROWPE_LOGIC_ERROR("");
	bInLoop	= pciText->FindHistory(this);
	pciText->PushHistory(this);

	if (pLookBehind != NULL)
	{
		//	�I���ʒu��ʂ�߂����ꍇ�� false ��Ԃ�����B
		if (pLookBehind->bAtEnd == true && pLookBehind->itrEnd != itrCurrent)
		{
			goto NOT_MATCH;
		}
		if (pLookBehind->itrEnd == itrCurrent)
		{
			pLookBehind->bAtEnd	= true;
		}
	}

	//------------------------------------------------------------
	//	(1)	��������̏ꍇ
	//------------------------------------------------------------
	switch (iType)
	{
	case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_INDEX:
	case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NAME:
	case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_POSITIVE_LOOKAHEAD:
	case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NEGATIVE_LOOKAHEAD:
	case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_POSITIVE_LOOKBEHIND:
	case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NEGATIVE_LOOKBEHIND:
		//--------------------------------------------------
		//	(1-1)	�J�ڂ�I��
		//--------------------------------------------------
		switch (iType)
		{
		case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_INDEX:
			if (pciText->GetCurrentBackRef(itrBegin, itrEnd, GetOptionalIndex()))
			{
				ptrCurrent = pNTransition;
			}
			else
			{
				ptrCurrent = pNTransition->GetNextTransition();
			}
			break;

		case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NAME:
			if (pciText->GetCurrentNamedBackRef(itrBegin, itrEnd, GetOptionalName()))
			{
				ptrCurrent = pNTransition;
			}
			else
			{
				ptrCurrent = pNTransition->GetNextTransition();
			}
			break;

		case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_POSITIVE_LOOKAHEAD:
		case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NEGATIVE_LOOKAHEAD:
		case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_POSITIVE_LOOKBEHIND:
		case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NEGATIVE_LOOKBEHIND:
			switch (iType)
			{
			case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_POSITIVE_LOOKAHEAD:
				siMatching.iType	= PREGEX_TRANSITION_MATCH_EX_POSITIVE_LOOKAHEAD;
				break;

			case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NEGATIVE_LOOKAHEAD:
				siMatching.iType	= PREGEX_TRANSITION_MATCH_EX_NEGATIVE_LOOKAHEAD;
				break;

			case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_POSITIVE_LOOKBEHIND:
				siMatching.iType	= PREGEX_TRANSITION_MATCH_EX_POSITIVE_LOOKBEHIND;
				break;

			case PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NEGATIVE_LOOKBEHIND:
				siMatching.iType	= PREGEX_TRANSITION_MATCH_EX_NEGATIVE_LOOKBEHIND;
				break;
			}
			siMatching.pValue	= GetOptionalData(0);

			if (pciBaseRegEx->Match(&siMatching, pciText, pLookBehind))
			{
				ptrCurrent = pNTransition;
			}
			else
			{
				ptrCurrent = pNTransition->GetNextTransition();
			}
		}

		//--------------------------------------------------
		//	(1-2)	�J�ڏ����Ƀ}�b�`���Ă��邩���ׂ�B
		//--------------------------------------------------
		pciText->PushNewIterator();

		//	�}�b�`�����ꍇ�A���̕������w���Ă���B
		if (pciBaseRegEx->Match(ptrCurrent->GetMatching(), pciText, pLookBehind))
		{
			pNextState	= ptrCurrent->GetDestination();

#if defined(PDEBUG) && defined(PDEBUG_MATCH)
			strDebug.clear();
			AppendNumToString<T_CHAR, int>(&strDebug, pfmt_nsd, (int)GetStateIndex());
			strDebug.append(TQU("goto "));
			AppendNumToString<T_CHAR, int>(&strDebug, pfmt_d, (int)pNextState->GetStateIndex());
			AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)pNextState);
			strDebug.append(TQU(" : "));
			if (!pciText->GetCurrentPos(itrCurrent))	THROWPE_LOGIC_ERROR("");
			pciText->GetSubStringFollowing(&strDebug, itrCurrent);
			NS_PLIB::Debug::Log(strDebug.c_str());
#endif

			//	�����ʒu�������Ȃ��܂܁A���݂̏�Ԃ��ȑO�ɂ���A����Ɏ��̑J�ڐ������ꍇ�A
			//	���� 0 �̕�����ւ̃}�b�`���J��Ԃ��Ă���Ƃ݂Ȃ��A�J�ڐ�Ȃ��Ƃ��ď�������B
			if (bInLoop == true && pciText->FindHistory(pNextState))
			{
				pciText->PopIterator();
				break;
			}

			//	���̏�Ԃֈړ�����B
			if (pNextState->NextState(pciText, pLookBehind))
			{
#if defined(PDEBUG) && defined(PDEBUG_MATCH)
				strDebug.clear();
				AppendNumToString<T_CHAR, int>(&strDebug, pfmt_nsd, (int)GetStateIndex());
				strDebug.append(TQU("Return true  : "));
				if (!pciText->GetCurrentPos(itrCurrent))	THROWPE_LOGIC_ERROR("");
				pciText->GetSubStringFollowing(&strDebug, itrCurrent);
				NS_PLIB::Debug::Log(strDebug.c_str());
#endif
				pciText->PopAndUpdateIterator();
				return true;
			}
		}
		pciText->PopIterator();
		break;

		//--------------------------------------------------
		//	(2)	�ʏ�̏ꍇ�ApNTransition ���珇�Ƀ}�b�`���Ă��邩���ׂ�B
		//--------------------------------------------------
	default:
		for (ptrCurrent = pNTransition; ptrCurrent != NULL; ptrCurrent = ptrCurrent->GetNextTransition())
		{
			pciText->PushNewIterator();

			//	�}�b�`�����ꍇ�A���̕������w���Ă���B
			if (pciBaseRegEx->Match(ptrCurrent->GetMatching(), pciText, pLookBehind))
			{
				pNextState	= ptrCurrent->GetDestination();

#if defined(PDEBUG) && defined(PDEBUG_MATCH)
				strDebug.clear();
				AppendNumToString<T_CHAR, int>(&strDebug, pfmt_nsd, (int)GetStateIndex());
				strDebug.append(TQU("goto "));
				AppendNumToString<T_CHAR, int>(&strDebug, pfmt_d, (int)pNextState->GetStateIndex());
				AppendNumToString<T_CHAR, int>(&strDebug, pfmt_08Xp, (int)pNextState);
				strDebug.append(TQU(" : "));
				if (!pciText->GetCurrentPos(itrCurrent))	THROWPE_LOGIC_ERROR("");
				pciText->GetSubStringFollowing(&strDebug, itrCurrent);
				NS_PLIB::Debug::Log(strDebug.c_str());
#endif

				//	�����ʒu�������Ȃ��܂܁A���݂̏�Ԃ��ȑO�ɂ���A����Ɏ��̑J�ڐ������ꍇ�A
				//	���� 0 �̕�����ւ̃}�b�`���J��Ԃ��Ă���Ƃ݂Ȃ��A
				//	�e�L�X�g�ʒu��߂��Ď��̑J�ڂ𒲂ׂ�B
				if (bInLoop == true && pciText->FindHistory(pNextState))
				{
					pciText->PopIterator();
					continue;
				}

				//	���̏�Ԃֈړ�����B
				if (pNextState->NextState(pciText, pLookBehind))
				{
#if defined(PDEBUG) && defined(PDEBUG_MATCH)
					strDebug.clear();
					AppendNumToString<T_CHAR, int>(&strDebug, pfmt_nsd, (int)GetStateIndex());
					strDebug.append(TQU("Return true  : "));
					if (!pciText->GetCurrentPos(itrCurrent))	THROWPE_LOGIC_ERROR("");
					pciText->GetSubStringFollowing(&strDebug, itrCurrent);
					NS_PLIB::Debug::Log(strDebug.c_str());
#endif
					pciText->PopAndUpdateIterator();
					return true;
				}
			}
			pciText->PopIterator();
		}
		break;
	}

#if defined(PDEBUG) && defined(PDEBUG_MATCH)
	strDebug.clear();
	NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug, pfmt_nsd, (int)iIndex);
	if (IsFinal())
		strDebug.append(TQU("Final  : "));
	else
		strDebug.append(TQU("Return false : "));
	if (!pciText->GetCurrentPos(itrCurrent))	THROWPE_LOGIC_ERROR("");
	pciText->GetSubStringFollowing(&strDebug, itrCurrent);
	NS_PLIB::Debug::Log(strDebug.c_str());
#endif

	//------------------------------------------------------------
	//	�J�ڐ悪������Ȃ��ꍇ�A
	//	�I����ԂŁA���� 0 �̃}�b�`���J��Ԃ��Ă��Ȃ��Ȃ� true ��Ԃ��B
	//------------------------------------------------------------
	if (IsFinal())
	{
		if (pciText->GlobalMatching()->bMatchZeroLength == false)
		{
			return true;
		}
		//	bMatchZeroLength �� true�A���Ȃ킿�A���O�̃}�b�`������ 0 �̏ꍇ�A
		//	����͒��� 0 �łȂ��Ȃ� true ��Ԃ��B
		//	��������� 0 �Ȃ玟�̌��𒲂ׂ�悤�ɂ���B�܂�A�㏈�������� false ��Ԃ��B
		if (!pciText->GlobalMatchingNotMove())	return true;
	}

	//------------------------------------------------------------
	//	�J�ڐ悪������Ȃ��ꍇ�A�I����ԂłȂ��Ȃ�
	//	�㏈�������� false ��Ԃ��B
	//------------------------------------------------------------
NOT_MATCH:

	switch (iType)
	{
	case PREGEX_NSTATE_TYPE_NORMAL:
		break;

	case PREGEX_NSTATE_TYPE_CTRL_SETOPTIONS:
		pciText->UndoSetOptions();
		break;

	case PREGEX_NSTATE_TYPE_EX_CAP_BEGIN:
	case PREGEX_NSTATE_TYPE_EX_CAP_NAMED_BEGIN:
	case PREGEX_NSTATE_TYPE_EX_NCAP_BEGIN:
		pciText->UndoPushOptions();
		break;

	case PREGEX_NSTATE_TYPE_EX_CAP_END:
	case PREGEX_NSTATE_TYPE_EX_CAP_NAMED_END:
	case PREGEX_NSTATE_TYPE_EX_NCAP_END:
		pciText->UndoPopOptions();
		break;

	case PREGEX_NSTATE_TYPE_EX_SETOPTIONS_BEGIN:
		pciText->UndoSetOptions();
		pciText->UndoPushOptions();
		break;

	case PREGEX_NSTATE_TYPE_EX_SETOPTIONS_END:
		pciText->UndoPopOptions();
		break;

	default:
		break;
	}

	pciText->PopHistory();
	return false;
}


//======================================================================
//	class PCRegExNTransition
//======================================================================
//----------------------------------------------------------------------
//	PCRegExNTransition	�R���X�g���N�^
//----------------------------------------------------------------------
CLASS_PREGEX_NTRANSITION::PCRegExNTransition()
:	pBaseRegEx(NULL),
	pDestination(NULL),
	pNextTransition(NULL)
{
}

//----------------------------------------------------------------------
//	PCRegExNTransition::Init
//----------------------------------------------------------------------
void CLASS_PREGEX_NTRANSITION::Init()
{
	pDestination	= NULL;
	pNextTransition	= NULL;
	siMatching.Clear();;
}

//----------------------------------------------------------------------
//	PCRegExNTransition::Match
//----------------------------------------------------------------------
bool CLASS_PREGEX_NTRANSITION::Match(PCRETEXT		psiText,
									  SMATCHTIMES*	psiMatchTimes,
									  SLOOKBEHIND*	pLookBehind)
{
	if (pBaseRegEx != NULL)
	{
		return pBaseRegEx->Match(&siMatching, psiText, pLookBehind);
	}
	return false;
}


//======================================================================
//	class PCSRegEx
//======================================================================
//----------------------------------------------------------------------
//	PCSRegEx::Clear()
//----------------------------------------------------------------------
void CLASS_SREGEX::Clear()
{
	pciBaseRegEx	= NULL;
	pciPattern		= NULL;
	iType			= PREGEX_EX_TYPE_CAP;
	pciRootNode		= NULL;

	ciNodeArray.clear();
}

//----------------------------------------------------------------------
//	PCSRegEx::Init()
//----------------------------------------------------------------------
bool CLASS_SREGEX::Init()
{
	ciNodeArray.clear();
	return true;
}

//----------------------------------------------------------------------
//	PCSRegEx	�R���X�g���N�^
//----------------------------------------------------------------------
CLASS_SREGEX::PCSRegEx(PCREGEX pRegEx)
:	pciBaseRegEx(pRegEx),
	pciPattern(NULL),
	iType(PREGEX_EX_TYPE_CAP),
	pciRootNode(NULL)
{
	int	i;
	for (i = 0; i < PREGEX_OPTIONALDATA_NUM; ++i)	pOptional[i] = (LPVOID)NULL;

	SetPattern();
}

//----------------------------------------------------------------------
//	PCSRegEx	�f�X�g���N�^
//----------------------------------------------------------------------
CLASS_SREGEX::~PCSRegEx()
{
	Clear();
}

//----------------------------------------------------------------------
//	PCSRegEx::SetBase
//----------------------------------------------------------------------
void CLASS_SREGEX::SetBase(PCREGEX pRegEx)
{
	pciBaseRegEx = pRegEx;
	SetPattern();
}

//----------------------------------------------------------------------
//	PCSRegEx::SetPattern
//----------------------------------------------------------------------
void CLASS_SREGEX::SetPattern()
{
	if (pciBaseRegEx != NULL)
	{
		pciPattern	= pciBaseRegEx->Pattern();
	}
}

//----------------------------------------------------------------------
//	PCSRegEx::SetOptionalData()
//----------------------------------------------------------------------
bool CLASS_SREGEX::SetOptionalData(int iIndex, LPVOID pData)
{
	if (iIndex < 0 || iIndex >= PREGEX_OPTIONALDATA_NUM)	return false;
	pOptional[iIndex]	= pData;
	return true;
}

//----------------------------------------------------------------------
//	PCSRegEx::GetOptionalData()
//----------------------------------------------------------------------
bool CLASS_SREGEX::GetOptionalData(LPVOID* ppData, int iIndex)
{
	if (iIndex >= 0 && iIndex < PREGEX_OPTIONALDATA_NUM)
	{
		*ppData	= pOptional[iIndex];
		return true;
	}
	return false;
}

LPVOID CLASS_SREGEX::GetOptionalData(int iIndex)
{
	if (iIndex >= 0 && iIndex < PREGEX_OPTIONALDATA_NUM)
	{
		return pOptional[iIndex];
	}
	return NULL;
}

//----------------------------------------------------------------------
//	PCSRegEx::CreateNode
//	�V���� Node ���쐬���A�z��ɓo�^����B
//	Node �̐ݒ�͍s��Ȃ��B�Ăяo�����ōs�����ƁB
//	�G���[�̏ꍇ�͗�O���X���[����B
//----------------------------------------------------------------------
PCRegExNode* CLASS_SREGEX::CreateNode(int iType)
{
	T_INDEX	iNodeCount	= (T_INDEX)(ciNodeArray.size());
	PCNODE	pNode		= NULL;

	if (iNodeCount >= PREGEX_NODE_MAX)	THROWPE_RUNTIME_ERROR("Too many nodes.");

	pNode	= pciBaseRegEx->AllocateNode();
	ciNodeArray.push_back(pNode);

	pNode->Clear();
	pNode->SetBase(pciBaseRegEx);
	pNode->SetNodeIndex(iNodeCount);
	pNode->SetNodeType(iType);

	return pNode;
}

//----------------------------------------------------------------------
//	PCSRegEx::Atom	�̕⏕�֐�	AtomMatchCp
//----------------------------------------------------------------------
static inline bool AtomMatchCp(T_UCP cp1, T_UCP cp2, DWORD dwFlags, T_PCSTR_U pszLocale)
{
	return (PLib::Unicode::CompareCodepointUCD(cp1, cp2, dwFlags, pszLocale) == CSTR_EQUAL);
}

//----------------------------------------------------------------------
//	PCSRegEx::Atom
//	�p�^�[������m�[�h���쐬����B
//	�������̃`�F�b�N�͍s��Ȃ��̂ŁA�Ăяo�����Ŋm�F���Ă������ƁB
//----------------------------------------------------------------------
PCRegExNode* CLASS_SREGEX::Atom()
{
	int				iToken, iToken2;
	int				iIndex, iType;
	LPVOID			pOptional[PREGEX_OPTIONALDATA_NUM]	= {0, 0};
	CNODE*			pciNode	= NULL; 
	T_UCP			cpSrc;
	CNSTATE*		pNState;
	CSREGEX*		pSRegEx;
	CSREGEXNFA*		pSRegExNFA;
	CBRACKETEX*		pBracketEx;
	ITR_UCPSTRING	itrPat1, itrPat2;
	UCPSTRING		ucsName;
	UCPSTRING*		pucsName;
	int				iTemp1, iTemp2;
	DWORD			dwOptOn, dwOptOff;
	DWORD			dwFlags		= 0;
	DWORD			dwFlagsC	= 0;
	T_PCSTR_U		pszLocale	= NULL;
	bool			bNormalize	= false;
	bool			bLegible	= false;
	T_STRING		strTemp;
	bool			bNegative	= false;
	bool			br;

	dwFlags		= (pciBaseRegEx->Options())->GetCompareStringUCDFlags();
	pszLocale	= (pciBaseRegEx->Options())->GetLocaleString();
	bLegible	= (pciBaseRegEx->Options())->IsLegiblePattern();
	dwFlagsC	= dwFlags;
	COMPARESTRING_UNSET_NORM_IGNORECASE(dwFlagsC);
	COMPARESTRING_UNSET_LINGUISTIC_IGNORECASE(dwFlagsC);

	if (pciBaseRegEx->Options()->IsNormIgnoreWidth()		||
		pciBaseRegEx->Options()->IsNormIgnoreNonSpace()	||
		pciBaseRegEx->Options()->IsNormalize())
	{
		bNormalize = true;
	}

PARSE_ATOM:
	//------------------------------------------------------------
	//	Lesible ���ݒ肳��Ă���ꍇ�̑O����
	//	�󔒂͓ǂݔ�΂��B
	//	# �͉��s�܂œǂݔ�΂��B
	//------------------------------------------------------------
	if (bLegible)
	{
		pciPattern->SkipBlankAndComment();
	}

	iToken	= pciPattern->GetCurrentToken();

	//------------------------------------------------------------
	//
	//------------------------------------------------------------
	switch (iToken)
	{
	case PREGEX_TOKEN_ERROR:
		THROWPE_LOGIC_ERROR("PCSRegEx::Atom : Invalid pattern.");
		return NULL;
		break;

		//--------------------------------------------------
		//	EOL
		//	PREGEX_TOKEN_END �̏ꍇ Node �͍쐬����Ȃ��B
		//--------------------------------------------------
	case PREGEX_TOKEN_END:
		return NULL;
		break;

		//--------------------------------------------------
		//	CHAR, CR, LF
		//--------------------------------------------------
	case PREGEX_TOKEN_CODEPAGE:
	case PREGEX_TOKEN_CR:
	case PREGEX_TOKEN_LF:
		if (!PCTEXT_GETVALIDCP(pciPattern->GetCurrentCp(&cpSrc)))	THROWPE_LOGIC_ERROR("");
		pciNode	= CreateNode(PREGEX_NODE_ATOM_CHAR);
		pciNode->SetOptionalCp(cpSrc);
		break;

		//--------------------------------------------------
		//	\ �̏ꍇ�B
		//--------------------------------------------------
	case PREGEX_TOKEN_ESCAPE:
		iToken	= pciPattern->GetNextToken();
		if (iToken == PREGEX_TOKEN_ERROR)
		{
			THROWPE_SYNTAX_ERROR("PCSRegEx::Atom");
			return NULL;
		}
		//--------------------------------------------------
		//	\ ���Ō�̕����̏ꍇ�́A�������G�X�P�[�v���Ă���ƍl���A
		//	EOL �Ɠ��l�ɏ�������B�i���ۂɏI�[�ɐi�߂Ă����B�j
		//--------------------------------------------------
		if (iToken == PREGEX_TOKEN_END)
		{
			pciPattern->Next();
			return NULL;
		}

		//--------------------------------------------------
		//	\ �̎��̕����ɂ���Ĉȉ��̂悤�ɏ�������B
		//--------------------------------------------------
		pciPattern->Next();
		iToken2	= pciPattern->GetNextToken();
		cpSrc	= 0;
		pciPattern->GetCurrentCp(&cpSrc);

		//--------------------------------------------------
		//	\w	�P��Ɏg���镶��
		//--------------------------------------------------
		if (AtomMatchCp(cpSrc, TQ_UCP('w'), dwFlagsC, pszLocale))
		{
			pciNode	= CreateNode(PREGEX_NODE_ATOM_CHAR_WORD);
			break;
		}
		//--------------------------------------------------
		//	\d	����
		//--------------------------------------------------
		else if (AtomMatchCp(cpSrc, TQ_UCP('d'), dwFlagsC, pszLocale))
		{
			pciNode	= CreateNode(PREGEX_NODE_ATOM_CHAR_DIGIT);
			break;
		}
		//--------------------------------------------------
		//	\s	��
		//--------------------------------------------------
		else if (AtomMatchCp(cpSrc, TQ_UCP('s'), dwFlagsC, pszLocale))
		{
			pciNode	= CreateNode(PREGEX_NODE_ATOM_CHAR_SPACE);
			break;
		}
		//--------------------------------------------------
		//	\b �P��̋��E
		//--------------------------------------------------
		else if (AtomMatchCp(cpSrc, TQ_UCP('b'), dwFlagsC, pszLocale))
		{
			pciNode	= CreateNode(PREGEX_NODE_ATOM_WORD_BOUNDARY);
			break;
		}
		//--------------------------------------------------
		//	\W	\w �ȊO
		//--------------------------------------------------
		else if (AtomMatchCp(cpSrc, TQ_UCP('W'), dwFlagsC, pszLocale))
		{
			pciNode	= CreateNode(PREGEX_NODE_ATOM_CHAR_NON_WORD);
			break;
		}
		//--------------------------------------------------
		//	\D	\d �ȊO
		//--------------------------------------------------
		else if (AtomMatchCp(cpSrc, TQ_UCP('D'), dwFlagsC, pszLocale))
		{
			pciNode	= CreateNode(PREGEX_NODE_ATOM_CHAR_NON_DIGIT);
			break;
		}
		//--------------------------------------------------
		//	\S	\s �ȊO
		//--------------------------------------------------
		else if (AtomMatchCp(cpSrc, TQ_UCP('S'), dwFlagsC, pszLocale))
		{
			pciNode	= CreateNode(PREGEX_NODE_ATOM_CHAR_NON_SPACE);
			break;
		}
		//--------------------------------------------------
		//	\B	\b �ȊO�̋��E
		//--------------------------------------------------
		else if (AtomMatchCp(cpSrc, TQ_UCP('B'), dwFlagsC, pszLocale))
		{
			pciNode	= CreateNode(PREGEX_NODE_ATOM_NOT_WORD_BOUNDARY);
			break;
		}
		//--------------------------------------------------
		//	\A	������̐擪
		//--------------------------------------------------
		else if (AtomMatchCp(cpSrc, TQ_UCP('A'), dwFlagsC, pszLocale))
		{
			pciNode	= CreateNode(PREGEX_NODE_ATOM_START_SINGLE);
			break;
		}
		//--------------------------------------------------
		//	\z	������̖���
		//--------------------------------------------------
		else if (AtomMatchCp(cpSrc, TQ_UCP('z'), dwFlagsC, pszLocale))
		{
			pciNode	= CreateNode(PREGEX_NODE_ATOM_END_SINGLE);
			break;
		}
		//--------------------------------------------------
		//	\Z	������̖����i���s���Ō�̕����Ȃ炻�̑O�j
		//--------------------------------------------------
		else if (AtomMatchCp(cpSrc, TQ_UCP('Z'), dwFlagsC, pszLocale))
		{
			pciNode	= CreateNode(PREGEX_NODE_ATOM_ENDLF_SINGLE);
			break;
		}
		//--------------------------------------------------
		//	\G	���O�̃}�b�`���I�������ʒu
		//--------------------------------------------------
		else if (AtomMatchCp(cpSrc, TQ_UCP('G'), dwFlagsC, pszLocale))
		{
			pciNode	= CreateNode(PREGEX_NODE_ATOM_LAST_MATCH);
			break;
		}
		//--------------------------------------------------
		//	\k<> �܂��� \k''	���O�ɂ�����Q��
		//
		//	Type:	PREGEX_NODE_ATOM_BACKREF_BYNAME
		//	Opt0:	���O�̃|�C���^
		//--------------------------------------------------
		else if (AtomMatchCp(cpSrc, TQ_UCP('k'), dwFlagsC, pszLocale)	&&
			(iToken2 == PREGEX_TOKEN_LESSTHAN || iToken2 == PREGEX_TOKEN_APOSTROPHE))
		{
			pciPattern->Next();
			if (!pciPattern->Next() || pciPattern->End())
			{
				if (iToken2 == PREGEX_TOKEN_LESSTHAN)
					THROWPE_SYNTAX_ERROR("Not found >");
				else
					THROWPE_SYNTAX_ERROR("Not found '");
			}
			if (!pciPattern->GetCurrentPos(itrPat1))	THROWPE_LOGIC_ERROR("");
			iToken	= pciPattern->GetCurrentToken();

			if (iToken2 == PREGEX_TOKEN_LESSTHAN)
			{
				if (iToken == PREGEX_TOKEN_GREATERTHAN)
				{
					THROWPE_SYNTAX_ERROR("Not found >");
				}
				if(!pciPattern->MoveTo(PREGEX_TOKEN_GREATERTHAN))
				{
					THROWPE_SYNTAX_ERROR("Not found >");
				}
			}
			else
			{
				if (iToken == PREGEX_TOKEN_APOSTROPHE)
				{
					THROWPE_SYNTAX_ERROR("Not found '");
				}
				if(!pciPattern->MoveTo(PREGEX_TOKEN_APOSTROPHE))
				{
					THROWPE_SYNTAX_ERROR("Not found '");
				}
			}

			if (!pciPattern->GetCurrentPos(itrPat2))	THROWPE_LOGIC_ERROR("");

			if (!pciBaseRegEx->FindNamedSRegEx(&pucsName, itrPat1, itrPat2))
			{
				THROWPE_SYNTAX_ERROR("The name is not defined.");
			}
			pciNode	= CreateNode(PREGEX_NODE_ATOM_BACKREF_BYNAME);
			pciNode->SetOptionalName(pucsName);
			break;
		}
		//--------------------------------------------------
		//	\g	�C���f�b�N�X�ɂ�����Q��
		//
		//	Type:	PREGEX_NODE_ATOM_BACKREF
		//	Opt0:	SRegEx �̃C���f�b�N�X
		//--------------------------------------------------
		else if (AtomMatchCp(cpSrc, TQ_UCP('g'), dwFlagsC, pszLocale))
		{
			pciPattern->Next();
			if (!PCTextUR_GetInt(&iIndex, pciPattern, dwFlagsC, pszLocale))
			{
				THROWPE_SYNTAX_ERROR("Positive integer must follow to \\g.");
			}
			if (!pciBaseRegEx->GetSRegEx(&pSRegEx, iIndex))
			{
				THROWPE_SYNTAX_ERROR("Invalid group number.");
			}
			pciNode	= CreateNode(PREGEX_NODE_ATOM_BACKREF);
			pciNode->SetOptionalIndex(iIndex);
			//	�����ŌĂяo���Ă��� PCTextUR_GetInt() �͕����ʒu��i�߂Ȃ��B
			pciPattern->Next();
			return pciNode;
			break;
		}
		//--------------------------------------------------
		//	\p, \P	Unicode �̑����ɂ��ƍ�
		//--------------------------------------------------
		else if (AtomMatchCp(cpSrc, TQ_UCP('p'), dwFlags, pszLocale)	||
		 AtomMatchCp(cpSrc, TQ_UCP('P'), dwFlagsC, pszLocale))
		{
			if (!ParseUnicodePropertyMatching(&iTemp1, pciPattern, dwFlags, pszLocale))
			{
				THROWPE_SYNTAX_ERROR("Invalid unicode property.");
			}

			//	\P �̏ꍇ�� Negative �������t���O���Z�b�g����B
			if (AtomMatchCp(cpSrc, TQ_UCP('P'), dwFlagsC, pszLocale))
				SET_PTEXTEX_UNICODE_PROPERTY_NEGATIVE(iTemp1);

			pciNode	= CreateNode(PREGEX_NODE_ATOM_CHAR_UNICODE_PROPERTY);
			pciNode->SetOptionalInt(iTemp1);
			return pciNode;
			break;
		}

		//--------------------------------------------------
		//	\1 ���� \9	����Q��
		//--------------------------------------------------
		if (PLib::Unicode::IsDigit(&iIndex, cpSrc, bNormalize))
		{
			if (!pciBaseRegEx->GetSRegEx(&pSRegEx, iIndex))
			{
				THROWPE_SYNTAX_ERROR("Invalid group number.");
			}
			pciNode	= CreateNode(PREGEX_NODE_ATOM_BACKREF);
			pciNode->SetOptionalIndex(iIndex);
			break;
		}

		//--------------------------------------------------
		//	�ȏ�ɓ��Ă͂܂�Ȃ��ꍇ�́A���̕�����l�Ƃ��镶�� atom �ł���B
		//--------------------------------------------------
		pciNode	= CreateNode(PREGEX_NODE_ATOM_CHAR);
		pciNode->SetOptionalCp(cpSrc);
		break;

		//--------------------------------------------------
		//	.
		//--------------------------------------------------
	case PREGEX_TOKEN_PERIOD:
		pciNode	= CreateNode(PREGEX_NODE_ATOM_ANY_CHAR);
		break;

		//--------------------------------------------------
		//	^
		//--------------------------------------------------
	case PREGEX_TOKEN_CIRCUMFLEX:
		pciNode	= CreateNode(PREGEX_NODE_ATOM_START_MULTI);
		break;

		//--------------------------------------------------
		//	$
		//--------------------------------------------------
	case PREGEX_TOKEN_DOLLAR:
		pciNode	= CreateNode(PREGEX_NODE_ATOM_END_MULTI);
		break;

		//--------------------------------------------------
		//	(   )
		//	(?# )			�R�����g
		//	(?: )			�������K�\���i����Q�ƂŎg�p���Ȃ��j
		//	(?= )			�㑱����e�L�X�g���J�b�R���̐��K�\���Ƀ}�b�`����B�i���� 0�j
		//	(?! )			�㑱����e�L�X�g���J�b�R���̐��K�\���Ƀ}�b�`���Ȃ��B�i���� 0�j
		//	(?<= )			��s����e�L�X�g���J�b�R���̐��K�\���Ƀ}�b�`����B�i���� 0�j
		//	(?<! )			��s����e�L�X�g���J�b�R���̐��K�\���Ƀ}�b�`���Ȃ��B�i���� 0�j
		//	(?< > )			���O�t���������K�\���i����Q�Ɨp�j
		//	(?' ' )			���O�t���������K�\���i����Q�Ɨp�j
		//	(?imsx-imsx)	�I�v�V������ύX����
		//	(?imsx-imsx: )	�I�v�V�������ꎞ�I�ɕύX����
		//	(?(����) )
		//	(?(���O) )
		//	(?(?= )  )
		//	(?(?! )  )
		//	(?(?<= ) )
		//	(?(?<! ) )
		//--------------------------------------------------
	case PREGEX_TOKEN_LPARENTHESIS:
		pciPattern->Next();
		iToken	= pciPattern->GetCurrentToken();
		iToken2	= pciPattern->GetNextToken();

		//--------------------------------------------------
		//	(? �͎��̕����ɂ���āA�ȉ��̒ʂ�ɏ�������B
		//--------------------------------------------------
		if (iToken == PREGEX_TOKEN_QUESTION)
		{
			//----------------------------------------
			//	(?# �R�����g
			//	���̏ꍇ�A) �܂œǂݔ�΂��A���̈ʒu�����͂������B
			//----------------------------------------
			if (iToken2 == PREGEX_TOKEN_NUMBERSIGN)
			{
				//	(# �̏ꍇ�� ) �܂Łi�������̓e�L�X�g�I�[�܂Łj�i�߂�B
				if(!pciPattern->MoveTo(PREGEX_TOKEN_RPARENTHESIS))
				{
					THROWPE_SYNTAX_ERROR("No )");
				}
				pciPattern->Next();
				goto PARSE_ATOM;
			}
			//----------------------------------------
			//	(?: �������K�\���i����Q�Ƃł͎g�p���Ȃ��B�j
			//----------------------------------------
			else if (iToken2 == PREGEX_TOKEN_COLON)
			{
				pciPattern->Next();
				pciPattern->Next();
				pSRegEx	= pciBaseRegEx->CreateSRegEx(PREGEX_EX_TYPE_NCAP);
				pciNode	= CreateNode(PREGEX_NODE_ATOM_REGEX);
				pciNode->SetOptionalSRegEx(pSRegEx);
			}
			//----------------------------------------
			//	(?= �}�b�`����㑱�����i���� 0�j
			//----------------------------------------
			else if (iToken2 == PREGEX_TOKEN_EQUAL)
			{
				pciPattern->Next();
				pciPattern->Next();
				pSRegEx	= pciBaseRegEx->CreateSRegEx(PREGEX_EX_TYPE_POSITIVE_LOOKAHEAD);
				pSRegExNFA	= (pSRegEx->GetBase())->CreateSRegExNFA(pSRegEx);
				pSRegExNFA->BuildNFA();
				pNState	= pSRegExNFA->GetNFAStartState();
				pSRegEx->SetOptionalNState(pNState);

				pciNode	= CreateNode(PREGEX_NODE_ATOM_REGEX);
				pciNode->SetOptionalSRegEx(pSRegEx);
			}
			//----------------------------------------
			//	(?! �}�b�`���Ȃ��㑱�������K�\���i���� 0�j
			//----------------------------------------
			else if (iToken2 == PREGEX_TOKEN_EXCLAMATION)
			{
				pciPattern->Next();
				pciPattern->Next();
				pSRegEx	= pciBaseRegEx->CreateSRegEx(PREGEX_EX_TYPE_NEGATIVE_LOOKAHEAD);
				pSRegExNFA	= (pSRegEx->GetBase())->CreateSRegExNFA(pSRegEx);
				pSRegExNFA->BuildNFA();
				pNState	= pSRegExNFA->GetNFAStartState();
				pSRegEx->SetOptionalNState(pNState);

				pciNode	= CreateNode(PREGEX_NODE_ATOM_REGEX);
				pciNode->SetOptionalSRegEx(pSRegEx);
			}
			//----------------------------------------
			//	(?<	�͐�s�����Ɋւ��鐬�������A
			//	�������́A���O�t���������K�\��
			//----------------------------------------
			else if (iToken2 == PREGEX_TOKEN_LESSTHAN)
			{
				pciPattern->Next();
				//	Current �� <
				iToken2	= pciPattern->GetNextToken();
				//------------------------------
				//	(?<= �}�b�`�����s�����i���� 0�j
				//------------------------------
				if (iToken2 == PREGEX_TOKEN_EQUAL)
				{
					pciPattern->Next();
					pciPattern->Next();
					pSRegEx	= pciBaseRegEx->CreateSRegEx(PREGEX_EX_TYPE_POSITIVE_LOOKBEHIND);
					pSRegExNFA	= (pSRegEx->GetBase())->CreateSRegExNFA(pSRegEx);
					pSRegExNFA->BuildNFA();
					pNState	= pSRegExNFA->GetNFAStartState();
					pSRegEx->SetOptionalNState(pNState);

					(pSRegEx->GetRootNode())->Size(&iTemp1, &iTemp2);
					pNState->SetOptionalData(0, (LPVOID)iTemp1);
					pNState->SetOptionalData(1, (LPVOID)iTemp2);

					pciNode	= CreateNode(PREGEX_NODE_ATOM_REGEX);
					pciNode->SetOptionalSRegEx(pSRegEx);
				}
				//------------------------------
				//	(?<! �}�b�`���Ȃ���s�����i���� 0�j
				//------------------------------
				else if (iToken2 == PREGEX_TOKEN_EXCLAMATION)
				{
					pciPattern->Next();
					pciPattern->Next();
					pSRegEx	= pciBaseRegEx->CreateSRegEx(PREGEX_EX_TYPE_NEGATIVE_LOOKBEHIND);
					pSRegExNFA	= (pSRegEx->GetBase())->CreateSRegExNFA(pSRegEx);
					pSRegExNFA->BuildNFA();
					pNState	= pSRegExNFA->GetNFAStartState();
					pSRegEx->SetOptionalNState(pNState);

					(pSRegEx->GetRootNode())->Size(&iTemp1, &iTemp2);
					pNState->SetOptionalData(0, (LPVOID)iTemp1);
					pNState->SetOptionalData(1, (LPVOID)iTemp2);

					pciNode	= CreateNode(PREGEX_NODE_ATOM_REGEX);
					pciNode->SetOptionalSRegEx(pSRegEx);
				}
				//------------------------------
				//	�ȏ�ɓ��Ă͂܂�Ȃ��ꍇ�́A
				//	���O�t���������K�\���Ƃ��ĉ�͂���B
				//	> �܂ł𖼑O�Ƃ���B
				//
				//	Type:	PREGEX_NODE_ATOM_REGEX
				//	Opt0:	SRegEx �̃|�C���^
				//
				//	�쐬����� SRegEx �ɂ�����
				//	Type:	PREGEX_EX_TYPE_CAP_NAMED
				//	Opt0:	���O�̃|�C���^
				//------------------------------
				else
				{
					if (!pciPattern->Next() || pciPattern->End())
					{
						THROWPE_SYNTAX_ERROR("Not found >");
					}
					//	Current �� < �̎��̕���
					if (pciPattern->GetCurrentToken() == PREGEX_TOKEN_GREATERTHAN)
					{
						THROWPE_SYNTAX_ERROR("No name between < and >");
					}
					if (!pciPattern->GetCurrentPos(itrPat1))	THROWPE_LOGIC_ERROR("");
					if(!pciPattern->MoveTo(PREGEX_TOKEN_GREATERTHAN))
					{
						THROWPE_SYNTAX_ERROR("Not found >");
					}
					if (!pciPattern->GetCurrentPos(itrPat2))	THROWPE_LOGIC_ERROR("");
					pciPattern->Next();

					//	���O�t���� PCSRegEx ���쐬����B
					pSRegEx	= pciBaseRegEx->CreateNamedSRegEx(itrPat1, itrPat2, pciPattern);
					pciNode	= CreateNode(PREGEX_NODE_ATOM_REGEX);
					pciNode->SetOptionalSRegEx(pSRegEx);
				}
			}
			//----------------------------------------
			//	(?' �͖��O�t���������K�\���Ƃ��ĉ�͂���B
			//
			//	Type:	PREGEX_NODE_ATOM_REGEX
			//	Opt0:	SRegEx �̃|�C���^
			//
			//	�쐬����� SRegEx �ɂ�����
			//	Type:	PREGEX_EX_TYPE_CAP_NAMED
			//	Opt0:	���O�̃|�C���^
			//----------------------------------------
			else if (iToken2 == PREGEX_TOKEN_APOSTROPHE)
			{
				pciPattern->Next();
				if (!pciPattern->Next() || pciPattern->End())
				{
					THROWPE_SYNTAX_ERROR("Not found '");
				}
				//	Current �� ' �̎��̕����B
				if (pciPattern->GetCurrentToken() == PREGEX_TOKEN_APOSTROPHE)
				{
					THROWPE_SYNTAX_ERROR("No name between ' and '");
				}
				if (!pciPattern->GetCurrentPos(itrPat1))	THROWPE_LOGIC_ERROR("");
				if(!pciPattern->MoveTo(PREGEX_TOKEN_APOSTROPHE))
				{
					THROWPE_SYNTAX_ERROR("Not found '");
				}
				if (!pciPattern->GetCurrentPos(itrPat2))	THROWPE_LOGIC_ERROR("");
				pciPattern->Next();

				//	���O�t���� PCSRegEx ���쐬����B
				pSRegEx	= pciBaseRegEx->CreateNamedSRegEx(itrPat1, itrPat2, pciPattern);
				pciNode	= CreateNode(PREGEX_NODE_ATOM_REGEX);
				pciNode->SetOptionalSRegEx(pSRegEx);
			}
			//----------------------------------------
			//	(?( �͏��������\���B
			//----------------------------------------
			else if (iToken2 == PREGEX_TOKEN_LPARENTHESIS)
			{
				pciPattern->Next();
				pciPattern->Next();
				//	current �� (?( �̎��̕���
				iToken	= pciPattern->GetCurrentToken();
				iToken2	= pciPattern->GetNextToken();
				if (iToken2 == PREGEX_TOKEN_END)
				{
					THROWPE_SYNTAX_ERROR("Not found ) of (?(");
				}

				//------------------------------
				//	(?(?	��s�܂��͌㑱���镔�����K�\���ɂ��ƍ��̌��ʂŕ��򂷂�B
				//	�e����� branch �Ƃ��镔�����K�\�����쐬���Aatom node �Ƃ���B
				//	������������̕������K�\���� pOptional[0] �Ɋi�[����B
				//------------------------------
				if (iToken == PREGEX_TOKEN_QUESTION)
				{
					pciPattern->Next();
					//	current �� (?(? �̎��̕���
					iToken	= pciPattern->GetCurrentToken();
					iToken2	= pciPattern->GetNextToken();
					if (iToken2 == PREGEX_TOKEN_END)
					{
						THROWPE_SYNTAX_ERROR("Not found ) of (?(");
					}
					pciPattern->Next();

					//	(?(?=
					if (iToken == PREGEX_TOKEN_EQUAL)
					{
						iType	= PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKAHEAD;
						pOptional[0]	= (LPVOID)pciBaseRegEx->CreateSRegEx(
							PREGEX_EX_TYPE_POSITIVE_LOOKAHEAD);
					}
					//	(?(?!
					else if (iToken == PREGEX_TOKEN_EXCLAMATION)
					{
						iType	= PREGEX_EX_TYPE_CONDITIONAL_NEGATIVE_LOOKAHEAD;
						pOptional[0]	= (LPVOID)pciBaseRegEx->CreateSRegEx(
							PREGEX_EX_TYPE_NEGATIVE_LOOKAHEAD);
					}
					//	(?(?<=
					else if (iToken == PREGEX_TOKEN_LESSTHAN && iToken2 == PREGEX_TOKEN_EQUAL)
					{
						pciPattern->Next();
						iType	= PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKBEHIND;
						pOptional[0]	= (LPVOID)pciBaseRegEx->CreateSRegEx(
							PREGEX_EX_TYPE_POSITIVE_LOOKBEHIND);
					}
					//	(?(?<!
					else if (iToken == PREGEX_TOKEN_LESSTHAN && iToken2 == PREGEX_TOKEN_EXCLAMATION)
					{
						pciPattern->Next();
						iType	= PREGEX_EX_TYPE_CONDITIONAL_NEGATIVE_LOOKBEHIND;
						pOptional[0]	= (LPVOID)pciBaseRegEx->CreateSRegEx(
							PREGEX_EX_TYPE_NEGATIVE_LOOKBEHIND);
					}
					else
					{
						THROWPE_SYNTAX_ERROR("");
						return false;
					}
				}
				//------------------------------
				//	(?(< >) ) �̏ꍇ
				//	(?(' ') ) �̏ꍇ
				//
				//	Type:	PREGEX_NODE_ATOM_REGEX
				//	Opt0:	SRegEx �̃|�C���^
				//
				//	�쐬����� SRegEx �ɂ�����
				//	Type:	PREGEX_EX_TYPE_CONDITIONAL_NAME
				//	Opt0:	���O�̃|�C���^
				//------------------------------
				else if (iToken == PREGEX_TOKEN_LESSTHAN || iToken == PREGEX_TOKEN_APOSTROPHE)
				{
					pciPattern->Next();
					iToken2	= pciPattern->GetCurrentToken();
					if (!pciPattern->GetCurrentPos(itrPat1))	THROWPE_LOGIC_ERROR("");
					if (iToken == PREGEX_TOKEN_LESSTHAN)
					{
						if (iToken2 == PREGEX_TOKEN_GREATERTHAN)
						{
							THROWPE_SYNTAX_ERROR("No name");
						}
						if(!pciPattern->MoveTo(PREGEX_TOKEN_GREATERTHAN))
						{
							THROWPE_SYNTAX_ERROR("Not found >");
						}
					}
					else
					{
						if (iToken2 == PREGEX_TOKEN_APOSTROPHE)
						{
							THROWPE_SYNTAX_ERROR("No name.");
						}
						if(!pciPattern->MoveTo(PREGEX_TOKEN_APOSTROPHE))
						{
							THROWPE_SYNTAX_ERROR("Not found '");
						}
					}

					if (!pciPattern->GetCurrentPos(itrPat2))	THROWPE_LOGIC_ERROR("");

					if (!pciBaseRegEx->FindNamedSRegEx(&pucsName, itrPat1, itrPat2))
					{
						THROWPE_SYNTAX_ERROR("The name is not defined.");
					}

					iType	= PREGEX_EX_TYPE_CONDITIONAL_NAME;
					pOptional[0]	= (LPVOID)pucsName;
					pciPattern->Next();
				}
				//------------------------------
				//	�ȏ�ɓ��Ă͂܂�Ȃ��ꍇ�B
				//------------------------------
				else
				{
					//--------------------
					//	(?(�����l) �̏ꍇ
					//
					//	Type:	PREGEX_NODE_ATOM_REGEX
					//	Opt0:	SRegEx �̃|�C���^
					//
					//	�쐬����� SRegEx �ɂ�����
					//	Type:	PREGEX_EX_TYPE_CONDITIONAL_INDEX
					//	Opt0:	SRegEx �̃C���f�b�N�X
					//--------------------
					pciPattern->PushNewIterator();
					br	= PLib::PCTextUR_GetInt(&iIndex, pciPattern, dwFlags, pszLocale);
					iToken2	= pciPattern->GetNextToken();
					//	2013/06/13	13:03
					//if (br										&&
					//	iToken2 == PREGEX_TOKEN_RPARENTHESIS	&&
					//	pciBaseRegEx->GetSRegEx(&pSRegEx, iIndex))
					//	2013/06/13	13:03
					if (br && iToken2 == PREGEX_TOKEN_RPARENTHESIS)
					{
						pciPattern->PopAndUpdateIterator();
						iType	= PREGEX_EX_TYPE_CONDITIONAL_INDEX;
						pOptional[0]	= (LPVOID)iIndex;
						pciPattern->Next();
					}
					//--------------------
					//	�ȏ�ɓ��Ă͂܂�Ȃ��ꍇ�̓}�b�`����㑱���� ?= �Ƃ��ď�������B
					//	Microsoft �Ɠ��������ł���B
					//
					//	Type:	PREGEX_NODE_ATOM_REGEX
					//	Opt0:	SRegEx �̃|�C���^
					//
					//	�쐬����� SRegEx �ɂ�����
					//	Type:	PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKAHEAD
					//	Opt0:	SRegEx �̃|�C���^
					//--------------------
					else
					{
						pciPattern->PopIterator();
						iType	= PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKAHEAD;
						pOptional[0]	= (LPVOID)pciBaseRegEx->CreateSRegEx(
							PREGEX_EX_TYPE_POSITIVE_LOOKAHEAD);
					}
				}

				if (pciPattern->GetCurrentToken() != PREGEX_TOKEN_RPARENTHESIS)
				{
					THROWPE_SYNTAX_ERROR("Not found ).");
				}
				pciPattern->Next();

				//	��������o���������K�\�����쐬����B
				pSRegEx	= pciBaseRegEx->CreateSRegEx(iType, pOptional[0], pOptional[1]);
				pciNode	= CreateNode(PREGEX_NODE_ATOM_REGEX);
				pciNode->SetOptionalSRegEx(pSRegEx);
			}
			//----------------------------------------
			//	(?> �͓Ɨ������������K�\���ł���B
			//
			//	�\���؂����łȂ� NFA �܂ō쐬����B
			//----------------------------------------
			else if (iToken2 == PREGEX_TOKEN_GREATERTHAN)
			{
				pciPattern->Next();
				pciPattern->Next();
				pSRegEx	= pciBaseRegEx->CreateSRegEx(PREGEX_EX_TYPE_INDEPENDENT);
				pSRegExNFA	= (pSRegEx->GetBase())->CreateSRegExNFA(pSRegEx);
				pSRegExNFA->BuildNFA();

				pNState	= pSRegExNFA->GetNFAStartState();
				pSRegEx->SetOptionalNState(pNState);

				pciNode	= CreateNode(PREGEX_NODE_ATOM_REGEX);
				pciNode->SetOptionalSRegEx(pSRegEx);
			}
			//----------------------------------------
			//	�ȏ�ɓ��Ă͂܂�Ȃ��ꍇ�́A�I�v�V�����̕ύX�Ƃ��ĉ�͂���B
			//		(?�I�v�V����-�I�v�V����)	�܂���
			//		(?�I�v�V����-�I�v�V����:���K�\��)
			//	�̂����ꂩ�̌`���ɓ��Ă͂܂�Ȃ��ꍇ�́A
			//	SYNTAX_ERROR ��O���X���[����B
			//----------------------------------------
			else
			{
				//	���̎��_�ł� (? �� ? ���w���Ă���B
				pciPattern->Next();
				PRegExOptions_StrToDWord(&dwOptOn, &dwOptOff, pciPattern);
				iToken	= pciPattern->GetCurrentToken();
				switch (iToken)
				{
				case PREGEX_TOKEN_COLON:
					pciPattern->Next();
					pSRegEx	= pciBaseRegEx->CreateSRegEx(
						PREGEX_EX_TYPE_SETOPTIONS, (LPVOID)dwOptOn, (LPVOID)dwOptOff);
					pciNode	= CreateNode(PREGEX_NODE_ATOM_REGEX);
					pciNode->SetOptionalSRegEx(pSRegEx);
					break;

				case PREGEX_TOKEN_RPARENTHESIS:
					pSRegEx	= pciBaseRegEx->CreateSRegEx(
						PREGEX_EX_TYPE_CTRL_SETOPTIONS, (LPVOID)dwOptOn, (LPVOID)dwOptOff);
					pciNode	= CreateNode(PREGEX_NODE_ATOM_REGEX);
					pciNode->SetOptionalSRegEx(pSRegEx);
					pciBaseRegEx->SetOptions(dwOptOn, dwOptOff);
					break;

				default:
					THROWPE_SYNTAX_ERROR("");
					break;
				}
			}

			//	�e�����̏������I�������� ) �ŕ����Ă��Ȃ���΂Ȃ�Ȃ��B
			iToken	= pciPattern->GetCurrentToken();
			if (iToken != PREGEX_TOKEN_RPARENTHESIS)
			{
				THROWPE_SYNTAX_ERROR("");
			}
			break;
		}
		//--------------------------------------------------
		//	�ȏ�ɓ��Ă͂܂�Ȃ��ꍇ�́A����Q�Ɨp�̕������K�\���Ƃ��ď�������B
		//
		//	Type:	PREGEX_NODE_ATOM_REGEX
		//	Opt0:	SRegEx �̃|�C���^
		//
		//	�쐬����� SRegEx �ɂ�����
		//	Type:	PREGEX_EX_TYPE_CAP
		//	Opt0:	SRegEx �̃C���f�b�N�X
		//--------------------------------------------------
		else
		{
			pSRegEx	= pciBaseRegEx->CreateSRegEx(PREGEX_EX_TYPE_CAP);
			pciNode	= CreateNode(PREGEX_NODE_ATOM_REGEX);
			pciNode->SetOptionalSRegEx(pSRegEx);
		}

		//--------------------------------------------------
		//	) ���Ȃ��ꍇ�� Syntax Error ��O���X���[����
		//--------------------------------------------------
		if (pciPattern->GetCurrentToken() == PREGEX_TOKEN_RPARENTHESIS)
		{
			pciPattern->Next();
			return pciNode;
		}
		THROWPE_SYNTAX_ERROR("Nof found )");
		break;

		//--------------------------------------------------
		//	) |
		//--------------------------------------------------
	case PREGEX_TOKEN_RPARENTHESIS:
	case PREGEX_TOKEN_VERTICALBAR:
		//	) �͕������K�\���̏I�����������̂Ƃ��āAAtom() �ŏ��������B
		//	| �� Expression() �ŏ�������B�����ł͉������Ȃ��B
		pciNode	= NULL;
		return pciNode;
		break;

		//--------------------------------------------------
		//	[
		//--------------------------------------------------
	case PREGEX_TOKEN_LBRACKET:
		pciPattern->Next();
		pBracketEx	= pciBaseRegEx->CreateBracketEx();
		pBracketEx->Parse(pciPattern);
		pciNode	= CreateNode(PREGEX_NODE_ATOM_BRACKETEX);
		pciNode->SetOptionalData(0, (LPVOID)pBracketEx);
		return pciNode;
		break;

		//--------------------------------------------------
		//	) * + ? { }
		//--------------------------------------------------
	case PREGEX_TOKEN_ASTERISK:
	case PREGEX_TOKEN_PLUS:
	case PREGEX_TOKEN_QUESTION:
		//	�����͊e�v�f�̈ꕔ�Ƃ��ď��������B
		//	�����֗���̂́A���@�G���[�̏ꍇ�ł���B
		THROWPE_SYNTAX_ERROR("");
		return NULL;
		break;

		//--------------------------------------------------
		//	�ȏ�ɓ��Ă͂܂�Ȃ����������ꂽ�ꍇ�͒ʏ�̕����Ƃ��ď�������B
		//--------------------------------------------------
		//	] - : = {}
	//case PREGEX_TOKEN_RBRACKET:
	//case PREGEX_TOKEN_HYPHEN:
	//case PREGEX_TOKEN_COLON:
	//case PREGEX_TOKEN_EQUAL:
	//case PREGEX_TOKEN_LBRACE:
	//case PREGEX_TOKEN_RBRACE:
	default:
		pciNode	= CreateNode(PREGEX_NODE_ATOM_CHAR);
		if (!PCTEXT_GETVALIDCP(pciPattern->GetCurrentCp(&cpSrc)))	THROWPE_LOGIC_ERROR("");
		pciNode->SetOptionalCp(cpSrc);
		break;
	}
	pciPattern->Next();	//	���̃g�[�N����ǂݍ��ށB
	return pciNode;
}

//----------------------------------------------------------------------
//	PCSRegEx::Piece
//
//	piece = atom [ * | + | ? | bound ]
//	atom �� 0 ��ȏ�J��Ԃ�������
//----------------------------------------------------------------------
PCRegExNode* CLASS_SREGEX::Piece()
{
	CNODE*		pAtom	= NULL;
	CNODE*		pPiece	= NULL;
	int			iPieceType;
	int			iToken, iToken2;
	int			iMin, iMax;
	bool		bLegible	= false;
	DWORD		dwFlags		= 0;
	T_PCSTR_U	pszLocale	= NULL;

	dwFlags		= (pciBaseRegEx->Options())->GetCompareStringUCDFlags();
	pszLocale	= (pciBaseRegEx->Options())->GetLocaleString();

	iToken	= pciPattern->GetCurrentToken();
	if (iToken == PREGEX_TOKEN_ERROR)
	{
		THROWPE_LOGIC_ERROR("PCSRegEx::Piece : Invalid pattern.");
		return NULL;
	}
	pAtom	= Atom();	//	�G���[�����������ꍇ�͗�O���X���[�����B

	//	Node ���쐬����Ȃ������ꍇ�iEOL �� ) �̏ꍇ�����j�B
	if (pAtom == NULL)
	{
		return NULL;
	}
	//	�R�����g��ǂݔ�΂��Bx �I�v�V�������w�肳��Ă���ꍇ�͋󔒂��ǂݔ�΂��B
	//pciPattern->SkipCommentGroup();
	if ((pciBaseRegEx->Options())->IsLegiblePattern())
	{
		pciPattern->SkipBlankAndComment();
	}

	iToken	= pciPattern->GetCurrentToken();

	//------------------------------------------------------------
	//	�J��Ԃ��w�肪�Ȃ��ꍇ
	//------------------------------------------------------------
	if (iToken != PREGEX_TOKEN_ASTERISK	&&
		iToken != PREGEX_TOKEN_PLUS		&&
		iToken != PREGEX_TOKEN_QUESTION	&&
		iToken != PREGEX_TOKEN_LBRACE)
	{
		iPieceType = PREGEX_NODE_PIECE_ONE_ATOM;
	}
	//------------------------------------------------------------
	//	�J��Ԃ��w�肪����ꍇ
	//------------------------------------------------------------
	else
	{
		if (!PREGEX_NODE_IS_ATOM(pAtom->GetNodeType()))
		{
			THROWPE_SYNTAX_ERROR("PCSRegEx::Piece : Invalid node.");
		}
		iToken2	= pciPattern->GetNextToken();

		//--------------------------------------------------
		//	*, *?
		//--------------------------------------------------
		if (iToken == PREGEX_TOKEN_ASTERISK)
		{
			if (iToken2 == PREGEX_TOKEN_QUESTION)
			{
				iPieceType = PREGEX_NODE_PIECE_ZERO_OR_MORE_NG;
				pciPattern->Next();
			}
			else
			{
				iPieceType	= PREGEX_NODE_PIECE_ZERO_OR_MORE;
			}
			pciPattern->Next();
		}
		//--------------------------------------------------
		//	+. +?
		//--------------------------------------------------
		else if (iToken == PREGEX_TOKEN_PLUS)
		{
			if (iToken2 == PREGEX_TOKEN_QUESTION)
			{
				iPieceType	= PREGEX_NODE_PIECE_ONE_OR_MORE_NG;
				pciPattern->Next();
			}
			else
			{
				iPieceType	= PREGEX_NODE_PIECE_ONE_OR_MORE;
			}
			pciPattern->Next();
		}
		//--------------------------------------------------
		//	?, ??
		//--------------------------------------------------
		else if (iToken == PREGEX_TOKEN_QUESTION)
		{
			if (iToken2 == PREGEX_TOKEN_QUESTION)
			{
				iPieceType	= PREGEX_NODE_PIECE_ZERO_OR_ONE_NG;
				pciPattern->Next();
			}
			else
			{
				iPieceType	= PREGEX_NODE_PIECE_ZERO_OR_ONE;
			}
			pciPattern->Next();
		}
		//--------------------------------------------------
		//	{ , }
		//--------------------------------------------------
		else if (iToken == PREGEX_TOKEN_LBRACE)
		{
			//	�{���󔒂͂Ȃ��͂������A�O�̂��ߓǂݔ�΂��悤�ɂ��Ă����B
			pciPattern->Next();
			PCTextUR_SkipSpace(pciPattern);

			//	�����̒l���擾����B
			if (!PCTextUR_GetInt(&iMin, -1, pciPattern, dwFlags, pszLocale))
			{
				iMin	= 0;
			}
			NS_PLIB::PCTextUR_SkipSpace(pciPattern);
			iToken	= pciPattern->GetCurrentToken();

			//	���̕����� } �� , �łȂ���΂Ȃ�Ȃ��B�����łȂ��ꍇ�͗�O���X���[����B
			if (iToken != PREGEX_TOKEN_RBRACE && iToken != PREGEX_TOKEN_COMMA)
			{
				THROWPE_SYNTAX_ERROR("");
			}

			//	���̕����� } �̏ꍇ�A����̒l�͉����Ɠ������̂Ƃ���B
			if (iToken == PREGEX_TOKEN_RBRACE)
			{
				iMax	= iMin;
				pciPattern->Next();
				goto BOUND_SET;
			}

			//	�ȉ��� { , �̏ꍇ�ł���B
			pciPattern->Next();
			PCTextUR_SkipSpace(pciPattern);
			iToken	= pciPattern->GetCurrentToken();

			//	,} �̌`���̏ꍇ�A����ɕ��̒l���Z�b�g���Ă����B
			if (iToken == PREGEX_TOKEN_RBRACE)
			{
				iMax	= -1;
				pciPattern->Next();
				goto BOUND_SET;
			}

			//	����̒l���擾����B
			if (!PCTextUR_GetInt(&iMax, -1, pciPattern, dwFlags, pszLocale))
			{
				THROWPE_SYNTAX_ERROR("PCSRegEx::Piece : Invalid upper bound.");
				return NULL;
			}

			//	�Ō�� } ���Ȃ��ꍇ�̓G���[�Ƃ���B
			PCTextUR_SkipSpace(pciPattern);
			if (pciPattern->GetCurrentToken() == PREGEX_TOKEN_RBRACE)
			{
				pciPattern->Next();
				goto BOUND_SET;
			}
			else
			{
				THROWPE_SYNTAX_ERROR("No } of {,}.");
			}

BOUND_SET:
			if ((iMax >= 0 && iMin > iMax) || iMin > PREGEX_BOUND_MAX)
			{
				THROWPE_SYNTAX_ERROR("{,} has invalid values.");
				return NULL;
			}
			if (iMax > PREGEX_BOUND_MAX)	iMax = PREGEX_BOUND_MAX;

			if (pciPattern->GetCurrentToken() == PREGEX_TOKEN_QUESTION)
			{
				iPieceType	= PREGEX_NODE_PIECE_BOUND_NG;
				pciPattern->Next();
			}
			else
			{
				iPieceType	= PREGEX_NODE_PIECE_BOUND;
			}
		}
		//--------------------------------------------------
		//
		//--------------------------------------------------
		else
		{
			//	�����ւ͗��Ȃ��B
		}
	}

	pPiece	= CreateNode(iPieceType);
	pPiece->AppendNode(pAtom);
	if (iPieceType == PREGEX_NODE_PIECE_BOUND || iPieceType == PREGEX_NODE_PIECE_BOUND_NG)
	{
		pPiece->SetBoundMax(iMax);
		pPiece->SetBoundMin(iMin);
	}

	return pPiece;
}

//----------------------------------------------------------------------
//	PCSRegEx::Branch
//
//	regular branch = piece [ piece ]
//	atom �������͂��̌J��Ԃ��w��Ƃ݂Ȃ��Ȃ����̂����ꂽ��I������B
//----------------------------------------------------------------------
PCRegExNode* CLASS_SREGEX::Branch()
{
	CNODE*	pPiece		= NULL;
	CNODE*	pBranch	= NULL;
	int		iToken;

	iToken	= pciPattern->GetCurrentToken();
	if (iToken == PREGEX_TOKEN_ERROR || iToken == PREGEX_TOKEN_END)
	{
		//THROWPE_SYNTAX_ERROR("PCSRegEx::Branch : Invalid pattern.");
		return NULL;
	}

	pPiece	= Piece();	//	�G���[�̏ꍇ�͗�O���X���[�����B
	//	���Ȃ��Ƃ� 1 �� Piece ���Ȃ���΂Ȃ�Ȃ��B
	if (pPiece == NULL)
	{
		return NULL;
	}

	pBranch	= CreateNode(PREGEX_NODE_BRANCH);
	pBranch->AppendNode(pPiece);

	while (true)
	{
		pPiece	= Piece();
		if (pPiece == NULL)	break;
		pBranch->AppendNode(pPiece);
	}

	return pBranch;
}

//----------------------------------------------------------------------
//	PCSRegEx::Expression
//
//	regular expression = branch [ '|' branch ]
//----------------------------------------------------------------------
PCRegExNode* CLASS_SREGEX::Expression()
{
	CNODE*	pBranch		= NULL;
	CNODE*	pExpression	= NULL;
	int		iToken;

	iToken = pciPattern->GetCurrentToken();
	if (iToken == PREGEX_TOKEN_ERROR)
	{
		THROWPE_SYNTAX_ERROR("PCSRegEx::Expression : Invalid pattern.");
		return NULL;
	}

	if (iToken == PREGEX_TOKEN_END)
	{
		return CreateNode(PREGEX_NODE_EXPRESSION_EMPTY);
	}

	//	Expression �m�[�h���쐬���Ă����B
	pExpression	= CreateNode(PREGEX_NODE_EXPRESSION);

	//	Branch �m�[�h���擾����B
	pBranch	= Branch();	//	�G���[������Η�O���X���[�����B
	//	Node ���쐬����Ȃ������ꍇ�͋�� branch �m�[�h���쐬����B
	if (pBranch == NULL)
	{
		pBranch	= CreateNode(PREGEX_NODE_EXPRESSION_EMPTY);
	}
	pExpression->AppendNode(pBranch);

	if ((pciBaseRegEx->Options())->IsLegiblePattern())
	{
		pciPattern->SkipBlankAndComment();
	}

	while ((iToken = pciPattern->GetCurrentToken()) == PREGEX_TOKEN_VERTICALBAR)
	{
		pciPattern->Next();
		pBranch	= Branch();
		if (pBranch == NULL)
		{
			pBranch	= CreateNode(PREGEX_NODE_BRANCH_EMPTY);
		}
		pExpression->AppendNode(pBranch);
		if ((pciBaseRegEx->Options())->IsLegiblePattern())
		{
			pciPattern->SkipBlankAndComment();
		}
	}

	//	Expression ���I������̂� EOL �� ) �����ꂽ�ꍇ�ł���B
	if (iToken != PREGEX_TOKEN_END && iToken != PREGEX_TOKEN_RPARENTHESIS)
	{
		THROWPE_SYNTAX_ERROR("PCSRegEx::Expression : Unfinished.");
		return NULL;
	}

	return pExpression;
}

//----------------------------------------------------------------------
//	PCSRegEx::Parse
//----------------------------------------------------------------------
void CLASS_SREGEX::Parse()
{
	if (pciBaseRegEx == NULL)
	{
		THROWPE_LOGIC_ERROR("PCSRegEx::Parse : Null base.");
	}
	pciBaseRegEx->PushNewOptions();
	if (iType == PREGEX_EX_TYPE_SETOPTIONS)
	{
		pciBaseRegEx->SetOptions((DWORD)GetOptionalData(0), (DWORD)GetOptionalData(1));
	}
	pciRootNode	= Expression();
	pciBaseRegEx->PopOptions();
}


//======================================================================
//	class PCSRegExNFA
//======================================================================
//----------------------------------------------------------------------
//	PCSRegExNFA	�R���X�g���N�^
//----------------------------------------------------------------------
CLASS_PREGEX_SREGEXDFA::PCSRegExNFA()
:	pciBaseRegEx(NULL),
	pciSRegEx(NULL),
	pciNFAStartState(NULL),
	pciNFAEndState(NULL),
	iNFAStartIndex(PREGEX_INVALID_INDEX),
	iNFAEndIndex(PREGEX_INVALID_INDEX)
{
}

//----------------------------------------------------------------------
//	PCSRegExNFA::Clear
//----------------------------------------------------------------------
void CLASS_PREGEX_SREGEXDFA::Clear()
{
	//pciBaseRegEx		= NULL;
	pciSRegEx			= NULL;
	pciNFAStartState	= NULL;
	pciNFAEndState		= NULL;
	iNFAStartIndex		= PREGEX_INVALID_INDEX;
	iNFAEndIndex		= PREGEX_INVALID_INDEX;
}

//----------------------------------------------------------------------
//	PCSRegExNFA::Init
//----------------------------------------------------------------------
bool CLASS_PREGEX_SREGEXDFA::Init()
{
	pciNFAStartState	= NULL;
	pciNFAEndState		= NULL;
	iNFAStartIndex		= PREGEX_INVALID_INDEX;
	iNFAEndIndex		= PREGEX_INVALID_INDEX;
	return true;
}

//----------------------------------------------------------------------
//	PCSRegExNFA::SetSRegEx
//----------------------------------------------------------------------
void CLASS_PREGEX_SREGEXDFA::SetSRegEx(CSREGEX* p)
{
	pciSRegEx = p;
	if (pciSRegEx != NULL)
	{
		pciBaseRegEx = pciSRegEx->GetBase();
	}
}

//----------------------------------------------------------------------
//	PCSRegExNFA::BuildNFA	(1)
//	�񌈒萫�I�[�g�}�g���̏�� iNDSrcState ���� iNDDstState �ւ̑J�ڂ�
//	iNode �̐��������ɍ��킹�č쐬����B
//----------------------------------------------------------------------
void CLASS_PREGEX_SREGEXDFA::BuildNFA(CNODE*		pNode,
									   CNSTATE*	pNDSrcState,
									   CNSTATE*	pNDDstState)
{
	CSREGEX*		pSRegEx			= NULL;
	CSREGEX*		pSRegExCond		= NULL;
	CSREGEXNFA*		pSRegExNFA		= NULL;
	CNODE*			pNdTemp			= NULL;
	CNSTATE*		pStTemp1		= NULL;
	CNSTATE*		pStTemp2		= NULL;
	T_INDEX			iStTemp1, iStTemp2;
	PCNTRANSITION	pTrTemp			= NULL;
	CNODELIST*		pNodeList		= NULL;
	ITR_NODELIST	itr_nl;
	RIT_NODELIST	rit_nl;
	int				iMin, iMax;
	int				i;

	if (pNode == NULL)
	{
		THROWPE_LOGIC_ERROR("PCSRegEx::BuildNFA Invalid Node Index.");
	}

	switch (pNode->GetNodeType())
	{
	case PREGEX_NODE_ERROR:
		THROWPE_LOGIC_ERROR("PCSRegEx::BuildNFA Invalid Node Type.");
		break;

	case PREGEX_NODE_ATOM_CHAR:
		pNDSrcState->AppendTransition(pNDDstState,
			PREGEX_TRANSITION_MATCH_CHAR, pNode->GetOptionalData(0));
		break;

	case PREGEX_NODE_ATOM_ANY_CHAR:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_ANY_CHAR);
		break;

	case PREGEX_NODE_ATOM_CHAR_UNICODE_PROPERTY:
		pNDSrcState->AppendTransition(pNDDstState,
			PREGEX_TRANSITION_MATCH_UNICODE_PROPERTY, pNode->GetOptionalData(0));
		break;

	case PREGEX_NODE_ATOM_CHAR_DIGIT:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_CHAR_DIGIT);
		break;

	case PREGEX_NODE_ATOM_CHAR_NON_DIGIT:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_CHAR_NON_DIGIT);
		break;

	case PREGEX_NODE_ATOM_CHAR_WORD:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_CHAR_WORD);
		break;

	case PREGEX_NODE_ATOM_CHAR_NON_WORD:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_CHAR_NON_WORD);
		break;

	case PREGEX_NODE_ATOM_CHAR_SPACE:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_CHAR_SPACE);
		break;

	case PREGEX_NODE_ATOM_CHAR_NON_SPACE:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_CHAR_NON_SPACE);
		break;

	case PREGEX_NODE_ATOM_WORD_BOUNDARY:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_WORD_BOUNDARY);
		break;

	case PREGEX_NODE_ATOM_NOT_WORD_BOUNDARY:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_NOT_WORD_BOUNDARY);
		break;

	case PREGEX_NODE_ATOM_LAST_MATCH:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_LAST_MATCH);
		break;

	case PREGEX_NODE_ATOM_START_MULTI:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_START_MULTI);
		break;

	case PREGEX_NODE_ATOM_END_MULTI:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_END_MULTI);
		break;

	case PREGEX_NODE_ATOM_START_SINGLE:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_START_SINGLE);
		break;

	case PREGEX_NODE_ATOM_END_SINGLE:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_END_SINGLE);
		break;

	case PREGEX_NODE_ATOM_ENDLF_SINGLE:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_ENDLF_SINGLE);
		break;

	case PREGEX_NODE_ATOM_BRACKETEX:
		pNDSrcState->AppendTransition(pNDDstState,
			PREGEX_TRANSITION_MATCH_BRACKETEX, pNode->GetOptionalData(0));
		break;

	case PREGEX_NODE_ATOM_REGEX:
		if ((pSRegEx = pNode->GetOptionalSRegEx()) == NULL)
			THROWPE_LOGIC_ERROR("PCSRegEx::BuildNFA : Invalid SRegEx address.");
		switch (pSRegEx->GetType())
		{
		case PREGEX_EX_TYPE_CAP:
		case PREGEX_EX_TYPE_CAP_NAMED:
		case PREGEX_EX_TYPE_NCAP:
		case PREGEX_EX_TYPE_SETOPTIONS:
			pciBaseRegEx->CreateNState(&iStTemp1, &pStTemp1);
			pciBaseRegEx->CreateNState(&iStTemp2, &pStTemp2);
			pNDSrcState->AppendTransition(pStTemp1, PREGEX_TRANSITION_MATCH_EPSILON);
			BuildNFA(pSRegEx->GetRootNode(), pStTemp1, pStTemp2);
			pStTemp2->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
			switch (pSRegEx->GetType())
			{
			case PREGEX_EX_TYPE_CAP:
				pStTemp1->SetType(PREGEX_NSTATE_TYPE_EX_CAP_BEGIN);
				pStTemp2->SetType(PREGEX_NSTATE_TYPE_EX_CAP_END);
				pStTemp1->SetOptionalIndex(pSRegEx->GetOptionalIndex());
				pStTemp2->SetOptionalIndex(pSRegEx->GetOptionalIndex());
				break;

			case PREGEX_EX_TYPE_CAP_NAMED:
				pStTemp1->SetType(PREGEX_NSTATE_TYPE_EX_CAP_NAMED_BEGIN);
				pStTemp2->SetType(PREGEX_NSTATE_TYPE_EX_CAP_NAMED_END);
				pStTemp1->SetOptionalName(pSRegEx->GetOptionalName());
				pStTemp2->SetOptionalName(pSRegEx->GetOptionalName());
				break;

			case PREGEX_EX_TYPE_NCAP:
				pStTemp1->SetType(PREGEX_NSTATE_TYPE_EX_NCAP_BEGIN);
				pStTemp2->SetType(PREGEX_NSTATE_TYPE_EX_NCAP_END);
				break;

			case PREGEX_EX_TYPE_SETOPTIONS:
				pStTemp1->SetType(PREGEX_NSTATE_TYPE_EX_SETOPTIONS_BEGIN);
				pStTemp1->SetOptionalData(0, pSRegEx->GetOptionalData(0));
				pStTemp1->SetOptionalData(1, pSRegEx->GetOptionalData(1));
				pStTemp2->SetType(PREGEX_NSTATE_TYPE_EX_SETOPTIONS_END);
				break;
			}
			break;

		case PREGEX_EX_TYPE_POSITIVE_LOOKAHEAD:
		case PREGEX_EX_TYPE_NEGATIVE_LOOKAHEAD:
		case PREGEX_EX_TYPE_POSITIVE_LOOKBEHIND:
		case PREGEX_EX_TYPE_NEGATIVE_LOOKBEHIND:
		case PREGEX_EX_TYPE_INDEPENDENT:
			pStTemp1	= pSRegEx->GetOptionalNState();
			if (pStTemp1 == NULL)
			{
				THROWPE_LOGIC_ERROR("PCSRegExNFA::BuildNFA : Failed to build sub NFA.");
			}
			switch (pSRegEx->GetType())
			{
			case PREGEX_EX_TYPE_POSITIVE_LOOKAHEAD:
				pNDSrcState->AppendTransition(pNDDstState,
					PREGEX_TRANSITION_MATCH_EX_POSITIVE_LOOKAHEAD, (LPVOID)pStTemp1);
				break;

			case PREGEX_EX_TYPE_NEGATIVE_LOOKAHEAD:
				pNDSrcState->AppendTransition(pNDDstState,
					PREGEX_TRANSITION_MATCH_EX_NEGATIVE_LOOKAHEAD, (LPVOID)pStTemp1);
				break;

			case PREGEX_EX_TYPE_POSITIVE_LOOKBEHIND:
				pNDSrcState->AppendTransition(pNDDstState,
					PREGEX_TRANSITION_MATCH_EX_POSITIVE_LOOKBEHIND, (LPVOID)pStTemp1);
				break;

			case PREGEX_EX_TYPE_NEGATIVE_LOOKBEHIND:
				pNDSrcState->AppendTransition(pNDDstState,
					PREGEX_TRANSITION_MATCH_EX_NEGATIVE_LOOKBEHIND, (LPVOID)pStTemp1);
				break;

			case PREGEX_EX_TYPE_INDEPENDENT:
				pNDSrcState->AppendTransition(pNDDstState,
					PREGEX_TRANSITION_MATCH_EX_INDEPENDENT, (LPVOID)pStTemp1);
				break;

			default:
				break;
			}
			break;

		case PREGEX_EX_TYPE_CTRL_SETOPTIONS:
			pciBaseRegEx->CreateNState(&iStTemp1, &pStTemp1, PREGEX_NSTATE_TYPE_CTRL_SETOPTIONS);
			pNDSrcState->AppendTransition(pStTemp1, PREGEX_TRANSITION_MATCH_EPSILON);
			pStTemp1->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
			pStTemp1->SetOptionalData(0, pSRegEx->GetOptionalData(0));
			pStTemp1->SetOptionalData(1, pSRegEx->GetOptionalData(1));
			break;

		case PREGEX_EX_TYPE_CONDITIONAL_INDEX:
		case PREGEX_EX_TYPE_CONDITIONAL_NAME:
		case PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKAHEAD:
		case PREGEX_EX_TYPE_CONDITIONAL_NEGATIVE_LOOKAHEAD:
		case PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKBEHIND:
		case PREGEX_EX_TYPE_CONDITIONAL_NEGATIVE_LOOKBEHIND:
			//	pStTemp1 �� pNDDstState �Ԃ� pSRegEx ���g���Ċe����łȂ��B
			pciBaseRegEx->CreateNState(&iStTemp1, &pStTemp1);
			pNDSrcState->AppendTransition(pStTemp1, PREGEX_TRANSITION_MATCH_EPSILON);
			pStTemp1->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
			BuildNFA(pSRegEx->GetRootNode(), pStTemp1, pNDDstState);

			//	pStTemp1 �ɕ���̐ݒ������B
			switch (pSRegEx->GetType())
			{
			case PREGEX_EX_TYPE_CONDITIONAL_INDEX:
				pStTemp1->SetType(PREGEX_NSTATE_TYPE_EX_CONDITIONAL_INDEX);
				pStTemp1->SetOptionalIndex(pSRegEx->GetOptionalIndex());
				break;

			case PREGEX_EX_TYPE_CONDITIONAL_NAME:
				pStTemp1->SetType(PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NAME);
				pStTemp1->SetOptionalName(pSRegEx->GetOptionalName());
				break;

			case PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKAHEAD:
			case PREGEX_EX_TYPE_CONDITIONAL_NEGATIVE_LOOKAHEAD:
			case PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKBEHIND:
			case PREGEX_EX_TYPE_CONDITIONAL_NEGATIVE_LOOKBEHIND:
				pSRegExCond	= (CSREGEX*)pSRegEx->GetOptionalData(0);
				pSRegExNFA	= (pSRegEx->GetBase())->CreateSRegExNFA(pSRegExCond);
				pSRegExNFA->BuildNFA();
				pStTemp2	= pSRegExNFA->GetNFAStartState();
				pStTemp1->SetOptionalData(0, (LPVOID)pStTemp2);
				switch (pSRegEx->GetType())
				{
				case PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKAHEAD:
					pStTemp1->SetType(PREGEX_NSTATE_TYPE_EX_CONDITIONAL_POSITIVE_LOOKAHEAD);
					break;

				case PREGEX_EX_TYPE_CONDITIONAL_NEGATIVE_LOOKAHEAD:
					pStTemp1->SetType(PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NEGATIVE_LOOKAHEAD);
					break;

				case PREGEX_EX_TYPE_CONDITIONAL_POSITIVE_LOOKBEHIND:
					pStTemp1->SetType(PREGEX_NSTATE_TYPE_EX_CONDITIONAL_POSITIVE_LOOKBEHIND);
					(pSRegExCond->GetRootNode())->Size(&iMin, &iMax);
					pStTemp2->SetOptionalData(0, (LPVOID)iMin);
					pStTemp2->SetOptionalData(1, (LPVOID)iMax);
					break;

				case PREGEX_EX_TYPE_CONDITIONAL_NEGATIVE_LOOKBEHIND:
					pStTemp1->SetType(PREGEX_NSTATE_TYPE_EX_CONDITIONAL_NEGATIVE_LOOKBEHIND);
					(pSRegExCond->GetRootNode())->Size(&iMin, &iMax);
					pStTemp2->SetOptionalData(0, (LPVOID)iMin);
					pStTemp2->SetOptionalData(1, (LPVOID)iMax);
					break;
				}
			}
			break;

		default:
			break;
		}
		break;

	case PREGEX_NODE_ATOM_BACKREF:
		pNDSrcState->AppendTransition(pNDDstState,
			PREGEX_TRANSITION_MATCH_BACKREF, pNode->GetOptionalData(0));
		break;

	case PREGEX_NODE_ATOM_BACKREF_BYNAME:
		pNDSrcState->AppendTransition(pNDDstState,
			PREGEX_TRANSITION_MATCH_BACKREF_BYNAME, pNode->GetOptionalData(0));
		break;

	case PREGEX_NODE_PIECE_ONE_ATOM:
		BuildNFA(pNode->GetFirstNode(), pNDSrcState, pNDDstState);
		break;

	case PREGEX_NODE_PIECE_ZERO_OR_MORE:
	case PREGEX_NODE_PIECE_ZERO_OR_MORE_NG:
		pciBaseRegEx->CreateNState(&iStTemp1, &pStTemp1, PREGEX_NSTATE_TYPE_NORMAL);
		pNDSrcState->AppendTransition(pStTemp1, PREGEX_TRANSITION_MATCH_EPSILON);
		//	�ƍ��̃`�F�b�N�� LIFO �ōs����B
		if (pNode->GetNodeType() == PREGEX_NODE_PIECE_ZERO_OR_MORE)
		{
			pStTemp1->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
			BuildNFA(pNode->GetFirstNode(), pStTemp1, pStTemp1);
		}
		else
		{
			BuildNFA(pNode->GetFirstNode(), pStTemp1, pStTemp1);
			pStTemp1->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
		}
		break;

	case PREGEX_NODE_PIECE_ONE_OR_MORE:
	case PREGEX_NODE_PIECE_ONE_OR_MORE_NG:
		pciBaseRegEx->CreateNState(&iStTemp1, &pStTemp1, PREGEX_NSTATE_TYPE_NORMAL);
		BuildNFA(pNode->GetFirstNode(), pNDSrcState, pStTemp1);
		//	�ƍ��̃`�F�b�N�� LIFO �ōs����B
		if (pNode->GetNodeType() == PREGEX_NODE_PIECE_ONE_OR_MORE)
		{
			pStTemp1->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
			BuildNFA(pNode->GetFirstNode(), pStTemp1, pStTemp1);
		}
		else
		{
			BuildNFA(pNode->GetFirstNode(), pStTemp1, pStTemp1);
			pStTemp1->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
		}
		break;

	case PREGEX_NODE_PIECE_ZERO_OR_ONE:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
		BuildNFA(pNode->GetFirstNode(), pNDSrcState, pNDDstState);
		break;

	case PREGEX_NODE_PIECE_ZERO_OR_ONE_NG:
		BuildNFA(pNode->GetFirstNode(), pNDSrcState, pNDDstState);
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
		break;

	case PREGEX_NODE_PIECE_BOUND:
	case PREGEX_NODE_PIECE_BOUND_NG:
		//	0 �񂩂�ŏ��J��Ԃ��������܂ŁB
		//	pSrcState �ł̑J�ڑI������������\�����Ȃ������߂� epsilon �J�ڂ�����B
		if (pNode->GetBoundMin() < 1)
		{
			pciBaseRegEx->CreateNState(&iStTemp1, &pStTemp1, PREGEX_NSTATE_TYPE_NORMAL);
			pNDSrcState->AppendTransition(pStTemp1, PREGEX_TRANSITION_MATCH_EPSILON);
		}
		else
		{
			pStTemp1	= pNDSrcState;
			for (i = 0; i < pNode->GetBoundMin(); ++i)
			{
				pciBaseRegEx->CreateNState(&iStTemp2, &pStTemp2, PREGEX_NSTATE_TYPE_NORMAL);
				BuildNFA(pNode->GetFirstNode(), pStTemp1, pStTemp2);
				pStTemp1	= pStTemp2;
			}
		}

		//	Max �ɕ��̒l���w�肳��Ă���ꍇ�͔C�Ӊ�̌J��Ԃ��Ƃ���B
		if (pNode->GetBoundMax() < 0)
		{
			if (pNode->GetNodeType() == PREGEX_NODE_PIECE_BOUND)
			{
				pStTemp1->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
				BuildNFA(pNode->GetFirstNode(), pStTemp1, pStTemp1);
			}
			else
			{
				BuildNFA(pNode->GetFirstNode(), pStTemp1, pStTemp1);
				pStTemp1->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
			}
		}
		else
		{
			for (i = pNode->GetBoundMin(); i < pNode->GetBoundMax(); ++i, pStTemp1 = pStTemp2)
			{
				pciBaseRegEx->CreateNState(&iStTemp2, &pStTemp2, PREGEX_NSTATE_TYPE_NORMAL);
				if (pNode->GetNodeType() == PREGEX_NODE_PIECE_BOUND)
				{
					pStTemp1->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
					BuildNFA(pNode->GetFirstNode(), pStTemp1, pStTemp2);
				}
				else
				{
					BuildNFA(pNode->GetFirstNode(), pStTemp1, pStTemp2);
					pStTemp1->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
				}
			}
			pStTemp1->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
		}
		break;

	case PREGEX_NODE_BRANCH:
		if ((pNodeList = pNode->GetNodeList()) == NULL || pNodeList->empty())
		{
			THROWPE_LOGIC_ERROR("PCSRegEx::BuildNFA Branch has no piece.");
			return;
		}
		itr_nl = pNodeList->begin();
		pStTemp1	= pNDSrcState;
		while (itr_nl != pNodeList->end())
		{
			pNdTemp	= *itr_nl;
			++itr_nl;
			if (itr_nl == pNodeList->end())
			{
				pStTemp2	= pNDDstState;
			}
			else
			{
				pciBaseRegEx->CreateNState(&iStTemp2, &pStTemp2);
			}
			BuildNFA(pNdTemp, pStTemp1, pStTemp2);
			pStTemp1	= pStTemp2;
		}
		break;

	case PREGEX_NODE_BRANCH_EMPTY:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
		break;

	case PREGEX_NODE_EXPRESSION:
		//	Branch ���Ȃ��ꍇ�͖������ňړ��ł���Ƃ���B
		if ((pNodeList = pNode->GetNodeList()) == NULL || pNodeList->empty())
		{
			pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
			return;
		}
		for (rit_nl = pNodeList->rbegin(); rit_nl != pNodeList->rend(); ++rit_nl)
		{
			BuildNFA(*rit_nl, pNDSrcState, pNDDstState);
		}
		break;

	case PREGEX_NODE_EXPRESSION_EMPTY:
		pNDSrcState->AppendTransition(pNDDstState, PREGEX_TRANSITION_MATCH_EPSILON);
		break;

	default:
		break;
	}
	return;
}

//----------------------------------------------------------------------
//	PCSRegExNFA::BuildNFA	(2)
//	�G���[�͗�O�Ƃ��ăX���[���APCRegEx �� BuildNFA �ŏ�������B
//----------------------------------------------------------------------
void CLASS_PREGEX_SREGEXDFA::BuildNFA()
{
	bool		bReverse	= false;
	T_STRING	strMessage;
	//LPVOID		pValue1, pValue2;
	UCPSTRING*	pSubStr;

#ifdef	PDEBUG
	T_STRING	strDebug;
#endif

	//	�������s�\���ȏꍇ�͗�O���X���[����B�B
	if (pciBaseRegEx == NULL || pciSRegEx->GetRootNode() == NULL)
	{
		THROWPE_LOGIC_ERROR("PCSRegEx::BuildNFA : Not ready.");
	}

#ifdef	PDEBUG
	strDebug.clear();
	Debug(&strDebug);
#endif

	//------------------------------------------------------------
	//	�I�[�g�}�g���̗��[�ƂȂ��Ԃ��쐬����B
	//------------------------------------------------------------
	(pciSRegEx->GetBase())->CreateNState(&iNFAStartIndex, &pciNFAStartState);
	(pciSRegEx->GetBase())->CreateNState(&iNFAEndIndex, &pciNFAEndState);
	pciNFAEndState->SetFinal();

	//------------------------------------------------------------
	//	�e�^�C�v�̑O�����ƌ㏈����ݒ肷��B
	//------------------------------------------------------------
	switch (pciSRegEx->GetType())
	{
	case PREGEX_EX_TYPE_CAP:
		pciNFAStartState->SetType(PREGEX_NSTATE_TYPE_EX_CAP_BEGIN);
		pciNFAStartState->SetOptionalIndex(pciSRegEx->GetOptionalIndex());
		pciNFAEndState->SetType(PREGEX_NSTATE_TYPE_EX_CAP_END);
		pciNFAEndState->SetOptionalIndex(pciSRegEx->GetOptionalIndex());
		break;

	case PREGEX_EX_TYPE_CAP_NAMED:
		pSubStr	= pciSRegEx->GetOptionalName();
		pciNFAStartState->SetType(PREGEX_NSTATE_TYPE_EX_CAP_NAMED_BEGIN);
		pciNFAStartState->SetOptionalName(pciSRegEx->GetOptionalName());
		pciNFAEndState->SetType(PREGEX_NSTATE_TYPE_EX_CAP_NAMED_END);
		pciNFAEndState->SetOptionalName(pciSRegEx->GetOptionalName());
		break;

	case PREGEX_EX_TYPE_NCAP:
		pciNFAStartState->SetType(PREGEX_NSTATE_TYPE_EX_NCAP_BEGIN);
		pciNFAEndState->SetType(PREGEX_NSTATE_TYPE_EX_NCAP_END);
		break;

	case PREGEX_EX_TYPE_POSITIVE_LOOKAHEAD:
		pciNFAStartState->SetType(PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKAHEAD_BEGIN);
		pciNFAEndState->SetType(PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKAHEAD_END);
		break;

	case PREGEX_EX_TYPE_NEGATIVE_LOOKAHEAD:
		pciNFAStartState->SetType(PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKAHEAD_BEGIN);
		pciNFAEndState->SetType(PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKAHEAD_END);
		break;


	case PREGEX_EX_TYPE_POSITIVE_LOOKBEHIND:
		pciNFAStartState->SetType(PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKBEHIND_BEGIN);
		pciNFAEndState->SetType(PREGEX_NSTATE_TYPE_EX_POSITIVE_LOOKBEHIND_END);
		break;

	case PREGEX_EX_TYPE_NEGATIVE_LOOKBEHIND:
		pciNFAStartState->SetType(PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKBEHIND_BEGIN);
		pciNFAEndState->SetType(PREGEX_NSTATE_TYPE_EX_NEGATIVE_LOOKBEHIND_END);
		break;

	case PREGEX_EX_TYPE_INDEPENDENT:
		pciNFAStartState->SetType(PREGEX_NSTATE_TYPE_EX_INDEPENDENT_BEGIN);
		pciNFAEndState->SetType(PREGEX_NSTATE_TYPE_EX_INDEPENDENT_END);
		break;

	case PREGEX_EX_TYPE_SETOPTIONS:
		pciNFAStartState->SetType(PREGEX_NSTATE_TYPE_EX_SETOPTIONS_BEGIN);
		pciNFAStartState->SetOptionalData(0, pciSRegEx->GetOptionalData(0));
		pciNFAStartState->SetOptionalData(1, pciSRegEx->GetOptionalData(1));
		pciNFAEndState->SetType(PREGEX_NSTATE_TYPE_EX_SETOPTIONS_END);
		break;

		//--------------------------------------------------
		//	Ctrl �^�C�v�̏ꍇ
		//	iDSExBegin �ɏ�����ݒ肵�AiDNextState �Ɍq����B
		//--------------------------------------------------
	case PREGEX_EX_TYPE_CTRL_SETOPTIONS:
		pciNFAStartState->SetType(PREGEX_NSTATE_TYPE_CTRL_SETOPTIONS);
		pciNFAStartState->SetOptionalData(0,  pciSRegEx->GetOptionalData(0));
		pciNFAStartState->SetOptionalData(1,  pciSRegEx->GetOptionalData(1));
		pciNFAStartState->AppendTransition(pciNFAEndState, PREGEX_TRANSITION_MATCH_EPSILON);
		return;
		break;

	default:
		break;
	}

	//------------------------------------------------------------
	//	�񌈒萫�L���I�[�g�}�g�����쐬����B
	//------------------------------------------------------------
	BuildNFA(pciSRegEx->GetRootNode(), pciNFAStartState, pciNFAEndState);
	return;
}


//======================================================================
//	class PCRegEx
//======================================================================
//----------------------------------------------------------------------
//	PCRegEx	�R���X�g���N�^
//	��O���X���[���ꂽ�ꍇ�̏����́A�C���X�^���X���쐬�������ōs�����ƁB
//----------------------------------------------------------------------
CLASS_PREGEX_REGEX::PCRegEx()
{
	ciMainSRegEx.SetType(PREGEX_EX_TYPE_CAP);
	ciMainSRegEx.SetBase(this);

	ciMainSRegEx.SetOptionalIndex((T_INDEX)ciCaptureArray.size());
	ciCaptureArray.push_back(&ciMainSRegEx);

	ciMainSRegExNFA.SetSRegEx(&ciMainSRegEx);

	ciPattern.SetCompareStringOptions(ciOptionsStack.Options());
	ciPattern.SetDecodeControlFunction(PLib::RegEx::DecodeEscapedControl);
}

//----------------------------------------------------------------------
//	PCRegEx	�f�X�g���N�^
//----------------------------------------------------------------------
CLASS_PREGEX_REGEX::~PCRegEx()
{
	Clear();
}

//----------------------------------------------------------------------
//	PCRegEx::Clear
//----------------------------------------------------------------------
void CLASS_PREGEX_REGEX::Clear()
{
	ciOptionsStack.Clear();
	ciPattern.Clear();
	strPattern.clear();
	ciMainSRegEx.Init();	//	Clear() �� protected

	ciCaptureArray.clear();
	ciNamedSRegExMap.clear();

	ciNStateArray.clear();
	ciNTransitionArray.clear();

	//ciMatchingPath.Clear();

	ciIPSRegEx.Clear();
	ciIPBracketEx.Clear();
	ciIPUCPString.Clear();
	ciIPNode.Clear();
	ciIPBracketEx.Clear();
	ciIPNodeList.Clear();
	ciIPNState.Clear();
	ciIPNTransition.Clear();
	ciIPSRegEx.Clear();
	ciIPSRegExDFA.Clear();
}

//----------------------------------------------------------------------
//	PCRegEx::ClearTemporary
//----------------------------------------------------------------------
void CLASS_PREGEX_REGEX::ClearTemporary()
{
}

//----------------------------------------------------------------------
//	PCRegEx::Init
//----------------------------------------------------------------------
bool CLASS_PREGEX_REGEX::Init()
{
	Clear();
	ciOptionsStack.Init();
	ciMainSRegEx.Init();
	ciMainSRegExNFA.Init();

	ciIPSRegEx.Init();
	ciIPBracketEx.Init();
	ciIPUCPString.Init();
	ciIPNode.Init();
	ciIPNodeList.Init();
	ciIPNState.Init();
	ciIPNTransition.Init();
	ciIPSRegEx.Init();
	ciIPSRegExDFA.Init();

	ciMainSRegEx.SetType(PREGEX_EX_TYPE_CAP);
	ciMainSRegEx.SetBase(this);

	ciMainSRegEx.SetOptionalIndex((T_INDEX)ciCaptureArray.size());
	ciCaptureArray.push_back(&ciMainSRegEx);

	ciMainSRegExNFA.SetSRegEx(&ciMainSRegEx);

	ciPattern.SetCompareStringOptions(ciOptionsStack.Options());
	ciPattern.SetDecodeControlFunction(PLib::RegEx::DecodeEscapedControl);

	return true;
}

//----------------------------------------------------------------------
//	PCRegEx::SetPattern	(1)
//----------------------------------------------------------------------
bool CLASS_PREGEX_REGEX::SetPattern(T_PCSTR pPatB, T_PCSTR pPatE)
{
	strPattern.assign(pPatB, (size_t)(pPatE - pPatB));
	ciPattern.SetCompareStringOptions(Options());
	return ciPattern.SetText(strPattern.c_str(), strPattern.size());
}

//----------------------------------------------------------------------
//	PCRegEx::SetPattern	(2)
//----------------------------------------------------------------------
bool CLASS_PREGEX_REGEX::SetPattern(T_PCSTR pPattern, size_t zPattern)
{
	strPattern.assign(pPattern, zPattern);
	ciPattern.SetCompareStringOptions(Options());
	return ciPattern.SetText(strPattern.c_str(), strPattern.size());
}

//----------------------------------------------------------------------
//	PCRegEx::SetPattern	(3)
//----------------------------------------------------------------------
bool CLASS_PREGEX_REGEX::SetPattern(T_PCSTR pszPattern)
{
	strPattern.assign(pszPattern);
	ciPattern.SetCompareStringOptions(Options());
	return ciPattern.SetText(strPattern.c_str(), strPattern.size());
}

//----------------------------------------------------------------------
//	PCRegEx::CreateBracketEx
//
//	CBRACKETEX �̃C���X�^���X���쐬���AciBracketExArray �ɓo�^����B
//	pciPattern ���� ] �܂ł�ǂݍ��݉�͂���B
//----------------------------------------------------------------------
PCBracketEx* CLASS_PREGEX_REGEX::CreateBracketEx()
{
	PCBRACKETEX	pBracketEx;

	pBracketEx	= ciIPBracketEx.Allocate();
	pBracketEx->SetBase(this);
	return pBracketEx;
}

//----------------------------------------------------------------------
//	PCRegEx::CreateSRegEx
//
//	CSREGEX �̃C���X�^���X���쐬���AciCaptureArray �ɓo�^����B
//	pciPattern ���� ) �܂ł�ǂݍ��݉�͂���B
//----------------------------------------------------------------------
PCSRegEx* CLASS_PREGEX_REGEX::CreateSRegEx(int iType, LPVOID pOpt0, LPVOID pOpt1)
{
	PCSREGEX	pSRegEx;

	pSRegEx	= ciIPSRegEx.Allocate();
	pSRegEx->Init();
	pSRegEx->SetBase(this);
	pSRegEx->SetType(iType);
	pSRegEx->SetOptionalData(0, pOpt0);
	pSRegEx->SetOptionalData(1, pOpt1);

	switch (iType)
	{
		//--------------------------------------------------
		//	Captured �̏ꍇ�AciCaptureArray �ɓo�^���Ă����B
		//--------------------------------------------------
	case PREGEX_EX_TYPE_CAP:
		pSRegEx->SetOptionalIndex((T_INDEX)ciCaptureArray.size());
		ciCaptureArray.push_back(pSRegEx);
		break;

	//case PREGEX_EX_TYPE_NCAP:
	//case PREGEX_EX_TYPE_SETOPTIONS:
	//case PREGEX_EX_TYPE_POSITIVE_LOOKAHEAD:
	//case PREGEX_EX_TYPE_NEGATIVE_LOOKAHEAD:
	//case PREGEX_EX_TYPE_POSITIVE_LOOKBEHIND:
	//case PREGEX_EX_TYPE_NEGATIVE_LOOKBEHIND:
	//case PREGEX_EX_TYPE_INDEPENDENT:
		//break;

	default:
		//THROWPE_LOGIC_ERROR("PCRegEx::CreateSRegEx");
		break;
	}

	//	��͖؂܂ō쐬���Ă����B
	pSRegEx->Parse();
	return pSRegEx;
}

//----------------------------------------------------------------------
//	PCRegEx::GetSRegEx
//	����Q�Ƃ̃C���f�b�N�X���� PCSRegEx �̃|�C���^���擾����B
//	�w�肳�ꂽ�C���f�b�N�X���s�K�؂ȏꍇ�A�������č�Ƃ𑱂�����悤
//	false ��Ԃ����Ƃɂ���B��O�΃X���[���Ȃ��B
//----------------------------------------------------------------------
bool CLASS_PREGEX_REGEX::GetSRegEx(PCSREGEX* ppciSRegEx, T_INDEX iIndex)
{
	PCSREGEX	pSRegEx;

	try
	{
		pSRegEx	= ciCaptureArray.at(iIndex);
	}
	catch (...)
	{
		return false;
	}

	*ppciSRegEx	= pSRegEx;
	return true;
}

//----------------------------------------------------------------------
//	PCRegEx::CreateNamedSRegEx
//
//	CSREGEX �̃C���X�^���X���쐬���AciSRegExCapArray�AciSRegExNCapArray �ɓo�^����B
//	pciPattern ���� ) �܂ł�ǂݍ��݉�͂���B
//----------------------------------------------------------------------
PCSRegEx* CLASS_PREGEX_REGEX::CreateNamedSRegEx(ITR_UCPSTRING&	itrNameB,
												ITR_UCPSTRING&	itrNameE,
												CTEXTR*			pciText)
{
	PCSREGEX	pSRegEx;
	UCPSTRING	*pName;

	std::pair<ITR_NAMEDSREGEXMAP, bool>	pr;

	pSRegEx	= ciIPSRegEx.Allocate();
	pSRegEx->Init();
	pSRegEx->SetBase(this);
	pSRegEx->SetType(PREGEX_EX_TYPE_CAP_NAMED);

	pName	= AllocateString();
	ciPattern.GetSubString(pName, itrNameB, itrNameE);
	pSRegEx->SetOptionalName(pName);
	pr	= ciNamedSRegExMap.insert(PAIR_NAMEDSREGEXMAP(pName, pSRegEx));
	//	���łɓo�^����Ă��閼�O�̏ꍇ�͕��@�G���[���X���[����B
	if (pr.second == false)	THROWPE_SYNTAX_ERROR("");

	//	��͖؂��쐬���Ă����B
	pSRegEx->Parse();
	return pSRegEx;
}

//----------------------------------------------------------------------
//	PCRegEx::FindNamedSRegEx
//
//	����Q�Ɨp�̖��Og�� ciNamedSRegExMap �ɓo�^����Ă��邩���ׂ�B
//----------------------------------------------------------------------
bool CLASS_PREGEX_REGEX::FindNamedSRegEx(ITR_NAMEDSREGEXMAP&	itr,
										 ITR_UCPSTRING&			itrB,
										 ITR_UCPSTRING&			itrE)
{
	UCPSTRING			ucsTemp;

	if (!ciPattern.GetSubString(&ucsTemp, itrB, itrE))	return false;
	if (ucsTemp.empty())	return false;

	itr	= ciNamedSRegExMap.find(&ucsTemp);
	return (itr != ciNamedSRegExMap.end());
}

bool CLASS_PREGEX_REGEX::FindNamedSRegEx(CSREGEX** ppSRegEx, ITR_UCPSTRING& itrB, ITR_UCPSTRING& itrE)
{
	ITR_NAMEDSREGEXMAP	itr;

	if (!FindNamedSRegEx(itr, itrB, itrE))	return false;
	*ppSRegEx	= itr->second;
	return true;
}

bool CLASS_PREGEX_REGEX::FindNamedSRegEx(UCPSTRING** ppName, ITR_UCPSTRING& itrB, ITR_UCPSTRING& itrE)
{
	ITR_NAMEDSREGEXMAP	itr;

	if (!FindNamedSRegEx(itr, itrB, itrE))	return false;
	*ppName	= itr->first;
	return true;
}

//----------------------------------------------------------------------
//	PCRegEx::CreateSRegExNFA
//----------------------------------------------------------------------
PCSRegExNFA* CLASS_PREGEX_REGEX::CreateSRegExNFA(PCSREGEX pSRegEx)
{
	PCSREGEXNFA	pSRegExNFA;

	pSRegExNFA	= AllocateSRegExDFA();
	pSRegExNFA->SetSRegEx(pSRegEx);
	return pSRegExNFA;
}

//----------------------------------------------------------------------
//	PCSRegEx::CreateNState
//	�����̃`�F�b�N�͍s��Ȃ��B�Ăяo�����Ŋm�F���Ă������ƁB
//----------------------------------------------------------------------
void CLASS_PREGEX_REGEX::CreateNState(T_INDEX* piNDSIndex, PCNSTATE* ppNState)
{
	T_INDEX		iIndex		= (T_INDEX)(ciNStateArray.size());
	PCNSTATE	pNState	= NULL;

	if (iIndex >= PREGEX_STATE_MAX)
	{
		THROWPE_RUNTIME_ERROR("Too many NStates.");
	}

	pNState	= AllocateNState();
	ciNStateArray.push_back(pNState);

	pNState->SetStateIndex(iIndex);
	pNState->SetBase(this);

	*piNDSIndex	= iIndex;
	*ppNState	= pNState;
	return;
}

void CLASS_PREGEX_REGEX::CreateNState(T_INDEX* piNDSIndex, PCNSTATE* ppNState, int iType)
{
	CreateNState(piNDSIndex, ppNState);
	(*ppNState)->SetType(iType);
}

//----------------------------------------------------------------------
//	PCSRegEx::CreateNTransition
//	�����̃`�F�b�N�͍s��Ȃ��B�Ăяo�����Ŋm�F���Ă������ƁB
//----------------------------------------------------------------------
PCRegExNTransition* CLASS_PREGEX_REGEX::CreateNTransition(CNSTATE*	pSrcState,
																	CNSTATE*	pDstState)
{
	T_INDEX			iIndex			= (T_INDEX)(ciNTransitionArray.size());
	CNTRANSITION*	pNTransition	= NULL;

	if (iIndex >= PREGEX_TRANSITION_MAX)
	{
		THROWPE_RUNTIME_ERROR("Too many NTransitions.");
	}

	pNTransition	= AllocateNTransition();
	pNTransition->Init();
	pNTransition->SetIndex(iIndex);
	pNTransition->SetBase(this);
	pNTransition->SetDestination(pDstState);
	pSrcState->AppendTransition(pNTransition);

	ciNTransitionArray.push_back(pNTransition);
	return pNTransition;
}

//----------------------------------------------------------------------
//	PCRegEx::OptimizeNFA
//	�I�[�g�}�g�����疳�ʂȏ�Ԃ���菜���B
//----------------------------------------------------------------------
void CLASS_PREGEX_REGEX::OptimizeNFA()
{
	/*
	typedef	std::set<CNTRANSITION*>		NTRANSSET;
	typedef	NTRANSSET::iterator	ITR_NTRANSSET;

	//------------------------------------------------------------
	//	struct	SPN
	//------------------------------------------------------------
	struct	SPN
	{
		NTRANSSET	ciPrev;
		NTRANSSET	ciNext;
		size_t		zTransitions;	//	�Ή����� NState �ɂ���S�J�ڐ��B
		bool		bNonEpsilonDst;	//	epsilon �J�ڈȊO�̑J�ڐ�ƂȂ��Ă���B

		SPN()	: zTransitions(0), bNonEpsilonDst(false)	{}

#ifdef	PDEBUG
		void DebugTransactionSet(T_STRING_U* pstrDebug, NTRANSSET* pTrSet)
		{
			ITR_NTRANSSET	itr;
			T_PCSTR_U		pfmt_p	= TQU(" 0x%08X");

			for (itr = pTrSet->begin(); itr != pTrSet->end(); ++itr)
			{
				NS_PLIB::AppendNumToString<T_CHAR, int>(pstrDebug, pfmt_p, (int)*itr);
			}
		}

		void Debug(T_STRING_U* pstrDebug)
		{
			T_PCSTR	pszCRLF	= TQU("\r\n");

			pstrDebug->append(TQU("Prev:"));
			DebugTransactionSet(pstrDebug, &ciPrev);
			pstrDebug->append(pszCRLF);
			pstrDebug->append(TQU("Next:"));
			DebugTransactionSet(pstrDebug, &ciNext);
			pstrDebug->append(pszCRLF);
		}
#endif
	};

	//------------------------------------------------------------
	//	�ϐ��̒�`
	//------------------------------------------------------------
	ITR_NSTATEARRAY	itr_nda;
	ITR_NTRANSSET		itr_trs;
	size_t				zDStates	= ciNStateArray.size();

	CNSTATE*		pNStateC	= NULL;
	CNSTATE*		pNStateN	= NULL;
	SPN*			pSPNArray	= NULL;
	SPN*			pSPNArrayE	= NULL;
	SPN*			pSPNC		= NULL;
	SPN*			pSPNN		= NULL;
	CNTRANSITION*	pTransC		= NULL;
	CNTRANSITION*	pTransN		= NULL;

	UINT	uic, uin, uit;

#ifdef	PDEBUG
	T_STRING	strDebug1, strDebug2;
	T_PCSTR_U		pfmt_d	= TQU("%d");
	T_PCSTR_U		pszCRLF	= TQU("\r\n");
	T_PCSTR_U		pszHR	= TQU("========================================\r\n\r\n");
#endif

	try
	{
		pSPNArray	= new SPN[zDStates];
		pSPNArrayE	= pSPNArray + zDStates;

		//--------------------------------------------------
		//	epsilon �J�ڂ�O��̏�Ԃɓo�^����B
		//--------------------------------------------------
		for (uic = 0; uic < zDStates; ++uic)
		{
			pNStateC	= ciNStateArray.at(uic);
			for (pTransC = pNStateC->GetTransition(); pTransC != NULL;
					pTransC = pTransC->GetNextTransition())
			{
				pNStateN	= pTransC->GetDestination();
				uin			= pNStateN->GetStateIndex();
				pSPNC		= pSPNArray + uic;
				pSPNN		= pSPNArray + uin;

				++(pSPNC->zTransitions);
				if (pTransC->GetMatchingType() != PREGEX_TRANSITION_MATCH_EPSILON)
				{
					pSPNN->bNonEpsilonDst	= true;
					continue;
				}

				pSPNC->ciNext.insert(pTransC);
				(pSPNArray + uin)->ciPrev.insert(pTransC);
			}
		}

#ifdef	PDEBUG
		strDebug1.assign(pszHR);
		Debug(&strDebug1);

		strDebug1.append(pszHR);
		for (uic = 0; uic < zDStates; ++uic)
		{
			pSPNC	= pSPNArray + uic;
			strDebug1.append(TQU("NState["));
			NS_PLIB::AppendNumToString<T_CHAR_U, int>(&strDebug1, pfmt_d, (int)uic);
			strDebug1.append(TQU("]\r\n"));
			pSPNC->Debug(&strDebug1);
			strDebug1.append(pszCRLF);
		}
#endif

		//--------------------------------------------------
		//	�O�オ epsilon �J�ڂł��� normal �ȏ�Ԃ�
		//	��΂��悤�ɑO�̑J�ڂ̈ړ����ύX����B
		//--------------------------------------------------
		for (uic = 0, pSPNC = pSPNArray; uic < zDStates; ++uic, ++pSPNC)
		{
			pNStateC	= ciNStateArray.at(uic);
			if (pSPNC->bNonEpsilonDst == true)	continue;
			if (pSPNC->ciPrev.size() < 1)		continue;
			if (pSPNC->zTransitions != 1)		continue;
			if (pSPNC->ciNext.size() != 1)		continue;
			if (pNStateC->GetType() != PREGEX_NSTATE_TYPE_NORMAL)	continue;

			//	�V�����J�ڐ�����߂�B�J�ڐ悪 Unused �Ȃ炻�̑J�ڐ�Ɉړ�����悤�ɏC������B
			for (uit = 0, pTransC = *(pSPNC->ciNext.begin()); uit < zDStates; ++uit)
			{
				pNStateN	= pTransC->GetDestination();
				uin	= (UINT)pNStateN->GetStateIndex();
				pSPNN = pSPNArray + uin;
				if (pNStateN->GetType() != PREGEX_NSTATE_TYPE_UNUSED)	break;
				if (pSPNN->ciNext.size() != 1)
					THROWPE_LOGIC_ERROR("PCRegEx::OptimizeNFA : Stage1 incorrectly processed.");
				pTransC	= *(pSPNN->ciNext.begin());
			}

			//	��Ԑ������ׂĂ�������Ȃ��ꍇ�͗�O���X���[����B
			if (uit >= zDStates)	THROWPE_LOGIC_ERROR("PCRegEx::OptimizeNFA");

			//	pSPN->ciPrev �ɓo�^����Ă��邷�ׂĂ̑J�ڂ̑J�ڐ��ύX����B
			//	�܂��A�V�����J�ڐ�̑J�ڌ��Ƃ��ēo�^����B
			for (itr_trs = pSPNC->ciPrev.begin(); itr_trs != pSPNC->ciPrev.end(); ++itr_trs)
			{
				(*itr_trs)->SetDestination(pNStateN);
				pSPNN->ciPrev.insert(*(itr_trs));
			}
			pNStateC->SetType(PREGEX_NSTATE_TYPE_UNUSED);
		}
	}
	catch (...)
	{
	}

#ifdef	PDEBUG
		strDebug1.assign(pszHR);
		Debug(&strDebug1);

		strDebug1.append(pszHR);
		for (uic = 0; uic < zDStates; ++uic)
		{
			pSPNC	= pSPNArray + uic;
			strDebug1.append(TQU("DState["));
			NS_PLIB::AppendNumToString<T_CHAR, int>(&strDebug1, pfmt_d, (int)uic);
			strDebug1.append(TQU("]\r\n"));
			pSPNC->Debug(&strDebug1);
			strDebug1.append(pszCRLF);
		}
#endif

	delete[]	pSPNArray;
	*/
}

//----------------------------------------------------------------------
//	PCRegEx::BuildNFA
//	�p�^�[������͂��A���萫�I�[�g�}�g�����쐬����B
//	�������ɔ���������O�͂��̊֐����ŏ�������B
//----------------------------------------------------------------------
bool CLASS_PREGEX_REGEX::BuildNFA(T_STRING_U* pstrError)
{
	T_STRING_U	strTemp;
#ifdef	PDEBUG
	T_STRING_U	strDebug;
#endif

	try
	{
		ciPattern.Begin();
		RestoreOptions();
		(ciMainSRegExNFA.SRegEx())->Parse();

#ifdef	PDEBUG
		strDebug.clear();
		this->Debug(&strDebug);
#endif

		ciMainSRegExNFA.BuildNFA();
		//OptimizeNFA();

#ifdef	PDEBUG
		strDebug.clear();
		this->Debug(&strDebug);
#endif
	}
	//------------------------------------------------------------
	//	�p�^�[���̉�͒��ɕ��@�G���[��������� PSyntaxError ���X���[�����B
	//------------------------------------------------------------
#ifdef	PDEBUG
	catch (NS_PLIB::PSyntaxError& e)
	{
		pstrError->append(e.What<T_CHAR_U>());
		if (pstrError != NULL)
		{
			ciPattern.ReportCurrentPos(pstrError, TQU("Error"));
		}
		return false;
	}
#else
	catch (NS_PLIB::PSyntaxError&)
	{
		if (pstrError != NULL)
		{
			ciPattern.ReportCurrentPos(pstrError, TQU("Error"));
		}
		return false;
	}
#endif
	//------------------------------------------------------------
	//	�v���O�������ɃG���[������� PLogicError ���X���[�����B
	//------------------------------------------------------------
#ifdef	PDEBUG
	catch (NS_PLIB::PLogicError& e)
	{
		strDebug.clear();
		this->Debug(&strDebug);
		if (pstrError != NULL)
		{
			pstrError->assign(TQU("Program Error: "));
			pstrError->append(e.What<T_CHAR_U>());
		}
		return false;
	}
#else
	catch (NS_PLIB::PLogicError& e)
	{
		if (pstrError != NULL)
		{
			pstrError->assign(TQU("Program Error: "));
			pstrError->append(e.What<T_CHAR_U>());
		}
		return false;
	}
#endif
	//------------------------------------------------------------
	//	����ȊO�̗�O���L���b�`���ꂽ�ꍇ�B
	//------------------------------------------------------------
#ifdef	PDEBUG
	catch (...)
	{
		strDebug.clear();
		this->Debug(&strDebug);
		return false;
	}
#else
	catch (...)
	{
		return false;
	}
#endif

	return true;
}

//----------------------------------------------------------------------
//	PCRegEx::Match	(1)
//
//	1 �̏����Ƀe�L�X�g���}�b�`���Ă��邩�����ۂɒ��ׂ�⏕�֐��B
//	�}�b�`���Ă���ꍇ�A�e�L�X�g�̏����ʒu�̓}�b�`���������̎��Ɉړ������B
//	�}�b�`���Ă��Ȃ��ꍇ�́A�Ώۃe�L�X�g�̏����ʒu�����ɖ߂��B
//----------------------------------------------------------------------
bool CLASS_PREGEX_REGEX::Match(SMATCHING* pMatching, PCRETEXT pciText, SLOOKBEHIND* pLookBehind)
{
	CNSTATE*			pNState;
	PCBRACKETEX			pciBracketEx;
	T_UCP				cpSrc, cpMatch;
	ITR_UCPSTRING		itrT1, itrT2;
	ITR_UCPSTRING		itrCurrent;
	int					iMin, iMax;
	int					i;
	DWORD				dwFlags		= 0;
	T_PCSTR_U			pszLocale	= NULL;
	bool				bNegative	= false;
	bool				br, bt;
	SLOOKBEHIND			siLookBehind;

	dwFlags		= pciText->Options()->GetCompareStringUCDFlags();
	pszLocale	= pciText->Options()->GetLocaleString();
	
	switch (pMatching->GetType())
	{
	case PREGEX_TRANSITION_MATCH_UNDEFINED:
		THROWPE_LOGIC_ERROR("PCRegEX::Match - invalid matching condition.");
		break;

	case PREGEX_TRANSITION_MATCH_EPSILON:
		return true;
		break;

		//--------------------------------------------------
		//	�ʏ�̕���
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_CHAR:
		cpMatch	= (T_UCP)(pMatching->GetValue());
		if (!PCTEXT_GETVALIDCP(pciText->GetCurrentCp(&cpSrc)))	return false;
		if (PLib::Unicode::CompareCodepointUCD(cpMatch, cpSrc, dwFlags, pszLocale) == CSTR_EQUAL)
		{
			pciText->Next();
			return true;
		}
		return false;
		break;

		//--------------------------------------------------
		//	�C�ӂ� 1 ����
		//	���s�� �V���O�����C�����[�h�̏ꍇ�ɂ̂݃}�b�`����B
		//	���łɏI�[�ɒB���Ă���ꍇ�� false ��Ԃ��B
		//	����ȊO�̏ꍇ�͈ꕶ���i�߂� true ��Ԃ��B
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_ANY_CHAR:
		if (!PCTEXT_GETVALIDCP(pciText->GetCurrentCp(&cpSrc)))	return false;
		//	CR �� LF �̏ꍇ�A
		//	Singleline Mode �̏ꍇ�A�͉��s�iCRLF �܂��͒P�Ƃ� CR�ALF�j���΂��B
		//	����ȊO�̏ꍇ�� false ��Ԃ��B
		if (PLib::Unicode::IsCRLF(cpSrc, true))
		{
			if ((pciText->Options())->IsSinglelineMode())
			{
				return PLib::PCTextUR_NextLine(pciText);
			}
			else
			{
				return false;
			}
		}
		else
		{
			return pciText->Next();
		}
		break;

		//--------------------------------------------------
		//	Unicode �̑���
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_UNICODE_PROPERTY:
		if (!PCTEXT_GETVALIDCP(pciText->GetCurrentCp(&cpSrc)))	return false;
		bt	= MatchUnicodeProperty(pMatching->GetInt(), cpSrc);
		if (bt)	pciText->Next();
		return bt;
		break;

		//--------------------------------------------------
		//	10 �i����\������
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_CHAR_DIGIT:
		if (!PCTEXT_GETVALIDCP(pciText->GetCurrentCp(&cpSrc)))	return false;
		if (PLib::Unicode::IsDigit_GC(cpSrc))
		{
			pciText->Next();
			return true;
		}
		return false;
		break;

		//--------------------------------------------------
		//	10 �i����\�������ȊO
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_CHAR_NON_DIGIT:
		if (!PCTEXT_GETVALIDCP(pciText->GetCurrentCp(&cpSrc)))	return false;
		if (!PLib::Unicode::IsDigit_GC(cpSrc))
		{
			pciText->Next();
			return true;
		}
		return false;
		break;

		//--------------------------------------------------
		//	�P��Ɏg�p����镶��
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_CHAR_WORD:
		if (!PCTEXT_GETVALIDCP(pciText->GetCurrentCp(&cpSrc)))	return false;
		if (PLib::Unicode::IsWord_GC(cpSrc))
		{
			pciText->Next();
			return true;
		}
		return false;
		break;

		//--------------------------------------------------
		//	�P��ł͎g�p����Ȃ�����
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_CHAR_NON_WORD:
		if (!PCTEXT_GETVALIDCP(pciText->GetCurrentCp(&cpSrc)))	return false;
		if (!PLib::Unicode::IsWord_GC(cpSrc))
		{
			pciText->Next();
			return true;
		}
		return false;
		break;

		//--------------------------------------------------
		//	�󔒕���
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_CHAR_SPACE:
		if (!PCTEXT_GETVALIDCP(pciText->GetCurrentCp(&cpSrc)))	return false;
		if (PLib::Unicode::IsSpace_GC(cpSrc))
		{
			pciText->Next();
			return true;
		}
		return false;
		break;

		//--------------------------------------------------
		//	�󔒕����ȊO
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_CHAR_NON_SPACE:
		if (!PCTEXT_GETVALIDCP(pciText->GetCurrentCp(&cpSrc)))	return false;
		if (!PLib::Unicode::IsSpace_GC(cpSrc))
		{
			pciText->Next();
			return true;
		}
		return false;
		break;

		//--------------------------------------------------
		//	�P�ꋫ�E�i�O�オ�P��p�̕����Ɣ�P�ꕶ���j
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_WORD_BOUNDARY:
		return PLib::IsWordBoundary(pciText);
		break;

		//--------------------------------------------------
		//	�P�ꋫ�E�ȊO�̋��E
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_NOT_WORD_BOUNDARY:
		return !PLib::IsWordBoundary(pciText);
		break;

		//--------------------------------------------------
		//	�Ō�Ƀ}�b�`�����ʒu
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_LAST_MATCH:
		if (pciText->GetReference(itrT1, itrT2, (T_INDEX)0))
		{
			if (!pciText->GetCurrentPos(itrCurrent))	THROWPE_LOGIC_ERROR("");
			return (itrT2 == itrCurrent);
		}
		return true;	//	�܂��}�b�`���Ă��Ȃ��ꍇ�� true ��Ԃ��B
		break;

		//--------------------------------------------------
		//	�s�̐擪
		//	�ʏ�̓e�L�X�g�̐擪�Ƀ}�b�`����B
		//	Multiline Mode �̏ꍇ�A�����
		//	���s�̒���ɂ��}�b�`����B
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_START_MULTI:
		return pciText->HeadOfLine((pciText->Options())->IsMultilineMode());
		break;

	case PREGEX_TRANSITION_MATCH_START_SINGLE:
		return pciText->HeadOfLine(false);
		break;

		//--------------------------------------------------
		//	�s�̖���
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_END_MULTI:
		return pciText->EndOfLine((pciText->Options())->IsMultilineMode());
		break;

	case PREGEX_TRANSITION_MATCH_END_SINGLE:
		return pciText->EndOfLine(false);
		break;

	case PREGEX_TRANSITION_MATCH_ENDLF_SINGLE:
		if (pciText->EndOfLine(false))	return true;
		//	�e�L�X�g�I�[�̉��s�ł��悢�B
		if (!PCTEXT_GETVALIDCP(pciText->GetCurrentCp(&cpSrc)))	THROWPE_LOGIC_ERROR("");
		pciText->PushNewIterator();
		PLib::PCTextUR_NextLine(pciText);
		if (pciText->End())
		{
			//pciText->PopAndUpdateIterator();
			pciText->PopIterator();
			return true;
		}
		pciText->PopIterator();
		return false;
		break;

		//--------------------------------------------------
		//	�u���P�b�g�\��
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_BRACKETEX:
		pciBracketEx	=  (CBRACKETEX*)pMatching->GetValue();
		if (pciBracketEx->Match(pciText))
		{
			//pciText->Next();
			return true;
		}
		return false;
		break;

		//--------------------------------------------------
		//	�������K�\��
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_REGEX:
		//	�o�O���c���Ă��Ȃ��Ȃ�A�����ɗ��邱�Ƃ͂Ȃ��B
		THROWPE_LOGIC_ERROR("PCRegEx::Match");
		break;

		//--------------------------------------------------
		//	LookAhead
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_EX_POSITIVE_LOOKAHEAD:
	case PREGEX_TRANSITION_MATCH_EX_NEGATIVE_LOOKAHEAD:
		pciText->PushNewOptions();
		pciText->PushNewIterator();
		br	= ((CNSTATE*)(pMatching->GetValue()))->NextState(pciText, pLookBehind);
		pciText->PopIterator();
		pciText->PopOptions();
		return (pMatching->GetType() == PREGEX_TRANSITION_MATCH_EX_POSITIVE_LOOKAHEAD ? br : !br);
		break;

		//--------------------------------------------------
		//	LookBehind
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_EX_POSITIVE_LOOKBEHIND:
	case PREGEX_TRANSITION_MATCH_EX_NEGATIVE_LOOKBEHIND:
		pciText->PushNewOptions();
		pciText->PushNewIterator();
		pNState	= (CNSTATE*)(pMatching->GetValue());
		iMin	= (int)pNState->GetOptionalData(0);
		iMax	= (int)pNState->GetOptionalData(1);
		if (!pciText->GetCurrentPos(itrCurrent))	THROWPE_LOGIC_ERROR("");
		siLookBehind.Init();
		siLookBehind.itrEnd	= itrCurrent;
		//pciText->SetLookBehind(itrCurrent);
		br	= false;

		//	�ő啶���������̒l�̏ꍇ�A����ɑΉ�����ʒu�����߂Ă����B
		pciText->GetBegin(itrT1);
		if (iMax >= 0)
		{
			if (!pciText->GetCurrentPos(itrT2))	THROWPE_LOGIC_ERROR("");
			for (i = 0; i < iMax; ++i)
			{
				if (itrT1 == itrT2)	break;
				--itrT2;
			}
		}
		else
		{
			itrT2	= itrT1;
		}
		//	�ŏ������������̒l�̏ꍇ�A���̕��O�֖߂��Ă����B
		if (iMin > 0)
		{
			for (i = 0; i < iMin; ++i)
			{
				if (!pciText->Previous())
				{
					br	= false;
					goto LOOKBEHIND_END_PROCESSING;
				}
			}
		}

		//	�J�n�ʒu�� 1 �������O�֖߂��Ē��ׂĂ����B
		do
		{
			//pciText->LookBehind()->bAtEnd	= false;
			pciText->PushNewIterator();
			bt	= pNState->NextState(pciText, &siLookBehind);
			pciText->PopIterator();
			if (bt == true && siLookBehind.bAtEnd == true)
			{
				br	= true;
				break;
			}
		}
		while (pciText->GetCurrentPos(itrCurrent) && (itrCurrent != itrT2) && (pciText->Previous()));

LOOKBEHIND_END_PROCESSING:
		pciText->PopIterator();
		pciText->PopOptions();
		return (pMatching->GetType() == PREGEX_TRANSITION_MATCH_EX_POSITIVE_LOOKBEHIND ? br : !br);
		break;

		//--------------------------------------------------
		//	�Ɨ������������K�\��
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_EX_INDEPENDENT:
		pciText->PushNewOptions();
		pciText->PushNewIterator();
		if (((CNSTATE*)(pMatching->GetValue()))->NextState(pciText, pLookBehind))
		{
			pciText->PopAndUpdateIterator();
			pciText->PopOptions();
			return true;
		}
		else
		{
			pciText->PopIterator();
			pciText->PopOptions();
			return false;
		}
		break;

		//--------------------------------------------------
		//	����Q��	(1)	�C���f�b�N�X�Ŏw��
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_BACKREF:
		if (!pciText->GetCurrentBackRef(itrT1, itrT2, pMatching->GetIndex()))
		{
			//THROWPE_LOGIC_ERROR("PCRegEx::Match cannot get back reference.");
			return false;
		}
		return pciText->Match(itrT1, itrT2);
		break;

		//--------------------------------------------------
		//	����Q��	(2)	���O�Ŏw��
		//--------------------------------------------------
	case PREGEX_TRANSITION_MATCH_BACKREF_BYNAME:
		if (!pciText->GetCurrentNamedBackRef(itrT1, itrT2, pMatching->GetName()))
		{
			//THROWPE_LOGIC_ERROR("PCRegEx::Match cannot get back reference.");
			return false;
		}
		return pciText->Match(itrT1, itrT2);
		break;

	default:
		break;
	}
	return false;
}

//----------------------------------------------------------------------
//	PCRegEx::Match	(2)
//
//	PCRegEx �ɂ���p�^�[���Ƀe�L�X�g���}�b�`���Ă��邩���ׂ�B
//	����������ɏI�����Ȃ������ꍇ�� false ��Ԃ��B
//	������Ȃ������ꍇ�� false ��Ԃ��B
//----------------------------------------------------------------------
bool CLASS_PREGEX_REGEX::Match(PCRETEXT pciText)
{
	ITR_UCPSTRING	itrCurrent;
	T_STRING		strTemp, strError;

#ifdef	PDEBUG
	T_PCSTR_U	pfmt_d	= TQU("%d");
	T_STRING	strDebug;

	strDebug.clear();
	Debug(&strDebug);
#endif

	//	�����ʒu�����ɐݒ肳��Ă���ꍇ�͂������璲�ׂ�B
	//	�I�[�Ƀ}�b�`����ꍇ������̂ŁAEnd() ���������Ă��Ă��ƍ�����B
	if (pciText == NULL)	return false;
	pciText->SetOptions(Options());

	try
	{
		do
		{
#ifdef	PDEBUG
			strDebug.clear();
			strDebug.append(TQU("---------- Start ----------\r\nAt : "));
			pciText->GetCurrentPos(itrCurrent);
			pciText->GetSubStringFollowing(&strDebug, itrCurrent);
			strDebug.append(TQU("\r\n"));
			NS_PLIB::Debug::Log(strDebug.c_str());
#endif

			pciText->InitHistory();
			pciText->MatchTimes()->Init();
			if (pciText->IsGlobalMatching())
			{
				if (!pciText->GetCurrentPos(pciText->GlobalMatching()->itrMatch))
					THROWPE_LOGIC_ERROR("");
			}

			pciText->PushNewIterator();
			if ((ciMainSRegExNFA.GetNFAStartState())->NextState(pciText, NULL))
			{
#ifdef	PDEBUG
				strDebug.clear();
				pciText->DebugHistory(&strDebug);
#endif
				//	�}�b�`���镔�������������ꍇ�A
				//	�������K�\���Ƀ}�b�`�����������L�^����B
				pciText->ParseBackRef();
				pciText->PopAndUpdateIterator();
				return true;
			}
			//	�}�b�`���Ȃ������ꍇ�́A���̕����Ɉړ����Ē��ג����B
			//	GlobalMatching �̏ꍇ�A���� 0 �̌J��Ԃ����N���A����B
			pciText->PopIterator();
			pciText->GlobalMatching()->Init();

#ifdef	PDEBUG
			strDebug.clear();
			strDebug.append(TQU("---------- End ----------\r\n"));
			NS_PLIB::Debug::Log(strDebug.c_str());
#endif
		}
		while (pciText->Next());
	}
	catch (PLib::PRegExTimeOut& e)
	{
		strError.assign(TQU("Time-Out"));
		strError.append(e.What<T_CHAR_U>());
	}
	catch (...)
	{
		throw;
	}

	//	�}�b�`���镔����������Ȃ������ꍇ
	return false;
}

//----------------------------------------------------------------------
//	PCRegEx::AllocateString
//----------------------------------------------------------------------
UCPSTRING* CLASS_PREGEX_REGEX::AllocateString()
{
	return ciIPUCPString.Allocate();
}

//----------------------------------------------------------------------
//	PCRegEx::AllocateNode
//----------------------------------------------------------------------
PCRegExNode* CLASS_PREGEX_REGEX::AllocateNode()
{
	return ciIPNode.Allocate();
}

//----------------------------------------------------------------------
//	PCRegEx::AllocateBracketEx
//----------------------------------------------------------------------
PCBracketEx* CLASS_PREGEX_REGEX::AllocateBracketEx()
{
	return ciIPBracketEx.Allocate();
}

//----------------------------------------------------------------------
//	PCRegEx::AllocateNodeList
//----------------------------------------------------------------------
PLib::PCBRegEx::CNODELIST* CLASS_PREGEX_REGEX::AllocateNodeList()
{
	return ciIPNodeList.Allocate();
}

//----------------------------------------------------------------------
//	PCRegEx::AllocateNState
//----------------------------------------------------------------------
PCRegExNState* CLASS_PREGEX_REGEX::AllocateNState()
{
	return ciIPNState.Allocate();
}
	
//----------------------------------------------------------------------
//	PCRegEx::AllocateNTransition
//----------------------------------------------------------------------
PCRegExNTransition* CLASS_PREGEX_REGEX::AllocateNTransition()
{
	return ciIPNTransition.Allocate();
}

//----------------------------------------------------------------------
//	PCRegEx::AllocateSRegEx
//----------------------------------------------------------------------
PCSRegEx* CLASS_PREGEX_REGEX::AllocateSRegEx()
{
	return ciIPSRegEx.Allocate();
}

//----------------------------------------------------------------------
//	PCRegEx::AllocateSRegExDFA
//----------------------------------------------------------------------
PCSRegExNFA* CLASS_PREGEX_REGEX::AllocateSRegExDFA()
{
	return ciIPSRegExDFA.Allocate();
}

NS_PLIB_END
