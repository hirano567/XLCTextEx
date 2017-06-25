//	XLCTextEx_1.0x	:	XLCTextEx

// XLCRegEx.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
//

#include "stdafx.h"

#define	XLREGEX_TEXTPROCESSING_MATCH	0
#define	XLREGEX_TEXTPROCESSING_FORMAT	1
#define	XLREGEX_TEXTPROCESSING_FORMATIF	2
#define	XLREGEX_TEXTPROCESSING_REPLACE	3
#define	XLREGEX_TEXTPROCESSING_VALUE	4


//======================================================================
//	XLCRegExCreate
//
//	���K�\���̃p�^�[������ NFA ���쐬���ēo�^����B
//======================================================================
//----------------------------------------------------------------------
//	XLCRegExCreate_exec
//	�G���[�����������Ƃ��͗�O���X���[����B
//	�����̉���͌Ăяo�����ōs�����ƁB
//----------------------------------------------------------------------
bool XLCRegExCreate_exec(XLOPER12* pxRet, XLOPER12* pxIndex, XLOPER12* pxPattern, XLOPER12* pxOptions)
{
	PLib::PCRegEx*	pciRegEx;
	int				iIndex;
	size_t			zt;
	T_PCSTR_U		pBegin, pEnd;
	T_CHAR_U		NullStr[1]	= { (T_CHAR_U)0 };
	T_STRING_U		strError;

#ifdef	PDEBUG
	T_STRING_U	strDebug;
#endif

	//------------------------------------------------------------
	//	�����̏���	(1)
	//	pxRet �� NULL �Ȃ��O���X���[����B
	//------------------------------------------------------------
	if (pxRet == NULL)
	{
		THROWPE_LOGIC_ERROR("XLCRegExCreate_exec");
	}

	//------------------------------------------------------------
	//	�����̏���	(2)
	//	pxIndex �� NULL �Ȃ��O���X���[����
	//	*pxIndex �� xltypeNum �� xltypeInt �łȂ炻�̒l�����o���B
	//	����ȊO�̏ꍇ�� false ��Ԃ��B
	//------------------------------------------------------------
	if (pxIndex == NULL)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
		return false;
	}

	switch (pxIndex->xltype)
	{
	case xltypeNum:
		iIndex	= (int)pxIndex->val.num;
		break;

	case xltypeInt:
		iIndex	= (int)pxIndex->val.w;
		break;

	default:
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
		return false;
		break;
	}

	//------------------------------------------------------------
	//	�����̏���	(3)
	//	pxPattern �� NULL �Ȃ��O���X���[����
	//	pxPattern �� xltypeStr �ŗL���Ȓl���Z�b�g����Ă���ꍇ�́A
	//	���̕���������o���ăp�^�[���Ƃ��A�t���O�Ƃ��� pBegin �� NULL ���Z�b�g����B
	//	�����ȕ�����̏ꍇ�� pBegin �� pEnd �ɋ󕶎��� NullBuf ���Z�b�g����B
	//	xltypeMissing �� xltypeNil �Ȃ� pBegin �� pEnd �ɋ󕶎��� NullBuf ���Z�b�g����B
	//------------------------------------------------------------
	if (pxPattern == NULL)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
		return false;
	}

	switch (pxPattern->xltype)
	{
	case xltypeStr:
		if (pxPattern->val.str == NULL || *(pxPattern->val.str) == 0)
		{
			pBegin	= NullStr;
			pEnd	= NullStr;
		}
		else
		{
			pBegin	= NULL;
			pEnd	= NULL;
		}
		break;

	case xltypeMissing:
	case xltypeNil:
		pBegin	= NullStr;
		pEnd	= NullStr;
		break;

	default:
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
		return false;
		break;
	}

	//------------------------------------------------------------
	//	PCRegEx �N���X�̃C���X�^���X���쐬����B�����̏ꍇ�͂�����g�p����B
	//------------------------------------------------------------
	pciRegEx	= GetXLRegExManager()->RegEx()->Create(iIndex);
	if (pciRegEx == NULL)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, true);
		return false;
	}
	pciRegEx->Init();

	//------------------------------------------------------------
	//	pxOptions �ɗL���ȃf�[�^���i�[����Ă���ꍇ�́A�I�v�V������ݒ肵�Ă����B
	//------------------------------------------------------------
	if (pxOptions != NULL)
	{
		switch (pxOptions->xltype)
		{
		case xltypeNum:
			(pciRegEx->Options())->Set((DWORD)(pxOptions->val.num));
			break;

		case xltypeStr:
			if (pxOptions->val.str != NULL && *(pxOptions->val.str) != 0)
			{
				zt		= XLL::GetXLOPER_StrSize<XLOPER12>(pxOptions);
				if (zt > 0)
				{
					(pciRegEx->Options())->Set(pxOptions->val.str + 1, zt);
				}
			}
			break;

		case xltypeInt:
			(pciRegEx->Options())->Set((DWORD)(pxOptions->val.w));
			break;

		default:
			(pciRegEx->Options())->Set((DWORD)0);
			break;
		}
	}

	//------------------------------------------------------------
	//	�p�^�[��������̈��p�����O���ăZ�b�g����B
	//------------------------------------------------------------
	if (pBegin == NULL)
	{
		if (t_XLCRegEx_IsOptionSet<T_CHAR_U, XLOPER12>(pxOptions, TQU("q")))
		{
			if (!XLL::XLRemoveQuote<wchar_t>(&pBegin, &pEnd, pxPattern,
				(pciRegEx->Options())->GetCompareStringUCDFlags(),
				(pciRegEx->Options())->GetLocaleString()))
			{
				XLCRegEx::LogError<T_CHAR_U>(TQU("Pattern is invalid."));
				goto ERROR_HANDLING;
			}
		}
		else
		{
			XLL::GetXLOPERString<T_CHAR_U, XLOPER12>(&pBegin, &pEnd, pxPattern);
		}
	}

	if (!pciRegEx->SetPattern(pBegin, pEnd))
	{
		XLCRegEx::LogError<T_CHAR_U>(TQU("Pattern is collapsed."));
		goto ERROR_HANDLING;
	}

	//------------------------------------------------------------
	//	NFA ���쐬����B���������� true ��Ԃ��B
	//------------------------------------------------------------
	if (pciRegEx->BuildNFA(&strError))
	{
#ifdef	PDEBUG
		strDebug.clear();
		pciRegEx->Debug(&strDebug);
#endif
		XLL::SetXLOPER_Num<XLOPER12>(pxRet, (double)iIndex, true);
		return true;
	}

	//	�ȉ��͍쐬�ł��Ȃ������ꍇ�̏����B
	if (!strError.empty())
	{
		XLCRegEx::LogError<T_CHAR_U>(strError.c_str());
	}
	else
	{
		XLCRegEx::LogError<T_CHAR_U>(TQU("Cannot create NFA."));
	}

	//------------------------------------------------------------
	//	�ȉ��̓G���[�����B
	//	�C���X�^���X���폜���A�G���[���b�Z�[�W���L�^���āA��O���X���[����B
	//------------------------------------------------------------
ERROR_HANDLING:
	GetXLRegExManager()->RegEx()->Delete(iIndex);
	XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
	return false;
}

//----------------------------------------------------------------------
//	XLCRegExCreate4
//	Excel ���瑗���Ă����f�[�^�̉���͌Ăяo�����ōs�����ƁB
//----------------------------------------------------------------------
#ifdef	XLL_AVAILABLE_TO_EXCEL11
XLOPER* WINAPI XLCRegExCreate4(XLOPER* pxIndex4, XLOPER* pxPattern4, XLOPER* pxOptions4)
{
	XLL::XLOPERConverter<PLib::PCMAlloc>	ciConverter;
	XLOPER12	xIndex12, xPattern12, xOptions12;
	XLOPER12	xRet12;
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
	xRet12.xltype	= xltypeNil;

	//------------------------------------------------------------
	//	�������L�����`�F�b�N����B
	//	���͂��������Ȃ������ɌĂяo����邱�Ƃ�����̂ŁAErr �ł͂Ȃ� Nil ��Ԃ��B
	//------------------------------------------------------------
	if (!PLib::IsPageReadWrite((LPVOID)pxIndex4)	||
		!PLib::IsPageReadWrite((LPVOID)pxPattern4)	||
		!PLib::IsPageReadWrite((LPVOID)pxOptions4))
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, true);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, true);
	}

	//------------------------------------------------------------
	//	�ϐ��̒l��ݒ肷��B
	//------------------------------------------------------------
	xIndex12.xltype		= xltypeNil;
	xPattern12.xltype	= xltypeNil;
	xOptions12.xltype	= xltypeNil;

	if (!ciConverter.Convert<XLOPER12, XLOPER>(&xIndex12, pxIndex4)		||
		!ciConverter.Convert<XLOPER12, XLOPER>(&xPattern12, pxPattern4)	||
		!ciConverter.Convert<XLOPER12, XLOPER>(&xOptions12, pxOptions4))
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
		goto END_PROCESSING;
	}

	//------------------------------------------------------------
	//	�p�^�[����o�^����B
	//------------------------------------------------------------
	try
	{
		XLCRegExCreate_exec(&xRet12, &xIndex12, &xPattern12, &xOptions12);
		if (ciConverter.Convert<XLOPER, XLOPER12>(pxRet4, &xRet12))
		{
			XLL::SetDLLFree(pxRet4);
		}
		else
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
		}
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
	}

	//------------------------------------------------------------
	//	�I������
	//------------------------------------------------------------
END_PROCESSING:
	XLL::DeleteXLOPER<XLOPER12>(&xIndex12);
	XLL::DeleteXLOPER<XLOPER12>(&xPattern12);
	XLL::DeleteXLOPER<XLOPER12>(&xOptions12);
	XLL::DeleteXLOPER<XLOPER12>(&xRet12);
	return pxRet4;
}
#endif

//----------------------------------------------------------------------
//	XLCRegExCreate12
//----------------------------------------------------------------------
XLOPER12* WINAPI XLCRegExCreate12(XLOPER12* pxIndex, XLOPER12* pxPattern, XLOPER12* pxOptions)
{
	XLOPER12*	pxRet12	= NULL;

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
	if (!PLib::IsPageReadWrite((LPVOID)pxIndex)		||
		!PLib::IsPageReadWrite((LPVOID)pxPattern)	||
		!PLib::IsPageReadWrite((LPVOID)pxOptions))
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, true);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, true);
	}

	//------------------------------------------------------------
	//	�o�^����B
	//------------------------------------------------------------
	try
	{
		XLCRegExCreate_exec(pxRet12, pxIndex, pxPattern, pxOptions);
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrNull, true);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrNull, true);
	}
	return pxRet12;
}


//======================================================================
//	XLCRegExDelete
//
//	�w�肳�ꂽ���K�\���C���X�^���X���폜����B
//======================================================================
//----------------------------------------------------------------------
//	t_XLCRegExDelete
//	�G���[�������������O���X���[����B
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER>
bool t_XLCRegExDelete(T_XLOPER* pxRet, T_XLOPER* pxIndex)
{
	int	iIndex;

	//------------------------------------------------------------
	//	�������`�F�b�N���āA�ԍ������o���B
	//------------------------------------------------------------
	if (pxRet == NULL)
	{
		THROWPE_LOGIC_ERROR("t_XLCRegExDelete");
	}
	if (pxIndex == NULL)
	{
		XLL::SetXLOPER_Err<T_XLOPER>(pxRet, xlerrValue, true);
		return false;
	}

	switch (pxIndex->xltype)
	{
	case xltypeNum:
		iIndex	= (int)pxIndex->val.num;
		break;

	case xltypeInt:
		iIndex	= (int)pxIndex->val.w;
		break;

	default:
		XLL::SetXLOPER_Err<T_XLOPER>(pxRet, xlerrValue, true);
		return false;
		break;
	}

	//------------------------------------------------------------
	//	�C���X�^���X���폜����B
	//	Delete() �͑��݂��Ă��Ȃ������ꍇ�� false ��Ԃ����A���̊֐������ true ��Ԃ��B
	//------------------------------------------------------------
	GetXLRegExManager()->RegEx()->Delete(iIndex);
	XLL::SetXLOPER_Bool<T_XLOPER>(pxRet, true, true);
	return true;
}

//----------------------------------------------------------------------
//	XLCRegExDelete4
//----------------------------------------------------------------------
XLOPER* WINAPI XLCRegExDelete4(XLOPER* pxIndex4)
{
	XLL::XLOPERConverter<>	ciConverter;

	XLOPER12	xIndex12;
	XLOPER12	xRet12;
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
	if (!PLib::IsPageReadWrite((LPVOID)pxIndex4))
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, true);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, true);
	}

	//------------------------------------------------------------
	//	�ϐ��̒l��ݒ肷��B
	//------------------------------------------------------------
	xIndex12.xltype	= xltypeNil;
	if (!ciConverter.Convert<XLOPER12, XLOPER>(&xIndex12, pxIndex4))
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
		goto END_PROCESSING;
	}

	//------------------------------------------------------------
	//	�p�^�[�����폜���A�Ԃ�l��ݒ肷��B
	//------------------------------------------------------------
	try
	{
		t_XLCRegExDelete<wchar_t, XLOPER12>(&xRet12, &xIndex12);
		if (ciConverter.Convert<XLOPER, XLOPER12>(pxRet4, &xRet12))
		{
			XLL::SetDLLFree(pxRet4);
		}
		else
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
		}
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
	}

	//------------------------------------------------------------
	//	�I������
	//------------------------------------------------------------
END_PROCESSING:
	XLL::DeleteXLOPER<XLOPER12>(&xIndex12);
	XLL::DeleteXLOPER<XLOPER12>(&xRet12);
	return pxRet4;
}

//----------------------------------------------------------------------
//	XLCRegExDelete12
//----------------------------------------------------------------------
XLOPER12* WINAPI XLCRegExDelete12(XLOPER12* pxIndex)
{
	XLOPER12*	pxRet	= NULL;

	try
	{
		pxRet	= XLL::AllocateXLOPER<XLOPER12>();
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
	if (!PLib::IsPageReadWrite((LPVOID)pxIndex))
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet, true);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet, true);
	}

	//------------------------------------------------------------
	//	�p�^�[�����폜���A�Ԃ�l��ݒ肷��B
	//------------------------------------------------------------
	try
	{
		t_XLCRegExDelete<wchar_t, XLOPER12>(pxRet, pxIndex);
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, true);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, true);
	}
	return pxRet;
}


//======================================================================
//	XLCRegExClear
//
//	�o�^����Ă��鐳�K�\���C���X�^���X�����ׂč폜����B
//======================================================================
//----------------------------------------------------------------------
//	t_XLCRegExClear	���ۂ̏������s���B
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER>
bool t_XLCRegExClear(T_XLOPER* pxRet, T_XLOPER* pxOption)
{
	bool		bAll	= false;
	DWORD		dwSheet	= 0;

	//------------------------------------------------------------
	//	�������`�F�b�N���āA�I�v�V���������o���B
	//------------------------------------------------------------
	if (pxRet == NULL)
	{
		THROWPE_LOGIC_ERROR("t_XLCRegExClear");
	}
	if (pxOption == NULL)
	{
		XLL::SetXLOPER_Err<T_XLOPER>(pxRet, xlerrValue, true);
		return false;
	}

	switch (pxOption->xltype)
	{
	case xltypeNum:
		bAll	= (pxOption->val.num != 0);
		break;

	case xltypeBool:
		bAll	= (pxOption->val.xbool != 0);
		break;

	case xltypeMissing:
		bAll	= false;
		break;

	case xltypeInt:
		bAll	= (pxOption->val.w != 0);
		break;

	default:
		XLL::SetXLOPER_Err<T_XLOPER>(pxRet, xlerrValue, true);
		return false;
		break;
	}

	//------------------------------------------------------------
	//	�I�v�V�����w��ɉ����ăC���X�^���X���폜����B
	//------------------------------------------------------------
	if (bAll)
	{
		GetXLRegExManager()->RegEx()->Clear();
	}
	else
	{
		if (XLL::GetActiveSheetId(&dwSheet))
		{
			GetXLRegExManager()->RegEx()->DeleteGroup(dwSheet);
		}
	}
	XLL::SetXLOPER_Bool<T_XLOPER>(pxRet, true, true);
	return true;
}

//----------------------------------------------------------------------
//	XLCRegExClear4
//----------------------------------------------------------------------
XLOPER* WINAPI XLCRegExClear4(XLOPER* pxOption4)
{
	XLL::XLOPERConverter<>	ciConverter;

	XLOPER12	xOption12;
	XLOPER12	xRet12;
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
	if (!PLib::IsPageReadWrite((LPVOID)pxOption4))
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, true);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, true);
	}

	//------------------------------------------------------------
	//	�ϐ��̒l��ݒ肷��B
	//------------------------------------------------------------
	xOption12.xltype	= xltypeNil;

	if (!ciConverter.Convert<XLOPER12, XLOPER>(&xOption12, pxOption4))
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
		goto END_PROCESSING;
	}

	//------------------------------------------------------------
	//	�p�^�[�����폜���A�Ԃ�l��ݒ肷��B
	//------------------------------------------------------------
	try
	{
		t_XLCRegExClear<wchar_t, XLOPER12>(&xRet12, &xOption12);
		if (ciConverter.Convert<XLOPER, XLOPER12>(pxRet4, &xRet12))
		{
			XLL::SetDLLFree(pxRet4);
		}
		else
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
		}
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
	}

END_PROCESSING:
	XLL::DeleteXLOPER<XLOPER12>(&xOption12);
	XLL::DeleteXLOPER<XLOPER12>(&xRet12);
	return pxRet4;
}

//----------------------------------------------------------------------
//	XLCRegExClear12
//----------------------------------------------------------------------
XLOPER12* WINAPI XLCRegExClear12(XLOPER12* pxOption)
{
	XLOPER12*	pxRet	= NULL;

	try
	{
		pxRet	= XLL::AllocateXLOPER<XLOPER12>();
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
	if (!PLib::IsPageReadWrite((LPVOID)pxOption))
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet, true);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet, true);
	}

	//------------------------------------------------------------
	//	�p�^�[�����폜���A�Ԃ�l��ݒ肷��B
	//------------------------------------------------------------
	try
	{
		t_XLCRegExClear<wchar_t, XLOPER12>(pxRet, pxOption);
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, true);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, true);
	}
	return pxRet;
}


//======================================================================
//	XLCRegExCreateReplacement
//
//	�u�����������́E�o�^����B
//======================================================================
//----------------------------------------------------------------------
//	XLCRegExCreateReplacement_exec
//----------------------------------------------------------------------
bool XLCRegExCreateReplacement_exec(XLOPER12*	pxRet,
								 XLOPER12*	pxIndex,
								 XLOPER12*	pxReplacement,
								 XLOPER12*	pxOptions)
{
	typedef	const T_CHAR_U*		T_PCSTR_U;

	PLib::PCRegExReplacement*	pciReplacement;
	int							iIndex;
	T_PCSTR_U						pBegin, pEnd;
	T_CHAR_U						NullStr[1]	= { (T_CHAR_U)0 };
	T_STRING_U	strError;

#ifdef	PDEBUG
	T_STRING_U	strDebug;
#endif

	//------------------------------------------------------------
	//	�����̏���	(1)
	//	pxRet �� NULL �Ȃ��O���X���[����B
	//------------------------------------------------------------
	if (pxRet == NULL)
	{
		THROWPE_LOGIC_ERROR("XLCRegExCreate_exec");
	}

	//------------------------------------------------------------
	//	�����̏���	(2)
	//	pxIndex �� NULL �Ȃ��O���X���[����
	//	*pxIndex �� xltypeNum �� xltypeInt �łȂ炻�̒l�����o���B
	//	����ȊO�̏ꍇ�� false ��Ԃ��B
	//------------------------------------------------------------
	if (pxIndex == NULL)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
		return false;
	}

	switch (pxIndex->xltype)
	{
	case xltypeNum:
		iIndex	= (int)pxIndex->val.num;
		break;

	case xltypeInt:
		iIndex	= (int)pxIndex->val.w;
		break;

	default:
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
		return false;
		break;
	}

	//------------------------------------------------------------
	//	�����̏���	(3)
	//	pxReplacement �� NULL �Ȃ��O���X���[����
	//	pxReplacement �� xltypeStr �ŗL���Ȓl���Z�b�g����Ă���ꍇ�́A
	//	���̕���������o���ăp�^�[���Ƃ��A�t���O�Ƃ��� pBegin �� NULL ���Z�b�g����B
	//	�����ȕ�����̏ꍇ�� pBegin �� pEnd �ɋ󕶎��� NullBuf ���Z�b�g����B
	//	xltypeMissing �� xltypeNil �Ȃ� pBegin �� pEnd �ɋ󕶎��� NullBuf ���Z�b�g����B
	//------------------------------------------------------------
	if (pxReplacement == NULL)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
		return false;
	}

	switch (pxReplacement->xltype)
	{
	case xltypeStr:
		if (pxReplacement->val.str == NULL || *(pxReplacement->val.str) == 0)
		{
			pBegin	= NullStr;
			pEnd	= NullStr;
		}
		else
		{
			pBegin	= NULL;
			pEnd	= NULL;
		}
		break;

	case xltypeMissing:
	case xltypeNil:
		pBegin	= NullStr;
		pEnd	= NullStr;
		break;

	default:
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
		return false;
		break;
	}

	//------------------------------------------------------------
	//	PCRegExReplacement �N���X�̃C���X�^���X���쐬����B�����̏ꍇ�͂�����g�p����B
	//------------------------------------------------------------
	pciReplacement	= GetXLRegExManager()->Replacement()->Create(iIndex);
	if (pciReplacement == NULL)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, true);
		return false;
	}
	pciReplacement->Init();

	//------------------------------------------------------------
	//	�������Z�b�g����O�ɁApxOptions ����I�v�V������ݒ肵�Ă����B
	//------------------------------------------------------------
	if (pxOptions != NULL)
	{
		switch (pxOptions->xltype)
		{
		case xltypeNum:
			(pciReplacement->Options())->Set((DWORD)(pxOptions->val.num));
			break;

		case xltypeStr:
			if (pxOptions->val.str != NULL && *(pxOptions->val.str) != 0)
			{
				(pciReplacement->Options())->Set(
					pxOptions->val.str + 1, XLL::GetXLOPER_StrSize<XLOPER12>(pxOptions));
			}
			break;

		case xltypeInt:
			(pciReplacement->Options())->Set((DWORD)(pxOptions->val.w));
			break;

		default:
			(pciReplacement->Options())->Set((DWORD)0);
			break;
		}
	}

	//------------------------------------------------------------
	//	������������Z�b�g����B����������C���f�b�N�X��Ԃ��B
	//------------------------------------------------------------
	//	�܂����p�����O���B
	if (pBegin == NULL)
	{
		if (t_XLCRegEx_IsOptionSet<T_CHAR_U, XLOPER12>(pxOptions, TQU("q")))
		{
			if (!XLL::XLRemoveQuote<wchar_t>(&pBegin, &pEnd, pxReplacement,
				(pciReplacement->Options())->GetCompareStringUCDFlags(),
				(pciReplacement->Options())->GetLocaleString()))
			{
				XLCRegEx::LogError<T_CHAR_U>(TQU("Replacement is collapsed."));
				goto ERROR_HANDLING;
			}
		}
		else
		{
			XLL::GetXLOPERString<T_CHAR_U, XLOPER12>(&pBegin, &pEnd, pxReplacement);
		}
	}

	//	���ۂɃZ�b�g����B
	if (pciReplacement->SetReplacement(pBegin, pEnd))
	{
#ifdef	PDEBUG
		strDebug.clear();
		pciReplacement->Debug(&strDebug);
#endif
		XLL::SetXLOPER_Num<XLOPER12>(pxRet, (double)iIndex, true);
		return true;
	}

	//------------------------------------------------------------
	//	�ȉ��̓G���[�����B
	//	�C���X�^���X���폜���A�G���[���b�Z�[�W���L�^���āA��O���X���[����B
	//------------------------------------------------------------
ERROR_HANDLING:
	GetXLRegExManager()->Replacement()->Delete(iIndex);
	//XLCRegEx::LogError<T_CHAR_U>(TQU("Cannot create the Replacement."));
	XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
	return false;
}

//----------------------------------------------------------------------
//	XLCRegExCreateReplacement4
//----------------------------------------------------------------------
XLOPER4* WINAPI XLCRegExCreateReplacement4(XLOPER*	pxIndex4,
										   XLOPER*	pxReplacement4,
										   XLOPER*	pxOptions4)
{
	XLL::XLOPERConverter<PLib::PCMAlloc>	ciConverter;
	XLOPER12	xIndex12, xReplacement12, xOptions12;
	XLOPER12	xRet12;
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
	xRet12.xltype	= xltypeNil;

	//------------------------------------------------------------
	//	�������L�����`�F�b�N����B
	//	���͂��������Ȃ������ɌĂяo����邱�Ƃ�����̂ŁAErr �ł͂Ȃ� Nil ��Ԃ��B
	//------------------------------------------------------------
	if (!PLib::IsPageReadWrite((LPVOID)pxIndex4)		||
		!PLib::IsPageReadWrite((LPVOID)pxReplacement4)	||
		!PLib::IsPageReadWrite((LPVOID)pxOptions4))
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, true);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, true);
	}

	//------------------------------------------------------------
	//	�ϐ��̒l��ݒ肷��B
	//------------------------------------------------------------
	xIndex12.xltype			= xltypeNil;
	xReplacement12.xltype	= xltypeNil;
	xOptions12.xltype		= xltypeNil;

	if (!ciConverter.Convert<XLOPER12, XLOPER>(&xIndex12, pxIndex4)				||
		!ciConverter.Convert<XLOPER12, XLOPER>(&xReplacement12, pxReplacement4)	||
		!ciConverter.Convert<XLOPER12, XLOPER>(&xOptions12, pxOptions4))
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
		goto END_PROCESSING;
	}
	//------------------------------------------------------------
	//	�u���������o�^����B
	//------------------------------------------------------------
	try
	{
		XLCRegExCreateReplacement_exec(
			&xRet12, &xIndex12, &xReplacement12, &xOptions12);
		if (ciConverter.Convert<XLOPER, XLOPER12>(pxRet4, &xRet12))
		{
			XLL::SetDLLFree(pxRet4);
		}
		else
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
		}
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
	}

	//------------------------------------------------------------
	//	�I������
	//------------------------------------------------------------
END_PROCESSING:
	XLL::DeleteXLOPER<XLOPER12>(&xIndex12);
	XLL::DeleteXLOPER<XLOPER12>(&xReplacement12);
	XLL::DeleteXLOPER<XLOPER12>(&xOptions12);
	XLL::DeleteXLOPER<XLOPER12>(&xRet12);
	return pxRet4;
}

//----------------------------------------------------------------------
//	XLCRegExCreateReplacement12
//----------------------------------------------------------------------
XLOPER12* WINAPI XLCRegExCreateReplacement12(XLOPER12*	pxIndex,
											 XLOPER12*	pxReplacement,
											 XLOPER12*	pxOptions)
{
	XLOPER12*	pxRet12	= NULL;

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
	if (!PLib::IsPageReadWrite((LPVOID)pxIndex)			||
		!PLib::IsPageReadWrite((LPVOID)pxReplacement)	||
		!PLib::IsPageReadWrite((LPVOID)pxOptions))
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, true);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, true);
	}
	
	//------------------------------------------------------------
	//	�o�^����B
	//------------------------------------------------------------
	try
	{
		XLCRegExCreateReplacement_exec(pxRet12, pxIndex, pxReplacement, pxOptions);
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrNull, true);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrNull, true);
	}
	return pxRet12;
}


//======================================================================
//	XLCRegExDeleteReplacement
//
//	�w�肳�ꂽ�u��������C���X�^���X���폜����B
//======================================================================
//----------------------------------------------------------------------
//	t_XLCRegExDeleteReplacement
//	�G���[�������������O���X���[����B
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER>
bool t_XLCRegExDeleteReplacement(T_XLOPER* pxRet, T_XLOPER* pxIndex)
{
	int			iIndex;

	//------------------------------------------------------------
	//	�������`�F�b�N���āA�ԍ������o���B
	//------------------------------------------------------------
	if (pxRet == NULL)
	{
		THROWPE_LOGIC_ERROR("t_XLCRegExDeleteReplacement");
	}
	if (pxIndex == NULL)
	{
		XLL::SetXLOPER_Err<T_XLOPER>(pxRet, xlerrValue, true);
		return false;
	}

	switch (pxIndex->xltype)
	{
	case xltypeNum:
		iIndex	= (int)pxIndex->val.num;
		break;

	case xltypeInt:
		iIndex	= (int)pxIndex->val.w;
		break;

	default:
		XLL::SetXLOPER_Err<T_XLOPER>(pxRet, xlerrValue, true);
		return false;
		break;
	}

	//------------------------------------------------------------
	//	�C���X�^���X���폜����B
	//	Delete() �͑��݂��Ă��Ȃ������ꍇ�� false ��Ԃ����A���̊֐������ true ��Ԃ��B
	//------------------------------------------------------------
	GetXLRegExManager()->Replacement()->Delete(iIndex);
	XLL::SetXLOPER_Bool<T_XLOPER>(pxRet, true, true);
	return true;
}

//----------------------------------------------------------------------
//	XLCRegExDeleteReplacement4
//----------------------------------------------------------------------
XLOPER* WINAPI XLCRegExDeleteReplacement4(XLOPER* pxIndex4)
{
	XLL::XLOPERConverter<>	ciConverter;

	XLOPER12	xIndex12;
	XLOPER12	xRet12;
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
	if (!PLib::IsPageReadWrite((LPVOID)pxIndex4))
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, true);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, true);
	}

	//------------------------------------------------------------
	//	�ϐ��̒l��ݒ肷��B
	//------------------------------------------------------------
	xIndex12.xltype	= xltypeNil;
	if (!ciConverter.Convert<XLOPER12, XLOPER>(&xIndex12, pxIndex4))
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
		goto END_PROCESSING;
	}

	//------------------------------------------------------------
	//	�p�^�[�����폜���A�Ԃ�l��ݒ肷��B
	//------------------------------------------------------------
	try
	{
		t_XLCRegExDeleteReplacement<wchar_t, XLOPER12>(&xRet12, &xIndex12);
		if (ciConverter.Convert<XLOPER, XLOPER12>(pxRet4, &xRet12))
		{
			XLL::SetDLLFree(pxRet4);
		}
		else
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
		}
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
	}

	//------------------------------------------------------------
	//	�I������
	//------------------------------------------------------------
END_PROCESSING:
	XLL::DeleteXLOPER<XLOPER12>(&xIndex12);
	XLL::DeleteXLOPER<XLOPER12>(&xRet12);
	return pxRet4;
}

//----------------------------------------------------------------------
//	XLCRegExDeleteReplacement12
//----------------------------------------------------------------------
XLOPER12* WINAPI XLCRegExDeleteReplacement12(XLOPER12* pxIndex)
{
	XLOPER12*	pxRet	= NULL;

	try
	{
		pxRet	= XLL::AllocateXLOPER<XLOPER12>();
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
	if (!PLib::IsPageReadWrite((LPVOID)pxIndex))
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet, true);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet, true);
	}

	//------------------------------------------------------------
	//	�p�^�[�����폜���A�Ԃ�l��ݒ肷��B
	//------------------------------------------------------------
	try
	{
		t_XLCRegExDeleteReplacement<wchar_t, XLOPER12>(pxRet, pxIndex);
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, true);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, true);
	}
	return pxRet;
}


//======================================================================
//	XLCRegExClearReplacement
//
//	�o�^����Ă��鐳�K�\���C���X�^���X�����ׂč폜����B
//======================================================================
//----------------------------------------------------------------------
//	t_XLCRegExClearReplacement	���ۂ̏������s���B
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER>
bool t_XLCRegExClearReplacement(T_XLOPER* pxRet, T_XLOPER* pxOption)
{
	bool		bAll	= false;
	DWORD		dwSheet	= 0;

	//------------------------------------------------------------
	//	�������`�F�b�N���āA�I�v�V���������o���B
	//------------------------------------------------------------
	if (pxRet == NULL)
	{
		THROWPE_LOGIC_ERROR("t_XLCRegExClearReplacement");
	}
	if (pxOption == NULL)
	{
		XLL::SetXLOPER_Err<T_XLOPER>(pxRet, xlerrValue, true);
		return false;
	}

	switch (pxOption->xltype)
	{
	case xltypeNum:
		bAll	= (pxOption->val.num != 0);
		break;

	case xltypeBool:
		bAll	= (pxOption->val.xbool != 0);
		break;

	case xltypeMissing:
		bAll	= false;
		break;

	case xltypeInt:
		bAll	= (pxOption->val.w != 0);
		break;

	default:
		XLL::SetXLOPER_Err<T_XLOPER>(pxRet, xlerrValue, true);
		return false;
		break;
	}

	//------------------------------------------------------------
	//	�I�v�V�����w��ɉ����ăC���X�^���X���폜����B
	//------------------------------------------------------------
	if (bAll)
	{
		GetXLRegExManager()->Replacement()->Clear();
	}
	else
	{
		if (XLL::GetActiveSheetId(&dwSheet))
		{
			GetXLRegExManager()->Replacement()->DeleteGroup(dwSheet);
		}
	}
	XLL::SetXLOPER_Bool<T_XLOPER>(pxRet, true, true);
	return true;
}

//----------------------------------------------------------------------
//	XLCRegExClearReplacement4
//----------------------------------------------------------------------
XLOPER* WINAPI XLCRegExClearReplacement4(XLOPER* pxOption4)
{
	XLL::XLOPERConverter<>	ciConverter;

	XLOPER12	xOption12;
	XLOPER12	xRet12;
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
	if (!PLib::IsPageReadWrite((LPVOID)pxOption4))
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, true);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, true);
	}

	//------------------------------------------------------------
	//	�ϐ��̒l��ݒ肷��B
	//------------------------------------------------------------
	xOption12.xltype	= xltypeNil;

	if (!ciConverter.Convert<XLOPER12, XLOPER>(&xOption12, pxOption4))
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
		goto END_PROCESSING;
	}

	//------------------------------------------------------------
	//	�p�^�[�����폜���A�Ԃ�l��ݒ肷��B
	//------------------------------------------------------------
	try
	{
		t_XLCRegExClearReplacement<wchar_t, XLOPER12>(&xRet12, &xOption12);
		if (ciConverter.Convert<XLOPER, XLOPER12>(pxRet4, &xRet12))
		{
			XLL::SetDLLFree(pxRet4);
		}
		else
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
		}
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
	}

END_PROCESSING:
	XLL::DeleteXLOPER<XLOPER12>(&xOption12);
	XLL::DeleteXLOPER<XLOPER12>(&xRet12);
	return pxRet4;
}

//----------------------------------------------------------------------
//	XLCRegExClearReplacement12
//----------------------------------------------------------------------
XLOPER12* WINAPI XLCRegExClearReplacement12(XLOPER12* pxOption)
{
	XLOPER12*	pxRet	= NULL;

	try
	{
		pxRet	= XLL::AllocateXLOPER<XLOPER12>();
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
	if (!PLib::IsPageReadWrite((LPVOID)pxOption))
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet, true);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet, true);
	}

	//------------------------------------------------------------
	//	�p�^�[�����폜���A�Ԃ�l��ݒ肷��B
	//------------------------------------------------------------
	try
	{
		t_XLCRegExClearReplacement<wchar_t, XLOPER12>(pxRet, pxOption);
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, true);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, true);
	}
	return pxRet;
}


//======================================================================
//	XLCRegExGetPCRegEx
//	�֐����ŃG���[�����������ꍇ�́@NULL ��Ԃ��B
//======================================================================
PLib::PCRegEx* XLCRegExGetPCRegEx(PLib::PCRegEx*	pciRegExTemp,
								  XLOPER12*			pxPattern,
								  XLOPER12*			pxOptions)
{
	PLib::PCRegEx*	pciRegExR	= NULL;
	int				iIndex;
	T_PCSTR_U		ps	= NULL;
	size_t			zs;
	T_PCSTR_U		pBegin, pEnd;
	XLOPER12		xTemp;
	T_CHAR_U		NullStr[1]	= { (T_CHAR_U)0 };
	T_STRING_U		strError;

	//	pxPattern �� NULL �̏ꍇ�̓p�^�[��������Ȃ��Ƃ��ĉ�͂𑱂���B
	if (pxPattern == NULL)
	{
		xTemp.xltype	= xltypeMissing;
		pxPattern		= &xTemp;
	}

	switch (pxPattern->xltype)
	{
		//--------------------------------------------------
		//	xltypeNum�AxltypeInt �̏ꍇ�A�C���f�b�N�X�ɑΉ����� PCRegEx ��Ԃ��B
		//--------------------------------------------------
	case xltypeNum:
	case xltypeInt:
		if (pxPattern->xltype == xltypeInt)
		{
			iIndex	= (int)(pxPattern->val.w);
		}
		else
		{
			iIndex	= (int)(pxPattern->val.num);
		}
		pciRegExR	= GetXLRegExManager()->RegEx()->Find(iIndex);
		if (pxOptions != NULL && pciRegExR)
		{
			switch (pxOptions->xltype)
			{
			case xltypeNum:
				(pciRegExR->Options())->Set((DWORD)(pxOptions->val.num));
				break;

			case xltypeStr:
				zs	= XLL::GetXLOPER_StrSize(pxOptions);
				if (zs > 0)	(pciRegExR->Options())->Set(pxOptions->val.str + 1, zs);
				break;

			case xltypeInt:
				(pciRegExR->Options())->Set((DWORD)(pxOptions->val.w));
				break;

			default:
				break;
			}
		}
		return pciRegExR;
		break;

		//--------------------------------------------------
		//	xltypeStr �̏ꍇ�ApciPCRegEx �Ƀp�^�[���ƃI�v�V������ݒ肵�A
		//	NFA ���쐬����B
		//	xltypeMissing�AxltypeNil �̏ꍇ�͋󕶎�����p�^�[���Ƃ��č쐬����B
		//--------------------------------------------------
	case xltypeStr:
	case xltypeMissing:
	case xltypeNil:
		if (pciRegExTemp == NULL)	THROWPE_LOGIC_ERROR("XLCRegExGetPCRegEx: pciRegExTemp is NULL.");
		//if (pxPattern->val.str == NULL)	return NULL;

		//	�܂��I�v�V����������ΐݒ肵�Ă����B
		if (pxOptions != NULL)
		{
			switch (pxOptions->xltype)
			{
			case xltypeNum:
				(pciRegExTemp->Options())->Set((DWORD)(pxOptions->val.num));
				break;

			case xltypeStr:
				zs	= XLL::GetXLOPER_StrSize(pxOptions);
				if (zs > 0)	(pciRegExTemp->Options())->Set(pxOptions->val.str + 1, zs);
				break;

			case xltypeInt:
				(pciRegExTemp->Options())->Set((DWORD)(pxOptions->val.w));
				break;

			default:
				break;
			}
		}

		//	xltypeStr �̏ꍇ�A�w�肪����Έ��p�����O��
		if (pxPattern->xltype == xltypeStr)
		{
			if (t_XLCRegEx_IsOptionSet<T_CHAR_U, XLOPER12>(pxOptions, TQU("q")))
			{
				if (!XLL::XLRemoveQuote<T_CHAR_U>(&pBegin, &pEnd, pxPattern,
					(pciRegExTemp->Options())->GetCompareStringUCDFlags(),
					(pciRegExTemp->Options())->GetLocaleString()))
				{
					//XLCRegEx::LogError<T_CHAR_U>(TQU("Pattern is invalid."));
					//return NULL;
					pBegin	= NullStr;
					pEnd	= NullStr;
				}
			}
			else
			{
				if (!XLL::GetXLOPERString<T_CHAR_U, XLOPER12>(&pBegin, &pEnd, pxPattern))
				{
					pBegin	= NullStr;
					pEnd	= NullStr;
				}
			}
		}
		else
		{
			pBegin	= NullStr;
			pEnd	= NullStr;
		}

		pciRegExTemp->SetPattern(pBegin, pEnd);

		if (!pciRegExTemp->BuildNFA(&strError))
		{
			XLCRegEx::LogError<T_CHAR_U>(strError.c_str());
			return NULL;
		}
		return pciRegExTemp;
		break;

	default:
		break;
	}
	return NULL;
}


//======================================================================
//	XLCRegExGetPCRegExReplacement
//	�֐����ŃG���[�����������ꍇ�́@NULL ��Ԃ��B
//======================================================================
PLib::PCRegExReplacement*
XLCRegExGetPCRegExReplacement(PLib::PCRegExReplacement*	pciReplacementTemp,
							  XLOPER12*					pxReplacement,
							  XLOPER12*					pxOptions)
{
	int			iIndex;
	T_PCSTR_U	ps	= NULL;
	size_t		zs;
	T_PCSTR_U	pBegin, pEnd;
	XLOPER12	xTemp;
	T_CHAR_U	NullStr[1]	= { (T_CHAR_U)0 };
	T_STRING_U	strError;

	if (pxReplacement == NULL)
	{
		xTemp.xltype	= xltypeMissing;
		pxReplacement	= &xTemp;
	}

	switch (pxReplacement->xltype)
	{
		//--------------------------------------------------
		//	xltypeNum �̏ꍇ�A�C���f�b�N�X�ɑΉ����� PCRegEx ��Ԃ��B
		//--------------------------------------------------
	case xltypeNum:
		iIndex	= (int)(pxReplacement->val.num);
		return GetXLRegExManager()->Replacement()->Find(iIndex);
		break;

		//--------------------------------------------------
		//	xltypeStr �̏ꍇ�ApciReplacement �Ƀp�^�[���ƃI�v�V������ݒ肵�A��͂���B
		//	xltypeMissing�AxltypeNil �̏ꍇ�͋󕶎����u��������Ƃ��č쐬����B
		//--------------------------------------------------
	case xltypeStr:
	case xltypeMissing:
	case xltypeNil:
		if (pciReplacementTemp == NULL)
			THROWPE_LOGIC_ERROR("XLCRegExGetPCRegExReplacement:pciReplacementTemp");
		//if (pxReplacement->val.str == NULL)	return NULL;

		//	PCRegExReplacement �̏ꍇ�A Set ���ŉ�͂��s���̂Ő�Ƀp�����[�^���Z�b�g���Ă����B
		if (pxOptions != NULL)
		{
			switch (pxOptions->xltype)
			{
			case xltypeNum:
				(pciReplacementTemp->Options())->Set((DWORD)(pxOptions->val.num));
				break;

			case xltypeStr:
				zs	= XLL::GetXLOPER_StrSize(pxOptions);
				if (zs > 0)	(pciReplacementTemp->Options())->Set(pxOptions->val.str + 1, zs);
				break;

			case xltypeInt:
				(pciReplacementTemp->Options())->Set((DWORD)(pxOptions->val.w));
				break;

			default:
				break;
			}
		}

		//	�w�肪����Έ��p�����O���B
		if (pxReplacement->xltype == xltypeStr)
		{
			if (t_XLCRegEx_IsOptionSet<T_CHAR_U, XLOPER12>(pxOptions, TQU("q")))
			{
				if (!XLL::XLRemoveQuote<wchar_t>(&pBegin, &pEnd, pxReplacement,
					(pciReplacementTemp->Options())->GetCompareStringUCDFlags(),
					(pciReplacementTemp->Options())->GetLocaleString()))
				{
					//XLCRegEx::LogError<T_CHAR_U>(TQU("Replacement is collapsed."));
					//return NULL;
					pBegin	= NullStr;
					pEnd	= NullStr;
				}
			}
			else
			{
				if (!XLL::GetXLOPERString<T_CHAR_U, XLOPER12>(&pBegin, &pEnd, pxReplacement))
				{
					pBegin	= NullStr;
					pEnd	= NullStr;
				}
			}
		}
		else
		{
			pBegin	= NullStr;
			pEnd	= NullStr;
		}

		//	�u����������Z�b�g����B
		if (pciReplacementTemp->SetReplacement(pBegin, pEnd))
		{
			return pciReplacementTemp;
		}
		else
		{
			XLCRegEx::LogError<T_CHAR_U>(TQU("Cannot create the Replacement."));
			return NULL;
		}
		break;

		//--------------------------------------------------
		//	xltypeInt �̏ꍇ�A�C���f�b�N�X�ɑΉ����� PCRegEx ��Ԃ��B
		//--------------------------------------------------
	case xltypeInt:
		iIndex	= (int)(pxReplacement->val.w);
		return GetXLRegExManager()->Replacement()->Find(iIndex);
		break;

	default:
		break;
	}
	THROWPE_INVALID_PARAMETER("Invalid pattern.");
	return NULL;
}

//======================================================================
//	XLCRegExGetPCRegExText
//======================================================================
bool XLCRegExGetPCRegExText(PLib::PCRegExText* pciText, XLOPER12* pxText, XLOPER12* pxOptions)
{
	typedef	const T_CHAR_U*	T_PCSTR_U;

	T_PCSTR_U	pBegin, pEnd;
	XLOPER12	xTemp;
	T_CHAR_U	NullStr[1]	= { (T_CHAR_U)0 };

	if (pciText == NULL)	return false;
	if (pxText == NULL)
	{
		xTemp.xltype	= xltypeMissing;
		pxText			= &xTemp;
	}

	switch (pxText->xltype)
	{
	case xltypeStr:
		//	�w�肪����Έ��p�����O���B
		if (pxOptions != NULL &&
			t_XLCRegEx_IsOptionSet<T_CHAR_U, XLOPER12>(pxOptions, TQU("q")))
		{
			if (!XLL::XLRemoveQuote<wchar_t>(&pBegin, &pEnd, pxText, 0, NULL))
			{
				//XLCRegEx::LogError<T_CHAR_U>(TQU("Text is collapsed."));
				//return false;
				pBegin	= NullStr;
				pEnd	= NullStr;
			}
		}
		else
		{
			if (!XLL::GetXLOPERString<T_CHAR_U, XLOPER12>(&pBegin, &pEnd, pxText))
			{
				pBegin	= NullStr;
				pEnd	= NullStr;
			}
		}
		break;

	case xltypeMissing:
	case xltypeNil:
		pBegin	= NullStr;
		pEnd	= NullStr;
		break;

	default:
		return false;
		break;
	}

	pciText->SetDecodeFlags(PCTEXT_FLAG_DECODE_NONE);
	return pciText->SetText(pBegin, pEnd);
}


//======================================================================
//	XLCRegExTextProcessing
//======================================================================
//----------------------------------------------------------------------
//	XLCRegExTextProcessing_exec
//	�G���[�����������ꍇ�́A��O���X���[����B
//----------------------------------------------------------------------
bool XLCRegExTextProcessing_exec(XLOPER12*	pxRet,
								 int		iProcessing,
								 XLOPER12*	pxPat,
								 XLOPER12*	pxTxt,
								 XLOPER12*	pxOpt,
								 XLOPER12*	pxRepT,
								 XLOPER12*	pxRepF)
{
	PLib::PCRegEx*				pciRegEx		= NULL;
	PLib::PCRegEx				ciRegExTemp;

	PLib::PCRegExReplacement*	pciReplacementT	= NULL;
	PLib::PCRegExReplacement	ciReplacementTempT;
	PLib::PCRegExReplacement*	pciReplacementF	= NULL;
	PLib::PCRegExReplacement	ciReplacementTempF;

	PLib::PCRegExText			ciText;
	T_STRING_U					strDebug;
	int							iMatches;
	T_PCSTR_U					pTemp;
	double						dValue;
	T_PCSTR_U					pBegin, pEnd;
	T_CHAR_U					NullStr[1]	= { (T_CHAR_U)0 };

	T_STRING_U					strOutput;
	bool						br	= false;

	if (pxRet == NULL)
	{
		THROWPE_LOGIC_ERROR("XLCRegExTextProcessing_exec");
	}

	switch (iProcessing)
	{
		//--------------------------------------------------
		//	XLREGEX_TEXTPROCESSING_MATCH
		//--------------------------------------------------
	case XLREGEX_TEXTPROCESSING_MATCH:
		pciRegEx	= XLCRegExGetPCRegEx(&ciRegExTemp, pxPat, pxOpt);
		if (pciRegEx == NULL)
		{
			XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
			return false;
		}
		if (!XLCRegExGetPCRegExText(&ciText, pxTxt, pxOpt))
		{
			XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
			return false;
		}
		ciText.Begin();
		br	= pciRegEx->Match(&ciText);
		XLL::SetXLOPER_Bool<XLOPER12>(pxRet, br, true);
		return true;
		break;

		//--------------------------------------------------
		//	XLREGEX_TEXTPROCESSING_FORMAT
		//	XLREGEX_TEXTPROCESSING_FORMATIF
		//	XLREGEX_TEXTPROCESSING_REPLACE
		//	XLREGEX_TEXTPROCESSING_VALUE
		//--------------------------------------------------
	case XLREGEX_TEXTPROCESSING_FORMAT:
	case XLREGEX_TEXTPROCESSING_FORMATIF:
	case XLREGEX_TEXTPROCESSING_REPLACE:
	case XLREGEX_TEXTPROCESSING_VALUE:
		//	���K�\���p�[�T���쐬����B
		pciRegEx	= XLCRegExGetPCRegEx(&ciRegExTemp, pxPat, pxOpt);
		if (pciRegEx == NULL)
		{
			XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
			return false;
		}

		//	�u�����������͂���B
		pciReplacementT	= XLCRegExGetPCRegExReplacement(&ciReplacementTempT, pxRepT, pxOpt);
		if (pciReplacementT == NULL)
		{
			XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
			return false;
		}

		//	�}�b�`���Ȃ������ꍇ�̒u�����������͂���B
		if (iProcessing == XLREGEX_TEXTPROCESSING_FORMATIF)
		{
			pciReplacementF	= XLCRegExGetPCRegExReplacement(&ciReplacementTempF, pxRepF, pxOpt);
			if (pciReplacementF == NULL)
			{
				XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
				return false;
			}
		}

		//	�Ώۃe�L�X�g��ǂݍ��ށB
		if (!XLCRegExGetPCRegExText(&ciText, pxTxt, pxOpt))
		{
			XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrValue, true);
			return false;
		}
		ciText.Begin();

		strOutput.clear();
		switch (iProcessing)
		{
			//----------------------------------------
			//	Format, FormatIf, Value
			//----------------------------------------
		case XLREGEX_TEXTPROCESSING_FORMAT:
		case XLREGEX_TEXTPROCESSING_FORMATIF:
		case XLREGEX_TEXTPROCESSING_VALUE:
			//	�}�b�`�����ꍇ�̏���
			if (pciRegEx->Match(&ciText))
			{
				pciReplacementT->Format(&strOutput, &ciText);
			}
			//	�ȉ��̓}�b�`���Ȃ������ꍇ�̏����B
			else if (iProcessing == XLREGEX_TEXTPROCESSING_FORMATIF)
			{
				pciReplacementF->Format(&strOutput, &ciText);
			}
			else
			{
				//	XLREGEX_TEXTPROCESSING_FORMAT �Ń}�b�`���Ȃ������ꍇ�B
				//	�󕶎��� strOutput �� pxRet �ɃZ�b�g����̂ŁA�����ł͉������Ȃ��B
			}
			break;

			//----------------------------------------
			//	Replace
			//----------------------------------------
		case XLREGEX_TEXTPROCESSING_REPLACE:
			PLib::PRegExReplace(&strOutput, pciRegEx, pciReplacementT, &ciText, &strDebug, &iMatches);
			break;
		}

		//--------------------------------------------------
		//	�o�͂���l�� XLOPER �Ɋi�[����B(1)	VALUE
		//--------------------------------------------------
		if (iProcessing == XLREGEX_TEXTPROCESSING_VALUE)
		{
			if (!strOutput.empty())
			{
				pTemp	= strOutput.c_str();
				if (!PLib::Unicode::StrToDouble(&dValue, &pTemp))
				{
					pTemp	= NULL;
				}
			}
			else
			{
				pTemp	= NULL;
			}
			//	���l���擾�ł����Ƃ��� pTemp �� NULL �ȊO�̒l���Z�b�g����Ă���B
			if (pTemp)
			{
				if (dValue == std::numeric_limits<double>::infinity() ||
					dValue == -std::numeric_limits<double>::infinity())
				{
					XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNum, true);
					return true;
				}
				else
				{
					pxRet->xltype	= xltypeNum;
					pxRet->val.num	= dValue;
					XLL::SetDLLFree(pxRet);
					return true;
				}
			}
			//	���l���擾�ł��Ȃ��ꍇ�́A��֒l���R�s�[����B
			else
			{
				switch (pxRepF->xltype)
				{
				case xltypeNum:
				case xltypeBool:
				case xltypeInt:
					XLL::CopyXLOPER<XLOPER12>(pxRet, pxRepF);
					XLL::SetDLLFree(pxRet);
					break;

				case xltypeStr:
					if (pxOpt != NULL &&
						t_XLCRegEx_IsOptionSet<T_CHAR_U, XLOPER12>(pxOpt, TQU("q")))
					{
						if (!XLL::XLRemoveQuote<wchar_t>(&pBegin, &pEnd, pxRepF, 0, NULL))
						{
							//XLCRegEx::LogError<T_CHAR_U>(TQU("Text is collapsed."));
							//return false;
							pBegin	= NullStr;
							pEnd	= NullStr;
						}
					}
					else
					{
						if (!XLL::GetXLOPERString<T_CHAR_U, XLOPER12>(&pBegin, &pEnd, pxRepF))
						{
							pBegin	= NullStr;
							pEnd	= NullStr;
						}
					}
					XLL::SetXLOPER_Str<T_CHAR_U, XLOPER12>(pxRet, pBegin, (size_t)(pEnd - pBegin), true);
					break;

				default:
					XLL::SetXLOPER_Nil<XLOPER12>(pxRet, true);
					break;
				}
				return true;
			}
		}
		//--------------------------------------------------
		//	�o�͂���l�� XLOPER �Ɋi�[����B(2)	����ȊO
		//--------------------------------------------------
		else
		{
			if (XLL::SetXLOPER_Str<T_CHAR_U, XLOPER12>(pxRet, strOutput.c_str(), strOutput.size(), true))
			{
				return true;
			}
			//	pxRet �ɕ�������i�[�ł��Ȃ��ꍇ�� Null �G���[��Ԃ��B
			XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, true);
			return false;
		}
		break;

	default:
		break;
	}
	XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, true);
	return false;
}

//----------------------------------------------------------------------
//	XLCRegExTextProcessing4
//	�f�[�^�̕ϊ��Ɨ�O�������s���B
//----------------------------------------------------------------------
static XLOPER* XLCRegExTextProcessing4(int		iProcessing,
									   XLOPER*	pxPat,
									   XLOPER*	pxTxt,
									   XLOPER*	pxOpt,
									   XLOPER*	pxRepT,
									   XLOPER*	pxRepF)
{
	XLL::XLOPERConverter<>	ciConverter;
	XLOPER12	xPat12, xTxt12, xOpt12, xRepT12, xRepF12;
	XLOPER12	xRet12;
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
	xRet12.xltype	= xltypeNil;

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, true);
	}

	//------------------------------------------------------------
	//	�ϐ��̒l��ݒ肷��B
	//------------------------------------------------------------
	xPat12.xltype	= xltypeNil;
	if (PLib::IsPageReadWrite((LPVOID)pxPat))
	{
		if (!ciConverter.Convert<XLOPER12, XLOPER>(&xPat12, pxPat))
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
			goto END_PROCESSING;
		}
	}

	xTxt12.xltype	= xltypeNil;
	if (PLib::IsPageReadWrite((LPVOID)pxTxt))
	{
		if (!ciConverter.Convert<XLOPER12, XLOPER>(&xTxt12, pxTxt))
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
			goto END_PROCESSING;
		}
	}

	xOpt12.xltype	= xltypeNil;
	if (PLib::IsPageReadWrite((LPVOID)pxOpt))
	{
		if (!ciConverter.Convert<XLOPER12, XLOPER>(&xOpt12, pxOpt))
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
			goto END_PROCESSING;
		}
	}

	xRepT12.xltype	= xltypeNil;
	if (PLib::IsPageReadWrite((LPVOID)pxRepT))
	{
		if (!ciConverter.Convert<XLOPER12, XLOPER>(&xRepT12, pxRepT))
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
			goto END_PROCESSING;
		}
	}

	xRepF12.xltype	= xltypeNil;
	if (PLib::IsPageReadWrite((LPVOID)pxRepF))
	{
		if (!ciConverter.Convert<XLOPER12, XLOPER>(&xRepF12, pxRepF))
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
			goto END_PROCESSING;
		}
	}

	//------------------------------------------------------------
	//	���ۂ̏����� XLCRegExTextProcessing_exec ���s���B
	//------------------------------------------------------------
	try
	{
		XLCRegExTextProcessing_exec(
			&xRet12, iProcessing, &xPat12, &xTxt12, &xOpt12, &xRepT12, &xRepF12);
		if (ciConverter.Convert<XLOPER, XLOPER12>(pxRet4, &xRet12))
		{
			XLL::SetDLLFree(pxRet4);
		}
		else
		{
			XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
		}
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, true);
	}

	//------------------------------------------------------------
	//	�I������
	//------------------------------------------------------------
END_PROCESSING:
	XLL::DeleteXLOPER<XLOPER12>(&xPat12);
	XLL::DeleteXLOPER<XLOPER12>(&xTxt12);
	XLL::DeleteXLOPER<XLOPER12>(&xOpt12);
	XLL::DeleteXLOPER<XLOPER12>(&xRepT12);
	XLL::DeleteXLOPER<XLOPER12>(&xRepF12);
	XLL::DeleteXLOPER<XLOPER12>(&xRet12);
	return pxRet4;
}

//----------------------------------------------------------------------
//	XLCRegExTextProcessing12
//	��O�����ƈ����̉�����s���B
//----------------------------------------------------------------------
static XLOPER12* XLCRegExTextProcessing12(int		iProcessing,
										  XLOPER12*	pxPat,
										  XLOPER12*	pxTxt,
										  XLOPER12*	pxOpt,
										  XLOPER12*	pxRepT,
										  XLOPER12*	pxRepF)
{
	XLOPER12*	pxRet;

	try
	{
		pxRet	= XLL::AllocateXLOPER<XLOPER12>();
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
	//if (!PLib::IsPageReadWrite((LPVOID)pxPat)	||
	//	!PLib::IsPageReadWrite((LPVOID)pxTxt)	||
	//	!PLib::IsPageReadWrite((LPVOID)pxOpt)	||
	//	!PLib::IsPageReadWrite((LPVOID)pxRepT)	||
	//	!PLib::IsPageReadWrite((LPVOID)pxRepF)	)
	//{
	//	return XLL::SetXLOPER_Nil<XLOPER12>(pxRet, true);
	//}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet, true);
	}

	//------------------------------------------------------------
	//	���ۂ̏����� XLCRegExTextProcessing_exec ���s���B
	//------------------------------------------------------------
	try
	{
		XLCRegExTextProcessing_exec(
			pxRet, iProcessing, pxPat, pxTxt, pxOpt, pxRepT, pxRepF);
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, true);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, true);
	}
	return pxRet;
}


//======================================================================
//	XLCRegExMatch
//======================================================================
//----------------------------------------------------------------------
//	XLCRegExMatch4
//----------------------------------------------------------------------
XLOPER* WINAPI XLCRegExMatch4(XLOPER*	pxPat,
							  XLOPER*	pxTxt,
							  XLOPER*	pxOpt)
{
#ifdef	XLL_AVAILABLE_TO_EXCEL11
	return XLCRegExTextProcessing4(
		XLREGEX_TEXTPROCESSING_MATCH, pxPat, pxTxt, pxOpt, NULL, NULL);
#else
	return NULL;
#endif
}

//----------------------------------------------------------------------
//	XLCRegExMatch12
//----------------------------------------------------------------------
XLOPER12* WINAPI XLCRegExMatch12(XLOPER12*	pxPat,
								 XLOPER12*	pxTxt,
								 XLOPER12*	pxOpt)
{
	return XLCRegExTextProcessing12(
		XLREGEX_TEXTPROCESSING_MATCH, pxPat, pxTxt, pxOpt, NULL, NULL);
}


//======================================================================
//	XLCRegExFormat
//	���K�\���Əo�͏����ɏ]���āA�e�L�X�g�𐮌`����B
//======================================================================
//----------------------------------------------------------------------
//	XLCRegExFormat4
//----------------------------------------------------------------------
XLOPER* WINAPI XLCRegExFormat4(XLOPER*	pxPat,
							   XLOPER*	pxRep,
							   XLOPER*	pxTxt,
							   XLOPER*	pxOpt)
{
#ifdef	XLL_AVAILABLE_TO_EXCEL11
	return XLCRegExTextProcessing4(
		XLREGEX_TEXTPROCESSING_FORMAT, pxPat, pxTxt, pxOpt, pxRep, NULL);
#else
	return NULL;
#endif
}

//----------------------------------------------------------------------
//	XLCRegExFormat12
//----------------------------------------------------------------------
XLOPER12* WINAPI XLCRegExFormat12(XLOPER12*	pxPat,
								  XLOPER12*	pxRep,
								  XLOPER12*	pxTxt,
								  XLOPER12*	pxOpt)
{
	return XLCRegExTextProcessing12(
		XLREGEX_TEXTPROCESSING_FORMAT, pxPat, pxTxt, pxOpt, pxRep, NULL);
}


//======================================================================
//	XLCRegExFormatIF
//	���K�\���Əo�͏�������яƍ��̌��ʂɏ]���āA�e�L�X�g�𐮌`����B
//======================================================================
//----------------------------------------------------------------------
//	XLCRegExFormatIf4
//----------------------------------------------------------------------
XLOPER* WINAPI XLCRegExFormatIf4(XLOPER*	pxPat,
								 XLOPER*	pxRepT,
								 XLOPER*	pxRepF,
								 XLOPER*	pxTxt,
								 XLOPER*	pxOpt)
{
#ifdef	XLL_AVAILABLE_TO_EXCEL11
	return XLCRegExTextProcessing4(
		XLREGEX_TEXTPROCESSING_FORMATIF, pxPat, pxTxt, pxOpt, pxRepT, pxRepF);
#else
	return NULL;
#endif
}

//----------------------------------------------------------------------
//	XLCRegExFormatIf12
//----------------------------------------------------------------------
XLOPER12* WINAPI XLCRegExFormatIf12(XLOPER12*	pxPat,
									XLOPER12*	pxRepT,
									XLOPER12*	pxRepF,
									XLOPER12*	pxTxt,
									XLOPER12*	pxOpt)
{
	return XLCRegExTextProcessing12(
		XLREGEX_TEXTPROCESSING_FORMATIF, pxPat, pxTxt, pxOpt, pxRepT, pxRepF);
}


//======================================================================
//	XLCRegExReplace
//======================================================================
//----------------------------------------------------------------------
//	XLCRegExReplace4
//----------------------------------------------------------------------
XLOPER* WINAPI XLCRegExReplace4(XLOPER*	pxPat,
								XLOPER*	pxRep,
								XLOPER*	pxTxt,
								XLOPER*	pxOpt)
{
#ifdef	XLL_AVAILABLE_TO_EXCEL11
	return XLCRegExTextProcessing4(
		XLREGEX_TEXTPROCESSING_REPLACE, pxPat, pxTxt, pxOpt, pxRep, NULL);
#else
	return NULL;
#endif
}

//----------------------------------------------------------------------
//	XLCRegExReplace12
//----------------------------------------------------------------------
XLOPER12* WINAPI XLCRegExReplace12(XLOPER12*	pxPat,
								   XLOPER12*	pxRep,
								   XLOPER12*	pxTxt,
								   XLOPER12*	pxOpt)
{
	return XLCRegExTextProcessing12(
		XLREGEX_TEXTPROCESSING_REPLACE, pxPat, pxTxt, pxOpt, pxRep, NULL);
}


//======================================================================
//	XLCRegExValue
//======================================================================
//----------------------------------------------------------------------
//	XLCRegExValue4
//----------------------------------------------------------------------
XLOPER* WINAPI XLCRegExValue4(XLOPER*	pxPat,
							  XLOPER*	pxRep,
							  XLOPER*	pxTxt,
							  XLOPER*	pxOpt,
							  XLOPER*	pxAlt)
{
#ifdef	XLL_AVAILABLE_TO_EXCEL11
	return XLCRegExTextProcessing4(
		XLREGEX_TEXTPROCESSING_VALUE, pxPat, pxTxt, pxOpt, pxRep, pxAlt);
#else
	return NULL;
#endif
}

//----------------------------------------------------------------------
//	XLCRegExValue12
//----------------------------------------------------------------------
XLOPER12* WINAPI XLCRegExValue12(XLOPER12*	pxPat,
								 XLOPER12*	pxRep,
								 XLOPER12*	pxTxt,
								 XLOPER12*	pxOpt,
								 XLOPER12*	pxAlt)
{
	return XLCRegExTextProcessing12(
		XLREGEX_TEXTPROCESSING_VALUE, pxPat, pxTxt, pxOpt, pxRep, pxAlt);
}
