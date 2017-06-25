//	XLCTextEx_1.0x	:	PLibXLL

//	XLLDebug.h
//
#pragma once

NS_XLL_BEGIN

//======================================================================
//	DebugXLPStr
//======================================================================
template<typename T_CHAR>
void DebugXLPStr(std::basic_string<T_CHAR>* pstrDebug, const T_CHAR* pXLStr)
{
	typedef	const T_CHAR*	T_PCSTR;

	size_t	zSize;
	T_PCSTR	pfmt_d	= t_Str<T_CHAR>(TEXTAW("(%d)"));

	if (pstrDebug == NULL || pXLStr == NULL)	return;
	zSize	= GetStringSize<T_CHAR>(pXLStr);
	PLib::AppendNumToString<T_CHAR, int>(pstrDebug, pfmt_d, (int)zSize);
	if (zSize > 0)
	{
		pstrDebug->append(pXLStr + 1, zSize);
	}
}


//======================================================================
//	t_DebugXLREF
//======================================================================
template<typename T_CHAR, typename T_XLREF>
void t_DebugXLREF(std::basic_string<T_CHAR>* pDString, T_XLREF* pXLRef,
				  std::basic_string<T_CHAR>* pIndent = NULL)
{
#ifdef PDEBUG

	typedef	const T_CHAR*				T_PCSTR;
	typedef	std::basic_string<T_CHAR>	T_STRING;

	const size_t	zBuf	= 64;
	//T_CHAR			Buf[zBuf];
	T_STRING		strIndent;
	T_PCSTR			pFmt_d	= t_Str<T_CHAR>(TEXTAW("%d"));

	if (pIndent == NULL)
	{
		strIndent.clear();
	}
	else
	{
		strIndent.append(pIndent->c_str());
	}

	pDString->append(t_Str<T_CHAR>("[XLREF] (", L"[XLREF12] ("));
	PLib::AppendNumToString<T_CHAR, int>(pDString, pFmt_d, (int)(pXLRef->rwFirst));
	//if (PLib::NumToStr<T_CHAR>(Buf, zBuf, (int)(pXLRef->rwFirst)))		pDString->append(Buf);
	pDString->append(t_Str<T_CHAR>(TEXTAW(", ")));
	PLib::AppendNumToString<T_CHAR, int>(pDString, pFmt_d, (int)(pXLRef->colFirst));
	//if (PLib::NumToStr<T_CHAR>(Buf, zBuf, (int)(pXLRef->colFirst)))	pDString->append(Buf);
	pDString->append(t_Str<T_CHAR>(TEXTAW(") - (")));
	PLib::AppendNumToString<T_CHAR, int>(pDString, pFmt_d, (int)(pXLRef->rwLast));
	//if (PLib::NumToStr<T_CHAR>(Buf, zBuf, (int)(pXLRef->rwLast)))		pDString->append(Buf);
	pDString->append(t_Str<T_CHAR>(TEXTAW(", ")));
	PLib::AppendNumToString<T_CHAR, int>(pDString, pFmt_d, (int)(pXLRef->colLast));
	//if (PLib::NumToStr<T_CHAR>(Buf, zBuf, (int)(pXLRef->colLast)))		pDString->append(Buf);
	pDString->append(t_Str<T_CHAR>(TEXTAW(")\r\n")));

#endif
}

//======================================================================
//	t_DebugXLMREF
//======================================================================
template<typename T_CHAR, typename T_XLMREF, typename T_XLREF>
void t_DebugXLMREF(std::basic_string<T_CHAR>* pDString, T_XLMREF* pXLMRef,
				   std::basic_string<T_CHAR>* pIndent = NULL)
{
#ifdef PDEBUG

	typedef	const T_CHAR*				T_PCSTR;
	typedef	std::basic_string<T_CHAR>	T_STRING;

	const size_t	zBuf	= 64;
	//T_CHAR			Buf[zBuf];
	T_STRING		strIndent;
	int				i, iCount;
	T_PCSTR			pFmt_d	= t_Str<T_CHAR>(TEXTAW("%d"));

	if (pIndent == NULL)
	{
		strIndent.clear();
	}
	else
	{
		strIndent.append(pIndent->c_str());
	}

	iCount	= (int)(pXLMRef->count);

	pDString->append(strIndent);
	pDString->append(t_Str<T_CHAR>(TEXTAW("count: ")));
	PLib::AppendNumToString<T_CHAR, int>(pDString, pFmt_d, iCount);
	pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
	//if (PLib::NumToStr<T_CHAR, int>(Buf, zBuf, iCount))
	//{
	//	pDString->append(Buf);
	//	pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
	//}

	for (i = 0; i < iCount; ++i)
	{
		t_DebugXLREF<T_CHAR, T_XLREF>(pDString, &(pXLMRef->reftbl[i]));
	}

#endif
}

//======================================================================
//	t_DebugXLOPER
//======================================================================
template<typename T_CHAR, typename T_XLOPER, typename T_XLMREF, typename T_XLREF>
void t_DebugXLOPER(std::basic_string<T_CHAR>* pDString, T_XLOPER* pXLOper,
				   std::basic_string<T_CHAR>* pIndent = NULL)
{
#ifdef PDEBUG

	typedef	const T_CHAR*				T_PCSTR;
	typedef	std::basic_string<T_CHAR>	T_STRING;

	const size_t	zBuf		= 64;
	//T_CHAR			Buf[zBuf];
	size_t			zSize;
	T_XLOPER*		pcx;
	int				iType		= 0;
	BOOL			bXLFree		= FALSE;
	BOOL			bDLLFree	= FALSE;

	int				i, j;
	T_PCSTR			pFmt_d	= t_Str<T_CHAR>(TEXTAW("%d"));
	T_PCSTR			pFmt_f	= t_Str<T_CHAR>(TEXTAW("%f"));
	T_STRING		strIndent;
	//int				iRet;

	if (pIndent == NULL)
	{
		strIndent.clear();
	}
	else
	{
		strIndent.append(pIndent->c_str());
	}

	iType		= pXLOper->xltype & 0xFFF;
	bXLFree		= ((pXLOper->xltype & xlbitXLFree) != 0);
	bDLLFree	= ((pXLOper->xltype & xlbitDLLFree) != 0);

	switch (iType)
	{
	case	xltypeNum:
		pDString->append(t_Str<T_CHAR>(TEXTAW("[xltypeNum]\r\n")));
		PLib::AppendNumToString<T_CHAR, double>(pDString, pFmt_f, pXLOper->val.num);
		pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
		//if (PLib::NumToStr<T_CHAR, double>(Buf, zBuf, pXLOper->val.num))
		//{
		//	pDString->append(Buf);
		//	pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
		//}
		break;

	case	xltypeStr:
		pDString->append(t_Str<T_CHAR>(TEXTAW("[xltypeStr]\r\n")));
		if (pXLOper->val.str != NULL)
		{
			zSize	= XLL::GetXLOPER_StrSize<T_XLOPER>(pXLOper);
			PLib::AppendNumToString<T_CHAR, int>(pDString, pFmt_d, (int)zSize);
			pDString->append(t_Str<T_CHAR>(TEXTAW(":")));
			//if (PLib::NumToStr<T_CHAR, int>(Buf, zBuf, (int)zSize))
			//{
			//	pDString->append(Buf);
			//	pDString->append(t_Str<T_CHAR>(TEXTAW(":")));
			//}
			if (zSize > 0)
			{
				pDString->append(pXLOper->val.str + 1, zSize);
			}
			pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
		}
		break;

	case	xltypeBool:
		pDString->append(t_Str<T_CHAR>(TEXTAW("[xltypeBool]\r\n")));
		if (pXLOper->val.xbool == TRUE)
		{
			pDString->append(t_Str<T_CHAR>(TEXTAW("TRUE\r\n")));
		}
		else
		{
			pDString->append(t_Str<T_CHAR>(TEXTAW("FALSE\r\n")));
		}
		break;

	case	xltypeRef:
		pDString->append(t_Str<T_CHAR>(TEXTAW("[xltypeRef]\r\n")));
		pDString->append(t_Str<T_CHAR>(TEXTAW("idSheet: ")));
		PLib::AppendNumToString<T_CHAR, int>(pDString, pFmt_d, (int)(pXLOper->val.mref.idSheet));
		pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
		//if (PLib::NumToStr<T_CHAR, int>(Buf, zBuf, (int)(pXLOper->val.mref.idSheet)))
		//{
		//	pDString->append(Buf);
		//	pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
		//}
		t_DebugXLMREF<T_CHAR, T_XLMREF, T_XLREF>(pDString, pXLOper->val.mref.lpmref);
		break;

	case	xltypeErr:
		pDString->append(t_Str<T_CHAR>(TEXTAW("[xltypeErr]\r\n")));
		switch (pXLOper->val.err)
		{
		case xlerrNull:
			pDString->append(t_Str<T_CHAR>(TEXTAW("xlerrNull\r\n")));
			break;

		case xlerrDiv0:
			pDString->append(t_Str<T_CHAR>(TEXTAW("xlerrDiv0\r\n")));
			break;

		case xlerrValue:
			pDString->append(t_Str<T_CHAR>(TEXTAW("xlerrValue\r\n")));
			break;

		case xlerrRef:
			pDString->append(t_Str<T_CHAR>(TEXTAW("xlerrRef\r\n")));
			break;

		case xlerrName:
			pDString->append(t_Str<T_CHAR>(TEXTAW("xlerrName\r\n")));
			break;

		case xlerrNum:
			pDString->append(t_Str<T_CHAR>(TEXTAW("xlerrNum\r\n")));
			break;

		case xlerrNA:
			pDString->append(t_Str<T_CHAR>(TEXTAW("xlerrNA\r\n")));
			break;

		default:
			break;
		}
		break;

	case	xltypeFlow:
		pDString->append(t_Str<T_CHAR>(TEXTAW("[xltypeFlow]\r\n")));
		break;

	case	xltypeMulti:
		pDString->append(t_Str<T_CHAR>(TEXTAW("[xltypeMulti]\r\n")));
		pDString->append(t_Str<T_CHAR>(TEXTAW("rows   : ")));
		PLib::AppendNumToString<T_CHAR, int>(pDString, pFmt_d, (int)(pXLOper->val.array.rows));
		pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
		//if (PLib::NumToStr<T_CHAR, int>(Buf, zBuf, (int)(pXLOper->val.array.rows)))
		//{
		//	pDString->append(Buf);
		//	pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
		//}
		pDString->append(t_Str<T_CHAR>(TEXTAW("columns: ")));
		PLib::AppendNumToString<T_CHAR, int>(pDString, pFmt_d, (int)(pXLOper->val.array.columns));
		pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
		//if (PLib::NumToStr<T_CHAR, int>(Buf, zBuf, (int)(pXLOper->val.array.columns)))
		//{
		//	pDString->append(Buf);
		//	pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
		//}

		pcx	= pXLOper->val.array.lparray;
		for (i = 0; i < pXLOper->val.array.rows; ++i)
		{
			for (j = 0; j < pXLOper->val.array.columns; ++j)
			{
				pDString->append(t_Str<T_CHAR>(TEXTAW("(")));
				PLib::AppendNumToString<T_CHAR, int>(pDString, pFmt_d, (int)i);
				//if (PLib::NumToStr<T_CHAR, int>(Buf, zBuf, (int)i))
				//{
				//	pDString->append(Buf);
				//}
				pDString->append(t_Str<T_CHAR>(TEXTAW(", ")));
				PLib::AppendNumToString<T_CHAR, int>(pDString, pFmt_d, (int)j);
				//if (PLib::NumToStr<T_CHAR, int>(Buf, zBuf, (int)j))
				//{
				//	pDString->append(Buf);
				//}
				pDString->append(t_Str<T_CHAR>(TEXTAW(")\r\n")));

				t_DebugXLOPER<T_CHAR, T_XLOPER, T_XLMREF, T_XLREF>(pDString, pcx);
				++pcx;
			}
		}
		break;

	case	xltypeMissing:
		pDString->append(t_Str<T_CHAR>(TEXTAW("[xltypeMissing]\r\n")));
		break;

	case	xltypeNil:
		pDString->append(t_Str<T_CHAR>(TEXTAW("[xltypeNil]\r\n")));
		break;

	case	xltypeSRef:
		pDString->append(t_Str<T_CHAR>(TEXTAW("[xltypeSRef]\r\n")));
		pDString->append(t_Str<T_CHAR>(TEXTAW("    count: ")));
		PLib::AppendNumToString<T_CHAR, int>(pDString, pFmt_d, (int)(pXLOper->val.sref.count));
		pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
		//if (PLib::NumToStr<T_CHAR, int>(Buf, zBuf, (int)(pXLOper->val.sref.count)))
		//{
		//	pDString->append(Buf);
		//	pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
		//}
		t_DebugXLREF<T_CHAR, T_XLREF>(pDString, &(pXLOper->val.sref.ref));
		break;

	case	xltypeInt:
		pDString->append(t_Str<T_CHAR>(TEXTAW("[xltypeInt]\r\n")));
		PLib::AppendNumToString<T_CHAR, int>(pDString, pFmt_d, (int)(pXLOper->val.w));
		pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
		//if (PLib::NumToStr<T_CHAR, int>(Buf, zBuf, (int)(pXLOper->val.w)))
		//{
		//	pDString->append(Buf);
		//	pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
		//}
		break;

	default:
		pDString->append(t_Str<T_CHAR>(TEXTAW("[unknown]\r\n")));
		break;
	}

	if (bXLFree)
	{
		pDString->append(t_Str<T_CHAR>(TEXTAW("(xlbitXLFree)\r\n")));
	}
	if (bDLLFree)
	{
		pDString->append(t_Str<T_CHAR>(TEXTAW("(xlbitDLLFree)\r\n")));
	}

#endif
}


//======================================================================
//	DebugXLOPER
//======================================================================
template<typename T_CHAR, typename T_XLOPER>
inline void DebugXLOPER(std::basic_string<T_CHAR>* pDString, T_XLOPER* pXLOper)
{
#ifdef	PDEBUG
#endif
}
template<>
inline void DebugXLOPER<char, XLOPER>(std::basic_string<char>* pDString, XLOPER* pXLOper)
{
#ifdef	PDEBUG
	return t_DebugXLOPER<char, XLOPER, XLMREF, XLREF>(pDString, pXLOper);
#endif
}
template<>
inline void DebugXLOPER<wchar_t, XLOPER12>(std::basic_string<wchar_t>* pDString, XLOPER12* pXLOper)
{
#ifdef	PDEBUG
	return t_DebugXLOPER<wchar_t, XLOPER12, XLMREF12, XLREF12>(pDString, pXLOper);
#endif
}


//======================================================================
//	DebugXLOPERArray
//======================================================================
template<typename T_CHAR, typename T_XLOPER, typename T_XLMREF, typename T_XLREF>
void t_DebugXLOPERArray(std::basic_string<T_CHAR>* pDString, int iNum, T_XLOPER* pXLOper,
						 std::basic_string<T_CHAR>* pIndent = NULL)
{
#ifdef PDEBUG

	T_XLOPER*	pxop;
	int			i;

	if (pDString == NULL || pXLOper == NULL)	return;

	for (i = 0, pxop = pXLOper; i < iNum; ++i, ++pxop)
	{
		t_DebugXLOPER<T_CHAR, T_XLOPER, T_XLMREF, T_XLREF>(
			pDString, pxop, pIndent);
		pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
	}

#endif
}

template<typename T_CHAR, typename T_XLOPER>
inline void DebugXLOPERArray(std::basic_string<T_CHAR>* pDString, int iNum, T_XLOPER* pXLOper)
{
#ifdef	PDEBUG
#endif
}
template<>
inline void DebugXLOPERArray<char, XLOPER>(std::basic_string<char>* pDString,
										   int iNum, XLOPER* pXLOper)
{
#ifdef	PDEBUG
	return t_DebugXLOPERArray<char, XLOPER, XLMREF, XLREF>(pDString, iNum, pXLOper);
#endif
}
template<>
inline void DebugXLOPERArray<wchar_t, XLOPER12>(std::basic_string<wchar_t>* pDString,
												int iNum, XLOPER12* pXLOper)
{
#ifdef	PDEBUG
	return t_DebugXLOPERArray<wchar_t, XLOPER12, XLMREF12, XLREF12>(pDString, iNum, pXLOper);
#endif
}


//======================================================================
//	DebugPXLOPERArray
//======================================================================
template<typename T_CHAR, typename T_XLOPER, typename T_XLMREF, typename T_XLREF>
void t_DebugPXLOPERArray(std::basic_string<T_CHAR>* pDString, int iNum, T_XLOPER** ppXLOper,
						 std::basic_string<T_CHAR>* pIndent = NULL)
{
#ifdef PDEBUG

	T_XLOPER**	ppxop;
	T_XLOPER*	pxop;
	int			i;

	if (pDString == NULL || ppXLOper == NULL)	return;

	for (i = 0, ppxop = ppXLOper; i < iNum; ++i, ++ppxop)
	{
		pxop	= *ppxop;
		t_DebugXLOPER<T_CHAR, T_XLOPER, T_XLMREF, T_XLREF>(
			pDString, pxop, pIndent);
		pDString->append(t_Str<T_CHAR>(TEXTAW("\r\n")));
	}

#endif
}

template<typename T_CHAR, typename T_XLOPER>
inline void DebugPXLOPERArray(std::basic_string<T_CHAR>* pDString, int iNum, T_XLOPER** ppXLOper)
{
#ifdef	PDEBUG
#endif
}
template<>
inline void DebugPXLOPERArray<char, XLOPER>(std::basic_string<char>* pDString,
											int iNum, XLOPER** ppXLOper)
{
#ifdef	PDEBUG
	return t_DebugPXLOPERArray<char, XLOPER, XLMREF, XLREF>(pDString, iNum, ppXLOper);
#endif
}
template<>
inline void DebugPXLOPERArray<wchar_t, XLOPER12>(std::basic_string<wchar_t>* pDString,
												 int iNum, XLOPER12** ppXLOper)
{
#ifdef	PDEBUG
	return t_DebugPXLOPERArray<wchar_t, XLOPER12, XLMREF12, XLREF12>(pDString, iNum, ppXLOper);
#endif
}

NS_XLL_END
