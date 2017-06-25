//	XLCTextEx_1.0x	:	XLCTextEx

//	XLError.cpp
//
#include "stdafx.h"

NS_XLCREGEX_BEGIN

//======================================================================
//	PCLogManager
//======================================================================
template<typename T_CHAR>
class PCLogManager
{
private:
	typedef	const T_CHAR*				T_PCSTR;
	typedef	std::basic_string<T_CHAR>	T_STRING;

	typedef	std::list<T_STRING*>			CONTAINER;
	typedef	typename CONTAINER::iterator	ITERATOR;

	//------------------------------------------------------------
	//	�f�[�^�����o
	//------------------------------------------------------------
	CONTAINER	ciContainer;
	size_t		zMaxLogs;

		PLib::PCInstanceSet<T_STRING, 8>	ciIPString;

	//------------------------------------------------------------
	//	�����o�֐�
	//------------------------------------------------------------
public:
	void Clear()
	{
		ITERATOR	itr;

		for (itr = ciContainer.begin(); itr != ciContainer.end(); ++itr)
		{
			(*itr)->clear();
		}
		ciContainer.clear();
		ciIPString.Clear();
	}

	PCLogManager(size_t zMax = 8)
		:	zMaxLogs(zMax)
	{
		if (zMaxLogs < 1)	zMaxLogs = 1;
	}

	~PCLogManager()
	{
		Clear();
	}

	void SetMax(size_t zMax)
	{
		if (zMax > 0)	zMaxLogs = zMax;
	}

	void Delete(T_STRING* ps)
	{
		ps->clear();
		ciIPString.Deallocate(ps);
	}

	void DeleteOld()
	{
		ITERATOR	itr;

		while (ciContainer.size() >= zMaxLogs)
		{
			itr	= ciContainer.end();
			--itr;
			Delete(*itr);
			ciContainer.pop_back();
		}
	}

	BOOL Log(T_STRING* pLog)
	{
		if (pLog == NULL)	return FALSE;
		try
		{
			ciContainer.push_front(pLog);
		}
		catch (...)
		{
			return FALSE;
		}
		return TRUE;
	}

	BOOL Log(T_PCSTR pszLog)
	{
		T_STRING*	ps	= NULL;

		DeleteOld();
		try
		{
			ps	= ciIPString.Allocate();
			ps->assign(pszLog);
		}
		catch (...)
		{
			if (ps != NULL)
			{
				ps->clear();
				ciIPString.Deallocate(ps);
			}
			return FALSE;
		}
		return Log(ps);
	}

	BOOL Log(T_PCSTR pLog, size_t zLog)
	{
		T_STRING*	ps;

		DeleteOld();
		try
		{
			ps	= ciIPString.Allocate();
			ps->assign(pLog, zLog);
		}
		catch (...)
		{
			if (ps != NULL)
			{
				ps->clear();
				ciIPString.Deallocate(ps);
			}
			return FALSE;
		}
		return Log(ps);
	}

	T_STRING* Get(int iIndex = 0)
	{
		ITERATOR	itr;
		size_t		zi;

		if (ciContainer.empty())	return NULL;
		if (iIndex == 0)			return *(ciContainer.begin());
		if ((size_t)iIndex >= ciContainer.size() || iIndex < 0)	return NULL;

		itr = ciContainer.begin();
		zi = 0;
		do
		{
			++itr;
			++zi;
		}
		while (zi < (size_t)iIndex);
		return *itr;
	}
};

//----------------------------------------------------------------------
//	PCLogManager �̃C���X�^���X�̃|�C���^
//----------------------------------------------------------------------
PCLogManager<char>*		pciLogManagerA	= NULL;
PCLogManager<wchar_t>*	pciLogManagerW	= NULL;


//----------------------------------------------------------------------
//	LogError
//----------------------------------------------------------------------
void LogError4(LPCSTR pszError)
{
	if (pciLogManagerA == NULL)
	{
		try
		{
			pciLogManagerA	= new PCLogManager<char>;
		}
		catch (...)
		{
			return;
		}
	}
	if (pciLogManagerA != NULL)
	{
		pciLogManagerA->Log(pszError);
	}
}

void LogError12(LPCWSTR pszError)
{
	if (pciLogManagerW == NULL)
	{
		try
		{
			pciLogManagerW	= new PCLogManager<wchar_t>;
		}
		catch (...)
		{
			return;
		}
	}
	if (pciLogManagerW != NULL)
	{
		pciLogManagerW->Log(pszError);
	}
}

//----------------------------------------------------------------------
//	GetErrorLog
//----------------------------------------------------------------------
std::string* GetErrorLog4(int iIndex)
{
	if (pciLogManagerA != NULL)
	{
		return pciLogManagerA->Get(iIndex);
	}
	return NULL;
}

std::wstring* GetErrorLog12(int iIndex)
{
	if (pciLogManagerW != NULL)
	{
		return pciLogManagerW->Get(iIndex);
	}
	return NULL;
}

//----------------------------------------------------------------------
//	ClearErrorLog
//----------------------------------------------------------------------
void ClearErrorLog4()
{
	if (pciLogManagerA != NULL)
	{
		return pciLogManagerA->Clear();
	}
}

void ClearErrorLog12()
{
	if (pciLogManagerW != NULL)
	{
		return pciLogManagerW->Clear();
	}
}

//----------------------------------------------------------------------
//	CleanupErrorLog
//----------------------------------------------------------------------
void CleanupErrorLog()
{
	delete	pciLogManagerA;
	delete	pciLogManagerW;
}

NS_XLCREGEX_END


//======================================================================
//	XLCRegExError
//======================================================================
//----------------------------------------------------------------------
//	t_XLCRegExError
//	�G���[���ɂ͗�O���X���[����B
//	�����̉���͌Ăяo�����ōs�����ƁB
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_XLOPER>
BOOL t_XLCRegExError(T_XLOPER* pxRet, T_XLOPER* pxIndex)
{
	typedef	const T_CHAR*				T_PCSTR;
	typedef	std::basic_string<T_CHAR>	T_STRING;

	int			iIndex;
	T_STRING*	pstrError;

	if (pxRet == NULL)
	{
		THROWPE_LOGIC_ERROR("t_XLCRegExError");
	}

	if (pxIndex == NULL)
	{
		iIndex	= 0;
	}
	else
	{
		switch (pxIndex->xltype)
		{
		case xltypeNum:
			iIndex	= (int)pxIndex->val.num;
			break;

		case xltypeMissing:
			iIndex	= 0;
			break;

		case xltypeInt:
			iIndex	= (int)pxIndex->val.w;
			break;

		default:
			XLL::SetXLOPER_Err<T_XLOPER>(pxRet, xlerrValue, TRUE);
			return FALSE;
			break;
		}
	}

	pstrError	= XLCRegEx::GetErrorLog<T_CHAR>(iIndex);
	if (pstrError == NULL)
	{
		XLL::SetXLOPER_Err<T_XLOPER>(pxRet, xlerrNull, TRUE);
		return FALSE;
	}

	try
	{
		XLL::SetXLOPER_Str<T_CHAR, T_XLOPER>(pxRet, pstrError->c_str(), TRUE);
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<T_XLOPER>(pxRet, xlerrNull, TRUE);
		return FALSE;
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<T_XLOPER>(pxRet, xlerrNull, TRUE);
		return FALSE;
	}
	return TRUE;
}

//----------------------------------------------------------------------
//	XLCRegExError4
//----------------------------------------------------------------------
XLOPER* WINAPI XLCRegExError4(XLOPER* pxIndex4)
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
		XLL::FreeXLOPER<XLOPER>(pxIndex4);
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, TRUE);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		XLL::FreeXLOPER<XLOPER>(pxIndex4);
		return XLL::SetXLOPER_Missing<XLOPER>(pxRet4, TRUE);
	}

	//------------------------------------------------------------
	//	�ϐ��̒l��ݒ肷��B
	//------------------------------------------------------------
	if (!ciConverter.Convert<XLOPER12, XLOPER>(&xIndex12, pxIndex4))
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
		goto END_PROCESSING;
	}

	//------------------------------------------------------------
	//	�G���[���b�Z�[�W�����o���B
	//------------------------------------------------------------
	try
	{
		t_XLCRegExError<wchar_t, XLOPER12>(&xRet12, &xIndex12);
		if (ciConverter.Convert<XLOPER, XLOPER12>(pxRet4, &xRet12))
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

END_PROCESSING:
	XLL::FreeXLOPER<XLOPER>(pxIndex4);
	XLL::DeleteXLOPER<XLOPER12>(&xIndex12);
	XLL::DeleteXLOPER<XLOPER12>(&xRet12);
	return pxRet4;
}

//----------------------------------------------------------------------
//	XLCRegExError12
//----------------------------------------------------------------------
XLOPER12* WINAPI XLCRegExError12(XLOPER12* pxIndex)
{
	XLOPER12*	pxRet;

	try
	{
		pxRet	= XLL::AllocateXLOPER<XLOPER12>();
	}
	catch (std::bad_alloc&)
	{
		XLL::FreeXLOPER<XLOPER12>(pxIndex);
		MSG_NOT_ENOUGH_MEMORY("");
		return NULL;
	}
	catch (...)
	{
		XLL::FreeXLOPER<XLOPER12>(pxIndex);
		return NULL;
	}

	//------------------------------------------------------------
	//	�������`�F�b�N����B
	//	���͒��ɌĂяo����邱�Ƃ�����̂ŁAErr �ł͂Ȃ� Nil ��Ԃ��B
	//------------------------------------------------------------
	if (!PLib::IsPageReadWrite((LPVOID)pxIndex))
	{
		XLL::FreeXLOPER<XLOPER12>(pxIndex);
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet, TRUE);
	}

	//------------------------------------------------------------
	//	Excel �� Owner �Ƃ���_�C�A���O���J���Ă���ꍇ�A
	//	�����̓��͂���������O�Ɋ֐����Ăяo�����Ƃ�����̂ŁA�܂��������s��Ȃ��B
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		XLL::FreeXLOPER<XLOPER12>(pxIndex);
		return XLL::SetXLOPER_Missing<XLOPER12>(pxRet, TRUE);
	}

	//------------------------------------------------------------
	//	�G���[���b�Z�[�W�����o���A�Ԃ�l��ݒ肷��B
	//------------------------------------------------------------
	try
	{
		t_XLCRegExError<wchar_t, XLOPER12>(pxRet, pxIndex);
	}
	catch (std::bad_alloc&)
	{
		MSG_NOT_ENOUGH_MEMORY("");
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, TRUE);
	}
	catch (...)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet, xlerrNull, TRUE);
	}

	XLL::FreeXLOPER<XLOPER12>(pxIndex);
	return pxRet;
}
