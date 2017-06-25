//	XLCTextEx_1.0x	:	PLib

//	PWindowUtility.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	各関数のテンプレート
//======================================================================
/*
//----------------------------------------------------------------------
//	t_MessageBox
//----------------------------------------------------------------------
template<typename T_CHAR>
inline int t_MessageBox(const T_CHAR* pszMessage, const T_CHAR* pszTitle)
{
	return 0;
}
template<>
inline int t_MessageBox<char>(LPCSTR pszMessage, LPCSTR pszTitle)
{
	if (pszMessage != NULL)
	{
		if (pszTitle == NULL)	pszTitle = pszTitleDefaultA;
		return MessageBoxA(NULL, pszMessage, pszTitle, MB_OK);
	}
	return 0;
}
template<>
inline int t_MessageBox<wchar_t>(LPCWSTR pszMessage, LPCWSTR pszTitle)
{
	if (pszMessage != NULL)
	{
		if (pszTitle == NULL)	pszTitle = pszTitleDefaultW;
		return MessageBoxW(NULL, pszMessage, pszTitle, MB_OK);
	}
	return 0;
}
*/

//----------------------------------------------------------------------
//	t_GetWindowTextLength
//----------------------------------------------------------------------
template<typename T_CHAR>
inline int t_GetWindowTextLength(HWND hWnd)
{
	return 0;
}
template<>
inline int t_GetWindowTextLength<char>(HWND hWnd)
{
	return GetWindowTextLengthA(hWnd);
}
template<>
inline int t_GetWindowTextLength<wchar_t>(HWND hWnd)
{
	return GetWindowTextLengthW(hWnd);
}

//----------------------------------------------------------------------
//	t_GetWindowText
//----------------------------------------------------------------------
template<typename T_CHAR>
inline int t_GetWindowText(HWND hWnd, T_CHAR* pBuffer, int iSize)
{
	return 0;
}
template<>
inline int t_GetWindowText<char>(HWND hWnd, LPSTR pBuffer, int iSize)
{
	if (pBuffer == NULL || iSize < 1)	return 0;
	return GetWindowTextA(hWnd, pBuffer, iSize);
}
template<>
inline int t_GetWindowText<wchar_t>(HWND hWnd, LPWSTR pBuffer, int iSize)
{
	if (pBuffer == NULL || iSize < 1)	return 0;
	return GetWindowTextW(hWnd, pBuffer, iSize);
}

//----------------------------------------------------------------------
//	t_GetWindowText
//	std::basic_string にコピーする。
//	例外は呼び出し側で処理すること。
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL t_GetWindowText(HWND hWnd, std::basic_string<T_CHAR>* pstrBuffer)
{
	T_CHAR*	pBuffer	= NULL;
	int		iBuffer	= 0;
	int		iCount	= 0;
	BOOL	br		= TRUE;

	if (pstrBuffer == NULL)	return FALSE;

	SetLastError(ERROR_SUCCESS);
	iBuffer	= t_GetWindowTextLength<T_CHAR>(hWnd);
	if (iBuffer < 1 && GetLastError() != ERROR_SUCCESS)	return FALSE;

	++iBuffer;
	pBuffer	= new T_CHAR[iBuffer + 1];

	SetLastError(ERROR_SUCCESS);
	iCount	= t_GetWindowText<T_CHAR>(hWnd, pBuffer, iBuffer);
	if (iCount > 0 && GetLastError() == ERROR_SUCCESS)
	{
		pstrBuffer->assign(pBuffer, iCount);
	}
	else
	{
		br	= FALSE;
	}
	delete[]	pBuffer;
	return br;
}

//----------------------------------------------------------------------
//	t_GetWindowTextMa
//	メモリを確保し、そこにコピーする。呼び出し側で解放すること。
//	*pzStr にはバッファのサイズではなく、格納された文字数が返される。
//	例外は呼び出し側で処理すること。
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL t_GetWindowTextMa(HWND hWnd, T_CHAR** ppBuffer, size_t* pzText)
{
	T_CHAR*	pBuffer	= NULL;
	int		iBuffer	= 0;
	int		iCount	= 0;

	if (ppBuffer == NULL || pzText == NULL)	return FALSE;

	SetLastError(ERROR_SUCCESS);
	iBuffer	= t_GetWindowTextLength<T_CHAR>(hWnd);
	if (iBuffer < 1 && GetLastError() != ERROR_SUCCESS)	return FALSE;

	++iBuffer;
	pBuffer	= new T_CHAR[iBuffer];

	SetLastError(ERROR_SUCCESS);
	iCount	= t_GetWindowText<T_CHAR>(hWnd, pBuffer, iBuffer);
	if (iCount < 1 && GetLastError() != ERROR_SUCCESS)
	{
		delete[]	pBuffer;
		*ppBuffer	= NULL;
		*pzText		= 0;
		return FALSE;
	}
	*ppBuffer	= pBuffer;
	*pzText		= (size_t)iCount;
	return TRUE;
}

//----------------------------------------------------------------------
//	t_SetWindowText
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL t_SetWindowText(HWND hWnd, const T_CHAR* pszText)
{
	return 0;
}
template<>
inline BOOL t_SetWindowText<char>(HWND hWnd, LPCSTR pszText)
{
	if (pszText == NULL)	return FALSE;
	return SetWindowTextA(hWnd, pszText);
}
template<>
inline BOOL t_SetWindowText<wchar_t>(HWND hWnd, LPCWSTR pszText)
{
	if (pszText == NULL)	return FALSE;
	return SetWindowTextW(hWnd, pszText);
}


/*
BOOL	GetWindowTextMaA(LPSTR* pBuffer, size_t* psizStr, HWND hWnd);
BOOL	GetWindowTextMaW(LPWSTR* pBuffer, size_t* psizStr, HWND hWnd);
*/


//======================================================================
//	ダイアログボックス
//======================================================================
//----------------------------------------------------------------------
//	t_DialogBoxParam	: DialogBoxParam のテンプレート
//----------------------------------------------------------------------
template<typename T_CHAR>
inline INT_PTR WINAPI t_DialogBoxParam(HINSTANCE hInst, WORD wDlgId, HWND hParent,
									   DLGPROC pDlgFunc, LPARAM lParam)
{
	throw std::logic_error("");
	return (INT_PTR)FALSE;
}
template<>
inline INT_PTR WINAPI t_DialogBoxParam<char>(HINSTANCE hInst, WORD wDlgId, HWND hParent,
											 DLGPROC pDlgFunc, LPARAM lParam)
{
	return DialogBoxParamA(hInst, MAKEINTRESOURCEA(wDlgId), hParent, pDlgFunc, lParam);
}
template<>
inline INT_PTR WINAPI t_DialogBoxParam<wchar_t>(HINSTANCE hInst, WORD wDlgId, HWND hParent,
												DLGPROC pDlgFunc, LPARAM lParam)
{
	return DialogBoxParamW(hInst, MAKEINTRESOURCEW(wDlgId), hParent, pDlgFunc, lParam);
}

NS_PLIB_END
