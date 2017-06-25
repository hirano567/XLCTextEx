//	XLCTextEx_1.0x	:	PLib

//	PCodePage.cpp
//
#include "stdafx.h"

NS_PLIB_BEGIN

//======================================================================
//	文字列の変換
//	マルチバイト文字列から Unicode 文字列へ変換する。
//======================================================================
//----------------------------------------------------------------------
//	GetSizeMBtoWC: 必要なバッファサイズを取得する。
//
//	終端のヌル文字は除く。
//	MultiByteToWideChar 関数の仕様により、
//	iSrc の値によって、得られる値は次のようになる。
//		-1		終端のヌル文字も含めた長さ。
//		正の値	終端は含めない。
//----------------------------------------------------------------------
bool GetSizeMBtoWC(size_t*	pzRequired,
				   LPCSTR	pSrc,
				   int		iSrc,
				   UINT		uiCodePage)
{
	int	iRet;

	if (pzRequired == NULL || pSrc == NULL)
	{
		return false;
	}
	*pzRequired	= 0;

	//	変換元文字列の長さに 0 を指定すると、関数は失敗する。
	if (iSrc < 1)
	{
		iSrc = -1;
	}

	iRet = MultiByteToWideChar(
		uiCodePage,	// (UINT) コードページ
		0,			// (DWORD) 文字の種類を指定するフラグ
		pSrc,		// (LPCSTR) マップ元文字列のアドレス
		iSrc,		// (int) マップ元文字列のバイト数
		NULL,		// (LPWSTR) マップ先ワイド文字列を入れるバッファのアドレス
		0			// (int) バッファのサイズ
		);

	if (iRet > 0)
	{
		*pzRequired	= (size_t)iRet;
		return true;
	}
	else
	{
		return false;
	}
}

//----------------------------------------------------------------------
//	ConvertMBtoWC: 変換する。
//
//	終端の処理は iSrc の値によって異なる。
//		-1		終端のヌル文字も含めて変換する。
//		正の値	指定された文字数分だけ変換する。
//----------------------------------------------------------------------
bool ConvertMBtoWC(LPWSTR	pDst,
					 size_t	zDst,
					 size_t*	pzConverted,
					 LPCSTR	pSrc,
					 int		iSrc,
					 UINT	uiCodePage)
{
	int	iDst, iRet;
	
	if (pDst == NULL || zDst < 1 || pzConverted == NULL || pSrc == NULL)
	{
		return false;
	}
	*pzConverted	= 0;
	iDst	= (int)(zDst < INT_MAX ? zDst : INT_MAX);

	//	変化元文字列の長さに 0 を指定すると、関数は失敗する。
	if (iSrc < 1)
	{
		iSrc = -1;
	}

	iRet = MultiByteToWideChar(
		uiCodePage,	// (UINT) コードページ
		0,			// (DWORD) 文字の種類を指定するフラグ
		pSrc,		// (LPCSTR) マップ元文字列のアドレス
		iSrc,		// (int) マップ元文字列のバイト数
		pDst,		// (LPWSTR) マップ先ワイド文字列を入れるバッファのアドレス
		iDst		// (int) バッファのサイズ
		);
	if (iSrc > 0)
	{
		*(pDst + iRet) = L'\0';
	}

	if (iRet > 0)
	{
		*pzConverted	= (size_t)iRet;
		return true;
	}
	else
	{
		*pzConverted	= 0;
		return false;
	}
}

/*
//----------------------------------------------------------------------
//	ConvertMBtoWCMa: バッファを確保し、変換する。
//
//	終端にはヌル文字を追加する。
//	バッファの解放は呼び出し側で行うこと（delete[] を使う）。
//	変換後の文字数を返す。
//----------------------------------------------------------------------
bool ConvertMBtoWCMa(LPWSTR*	ppDst,
					   size_t*	pzDst,
					   LPCSTR	pSrc,
					   int		iSrc,
					   UINT	uiCodePage)
{
	size_t	zDst;
	int		iBuf;

	if (ppDst == NULL || pzDst == NULL || pSrc == NULL)
	{
		return false;
	}
	*ppDst	= NULL;
	*pzDst	= 0;

	//	必要なバッファサイズを調べる。
	if (!GetSizeMBtoWC(&zDst, pSrc, iSrc, uiCodePage))
	{
		THROWPE_RUNTIME_ERROR("ConvertMBtoWCMa: GetSizeMBtoWC");
		return false;
	}
	if (zDst > INT_MAX - 1)
	{
		return false;
	}

	//	必要なバッファを確保し、変換する。
	//	MultiByteToWideChar の仕様では、必要なバッファサイズを求める際、
	//		iSrc に負の値が指定されると、終端の NULL も含めて計算する。
	//		iSrc に正の値が指定されると、終端の NULL は考慮しない。
	if (iSrc > 0)
	{
		iBuf = (int)zDst + 1;
	}
	else
	{
		iBuf = (int)zDst;
	}

	try
	{
		*ppDst = new wchar_t[iBuf];
	}
	CATCH_AND_RETURN_BAD_ALLOC(false, "");

	if (!ConvertMBtoWC(*ppDst, (size_t)iBuf, pzDst, pSrc, iSrc, uiCodePage))
	{
		goto ERROR_HANDLING;
	}

	return true;

ERROR_HANDLING:
	delete[]	*ppDst;
	*ppDst	= NULL;
	return false;
}
*/

//======================================================================
//	文字列の変換: Unicode 文字列からマルチバイト文字列へ変換する。
//======================================================================
//----------------------------------------------------------------------
//	GetSizeWCtoMB	:	必要なバッファサイズを求める。
//
//	終端のヌル文字は除く。
//	MultiByteToWideChar 関数の仕様により、
//	iSrc の値によって、得られる値は次のようになる。
//		-1		終端のヌル文字も含めた長さ。
//		正の値	終端は含めない。
//----------------------------------------------------------------------
bool GetSizeWCtoMB(size_t*		pzRequired,
					 LPCWSTR	pSrc,
					 int	iSrc,
					 UINT		uiCodePage)
{
	int	iRet;

	if (pzRequired == NULL || pSrc == NULL)
	{
		return false;
	}
	*pzRequired	= 0;

	//	変化元文字列の長さに 0 を指定すると、関数は失敗する。
	if (iSrc < 1)
	{
		iSrc = -1;
	}

	iRet	= WideCharToMultiByte(
		uiCodePage,	// コードページ
		0,			// 処理速度とマッピング方法を決定するフラグ
		pSrc,		// ワイド文字列のアドレス
		iSrc,		// ワイド文字列の文字数
		NULL,		// 新しい文字列を受け取るバッファのアドレス
		0,			// 新しい文字列を受け取るバッファのサイズ
		NULL,		// マップできない文字の既定値のアドレス
		NULL		// 既定の文字を使ったときにセットするフラグのアドレス
		);

	if (iRet > 0)
	{
		*pzRequired	= (size_t)iRet;
		return true;
	}
	else
	{
		return false;
	}
}

//----------------------------------------------------------------------
//	ConvertWCtoMB	:	変換する。変換後の文字数を返す。
//
//	終端の処理は iSrc の値によって異なる。
//		-1		終端のヌル文字も含めて変換する。
//		正の値	指定された文字数分だけ変換する。
//----------------------------------------------------------------------
bool ConvertWCtoMB(LPSTR		pDst,
					 size_t		zDst,
					 size_t*		pzConverted,
					 LPCWSTR	pSrc,
					 int	iSrc,
					 UINT		uiCodePage)
{
	int	iDst, iRet;
	
	if (pDst == NULL || zDst < 1 || pzConverted == NULL || pSrc == NULL)
	{
		return false;
	}
	*pzConverted	= 0;
	iDst	= (int)(zDst < INT_MAX ? zDst : INT_MAX);

	//	変換元文字列の長さに 0 を指定すると、関数は失敗する。
	if (iSrc < 1)
	{
		iSrc = -1;
	}

	iRet	= WideCharToMultiByte(
		uiCodePage,	// コードページ
		0,			// 処理速度とマッピング方法を決定するフラグ
		pSrc,		// ワイド文字列のアドレス
		iSrc,		// ワイド文字列の文字数
		pDst,		// 新しい文字列を受け取るバッファのアドレス
		iDst,		// 新しい文字列を受け取るバッファのサイズ
		NULL,		// マップできない文字の既定値のアドレス
		NULL		// 既定の文字を使ったときにセットするフラグのアドレス
		);
	if (iSrc > 0)
	{
		*(pDst + iRet) = '\0';
	}

	if (iRet > 0)
	{
		*pzConverted	= (size_t)iRet;
		return true;
	}
	else
	{
		*pzConverted	= 0;
		return false;
	}
}

/*
//----------------------------------------------------------------------
//	ConvertWCtoMBMa	:	必要なバッファを確保し、変換する。変換後の文字数を返す。
//
//	終端にはヌル文字を追加する。
//	バッファの解放は呼び出し側で行うこと（delete[] を使う）。
//	変換後の文字数を返す。
//----------------------------------------------------------------------
bool ConvertWCtoMBMa(LPSTR*	ppDst,
					 size_t*	pzDst,
					 LPCWSTR	pSrc,
					 int	iSrc,
					 UINT	uiCodePage)
{
	size_t	zDst;
	int		iBuf;

	if (ppDst == NULL || pzDst == NULL || pSrc == NULL)
	{
		return false;
	}
	*ppDst	= NULL;
	*pzDst	= 0;

	//	必要なバッファサイズを調べる。
	if (!GetSizeWCtoMB(&zDst, pSrc, iSrc, uiCodePage))
	{
		THROWPE_RUNTIME_ERROR("ConvertMBtoWCMa (2)");
		return false;
	}
	if (zDst > INT_MAX - 1)
	{
		return false;
	}

	//	必要なバッファを確保し、変換する。
	if (iSrc > 0)
	{
		iBuf = (int)zDst + 1;
	}
	else
	{
		iBuf = (int)zDst;
	}

	try
	{
		*ppDst = new char[iBuf];
	}
	CATCH_AND_RETURN_BAD_ALLOC(false, "");

	if (!ConvertWCtoMB(*ppDst, (size_t)iBuf, pzDst, pSrc, iSrc, uiCodePage))
	{
		goto ERROR_HANDLING;
	}

	return true;

ERROR_HANDLING:
	delete[]	*ppDst;
	*ppDst	= NULL;
	return false;
}
*/
/*
//======================================================================
//	文字列の変換: マルチバイト文字列間で変換する。
//======================================================================
//----------------------------------------------------------------------
//	ConvertMtoMMa: バッファを確保し、変換する。
//
//	変換対象の文字列は、ヌル終了文字列でなければならない。
//	バッファの解放は呼び出し側で行うこと（delete[] を使う）。
//	変換後の文字数を返す。
//	エラーが起こった場合は負の値を返す。（FAILED() マクロで判定できる。）
//----------------------------------------------------------------------
//	必要なバッファを確保し、変換する。
//	変換対象の文字列は、ヌル終了文字列でなければならない。
//	変換後の文字数を返す。
//	エラーが起こった場合は負の値を返す。（FAILED() マクロで判定できる。）
bool ConvertMBtoMBMa(LPSTR*	ppDst,
					 size_t*	pzDst,
					 LPCSTR		pSrc,
					 int		iSrc,
					 UINT		uCPDst,
					 UINT		uCPSrc)
{
	LPWSTR	pTempW	= NULL;
	size_t	zSrc, zTemp;
	bool	bRet;

	//	コードページが等しい場合。
	if (uCPDst== uCPSrc)
	{
		if (iSrc < 1)
		{
			if (!NS_PLIB::t_StrLen<char>(&zSrc, pSrc))	return false;
		}
		else
		{
			zSrc	= (size_t)iSrc;
		}
		return NS_PLIB::StrCopyMa<char>(ppDst, pzDst, pSrc, zSrc);
	}
	//	コードページが異なる場合。
	else
	{
		if (!ConvertMBtoWCMa(&pTempW, &zTemp, pSrc, iSrc, uCPSrc))	return false;
		if (zTemp > (size_t)(INT_MAX - 1))	return false;

		bRet = ConvertWCtoMBMa(ppDst, pzDst, pTempW, (int)zTemp, uCPDst);
		delete[] pTempW;
		return bRet;
	}

	return false;
}
*/

//======================================================================
//	文字列の変換: std::string と std::wstring の変換
//======================================================================
//----------------------------------------------------------------------
//	ConvertStringToWString
//----------------------------------------------------------------------
bool ConvertStringToWString(std::wstring* pWString, std::string* pString)
{
	LPWSTR	pBuffer	= NULL;
	size_t	zSize;
	bool	bConvertStringToWString	= false;

	if (ConvertMBtoWCMa(&pBuffer, &zSize, pString->c_str(), (int)pString->size(), CP_ACP))
	{
		try
		{
			pWString->assign(pBuffer, zSize);
			bConvertStringToWString	= true;
		}
		catch (std::bad_alloc&)
		{
			MSG_NOT_ENOUGH_MEMORY("");
		}
		catch (...)
		{
		}
	}

	delete[]	pBuffer;
	return bConvertStringToWString;
}

//----------------------------------------------------------------------
//	ConvertWStringToString
//----------------------------------------------------------------------
bool ConvertWStringToString(std::string* pString, std::wstring* pWString)
{
	LPSTR	pBuffer	= NULL;
	size_t	zSize;
	bool	bConvertWStringToString	= false;

	if (ConvertWCtoMBMa(&pBuffer, &zSize, pWString->c_str(), (int)pWString->size(), CP_ACP))
	{
		try
		{
			pString->assign(pBuffer, zSize);
			bConvertWStringToString	= true;
		}
		catch (std::bad_alloc&)
		{
			MSG_NOT_ENOUGH_MEMORY("");
		}
		catch (...)
		{
		}
	}

	delete[]	pBuffer;
	return bConvertWStringToString;
}


//======================================================================
//	ConvertStringToWString, ConvertWStringToString
//
//	std::string と std::wstring の変換
//======================================================================
bool	ConvertStringToWString(std::wstring* pWString, std::string* pString);
bool	ConvertWStringToString(std::string* pString, std::wstring* pWString);



NS_PLIB_END
