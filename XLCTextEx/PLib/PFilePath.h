//	XLCTextEx_1.0x	:	PLib

//	PFilePath.h
//
#pragma once

NS_PLIB_BEGIN

#define	IS_PATH_SEPARATOR(c)	\
	(((c) == t_Char<T_CHAR>('/', L'/')) || ((c) == t_Char<T_CHAR>('\\', L'\\')))


//======================================================================
//	SplitPath
//	パスからファイル名を取り出す。
//======================================================================
//----------------------------------------------------------------------
//	t_SplitPath
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL t_SplitPath(const T_CHAR** ppDir, size_t* pzDir,
				 const T_CHAR** ppFile, size_t* pzFile,
				 const T_CHAR* pPath, size_t zPath)
{
	typedef	const T_CHAR*	T_PCSTR;

	T_PCSTR	pb, pc, pe;

	if (ppDir == NULL || pzDir == NULL || ppFile == NULL || pzFile == NULL ||
		pPath == NULL || zPath < 1)	return FALSE;

	if (!NS_PLIB::Trim<T_CHAR>(&pb, &pe, pPath, pPath + zPath) || pb == NULL)	goto ERROR_HANDLING;
	pc	= pe - 1;
	while (!(pc < pb))
	{
		//	区切り文字が見つかった場合
		if (IS_PATH_SEPARATOR(*pc) || *pc == t_Char<T_CHAR>(TEXTAW(':')))
		{
			//	パスの最後が区切り文字の場合は、全体がディレクトリパスである。
			if (pc == pe)
			{
				*ppDir	= pb;
				*pzDir	= (size_t)(pe - pb);
				*ppFile	= NULL;
				*pzFile	= 0;
				return TRUE;
			}
			//	それ以外の場合
			else
			{
				*ppDir	= pb;
				*pzDir	= (size_t)(pc - pb + 1);
				*ppFile	= pc + 1;
				*pzFile	= (size_t)(pe - pc - 1);
				return TRUE;
			}
		}
		--pc;
	}

	//	区切り文字が見つからなかった場合は、全体をファイル名とする。
	*ppDir	= NULL;
	*pzDir	= 0;
	*ppFile	= pb;
	*pzFile	= (size_t)(pe - pb);
	return TRUE;

ERROR_HANDLING:
	*ppDir	= NULL;
	*pzDir	= 0;
	*ppFile	= NULL;
	*pzFile	= 0;
	return FALSE;
}


//----------------------------------------------------------------------
//	SplitPath
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL SplitPath(const T_CHAR** ppDir, size_t* pzDir,
					  const T_CHAR** ppFile, size_t* pzFile,
					  const T_CHAR* pPath, size_t zPath)
{
	throw std::logic_error("SplitPath");
	return FALSE;
}
template<>
inline BOOL SplitPath<char>(LPCSTR* ppDir, size_t* pzDir, LPCSTR* ppFile, size_t* pzFile,
							LPCSTR pPath, size_t zPath)
{
	return t_SplitPath<char>(ppDir, pzDir, ppFile, pzFile, pPath, zPath);
}
template<>
inline BOOL SplitPath<wchar_t>(LPCWSTR* ppDir, size_t* pzDir, LPCWSTR* ppFile, size_t* pzFile,
							   LPCWSTR pPath, size_t zPath)
{
	return t_SplitPath<wchar_t>(ppDir, pzDir, ppFile, pzFile, pPath, zPath);
}


//======================================================================
//	GetFileNameFromPath
//	パスからファイル名を取り出す。
//======================================================================
//----------------------------------------------------------------------
//	GetFileNameFromPath
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL GetFileNameFromPath(const T_CHAR** ppFile, size_t* pzFile,
								const T_CHAR* pPath, size_t zPath)
{
	throw std::logic_error("GetFileNameFromPath");
	return FALSE;
}
template<>
inline BOOL GetFileNameFromPath<char>(LPCSTR* ppFile, size_t* pzFile,
									  LPCSTR pPath, size_t zPath)
{
	LPCSTR	pDir;
	size_t	zDir;

	return t_SplitPath<char>(&pDir, &zDir, ppFile, pzFile, pPath, zPath);
}
template<>
inline BOOL GetFileNameFromPath<wchar_t>(LPCWSTR* ppFile, size_t* pzFile,
										 LPCWSTR pPath, size_t zPath)
{
	LPCWSTR	pDir;
	size_t	zDir;

	return t_SplitPath<wchar_t>(&pDir, &zDir, ppFile, pzFile, pPath, zPath);
}


//======================================================================
//	GetDirectoryPath	(1)
//	パスからディレクトリ名を取り出す。
//======================================================================
template<typename T_CHAR>
inline BOOL GetDirectoryPath(const T_CHAR** ppDir, size_t* pzDir,
							 const T_CHAR* pPath, size_t zPath)
{
	throw std::logic_error("GetDirectoryPath");
	return FALSE;
}
template<>
inline BOOL GetDirectoryPath<char>(LPCSTR* ppDir, size_t* pzDir,
								   LPCSTR pPath, size_t zPath)
{
	LPCSTR	pFile;
	size_t	zFile;

	return t_SplitPath<char>(ppDir, pzDir, &pFile, &zFile, pPath, zPath);
}
template<>
inline BOOL GetDirectoryPath<wchar_t>(LPCWSTR* ppDir, size_t* pzDir,
									  LPCWSTR pPath, size_t zPath)
{
	LPCWSTR	pFile;
	size_t	zFile;

	return t_SplitPath<wchar_t>(ppDir, pzDir, &pFile, &zFile, pPath, zPath);
}


//======================================================================
//	GetDirectoryPath	(2)
//	パスからディレクトリ名を取り出す。（std::basic_string 版）
//======================================================================
template<typename T_CHAR>
inline BOOL GetDirectoryPath(std::basic_string<T_CHAR>* pstrDirectory,
							 std::basic_string<T_CHAR>* pstrPath)
{
	const T_CHAR*	pd;
	size_t			zd;

	if (pstrDirectory == NULL || pstrPath == NULL)	return false;
	if (!GetDirectoryPath<T_CHAR>(&pd, &zd, pstrPath->c_str(), pstrPath->size()))	return false;
	pstrDirectory->append(pd, zd);
	return true;
}

/*
//======================================================================
//	ResolvePath
//	パスをフォルダ名、ファイル名に分解する。
//	指定されたパスが絶対パスとみなせる場合は *pbAbsPath に TRUE がセットされる。
//======================================================================
//----------------------------------------------------------------------
//	ResolvePath
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL ResolvePath(NS_PLIB::PCPStrList<T_CHAR>* pPathElements, BOOL* pbAbsPath,
				 const T_CHAR* pPath, size_t zPath)
{
	typedef	const T_CHAR*	T_PCSTR;

	T_PCSTR	pc, pt, pb, pe;

	if (pPathElements == NULL || pbAbsPath == NULL || pPath == NULL || zPath < 1)
		return FALSE;

	if (!NS_PLIB::Trim<T_CHAR>(&pb, &pe, pPath, pPath + zPath) || pb == NULL)	return FALSE;
	pc	= pb;

	//	ドライブ名から始まっていたら、その部分を格納しておく。
	if (zPath > 1)
	{
		if (NS_PLIB::t_IsAlpha<T_CHAR>(*pc) && *(pc + 1) == t_Char<T_CHAR>(':', L':'))
		{
			pPathElements->Append(pc, 2);
			pc += 2;
		}
	}

	//	/ か \ で始まっている場合は絶対パスとみなす。
	if (IS_PATH_SEPARATOR(*pc))
	{
		*pbAbsPath = TRUE;
	}
	else
	{
		*pbAbsPath = FALSE;
	}

	while (pc < pe)
	{
		pt	= pc;
		while (pc < pe && !IS_PATH_SEPARATOR(*pc))	++pc;
		if (pc < pe)	++pc;
		pPathElements->Append(pt, (size_t)(pc - pt));
	}
	return TRUE;
}
*/

//======================================================================
//	IsAbsolutePath
//======================================================================
template<typename T_CHAR>
BOOL IsAbsolutePath(const T_CHAR* pPath, size_t zPath)
{
	if (pPath == NULL || zPath < 1)	return FALSE;

	if (IS_PATH_SEPARATOR(*pPath))	return TRUE;
	if (zPath > 2)
	{
		if (NS_PLIB::t_IsAlpha<T_CHAR>(*pPath) &&
			*(pPath + 1) == t_Char<T_CHAR>(':', L':') &&
			(*(pPath + 2) == t_Char<T_CHAR>('/', L'/') || *(pPath + 2) == t_Char<T_CHAR>('\\', L'\\')))
		{
			return TRUE;
		}
	}
	return FALSE;
}


//======================================================================
//	IsDirectoryPath
//======================================================================
template<typename T_CHAR>
BOOL IsDirectoryPath(const T_CHAR* pPath, size_t zPath)
{
	if (pPath == NULL || zPath < 1)	return FALSE;

	return IS_PATH_SEPARATOR(*(pPath + zPath - 1));
}


//======================================================================
//	GetExtension
//	ファイル名から拡張子を取り出す。
//======================================================================
//----------------------------------------------------------------------
//	t_GetExtension
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL t_GetExtension(const T_CHAR** ppExtension, size_t* pzExtension,
					const T_CHAR* pFile, const T_CHAR* pEnd)
{
	typedef	const T_CHAR*	T_PCSTR;

	T_PCSTR	pc, pe;
	BOOL	bFound	= FALSE;

	if (ppExtension == NULL || pFile == NULL || !(pFile < pEnd))	return FALSE;
	pe	= pEnd;
	do
	{
		--pe;
	}
	while (!(pe < pFile) && t_IsSpace<T_CHAR>(*pe));
	if (pe < pFile)	return FALSE;

	pc	= pe;
	while (!(pc < pFile))
	{
		if (*pc == t_Char<T_CHAR>(TEXTAW('.')))
		{
			if (pc < pEnd - 1)
			{
				bFound	= TRUE;
			}
			break;
		}
		else if (IS_PATH_SEPARATOR(*pc) || *pc == t_Char<T_CHAR>(TEXTAW(':')))
		{
			break;
		}
		--pc;
	}

	if (bFound == TRUE)
	{
		*ppExtension	= pc + 1;
		*pzExtension	= pe - pc;
		return	TRUE;
	}
	*ppExtension	= pEnd;
	*pzExtension	= 0;
	return FALSE;
}

//----------------------------------------------------------------------
//	GetExtension
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL GetExtension(const T_CHAR** ppExtension, size_t* pzExtension,
						 const T_CHAR* pFile, size_t zFile)
{
	throw std::logic_error("GetExtension");
	return FALSE;
}
template<>
inline BOOL GetExtension<char>(LPCSTR* ppExtension, size_t* pzExtension,
							   LPCSTR pFile, size_t zFile)
{
	return t_GetExtension<char>(ppExtension, pzExtension, pFile, pFile + zFile);
}
template<>
inline BOOL GetExtension<wchar_t>(LPCWSTR* ppExtension, size_t* pzExtension,
								  LPCWSTR pFile, size_t zFile)
{
	return t_GetExtension<wchar_t>(ppExtension, pzExtension, pFile, pFile + zFile);
}


//======================================================================
//	CheckExtension
//	ファイル名の拡張子が、指定したグループ内にあるか調べる。
//======================================================================
//----------------------------------------------------------------------
//	t_CheckExtension
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL t_CheckExtension(const T_CHAR* pFile, size_t zFile, std::list<const T_CHAR*>* pExtensions)
{
	typedef	const T_CHAR*						T_PCSTR;
	typedef	std::list<const T_CHAR*>::iterator	ITERATOR;

	T_PCSTR		pExtension	= NULL;
	size_t		zExtension;
	ITERATOR	itr;

	if (pFile == NULL || zFile < 1 || pExtensions == NULL)	return FALSE;

	if (!GetExtension<T_CHAR>(&pExtension, &zExtension, pFile, zFile))	return FALSE;

	for (itr = pExtensions->begin(); itr != pExtensions->end(); ++itr)
	{
		if (!NS_PLIB::t_StrNCmp<T_CHAR, FALSE>(pExtension, *itr, zExtension))	return TRUE;
	}
	return FALSE;
}

//----------------------------------------------------------------------
//	CheckExtension
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL CheckExtension(const T_CHAR* pFile, size_t zFile, std::list<const T_CHAR*>* pExtensions)
{
	throw std::logic_error("CheckExtension");
	return FALSE;
}
template<>
inline BOOL CheckExtension<char>(LPCSTR pFile, size_t zFile, std::list<LPCSTR>* pExtensions)
{
	return t_CheckExtension<char>(pFile, zFile, pExtensions);
}
template<>
inline BOOL CheckExtension<wchar_t>(LPCWSTR pFile, size_t zFile, std::list<LPCWSTR>* pExtensions)
{
	return t_CheckExtension<wchar_t>(pFile, zFile, pExtensions);
}

NS_PLIB_END
