//	XLCTextEx_1.0x	:	PLib

//	PCodePage.cpp
//
#include "stdafx.h"

NS_PLIB_BEGIN

//======================================================================
//	������̕ϊ�
//	�}���`�o�C�g�����񂩂� Unicode ������֕ϊ�����B
//======================================================================
//----------------------------------------------------------------------
//	GetSizeMBtoWC: �K�v�ȃo�b�t�@�T�C�Y���擾����B
//
//	�I�[�̃k�������͏����B
//	MultiByteToWideChar �֐��̎d�l�ɂ��A
//	iSrc �̒l�ɂ���āA������l�͎��̂悤�ɂȂ�B
//		-1		�I�[�̃k���������܂߂������B
//		���̒l	�I�[�͊܂߂Ȃ��B
//----------------------------------------------------------------------
bool GetSizeMBtoWC(size_t*	pzRequired,
				   LPCSTR	pSrc,
				   int		iSrc,
				   UINT		uiCodePage)
{
	int	iRet;

	if (pzRequired == NULL || pSrc == NULL)
	{
		return false;
	}
	*pzRequired	= 0;

	//	�ϊ���������̒����� 0 ���w�肷��ƁA�֐��͎��s����B
	if (iSrc < 1)
	{
		iSrc = -1;
	}

	iRet = MultiByteToWideChar(
		uiCodePage,	// (UINT) �R�[�h�y�[�W
		0,			// (DWORD) �����̎�ނ��w�肷��t���O
		pSrc,		// (LPCSTR) �}�b�v��������̃A�h���X
		iSrc,		// (int) �}�b�v��������̃o�C�g��
		NULL,		// (LPWSTR) �}�b�v�惏�C�h�����������o�b�t�@�̃A�h���X
		0			// (int) �o�b�t�@�̃T�C�Y
		);

	if (iRet > 0)
	{
		*pzRequired	= (size_t)iRet;
		return true;
	}
	else
	{
		return false;
	}
}

//----------------------------------------------------------------------
//	ConvertMBtoWC: �ϊ�����B
//
//	�I�[�̏����� iSrc �̒l�ɂ���ĈقȂ�B
//		-1		�I�[�̃k���������܂߂ĕϊ�����B
//		���̒l	�w�肳�ꂽ�������������ϊ�����B
//----------------------------------------------------------------------
bool ConvertMBtoWC(LPWSTR	pDst,
					 size_t	zDst,
					 size_t*	pzConverted,
					 LPCSTR	pSrc,
					 int		iSrc,
					 UINT	uiCodePage)
{
	int	iDst, iRet;
	
	if (pDst == NULL || zDst < 1 || pzConverted == NULL || pSrc == NULL)
	{
		return false;
	}
	*pzConverted	= 0;
	iDst	= (int)(zDst < INT_MAX ? zDst : INT_MAX);

	//	�ω���������̒����� 0 ���w�肷��ƁA�֐��͎��s����B
	if (iSrc < 1)
	{
		iSrc = -1;
	}

	iRet = MultiByteToWideChar(
		uiCodePage,	// (UINT) �R�[�h�y�[�W
		0,			// (DWORD) �����̎�ނ��w�肷��t���O
		pSrc,		// (LPCSTR) �}�b�v��������̃A�h���X
		iSrc,		// (int) �}�b�v��������̃o�C�g��
		pDst,		// (LPWSTR) �}�b�v�惏�C�h�����������o�b�t�@�̃A�h���X
		iDst		// (int) �o�b�t�@�̃T�C�Y
		);
	if (iSrc > 0)
	{
		*(pDst + iRet) = L'\0';
	}

	if (iRet > 0)
	{
		*pzConverted	= (size_t)iRet;
		return true;
	}
	else
	{
		*pzConverted	= 0;
		return false;
	}
}

/*
//----------------------------------------------------------------------
//	ConvertMBtoWCMa: �o�b�t�@���m�ۂ��A�ϊ�����B
//
//	�I�[�ɂ̓k��������ǉ�����B
//	�o�b�t�@�̉���͌Ăяo�����ōs�����Ɓidelete[] ���g���j�B
//	�ϊ���̕�������Ԃ��B
//----------------------------------------------------------------------
bool ConvertMBtoWCMa(LPWSTR*	ppDst,
					   size_t*	pzDst,
					   LPCSTR	pSrc,
					   int		iSrc,
					   UINT	uiCodePage)
{
	size_t	zDst;
	int		iBuf;

	if (ppDst == NULL || pzDst == NULL || pSrc == NULL)
	{
		return false;
	}
	*ppDst	= NULL;
	*pzDst	= 0;

	//	�K�v�ȃo�b�t�@�T�C�Y�𒲂ׂ�B
	if (!GetSizeMBtoWC(&zDst, pSrc, iSrc, uiCodePage))
	{
		THROWPE_RUNTIME_ERROR("ConvertMBtoWCMa: GetSizeMBtoWC");
		return false;
	}
	if (zDst > INT_MAX - 1)
	{
		return false;
	}

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

	try
	{
		*ppDst = new wchar_t[iBuf];
	}
	CATCH_AND_RETURN_BAD_ALLOC(false, "");

	if (!ConvertMBtoWC(*ppDst, (size_t)iBuf, pzDst, pSrc, iSrc, uiCodePage))
	{
		goto ERROR_HANDLING;
	}

	return true;

ERROR_HANDLING:
	delete[]	*ppDst;
	*ppDst	= NULL;
	return false;
}
*/

//======================================================================
//	������̕ϊ�: Unicode �����񂩂�}���`�o�C�g������֕ϊ�����B
//======================================================================
//----------------------------------------------------------------------
//	GetSizeWCtoMB	:	�K�v�ȃo�b�t�@�T�C�Y�����߂�B
//
//	�I�[�̃k�������͏����B
//	MultiByteToWideChar �֐��̎d�l�ɂ��A
//	iSrc �̒l�ɂ���āA������l�͎��̂悤�ɂȂ�B
//		-1		�I�[�̃k���������܂߂������B
//		���̒l	�I�[�͊܂߂Ȃ��B
//----------------------------------------------------------------------
bool GetSizeWCtoMB(size_t*		pzRequired,
					 LPCWSTR	pSrc,
					 int	iSrc,
					 UINT		uiCodePage)
{
	int	iRet;

	if (pzRequired == NULL || pSrc == NULL)
	{
		return false;
	}
	*pzRequired	= 0;

	//	�ω���������̒����� 0 ���w�肷��ƁA�֐��͎��s����B
	if (iSrc < 1)
	{
		iSrc = -1;
	}

	iRet	= WideCharToMultiByte(
		uiCodePage,	// �R�[�h�y�[�W
		0,			// �������x�ƃ}�b�s���O���@�����肷��t���O
		pSrc,		// ���C�h������̃A�h���X
		iSrc,		// ���C�h������̕�����
		NULL,		// �V������������󂯎��o�b�t�@�̃A�h���X
		0,			// �V������������󂯎��o�b�t�@�̃T�C�Y
		NULL,		// �}�b�v�ł��Ȃ������̊���l�̃A�h���X
		NULL		// ����̕������g�����Ƃ��ɃZ�b�g����t���O�̃A�h���X
		);

	if (iRet > 0)
	{
		*pzRequired	= (size_t)iRet;
		return true;
	}
	else
	{
		return false;
	}
}

//----------------------------------------------------------------------
//	ConvertWCtoMB	:	�ϊ�����B�ϊ���̕�������Ԃ��B
//
//	�I�[�̏����� iSrc �̒l�ɂ���ĈقȂ�B
//		-1		�I�[�̃k���������܂߂ĕϊ�����B
//		���̒l	�w�肳�ꂽ�������������ϊ�����B
//----------------------------------------------------------------------
bool ConvertWCtoMB(LPSTR		pDst,
					 size_t		zDst,
					 size_t*		pzConverted,
					 LPCWSTR	pSrc,
					 int	iSrc,
					 UINT		uiCodePage)
{
	int	iDst, iRet;
	
	if (pDst == NULL || zDst < 1 || pzConverted == NULL || pSrc == NULL)
	{
		return false;
	}
	*pzConverted	= 0;
	iDst	= (int)(zDst < INT_MAX ? zDst : INT_MAX);

	//	�ϊ���������̒����� 0 ���w�肷��ƁA�֐��͎��s����B
	if (iSrc < 1)
	{
		iSrc = -1;
	}

	iRet	= WideCharToMultiByte(
		uiCodePage,	// �R�[�h�y�[�W
		0,			// �������x�ƃ}�b�s���O���@�����肷��t���O
		pSrc,		// ���C�h������̃A�h���X
		iSrc,		// ���C�h������̕�����
		pDst,		// �V������������󂯎��o�b�t�@�̃A�h���X
		iDst,		// �V������������󂯎��o�b�t�@�̃T�C�Y
		NULL,		// �}�b�v�ł��Ȃ������̊���l�̃A�h���X
		NULL		// ����̕������g�����Ƃ��ɃZ�b�g����t���O�̃A�h���X
		);
	if (iSrc > 0)
	{
		*(pDst + iRet) = '\0';
	}

	if (iRet > 0)
	{
		*pzConverted	= (size_t)iRet;
		return true;
	}
	else
	{
		*pzConverted	= 0;
		return false;
	}
}

/*
//----------------------------------------------------------------------
//	ConvertWCtoMBMa	:	�K�v�ȃo�b�t�@���m�ۂ��A�ϊ�����B�ϊ���̕�������Ԃ��B
//
//	�I�[�ɂ̓k��������ǉ�����B
//	�o�b�t�@�̉���͌Ăяo�����ōs�����Ɓidelete[] ���g���j�B
//	�ϊ���̕�������Ԃ��B
//----------------------------------------------------------------------
bool ConvertWCtoMBMa(LPSTR*	ppDst,
					 size_t*	pzDst,
					 LPCWSTR	pSrc,
					 int	iSrc,
					 UINT	uiCodePage)
{
	size_t	zDst;
	int		iBuf;

	if (ppDst == NULL || pzDst == NULL || pSrc == NULL)
	{
		return false;
	}
	*ppDst	= NULL;
	*pzDst	= 0;

	//	�K�v�ȃo�b�t�@�T�C�Y�𒲂ׂ�B
	if (!GetSizeWCtoMB(&zDst, pSrc, iSrc, uiCodePage))
	{
		THROWPE_RUNTIME_ERROR("ConvertMBtoWCMa (2)");
		return false;
	}
	if (zDst > INT_MAX - 1)
	{
		return false;
	}

	//	�K�v�ȃo�b�t�@���m�ۂ��A�ϊ�����B
	if (iSrc > 0)
	{
		iBuf = (int)zDst + 1;
	}
	else
	{
		iBuf = (int)zDst;
	}

	try
	{
		*ppDst = new char[iBuf];
	}
	CATCH_AND_RETURN_BAD_ALLOC(false, "");

	if (!ConvertWCtoMB(*ppDst, (size_t)iBuf, pzDst, pSrc, iSrc, uiCodePage))
	{
		goto ERROR_HANDLING;
	}

	return true;

ERROR_HANDLING:
	delete[]	*ppDst;
	*ppDst	= NULL;
	return false;
}
*/
/*
//======================================================================
//	������̕ϊ�: �}���`�o�C�g������Ԃŕϊ�����B
//======================================================================
//----------------------------------------------------------------------
//	ConvertMtoMMa: �o�b�t�@���m�ۂ��A�ϊ�����B
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
bool ConvertMBtoMBMa(LPSTR*	ppDst,
					 size_t*	pzDst,
					 LPCSTR		pSrc,
					 int		iSrc,
					 UINT		uCPDst,
					 UINT		uCPSrc)
{
	LPWSTR	pTempW	= NULL;
	size_t	zSrc, zTemp;
	bool	bRet;

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
		return NS_PLIB::StrCopyMa<char>(ppDst, pzDst, pSrc, zSrc);
	}
	//	�R�[�h�y�[�W���قȂ�ꍇ�B
	else
	{
		if (!ConvertMBtoWCMa(&pTempW, &zTemp, pSrc, iSrc, uCPSrc))	return false;
		if (zTemp > (size_t)(INT_MAX - 1))	return false;

		bRet = ConvertWCtoMBMa(ppDst, pzDst, pTempW, (int)zTemp, uCPDst);
		delete[] pTempW;
		return bRet;
	}

	return false;
}
*/

//======================================================================
//	������̕ϊ�: std::string �� std::wstring �̕ϊ�
//======================================================================
//----------------------------------------------------------------------
//	ConvertStringToWString
//----------------------------------------------------------------------
bool ConvertStringToWString(std::wstring* pWString, std::string* pString)
{
	LPWSTR	pBuffer	= NULL;
	size_t	zSize;
	bool	bConvertStringToWString	= false;

	if (ConvertMBtoWCMa(&pBuffer, &zSize, pString->c_str(), (int)pString->size(), CP_ACP))
	{
		try
		{
			pWString->assign(pBuffer, zSize);
			bConvertStringToWString	= true;
		}
		catch (std::bad_alloc&)
		{
			MSG_NOT_ENOUGH_MEMORY("");
		}
		catch (...)
		{
		}
	}

	delete[]	pBuffer;
	return bConvertStringToWString;
}

//----------------------------------------------------------------------
//	ConvertWStringToString
//----------------------------------------------------------------------
bool ConvertWStringToString(std::string* pString, std::wstring* pWString)
{
	LPSTR	pBuffer	= NULL;
	size_t	zSize;
	bool	bConvertWStringToString	= false;

	if (ConvertWCtoMBMa(&pBuffer, &zSize, pWString->c_str(), (int)pWString->size(), CP_ACP))
	{
		try
		{
			pString->assign(pBuffer, zSize);
			bConvertWStringToString	= true;
		}
		catch (std::bad_alloc&)
		{
			MSG_NOT_ENOUGH_MEMORY("");
		}
		catch (...)
		{
		}
	}

	delete[]	pBuffer;
	return bConvertWStringToString;
}


//======================================================================
//	ConvertStringToWString, ConvertWStringToString
//
//	std::string �� std::wstring �̕ϊ�
//======================================================================
bool	ConvertStringToWString(std::wstring* pWString, std::string* pString);
bool	ConvertWStringToString(std::string* pString, std::wstring* pWString);



NS_PLIB_END
