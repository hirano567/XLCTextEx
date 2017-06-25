//	XLCTextEx_1.0x	:	PLibUCD

//	PLibUCD:	PFoldTable.h
//
#pragma once

NS_PLIB_UNICODE_BEGIN
/*

//======================================================================
//	FoldTable の型と宣言
//======================================================================

#define	PUCD_BMPTABLE_FLAG_ICASE_S		0
#define	PUCD_BMPTABLE_FLAG_ICASE_F		1
#define	PUCD_BMPTABLE_FLAG_DECOMP		2
#define	PUCD_BMPTABLE_FLAG_NONSTARTER	3	
#define	PUCD_BMPTABLE_FLAG_IKANAWIDTH	4
#define	PUCD_BMPTABLE_FLAG_IKANATYPE	5
#define	PUCD_BMPTABLE_FLAG_IKANACASE	6

//typedef	unsigned char	T_BMPINFO;
//#define	BMPTABLE_FLAGS_ALL	((unsigned char)(char)-1)

typedef	unsigned short		T_BMPINFO;
#define	BMPTABLE_FLAGS_ALL	((unsigned short)(short)-1)

extern T_BMPINFO	FoldTable[];
const UINT			nFoldTable	= 0x10000;

//======================================================================
//	FoldTable 操作用のマクロと関数
//======================================================================
#define	BMPTABLE_SETFLAG(f, b)	((f) |= (1 << (b)))

#define	PUCD_IN_BMP(u)	(((u) | 0xFFFF) == 0xFFFF)

#define	BMPTABLE_ELEMENT(i)				PLib::Unicode::FoldTable[i]
#define	PUCD_BMPTABLE_NOFLAG(i, f)		(PUCD_IN_BMP(i) && ((f) == 0))

//
//	フラグがセットされていれば true を返す。
//
#define	PUCD_BMPTABLE_IS_ICASE_S_SET2(i, f)		(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_ICASE_S)) != 0))
#define	PUCD_BMPTABLE_IS_ICASE_F_SET2(i, f)		(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_ICASE_F)) != 0))
#define	PUCD_BMPTABLE_IS_DECOMP_SET2(i, f)		(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_DECOMP)) != 0))
#define	PUCD_BMPTABLE_IS_NONSTARTER_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_NONSTARTER)) != 0))
#define	PUCD_BMPTABLE_IS_IKANAWIDTH_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_IKANAWIDTH)) != 0))
#define	PUCD_BMPTABLE_IS_IKANATYPE(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_IKANATYPE)) != 0))
#define	PUCD_BMPTABLE_IS_IKANACASE(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_IKANACASE)) != 0))

//
//	フラグがセットされていれば true を返す。	（簡略版）
//
#define	PUCD_BMPTABLE_IS_ICASE_S_SET(i)		PUCD_BMPTABLE_IS_ICASE_S_SET2(i, PLib::Unicode::FoldTable[i])
#define	PUCD_BMPTABLE_IS_ICASE_F_SET(i)		PUCD_BMPTABLE_IS_ICASE_F_SET2(i, PLib::Unicode::FoldTable[i])
#define	PUCD_BMPTABLE_IS_DECOMP_SET(i)		PUCD_BMPTABLE_IS_DECOMP_SET2(i, PLib::Unicode::FoldTable[i])
#define	PUCD_BMPTABLE_IS_NONSTARTER_SET(i)	PUCD_BMPTABLE_IS_NONSTARTER_SET2(i, PLib::Unicode::FoldTable[i])
#define	PUCD_BMPTABLE_IS_IKANAWIDTH_SET(i)	PUCD_BMPTABLE_IS_IKANAWIDTH_SET2(i, PLib::Unicode::FoldTable[i])
#define	PUCD_BMPTABLE_IS_IKANATYPE_S(i)	PUCD_BMPTABLE_IS_IKANATYPE(i, PLib::Unicode::FoldTable[i])
#define	PUCD_BMPTABLE_IS_IKANACASE_S(i)	PUCD_BMPTABLE_IS_IKANACASE(i, PLib::Unicode::FoldTable[i])

//
//	フラグがセットされていれば true を返す。（引数チェックなし）
//
#define	PUCD_BMPTABLE_IS_ICASE_S_SET3(i, f)		(((f) & (1 << PUCD_BMPTABLE_FLAG_ICASE_S)) != 0)
#define	PUCD_BMPTABLE_IS_ICASE_F_SET3(i, f)		(((f) & (1 << PUCD_BMPTABLE_FLAG_ICASE_F)) != 0)
#define	PUCD_BMPTABLE_IS_DECOMP_SET3(i, f)		(((f) & (1 << PUCD_BMPTABLE_FLAG_DECOMP)) != 0)
#define	PUCD_BMPTABLE_IS_NONSTARTER_SET3(i, f)	(((f) & (1 << PUCD_BMPTABLE_FLAG_NONSTARTER)) != 0)
#define	PUCD_BMPTABLE_IS_IKANAWIDTH_SET3(i, f)	(((f) & (1 << PUCD_BMPTABLE_FLAG_IKANAWIDTH)) != 0)
#define	PUCD_BMPTABLE_IS_IKANATYPE_NC(i, f)		(((f) & (1 << PUCD_BMPTABLE_FLAG_IKANATYPE)) != 0)
#define	PUCD_BMPTABLE_IS_IKANACASE_NC(i, f)		(((f) & (1 << PUCD_BMPTABLE_FLAG_IKANACASE)) != 0)

//
//	フラグがセットされていなければ true を返す。
//
#define	PUCD_BMPTABLE_NOT_ICASE_S_SET2(i, f)		(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_ICASE_S)) == 0))
#define	PUCD_BMPTABLE_NOT_ICASE_F_SET2(i, f)		(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_ICASE_F)) == 0))
#define	PUCD_BMPTABLE_NOT_DECOMP_SET2(i, f)		(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_DECOMP)) == 0))
#define	PUCD_BMPTABLE_NOT_NONSTARTER_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_NONSTARTER)) == 0))
#define	PUCD_BMPTABLE_NOT_IKANAWIDTH_SET2(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_IKANAWIDTH)) == 0))
#define	PUCD_BMPTABLE_NOT_IKANATYPE(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_IKANATYPE)) == 0))
#define	PUCD_BMPTABLE_NOT_IKANACASE(i, f)	(PUCD_IN_BMP(i) && (((f) & (1 << PUCD_BMPTABLE_FLAG_IKANACASE)) == 0))

//
//	フラグがセットされていなければ true を返す。	（簡略版）
//
#define	PUCD_BMPTABLE_NOT_ICASE_S_SET(i)		PUCD_BMPTABLE_NOT_ICASE_S_SET2(i, PLib::Unicode::FoldTable[i])
#define	PUCD_BMPTABLE_NOT_ICASE_F_SET(i)		PUCD_BMPTABLE_NOT_ICASE_F_SET2(i, PLib::Unicode::FoldTable[i])
#define	PUCD_BMPTABLE_NOT_DECOMP_SET(i)		PUCD_BMPTABLE_NOT_DECOMP_SET2(i, PLib::Unicode::FoldTable[i])
#define	PUCD_BMPTABLE_NOT_NONSTARTER_SET(i)	PUCD_BMPTABLE_NOT_NONSTARTER_SET2(i, PLib::Unicode::FoldTable[i])
#define	PUCD_BMPTABLE_NOT_IKANAWIDTH_SET(i)	PUCD_BMPTABLE_NOT_IKANAWIDTH_SET2(i, PLib::Unicode::FoldTable[i])
#define	PUCD_BMPTABLE_NOT_IKANATYPE_S(i)	PUCD_BMPTABLE_NOT_IKANATYPE(i, PLib::Unicode::FoldTable[i])
#define	PUCD_BMPTABLE_NOT_IKANACASE_S(i)	PUCD_BMPTABLE_NOT_IKANACASE(i, PLib::Unicode::FoldTable[i])

//
//	フラグがセットされていなければ true を返す。（引数チェックなし）
//
#define	PUCD_BMPTABLE_NOT_ICASE_S_SET3(i, f)		(((f) & (1 << PUCD_BMPTABLE_FLAG_ICASE_S)) == 0)
#define	PUCD_BMPTABLE_NOT_ICASE_F_SET3(i, f)		(((f) & (1 << PUCD_BMPTABLE_FLAG_ICASE_F)) == 0)
#define	PUCD_BMPTABLE_NOT_DECOMP_SET3(i, f)		(((f) & (1 << PUCD_BMPTABLE_FLAG_DECOMP)) == 0)
#define	PUCD_BMPTABLE_NOT_NONSTARTER_SET3(i, f)	(((f) & (1 << PUCD_BMPTABLE_FLAG_NONSTARTER)) == 0)
#define	PUCD_BMPTABLE_NOT_IKANAWIDTH_SET3(i, f)	(((f) & (1 << PUCD_BMPTABLE_FLAG_IKANAWIDTH)) == 0)
#define	PUCD_BMPTABLE_NOT_IKANATYPE_NC(i, f)	(((f) & (1 << PUCD_BMPTABLE_FLAG_IKANATYPE)) == 0)
#define	PUCD_BMPTABLE_NOT_IKANACASE_NC(i, f)	(((f) & (1 << PUCD_BMPTABLE_FLAG_IKANACASE)) == 0)

//----------------------------------------------------------------------
//	GetFlagsFromFoldTable
//----------------------------------------------------------------------
inline T_BMPINFO GetFlagsFromFoldTable(T_UCP cpSrc)
{
	return (PUCD_IN_BMP(cpSrc) ? PLib::Unicode::FoldTable[cpSrc] : BMPTABLE_FLAGS_ALL);
}
//----------------------------------------------------------------------
//	NoDecomposition
//----------------------------------------------------------------------
inline bool NoDecomposition(T_UCP cpSrc)
{
	return (PUCD_BMPTABLE_NOT_DECOMP_SET2(cpSrc, PLib::Unicode::FoldTable[cpSrc]));
}

//----------------------------------------------------------------------
//	IsNonStarter
//----------------------------------------------------------------------
inline bool	IsNonStarterBMP(T_UCP cpSrc)
{
	return
}

//----------------------------------------------------------------------
//	IsStarter
//----------------------------------------------------------------------
inline bool IsStarter(T_UCP cpSrc)
{
	return (PUCD_IN_BMP(cpSrc) && PUCD_BMPTABLE_NOT_NONSTARTER_SET3(cpSrc, PLib::Unicode::FoldTable[cpSrc]));
}
*/

NS_PLIB_UNICODE_END
