//	XLCTextEx_1.0x	:	PLibXLL

//	XLWorkSheetFunctions.h
//
#pragma once

NS_XLL_BEGIN

//======================================================================
//	WSFCell
//	125	xlfCell
//======================================================================
#define	WSFCELL_ADDRESS		1
#define	WSFCELL_COL			2
#define	WSFCELL_COLOR		3
#define	WSFCELL_CONTENTS	4
#define	WSFCELL_FILENAME	5
#define	WSFCELL_FORMAT		6
#define	WSFCELL_PARENTHESES	7
#define	WSFCELL_PREFIX		8
#define	WSFCELL_PROTECT		9
#define	WSFCELL_ROW			10
#define	WSFCELL_TYPE		11
#define	WSFCELL_WIDTH		12

template<typename T_CHAR, typename T_XLOPER>
BOOL WSFCell(std::basic_string<T_CHAR>* pstrCell, int* piCell, int iType)
{
	T_XLOPER	xType, xRet;
	int			ir;

	xType.xltype	= xltypeStr;
	switch (iType)
	{
	case WSFCELL_ADDRESS:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\007address"));
		break;

	case WSFCELL_COL:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\003col"));
		break;

	case WSFCELL_COLOR:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\005color"));
		break;

	//case WSFCELL_CONTENTS:	//	xlretUncalced ‚ðˆø‚«‹N‚±‚·
	//	xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\010contents"));
	//	break;

	case WSFCELL_FILENAME:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\010filename"));
		break;

	case WSFCELL_FORMAT:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\006format"));
		break;

	case WSFCELL_PARENTHESES:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\013parentheses"));
		break;

	case WSFCELL_PREFIX:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\006prefix"));
		break;

	case WSFCELL_PROTECT:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\007protect"));
		break;

	case WSFCELL_ROW:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\003row"));
		break;

	//case WSFCELL_TYPE:	//	xlretUncalced ‚ðˆø‚«‹N‚±‚·
	//	xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\004type"));
	//	break;

	case WSFCELL_WIDTH:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\005width"));
		break;

	default:
		return FALSE;
		break;
	}

	ir	= t_Excel<T_XLOPER, FALSE>(xlfCell, &xRet, &xType);
	if (ir == xlretSuccess)
	{
		if (xRet.xltype == xltypeStr && xRet.val.str != NULL && *(xRet.val.str) != 0)
		{
			if (pstrCell == NULL)	return FALSE;
			pstrCell->append(xRet.val.str + 1, (size_t)*(xRet.val.str));
			return TRUE;
		}
		else if (xRet.xltype == xltypeNum)
		{
			if (piCell == NULL)	return FALSE;
			*piCell	= (int)xRet.val.num;
			return TRUE;
		}
		else if (xRet.xltype == xltypeInt)
		{
			if (piCell == NULL)	return FALSE;
			*piCell	= (int)xRet.val.w;
			return TRUE;
		}
	}
	return FALSE;
}


//======================================================================
//	WSFInfo
//	244	xlfInfo
//======================================================================
#define	WSFINFO_DIRECTORY	1
#define	WSFINFO_MEMAVAIL	2
#define	WSFINFO_MEMUSED		3
#define	WSFINFO_NUMFILE		4
#define	WSFINFO_ORIGIN		5
#define	WSFINFO_OSVERSION	6
#define	WSFINFO_RECALC		7
#define	WSFINFO_RELEASE		8
#define	WSFINFO_SYSTEM		9
#define	WSFINFO_TOTMEM		10

template<typename T_CHAR, typename T_XLOPER>
BOOL WSFInfo(std::basic_string<T_CHAR>* pstrInfo, int* piInfo, int iType)
{
	T_XLOPER	xType, xRet;
	int			ir;

	xType.xltype	= xltypeStr;
	switch (iType)
	{
	case WSFINFO_DIRECTORY:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\011directory"));
		break;

	case WSFINFO_MEMAVAIL:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\010memavail"));
		break;

	case WSFINFO_MEMUSED:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\007memused"));
		break;

	case WSFINFO_NUMFILE:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\007numfile"));
		break;

	case WSFINFO_ORIGIN:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\006origin"));
		break;

	case WSFINFO_OSVERSION:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\011osversion"));
		break;

	case WSFINFO_RECALC:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\006recalc"));
		break;

	case WSFINFO_RELEASE:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\007release"));
		break;

	case WSFINFO_SYSTEM:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\006system"));
		break;

	case WSFINFO_TOTMEM:
		xType.val.str	= (T_CHAR*)t_Str<T_CHAR>(TEXTAW("\006totmem"));
		break;

	default:
		return FALSE;
		break;
	}

	ir	= t_Excel<T_XLOPER, FALSE>(xlfInfo, &xRet, &xType);
	if (ir == xlretSuccess)
	{
		if (xRet.xltype == xltypeStr && xRet.val.str != NULL && *(xRet.val.str) != 0)
		{
			if (pstrInfo == NULL)	return FALSE;
			pstrInfo->append(xRet.val.str + 1, (size_t)*(xRet.val.str));
			return TRUE;
		}
		else if (xRet.xltype == xltypeNum)
		{
			if (piInfo == NULL)	return FALSE;
			*piInfo	= (int)xRet.val.num;
			return TRUE;
		}
		else if (xRet.xltype == xltypeInt)
		{
			if (piInfo == NULL)	return FALSE;
			*piInfo	= (int)xRet.val.w;
			return TRUE;
		}
	}
	return FALSE;
}

NS_XLL_END
