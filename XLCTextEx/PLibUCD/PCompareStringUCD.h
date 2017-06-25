//	XLCTextEx_1.0x	:	PLibUCD

//	PLibUCD:	PCompareStringUCD.h
//
#pragma once

NS_PLIB_UNICODE_BEGIN

//======================================================================
//	class PCCompareStringUCDOptions
//
//	#define NORM_IGNORECASE				0x00000001	// ignore case
//	#define NORM_IGNORENONSPACE			0x00000002	// ignore nonspacing chars
//	#define NORM_IGNORESYMBOLS			0x00000004	// ignore symbols
//	#define LINGUISTIC_IGNORECASE		0x00000010	// linguistically appropriate 'ignore case'
//	#define LINGUISTIC_IGNOREDIACRITIC	0x00000020	// linguistically appropriate 'ignore nonspace'
//	#define NORM_IGNOREKANATYPE			0x00010000	// ignore kanatype
//	#define NORM_IGNOREWIDTH			0x00020000	// ignore width
//	#define NORM_LINGUISTIC_CASING		0x08000000	// use linguistic rules for casing
//	#define SORT_STRINGSORT				0x00001000	// use string sort method
//======================================================================
//----------------------------------------------------------------------
//	�g���I�v�V����
//----------------------------------------------------------------------

//	�G���[
#define	CSTRUCD_ERROR					0x00000000

//	���K�����Ĕ�r����
#define	CSTRUCD_NORMALIZE				0x00100000

//	�Ђ炪�ȁE�J�^�J�i�̏������ƒʏ�̕�������ʂ��Ȃ�
#define	CSTRUCD_IGNOREKANACASE			0x00200000

//	�e�t���O�̏�
#define	COMPARESTRINGUCD_IS_NORMALIZE(f)		(((f) & CSTRUCD_NORMALIZE) != 0)
#define	COMPARESTRINGUCD_IS_IGNOREKANACASE(f)	(((f) & CSTRUCD_IGNOREKANACASE) != 0)

//	�e�t���O������

#define	COMPARESTRINGUCD_UNSET_NORMALIZE(f)			((f) &= ~CSTRUCD_NORMALIZE)
#define	COMPARESTRINGUCD_UNSET_IGNOREKANACASE(f)	((f) &= ~CSTRUCD_IGNOREKANACASE)

//	�e�t���O��ݒ�

#define	COMPARESTRING_SET_NORMALIZE(f)		((f) |= CSTRUCD_NORMALIZE)
#define	COMPARESTRING_SET_IGNOREKANACASE(f)	((f) |= CSTRUCD_IGNOREKANACASE)

//----------------------------------------------------------------------
//	class PCCompareStringUCDOptions
//----------------------------------------------------------------------
class PCCompareStringUCDOptions	: public PCCompareStringOptions
{
protected:
	BOOL	bIgnoreKanaCase;
	BOOL	bNormalize;

public:
	PCCompareStringUCDOptions()
		:	PCCompareStringOptions(),
			bNormalize(FALSE),
			bIgnoreKanaCase(FALSE)
	{
	}

	//------------------------------------------------------------
	//	PCCompareStringUCDOptions	�e�t���O�̉���
	//------------------------------------------------------------
	void UnsetNormalize()
	{
		bNormalize	= FALSE;
	}

	void UnsetIgnoreKanaCase()
	{
		bIgnoreKanaCase	= FALSE;
	}

	//------------------------------------------------------------
	//	PCCompareStringUCDOptions	�e�t���O�̐ݒ�
	//------------------------------------------------------------
	void SetNormalize()
	{
		bNormalize	= TRUE;
	}

	void SetIgnoreKanaCase()
	{
		bIgnoreKanaCase	= TRUE;
	}

	//------------------------------------------------------------
	//	PCCompareStringUCDOptions::Reset
	//------------------------------------------------------------
	virtual void Reset()
	{
		PCCompareStringOptions::Reset();
		UnsetIgnoreKanaCase();
	}

	//------------------------------------------------------------
	//	PCCompareStringUCDOptions::CopyFrom
	//------------------------------------------------------------
	virtual void CopyFrom(PCCompareStringUCDOptions* pSrc)
	{
		PCCompareStringOptions::CopyFrom(pSrc);

		bNormalize		= pSrc->bNormalize;
		bIgnoreKanaCase	= pSrc->bIgnoreKanaCase;
	}

	//------------------------------------------------------------
	//	PCCompareStringUCDOptions::CopyTo
	//------------------------------------------------------------
	virtual void CopyTo(PCCompareStringUCDOptions* pDst)
	{
		PCCompareStringOptions::CopyTo(pDst);

		pDst->bNormalize		= bNormalize;
		pDst->bIgnoreKanaCase	= bIgnoreKanaCase;
	}

	//------------------------------------------------------------
	//	PCCompareStringOptions:	�e�t���O���擾����
	//------------------------------------------------------------
	BOOL IsNormalize()		{ return bNormalize; }
	BOOL IsIgnoreKanaCase()	{ return bIgnoreKanaCase; }

	virtual bool NoOption()
	{
		return (PCCompareStringOptions::NoOption() && bNormalize == FALSE && bIgnoreKanaCase == FALSE);
	}

	DWORD GetCompareStringUCDFlags()
	{
		DWORD	dwr	= dwCompareStringFlags;

		if (IsNormalize())		dwr |= CSTRUCD_NORMALIZE;
		if (IsIgnoreKanaCase())	dwr |= CSTRUCD_IGNOREKANACASE;
		return dwr;
	}

	//------------------------------------------------------------
	//	�f�o�b�O�p
	//------------------------------------------------------------
#ifdef	PDEBUG

	void Debug(T_STRING_U* pstrDebug);
	bool DebugSimple(T_STRING_U* pstrDebug);

#endif
};


//======================================================================
//	�֐��̐錾
//======================================================================
//-----------------------------------------------------------------
//	StrFoldingUCD
//-----------------------------------------------------------------
bool	StrFoldingUCD(UCPSTRING*	pucsFolded,
					  UCPSTRING*	pucsSrc,
					  DWORD			dwFlags,
					  T_PCSTR_U		pszLocale);

//-----------------------------------------------------------------
//	CompareConvertedStringUCD	(1)	PIFUnicodeBuffer �������Ƃ���B
//
//	�e��������A�o�b�t�@�̌��݂̏����ʒu����Ō�܂ŕϊ����Ă����r����B
//	���K���Ȃǂɂ�� 1 �̃R�[�h�|�C���g�������̃R�[�h�|�C���g�ɕϊ�����铙�A
//	�Ή�������Ă��܂��ꍇ�ȂǂɎg�p����B
//-----------------------------------------------------------------
int		CompareConvertedStringUCD(PIFUnicodeBuffer*	pUBuf1,
								  PIFUnicodeBuffer*	pUBuf2,
								  DWORD				dwFlags,
								  T_PCSTR_U			pszLocale);

int		CompareConvertedStringUCD(const T_UCP*	pStr1,
								  int			izStr1,
								  const T_UCP*	pStr2,
								  int			izStr2,
								  DWORD			dwFlags,
								  T_PCSTR_U		pszLocale);

int		CompareConvertedStringUCD(T_PCSTR_U	pStr1,
								  int		izStr1,
								  T_PCSTR_U	pStr2,
								  int		izStr2,
								  DWORD		dwFlags,
								  T_PCSTR_U	pszLocale);

//-----------------------------------------------------------------
//	CompareCodepointUCD
//-----------------------------------------------------------------
int		CompareCodepointUCD(T_UCP		cpSrc1,
							T_UCP		cpSrc2,
							DWORD		dwFlags,
							T_PCSTR_U	pszLocale);

//-----------------------------------------------------------------
//	CompareStringUCD
//-----------------------------------------------------------------
int		CompareStringUCD(PIFUnicodeBuffer*	pUBuf1,
						 PIFUnicodeBuffer*	pUBuf2,
						 DWORD				dwFlags,
						 T_PCSTR_U			pszLocale);

int		CompareStringUCD(T_PCSTR_U	pStr1,
						 int		izStr1,
						 T_PCSTR_U	pStr2,
						 int		izStr2,
						 DWORD		dwFlags,
						 T_PCSTR_U	pszLocale);

int		CompareStringUCD(const T_UCP*	pStr1,
						 int			izStr1,
						 const T_UCP*	pStr2,
						 int			izStr2,
						 DWORD			dwFlags,
						 T_PCSTR_U		pszLocale);

int		CompareStringUCD(UCPSTRING*	puisStr1,
						 UCPSTRING*	puisStr2,
						 DWORD		dwFlags,
						 T_PCSTR_U	pszLocale);


NS_PLIB_UNICODE_END
