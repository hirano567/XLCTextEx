//	XLCTextEx_1.0x	:	XLCTextEx

//	XLCGrep.h
//
#pragma once

#define	XLCGREP_ERROR				-1
#define	XLCGREP_ERROR_BAD_ALLOC		-2
#define	XLCGREP_ERROR_SYNTAX_ERROR	-3

//======================================================================
//	class PCGrepOptions
//======================================================================
class PCGrepOptions
{
private:
	bool		bRowNumber;
	bool		bSheetName;
	bool		bNonMatching;
	T_STRING_U	strMatchingDelimiter;
	T_STRING_U	strOutputDelimiter;

public:
	bool	IsRowNumber()			{ return bRowNumber; }
	bool	IsSheetName()			{ return bSheetName; }
	bool	IsNonMatching()			{ return bNonMatching; }

	void	SetRowNumber()			{ bRowNumber = true; }
	void	SetSheetName()			{ bSheetName = true; }
	void	SetNonMatching()		{ bNonMatching = true; }

	void		SetMatchingDelimiter()					{ strMatchingDelimiter.clear(); }
	void		SetMatchingDelimiter(T_UCP cp)			{ PLib::Unicode::ConvertFromCodepoint(&strMatchingDelimiter, cp); }
	void		SetMatchingDelimiter(T_PCSTR_U psz)		{ strMatchingDelimiter.assign(psz); }
	T_STRING_U*	GetMatchingDelimiter()					{ return &strMatchingDelimiter; }

	void		SetOutputDelimiter()					{ strOutputDelimiter.assign(1, (T_UCP)0x09); }
	void		SetOutputDelimiter(T_UCP c)				{ PLib::Unicode::ConvertFromCodepoint(&strOutputDelimiter, c); }
	void		SetOutputDelimiter(T_PCSTR_U psz)		{ strOutputDelimiter.assign(psz); }
	T_STRING_U*	GetOutputDelimiter()					{ return &strOutputDelimiter; }

	void	UnsetRowNumber()			{ bRowNumber = false; }
	void	UnsetSheetName()			{ bSheetName = false; }
	void	UnsetNonMatching()			{ bNonMatching = false; }
	void	UnsetMatchingDelimiter()	{ strMatchingDelimiter.clear(); }
	void	UnsetOutputDelimiter()		{ strOutputDelimiter.assign(1, TQU('\t')); }

	void	Reset()
	{
		UnsetRowNumber();
		UnsetSheetName();
		UnsetNonMatching();
		UnsetMatchingDelimiter();
		UnsetOutputDelimiter();
	}

	PCGrepOptions()
	{
		Reset();
	}

	void	Set(T_PCSTR_U pStr, size_t zStr);

#ifdef	PDEBUG
	void	Debug(T_STRING_U* pstrDebug);
#endif
};


//======================================================================
//	エクスポートする関数
//======================================================================
int	XLCGrep4(LPCSTR pPattern, LPCSTR pOpt1, LPCSTR pOpt2);
int	XLCGrep12(LPCWSTR pPattern, LPCWSTR pOpt1, LPCWSTR pOpt2);
