//	XLCTextEx_1.0x	:	PLib

//	PDebug.h
//
#pragma once

#ifndef NS_DEBUG
#define NS_DEBUG	Debug
#define NS_PLIB_DEBUG_BEGIN	namespace NS_PLIB {	namespace NS_DEBUG {
#define NS_PLIB_DEBUG_END	}}
#endif

NS_PLIB_DEBUG_BEGIN

//======================================================================
//	デバッグ用用のユーティリティ
//======================================================================
//----------------------------------------------------------------------
//	AppendNumToString
//----------------------------------------------------------------------
template<typename T_CHAR, typename T_NUM>
bool AppendNumToString(std::basic_string<T_CHAR>* pString, const T_CHAR* pFormat, T_NUM tNum)
{
	const size_t	zBuf	= 64;
	T_CHAR			Buf[zBuf];

	if (pString == NULL || pFormat == NULL)	return false;

	if (!t_Sprintf_1<T_NUM>(Buf, zBuf, pFormat, tNum))	return false;
	pString->append(Buf);
	return true;
}


//======================================================================
//	PCDebugInstancePool	（デバッグ用）
//
//	特定のインスタンス用のメモリを確保、破棄するためのクラス。
//	このクラス内では例外の処理を行わない。利用する側で行うこと。
//======================================================================
#define	PCINSTANCEPOOL_BLOCKNUM_DEFAULT		32
#define	PCINSTANCEPOOL_BLOCKNUM_LOWERLIMIT	1

template<class T_CLASS, size_t Z_INC = PCINSTANCEPOOL_BLOCKNUM_DEFAULT>
class PCDebugInstancePool
{
public:
	typedef	T_CLASS*								T_PCLASS;
	typedef	std::list<T_PCLASS>						T_MEMORYBLOCKLIST;
	typedef	typename T_MEMORYBLOCKLIST::iterator	ITR_MEMORYBLOCKLIST;
	typedef	std::set<T_PCLASS>						T_INSTANCESET;
	typedef	typename T_INSTANCESET::iterator		ITR_INSTANCESET;
	typedef	std::pair<ITR_INSTANCESET, bool>		RV_INSTANCESET_INSERT;

	//------------------------------------------------------------
	//	データメンバ
	//------------------------------------------------------------
protected:
	T_MEMORYBLOCKLIST	ciBlockList;		//	取得したメモリブロックのポインタを記録する。
	T_INSTANCESET		ciUsable;			//	利用可能なインスタンス用メモリのポインタを格納する。
	T_INSTANCESET		ciInUse;			//	使用中のインスタンス用メモリのポインタを格納する。

	//------------------------------------------------------------
	//	PCDebugInstancePool::AllocateBlock
	//------------------------------------------------------------
	void AllocateBlock()
	{
		T_PCLASS	p;
		size_t		i;

		p	= new T_CLASS[Z_INC];
		ciBlockList.push_back(p);

		for (i = 0; i < Z_INC; ++i, ++p)
		{
			ciUsable.insert(p);
		}
	}

public:
	//------------------------------------------------------------
	//	PCDebugInstancePool::Clear
	//------------------------------------------------------------
	void Clear()
	{
		ITR_MEMORYBLOCKLIST	itrb;
		ITR_INSTANCESET		itri;

		ciUsable.clear();
		ciInUse.clear();

		for (itrb = ciBlockList.begin(); itrb != ciBlockList.end(); ++itrb)
		{
			delete[]	*itrb;
		}
		ciBlockList.clear();
	}

	//------------------------------------------------------------
	//	PCDebugInstancePool::Init
	//------------------------------------------------------------
	void Init()
	{
		Clear();
		AllocateBlock();
	}

	//------------------------------------------------------------
	//	PCDebugInstancePool	コンストラクタ
	//------------------------------------------------------------
	PCDebugInstancePool()
	{
		AllocateBlock();
	}

	//------------------------------------------------------------
	//	~PCDebugInstancePool	デストラクタ
	//------------------------------------------------------------
	~PCDebugInstancePool()
	{
		Clear();
	}

	//------------------------------------------------------------
	//	PCDebugInstancePool::Allocate
	//------------------------------------------------------------
	T_PCLASS Allocate()
	{
		ITR_INSTANCESET	itr;
		T_PCLASS		pmem;

		if (ciUsable.empty())
		{
			AllocateBlock();
		}
		itr	= ciUsable.begin();
		pmem	= *itr;
		ciUsable.erase(itr);
		ciInUse.insert(pmem);
		return pmem;
	}

	//------------------------------------------------------------
	//	PCDebugInstancePool::Deallocate
	//------------------------------------------------------------
	void Deallocate(T_PCLASS pMemory)
	{
		if (ciInUse.erase(pMemory))
		{
			ciUsable.insert(pMemory);
		}
	}
};

//======================================================================
//	std::basic_string 用の Debug ユーティリティ
//======================================================================
//----------------------------------------------------------------------
//	AppendCharToString
//----------------------------------------------------------------------
#ifdef	PDEBUG
template<typename T_CHAR>
bool AppendCharToString(std::basic_string<T_CHAR>* pString, T_CHAR tChar)
{
	if (pString == NULL)	return false;
	if (PLib::t_IsCntrl<T_CHAR>(tChar))
	{
		PLib::AppendNumToString<T_CHAR, UINT>(pString, t_Str<T_CHAR>("(%02X)", L"(%04X)"), (UINT)tChar);
	}
	else
	{
		pString->append(1, tChar);
	}
}

#else
template<typename T_CHAR>
bool AppendCharToString(std::basic_string<T_CHAR>* pString, T_CHAR tChar)
{
	return false
}
#endif

//----------------------------------------------------------------------
//	AppendCodepointToString
//----------------------------------------------------------------------
bool	AppendCodepointToString(std::wstring* pString, T_UCP cpSrc);


//======================================================================
//	Profile 用
//======================================================================
//----------------------------------------------------------------------
//	PCTickCounter
//----------------------------------------------------------------------
class PCTickCounter
{
#ifdef	PDEBUG

private:
	DWORD		dwStart;
	DWORD		dwStop;
	DWORD		dwTotal;
	T_STRING_U	strDesc;

public:
	PCTickCounter()	: dwStart(0), dwStop(0), dwTotal(0)	{}

	void	Reset()			{ dwStart = 0; dwStop = 0; dwTotal = 0; }
	void	Start()			{ dwStart = GetTickCount(); dwStop = dwStart; }
	void	Stop()			{ dwStop = GetTickCount(); dwTotal += (dwStop - dwStart); }
	DWORD	GetInterval()	{ return (dwStop - dwStart); }
	DWORD	GetTotal()		{ return dwTotal; }

	void	SetDesc(T_PCSTR_U pszDesc)	{ strDesc.assign(pszDesc); }
	void	GetTotal(T_STRING_U* pstrBuf, T_PCSTR_U pszFmt)
	{
		pstrBuf->append(strDesc);
		PLib::Debug::AppendNumToString<T_CHAR_U, DWORD>(pstrBuf, pszFmt, GetTotal());
	}

#else
public:
	void	Reset()			{}
	void	Start()			{}
	void	Stop()			{}
	DWORD	GetInterval()	{ return 0; }
	DWORD	GetTotal()		{ return 0; }

	void	SetDesc(T_PCSTR_U pszDesc)	{}
	void	GetTotal(T_STRING_U* pstrBuf, T_PCSTR_U pszFmt)	{}
#endif
};

//----------------------------------------------------------------------
//	PCTickCounters
//----------------------------------------------------------------------
class PCTickCounters
{
#ifdef	PDEBUG

private:
	typedef	std::vector<PCTickCounter*>	CCOUNTERARRAY;
	typedef	CCOUNTERARRAY::size_type	SIZET_COUNTERARRAY;
	CCOUNTERARRAY					ciCounters;
	PCDebugInstancePool<PCTickCounter>	ciIPCounter;

public:
	PCTickCounters()	{}
	~PCTickCounters()	{ ciCounters.clear(); ciIPCounter.Clear(); }

	size_t	Size()	{ return ciCounters.size(); }

	void Reset()
	{
		SIZET_COUNTERARRAY	i;

		for (i = 0; i < ciCounters.size(); ++i)
		{
			(ciCounters.at(i))->Reset();
		}
	}

	void Reset(UINT i)
	{
		try
		{
			(ciCounters.at((SIZET_COUNTERARRAY)i))->Reset();
		}
		catch (...)
		{
		}
		return ;
	}

	void Start(UINT i)
	{
		PCTickCounter*	pc;

		while (ciCounters.size() < i + 1)
		{
			pc	= ciIPCounter.Allocate();
			ciCounters.push_back(pc);
		}

		try
		{
			(ciCounters.at((SIZET_COUNTERARRAY)i))->Start();
		}
		catch (...)
		{
		}
		return ;
	}

	void Stop(UINT i)
	{
		try
		{
			(ciCounters.at((SIZET_COUNTERARRAY)i))->Stop();
		}
		catch (...)
		{
			return ;
		}
	}

	DWORD GetInterval(UINT i)
	{
		try
		{
			return (ciCounters.at((SIZET_COUNTERARRAY)i))->GetInterval();
		}
		catch (...)
		{
			return 0;
		}
	}

	DWORD GetTotal(UINT i)
	{
		try
		{
			return (ciCounters.at((SIZET_COUNTERARRAY)i))->GetTotal();
		}
		catch (...)
		{
			return 0;
		}
	}

	void SetDesc(UINT i, T_PCSTR_U pszDesc)
	{
		PCTickCounter*	pc;

		while (ciCounters.size() < i + 1)
		{
			pc	= ciIPCounter.Allocate();
			ciCounters.push_back(pc);
		}

		try
		{
			return (ciCounters.at((SIZET_COUNTERARRAY)i))->SetDesc(pszDesc);
		}
		catch (...)
		{
		}
	}

	void GetTotal(T_STRING_U* pstrBuf, T_PCSTR_U pszFmt)
	{
		SIZET_COUNTERARRAY	i;

		for (i = 0; i < ciCounters.size(); ++i)
		{
			(ciCounters.at(i))->GetTotal(pstrBuf, pszFmt);
			pstrBuf->append(TQU("\r\n"));
		}
	}

#else
	typedef	std::vector<PCTickCounter*>	CCOUNTERARRAY;
	typedef	CCOUNTERARRAY::size_type	SIZET_COUNTERARRAY;

	size_t	Size()								{ return 0; }
	void	Reset()								{}
	void	Reset(SIZET_COUNTERARRAY i)			{}
	void	Start(SIZET_COUNTERARRAY i)			{}
	void	Stop(SIZET_COUNTERARRAY i)			{}
	DWORD	GetInterval(SIZET_COUNTERARRAY i)	{ return 0; }
	DWORD	GetTotal(SIZET_COUNTERARRAY i)		{ return 0; }

	void	SetDesc(UINT i, T_PCSTR_U pszDesc)	{}
#endif
};

//======================================================================
//	Profile
//======================================================================
size_t	Profiler_Size();
void	Profiler_Reset();
void	Profiler_Reset(UINT i);
void	Profiler_Start(UINT i);
void	Profiler_Stop(UINT i);
DWORD	Profiler_GetInterval(UINT i);
DWORD	Profiler_GetTotal(UINT i);

void	Profiler_SetDesc(UINT i, T_PCSTR_U pszDesc);
void	Profiler_GetTotal(T_STRING_U* pstrBuf, T_PCSTR_U pszFmt);

#ifdef	PDEBUG
#define	PROFILER_RESET_ALL	PLib::Debug::Profiler_Reset()
#else
#define	PROFILER_RESET_ALL
#endif

#ifdef	PDEBUG
#define	PROFILER_RESET(i)	PLib::Debug::Profiler_Reset((UINT)i)
#else
#define	PROFILER_RESET(i)
#endif

#ifdef	PDEBUG
#define	PROFILER_START(i)	PLib::Debug::Profiler_Start((UINT)i)
#else
#define	PROFILER_START(i)
#endif

#ifdef	PDEBUG
#define	PROFILER_STOP(i)	PLib::Debug::Profiler_Stop((UINT)i)
#else
#define	PROFILER_STOP(i)
#endif

#ifdef	PDEBUG
#define	PROFILER_SETDESC(i, ps)	PLib::Debug::Profiler_SetDesc((UINT)i, (T_PCSTR_U)ps)
#else
#define	PROFILER_SETDESC(i)
#endif

#ifdef	PDEBUG
#define	PROFILER_GETTOTAL(ps, pf)	PLib::Debug::Profiler_GetTotal((T_STRING_U*)ps, (T_PCSTR_U)pf)
#else
#define	PROFILER_GETTOTAL(ps, pf)
#endif

//======================================================================
//	デバッグ用のログ
//======================================================================
#ifdef	PDEBUG

void	ClearLogA(int i = 0);
void	ClearLogW(int i = 0);

void	LogA(LPCSTR pStr, int i = 0);
void	LogW(LPCWSTR pStr, int i = 0);

void	GetLogA(std::string* pBuf, int i = 0);
void	GetLogW(std::wstring* pBuf, int i = 0);

#endif

//----------------------------------------------------------------------
//	ClearLog
//----------------------------------------------------------------------
template<typename T_CHAR>
inline void ClearLog(int i = 0)
{
}
#ifdef	PDEBUG
template<>
inline void ClearLog<char>(int i)
{
	ClearLogA(i);
}
template<>
inline void ClearLog<wchar_t>(int i)
{
	ClearLogW(i);
}
#endif

//----------------------------------------------------------------------
//	Log
//----------------------------------------------------------------------
template<typename T_CHAR>
inline void Log(const T_CHAR* pStr, int i = 0)
{
	return;
}
#ifdef	PDEBUG
template<>
inline void Log<char>(LPCSTR pStr, int i)
{
	LogA(pStr, i);
}
template<>
inline void Log<wchar_t>(LPCWSTR pStr, int i)
{
	LogW(pStr, i);
}
#endif

//----------------------------------------------------------------------
//	GetLog
//----------------------------------------------------------------------
template<typename T_CHAR>
inline void GetLog(std::basic_string<T_CHAR>* pBuf, int i = 0)
{
	return;
}
#ifdef	PDEBUG
template<>
inline void GetLog<char>(std::string* pBuf, int i)
{
	GetLogA(pBuf, i);
}
template<>
inline void GetLog<wchar_t>(std::wstring* pBuf, int i)
{
	GetLogW(pBuf, i);
}
#endif

//======================================================================
//	初期化と終了処理
//======================================================================
void			Init();
void			Cleanup();

NS_PLIB_DEBUG_END
