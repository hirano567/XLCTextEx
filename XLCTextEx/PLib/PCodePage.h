//	XLCTextEx_1.0x	:	PLib

//	PCodePage.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	�}���`�o�C�g������� Unicode ������ɕϊ�����B
//======================================================================
//----------------------------------------------------------------------
//	GetSizeMBtoWC	:	�K�v�ȃo�b�t�@�T�C�Y�����߂�B
//----------------------------------------------------------------------
bool	GetSizeMBtoWC(size_t*	pzRequired,
					  LPCSTR	pSrc,
					  int		iSrc,
					  UINT		uiCodePage	= CP_ACP);

//----------------------------------------------------------------------
//	ConvertMBtoWC	:	�ϊ�����B�ϊ���̕�������Ԃ��B
//----------------------------------------------------------------------
bool	ConvertMBtoWC(LPWSTR	pDst,
					  size_t	zDst,
					  size_t*	pzConverted,
					  LPCSTR	pSrc,
					  int		iSrc,
					  UINT		uiCodePage	= CP_ACP);

//----------------------------------------------------------------------
//	ConvertMBtoWCMa: �o�b�t�@���m�ۂ��A�ϊ�����B
//
//	�I�[�ɂ̓k��������ǉ�����B
//	�o�b�t�@�̉���͌Ăяo�����ōs�����ƁB
//	�ϊ���̕�������Ԃ��B
//----------------------------------------------------------------------
template<class C_MALLOC>
bool t_ConvertMBtoWCMa(LPWSTR*	ppDst,
					   size_t*	pzDst,
					   LPCSTR	pSrc,
					   int		iSrc,
					   UINT		uiCodePage)
{
	C_MALLOC	ciMAlloc;
	size_t		zDst;
	int			iBuf;

	if (ppDst == NULL || pzDst == NULL || pSrc == NULL)	return false;

	//	�K�v�ȃo�b�t�@�T�C�Y�𒲂ׂ�B
	if (!GetSizeMBtoWC(&zDst, pSrc, iSrc, uiCodePage))
	{
		THROWPE_RUNTIME_ERROR("ConvertMBtoWCMa: GetSizeMBtoWC");
		return false;
	}
	if (zDst > INT_MAX - 1)	return false;

	//	�K�v�ȃo�b�t�@���m�ۂ��A�ϊ�����B
	//	MultiByteToWideChar �̎d�l�ł́A�K�v�ȃo�b�t�@�T�C�Y�����߂�ہA
	//		iSrc �ɕ��̒l���w�肳���ƁA�I�[�� NULL ���܂߂Čv�Z����B
	//		iSrc �ɐ��̒l���w�肳���ƁA�I�[�� NULL �͍l�����Ȃ��B
	if (iSrc > 0)
	{
		iBuf = (int)zDst + 1;
	}
	else
	{
		iBuf = (int)zDst;
	}
	*ppDst = ciMAlloc.Allocate<wchar_t>(iBuf);

	if (!ConvertMBtoWC(*ppDst, (size_t)iBuf, pzDst, pSrc, iSrc, uiCodePage))	goto ERROR_HANDLING;
	return true;

ERROR_HANDLING:
	ciMAlloc.Deallocate(*ppDst);
	*ppDst	= NULL;
	return false;
}

inline bool ConvertMBtoWCMa(LPWSTR*	ppDst,
							size_t*	pzDst,
							LPCSTR	pSrc,
							int		iSrc,
							UINT	uiCodePage)
{
	return t_ConvertMBtoWCMa<PLib::PCMAlloc>(ppDst, pzDst, pSrc, iSrc, uiCodePage);
}

//======================================================================
//	Unicode ��������}���`�o�C�g������ɕϊ�����B
//======================================================================
//----------------------------------------------------------------------
//	GetSizeWCtoMB	:	�K�v�ȃo�b�t�@�T�C�Y�����߂�B
//----------------------------------------------------------------------
bool	GetSizeWCtoMB(size_t*	pzConverted,
					  LPCWSTR	pSrc,
					  int		iSrc,
					  UINT		uiCodePage	= CP_ACP);

//----------------------------------------------------------------------
//	ConvertWCtoMB	:	�ϊ�����B�ϊ���̕�������Ԃ��B
//----------------------------------------------------------------------
bool	ConvertWCtoMB(LPSTR		pDst,
					  size_t	zDst,
					  size_t*	pzConverted,
					  LPCWSTR	pSrc,
					  int		iSrc,
					  UINT		uiCodePage	= CP_ACP);

//----------------------------------------------------------------------
//	ConvertWCtoMBMa	:	�K�v�ȃo�b�t�@���m�ۂ��A�ϊ�����B�ϊ���̕�������Ԃ��B
//
//	�I�[�ɂ̓k��������ǉ�����B
//	�o�b�t�@�̉���͌Ăяo�����ōs�����ƁB
//	�ϊ���̕�������Ԃ��B
//----------------------------------------------------------------------
template<class C_MALLOC>
bool t_ConvertWCtoMBMa(LPSTR*	ppDst,
					   size_t*	pzDst,
					   LPCWSTR	pSrc,
					   int		iSrc,
					   UINT		uiCodePage)
{
	C_MALLOC	ciMAlloc;
	size_t		zDst;
	int			iBuf;

	if (ppDst == NULL || pzDst == NULL || pSrc == NULL)	return false;

	//	�K�v�ȃo�b�t�@�T�C�Y�𒲂ׂ�B
	if (!GetSizeWCtoMB(&zDst, pSrc, iSrc, uiCodePage))
	{
		THROWPE_RUNTIME_ERROR("ConvertMBtoWCMa (2)");
		return false;
	}
	if (zDst > INT_MAX - 1)	return false;

	//	�K�v�ȃo�b�t�@���m�ۂ��A�ϊ�����B
	if (iSrc > 0)
	{
		iBuf = (int)zDst + 1;
	}
	else
	{
		iBuf = (int)zDst;
	}
	*ppDst = ciMAlloc.Allocate<char>(iBuf);

	if (!ConvertWCtoMB(*ppDst, (size_t)iBuf, pzDst, pSrc, iSrc, uiCodePage))	goto ERROR_HANDLING;
	return true;

ERROR_HANDLING:
	ciMAlloc.Deallocate(*ppDst);
	*ppDst	= NULL;
	return false;
}

inline bool ConvertWCtoMBMa(LPSTR*	ppDst,
							size_t*	pzDst,
							LPCWSTR	pSrc,
							int		iSrc,
							UINT	uiCodePage)
{
	return t_ConvertWCtoMBMa<PLib::PCMAlloc>(ppDst, pzDst, pSrc, iSrc, uiCodePage);
}

//======================================================================
//	������̕ϊ�: �}���`�o�C�g������Ԃŕϊ�����B
//======================================================================
//----------------------------------------------------------------------
//	ConvertMBtoMBMa: �o�b�t�@���m�ۂ��A�ϊ�����B
//
//	�ϊ��Ώۂ̕�����́A�k���I��������łȂ���΂Ȃ�Ȃ��B
//	�o�b�t�@�̉���͌Ăяo�����ōs�����Ɓidelete[] ���g���j�B
//	�ϊ���̕�������Ԃ��B
//	�G���[���N�������ꍇ�͕��̒l��Ԃ��B�iFAILED() �}�N���Ŕ���ł���B�j
//----------------------------------------------------------------------
//	�K�v�ȃo�b�t�@���m�ۂ��A�ϊ�����B
//	�ϊ��Ώۂ̕�����́A�k���I��������łȂ���΂Ȃ�Ȃ��B
//	�ϊ���̕�������Ԃ��B
//	�G���[���N�������ꍇ�͕��̒l��Ԃ��B�iFAILED() �}�N���Ŕ���ł���B�j
template<class C_MALLOC>
bool t_ConvertMBtoMBMa(LPSTR*	ppDst,
					   size_t*	pzDst,
					   LPCSTR	pSrc,
					   int		iSrc,
					   UINT		uCPDst,
					   UINT		uCPSrc)
{
	C_MALLOC	ciMAlloc;
	LPWSTR		pTempW	= NULL;
	size_t		zSrc, zTemp;
	bool		bRet;

	//	�R�[�h�y�[�W���������ꍇ�B
	if (uCPDst== uCPSrc)
	{
		if (iSrc < 1)
		{
			if (!NS_PLIB::t_StrLen<char>(&zSrc, pSrc))	return false;
		}
		else
		{
			zSrc	= (size_t)iSrc;
		}
		return NS_PLIB::t_StrCopyMa<char, C_MALLOC>(ppDst, pzDst, pSrc, zSrc);
	}
	//	�R�[�h�y�[�W���قȂ�ꍇ�B
	else
	{
		if (!t_ConvertMBtoWCMa<C_MALLOC>(&pTempW, &zTemp, pSrc, iSrc, uCPSrc))	return false;
		if (zTemp > (size_t)(INT_MAX - 1))	return false;

		bRet = t_ConvertWCtoMBMa<C_MALLOC>(ppDst, pzDst, pTempW, (int)zTemp, uCPDst);
		ciMAlloc.Deallocate(pTempW);
		return bRet;
	}

	return false;
}

inline bool ConvertMBtoMBMa(LPSTR*	ppDst,
							size_t*	pzDst,
							LPCSTR	pSrc,
							int		iSrc,
							UINT	uCPDst,
							UINT	uCPSrc)
{
	return t_ConvertMBtoMBMa<PLib::PCMAlloc>(ppDst, pzDst, pSrc, iSrc, uCPDst, uCPSrc);
}


//======================================================================
//	ConvertStringToWString, ConvertWStringToString
//
//	std::string �� std::wstring �̕ϊ�
//======================================================================
bool	ConvertStringToWString(std::wstring* pWString, std::string* pString);
bool	ConvertWStringToString(std::string* pString, std::wstring* pWString);


//======================================================================
//	class PCPStrConverter
//
//	�����Ƀo�b�t�@�������A�ϊ����s��ꂽ�ꍇ�A�ϊ���̕�������i�[���Ă����B
//	�o�b�t�@�p�� PCStrBuffer �N���X�� PGClasses.h �Œ�`����Ă���B
//======================================================================
#define	CONVERTER_BUFFER_SIZE_DEFAULT		256
#define	CONVERTER_BUFFER_SIZE_MAX_DEFAULT	INT_MAX

#define	CONVERTER_KEEP_DEFAULT	0
#define	CONVERTER_KEEP			1
#define	CONVERTER_NOT_KEEP		-1

//----------------------------------------------------------------------
//	class PCPStrConverter_base
//----------------------------------------------------------------------
template<
	typename	TC_DST,
	typename	TC_SRC,
	class		C_MALLOC		= NS_PLIB::PCMAllocArray,
	size_t		BUFFER_SIZE		= CONVERTER_BUFFER_SIZE_DEFAULT,
	size_t		BUFFER_SIZE_MAX	= CONVERTER_BUFFER_SIZE_MAX_DEFAULT
>
class PCPStrConverter_base
	: public PCStrBuffer<TC_DST, C_MALLOC, BUFFER_SIZE, BUFFER_SIZE_MAX>
{
protected:
	typedef	TC_DST*			T_PDST;
	typedef	const TC_DST*	T_PCDST;
	typedef	const TC_SRC*	T_PCSRC;

	size_t	zStrSize;	//	�o�b�t�@�Ɋi�[���Ă��镶����̒����B�I�[�� NULL �͊܂܂Ȃ��B

public:
	//------------------------------------------------------------
	//	�R���X�g���N�^�ƃf�X�g���N�^
	//------------------------------------------------------------
	PCPStrConverter_base()
		:	PCStrBuffer(),
			zStrSize(0)
	{
	}

	~PCPStrConverter_base()
	{
	}

	//------------------------------------------------------------
	//	Convert
	//------------------------------------------------------------
	virtual bool Convert(T_PCDST* ppDst, size_t* pzDst, T_PCSRC pSrc, size_t zSrc,
		UINT uiCP = CP_ACP, int iKeep = CONVERTER_KEEP_DEFAULT)
	{
		return false;
	}

	//------------------------------------------------------------
	//	ClearBuffer
	//------------------------------------------------------------
	void ClearBuffer()
	{
		*pBuffer	= NULL;
		zStrSize	= 0;
	}

	//------------------------------------------------------------
	//	ReadBuffer
	//------------------------------------------------------------
	bool ReadBuffer(T_PCDST* ppConverted, size_t* pzConverted)
	{
		*ppConverted	= pBuffer;
		*pzConverted	= zStrSize;
		return (zStrSize > 0);
	}

	//------------------------------------------------------------
	//	WriteBuffer
	//------------------------------------------------------------
	bool WriteBuffer(T_PCDST pStr, size_t zStr)
	{
		if (pStr == NULL || zStr < 1)	return false;
		if (Write(pStr, zStr))
		{
			zStrSize	= zStr;
			return true;
		}
		return false;
	}
};

//----------------------------------------------------------------------
//	class PCPStrConverter
//----------------------------------------------------------------------
template<
	typename	TC_DST,
	typename	TC_SRC,
	class		C_MALLOC		= NS_PLIB::PCMAlloc,
	size_t		BUFFER_SIZE		= CONVERTER_BUFFER_SIZE_DEFAULT,
	size_t		BUFFER_SIZE_MAX	= CONVERTER_BUFFER_SIZE_MAX_DEFAULT
>
class PCPStrConverter
	:	public PCPStrConverter_base<TC_DST, TC_SRC, C_MALLOC, BUFFER_SIZE, BUFFER_SIZE_MAX>
{
public:
	PCPStrConverter()	: PCPStrConverter_base()	{}
	~PCPStrConverter()	{}
};
//----------------------------------------------------------------------
//	class PCPStrConverter	: char <- char
//----------------------------------------------------------------------
template<class C_MALLOC, size_t BUFFER_SIZE, size_t BUFFER_SIZE_MAX>
class PCPStrConverter<char, char, C_MALLOC, BUFFER_SIZE, BUFFER_SIZE_MAX>
	:	public PCPStrConverter_base<char, char, C_MALLOC, BUFFER_SIZE, BUFFER_SIZE_MAX>
{
public:
	//------------------------------------------------------------
	//	�R���X�g���N�^�ƃf�X�g���N�^
	//------------------------------------------------------------
	PCPStrConverter()	: PCPStrConverter_base()	{}
	~PCPStrConverter()	{}

	//------------------------------------------------------------
	//	Convert
	//------------------------------------------------------------
	bool Convert(LPCSTR* ppDst, size_t* pzDst, LPCSTR pSrc, size_t zSrc,
		UINT uiCP = CP_ACP, int iKeep = CONVERTER_KEEP_DEFAULT)
	{
		UNREFERENCED_PARAMETER(uiCP);

		if (ppDst == NULL || pzDst == NULL)	return false;
		if (pSrc == NULL || zSrc < 1)		goto ERROR_HANDLING;

		if (iKeep == CONVERTER_KEEP)
		{
			if (!WriteBuffer(pSrc, zSrc))	goto ERROR_HANDLING;
			*ppDst	= pBuffer;
			*pzDst	= zStrSize;
		}
		else
		{
			//	�o�b�t�@�Ɋi�[���Ȃ��ꍇ�́A�\�[�X�����̂܂ܓn���B
			*ppDst	= pSrc;
			*pzDst	= zSrc;
		}
		return true;

ERROR_HANDLING:
		*ppDst	= NULL;
		*pzDst	= 0;
		return false;
	}
};
//----------------------------------------------------------------------
//	class PCPStrConverter	: char <- wchar_t
//----------------------------------------------------------------------
template<class C_MALLOC, size_t BUFFER_SIZE, size_t BUFFER_SIZE_MAX>
class PCPStrConverter<char, wchar_t, C_MALLOC, BUFFER_SIZE, BUFFER_SIZE_MAX>
	:	public PCPStrConverter_base<char, wchar_t, C_MALLOC, BUFFER_SIZE, BUFFER_SIZE_MAX>
{
public:
	//------------------------------------------------------------
	//	�R���X�g���N�^�ƃf�X�g���N�^
	//------------------------------------------------------------
	PCPStrConverter()	: PCPStrConverter_base()	{}
	~PCPStrConverter()	{}

	//------------------------------------------------------------
	//	Convert
	//------------------------------------------------------------
	bool Convert(LPCSTR* ppDst, size_t* pzDst, LPCWSTR pSrc, size_t zSrc,
		UINT uiCP = CP_ACP, int iKeep = CONVERTER_KEEP_DEFAULT)
	{
		size_t	zRequired;

		if (!GetSizeWCtoMB(&zRequired, pSrc, (int)zSrc, uiCP))
		{
			return false;
		}
		++zRequired;	//	�I�[�� NULL ��������ǉ����Ă����B
		if (zRequired > zBuffer)
		{
			if (!ExtendBuffer(zRequired))
			{
				return false;
			}
		}

		if (ConvertWCtoMB(pBuffer, zBuffer, &zStrSize, pSrc, (int)zSrc, CP_ACP))
		{
			*ppDst	= (LPCSTR)pBuffer;
			*pzDst	= zStrSize;
			return true;
		}
		*ppDst	= NULL;
		*pzDst	= 0;
		return false;
	}
};
//----------------------------------------------------------------------
//	class PCPStrConverter	: wchar_t <- char
//----------------------------------------------------------------------
template<class C_MALLOC, size_t BUFFER_SIZE, size_t BUFFER_SIZE_MAX>
class PCPStrConverter<wchar_t, char, C_MALLOC, BUFFER_SIZE, BUFFER_SIZE_MAX>
	:	public PCPStrConverter_base<wchar_t, char, C_MALLOC, BUFFER_SIZE, BUFFER_SIZE_MAX>
{
public:
	//------------------------------------------------------------
	//	�R���X�g���N�^�ƃf�X�g���N�^
	//------------------------------------------------------------
	PCPStrConverter()	: PCPStrConverter_base()	{}
	~PCPStrConverter()	{}

	//------------------------------------------------------------
	//	Convert
	//------------------------------------------------------------
	bool Convert(LPCWSTR* ppDst, size_t* pzDst, LPCSTR pSrc, size_t zSrc,
		UINT uiCP = CP_ACP, int iKeep = CONVERTER_KEEP_DEFAULT)
	{
		size_t	zRequired, zConverted;

		if (!GetSizeMBtoWC(&zRequired, pSrc, (int)zSrc, uiCP))
		{
			return false;
		}
		++zRequired;	//	�I�[�� NULL ��������ǉ����Ă����B
		if (zRequired > zBuffer)
		{
			if (!ExtendBuffer(zRequired))
			{
				return false;
			}
		}

		if (ConvertMBtoWC(pBuffer, zBuffer, &zConverted, pSrc, (int)zSrc, CP_ACP))
		{
			*ppDst	= (LPCWSTR)pBuffer;
			*pzDst	= zConverted;
			return true;
		}
		*ppDst	= NULL;
		*pzDst	= 0;
		return false;
	}
};
//----------------------------------------------------------------------
//	class PCPStrConverter	: wchar_t <- wchar_t
//----------------------------------------------------------------------
template<class C_MALLOC, size_t BUFFER_SIZE, size_t BUFFER_SIZE_MAX>
class PCPStrConverter<wchar_t, wchar_t, C_MALLOC, BUFFER_SIZE, BUFFER_SIZE_MAX>
	:	public PCPStrConverter_base<wchar_t, wchar_t, C_MALLOC, BUFFER_SIZE, BUFFER_SIZE_MAX>
{
public:
	//------------------------------------------------------------
	//	�R���X�g���N�^�ƃf�X�g���N�^
	//------------------------------------------------------------
	PCPStrConverter()	: PCPStrConverter_base()	{}
	~PCPStrConverter()	{}

	//------------------------------------------------------------
	//	Convert
	//------------------------------------------------------------
	bool Convert(LPCWSTR* ppDst, size_t* pzDst, LPCWSTR pSrc, size_t zSrc,
		UINT uiCP = CP_ACP, int iKeep = CONVERTER_KEEP_DEFAULT)
	{
		UNREFERENCED_PARAMETER(uiCP);

		if (ppDst == NULL || pzDst == NULL)	return false;
		if (pSrc == NULL || zSrc < 1)		goto ERROR_HANDLING;

		if (iKeep == CONVERTER_KEEP)
		{
			if (!WriteBuffer(pSrc, zSrc))	goto ERROR_HANDLING;
			*ppDst	= pBuffer;
			*pzDst	= zStrSize;
		}
		else
		{
			//	�o�b�t�@�Ɋi�[���Ȃ��ꍇ�́A�\�[�X�����̂܂ܓn���B
			*ppDst	= pSrc;
			*pzDst	= zSrc;
		}
		return true;

ERROR_HANDLING:
		*ppDst	= NULL;
		*pzDst	= 0;
		return false;
	}
};


//======================================================================
//	class PCStringConverter
//
//	�����ɕϊ��p�̃o�b�t�@�������Ă���B
//======================================================================
template<typename TC_DST, typename TC_SRC>
class PIStringConverter
{
protected:
	typedef	std::basic_string<TC_DST>	T_STRING_DST, *T_PSTRING_DST;
	typedef	std::basic_string<TC_SRC>	T_STRING_SRC, *T_PSTRING_SRC;

public:
	virtual bool Convert(T_PSTRING_DST pstrDst, T_PSTRING_SRC pstrSrc, UINT uiCPDst, UINT uiCPSrc) = 0;
};

//----------------------------------------------------------------------
//	class PCStringConverter	: �e���v���[�g�p�����[�^�`�F�b�N�p
//----------------------------------------------------------------------
template<typename TC_DST, typename TC_SRC>
class PCStringConverter	: public PIStringConverter<TC_DST, TC_SRC>
{
public:
	bool Convert(T_PSTRING_DST pstrDst, T_PSTRING_SRC pstrSrc, UINT uiCPDst, UINT uiCPSrc)
	{
		throw std::logic_error("PCStringConverter::Convert");
		return false;
	}
};
//----------------------------------------------------------------------
//	class PCStringConverter	: char <- char
//----------------------------------------------------------------------
template<>
class PCStringConverter<char, char>	: public PIStringConverter<char, char>
{
protected:
	PCStrBuffer<char>		ciBufA;
	PCStrBuffer<wchar_t>	ciBufW;

public:
	PCStringConverter()		{}
	~PCStringConverter()	{}

	bool Convert(T_PSTRING_DST pstrDst, T_PSTRING_SRC pstrSrc,
					UINT uiCPDst = CP_ACP, UINT uiCPSrc = CP_ACP)
	{
		size_t	zSizeA, zSizeW;

		if (pstrDst == NULL || pstrSrc == NULL)	return false;

		if (uiCPDst == uiCPSrc)
		{
			try
			{
				pstrDst->assign(pstrSrc->c_str(), pstrSrc->size());
			}
			CATCH_AND_RETURN_BAD_ALLOC(false, "");
			return true;
		}
		else
		{
			//	UTF-16 �ɕϊ�����B�܂��A�K�v�ȃo�b�t�@�T�C�Y�����߂�B
			if (!NS_PLIB::GetSizeMBtoWC(
				&zSizeW, pstrSrc->c_str(), (int)(pstrSrc->size()), uiCPSrc))
			{
				return false;
			}
			if (ciBufW.Size() < zSizeW)
			{
				if (!ciBufW.ExtendBuffer(zSizeW))	return false;
			}
			if (!NS_PLIB::ConvertMBtoWC(ciBufW.Buffer(), ciBufW.Size(), &zSizeW,
				pstrSrc->c_str(), (int)(pstrSrc->size()), uiCPSrc))
			{
				return false;
			}

			//	uiCPDst �ɕϊ�����B
			if (!NS_PLIB::GetSizeWCtoMB(&zSizeA, ciBufW.Buffer(), (int)zSizeW, uiCPDst))
			{
				return false;
			}
			if (ciBufA.Size() < zSizeA)
			{
				if (!ciBufA.ExtendBuffer(zSizeA))	return false;
			}
			if (!NS_PLIB::ConvertWCtoMB(ciBufA.Buffer(), ciBufA.Size(), &zSizeA,
				ciBufW.Buffer(), (int)(ciBufW.Size()), uiCPDst))
			{
				return false;
			}
			
			//	string �Ɋi�[����B
			try
			{
				pstrDst->assign(ciBufA.Buffer(), ciBufA.Size());
			}
			CATCH_AND_RETURN_BAD_ALLOC(false, "");
		}
		return true;
	}
};
//----------------------------------------------------------------------
//	class PCStringConverter	: char <- wchar_t
//----------------------------------------------------------------------
template<>
class PCStringConverter<char, wchar_t>	: public PIStringConverter<char, wchar_t>
{
protected:
	PCStrBuffer<char>		ciBufA;

public:
	PCStringConverter()		{}
	~PCStringConverter()	{}

	bool Convert(T_PSTRING_DST pstrDst, T_PSTRING_SRC pstrSrc,
					UINT uiCPDst = CP_ACP, UINT uiCPSrc = CP_ACP)
	{
		size_t	zSize;

		if (!NS_PLIB::GetSizeWCtoMB(&zSize,
			pstrSrc->c_str(), (int)(pstrSrc->size()), uiCPDst))
		{
			return false;
		}
		if (zSize > ciBufA.Size())
		{
			if (!ciBufA.ExtendBuffer(zSize))	return false;
		}
		if (!NS_PLIB::ConvertWCtoMB(ciBufA.Buffer(), ciBufA.Size(), &zSize,
			pstrSrc->c_str(), pstrSrc->size(), uiCPDst))
		{
			return false;
		}
		try
		{
			pstrDst->assign(ciBufA.Buffer(), zSize);
		}
		CATCH_AND_RETURN_BAD_ALLOC(false, "");
		return true;
	}
};
//----------------------------------------------------------------------
//	class PCStringConverter	: wchar_t <- char
//----------------------------------------------------------------------
template<>
class PCStringConverter<wchar_t, char>	: public PIStringConverter<wchar_t, char>
{
protected:
	PCStrBuffer<wchar_t>	ciBufW;

public:
	PCStringConverter()		{}
	~PCStringConverter()	{}

	bool Convert(T_PSTRING_DST pstrDst, T_PSTRING_SRC pstrSrc,
					UINT uiCPDst = CP_ACP, UINT uiCPSrc = CP_ACP)
	{
		size_t	zSize;

		if (!NS_PLIB::GetSizeMBtoWC(&zSize,
			pstrSrc->c_str(), (int)(pstrSrc->size()), uiCPSrc))
		{
			return false;
		}
		if (zSize > ciBufW.Size())
		{
			if (!ciBufW.ExtendBuffer(zSize))	return false;
		}
		if (!NS_PLIB::ConvertMBtoWC(ciBufW.Buffer(), ciBufW.Size(), &zSize,
			pstrSrc->c_str(), pstrSrc->size(), uiCPSrc))
		{
			return false;
		}
		try
		{
			pstrDst->assign(ciBufW.Buffer(), zSize);
		}
		CATCH_AND_RETURN_BAD_ALLOC(false, "");
		return true;
	}
};
//----------------------------------------------------------------------
//	class PCStringConverter	: wchar_t <- wchar_t
//----------------------------------------------------------------------
template<>
class PCStringConverter<wchar_t, wchar_t>	: public PIStringConverter<wchar_t, wchar_t>
{
protected:
	typedef	std::basic_string<wchar_t>	T_STRING, *T_PSTRING;

public:
	PCStringConverter()		{}
	~PCStringConverter()	{}

	bool Convert(T_PSTRING_DST pstrDst, T_PSTRING_SRC pstrSrc,
					UINT uiCPDst = CP_ACP, UINT uiCPSrc = CP_ACP)
	{
		//	�R�s�[���邾���ł悢�B
		try
		{
			pstrDst->assign(pstrSrc->c_str(), pstrSrc->size());
		}
		CATCH_AND_RETURN_BAD_ALLOC(false, "");
		return true;
	}
};

NS_PLIB_END
