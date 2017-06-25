//	XLCTextEx_1.0x	:	PLib

//	PMemory.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	メモリを割り当てるためのクラス
//	以下のメソッドを持っていなければならない。
//
//	template<typename T>	BOOL Allocate(T** , size_t)	//	メモリが確保できない場合は FALSE を返す。
//	template<typename T>	T* Allocate(size_t)	//	メモリが確保できない場合は例外をスローする。
//	template<typename T>	void Deallocate(T*)
//======================================================================
//----------------------------------------------------------------------
//	class PCMAlloc
//	1 つのオブジェクトにメモリを割り当てるためのクラス
//----------------------------------------------------------------------
class PCMAlloc
{
public:
	template<typename T>
	BOOL Allocate(T** ppMem, size_t zCount = 1)
	{
		try
		{
			*ppMem	= new T[zCount];
		}
		CATCH_AND_RETURN_BAD_ALLOC(FALSE, "");
		return TRUE;
	}

	template<typename T>
	T* Allocate(size_t zCount = 1)
	{
		return new T[zCount];
		//	例外は利用する側で処理すること。
	}

	template<typename T>
	void Deallocate(T* pMem)
	{
		delete[]	pMem;
	}
};

//----------------------------------------------------------------------
//	class PCMAllocTemp
//	1 つのオブジェクトに一時メモリを割り当てるためのクラス
//----------------------------------------------------------------------
class PCMAllocTemp
{
public:
	template<typename T>
	BOOL Allocate(T** ppMem, size_t zCount)
	{
		*ppMem	= (T*)GetTempMemory(sizeof(T) * zCount);
		return (*ppMem != NULL);
	}

	template<typename T>
	T* Allocate(size_t zCount)
	{
		return (T*)GetTempMemory(sizeof(T) * zCount);
	}

	template<typename T>
	void Deallocate(T* pMem)
	{
		//	呼び出し側で DeallocateAllTempMemory()　呼び出すこと。
	}
};

//----------------------------------------------------------------------
//	class PCMAllocNOP
//
//	メモリの確保、解放が必要ない場合に指定するためのダミークラス。
//----------------------------------------------------------------------
class PCMAllocNOP
{
public:
	template<typename T>
	BOOL AllocateArray(T** ppMem, size_t zCount)
	{
		return TRUE;
	}

	template<typename T>
	T* AllocateArray(size_t zCount)
	{
		return NULL;
	}

	template<typename T>
	void Deallocate(T* pMem)
	{
	}
};


#define	PMEMORY_INSTANCENUM_DEFAULT		32
#define	PMEMORY_INSTANCENUM_LOWERLIMIT	1

//======================================================================
//	PCInstanceAllocator
//
//	特定のインスタンス用のメモリを確保、破棄するためのクラス。
//	このクラス内では例外の処理を行わない。利用する側で行うこと。
//======================================================================
template<class T_CLASS>
class PCInstanceAllocator
{
public:
	//------------------------------------------------------------
	//	データメンバ
	//------------------------------------------------------------

public:
	//------------------------------------------------------------
	//	PCInstanceAllocator::Clear
	//------------------------------------------------------------
	void Clear()
	{
	}

	//------------------------------------------------------------
	//	PCInstanceAllocator::Init
	//------------------------------------------------------------
	void Init()
	{
	}

	//------------------------------------------------------------
	//	PCInstanceAllocator	コンストラクタ
	//------------------------------------------------------------
	PCInstanceAllocator()
	{
	}

	//------------------------------------------------------------
	//	~PCInstanceAllocator	デストラクタ
	//------------------------------------------------------------
	~PCInstanceAllocator()
	{
	}

	//------------------------------------------------------------
	//	PCInstanceAllocator::Allocate
	//------------------------------------------------------------
	T_CLASS* Allocate(size_t zCount = 1)
	{
		return new T_CLASS[zCount];
	}

	//------------------------------------------------------------
	//	PCInstanceAllocator::Deallocate
	//------------------------------------------------------------
	void Deallocate(T_CLASS* p)
	{
		delete[]	p;
	}
};

//======================================================================
//	PCInstanceSet
//
//	特定のインスタンス用のメモリを確保、破棄するためのクラス。
//	実行中にランダムに解放する必要がある場合に使用する。
//	このクラス内では例外の処理を行わない。利用する側で行うこと。
//======================================================================
template<class T_CLASS, size_t Z_INC = PMEMORY_INSTANCENUM_DEFAULT>
class PCInstanceSet
{
public:
	typedef	T_CLASS*								T_PCLASS;
	typedef	std::set<T_PCLASS>						T_INSTANCESET;
	typedef	typename T_INSTANCESET::iterator		ITR_INSTANCESET;
	typedef	std::pair<ITR_INSTANCESET, bool>		RV_INSTANCESET_INSERT;

	typedef	void (*PF_TREAT)(T_PCLASS);	//	インスタンスの処理を行う関数のポインタ

	//------------------------------------------------------------
	//	データメンバ
	//------------------------------------------------------------
protected:
	T_INSTANCESET		ciInUse;			//	使用中のインスタンス用メモリのポインタを格納する。

	PF_TREAT			pfDeallocate;	//	メモリ解放時の処理を行う関数のポインタ

public:
	//------------------------------------------------------------
	//	SetPreDeallocateFunction
	//------------------------------------------------------------
	void SetPreDeallocateFunction(PF_TREAT pFunc)	{ pfDeallocate = pFunc; }

	//------------------------------------------------------------
	//	PCInstanceSet::Clear
	//------------------------------------------------------------
	void Clear()
	{
		ITR_INSTANCESET		itri;

		if (pfDeallocate != NULL)
		{
			for (itri = ciInUse.begin(); itri != ciInUse.end(); ++itri)
			{
				(*pfDeallocate)(*itri);
			}
		}

		for (itri = ciInUse.begin(); itri != ciInUse.end(); ++itri)
		{
			delete	*itri;
		}
		ciInUse.clear();
	}

	//------------------------------------------------------------
	//	PCInstanceSet::Init
	//------------------------------------------------------------
	void Init()
	{
		Clear();
	}

	//------------------------------------------------------------
	//	PCInstanceSet	コンストラクタ
	//------------------------------------------------------------
	PCInstanceSet()
		:	pfDeallocate(NULL)
	{
	}

	//------------------------------------------------------------
	//	~PCInstanceSet	デストラクタ
	//------------------------------------------------------------
	~PCInstanceSet()
	{
		Clear();
	}

	//------------------------------------------------------------
	//	PCInstanceSet::Allocate
	//------------------------------------------------------------
	T_PCLASS Allocate()
	{
		T_PCLASS		pi;

		pi	= new T_CLASS;
		ciInUse.insert(pi);
		return pi;
	}

	//------------------------------------------------------------
	//	PCInstanceSet::Deallocate
	//------------------------------------------------------------
	void Deallocate(T_PCLASS pi)
	{
		if (ciInUse.erase(pi))
		{
			if (pfDeallocate != NULL)	(*pfDeallocate)(pi);
			delete	pi;
		}
	}

	//------------------------------------------------------------
	//	PCInstanceSet::ForEachInUse
	//------------------------------------------------------------
	void ForEachInUse(void (*pfunc)(T_PCLASS))
	{
		ITR_INSTANCESET	itr;

		for (itr = ciInUse.begin(); itr != ciInUse.end(); ++itr)
		{
			(*pfunc)(*itr);
		}
	}

	//------------------------------------------------------------
	//	PCInstanceSet::BeginInUse, PCInstanceSet::EndInUse
	//------------------------------------------------------------
	void BeginInUse(ITR_INSTANCESET& itr)
	{
		itr	= ciInUse.begin();
	}

	BOOL EndInUse(ITR_INSTANCESET& itr)
	{
		return (itr == ciInUse.end());
	}
};


//======================================================================
//	PCInstanceList
//
//	特定のインスタンス用のメモリを確保、保持、破棄するためのクラス。
//	実行中に解放しない場合に使用する。
//	このクラス内では例外の処理を行わない。利用する側で行うこと。
//======================================================================
template<class T_CLASS>
class PCInstanceList
{
public:
	typedef	T_CLASS*								T_PCLASS;
	typedef	std::list<T_PCLASS>						T_INSTANCELIST;
	typedef	typename T_INSTANCELIST::iterator		ITR_INSTANCELIST;

	typedef	void (*PF_TREAT)(T_PCLASS);	//	インスタンスの処理を行う関数のポインタ

	//------------------------------------------------------------
	//	データメンバ
	//------------------------------------------------------------
protected:
	T_INSTANCELIST	ciInUse;		//	使用中のインスタンス用メモリのポインタを格納する。

	PF_TREAT		pfDeallocate;	//	メモリ解放時の処理を行う関数のポインタ

public:
	//------------------------------------------------------------
	//	SetPreDeallocateFunction
	//------------------------------------------------------------
	void SetPreDeallocateFunction(PF_TREAT pFunc)	{ pfDeallocate = pFunc; }

	//------------------------------------------------------------
	//	PCInstanceList::Clear
	//------------------------------------------------------------
	void Clear()
	{
		ITR_INSTANCELIST	itri;

		if (pfDeallocate != NULL)
		{
			for (itri = ciInUse.begin(); itri != ciInUse.end(); ++itri)
			{
				(*pfDeallocate)(*itri);
			}
		}

		for (itri = ciInUse.begin(); itri != ciInUse.end(); ++itri)
		{
			delete	*itri;
		}
		ciInUse.clear();
	}

	//------------------------------------------------------------
	//	PCInstanceList::Init
	//------------------------------------------------------------
	void Init()
	{
		Clear();
	}

	//------------------------------------------------------------
	//	PCInstanceList	コンストラクタ
	//------------------------------------------------------------
	PCInstanceList()
		:	pfDeallocate(NULL)
	{
	}

	//------------------------------------------------------------
	//	~PCInstanceList	デストラクタ
	//------------------------------------------------------------
	~PCInstanceList()
	{
		Clear();
	}

	//------------------------------------------------------------
	//	PCInstanceList::Allocate
	//------------------------------------------------------------
	T_PCLASS Allocate()
	{
		T_PCLASS	p;

		p	= new T_CLASS;
		ciInUse.push_back(p);
		return p;
	}

	//------------------------------------------------------------
	//	PCInstanceList::ForEachInUse
	//------------------------------------------------------------
	void ForEachInUse(void (*pfunc)(T_PCLASS))
	{
		ITR_INSTANCELIST	itr;

		for (itr = ciInUse.begin(); itr != ciInUse.end(); ++itr)
		{
			(*pfunc)(*itr);
		}
	}

	//------------------------------------------------------------
	//	PCInstanceList::BeginInUse, PCInstanceList::EndInUse
	//------------------------------------------------------------
	void BeginInUse(ITR_INSTANCELIST& itr)
	{
		itr	= ciInUse.begin();
	}

	BOOL EndInUse(ITR_INSTANCELIST& itr)
	{
		return (itr == ciInUse.end());
	}
};


//======================================================================
//	PCInstanceStack
//
//	特定のインスタンス用のメモリを確保、破棄するためのクラス。
//	実行中に FIFO で割り当てと解放を行う場合に使用する。
//	このクラス内では例外の処理を行わない。利用する側で行うこと。
//======================================================================
template<class T_CLASS, bool B_INITPUSH, size_t Z_INC>
class PCInstanceStack
{
public:
	typedef	std::list<T_CLASS*>					T_STACK;
	typedef	typename T_STACK::iterator			ITR_STACK;
	typedef typename T_STACK::reverse_iterator	RITR_STACK;

	//------------------------------------------------------------
	//	データメンバ
	//------------------------------------------------------------
protected:
	T_STACK		ciStack;			//	インスタンスのポインタのスタック
	T_STACK		ciUndoStack;		//	Undo 用のデータを格納するスタック

	ITR_STACK	itrStack;
	RITR_STACK	ritrStack;
	ITR_STACK	itrUndo;

public:
	//------------------------------------------------------------
	//	PCInstanceStack::ClearUndo
	//------------------------------------------------------------
	void ClearUndo()
	{
		ITR_STACK	itr;

		for (itr = ciUndoStack.begin(); itr != ciUndoStack.end(); ++itr)
		{
			delete	*itr;
		}
		ciUndoStack.clear();
	}

	//------------------------------------------------------------
	//	PCInstanceStack::Clear
	//------------------------------------------------------------
	void Clear()
	{
		ITR_STACK	itr;

		for (itr = ciStack.begin(); itr != ciStack.end(); ++itr)
		{
			delete	*itr;
		}
		ciStack.clear();

		ClearUndo();
	}

	//------------------------------------------------------------
	//	PCInstanceStack::Init
	//------------------------------------------------------------
	void Init()
	{
		Clear();
		if (B_INITPUSH)
		{
			PushNew();
		}
	}

	//------------------------------------------------------------
	//	PCInstanceStack	コンストラクタ
	//------------------------------------------------------------
	PCInstanceStack()
	{
		Init();
		itrStack	= ciStack.end();
		itrUndo		= ciUndoStack.end();
	}

	//------------------------------------------------------------
	//	~PCInstanceStack	デストラクタ
	//------------------------------------------------------------
	~PCInstanceStack()
	{
		Clear();
	}

	//------------------------------------------------------------
	//	Empty
	//------------------------------------------------------------
	bool Empty()	{ return ciStack.empty(); }

	//------------------------------------------------------------
	//	GetStackTop
	//------------------------------------------------------------
	T_CLASS* GetStackTop()
	{
		if (ciStack.empty())	return NULL;
		return *(ciStack.begin());
	}

	bool GetStackTop(T_CLASS** ppi)
	{
		if (ciStack.empty())
		{
			*ppi	= NULL;
			return false;
		}
		*ppi	= *(ciStack.begin());
		return true;
	}

	//------------------------------------------------------------
	//	PCInstanceStack::PushNew
	//------------------------------------------------------------
	void PushNew()
	{
		T_CLASS*	pNew;

		pNew	= new T_CLASS;
		if (!ciStack.empty())	pNew->CopyFrom(*(ciStack.begin()));
		ciStack.push_front(pNew);
		return;
	}

	//------------------------------------------------------------
	//	PCInstanceStack::PushNew
	//------------------------------------------------------------
	void PushNew(T_CLASS** ppNew)
	{
		*ppNew	= new T_CLASS;
		if (!ciStack.empty())	(*ppNew)->CopyFrom(*(ciStack.begin()));
		ciStack.push_front(*ppNew);
		return;
	}

	//------------------------------------------------------------
	//	PCInstanceStack::Pop
	//	Pop したポインタは解放せずに Undo スタックに push する。
	//------------------------------------------------------------
	void Pop(T_CLASS** ppi)
	{
		if (ciStack.empty())
		{
			*ppi	= NULL;
			return;
		}
		*ppi	= *(ciStack.begin());
		ciStack.pop_front();
		ciUndoStack.push_front(*ppi);
	}

	void Pop()
	{
		T_CLASS*	pi;
		Pop(&pi);
	}

	//------------------------------------------------------------
	//	SaveUndoValue
	//------------------------------------------------------------
	void SaveUndoValue()
	{
		T_CLASS*	pUndo;

		if (ciStack.empty())	return;

		pUndo	= new T_CLASS;
		pUndo->CopyFrom(*(ciStack.begin()));
		ciUndoStack.push_front(pUndo);
	}

	//------------------------------------------------------------
	//	PCInstanceStack::UndoPush
	//	直前の Push を取り消す。すなわち、
	//	スタック先頭の ポインタ を pop し、メモリを解放する。
	//------------------------------------------------------------
	void UndoPush()
	{
		T_CLASS*	pi;

		//	何も push されていない場合。
		if (ciStack.empty())
		{
			return;
		}

		pi	= *(ciStack.begin());
		ciStack.pop_front();
		delete	pi;
		return;
	}

	//------------------------------------------------------------
	//	PCInstanceStack::UndoPop
	//	直前の Pop を取り消す。すなわち、
	//	Undo スタックの先頭にあるポインタをスタックに push する。
	//------------------------------------------------------------
	void UndoPop()
	{
		T_CLASS*	pi;

		if (ciUndoStack.empty())	return;
		pi	= *(ciUndoStack.begin());
		ciUndoStack.pop_front();
		ciStack.push_front(pi);
	}

	//------------------------------------------------------------
	//	PCInstanceStack::UndoValue
	//	値を Undo スタック先頭のものに戻す。
	//------------------------------------------------------------
	void UndoValue()
	{
		T_CLASS*	pi;

		if (ciUndoStack.empty() || ciStack.empty())
		{
			THROWPE_LOGIC_ERROR("UndoPop: UndoStack is empty.");
		}
		pi	= *(ciUndoStack.begin());
		(*(ciStack.begin()))->CopyFrom(pi);
		ciUndoStack.pop_front();
		delete	pi;
	}

	//------------------------------------------------------------
	//	Restore
	//	最初の状態に戻す。
	//------------------------------------------------------------
	void Restore()
	{
		ClearUndo();
		if (ciStack.size() < 1)
		{
			Init();
			return;
		}
		while (ciStack.size() > 1)
		{
			UndoPush();
		}
	}

	//------------------------------------------------------------
	//	PCInstanceStack::PopAndUpdate
	//------------------------------------------------------------
	void PopAndUpdate()
	{
		T_CLASS	*p1, *p2;

		if (ciStack.size() <= 1)	return;

		p1	= *(ciStack.begin());
		ciStack.pop_front();

		p2	= *(ciStack.begin());
		ciStack.pop_front();
		delete	p2;

		ciStack.push_front(p1);
	}

	//------------------------------------------------------------
	//	繰り返し処理用	(1-1)
	//------------------------------------------------------------
	void Begin()	{ itrStack = ciStack.begin(); }
	bool End()		{ return (itrStack == ciStack.end()); }
	void Next()		{ if (!End())	++itrStack; }
	bool GetCurrent(T_CLASS** ppi)
	{
		if (itrStack != ciStack.end())
		{
			*ppi	= *itrStack;
			return true;
		}
		*ppi	= NULL;
		return false;
	}

	//------------------------------------------------------------
	//	繰り返し処理用	(1-2)
	//------------------------------------------------------------
	void RBegin()	{ ritrStack = ciStack.rbegin(); }
	bool REnd()		{ return (ritrStack == ciStack.rend()); }
	void RNext()	{ if (!REnd())	++ritrStack; }
	bool RGetCurrent(T_CLASS** ppi)
	{
		if (ritrStack != ciStack.rend())
		{
			*ppi	= *ritrStack;
			return true;
		}
		*ppi	= NULL;
		return false;
	}

	//------------------------------------------------------------
	//	繰り返し処理用	(2)
	//------------------------------------------------------------
	void BeginUndo()	{ itrUndo = ciUndoStack.begin(); }
	bool EndUndo()		{ return (itrUndo == ciUndoStack.end()); }
	void NextUndo()		{ if (!EndUndo())	++itrUndo; }
	bool GetCurrentUndo(T_CLASS** ppi)
	{
		if (itrUndo != ciUndoStack.end())
		{
			*ppi	= *itrUndo;
			return true;
		}
		*ppi	= NULL;
		return false;
	}
};

NS_PLIB_END

