//	XLCTextEx_1.0x	:	PLib

//	PException.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	PException
//
//	�v���W�F�N�g�Œ�`������O�N���X�̊��N���X
//
//	STL �� exception �ł͈ȉ��̃��\�b�h����`����Ă���B
//		__CLR_OR_THIS_CALL exception();
//		__CLR_OR_THIS_CALL exception(const char *const&);
//		__CLR_OR_THIS_CALL exception(const char *const&, int);
//		__CLR_OR_THIS_CALL exception(const exception&);
//		exception& __CLR_OR_THIS_CALL operator=(const exception&);
//		virtual __CLR_OR_THIS_CALL ~exception();
//		virtual const char * __CLR_OR_THIS_CALL what() const;
//	�܂��A�ȉ��̃����o����`����Ă���B
//		const char *_m_what;
//		int _m_doFree;
//======================================================================
class PException	: public std::exception
{
protected:
	std::string		_Str;
	std::wstring	_StrW;

public:
	//------------------------------------------------------------
	//	SetMessage
	//------------------------------------------------------------
	BOOL SetMessage(const char *const& pszMessageA);
	BOOL SetMessage(const wchar_t *const& pszMessageW);

	//------------------------------------------------------------
	//	PException	: �R���X�g���N�^	default
	//------------------------------------------------------------
	PException()
	{
	}

	//------------------------------------------------------------
	//	PException	: �R���X�g���N�^	���b�Z�[�W���w�肷��B
	//	int iDummy �� exception(const char *const&, int) �ɍ��킹�邽�߂̂��́B
	//------------------------------------------------------------
	PException(const char *const& pszMessageA, int iDummy = 0)
	{
		SetMessage(pszMessageA);
	}

	PException(const wchar_t *const& pszMessageW, int iDummy = 0)
	{
		SetMessage(pszMessageW);
	}

	//------------------------------------------------------------
	//	PException	: �R�s�[�R���X�g���N�^
	//------------------------------------------------------------
	PException(const PException& ciSrc)
	{
		try
		{
			_Str.assign(ciSrc._Str);
			_StrW.assign(ciSrc._StrW);
		}
		catch (...)	{}
	}

	//------------------------------------------------------------
	//	PException	operator=
	//------------------------------------------------------------
	PException& operator=(const PException& ciSrc)
	{
		try
		{
			_Str.assign(ciSrc._Str);
			_StrW.assign(ciSrc._StrW);
		}
		catch (...)	{}
		return *this;
	}

	//------------------------------------------------------------
	//	PException	�f�X�g���N�^
	//------------------------------------------------------------
	virtual ~PException() _THROW0()
	{
	}

	//------------------------------------------------------------
	//	PException::what, PException::whatW
	//------------------------------------------------------------
	virtual const char *	what()	const _THROW0()
	{
		return _Str.c_str();
	}

	virtual const wchar_t *	whatW()	const _THROW0()
	{
		return _StrW.c_str();
	}

	//------------------------------------------------------------
	//	PException::What	: what, whatW �p�̃e���v���[�g�֐�
	//------------------------------------------------------------
	template<typename T_CHAR>
	const T_CHAR* What()
	{
		return NULL;
	}
	template<>
	LPCSTR What<char>()
	{
		return what();
	}
	template<>
	LPCWSTR What<wchar_t>()
	{
		return whatW();
	}
};


//======================================================================
//	PException �̔h���N���X
//======================================================================
//----------------------------------------------------------------------
//	PLogicError
//----------------------------------------------------------------------
class PLogicError	: public NS_PLIB::PException
{
public:
	PLogicError()								: PException()							{}
	PLogicError(const char *const& pszMsgA)		: PException(pszMsgA)					{}
	PLogicError(const PLogicError& ciSrc)		: PException((const PException&)ciSrc)	{}
};

#define	THROWPE_LOGIC_ERROR(msg)	throw NS_PLIB::PLogicError(msg)

//----------------------------------------------------------------------
//	PRuntimeError
//----------------------------------------------------------------------
class PRuntimeError	: public NS_PLIB::PException
{
public:
	PRuntimeError()									: PException()							{}
	PRuntimeError(const char *const& pszMsgA)		: PException(pszMsgA)					{}
	PRuntimeError(const PRuntimeError& ciSrc)		: PException((const PException&)ciSrc)	{}
};

#define	THROWPE_RUNTIME_ERROR(msg)	throw NS_PLIB::PRuntimeError(msg)

//----------------------------------------------------------------------
//	POutOfRange	PLogicError �̔h���N���X
//----------------------------------------------------------------------
class POutOfRange	: public NS_PLIB::PLogicError
{
public:
	POutOfRange()								: PLogicError()								{}
	POutOfRange(const char *const& pszMsgA)		: PLogicError(pszMsgA)						{}
	POutOfRange(const POutOfRange& ciSrc)		: PLogicError((const PLogicError&)ciSrc)	{}
};

#define	THROWPE_OUT_OF_RANGE(msg)	throw NS_PLIB::POutOfRange(msg)

//----------------------------------------------------------------------
//	PInvalidParameter	PLogicError �̔h���N���X
//----------------------------------------------------------------------
class PInvalidParameter	: public NS_PLIB::PLogicError
{
public:
	PInvalidParameter()									: PLogicError()								{}
	PInvalidParameter(const char *const& pszMsgA)		: PLogicError(pszMsgA)						{}
	PInvalidParameter(const PInvalidParameter& ciSrc)	: PLogicError((const PLogicError&)ciSrc)	{}
};

#define	THROWPE_INVALID_PARAMETER(msg)	throw NS_PLIB::PInvalidParameter(msg)

//----------------------------------------------------------------------
//	PSyntaxError
//----------------------------------------------------------------------
class PSyntaxError		: public NS_PLIB::PException
{
public:
	PSyntaxError()								: PException()							{}
	PSyntaxError(const char *const& pszMsgA)	: PException(pszMsgA)					{}
	PSyntaxError(const PSyntaxError& ciSrc)		: PException((const PException&)ciSrc)	{}
};

#define	THROWPE_SYNTAX_ERROR(msg)	throw NS_PLIB::PSyntaxError(msg)

//----------------------------------------------------------------------
//	PInvalidData
//----------------------------------------------------------------------
class PInvalidData		: public NS_PLIB::PException
{
public:
	PInvalidData()								: PException()							{}
	PInvalidData(const char *const& pszMsgA)	: PException(pszMsgA)					{}
	PInvalidData(const PInvalidData& ciSrc)		: PException((const PException&)ciSrc)	{}
};

#define	THROWPE_INVALID_DATA(msg)	throw NS_PLIB::PInvalidData(msg)


//======================================================================
//	catch �p�̃}�N��
//======================================================================
//----------------------------------------------------------------------
//	return
//----------------------------------------------------------------------
#define	CATCH_AND_RETURN(rval)	\
catch (...)						\
{								\
	return (rval);				\
}

#define	CATCH_AND_RETURN_BAD_ALLOC(rval, msg)	\
catch (std::bad_alloc&)							\
{												\
	MSG_NOT_ENOUGH_MEMORY(msg);		\
	return (rval);								\
}												\
catch (...)										\
{												\
	return (rval);								\
}

//----------------------------------------------------------------------
//	goto
//----------------------------------------------------------------------
#define	CATCH_AND_GOTO(lab)	\
catch (...)					\
{							\
	goto lab;				\
}

#define	CATCH_AND_GOTO_BAD_ALLOC(lab, msg)	\
catch (std::bad_alloc&)						\
{											\
	MSG_NOT_ENOUGH_MEMORY(msg);	\
	goto lab;								\
}											\
catch (...)									\
{											\
	goto lab;								\
}

//----------------------------------------------------------------------
//	throw
//----------------------------------------------------------------------
#define	CATCH_AND_THROW(msg)			\
catch (...)								\
{										\
	throw	std::runtime_error(msg);	\
}

#define	CATCH_AND_THROW_BAD_ALLOC(tmsg, dmsg)	\
catch (std::bad_alloc&)							\
{												\
	MSG_NOT_ENOUGH_MEMORY(TEXTAW(##dmsg));		\
	throw	std::runtime_error(tmsg);			\
}												\
catch (...)										\
{												\
	throw	std::runtime_error(tmsg);			\
}

NS_PLIB_END
