//	XLCTextEx_1.0x	:	PLib

//	PUnicode.h
//
#pragma once

#ifndef NS_PLIB
#define NS_PLIB			PLib
#define NS_PLIB_BEGIN	namespace NS_PLIB {
#define NS_PLIB_END		}
#endif

#ifndef NS_UNICODE
#define NS_UNICODE	Unicode
#define NS_PLIB_UNICODE_BEGIN	namespace NS_PLIB {	namespace NS_UNICODE {
#define NS_PLIB_UNICODE_END	}}
#endif

NS_PLIB_UNICODE_BEGIN

#define	INVALID_CODEPOINT	((T_UCP)-1)


//======================================================================
//	�R�[�h�|�C���g�Ǝ��ۂ̕����R�[�h�Ԃ̕ϊ�
//======================================================================
//	21 �r�b�g�R�[�h�|�C���g�l�����ۂ̕����R�[�h�ɕϊ�����B
//	pBuf �ɂ́A�T���Q�[�g�̏ꍇ�� 2 �������A�I�[�� NULL 1 ���������K�v�Ȃ̂ŁA
//	�ŏ��ł� wchar_t 3 ���������蓖�ĂĂ������ƁB
BOOL	ConvertFromCodepoint(LPWSTR pBuf, UINT uiCodepoint);

//	���ۂ̕����R�[�h�� 21 �r�b�g�̃R�[�h�|�C���g�l�ɕϊ�����B
size_t	ConvertToCodepoint(UINT* puiCodepoint, LPCWSTR* ppSrc, LPCWSTR pEnd);
size_t	ConvertToCodepoint(UINT* puiCodepoint, LPCWSTR* ppszSrc);
size_t	ConvertToCodepoint(UINT* puiCodepoint, PIFStrBuffer<wchar_t>* pciBuf);

//======================================================================
//	�R�[�h�|�C���g��Ǝ��ۂ̃��j�R�[�h������Ԃ̕ϊ�
//======================================================================
bool	ConvertFromCodepoint(T_STRING_U* pstrDst, UINT uiCodepoint);
bool	ConvertFromCodepoint(T_STRING_U* pstrDst, UCPSTRING* puisSrc);

bool	ConvertToCodepoint(UCPSTRING* puisDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE);
bool	ConvertToCodepoint(UCPSTRING* puisDst, T_PCSTR_U pszSrc);


//======================================================================
//	PIFUnicodeBuffer �Ƃ��̔h���N���X
//
//	�ϊ����ƂȂ镶���񂩂�R�[�h�|�C���g���P�����o�����߂̃N���X�B
//======================================================================
//----------------------------------------------------------------------
//	PIFUnicodeBuffer	�C���^�[�t�F�[�X
//----------------------------------------------------------------------
class PIFUnicodeBuffer
{
public:
	virtual bool Set()	= 0;	//	�f�[�^���Z�b�g����Ă��邩�ǂ�����Ԃ��B

	virtual bool Begin()	= 0;
	virtual bool End()		= 0;
	virtual bool Next()		= 0;

	virtual bool GetCp(UINT* puiCp)	= 0;

	virtual bool GetCpString(UCPSTRING* puisBuffer)
	{
		T_UCP	cp;

		if (puisBuffer == NULL)	return false;

		for ( ; !End(); Next())
		{
			if (!GetCp(&cp))	return false;
			puisBuffer->append(1, cp);
		}
		return true;
	}

	virtual int Compare(PIFUnicodeBuffer* pOther)
	{
		T_UCP	cp1, cp2;

		if (!Begin())	return 0;
		if (pOther == NULL || !pOther->Begin())	return 0;

		for ( ; !End() && !(pOther->End()); Next(), pOther->Next())
		{
			if (!GetCp(&cp1))	return 0;
			if (!(pOther->GetCp(&cp2)))	return 0;
			if (cp1 < cp2)	return CSTR_LESS_THAN;
			if (cp1 > cp2)	return CSTR_GREATER_THAN;
		}
		if (End() && pOther->End())	return CSTR_EQUAL;	//	��񓯎m���������Ƃ݂Ȃ��B
		if (End())	return CSTR_LESS_THAN;
		return CSTR_GREATER_THAN;
	}
};

//----------------------------------------------------------------------
//	PBCUnicodeStrBuffer	���N���X
//	������̂܂܁i�|�C���^���j�i�[����B
//----------------------------------------------------------------------
class PBCUnicodeStrBuffer	: public PIFUnicodeBuffer
{
protected:
	T_PCSTR_U	pStr;
	T_PCSTR_U	pCurrent;
	T_PCSTR_U	pNext;

public:
	PBCUnicodeStrBuffer()	: pStr(NULL), pCurrent(NULL), pNext(NULL)	{}

	virtual bool Set()	{ return (pStr != NULL); }	//	�f�[�^���Z�b�g����Ă��邩�ǂ�����Ԃ��B

	//------------------------------------------------------------
	//	Begin, End, Next, GetCurrentPos
	//------------------------------------------------------------
	virtual bool Begin()
	{
		if (!Set())	return false;
		pCurrent	= pStr;
		return true;
	}
	virtual bool End()				= 0;
	virtual bool End(T_PCSTR_U ps)	= 0;
	virtual bool Next()
	{
		if (End())	return false;
		if (pCurrent < pNext)
		{
			pCurrent = pNext;
			return true;
		}
		++pCurrent;
		return true;
	}
	virtual T_PCSTR_U	GetCurrentPos()	{ return pCurrent; }

	//------------------------------------------------------------
	//	GetChar
	//------------------------------------------------------------
	virtual bool GetChar(T_CHAR_U* pc)
	{
		if (End())	return false;
		*pc	= *pCurrent;
		return true;
	}

	//------------------------------------------------------------
	//	GetCp
	//------------------------------------------------------------
	virtual bool GetCp(UINT* puiCp)
	{
		T_PCSTR_U	pc;
		UINT			uiHigh, uiLow;

		if (End())	return false;

		//	�T���Q�[�g�̂Q�����ڂȂ�A�f�[�^�Ɉُ킪����̂ŗ�O���X���[����B
		if (IS_LOW_SURROGATE(*pCurrent))
		{
			THROWPE_RUNTIME_ERROR("PCUnicodeBuffer: no high surrogate");
		}

		//	�T���Q�[�g�̂P�����ڂȂ�A���̕����ƍ��킹�ăR�[�h�|�C���g���v�Z����B
		if (IS_HIGH_SURROGATE(*pCurrent))
		{
			pc	= pCurrent;
			uiHigh	= (UINT)(*pc) - (UINT)(0xD800);
			++pc;
			//	�T���Q�[�g�̂Q�����ڂ��Ȃ��Ȃ��O���X���[����B
			if (End(pc) || !IS_LOW_SURROGATE(*pc))
			{
				THROWPE_RUNTIME_ERROR("PCUnicodeBuffer: no low surrogate");
			}
			uiLow	= (UINT)(*pc) - (UINT)(0xDC00);
			*puiCp	= (UINT)((uiHigh << 10) | uiLow) + (UINT)0x10000;
			++pc;
			pNext	= pc;
			return true;
		}

		//	�ȏ�ɓ��Ă͂܂�Ȃ��ꍇ�́A���݂̕������R�[�h�|�C���g�Ƃ��ĕԂ��B
		*puiCp	= (UINT)(*pCurrent);
		pNext	= pCurrent;
		++pNext;
		return true;
	}
};

//----------------------------------------------------------------------
//	PBCCodepointBuffer	���N���X
//	Codepoint ��𑀍삷��B
//----------------------------------------------------------------------
class PBCCodepointBuffer	: public PIFUnicodeBuffer
{
protected:
	const T_UCP*	puiStr;
	const T_UCP*	pCurrent;

public:
	PBCCodepointBuffer()	: puiStr(NULL), pCurrent(NULL)	{}

	virtual bool Set()	{ return (puiStr != NULL); }	//	�f�[�^���Z�b�g����Ă��邩�ǂ�����Ԃ��B

	//------------------------------------------------------------
	//	Begin, End, Next, GetCurrentPos
	//------------------------------------------------------------
	virtual bool Begin()
	{
		if (!Set())	return false;
		pCurrent	= puiStr;
		return true;
	}
	virtual bool End()	= 0;
	virtual bool Next()
	{
		if (pCurrent == NULL || End())	return false;
		++pCurrent;
		return true;
	}
	virtual const T_UCP*	GetCurrentPos()	{ return pCurrent; }

	//------------------------------------------------------------
	//	GetCp
	//------------------------------------------------------------
	virtual bool GetCp(T_UCP* puiCp)
	{
		if (pCurrent != NULL)
		{
			*puiCp	= *pCurrent;
			return true;
		}
		return false;
	}
};

//----------------------------------------------------------------------
//	PCUnicodeSegmentBuffer
//	������������������߂̃N���X�B
//----------------------------------------------------------------------
class PCUnicodeSegmentBuffer	: public PBCUnicodeStrBuffer
{
protected:
	T_PCSTR_U	pEnd;

public:
	PCUnicodeSegmentBuffer()	: PBCUnicodeStrBuffer(), pEnd(NULL)	{}

	virtual bool Set()
	{
		if(!PBCUnicodeStrBuffer::Set()) return false;
		return (pStr < pEnd);
	}
	virtual bool End()	{ return (pCurrent >= pEnd); }
	virtual bool End(T_PCSTR_U ps)	{ return (ps >= pEnd); }

	bool Set(T_PCSTR_U pb, T_PCSTR_U pe)
	{
		if (pb == NULL || pb > pe)	return false;
		pStr = pb;
		pEnd = pe;
		pCurrent = pStr;
		return true;
	}
	bool Set(T_PCSTR_U ps, size_t zs)
	{
		if (ps == NULL)	return false;
		pStr = ps;
		pEnd = ps + zs;
		pCurrent = pStr;
		return true;
	}
};

//----------------------------------------------------------------------
//	PCUnicodeSzBuffer
//	NULL �I����������������߂̃N���X�B
//----------------------------------------------------------------------
class PCUnicodeSzBuffer	: public PBCUnicodeStrBuffer
{
protected:

public:
	PCUnicodeSzBuffer()	: PBCUnicodeStrBuffer()	{}

	//	virtual bool Set() �͊��N���X�̂��̂��g�p����B

	//	�����񂪃Z�b�g����Ă��Ȃ��ƃG���[�ɂȂ�B
	//	Set() �� Begin() ���Ăяo���Ă���g�p���邱�ƁB
	virtual bool End()	{ return (*pCurrent == NULL); }
	virtual bool End(T_PCSTR_U ps)	{ return (*ps == NULL); }

	bool Set(T_PCSTR_U ps)
	{
		if (ps == NULL)	return false;
		pStr = ps;
		pCurrent = pStr;
		return true;
	}
};

//----------------------------------------------------------------------
//	PCCodepointSegmentBuffer
//	���� Codepoint ����������߂̃N���X�B
//----------------------------------------------------------------------
class PCCodepointSegmentBuffer	: public PBCCodepointBuffer
{
protected:
	const T_UCP*	puiEnd;

public:
	PCCodepointSegmentBuffer()	: PBCCodepointBuffer(), puiEnd(NULL)	{}

	virtual bool Set()
	{
		if(!PBCCodepointBuffer::Set()) return false;
		return (puiStr < puiEnd);
	}
	virtual bool End()	{ return (pCurrent >= puiEnd); }
	virtual bool End(const T_UCP* ps)	{ return (ps >= puiEnd); }

	bool Set(const T_UCP* pb, const T_UCP* pe)
	{
		if (pb == NULL || pb > pe)	return false;
		puiStr = pb;
		puiEnd = pe;
		pCurrent = puiStr;
		return true;
	}
	bool Set(const T_UCP* ps, size_t zs)
	{
		if (ps == NULL)	return false;
		puiStr = ps;
		puiEnd = ps + zs;
		pCurrent = puiStr;
		return true;
	}
};

//----------------------------------------------------------------------
//	PCCodepointSzBuffer
//	NULL �I�� Codepoint ����������߂̃N���X�B
//----------------------------------------------------------------------
class PCCodepointSzBuffer	: public PBCCodepointBuffer
{
protected:

public:
	PCCodepointSzBuffer()	: PBCCodepointBuffer()	{}

	virtual bool Set()
	{
		return PBCCodepointBuffer::Set();
	}
	virtual bool End()	{ return (*pCurrent == 0); }
	virtual bool End(T_UCP* ps)	{ return (*ps == 0); }

	bool Set(const T_UCP* ps)
	{
		if (ps == NULL)	return false;
		puiStr		= ps;
		pCurrent	= ps;
		return true;
	}
};

//----------------------------------------------------------------------
//	PCUIStringBuffer
//	UCPSTRING ����R�[�h�|�C���g�����o���B
//----------------------------------------------------------------------
class PCUIStringBuffer	: public PIFUnicodeBuffer
{
protected:
	UCPSTRING*	puisBuffer;
	const UINT*	pCurrent;

public:
	PCUIStringBuffer()	: pCurrent(NULL)	{}

	UCPSTRING* GetBuffer()	{ return puisBuffer; }

	virtual bool Set()	{ return (puisBuffer != NULL); }

	bool Set(UCPSTRING* puisSrc)
	{
		puisBuffer	= puisSrc;
		if (puisBuffer != NULL)
		{
			pCurrent	= puisBuffer->c_str();
			return true;
		}
		return false;
	}

	virtual bool Begin()
	{
		if (puisBuffer == NULL || puisBuffer->empty())
		{
			pCurrent	= NULL;
			return false;
		}
		pCurrent	= puisBuffer->c_str();
		return true;
	}

	virtual bool End()	{ return (pCurrent == NULL || *pCurrent == NULL); }

	virtual bool Next()
	{
		if (pCurrent == NULL || *pCurrent == NULL)	return false;
		++pCurrent;
		return true;
	}

	virtual bool GetCp(UINT* puiCp)
	{
		if (pCurrent == NULL || *pCurrent == NULL)	return false;
		*puiCp	= *pCurrent;
		return true;
	}
};

//----------------------------------------------------------------------
//	PCUnicodeCpBuffer
//	�R�[�h�|�C���g�ɕϊ����Ċi�[����B
//----------------------------------------------------------------------
class PCUnicodeCpBuffer	: public PIFUnicodeBuffer
{
protected:
	UCPSTRING	uisBuffer;
	const UINT*	pCurrent;

public:
	PCUnicodeCpBuffer()	: pCurrent(NULL)	{}

	UCPSTRING* GetBuffer()	{ return &uisBuffer; }

	virtual bool Set()	{ return !(uisBuffer.empty()); }

	bool Set(T_PCSTR_U pb, T_PCSTR_U pe)
	{
		if (pb == NULL || pb > pe)	return false;
		uisBuffer.clear();
		pCurrent	= NULL;
		return ConvertToCodepoint(&uisBuffer, pb, pe);
	}

	bool Set(T_PCSTR_U psz)
	{
		if (psz == NULL)	return false;
		uisBuffer.clear();
		pCurrent	= NULL;
		return ConvertToCodepoint(&uisBuffer, psz);
	}

	virtual bool Begin()
	{
		if (uisBuffer.empty())
		{
			pCurrent	= NULL;
			return false;
		}
		pCurrent	= uisBuffer.c_str();
		return true;
	}

	virtual bool End()	{ return (pCurrent == NULL || *pCurrent == NULL); }

	virtual bool Next()
	{
		if (pCurrent == NULL || *pCurrent == NULL)	return false;
		++pCurrent;
		return true;
	}

	virtual bool GetCp(UINT* puiCp)
	{
		if (pCurrent == NULL || *pCurrent == NULL)	return false;
		*puiCp	= *pCurrent;
		return true;
	}
};

NS_PLIB_UNICODE_END
