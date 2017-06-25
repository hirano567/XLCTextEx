//	XLCTextEx_1.0x	:	XLCTextEx

//	XLCRegEx.h
//
#pragma once
#include <xlcall.h>

//======================================================================
//	補助関数
//======================================================================
template<typename T_CHAR, typename T_XLOPER>
BOOL t_XLCRegEx_IsOptionSet(T_XLOPER* pxSrc, const T_CHAR* pszOpt)
{
	typedef	const T_CHAR*	T_PCSTR;

	//T_PCSTR	pSrc;
	size_t	zSrc, zOpt;
	T_PCSTR	pc, pe;

	if (pxSrc == NULL || pszOpt == NULL)	return FALSE;
	if (pxSrc->xltype != xltypeStr || pxSrc->val.str == NULL || *(pxSrc->val.str) == 0) return FALSE;

	zSrc	= XLL::GetStringSize(pxSrc->val.str);
	if (!PLib::t_StrLen<T_CHAR>(&zOpt, pszOpt))	return FALSE;
	pc	= pxSrc->val.str + 1;
	pe	= pc + zSrc - zOpt + 1;
	if (pc >= pe)	return FALSE;

	for (; pc < pe; ++pc)
	{
		//	- 以降は取り消しの指定なので FALSE を返す。
		if (PLib::t_CompareString<T_CHAR>(LOCALE_USER_DEFAULT, NORM_IGNOREWIDTH,
			pc, zOpt, t_Str<T_CHAR>(TEXTAW("-")), zOpt) == CSTR_EQUAL)
		{
			return FALSE;
		}
		if (PLib::t_CompareString<T_CHAR>(LOCALE_USER_DEFAULT, NORM_IGNOREWIDTH,
			pc, zOpt, pszOpt, zOpt) == CSTR_EQUAL)
		{
			return TRUE;
		}
	}
	return FALSE;
}

//----------------------------------------------------------------------
//
//----------------------------------------------------------------------
PLib::PCRegEx* XLCRegExGetPCRegEx(PLib::PCRegEx*	pciRegExTemp,
								  XLOPER12*			pxPattern,
								  XLOPER12*			pxOptions);

PLib::PCRegExReplacement*
XLCRegExGetPCRegExReplacement(PLib::PCRegExReplacement*	pciReplacementTemp,
							  XLOPER12*					pxReplacement,
							  XLOPER12*					pxOptions);

bool	XLCRegExGetPCRegExText(PLib::PCRegExText* pciText, XLOPER12* pxText, XLOPER12* pxOptions);


//======================================================================
//	エクスポートする関数
//======================================================================
//----------------------------------------------------------------------
//	Excel4
//----------------------------------------------------------------------
XLOPER* WINAPI	XLCRegExCreate4(XLOPER*	pxIndex,
								XLOPER*	pxPattern,
								XLOPER*	pxOptions);
XLOPER* WINAPI	XLCRegExDelete4(XLOPER* pxIndex);
XLOPER* WINAPI	XLCRegExClear4(XLOPER* pxOption);

XLOPER* WINAPI	XLCRegExCreateReplacement4(XLOPER*	pxIndex,
										   XLOPER*	pxReplacement,
										   XLOPER*	pxOptions);
XLOPER* WINAPI	XLCRegExDeleteReplacement4(XLOPER* pxIndex);
XLOPER* WINAPI	XLCRegExClearReplacement4(XLOPER* pxOption);

XLOPER* WINAPI	XLCRegExMatch4(XLOPER*	pxPat,
							   XLOPER*	pxTxt,
							   XLOPER*	pxOpt);
XLOPER* WINAPI	XLCRegExFormat4(XLOPER*	pxPat,
								XLOPER*	pxRep,
								XLOPER*	pxTxt,
								XLOPER*	pxOpt);
XLOPER* WINAPI	XLCRegExFormatIf4(XLOPER*	pxPat,
								  XLOPER*	pxRepT,
								  XLOPER*	pxRepF,
								  XLOPER*	pxTxt,
								  XLOPER*	pxOpt);
XLOPER* WINAPI	XLCRegExReplace4(XLOPER*	pxPat,
								 XLOPER*	pxRep,
								 XLOPER*	pxTxt,
								 XLOPER*	pxOpt);
XLOPER* WINAPI	XLCRegExValue4(XLOPER*	pxPat,
							   XLOPER*	pxRep,
							   XLOPER*	pxTxt,
							   XLOPER*	pxOpt,
							   XLOPER*	pxAlt);

//----------------------------------------------------------------------
//	Excel12
//----------------------------------------------------------------------
XLOPER12* WINAPI	XLCRegExCreate12(XLOPER12*	pxIndex,
									 XLOPER12*	pxPattern,
									 XLOPER12*	pxOptions);
XLOPER12* WINAPI	XLCRegExDelete12(XLOPER12*	pxIndex);
XLOPER12* WINAPI	XLCRegExClear12(XLOPER12*	pxOption);

XLOPER12* WINAPI	XLCRegExCreateReplacement12(XLOPER12*	pxIndex,
												XLOPER12*	pxReplacement,
												XLOPER12*	pxOptions);
XLOPER12* WINAPI	XLCRegExDeleteReplacement12(XLOPER12*	pxIndex);
XLOPER12* WINAPI	XLCRegExClearReplacement12(XLOPER12*	pxOption);

XLOPER12* WINAPI	XLCRegExMatch12(XLOPER12*	pxPat,
									XLOPER12*	pxTxt,
									XLOPER12*	pxOpt);
XLOPER12* WINAPI	XLCRegExFormat12(XLOPER12*	pxPat,
									 XLOPER12*	pxRep,
									 XLOPER12*	pxTxt,
									 XLOPER12*	pxOpt);
XLOPER12* WINAPI	XLCRegExFormatIf12(XLOPER12*	pxPat,
									   XLOPER12*	pxRepT,
									   XLOPER12*	pxRepF,
									   XLOPER12*	pxTxt,
									   XLOPER12*	pxOpt);
XLOPER12* WINAPI	XLCRegExReplace12(XLOPER12*	pxPat,
									  XLOPER12*	pxRep,
									  XLOPER12*	pxTxt,
									  XLOPER12*	pxOpt);
XLOPER12* WINAPI	XLCRegExValue12(XLOPER12*	pxPat,
									XLOPER12*	pxRep,
									XLOPER12*	pxTxt,
									XLOPER12*	pxOpt,
									XLOPER12*	pxAlt);

