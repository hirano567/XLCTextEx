//	XLCTextEx_1.0x	:	PLibXLL

//	XLInstanceManager.h
//
#pragma once

NS_XLL_BEGIN

//======================================================================
//	インスタンスの管理
//======================================================================
//----------------------------------------------------------------------
//	class PCXLInstanceManager
//----------------------------------------------------------------------
template<typename T_CHAR, class C_OBJ>
class PCXLInstanceManager
{
private:
	struct SRegistrationId
	{
		DWORD	dwSheetId;
		int		iNum;
	};
	typedef	SRegistrationId	SREGID;

	class CompareId
	{
	public:
		bool operator()(const SREGID* pa, const SREGID* pb)	const
		{
			if (pa->dwSheetId < pb->dwSheetId)	return true;
			if (pa->dwSheetId > pb->dwSheetId)	return false;
			if (pa->iNum < pb->iNum)			return true;
			return false;
		}
	};

	typedef	T_CHAR*									T_PSTR;
	typedef	const T_CHAR*							T_PCSTR;
	typedef	std::basic_string<T_CHAR>				T_STRING,	*T_PSTRING;

	typedef	std::map<SREGID*, C_OBJ*, CompareId>	CIDMAP;
	typedef	typename CIDMAP::iterator				ITR_IDMAP;
	typedef	std::pair<SREGID*, C_OBJ*>				PAIR_IDMAP;

	//------------------------------------------------------------
	//	データメンバ
	//------------------------------------------------------------
	PLib::PCInstanceSet<SREGID, 4>	ciIPId;
	PLib::PCInstanceSet<C_OBJ, 4>	ciIPObject;

	CIDMAP	ciIdMap;

public:
	//------------------------------------------------------------
	//	Clear
	//------------------------------------------------------------
	void Clear()
	{
		ciIdMap.clear();
		ciIPId.Clear();
		ciIPObject.Clear();
	}

	//------------------------------------------------------------
	//	コンストラクタ
	//------------------------------------------------------------
	PCXLInstanceManager()
	{
	}

	//------------------------------------------------------------
	//	デストラクタ
	//------------------------------------------------------------
	~PCXLInstanceManager()
	{
		Clear();
	}

	//------------------------------------------------------------
	//	NumToId
	//------------------------------------------------------------
	void NumToId(SREGID* psiId, int iNum)
	{
		DWORD	dwId;

		if (!XLL::GetActiveSheetId(&dwId))	dwId	= 0;
		psiId->dwSheetId	= dwId;
		psiId->iNum			= iNum;
	}

	//------------------------------------------------------------
	//	Find	(1)
	//------------------------------------------------------------
	BOOL Find(ITR_IDMAP& itr, int iNum)
	{
		SREGID	siId;

		if (ciIdMap.empty())	return FALSE;

		NumToId(&siId, iNum);
		itr	= ciIdMap.find(&siId);
		if (itr != ciIdMap.end())	return TRUE;
		return FALSE;
	}

	//------------------------------------------------------------
	//	Find	(2)
	//------------------------------------------------------------
	C_OBJ* Find(int iNum)
	{
		ITR_IDMAP	itr;

		if (Find(itr, iNum))
		{
			return itr->second;
		}
		return NULL;
	}

	//------------------------------------------------------------
	//	Create
	//------------------------------------------------------------
	C_OBJ* Create(int iNum)
	{
		SREGID*	pId;
		C_OBJ*	pObj;

		pObj = Find(iNum);
		if (pObj == NULL)
		{
			pId		= ciIPId.Allocate();
			NumToId(pId, iNum);
			pObj	= ciIPObject.Allocate();
			ciIdMap.insert(PAIR_IDMAP(pId, pObj));
		}
		return pObj;
	}

	//------------------------------------------------------------
	//	Delete
	//------------------------------------------------------------
	BOOL Delete(ITR_IDMAP& itr)
	{
		if (itr != ciIdMap.end())
		{
			ciIPId.Deallocate(itr->first);
			ciIPObject.Deallocate(itr->second);
			ciIdMap.erase(itr);
			return TRUE;
		}
		return FALSE;
	}

	BOOL Delete(int iNum)
	{
		ITR_IDMAP	itr;

		if (Find(itr, iNum))
		{
			return Delete(itr);
		}
		return FALSE;
	}

	//------------------------------------------------------------
	//	DeleteGroup
	//------------------------------------------------------------
	BOOL DeleteGroup(DWORD dwSheet)
	{
		ITR_IDMAP	itr, itr_d;

		itr	= ciIdMap.begin();
		while (itr != ciIdMap.end())
		{
			itr_d	= itr;
			++itr;
			if (itr_d->first->dwSheetId == dwSheet)	Delete(itr_d);
		}
		return TRUE;
	}
};

NS_XLL_END
