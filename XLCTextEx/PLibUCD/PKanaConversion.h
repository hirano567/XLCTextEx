//	XLCTextEx_1.0x	:	PLibUCD

//	PLibUCD:	PKanaConversion.h
//
#pragma once

NS_PLIB_UNICODE_BEGIN

//----------------------------------------------------------------------
//	struct	SCASEFOLDMAP
//----------------------------------------------------------------------
struct	SCSTRMAP
{
	UINT			uiCpSrc;
	UINT*			pCpDst;
	int				nCpDst;
	T_PCSTR_U	pszDst;

	bool LessThan(UINT uiOther)	{ return (uiCpSrc < uiOther); }
	bool Match(UINT uiOther)	{ return (uiCpSrc == uiOther); }
};
typedef	SCSTRMAP	*PSCSTRMAP;

//extern SCSTRMAP	siCStrMapKanaType[];
//extern int		nCStrMapKanaType;

extern SCSTRMAP	siCStrMapKanaWidth[];
extern int		nCStrMapKanaWidth;

//======================================================================
//	KanaTypeFolding
//======================================================================
bool	KanaTypeFolding(UINT* puiDst, UINT uiSrc);
UINT	KanaTypeFolding(UINT uiSrc);

bool	KanaTypeFolding(UCPSTRING* puisDst, UCPSTRING* puisSrc);
bool	KanaTypeFolding(UCPSTRING* puisDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE);
bool	KanaTypeFolding(UCPSTRING* puisDst, T_PCSTR_U pszSrc);
bool	KanaTypeFolding(T_STRING_U* pstrDst, UCPSTRING* puisSrc);

bool	KanaTypeFolding(T_STRING_U* pstrDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE);
bool	KanaTypeFolding(T_STRING_U* pstrDst, T_PCSTR_U pSrc);

//======================================================================
//	KanaWidthFolding
//======================================================================
bool	KanaWidthFolding(UINT* puiDst, UINT uiSrc);
UINT	KanaWidthFolding(UINT uiSrc);

bool	KanaWidthFolding(UCPSTRING* puisDst, UCPSTRING* puisSrc);
bool	KanaWidthFolding(UCPSTRING* puisDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE);
bool	KanaWidthFolding(UCPSTRING* puisDst, T_PCSTR_U pszSrc);
bool	KanaWidthFolding(T_STRING_U* pstrDst, UCPSTRING* puisSrc);

bool	KanaWidthFolding(T_STRING_U* pstrDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE);
bool	KanaWidthFolding(T_STRING_U* pstrDst, T_PCSTR_U pSrc);

//======================================================================
//	デバッグ用
//======================================================================
#ifdef	PDEBUG
void	TestKanaConversion();
#endif
NS_PLIB_UNICODE_END
