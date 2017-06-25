//	XLCTextEx_1.0x	:	PLibUCD

//	PStrToNum.h
//
#pragma once

NS_PLIB_UNICODE_BEGIN

#define	PUCD_STRTONUM_ZERO			0
#define	PUCD_STRTONUM_ONE			1
#define	PUCD_STRTONUM_TWO			2
#define	PUCD_STRTONUM_THREE			3
#define	PUCD_STRTONUM_FOUR			4
#define	PUCD_STRTONUM_FIVE			5
#define	PUCD_STRTONUM_SIX			6
#define	PUCD_STRTONUM_SEVEN			7
#define	PUCD_STRTONUM_EIGHT			8
#define	PUCD_STRTONUM_NINE			9
//#define	PUCD_STRTONUM_HEX_A			10
//#define	PUCD_STRTONUM_HEX_B			11
//#define	PUCD_STRTONUM_HEX_C			12
//#define	PUCD_STRTONUM_HEX_D			13
//#define	PUCD_STRTONUM_HEX_E			14
//#define	PUCD_STRTONUM_HEX_F			15
#define	PUCD_STRTONUM_PLUS			16
#define	PUCD_STRTONUM_MINUS			17
#define	PUCD_STRTONUM_POINT			18
#define	PUCD_STRTONUM_EXPONENTIAL	19
#define	PUCD_STRTONUM_COMMA			20
#define	PUCD_STRTONUM_PERCENT		21

//#define	PUCD_STRTONUM_IS_DEC(i)	(((i) >= 0) && ((i) <= 9))
#define	PUCD_STRTONUM_IS_DEC(i)	(((i) | 0x0F) == 0x0F)

//======================================================================
//	ŠÖ”‚ÌéŒ¾
//======================================================================
bool	StrToIntDecUsgn(int* piVal, T_PCSTR_U* ppszSrc);
//bool	StrToIntDecSgn(int* piVal, T_PCSTR_U* ppszSrc);
//bool	StrToIntDecSgn(T_VAL* pVal, T_PCSTR_U* ppszSrc, int* piSign);
//bool	StrToIntDecFmt(T_VAL* pVal, T_PCSTR_U* ppszSrc, int* piSign);

bool	StrToDouble(double* pdValue, T_PCSTR_U* ppszSrc);

NS_PLIB_UNICODE_END
