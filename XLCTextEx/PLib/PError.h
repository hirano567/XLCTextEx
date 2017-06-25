//	XLCTextEx_1.0x	:	PLib

//	PError.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	t_FormatMessage �֐�
//
//	FormatMessage �֐����g�������邽�߂̃e���v���[�g�֐��B
//======================================================================
//----------------------------------------------------------------------
//	
//----------------------------------------------------------------------
template<typename T_CODE, typename T_CHAR>
inline DWORD t_FormatMessage(DWORD		dwFlags,
							 LPCVOID	pSource,
							 T_CODE		tMessageId,
							 DWORD		dwLanguageId,
							 T_CHAR*	pBuffer,
							 DWORD		nSize,
							 va_list	*Arguments)
{
	throw std::logic_error(std::string("t_FormatMessage: invalid template parameters."));
	return (DWORD)0;
}
//----------------------------------------------------------------------
//	DWORD, char
//----------------------------------------------------------------------
template<>
inline DWORD t_FormatMessage<DWORD, char>(DWORD		dwFlags,
										  LPCVOID	pSource,
										  DWORD		dwMessageId,	//	�G���[�R�[�h�� DWORD �^
										  DWORD		dwLanguageId,
										  LPSTR		pBuffer,	//	�o�b�t�@�̓}���`�o�C�g������p
										  DWORD		nSize,
										  va_list	*Arguments)
{
	return FormatMessageA(
		dwFlags,
		pSource,
		dwMessageId,	//	�G���[�R�[�h�� DWORD �^
		dwLanguageId,
		pBuffer,		//	�o�b�t�@�̓}���`�o�C�g������p
		nSize,
		Arguments);
}
//----------------------------------------------------------------------
//	DWORD, wchar_t
//----------------------------------------------------------------------
template<>
inline DWORD t_FormatMessage<DWORD, wchar_t>(DWORD		dwFlags,
											 LPCVOID	pSource,
											 DWORD		dwMessageId,	//	�G���[�R�[�h�� DWORD �^
											 DWORD		dwLanguageId,
											 LPWSTR		pBuffer,	//	�o�b�t�@�̓��C�h������p
											 DWORD		nSize,
											 va_list	*Arguments)
{
	return FormatMessageW(
		dwFlags,
		pSource,
		dwMessageId,	//	�G���[�R�[�h�� DWORD �^
		dwLanguageId,
		pBuffer,		//	�o�b�t�@�̓}���`�o�C�g������p
		nSize,
		Arguments);
}
//----------------------------------------------------------------------
//	HRESULT, char
//----------------------------------------------------------------------
template<>
inline DWORD t_FormatMessage<HRESULT, char>(DWORD	dwFlags,
											LPCVOID	pSource,
											HRESULT	hrMessageId,	//	�G���[�R�[�h�� HRESULT �^
											DWORD	dwLanguageId,
											LPSTR	pBuffer,	//	�o�b�t�@�̓}���`�o�C�g������p
											DWORD	nSize,
											va_list	*Arguments)
{
	return FormatMessageA(
		dwFlags,
		pSource,
		hrMessageId,	//	�G���[�R�[�h�� HRESULT �^
		dwLanguageId,
		pBuffer,		//	�o�b�t�@�̓}���`�o�C�g������p
		nSize,
		Arguments);
}
//----------------------------------------------------------------------
//	HRESULT, wchar_t
//----------------------------------------------------------------------
template<>
inline DWORD t_FormatMessage<HRESULT, wchar_t>(DWORD	dwFlags,
											   LPCVOID	pSource,
											   HRESULT	hrMessageId,	//	�G���[�R�[�h�� HRESULT �^
											   DWORD	dwLanguageId,
											   LPWSTR	pBuffer,		//	�o�b�t�@�̓��C�h������p
											   DWORD	nSize,
											   va_list	*Arguments)
{
	return FormatMessageW(
		dwFlags,
		pSource,
		hrMessageId,	//	�G���[�R�[�h�� HRESULT �^
		dwLanguageId,
		pBuffer,		//	�o�b�t�@�̓��C�h������p
		nSize,
		Arguments);
}
//----------------------------------------------------------------------
//	int, char
//----------------------------------------------------------------------
template<>
inline DWORD t_FormatMessage<int, char>(DWORD	dwFlags,
										LPCVOID	pSource,
										int		iMessageId,		//	�G���[�R�[�h�� int �^
										DWORD	dwLanguageId,
										LPSTR	pBuffer,		//	�o�b�t�@�̓}���`�o�C�g������p
										DWORD	nSize,
										va_list	*Arguments)
{
	return FormatMessageA(
		dwFlags,
		pSource,
		(DWORD)iMessageId,	//	�G���[�R�[�h�� int �^�iDWORD �ɃL���X�g����j
		dwLanguageId,
		pBuffer,			//	�o�b�t�@�̓}���`�o�C�g������p
		nSize,
		Arguments);
}
//----------------------------------------------------------------------
//	int, wchar_t
//----------------------------------------------------------------------
template<>
inline DWORD t_FormatMessage<int, wchar_t>(DWORD	dwFlags,
										   LPCVOID	pSource,
										   int		iMessageId,		//	�G���[�R�[�h�� int �^
										   DWORD	dwLanguageId,
										   LPWSTR	pBuffer,		//	�o�b�t�@�̓��C�h������p
										   DWORD	nSize,
										   va_list	*Arguments)
{
	return FormatMessageW(
		dwFlags,
		pSource,
		(DWORD)iMessageId,	//	�G���[�R�[�h�� int �^�iDWORD �ɃL���X�g����j
		dwLanguageId,
		pBuffer,			//	�o�b�t�@�̓��C�h������p
		nSize,
		Arguments);
}


//======================================================================
//  ErrorCodeToMessageMa
//	ErrorCodeToMessage		: std::basic_string �ɒǉ�����B
//
//	�w�肳�ꂽ�G���[�R�[�h����G���[���b�Z�[�W�𐶐�����B
//	�m�ۂ��ꂽ�o�b�t�@�͌Ăяo�������ŉ�����邱�ƁB
//======================================================================
template<typename T_CHAR, typename T_CODE>
BOOL ErrorCodeToMessageMa(T_CHAR** ppMessage, size_t* pzMessage, T_CODE nCode)
{
	T_CHAR*	pBuffer = NULL;
	DWORD	dwRet;
	size_t	zCopied;
	BOOL	br	= FALSE;

	if (ppMessage == NULL || pzMessage == NULL)	return FALSE;
	*ppMessage	= NULL;
	*pzMessage	= 0;

	dwRet = t_FormatMessage<T_CODE, T_CHAR>(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		nCode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(T_CHAR*)&pBuffer,
		0,
		NULL
		);

	if (dwRet > 0)
	{
		//	std::bad_alloc ��O�� StrCopyMa() ���ŏ��������B
		try
		{
			br = NS_PLIB::StrCopyMa<T_CHAR>(ppMessage, &zCopied, (const T_CHAR*)pBuffer);
		}
		catch(...)
		{
			br	= FALSE;
		}
	}

	if (pBuffer != NULL)
	{
		LocalFree((HLOCAL)pBuffer);
	}

	return br;
}

template<typename T_CHAR, typename T_CODE>
BOOL ErrorCodeToMessage(std::basic_string<T_CHAR> pstrMessage, T_CODE nCode)
{
	T_CHAR*	pBuffer = NULL;
	DWORD	dwRet;
	size_t	zCopied;
	BOOL	br	= TRUE;

	if (pstrMessage == NULL)	return FALSE;

	dwRet = t_FormatMessage<T_CODE, T_CHAR>(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		nCode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(T_CHAR*)&pBuffer,
		0,
		NULL
		);

	if (dwRet > 0)
	{
		try
		{
			pstrMessage->append(pBuffer);
		}
		catch(...)
		{
			br	= FALSE;
		}
	}

	if (pBuffer != NULL)
	{
		LocalFree((HLOCAL)pBuffer);
	}

	return br;
}


//======================================================================
//	MakeErrorMessage	(1)
//======================================================================
template<typename T_CHAR>
inline BOOL MakeErrorMessage(T_CHAR*		pBuffer,
							 const size_t	zBuffer,
							 DWORD			dwCode)
{
	throw std::logic_error("MakeErrorMessage");
	return FALSE;
}
template<>
inline BOOL MakeErrorMessage<char>(LPSTR		pBuffer,
								   const size_t	zBuffer,
								   DWORD		dwCode)
{
	HRESULT	hr;
	DWORD	dwc;
	LPSTR	pMsg	= NULL;
	size_t	zMsg	= 0;

	if (pBuffer == NULL || zBuffer < 1)	return FALSE;

	dwc	= (0xFFFF & dwCode);
	if (!ErrorCodeToMessageMa<char, DWORD>(&pMsg, &zMsg, dwc) || zMsg < 1)	return FALSE;
	hr = StringCchPrintfA(pBuffer, zBuffer, "(%d) %s", dwc, pMsg);
	delete[]	pMsg;
	return SUCCEEDED(hr);
}
template<>
inline BOOL MakeErrorMessage<wchar_t>(LPWSTR		pBuffer,
									  const size_t	zBuffer,
									  DWORD			dwCode)
{
	HRESULT	hr;
	DWORD	dwc;
	LPWSTR	pMsg	= NULL;
	size_t	zMsg	= 0;

	if (pBuffer == NULL || zBuffer < 1)	return FALSE;

	dwc	= (0xFFFF & dwCode);
	if (!ErrorCodeToMessageMa<wchar_t, DWORD>(&pMsg, &zMsg, dwc) || zMsg < 1)	return FALSE;
	hr = StringCchPrintfW(pBuffer, zBuffer, L"(%d) %s", dwc, pMsg);
	delete[]	pMsg;
	return SUCCEEDED(hr);
}

//======================================================================
//	MakeErrorMessage	(2)
//======================================================================
template<typename T_CHAR>
inline BOOL MakeErrorMessage(std::basic_string<T_CHAR>*	pstrBuffer,
							 DWORD						dwCode)
{
	const size_t	zBuf	= 256;
	T_CHAR			Buf[zBuf];

	if (MakeErrorMessage(Buf, zBuf, dwCode))
	{
		pstrBuffer->append(Buf);
		return TRUE;
	}
	return FALSE;
}

//======================================================================
//	ErrorMessageBox
//======================================================================
template<typename T_CHAR>
int ErrorMessageBox(DWORD dwCode, LPCWSTR pszMsg)
{
	std::basic_string<T_CHAR>	strBuffer;

	if (!MakeErrorMessage<T_CHAR>(&strBuffer, dwCode))
	{
		strBuffer.append(t_Str<T_CHAR>(TEXTAW("unknown error.")));
	}
	if (pszMsg != NULL)
	{
		strBuffer.append(t_Str<T_CHAR>(TEXTAW("\r\n")));
		strBuffer.append(pszMsg);
	}
	return t_MessageBox<T_CHAR>(NULL, strBuffer.c_str(), t_Str<T_CHAR>(TEXTAW("Error")), MB_OK);
}


NS_PLIB_END


//======================================================================
//	�G���[�����p�̃}�N��
//======================================================================
#ifndef	MSG_NOT_ENOUGH_MEMORY
#define	MSG_NOT_ENOUGH_MEMORY(msg)	NS_PLIB::ErrorMessageBox<T_CHAR_U>(ERROR_NOT_ENOUGH_MEMORY, TQU(msg));
#endif

#define THROW_NOT_ENOUGH_MEMORY(msg)	throw NS_PLIB::PException(msg, (DWORD)ERROR_NOT_ENOUGH_MEMORY)

#ifndef	MSG_INVALID_PARAMETER
#define	MSG_INVALID_PARAMETER(msg)	NS_PLIB::ErrorMessageBox(ERROR_INVALID_PARAMETER, msg)
#endif

#define THROW_INVALID_PARAMETER(msg)	throw NS_PLIB::PException(msg, (DWORD)ERROR_INVALID_PARAMETER)

#ifndef	MSG_BAD_ARGUMENTS
#define	MSG_BAD_ARGUMENTS(msg)	NS_PLIB::ErrorMessageBox(ERROR_BAD_ARGUMENTS, msg)
#endif

#define THROW_BAD_ARGUMENTS(msg)	throw NS_PLIB::PException(msg, (DWORD)ERROR_BAD_ARGUMENTS)

