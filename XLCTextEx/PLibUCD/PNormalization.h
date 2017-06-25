//	XLCTextEx_1.0x	:	PLibUCD

//	PLibUCD:	PNormalization.h
//
#pragma once

NS_PLIB_UNICODE_BEGIN

//======================================================================
//	Nonstarter の情報
//======================================================================
#define	PUCD_CCC_NOT_REORDERED			0
#define	PUCD_CCC_OVERLAY				1
#define	PUCD_CCC_NUKTA					7
#define	PUCD_CCC_KANA_VOICING			8
#define	PUCD_CCC_VIRAMA					9
#define	PUCD_CCC_CCC10					10
//#define	PUCD_CCC_	199
#define	PUCD_CCC_ATTACHED_BELOW_LEFT	200
#define	PUCD_CCC_ATTACHED_BELOW			202
//#define	PUCD_CCC_	204
//#define	PUCD_CCC_	208
//#define	PUCD_CCC_	210
//#define	PUCD_CCC_	212
#define	PUCD_CCC_ATTACHED_ABOVE			214
#define	PUCD_CCC_ATTACHED_ABOVE_RIGHT	216
#define	PUCD_CCC_BELOW_LEFT				218
#define	PUCD_CCC_BELOW					220
#define	PUCD_CCC_BELOW_RIGHT			222
#define	PUCD_CCC_LEFT					224
#define	PUCD_CCC_RIGHT					226
#define	PUCD_CCC_ABOVE_LEFT				228
#define	PUCD_CCC_ABOVE					230
#define	PUCD_CCC_ABOVE_RIGHT			232
#define	PUCD_CCC_DOUBLE_BELOW			233
#define	PUCD_CCC_DOUBLE_ABOVE			234
#define	PUCD_CCC_IOTA_SUBSCRIPT			240

struct	PSCANONICALCOMBININGCLASS
{
	T_UCP	cpSrc;
	int		iClass;

	bool LessThan(UINT cpOther)	{ return (cpSrc < cpOther); }
	bool Match(UINT cpOther)	{ return (cpSrc == cpOther); }
};

extern PSCANONICALCOMBININGCLASS	siCanonicalCombiningClass[];
extern int	nCanonicalCombiningClass;

//======================================================================
//	Decomposition の情報
//======================================================================
#define	PUCD_DECOMPOSITION_TYPE_CANONICAL	0
#define	PUCD_DECOMPOSITION_TYPE_FONT		1
#define	PUCD_DECOMPOSITION_TYPE_NOBREAK		2
#define	PUCD_DECOMPOSITION_TYPE_INITIAL		3
#define	PUCD_DECOMPOSITION_TYPE_MEDIAL		4
#define	PUCD_DECOMPOSITION_TYPE_FINAL		5
#define	PUCD_DECOMPOSITION_TYPE_ISOLATED	6
#define	PUCD_DECOMPOSITION_TYPE_CIRCLE		7
#define	PUCD_DECOMPOSITION_TYPE_SUPER		8
#define	PUCD_DECOMPOSITION_TYPE_SUB			9
#define	PUCD_DECOMPOSITION_TYPE_VERTICAL	10
#define	PUCD_DECOMPOSITION_TYPE_WIDE		11
#define	PUCD_DECOMPOSITION_TYPE_NARROW		12
#define	PUCD_DECOMPOSITION_TYPE_SMALL		13
#define	PUCD_DECOMPOSITION_TYPE_SQUARE		14
#define	PUCD_DECOMPOSITION_TYPE_FRACTION	15
#define	PUCD_DECOMPOSITION_TYPE_COMPAT		16

struct	PSDECOMPOSITION
{
	T_UCP		cpSrc;
	T_UCP*		pcpDecomposition;
	int			nDecomposition;
	T_PCSTR_U	pszDecomposition;
	T_UCP*		pcpStarter;
	int			nStarter;
	T_PCSTR_U	pszStarter;
	int			iType;

	bool LessThan(UINT cpOther)	{ return (cpSrc < cpOther); }
	bool Match(UINT cpOther)	{ return (cpSrc == cpOther); }
};

extern PSDECOMPOSITION	siDecomposition[];
extern int	nDecomposition;

//======================================================================
//	GetDecomposition
//======================================================================
bool	GetDecomposition(PSDECOMPOSITION** ppDecmp, T_UCP cpSrc);

bool	GetDecomposition(UCPSTRING* puisDst, const T_UCP cpSrc);
bool	GetDecomposition(UCPSTRING* puisDst, ITR_UCPSTRING& itrB, ITR_UCPSTRING& itrE);
bool	GetDecomposition(UCPSTRING* puisDst, UCPSTRING* puisSrc);
bool	GetDecomposition(UCPSTRING* puisDst, T_PCSTR_U pszSrcB, T_PCSTR_U pszSrcE);
bool	GetDecomposition(UCPSTRING* puisDst, T_PCSTR_U pszSrc);

bool	GetDecomposition2(PSDECOMPOSITION** ppDecmp, T_UCP cpSrc);

//======================================================================
//	Canonical Combining Class 関係
//======================================================================
int		GetCanonicalCombiningClass(T_UCP cpSrc);

//----------------------------------------------------------------------
//	IsStarter
//----------------------------------------------------------------------
inline bool IsStarter(T_UCP cpSrc)
{
	return (GetCanonicalCombiningClass(cpSrc) == 0);
}

//----------------------------------------------------------------------
//	IsNonStarter
//----------------------------------------------------------------------
inline bool IsNonStarter(T_UCP cpSrc)
{
	return (GetCanonicalCombiningClass(cpSrc) != 0);
}

//======================================================================
//	GetStarter
//======================================================================
bool	GetStarter(T_UCP** ppcpStarter, int* pnStarter, T_UCP cpSrc);
bool	GetStarter(UCPSTRING* pucsDst, T_UCP cpSrc);
bool	GetStarter(UCPSTRING* pucsDst, UCPSTRING* pucsSrc);
bool	GetStarter(T_STRING_U* pstrBuf, const T_UCP cpSrc);


//======================================================================
//	デバッグ用
//======================================================================
#ifdef	PDEBUG
void	TestNormalization();
#endif
NS_PLIB_UNICODE_END
