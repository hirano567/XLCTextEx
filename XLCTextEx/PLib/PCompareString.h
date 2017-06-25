//	XLCTextEx_1.0x	:	PLib

//	PLib	:	PCompareString.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	t_CompareString
//
//	CompareString 系関数のテンプレート
//======================================================================
//----------------------------------------------------------------------
//	CompareString 関係のユーティリティ
//----------------------------------------------------------------------
#define	IS_CSFLAG_LINGUISTIC_IGNORECASE_SET(f)		(((f) & LINGUISTIC_IGNORECASE) != 0)
#define	IS_CSFLAG_LINGUISTIC_IGNOREDIACRITIC_SET(f)	(((f) & LINGUISTIC_IGNOREDIACRITIC) != 0)
#define	IS_CSFLAG_NORM_IGNORECASE_SET(f)			(((f) & NORM_IGNORECASE) != 0)
#define	IS_CSFLAG_NORM_IGNOREKANATYPE_SET(f)		(((f) & NORM_IGNOREKANATYPE) != 0)
#define	IS_CSFLAG_NORM_IGNORENONSPACE_SET(f)		(((f) & NORM_IGNORENONSPACE) != 0)
#define	IS_CSFLAG_NORM_IGNORESYMBOLS_SET(f)			(((f) & NORM_IGNORESYMBOLS) != 0)
#define	IS_CSFLAG_NORM_IGNOREWIDTH_SET(f)			(((f) & NORM_IGNOREWIDTH) != 0)
#define	IS_CSFLAG_NORM_LINGUISTIC_CASING_SET(f)		(((f) & NORM_LINGUISTIC_CASING) != 0)
#define	IS_CSFLAG_SORT_DIGITSASNUMBERS_SET(f)		(((f) & SORT_DIGITSASNUMBERS) != 0)
#define	IS_CSFLAG_SORT_STRINGSORT_SET(f)			(((f) & SORT_STRINGSORT) != 0)

#define	CSFLAG_IGNORECASE	NORM_IGNORECASE

#define	IS_CSFLAG_IGNORECASE(f)			(((f) & CSFLAG_IGNORECASE) != 0)
#define	IS_CSFLAG_IGNORECASE_ONLY(f)	(((f) | CSFLAG_IGNORECASE) == CSFLAG_IGNORECASE)

//----------------------------------------------------------------------
//	t_CompareString	(1)
//----------------------------------------------------------------------
template<typename T_CHAR>
inline int t_CompareString(LCID				Locale,
						   DWORD			dwCmpFlags,
						   const T_CHAR*	pString1,
						   int				cchCount1,
						   const T_CHAR*	pString2,
						   int				cchCount2)
{
	THROW_LOGIC_ERROR("t_CompareString");
	return 0;
}
template<>
inline int t_CompareString<char>(LCID	Locale,
								 DWORD	dwCmpFlags,
								 LPCSTR	pString1,
								 int	cchCount1,
								 LPCSTR	pString2,
								 int	cchCount2)
{
	return CompareStringA(Locale, dwCmpFlags, pString1, cchCount1, pString2, cchCount2);
}
template<>
inline int t_CompareString<wchar_t>(LCID	Locale,
									DWORD	dwCmpFlags,
									LPCWSTR	pString1,
									int		cchCount1,
									LPCWSTR	pString2,
									int		cchCount2)
{
	return CompareStringW(Locale, dwCmpFlags, pString1, cchCount1, pString2, cchCount2);
}

//----------------------------------------------------------------------
//	t_CompareString	(2)	NULL 終了文字列用簡略版
//----------------------------------------------------------------------
template<typename T_CHAR>
inline int t_CompareString(const T_CHAR*	pString1,
						   const T_CHAR*	pString2,
						   DWORD			dwCmpFlags	= 0,
						   LCID				Locale		= LOCALE_USER_DEFAULT)
{
	THROW_LOGIC_ERROR("t_CompareString");
	return 0;
}
template<>
inline int t_CompareString<char>(LPCSTR	pString1,
								 LPCSTR	pString2,
								 DWORD	dwCmpFlags,
								 LCID	Locale)
{
	return CompareStringA(Locale, dwCmpFlags, pString1, -1, pString2, -1);
}
template<>
inline int t_CompareString<wchar_t>(LPCWSTR	pString1,
									LPCWSTR	pString2,
									DWORD	dwCmpFlags,
									LCID	Locale)
{
	return CompareStringW(Locale, dwCmpFlags, pString1, -1, pString2, -1);
}

//----------------------------------------------------------------------
//	フラグ処理用のマクロ
//----------------------------------------------------------------------

//	各フラグの状況

#define	COMPARESTRING_IS_LINGUISTIC_IGNORECASE(f)		(((f) & LINGUISTIC_IGNORECASE) != 0)
#define	COMPARESTRING_IS_LINGUISTIC_IGNOREDIACRITIC(f)	(((f) & LINGUISTIC_IGNOREDIACRITIC) != 0)
#define	COMPARESTRING_IS_NORM_IGNORECASE(f)				(((f) & NORM_IGNORECASE) != 0)
#define	COMPARESTRING_IS_NORM_IGNOREKANATYPE(f)			(((f) & NORM_IGNOREKANATYPE) != 0)
#define	COMPARESTRING_IS_NORM_IGNORENONSPACE(f)			(((f) & NORM_IGNORENONSPACE) != 0)
#define	COMPARESTRING_IS_NORM_IGNORESYMBOLS(f)			(((f) & NORM_IGNORESYMBOLS) != 0)
#define	COMPARESTRING_IS_NORM_IGNOREWIDTH(f)			(((f) & NORM_IGNOREWIDTH) != 0)
#define	COMPARESTRING_IS_NORM_LINGUISTIC_CASING(f)		(((f) & NORM_LINGUISTIC_CASING) != 0)
//#define	COMPARESTRING_IS_SORT_DIGITSASNUMBERS(f)		(((f) & SORT_DIGITSASNUMBERS) != 0)
#define	COMPARESTRING_IS_SORT_STRINGSORT(f)				(((f) & SORT_STRINGSORT) != 0)

//	各フラグを解除

#define	COMPARESTRING_UNSET_LINGUISTIC_IGNORECASE(f)		((f) &= ~LINGUISTIC_IGNORECASE)
#define	COMPARESTRING_UNSET_LINGUISTIC_IGNOREDIACRITIC(f)	((f) &= ~LINGUISTIC_IGNOREDIACRITIC)
#define	COMPARESTRING_UNSET_NORM_IGNORECASE(f)				((f) &= ~NORM_IGNORECASE)
#define	COMPARESTRING_UNSET_NORM_IGNOREKANATYPE(f)			((f) &= ~NORM_IGNOREKANATYPE)
#define	COMPARESTRING_UNSET_NORM_IGNORENONSPACE(f)			((f) &= ~NORM_IGNORENONSPACE)
#define	COMPARESTRING_UNSET_NORM_IGNORESYMBOLS(f)			((f) &= ~NORM_IGNORESYMBOLS)
#define	COMPARESTRING_UNSET_NORM_IGNOREWIDTH(f)				((f) &= ~NORM_IGNOREWIDTH)
#define	COMPARESTRING_UNSET_NORM_LINGUISTIC_CASING(f)		((f) &= ~NORM_LINGUISTIC_CASING)
//#define	COMPARESTRING_UNSET_SORT_DIGITSASNUMBERS(f)			((f) &= ~SORT_DIGITSASNUMBERS)
#define	COMPARESTRING_UNSET_SORT_STRINGSORT(f)				((f) &= ~SORT_STRINGSORT)

//	各フラグを設定

#define	COMPARESTRING_SET_LINGUISTIC_IGNORECASE(f)	\
	COMPARESTRING_UNSET_NORM_IGNORECASE(f); ((f) |= LINGUISTIC_IGNORECASE)
#define	COMPARESTRING_SET_LINGUISTIC_IGNOREDIACRITIC(f)	\
	COMPARESTRING_UNSET_NORM_IGNORENONSPACE(f); ((f) |= LINGUISTIC_IGNOREDIACRITIC)
#define	COMPARESTRING_SET_NORM_IGNORECASE(f)	\
	COMPARESTRING_UNSET_LINGUISTIC_IGNORECASE(f); ((f) |= NORM_IGNORECASE)
#define	COMPARESTRING_SET_NORM_IGNOREKANATYPE(f)		((f) |= NORM_IGNOREKANATYPE)
#define	COMPARESTRING_SET_NORM_IGNORENONSPACE(f)	\
	COMPARESTRING_UNSET_LINGUISTIC_IGNOREDIACRITIC(f); ((f) |= NORM_IGNORENONSPACE)
#define	COMPARESTRING_SET_NORM_IGNORESYMBOLS(f)			((f) |= NORM_IGNORESYMBOLS)
#define	COMPARESTRING_SET_NORM_IGNOREWIDTH(f)			((f) |= NORM_IGNOREWIDTH)
#define	COMPARESTRING_SET_NORM_LINGUISTIC_CASING(f)		((f) |= NORM_LINGUISTIC_CASING)
//#define	COMPARESTRING_SET_SORT_DIGITSASNUMBERS(f)	((f) |= SORT_DIGITSASNUMBERS)
#define	COMPARESTRING_SET_SORT_STRINGSORT(f)			((f) |= SORT_STRINGSORT)

//	ignore case 関係

#define	COMPARESTRING_IS_IGNORECASE_VALID(f)	\
	((COMPARESTRING_IS_NORM_IGNORECASE(f) && !COMPARESTRING_IS_LINGUISTIC_IGNORECASE(f))	||	\
	(!COMPARESTRING_IS_NORM_IGNORECASE(f) && COMPARESTRING_IS_LINGUISTIC_IGNORECASE(f)))

#define	COMPARESTRING_IS_IGNORECASE(f)	COMPARESTRING_IS_IGNORECASE_VALID(f)

#define	COMPARESTRING_NOT_IGNORECASE(f)	\
	(!COMPARESTRING_IS_NORM_IGNORECASE(f) && !COMPARESTRING_IS_LINGUISTIC_IGNORECASE(f))

#define	COMPARESTRING_IS_IGNORECASE_INVALID(f)	\
	(COMPARESTRING_IS_NORM_IGNORECASE(f) && COMPARESTRING_IS_LINGUISTIC_IGNORECASE(f))

//	ignore nonspace 関係

#define	COMPARESTRING_IS_IGNORENONSPACE_VALID(f)	\
	((COMPARESTRING_IS_NORM_IGNORENONSPACE(f) && !COMPARESTRING_IS_LINGUISTIC_IGNOREDIACRITIC(f))	||	\
	(!COMPARESTRING_IS_NORM_IGNORENONSPACE(f) && COMPARESTRING_IS_LINGUISTIC_IGNOREDIACRITIC(f)))

#define	COMPARESTRING_IS_IGNORENONSPACE(f)	COMPARESTRING_IS_IGNORENONSPACE_VALID(f)

#define	COMPARESTRING_NOT_IGNORENONSPACE(f)	\
	(!COMPARESTRING_IS_NORM_IGNORENONSPACE(f) && !COMPARESTRING_IS_LINGUISTIC_IGNOREDIACRITIC(f))

#define	COMPARESTRING_IS_IGNORENONSPACE_INVALID(f)	\
	(COMPARESTRING_IS_NORM_IGNORENONSPACE(f) && COMPARESTRING_IS_LINGUISTIC_IGNOREDIACRITIC(f))

//	全体の状況

#define	COMPARESTRING_IS_INVALID_FLAGS(f)	\
	(COMPARESTRING_IS_IGNORECASE_INVALID(f) && COMPARESTRING_IS_IGNORENONSPACE_INVALID(f))

//----------------------------------------------------------------------
//	DebugCompareStringFlags
//----------------------------------------------------------------------
template<typename T_CHAR>
void DebugCompareStringFlags(std::basic_string<T_CHAR>* pstrDebug, DWORD dwFlags)
{
#ifdef	PDEBUG
	typedef	const T_CHAR*	T_PCSTR;
	T_PCSTR	pfmt_s1		= t_Str<T_CHAR>(TEXTAW("\t%s\r\n"));

	T_PCSTR	pszLinguisticIgnoreCase			= t_Str<T_CHAR>(TEXTAW("LINGUISTIC_IGNORECASE"));
	T_PCSTR	pszLinguisticIgnoreDiacritic	= t_Str<T_CHAR>(TEXTAW("LINGUISTIC_IGNOREDIACRITIC"));
	T_PCSTR	pszNormIgnoreCase				= t_Str<T_CHAR>(TEXTAW("NORM_IGNORECASE"));
	T_PCSTR	pszNormIgnoreKanaType			= t_Str<T_CHAR>(TEXTAW("NORM_IGNOREKANATYPE"));
	T_PCSTR	pszNormIgnoreNonSpace			= t_Str<T_CHAR>(TEXTAW("NORM_IGNORENONSPACE"));
	T_PCSTR	pszNormIgnoreSymbols			= t_Str<T_CHAR>(TEXTAW("NORM_IGNORESYMBOLS"));
	T_PCSTR	pszNormIgnoreWidth				= t_Str<T_CHAR>(TEXTAW("NORM_IGNOREWIDTH"));
	T_PCSTR	pszNormLinguisticCasing			= t_Str<T_CHAR>(TEXTAW("NORM_LINGUISTIC_CASING"));
	//T_PCSTR	pszSortDisitsAsNumbers			= t_Str<T_CHAR>(TEXTAW("SORT_DIGITSASNUMBERS"));
	T_PCSTR	pszSortStringSort				= t_Str<T_CHAR>(TEXTAW("SORT_STRINGSORT"));

#define	CSFLAG_SET(b)	(((b) & dwFlags) != 0)

	//pstrDebug->append(t_Str<T_CHAR>(TEXTAW("CompareString Flags\r\n")));
	if (CSFLAG_SET(LINGUISTIC_IGNORECASE))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszLinguisticIgnoreCase);
	if (CSFLAG_SET(LINGUISTIC_IGNOREDIACRITIC))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszLinguisticIgnoreDiacritic);
	if (CSFLAG_SET(NORM_IGNORECASE))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszNormIgnoreCase);
	if (CSFLAG_SET(NORM_IGNOREKANATYPE))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszNormIgnoreKanaType);
	if (CSFLAG_SET(NORM_IGNORENONSPACE))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszNormIgnoreNonSpace);
	if (CSFLAG_SET(NORM_IGNORESYMBOLS))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszNormIgnoreSymbols);
	if (CSFLAG_SET(NORM_IGNOREWIDTH))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszNormIgnoreWidth);
	if (CSFLAG_SET(NORM_LINGUISTIC_CASING))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszNormLinguisticCasing);
	//if (CSFLAG_SET(SORT_DIGITSASNUMBERS))
	//	AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszSortDisitsAsNumbers);
	if (CSFLAG_SET(SORT_STRINGSORT))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszSortStringSort);

#endif
}

//----------------------------------------------------------------------
//	class PCCompareStringOptions
//
//	CompareString 関数のオプションを作成・保持するためのクラス
//----------------------------------------------------------------------
class PCCompareStringOptions
{
protected:
	//------------------------------------------------------------
	//	PCCompareStringOptions:	データメンバ
	//------------------------------------------------------------
	LCID			dwLocale;
	std::wstring	strLocale;

	bool	bLinguisticIgnoreCase;
	bool	bLinguisticIgnoreDiacritic;
	bool	bNormIgnoreCase;
	bool	bNormIgnoreKanaType;
	bool	bNormIgnoreNonSpace;
	bool	bNormIgnoreSymbols;
	bool	bNormIgnoreWidth;
	bool	bNormLinguisticCasing;
	//bool	bSortDigitsAsNumbers;
	bool	bSortStringSort;

	DWORD	dwCompareStringFlags;

public:
	//------------------------------------------------------------
	//	PCCompareStringOptions:	コンストラクタ
	//------------------------------------------------------------
	PCCompareStringOptions()
		:	dwLocale(LOCALE_USER_DEFAULT),
			bLinguisticIgnoreCase(false),
			bLinguisticIgnoreDiacritic(false),
			bNormIgnoreCase(false),
			bNormIgnoreKanaType(false),
			bNormIgnoreNonSpace(false),
			bNormIgnoreSymbols(false),
			bNormIgnoreWidth(false),
			bNormLinguisticCasing(false),
			//bSortDigitsAsNumbers(false),
			bSortStringSort(false),
			dwCompareStringFlags(0)
	{
		strLocale.clear();
	}

	//------------------------------------------------------------
	//	PCCompareStringOptions:	Locale を設定する
	//------------------------------------------------------------
	void SetLocale(LCID dwLoc)
	{
		dwLocale	= dwLoc;
	}

	void SetLocale(LPCWSTR pLocale, size_t zLocale)
	{
		strLocale.assign(pLocale, zLocale);
	}

	void SetLocale(LPCWSTR pszLocale)
	{
		strLocale.assign(pszLocale);
	}

	void ResetLocale()
	{
		dwLocale	= LOCALE_USER_DEFAULT;
		strLocale.clear();
	}

	//------------------------------------------------------------
	//	各フラグの解除
	//------------------------------------------------------------
	void UnsetLinguisticIgnoreCase()
	{
		bLinguisticIgnoreCase	= false;
		dwCompareStringFlags	&= ~(DWORD)LINGUISTIC_IGNORECASE;
	}

	void UnsetLinguisticIgnoreDiacritic()
	{
		bLinguisticIgnoreDiacritic	= false;
		dwCompareStringFlags		&= ~(DWORD)LINGUISTIC_IGNOREDIACRITIC;
	}

	void UnsetNormIgnoreCase()
	{
		bNormIgnoreCase			= false;
		dwCompareStringFlags	&= ~(DWORD)NORM_IGNORECASE;
	}

	void UnsetNormIgnoreKanaType()
	{
		bNormIgnoreKanaType		= false;
		dwCompareStringFlags	&= ~(DWORD)NORM_IGNOREKANATYPE;
	}

	void UnsetNormIgnoreNonSpace()
	{
		bNormIgnoreNonSpace		= false;
		dwCompareStringFlags	&= ~(DWORD)NORM_IGNORENONSPACE;
	}

	void UnsetNormIgnoreSymbols()
	{
		bNormIgnoreSymbols		= false;
		dwCompareStringFlags	&= ~(DWORD)NORM_IGNORESYMBOLS;
	}

	void UnsetNormIgnoreWidth()
	{
		bNormIgnoreWidth		= false;
		dwCompareStringFlags	&= ~(DWORD)NORM_IGNOREWIDTH;
	}

	void UnsetNormLinguisticCasing()
	{
		bNormLinguisticCasing	= false;
		dwCompareStringFlags	&= ~(DWORD)NORM_LINGUISTIC_CASING;
	}

	//void UnsetSortDigitsAsNumbers()
	//{
	//	bSortDigitsAsNumbers	= false;
	//	dwCompareStringFlags	&= ~(DWORD)SORT_DIGITSASNUMBERS;
	//}

	void UnsetSortStringSort()
	{
		bSortStringSort			= false;
		dwCompareStringFlags	&= ~(DWORD)SORT_STRINGSORT;
	}

	//------------------------------------------------------------
	//	各フラグの設定
	//------------------------------------------------------------
	void SetLinguisticIgnoreCase()
	{
		UnsetNormIgnoreCase();
		bLinguisticIgnoreCase	= true;
		dwCompareStringFlags	|= LINGUISTIC_IGNORECASE;
	}

	void SetLinguisticIgnoreDiacritic()
	{
		UnsetNormIgnoreNonSpace();
		bLinguisticIgnoreDiacritic	= true;
		dwCompareStringFlags		|= LINGUISTIC_IGNOREDIACRITIC;
	}

	void SetNormIgnoreCase()
	{
		UnsetLinguisticIgnoreCase();
		bNormIgnoreCase			= true;
		dwCompareStringFlags	|= NORM_IGNORECASE;
	}

	void SetNormIgnoreKanaType()
	{
		bNormIgnoreKanaType		= true;
		dwCompareStringFlags	|= NORM_IGNOREKANATYPE;
	}

	void SetNormIgnoreNonSpace()
	{
		UnsetLinguisticIgnoreDiacritic();
		bNormIgnoreNonSpace		= true;
		dwCompareStringFlags	|= NORM_IGNORENONSPACE;
	}

	void SetNormIgnoreSymbols()
	{
		bNormIgnoreSymbols		= true;
		dwCompareStringFlags	|= NORM_IGNORESYMBOLS;
	}

	void SetNormIgnoreWidth()
	{
		bNormIgnoreWidth		= true;
		dwCompareStringFlags	|= NORM_IGNOREWIDTH;
	}

	void SetNormLinguisticCasing()
	{
		bNormLinguisticCasing	= true;
		dwCompareStringFlags	|= NORM_LINGUISTIC_CASING;
	}

	//void SetSortDigitsAsNumbers()
	//{
	//	bSortDigitsAsNumbers	= true;
	//	dwCompareStringFlags	|= SORT_DIGITSASNUMBERS;
	//}

	void SetSortStringSort()
	{
		bSortStringSort			= true;
		dwCompareStringFlags	|= SORT_STRINGSORT;
	}

	//------------------------------------------------------------
	//	PCCompareStringOptions::Reset
	//------------------------------------------------------------
	virtual void Reset()
	{
		bLinguisticIgnoreCase		= false;
		bLinguisticIgnoreDiacritic	= false;
		bNormIgnoreCase				= false;
		bNormIgnoreKanaType			= false;
		bNormIgnoreNonSpace			= false;
		bNormIgnoreSymbols			= false;
		bNormIgnoreWidth			= false;
		bNormLinguisticCasing		= false;
		//bSortDigitsAsNumbers		= false;
		bSortStringSort				= false;
		dwCompareStringFlags		= 0;

		ResetLocale();
	}

	//------------------------------------------------------------
	//	CopyFrom
	//------------------------------------------------------------
	virtual void CopyFrom(PCCompareStringOptions* pSrc)
	{
		dwLocale					= pSrc->GetLocaleId();
		strLocale.assign(pSrc->strLocale);

		bLinguisticIgnoreCase		= pSrc->IsLinguisticIgnoreCase();
		bLinguisticIgnoreDiacritic	= pSrc->IsLinguisticIgnoreDiacritic();
		bNormIgnoreCase				= pSrc->IsNormIgnoreCase();
		bNormIgnoreKanaType			= pSrc->IsNormIgnoreKanaType();
		bNormIgnoreNonSpace			= pSrc->IsNormIgnoreNonSpace();
		bNormIgnoreSymbols			= pSrc->IsNormIgnoreSymbols();
		bNormIgnoreWidth			= pSrc->IsNormIgnoreWidth();
		bNormLinguisticCasing		= pSrc->IsNormLinguisticCasing();
		//bSortDigitsAsNumbers		= pSrc->IsSortDigitsAsNumbers();
		bSortStringSort				= pSrc->IsSortStringSort();
		//dwCompareStringFlags		= pSrc->GetCompareStringFlags();
		dwCompareStringFlags		= pSrc->GetCStrFlags();
	}

	//------------------------------------------------------------
	//	CopyTo
	//------------------------------------------------------------
	virtual void CopyTo(PCCompareStringOptions* pDst)
	{
		pDst->dwLocale						= dwLocale;
		pDst->strLocale.assign(strLocale);

		pDst->bLinguisticIgnoreCase			= bLinguisticIgnoreCase;
		pDst->bLinguisticIgnoreDiacritic	= bLinguisticIgnoreDiacritic;
		pDst->bNormIgnoreCase				= bNormIgnoreCase;
		pDst->bNormIgnoreKanaType			= bNormIgnoreKanaType;
		pDst->bNormIgnoreNonSpace			= bNormIgnoreNonSpace;
		pDst->bNormIgnoreSymbols			= bNormIgnoreSymbols;
		pDst->bNormIgnoreWidth				= bNormIgnoreWidth;
		pDst->bNormLinguisticCasing			= bNormLinguisticCasing;
		//pDst->bSortDigitsAsNumbers		= bSortDigitsAsNumbers;
		pDst->bSortStringSort				= bSortStringSort;
		pDst->dwCompareStringFlags			= dwCompareStringFlags;
	}

	//------------------------------------------------------------
	//	PCCompareStringOptions:	各フラグを取得する
	//------------------------------------------------------------
	LCID GetLocaleId()					{ return dwLocale; }
	LPCWSTR GetLocaleString()			{ return strLocale.c_str(); }

	bool IsLinguisticIgnoreCase()		{ return bLinguisticIgnoreCase; }
	bool IsLinguisticIgnoreDiacritic()	{ return bLinguisticIgnoreDiacritic; }
	bool IsNormIgnoreCase()				{ return bNormIgnoreCase; }
	bool IsNormIgnoreKanaType()			{ return bNormIgnoreKanaType; }
	bool IsNormIgnoreNonSpace()			{ return bNormIgnoreNonSpace; }
	bool IsNormIgnoreSymbols()			{ return bNormIgnoreSymbols; }
	bool IsNormIgnoreWidth()			{ return bNormIgnoreWidth; }
	bool IsNormLinguisticCasing()		{ return bNormLinguisticCasing; }
	//bool IsSortDigitsAsNumbers()		{ return bSortDigitsAsNumbers; }
	bool IsSortStringSort()				{ return bSortStringSort; }

	virtual bool IsIgnoreCase()
	{
		return (bNormIgnoreCase || bLinguisticIgnoreCase);
	}

	bool IsIgnoreNonSpace()
	{
		return (bNormIgnoreNonSpace || bLinguisticIgnoreDiacritic);
	}

	//------------------------------------------------------------
	//	各種の設定取得
	//------------------------------------------------------------
	virtual bool NoOption()
	{
		return (dwCompareStringFlags == 0 && dwLocale == LOCALE_USER_DEFAULT);
	}

	bool IgnoreCaseOnly(DWORD dwCSFlags)
	{
		return (dwCSFlags == NORM_IGNORECASE);
	}

	bool IgnoreCaseOnly()
	{
		return (dwCompareStringFlags == NORM_IGNORECASE);
	}

	bool NotOnlyIgnoreCase()
	{
		return (dwCompareStringFlags != 0 && dwCompareStringFlags != NORM_IGNORECASE);
	}

	//------------------------------------------------------------
	//	CompareString 関数用のフラグを出力する
	//------------------------------------------------------------
	//DWORD GetCompareStringFlags()	{ return dwCompareStringFlags; }
	DWORD GetCStrFlags()	{ return dwCompareStringFlags; }

	//------------------------------------------------------------
	//	デバッグ用
	//------------------------------------------------------------
#ifdef	PDEBUG

	template<typename T_CHAR>
	void Debug(std::basic_string<T_CHAR>* pstrDebug);

	template<typename T_CHAR>
	bool DebugSimple(std::basic_string<T_CHAR>* pstrDebug);

#endif
};

#ifdef	PDEBUG

//----------------------------------------------------------------------
//	PCCompareStringOptions::Debug
//----------------------------------------------------------------------
template<typename T_CHAR>
void PCCompareStringOptions::Debug(std::basic_string<T_CHAR>* pstrDebug)
{
	typedef	const T_CHAR*	T_PCSTR;

	T_PCSTR	pszLinguisticIgnoreCase			= t_Str<T_CHAR>(TEXTAW("LINGUISTIC_IGNORECASE"));
	T_PCSTR	pszLinguisticIgnoreDiacritic	= t_Str<T_CHAR>(TEXTAW("LINGUISTIC_IGNOREDIACRITIC"));
	T_PCSTR	pszNormIgnoreCase				= t_Str<T_CHAR>(TEXTAW("NORM_IGNORECASE"));
	T_PCSTR	pszNormIgnoreKanaType			= t_Str<T_CHAR>(TEXTAW("NORM_IGNOREKANATYPE"));
	T_PCSTR	pszNormIgnoreNonSpace			= t_Str<T_CHAR>(TEXTAW("NORM_IGNORENONSPACE"));
	T_PCSTR	pszNormIgnoreSymbols			= t_Str<T_CHAR>(TEXTAW("NORM_IGNORESYMBOLS"));
	T_PCSTR	pszNormIgnoreWidth				= t_Str<T_CHAR>(TEXTAW("NORM_IGNOREWIDTH"));
	T_PCSTR	pszNormLinguisticCasing			= t_Str<T_CHAR>(TEXTAW("NORM_LINGUISTIC_CASING"));
	//T_PCSTR	pszSortDisitsAsNumbers			= t_Str<T_CHAR>(TEXTAW("SORT_DIGITSASNUMBERS"));
	T_PCSTR	pszSortStringSort				= t_Str<T_CHAR>(TEXTAW("SORT_STRINGSORT"));
	
	T_PCSTR	pfmt_Locale	= t_Str<T_CHAR>(TEXTAW("Locale: 0x%04X\r\n"));
	T_PCSTR	pfmt_s1		= t_Str<T_CHAR>(TEXTAW("\t%s\r\n"));
	T_PCSTR	pszCRLF		= t_Str<T_CHAR>(TEXTAW("\r\n"));
	T_PCSTR	pszTRUE1	= t_Str<T_CHAR>(TEXTAW(": ○\r\n"));
	T_PCSTR	pszFALSE1	= t_Str<T_CHAR>(TEXTAW(": ×\r\n"));
	T_PCSTR	pszTF;

#define	SELECT_TF(b)	((b) ? pszTRUE1 : pszFALSE1)

	AppendNumToString<T_CHAR, DWORD>(pstrDebug, pfmt_Locale, dwLocale);

	pstrDebug->append(pszLinguisticIgnoreCase);
	pszTF	= SELECT_TF(IsLinguisticIgnoreCase());
	pstrDebug->append(pszTF);

	pstrDebug->append(pszLinguisticIgnoreDiacritic);
	pszTF	= SELECT_TF(IsLinguisticIgnoreDiacritic());
	pstrDebug->append(pszTF);

	pstrDebug->append(pszNormIgnoreCase);
	pszTF	= SELECT_TF(IsNormIgnoreCase());
	pstrDebug->append(pszTF);

	pstrDebug->append(pszNormIgnoreKanaType);
	pszTF	= SELECT_TF(IsNormIgnoreKanaType());
	pstrDebug->append(pszTF);

	pstrDebug->append(pszNormIgnoreNonSpace);
	pszTF	= SELECT_TF(IsNormIgnoreNonSpace());
	pstrDebug->append(pszTF);

	pstrDebug->append(pszNormIgnoreSymbols);
	pszTF	= SELECT_TF(IsNormIgnoreSymbols());
	pstrDebug->append(pszTF);

	pstrDebug->append(pszNormIgnoreWidth);
	pszTF	= SELECT_TF(IsNormIgnoreWidth());
	pstrDebug->append(pszTF);

	pstrDebug->append(pszNormLinguisticCasing);
	pszTF	= SELECT_TF(IsNormLinguisticCasing());
	pstrDebug->append(pszTF);

	//pstrDebug->append(pszSortDisitsAsNumbers);
	//pszTF	= SELECT_TF(IsSortDisitsAsNumbers());
	//pstrDebug->append(pszTF);

	pstrDebug->append(pszSortStringSort);
	pszTF	= SELECT_TF(IsSortStringSort());
	pstrDebug->append(pszTF);
	pstrDebug->append(pszCRLF);

	pstrDebug->append(t_Str<T_CHAR>(TEXTAW("CompareString Flags\r\n")));
	DebugCompareStringFlags(pstrDebug, GetCStrFlags());

	/*
#define	CSFLAG_SET(b)	(((b) & GetCompareStringFlags()) != 0)

	pstrDebug->append(t_Str<T_CHAR>(TEXTAW("CompareString Flags\r\n")));
	if (CSFLAG_SET(LINGUISTIC_IGNORECASE))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszLinguisticIgnoreCase);
	if (CSFLAG_SET(LINGUISTIC_IGNOREDIACRITIC))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszLinguisticIgnoreDiacritic);
	if (CSFLAG_SET(NORM_IGNORECASE))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszNormIgnoreCase);
	if (CSFLAG_SET(NORM_IGNOREKANATYPE))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszNormIgnoreKanaType);
	if (CSFLAG_SET(NORM_IGNORENONSPACE))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszNormIgnoreNonSpace);
	if (CSFLAG_SET(NORM_IGNORESYMBOLS))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszNormIgnoreSymbols);
	if (CSFLAG_SET(NORM_IGNOREWIDTH))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszNormIgnoreWidth);
	if (CSFLAG_SET(NORM_LINGUISTIC_CASING))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszNormLinguisticCasing);
	//if (CSFLAG_SET(SORT_DIGITSASNUMBERS))
	//	AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszSortDisitsAsNumbers);
	if (CSFLAG_SET(SORT_STRINGSORT))
		AppendNumToString<T_CHAR, T_PCSTR>(pstrDebug, pfmt_s1, pszSortStringSort);
		*/
}

//----------------------------------------------------------------------
//	PCCompareStringOptions::DebugSimple
//----------------------------------------------------------------------
template<typename T_CHAR>
bool PCCompareStringOptions::DebugSimple(std::basic_string<T_CHAR>* pstrDebug)
{
	typedef	std::basic_string<T_CHAR>	T_STRING;

	T_STRING	strTemp;
	bool		br	= false;

	if (IsLinguisticIgnoreCase())
	{
		if (!strTemp.empty())	strTemp.append(t_Str<T_CHAR>(TEXTAW(",")));
		strTemp.append(t_Str<T_CHAR>(TEXTAW("li")));
		br	= true;
	}

	if (IsLinguisticIgnoreDiacritic())
	{
		if (!strTemp.empty())	strTemp.append(t_Str<T_CHAR>(TEXTAW(",")));
		strTemp.append(t_Str<T_CHAR>(TEXTAW("ld")));
		br	= true;
	}

	if (IsNormIgnoreCase())
	{
		if (!strTemp.empty())	strTemp.append(t_Str<T_CHAR>(TEXTAW(",")));
		strTemp.append(t_Str<T_CHAR>(TEXTAW("i")));
		br	= true;
	}

	if (IsNormIgnoreKanaType())
	{
		if (!strTemp.empty())	strTemp.append(t_Str<T_CHAR>(TEXTAW(",")));
		strTemp.append(t_Str<T_CHAR>(TEXTAW("k")));
		br	= true;
	}

	if (IsNormIgnoreNonSpace())
	{
		if (!strTemp.empty())	strTemp.append(t_Str<T_CHAR>(TEXTAW(",")));
		strTemp.append(t_Str<T_CHAR>(TEXTAW("d")));
		br	= true;
	}

	if (IsNormIgnoreSymbols())
	{
		if (!strTemp.empty())	strTemp.append(t_Str<T_CHAR>(TEXTAW(",")));
		strTemp.append(t_Str<T_CHAR>(TEXTAW("y")));
		br	= true;
	}

	if (IsNormIgnoreWidth())
	{
		if (!strTemp.empty())	strTemp.append(t_Str<T_CHAR>(TEXTAW(",")));
		strTemp.append(t_Str<T_CHAR>(TEXTAW("w")));
		br	= true;
	}

	if (IsNormLinguisticCasing())
	{
		if (!strTemp.empty())	strTemp.append(t_Str<T_CHAR>(TEXTAW(",")));
		strTemp.append(t_Str<T_CHAR>(TEXTAW("lc")));
		br	= true;
	}

	//if (IsSortDisitsAsNumbers())
	//{
	//	if (!strTemp.empty())	strTemp.append(t_Str<T_CHAR>(TEXTAW(",")));
	//	strTemp.append(t_Str<T_CHAR>(TEXTAW("sn")));
	//	br	= true;
	//}

	if (IsSortStringSort())
	{
		if (!strTemp.empty())	strTemp.append(t_Str<T_CHAR>(TEXTAW(",")));
		strTemp.append(t_Str<T_CHAR>(TEXTAW("ss")));
		br	= true;
	}

	pstrDebug->append(strTemp);
	return br;
}

#endif

NS_PLIB_END
