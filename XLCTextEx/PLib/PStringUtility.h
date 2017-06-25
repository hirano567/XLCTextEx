//	XLCTextEx_1.0x	:	PLib

//	PException.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	PIFStrBuffer �Ƃ��̔h���N���X
//
//	�����Ŏw�肳��镶����� NULL �I����������܂Ƃ߂Ď�舵�����߂̃N���X
//======================================================================
//----------------------------------------------------------------------
//	PIFStrBuffer	�C���^�[�t�F�[�X
//----------------------------------------------------------------------
template<typename T_CHAR>
class PIFStrBuffer
{
public:
	typedef	T_CHAR*						T_PSTR;
	typedef	const T_CHAR*				T_PCSTR;
	typedef	std::basic_string<T_CHAR>	T_STRING;
	
	virtual bool Set()	= 0;	//	�f�[�^���Z�b�g����Ă��邩�ǂ�����Ԃ��B

	virtual bool Begin()	= 0;
	virtual bool End()		= 0;
	virtual bool Next()		= 0;

	virtual T_PCSTR GetCurrentPos()					= 0;
	virtual bool	GetChar(T_CHAR* pChar)			= 0;
	virtual bool	GetString(T_STRING* pstrBuffer)	= 0;

	virtual int Compare(PIFStrBuffer* pOther)
	{
		T_CHAR	c1, c2;

		if (!Begin())	return 0;
		if (pOther == NULL || !pOther->Begin())	return 0;

		for ( ; !End() && !(pOther->End()); Next(), pOther->Next())
		{
			if (!GetChar(&c1))	return 0;
			if (!(pOther->GetChar(&c2)))	return 0;
			if (c1 < c2)	return CSTR_LESS_THAN;
			if (c1 > c2)	return CSTR_GREATER_THAN;
		}
		if (End() && pOther->End())	return CSTR_EQUAL;
		if (End())	return CSTR_LESS_THAN;
		return CSTR_GREATER_THAN;
	}
};


//----------------------------------------------------------------------
//	PBCStrBuffer	���N���X
//	������̂܂܁i�|�C���^���j�i�[����B
//----------------------------------------------------------------------
template<typename T_CHAR>
class PBCStrBuffer	: public PIFStrBuffer<T_CHAR>
{
protected:
	T_PCSTR	pStr;
	T_PCSTR	pCurrent;

public:
	PBCStrBuffer()	: pStr(NULL), pCurrent(NULL)	{}

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
	virtual bool End()	= 0;
	virtual bool Next()
	{
		if (End())	return false;
		++pCurrent;
		return true;
	}
	virtual T_PCSTR	GetCurrentPos()	{ return pCurrent; }

	//------------------------------------------------------------
	//	GetChar
	//------------------------------------------------------------
	virtual bool GetChar(T_CHAR* pc)
	{
		if (pCurrent == NULL || End())	return false;
		*pc	= *pCurrent;
		return true;
	}

	//------------------------------------------------------------
	//	CompareStr
	//------------------------------------------------------------
	virtual int CompareStr(PBCStrBuffer* pOther)
	{
		T_CHAR_U	c1, c2;

		if (pOther == NULL || !(pOther->Set()))	return 0;

		for (Begin(), pOther->Begin(); !End() && !(pOther->End()); Next(), pOther->End())
		{
			if (!GetChar(&c1))	return 0;
			if (!(pOther->GetChar(&c2)))	return 0;
			if (c1 < c2)	return CSTR_LESS_THAN;
			if (c1 > c2)	return CSTR_GREATER_THAN;
		}
		if (End() && pOther->End())	return CSTR_EQUAL;
		if (End())	return CSTR_LESS_THAN;
		return CSTR_GREATER_THAN;
	}

	virtual bool GetString(T_STRING* pstrBuffer)	= 0;
};


//----------------------------------------------------------------------
//	PCStrSegmentBuffer
//	������������������߂̃N���X�B
//----------------------------------------------------------------------
template<typename T_CHAR>
class PCStrSegmentBuffer	: public PBCStrBuffer<T_CHAR>
{
protected:
	T_PCSTR	pEnd;

public:
	PCStrSegmentBuffer()	: PBCStrBuffer(), pEnd(NULL)	{}

	virtual bool Set()
	{
		if(!PBCStrBuffer::Set()) return false;
		return (pStr < pEnd);
	}
	virtual bool End()	{ return (pCurrent >= pEnd); }

	bool Set(T_PCSTR pb, T_PCSTR pe)
	{
		if (pb == NULL || pb > pe)	return false;
		pStr = pb;
		pEnd = pe;
		pCurrent = pStr;
		return true;
	}
	bool Set(T_PCSTR ps, size_t zs)
	{
		if (ps == NULL)	return false;
		pStr = ps;
		pEnd = ps + zs;
		pCurrent = pStr;
		return true;
	}

	virtual bool GetString(T_STRING* pstrBuffer)
	{
		if (pstrBuffer == NULL)	return false;
		pstrBuffer->append(pStr, (size_t)(pEnd - pStr));
		return true;
	}
};

//----------------------------------------------------------------------
//	PCStrSzBuffer
//	NULL �I����������������߂̃N���X�B
//----------------------------------------------------------------------
template<typename T_CHAR>
class PCStrSzBuffer	: public PBCStrBuffer<T_CHAR>
{
protected:

public:
	PCStrSzBuffer()	: PBCStrBuffer()	{}

	//	virtual bool Set() �͊��N���X�̂��̂��g�p����B

	//	�����񂪃Z�b�g����Ă��Ȃ��ƃG���[�ɂȂ�B
	//	Set() �� Begin() ���Ăяo���Ă���g�p���邱�ƁB
	virtual bool End()	{ return (*pCurrent == NULL); }

	bool Set(T_PCSTR ps)
	{
		if (ps == NULL)	return false;
		pStr = ps;
		pCurrent = pStr;
		return true;
	}

	virtual bool GetString(T_STRING* pstrBuffer)
	{
		if (pstrBuffer == NULL)	return false;
		pstrBuffer->append(pStr);
		return true;
	}
};


//======================================================================
//	is �֐��̃e���v���[�g
//======================================================================
//----------------------------------------------------------------------
//	t_IsAlNum
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL t_IsAlNum(T_CHAR c)
{
	THROW_LOGIC_ERROR("t_IsAlNum");
	return FALSE;
}
template<>
inline BOOL t_IsAlNum<char>(char c)
{
	return (BOOL)isalnum((int)(unsigned char)c);
}
template<>
inline BOOL t_IsAlNum<wchar_t>(wchar_t c)
{
	return (BOOL)iswalnum((wint_t)c);
}

//----------------------------------------------------------------------
//	t_IsAlpha
//
//	isalpha �n�֐��̃e���v���[�g
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL t_IsAlpha(T_CHAR c)
{
	THROW_LOGIC_ERROR("t_IsAlpha");
	return FALSE;
}
template<>
inline BOOL t_IsAlpha<char>(char c)
{
	return isalpha((int)(unsigned char)c);
}
template<>
inline BOOL t_IsAlpha<wchar_t>(wchar_t c)
{
	return iswalpha((wint_t)c);
}

//----------------------------------------------------------------------
//	t_IsBlank
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL t_IsBlank(T_CHAR c)
{
	THROW_LOGIC_ERROR("t_IsBlank");
	return FALSE;
}
template<>
inline BOOL t_IsBlank<char>(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f');
}
template<>
inline BOOL t_IsBlank<wchar_t>(wchar_t wc)
{
	return (wc == L' ' || wc == L'\t' || wc == L'\v' || wc == L'\f');
}

//----------------------------------------------------------------------
//	t_IsCntrl
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL t_IsCntrl(T_CHAR c)
{
	THROW_LOGIC_ERROR("t_IsCntrl");
	return FALSE;
}
template<>
inline BOOL t_IsCntrl<char>(char c)
{
	return (BOOL)iscntrl((int)(unsigned char)c);
}
template<>
inline BOOL t_IsCntrl<wchar_t>(wchar_t wc)
{
	return (BOOL)iswcntrl((wint_t)wc);
}
template<>
inline BOOL t_IsCntrl<T_UCP>(T_UCP cp)
{
	return (IS_16BIT(cp) && (BOOL)iswcntrl((wint_t)cp));
}

//----------------------------------------------------------------------
//	t_IsDigit
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL t_IsDigit(T_CHAR c)
{
	THROW_LOGIC_ERROR("t_IsDigit");
	return FALSE;
}
template<>
inline BOOL t_IsDigit<char>(char c)
{
	return (BOOL)isdigit((int)(unsigned char)c);
}
template<>
inline BOOL t_IsDigit<wchar_t>(wchar_t wc)
{
	return (BOOL)iswdigit((wint_t)wc);
}

//----------------------------------------------------------------------
//	t_IsGraph
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL t_IsGraph(T_CHAR c)
{
	THROW_LOGIC_ERROR("t_IsGraph");
	return FALSE;
}
template<>
inline BOOL t_IsGraph<char>(char c)
{
	return (BOOL)isgraph((int)(unsigned char)c);
}
template<>
inline BOOL t_IsGraph<wchar_t>(wchar_t wc)
{
	return (BOOL)iswgraph((wint_t)wc);
}

//----------------------------------------------------------------------
//	t_IsLower
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL t_IsLower(T_CHAR c)
{
	THROW_LOGIC_ERROR("t_IsLower");
	return FALSE;
}
template<>
inline BOOL t_IsLower<char>(char c)
{
	return (BOOL)islower((int)(unsigned char)c);
}
template<>
inline BOOL t_IsLower<wchar_t>(wchar_t wc)
{
	return (BOOL)iswlower((wint_t)wc);
}

//----------------------------------------------------------------------
//	t_IsPrint
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL t_IsPrint(T_CHAR c)
{
	THROW_LOGIC_ERROR("t_IsPrint");
	return FALSE;
}
template<>
inline BOOL t_IsPrint<char>(char c)
{
	return (BOOL)isprint((int)(unsigned char)c);
}
template<>
inline BOOL t_IsPrint<wchar_t>(wchar_t wc)
{
	return (BOOL)iswprint((wint_t)wc);
}

//----------------------------------------------------------------------
//	t_IsPunct
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL t_IsPunct(T_CHAR c)
{
	THROW_LOGIC_ERROR("t_IsPunct");
	return FALSE;
}
template<>
inline BOOL t_IsPunct<char>(char c)
{
	return (BOOL)ispunct((int)(unsigned char)c);
}
template<>
inline BOOL t_IsPunct<wchar_t>(wchar_t wc)
{
	return (BOOL)iswpunct((wint_t)wc);
}

//----------------------------------------------------------------------
//	t_IsSpace
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL t_IsSpace(T_CHAR c)
{
	THROW_LOGIC_ERROR("t_IsSpace");
	return FALSE;
}
template<>
inline BOOL t_IsSpace<char>(char c)
{
	return (BOOL)isspace((int)(unsigned char)c);
}
template<>
inline BOOL t_IsSpace<wchar_t>(wchar_t c)
{
	return (BOOL)iswspace((wint_t)c);
}
template<>
inline BOOL t_IsSpace<UINT>(UINT c)
{
	return (IS_16BIT(c) && (BOOL)iswspace((wint_t)c));
}

//----------------------------------------------------------------------
//	t_IsUpper
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL t_IsUpper(T_CHAR c)
{
	THROW_LOGIC_ERROR("t_IsUpper");
	return FALSE;
}
template<>
inline BOOL t_IsUpper<char>(char c)
{
	return (BOOL)isupper((int)(unsigned char)c);
}
template<>
inline BOOL t_IsUpper<wchar_t>(wchar_t wc)
{
	return (BOOL)iswupper((wint_t)wc);
}

//----------------------------------------------------------------------
//	t_IsXDigit
//----------------------------------------------------------------------
template<typename T_CHAR>
inline BOOL t_IsXDigit(T_CHAR c)
{
	THROW_LOGIC_ERROR("t_IsXDigit");
	return FALSE;
}
template<>
inline BOOL t_IsXDigit<char>(char c)
{
	return (BOOL)isxdigit((int)(unsigned char)c);
}
template<>
inline BOOL t_IsXDigit<wchar_t>(wchar_t wc)
{
	return (BOOL)iswxdigit((wint_t)wc);
}

//======================================================================
//	is �֐�	(2)	���̂ق��̕�������
//======================================================================
//----------------------------------------------------------------------
//	IsDoubleQuote
//	Unicode �� "(0x0020) �ɐ��K�������̂́A�h(0xFF02) �����ł���B
//----------------------------------------------------------------------
template<typename T_CHAR>
inline bool IsDoubleQuote(T_CHAR c)
{
	THROWPE_LOGIC_ERROR("IsDoubleQuote");
	return false;
}
template<>
inline bool IsDoubleQuote<char>(char c)
{
	return (c == '"');
}
template<>
inline bool IsDoubleQuote<wchar_t>(wchar_t c)
{
	return (c == L'"' || c == L'�h');
}
template<>
inline bool IsDoubleQuote<T_UCP>(T_UCP c)
{
	return (c == (T_UCP)L'"' || c == (T_UCP)L'�h');
}

//======================================================================
//	t_StrLen
//	strlen �n�֐��̃e���v���[�g
//	���������s�����ꍇ�� FALSE ��Ԃ��B
//======================================================================
template<typename T>
inline BOOL t_StrLen(size_t* pzLen, const T* pszStr)
{
	THROWPE_LOGIC_ERROR("t_StrLen");
	return FALSE;
}
template<>
inline BOOL t_StrLen<char>(size_t* pzLen, const char* pszStr)
{
	if (pzLen != NULL && pszStr != NULL)
	{
		*pzLen = strlen(pszStr);
		return TRUE;
	}
	return FALSE;
}
template<>
inline BOOL t_StrLen<wchar_t>(size_t* pzLen, const wchar_t* pszStr)
{
	if (pzLen != NULL && pszStr != NULL)
	{
		*pzLen = wcslen(pszStr);
		return TRUE;
	}
	return FALSE;
}


//======================================================================
//	t_StrCmp
//
//	_stricmp �n�֐��� strcmp �n�֐��̃e���v���[�g	(1)
//======================================================================
template<typename T, BOOL B_CASE>
inline int t_StrCmp(const T* ps1, const T* ps2)
{
	THROW_LOGIC_ERROR("t_StrCmp: bad parameter");
	return -1;
}
//----------------------------------------------------------------------
//	char�A�啶���������̋�ʂȂ�
//----------------------------------------------------------------------
template<>
inline int t_StrCmp<char, FALSE>(const char* ps1, const char* ps2)
{
	return _stricmp(ps1, ps2);
}
//----------------------------------------------------------------------
//	wchar_t�A�啶���������̋�ʂȂ�
//----------------------------------------------------------------------
template<>
inline int t_StrCmp<wchar_t, FALSE>(const wchar_t* ps1, const wchar_t* ps2)
{
	return _wcsicmp(ps1, ps2);
}
//----------------------------------------------------------------------
//	char�A�啶���������̋�ʂ���
//----------------------------------------------------------------------
template<>
inline int t_StrCmp<char, TRUE>(const char* ps1, const char* ps2)
{
	return strcmp(ps1, ps2);
}
//----------------------------------------------------------------------
//	wchar_t�A�啶���������̋�ʂ���
//----------------------------------------------------------------------
template<>
inline int t_StrCmp<wchar_t, TRUE>(const wchar_t* ps1, const wchar_t* ps2)
{
	return wcscmp(ps1, ps2);
}

//======================================================================
//	t_StrNCmp
//
//	_strncmp�A_strnicmp �n�֐��̃e���v���[�g	(1)
//======================================================================
template<typename T_CHAR, BOOL B_CASE>
inline int t_StrNCmp(const T_CHAR* pStr1, const T_CHAR* pStr2, size_t zCount)
{
	THROW_LOGIC_ERROR("t_StrNCmp");
	return 0;
}
//----------------------------------------------------------------------
//	char�A�啶���������̋�ʂȂ�
//----------------------------------------------------------------------
template<>
inline int t_StrNCmp<char, FALSE>(LPCSTR pStr1, LPCSTR pStr2, size_t zCount)
{
	return _strnicmp(pStr1, pStr2, zCount);
}
//----------------------------------------------------------------------
//	wchar_t�A�啶���������̋�ʂȂ�
//----------------------------------------------------------------------
template<>
inline int t_StrNCmp<wchar_t, FALSE>(LPCWSTR pStr1, LPCWSTR pStr2, size_t zCount)
{
	return _wcsnicmp(pStr1, pStr2, zCount);
}
//----------------------------------------------------------------------
//	char�A�啶���������̋�ʂ���
//----------------------------------------------------------------------
template<>
inline int t_StrNCmp<char, TRUE>(LPCSTR pStr1, LPCSTR pStr2, size_t zCount)
{
	return strncmp(pStr1, pStr2, zCount);
}
//----------------------------------------------------------------------
//	wchar_t�A�啶���������̋�ʂ���
//----------------------------------------------------------------------
template<>
inline int t_StrNCmp<wchar_t, TRUE>(LPCWSTR pStr1, LPCWSTR pStr2, size_t zCount)
{
	return wcsncmp(pStr1, pStr2, zCount);
}

//======================================================================
//	�����񌟍��֐��̃e���v���[�g
//======================================================================
//----------------------------------------------------------------------
//	t_StrStr
//----------------------------------------------------------------------
template<typename T_CHAR>
inline T_CHAR* t_StrStr(T_CHAR* pText, const T_CHAR* pSearch)
{
	THROWPE_LOGIC_ERROR("t_StrStr");
	return NULL;
}
template<>
inline LPSTR t_StrStr<char>(LPSTR pText, LPCSTR pSearch)
{
	return strstr(pText, pSearch);
}
template<>
inline LPWSTR t_StrStr<wchar_t>(LPWSTR pText, LPCWSTR pSearch)
{
	return wcsstr(pText, pSearch);
}


//======================================================================
//	StrCopyMa: ������̕���
//======================================================================
//----------------------------------------------------------------------
//	StrCopyMa
//
//	T_CHAR**		ppDst		������ƂȂ�o�b�t�@�ւ̃|�C���^�̃|�C���^�B
//								�o�b�t�@�͊֐����Ŋm�ۂ����B
//								�o�b�t�@�̉���͌Ăяo�����ōs���Ƃ���B
//	size_t*			pzCopied	�������ꂽ���������i�[����ϐ��̃|�C���^�B
//	const T_CHAR*	pSrc		�������̕�������w���|�C���^�B
//	const T_CHAR*	pEnd		�������̏I�[�ƂȂ镶�����w���|�C���^�B
//								���̃|�C���^���w�������͕�������Ȃ��B
//----------------------------------------------------------------------
template<typename T_CHAR, class C_MALLOC>
bool t_StrCopyMa(T_CHAR** ppDst, size_t* pzCopied, const T_CHAR* pSrc, const T_CHAR* pEnd)
{
	C_MALLOC		ciMAlloc;
	const T_CHAR*	pcs;
	T_CHAR*			pcd;
	T_CHAR*			pDst	= NULL;
	size_t			zCopy;
	bool			bStrCoppyMa	= true;

	if (ppDst == NULL || pzCopied == NULL || pSrc == NULL || pSrc >= pEnd)	return false;

	zCopy	= (size_t)(pEnd - pSrc);
	if (zCopy > MAX_STR_LENGTH)	return false;

	pDst	= ciMAlloc.Allocate<T_CHAR>(zCopy + 1);

	for (pcs = pSrc, pcd = pDst; pcs < pEnd; ++pcs, ++pcd)
	{
		*pcd = *pcs;
	}
	*pcd		= NULL;
	*ppDst		= pDst;
	*pzCopied	= zCopy;
	return true;
}

template<typename T_CHAR>
inline bool StrCopyMa(T_CHAR** ppDst, size_t* pzCopied, const T_CHAR* pSrc, const T_CHAR* pEnd)
{
	return t_StrCopyMa<T_CHAR, PLib::PCMAlloc>(ppDst, pzCopied, pSrc, pEnd);
}

//----------------------------------------------------------------------
//	StrCopyMa
//
//	T_CHAR**		ppDst		������ƂȂ�o�b�t�@�ւ̃|�C���^�̃|�C���^�B
//								�o�b�t�@�͊֐����Ŋm�ۂ����B
//								�o�b�t�@�̉���͌Ăяo�����ōs���Ƃ���B
//	size_t*			pzCopied	�������ꂽ���������i�[����ϐ��̃|�C���^�B
//	const T_CHAR*	pszSrc		�������̃k���I����������w���|�C���^�B
//----------------------------------------------------------------------
template<typename T_CHAR, class C_MALLOC>
bool t_StrCopyMa(T_CHAR** ppDst, size_t* pzCopied, const T_CHAR* pszSrc)
{
	size_t	zSrc;
	if (!NS_PLIB::t_StrLen<T_CHAR>(&zSrc, pszSrc))	return false;
	return t_StrCopyMa<T_CHAR, C_MALLOC>(ppDst, pzCopied, pszSrc, zSrc);
}

template<typename T_CHAR>
inline bool StrCopyMa(T_CHAR** ppDst, size_t* pzCopied, const T_CHAR* pszSrc)
{
	return t_StrCopyMa<T_CHAR, PLib::PCMAlloc>(ppDst, pzCopied, pszSrc);
}

//----------------------------------------------------------------------
//	StrCopyMa
//
//	T**		ppDst		������ƂȂ�o�b�t�@�ւ̃|�C���^�̃|�C���^�B
//						�o�b�t�@�͊֐����Ŋm�ۂ����B
//						�o�b�t�@�̉���͌Ăяo�����ōs���Ƃ���B
//	size_t* pzCopied	�������ꂽ���������i�[����ϐ��̃|�C���^�B
//	const T	pSrc		�������̕�������w���|�C���^�B
//	size_t	zCopy		�������镶�����B0 �Ȃ當����S�̂𕡐�����B
//----------------------------------------------------------------------
template<typename T_CHAR, class C_MALLOC>
bool t_StrCopyMa(T_CHAR** ppDst, size_t* pzCopied, const T_CHAR* pSrc, size_t zCopy)
{
	if (zCopy < 1)	return false;
	return t_StrCopyMa<T_CHAR, C_MALLOC>(ppDst, pzCopied, pSrc, (const T_CHAR*)(pSrc + zCopy));
}

template<typename T_CHAR>
inline bool StrCopyMa(T_CHAR** ppDst, size_t* pzCopied, const T_CHAR* pSrc, size_t zCopy)
{
	return t_StrCopyMa<T_CHAR, PLib::PCMAlloc>(ppDst, pzCopied, pSrc, zCopy);
}

//======================================================================
//	Trim	:	�O��̋󔒂��������Ƃ��͈̔͂����߂�B
//				pSrcE�A*ppEnd �͔͈͂ɑ����Ȃ��B
//
//	�f�[�^�`�F�b�N�͂��Ȃ��̂ŁA���S�����m�F����Ă���ꍇ�Ɏg�p���邱�ƁB
//	���������s�����Ƃ��� FALSE ��Ԃ��B
//	�������������ʁA�󕶎���ƂȂ�ꍇ�́A
//	*ppBegin�A*ppEnd �� NULL �������ATRUE ��Ԃ��B
//======================================================================
//----------------------------------------------------------------------
//	�\�[�X�̗��[���w��
//----------------------------------------------------------------------
template<typename T_CHAR>
BOOL Trim(const T_CHAR** ppBegin, const T_CHAR** ppEnd, const T_CHAR* pSrcB, const T_CHAR* pSrcE)
{
	const T_CHAR*	pb			= pSrcB;	//	������̐擪
	const T_CHAR*	pe			= pSrcE;	//	������̍Ō�̕���
	const T_CHAR*	pMaxAddress	= NULL;

	if (ppBegin == NULL || ppEnd == NULL || pSrcB == NULL || !(pSrcB < pSrcE))	return FALSE;
	//NS_PLIB::AdjustToMaximumAddress((LPVOID*)&pSrcE);

	//	�Ō�̕�������O���ցA�󔒈ȊO�̕��������邩���ׂĂ����B
	do
	{
		--pe;
	}
	while (pb < pe && t_IsSpace<T_CHAR>(*pe));

	//	�擪�܂ŒB�����ꍇ�B
	if (pe == pb)
	{
		//	�擪�̕������󔒕����łȂ��ꍇ�B
		if (!t_IsSpace<T_CHAR>(*pb))
		{
			*ppBegin	= pb;
			*ppEnd		= pe + 1;
		}
		//	�擪�̕������󔒂̏ꍇ�� NULL ��������B
		else
		{
			*ppBegin	= NULL;
			*ppEnd		= NULL;
			return TRUE;
		}
	}

	//	�r���ŋ󔒈ȊO�̕��������������ꍇ�A�擪����󔒈ȊO�̕�����T���B
	while (t_IsSpace<T_CHAR>(*pb))
	{
		++pb;
	}
	*ppBegin	= pb;
	*ppEnd		= pe + 1;

	return TRUE;
}

//======================================================================
//	IsLastCharWrong
//	�w�肳�ꂽ������̍Ō�̕������K�؂��ǂ������ׂ�B
//======================================================================
template<typename T_CHAR>
inline BOOL IsLastCharWrong(const T_CHAR* pStrB, const T_CHAR* pStrE)
{
	THROWPE_LOGIC_ERROR("IsLastCharWrong");
	return FALSE;
}
template<>
inline BOOL IsLastCharWrong<char>(LPCSTR pStrB, LPCSTR pStrE)
{
	LPCSTR	pc;
	
	if (pStrB == NULL || pStrB >= pStrE)	THROWPE_INVALID_PARAMETER("IsLastCharWrong");

	for (pc = pStrB; pc < pStrE; ++pc)
	{
		if (IsDBCSLeadByte((BYTE)*pc))
		{
			++pc;
			if (pc >= pStrE)	return TRUE;
		}
	}
	return FALSE;
}
template<>
inline BOOL IsLastCharWrong<wchar_t>(LPCWSTR pStrB, LPCWSTR pStrE)
{
	if (pStrB == NULL || pStrB >= pStrE)	THROWPE_INVALID_PARAMETER("IsLastCharWrong");
	return IS_HIGH_SURROGATE(*(pStrE - 1));
}

template<typename T_CHAR>
BOOL IsLastCharWrong(const T_CHAR* pStrB, size_t zStr)
{
	if (pStrB == NULL || zStr < 1)	THROWPE_INVALID_PARAMETER("IsLastCharWrong");
	return IsLastCharWrong<T_CHAR>(pStrB, pStrB + zStr);
}

//======================================================================
//	FindValidEnd
//	�w�肳�ꂽ������̏I�[�Ƃ��ēK�؂Ȉʒu�����߂�B
//======================================================================
template<typename T_CHAR>
inline BOOL FindValidEnd(const T_CHAR** ppEnd, const T_CHAR* pStrB, const T_CHAR* pStrE)
{
	THROWPE_LOGIC_ERROR("FindValidEnd");
	return FALSE;
}
template<>
inline BOOL FindValidEnd<char>(LPCSTR* ppEnd, LPCSTR pStrB, LPCSTR pStrE)
{
	LPCSTR	pc, pe;
	BOOL	bLB	= FALSE;
	
	if (ppEnd == NULL || pStrB == NULL || pStrB >= pStrE)
		THROWPE_INVALID_PARAMETER("FindValidEnd");
	pe	= NULL;

	for (pc = pStrB; pc < pStrE; ++pc)
	{
		if (bLB == FALSE && IsDBCSLeadByte((BYTE)*pc))
		{
			bLB	= TRUE;
			continue;
		}
		if (bLB == TRUE)	bLB	= FALSE;
		pe	= pc;
	}
	if (pe != NULL)
	{
		*ppEnd	= pe + 1;
		return TRUE;
	}
	return FALSE;
}
template<>
inline BOOL FindValidEnd<wchar_t>(LPCWSTR* ppEnd, LPCWSTR pStrB, LPCWSTR pStrE)
{
	if (pStrB == NULL || pStrB >= pStrE)	THROWPE_INVALID_PARAMETER("FindValidEnd");
	if (IS_HIGH_SURROGATE(*(pStrE - 1)))
	{
		if (pStrB + 1 >= pStrE)	return FALSE;	//	�T���Q�[�g�̏�ʕ��������̕�����͕s�K��
		*ppEnd	= pStrE - 1;
	}
	else
	{
		*ppEnd	= pStrE;
	}
	return TRUE;
}

template<typename T_CHAR>
BOOL FindValidEnd(const T_CHAR** ppEnd, const T_CHAR* pStrB, size_t zStr)
{
	if (pStrB == NULL || zStr < 1)	THROWPE_INVALID_PARAMETER("FindValidEnd");
	return FindValidEnd<T_CHAR>(ppEnd, pStrB, pStrB + zStr);
}

//======================================================================
//	t_Sprintf	sprintf_s �n�֐��̃e���v���[�g
//======================================================================
//----------------------------------------------------------------------
//	t_Sprintf_1	�ΏۂƂȂ�l�� 1 ��
//----------------------------------------------------------------------
template<typename T_NUM>
int t_Sprintf_1(char* pBuf, size_t zBuf, LPCSTR pReplacement, T_NUM x)
{
	return sprintf_s(pBuf, zBuf, pReplacement, x);
}

template<typename T_NUM>
int t_Sprintf_1(wchar_t* pBuf, size_t zBuf, LPCWSTR pReplacement, T_NUM x)
{
	return swprintf_s(pBuf, zBuf, pReplacement, x);
}

//======================================================================
//	std::basic_string �p�̃��[�e�B���e�B
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

//----------------------------------------------------------------------
//	AppendCharToString
//----------------------------------------------------------------------

NS_PLIB_END
