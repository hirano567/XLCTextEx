//	XLCTextEx_1.0x	:	PLibUCD

//	PLibUCD:	PBMPTable.h
//
#pragma once

NS_PLIB_UNICODE_BEGIN

//======================================================================
//	BMPTable の型と宣言
//======================================================================
#define	PUCD_BMPTABLE_MASK_GENERALCATEGORY	0x3F
#define	PUCD_BMPTABLE_FLAG_ALPHABETIC		6
#define	PUCD_BMPTABLE_FLAG_UPPERCASE		7
#define	PUCD_BMPTABLE_FLAG_LOWERCASE		8
#define	PUCD_BMPTABLE_FLAG_ICASE_S			9
#define	PUCD_BMPTABLE_FLAG_ICASE_F			10
#define	PUCD_BMPTABLE_FLAG_DECOMP			11
#define	PUCD_BMPTABLE_FLAG_NONSTARTER		12	
#define	PUCD_BMPTABLE_FLAG_IKANAWIDTH		13
#define	PUCD_BMPTABLE_FLAG_IKANATYPE		14
#define	PUCD_BMPTABLE_FLAG_IKANACASE		15


typedef	unsigned short		T_BMPINFO;
#define	BMPTABLE_FLAGS_ALL	((unsigned short)(short)-1)

extern T_BMPINFO	BMPTable[];
const UINT			nBMPTable	= 0x10000;

//======================================================================
//	BMPTable 操作用のマクロと関数
//======================================================================
#define	BMPTABLE_SETFLAG(f, b)	((f) |= (1 << (b)))

#define	PUCD_IN_BMP(u)	(((u) | 0xFFFF) == 0xFFFF)

#define	BMPTABLE_ELEMENT(i)			PLib::Unicode::BMPTable[i]
#define	PUCD_BMPTABLE_NOFLAG(i, f)	(PUCD_IN_BMP(i) && ((f) == 0))


//
//	フラグがセットされていれば true を返す。（フラグ指定）
//
#define	PUCD_BMPTABLE_IS_ALPHABETIC_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_ALPHABETIC)) != 0))
#define	PUCD_BMPTABLE_IS_UPPERCASE_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_UPPERCASE)) != 0))
#define	PUCD_BMPTABLE_IS_LOWERCASE_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_LOWERCASE)) != 0))
#define	PUCD_BMPTABLE_IS_ICASE_S_SET2(i, f)		(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_ICASE_S)) != 0))
#define	PUCD_BMPTABLE_IS_ICASE_F_SET2(i, f)		(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_ICASE_F)) != 0))
#define	PUCD_BMPTABLE_IS_DECOMP_SET2(i, f)		(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_DECOMP)) != 0))
#define	PUCD_BMPTABLE_IS_NONSTARTER_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_NONSTARTER)) != 0))
#define	PUCD_BMPTABLE_IS_IKANAWIDTH_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_IKANAWIDTH)) != 0))
#define	PUCD_BMPTABLE_IS_IKANATYPE_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_IKANATYPE)) != 0))
#define	PUCD_BMPTABLE_IS_IKANACASE_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_IKANACASE)) != 0))


//
//	フラグがセットされていれば true を返す。
//
#define	PUCD_BMPTABLE_IS_ALPHABETIC_SET(i)	PUCD_BMPTABLE_IS_ALPHABETIC_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_IS_UPPERCASE_SET(i)	PUCD_BMPTABLE_IS_UPPERCASE_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_IS_LOWERCASE_SET(i)	PUCD_BMPTABLE_IS_LOWERCASE_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_IS_ICASE_S_SET(i)		PUCD_BMPTABLE_IS_ICASE_S_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_IS_ICASE_F_SET(i)		PUCD_BMPTABLE_IS_ICASE_F_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_IS_DECOMP_SET(i)		PUCD_BMPTABLE_IS_DECOMP_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_IS_NONSTARTER_SET(i)	PUCD_BMPTABLE_IS_NONSTARTER_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_IS_IKANAWIDTH_SET(i)	PUCD_BMPTABLE_IS_IKANAWIDTH_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_IS_IKANATYPE_SET(i)	PUCD_BMPTABLE_IS_IKANATYPE_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_IS_IKANACASE_SET(i)	PUCD_BMPTABLE_IS_IKANACASE_SET2(i, PLib::Unicode::BMPTable[i])

//
//	フラグがセットされていれば true を返す。（引数チェックなし）
//
#define	PUCD_BMPTABLE_IS_ALPHABETIC_SET_NC(i)	((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_ALPHABETIC)) != 0)
#define	PUCD_BMPTABLE_IS_UPPERCASE_SET_NC(i)	((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_UPPERCASE)) != 0)
#define	PUCD_BMPTABLE_IS_LOWERCASE_SET_NC(i)	((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_LOWERCASE)) != 0)
#define	PUCD_BMPTABLE_IS_ICASE_S_SET_NC(i)		((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_ICASE_S)) != 0)
#define	PUCD_BMPTABLE_IS_ICASE_F_SET_NC(i)		((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_ICASE_F)) != 0)
#define	PUCD_BMPTABLE_IS_DECOMP_SET_NC(i)		((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_DECOMP)) != 0)
#define	PUCD_BMPTABLE_IS_NONSTARTER_SET_NC(i)	((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_NONSTARTER)) != 0)
#define	PUCD_BMPTABLE_IS_IKANAWIDTH_SET_NC(i)	((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_IKANAWIDTH)) != 0)
#define	PUCD_BMPTABLE_IS_IKANATYPE_SET_NC(i)	((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_IKANATYPE)) != 0)
#define	PUCD_BMPTABLE_IS_IKANACASE_SET_NC(i)	((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_IKANACASE)) != 0)


//
//	フラグがセットされていなければ true を返す。（フラグ指定）
//
#define	PUCD_BMPTABLE_NOT_ALPHABETIC_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_ALPHABETIC)) == 0))
#define	PUCD_BMPTABLE_NOT_UPPERCASE_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_UPPERCASE)) == 0))
#define	PUCD_BMPTABLE_NOT_LOWERCASE_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_LOWERCASE)) == 0))
#define	PUCD_BMPTABLE_NOT_ICASE_S_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_ICASE_S)) == 0))
#define	PUCD_BMPTABLE_NOT_ICASE_F_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_ICASE_F)) == 0))
#define	PUCD_BMPTABLE_NOT_DECOMP_SET2(i, f)		(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_DECOMP)) == 0))
#define	PUCD_BMPTABLE_NOT_NONSTARTER_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_NONSTARTER)) == 0))
#define	PUCD_BMPTABLE_NOT_IKANAWIDTH_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_IKANAWIDTH)) == 0))
#define	PUCD_BMPTABLE_NOT_IKANATYPE_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_IKANATYPE)) == 0))
#define	PUCD_BMPTABLE_NOT_IKANACASE_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_IKANACASE)) == 0))

//
//	フラグがセットされていなければ true を返す。
//
#define	PUCD_BMPTABLE_NOT_ALPHABETIC_SET(i)	PUCD_BMPTABLE_NOT_ALPHABETIC_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_NOT_UPPERCASE_SET(i)	PUCD_BMPTABLE_NOT_UPPERCASE_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_NOT_LOWERCASE_SET(i)	PUCD_BMPTABLE_NOT_LOWERCASE_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_NOT_ICASE_S_SET(i)	PUCD_BMPTABLE_NOT_ICASE_S_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_NOT_ICASE_F_SET(i)	PUCD_BMPTABLE_NOT_ICASE_F_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_NOT_DECOMP_SET(i)		PUCD_BMPTABLE_NOT_DECOMP_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_NOT_NONSTARTER_SET(i)	PUCD_BMPTABLE_NOT_NONSTARTER_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_NOT_IKANAWIDTH_SET(i)	PUCD_BMPTABLE_NOT_IKANAWIDTH_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_NOT_IKANATYPE_SET(i)	PUCD_BMPTABLE_NOT_IKANATYPE_SET2(i, PLib::Unicode::BMPTable[i])
#define	PUCD_BMPTABLE_NOT_IKANACASE_SET(i)	PUCD_BMPTABLE_NOT_IKANACASE_SET2(i, PLib::Unicode::BMPTable[i])

//
//	フラグがセットされていなければ true を返す。（引数チェックなし）
//
#define	PUCD_BMPTABLE_NOT_ALPHABETIC_SET_NC(i)	((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_ALPHABETIC)) == 0)
#define	PUCD_BMPTABLE_NOT_UPPERCASE_SET_NC(i)	((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_UPPERCASE)) == 0)
#define	PUCD_BMPTABLE_NOT_LOWERCASE_SET_NC(i)	((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_LOWERCASE)) == 0)
#define	PUCD_BMPTABLE_NOT_ICASE_S_SET_NC(i)		((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_ICASE_S)) == 0)
#define	PUCD_BMPTABLE_NOT_ICASE_F_SET_NC(i)		((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_ICASE_F)) == 0)
#define	PUCD_BMPTABLE_NOT_DECOMP_SET_NC(i)		((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_DECOMP)) == 0)
#define	PUCD_BMPTABLE_NOT_NONSTARTER_SET_NC(i)	((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_NONSTARTER)) == 0)
#define	PUCD_BMPTABLE_NOT_IKANAWIDTH_SET_NC(i)	((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_IKANAWIDTH)) == 0)
#define	PUCD_BMPTABLE_NOT_IKANATYPE_SET_NC(i)	((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_IKANATYPE)) == 0)
#define	PUCD_BMPTABLE_NOT_IKANACASE_SET_NC(i)	((PLib::Unicode::BMPTable[i] & (1 << PUCD_BMPTABLE_FLAG_IKANATYPE)) == 0)

//----------------------------------------------------------------------
//	GetInfoFromBMPTable	(1)
//----------------------------------------------------------------------
inline bool GetInfoFromBMPTable(T_BMPINFO* pInfo, T_UCP cpSrc)
{
	if (PUCD_IN_BMP(cpSrc))
	{
		*pInfo	= PLib::Unicode::BMPTable[cpSrc];
		return true;
	}
	return false;
}

//----------------------------------------------------------------------
//	GetInfoFromBMPTable	(2)
//----------------------------------------------------------------------
inline T_BMPINFO GetInfoFromBMPTable(T_UCP cpSrc)
{
	if (PUCD_IN_BMP(cpSrc))
	{
		return PLib::Unicode::BMPTable[cpSrc];
	}
	return BMPTABLE_FLAGS_ALL;
}

//----------------------------------------------------------------------
//	GetGeneralCategoryFromBMPTable
//----------------------------------------------------------------------
inline bool GetGeneralCategoryFromBMPTable(int* piGC, T_UCP cpSrc)
{
	if (PUCD_IN_BMP(cpSrc))
	{
		*piGC	= (PLib::Unicode::BMPTable[cpSrc] & PUCD_BMPTABLE_MASK_GENERALCATEGORY);
		return true;
	}
	return false;
}

NS_PLIB_UNICODE_END
