//	XLCTextEx_1.0x	:	PLibTextEx

//	PTransChar.h
//
#include "stdafx.h"

NS_PLIB_BEGIN

#define	PTRANSCHAR_CP_ERROR		0
#define	PTRANSCHAR_CP_END		0
#define	PTRANSCHAR_CP_CHAR		1
#define	PTRANSCHAR_CP_HYPHEN	2
#define	PTRANSCHAR_CP_LBRACKET	3
#define	PTRANSCHAR_CP_RBRACKET	4
#define	PTRANSCHAR_CP_PERIOD	5

//======================================================================
//	class PCTrBuffer
//======================================================================
//----------------------------------------------------------------------
//	PCTrBuffer	�R���X�g���N�^�ƃf�X�g���N�^
//----------------------------------------------------------------------
PCTrBuffer::PCTrBuffer(PCTransChar* pb)
:	pciBase(pb),
	cpRangeC(INVALID_CODEPOINT),
	cpRangeE(INVALID_CODEPOINT),
	bDescend(false)
{
	ciBuffer.SetDecodeFlags(PTRANSCHAR_DECODEFLAGS);
	ciBuffer.SetDecodeControlFunction(PLib::Unicode::DecodeEscapedControl);
}

PCTrBuffer::~PCTrBuffer()
{
	Clear();
}

//----------------------------------------------------------------------
//	PCTrBuffer::Clear
//----------------------------------------------------------------------
void PCTrBuffer::Clear()
{
	ciBuffer.Clear();
	cpRangeC	= INVALID_CODEPOINT;
	cpRangeE	= INVALID_CODEPOINT;
	bDescend	= false;
}

//----------------------------------------------------------------------
//	PCTrBuffer::SetOptIgnoreWidth
//----------------------------------------------------------------------
void PCTrBuffer::SetOptIgnoreWidth(bool bw)
{
	bIgnoreWidth = bw;
	if (bIgnoreWidth)
	{
		ciBuffer.SetDefaultCSFlags(NORM_IGNOREWIDTH);
	}
	else
	{
		ciBuffer.SetDefaultCSFlags(0);
	}
}

//----------------------------------------------------------------------
//	PCTrBuffer::GetElement
//	������̏I�[�ɒB���Ă���ꍇ�� false ��Ԃ��B
//	���@�G���[�̏ꍇ�͗�O���X���[����B
//----------------------------------------------------------------------
int PCTrBuffer::GetElement(LPVOID *ppElement, bool bNormalize)
{
	T_UCP			cpCurrent, cpNext;
	ITR_UCPSTRING	itrB, itrE;
	UCPSTRING*		ps;

START:
	//------------------------------------------------------------
	//	�͈͒��ɂ���ꍇ
	//------------------------------------------------------------
	if (cpRangeE != INVALID_CODEPOINT)
	{
		if (bDescend)
		{
			--cpRangeC;
			if (cpRangeC >= cpRangeE)
			{
				*ppElement	= (LPVOID)cpRangeC;
				return PTRANSCHAR_ELEMENT_CODEPOINT;
			}
		}
		else
		{
			++cpRangeC;
			if (cpRangeC <= cpRangeE)
			{
				*ppElement	= (LPVOID)cpRangeC;
				return PTRANSCHAR_ELEMENT_CODEPOINT;
			}
		}
		//	�ȉ��͔͈͊O�ɂȂ����ꍇ�̏����ł���B
		//	�͈͒��̏ꍇ�AcpCurrent �� - ���w���Ă���̂ŁA
		//	�͈͂��甲����Ƃ��� 2 �����i�߂�K�v������B
		InitState();
		ciBuffer.Next();
		ciBuffer.Next();
	}

	//------------------------------------------------------------
	//	�ȉ��͔͈͒��ł͂Ȃ��ꍇ
	//------------------------------------------------------------
	if (!PCTEXT_GETVALIDCP(ciBuffer.GetCurrentCp(&cpCurrent)))	return PTRANSCHAR_ELEMENT_END;

	//------------------------------------------------------------
	//	���ʂȏ������K�v�ƂȂ�̂� \�A- �� [. �̏ꍇ�ŁA������� cpNext ���K�v�ł���B
	//	���������� cpNext �������Ȃ��ꍇ�� cpCurrent ��Ԃ��A���̕����Ɉړ������Ă����B
	//------------------------------------------------------------
	if (!PCTEXT_GETVALIDCP(ciBuffer.GetNextCp(&cpNext)))
	{
		*ppElement	= (LPVOID)cpCurrent;
		cpRangeC	= cpCurrent;
		ciBuffer.Next();
		return PTRANSCHAR_ELEMENT_CODEPOINT;
	}

	//------------------------------------------------------------
	//	\ �̏ꍇ�� cpNext ��Ԃ��A���̎��Ɉړ������Ă����B
	//------------------------------------------------------------
	if (PLib::Unicode::IsEscape(cpCurrent, bIgnoreWidth))
	{
		*ppElement	= (LPVOID)cpNext;
		cpRangeC	= cpNext;
		ciBuffer.Next();
		ciBuffer.Next();
		return PTRANSCHAR_ELEMENT_CODEPOINT;
	}

	//------------------------------------------------------------
	//	- �̏ꍇ�AcpRangeC ���L���Ȓl�̏ꍇ�ɔ͈͒��Ƃ݂Ȃ��B
	//------------------------------------------------------------
	if ((PLib::Unicode::IsHyphen(cpCurrent, bIgnoreWidth) || (bIgnoreWidth && cpCurrent == (T_UCP)0x30FC))
		&& cpRangeC != INVALID_CODEPOINT)
	{
		if (cpRangeC < cpNext)
		{
			cpRangeE	= cpNext;
			bDescend	= false;
			++cpRangeC;
			*ppElement	= (LPVOID)cpRangeC;
			return PTRANSCHAR_ELEMENT_CODEPOINT;
		}
		else if (cpRangeC > cpNext)
		{
			cpRangeE	= cpNext;
			bDescend	= true;
			--cpRangeC;
			*ppElement	= (LPVOID)cpRangeC;
			return PTRANSCHAR_ELEMENT_CODEPOINT;
		}
		else	//	cpRangeC == cpNext	�͈͂̊J�n�ƏI��������
		{
			ciBuffer.Next();
			ciBuffer.Next();
			InitState();
			goto START;
		}
	}

	//------------------------------------------------------------
	//	[. �łȂ��ꍇ�� cpCurrent ��Ԃ��΂悢�B
	//------------------------------------------------------------
	if (!PLib::Unicode::IsLBracket(cpCurrent, bIgnoreWidth)	||
		!PLib::Unicode::IsPeriod(cpNext, bIgnoreWidth))
	{
		*ppElement	= (LPVOID)cpCurrent;
		cpRangeC	= cpCurrent;
		ciBuffer.Next();
		return PTRANSCHAR_ELEMENT_CODEPOINT;
	}

	//------------------------------------------------------------
	//	[. �̏ꍇ�� .] ��T���A�Ԃ̕������o�^����B
	//------------------------------------------------------------
	ciBuffer.Next();
	ciBuffer.Next();
	if (ciBuffer.End())	return PTRANSCHAR_ELEMENT_END;
	ciBuffer.GetCurrentPos(itrB);
	while (!ciBuffer.End())
	{
		//	. �łȂ��Ȃ玟�̕����𒲂ׂ�B
		if (!PCTEXT_GETVALIDCP(ciBuffer.GetCurrentCp(&cpCurrent)))	THROWPE_SYNTAX_ERROR("");
		if (!PLib::Unicode::IsPeriod(cpCurrent, bIgnoreWidth))
		{
			ciBuffer.Next();
			continue;
		}
		//	����ȍ~�� . �����������ꍇ�̏����B�܂��A�ʒu���L�^���Ă����B
		ciBuffer.GetCurrentPos(itrE);
		//	. �̎��̕������擾�ł��Ȃ��Ȃ當�@�G���[�ł���B
		if (!ciBuffer.Next())	THROWPE_SYNTAX_ERROR("");
		if (!PCTEXT_GETVALIDCP(ciBuffer.GetCurrentCp(&cpCurrent)))	THROWPE_SYNTAX_ERROR("");
		//	. �̎��̕����� ] �łȂ��Ȃ�A���̎��̕������璲�ג����B
		if (!PLib::Unicode::IsRBracket(cpCurrent, bIgnoreWidth))
		{
			ciBuffer.Next();
			continue;
		}
		//	.] �����������烋�[�v���甲����B
		break;
	}
	//	.] �����������ꍇ�A���݈ʒu�� ] �ł���B
	if (ciBuffer.End())		return PTRANSCHAR_ELEMENT_END;
	if (pciBase == NULL)	THROWPE_LOGIC_ERROR("");
	ps	= pciBase->AllocateUCPString();
	if (bNormalize)
	{
		if (!PLib::Unicode::GetDecomposition(ps, itrB, itrE))	THROWPE_LOGIC_ERROR("");
	}
	else
	{
		ps->assign(itrB, itrE);
	}
	*ppElement	= (LPVOID)ps;
	InitState();
	ciBuffer.Next();
	return PTRANSCHAR_ELEMENT_STRING;
}


//======================================================================
//	class PCTransChar
//======================================================================
//----------------------------------------------------------------------
//	PCTransChar	�R���X�g���N�^�ƃf�X�g���N�^
//----------------------------------------------------------------------
PCTransChar::PCTransChar()
:	zMaxStrLength(0),
	bNormalize(true),
	bComplement(false),
	bDelete(false),
	bIgnoreWidth(true)
{
}

PCTransChar::~PCTransChar()
{
	Clear();
}

//----------------------------------------------------------------------
//	PCTransChar::ClearMap
//----------------------------------------------------------------------
void PCTransChar::ClearMap()
{
	ITR_STRMAP	itr_sm;

	ciCpMap.clear();
	ciFCpSet.clear();

	for (itr_sm = ciStrMap.begin(); itr_sm != ciStrMap.end(); ++itr_sm)
	{
		DeallocateUCPString(itr_sm->first);
		DeallocateUCPString(itr_sm->second);
	}
	ciStrMap.clear();
}

//----------------------------------------------------------------------
//	PCTransChar::Clear
//----------------------------------------------------------------------
void PCTransChar::Clear()
{
	ClearMap();

	zMaxStrLength	= 0;
	bNormalize		= true;
	bComplement		= false;
	bDelete			= false;
	bIgnoreWidth	= true;
}


//----------------------------------------------------------------------
//	PCTransChar::SetOpt
//----------------------------------------------------------------------
#define	MATCHCP_OPT(cp1, cp2)	\
	(PLib::Unicode::CompareCodepointUCD((cp1), (cp2), NORM_IGNOREWIDTH, NULL) == CSTR_EQUAL)

bool PCTransChar::SetOpt(T_PCSTR_U pSrc, size_t zSrc)
{
	T_PCSTR_U	pc		= pSrc;
	T_PCSTR_U	pe		= pSrc + zSrc;
	bool		bSet	= true;

	if (pc == NULL)	return true;
	while (pc < pe)
	{
		if (MATCHCP_OPT(*pc, (T_UCP)L'-'))
		{
			bSet	= false;
		}
		else if (MATCHCP_OPT(*pc, (T_UCP)L'n'))
		{
			bNormalize	= bSet;
		}
		else if (MATCHCP_OPT(*pc, (T_UCP)L'c'))
		{
			bComplement	= bSet;
		}
		else if (MATCHCP_OPT(*pc, (T_UCP)L'd'))
		{
			bDelete	= bSet;
		}
		else if (MATCHCP_OPT(*pc, (T_UCP)L'w'))
		{
			bIgnoreWidth	= bSet;
		}
		++pc;
	}
	return true;
}

//----------------------------------------------------------------------
//	PCTransChar::AppendCpTrans
//----------------------------------------------------------------------
bool PCTransChar::AppendCpTrans(T_UCP cSrc, T_UCP cDst)
{
	std::pair<ITR_CPMAP, bool>	res;

	res	= ciCpMap.insert(PAIR_CPMAP(cSrc, cDst));
	return res.second;
}

//----------------------------------------------------------------------
//	PCTransChar::AppendStrTrans
//----------------------------------------------------------------------
bool PCTransChar::AppendStrTrans(UCPSTRING* pcpsSrc, UCPSTRING* pcpsDst)
{
	std::pair<ITR_STRMAP, bool>		res;
	PLib::Unicode::PSDECOMPOSITION*	pDcmp	= NULL;
	UCPSTRING*					pucsSrcReg	=NULL;
	UCPSTRING					ucsTemp;

	pucsSrcReg	= AllocateUCPString();
	if (bNormalize)
	{
		if (!PLib::Unicode::GetDecomposition(pucsSrcReg, pcpsSrc))	goto ERROR_HANDLING;
	}
	else
	{
		pucsSrcReg->assign(*pcpsSrc);
	}
	res	= ciStrMap.insert(PAIR_STRMAP(pucsSrcReg, pcpsDst));
	DeallocateUCPString(pcpsSrc);
	pcpsSrc	= NULL;
	if (!res.second)	goto ERROR_HANDLING;

	//	�����p�ɁA�擪�̕�����o�^���Ă����B
	ciFCpSet.insert(*(pucsSrcReg->begin()));

	//	�����̏I�������p�ɕ�����̍ő咷�����߂Ă����B
	if (zMaxStrLength < pucsSrcReg->size())	zMaxStrLength = pucsSrcReg->size();
	return true;

ERROR_HANDLING:
	if (pucsSrcReg != NULL)	DeallocateUCPString(pucsSrcReg);
	if (pcpsDst != NULL)	DeallocateUCPString(pcpsDst);
	return false;
}

//----------------------------------------------------------------------
//	PCTransChar::AppendStrTrans
//----------------------------------------------------------------------
bool PCTransChar::AppendStrTrans(const T_UCP* pczSrc, const T_UCP* pczDst)
{
	UCPSTRING	*ps1, *ps2;

	if (pczSrc == NULL || pczDst == NULL)	return false;

	ps1	= AllocateUCPString();
	ps2	= AllocateUCPString();
	ps1->assign(pczSrc);
	ps2->assign(pczDst);
	return AppendStrTrans(ps1, ps2);
}

//----------------------------------------------------------------------
//	PCTransChar::SetTrans
//----------------------------------------------------------------------
bool PCTransChar::SetTrans(PCTrBuffer* pciSrcBuf, PCTrBuffer* pciDstBuf)
{
	int			iTypeS, iTypeD;
	LPVOID		pSrc, pDst;
	UCPSTRING*	pucsTemp;

	//------------------------------------------------------------
	//	�ϊ�����ꍇ (bDelete = false)
	//------------------------------------------------------------
	if (!bDelete)
	{
		pDst	= (LPVOID)INVALID_CODEPOINT;

		for (pciSrcBuf->Begin(), pciDstBuf->Begin(); !pciSrcBuf->End();)
		{
			iTypeS	= pciSrcBuf->GetElement(&pSrc, bNormalize);
			if (iTypeS == PTRANSCHAR_ELEMENT_END)	break;

			iTypeD	= pciDstBuf->GetElement(&pDst, bNormalize);

			//----------------------------------------
			//	�R�[�h�|�C���g -> �R�[�h�|�C���g
			//----------------------------------------
			if (iTypeS == PTRANSCHAR_ELEMENT_CODEPOINT && iTypeD == PTRANSCHAR_ELEMENT_CODEPOINT)
			{
				AppendCpTrans((T_UCP)pSrc, (T_UCP)pDst);
				continue;
			}
			//----------------------------------------
			//	�R�[�h�|�C���g -> ������
			//----------------------------------------
			else if (iTypeS == PTRANSCHAR_ELEMENT_CODEPOINT && iTypeD == PTRANSCHAR_ELEMENT_STRING)
			{
				pucsTemp	= AllocateUCPString();
				pucsTemp->assign(1, (T_UCP)pSrc);
				AppendStrTrans(pucsTemp, (UCPSTRING*)pDst);
				continue;
			}
			//----------------------------------------
			//	�R�[�h�|�C���g -> �Ή��Ȃ�
			//----------------------------------------
			else if (iTypeS == PTRANSCHAR_ELEMENT_CODEPOINT && iTypeD == PTRANSCHAR_ELEMENT_END)
			{
				AppendCpTrans((T_UCP)pSrc, (T_UCP)pDst);
				continue;
			}
			//----------------------------------------
			//	������ -> �R�[�h�|�C���g
			//----------------------------------------
			else if (iTypeS == PTRANSCHAR_ELEMENT_STRING && iTypeD == PTRANSCHAR_ELEMENT_CODEPOINT)
			{
				pucsTemp	= AllocateUCPString();
				pucsTemp->assign(1, (T_UCP)pDst);
				AppendStrTrans((UCPSTRING*)pSrc, pucsTemp);
				continue;
			}
			//----------------------------------------
			//	������ -> ������
			//----------------------------------------
			else if (iTypeS == PTRANSCHAR_ELEMENT_STRING && iTypeD == PTRANSCHAR_ELEMENT_STRING)
			{
				AppendStrTrans((UCPSTRING*)pSrc, (UCPSTRING*)pDst);
				continue;
			}
			//----------------------------------------
			//	������ -> �Ή��Ȃ�
			//----------------------------------------
			else if (iTypeS == PTRANSCHAR_ELEMENT_STRING && iTypeD == PTRANSCHAR_ELEMENT_END)
			{
				pucsTemp	= AllocateUCPString();
				pucsTemp->assign(1, (T_UCP)pDst);
				AppendStrTrans((UCPSTRING*)pSrc, pucsTemp);
				continue;
			}
		}
	}
	//------------------------------------------------------------
	//	�폜����ꍇ (bDelete = false)
	//------------------------------------------------------------
	else
	{
		for (pciSrcBuf->Begin(), pciDstBuf->Begin(); !pciSrcBuf->End();)
		{
			iTypeS	= pciSrcBuf->GetElement(&pSrc, bNormalize);
			if (iTypeS == PTRANSCHAR_ELEMENT_END)	break;

			if (iTypeS == PTRANSCHAR_ELEMENT_CODEPOINT)
			{
				AppendCpTrans((T_UCP)pSrc, INVALID_CODEPOINT);
				continue;
			}
			else if (iTypeS == PTRANSCHAR_ELEMENT_STRING)
			{
				pucsTemp	= AllocateUCPString();
				pucsTemp->clear();
				AppendStrTrans((UCPSTRING*)pSrc, pucsTemp);
				continue;
			}
		}
	}
	return true;
}

//----------------------------------------------------------------------
//	PCTransChar::SetTrans
//----------------------------------------------------------------------
bool PCTransChar::SetTrans(T_PCSTR_U pSrcB, T_PCSTR_U pSrcE, T_PCSTR_U pDstB, T_PCSTR_U pDstE)
{
	PCTrBuffer	ciSrcBuf(this);
	PCTrBuffer	ciDstBuf(this);

	ciSrcBuf.SetOptIgnoreWidth(bIgnoreWidth);
	ciDstBuf.SetOptIgnoreWidth(bIgnoreWidth);

	ciSrcBuf.Set(pSrcB, pSrcE);
	ciDstBuf.Set(pDstB, pDstE);
	return SetTrans(&ciSrcBuf, &ciDstBuf);
}

//----------------------------------------------------------------------
//	PCTransChar::SetTrans
//----------------------------------------------------------------------
bool PCTransChar::SetTrans(T_PCSTR_U pSrc, size_t zSrc, T_PCSTR_U pDst, size_t zDst)
{
	PCTrBuffer	ciSrcBuf(this);
	PCTrBuffer	ciDstBuf(this);

	ciSrcBuf.SetOptIgnoreWidth(bIgnoreWidth);
	ciDstBuf.SetOptIgnoreWidth(bIgnoreWidth);

	ciSrcBuf.Set(pSrc, zSrc);
	ciDstBuf.Set(pDst, zDst);
	return SetTrans(&ciSrcBuf, &ciDstBuf);
}

//----------------------------------------------------------------------
//	PCTransChar::SetTrans
//----------------------------------------------------------------------
bool PCTransChar::SetTrans(T_PCSTR_U pszSrc, T_PCSTR_U pszDst)
{
	PCTrBuffer	ciSrcBuf(this);
	PCTrBuffer	ciDstBuf(this);

	ciSrcBuf.SetOptIgnoreWidth(bIgnoreWidth);
	ciDstBuf.SetOptIgnoreWidth(bIgnoreWidth);

	ciSrcBuf.Set(pszSrc);
	ciDstBuf.Set(pszDst);
	return SetTrans(&ciSrcBuf, &ciDstBuf);
}


//----------------------------------------------------------------------
//	PCTransChar::Translate	(1)
//----------------------------------------------------------------------
bool PCTransChar::Translate(UCPSTRING* pucsDst, UCPSTRING* pucsSrc)
{
	ITR_UCPSTRING	itrSrc, itrSrcNext, itrTemp;
	UCPSTRING		ucsDst, ucsTemp;
	ITR_STRMAP		itrStrMap;
	ITR_CPSET		itrFStr;
	ITR_CPMAP		itrCpMap;
	bool			bFound;

	itrSrc	= pucsSrc->begin();
	while (itrSrc != pucsSrc->end())
	{
		//--------------------------------------------------
		//	ciStrMap �Ɉ�v������̂����邩���ׂ�B
		//	(1)	�܂��A�擪�̕������o�^����Ă��邩�𒲂ׂ�B
		//--------------------------------------------------
		if (ciStrMap.empty())	goto TRANS_CODEPAGE;
		ucsTemp.clear();
		ucsDst.clear();
		itrSrcNext	= itrSrc;
		itrTemp		= itrSrc;
		bFound		= false;

		if (bNormalize)
		{
			PLib::Unicode::GetDecomposition(&ucsTemp, *itrTemp);
		}
		else
		{
			ucsTemp.append(1, *itrTemp);
		}
		itrFStr	= ciFCpSet.find(*(ucsTemp.begin()));
		if (itrFStr == ciFCpSet.end())	goto TRANS_CODEPAGE;

		//--------------------------------------------------
		//	(2)	�����𑝂₵�Ȃ���A��v������̂����邩���ׂ�B
		//--------------------------------------------------

		while (true)
		{
			if (ucsTemp.size() > zMaxStrLength)	break;

			itrStrMap	= ciStrMap.find(&ucsTemp);
			if (itrStrMap != ciStrMap.end())
			{
				ucsDst.assign(*(itrStrMap->second));
				itrSrcNext	= itrTemp;
				bFound		= true;
			}

			++itrTemp;
			if (itrTemp == pucsSrc->end())	break;

			if (bNormalize)
			{
				PLib::Unicode::GetDecomposition(&ucsTemp, *itrTemp);
			}
			else
			{
				ucsTemp.append(1, *itrTemp);
			}
		}

		if (bFound)
		{
			pucsDst->append(ucsDst);
			itrSrc	= itrSrcNext;
			++itrSrc;
			continue;
		}

TRANS_CODEPAGE:
		//--------------------------------------------------
		//	ciCpMap 
		//--------------------------------------------------
		itrCpMap	= ciCpMap.find(*itrSrc);
		if (itrCpMap != ciCpMap.end())
		{
			pucsDst->append(1, itrCpMap->second);
		}
		else
		{
			pucsDst->append(1, *itrSrc);
		}
		++itrSrc;
	}
	return true;
}

//----------------------------------------------------------------------
//	PCTransChar::Translate	(2-1)
//----------------------------------------------------------------------
T_UCP PCTransChar::Translate(T_UCP cSrc)
{
	ITR_CPMAP		itrCpMap;

	itrCpMap	= ciCpMap.find(cSrc);
	if (itrCpMap != ciCpMap.end())
	{
		return itrCpMap->second;
	}
	return cSrc;
}

//----------------------------------------------------------------------
//	PCTransChar::Translate	(3-1)
//----------------------------------------------------------------------
bool PCTransChar::Translate(T_STRING_U* pstrDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE)
{
	UCPSTRING	ucsSrc, ucsDst;

	if (!PLib::Unicode::ConvertToCodepoint(&ucsSrc, pSrcB, pSrcE))	return false;
	if (!Translate(&ucsDst, &ucsSrc))	return false;
	return PLib::Unicode::ConvertFromCodepoint(pstrDst, &ucsDst);
}

//----------------------------------------------------------------------
//	PCTransChar::Translate	(3-2)
//----------------------------------------------------------------------
bool PCTransChar::Translate(T_STRING_U* pstrDst, T_PCSTR_U pSrc, size_t zStr)
{
	UCPSTRING	ucsSrc, ucsDst;

	if (!PLib::Unicode::ConvertToCodepoint(&ucsSrc, pSrc, pSrc + zStr))	return false;
	if (!Translate(&ucsDst, &ucsSrc))	return false;
	return PLib::Unicode::ConvertFromCodepoint(pstrDst, &ucsDst);
}

//----------------------------------------------------------------------
//	PCTransChar::Translate	(3-3)
//----------------------------------------------------------------------
bool PCTransChar::Translate(T_STRING_U* pstrDst, T_PCSTR_U pszSrc)
{
	UCPSTRING	ucsSrc, ucsDst;

	if (!PLib::Unicode::ConvertToCodepoint(&ucsSrc, pszSrc))	return false;
	if (!Translate(&ucsDst, &ucsSrc))	return false;
	return PLib::Unicode::ConvertFromCodepoint(pstrDst, &ucsDst);
}

//----------------------------------------------------------------------
//	PCTransChar::Debug
//----------------------------------------------------------------------
#ifdef	PDEBUG
void PCTransChar::Debug(T_STRING_U* pstrDebug)
{
	ITR_CPMAP	itr_cpm;
	ITR_STRMAP	itr_stm;
	ITR_CPSET	itr_fcs;

	T_CHAR_U	wcBuf[3];
	T_PCSTR_U	pTR	= TQU(" -> ");
	T_PCSTR_U	pLF	= TQU("\r\n");
	T_PCSTR_U	pCM	= TQU(", ");

	pstrDebug->append(TQU("[Codepoint Map]\r\n"));
	for (itr_cpm = ciCpMap.begin(); itr_cpm != ciCpMap.end(); ++itr_cpm)
	{
		PLib::Unicode::ConvertFromCodepoint(wcBuf, itr_cpm->first);
		pstrDebug->append(wcBuf);
		pstrDebug->append(pTR);
		PLib::Unicode::ConvertFromCodepoint(wcBuf, itr_cpm->second);
		pstrDebug->append(wcBuf);
		pstrDebug->append(pLF);
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("[String Map]\r\n"));
	for (itr_stm = ciStrMap.begin(); itr_stm != ciStrMap.end(); ++itr_stm)
	{
		PLib::Unicode::ConvertFromCodepoint(pstrDebug, itr_stm->first);
		pstrDebug->append(pTR);
		PLib::Unicode::ConvertFromCodepoint(pstrDebug, itr_stm->second);
		pstrDebug->append(pLF);
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("[First Char of String]\r\n"));
	for (itr_fcs = ciFCpSet.begin(); itr_fcs != ciFCpSet.end(); ++itr_fcs)
	{
		if (itr_fcs != ciFCpSet.begin())	pstrDebug->append(pCM);
		if (PLib::Unicode::ConvertFromCodepoint(wcBuf, *itr_fcs))
		{
			pstrDebug->append(wcBuf);
		}
	}
	pstrDebug->append(pLF);
}
#endif

NS_PLIB_END
