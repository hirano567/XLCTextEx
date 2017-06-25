//	XLCTextEx_1.0x	:	PLib

//	PGClass.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	PCStrBuffer	:	文字列用のバッファを管理するクラス
//======================================================================
#define	BUFFER_SIZE_DEFAULT			256
#define	BUFFER_SIZE_MAX_DEFAULT		INT_MAX
#define	BUFFER_SIZE_MIN_DEFAULT		16

template<
	typename	T_DATA,
	class		C_MALLOC		= NS_PLIB::PCMAlloc,
	size_t		BUFFER_SIZE			= BUFFER_SIZE_DEFAULT,
	size_t		BUFFER_SIZE_MAX		= BUFFER_SIZE_MAX_DEFAULT,
	size_t		BUFFER_SIZE_MIN		= BUFFER_SIZE_MIN_DEFAULT
>
class PCStrBuffer
{
protected:
	typedef	T_DATA*			T_PDATA;
	typedef	const T_DATA*	T_PCDATA;

	T_PDATA	pBuffer;
	size_t	zBuffer;

	C_MALLOC	ciMAlloc;

public:
	//------------------------------------------------------------
	//	Init
	//------------------------------------------------------------
	BOOL Init()
	{
		ciMAlloc.Deallocate<T_DATA>(pBuffer);

		zBuffer	= BUFFER_SIZE;
		if (ciMAlloc.Allocate<T_DATA>(&pBuffer, zBuffer))
		{
			*pBuffer	= NULL;
			return TRUE;
		}
		return FALSE;
	}

	//------------------------------------------------------------
	//	PCStrBuffer	コンストラクタ
	//------------------------------------------------------------
	PCStrBuffer()
		: pBuffer(NULL), zBuffer(BUFFER_SIZE)
	{
		if (zBuffer < BUFFER_SIZE_MIN) zBuffer	= BUFFER_SIZE_MIN;
		Init();
	}

	//------------------------------------------------------------
	//	~PCStrBuffer	デストラクタ
	//------------------------------------------------------------
	~PCStrBuffer()
	{
		ciMAlloc.Deallocate<T_DATA>(pBuffer);
	}

	//------------------------------------------------------------
	//	Buffer
	//------------------------------------------------------------
	T_PDATA Buffer()
	{
		return pBuffer;
	}

	//------------------------------------------------------------
	//	Size
	//------------------------------------------------------------
	size_t Size()
	{
		return zBuffer;
	}

	//------------------------------------------------------------
	//	ExtendBuffer
	//------------------------------------------------------------
	BOOL ExtendBuffer(size_t zRequired)
	{
		if (zRequired > BUFFER_SIZE_MAX)	return FALSE;
		while (zBuffer < zRequired)	zBuffer += BUFFER_SIZE;
		if (zRequired > BUFFER_SIZE_MAX)	zRequired	= BUFFER_SIZE_MAX;

		ciMAlloc.Deallocate<T_DATA>(pBuffer);
		if (ciMAlloc.Allocate<T_DATA>(&pBuffer, zBuffer))	return TRUE;
		return FALSE;
	}

	//------------------------------------------------------------
	//	Read
	//------------------------------------------------------------
	BOOL Read(T_PCDATA* ppBuffer, size_t* pzBuffer)
	{
		if (pBuffer != NULL)
		{
			*ppBuffer	= (T_PCDATA)pBuffer;
			*pzBuffer	= zBuffer;
			return TRUE;
		}
		return FALSE;
	}

	//------------------------------------------------------------
	//	Write
	//
	//	念のため、終端に NULL を追加する。
	//------------------------------------------------------------
	BOOL Write(T_PCDATA pData, size_t zData)
	{
		T_PCDATA	ps, pe;
		T_PDATA		pd;
		size_t		zReq;

		zReq	= zData + 1;
		if (zReq > zBuffer)
		{
			if (!ExtendBuffer(zReq))	return FALSE;
		}

		pe	= pData + zData;
		for (ps = pData, pd = pBuffer; ps < pe; ++ps, ++pd)	*pd	= *ps;
		*pd	= NULL;
		return TRUE;
	}
};


//======================================================================
//	class PCIteratorStack	:	反復子のスタックを管理するためのクラス
//======================================================================
template<class C_CONTAINER, class C_MALLOC = PLib::PCInstanceSet<typename C_CONTAINER::iterator> >
class PCIteratorStack
{
private:
	typedef	typename C_CONTAINER::iterator	ITERATOR, *PITERATOR;
	typedef	std::list<PITERATOR>			ITRSTACK;
	typedef	typename ITRSTACK::iterator		ITR_ITRSTACK;

	//------------------------------------------------------------
	//	データメンバ
	//------------------------------------------------------------
	ITRSTACK	ciItrStack;
	C_MALLOC	ciMAlloc;

	//------------------------------------------------------------
	//	メンバ関数
	//------------------------------------------------------------
private:
	void Clear()
	{
		ITR_ITRSTACK	i;

		for (i = ciItrStack.begin(); i != ciItrStack.end(); ++i)
		{
			ciMAlloc.Deallocate(*i);
		}
		ciItrStack.clear();
		ciMAlloc.Clear();
	}

public:
	size_t Size()
	{
		return (size_t)ciItrStack.size();
	}

	void PushNew()
	{
		ITR_ITRSTACK	itr;
		PITERATOR		p;

		p	= ciMAlloc.Allocate();
		if (!ciItrStack.empty())
		{
			itr	= ciItrStack.begin();
			*p	= **itr;
		}
		ciItrStack.push_front(p);
	}

	void Pop()
	{
		PITERATOR	pi;

		if (ciItrStack.empty())	THROWPE_LOGIC_ERROR("PCIteratorStack::Pop");
		pi	= *(ciItrStack.begin());
		ciItrStack.pop_front();
		if (ciItrStack.empty())	THROWPE_LOGIC_ERROR("PCIteratorStack::Pop");
		ciMAlloc.Deallocate(pi);
	}

	void PopAndUpdate()
	{
		PITERATOR	pi;

		if (ciItrStack.empty())	THROWPE_LOGIC_ERROR("PCIteratorStack::PopAndUpdate");
		pi	= *(ciItrStack.begin());
		ciItrStack.pop_front();
		if (ciItrStack.empty())	THROWPE_LOGIC_ERROR("PCIteratorStack::PopAndUpdate");
		**(ciItrStack.begin())	= *pi;
		ciMAlloc.Deallocate(pi);
	}

	PITERATOR pIterator()
	{
		if (!ciItrStack.empty())
		{
			return *(ciItrStack.begin());
		}
		return NULL;
	}

	void Init()
	{
		Clear();
		ciMAlloc.Init();
		PushNew();
	}

	PCIteratorStack()
	{
		Init();
	}

	~PCIteratorStack()
	{
		Clear();
	}
};

NS_PLIB_END
