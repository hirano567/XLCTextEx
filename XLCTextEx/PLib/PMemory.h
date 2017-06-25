//	XLCTextEx_1.0x	:	PLib

//	PMemory.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	�����������蓖�Ă邽�߂̃N���X
//	�ȉ��̃��\�b�h�������Ă��Ȃ���΂Ȃ�Ȃ��B
//
//	template<typename T>	BOOL Allocate(T** , size_t)	//	���������m�ۂł��Ȃ��ꍇ�� FALSE ��Ԃ��B
//	template<typename T>	T* Allocate(size_t)	//	���������m�ۂł��Ȃ��ꍇ�͗�O���X���[����B
//	template<typename T>	void Deallocate(T*)
//======================================================================
//----------------------------------------------------------------------
//	class PCMAlloc
//	1 �̃I�u�W�F�N�g�Ƀ����������蓖�Ă邽�߂̃N���X
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
		//	��O�͗��p���鑤�ŏ������邱�ƁB
	}

	template<typename T>
	void Deallocate(T* pMem)
	{
		delete[]	pMem;
	}
};

//----------------------------------------------------------------------
//	class PCMAllocTemp
//	1 �̃I�u�W�F�N�g�Ɉꎞ�����������蓖�Ă邽�߂̃N���X
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
		//	�Ăяo������ DeallocateAllTempMemory()�@�Ăяo�����ƁB
	}
};

//----------------------------------------------------------------------
//	class PCMAllocNOP
//
//	�������̊m�ہA������K�v�Ȃ��ꍇ�Ɏw�肷�邽�߂̃_�~�[�N���X�B
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
//	����̃C���X�^���X�p�̃��������m�ہA�j�����邽�߂̃N���X�B
//	���̃N���X���ł͗�O�̏������s��Ȃ��B���p���鑤�ōs�����ƁB
//======================================================================
template<class T_CLASS>
class PCInstanceAllocator
{
public:
	//------------------------------------------------------------
	//	�f�[�^�����o
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
	//	PCInstanceAllocator	�R���X�g���N�^
	//------------------------------------------------------------
	PCInstanceAllocator()
	{
	}

	//------------------------------------------------------------
	//	~PCInstanceAllocator	�f�X�g���N�^
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
//	����̃C���X�^���X�p�̃��������m�ہA�j�����邽�߂̃N���X�B
//	���s���Ƀ����_���ɉ������K�v������ꍇ�Ɏg�p����B
//	���̃N���X���ł͗�O�̏������s��Ȃ��B���p���鑤�ōs�����ƁB
//======================================================================
template<class T_CLASS, size_t Z_INC = PMEMORY_INSTANCENUM_DEFAULT>
class PCInstanceSet
{
public:
	typedef	T_CLASS*								T_PCLASS;
	typedef	std::set<T_PCLASS>						T_INSTANCESET;
	typedef	typename T_INSTANCESET::iterator		ITR_INSTANCESET;
	typedef	std::pair<ITR_INSTANCESET, bool>		RV_INSTANCESET_INSERT;

	typedef	void (*PF_TREAT)(T_PCLASS);	//	�C���X�^���X�̏������s���֐��̃|�C���^

	//------------------------------------------------------------
	//	�f�[�^�����o
	//------------------------------------------------------------
protected:
	T_INSTANCESET		ciInUse;			//	�g�p���̃C���X�^���X�p�������̃|�C���^���i�[����B

	PF_TREAT			pfDeallocate;	//	������������̏������s���֐��̃|�C���^

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
	//	PCInstanceSet	�R���X�g���N�^
	//------------------------------------------------------------
	PCInstanceSet()
		:	pfDeallocate(NULL)
	{
	}

	//------------------------------------------------------------
	//	~PCInstanceSet	�f�X�g���N�^
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
//	����̃C���X�^���X�p�̃��������m�ہA�ێ��A�j�����邽�߂̃N���X�B
//	���s���ɉ�����Ȃ��ꍇ�Ɏg�p����B
//	���̃N���X���ł͗�O�̏������s��Ȃ��B���p���鑤�ōs�����ƁB
//======================================================================
template<class T_CLASS>
class PCInstanceList
{
public:
	typedef	T_CLASS*								T_PCLASS;
	typedef	std::list<T_PCLASS>						T_INSTANCELIST;
	typedef	typename T_INSTANCELIST::iterator		ITR_INSTANCELIST;

	typedef	void (*PF_TREAT)(T_PCLASS);	//	�C���X�^���X�̏������s���֐��̃|�C���^

	//------------------------------------------------------------
	//	�f�[�^�����o
	//------------------------------------------------------------
protected:
	T_INSTANCELIST	ciInUse;		//	�g�p���̃C���X�^���X�p�������̃|�C���^���i�[����B

	PF_TREAT		pfDeallocate;	//	������������̏������s���֐��̃|�C���^

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
	//	PCInstanceList	�R���X�g���N�^
	//------------------------------------------------------------
	PCInstanceList()
		:	pfDeallocate(NULL)
	{
	}

	//------------------------------------------------------------
	//	~PCInstanceList	�f�X�g���N�^
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
//	����̃C���X�^���X�p�̃��������m�ہA�j�����邽�߂̃N���X�B
//	���s���� FIFO �Ŋ��蓖�ĂƉ�����s���ꍇ�Ɏg�p����B
//	���̃N���X���ł͗�O�̏������s��Ȃ��B���p���鑤�ōs�����ƁB
//======================================================================
template<class T_CLASS, bool B_INITPUSH, size_t Z_INC>
class PCInstanceStack
{
public:
	typedef	std::list<T_CLASS*>					T_STACK;
	typedef	typename T_STACK::iterator			ITR_STACK;
	typedef typename T_STACK::reverse_iterator	RITR_STACK;

	//------------------------------------------------------------
	//	�f�[�^�����o
	//------------------------------------------------------------
protected:
	T_STACK		ciStack;			//	�C���X�^���X�̃|�C���^�̃X�^�b�N
	T_STACK		ciUndoStack;		//	Undo �p�̃f�[�^���i�[����X�^�b�N

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
	//	PCInstanceStack	�R���X�g���N�^
	//------------------------------------------------------------
	PCInstanceStack()
	{
		Init();
		itrStack	= ciStack.end();
		itrUndo		= ciUndoStack.end();
	}

	//------------------------------------------------------------
	//	~PCInstanceStack	�f�X�g���N�^
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
	//	Pop �����|�C���^�͉�������� Undo �X�^�b�N�� push ����B
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
	//	���O�� Push ���������B���Ȃ킿�A
	//	�X�^�b�N�擪�� �|�C���^ �� pop ���A���������������B
	//------------------------------------------------------------
	void UndoPush()
	{
		T_CLASS*	pi;

		//	���� push ����Ă��Ȃ��ꍇ�B
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
	//	���O�� Pop ���������B���Ȃ킿�A
	//	Undo �X�^�b�N�̐擪�ɂ���|�C���^���X�^�b�N�� push ����B
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
	//	�l�� Undo �X�^�b�N�擪�̂��̂ɖ߂��B
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
	//	�ŏ��̏�Ԃɖ߂��B
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
	//	�J��Ԃ������p	(1-1)
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
	//	�J��Ԃ������p	(1-2)
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
	//	�J��Ԃ������p	(2)
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

