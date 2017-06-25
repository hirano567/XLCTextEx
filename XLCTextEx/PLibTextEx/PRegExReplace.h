//	XLCTextEx_1.0x	:	PLibTextEx

//	PRegExReplace.h
//
#pragma once

NS_PLIB_BEGIN

//======================================================================
//	PRegExReplace
//======================================================================
bool PRegExReplace(T_STRING_U*			pstrBuffer,
				   PCRegEx*				pciRegEx,
				   PCRegExReplacement*	pciReplacement,
				   PCRegExText*			pciText,
				   T_STRING_U*			pstrDebug,
				   int*					piMatches);

NS_PLIB_END
