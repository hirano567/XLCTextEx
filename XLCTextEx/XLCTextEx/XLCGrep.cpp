//	XLCTextEx_1.0x	:	XLCTextEx

// XLCGrep.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"

//======================================================================
//	class PCGrepOptions
//======================================================================
//----------------------------------------------------------------------
//	PCGrepOptions::Set
//----------------------------------------------------------------------
void PCGrepOptions::Set(T_PCSTR_U pStr, size_t zStr)
{
#define	XLCGREP_FLAG_DECODE	0		\
	| PCTEXT_FLAG_DECODE_OCTAL		\
	| PCTEXT_FLAG_DECODE_HEX		\
	| PCTEXT_FLAG_DECODE_ESCCTRL	\
	| PCTEXT_FLAG_DECODE_UNICODE	\
	| PCTEXT_FLAG_DECODE_ITSELF
//	| PCTEXT_FLAG_DECODE_CTRLCHAR

	PLib::PCTextUR	ciSrc;
	T_UCP			cpSrc;
	int				ir;
	T_PCSTR_U		pszCRLF	= TQU("\r\n");

#ifdef	PDEBUG
	T_STRING_U	strDebug;
#endif

	Reset();
	if (pStr == NULL || zStr < 1)	return;

	ciSrc.SetDecodeFlags(XLCGREP_FLAG_DECODE);
	ciSrc.SetDecodeControlFunction(PLib::RegEx::DecodeEscapedControl);
	ciSrc.SetText(pStr, zStr);

#ifdef	PDEBUG
	ciSrc.Debug(&strDebug);
#endif

	for (ciSrc.Begin(); !ciSrc.End(); ciSrc.Next())
	{
		ir	= ciSrc.GetCurrentCp(&cpSrc);
		if (!PCTEXT_GETVALIDCP(ir))	continue;

		switch (cpSrc)
		{
		case (T_UCP)'n':
		case (T_UCP)0xFF4E:
			SetRowNumber();
			break;

		case (T_UCP)'v':
		case (T_UCP)0xFF56:
			SetNonMatching();
			break;

		case (T_UCP)'h':
		case (T_UCP)0xFF48:
			SetSheetName();
			break;

		case (T_UCP)'c':
		case (T_UCP)0xFF43:
			ciSrc.Next();
			ir	= ciSrc.GetCurrentCp(&cpSrc);
			if (!PCTEXT_GETVALIDCP(ir))
			{
				SetMatchingDelimiter();
			}
			else if (cpSrc == (T_UCP)'N' || cpSrc == (T_UCP)0xFF2E)
			{
				strMatchingDelimiter.clear();
			}
			else
			{
				strMatchingDelimiter.clear();
				SetMatchingDelimiter(cpSrc);
			}
			break;

		case (T_UCP)'d':
		case (T_UCP)0xFF44:
			ciSrc.Next();
			ir	= ciSrc.GetCurrentCp(&cpSrc);
			if (!PCTEXT_GETVALIDCP(ir))
			{
				SetOutputDelimiter();
			}
			else if (cpSrc == (T_UCP)'N' || cpSrc == (T_UCP)0xFF2E)
			{
				strOutputDelimiter.clear();
			}
			else if (cpSrc == (T_UCP)'L' || cpSrc == (T_UCP)0xFF2C)
			{
				strOutputDelimiter.clear();
				SetOutputDelimiter(pszCRLF);
			}
			else
			{
				strOutputDelimiter.clear();
				SetOutputDelimiter(cpSrc);
			}
			break;

		default:
			break;
		}
	}
}

//----------------------------------------------------------------------
//	PCGrepOptions::Debug
//----------------------------------------------------------------------
#ifdef	PDEBUG
void PCGrepOptions::Debug(T_STRING_U* pstrDebug)
{
	T_STRING_U::iterator	itr;
	T_PCSTR_U				pFmt	= TQU(" 0x%04X");
	T_PCSTR_U				pLF		= TQU("\r\n");

	pstrDebug->append(TQU("RowNumber\t: "));
	if (this->IsRowNumber())
	{
		pstrDebug->append(TQU("True"));
	}
	else
	{
		pstrDebug->append(TQU("False"));
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("NonMatching\t: "));
	if (this->IsNonMatching())
	{
		pstrDebug->append(TQU("True"));
	}
	else
	{
		pstrDebug->append(TQU("False"));
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("SheetName\t: "));
	if (this->IsSheetName())
	{
		pstrDebug->append(TQU("True"));
	}
	else
	{
		pstrDebug->append(TQU("False"));
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("MatchingDelimiter\t:"));
	for (itr = strMatchingDelimiter.begin(); itr != strMatchingDelimiter.end(); ++itr)
	{
		PLib::AppendNumToString<T_CHAR_U, UINT>(pstrDebug, pFmt, (UINT)*itr);
	}
	pstrDebug->append(pLF);

	pstrDebug->append(TQU("OutputDelimiter\t:"));
	for (itr = strOutputDelimiter.begin(); itr != strOutputDelimiter.end(); ++itr)
	{
		PLib::AppendNumToString<T_CHAR_U, UINT>(pstrDebug, pFmt, (UINT)*itr);
	}
	pstrDebug->append(pLF);
}
#endif

//======================================================================
//	XLCGrepGetSheetName
//======================================================================
template<typename T_XLOPER>
bool XLCGrepGetSheetName(T_STRING_U* pstrName)
{
	THROWPE_LOGIC_ERROR("XLCGrepGetSheetName: not implemented.");
	return false;
}
//----------------------------------------------------------------------
//	XLOPER
//----------------------------------------------------------------------
template<>
bool XLCGrepGetSheetName<XLOPER>(T_STRING_U* pstrName)
{
	std::string	strNameA;
	PLib::PCStringConverter<wchar_t, char>	ciConverter;

	if (!XLL::t_GetActiveSheetName<char, XLOPER>(&strNameA))	return false;
	return ciConverter.Convert(pstrName, &strNameA);
}
//----------------------------------------------------------------------
//	XLOPER12
//----------------------------------------------------------------------
template<>
bool XLCGrepGetSheetName<XLOPER12>(T_STRING_U* pstrName)
{
	return XLL::t_GetActiveSheetName<wchar_t, XLOPER12>(pstrName);
}

//======================================================================
//	PCXLCGrepRowConverter	(1)	dummy
//======================================================================
template<typename T_CHAR, typename T_XLOPER>
class PCXLCGrepRowConverter
{
public:
	typedef	T_CHAR*						T_PSTR;
	typedef	const T_CHAR*				T_PCSTR;
	typedef	std::basic_string<T_CHAR>	T_STRING;
	typedef	XLOPER						T_XLOPER;

	void ThrowException()	{ THROWPE_LOGIC_ERROR("PCXLCGrepRowConverter: not implemented."); }

	void	SetMatchingDelimiter(T_STRING_U* pstrSrc)			{ ThrowException(); };
	void	SetOutputDelimiter(T_STRING_U* pstrSrc)				{ ThrowException(); };
	void	GetRowText(size_t zRow, size_t zColF, size_t zColL)	{ ThrowException(); };
	void	GetMatchingString(T_STRING_U* pstrBuf)				{ ThrowException(); };
	void	GetOutputString(T_STRING_U* pstrBuf)				{ ThrowException(); };
};
//======================================================================
//	PCXLCGrepRowConverter	(2)	char, XLOPER
//======================================================================
template<>
class PCXLCGrepRowConverter<char, XLOPER>
{
public:
	typedef	char						T_CHAR;
	typedef	T_CHAR*						T_PSTR;
	typedef	const T_CHAR*				T_PCSTR;
	typedef	std::basic_string<T_CHAR>	T_STRING;
	typedef	XLOPER						T_XLOPER;
	typedef	XLMREF						T_XLMREF;

	typedef	std::vector<T_STRING_U*>	CSTRINGARRAY;
	typedef	CSTRINGARRAY::iterator		ITR_STRINGARRAY;

private:
	T_STRING_U		strMatchingDelimiter;
	T_STRING_U		strOutputDelimiter;
	CSTRINGARRAY	ciStringArray;
	size_t			zCells;

	PLib::PCPStrConverter<wchar_t, char>	ciConverter;

public:
	PCXLCGrepRowConverter()
		:	zCells(0)
	{}

	~PCXLCGrepRowConverter()
	{
		ITR_STRINGARRAY	itr;

		for (itr = ciStringArray.begin(); itr != ciStringArray.end(); ++itr)
		{
			delete	*itr;
		}
	}

	//------------------------------------------------------------
	//	ConvertToStringU
	//------------------------------------------------------------
	void ConvertToStringU(T_STRING_U* pstrBufU, T_PCSTR pSrc, size_t zSrc)
	{
		T_PCSTR_U	pStrU;
		size_t		zStrU;

		if (pstrBufU == NULL)	return;
		if (pSrc == NULL || zSrc < 1)
		{
			pstrBufU->clear();
			return;
		}

		if (ciConverter.Convert(&pStrU, &zStrU, pSrc, zSrc))
		{
			pstrBufU->assign(pStrU, zStrU);
		}
	}

	//------------------------------------------------------------
	//	SetMatchingDelimiter
	//------------------------------------------------------------
	void SetMatchingDelimiter(T_STRING_U* pstrSrc)
	{
		strMatchingDelimiter.assign(*pstrSrc);
	}

	//------------------------------------------------------------
	//	SetOutputDelimiter
	//------------------------------------------------------------
	void SetOutputDelimiter(T_STRING_U* pstrSrc)
	{
		strOutputDelimiter.assign(*pstrSrc);
	}

	//------------------------------------------------------------
	//	PrepareToGetRowText
	//------------------------------------------------------------
	bool PrepareToGetRowText()
	{
		return true;
	}

	//------------------------------------------------------------
	//	GetRowText
	//------------------------------------------------------------
	void GetRowText(size_t zRow, size_t zColF, size_t zColL)
	{
		T_XLOPER		xCell, xType, xRef;
		T_XLMREF		xMRef;
		ITR_STRINGARRAY	itr;
		size_t			zi;
		int				ir;
		size_t			zs;

		if (zColF > zColL)	return;
		zCells	= zColL - zColF + 1;

		//	格納用の文字列を作成する。
		while (ciStringArray.size() < zCells)
		{
			ciStringArray.push_back(new T_STRING_U);
		}

		//	ワークシートの行からデータをテキスト形式で取得する。
		xType.xltype	= xltypeInt;
		xType.val.w		= 53;

		if (t_Excel<T_XLOPER>(xlSheetId, &xRef) != xlretSuccess)	return;
		xRef.xltype				= xltypeRef;
		xRef.val.mref.lpmref	= &xMRef;
		xRef.val.mref.lpmref->count	= 1;

		for (zi = zColF, itr = ciStringArray.begin();zi <= zColL && itr != ciStringArray.end(); ++zi, ++itr)
		{
			XLL::SetXLOPER_Ref<size_t>(&xRef, 0, zRow, zRow, zi, zi);
			ir	= t_Excel<T_XLOPER, false>(xlfGetCell, &xCell, &xType, &xRef);
			if (ir != xlretSuccess || xCell.xltype != xltypeStr)
			{
				(*itr)->clear();
			}
			else
			{
				zs	= (size_t)(unsigned char)*(xCell.val.str);
				if (zs > 0)
				{
					ConvertToStringU(*itr, xCell.val.str + 1, zs);
				}
				else
				{
					(*itr)->clear();
				}
			}
			XLL::FreeXLOPER<T_XLOPER>(&xCell);
		}
	}

	//------------------------------------------------------------
	//	GetString
	//------------------------------------------------------------
	void GetString(T_STRING_U* pstrBuf, T_STRING_U* pstrDelim)
	{
		size_t	zi;

		if (zCells == 0 || zCells > ciStringArray.size())	return;
		pstrBuf->append(*(ciStringArray.at(0)));
		for (zi = 1; zi < zCells; ++zi)
		{
			pstrBuf->append(*pstrDelim);
			pstrBuf->append(*(ciStringArray.at(zi)));
		}
	}

	//------------------------------------------------------------
	//	GetMatchingString
	//------------------------------------------------------------
	void GetMatchingString(T_STRING_U* pstrBuf)
	{
		pstrBuf->clear();
		GetString(pstrBuf, &strMatchingDelimiter);
	}

	//------------------------------------------------------------
	//	GetOutputString
	//------------------------------------------------------------
	void GetOutputString(T_STRING_U* pstrBuf)
	{
		GetString(pstrBuf, &strOutputDelimiter);
	}
};
//======================================================================
//	PCXLCGrepRowConverter<wchar_t, XLOPER12>
//======================================================================
template<>
class PCXLCGrepRowConverter<wchar_t, XLOPER12>
{
public:
	typedef	wchar_t						T_CHAR;
	typedef	T_CHAR*						T_PSTR;
	typedef	const T_CHAR*				T_PCSTR;
	typedef	std::basic_string<T_CHAR>	T_STRING;
	typedef	XLOPER12					T_XLOPER;

private:
	T_STRING_U		strMatchingDelimiter;
	T_STRING_U		strOutputDelimiter;
	T_XLOPER*		pxCellArray;
	size_t			zCellArray;
	size_t			zCells;

	//PLib::PCPStrConverter<wchar_t, char>	ciConverter;
	//	作業用一時変数
	XLOPER12	xOpRef;
	XLMREF12	xMRef;

public:
	//------------------------------------------------------------
	//	FreeRowXLOPER
	//------------------------------------------------------------
	void FreeRowXLOPER()
	{
		T_XLOPER*	px;
		T_XLOPER*	pe;

		if (pxCellArray == NULL || zCellArray < 1)	return;

		px	= pxCellArray;
		pe	= px + zCellArray;
		for ( ; px < pe; ++px)
		{
			XLL::FreeXLOPER<T_XLOPER>(px);
		}
	}

	//------------------------------------------------------------
	//	コンストラクタとデストラクタ
	//------------------------------------------------------------
	PCXLCGrepRowConverter()
		:	pxCellArray(NULL), zCellArray(0), zCells(0)
	{
	}

	~PCXLCGrepRowConverter()
	{
		FreeRowXLOPER();
		delete[]	pxCellArray;
	}

	//------------------------------------------------------------
	//	SetMatchingDelimiter
	//------------------------------------------------------------
	void SetMatchingDelimiter(T_STRING_U* pstrSrc)
	{
		strMatchingDelimiter.assign(*pstrSrc);
	}

	//------------------------------------------------------------
	//	SetOutputDelimiter
	//------------------------------------------------------------
	void SetOutputDelimiter(T_STRING_U* pstrSrc)
	{
		strOutputDelimiter.assign(*pstrSrc);
	}

	//------------------------------------------------------------
	//	PrepareToGetRowText
	//------------------------------------------------------------
	bool PrepareToGetRowText()
	{
		if (t_Excel<T_XLOPER>(xlSheetId, &xOpRef) != xlretSuccess)	return false;
		xOpRef.xltype					= xltypeRef;
		xOpRef.val.mref.lpmref			= &xMRef;
		xOpRef.val.mref.lpmref->count	= 1;
		return true;
	}

	//------------------------------------------------------------
	//	GetRowText
	//------------------------------------------------------------
	void GetRowText(size_t zRow, size_t zColF, size_t zColL)
	{
		T_XLOPER		xType;	//, xRef;
		T_XLOPER*		px;
		T_XLOPER*		pxe;
		size_t			zi;
		int				ir;

		//	以前のデータを解放しておく。
		FreeRowXLOPER();

		if (zColF > zColL)	return;
		zCells	= zColL - zColF + 1;
		
		//	格納用の XLOPER を作成する。
		if (zCells > zCellArray)
		{
			delete[]	pxCellArray;
			pxCellArray	= new T_XLOPER[zCells];
			zCellArray	= zCells;
		}

		//	ワークシートの行からデータをテキスト形式で取得する。
		xType.xltype	= xltypeInt;
		xType.val.w		= 53;

		px	= pxCellArray;
		pxe	= px + zCells;
		for (zi = zColF;px < pxe && zi <= zColL; ++zi, ++px)
		{
			XLL::SetXLOPER_Ref<size_t>(&xOpRef, 0, zRow, zRow, zi, zi);
			ir	= t_Excel<T_XLOPER, false>(xlfGetCell, px, &xType, &xOpRef);
		}
	}

	//------------------------------------------------------------
	//	GetString
	//------------------------------------------------------------
	void GetString(T_STRING_U* pstrBuf, T_STRING_U* pstrDelim)
	{
		T_XLOPER*	px;
		T_XLOPER*	pxe;
		size_t		zs;

		if (pxCellArray == NULL || zCells == 0 || zCells > zCellArray)	return;
		px	= pxCellArray;
		pxe	= px + zCells;

		zs	= (size_t)*(px->val.str);
		if (zs > 0)
		{
			pstrBuf->append(px->val.str + 1, zs);
		}

		for (++px; px < pxe; ++px)
		{
			pstrBuf->append(*pstrDelim);
			zs	= (size_t)*(px->val.str);
			if (zs > 0)
			{
				pstrBuf->append(px->val.str + 1, zs);
			}
		}
	}

	//------------------------------------------------------------
	//	GetMatchingString
	//------------------------------------------------------------
	void GetMatchingString(T_STRING_U* pstrBuf)
	{
		pstrBuf->clear();
		GetString(pstrBuf, &strMatchingDelimiter);
	}

	//------------------------------------------------------------
	//	GetOutputString
	//------------------------------------------------------------
	void GetOutputString(T_STRING_U* pstrBuf)
	{
		GetString(pstrBuf, &strOutputDelimiter);
	}
};

//======================================================================
//	XLCGrepSetOptions
//	引数はカウント付き文字列
//======================================================================
void XLCGrepSetOptions(PCGrepOptions* pciOpt, LPCSTR pOpt)
{
	LPWSTR	pOptW	= NULL;
	size_t	zs1, zs2;

	if (pOpt == NULL || (zs1 = (size_t)(unsigned char)(*pOpt)) < 1)	return;
	if (PLib::ConvertMBtoWCMa(&pOptW, &zs2, pOpt + 1, zs1, CP_ACP))
	{
		if (zs2 > 0)
		{
			pciOpt->Set(pOptW, zs2);
		}
	}
	delete[]	pOptW;
	return;
}

void XLCGrepSetOptions(PCGrepOptions* pciOpt, LPCWSTR pszOpt)
{
	size_t	zs;

	zs	= (size_t)*pszOpt;
	if (zs > 0)
	{
		pciOpt->Set(pszOpt + 1, zs);
	}
}

//======================================================================
//	XLCGrepSetRegEx
//	引数はカウント付き文字列
//======================================================================
//----------------------------------------------------------------------
//	char
//----------------------------------------------------------------------
bool XLCGrepSetRegEx(PLib::PCRegEx* pciRegEx, LPCSTR pPat, LPCSTR pOpt, T_STRING_U* pstrError)
{
	typedef	char	T_CHAR;

	LPWSTR		psu	= NULL;
	size_t		zs1, zs2;
	LPCWSTR		pszNull	= L"";
	bool		br;

	if (pOpt != NULL && (zs1 = XLL::GetStringSize<T_CHAR>(pOpt)) > 0)
	{
		if (!PLib::ConvertMBtoWCMa(&psu, &zs2, pOpt + 1, zs1, CP_ACP))	goto ERROR_HANDLING;
		(pciRegEx->Options())->Set(psu, zs2);
		delete[]	psu;
	}

	if (pPat != NULL && (zs1 = XLL::GetStringSize<T_CHAR>(pPat)) > 0)
	{
		if (!PLib::ConvertMBtoWCMa(&psu, &zs2, pPat + 1, zs1, CP_ACP))	goto ERROR_HANDLING;
		pciRegEx->SetPattern(psu, zs2);
		delete[]	psu;
	}
	else
	{
		pciRegEx->SetPattern(pszNull);
	}

	pstrError->clear();
	br	= pciRegEx->BuildNFA(pstrError);
	return br;

ERROR_HANDLING:
	delete[]	psu;
	return false;
}

//----------------------------------------------------------------------
//	wchar_t
//----------------------------------------------------------------------
bool XLCGrepSetRegEx(PLib::PCRegEx* pciRegEx, LPCWSTR pPat, LPCWSTR pOpt, T_STRING_U* pstrError)
{
	typedef	wchar_t	T_CHAR;

	size_t		zs;
	LPCWSTR		pszNull	= L"";
	bool		br;

	if (pOpt != NULL && (zs = XLL::GetStringSize<T_CHAR>(pOpt)) > 0)
	{
		(pciRegEx->Options())->Set(pOpt + 1, zs);
	}
	if (pPat != NULL && (zs = XLL::GetStringSize<T_CHAR>(pPat)) > 0)
	{
		pciRegEx->SetPattern(pPat + 1, zs);
	}
	else
	{
		pciRegEx->SetPattern(pszNull);
	}

	pstrError->clear();
	br	= pciRegEx->BuildNFA(pstrError);
	return br;
}

//======================================================================
//	t_XLCGrep
//	引数はカウント付き文字列
//======================================================================
template<typename T_CHAR, typename T_XLOPER>
int	t_XLCGrep(const T_CHAR* pPattern, const T_CHAR* pOpt1, const T_CHAR* pOpt2, T_STRING_U* pstrError)
{
	typedef	T_CHAR*						T_PSTR;
	typedef	const T_CHAR*				T_PCSTR;
	typedef	std::basic_string<T_CHAR>	T_STRING;

	PCGrepOptions		ciOpt;
	PLib::PCRegEx		ciRegEx;
	PLib::PCRegExText	ciText;

	double	dRowF, dRowL, dColF, dColL;
	size_t	zRowF, zRowL, zColF, zColL;
	UINT	uir;
	bool	br;
	int		ir;
	int		iMatch;


	PCXLCGrepRowConverter<T_CHAR, T_XLOPER>	ciRowConverter;

	T_STRING_U		strRowU, strOutputU;
	T_PCSTR_U		pLF	= TQU("\r\n");
	T_PCSTR_U		pHT	= TQU("\t");
	T_STRING_U		strSheetName;
	const size_t	zRowNumBuf	= 16;
	T_CHAR_U		szRowNumBuf[zRowNumBuf];

	XLL::GetUsedRegion<T_XLOPER>(&dRowF, &dRowL, &dColF, &dColL);
	if (dRowF <= 0)	return 0;
	zRowF	= (size_t)dRowF - 1;
	zRowL	= (size_t)dRowL - 1;
	zColF	= (size_t)dColF - 1;
	zColL	= (size_t)dColL - 1;

	if (!ciRowConverter.PrepareToGetRowText())	return 0;

	//	オプションを設定する。
	XLCGrepSetOptions(&ciOpt, pOpt2);
	ciRowConverter.SetMatchingDelimiter(ciOpt.GetMatchingDelimiter());
	ciRowConverter.SetOutputDelimiter(ciOpt.GetOutputDelimiter());

	if (ciOpt.IsSheetName())
	{
		XLCGrepGetSheetName<T_XLOPER>(&strSheetName);
	}

	//	PCRegEx にオプションとパターンを設定する。
	if (!XLCGrepSetRegEx(&ciRegEx, pPattern, pOpt1, pstrError))
	{
		return XLCGREP_ERROR_SYNTAX_ERROR;
	}

	//	PCRegExText の設定
	ciText.SetDecodeFlags(PCTEXT_FLAG_DECODE_NONE);

	strOutputU.clear();
	iMatch	= 0;
	for (uir = zRowF; uir <= zRowL; ++uir)
	{
		//	1 行分のデータを取得する。
		ciRowConverter.GetRowText(uir, zColF,zColL);

		//	パターンマッチ用の文字列を取得する。
		ciRowConverter.GetMatchingString(&strRowU);

		//	パターンマッチを行う
		ciText.Init();
		ciText.SetText(strRowU.c_str(), strRowU.size());
		ciText.Begin();
		br	= ciRegEx.Match(&ciText);
		if (br == ciOpt.IsNonMatching())	continue;

		//	クリップボード出力用の文字列を取得する。
		if (ciOpt.IsSheetName())
		{
			strOutputU.append(strSheetName);
			strOutputU.append(*(ciOpt.GetOutputDelimiter()));
		}
		if (ciOpt.IsRowNumber())
		{
			ir	= swprintf_s(szRowNumBuf, zRowNumBuf, L"%d", (uir + 1));
			if (ir > 0)
			{
				strOutputU.append(szRowNumBuf);
			}
			strOutputU.append(*(ciOpt.GetOutputDelimiter()));
		}
		ciRowConverter.GetOutputString(&strOutputU);
		strOutputU.append(pLF);
		++iMatch;
	}
	PLib::CopyToClipboard(NULL, CF_UNICODETEXT, (LPVOID)(strOutputU.c_str()), (strOutputU.size() + 1) * sizeof(wchar_t));
	return iMatch;
}

//======================================================================
//	t_XLCGrep_ex
//	引数はカウント付き文字列
//	例外処理と返り値の設定を行う
//======================================================================
template<typename T_CHAR, typename T_XLOPER>
int	t_XLCGrep_ex(const T_CHAR* pPattern, const T_CHAR* pOpt1, const T_CHAR* pOpt2)
{
	int			ir	= XLCGREP_ERROR;
	T_STRING_U	strError;

	try
	{
		ir	= t_XLCGrep<T_CHAR, T_XLOPER>(pPattern, pOpt1, pOpt2, &strError);
	}
	catch (std::bad_alloc&)
	{
		ir	= XLCGREP_ERROR_BAD_ALLOC;
	}
	catch (...)
	{
		//	ir	= -1;
	}
	return ir;
}

//======================================================================
//	XLCGrep4
//	引数はカウント付き文字列
//======================================================================
int	XLCGrep4(LPCSTR pszPattern, LPCSTR pszOpt1, LPCSTR pszOpt2)
{
	return t_XLCGrep_ex<char, XLOPER>(pszPattern, pszOpt1, pszOpt2);
}

//======================================================================
//	XLCGrep12
//	引数はカウント付き文字列
//======================================================================
int	XLCGrep12(LPCWSTR pszPattern, LPCWSTR pszOpt1, LPCWSTR pszOpt2)
{
	return t_XLCGrep_ex<wchar_t, XLOPER12>(pszPattern, pszOpt1, pszOpt2);
}
