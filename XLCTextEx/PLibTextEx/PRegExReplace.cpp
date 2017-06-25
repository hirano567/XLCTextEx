//	XLCTextEx_1.0x	:	PLibTextEx

//	PRegExReplace.cpp
//
#include "stdafx.h"

NS_PLIB_BEGIN

//======================================================================
//	PRegExReplace
//======================================================================
bool PRegExReplace(T_STRING_U*			pstrBuffer,
				   PCRegEx*				pciRegEx,
				   PCRegExReplacement*	pciReplacement,
				   PCRegExText*			pciText,
				   T_STRING_U*			pstrDebug,
				   int*					piMatches)
{
	ITR_UCPSTRING	itrMatchB, itrMatchE, itrNext;
	ITR_UCPSTRING	itrTemp;
	int				iMatches	= 0;
	
	if (pstrBuffer == NULL || pciRegEx == NULL || pciReplacement == NULL || pciText == NULL)
		return false;

	pciText->Begin();
	pciText->InitReferences();
	pciText->InitGlobalMatching();

	pciText->GetBeginPos(itrMatchB);
	pciText->GetBeginPos(itrMatchE);
	if (!pciText->GetCurrentPos(itrNext))	THROWPE_LOGIC_ERROR("");
	if (!pciText->GetCurrentPos(pciText->GlobalMatching()->itrMatch))	THROWPE_LOGIC_ERROR("");

	do
	{
		if (!pciRegEx->Match(pciText))	break;
		++iMatches;

#ifdef	PDEBUG
		if  (pstrDebug != NULL)
		{
			pciText->Debug(pstrDebug);
			pstrDebug->append(TQU("\r\n"));
		}
#endif

		pciText->GetReference(itrMatchB, itrMatchE, 0);
		pciText->GetSubString(pstrBuffer, itrNext, itrMatchB);
		pciReplacement->Format(pstrBuffer, pciText);

		//	長さ 0 の文字列とマッチした場合。
		if (!pciText->GetCurrentPos(itrTemp))	THROWPE_LOGIC_ERROR("");
		if (pciText->GlobalMatching()->itrMatch	== itrTemp)
		{
			pciText->GlobalMatching()->bMatchZeroLength	= true;
		}
		//	それ以外
		else
		{
			pciText->GlobalMatching()->bMatchZeroLength	= false;
			pciText->GlobalMatching()->itrMatch			= itrTemp;
		}
		itrNext	= itrTemp;
	}
	while (!pciText->End() && pciText->IsGlobalMatching());

	pciText->GetSubStringFollowing(pstrBuffer, itrMatchE);
	pciText->ClearOptional();
	if (piMatches != NULL)	*piMatches = iMatches;
	return true;
}

NS_PLIB_END
