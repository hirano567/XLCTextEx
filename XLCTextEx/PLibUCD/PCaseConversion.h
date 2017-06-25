//	XLCTextEx_1.0x	:	PLibUCD

//	PLibUCD:	PCaseConversion.h
//
#pragma once

NS_PLIB_UNICODE_BEGIN

//----------------------------------------------------------------------
//	struct	SCASEFOLDMAP
//----------------------------------------------------------------------
struct	SCASEFOLDMAP
{
	T_UCP		cpSrc;
	T_UCP*		pcpDst;
	int			nDst;
	T_PCSTR_U	pszDst;

	bool LessThan(UINT uiOther)	{ return (cpSrc < uiOther); }
	bool Match(UINT uiOther)	{ return (cpSrc == uiOther); }

#ifdef	PDEBUG
	void Debug(T_STRING_U* pstrDebug)
	{
		int			i;
		UINT*		pui;
		T_PCSTR_U	pfmt_CpSrc	= TQU("Map:\t0x%04X,\tDst:");
		T_PCSTR_U	pfmt_CpDst	= TQU(" 0x%04X");
		T_PCSTR_U	pLF			= TQU("\r\n");
		T_PCSTR_U	pHT			= TQU("\t");
		T_PCSTR_U	pCM			= TQU(",");

		PLib::AppendNumToString<T_CHAR_U, T_UCP>(pstrDebug, pfmt_CpSrc, cpSrc);
		for (i = 0, pui = pcpDst; i < nDst; ++i, ++pui)
		{
			PLib::AppendNumToString<T_CHAR_U, UINT>(pstrDebug, pfmt_CpDst, *pui);
		}
		pstrDebug->append(TQU(",\t"));
		pstrDebug->append(pszDst);
		pstrDebug->append(pLF);
	}
#endif
};
typedef	SCASEFOLDMAP	*PSCASEFOLDMAP;

//----------------------------------------------------------------------
//	CaseFolding �Ŏg�p����f�[�^
//----------------------------------------------------------------------
extern SCASEFOLDMAP	siCaseFolding_CF[];
extern const size_t	nCaseFolding_CF;

extern SCASEFOLDMAP	siCaseFolding_CS[];
extern const size_t	nCaseFolding_CS;

extern SCASEFOLDMAP	siCaseFolding_Kana[];
extern const size_t	nCaseFolding_Kana;

//======================================================================
//	CaseFolding	�i1 �̃R�[�h�|�C���g��ϊ�����j
//======================================================================
bool	CaseFoldingFull(T_UCP** ppuiDst, int* pnDst, T_UCP uiSrc);
bool	CaseFoldingSimple(T_UCP** ppuiDst, int* pnDst, T_UCP uiSrc);

//======================================================================
//	CaseFolding	(1)	Codepoint �ł̓��o��
//======================================================================
bool	CaseFoldingFull(UCPSTRING* puisDst, UCPSTRING* puisSrc);
bool	CaseFoldingSimple(UCPSTRING* puisDst, UCPSTRING* puisSrc);

bool	CaseFoldingFull(UCPSTRING* puisDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE);
bool	CaseFoldingSimple(UCPSTRING* puisDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE);

bool	CaseFoldingFull(UCPSTRING* puisDst, T_PCSTR_U pszSrc);
bool	CaseFoldingSimple(UCPSTRING* puisDst, T_PCSTR_U pszSrc);

bool	CaseFoldingFull(T_STRING_U* pstrDst, UCPSTRING* puisSrc);
bool	CaseFoldingSimple(T_STRING_U* pstrDst, UCPSTRING* puisSrc);

//======================================================================
//	CaseFolding	(2)	Unicode ������ł̓��o��
//======================================================================
bool	CaseFoldingFull(T_STRING_U* pstrDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE);
bool	CaseFoldingSimple(T_STRING_U* pstrDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE);

bool	CaseFoldingFull(T_STRING_U* pstrDst, T_PCSTR_U pSrc);
bool	CaseFoldingSimple(T_STRING_U* pstrDst, T_PCSTR_U pSrc);

//======================================================================
//	CaseFoldingKana	�Ђ炪�ȁA�J�^�J�i
//======================================================================
bool	CaseFoldingKana(T_UCP* puiCpDst, T_UCP uiCpSrc);
T_UCP	CaseFoldingKana(T_UCP uiCpSrc);

bool	CaseFoldingKana(UCPSTRING* puisDst, UCPSTRING* puisSrc);
bool	CaseFoldingKana(UCPSTRING* puisDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE);
bool	CaseFoldingKana(UCPSTRING* puisDst, T_PCSTR_U pszSrc);
bool	CaseFoldingKana(T_STRING_U* pstrDst, UCPSTRING* puisSrc);

bool	CaseFoldingKana(T_STRING_U* pstrDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE);
bool	CaseFoldingKana(T_STRING_U* pstrDst, T_PCSTR_U pSrc);

//======================================================================
//	�e���v���[�g
//======================================================================
template<typename T_CHAR>
inline bool	t_CaseFoldingSimple(std::basic_string<T_CHAR>* pstrDst, const T_CHAR* pSrc)
{
	THROWPE_LOGIC_ERROR("CaseFoldingSimple: not implemented.");
	return false;
}
template<>
inline bool	t_CaseFoldingSimple<wchar_t>(std::wstring* pstrDst, LPCWSTR pSrc)
{
	return CaseFoldingSimple(pstrDst, pSrc);
}

//======================================================================
//	CICompare
//======================================================================
int	CICompareFull(T_PCSTR_U pStr1B, T_PCSTR_U pStr1E,
					T_PCSTR_U pStr2B, T_PCSTR_U pStr2E);
int	CICompareSimple(T_PCSTR_U pStr1B, T_PCSTR_U pStr1E,
					  T_PCSTR_U pStr2B, T_PCSTR_U pStr2E);

int	CICompareFull(T_PCSTR_U pStr1, T_PCSTR_U pStr2);
int	CICompareSimple(T_PCSTR_U pStr1, T_PCSTR_U pStr2);

//======================================================================
//	CICompareN
//======================================================================
int	CICompareNFull(T_PCSTR_U pStr1B, T_PCSTR_U pStr1E,
					 T_PCSTR_U pStr2B, T_PCSTR_U pStr2E, size_t zCount);
int	CICompareNSimple(T_PCSTR_U pStr1B, T_PCSTR_U pStr1E,
					   T_PCSTR_U pStr2B, T_PCSTR_U pStr2E, size_t zCount);

int	CICompareNFull(T_PCSTR_U pStr1, T_PCSTR_U pStr2, size_t zCount);
int	CICompareNSimple(T_PCSTR_U pStr1, T_PCSTR_U pStr2, size_t zCount);


//======================================================================
//	t_StrCmp	�iUnicode Simple Loose Match �Łj
//
//	_stricmp �n�֐��� strcmp �n�֐��̃e���v���[�g	(1)
//======================================================================
template<typename T, BOOL B_CASE>
inline int t_StrCmp(const T* ps1, const T* ps2)
{
	THROW_LOGIC_ERROR("t_StrCmp: bad parameter");
	return -1;
}
//----------------------------------------------------------------------
//	char�A�啶���������̋�ʂȂ�
//----------------------------------------------------------------------
template<>
inline int t_StrCmp<char, FALSE>(const char* ps1, const char* ps2)
{
	return _stricmp(ps1, ps2);
}
//----------------------------------------------------------------------
//	wchar_t�A�啶���������̋�ʂȂ�
//----------------------------------------------------------------------
template<>
inline int t_StrCmp<wchar_t, FALSE>(const wchar_t* ps1, const wchar_t* ps2)
{
	return CICompareSimple(ps1, ps2);
}
//----------------------------------------------------------------------
//	char�A�啶���������̋�ʂ���
//----------------------------------------------------------------------
template<>
inline int t_StrCmp<char, TRUE>(const char* ps1, const char* ps2)
{
	return strcmp(ps1, ps2);
}
//----------------------------------------------------------------------
//	wchar_t�A�啶���������̋�ʂ���
//----------------------------------------------------------------------
template<>
inline int t_StrCmp<wchar_t, TRUE>(const wchar_t* ps1, const wchar_t* ps2)
{
	return wcscmp(ps1, ps2);
}

//======================================================================
//	t_StrCmpICase	�iUnicode Simple Loose Match �Łj
//
//	_stricmp �n�֐��� strcmp �n�֐��̃e���v���[�g	(2)
//======================================================================
template<typename T, BOOL B_ICASE>
inline int t_StrCmpICase(const T* ps1, const T* ps2)
{
	THROWPE_LOGIC_ERROR("t_StrCmpICase: bad parameter");
	return -1;
}
//----------------------------------------------------------------------
//	char�A�啶���������̋�ʂȂ�
//----------------------------------------------------------------------
template<>
inline int t_StrCmpICase<char, TRUE>(const char* ps1, const char* ps2)
{
	return _stricmp(ps1, ps2);
}
//----------------------------------------------------------------------
//	wchar_t�A�啶���������̋�ʂȂ�
//----------------------------------------------------------------------
template<>
inline int t_StrCmpICase<wchar_t, TRUE>(const wchar_t* ps1, const wchar_t* ps2)
{
	return CICompareSimple(ps1, ps2);
}
//----------------------------------------------------------------------
//	char�A�啶���������̋�ʂ���
//----------------------------------------------------------------------
template<>
inline int t_StrCmpICase<char, FALSE>(const char* ps1, const char* ps2)
{
	return strcmp(ps1, ps2);
}
//----------------------------------------------------------------------
//	wchar_t�A�啶���������̋�ʂ���
//----------------------------------------------------------------------
template<>
inline int t_StrCmpICase<wchar_t, FALSE>(const wchar_t* ps1, const wchar_t* ps2)
{
	return wcscmp(ps1, ps2);
}

//======================================================================
//	t_StrNCmp	�iUnicode Simple Loose Match �Łj
//
//	_strncmp�A_strnicmp �n�֐��̃e���v���[�g	(1)
//======================================================================
template<typename T_CHAR, BOOL B_CASE>
inline int t_StrNCmp(const T_CHAR* pStr1, const T_CHAR* pStr2, size_t zCount)
{
	THROW_LOGIC_ERROR("t_StrNCmp");
	return 0;
}
//----------------------------------------------------------------------
//	char�A�啶���������̋�ʂȂ�
//----------------------------------------------------------------------
template<>
inline int t_StrNCmp<char, FALSE>(LPCSTR pStr1, LPCSTR pStr2, size_t zCount)
{
	return _strnicmp(pStr1, pStr2, zCount);
}
//----------------------------------------------------------------------
//	wchar_t�A�啶���������̋�ʂȂ�
//----------------------------------------------------------------------
template<>
inline int t_StrNCmp<wchar_t, FALSE>(LPCWSTR pStr1, LPCWSTR pStr2, size_t zCount)
{
	return CICompareNSimple(pStr1, pStr2, zCount);
}
//----------------------------------------------------------------------
//	char�A�啶���������̋�ʂ���
//----------------------------------------------------------------------
template<>
inline int t_StrNCmp<char, TRUE>(LPCSTR pStr1, LPCSTR pStr2, size_t zCount)
{
	return strncmp(pStr1, pStr2, zCount);
}
//----------------------------------------------------------------------
//	wchar_t�A�啶���������̋�ʂ���
//----------------------------------------------------------------------
template<>
inline int t_StrNCmp<wchar_t, TRUE>(LPCWSTR pStr1, LPCWSTR pStr2, size_t zCount)
{
	return wcsncmp(pStr1, pStr2, zCount);
}

//======================================================================
//	t_StrNCmpICase	�iUnicode Simple Loose Match �Łj
//
//	_strncmp�A_strnicmp �n�֐��̃e���v���[�g	(2)
//======================================================================
template<typename T_CHAR, BOOL B_CASE>
inline int t_StrNCmpICase(const T_CHAR* pStr1, const T_CHAR* pStr2, size_t zCount)
{
	THROW_LOGIC_ERROR("t_StrNCmpICase");
	return 0;
}
//----------------------------------------------------------------------
//	char�A�啶���������̋�ʂȂ�
//----------------------------------------------------------------------
template<>
inline int t_StrNCmpICase<char, TRUE>(LPCSTR pStr1, LPCSTR pStr2, size_t zCount)
{
	return _strnicmp(pStr1, pStr2, zCount);
}
//----------------------------------------------------------------------
//	wchar_t�A�啶���������̋�ʂȂ�
//----------------------------------------------------------------------
template<>
inline int t_StrNCmpICase<wchar_t, TRUE>(LPCWSTR pStr1, LPCWSTR pStr2, size_t zCount)
{
	return CICompareNSimple(pStr1, pStr2, zCount);
}
//----------------------------------------------------------------------
//	char�A�啶���������̋�ʂ���
//----------------------------------------------------------------------
template<>
inline int t_StrNCmpICase<char, FALSE>(LPCSTR pStr1, LPCSTR pStr2, size_t zCount)
{
	return strncmp(pStr1, pStr2, zCount);
}
//----------------------------------------------------------------------
//	wchar_t�A�啶���������̋�ʂ���
//----------------------------------------------------------------------
template<>
inline int t_StrNCmpICase<wchar_t, FALSE>(LPCWSTR pStr1, LPCWSTR pStr2, size_t zCount)
{
	return wcsncmp(pStr1, pStr2, zCount);
}

/*
//======================================================================
//	�������ƏI������
//======================================================================
BOOL	InitCaseFolding();
void	CleanupCaseFolding();
*/

//======================================================================
//	�f�o�b�O�p
//======================================================================
#ifdef	PDEBUG
void	TestCaseConvert();
#endif

NS_PLIB_UNICODE_END
