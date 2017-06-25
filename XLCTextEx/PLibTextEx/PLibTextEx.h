//	XLCTextEx_1.0x	:	PLibTextEx

//	XLCTextEx_1.01	2013/06/02
//	XLCTextEx_1.02

//	PLibTextEx.h
//
#pragma once

#include "PLib.h"
#include "PLibUCD.h"


#ifndef NS_PTEXTEX
#define NS_PTEXTEX				TextEx
#define NS_PLIB_TEXTEX_BEGIN	namespace NS_PLIB { namespace NS_PTEXTEX {
#define NS_PLIB_TEXTEX_END		}}
#endif

#ifndef NS_REGEX
#define NS_REGEX			RegEx
#define NS_PLIB_REGEX_BEGIN	namespace NS_PLIB {	namespace NS_REGEX {
#define NS_PLIB_REGEX_END	}}
#endif

//#define	PDEBUG_MATCH

#include "PTextExUtility.h"
#include "PGClassesText.h"
#include "PRegEx.h"
#include "PRegExUtility.h"
#include "PRegExText.h"
#include "PBracketEx.h"
#include "PCRegEx.h"
#include "PRegExReplace.h"
#include "PTransChar.h"
#include "PTransCharPreset.h"

#include "PRegExDebug.h"

//======================================================================
//	PLibTextEx ÇÃèâä˙âªÇ∆èIóπèàóù
//======================================================================
NS_PLIB_TEXTEX_BEGIN

BOOL	Init();
void	Cleanup();

NS_PLIB_TEXTEX_END
