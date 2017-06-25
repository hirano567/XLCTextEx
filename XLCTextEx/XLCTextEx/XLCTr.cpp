//	XLCTextEx_1.0x	:	XLCTextEx

// XLCTr.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
//
#include "stdafx.h"

T_PCSTR_U	pszNull	= TQU("");

//======================================================================
//	SetTrOption
//======================================================================
bool SetTrOption(CTRANSCHAR* pTrChar, bool* pbQuoted, XLOPER12* pxOpt)
{
	size_t	zt;

	if (pxOpt != NULL)
	{
		switch (pxOpt->xltype)
		{
		case xltypeStr:
			if (pxOpt->val.str != NULL && *(pxOpt->val.str) != 0)
			{
				zt	= XLL::GetXLOPER_StrSize<XLOPER12>(pxOpt);
				if (zt > 0)
				{
					pTrChar->SetOpt(pxOpt->val.str + 1, zt);
					*pbQuoted	= XLL::XLIsOptionSet<T_CHAR_U, XLOPER12>(pxOpt, TQU("q"));
				}
			}
			break;

		default:
			break;
		}
	}
	return true;
}


//======================================================================
//	XLCTrCreate12
//======================================================================
XLOPER12* WINAPI XLCTrCreate12(XLOPER12* pxId, XLOPER12* pxSrc, XLOPER12* pxDst, XLOPER12* pxOpt)
{
	XLOPER12*	pxRet12		= NULL;
	CTRANSCHAR*	pciTrChar	= NULL;
	int			iId;
	T_PCSTR_U	pSrcB, pSrcE;
	T_PCSTR_U	pDstB, pDstE;
	//size_t		zSrc, zDst, zt;
	DWORD		dwCSFlags	= NORM_IGNOREWIDTH;
	LCID		dwLocale	= LOCALE_USER_DEFAULT;
	bool		bQuoted	= false;

	static T_CHAR_U	NullStr[1]	= { (T_CHAR_U)0 };	//	�󕶎���p�̃_�~�[

	try
	{
		pxRet12	= XLL::AllocateXLOPER<XLOPER12>();
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		return NULL;
	}
	catch (...)
	{
		return NULL;
	}

	//------------------------------------------------------------
	//	�������`�F�b�N����B
	//	���͒��ɌĂяo����邱�Ƃ�����̂ŁAErr �ł͂Ȃ� Nil ��Ԃ��B
	//------------------------------------------------------------
	if (!PLib::IsPageReadWrite((LPVOID)pxId)	||
		!PLib::IsPageReadWrite((LPVOID)pxSrc)	||
		!PLib::IsPageReadWrite((LPVOID)pxDst)	||
		!PLib::IsPageReadWrite((LPVOID)pxOpt))
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, TRUE);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, TRUE);
	}

	//------------------------------------------------------------
	//	�����̃`�F�b�N
	//------------------------------------------------------------
	if (pxId == NULL || pxSrc == NULL || pxDst == NULL)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrValue, TRUE);
		return pxRet12;
	}

	//------------------------------------------------------------
	//	�����̏���	(1)	pxId	���蓖�Ă� ID
	//	pxId �� NULL �Ȃ�G���[�l��Ԃ��B
	//	*pxId �� xltypeNum �� xltypeInt �łȂ炻�̒l�����o���B
	//	����ȊO�̏ꍇ�� FALSE ��Ԃ��B
	//------------------------------------------------------------
	switch (pxId->xltype)
	{
	case xltypeNum:
		iId	= (int)pxId->val.num;
		break;

	case xltypeInt:
		iId	= (int)pxId->val.w;
		break;

	default:
		XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrValue, TRUE);
		return pxRet12;
		break;
	}

	//------------------------------------------------------------
	//	PCTransChar �N���X�̃C���X�^���X���쐬����B�����̏ꍇ�͂�����g�p����B
	//------------------------------------------------------------
	if (pciTrManager == NULL)
	{
		return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrNull, TRUE);
	}
	pciTrChar	= pciTrManager->Create(iId);
	if (pciTrChar == NULL)
	{
		return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrNull, TRUE);
	}
	pciTrChar->Clear();

	//------------------------------------------------------------
	//	�����̏���	(2)	pxOpt
	//------------------------------------------------------------
	SetTrOption(pciTrChar, &bQuoted, pxOpt);

	//------------------------------------------------------------
	//	�����̏���	(3)	pxSrc
	//------------------------------------------------------------
	if (!XLL::XLGetString<T_CHAR_U, XLOPER12>(&pSrcB, &pSrcE, pxSrc, pszNull, bQuoted))
		goto ERROR_HANDLING;

	//------------------------------------------------------------
	//	�����̏���	(4)	pxDst
	//------------------------------------------------------------
	if (!XLL::XLGetString<T_CHAR_U, XLOPER12>(&pDstB, &pDstE, pxDst, pszNull, bQuoted))
		goto ERROR_HANDLING;

	//------------------------------------------------------------
	//	�o�^����B
	//------------------------------------------------------------
	if (!pciTrChar->SetTrans(pSrcB, pSrcE, pDstB, pDstE))	goto ERROR_HANDLING;

	//------------------------------------------------------------
	//	�I���B�w�肳�ꂽ ID ��Ԃ��B
	//------------------------------------------------------------
	return XLL::SetXLOPER_Num<XLOPER12>(pxRet12, (double)iId, TRUE);

ERROR_HANDLING:
	pciTrManager->Delete(iId);
	return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrNull, TRUE);
}

//======================================================================
//	XLCTrCreate4
//======================================================================
XLOPER* WINAPI XLCTrCreate4(XLOPER* pxId4, XLOPER* pxSrc4, XLOPER* pxDst4, XLOPER* pxOpt4)
{
	XLL::XLOPERConverter<PLib::PCMAlloc>	ciConverter;
	XLOPER12	xId12, xSrc12, xDst12, xOpt12;
	XLOPER12*	pxRet12;
	XLOPER*		pxRet4	= NULL;

	try
	{
		pxRet4	= XLL::AllocateXLOPER<XLOPER>();
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		return NULL;
	}
	catch (...)
	{
		return NULL;
	}

	//------------------------------------------------------------
	//	�������L�����`�F�b�N����B
	//	���͂��������Ȃ������ɌĂяo����邱�Ƃ�����̂ŁAErr �ł͂Ȃ� Nil ��Ԃ��B
	//------------------------------------------------------------
	if (!PLib::IsPageReadWrite((LPVOID)pxId4)	||
		!PLib::IsPageReadWrite((LPVOID)pxSrc4)	||
		!PLib::IsPageReadWrite((LPVOID)pxDst4)	||
		!PLib::IsPageReadWrite((LPVOID)pxOpt4))
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, TRUE);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, TRUE);
	}

	//------------------------------------------------------------
	//	�ϐ��̒l��ݒ肷��B
	//------------------------------------------------------------
	xId12.xltype	= xltypeNil;
	xSrc12.xltype	= xltypeNil;
	xDst12.xltype	= xltypeNil;
	xOpt12.xltype	= xltypeNil;

	if (!ciConverter.Convert<XLOPER12, XLOPER>(&xId12, pxId4)	||
		!ciConverter.Convert<XLOPER12, XLOPER>(&xSrc12, pxSrc4)	||
		!ciConverter.Convert<XLOPER12, XLOPER>(&xDst12, pxDst4)	||
		!ciConverter.Convert<XLOPER12, XLOPER>(&xOpt12, pxOpt4))
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
		goto END_PROCESSING;
	}

	//------------------------------------------------------------
	//	�p�^�[����o�^����B
	//------------------------------------------------------------
	try
	{
		pxRet12	= XLCTrCreate12(&xId12, &xSrc12, &xDst12, &xOpt12);
		if (pxRet12 != NULL && ciConverter.Convert<XLOPER, XLOPER12>(pxRet4, pxRet12))
		{
			XLL::SetDLLFree(pxRet4);
		}
		else
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
		}
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
	}

	//------------------------------------------------------------
	//	�I������
	//------------------------------------------------------------
END_PROCESSING:
	XLL::DeleteXLOPER<XLOPER12>(&xId12);
	XLL::DeleteXLOPER<XLOPER12>(&xSrc12);
	XLL::DeleteXLOPER<XLOPER12>(&xDst12);
	XLL::DeleteXLOPER<XLOPER12>(&xOpt12);
	XLL::DeleteXLOPER<XLOPER12>(pxRet12);
	return pxRet4;
}

//======================================================================
//	XLCTrDelete12
//======================================================================
XLOPER12* WINAPI XLCTrDelete12(XLOPER12* pxId)
{
	XLOPER12*	pxRet12	= NULL;
	int			iId;
	CTRANSCHAR*	pciTrChar	= NULL;

	try
	{
		pxRet12	= XLL::AllocateXLOPER<XLOPER12>();
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		return NULL;
	}
	catch (...)
	{
		return NULL;
	}

	//------------------------------------------------------------
	//	�������`�F�b�N����B
	//	���͒��ɌĂяo����邱�Ƃ�����̂ŁAErr �ł͂Ȃ� Nil ��Ԃ��B
	//------------------------------------------------------------
	if (!PLib::IsPageReadWrite((LPVOID)pxId))
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, TRUE);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, TRUE);
	}

	//------------------------------------------------------------
	//	�������`�F�b�N���āA�ԍ������o���B
	//------------------------------------------------------------

	switch (pxId->xltype)
	{
	case xltypeNum:
		iId	= (int)pxId->val.num;
		break;

	case xltypeInt:
		iId	= (int)pxId->val.w;
		break;

	default:
		XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrValue, TRUE);
		return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrValue, TRUE);
		break;
	}

	//------------------------------------------------------------
	//	�C���X�^���X���폜����B
	//	Delete() �͑��݂��Ă��Ȃ������ꍇ�� FALSE ��Ԃ����A���̊֐������ TRUE ��Ԃ��B
	//------------------------------------------------------------
	if (pciTrManager == NULL)
	{
		return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrNull, TRUE);
	}
	pciTrChar	= pciTrManager->Find(iId);
	if (pciTrChar != NULL)
	{
		pciTrChar->Clear();
		pciTrManager->Delete(iId);
	}
	return XLL::SetXLOPER_Bool<XLOPER12>(pxRet12, TRUE, TRUE);
}

//======================================================================
//	XLCTrDelete4
//======================================================================
XLOPER* WINAPI XLCTrDelete4(XLOPER* pxId4)
{
	XLL::XLOPERConverter<PLib::PCMAlloc>	ciConverter;

	XLOPER12	xId12;
	XLOPER12*	pxRet12	= NULL;
	XLOPER*		pxRet4	= NULL;

	try
	{
		pxRet4	= XLL::AllocateXLOPER<XLOPER>();
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		return NULL;
	}
	catch (...)
	{
		return NULL;
	}

	//------------------------------------------------------------
	//	�������`�F�b�N����B
	//	���͒��ɌĂяo����邱�Ƃ�����̂ŁAErr �ł͂Ȃ� Nil ��Ԃ��B
	//------------------------------------------------------------
	if (!PLib::IsPageReadWrite((LPVOID)pxId4))
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, TRUE);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, TRUE);
	}

	//------------------------------------------------------------
	//	�ϐ��̒l��ݒ肷��B
	//------------------------------------------------------------
	xId12.xltype	= xltypeNil;
	if (!ciConverter.Convert<XLOPER12, XLOPER>(&xId12, pxId4))
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
		goto END_PROCESSING;
	}

	//------------------------------------------------------------
	//	�p�^�[�����폜���A�Ԃ�l��ݒ肷��B
	//------------------------------------------------------------
	try
	{
		pxRet12	= XLCTrDelete12(&xId12);
		if (pxRet12 != NULL && ciConverter.Convert<XLOPER, XLOPER12>(pxRet4, pxRet12))
		{
			XLL::SetDLLFree(pxRet4);
		}
		else
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
		}
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
	}

	//------------------------------------------------------------
	//	�I������
	//------------------------------------------------------------
END_PROCESSING:
	XLL::DeleteXLOPER<XLOPER12>(&xId12);
	XLL::DeleteXLOPER<XLOPER12>(pxRet12);
	return pxRet4;
}

//======================================================================
//	XLCTr12
//======================================================================
XLOPER12* WINAPI XLCTr12(XLOPER12* pxArg1, XLOPER12* pxArg2, XLOPER12* pxArg3, XLOPER12* pxArg4)
{
	CTRANSCHAR	ciTrCharTemp;
	CTRANSCHAR*	pciTrChar	= NULL;

	XLOPER12*	pxRet12	= NULL;
	XLOPER12*	pxTxt	= NULL;
	int			iId;
	bool		bQuoted	= false;
	T_PCSTR_U	pSrcB, pSrcE;
	T_PCSTR_U	pDstB, pDstE;
	T_PCSTR_U	pTxtB, pTxtE;
	T_STRING_U	strBuffer;

	try
	{
		pxRet12	= XLL::AllocateXLOPER<XLOPER12>();
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		return NULL;
	}
	catch (...)
	{
		return NULL;
	}

	if (pxArg1 == NULL)	return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrNull, TRUE);

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, TRUE);
	}

	//------------------------------------------------------------
	//	xltypeNum�AxltypeInt �̏ꍇ�o�^ ID �Ŏw�肳�ꂽ�Ƃ݂Ȃ��B
	//	pxArg2 �ɑΏۃe�L�X�g���i�[����Ă���Ƃ��ď������s���B
	//------------------------------------------------------------
	if (pxArg1->xltype == xltypeNum || pxArg1->xltype == xltypeInt)
	{
		if (pxArg1->xltype == xltypeNum)
		{
			iId	= (int)pxArg1->val.num;
		}
		else
		{
			iId	= (int)pxArg1->val.w;
		}

		if (pciTrManager == NULL)
		{
			return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrNull, TRUE);
		}
		pciTrChar	= pciTrManager->Find(iId);
		if (pciTrChar == NULL)
		{
			return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrValue, TRUE);
		}
		SetTrOption(&ciTrCharTemp, &bQuoted, pxArg3);
		pxTxt	= pxArg2;
	}
	//------------------------------------------------------------
	//	pxArg1 �� xltypeStr �̏ꍇ�A�����W�������ڎw�肳�ꂽ�Ƃ݂Ȃ��B
	//	xltypeNil, xltypeMissing �̏ꍇ�A�����W���Ȃ��Ƃ��ď����𑱂���B
	//	pxArg1 �� Src�ApxArg2 �� Dst�ApxArg3 �� Txt�ApxArg4 �� Opt �ƂȂ�B
	//------------------------------------------------------------
	else if (	pxArg1->xltype == xltypeStr		||
				pxArg1->xltype == xltypeNil		||
				pxArg1->xltype == xltypeMissing)
	{
		SetTrOption(&ciTrCharTemp, &bQuoted, pxArg4);

		//	XLGetString �֐��́AxltypeNil�AxltypeMissing �̏ꍇ�A�󕶎�����Z�b�g����B
		if (!XLL::XLGetString<T_CHAR_U, XLOPER12>(&pSrcB, &pSrcE, pxArg1, pszNull, bQuoted))
			return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrValue, TRUE);

		if (!XLL::XLGetString<T_CHAR_U, XLOPER12>(&pDstB, &pDstE, pxArg2, pszNull, bQuoted))
			return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrValue, TRUE);

		if (!ciTrCharTemp.SetTrans(pSrcB, pSrcE, pDstB, pDstE))
			return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrValue, TRUE);
		pciTrChar	= &ciTrCharTemp;
		pxTxt		= pxArg3;
	}
	//------------------------------------------------------------
	//	�ȏ�ɓ��Ă͂܂�Ȃ��ꍇ�̓G���[��Ԃ��B
	//------------------------------------------------------------
	else
	{
		return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrValue, TRUE);
	}

	//------------------------------------------------------------
	//	�������ϊ����ĕԂ��B
	//------------------------------------------------------------
	if (!XLL::XLGetString<T_CHAR_U, XLOPER12>(&pTxtB, &pTxtE, pxTxt, pszNull, bQuoted))
		return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrValue, TRUE);

	if (pciTrChar->Translate(&strBuffer, pTxtB, pTxtE))
	{
		XLL::SetXLOPER_Str<T_CHAR_U, XLOPER12>(
			pxRet12, strBuffer.c_str(), strBuffer.size(), TRUE);
		return pxRet12;
	}

	return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrNull, TRUE);
}

//======================================================================
//	XLCTr4
//======================================================================
XLOPER* WINAPI XLCTr4(XLOPER* pxArg4_1, XLOPER* pxArg4_2, XLOPER* pxArg4_3, XLOPER* pxArg4_4)
{
	XLL::XLOPERConverter<PLib::PCMAlloc>	ciConverter;
	XLOPER12	xArg12_1, xArg12_2, xArg12_3, xArg12_4;
	XLOPER12*	pxRet12	= NULL;
	XLOPER*		pxRet4	= NULL;

	try
	{
		pxRet4	= XLL::AllocateXLOPER<XLOPER>();
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		return NULL;
	}
	catch (...)
	{
		return NULL;
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, TRUE);
	}

	//------------------------------------------------------------
	//	�ϐ��̒l��ݒ肷��B
	//------------------------------------------------------------
	xArg12_1.xltype	= xltypeNil;
	if (PLib::IsPageReadWrite((LPVOID)pxArg4_1))
	{
		if (!ciConverter.Convert<XLOPER12, XLOPER>(&xArg12_1, pxArg4_1))
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
			goto END_PROCESSING;
		}
	}

	xArg12_2.xltype	= xltypeNil;
	if (PLib::IsPageReadWrite((LPVOID)pxArg4_2))
	{
		if (!ciConverter.Convert<XLOPER12, XLOPER>(&xArg12_2, pxArg4_2))
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
			goto END_PROCESSING;
		}
	}

	xArg12_3.xltype	= xltypeNil;
	if (PLib::IsPageReadWrite((LPVOID)pxArg4_3))
	{
		if (!ciConverter.Convert<XLOPER12, XLOPER>(&xArg12_3, pxArg4_3))
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
			goto END_PROCESSING;
		}
	}

	xArg12_4.xltype	= xltypeNil;
	if (PLib::IsPageReadWrite((LPVOID)pxArg4_4))
	{
		if (!ciConverter.Convert<XLOPER12, XLOPER>(&xArg12_4, pxArg4_4))
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
			goto END_PROCESSING;
		}
	}

	//------------------------------------------------------------
	//	���ۂ̏����� XLCRegExTextProcessing_exec ���s���B
	//------------------------------------------------------------
	try
	{
		pxRet12	= XLCTr12(&xArg12_1, &xArg12_2, &xArg12_3, &xArg12_4);
		if (pxRet12 != NULL && ciConverter.Convert<XLOPER, XLOPER12>(pxRet4, pxRet12))
		{
			XLL::SetDLLFree(pxRet4);
		}
		else
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
		}
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
	}

	//------------------------------------------------------------
	//	�I������
	//------------------------------------------------------------
END_PROCESSING:
	XLL::DeleteXLOPER<XLOPER12>(&xArg12_1);
	XLL::DeleteXLOPER<XLOPER12>(&xArg12_2);
	XLL::DeleteXLOPER<XLOPER12>(&xArg12_3);
	XLL::DeleteXLOPER<XLOPER12>(&xArg12_4);
	XLL::DeleteXLOPER<XLOPER12>(pxRet12);
	return pxRet4;
}


//======================================================================
//	PresetTranslate
//======================================================================
#define	TEXTEX_TR_PRESET_TOHIRAGANA		1
#define	TEXTEX_TR_PRESET_TOKATAKANA		2
#define	TEXTEX_TR_PRESET_TOZENKAKU		3
#define	TEXTEX_TR_PRESET_TOZENKAKUKANA	4
#define	TEXTEX_TR_PRESET_TOHANKAKU		5
#define	TEXTEX_TR_PRESET_NORMALIZEWIDTH	6

//----------------------------------------------------------------------
//	PresetTranslate12
//----------------------------------------------------------------------
XLOPER12* PresetTranslate12(int iType, XLOPER12* pxStr, XLOPER12* pxOpt)
{
	XLOPER12*	pxRet12	= NULL;
	bool		bQuoted	= false;
	T_PCSTR_U	pStrB, pStrE;
	T_STRING_U	strBuffer;
	bool		br;

	//------------------------------------------------------------
	//	�߂�l pxRet12 ���쐬����B
	//------------------------------------------------------------
	try
	{
		pxRet12	= XLL::AllocateXLOPER<XLOPER12>();
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		return NULL;
	}
	catch (...)
	{
		return NULL;
	}

	if (pxStr == NULL)	return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrNull, TRUE);
	//if (pxStr->xltype != xltypeStr) return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrValue, TRUE);

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, TRUE);
	}

	//------------------------------------------------------------
	//	q �I�v�V�����𒲂ׁA�Ώە���������o���B
	//------------------------------------------------------------
	bQuoted	= XLL::XLIsOptionSet<T_CHAR_U, XLOPER12>(pxOpt, TQU("q"));
	if (!XLL::XLGetString<T_CHAR_U, XLOPER12>(&pStrB, &pStrE, pxStr, pszNull, bQuoted))
	{
		return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrValue, TRUE);
	}

	//------------------------------------------------------------
	//	�������ϊ����ĕԂ��B
	//------------------------------------------------------------
	switch (iType)
	{
	case TEXTEX_TR_PRESET_TOHIRAGANA:
		br	= PLib::TextEx::ToHiragana(&strBuffer, pStrB, pStrE);
		break;

	case TEXTEX_TR_PRESET_TOKATAKANA:
		br	= PLib::TextEx::ToKatakana(&strBuffer, pStrB, pStrE);
		break;

	case TEXTEX_TR_PRESET_TOZENKAKU:
		br	= PLib::TextEx::ToZenkaku(&strBuffer, pStrB, pStrE);
		break;

	case TEXTEX_TR_PRESET_TOZENKAKUKANA:
		br	= PLib::TextEx::ToZenkakuKana(&strBuffer, pStrB, pStrE);
		break;

	case TEXTEX_TR_PRESET_TOHANKAKU:
		br	= PLib::TextEx::ToHankaku(&strBuffer, pStrB, pStrE);
		break;

	case TEXTEX_TR_PRESET_NORMALIZEWIDTH:
		br	= PLib::TextEx::WidthFolding(&strBuffer, pStrB, pStrE);
		break;

	default:
		THROWPE_LOGIC_ERROR("PresetTranslate12");
		break;
	}

	if (br)
	{
		XLL::SetXLOPER_Str<T_CHAR_U, XLOPER12>(
			pxRet12, strBuffer.c_str(), strBuffer.size(), TRUE);
		return pxRet12;
	}
	return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrNull, TRUE);
}

//----------------------------------------------------------------------
//	PresetTranslate4
//----------------------------------------------------------------------
XLOPER* PresetTranslate4(int iType, XLOPER* pxStr4, XLOPER* pxOpt4)
{
	XLL::XLOPERConverter<PLib::PCMAlloc>	ciConverter;
	XLOPER12	xStr12, xOpt12;
	XLOPER12*	pxRet12	= NULL;
	XLOPER*		pxRet4	= NULL;

	try
	{
		pxRet4	= XLL::AllocateXLOPER<XLOPER>();
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		return NULL;
	}
	catch (...)
	{
		return NULL;
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, TRUE);
	}

	//------------------------------------------------------------
	//	�ϐ��̒l��ݒ肷��B
	//------------------------------------------------------------
	xStr12.xltype	= xltypeNil;
	if (!PLib::IsPageReadWrite((LPVOID)pxStr4)	||
		!ciConverter.Convert<XLOPER12, XLOPER>(&xStr12, pxStr4))
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
		goto END_PROCESSING;
	}

	xOpt12.xltype	= xltypeNil;
	if (!PLib::IsPageReadWrite((LPVOID)pxOpt4)	||
		!ciConverter.Convert<XLOPER12, XLOPER>(&xOpt12, pxOpt4))
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
		goto END_PROCESSING;
	}

	//------------------------------------------------------------
	//	���ۂ̏����� PresetTranslate12 ���s���B
	//------------------------------------------------------------
	try
	{
		pxRet12	= PresetTranslate12(iType, &xStr12, &xOpt12);
		if (pxRet12 != NULL && ciConverter.Convert<XLOPER, XLOPER12>(pxRet4, pxRet12))
		{
			XLL::SetDLLFree(pxRet4);
		}
		else
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
		}
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
	}

	//------------------------------------------------------------
	//	�I������
	//------------------------------------------------------------
END_PROCESSING:
	XLL::DeleteXLOPER<XLOPER12>(&xStr12);
	XLL::DeleteXLOPER<XLOPER12>(&xOpt12);
	XLL::DeleteXLOPER<XLOPER12>(pxRet12);
	return pxRet4;
}

//======================================================================
//	XLCToHiragana12
//======================================================================
XLOPER12* WINAPI XLCToHiragana12(XLOPER12* pxStr, XLOPER12* pxOpt)
{
	return PresetTranslate12(TEXTEX_TR_PRESET_TOHIRAGANA, pxStr, pxOpt);
}

//======================================================================
//	XLCToHiragana4
//======================================================================
XLOPER* WINAPI	XLCToHiragana4(XLOPER* pxStr, XLOPER* pxOpt)
{
	return PresetTranslate4(TEXTEX_TR_PRESET_TOHIRAGANA, pxStr, pxOpt);
}

//======================================================================
//	XLCToKatakana12
//======================================================================
XLOPER12* WINAPI XLCToKatakana12(XLOPER12* pxStr, XLOPER12* pxOpt)
{
	return PresetTranslate12(TEXTEX_TR_PRESET_TOKATAKANA, pxStr, pxOpt);
}

//======================================================================
//	XLCToKatakana4
//======================================================================
XLOPER* WINAPI XLCToKatakana4(XLOPER* pxStr, XLOPER* pxOpt)
{
	return PresetTranslate4(TEXTEX_TR_PRESET_TOKATAKANA, pxStr, pxOpt);
}

//======================================================================
//	XLCToZenkaku12
//======================================================================
XLOPER12* WINAPI XLCToZenkaku12(XLOPER12* pxStr, XLOPER12* pxOpt)
{
	return PresetTranslate12(TEXTEX_TR_PRESET_TOZENKAKU, pxStr, pxOpt);
}

//======================================================================
//	XLCToZenkaku4
//======================================================================
XLOPER* WINAPI XLCToZenkaku4(XLOPER* pxStr, XLOPER* pxOpt)
{
	return PresetTranslate4(TEXTEX_TR_PRESET_TOZENKAKU, pxStr, pxOpt);
}

//======================================================================
//	XLCToZenkakuKana12
//======================================================================
XLOPER12* WINAPI XLCToZenkakuKana12(XLOPER12* pxStr, XLOPER12* pxOpt)
{
	return PresetTranslate12(TEXTEX_TR_PRESET_TOZENKAKUKANA, pxStr, pxOpt);
}

//======================================================================
//	XLCToZenkakuKana4
//======================================================================
XLOPER* WINAPI XLCToZenkakuKana4(XLOPER* pxStr, XLOPER* pxOpt)
{
	return PresetTranslate4(TEXTEX_TR_PRESET_TOZENKAKUKANA, pxStr, pxOpt);
}

//======================================================================
//	XLCToHankaku12
//======================================================================
XLOPER12* WINAPI XLCToHankaku12(XLOPER12* pxStr, XLOPER12* pxOpt)
{
	return PresetTranslate12(TEXTEX_TR_PRESET_TOHANKAKU, pxStr, pxOpt);
}

//======================================================================
//	XLCToHankaku4
//======================================================================
XLOPER* WINAPI XLCToHankaku4(XLOPER* pxStr, XLOPER* pxOpt)
{
	return PresetTranslate4(TEXTEX_TR_PRESET_TOHANKAKU, pxStr, pxOpt);
}

//======================================================================
//	XLCNormalizeWidth12
//======================================================================
XLOPER12* WINAPI XLCNormalizeWidth12(XLOPER12* pxStr, XLOPER12* pxOpt)
{
	return PresetTranslate12(TEXTEX_TR_PRESET_NORMALIZEWIDTH, pxStr, pxOpt);
}

//======================================================================
//	XLCNormalizeWidth4
//======================================================================
XLOPER* WINAPI XLCNormalizeWidth4(XLOPER* pxStr, XLOPER* pxOpt)
{
	return PresetTranslate4(TEXTEX_TR_PRESET_NORMALIZEWIDTH, pxStr, pxOpt);
}

