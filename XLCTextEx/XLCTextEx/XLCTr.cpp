//	XLCTextEx_1.0x	:	XLCTextEx

// XLCTr.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
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

	static T_CHAR_U	NullStr[1]	= { (T_CHAR_U)0 };	//	空文字列用のダミー

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
	//	引数をチェックする。
	//	入力中に呼び出されることもあるので、Err ではなく Nil を返す。
	//------------------------------------------------------------
	if (!PLib::IsPageReadWrite((LPVOID)pxId)	||
		!PLib::IsPageReadWrite((LPVOID)pxSrc)	||
		!PLib::IsPageReadWrite((LPVOID)pxDst)	||
		!PLib::IsPageReadWrite((LPVOID)pxOpt))
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, TRUE);
	}

	//------------------------------------------------------------
	//	Excel を Owner とするダイアログが開いている場合、
	//	引数の入力が完了する前に関数を呼び出すことがあるので、まだ処理を行わない。
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, TRUE);
	}

	//------------------------------------------------------------
	//	引数のチェック
	//------------------------------------------------------------
	if (pxId == NULL || pxSrc == NULL || pxDst == NULL)
	{
		XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrValue, TRUE);
		return pxRet12;
	}

	//------------------------------------------------------------
	//	引数の処理	(1)	pxId	割り当てる ID
	//	pxId が NULL ならエラー値を返す。
	//	*pxId が xltypeNum か xltypeInt でならその値を取り出す。
	//	それ以外の場合は FALSE を返す。
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
	//	PCTransChar クラスのインスタンスを作成する。既存の場合はそれを使用する。
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
	//	引数の処理	(2)	pxOpt
	//------------------------------------------------------------
	SetTrOption(pciTrChar, &bQuoted, pxOpt);

	//------------------------------------------------------------
	//	引数の処理	(3)	pxSrc
	//------------------------------------------------------------
	if (!XLL::XLGetString<T_CHAR_U, XLOPER12>(&pSrcB, &pSrcE, pxSrc, pszNull, bQuoted))
		goto ERROR_HANDLING;

	//------------------------------------------------------------
	//	引数の処理	(4)	pxDst
	//------------------------------------------------------------
	if (!XLL::XLGetString<T_CHAR_U, XLOPER12>(&pDstB, &pDstE, pxDst, pszNull, bQuoted))
		goto ERROR_HANDLING;

	//------------------------------------------------------------
	//	登録する。
	//------------------------------------------------------------
	if (!pciTrChar->SetTrans(pSrcB, pSrcE, pDstB, pDstE))	goto ERROR_HANDLING;

	//------------------------------------------------------------
	//	終了。指定された ID を返す。
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
	//	引数が有効かチェックする。
	//	入力が完了しないうちに呼び出されることもあるので、Err ではなく Nil を返す。
	//------------------------------------------------------------
	if (!PLib::IsPageReadWrite((LPVOID)pxId4)	||
		!PLib::IsPageReadWrite((LPVOID)pxSrc4)	||
		!PLib::IsPageReadWrite((LPVOID)pxDst4)	||
		!PLib::IsPageReadWrite((LPVOID)pxOpt4))
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, TRUE);
	}

	//------------------------------------------------------------
	//	Excel を Owner とするダイアログが開いている場合、
	//	引数の入力が完了する前に関数を呼び出すことがあるので、まだ処理を行わない。
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, TRUE);
	}

	//------------------------------------------------------------
	//	変数の値を設定する。
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
	//	パターンを登録する。
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
	//	終了処理
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
	//	引数をチェックする。
	//	入力中に呼び出されることもあるので、Err ではなく Nil を返す。
	//------------------------------------------------------------
	if (!PLib::IsPageReadWrite((LPVOID)pxId))
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, TRUE);
	}

	//------------------------------------------------------------
	//	Excel を Owner とするダイアログが開いている場合、
	//	引数の入力が完了する前に関数を呼び出すことがあるので、まだ処理を行わない。
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, TRUE);
	}

	//------------------------------------------------------------
	//	引数をチェックして、番号を取り出す。
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
	//	インスタンスを削除する。
	//	Delete() は存在していなかった場合は FALSE を返すが、この関数からは TRUE を返す。
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
	//	引数をチェックする。
	//	入力中に呼び出されることもあるので、Err ではなく Nil を返す。
	//------------------------------------------------------------
	if (!PLib::IsPageReadWrite((LPVOID)pxId4))
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, TRUE);
	}

	//------------------------------------------------------------
	//	Excel を Owner とするダイアログが開いている場合、
	//	引数の入力が完了する前に関数を呼び出すことがあるので、まだ処理を行わない。
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, TRUE);
	}

	//------------------------------------------------------------
	//	変数の値を設定する。
	//------------------------------------------------------------
	xId12.xltype	= xltypeNil;
	if (!ciConverter.Convert<XLOPER12, XLOPER>(&xId12, pxId4))
	{
		XLL::SetXLOPER_Err<XLOPER>(pxRet4, xlerrNull, TRUE);
		goto END_PROCESSING;
	}

	//------------------------------------------------------------
	//	パターンを削除し、返り値を設定する。
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
	//	終了処理
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
	//	Excel を Owner とするダイアログが開いている場合、
	//	引数の入力が完了する前に関数を呼び出すことがあるので、まだ処理を行わない。
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, TRUE);
	}

	//------------------------------------------------------------
	//	xltypeNum、xltypeInt の場合登録 ID で指定されたとみなす。
	//	pxArg2 に対象テキストが格納されているとして処理を行う。
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
	//	pxArg1 が xltypeStr の場合、文字集合が直接指定されたとみなす。
	//	xltypeNil, xltypeMissing の場合、文字集合なしとして処理を続ける。
	//	pxArg1 が Src、pxArg2 が Dst、pxArg3 が Txt、pxArg4 が Opt となる。
	//------------------------------------------------------------
	else if (	pxArg1->xltype == xltypeStr		||
				pxArg1->xltype == xltypeNil		||
				pxArg1->xltype == xltypeMissing)
	{
		SetTrOption(&ciTrCharTemp, &bQuoted, pxArg4);

		//	XLGetString 関数は、xltypeNil、xltypeMissing の場合、空文字列をセットする。
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
	//	以上に当てはまらない場合はエラーを返す。
	//------------------------------------------------------------
	else
	{
		return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrValue, TRUE);
	}

	//------------------------------------------------------------
	//	文字列を変換して返す。
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
	//	Excel を Owner とするダイアログが開いている場合、
	//	引数の入力が完了する前に関数を呼び出すことがあるので、まだ処理を行わない。
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, TRUE);
	}

	//------------------------------------------------------------
	//	変数の値を設定する。
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
	//	実際の処理は XLCRegExTextProcessing_exec が行う。
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
	//	終了処理
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
	//	戻り値 pxRet12 を作成する。
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
	//	Excel を Owner とするダイアログが開いている場合、
	//	引数の入力が完了する前に関数を呼び出すことがあるので、まだ処理を行わない。
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER12>(pxRet12, TRUE);
	}

	//------------------------------------------------------------
	//	q オプションを調べ、対象文字列を取り出す。
	//------------------------------------------------------------
	bQuoted	= XLL::XLIsOptionSet<T_CHAR_U, XLOPER12>(pxOpt, TQU("q"));
	if (!XLL::XLGetString<T_CHAR_U, XLOPER12>(&pStrB, &pStrE, pxStr, pszNull, bQuoted))
	{
		return XLL::SetXLOPER_Err<XLOPER12>(pxRet12, xlerrValue, TRUE);
	}

	//------------------------------------------------------------
	//	文字列を変換して返す。
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
	//	Excel を Owner とするダイアログが開いている場合、
	//	引数の入力が完了する前に関数を呼び出すことがあるので、まだ処理を行わない。
	//------------------------------------------------------------
	if (XLL::CalledFromExcelDialog())
	{
		return XLL::SetXLOPER_Nil<XLOPER>(pxRet4, TRUE);
	}

	//------------------------------------------------------------
	//	変数の値を設定する。
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
	//	実際の処理は PresetTranslate12 が行う。
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
	//	終了処理
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

