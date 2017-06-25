//	XLCTextEx_1.0x	:	PLibXLL

//	XLLException.h
//
#pragma once

//======================================================================
//	XLLException
//======================================================================
class XLLException	: public PLib::PException	{};

class XLLExceptionErrNull	: XLLException	{};
class XLLExceptionErrDiv0	: XLLException	{};
class XLLExceptionErrValue	: XLLException	{};
class XLLExceptionErrRef	: XLLException	{};
class XLLExceptionErrName	: XLLException	{};
class XLLExceptionErrNum	: XLLException	{};
class XLLExceptionErrNA		: XLLException	{};
