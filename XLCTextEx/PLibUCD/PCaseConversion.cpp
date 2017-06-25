//	XLCTextEx_1.0x	:	PLibUCD

//	PLibUCD:	PCaseFolding.cpp
//
#include "stdafx.h"

NS_PLIB_UNICODE_BEGIN

//======================================================================
//	CaseFolding.txt のデータ
//======================================================================
//----------------------------------------------------------------------
//	Common and Full Case Folding	: Codepage List
//----------------------------------------------------------------------
UINT	CaseFoldingCF_CpList0041[]	= { 0x0061, 0 };
UINT	CaseFoldingCF_CpList0042[]	= { 0x0062, 0 };
UINT	CaseFoldingCF_CpList0043[]	= { 0x0063, 0 };
UINT	CaseFoldingCF_CpList0044[]	= { 0x0064, 0 };
UINT	CaseFoldingCF_CpList0045[]	= { 0x0065, 0 };
UINT	CaseFoldingCF_CpList0046[]	= { 0x0066, 0 };
UINT	CaseFoldingCF_CpList0047[]	= { 0x0067, 0 };
UINT	CaseFoldingCF_CpList0048[]	= { 0x0068, 0 };
UINT	CaseFoldingCF_CpList0049[]	= { 0x0069, 0 };
UINT	CaseFoldingCF_CpList004A[]	= { 0x006A, 0 };
UINT	CaseFoldingCF_CpList004B[]	= { 0x006B, 0 };
UINT	CaseFoldingCF_CpList004C[]	= { 0x006C, 0 };
UINT	CaseFoldingCF_CpList004D[]	= { 0x006D, 0 };
UINT	CaseFoldingCF_CpList004E[]	= { 0x006E, 0 };
UINT	CaseFoldingCF_CpList004F[]	= { 0x006F, 0 };
UINT	CaseFoldingCF_CpList0050[]	= { 0x0070, 0 };
UINT	CaseFoldingCF_CpList0051[]	= { 0x0071, 0 };
UINT	CaseFoldingCF_CpList0052[]	= { 0x0072, 0 };
UINT	CaseFoldingCF_CpList0053[]	= { 0x0073, 0 };
UINT	CaseFoldingCF_CpList0054[]	= { 0x0074, 0 };
UINT	CaseFoldingCF_CpList0055[]	= { 0x0075, 0 };
UINT	CaseFoldingCF_CpList0056[]	= { 0x0076, 0 };
UINT	CaseFoldingCF_CpList0057[]	= { 0x0077, 0 };
UINT	CaseFoldingCF_CpList0058[]	= { 0x0078, 0 };
UINT	CaseFoldingCF_CpList0059[]	= { 0x0079, 0 };
UINT	CaseFoldingCF_CpList005A[]	= { 0x007A, 0 };
UINT	CaseFoldingCF_CpList00B5[]	= { 0x03BC, 0 };
UINT	CaseFoldingCF_CpList00C0[]	= { 0x00E0, 0 };
UINT	CaseFoldingCF_CpList00C1[]	= { 0x00E1, 0 };
UINT	CaseFoldingCF_CpList00C2[]	= { 0x00E2, 0 };
UINT	CaseFoldingCF_CpList00C3[]	= { 0x00E3, 0 };
UINT	CaseFoldingCF_CpList00C4[]	= { 0x00E4, 0 };
UINT	CaseFoldingCF_CpList00C5[]	= { 0x00E5, 0 };
UINT	CaseFoldingCF_CpList00C6[]	= { 0x00E6, 0 };
UINT	CaseFoldingCF_CpList00C7[]	= { 0x00E7, 0 };
UINT	CaseFoldingCF_CpList00C8[]	= { 0x00E8, 0 };
UINT	CaseFoldingCF_CpList00C9[]	= { 0x00E9, 0 };
UINT	CaseFoldingCF_CpList00CA[]	= { 0x00EA, 0 };
UINT	CaseFoldingCF_CpList00CB[]	= { 0x00EB, 0 };
UINT	CaseFoldingCF_CpList00CC[]	= { 0x00EC, 0 };
UINT	CaseFoldingCF_CpList00CD[]	= { 0x00ED, 0 };
UINT	CaseFoldingCF_CpList00CE[]	= { 0x00EE, 0 };
UINT	CaseFoldingCF_CpList00CF[]	= { 0x00EF, 0 };
UINT	CaseFoldingCF_CpList00D0[]	= { 0x00F0, 0 };
UINT	CaseFoldingCF_CpList00D1[]	= { 0x00F1, 0 };
UINT	CaseFoldingCF_CpList00D2[]	= { 0x00F2, 0 };
UINT	CaseFoldingCF_CpList00D3[]	= { 0x00F3, 0 };
UINT	CaseFoldingCF_CpList00D4[]	= { 0x00F4, 0 };
UINT	CaseFoldingCF_CpList00D5[]	= { 0x00F5, 0 };
UINT	CaseFoldingCF_CpList00D6[]	= { 0x00F6, 0 };
UINT	CaseFoldingCF_CpList00D8[]	= { 0x00F8, 0 };
UINT	CaseFoldingCF_CpList00D9[]	= { 0x00F9, 0 };
UINT	CaseFoldingCF_CpList00DA[]	= { 0x00FA, 0 };
UINT	CaseFoldingCF_CpList00DB[]	= { 0x00FB, 0 };
UINT	CaseFoldingCF_CpList00DC[]	= { 0x00FC, 0 };
UINT	CaseFoldingCF_CpList00DD[]	= { 0x00FD, 0 };
UINT	CaseFoldingCF_CpList00DE[]	= { 0x00FE, 0 };
UINT	CaseFoldingCF_CpList00DF[]	= { 0x0073, 0x0073, 0 };
UINT	CaseFoldingCF_CpList0100[]	= { 0x0101, 0 };
UINT	CaseFoldingCF_CpList0102[]	= { 0x0103, 0 };
UINT	CaseFoldingCF_CpList0104[]	= { 0x0105, 0 };
UINT	CaseFoldingCF_CpList0106[]	= { 0x0107, 0 };
UINT	CaseFoldingCF_CpList0108[]	= { 0x0109, 0 };
UINT	CaseFoldingCF_CpList010A[]	= { 0x010B, 0 };
UINT	CaseFoldingCF_CpList010C[]	= { 0x010D, 0 };
UINT	CaseFoldingCF_CpList010E[]	= { 0x010F, 0 };
UINT	CaseFoldingCF_CpList0110[]	= { 0x0111, 0 };
UINT	CaseFoldingCF_CpList0112[]	= { 0x0113, 0 };
UINT	CaseFoldingCF_CpList0114[]	= { 0x0115, 0 };
UINT	CaseFoldingCF_CpList0116[]	= { 0x0117, 0 };
UINT	CaseFoldingCF_CpList0118[]	= { 0x0119, 0 };
UINT	CaseFoldingCF_CpList011A[]	= { 0x011B, 0 };
UINT	CaseFoldingCF_CpList011C[]	= { 0x011D, 0 };
UINT	CaseFoldingCF_CpList011E[]	= { 0x011F, 0 };
UINT	CaseFoldingCF_CpList0120[]	= { 0x0121, 0 };
UINT	CaseFoldingCF_CpList0122[]	= { 0x0123, 0 };
UINT	CaseFoldingCF_CpList0124[]	= { 0x0125, 0 };
UINT	CaseFoldingCF_CpList0126[]	= { 0x0127, 0 };
UINT	CaseFoldingCF_CpList0128[]	= { 0x0129, 0 };
UINT	CaseFoldingCF_CpList012A[]	= { 0x012B, 0 };
UINT	CaseFoldingCF_CpList012C[]	= { 0x012D, 0 };
UINT	CaseFoldingCF_CpList012E[]	= { 0x012F, 0 };
UINT	CaseFoldingCF_CpList0130[]	= { 0x0069, 0x0307, 0 };
UINT	CaseFoldingCF_CpList0132[]	= { 0x0133, 0 };
UINT	CaseFoldingCF_CpList0134[]	= { 0x0135, 0 };
UINT	CaseFoldingCF_CpList0136[]	= { 0x0137, 0 };
UINT	CaseFoldingCF_CpList0139[]	= { 0x013A, 0 };
UINT	CaseFoldingCF_CpList013B[]	= { 0x013C, 0 };
UINT	CaseFoldingCF_CpList013D[]	= { 0x013E, 0 };
UINT	CaseFoldingCF_CpList013F[]	= { 0x0140, 0 };
UINT	CaseFoldingCF_CpList0141[]	= { 0x0142, 0 };
UINT	CaseFoldingCF_CpList0143[]	= { 0x0144, 0 };
UINT	CaseFoldingCF_CpList0145[]	= { 0x0146, 0 };
UINT	CaseFoldingCF_CpList0147[]	= { 0x0148, 0 };
UINT	CaseFoldingCF_CpList0149[]	= { 0x02BC, 0x006E, 0 };
UINT	CaseFoldingCF_CpList014A[]	= { 0x014B, 0 };
UINT	CaseFoldingCF_CpList014C[]	= { 0x014D, 0 };
UINT	CaseFoldingCF_CpList014E[]	= { 0x014F, 0 };
UINT	CaseFoldingCF_CpList0150[]	= { 0x0151, 0 };
UINT	CaseFoldingCF_CpList0152[]	= { 0x0153, 0 };
UINT	CaseFoldingCF_CpList0154[]	= { 0x0155, 0 };
UINT	CaseFoldingCF_CpList0156[]	= { 0x0157, 0 };
UINT	CaseFoldingCF_CpList0158[]	= { 0x0159, 0 };
UINT	CaseFoldingCF_CpList015A[]	= { 0x015B, 0 };
UINT	CaseFoldingCF_CpList015C[]	= { 0x015D, 0 };
UINT	CaseFoldingCF_CpList015E[]	= { 0x015F, 0 };
UINT	CaseFoldingCF_CpList0160[]	= { 0x0161, 0 };
UINT	CaseFoldingCF_CpList0162[]	= { 0x0163, 0 };
UINT	CaseFoldingCF_CpList0164[]	= { 0x0165, 0 };
UINT	CaseFoldingCF_CpList0166[]	= { 0x0167, 0 };
UINT	CaseFoldingCF_CpList0168[]	= { 0x0169, 0 };
UINT	CaseFoldingCF_CpList016A[]	= { 0x016B, 0 };
UINT	CaseFoldingCF_CpList016C[]	= { 0x016D, 0 };
UINT	CaseFoldingCF_CpList016E[]	= { 0x016F, 0 };
UINT	CaseFoldingCF_CpList0170[]	= { 0x0171, 0 };
UINT	CaseFoldingCF_CpList0172[]	= { 0x0173, 0 };
UINT	CaseFoldingCF_CpList0174[]	= { 0x0175, 0 };
UINT	CaseFoldingCF_CpList0176[]	= { 0x0177, 0 };
UINT	CaseFoldingCF_CpList0178[]	= { 0x00FF, 0 };
UINT	CaseFoldingCF_CpList0179[]	= { 0x017A, 0 };
UINT	CaseFoldingCF_CpList017B[]	= { 0x017C, 0 };
UINT	CaseFoldingCF_CpList017D[]	= { 0x017E, 0 };
UINT	CaseFoldingCF_CpList017F[]	= { 0x0073, 0 };
UINT	CaseFoldingCF_CpList0181[]	= { 0x0253, 0 };
UINT	CaseFoldingCF_CpList0182[]	= { 0x0183, 0 };
UINT	CaseFoldingCF_CpList0184[]	= { 0x0185, 0 };
UINT	CaseFoldingCF_CpList0186[]	= { 0x0254, 0 };
UINT	CaseFoldingCF_CpList0187[]	= { 0x0188, 0 };
UINT	CaseFoldingCF_CpList0189[]	= { 0x0256, 0 };
UINT	CaseFoldingCF_CpList018A[]	= { 0x0257, 0 };
UINT	CaseFoldingCF_CpList018B[]	= { 0x018C, 0 };
UINT	CaseFoldingCF_CpList018E[]	= { 0x01DD, 0 };
UINT	CaseFoldingCF_CpList018F[]	= { 0x0259, 0 };
UINT	CaseFoldingCF_CpList0190[]	= { 0x025B, 0 };
UINT	CaseFoldingCF_CpList0191[]	= { 0x0192, 0 };
UINT	CaseFoldingCF_CpList0193[]	= { 0x0260, 0 };
UINT	CaseFoldingCF_CpList0194[]	= { 0x0263, 0 };
UINT	CaseFoldingCF_CpList0196[]	= { 0x0269, 0 };
UINT	CaseFoldingCF_CpList0197[]	= { 0x0268, 0 };
UINT	CaseFoldingCF_CpList0198[]	= { 0x0199, 0 };
UINT	CaseFoldingCF_CpList019C[]	= { 0x026F, 0 };
UINT	CaseFoldingCF_CpList019D[]	= { 0x0272, 0 };
UINT	CaseFoldingCF_CpList019F[]	= { 0x0275, 0 };
UINT	CaseFoldingCF_CpList01A0[]	= { 0x01A1, 0 };
UINT	CaseFoldingCF_CpList01A2[]	= { 0x01A3, 0 };
UINT	CaseFoldingCF_CpList01A4[]	= { 0x01A5, 0 };
UINT	CaseFoldingCF_CpList01A6[]	= { 0x0280, 0 };
UINT	CaseFoldingCF_CpList01A7[]	= { 0x01A8, 0 };
UINT	CaseFoldingCF_CpList01A9[]	= { 0x0283, 0 };
UINT	CaseFoldingCF_CpList01AC[]	= { 0x01AD, 0 };
UINT	CaseFoldingCF_CpList01AE[]	= { 0x0288, 0 };
UINT	CaseFoldingCF_CpList01AF[]	= { 0x01B0, 0 };
UINT	CaseFoldingCF_CpList01B1[]	= { 0x028A, 0 };
UINT	CaseFoldingCF_CpList01B2[]	= { 0x028B, 0 };
UINT	CaseFoldingCF_CpList01B3[]	= { 0x01B4, 0 };
UINT	CaseFoldingCF_CpList01B5[]	= { 0x01B6, 0 };
UINT	CaseFoldingCF_CpList01B7[]	= { 0x0292, 0 };
UINT	CaseFoldingCF_CpList01B8[]	= { 0x01B9, 0 };
UINT	CaseFoldingCF_CpList01BC[]	= { 0x01BD, 0 };
UINT	CaseFoldingCF_CpList01C4[]	= { 0x01C6, 0 };
UINT	CaseFoldingCF_CpList01C5[]	= { 0x01C6, 0 };
UINT	CaseFoldingCF_CpList01C7[]	= { 0x01C9, 0 };
UINT	CaseFoldingCF_CpList01C8[]	= { 0x01C9, 0 };
UINT	CaseFoldingCF_CpList01CA[]	= { 0x01CC, 0 };
UINT	CaseFoldingCF_CpList01CB[]	= { 0x01CC, 0 };
UINT	CaseFoldingCF_CpList01CD[]	= { 0x01CE, 0 };
UINT	CaseFoldingCF_CpList01CF[]	= { 0x01D0, 0 };
UINT	CaseFoldingCF_CpList01D1[]	= { 0x01D2, 0 };
UINT	CaseFoldingCF_CpList01D3[]	= { 0x01D4, 0 };
UINT	CaseFoldingCF_CpList01D5[]	= { 0x01D6, 0 };
UINT	CaseFoldingCF_CpList01D7[]	= { 0x01D8, 0 };
UINT	CaseFoldingCF_CpList01D9[]	= { 0x01DA, 0 };
UINT	CaseFoldingCF_CpList01DB[]	= { 0x01DC, 0 };
UINT	CaseFoldingCF_CpList01DE[]	= { 0x01DF, 0 };
UINT	CaseFoldingCF_CpList01E0[]	= { 0x01E1, 0 };
UINT	CaseFoldingCF_CpList01E2[]	= { 0x01E3, 0 };
UINT	CaseFoldingCF_CpList01E4[]	= { 0x01E5, 0 };
UINT	CaseFoldingCF_CpList01E6[]	= { 0x01E7, 0 };
UINT	CaseFoldingCF_CpList01E8[]	= { 0x01E9, 0 };
UINT	CaseFoldingCF_CpList01EA[]	= { 0x01EB, 0 };
UINT	CaseFoldingCF_CpList01EC[]	= { 0x01ED, 0 };
UINT	CaseFoldingCF_CpList01EE[]	= { 0x01EF, 0 };
UINT	CaseFoldingCF_CpList01F0[]	= { 0x006A, 0x030C, 0 };
UINT	CaseFoldingCF_CpList01F1[]	= { 0x01F3, 0 };
UINT	CaseFoldingCF_CpList01F2[]	= { 0x01F3, 0 };
UINT	CaseFoldingCF_CpList01F4[]	= { 0x01F5, 0 };
UINT	CaseFoldingCF_CpList01F6[]	= { 0x0195, 0 };
UINT	CaseFoldingCF_CpList01F7[]	= { 0x01BF, 0 };
UINT	CaseFoldingCF_CpList01F8[]	= { 0x01F9, 0 };
UINT	CaseFoldingCF_CpList01FA[]	= { 0x01FB, 0 };
UINT	CaseFoldingCF_CpList01FC[]	= { 0x01FD, 0 };
UINT	CaseFoldingCF_CpList01FE[]	= { 0x01FF, 0 };
UINT	CaseFoldingCF_CpList0200[]	= { 0x0201, 0 };
UINT	CaseFoldingCF_CpList0202[]	= { 0x0203, 0 };
UINT	CaseFoldingCF_CpList0204[]	= { 0x0205, 0 };
UINT	CaseFoldingCF_CpList0206[]	= { 0x0207, 0 };
UINT	CaseFoldingCF_CpList0208[]	= { 0x0209, 0 };
UINT	CaseFoldingCF_CpList020A[]	= { 0x020B, 0 };
UINT	CaseFoldingCF_CpList020C[]	= { 0x020D, 0 };
UINT	CaseFoldingCF_CpList020E[]	= { 0x020F, 0 };
UINT	CaseFoldingCF_CpList0210[]	= { 0x0211, 0 };
UINT	CaseFoldingCF_CpList0212[]	= { 0x0213, 0 };
UINT	CaseFoldingCF_CpList0214[]	= { 0x0215, 0 };
UINT	CaseFoldingCF_CpList0216[]	= { 0x0217, 0 };
UINT	CaseFoldingCF_CpList0218[]	= { 0x0219, 0 };
UINT	CaseFoldingCF_CpList021A[]	= { 0x021B, 0 };
UINT	CaseFoldingCF_CpList021C[]	= { 0x021D, 0 };
UINT	CaseFoldingCF_CpList021E[]	= { 0x021F, 0 };
UINT	CaseFoldingCF_CpList0220[]	= { 0x019E, 0 };
UINT	CaseFoldingCF_CpList0222[]	= { 0x0223, 0 };
UINT	CaseFoldingCF_CpList0224[]	= { 0x0225, 0 };
UINT	CaseFoldingCF_CpList0226[]	= { 0x0227, 0 };
UINT	CaseFoldingCF_CpList0228[]	= { 0x0229, 0 };
UINT	CaseFoldingCF_CpList022A[]	= { 0x022B, 0 };
UINT	CaseFoldingCF_CpList022C[]	= { 0x022D, 0 };
UINT	CaseFoldingCF_CpList022E[]	= { 0x022F, 0 };
UINT	CaseFoldingCF_CpList0230[]	= { 0x0231, 0 };
UINT	CaseFoldingCF_CpList0232[]	= { 0x0233, 0 };
UINT	CaseFoldingCF_CpList023A[]	= { 0x2C65, 0 };
UINT	CaseFoldingCF_CpList023B[]	= { 0x023C, 0 };
UINT	CaseFoldingCF_CpList023D[]	= { 0x019A, 0 };
UINT	CaseFoldingCF_CpList023E[]	= { 0x2C66, 0 };
UINT	CaseFoldingCF_CpList0241[]	= { 0x0242, 0 };
UINT	CaseFoldingCF_CpList0243[]	= { 0x0180, 0 };
UINT	CaseFoldingCF_CpList0244[]	= { 0x0289, 0 };
UINT	CaseFoldingCF_CpList0245[]	= { 0x028C, 0 };
UINT	CaseFoldingCF_CpList0246[]	= { 0x0247, 0 };
UINT	CaseFoldingCF_CpList0248[]	= { 0x0249, 0 };
UINT	CaseFoldingCF_CpList024A[]	= { 0x024B, 0 };
UINT	CaseFoldingCF_CpList024C[]	= { 0x024D, 0 };
UINT	CaseFoldingCF_CpList024E[]	= { 0x024F, 0 };
UINT	CaseFoldingCF_CpList0345[]	= { 0x03B9, 0 };
UINT	CaseFoldingCF_CpList0370[]	= { 0x0371, 0 };
UINT	CaseFoldingCF_CpList0372[]	= { 0x0373, 0 };
UINT	CaseFoldingCF_CpList0376[]	= { 0x0377, 0 };
UINT	CaseFoldingCF_CpList0386[]	= { 0x03AC, 0 };
UINT	CaseFoldingCF_CpList0388[]	= { 0x03AD, 0 };
UINT	CaseFoldingCF_CpList0389[]	= { 0x03AE, 0 };
UINT	CaseFoldingCF_CpList038A[]	= { 0x03AF, 0 };
UINT	CaseFoldingCF_CpList038C[]	= { 0x03CC, 0 };
UINT	CaseFoldingCF_CpList038E[]	= { 0x03CD, 0 };
UINT	CaseFoldingCF_CpList038F[]	= { 0x03CE, 0 };
UINT	CaseFoldingCF_CpList0390[]	= { 0x03B9, 0x0308, 0x0301, 0 };
UINT	CaseFoldingCF_CpList0391[]	= { 0x03B1, 0 };
UINT	CaseFoldingCF_CpList0392[]	= { 0x03B2, 0 };
UINT	CaseFoldingCF_CpList0393[]	= { 0x03B3, 0 };
UINT	CaseFoldingCF_CpList0394[]	= { 0x03B4, 0 };
UINT	CaseFoldingCF_CpList0395[]	= { 0x03B5, 0 };
UINT	CaseFoldingCF_CpList0396[]	= { 0x03B6, 0 };
UINT	CaseFoldingCF_CpList0397[]	= { 0x03B7, 0 };
UINT	CaseFoldingCF_CpList0398[]	= { 0x03B8, 0 };
UINT	CaseFoldingCF_CpList0399[]	= { 0x03B9, 0 };
UINT	CaseFoldingCF_CpList039A[]	= { 0x03BA, 0 };
UINT	CaseFoldingCF_CpList039B[]	= { 0x03BB, 0 };
UINT	CaseFoldingCF_CpList039C[]	= { 0x03BC, 0 };
UINT	CaseFoldingCF_CpList039D[]	= { 0x03BD, 0 };
UINT	CaseFoldingCF_CpList039E[]	= { 0x03BE, 0 };
UINT	CaseFoldingCF_CpList039F[]	= { 0x03BF, 0 };
UINT	CaseFoldingCF_CpList03A0[]	= { 0x03C0, 0 };
UINT	CaseFoldingCF_CpList03A1[]	= { 0x03C1, 0 };
UINT	CaseFoldingCF_CpList03A3[]	= { 0x03C3, 0 };
UINT	CaseFoldingCF_CpList03A4[]	= { 0x03C4, 0 };
UINT	CaseFoldingCF_CpList03A5[]	= { 0x03C5, 0 };
UINT	CaseFoldingCF_CpList03A6[]	= { 0x03C6, 0 };
UINT	CaseFoldingCF_CpList03A7[]	= { 0x03C7, 0 };
UINT	CaseFoldingCF_CpList03A8[]	= { 0x03C8, 0 };
UINT	CaseFoldingCF_CpList03A9[]	= { 0x03C9, 0 };
UINT	CaseFoldingCF_CpList03AA[]	= { 0x03CA, 0 };
UINT	CaseFoldingCF_CpList03AB[]	= { 0x03CB, 0 };
UINT	CaseFoldingCF_CpList03B0[]	= { 0x03C5, 0x0308, 0x0301, 0 };
UINT	CaseFoldingCF_CpList03C2[]	= { 0x03C3, 0 };
UINT	CaseFoldingCF_CpList03CF[]	= { 0x03D7, 0 };
UINT	CaseFoldingCF_CpList03D0[]	= { 0x03B2, 0 };
UINT	CaseFoldingCF_CpList03D1[]	= { 0x03B8, 0 };
UINT	CaseFoldingCF_CpList03D5[]	= { 0x03C6, 0 };
UINT	CaseFoldingCF_CpList03D6[]	= { 0x03C0, 0 };
UINT	CaseFoldingCF_CpList03D8[]	= { 0x03D9, 0 };
UINT	CaseFoldingCF_CpList03DA[]	= { 0x03DB, 0 };
UINT	CaseFoldingCF_CpList03DC[]	= { 0x03DD, 0 };
UINT	CaseFoldingCF_CpList03DE[]	= { 0x03DF, 0 };
UINT	CaseFoldingCF_CpList03E0[]	= { 0x03E1, 0 };
UINT	CaseFoldingCF_CpList03E2[]	= { 0x03E3, 0 };
UINT	CaseFoldingCF_CpList03E4[]	= { 0x03E5, 0 };
UINT	CaseFoldingCF_CpList03E6[]	= { 0x03E7, 0 };
UINT	CaseFoldingCF_CpList03E8[]	= { 0x03E9, 0 };
UINT	CaseFoldingCF_CpList03EA[]	= { 0x03EB, 0 };
UINT	CaseFoldingCF_CpList03EC[]	= { 0x03ED, 0 };
UINT	CaseFoldingCF_CpList03EE[]	= { 0x03EF, 0 };
UINT	CaseFoldingCF_CpList03F0[]	= { 0x03BA, 0 };
UINT	CaseFoldingCF_CpList03F1[]	= { 0x03C1, 0 };
UINT	CaseFoldingCF_CpList03F4[]	= { 0x03B8, 0 };
UINT	CaseFoldingCF_CpList03F5[]	= { 0x03B5, 0 };
UINT	CaseFoldingCF_CpList03F7[]	= { 0x03F8, 0 };
UINT	CaseFoldingCF_CpList03F9[]	= { 0x03F2, 0 };
UINT	CaseFoldingCF_CpList03FA[]	= { 0x03FB, 0 };
UINT	CaseFoldingCF_CpList03FD[]	= { 0x037B, 0 };
UINT	CaseFoldingCF_CpList03FE[]	= { 0x037C, 0 };
UINT	CaseFoldingCF_CpList03FF[]	= { 0x037D, 0 };
UINT	CaseFoldingCF_CpList0400[]	= { 0x0450, 0 };
UINT	CaseFoldingCF_CpList0401[]	= { 0x0451, 0 };
UINT	CaseFoldingCF_CpList0402[]	= { 0x0452, 0 };
UINT	CaseFoldingCF_CpList0403[]	= { 0x0453, 0 };
UINT	CaseFoldingCF_CpList0404[]	= { 0x0454, 0 };
UINT	CaseFoldingCF_CpList0405[]	= { 0x0455, 0 };
UINT	CaseFoldingCF_CpList0406[]	= { 0x0456, 0 };
UINT	CaseFoldingCF_CpList0407[]	= { 0x0457, 0 };
UINT	CaseFoldingCF_CpList0408[]	= { 0x0458, 0 };
UINT	CaseFoldingCF_CpList0409[]	= { 0x0459, 0 };
UINT	CaseFoldingCF_CpList040A[]	= { 0x045A, 0 };
UINT	CaseFoldingCF_CpList040B[]	= { 0x045B, 0 };
UINT	CaseFoldingCF_CpList040C[]	= { 0x045C, 0 };
UINT	CaseFoldingCF_CpList040D[]	= { 0x045D, 0 };
UINT	CaseFoldingCF_CpList040E[]	= { 0x045E, 0 };
UINT	CaseFoldingCF_CpList040F[]	= { 0x045F, 0 };
UINT	CaseFoldingCF_CpList0410[]	= { 0x0430, 0 };
UINT	CaseFoldingCF_CpList0411[]	= { 0x0431, 0 };
UINT	CaseFoldingCF_CpList0412[]	= { 0x0432, 0 };
UINT	CaseFoldingCF_CpList0413[]	= { 0x0433, 0 };
UINT	CaseFoldingCF_CpList0414[]	= { 0x0434, 0 };
UINT	CaseFoldingCF_CpList0415[]	= { 0x0435, 0 };
UINT	CaseFoldingCF_CpList0416[]	= { 0x0436, 0 };
UINT	CaseFoldingCF_CpList0417[]	= { 0x0437, 0 };
UINT	CaseFoldingCF_CpList0418[]	= { 0x0438, 0 };
UINT	CaseFoldingCF_CpList0419[]	= { 0x0439, 0 };
UINT	CaseFoldingCF_CpList041A[]	= { 0x043A, 0 };
UINT	CaseFoldingCF_CpList041B[]	= { 0x043B, 0 };
UINT	CaseFoldingCF_CpList041C[]	= { 0x043C, 0 };
UINT	CaseFoldingCF_CpList041D[]	= { 0x043D, 0 };
UINT	CaseFoldingCF_CpList041E[]	= { 0x043E, 0 };
UINT	CaseFoldingCF_CpList041F[]	= { 0x043F, 0 };
UINT	CaseFoldingCF_CpList0420[]	= { 0x0440, 0 };
UINT	CaseFoldingCF_CpList0421[]	= { 0x0441, 0 };
UINT	CaseFoldingCF_CpList0422[]	= { 0x0442, 0 };
UINT	CaseFoldingCF_CpList0423[]	= { 0x0443, 0 };
UINT	CaseFoldingCF_CpList0424[]	= { 0x0444, 0 };
UINT	CaseFoldingCF_CpList0425[]	= { 0x0445, 0 };
UINT	CaseFoldingCF_CpList0426[]	= { 0x0446, 0 };
UINT	CaseFoldingCF_CpList0427[]	= { 0x0447, 0 };
UINT	CaseFoldingCF_CpList0428[]	= { 0x0448, 0 };
UINT	CaseFoldingCF_CpList0429[]	= { 0x0449, 0 };
UINT	CaseFoldingCF_CpList042A[]	= { 0x044A, 0 };
UINT	CaseFoldingCF_CpList042B[]	= { 0x044B, 0 };
UINT	CaseFoldingCF_CpList042C[]	= { 0x044C, 0 };
UINT	CaseFoldingCF_CpList042D[]	= { 0x044D, 0 };
UINT	CaseFoldingCF_CpList042E[]	= { 0x044E, 0 };
UINT	CaseFoldingCF_CpList042F[]	= { 0x044F, 0 };
UINT	CaseFoldingCF_CpList0460[]	= { 0x0461, 0 };
UINT	CaseFoldingCF_CpList0462[]	= { 0x0463, 0 };
UINT	CaseFoldingCF_CpList0464[]	= { 0x0465, 0 };
UINT	CaseFoldingCF_CpList0466[]	= { 0x0467, 0 };
UINT	CaseFoldingCF_CpList0468[]	= { 0x0469, 0 };
UINT	CaseFoldingCF_CpList046A[]	= { 0x046B, 0 };
UINT	CaseFoldingCF_CpList046C[]	= { 0x046D, 0 };
UINT	CaseFoldingCF_CpList046E[]	= { 0x046F, 0 };
UINT	CaseFoldingCF_CpList0470[]	= { 0x0471, 0 };
UINT	CaseFoldingCF_CpList0472[]	= { 0x0473, 0 };
UINT	CaseFoldingCF_CpList0474[]	= { 0x0475, 0 };
UINT	CaseFoldingCF_CpList0476[]	= { 0x0477, 0 };
UINT	CaseFoldingCF_CpList0478[]	= { 0x0479, 0 };
UINT	CaseFoldingCF_CpList047A[]	= { 0x047B, 0 };
UINT	CaseFoldingCF_CpList047C[]	= { 0x047D, 0 };
UINT	CaseFoldingCF_CpList047E[]	= { 0x047F, 0 };
UINT	CaseFoldingCF_CpList0480[]	= { 0x0481, 0 };
UINT	CaseFoldingCF_CpList048A[]	= { 0x048B, 0 };
UINT	CaseFoldingCF_CpList048C[]	= { 0x048D, 0 };
UINT	CaseFoldingCF_CpList048E[]	= { 0x048F, 0 };
UINT	CaseFoldingCF_CpList0490[]	= { 0x0491, 0 };
UINT	CaseFoldingCF_CpList0492[]	= { 0x0493, 0 };
UINT	CaseFoldingCF_CpList0494[]	= { 0x0495, 0 };
UINT	CaseFoldingCF_CpList0496[]	= { 0x0497, 0 };
UINT	CaseFoldingCF_CpList0498[]	= { 0x0499, 0 };
UINT	CaseFoldingCF_CpList049A[]	= { 0x049B, 0 };
UINT	CaseFoldingCF_CpList049C[]	= { 0x049D, 0 };
UINT	CaseFoldingCF_CpList049E[]	= { 0x049F, 0 };
UINT	CaseFoldingCF_CpList04A0[]	= { 0x04A1, 0 };
UINT	CaseFoldingCF_CpList04A2[]	= { 0x04A3, 0 };
UINT	CaseFoldingCF_CpList04A4[]	= { 0x04A5, 0 };
UINT	CaseFoldingCF_CpList04A6[]	= { 0x04A7, 0 };
UINT	CaseFoldingCF_CpList04A8[]	= { 0x04A9, 0 };
UINT	CaseFoldingCF_CpList04AA[]	= { 0x04AB, 0 };
UINT	CaseFoldingCF_CpList04AC[]	= { 0x04AD, 0 };
UINT	CaseFoldingCF_CpList04AE[]	= { 0x04AF, 0 };
UINT	CaseFoldingCF_CpList04B0[]	= { 0x04B1, 0 };
UINT	CaseFoldingCF_CpList04B2[]	= { 0x04B3, 0 };
UINT	CaseFoldingCF_CpList04B4[]	= { 0x04B5, 0 };
UINT	CaseFoldingCF_CpList04B6[]	= { 0x04B7, 0 };
UINT	CaseFoldingCF_CpList04B8[]	= { 0x04B9, 0 };
UINT	CaseFoldingCF_CpList04BA[]	= { 0x04BB, 0 };
UINT	CaseFoldingCF_CpList04BC[]	= { 0x04BD, 0 };
UINT	CaseFoldingCF_CpList04BE[]	= { 0x04BF, 0 };
UINT	CaseFoldingCF_CpList04C0[]	= { 0x04CF, 0 };
UINT	CaseFoldingCF_CpList04C1[]	= { 0x04C2, 0 };
UINT	CaseFoldingCF_CpList04C3[]	= { 0x04C4, 0 };
UINT	CaseFoldingCF_CpList04C5[]	= { 0x04C6, 0 };
UINT	CaseFoldingCF_CpList04C7[]	= { 0x04C8, 0 };
UINT	CaseFoldingCF_CpList04C9[]	= { 0x04CA, 0 };
UINT	CaseFoldingCF_CpList04CB[]	= { 0x04CC, 0 };
UINT	CaseFoldingCF_CpList04CD[]	= { 0x04CE, 0 };
UINT	CaseFoldingCF_CpList04D0[]	= { 0x04D1, 0 };
UINT	CaseFoldingCF_CpList04D2[]	= { 0x04D3, 0 };
UINT	CaseFoldingCF_CpList04D4[]	= { 0x04D5, 0 };
UINT	CaseFoldingCF_CpList04D6[]	= { 0x04D7, 0 };
UINT	CaseFoldingCF_CpList04D8[]	= { 0x04D9, 0 };
UINT	CaseFoldingCF_CpList04DA[]	= { 0x04DB, 0 };
UINT	CaseFoldingCF_CpList04DC[]	= { 0x04DD, 0 };
UINT	CaseFoldingCF_CpList04DE[]	= { 0x04DF, 0 };
UINT	CaseFoldingCF_CpList04E0[]	= { 0x04E1, 0 };
UINT	CaseFoldingCF_CpList04E2[]	= { 0x04E3, 0 };
UINT	CaseFoldingCF_CpList04E4[]	= { 0x04E5, 0 };
UINT	CaseFoldingCF_CpList04E6[]	= { 0x04E7, 0 };
UINT	CaseFoldingCF_CpList04E8[]	= { 0x04E9, 0 };
UINT	CaseFoldingCF_CpList04EA[]	= { 0x04EB, 0 };
UINT	CaseFoldingCF_CpList04EC[]	= { 0x04ED, 0 };
UINT	CaseFoldingCF_CpList04EE[]	= { 0x04EF, 0 };
UINT	CaseFoldingCF_CpList04F0[]	= { 0x04F1, 0 };
UINT	CaseFoldingCF_CpList04F2[]	= { 0x04F3, 0 };
UINT	CaseFoldingCF_CpList04F4[]	= { 0x04F5, 0 };
UINT	CaseFoldingCF_CpList04F6[]	= { 0x04F7, 0 };
UINT	CaseFoldingCF_CpList04F8[]	= { 0x04F9, 0 };
UINT	CaseFoldingCF_CpList04FA[]	= { 0x04FB, 0 };
UINT	CaseFoldingCF_CpList04FC[]	= { 0x04FD, 0 };
UINT	CaseFoldingCF_CpList04FE[]	= { 0x04FF, 0 };
UINT	CaseFoldingCF_CpList0500[]	= { 0x0501, 0 };
UINT	CaseFoldingCF_CpList0502[]	= { 0x0503, 0 };
UINT	CaseFoldingCF_CpList0504[]	= { 0x0505, 0 };
UINT	CaseFoldingCF_CpList0506[]	= { 0x0507, 0 };
UINT	CaseFoldingCF_CpList0508[]	= { 0x0509, 0 };
UINT	CaseFoldingCF_CpList050A[]	= { 0x050B, 0 };
UINT	CaseFoldingCF_CpList050C[]	= { 0x050D, 0 };
UINT	CaseFoldingCF_CpList050E[]	= { 0x050F, 0 };
UINT	CaseFoldingCF_CpList0510[]	= { 0x0511, 0 };
UINT	CaseFoldingCF_CpList0512[]	= { 0x0513, 0 };
UINT	CaseFoldingCF_CpList0514[]	= { 0x0515, 0 };
UINT	CaseFoldingCF_CpList0516[]	= { 0x0517, 0 };
UINT	CaseFoldingCF_CpList0518[]	= { 0x0519, 0 };
UINT	CaseFoldingCF_CpList051A[]	= { 0x051B, 0 };
UINT	CaseFoldingCF_CpList051C[]	= { 0x051D, 0 };
UINT	CaseFoldingCF_CpList051E[]	= { 0x051F, 0 };
UINT	CaseFoldingCF_CpList0520[]	= { 0x0521, 0 };
UINT	CaseFoldingCF_CpList0522[]	= { 0x0523, 0 };
UINT	CaseFoldingCF_CpList0524[]	= { 0x0525, 0 };
UINT	CaseFoldingCF_CpList0526[]	= { 0x0527, 0 };
UINT	CaseFoldingCF_CpList0531[]	= { 0x0561, 0 };
UINT	CaseFoldingCF_CpList0532[]	= { 0x0562, 0 };
UINT	CaseFoldingCF_CpList0533[]	= { 0x0563, 0 };
UINT	CaseFoldingCF_CpList0534[]	= { 0x0564, 0 };
UINT	CaseFoldingCF_CpList0535[]	= { 0x0565, 0 };
UINT	CaseFoldingCF_CpList0536[]	= { 0x0566, 0 };
UINT	CaseFoldingCF_CpList0537[]	= { 0x0567, 0 };
UINT	CaseFoldingCF_CpList0538[]	= { 0x0568, 0 };
UINT	CaseFoldingCF_CpList0539[]	= { 0x0569, 0 };
UINT	CaseFoldingCF_CpList053A[]	= { 0x056A, 0 };
UINT	CaseFoldingCF_CpList053B[]	= { 0x056B, 0 };
UINT	CaseFoldingCF_CpList053C[]	= { 0x056C, 0 };
UINT	CaseFoldingCF_CpList053D[]	= { 0x056D, 0 };
UINT	CaseFoldingCF_CpList053E[]	= { 0x056E, 0 };
UINT	CaseFoldingCF_CpList053F[]	= { 0x056F, 0 };
UINT	CaseFoldingCF_CpList0540[]	= { 0x0570, 0 };
UINT	CaseFoldingCF_CpList0541[]	= { 0x0571, 0 };
UINT	CaseFoldingCF_CpList0542[]	= { 0x0572, 0 };
UINT	CaseFoldingCF_CpList0543[]	= { 0x0573, 0 };
UINT	CaseFoldingCF_CpList0544[]	= { 0x0574, 0 };
UINT	CaseFoldingCF_CpList0545[]	= { 0x0575, 0 };
UINT	CaseFoldingCF_CpList0546[]	= { 0x0576, 0 };
UINT	CaseFoldingCF_CpList0547[]	= { 0x0577, 0 };
UINT	CaseFoldingCF_CpList0548[]	= { 0x0578, 0 };
UINT	CaseFoldingCF_CpList0549[]	= { 0x0579, 0 };
UINT	CaseFoldingCF_CpList054A[]	= { 0x057A, 0 };
UINT	CaseFoldingCF_CpList054B[]	= { 0x057B, 0 };
UINT	CaseFoldingCF_CpList054C[]	= { 0x057C, 0 };
UINT	CaseFoldingCF_CpList054D[]	= { 0x057D, 0 };
UINT	CaseFoldingCF_CpList054E[]	= { 0x057E, 0 };
UINT	CaseFoldingCF_CpList054F[]	= { 0x057F, 0 };
UINT	CaseFoldingCF_CpList0550[]	= { 0x0580, 0 };
UINT	CaseFoldingCF_CpList0551[]	= { 0x0581, 0 };
UINT	CaseFoldingCF_CpList0552[]	= { 0x0582, 0 };
UINT	CaseFoldingCF_CpList0553[]	= { 0x0583, 0 };
UINT	CaseFoldingCF_CpList0554[]	= { 0x0584, 0 };
UINT	CaseFoldingCF_CpList0555[]	= { 0x0585, 0 };
UINT	CaseFoldingCF_CpList0556[]	= { 0x0586, 0 };
UINT	CaseFoldingCF_CpList0587[]	= { 0x0565, 0x0582, 0 };
UINT	CaseFoldingCF_CpList10A0[]	= { 0x2D00, 0 };
UINT	CaseFoldingCF_CpList10A1[]	= { 0x2D01, 0 };
UINT	CaseFoldingCF_CpList10A2[]	= { 0x2D02, 0 };
UINT	CaseFoldingCF_CpList10A3[]	= { 0x2D03, 0 };
UINT	CaseFoldingCF_CpList10A4[]	= { 0x2D04, 0 };
UINT	CaseFoldingCF_CpList10A5[]	= { 0x2D05, 0 };
UINT	CaseFoldingCF_CpList10A6[]	= { 0x2D06, 0 };
UINT	CaseFoldingCF_CpList10A7[]	= { 0x2D07, 0 };
UINT	CaseFoldingCF_CpList10A8[]	= { 0x2D08, 0 };
UINT	CaseFoldingCF_CpList10A9[]	= { 0x2D09, 0 };
UINT	CaseFoldingCF_CpList10AA[]	= { 0x2D0A, 0 };
UINT	CaseFoldingCF_CpList10AB[]	= { 0x2D0B, 0 };
UINT	CaseFoldingCF_CpList10AC[]	= { 0x2D0C, 0 };
UINT	CaseFoldingCF_CpList10AD[]	= { 0x2D0D, 0 };
UINT	CaseFoldingCF_CpList10AE[]	= { 0x2D0E, 0 };
UINT	CaseFoldingCF_CpList10AF[]	= { 0x2D0F, 0 };
UINT	CaseFoldingCF_CpList10B0[]	= { 0x2D10, 0 };
UINT	CaseFoldingCF_CpList10B1[]	= { 0x2D11, 0 };
UINT	CaseFoldingCF_CpList10B2[]	= { 0x2D12, 0 };
UINT	CaseFoldingCF_CpList10B3[]	= { 0x2D13, 0 };
UINT	CaseFoldingCF_CpList10B4[]	= { 0x2D14, 0 };
UINT	CaseFoldingCF_CpList10B5[]	= { 0x2D15, 0 };
UINT	CaseFoldingCF_CpList10B6[]	= { 0x2D16, 0 };
UINT	CaseFoldingCF_CpList10B7[]	= { 0x2D17, 0 };
UINT	CaseFoldingCF_CpList10B8[]	= { 0x2D18, 0 };
UINT	CaseFoldingCF_CpList10B9[]	= { 0x2D19, 0 };
UINT	CaseFoldingCF_CpList10BA[]	= { 0x2D1A, 0 };
UINT	CaseFoldingCF_CpList10BB[]	= { 0x2D1B, 0 };
UINT	CaseFoldingCF_CpList10BC[]	= { 0x2D1C, 0 };
UINT	CaseFoldingCF_CpList10BD[]	= { 0x2D1D, 0 };
UINT	CaseFoldingCF_CpList10BE[]	= { 0x2D1E, 0 };
UINT	CaseFoldingCF_CpList10BF[]	= { 0x2D1F, 0 };
UINT	CaseFoldingCF_CpList10C0[]	= { 0x2D20, 0 };
UINT	CaseFoldingCF_CpList10C1[]	= { 0x2D21, 0 };
UINT	CaseFoldingCF_CpList10C2[]	= { 0x2D22, 0 };
UINT	CaseFoldingCF_CpList10C3[]	= { 0x2D23, 0 };
UINT	CaseFoldingCF_CpList10C4[]	= { 0x2D24, 0 };
UINT	CaseFoldingCF_CpList10C5[]	= { 0x2D25, 0 };
UINT	CaseFoldingCF_CpList10C7[]	= { 0x2D27, 0 };
UINT	CaseFoldingCF_CpList10CD[]	= { 0x2D2D, 0 };
UINT	CaseFoldingCF_CpList1E00[]	= { 0x1E01, 0 };
UINT	CaseFoldingCF_CpList1E02[]	= { 0x1E03, 0 };
UINT	CaseFoldingCF_CpList1E04[]	= { 0x1E05, 0 };
UINT	CaseFoldingCF_CpList1E06[]	= { 0x1E07, 0 };
UINT	CaseFoldingCF_CpList1E08[]	= { 0x1E09, 0 };
UINT	CaseFoldingCF_CpList1E0A[]	= { 0x1E0B, 0 };
UINT	CaseFoldingCF_CpList1E0C[]	= { 0x1E0D, 0 };
UINT	CaseFoldingCF_CpList1E0E[]	= { 0x1E0F, 0 };
UINT	CaseFoldingCF_CpList1E10[]	= { 0x1E11, 0 };
UINT	CaseFoldingCF_CpList1E12[]	= { 0x1E13, 0 };
UINT	CaseFoldingCF_CpList1E14[]	= { 0x1E15, 0 };
UINT	CaseFoldingCF_CpList1E16[]	= { 0x1E17, 0 };
UINT	CaseFoldingCF_CpList1E18[]	= { 0x1E19, 0 };
UINT	CaseFoldingCF_CpList1E1A[]	= { 0x1E1B, 0 };
UINT	CaseFoldingCF_CpList1E1C[]	= { 0x1E1D, 0 };
UINT	CaseFoldingCF_CpList1E1E[]	= { 0x1E1F, 0 };
UINT	CaseFoldingCF_CpList1E20[]	= { 0x1E21, 0 };
UINT	CaseFoldingCF_CpList1E22[]	= { 0x1E23, 0 };
UINT	CaseFoldingCF_CpList1E24[]	= { 0x1E25, 0 };
UINT	CaseFoldingCF_CpList1E26[]	= { 0x1E27, 0 };
UINT	CaseFoldingCF_CpList1E28[]	= { 0x1E29, 0 };
UINT	CaseFoldingCF_CpList1E2A[]	= { 0x1E2B, 0 };
UINT	CaseFoldingCF_CpList1E2C[]	= { 0x1E2D, 0 };
UINT	CaseFoldingCF_CpList1E2E[]	= { 0x1E2F, 0 };
UINT	CaseFoldingCF_CpList1E30[]	= { 0x1E31, 0 };
UINT	CaseFoldingCF_CpList1E32[]	= { 0x1E33, 0 };
UINT	CaseFoldingCF_CpList1E34[]	= { 0x1E35, 0 };
UINT	CaseFoldingCF_CpList1E36[]	= { 0x1E37, 0 };
UINT	CaseFoldingCF_CpList1E38[]	= { 0x1E39, 0 };
UINT	CaseFoldingCF_CpList1E3A[]	= { 0x1E3B, 0 };
UINT	CaseFoldingCF_CpList1E3C[]	= { 0x1E3D, 0 };
UINT	CaseFoldingCF_CpList1E3E[]	= { 0x1E3F, 0 };
UINT	CaseFoldingCF_CpList1E40[]	= { 0x1E41, 0 };
UINT	CaseFoldingCF_CpList1E42[]	= { 0x1E43, 0 };
UINT	CaseFoldingCF_CpList1E44[]	= { 0x1E45, 0 };
UINT	CaseFoldingCF_CpList1E46[]	= { 0x1E47, 0 };
UINT	CaseFoldingCF_CpList1E48[]	= { 0x1E49, 0 };
UINT	CaseFoldingCF_CpList1E4A[]	= { 0x1E4B, 0 };
UINT	CaseFoldingCF_CpList1E4C[]	= { 0x1E4D, 0 };
UINT	CaseFoldingCF_CpList1E4E[]	= { 0x1E4F, 0 };
UINT	CaseFoldingCF_CpList1E50[]	= { 0x1E51, 0 };
UINT	CaseFoldingCF_CpList1E52[]	= { 0x1E53, 0 };
UINT	CaseFoldingCF_CpList1E54[]	= { 0x1E55, 0 };
UINT	CaseFoldingCF_CpList1E56[]	= { 0x1E57, 0 };
UINT	CaseFoldingCF_CpList1E58[]	= { 0x1E59, 0 };
UINT	CaseFoldingCF_CpList1E5A[]	= { 0x1E5B, 0 };
UINT	CaseFoldingCF_CpList1E5C[]	= { 0x1E5D, 0 };
UINT	CaseFoldingCF_CpList1E5E[]	= { 0x1E5F, 0 };
UINT	CaseFoldingCF_CpList1E60[]	= { 0x1E61, 0 };
UINT	CaseFoldingCF_CpList1E62[]	= { 0x1E63, 0 };
UINT	CaseFoldingCF_CpList1E64[]	= { 0x1E65, 0 };
UINT	CaseFoldingCF_CpList1E66[]	= { 0x1E67, 0 };
UINT	CaseFoldingCF_CpList1E68[]	= { 0x1E69, 0 };
UINT	CaseFoldingCF_CpList1E6A[]	= { 0x1E6B, 0 };
UINT	CaseFoldingCF_CpList1E6C[]	= { 0x1E6D, 0 };
UINT	CaseFoldingCF_CpList1E6E[]	= { 0x1E6F, 0 };
UINT	CaseFoldingCF_CpList1E70[]	= { 0x1E71, 0 };
UINT	CaseFoldingCF_CpList1E72[]	= { 0x1E73, 0 };
UINT	CaseFoldingCF_CpList1E74[]	= { 0x1E75, 0 };
UINT	CaseFoldingCF_CpList1E76[]	= { 0x1E77, 0 };
UINT	CaseFoldingCF_CpList1E78[]	= { 0x1E79, 0 };
UINT	CaseFoldingCF_CpList1E7A[]	= { 0x1E7B, 0 };
UINT	CaseFoldingCF_CpList1E7C[]	= { 0x1E7D, 0 };
UINT	CaseFoldingCF_CpList1E7E[]	= { 0x1E7F, 0 };
UINT	CaseFoldingCF_CpList1E80[]	= { 0x1E81, 0 };
UINT	CaseFoldingCF_CpList1E82[]	= { 0x1E83, 0 };
UINT	CaseFoldingCF_CpList1E84[]	= { 0x1E85, 0 };
UINT	CaseFoldingCF_CpList1E86[]	= { 0x1E87, 0 };
UINT	CaseFoldingCF_CpList1E88[]	= { 0x1E89, 0 };
UINT	CaseFoldingCF_CpList1E8A[]	= { 0x1E8B, 0 };
UINT	CaseFoldingCF_CpList1E8C[]	= { 0x1E8D, 0 };
UINT	CaseFoldingCF_CpList1E8E[]	= { 0x1E8F, 0 };
UINT	CaseFoldingCF_CpList1E90[]	= { 0x1E91, 0 };
UINT	CaseFoldingCF_CpList1E92[]	= { 0x1E93, 0 };
UINT	CaseFoldingCF_CpList1E94[]	= { 0x1E95, 0 };
UINT	CaseFoldingCF_CpList1E96[]	= { 0x0068, 0x0331, 0 };
UINT	CaseFoldingCF_CpList1E97[]	= { 0x0074, 0x0308, 0 };
UINT	CaseFoldingCF_CpList1E98[]	= { 0x0077, 0x030A, 0 };
UINT	CaseFoldingCF_CpList1E99[]	= { 0x0079, 0x030A, 0 };
UINT	CaseFoldingCF_CpList1E9A[]	= { 0x0061, 0x02BE, 0 };
UINT	CaseFoldingCF_CpList1E9B[]	= { 0x1E61, 0 };
UINT	CaseFoldingCF_CpList1E9E[]	= { 0x0073, 0x0073, 0 };
UINT	CaseFoldingCF_CpList1EA0[]	= { 0x1EA1, 0 };
UINT	CaseFoldingCF_CpList1EA2[]	= { 0x1EA3, 0 };
UINT	CaseFoldingCF_CpList1EA4[]	= { 0x1EA5, 0 };
UINT	CaseFoldingCF_CpList1EA6[]	= { 0x1EA7, 0 };
UINT	CaseFoldingCF_CpList1EA8[]	= { 0x1EA9, 0 };
UINT	CaseFoldingCF_CpList1EAA[]	= { 0x1EAB, 0 };
UINT	CaseFoldingCF_CpList1EAC[]	= { 0x1EAD, 0 };
UINT	CaseFoldingCF_CpList1EAE[]	= { 0x1EAF, 0 };
UINT	CaseFoldingCF_CpList1EB0[]	= { 0x1EB1, 0 };
UINT	CaseFoldingCF_CpList1EB2[]	= { 0x1EB3, 0 };
UINT	CaseFoldingCF_CpList1EB4[]	= { 0x1EB5, 0 };
UINT	CaseFoldingCF_CpList1EB6[]	= { 0x1EB7, 0 };
UINT	CaseFoldingCF_CpList1EB8[]	= { 0x1EB9, 0 };
UINT	CaseFoldingCF_CpList1EBA[]	= { 0x1EBB, 0 };
UINT	CaseFoldingCF_CpList1EBC[]	= { 0x1EBD, 0 };
UINT	CaseFoldingCF_CpList1EBE[]	= { 0x1EBF, 0 };
UINT	CaseFoldingCF_CpList1EC0[]	= { 0x1EC1, 0 };
UINT	CaseFoldingCF_CpList1EC2[]	= { 0x1EC3, 0 };
UINT	CaseFoldingCF_CpList1EC4[]	= { 0x1EC5, 0 };
UINT	CaseFoldingCF_CpList1EC6[]	= { 0x1EC7, 0 };
UINT	CaseFoldingCF_CpList1EC8[]	= { 0x1EC9, 0 };
UINT	CaseFoldingCF_CpList1ECA[]	= { 0x1ECB, 0 };
UINT	CaseFoldingCF_CpList1ECC[]	= { 0x1ECD, 0 };
UINT	CaseFoldingCF_CpList1ECE[]	= { 0x1ECF, 0 };
UINT	CaseFoldingCF_CpList1ED0[]	= { 0x1ED1, 0 };
UINT	CaseFoldingCF_CpList1ED2[]	= { 0x1ED3, 0 };
UINT	CaseFoldingCF_CpList1ED4[]	= { 0x1ED5, 0 };
UINT	CaseFoldingCF_CpList1ED6[]	= { 0x1ED7, 0 };
UINT	CaseFoldingCF_CpList1ED8[]	= { 0x1ED9, 0 };
UINT	CaseFoldingCF_CpList1EDA[]	= { 0x1EDB, 0 };
UINT	CaseFoldingCF_CpList1EDC[]	= { 0x1EDD, 0 };
UINT	CaseFoldingCF_CpList1EDE[]	= { 0x1EDF, 0 };
UINT	CaseFoldingCF_CpList1EE0[]	= { 0x1EE1, 0 };
UINT	CaseFoldingCF_CpList1EE2[]	= { 0x1EE3, 0 };
UINT	CaseFoldingCF_CpList1EE4[]	= { 0x1EE5, 0 };
UINT	CaseFoldingCF_CpList1EE6[]	= { 0x1EE7, 0 };
UINT	CaseFoldingCF_CpList1EE8[]	= { 0x1EE9, 0 };
UINT	CaseFoldingCF_CpList1EEA[]	= { 0x1EEB, 0 };
UINT	CaseFoldingCF_CpList1EEC[]	= { 0x1EED, 0 };
UINT	CaseFoldingCF_CpList1EEE[]	= { 0x1EEF, 0 };
UINT	CaseFoldingCF_CpList1EF0[]	= { 0x1EF1, 0 };
UINT	CaseFoldingCF_CpList1EF2[]	= { 0x1EF3, 0 };
UINT	CaseFoldingCF_CpList1EF4[]	= { 0x1EF5, 0 };
UINT	CaseFoldingCF_CpList1EF6[]	= { 0x1EF7, 0 };
UINT	CaseFoldingCF_CpList1EF8[]	= { 0x1EF9, 0 };
UINT	CaseFoldingCF_CpList1EFA[]	= { 0x1EFB, 0 };
UINT	CaseFoldingCF_CpList1EFC[]	= { 0x1EFD, 0 };
UINT	CaseFoldingCF_CpList1EFE[]	= { 0x1EFF, 0 };
UINT	CaseFoldingCF_CpList1F08[]	= { 0x1F00, 0 };
UINT	CaseFoldingCF_CpList1F09[]	= { 0x1F01, 0 };
UINT	CaseFoldingCF_CpList1F0A[]	= { 0x1F02, 0 };
UINT	CaseFoldingCF_CpList1F0B[]	= { 0x1F03, 0 };
UINT	CaseFoldingCF_CpList1F0C[]	= { 0x1F04, 0 };
UINT	CaseFoldingCF_CpList1F0D[]	= { 0x1F05, 0 };
UINT	CaseFoldingCF_CpList1F0E[]	= { 0x1F06, 0 };
UINT	CaseFoldingCF_CpList1F0F[]	= { 0x1F07, 0 };
UINT	CaseFoldingCF_CpList1F18[]	= { 0x1F10, 0 };
UINT	CaseFoldingCF_CpList1F19[]	= { 0x1F11, 0 };
UINT	CaseFoldingCF_CpList1F1A[]	= { 0x1F12, 0 };
UINT	CaseFoldingCF_CpList1F1B[]	= { 0x1F13, 0 };
UINT	CaseFoldingCF_CpList1F1C[]	= { 0x1F14, 0 };
UINT	CaseFoldingCF_CpList1F1D[]	= { 0x1F15, 0 };
UINT	CaseFoldingCF_CpList1F28[]	= { 0x1F20, 0 };
UINT	CaseFoldingCF_CpList1F29[]	= { 0x1F21, 0 };
UINT	CaseFoldingCF_CpList1F2A[]	= { 0x1F22, 0 };
UINT	CaseFoldingCF_CpList1F2B[]	= { 0x1F23, 0 };
UINT	CaseFoldingCF_CpList1F2C[]	= { 0x1F24, 0 };
UINT	CaseFoldingCF_CpList1F2D[]	= { 0x1F25, 0 };
UINT	CaseFoldingCF_CpList1F2E[]	= { 0x1F26, 0 };
UINT	CaseFoldingCF_CpList1F2F[]	= { 0x1F27, 0 };
UINT	CaseFoldingCF_CpList1F38[]	= { 0x1F30, 0 };
UINT	CaseFoldingCF_CpList1F39[]	= { 0x1F31, 0 };
UINT	CaseFoldingCF_CpList1F3A[]	= { 0x1F32, 0 };
UINT	CaseFoldingCF_CpList1F3B[]	= { 0x1F33, 0 };
UINT	CaseFoldingCF_CpList1F3C[]	= { 0x1F34, 0 };
UINT	CaseFoldingCF_CpList1F3D[]	= { 0x1F35, 0 };
UINT	CaseFoldingCF_CpList1F3E[]	= { 0x1F36, 0 };
UINT	CaseFoldingCF_CpList1F3F[]	= { 0x1F37, 0 };
UINT	CaseFoldingCF_CpList1F48[]	= { 0x1F40, 0 };
UINT	CaseFoldingCF_CpList1F49[]	= { 0x1F41, 0 };
UINT	CaseFoldingCF_CpList1F4A[]	= { 0x1F42, 0 };
UINT	CaseFoldingCF_CpList1F4B[]	= { 0x1F43, 0 };
UINT	CaseFoldingCF_CpList1F4C[]	= { 0x1F44, 0 };
UINT	CaseFoldingCF_CpList1F4D[]	= { 0x1F45, 0 };
UINT	CaseFoldingCF_CpList1F50[]	= { 0x03C5, 0x0313, 0 };
UINT	CaseFoldingCF_CpList1F52[]	= { 0x03C5, 0x0313, 0x0300, 0 };
UINT	CaseFoldingCF_CpList1F54[]	= { 0x03C5, 0x0313, 0x0301, 0 };
UINT	CaseFoldingCF_CpList1F56[]	= { 0x03C5, 0x0313, 0x0342, 0 };
UINT	CaseFoldingCF_CpList1F59[]	= { 0x1F51, 0 };
UINT	CaseFoldingCF_CpList1F5B[]	= { 0x1F53, 0 };
UINT	CaseFoldingCF_CpList1F5D[]	= { 0x1F55, 0 };
UINT	CaseFoldingCF_CpList1F5F[]	= { 0x1F57, 0 };
UINT	CaseFoldingCF_CpList1F68[]	= { 0x1F60, 0 };
UINT	CaseFoldingCF_CpList1F69[]	= { 0x1F61, 0 };
UINT	CaseFoldingCF_CpList1F6A[]	= { 0x1F62, 0 };
UINT	CaseFoldingCF_CpList1F6B[]	= { 0x1F63, 0 };
UINT	CaseFoldingCF_CpList1F6C[]	= { 0x1F64, 0 };
UINT	CaseFoldingCF_CpList1F6D[]	= { 0x1F65, 0 };
UINT	CaseFoldingCF_CpList1F6E[]	= { 0x1F66, 0 };
UINT	CaseFoldingCF_CpList1F6F[]	= { 0x1F67, 0 };
UINT	CaseFoldingCF_CpList1F80[]	= { 0x1F00, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F81[]	= { 0x1F01, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F82[]	= { 0x1F02, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F83[]	= { 0x1F03, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F84[]	= { 0x1F04, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F85[]	= { 0x1F05, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F86[]	= { 0x1F06, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F87[]	= { 0x1F07, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F88[]	= { 0x1F00, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F89[]	= { 0x1F01, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F8A[]	= { 0x1F02, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F8B[]	= { 0x1F03, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F8C[]	= { 0x1F04, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F8D[]	= { 0x1F05, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F8E[]	= { 0x1F06, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F8F[]	= { 0x1F07, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F90[]	= { 0x1F20, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F91[]	= { 0x1F21, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F92[]	= { 0x1F22, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F93[]	= { 0x1F23, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F94[]	= { 0x1F24, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F95[]	= { 0x1F25, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F96[]	= { 0x1F26, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F97[]	= { 0x1F27, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F98[]	= { 0x1F20, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F99[]	= { 0x1F21, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F9A[]	= { 0x1F22, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F9B[]	= { 0x1F23, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F9C[]	= { 0x1F24, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F9D[]	= { 0x1F25, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F9E[]	= { 0x1F26, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1F9F[]	= { 0x1F27, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FA0[]	= { 0x1F60, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FA1[]	= { 0x1F61, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FA2[]	= { 0x1F62, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FA3[]	= { 0x1F63, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FA4[]	= { 0x1F64, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FA5[]	= { 0x1F65, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FA6[]	= { 0x1F66, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FA7[]	= { 0x1F67, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FA8[]	= { 0x1F60, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FA9[]	= { 0x1F61, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FAA[]	= { 0x1F62, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FAB[]	= { 0x1F63, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FAC[]	= { 0x1F64, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FAD[]	= { 0x1F65, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FAE[]	= { 0x1F66, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FAF[]	= { 0x1F67, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FB2[]	= { 0x1F70, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FB3[]	= { 0x03B1, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FB4[]	= { 0x03AC, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FB6[]	= { 0x03B1, 0x0342, 0 };
UINT	CaseFoldingCF_CpList1FB7[]	= { 0x03B1, 0x0342, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FB8[]	= { 0x1FB0, 0 };
UINT	CaseFoldingCF_CpList1FB9[]	= { 0x1FB1, 0 };
UINT	CaseFoldingCF_CpList1FBA[]	= { 0x1F70, 0 };
UINT	CaseFoldingCF_CpList1FBB[]	= { 0x1F71, 0 };
UINT	CaseFoldingCF_CpList1FBC[]	= { 0x03B1, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FBE[]	= { 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FC2[]	= { 0x1F74, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FC3[]	= { 0x03B7, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FC4[]	= { 0x03AE, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FC6[]	= { 0x03B7, 0x0342, 0 };
UINT	CaseFoldingCF_CpList1FC7[]	= { 0x03B7, 0x0342, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FC8[]	= { 0x1F72, 0 };
UINT	CaseFoldingCF_CpList1FC9[]	= { 0x1F73, 0 };
UINT	CaseFoldingCF_CpList1FCA[]	= { 0x1F74, 0 };
UINT	CaseFoldingCF_CpList1FCB[]	= { 0x1F75, 0 };
UINT	CaseFoldingCF_CpList1FCC[]	= { 0x03B7, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FD2[]	= { 0x03B9, 0x0308, 0x0300, 0 };
UINT	CaseFoldingCF_CpList1FD3[]	= { 0x03B9, 0x0308, 0x0301, 0 };
UINT	CaseFoldingCF_CpList1FD6[]	= { 0x03B9, 0x0342, 0 };
UINT	CaseFoldingCF_CpList1FD7[]	= { 0x03B9, 0x0308, 0x0342, 0 };
UINT	CaseFoldingCF_CpList1FD8[]	= { 0x1FD0, 0 };
UINT	CaseFoldingCF_CpList1FD9[]	= { 0x1FD1, 0 };
UINT	CaseFoldingCF_CpList1FDA[]	= { 0x1F76, 0 };
UINT	CaseFoldingCF_CpList1FDB[]	= { 0x1F77, 0 };
UINT	CaseFoldingCF_CpList1FE2[]	= { 0x03C5, 0x0308, 0x0300, 0 };
UINT	CaseFoldingCF_CpList1FE3[]	= { 0x03C5, 0x0308, 0x0301, 0 };
UINT	CaseFoldingCF_CpList1FE4[]	= { 0x03C1, 0x0313, 0 };
UINT	CaseFoldingCF_CpList1FE6[]	= { 0x03C5, 0x0342, 0 };
UINT	CaseFoldingCF_CpList1FE7[]	= { 0x03C5, 0x0308, 0x0342, 0 };
UINT	CaseFoldingCF_CpList1FE8[]	= { 0x1FE0, 0 };
UINT	CaseFoldingCF_CpList1FE9[]	= { 0x1FE1, 0 };
UINT	CaseFoldingCF_CpList1FEA[]	= { 0x1F7A, 0 };
UINT	CaseFoldingCF_CpList1FEB[]	= { 0x1F7B, 0 };
UINT	CaseFoldingCF_CpList1FEC[]	= { 0x1FE5, 0 };
UINT	CaseFoldingCF_CpList1FF2[]	= { 0x1F7C, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FF3[]	= { 0x03C9, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FF4[]	= { 0x03CE, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FF6[]	= { 0x03C9, 0x0342, 0 };
UINT	CaseFoldingCF_CpList1FF7[]	= { 0x03C9, 0x0342, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList1FF8[]	= { 0x1F78, 0 };
UINT	CaseFoldingCF_CpList1FF9[]	= { 0x1F79, 0 };
UINT	CaseFoldingCF_CpList1FFA[]	= { 0x1F7C, 0 };
UINT	CaseFoldingCF_CpList1FFB[]	= { 0x1F7D, 0 };
UINT	CaseFoldingCF_CpList1FFC[]	= { 0x03C9, 0x03B9, 0 };
UINT	CaseFoldingCF_CpList2126[]	= { 0x03C9, 0 };
UINT	CaseFoldingCF_CpList212A[]	= { 0x006B, 0 };
UINT	CaseFoldingCF_CpList212B[]	= { 0x00E5, 0 };
UINT	CaseFoldingCF_CpList2132[]	= { 0x214E, 0 };
UINT	CaseFoldingCF_CpList2160[]	= { 0x2170, 0 };
UINT	CaseFoldingCF_CpList2161[]	= { 0x2171, 0 };
UINT	CaseFoldingCF_CpList2162[]	= { 0x2172, 0 };
UINT	CaseFoldingCF_CpList2163[]	= { 0x2173, 0 };
UINT	CaseFoldingCF_CpList2164[]	= { 0x2174, 0 };
UINT	CaseFoldingCF_CpList2165[]	= { 0x2175, 0 };
UINT	CaseFoldingCF_CpList2166[]	= { 0x2176, 0 };
UINT	CaseFoldingCF_CpList2167[]	= { 0x2177, 0 };
UINT	CaseFoldingCF_CpList2168[]	= { 0x2178, 0 };
UINT	CaseFoldingCF_CpList2169[]	= { 0x2179, 0 };
UINT	CaseFoldingCF_CpList216A[]	= { 0x217A, 0 };
UINT	CaseFoldingCF_CpList216B[]	= { 0x217B, 0 };
UINT	CaseFoldingCF_CpList216C[]	= { 0x217C, 0 };
UINT	CaseFoldingCF_CpList216D[]	= { 0x217D, 0 };
UINT	CaseFoldingCF_CpList216E[]	= { 0x217E, 0 };
UINT	CaseFoldingCF_CpList216F[]	= { 0x217F, 0 };
UINT	CaseFoldingCF_CpList2183[]	= { 0x2184, 0 };
UINT	CaseFoldingCF_CpList24B6[]	= { 0x24D0, 0 };
UINT	CaseFoldingCF_CpList24B7[]	= { 0x24D1, 0 };
UINT	CaseFoldingCF_CpList24B8[]	= { 0x24D2, 0 };
UINT	CaseFoldingCF_CpList24B9[]	= { 0x24D3, 0 };
UINT	CaseFoldingCF_CpList24BA[]	= { 0x24D4, 0 };
UINT	CaseFoldingCF_CpList24BB[]	= { 0x24D5, 0 };
UINT	CaseFoldingCF_CpList24BC[]	= { 0x24D6, 0 };
UINT	CaseFoldingCF_CpList24BD[]	= { 0x24D7, 0 };
UINT	CaseFoldingCF_CpList24BE[]	= { 0x24D8, 0 };
UINT	CaseFoldingCF_CpList24BF[]	= { 0x24D9, 0 };
UINT	CaseFoldingCF_CpList24C0[]	= { 0x24DA, 0 };
UINT	CaseFoldingCF_CpList24C1[]	= { 0x24DB, 0 };
UINT	CaseFoldingCF_CpList24C2[]	= { 0x24DC, 0 };
UINT	CaseFoldingCF_CpList24C3[]	= { 0x24DD, 0 };
UINT	CaseFoldingCF_CpList24C4[]	= { 0x24DE, 0 };
UINT	CaseFoldingCF_CpList24C5[]	= { 0x24DF, 0 };
UINT	CaseFoldingCF_CpList24C6[]	= { 0x24E0, 0 };
UINT	CaseFoldingCF_CpList24C7[]	= { 0x24E1, 0 };
UINT	CaseFoldingCF_CpList24C8[]	= { 0x24E2, 0 };
UINT	CaseFoldingCF_CpList24C9[]	= { 0x24E3, 0 };
UINT	CaseFoldingCF_CpList24CA[]	= { 0x24E4, 0 };
UINT	CaseFoldingCF_CpList24CB[]	= { 0x24E5, 0 };
UINT	CaseFoldingCF_CpList24CC[]	= { 0x24E6, 0 };
UINT	CaseFoldingCF_CpList24CD[]	= { 0x24E7, 0 };
UINT	CaseFoldingCF_CpList24CE[]	= { 0x24E8, 0 };
UINT	CaseFoldingCF_CpList24CF[]	= { 0x24E9, 0 };
UINT	CaseFoldingCF_CpList2C00[]	= { 0x2C30, 0 };
UINT	CaseFoldingCF_CpList2C01[]	= { 0x2C31, 0 };
UINT	CaseFoldingCF_CpList2C02[]	= { 0x2C32, 0 };
UINT	CaseFoldingCF_CpList2C03[]	= { 0x2C33, 0 };
UINT	CaseFoldingCF_CpList2C04[]	= { 0x2C34, 0 };
UINT	CaseFoldingCF_CpList2C05[]	= { 0x2C35, 0 };
UINT	CaseFoldingCF_CpList2C06[]	= { 0x2C36, 0 };
UINT	CaseFoldingCF_CpList2C07[]	= { 0x2C37, 0 };
UINT	CaseFoldingCF_CpList2C08[]	= { 0x2C38, 0 };
UINT	CaseFoldingCF_CpList2C09[]	= { 0x2C39, 0 };
UINT	CaseFoldingCF_CpList2C0A[]	= { 0x2C3A, 0 };
UINT	CaseFoldingCF_CpList2C0B[]	= { 0x2C3B, 0 };
UINT	CaseFoldingCF_CpList2C0C[]	= { 0x2C3C, 0 };
UINT	CaseFoldingCF_CpList2C0D[]	= { 0x2C3D, 0 };
UINT	CaseFoldingCF_CpList2C0E[]	= { 0x2C3E, 0 };
UINT	CaseFoldingCF_CpList2C0F[]	= { 0x2C3F, 0 };
UINT	CaseFoldingCF_CpList2C10[]	= { 0x2C40, 0 };
UINT	CaseFoldingCF_CpList2C11[]	= { 0x2C41, 0 };
UINT	CaseFoldingCF_CpList2C12[]	= { 0x2C42, 0 };
UINT	CaseFoldingCF_CpList2C13[]	= { 0x2C43, 0 };
UINT	CaseFoldingCF_CpList2C14[]	= { 0x2C44, 0 };
UINT	CaseFoldingCF_CpList2C15[]	= { 0x2C45, 0 };
UINT	CaseFoldingCF_CpList2C16[]	= { 0x2C46, 0 };
UINT	CaseFoldingCF_CpList2C17[]	= { 0x2C47, 0 };
UINT	CaseFoldingCF_CpList2C18[]	= { 0x2C48, 0 };
UINT	CaseFoldingCF_CpList2C19[]	= { 0x2C49, 0 };
UINT	CaseFoldingCF_CpList2C1A[]	= { 0x2C4A, 0 };
UINT	CaseFoldingCF_CpList2C1B[]	= { 0x2C4B, 0 };
UINT	CaseFoldingCF_CpList2C1C[]	= { 0x2C4C, 0 };
UINT	CaseFoldingCF_CpList2C1D[]	= { 0x2C4D, 0 };
UINT	CaseFoldingCF_CpList2C1E[]	= { 0x2C4E, 0 };
UINT	CaseFoldingCF_CpList2C1F[]	= { 0x2C4F, 0 };
UINT	CaseFoldingCF_CpList2C20[]	= { 0x2C50, 0 };
UINT	CaseFoldingCF_CpList2C21[]	= { 0x2C51, 0 };
UINT	CaseFoldingCF_CpList2C22[]	= { 0x2C52, 0 };
UINT	CaseFoldingCF_CpList2C23[]	= { 0x2C53, 0 };
UINT	CaseFoldingCF_CpList2C24[]	= { 0x2C54, 0 };
UINT	CaseFoldingCF_CpList2C25[]	= { 0x2C55, 0 };
UINT	CaseFoldingCF_CpList2C26[]	= { 0x2C56, 0 };
UINT	CaseFoldingCF_CpList2C27[]	= { 0x2C57, 0 };
UINT	CaseFoldingCF_CpList2C28[]	= { 0x2C58, 0 };
UINT	CaseFoldingCF_CpList2C29[]	= { 0x2C59, 0 };
UINT	CaseFoldingCF_CpList2C2A[]	= { 0x2C5A, 0 };
UINT	CaseFoldingCF_CpList2C2B[]	= { 0x2C5B, 0 };
UINT	CaseFoldingCF_CpList2C2C[]	= { 0x2C5C, 0 };
UINT	CaseFoldingCF_CpList2C2D[]	= { 0x2C5D, 0 };
UINT	CaseFoldingCF_CpList2C2E[]	= { 0x2C5E, 0 };
UINT	CaseFoldingCF_CpList2C60[]	= { 0x2C61, 0 };
UINT	CaseFoldingCF_CpList2C62[]	= { 0x026B, 0 };
UINT	CaseFoldingCF_CpList2C63[]	= { 0x1D7D, 0 };
UINT	CaseFoldingCF_CpList2C64[]	= { 0x027D, 0 };
UINT	CaseFoldingCF_CpList2C67[]	= { 0x2C68, 0 };
UINT	CaseFoldingCF_CpList2C69[]	= { 0x2C6A, 0 };
UINT	CaseFoldingCF_CpList2C6B[]	= { 0x2C6C, 0 };
UINT	CaseFoldingCF_CpList2C6D[]	= { 0x0251, 0 };
UINT	CaseFoldingCF_CpList2C6E[]	= { 0x0271, 0 };
UINT	CaseFoldingCF_CpList2C6F[]	= { 0x0250, 0 };
UINT	CaseFoldingCF_CpList2C70[]	= { 0x0252, 0 };
UINT	CaseFoldingCF_CpList2C72[]	= { 0x2C73, 0 };
UINT	CaseFoldingCF_CpList2C75[]	= { 0x2C76, 0 };
UINT	CaseFoldingCF_CpList2C7E[]	= { 0x023F, 0 };
UINT	CaseFoldingCF_CpList2C7F[]	= { 0x0240, 0 };
UINT	CaseFoldingCF_CpList2C80[]	= { 0x2C81, 0 };
UINT	CaseFoldingCF_CpList2C82[]	= { 0x2C83, 0 };
UINT	CaseFoldingCF_CpList2C84[]	= { 0x2C85, 0 };
UINT	CaseFoldingCF_CpList2C86[]	= { 0x2C87, 0 };
UINT	CaseFoldingCF_CpList2C88[]	= { 0x2C89, 0 };
UINT	CaseFoldingCF_CpList2C8A[]	= { 0x2C8B, 0 };
UINT	CaseFoldingCF_CpList2C8C[]	= { 0x2C8D, 0 };
UINT	CaseFoldingCF_CpList2C8E[]	= { 0x2C8F, 0 };
UINT	CaseFoldingCF_CpList2C90[]	= { 0x2C91, 0 };
UINT	CaseFoldingCF_CpList2C92[]	= { 0x2C93, 0 };
UINT	CaseFoldingCF_CpList2C94[]	= { 0x2C95, 0 };
UINT	CaseFoldingCF_CpList2C96[]	= { 0x2C97, 0 };
UINT	CaseFoldingCF_CpList2C98[]	= { 0x2C99, 0 };
UINT	CaseFoldingCF_CpList2C9A[]	= { 0x2C9B, 0 };
UINT	CaseFoldingCF_CpList2C9C[]	= { 0x2C9D, 0 };
UINT	CaseFoldingCF_CpList2C9E[]	= { 0x2C9F, 0 };
UINT	CaseFoldingCF_CpList2CA0[]	= { 0x2CA1, 0 };
UINT	CaseFoldingCF_CpList2CA2[]	= { 0x2CA3, 0 };
UINT	CaseFoldingCF_CpList2CA4[]	= { 0x2CA5, 0 };
UINT	CaseFoldingCF_CpList2CA6[]	= { 0x2CA7, 0 };
UINT	CaseFoldingCF_CpList2CA8[]	= { 0x2CA9, 0 };
UINT	CaseFoldingCF_CpList2CAA[]	= { 0x2CAB, 0 };
UINT	CaseFoldingCF_CpList2CAC[]	= { 0x2CAD, 0 };
UINT	CaseFoldingCF_CpList2CAE[]	= { 0x2CAF, 0 };
UINT	CaseFoldingCF_CpList2CB0[]	= { 0x2CB1, 0 };
UINT	CaseFoldingCF_CpList2CB2[]	= { 0x2CB3, 0 };
UINT	CaseFoldingCF_CpList2CB4[]	= { 0x2CB5, 0 };
UINT	CaseFoldingCF_CpList2CB6[]	= { 0x2CB7, 0 };
UINT	CaseFoldingCF_CpList2CB8[]	= { 0x2CB9, 0 };
UINT	CaseFoldingCF_CpList2CBA[]	= { 0x2CBB, 0 };
UINT	CaseFoldingCF_CpList2CBC[]	= { 0x2CBD, 0 };
UINT	CaseFoldingCF_CpList2CBE[]	= { 0x2CBF, 0 };
UINT	CaseFoldingCF_CpList2CC0[]	= { 0x2CC1, 0 };
UINT	CaseFoldingCF_CpList2CC2[]	= { 0x2CC3, 0 };
UINT	CaseFoldingCF_CpList2CC4[]	= { 0x2CC5, 0 };
UINT	CaseFoldingCF_CpList2CC6[]	= { 0x2CC7, 0 };
UINT	CaseFoldingCF_CpList2CC8[]	= { 0x2CC9, 0 };
UINT	CaseFoldingCF_CpList2CCA[]	= { 0x2CCB, 0 };
UINT	CaseFoldingCF_CpList2CCC[]	= { 0x2CCD, 0 };
UINT	CaseFoldingCF_CpList2CCE[]	= { 0x2CCF, 0 };
UINT	CaseFoldingCF_CpList2CD0[]	= { 0x2CD1, 0 };
UINT	CaseFoldingCF_CpList2CD2[]	= { 0x2CD3, 0 };
UINT	CaseFoldingCF_CpList2CD4[]	= { 0x2CD5, 0 };
UINT	CaseFoldingCF_CpList2CD6[]	= { 0x2CD7, 0 };
UINT	CaseFoldingCF_CpList2CD8[]	= { 0x2CD9, 0 };
UINT	CaseFoldingCF_CpList2CDA[]	= { 0x2CDB, 0 };
UINT	CaseFoldingCF_CpList2CDC[]	= { 0x2CDD, 0 };
UINT	CaseFoldingCF_CpList2CDE[]	= { 0x2CDF, 0 };
UINT	CaseFoldingCF_CpList2CE0[]	= { 0x2CE1, 0 };
UINT	CaseFoldingCF_CpList2CE2[]	= { 0x2CE3, 0 };
UINT	CaseFoldingCF_CpList2CEB[]	= { 0x2CEC, 0 };
UINT	CaseFoldingCF_CpList2CED[]	= { 0x2CEE, 0 };
UINT	CaseFoldingCF_CpList2CF2[]	= { 0x2CF3, 0 };
UINT	CaseFoldingCF_CpListA640[]	= { 0xA641, 0 };
UINT	CaseFoldingCF_CpListA642[]	= { 0xA643, 0 };
UINT	CaseFoldingCF_CpListA644[]	= { 0xA645, 0 };
UINT	CaseFoldingCF_CpListA646[]	= { 0xA647, 0 };
UINT	CaseFoldingCF_CpListA648[]	= { 0xA649, 0 };
UINT	CaseFoldingCF_CpListA64A[]	= { 0xA64B, 0 };
UINT	CaseFoldingCF_CpListA64C[]	= { 0xA64D, 0 };
UINT	CaseFoldingCF_CpListA64E[]	= { 0xA64F, 0 };
UINT	CaseFoldingCF_CpListA650[]	= { 0xA651, 0 };
UINT	CaseFoldingCF_CpListA652[]	= { 0xA653, 0 };
UINT	CaseFoldingCF_CpListA654[]	= { 0xA655, 0 };
UINT	CaseFoldingCF_CpListA656[]	= { 0xA657, 0 };
UINT	CaseFoldingCF_CpListA658[]	= { 0xA659, 0 };
UINT	CaseFoldingCF_CpListA65A[]	= { 0xA65B, 0 };
UINT	CaseFoldingCF_CpListA65C[]	= { 0xA65D, 0 };
UINT	CaseFoldingCF_CpListA65E[]	= { 0xA65F, 0 };
UINT	CaseFoldingCF_CpListA660[]	= { 0xA661, 0 };
UINT	CaseFoldingCF_CpListA662[]	= { 0xA663, 0 };
UINT	CaseFoldingCF_CpListA664[]	= { 0xA665, 0 };
UINT	CaseFoldingCF_CpListA666[]	= { 0xA667, 0 };
UINT	CaseFoldingCF_CpListA668[]	= { 0xA669, 0 };
UINT	CaseFoldingCF_CpListA66A[]	= { 0xA66B, 0 };
UINT	CaseFoldingCF_CpListA66C[]	= { 0xA66D, 0 };
UINT	CaseFoldingCF_CpListA680[]	= { 0xA681, 0 };
UINT	CaseFoldingCF_CpListA682[]	= { 0xA683, 0 };
UINT	CaseFoldingCF_CpListA684[]	= { 0xA685, 0 };
UINT	CaseFoldingCF_CpListA686[]	= { 0xA687, 0 };
UINT	CaseFoldingCF_CpListA688[]	= { 0xA689, 0 };
UINT	CaseFoldingCF_CpListA68A[]	= { 0xA68B, 0 };
UINT	CaseFoldingCF_CpListA68C[]	= { 0xA68D, 0 };
UINT	CaseFoldingCF_CpListA68E[]	= { 0xA68F, 0 };
UINT	CaseFoldingCF_CpListA690[]	= { 0xA691, 0 };
UINT	CaseFoldingCF_CpListA692[]	= { 0xA693, 0 };
UINT	CaseFoldingCF_CpListA694[]	= { 0xA695, 0 };
UINT	CaseFoldingCF_CpListA696[]	= { 0xA697, 0 };
UINT	CaseFoldingCF_CpListA722[]	= { 0xA723, 0 };
UINT	CaseFoldingCF_CpListA724[]	= { 0xA725, 0 };
UINT	CaseFoldingCF_CpListA726[]	= { 0xA727, 0 };
UINT	CaseFoldingCF_CpListA728[]	= { 0xA729, 0 };
UINT	CaseFoldingCF_CpListA72A[]	= { 0xA72B, 0 };
UINT	CaseFoldingCF_CpListA72C[]	= { 0xA72D, 0 };
UINT	CaseFoldingCF_CpListA72E[]	= { 0xA72F, 0 };
UINT	CaseFoldingCF_CpListA732[]	= { 0xA733, 0 };
UINT	CaseFoldingCF_CpListA734[]	= { 0xA735, 0 };
UINT	CaseFoldingCF_CpListA736[]	= { 0xA737, 0 };
UINT	CaseFoldingCF_CpListA738[]	= { 0xA739, 0 };
UINT	CaseFoldingCF_CpListA73A[]	= { 0xA73B, 0 };
UINT	CaseFoldingCF_CpListA73C[]	= { 0xA73D, 0 };
UINT	CaseFoldingCF_CpListA73E[]	= { 0xA73F, 0 };
UINT	CaseFoldingCF_CpListA740[]	= { 0xA741, 0 };
UINT	CaseFoldingCF_CpListA742[]	= { 0xA743, 0 };
UINT	CaseFoldingCF_CpListA744[]	= { 0xA745, 0 };
UINT	CaseFoldingCF_CpListA746[]	= { 0xA747, 0 };
UINT	CaseFoldingCF_CpListA748[]	= { 0xA749, 0 };
UINT	CaseFoldingCF_CpListA74A[]	= { 0xA74B, 0 };
UINT	CaseFoldingCF_CpListA74C[]	= { 0xA74D, 0 };
UINT	CaseFoldingCF_CpListA74E[]	= { 0xA74F, 0 };
UINT	CaseFoldingCF_CpListA750[]	= { 0xA751, 0 };
UINT	CaseFoldingCF_CpListA752[]	= { 0xA753, 0 };
UINT	CaseFoldingCF_CpListA754[]	= { 0xA755, 0 };
UINT	CaseFoldingCF_CpListA756[]	= { 0xA757, 0 };
UINT	CaseFoldingCF_CpListA758[]	= { 0xA759, 0 };
UINT	CaseFoldingCF_CpListA75A[]	= { 0xA75B, 0 };
UINT	CaseFoldingCF_CpListA75C[]	= { 0xA75D, 0 };
UINT	CaseFoldingCF_CpListA75E[]	= { 0xA75F, 0 };
UINT	CaseFoldingCF_CpListA760[]	= { 0xA761, 0 };
UINT	CaseFoldingCF_CpListA762[]	= { 0xA763, 0 };
UINT	CaseFoldingCF_CpListA764[]	= { 0xA765, 0 };
UINT	CaseFoldingCF_CpListA766[]	= { 0xA767, 0 };
UINT	CaseFoldingCF_CpListA768[]	= { 0xA769, 0 };
UINT	CaseFoldingCF_CpListA76A[]	= { 0xA76B, 0 };
UINT	CaseFoldingCF_CpListA76C[]	= { 0xA76D, 0 };
UINT	CaseFoldingCF_CpListA76E[]	= { 0xA76F, 0 };
UINT	CaseFoldingCF_CpListA779[]	= { 0xA77A, 0 };
UINT	CaseFoldingCF_CpListA77B[]	= { 0xA77C, 0 };
UINT	CaseFoldingCF_CpListA77D[]	= { 0x1D79, 0 };
UINT	CaseFoldingCF_CpListA77E[]	= { 0xA77F, 0 };
UINT	CaseFoldingCF_CpListA780[]	= { 0xA781, 0 };
UINT	CaseFoldingCF_CpListA782[]	= { 0xA783, 0 };
UINT	CaseFoldingCF_CpListA784[]	= { 0xA785, 0 };
UINT	CaseFoldingCF_CpListA786[]	= { 0xA787, 0 };
UINT	CaseFoldingCF_CpListA78B[]	= { 0xA78C, 0 };
UINT	CaseFoldingCF_CpListA78D[]	= { 0x0265, 0 };
UINT	CaseFoldingCF_CpListA790[]	= { 0xA791, 0 };
UINT	CaseFoldingCF_CpListA792[]	= { 0xA793, 0 };
UINT	CaseFoldingCF_CpListA7A0[]	= { 0xA7A1, 0 };
UINT	CaseFoldingCF_CpListA7A2[]	= { 0xA7A3, 0 };
UINT	CaseFoldingCF_CpListA7A4[]	= { 0xA7A5, 0 };
UINT	CaseFoldingCF_CpListA7A6[]	= { 0xA7A7, 0 };
UINT	CaseFoldingCF_CpListA7A8[]	= { 0xA7A9, 0 };
UINT	CaseFoldingCF_CpListA7AA[]	= { 0x0266, 0 };
UINT	CaseFoldingCF_CpListFB00[]	= { 0x0066, 0x0066, 0 };
UINT	CaseFoldingCF_CpListFB01[]	= { 0x0066, 0x0069, 0 };
UINT	CaseFoldingCF_CpListFB02[]	= { 0x0066, 0x006C, 0 };
UINT	CaseFoldingCF_CpListFB03[]	= { 0x0066, 0x0066, 0x0069, 0 };
UINT	CaseFoldingCF_CpListFB04[]	= { 0x0066, 0x0066, 0x006C, 0 };
UINT	CaseFoldingCF_CpListFB05[]	= { 0x0073, 0x0074, 0 };
UINT	CaseFoldingCF_CpListFB06[]	= { 0x0073, 0x0074, 0 };
UINT	CaseFoldingCF_CpListFB13[]	= { 0x0574, 0x0576, 0 };
UINT	CaseFoldingCF_CpListFB14[]	= { 0x0574, 0x0565, 0 };
UINT	CaseFoldingCF_CpListFB15[]	= { 0x0574, 0x056B, 0 };
UINT	CaseFoldingCF_CpListFB16[]	= { 0x057E, 0x0576, 0 };
UINT	CaseFoldingCF_CpListFB17[]	= { 0x0574, 0x056D, 0 };
UINT	CaseFoldingCF_CpListFF21[]	= { 0xFF41, 0 };
UINT	CaseFoldingCF_CpListFF22[]	= { 0xFF42, 0 };
UINT	CaseFoldingCF_CpListFF23[]	= { 0xFF43, 0 };
UINT	CaseFoldingCF_CpListFF24[]	= { 0xFF44, 0 };
UINT	CaseFoldingCF_CpListFF25[]	= { 0xFF45, 0 };
UINT	CaseFoldingCF_CpListFF26[]	= { 0xFF46, 0 };
UINT	CaseFoldingCF_CpListFF27[]	= { 0xFF47, 0 };
UINT	CaseFoldingCF_CpListFF28[]	= { 0xFF48, 0 };
UINT	CaseFoldingCF_CpListFF29[]	= { 0xFF49, 0 };
UINT	CaseFoldingCF_CpListFF2A[]	= { 0xFF4A, 0 };
UINT	CaseFoldingCF_CpListFF2B[]	= { 0xFF4B, 0 };
UINT	CaseFoldingCF_CpListFF2C[]	= { 0xFF4C, 0 };
UINT	CaseFoldingCF_CpListFF2D[]	= { 0xFF4D, 0 };
UINT	CaseFoldingCF_CpListFF2E[]	= { 0xFF4E, 0 };
UINT	CaseFoldingCF_CpListFF2F[]	= { 0xFF4F, 0 };
UINT	CaseFoldingCF_CpListFF30[]	= { 0xFF50, 0 };
UINT	CaseFoldingCF_CpListFF31[]	= { 0xFF51, 0 };
UINT	CaseFoldingCF_CpListFF32[]	= { 0xFF52, 0 };
UINT	CaseFoldingCF_CpListFF33[]	= { 0xFF53, 0 };
UINT	CaseFoldingCF_CpListFF34[]	= { 0xFF54, 0 };
UINT	CaseFoldingCF_CpListFF35[]	= { 0xFF55, 0 };
UINT	CaseFoldingCF_CpListFF36[]	= { 0xFF56, 0 };
UINT	CaseFoldingCF_CpListFF37[]	= { 0xFF57, 0 };
UINT	CaseFoldingCF_CpListFF38[]	= { 0xFF58, 0 };
UINT	CaseFoldingCF_CpListFF39[]	= { 0xFF59, 0 };
UINT	CaseFoldingCF_CpListFF3A[]	= { 0xFF5A, 0 };
UINT	CaseFoldingCF_CpList10400[]	= { 0x10428, 0 };
UINT	CaseFoldingCF_CpList10401[]	= { 0x10429, 0 };
UINT	CaseFoldingCF_CpList10402[]	= { 0x1042A, 0 };
UINT	CaseFoldingCF_CpList10403[]	= { 0x1042B, 0 };
UINT	CaseFoldingCF_CpList10404[]	= { 0x1042C, 0 };
UINT	CaseFoldingCF_CpList10405[]	= { 0x1042D, 0 };
UINT	CaseFoldingCF_CpList10406[]	= { 0x1042E, 0 };
UINT	CaseFoldingCF_CpList10407[]	= { 0x1042F, 0 };
UINT	CaseFoldingCF_CpList10408[]	= { 0x10430, 0 };
UINT	CaseFoldingCF_CpList10409[]	= { 0x10431, 0 };
UINT	CaseFoldingCF_CpList1040A[]	= { 0x10432, 0 };
UINT	CaseFoldingCF_CpList1040B[]	= { 0x10433, 0 };
UINT	CaseFoldingCF_CpList1040C[]	= { 0x10434, 0 };
UINT	CaseFoldingCF_CpList1040D[]	= { 0x10435, 0 };
UINT	CaseFoldingCF_CpList1040E[]	= { 0x10436, 0 };
UINT	CaseFoldingCF_CpList1040F[]	= { 0x10437, 0 };
UINT	CaseFoldingCF_CpList10410[]	= { 0x10438, 0 };
UINT	CaseFoldingCF_CpList10411[]	= { 0x10439, 0 };
UINT	CaseFoldingCF_CpList10412[]	= { 0x1043A, 0 };
UINT	CaseFoldingCF_CpList10413[]	= { 0x1043B, 0 };
UINT	CaseFoldingCF_CpList10414[]	= { 0x1043C, 0 };
UINT	CaseFoldingCF_CpList10415[]	= { 0x1043D, 0 };
UINT	CaseFoldingCF_CpList10416[]	= { 0x1043E, 0 };
UINT	CaseFoldingCF_CpList10417[]	= { 0x1043F, 0 };
UINT	CaseFoldingCF_CpList10418[]	= { 0x10440, 0 };
UINT	CaseFoldingCF_CpList10419[]	= { 0x10441, 0 };
UINT	CaseFoldingCF_CpList1041A[]	= { 0x10442, 0 };
UINT	CaseFoldingCF_CpList1041B[]	= { 0x10443, 0 };
UINT	CaseFoldingCF_CpList1041C[]	= { 0x10444, 0 };
UINT	CaseFoldingCF_CpList1041D[]	= { 0x10445, 0 };
UINT	CaseFoldingCF_CpList1041E[]	= { 0x10446, 0 };
UINT	CaseFoldingCF_CpList1041F[]	= { 0x10447, 0 };
UINT	CaseFoldingCF_CpList10420[]	= { 0x10448, 0 };
UINT	CaseFoldingCF_CpList10421[]	= { 0x10449, 0 };
UINT	CaseFoldingCF_CpList10422[]	= { 0x1044A, 0 };
UINT	CaseFoldingCF_CpList10423[]	= { 0x1044B, 0 };
UINT	CaseFoldingCF_CpList10424[]	= { 0x1044C, 0 };
UINT	CaseFoldingCF_CpList10425[]	= { 0x1044D, 0 };
UINT	CaseFoldingCF_CpList10426[]	= { 0x1044E, 0 };
UINT	CaseFoldingCF_CpList10427[]	= { 0x1044F, 0 };

//----------------------------------------------------------------------
//	Common and Full Case Folding	: Info
//----------------------------------------------------------------------
SCASEFOLDMAP	siCaseFolding_CF[]	=
{
	0x0041,	CaseFoldingCF_CpList0041,	1,	TQU("\x0061"),
	0x0042,	CaseFoldingCF_CpList0042,	1,	TQU("\x0062"),
	0x0043,	CaseFoldingCF_CpList0043,	1,	TQU("\x0063"),
	0x0044,	CaseFoldingCF_CpList0044,	1,	TQU("\x0064"),
	0x0045,	CaseFoldingCF_CpList0045,	1,	TQU("\x0065"),
	0x0046,	CaseFoldingCF_CpList0046,	1,	TQU("\x0066"),
	0x0047,	CaseFoldingCF_CpList0047,	1,	TQU("\x0067"),
	0x0048,	CaseFoldingCF_CpList0048,	1,	TQU("\x0068"),
	0x0049,	CaseFoldingCF_CpList0049,	1,	TQU("\x0069"),
	0x004A,	CaseFoldingCF_CpList004A,	1,	TQU("\x006A"),
	0x004B,	CaseFoldingCF_CpList004B,	1,	TQU("\x006B"),
	0x004C,	CaseFoldingCF_CpList004C,	1,	TQU("\x006C"),
	0x004D,	CaseFoldingCF_CpList004D,	1,	TQU("\x006D"),
	0x004E,	CaseFoldingCF_CpList004E,	1,	TQU("\x006E"),
	0x004F,	CaseFoldingCF_CpList004F,	1,	TQU("\x006F"),
	0x0050,	CaseFoldingCF_CpList0050,	1,	TQU("\x0070"),
	0x0051,	CaseFoldingCF_CpList0051,	1,	TQU("\x0071"),
	0x0052,	CaseFoldingCF_CpList0052,	1,	TQU("\x0072"),
	0x0053,	CaseFoldingCF_CpList0053,	1,	TQU("\x0073"),
	0x0054,	CaseFoldingCF_CpList0054,	1,	TQU("\x0074"),
	0x0055,	CaseFoldingCF_CpList0055,	1,	TQU("\x0075"),
	0x0056,	CaseFoldingCF_CpList0056,	1,	TQU("\x0076"),
	0x0057,	CaseFoldingCF_CpList0057,	1,	TQU("\x0077"),
	0x0058,	CaseFoldingCF_CpList0058,	1,	TQU("\x0078"),
	0x0059,	CaseFoldingCF_CpList0059,	1,	TQU("\x0079"),
	0x005A,	CaseFoldingCF_CpList005A,	1,	TQU("\x007A"),
	0x00B5,	CaseFoldingCF_CpList00B5,	1,	TQU("\x03BC"),
	0x00C0,	CaseFoldingCF_CpList00C0,	1,	TQU("\x00E0"),
	0x00C1,	CaseFoldingCF_CpList00C1,	1,	TQU("\x00E1"),
	0x00C2,	CaseFoldingCF_CpList00C2,	1,	TQU("\x00E2"),
	0x00C3,	CaseFoldingCF_CpList00C3,	1,	TQU("\x00E3"),
	0x00C4,	CaseFoldingCF_CpList00C4,	1,	TQU("\x00E4"),
	0x00C5,	CaseFoldingCF_CpList00C5,	1,	TQU("\x00E5"),
	0x00C6,	CaseFoldingCF_CpList00C6,	1,	TQU("\x00E6"),
	0x00C7,	CaseFoldingCF_CpList00C7,	1,	TQU("\x00E7"),
	0x00C8,	CaseFoldingCF_CpList00C8,	1,	TQU("\x00E8"),
	0x00C9,	CaseFoldingCF_CpList00C9,	1,	TQU("\x00E9"),
	0x00CA,	CaseFoldingCF_CpList00CA,	1,	TQU("\x00EA"),
	0x00CB,	CaseFoldingCF_CpList00CB,	1,	TQU("\x00EB"),
	0x00CC,	CaseFoldingCF_CpList00CC,	1,	TQU("\x00EC"),
	0x00CD,	CaseFoldingCF_CpList00CD,	1,	TQU("\x00ED"),
	0x00CE,	CaseFoldingCF_CpList00CE,	1,	TQU("\x00EE"),
	0x00CF,	CaseFoldingCF_CpList00CF,	1,	TQU("\x00EF"),
	0x00D0,	CaseFoldingCF_CpList00D0,	1,	TQU("\x00F0"),
	0x00D1,	CaseFoldingCF_CpList00D1,	1,	TQU("\x00F1"),
	0x00D2,	CaseFoldingCF_CpList00D2,	1,	TQU("\x00F2"),
	0x00D3,	CaseFoldingCF_CpList00D3,	1,	TQU("\x00F3"),
	0x00D4,	CaseFoldingCF_CpList00D4,	1,	TQU("\x00F4"),
	0x00D5,	CaseFoldingCF_CpList00D5,	1,	TQU("\x00F5"),
	0x00D6,	CaseFoldingCF_CpList00D6,	1,	TQU("\x00F6"),
	0x00D8,	CaseFoldingCF_CpList00D8,	1,	TQU("\x00F8"),
	0x00D9,	CaseFoldingCF_CpList00D9,	1,	TQU("\x00F9"),
	0x00DA,	CaseFoldingCF_CpList00DA,	1,	TQU("\x00FA"),
	0x00DB,	CaseFoldingCF_CpList00DB,	1,	TQU("\x00FB"),
	0x00DC,	CaseFoldingCF_CpList00DC,	1,	TQU("\x00FC"),
	0x00DD,	CaseFoldingCF_CpList00DD,	1,	TQU("\x00FD"),
	0x00DE,	CaseFoldingCF_CpList00DE,	1,	TQU("\x00FE"),
	0x00DF,	CaseFoldingCF_CpList00DF,	2,	TQU("\x0073\x0073"),
	0x0100,	CaseFoldingCF_CpList0100,	1,	TQU("\x0101"),
	0x0102,	CaseFoldingCF_CpList0102,	1,	TQU("\x0103"),
	0x0104,	CaseFoldingCF_CpList0104,	1,	TQU("\x0105"),
	0x0106,	CaseFoldingCF_CpList0106,	1,	TQU("\x0107"),
	0x0108,	CaseFoldingCF_CpList0108,	1,	TQU("\x0109"),
	0x010A,	CaseFoldingCF_CpList010A,	1,	TQU("\x010B"),
	0x010C,	CaseFoldingCF_CpList010C,	1,	TQU("\x010D"),
	0x010E,	CaseFoldingCF_CpList010E,	1,	TQU("\x010F"),
	0x0110,	CaseFoldingCF_CpList0110,	1,	TQU("\x0111"),
	0x0112,	CaseFoldingCF_CpList0112,	1,	TQU("\x0113"),
	0x0114,	CaseFoldingCF_CpList0114,	1,	TQU("\x0115"),
	0x0116,	CaseFoldingCF_CpList0116,	1,	TQU("\x0117"),
	0x0118,	CaseFoldingCF_CpList0118,	1,	TQU("\x0119"),
	0x011A,	CaseFoldingCF_CpList011A,	1,	TQU("\x011B"),
	0x011C,	CaseFoldingCF_CpList011C,	1,	TQU("\x011D"),
	0x011E,	CaseFoldingCF_CpList011E,	1,	TQU("\x011F"),
	0x0120,	CaseFoldingCF_CpList0120,	1,	TQU("\x0121"),
	0x0122,	CaseFoldingCF_CpList0122,	1,	TQU("\x0123"),
	0x0124,	CaseFoldingCF_CpList0124,	1,	TQU("\x0125"),
	0x0126,	CaseFoldingCF_CpList0126,	1,	TQU("\x0127"),
	0x0128,	CaseFoldingCF_CpList0128,	1,	TQU("\x0129"),
	0x012A,	CaseFoldingCF_CpList012A,	1,	TQU("\x012B"),
	0x012C,	CaseFoldingCF_CpList012C,	1,	TQU("\x012D"),
	0x012E,	CaseFoldingCF_CpList012E,	1,	TQU("\x012F"),
	0x0130,	CaseFoldingCF_CpList0130,	2,	TQU("\x0069\x0307"),
	0x0132,	CaseFoldingCF_CpList0132,	1,	TQU("\x0133"),
	0x0134,	CaseFoldingCF_CpList0134,	1,	TQU("\x0135"),
	0x0136,	CaseFoldingCF_CpList0136,	1,	TQU("\x0137"),
	0x0139,	CaseFoldingCF_CpList0139,	1,	TQU("\x013A"),
	0x013B,	CaseFoldingCF_CpList013B,	1,	TQU("\x013C"),
	0x013D,	CaseFoldingCF_CpList013D,	1,	TQU("\x013E"),
	0x013F,	CaseFoldingCF_CpList013F,	1,	TQU("\x0140"),
	0x0141,	CaseFoldingCF_CpList0141,	1,	TQU("\x0142"),
	0x0143,	CaseFoldingCF_CpList0143,	1,	TQU("\x0144"),
	0x0145,	CaseFoldingCF_CpList0145,	1,	TQU("\x0146"),
	0x0147,	CaseFoldingCF_CpList0147,	1,	TQU("\x0148"),
	0x0149,	CaseFoldingCF_CpList0149,	2,	TQU("\x02BC\x006E"),
	0x014A,	CaseFoldingCF_CpList014A,	1,	TQU("\x014B"),
	0x014C,	CaseFoldingCF_CpList014C,	1,	TQU("\x014D"),
	0x014E,	CaseFoldingCF_CpList014E,	1,	TQU("\x014F"),
	0x0150,	CaseFoldingCF_CpList0150,	1,	TQU("\x0151"),
	0x0152,	CaseFoldingCF_CpList0152,	1,	TQU("\x0153"),
	0x0154,	CaseFoldingCF_CpList0154,	1,	TQU("\x0155"),
	0x0156,	CaseFoldingCF_CpList0156,	1,	TQU("\x0157"),
	0x0158,	CaseFoldingCF_CpList0158,	1,	TQU("\x0159"),
	0x015A,	CaseFoldingCF_CpList015A,	1,	TQU("\x015B"),
	0x015C,	CaseFoldingCF_CpList015C,	1,	TQU("\x015D"),
	0x015E,	CaseFoldingCF_CpList015E,	1,	TQU("\x015F"),
	0x0160,	CaseFoldingCF_CpList0160,	1,	TQU("\x0161"),
	0x0162,	CaseFoldingCF_CpList0162,	1,	TQU("\x0163"),
	0x0164,	CaseFoldingCF_CpList0164,	1,	TQU("\x0165"),
	0x0166,	CaseFoldingCF_CpList0166,	1,	TQU("\x0167"),
	0x0168,	CaseFoldingCF_CpList0168,	1,	TQU("\x0169"),
	0x016A,	CaseFoldingCF_CpList016A,	1,	TQU("\x016B"),
	0x016C,	CaseFoldingCF_CpList016C,	1,	TQU("\x016D"),
	0x016E,	CaseFoldingCF_CpList016E,	1,	TQU("\x016F"),
	0x0170,	CaseFoldingCF_CpList0170,	1,	TQU("\x0171"),
	0x0172,	CaseFoldingCF_CpList0172,	1,	TQU("\x0173"),
	0x0174,	CaseFoldingCF_CpList0174,	1,	TQU("\x0175"),
	0x0176,	CaseFoldingCF_CpList0176,	1,	TQU("\x0177"),
	0x0178,	CaseFoldingCF_CpList0178,	1,	TQU("\x00FF"),
	0x0179,	CaseFoldingCF_CpList0179,	1,	TQU("\x017A"),
	0x017B,	CaseFoldingCF_CpList017B,	1,	TQU("\x017C"),
	0x017D,	CaseFoldingCF_CpList017D,	1,	TQU("\x017E"),
	0x017F,	CaseFoldingCF_CpList017F,	1,	TQU("\x0073"),
	0x0181,	CaseFoldingCF_CpList0181,	1,	TQU("\x0253"),
	0x0182,	CaseFoldingCF_CpList0182,	1,	TQU("\x0183"),
	0x0184,	CaseFoldingCF_CpList0184,	1,	TQU("\x0185"),
	0x0186,	CaseFoldingCF_CpList0186,	1,	TQU("\x0254"),
	0x0187,	CaseFoldingCF_CpList0187,	1,	TQU("\x0188"),
	0x0189,	CaseFoldingCF_CpList0189,	1,	TQU("\x0256"),
	0x018A,	CaseFoldingCF_CpList018A,	1,	TQU("\x0257"),
	0x018B,	CaseFoldingCF_CpList018B,	1,	TQU("\x018C"),
	0x018E,	CaseFoldingCF_CpList018E,	1,	TQU("\x01DD"),
	0x018F,	CaseFoldingCF_CpList018F,	1,	TQU("\x0259"),
	0x0190,	CaseFoldingCF_CpList0190,	1,	TQU("\x025B"),
	0x0191,	CaseFoldingCF_CpList0191,	1,	TQU("\x0192"),
	0x0193,	CaseFoldingCF_CpList0193,	1,	TQU("\x0260"),
	0x0194,	CaseFoldingCF_CpList0194,	1,	TQU("\x0263"),
	0x0196,	CaseFoldingCF_CpList0196,	1,	TQU("\x0269"),
	0x0197,	CaseFoldingCF_CpList0197,	1,	TQU("\x0268"),
	0x0198,	CaseFoldingCF_CpList0198,	1,	TQU("\x0199"),
	0x019C,	CaseFoldingCF_CpList019C,	1,	TQU("\x026F"),
	0x019D,	CaseFoldingCF_CpList019D,	1,	TQU("\x0272"),
	0x019F,	CaseFoldingCF_CpList019F,	1,	TQU("\x0275"),
	0x01A0,	CaseFoldingCF_CpList01A0,	1,	TQU("\x01A1"),
	0x01A2,	CaseFoldingCF_CpList01A2,	1,	TQU("\x01A3"),
	0x01A4,	CaseFoldingCF_CpList01A4,	1,	TQU("\x01A5"),
	0x01A6,	CaseFoldingCF_CpList01A6,	1,	TQU("\x0280"),
	0x01A7,	CaseFoldingCF_CpList01A7,	1,	TQU("\x01A8"),
	0x01A9,	CaseFoldingCF_CpList01A9,	1,	TQU("\x0283"),
	0x01AC,	CaseFoldingCF_CpList01AC,	1,	TQU("\x01AD"),
	0x01AE,	CaseFoldingCF_CpList01AE,	1,	TQU("\x0288"),
	0x01AF,	CaseFoldingCF_CpList01AF,	1,	TQU("\x01B0"),
	0x01B1,	CaseFoldingCF_CpList01B1,	1,	TQU("\x028A"),
	0x01B2,	CaseFoldingCF_CpList01B2,	1,	TQU("\x028B"),
	0x01B3,	CaseFoldingCF_CpList01B3,	1,	TQU("\x01B4"),
	0x01B5,	CaseFoldingCF_CpList01B5,	1,	TQU("\x01B6"),
	0x01B7,	CaseFoldingCF_CpList01B7,	1,	TQU("\x0292"),
	0x01B8,	CaseFoldingCF_CpList01B8,	1,	TQU("\x01B9"),
	0x01BC,	CaseFoldingCF_CpList01BC,	1,	TQU("\x01BD"),
	0x01C4,	CaseFoldingCF_CpList01C4,	1,	TQU("\x01C6"),
	0x01C5,	CaseFoldingCF_CpList01C5,	1,	TQU("\x01C6"),
	0x01C7,	CaseFoldingCF_CpList01C7,	1,	TQU("\x01C9"),
	0x01C8,	CaseFoldingCF_CpList01C8,	1,	TQU("\x01C9"),
	0x01CA,	CaseFoldingCF_CpList01CA,	1,	TQU("\x01CC"),
	0x01CB,	CaseFoldingCF_CpList01CB,	1,	TQU("\x01CC"),
	0x01CD,	CaseFoldingCF_CpList01CD,	1,	TQU("\x01CE"),
	0x01CF,	CaseFoldingCF_CpList01CF,	1,	TQU("\x01D0"),
	0x01D1,	CaseFoldingCF_CpList01D1,	1,	TQU("\x01D2"),
	0x01D3,	CaseFoldingCF_CpList01D3,	1,	TQU("\x01D4"),
	0x01D5,	CaseFoldingCF_CpList01D5,	1,	TQU("\x01D6"),
	0x01D7,	CaseFoldingCF_CpList01D7,	1,	TQU("\x01D8"),
	0x01D9,	CaseFoldingCF_CpList01D9,	1,	TQU("\x01DA"),
	0x01DB,	CaseFoldingCF_CpList01DB,	1,	TQU("\x01DC"),
	0x01DE,	CaseFoldingCF_CpList01DE,	1,	TQU("\x01DF"),
	0x01E0,	CaseFoldingCF_CpList01E0,	1,	TQU("\x01E1"),
	0x01E2,	CaseFoldingCF_CpList01E2,	1,	TQU("\x01E3"),
	0x01E4,	CaseFoldingCF_CpList01E4,	1,	TQU("\x01E5"),
	0x01E6,	CaseFoldingCF_CpList01E6,	1,	TQU("\x01E7"),
	0x01E8,	CaseFoldingCF_CpList01E8,	1,	TQU("\x01E9"),
	0x01EA,	CaseFoldingCF_CpList01EA,	1,	TQU("\x01EB"),
	0x01EC,	CaseFoldingCF_CpList01EC,	1,	TQU("\x01ED"),
	0x01EE,	CaseFoldingCF_CpList01EE,	1,	TQU("\x01EF"),
	0x01F0,	CaseFoldingCF_CpList01F0,	2,	TQU("\x006A\x030C"),
	0x01F1,	CaseFoldingCF_CpList01F1,	1,	TQU("\x01F3"),
	0x01F2,	CaseFoldingCF_CpList01F2,	1,	TQU("\x01F3"),
	0x01F4,	CaseFoldingCF_CpList01F4,	1,	TQU("\x01F5"),
	0x01F6,	CaseFoldingCF_CpList01F6,	1,	TQU("\x0195"),
	0x01F7,	CaseFoldingCF_CpList01F7,	1,	TQU("\x01BF"),
	0x01F8,	CaseFoldingCF_CpList01F8,	1,	TQU("\x01F9"),
	0x01FA,	CaseFoldingCF_CpList01FA,	1,	TQU("\x01FB"),
	0x01FC,	CaseFoldingCF_CpList01FC,	1,	TQU("\x01FD"),
	0x01FE,	CaseFoldingCF_CpList01FE,	1,	TQU("\x01FF"),
	0x0200,	CaseFoldingCF_CpList0200,	1,	TQU("\x0201"),
	0x0202,	CaseFoldingCF_CpList0202,	1,	TQU("\x0203"),
	0x0204,	CaseFoldingCF_CpList0204,	1,	TQU("\x0205"),
	0x0206,	CaseFoldingCF_CpList0206,	1,	TQU("\x0207"),
	0x0208,	CaseFoldingCF_CpList0208,	1,	TQU("\x0209"),
	0x020A,	CaseFoldingCF_CpList020A,	1,	TQU("\x020B"),
	0x020C,	CaseFoldingCF_CpList020C,	1,	TQU("\x020D"),
	0x020E,	CaseFoldingCF_CpList020E,	1,	TQU("\x020F"),
	0x0210,	CaseFoldingCF_CpList0210,	1,	TQU("\x0211"),
	0x0212,	CaseFoldingCF_CpList0212,	1,	TQU("\x0213"),
	0x0214,	CaseFoldingCF_CpList0214,	1,	TQU("\x0215"),
	0x0216,	CaseFoldingCF_CpList0216,	1,	TQU("\x0217"),
	0x0218,	CaseFoldingCF_CpList0218,	1,	TQU("\x0219"),
	0x021A,	CaseFoldingCF_CpList021A,	1,	TQU("\x021B"),
	0x021C,	CaseFoldingCF_CpList021C,	1,	TQU("\x021D"),
	0x021E,	CaseFoldingCF_CpList021E,	1,	TQU("\x021F"),
	0x0220,	CaseFoldingCF_CpList0220,	1,	TQU("\x019E"),
	0x0222,	CaseFoldingCF_CpList0222,	1,	TQU("\x0223"),
	0x0224,	CaseFoldingCF_CpList0224,	1,	TQU("\x0225"),
	0x0226,	CaseFoldingCF_CpList0226,	1,	TQU("\x0227"),
	0x0228,	CaseFoldingCF_CpList0228,	1,	TQU("\x0229"),
	0x022A,	CaseFoldingCF_CpList022A,	1,	TQU("\x022B"),
	0x022C,	CaseFoldingCF_CpList022C,	1,	TQU("\x022D"),
	0x022E,	CaseFoldingCF_CpList022E,	1,	TQU("\x022F"),
	0x0230,	CaseFoldingCF_CpList0230,	1,	TQU("\x0231"),
	0x0232,	CaseFoldingCF_CpList0232,	1,	TQU("\x0233"),
	0x023A,	CaseFoldingCF_CpList023A,	1,	TQU("\x2C65"),
	0x023B,	CaseFoldingCF_CpList023B,	1,	TQU("\x023C"),
	0x023D,	CaseFoldingCF_CpList023D,	1,	TQU("\x019A"),
	0x023E,	CaseFoldingCF_CpList023E,	1,	TQU("\x2C66"),
	0x0241,	CaseFoldingCF_CpList0241,	1,	TQU("\x0242"),
	0x0243,	CaseFoldingCF_CpList0243,	1,	TQU("\x0180"),
	0x0244,	CaseFoldingCF_CpList0244,	1,	TQU("\x0289"),
	0x0245,	CaseFoldingCF_CpList0245,	1,	TQU("\x028C"),
	0x0246,	CaseFoldingCF_CpList0246,	1,	TQU("\x0247"),
	0x0248,	CaseFoldingCF_CpList0248,	1,	TQU("\x0249"),
	0x024A,	CaseFoldingCF_CpList024A,	1,	TQU("\x024B"),
	0x024C,	CaseFoldingCF_CpList024C,	1,	TQU("\x024D"),
	0x024E,	CaseFoldingCF_CpList024E,	1,	TQU("\x024F"),
	0x0345,	CaseFoldingCF_CpList0345,	1,	TQU("\x03B9"),
	0x0370,	CaseFoldingCF_CpList0370,	1,	TQU("\x0371"),
	0x0372,	CaseFoldingCF_CpList0372,	1,	TQU("\x0373"),
	0x0376,	CaseFoldingCF_CpList0376,	1,	TQU("\x0377"),
	0x0386,	CaseFoldingCF_CpList0386,	1,	TQU("\x03AC"),
	0x0388,	CaseFoldingCF_CpList0388,	1,	TQU("\x03AD"),
	0x0389,	CaseFoldingCF_CpList0389,	1,	TQU("\x03AE"),
	0x038A,	CaseFoldingCF_CpList038A,	1,	TQU("\x03AF"),
	0x038C,	CaseFoldingCF_CpList038C,	1,	TQU("\x03CC"),
	0x038E,	CaseFoldingCF_CpList038E,	1,	TQU("\x03CD"),
	0x038F,	CaseFoldingCF_CpList038F,	1,	TQU("\x03CE"),
	0x0390,	CaseFoldingCF_CpList0390,	3,	TQU("\x03B9\x0308\x0301"),
	0x0391,	CaseFoldingCF_CpList0391,	1,	TQU("\x03B1"),
	0x0392,	CaseFoldingCF_CpList0392,	1,	TQU("\x03B2"),
	0x0393,	CaseFoldingCF_CpList0393,	1,	TQU("\x03B3"),
	0x0394,	CaseFoldingCF_CpList0394,	1,	TQU("\x03B4"),
	0x0395,	CaseFoldingCF_CpList0395,	1,	TQU("\x03B5"),
	0x0396,	CaseFoldingCF_CpList0396,	1,	TQU("\x03B6"),
	0x0397,	CaseFoldingCF_CpList0397,	1,	TQU("\x03B7"),
	0x0398,	CaseFoldingCF_CpList0398,	1,	TQU("\x03B8"),
	0x0399,	CaseFoldingCF_CpList0399,	1,	TQU("\x03B9"),
	0x039A,	CaseFoldingCF_CpList039A,	1,	TQU("\x03BA"),
	0x039B,	CaseFoldingCF_CpList039B,	1,	TQU("\x03BB"),
	0x039C,	CaseFoldingCF_CpList039C,	1,	TQU("\x03BC"),
	0x039D,	CaseFoldingCF_CpList039D,	1,	TQU("\x03BD"),
	0x039E,	CaseFoldingCF_CpList039E,	1,	TQU("\x03BE"),
	0x039F,	CaseFoldingCF_CpList039F,	1,	TQU("\x03BF"),
	0x03A0,	CaseFoldingCF_CpList03A0,	1,	TQU("\x03C0"),
	0x03A1,	CaseFoldingCF_CpList03A1,	1,	TQU("\x03C1"),
	0x03A3,	CaseFoldingCF_CpList03A3,	1,	TQU("\x03C3"),
	0x03A4,	CaseFoldingCF_CpList03A4,	1,	TQU("\x03C4"),
	0x03A5,	CaseFoldingCF_CpList03A5,	1,	TQU("\x03C5"),
	0x03A6,	CaseFoldingCF_CpList03A6,	1,	TQU("\x03C6"),
	0x03A7,	CaseFoldingCF_CpList03A7,	1,	TQU("\x03C7"),
	0x03A8,	CaseFoldingCF_CpList03A8,	1,	TQU("\x03C8"),
	0x03A9,	CaseFoldingCF_CpList03A9,	1,	TQU("\x03C9"),
	0x03AA,	CaseFoldingCF_CpList03AA,	1,	TQU("\x03CA"),
	0x03AB,	CaseFoldingCF_CpList03AB,	1,	TQU("\x03CB"),
	0x03B0,	CaseFoldingCF_CpList03B0,	3,	TQU("\x03C5\x0308\x0301"),
	0x03C2,	CaseFoldingCF_CpList03C2,	1,	TQU("\x03C3"),
	0x03CF,	CaseFoldingCF_CpList03CF,	1,	TQU("\x03D7"),
	0x03D0,	CaseFoldingCF_CpList03D0,	1,	TQU("\x03B2"),
	0x03D1,	CaseFoldingCF_CpList03D1,	1,	TQU("\x03B8"),
	0x03D5,	CaseFoldingCF_CpList03D5,	1,	TQU("\x03C6"),
	0x03D6,	CaseFoldingCF_CpList03D6,	1,	TQU("\x03C0"),
	0x03D8,	CaseFoldingCF_CpList03D8,	1,	TQU("\x03D9"),
	0x03DA,	CaseFoldingCF_CpList03DA,	1,	TQU("\x03DB"),
	0x03DC,	CaseFoldingCF_CpList03DC,	1,	TQU("\x03DD"),
	0x03DE,	CaseFoldingCF_CpList03DE,	1,	TQU("\x03DF"),
	0x03E0,	CaseFoldingCF_CpList03E0,	1,	TQU("\x03E1"),
	0x03E2,	CaseFoldingCF_CpList03E2,	1,	TQU("\x03E3"),
	0x03E4,	CaseFoldingCF_CpList03E4,	1,	TQU("\x03E5"),
	0x03E6,	CaseFoldingCF_CpList03E6,	1,	TQU("\x03E7"),
	0x03E8,	CaseFoldingCF_CpList03E8,	1,	TQU("\x03E9"),
	0x03EA,	CaseFoldingCF_CpList03EA,	1,	TQU("\x03EB"),
	0x03EC,	CaseFoldingCF_CpList03EC,	1,	TQU("\x03ED"),
	0x03EE,	CaseFoldingCF_CpList03EE,	1,	TQU("\x03EF"),
	0x03F0,	CaseFoldingCF_CpList03F0,	1,	TQU("\x03BA"),
	0x03F1,	CaseFoldingCF_CpList03F1,	1,	TQU("\x03C1"),
	0x03F4,	CaseFoldingCF_CpList03F4,	1,	TQU("\x03B8"),
	0x03F5,	CaseFoldingCF_CpList03F5,	1,	TQU("\x03B5"),
	0x03F7,	CaseFoldingCF_CpList03F7,	1,	TQU("\x03F8"),
	0x03F9,	CaseFoldingCF_CpList03F9,	1,	TQU("\x03F2"),
	0x03FA,	CaseFoldingCF_CpList03FA,	1,	TQU("\x03FB"),
	0x03FD,	CaseFoldingCF_CpList03FD,	1,	TQU("\x037B"),
	0x03FE,	CaseFoldingCF_CpList03FE,	1,	TQU("\x037C"),
	0x03FF,	CaseFoldingCF_CpList03FF,	1,	TQU("\x037D"),
	0x0400,	CaseFoldingCF_CpList0400,	1,	TQU("\x0450"),
	0x0401,	CaseFoldingCF_CpList0401,	1,	TQU("\x0451"),
	0x0402,	CaseFoldingCF_CpList0402,	1,	TQU("\x0452"),
	0x0403,	CaseFoldingCF_CpList0403,	1,	TQU("\x0453"),
	0x0404,	CaseFoldingCF_CpList0404,	1,	TQU("\x0454"),
	0x0405,	CaseFoldingCF_CpList0405,	1,	TQU("\x0455"),
	0x0406,	CaseFoldingCF_CpList0406,	1,	TQU("\x0456"),
	0x0407,	CaseFoldingCF_CpList0407,	1,	TQU("\x0457"),
	0x0408,	CaseFoldingCF_CpList0408,	1,	TQU("\x0458"),
	0x0409,	CaseFoldingCF_CpList0409,	1,	TQU("\x0459"),
	0x040A,	CaseFoldingCF_CpList040A,	1,	TQU("\x045A"),
	0x040B,	CaseFoldingCF_CpList040B,	1,	TQU("\x045B"),
	0x040C,	CaseFoldingCF_CpList040C,	1,	TQU("\x045C"),
	0x040D,	CaseFoldingCF_CpList040D,	1,	TQU("\x045D"),
	0x040E,	CaseFoldingCF_CpList040E,	1,	TQU("\x045E"),
	0x040F,	CaseFoldingCF_CpList040F,	1,	TQU("\x045F"),
	0x0410,	CaseFoldingCF_CpList0410,	1,	TQU("\x0430"),
	0x0411,	CaseFoldingCF_CpList0411,	1,	TQU("\x0431"),
	0x0412,	CaseFoldingCF_CpList0412,	1,	TQU("\x0432"),
	0x0413,	CaseFoldingCF_CpList0413,	1,	TQU("\x0433"),
	0x0414,	CaseFoldingCF_CpList0414,	1,	TQU("\x0434"),
	0x0415,	CaseFoldingCF_CpList0415,	1,	TQU("\x0435"),
	0x0416,	CaseFoldingCF_CpList0416,	1,	TQU("\x0436"),
	0x0417,	CaseFoldingCF_CpList0417,	1,	TQU("\x0437"),
	0x0418,	CaseFoldingCF_CpList0418,	1,	TQU("\x0438"),
	0x0419,	CaseFoldingCF_CpList0419,	1,	TQU("\x0439"),
	0x041A,	CaseFoldingCF_CpList041A,	1,	TQU("\x043A"),
	0x041B,	CaseFoldingCF_CpList041B,	1,	TQU("\x043B"),
	0x041C,	CaseFoldingCF_CpList041C,	1,	TQU("\x043C"),
	0x041D,	CaseFoldingCF_CpList041D,	1,	TQU("\x043D"),
	0x041E,	CaseFoldingCF_CpList041E,	1,	TQU("\x043E"),
	0x041F,	CaseFoldingCF_CpList041F,	1,	TQU("\x043F"),
	0x0420,	CaseFoldingCF_CpList0420,	1,	TQU("\x0440"),
	0x0421,	CaseFoldingCF_CpList0421,	1,	TQU("\x0441"),
	0x0422,	CaseFoldingCF_CpList0422,	1,	TQU("\x0442"),
	0x0423,	CaseFoldingCF_CpList0423,	1,	TQU("\x0443"),
	0x0424,	CaseFoldingCF_CpList0424,	1,	TQU("\x0444"),
	0x0425,	CaseFoldingCF_CpList0425,	1,	TQU("\x0445"),
	0x0426,	CaseFoldingCF_CpList0426,	1,	TQU("\x0446"),
	0x0427,	CaseFoldingCF_CpList0427,	1,	TQU("\x0447"),
	0x0428,	CaseFoldingCF_CpList0428,	1,	TQU("\x0448"),
	0x0429,	CaseFoldingCF_CpList0429,	1,	TQU("\x0449"),
	0x042A,	CaseFoldingCF_CpList042A,	1,	TQU("\x044A"),
	0x042B,	CaseFoldingCF_CpList042B,	1,	TQU("\x044B"),
	0x042C,	CaseFoldingCF_CpList042C,	1,	TQU("\x044C"),
	0x042D,	CaseFoldingCF_CpList042D,	1,	TQU("\x044D"),
	0x042E,	CaseFoldingCF_CpList042E,	1,	TQU("\x044E"),
	0x042F,	CaseFoldingCF_CpList042F,	1,	TQU("\x044F"),
	0x0460,	CaseFoldingCF_CpList0460,	1,	TQU("\x0461"),
	0x0462,	CaseFoldingCF_CpList0462,	1,	TQU("\x0463"),
	0x0464,	CaseFoldingCF_CpList0464,	1,	TQU("\x0465"),
	0x0466,	CaseFoldingCF_CpList0466,	1,	TQU("\x0467"),
	0x0468,	CaseFoldingCF_CpList0468,	1,	TQU("\x0469"),
	0x046A,	CaseFoldingCF_CpList046A,	1,	TQU("\x046B"),
	0x046C,	CaseFoldingCF_CpList046C,	1,	TQU("\x046D"),
	0x046E,	CaseFoldingCF_CpList046E,	1,	TQU("\x046F"),
	0x0470,	CaseFoldingCF_CpList0470,	1,	TQU("\x0471"),
	0x0472,	CaseFoldingCF_CpList0472,	1,	TQU("\x0473"),
	0x0474,	CaseFoldingCF_CpList0474,	1,	TQU("\x0475"),
	0x0476,	CaseFoldingCF_CpList0476,	1,	TQU("\x0477"),
	0x0478,	CaseFoldingCF_CpList0478,	1,	TQU("\x0479"),
	0x047A,	CaseFoldingCF_CpList047A,	1,	TQU("\x047B"),
	0x047C,	CaseFoldingCF_CpList047C,	1,	TQU("\x047D"),
	0x047E,	CaseFoldingCF_CpList047E,	1,	TQU("\x047F"),
	0x0480,	CaseFoldingCF_CpList0480,	1,	TQU("\x0481"),
	0x048A,	CaseFoldingCF_CpList048A,	1,	TQU("\x048B"),
	0x048C,	CaseFoldingCF_CpList048C,	1,	TQU("\x048D"),
	0x048E,	CaseFoldingCF_CpList048E,	1,	TQU("\x048F"),
	0x0490,	CaseFoldingCF_CpList0490,	1,	TQU("\x0491"),
	0x0492,	CaseFoldingCF_CpList0492,	1,	TQU("\x0493"),
	0x0494,	CaseFoldingCF_CpList0494,	1,	TQU("\x0495"),
	0x0496,	CaseFoldingCF_CpList0496,	1,	TQU("\x0497"),
	0x0498,	CaseFoldingCF_CpList0498,	1,	TQU("\x0499"),
	0x049A,	CaseFoldingCF_CpList049A,	1,	TQU("\x049B"),
	0x049C,	CaseFoldingCF_CpList049C,	1,	TQU("\x049D"),
	0x049E,	CaseFoldingCF_CpList049E,	1,	TQU("\x049F"),
	0x04A0,	CaseFoldingCF_CpList04A0,	1,	TQU("\x04A1"),
	0x04A2,	CaseFoldingCF_CpList04A2,	1,	TQU("\x04A3"),
	0x04A4,	CaseFoldingCF_CpList04A4,	1,	TQU("\x04A5"),
	0x04A6,	CaseFoldingCF_CpList04A6,	1,	TQU("\x04A7"),
	0x04A8,	CaseFoldingCF_CpList04A8,	1,	TQU("\x04A9"),
	0x04AA,	CaseFoldingCF_CpList04AA,	1,	TQU("\x04AB"),
	0x04AC,	CaseFoldingCF_CpList04AC,	1,	TQU("\x04AD"),
	0x04AE,	CaseFoldingCF_CpList04AE,	1,	TQU("\x04AF"),
	0x04B0,	CaseFoldingCF_CpList04B0,	1,	TQU("\x04B1"),
	0x04B2,	CaseFoldingCF_CpList04B2,	1,	TQU("\x04B3"),
	0x04B4,	CaseFoldingCF_CpList04B4,	1,	TQU("\x04B5"),
	0x04B6,	CaseFoldingCF_CpList04B6,	1,	TQU("\x04B7"),
	0x04B8,	CaseFoldingCF_CpList04B8,	1,	TQU("\x04B9"),
	0x04BA,	CaseFoldingCF_CpList04BA,	1,	TQU("\x04BB"),
	0x04BC,	CaseFoldingCF_CpList04BC,	1,	TQU("\x04BD"),
	0x04BE,	CaseFoldingCF_CpList04BE,	1,	TQU("\x04BF"),
	0x04C0,	CaseFoldingCF_CpList04C0,	1,	TQU("\x04CF"),
	0x04C1,	CaseFoldingCF_CpList04C1,	1,	TQU("\x04C2"),
	0x04C3,	CaseFoldingCF_CpList04C3,	1,	TQU("\x04C4"),
	0x04C5,	CaseFoldingCF_CpList04C5,	1,	TQU("\x04C6"),
	0x04C7,	CaseFoldingCF_CpList04C7,	1,	TQU("\x04C8"),
	0x04C9,	CaseFoldingCF_CpList04C9,	1,	TQU("\x04CA"),
	0x04CB,	CaseFoldingCF_CpList04CB,	1,	TQU("\x04CC"),
	0x04CD,	CaseFoldingCF_CpList04CD,	1,	TQU("\x04CE"),
	0x04D0,	CaseFoldingCF_CpList04D0,	1,	TQU("\x04D1"),
	0x04D2,	CaseFoldingCF_CpList04D2,	1,	TQU("\x04D3"),
	0x04D4,	CaseFoldingCF_CpList04D4,	1,	TQU("\x04D5"),
	0x04D6,	CaseFoldingCF_CpList04D6,	1,	TQU("\x04D7"),
	0x04D8,	CaseFoldingCF_CpList04D8,	1,	TQU("\x04D9"),
	0x04DA,	CaseFoldingCF_CpList04DA,	1,	TQU("\x04DB"),
	0x04DC,	CaseFoldingCF_CpList04DC,	1,	TQU("\x04DD"),
	0x04DE,	CaseFoldingCF_CpList04DE,	1,	TQU("\x04DF"),
	0x04E0,	CaseFoldingCF_CpList04E0,	1,	TQU("\x04E1"),
	0x04E2,	CaseFoldingCF_CpList04E2,	1,	TQU("\x04E3"),
	0x04E4,	CaseFoldingCF_CpList04E4,	1,	TQU("\x04E5"),
	0x04E6,	CaseFoldingCF_CpList04E6,	1,	TQU("\x04E7"),
	0x04E8,	CaseFoldingCF_CpList04E8,	1,	TQU("\x04E9"),
	0x04EA,	CaseFoldingCF_CpList04EA,	1,	TQU("\x04EB"),
	0x04EC,	CaseFoldingCF_CpList04EC,	1,	TQU("\x04ED"),
	0x04EE,	CaseFoldingCF_CpList04EE,	1,	TQU("\x04EF"),
	0x04F0,	CaseFoldingCF_CpList04F0,	1,	TQU("\x04F1"),
	0x04F2,	CaseFoldingCF_CpList04F2,	1,	TQU("\x04F3"),
	0x04F4,	CaseFoldingCF_CpList04F4,	1,	TQU("\x04F5"),
	0x04F6,	CaseFoldingCF_CpList04F6,	1,	TQU("\x04F7"),
	0x04F8,	CaseFoldingCF_CpList04F8,	1,	TQU("\x04F9"),
	0x04FA,	CaseFoldingCF_CpList04FA,	1,	TQU("\x04FB"),
	0x04FC,	CaseFoldingCF_CpList04FC,	1,	TQU("\x04FD"),
	0x04FE,	CaseFoldingCF_CpList04FE,	1,	TQU("\x04FF"),
	0x0500,	CaseFoldingCF_CpList0500,	1,	TQU("\x0501"),
	0x0502,	CaseFoldingCF_CpList0502,	1,	TQU("\x0503"),
	0x0504,	CaseFoldingCF_CpList0504,	1,	TQU("\x0505"),
	0x0506,	CaseFoldingCF_CpList0506,	1,	TQU("\x0507"),
	0x0508,	CaseFoldingCF_CpList0508,	1,	TQU("\x0509"),
	0x050A,	CaseFoldingCF_CpList050A,	1,	TQU("\x050B"),
	0x050C,	CaseFoldingCF_CpList050C,	1,	TQU("\x050D"),
	0x050E,	CaseFoldingCF_CpList050E,	1,	TQU("\x050F"),
	0x0510,	CaseFoldingCF_CpList0510,	1,	TQU("\x0511"),
	0x0512,	CaseFoldingCF_CpList0512,	1,	TQU("\x0513"),
	0x0514,	CaseFoldingCF_CpList0514,	1,	TQU("\x0515"),
	0x0516,	CaseFoldingCF_CpList0516,	1,	TQU("\x0517"),
	0x0518,	CaseFoldingCF_CpList0518,	1,	TQU("\x0519"),
	0x051A,	CaseFoldingCF_CpList051A,	1,	TQU("\x051B"),
	0x051C,	CaseFoldingCF_CpList051C,	1,	TQU("\x051D"),
	0x051E,	CaseFoldingCF_CpList051E,	1,	TQU("\x051F"),
	0x0520,	CaseFoldingCF_CpList0520,	1,	TQU("\x0521"),
	0x0522,	CaseFoldingCF_CpList0522,	1,	TQU("\x0523"),
	0x0524,	CaseFoldingCF_CpList0524,	1,	TQU("\x0525"),
	0x0526,	CaseFoldingCF_CpList0526,	1,	TQU("\x0527"),
	0x0531,	CaseFoldingCF_CpList0531,	1,	TQU("\x0561"),
	0x0532,	CaseFoldingCF_CpList0532,	1,	TQU("\x0562"),
	0x0533,	CaseFoldingCF_CpList0533,	1,	TQU("\x0563"),
	0x0534,	CaseFoldingCF_CpList0534,	1,	TQU("\x0564"),
	0x0535,	CaseFoldingCF_CpList0535,	1,	TQU("\x0565"),
	0x0536,	CaseFoldingCF_CpList0536,	1,	TQU("\x0566"),
	0x0537,	CaseFoldingCF_CpList0537,	1,	TQU("\x0567"),
	0x0538,	CaseFoldingCF_CpList0538,	1,	TQU("\x0568"),
	0x0539,	CaseFoldingCF_CpList0539,	1,	TQU("\x0569"),
	0x053A,	CaseFoldingCF_CpList053A,	1,	TQU("\x056A"),
	0x053B,	CaseFoldingCF_CpList053B,	1,	TQU("\x056B"),
	0x053C,	CaseFoldingCF_CpList053C,	1,	TQU("\x056C"),
	0x053D,	CaseFoldingCF_CpList053D,	1,	TQU("\x056D"),
	0x053E,	CaseFoldingCF_CpList053E,	1,	TQU("\x056E"),
	0x053F,	CaseFoldingCF_CpList053F,	1,	TQU("\x056F"),
	0x0540,	CaseFoldingCF_CpList0540,	1,	TQU("\x0570"),
	0x0541,	CaseFoldingCF_CpList0541,	1,	TQU("\x0571"),
	0x0542,	CaseFoldingCF_CpList0542,	1,	TQU("\x0572"),
	0x0543,	CaseFoldingCF_CpList0543,	1,	TQU("\x0573"),
	0x0544,	CaseFoldingCF_CpList0544,	1,	TQU("\x0574"),
	0x0545,	CaseFoldingCF_CpList0545,	1,	TQU("\x0575"),
	0x0546,	CaseFoldingCF_CpList0546,	1,	TQU("\x0576"),
	0x0547,	CaseFoldingCF_CpList0547,	1,	TQU("\x0577"),
	0x0548,	CaseFoldingCF_CpList0548,	1,	TQU("\x0578"),
	0x0549,	CaseFoldingCF_CpList0549,	1,	TQU("\x0579"),
	0x054A,	CaseFoldingCF_CpList054A,	1,	TQU("\x057A"),
	0x054B,	CaseFoldingCF_CpList054B,	1,	TQU("\x057B"),
	0x054C,	CaseFoldingCF_CpList054C,	1,	TQU("\x057C"),
	0x054D,	CaseFoldingCF_CpList054D,	1,	TQU("\x057D"),
	0x054E,	CaseFoldingCF_CpList054E,	1,	TQU("\x057E"),
	0x054F,	CaseFoldingCF_CpList054F,	1,	TQU("\x057F"),
	0x0550,	CaseFoldingCF_CpList0550,	1,	TQU("\x0580"),
	0x0551,	CaseFoldingCF_CpList0551,	1,	TQU("\x0581"),
	0x0552,	CaseFoldingCF_CpList0552,	1,	TQU("\x0582"),
	0x0553,	CaseFoldingCF_CpList0553,	1,	TQU("\x0583"),
	0x0554,	CaseFoldingCF_CpList0554,	1,	TQU("\x0584"),
	0x0555,	CaseFoldingCF_CpList0555,	1,	TQU("\x0585"),
	0x0556,	CaseFoldingCF_CpList0556,	1,	TQU("\x0586"),
	0x0587,	CaseFoldingCF_CpList0587,	2,	TQU("\x0565\x0582"),
	0x10A0,	CaseFoldingCF_CpList10A0,	1,	TQU("\x2D00"),
	0x10A1,	CaseFoldingCF_CpList10A1,	1,	TQU("\x2D01"),
	0x10A2,	CaseFoldingCF_CpList10A2,	1,	TQU("\x2D02"),
	0x10A3,	CaseFoldingCF_CpList10A3,	1,	TQU("\x2D03"),
	0x10A4,	CaseFoldingCF_CpList10A4,	1,	TQU("\x2D04"),
	0x10A5,	CaseFoldingCF_CpList10A5,	1,	TQU("\x2D05"),
	0x10A6,	CaseFoldingCF_CpList10A6,	1,	TQU("\x2D06"),
	0x10A7,	CaseFoldingCF_CpList10A7,	1,	TQU("\x2D07"),
	0x10A8,	CaseFoldingCF_CpList10A8,	1,	TQU("\x2D08"),
	0x10A9,	CaseFoldingCF_CpList10A9,	1,	TQU("\x2D09"),
	0x10AA,	CaseFoldingCF_CpList10AA,	1,	TQU("\x2D0A"),
	0x10AB,	CaseFoldingCF_CpList10AB,	1,	TQU("\x2D0B"),
	0x10AC,	CaseFoldingCF_CpList10AC,	1,	TQU("\x2D0C"),
	0x10AD,	CaseFoldingCF_CpList10AD,	1,	TQU("\x2D0D"),
	0x10AE,	CaseFoldingCF_CpList10AE,	1,	TQU("\x2D0E"),
	0x10AF,	CaseFoldingCF_CpList10AF,	1,	TQU("\x2D0F"),
	0x10B0,	CaseFoldingCF_CpList10B0,	1,	TQU("\x2D10"),
	0x10B1,	CaseFoldingCF_CpList10B1,	1,	TQU("\x2D11"),
	0x10B2,	CaseFoldingCF_CpList10B2,	1,	TQU("\x2D12"),
	0x10B3,	CaseFoldingCF_CpList10B3,	1,	TQU("\x2D13"),
	0x10B4,	CaseFoldingCF_CpList10B4,	1,	TQU("\x2D14"),
	0x10B5,	CaseFoldingCF_CpList10B5,	1,	TQU("\x2D15"),
	0x10B6,	CaseFoldingCF_CpList10B6,	1,	TQU("\x2D16"),
	0x10B7,	CaseFoldingCF_CpList10B7,	1,	TQU("\x2D17"),
	0x10B8,	CaseFoldingCF_CpList10B8,	1,	TQU("\x2D18"),
	0x10B9,	CaseFoldingCF_CpList10B9,	1,	TQU("\x2D19"),
	0x10BA,	CaseFoldingCF_CpList10BA,	1,	TQU("\x2D1A"),
	0x10BB,	CaseFoldingCF_CpList10BB,	1,	TQU("\x2D1B"),
	0x10BC,	CaseFoldingCF_CpList10BC,	1,	TQU("\x2D1C"),
	0x10BD,	CaseFoldingCF_CpList10BD,	1,	TQU("\x2D1D"),
	0x10BE,	CaseFoldingCF_CpList10BE,	1,	TQU("\x2D1E"),
	0x10BF,	CaseFoldingCF_CpList10BF,	1,	TQU("\x2D1F"),
	0x10C0,	CaseFoldingCF_CpList10C0,	1,	TQU("\x2D20"),
	0x10C1,	CaseFoldingCF_CpList10C1,	1,	TQU("\x2D21"),
	0x10C2,	CaseFoldingCF_CpList10C2,	1,	TQU("\x2D22"),
	0x10C3,	CaseFoldingCF_CpList10C3,	1,	TQU("\x2D23"),
	0x10C4,	CaseFoldingCF_CpList10C4,	1,	TQU("\x2D24"),
	0x10C5,	CaseFoldingCF_CpList10C5,	1,	TQU("\x2D25"),
	0x10C7,	CaseFoldingCF_CpList10C7,	1,	TQU("\x2D27"),
	0x10CD,	CaseFoldingCF_CpList10CD,	1,	TQU("\x2D2D"),
	0x1E00,	CaseFoldingCF_CpList1E00,	1,	TQU("\x1E01"),
	0x1E02,	CaseFoldingCF_CpList1E02,	1,	TQU("\x1E03"),
	0x1E04,	CaseFoldingCF_CpList1E04,	1,	TQU("\x1E05"),
	0x1E06,	CaseFoldingCF_CpList1E06,	1,	TQU("\x1E07"),
	0x1E08,	CaseFoldingCF_CpList1E08,	1,	TQU("\x1E09"),
	0x1E0A,	CaseFoldingCF_CpList1E0A,	1,	TQU("\x1E0B"),
	0x1E0C,	CaseFoldingCF_CpList1E0C,	1,	TQU("\x1E0D"),
	0x1E0E,	CaseFoldingCF_CpList1E0E,	1,	TQU("\x1E0F"),
	0x1E10,	CaseFoldingCF_CpList1E10,	1,	TQU("\x1E11"),
	0x1E12,	CaseFoldingCF_CpList1E12,	1,	TQU("\x1E13"),
	0x1E14,	CaseFoldingCF_CpList1E14,	1,	TQU("\x1E15"),
	0x1E16,	CaseFoldingCF_CpList1E16,	1,	TQU("\x1E17"),
	0x1E18,	CaseFoldingCF_CpList1E18,	1,	TQU("\x1E19"),
	0x1E1A,	CaseFoldingCF_CpList1E1A,	1,	TQU("\x1E1B"),
	0x1E1C,	CaseFoldingCF_CpList1E1C,	1,	TQU("\x1E1D"),
	0x1E1E,	CaseFoldingCF_CpList1E1E,	1,	TQU("\x1E1F"),
	0x1E20,	CaseFoldingCF_CpList1E20,	1,	TQU("\x1E21"),
	0x1E22,	CaseFoldingCF_CpList1E22,	1,	TQU("\x1E23"),
	0x1E24,	CaseFoldingCF_CpList1E24,	1,	TQU("\x1E25"),
	0x1E26,	CaseFoldingCF_CpList1E26,	1,	TQU("\x1E27"),
	0x1E28,	CaseFoldingCF_CpList1E28,	1,	TQU("\x1E29"),
	0x1E2A,	CaseFoldingCF_CpList1E2A,	1,	TQU("\x1E2B"),
	0x1E2C,	CaseFoldingCF_CpList1E2C,	1,	TQU("\x1E2D"),
	0x1E2E,	CaseFoldingCF_CpList1E2E,	1,	TQU("\x1E2F"),
	0x1E30,	CaseFoldingCF_CpList1E30,	1,	TQU("\x1E31"),
	0x1E32,	CaseFoldingCF_CpList1E32,	1,	TQU("\x1E33"),
	0x1E34,	CaseFoldingCF_CpList1E34,	1,	TQU("\x1E35"),
	0x1E36,	CaseFoldingCF_CpList1E36,	1,	TQU("\x1E37"),
	0x1E38,	CaseFoldingCF_CpList1E38,	1,	TQU("\x1E39"),
	0x1E3A,	CaseFoldingCF_CpList1E3A,	1,	TQU("\x1E3B"),
	0x1E3C,	CaseFoldingCF_CpList1E3C,	1,	TQU("\x1E3D"),
	0x1E3E,	CaseFoldingCF_CpList1E3E,	1,	TQU("\x1E3F"),
	0x1E40,	CaseFoldingCF_CpList1E40,	1,	TQU("\x1E41"),
	0x1E42,	CaseFoldingCF_CpList1E42,	1,	TQU("\x1E43"),
	0x1E44,	CaseFoldingCF_CpList1E44,	1,	TQU("\x1E45"),
	0x1E46,	CaseFoldingCF_CpList1E46,	1,	TQU("\x1E47"),
	0x1E48,	CaseFoldingCF_CpList1E48,	1,	TQU("\x1E49"),
	0x1E4A,	CaseFoldingCF_CpList1E4A,	1,	TQU("\x1E4B"),
	0x1E4C,	CaseFoldingCF_CpList1E4C,	1,	TQU("\x1E4D"),
	0x1E4E,	CaseFoldingCF_CpList1E4E,	1,	TQU("\x1E4F"),
	0x1E50,	CaseFoldingCF_CpList1E50,	1,	TQU("\x1E51"),
	0x1E52,	CaseFoldingCF_CpList1E52,	1,	TQU("\x1E53"),
	0x1E54,	CaseFoldingCF_CpList1E54,	1,	TQU("\x1E55"),
	0x1E56,	CaseFoldingCF_CpList1E56,	1,	TQU("\x1E57"),
	0x1E58,	CaseFoldingCF_CpList1E58,	1,	TQU("\x1E59"),
	0x1E5A,	CaseFoldingCF_CpList1E5A,	1,	TQU("\x1E5B"),
	0x1E5C,	CaseFoldingCF_CpList1E5C,	1,	TQU("\x1E5D"),
	0x1E5E,	CaseFoldingCF_CpList1E5E,	1,	TQU("\x1E5F"),
	0x1E60,	CaseFoldingCF_CpList1E60,	1,	TQU("\x1E61"),
	0x1E62,	CaseFoldingCF_CpList1E62,	1,	TQU("\x1E63"),
	0x1E64,	CaseFoldingCF_CpList1E64,	1,	TQU("\x1E65"),
	0x1E66,	CaseFoldingCF_CpList1E66,	1,	TQU("\x1E67"),
	0x1E68,	CaseFoldingCF_CpList1E68,	1,	TQU("\x1E69"),
	0x1E6A,	CaseFoldingCF_CpList1E6A,	1,	TQU("\x1E6B"),
	0x1E6C,	CaseFoldingCF_CpList1E6C,	1,	TQU("\x1E6D"),
	0x1E6E,	CaseFoldingCF_CpList1E6E,	1,	TQU("\x1E6F"),
	0x1E70,	CaseFoldingCF_CpList1E70,	1,	TQU("\x1E71"),
	0x1E72,	CaseFoldingCF_CpList1E72,	1,	TQU("\x1E73"),
	0x1E74,	CaseFoldingCF_CpList1E74,	1,	TQU("\x1E75"),
	0x1E76,	CaseFoldingCF_CpList1E76,	1,	TQU("\x1E77"),
	0x1E78,	CaseFoldingCF_CpList1E78,	1,	TQU("\x1E79"),
	0x1E7A,	CaseFoldingCF_CpList1E7A,	1,	TQU("\x1E7B"),
	0x1E7C,	CaseFoldingCF_CpList1E7C,	1,	TQU("\x1E7D"),
	0x1E7E,	CaseFoldingCF_CpList1E7E,	1,	TQU("\x1E7F"),
	0x1E80,	CaseFoldingCF_CpList1E80,	1,	TQU("\x1E81"),
	0x1E82,	CaseFoldingCF_CpList1E82,	1,	TQU("\x1E83"),
	0x1E84,	CaseFoldingCF_CpList1E84,	1,	TQU("\x1E85"),
	0x1E86,	CaseFoldingCF_CpList1E86,	1,	TQU("\x1E87"),
	0x1E88,	CaseFoldingCF_CpList1E88,	1,	TQU("\x1E89"),
	0x1E8A,	CaseFoldingCF_CpList1E8A,	1,	TQU("\x1E8B"),
	0x1E8C,	CaseFoldingCF_CpList1E8C,	1,	TQU("\x1E8D"),
	0x1E8E,	CaseFoldingCF_CpList1E8E,	1,	TQU("\x1E8F"),
	0x1E90,	CaseFoldingCF_CpList1E90,	1,	TQU("\x1E91"),
	0x1E92,	CaseFoldingCF_CpList1E92,	1,	TQU("\x1E93"),
	0x1E94,	CaseFoldingCF_CpList1E94,	1,	TQU("\x1E95"),
	0x1E96,	CaseFoldingCF_CpList1E96,	2,	TQU("\x0068\x0331"),
	0x1E97,	CaseFoldingCF_CpList1E97,	2,	TQU("\x0074\x0308"),
	0x1E98,	CaseFoldingCF_CpList1E98,	2,	TQU("\x0077\x030A"),
	0x1E99,	CaseFoldingCF_CpList1E99,	2,	TQU("\x0079\x030A"),
	0x1E9A,	CaseFoldingCF_CpList1E9A,	2,	TQU("\x0061\x02BE"),
	0x1E9B,	CaseFoldingCF_CpList1E9B,	1,	TQU("\x1E61"),
	0x1E9E,	CaseFoldingCF_CpList1E9E,	2,	TQU("\x0073\x0073"),
	0x1EA0,	CaseFoldingCF_CpList1EA0,	1,	TQU("\x1EA1"),
	0x1EA2,	CaseFoldingCF_CpList1EA2,	1,	TQU("\x1EA3"),
	0x1EA4,	CaseFoldingCF_CpList1EA4,	1,	TQU("\x1EA5"),
	0x1EA6,	CaseFoldingCF_CpList1EA6,	1,	TQU("\x1EA7"),
	0x1EA8,	CaseFoldingCF_CpList1EA8,	1,	TQU("\x1EA9"),
	0x1EAA,	CaseFoldingCF_CpList1EAA,	1,	TQU("\x1EAB"),
	0x1EAC,	CaseFoldingCF_CpList1EAC,	1,	TQU("\x1EAD"),
	0x1EAE,	CaseFoldingCF_CpList1EAE,	1,	TQU("\x1EAF"),
	0x1EB0,	CaseFoldingCF_CpList1EB0,	1,	TQU("\x1EB1"),
	0x1EB2,	CaseFoldingCF_CpList1EB2,	1,	TQU("\x1EB3"),
	0x1EB4,	CaseFoldingCF_CpList1EB4,	1,	TQU("\x1EB5"),
	0x1EB6,	CaseFoldingCF_CpList1EB6,	1,	TQU("\x1EB7"),
	0x1EB8,	CaseFoldingCF_CpList1EB8,	1,	TQU("\x1EB9"),
	0x1EBA,	CaseFoldingCF_CpList1EBA,	1,	TQU("\x1EBB"),
	0x1EBC,	CaseFoldingCF_CpList1EBC,	1,	TQU("\x1EBD"),
	0x1EBE,	CaseFoldingCF_CpList1EBE,	1,	TQU("\x1EBF"),
	0x1EC0,	CaseFoldingCF_CpList1EC0,	1,	TQU("\x1EC1"),
	0x1EC2,	CaseFoldingCF_CpList1EC2,	1,	TQU("\x1EC3"),
	0x1EC4,	CaseFoldingCF_CpList1EC4,	1,	TQU("\x1EC5"),
	0x1EC6,	CaseFoldingCF_CpList1EC6,	1,	TQU("\x1EC7"),
	0x1EC8,	CaseFoldingCF_CpList1EC8,	1,	TQU("\x1EC9"),
	0x1ECA,	CaseFoldingCF_CpList1ECA,	1,	TQU("\x1ECB"),
	0x1ECC,	CaseFoldingCF_CpList1ECC,	1,	TQU("\x1ECD"),
	0x1ECE,	CaseFoldingCF_CpList1ECE,	1,	TQU("\x1ECF"),
	0x1ED0,	CaseFoldingCF_CpList1ED0,	1,	TQU("\x1ED1"),
	0x1ED2,	CaseFoldingCF_CpList1ED2,	1,	TQU("\x1ED3"),
	0x1ED4,	CaseFoldingCF_CpList1ED4,	1,	TQU("\x1ED5"),
	0x1ED6,	CaseFoldingCF_CpList1ED6,	1,	TQU("\x1ED7"),
	0x1ED8,	CaseFoldingCF_CpList1ED8,	1,	TQU("\x1ED9"),
	0x1EDA,	CaseFoldingCF_CpList1EDA,	1,	TQU("\x1EDB"),
	0x1EDC,	CaseFoldingCF_CpList1EDC,	1,	TQU("\x1EDD"),
	0x1EDE,	CaseFoldingCF_CpList1EDE,	1,	TQU("\x1EDF"),
	0x1EE0,	CaseFoldingCF_CpList1EE0,	1,	TQU("\x1EE1"),
	0x1EE2,	CaseFoldingCF_CpList1EE2,	1,	TQU("\x1EE3"),
	0x1EE4,	CaseFoldingCF_CpList1EE4,	1,	TQU("\x1EE5"),
	0x1EE6,	CaseFoldingCF_CpList1EE6,	1,	TQU("\x1EE7"),
	0x1EE8,	CaseFoldingCF_CpList1EE8,	1,	TQU("\x1EE9"),
	0x1EEA,	CaseFoldingCF_CpList1EEA,	1,	TQU("\x1EEB"),
	0x1EEC,	CaseFoldingCF_CpList1EEC,	1,	TQU("\x1EED"),
	0x1EEE,	CaseFoldingCF_CpList1EEE,	1,	TQU("\x1EEF"),
	0x1EF0,	CaseFoldingCF_CpList1EF0,	1,	TQU("\x1EF1"),
	0x1EF2,	CaseFoldingCF_CpList1EF2,	1,	TQU("\x1EF3"),
	0x1EF4,	CaseFoldingCF_CpList1EF4,	1,	TQU("\x1EF5"),
	0x1EF6,	CaseFoldingCF_CpList1EF6,	1,	TQU("\x1EF7"),
	0x1EF8,	CaseFoldingCF_CpList1EF8,	1,	TQU("\x1EF9"),
	0x1EFA,	CaseFoldingCF_CpList1EFA,	1,	TQU("\x1EFB"),
	0x1EFC,	CaseFoldingCF_CpList1EFC,	1,	TQU("\x1EFD"),
	0x1EFE,	CaseFoldingCF_CpList1EFE,	1,	TQU("\x1EFF"),
	0x1F08,	CaseFoldingCF_CpList1F08,	1,	TQU("\x1F00"),
	0x1F09,	CaseFoldingCF_CpList1F09,	1,	TQU("\x1F01"),
	0x1F0A,	CaseFoldingCF_CpList1F0A,	1,	TQU("\x1F02"),
	0x1F0B,	CaseFoldingCF_CpList1F0B,	1,	TQU("\x1F03"),
	0x1F0C,	CaseFoldingCF_CpList1F0C,	1,	TQU("\x1F04"),
	0x1F0D,	CaseFoldingCF_CpList1F0D,	1,	TQU("\x1F05"),
	0x1F0E,	CaseFoldingCF_CpList1F0E,	1,	TQU("\x1F06"),
	0x1F0F,	CaseFoldingCF_CpList1F0F,	1,	TQU("\x1F07"),
	0x1F18,	CaseFoldingCF_CpList1F18,	1,	TQU("\x1F10"),
	0x1F19,	CaseFoldingCF_CpList1F19,	1,	TQU("\x1F11"),
	0x1F1A,	CaseFoldingCF_CpList1F1A,	1,	TQU("\x1F12"),
	0x1F1B,	CaseFoldingCF_CpList1F1B,	1,	TQU("\x1F13"),
	0x1F1C,	CaseFoldingCF_CpList1F1C,	1,	TQU("\x1F14"),
	0x1F1D,	CaseFoldingCF_CpList1F1D,	1,	TQU("\x1F15"),
	0x1F28,	CaseFoldingCF_CpList1F28,	1,	TQU("\x1F20"),
	0x1F29,	CaseFoldingCF_CpList1F29,	1,	TQU("\x1F21"),
	0x1F2A,	CaseFoldingCF_CpList1F2A,	1,	TQU("\x1F22"),
	0x1F2B,	CaseFoldingCF_CpList1F2B,	1,	TQU("\x1F23"),
	0x1F2C,	CaseFoldingCF_CpList1F2C,	1,	TQU("\x1F24"),
	0x1F2D,	CaseFoldingCF_CpList1F2D,	1,	TQU("\x1F25"),
	0x1F2E,	CaseFoldingCF_CpList1F2E,	1,	TQU("\x1F26"),
	0x1F2F,	CaseFoldingCF_CpList1F2F,	1,	TQU("\x1F27"),
	0x1F38,	CaseFoldingCF_CpList1F38,	1,	TQU("\x1F30"),
	0x1F39,	CaseFoldingCF_CpList1F39,	1,	TQU("\x1F31"),
	0x1F3A,	CaseFoldingCF_CpList1F3A,	1,	TQU("\x1F32"),
	0x1F3B,	CaseFoldingCF_CpList1F3B,	1,	TQU("\x1F33"),
	0x1F3C,	CaseFoldingCF_CpList1F3C,	1,	TQU("\x1F34"),
	0x1F3D,	CaseFoldingCF_CpList1F3D,	1,	TQU("\x1F35"),
	0x1F3E,	CaseFoldingCF_CpList1F3E,	1,	TQU("\x1F36"),
	0x1F3F,	CaseFoldingCF_CpList1F3F,	1,	TQU("\x1F37"),
	0x1F48,	CaseFoldingCF_CpList1F48,	1,	TQU("\x1F40"),
	0x1F49,	CaseFoldingCF_CpList1F49,	1,	TQU("\x1F41"),
	0x1F4A,	CaseFoldingCF_CpList1F4A,	1,	TQU("\x1F42"),
	0x1F4B,	CaseFoldingCF_CpList1F4B,	1,	TQU("\x1F43"),
	0x1F4C,	CaseFoldingCF_CpList1F4C,	1,	TQU("\x1F44"),
	0x1F4D,	CaseFoldingCF_CpList1F4D,	1,	TQU("\x1F45"),
	0x1F50,	CaseFoldingCF_CpList1F50,	2,	TQU("\x03C5\x0313"),
	0x1F52,	CaseFoldingCF_CpList1F52,	3,	TQU("\x03C5\x0313\x0300"),
	0x1F54,	CaseFoldingCF_CpList1F54,	3,	TQU("\x03C5\x0313\x0301"),
	0x1F56,	CaseFoldingCF_CpList1F56,	3,	TQU("\x03C5\x0313\x0342"),
	0x1F59,	CaseFoldingCF_CpList1F59,	1,	TQU("\x1F51"),
	0x1F5B,	CaseFoldingCF_CpList1F5B,	1,	TQU("\x1F53"),
	0x1F5D,	CaseFoldingCF_CpList1F5D,	1,	TQU("\x1F55"),
	0x1F5F,	CaseFoldingCF_CpList1F5F,	1,	TQU("\x1F57"),
	0x1F68,	CaseFoldingCF_CpList1F68,	1,	TQU("\x1F60"),
	0x1F69,	CaseFoldingCF_CpList1F69,	1,	TQU("\x1F61"),
	0x1F6A,	CaseFoldingCF_CpList1F6A,	1,	TQU("\x1F62"),
	0x1F6B,	CaseFoldingCF_CpList1F6B,	1,	TQU("\x1F63"),
	0x1F6C,	CaseFoldingCF_CpList1F6C,	1,	TQU("\x1F64"),
	0x1F6D,	CaseFoldingCF_CpList1F6D,	1,	TQU("\x1F65"),
	0x1F6E,	CaseFoldingCF_CpList1F6E,	1,	TQU("\x1F66"),
	0x1F6F,	CaseFoldingCF_CpList1F6F,	1,	TQU("\x1F67"),
	0x1F80,	CaseFoldingCF_CpList1F80,	2,	TQU("\x1F00\x03B9"),
	0x1F81,	CaseFoldingCF_CpList1F81,	2,	TQU("\x1F01\x03B9"),
	0x1F82,	CaseFoldingCF_CpList1F82,	2,	TQU("\x1F02\x03B9"),
	0x1F83,	CaseFoldingCF_CpList1F83,	2,	TQU("\x1F03\x03B9"),
	0x1F84,	CaseFoldingCF_CpList1F84,	2,	TQU("\x1F04\x03B9"),
	0x1F85,	CaseFoldingCF_CpList1F85,	2,	TQU("\x1F05\x03B9"),
	0x1F86,	CaseFoldingCF_CpList1F86,	2,	TQU("\x1F06\x03B9"),
	0x1F87,	CaseFoldingCF_CpList1F87,	2,	TQU("\x1F07\x03B9"),
	0x1F88,	CaseFoldingCF_CpList1F88,	2,	TQU("\x1F00\x03B9"),
	0x1F89,	CaseFoldingCF_CpList1F89,	2,	TQU("\x1F01\x03B9"),
	0x1F8A,	CaseFoldingCF_CpList1F8A,	2,	TQU("\x1F02\x03B9"),
	0x1F8B,	CaseFoldingCF_CpList1F8B,	2,	TQU("\x1F03\x03B9"),
	0x1F8C,	CaseFoldingCF_CpList1F8C,	2,	TQU("\x1F04\x03B9"),
	0x1F8D,	CaseFoldingCF_CpList1F8D,	2,	TQU("\x1F05\x03B9"),
	0x1F8E,	CaseFoldingCF_CpList1F8E,	2,	TQU("\x1F06\x03B9"),
	0x1F8F,	CaseFoldingCF_CpList1F8F,	2,	TQU("\x1F07\x03B9"),
	0x1F90,	CaseFoldingCF_CpList1F90,	2,	TQU("\x1F20\x03B9"),
	0x1F91,	CaseFoldingCF_CpList1F91,	2,	TQU("\x1F21\x03B9"),
	0x1F92,	CaseFoldingCF_CpList1F92,	2,	TQU("\x1F22\x03B9"),
	0x1F93,	CaseFoldingCF_CpList1F93,	2,	TQU("\x1F23\x03B9"),
	0x1F94,	CaseFoldingCF_CpList1F94,	2,	TQU("\x1F24\x03B9"),
	0x1F95,	CaseFoldingCF_CpList1F95,	2,	TQU("\x1F25\x03B9"),
	0x1F96,	CaseFoldingCF_CpList1F96,	2,	TQU("\x1F26\x03B9"),
	0x1F97,	CaseFoldingCF_CpList1F97,	2,	TQU("\x1F27\x03B9"),
	0x1F98,	CaseFoldingCF_CpList1F98,	2,	TQU("\x1F20\x03B9"),
	0x1F99,	CaseFoldingCF_CpList1F99,	2,	TQU("\x1F21\x03B9"),
	0x1F9A,	CaseFoldingCF_CpList1F9A,	2,	TQU("\x1F22\x03B9"),
	0x1F9B,	CaseFoldingCF_CpList1F9B,	2,	TQU("\x1F23\x03B9"),
	0x1F9C,	CaseFoldingCF_CpList1F9C,	2,	TQU("\x1F24\x03B9"),
	0x1F9D,	CaseFoldingCF_CpList1F9D,	2,	TQU("\x1F25\x03B9"),
	0x1F9E,	CaseFoldingCF_CpList1F9E,	2,	TQU("\x1F26\x03B9"),
	0x1F9F,	CaseFoldingCF_CpList1F9F,	2,	TQU("\x1F27\x03B9"),
	0x1FA0,	CaseFoldingCF_CpList1FA0,	2,	TQU("\x1F60\x03B9"),
	0x1FA1,	CaseFoldingCF_CpList1FA1,	2,	TQU("\x1F61\x03B9"),
	0x1FA2,	CaseFoldingCF_CpList1FA2,	2,	TQU("\x1F62\x03B9"),
	0x1FA3,	CaseFoldingCF_CpList1FA3,	2,	TQU("\x1F63\x03B9"),
	0x1FA4,	CaseFoldingCF_CpList1FA4,	2,	TQU("\x1F64\x03B9"),
	0x1FA5,	CaseFoldingCF_CpList1FA5,	2,	TQU("\x1F65\x03B9"),
	0x1FA6,	CaseFoldingCF_CpList1FA6,	2,	TQU("\x1F66\x03B9"),
	0x1FA7,	CaseFoldingCF_CpList1FA7,	2,	TQU("\x1F67\x03B9"),
	0x1FA8,	CaseFoldingCF_CpList1FA8,	2,	TQU("\x1F60\x03B9"),
	0x1FA9,	CaseFoldingCF_CpList1FA9,	2,	TQU("\x1F61\x03B9"),
	0x1FAA,	CaseFoldingCF_CpList1FAA,	2,	TQU("\x1F62\x03B9"),
	0x1FAB,	CaseFoldingCF_CpList1FAB,	2,	TQU("\x1F63\x03B9"),
	0x1FAC,	CaseFoldingCF_CpList1FAC,	2,	TQU("\x1F64\x03B9"),
	0x1FAD,	CaseFoldingCF_CpList1FAD,	2,	TQU("\x1F65\x03B9"),
	0x1FAE,	CaseFoldingCF_CpList1FAE,	2,	TQU("\x1F66\x03B9"),
	0x1FAF,	CaseFoldingCF_CpList1FAF,	2,	TQU("\x1F67\x03B9"),
	0x1FB2,	CaseFoldingCF_CpList1FB2,	2,	TQU("\x1F70\x03B9"),
	0x1FB3,	CaseFoldingCF_CpList1FB3,	2,	TQU("\x03B1\x03B9"),
	0x1FB4,	CaseFoldingCF_CpList1FB4,	2,	TQU("\x03AC\x03B9"),
	0x1FB6,	CaseFoldingCF_CpList1FB6,	2,	TQU("\x03B1\x0342"),
	0x1FB7,	CaseFoldingCF_CpList1FB7,	3,	TQU("\x03B1\x0342\x03B9"),
	0x1FB8,	CaseFoldingCF_CpList1FB8,	1,	TQU("\x1FB0"),
	0x1FB9,	CaseFoldingCF_CpList1FB9,	1,	TQU("\x1FB1"),
	0x1FBA,	CaseFoldingCF_CpList1FBA,	1,	TQU("\x1F70"),
	0x1FBB,	CaseFoldingCF_CpList1FBB,	1,	TQU("\x1F71"),
	0x1FBC,	CaseFoldingCF_CpList1FBC,	2,	TQU("\x03B1\x03B9"),
	0x1FBE,	CaseFoldingCF_CpList1FBE,	1,	TQU("\x03B9"),
	0x1FC2,	CaseFoldingCF_CpList1FC2,	2,	TQU("\x1F74\x03B9"),
	0x1FC3,	CaseFoldingCF_CpList1FC3,	2,	TQU("\x03B7\x03B9"),
	0x1FC4,	CaseFoldingCF_CpList1FC4,	2,	TQU("\x03AE\x03B9"),
	0x1FC6,	CaseFoldingCF_CpList1FC6,	2,	TQU("\x03B7\x0342"),
	0x1FC7,	CaseFoldingCF_CpList1FC7,	3,	TQU("\x03B7\x0342\x03B9"),
	0x1FC8,	CaseFoldingCF_CpList1FC8,	1,	TQU("\x1F72"),
	0x1FC9,	CaseFoldingCF_CpList1FC9,	1,	TQU("\x1F73"),
	0x1FCA,	CaseFoldingCF_CpList1FCA,	1,	TQU("\x1F74"),
	0x1FCB,	CaseFoldingCF_CpList1FCB,	1,	TQU("\x1F75"),
	0x1FCC,	CaseFoldingCF_CpList1FCC,	2,	TQU("\x03B7\x03B9"),
	0x1FD2,	CaseFoldingCF_CpList1FD2,	3,	TQU("\x03B9\x0308\x0300"),
	0x1FD3,	CaseFoldingCF_CpList1FD3,	3,	TQU("\x03B9\x0308\x0301"),
	0x1FD6,	CaseFoldingCF_CpList1FD6,	2,	TQU("\x03B9\x0342"),
	0x1FD7,	CaseFoldingCF_CpList1FD7,	3,	TQU("\x03B9\x0308\x0342"),
	0x1FD8,	CaseFoldingCF_CpList1FD8,	1,	TQU("\x1FD0"),
	0x1FD9,	CaseFoldingCF_CpList1FD9,	1,	TQU("\x1FD1"),
	0x1FDA,	CaseFoldingCF_CpList1FDA,	1,	TQU("\x1F76"),
	0x1FDB,	CaseFoldingCF_CpList1FDB,	1,	TQU("\x1F77"),
	0x1FE2,	CaseFoldingCF_CpList1FE2,	3,	TQU("\x03C5\x0308\x0300"),
	0x1FE3,	CaseFoldingCF_CpList1FE3,	3,	TQU("\x03C5\x0308\x0301"),
	0x1FE4,	CaseFoldingCF_CpList1FE4,	2,	TQU("\x03C1\x0313"),
	0x1FE6,	CaseFoldingCF_CpList1FE6,	2,	TQU("\x03C5\x0342"),
	0x1FE7,	CaseFoldingCF_CpList1FE7,	3,	TQU("\x03C5\x0308\x0342"),
	0x1FE8,	CaseFoldingCF_CpList1FE8,	1,	TQU("\x1FE0"),
	0x1FE9,	CaseFoldingCF_CpList1FE9,	1,	TQU("\x1FE1"),
	0x1FEA,	CaseFoldingCF_CpList1FEA,	1,	TQU("\x1F7A"),
	0x1FEB,	CaseFoldingCF_CpList1FEB,	1,	TQU("\x1F7B"),
	0x1FEC,	CaseFoldingCF_CpList1FEC,	1,	TQU("\x1FE5"),
	0x1FF2,	CaseFoldingCF_CpList1FF2,	2,	TQU("\x1F7C\x03B9"),
	0x1FF3,	CaseFoldingCF_CpList1FF3,	2,	TQU("\x03C9\x03B9"),
	0x1FF4,	CaseFoldingCF_CpList1FF4,	2,	TQU("\x03CE\x03B9"),
	0x1FF6,	CaseFoldingCF_CpList1FF6,	2,	TQU("\x03C9\x0342"),
	0x1FF7,	CaseFoldingCF_CpList1FF7,	3,	TQU("\x03C9\x0342\x03B9"),
	0x1FF8,	CaseFoldingCF_CpList1FF8,	1,	TQU("\x1F78"),
	0x1FF9,	CaseFoldingCF_CpList1FF9,	1,	TQU("\x1F79"),
	0x1FFA,	CaseFoldingCF_CpList1FFA,	1,	TQU("\x1F7C"),
	0x1FFB,	CaseFoldingCF_CpList1FFB,	1,	TQU("\x1F7D"),
	0x1FFC,	CaseFoldingCF_CpList1FFC,	2,	TQU("\x03C9\x03B9"),
	0x2126,	CaseFoldingCF_CpList2126,	1,	TQU("\x03C9"),
	0x212A,	CaseFoldingCF_CpList212A,	1,	TQU("\x006B"),
	0x212B,	CaseFoldingCF_CpList212B,	1,	TQU("\x00E5"),
	0x2132,	CaseFoldingCF_CpList2132,	1,	TQU("\x214E"),
	0x2160,	CaseFoldingCF_CpList2160,	1,	TQU("\x2170"),
	0x2161,	CaseFoldingCF_CpList2161,	1,	TQU("\x2171"),
	0x2162,	CaseFoldingCF_CpList2162,	1,	TQU("\x2172"),
	0x2163,	CaseFoldingCF_CpList2163,	1,	TQU("\x2173"),
	0x2164,	CaseFoldingCF_CpList2164,	1,	TQU("\x2174"),
	0x2165,	CaseFoldingCF_CpList2165,	1,	TQU("\x2175"),
	0x2166,	CaseFoldingCF_CpList2166,	1,	TQU("\x2176"),
	0x2167,	CaseFoldingCF_CpList2167,	1,	TQU("\x2177"),
	0x2168,	CaseFoldingCF_CpList2168,	1,	TQU("\x2178"),
	0x2169,	CaseFoldingCF_CpList2169,	1,	TQU("\x2179"),
	0x216A,	CaseFoldingCF_CpList216A,	1,	TQU("\x217A"),
	0x216B,	CaseFoldingCF_CpList216B,	1,	TQU("\x217B"),
	0x216C,	CaseFoldingCF_CpList216C,	1,	TQU("\x217C"),
	0x216D,	CaseFoldingCF_CpList216D,	1,	TQU("\x217D"),
	0x216E,	CaseFoldingCF_CpList216E,	1,	TQU("\x217E"),
	0x216F,	CaseFoldingCF_CpList216F,	1,	TQU("\x217F"),
	0x2183,	CaseFoldingCF_CpList2183,	1,	TQU("\x2184"),
	0x24B6,	CaseFoldingCF_CpList24B6,	1,	TQU("\x24D0"),
	0x24B7,	CaseFoldingCF_CpList24B7,	1,	TQU("\x24D1"),
	0x24B8,	CaseFoldingCF_CpList24B8,	1,	TQU("\x24D2"),
	0x24B9,	CaseFoldingCF_CpList24B9,	1,	TQU("\x24D3"),
	0x24BA,	CaseFoldingCF_CpList24BA,	1,	TQU("\x24D4"),
	0x24BB,	CaseFoldingCF_CpList24BB,	1,	TQU("\x24D5"),
	0x24BC,	CaseFoldingCF_CpList24BC,	1,	TQU("\x24D6"),
	0x24BD,	CaseFoldingCF_CpList24BD,	1,	TQU("\x24D7"),
	0x24BE,	CaseFoldingCF_CpList24BE,	1,	TQU("\x24D8"),
	0x24BF,	CaseFoldingCF_CpList24BF,	1,	TQU("\x24D9"),
	0x24C0,	CaseFoldingCF_CpList24C0,	1,	TQU("\x24DA"),
	0x24C1,	CaseFoldingCF_CpList24C1,	1,	TQU("\x24DB"),
	0x24C2,	CaseFoldingCF_CpList24C2,	1,	TQU("\x24DC"),
	0x24C3,	CaseFoldingCF_CpList24C3,	1,	TQU("\x24DD"),
	0x24C4,	CaseFoldingCF_CpList24C4,	1,	TQU("\x24DE"),
	0x24C5,	CaseFoldingCF_CpList24C5,	1,	TQU("\x24DF"),
	0x24C6,	CaseFoldingCF_CpList24C6,	1,	TQU("\x24E0"),
	0x24C7,	CaseFoldingCF_CpList24C7,	1,	TQU("\x24E1"),
	0x24C8,	CaseFoldingCF_CpList24C8,	1,	TQU("\x24E2"),
	0x24C9,	CaseFoldingCF_CpList24C9,	1,	TQU("\x24E3"),
	0x24CA,	CaseFoldingCF_CpList24CA,	1,	TQU("\x24E4"),
	0x24CB,	CaseFoldingCF_CpList24CB,	1,	TQU("\x24E5"),
	0x24CC,	CaseFoldingCF_CpList24CC,	1,	TQU("\x24E6"),
	0x24CD,	CaseFoldingCF_CpList24CD,	1,	TQU("\x24E7"),
	0x24CE,	CaseFoldingCF_CpList24CE,	1,	TQU("\x24E8"),
	0x24CF,	CaseFoldingCF_CpList24CF,	1,	TQU("\x24E9"),
	0x2C00,	CaseFoldingCF_CpList2C00,	1,	TQU("\x2C30"),
	0x2C01,	CaseFoldingCF_CpList2C01,	1,	TQU("\x2C31"),
	0x2C02,	CaseFoldingCF_CpList2C02,	1,	TQU("\x2C32"),
	0x2C03,	CaseFoldingCF_CpList2C03,	1,	TQU("\x2C33"),
	0x2C04,	CaseFoldingCF_CpList2C04,	1,	TQU("\x2C34"),
	0x2C05,	CaseFoldingCF_CpList2C05,	1,	TQU("\x2C35"),
	0x2C06,	CaseFoldingCF_CpList2C06,	1,	TQU("\x2C36"),
	0x2C07,	CaseFoldingCF_CpList2C07,	1,	TQU("\x2C37"),
	0x2C08,	CaseFoldingCF_CpList2C08,	1,	TQU("\x2C38"),
	0x2C09,	CaseFoldingCF_CpList2C09,	1,	TQU("\x2C39"),
	0x2C0A,	CaseFoldingCF_CpList2C0A,	1,	TQU("\x2C3A"),
	0x2C0B,	CaseFoldingCF_CpList2C0B,	1,	TQU("\x2C3B"),
	0x2C0C,	CaseFoldingCF_CpList2C0C,	1,	TQU("\x2C3C"),
	0x2C0D,	CaseFoldingCF_CpList2C0D,	1,	TQU("\x2C3D"),
	0x2C0E,	CaseFoldingCF_CpList2C0E,	1,	TQU("\x2C3E"),
	0x2C0F,	CaseFoldingCF_CpList2C0F,	1,	TQU("\x2C3F"),
	0x2C10,	CaseFoldingCF_CpList2C10,	1,	TQU("\x2C40"),
	0x2C11,	CaseFoldingCF_CpList2C11,	1,	TQU("\x2C41"),
	0x2C12,	CaseFoldingCF_CpList2C12,	1,	TQU("\x2C42"),
	0x2C13,	CaseFoldingCF_CpList2C13,	1,	TQU("\x2C43"),
	0x2C14,	CaseFoldingCF_CpList2C14,	1,	TQU("\x2C44"),
	0x2C15,	CaseFoldingCF_CpList2C15,	1,	TQU("\x2C45"),
	0x2C16,	CaseFoldingCF_CpList2C16,	1,	TQU("\x2C46"),
	0x2C17,	CaseFoldingCF_CpList2C17,	1,	TQU("\x2C47"),
	0x2C18,	CaseFoldingCF_CpList2C18,	1,	TQU("\x2C48"),
	0x2C19,	CaseFoldingCF_CpList2C19,	1,	TQU("\x2C49"),
	0x2C1A,	CaseFoldingCF_CpList2C1A,	1,	TQU("\x2C4A"),
	0x2C1B,	CaseFoldingCF_CpList2C1B,	1,	TQU("\x2C4B"),
	0x2C1C,	CaseFoldingCF_CpList2C1C,	1,	TQU("\x2C4C"),
	0x2C1D,	CaseFoldingCF_CpList2C1D,	1,	TQU("\x2C4D"),
	0x2C1E,	CaseFoldingCF_CpList2C1E,	1,	TQU("\x2C4E"),
	0x2C1F,	CaseFoldingCF_CpList2C1F,	1,	TQU("\x2C4F"),
	0x2C20,	CaseFoldingCF_CpList2C20,	1,	TQU("\x2C50"),
	0x2C21,	CaseFoldingCF_CpList2C21,	1,	TQU("\x2C51"),
	0x2C22,	CaseFoldingCF_CpList2C22,	1,	TQU("\x2C52"),
	0x2C23,	CaseFoldingCF_CpList2C23,	1,	TQU("\x2C53"),
	0x2C24,	CaseFoldingCF_CpList2C24,	1,	TQU("\x2C54"),
	0x2C25,	CaseFoldingCF_CpList2C25,	1,	TQU("\x2C55"),
	0x2C26,	CaseFoldingCF_CpList2C26,	1,	TQU("\x2C56"),
	0x2C27,	CaseFoldingCF_CpList2C27,	1,	TQU("\x2C57"),
	0x2C28,	CaseFoldingCF_CpList2C28,	1,	TQU("\x2C58"),
	0x2C29,	CaseFoldingCF_CpList2C29,	1,	TQU("\x2C59"),
	0x2C2A,	CaseFoldingCF_CpList2C2A,	1,	TQU("\x2C5A"),
	0x2C2B,	CaseFoldingCF_CpList2C2B,	1,	TQU("\x2C5B"),
	0x2C2C,	CaseFoldingCF_CpList2C2C,	1,	TQU("\x2C5C"),
	0x2C2D,	CaseFoldingCF_CpList2C2D,	1,	TQU("\x2C5D"),
	0x2C2E,	CaseFoldingCF_CpList2C2E,	1,	TQU("\x2C5E"),
	0x2C60,	CaseFoldingCF_CpList2C60,	1,	TQU("\x2C61"),
	0x2C62,	CaseFoldingCF_CpList2C62,	1,	TQU("\x026B"),
	0x2C63,	CaseFoldingCF_CpList2C63,	1,	TQU("\x1D7D"),
	0x2C64,	CaseFoldingCF_CpList2C64,	1,	TQU("\x027D"),
	0x2C67,	CaseFoldingCF_CpList2C67,	1,	TQU("\x2C68"),
	0x2C69,	CaseFoldingCF_CpList2C69,	1,	TQU("\x2C6A"),
	0x2C6B,	CaseFoldingCF_CpList2C6B,	1,	TQU("\x2C6C"),
	0x2C6D,	CaseFoldingCF_CpList2C6D,	1,	TQU("\x0251"),
	0x2C6E,	CaseFoldingCF_CpList2C6E,	1,	TQU("\x0271"),
	0x2C6F,	CaseFoldingCF_CpList2C6F,	1,	TQU("\x0250"),
	0x2C70,	CaseFoldingCF_CpList2C70,	1,	TQU("\x0252"),
	0x2C72,	CaseFoldingCF_CpList2C72,	1,	TQU("\x2C73"),
	0x2C75,	CaseFoldingCF_CpList2C75,	1,	TQU("\x2C76"),
	0x2C7E,	CaseFoldingCF_CpList2C7E,	1,	TQU("\x023F"),
	0x2C7F,	CaseFoldingCF_CpList2C7F,	1,	TQU("\x0240"),
	0x2C80,	CaseFoldingCF_CpList2C80,	1,	TQU("\x2C81"),
	0x2C82,	CaseFoldingCF_CpList2C82,	1,	TQU("\x2C83"),
	0x2C84,	CaseFoldingCF_CpList2C84,	1,	TQU("\x2C85"),
	0x2C86,	CaseFoldingCF_CpList2C86,	1,	TQU("\x2C87"),
	0x2C88,	CaseFoldingCF_CpList2C88,	1,	TQU("\x2C89"),
	0x2C8A,	CaseFoldingCF_CpList2C8A,	1,	TQU("\x2C8B"),
	0x2C8C,	CaseFoldingCF_CpList2C8C,	1,	TQU("\x2C8D"),
	0x2C8E,	CaseFoldingCF_CpList2C8E,	1,	TQU("\x2C8F"),
	0x2C90,	CaseFoldingCF_CpList2C90,	1,	TQU("\x2C91"),
	0x2C92,	CaseFoldingCF_CpList2C92,	1,	TQU("\x2C93"),
	0x2C94,	CaseFoldingCF_CpList2C94,	1,	TQU("\x2C95"),
	0x2C96,	CaseFoldingCF_CpList2C96,	1,	TQU("\x2C97"),
	0x2C98,	CaseFoldingCF_CpList2C98,	1,	TQU("\x2C99"),
	0x2C9A,	CaseFoldingCF_CpList2C9A,	1,	TQU("\x2C9B"),
	0x2C9C,	CaseFoldingCF_CpList2C9C,	1,	TQU("\x2C9D"),
	0x2C9E,	CaseFoldingCF_CpList2C9E,	1,	TQU("\x2C9F"),
	0x2CA0,	CaseFoldingCF_CpList2CA0,	1,	TQU("\x2CA1"),
	0x2CA2,	CaseFoldingCF_CpList2CA2,	1,	TQU("\x2CA3"),
	0x2CA4,	CaseFoldingCF_CpList2CA4,	1,	TQU("\x2CA5"),
	0x2CA6,	CaseFoldingCF_CpList2CA6,	1,	TQU("\x2CA7"),
	0x2CA8,	CaseFoldingCF_CpList2CA8,	1,	TQU("\x2CA9"),
	0x2CAA,	CaseFoldingCF_CpList2CAA,	1,	TQU("\x2CAB"),
	0x2CAC,	CaseFoldingCF_CpList2CAC,	1,	TQU("\x2CAD"),
	0x2CAE,	CaseFoldingCF_CpList2CAE,	1,	TQU("\x2CAF"),
	0x2CB0,	CaseFoldingCF_CpList2CB0,	1,	TQU("\x2CB1"),
	0x2CB2,	CaseFoldingCF_CpList2CB2,	1,	TQU("\x2CB3"),
	0x2CB4,	CaseFoldingCF_CpList2CB4,	1,	TQU("\x2CB5"),
	0x2CB6,	CaseFoldingCF_CpList2CB6,	1,	TQU("\x2CB7"),
	0x2CB8,	CaseFoldingCF_CpList2CB8,	1,	TQU("\x2CB9"),
	0x2CBA,	CaseFoldingCF_CpList2CBA,	1,	TQU("\x2CBB"),
	0x2CBC,	CaseFoldingCF_CpList2CBC,	1,	TQU("\x2CBD"),
	0x2CBE,	CaseFoldingCF_CpList2CBE,	1,	TQU("\x2CBF"),
	0x2CC0,	CaseFoldingCF_CpList2CC0,	1,	TQU("\x2CC1"),
	0x2CC2,	CaseFoldingCF_CpList2CC2,	1,	TQU("\x2CC3"),
	0x2CC4,	CaseFoldingCF_CpList2CC4,	1,	TQU("\x2CC5"),
	0x2CC6,	CaseFoldingCF_CpList2CC6,	1,	TQU("\x2CC7"),
	0x2CC8,	CaseFoldingCF_CpList2CC8,	1,	TQU("\x2CC9"),
	0x2CCA,	CaseFoldingCF_CpList2CCA,	1,	TQU("\x2CCB"),
	0x2CCC,	CaseFoldingCF_CpList2CCC,	1,	TQU("\x2CCD"),
	0x2CCE,	CaseFoldingCF_CpList2CCE,	1,	TQU("\x2CCF"),
	0x2CD0,	CaseFoldingCF_CpList2CD0,	1,	TQU("\x2CD1"),
	0x2CD2,	CaseFoldingCF_CpList2CD2,	1,	TQU("\x2CD3"),
	0x2CD4,	CaseFoldingCF_CpList2CD4,	1,	TQU("\x2CD5"),
	0x2CD6,	CaseFoldingCF_CpList2CD6,	1,	TQU("\x2CD7"),
	0x2CD8,	CaseFoldingCF_CpList2CD8,	1,	TQU("\x2CD9"),
	0x2CDA,	CaseFoldingCF_CpList2CDA,	1,	TQU("\x2CDB"),
	0x2CDC,	CaseFoldingCF_CpList2CDC,	1,	TQU("\x2CDD"),
	0x2CDE,	CaseFoldingCF_CpList2CDE,	1,	TQU("\x2CDF"),
	0x2CE0,	CaseFoldingCF_CpList2CE0,	1,	TQU("\x2CE1"),
	0x2CE2,	CaseFoldingCF_CpList2CE2,	1,	TQU("\x2CE3"),
	0x2CEB,	CaseFoldingCF_CpList2CEB,	1,	TQU("\x2CEC"),
	0x2CED,	CaseFoldingCF_CpList2CED,	1,	TQU("\x2CEE"),
	0x2CF2,	CaseFoldingCF_CpList2CF2,	1,	TQU("\x2CF3"),
	0xA640,	CaseFoldingCF_CpListA640,	1,	TQU("\xA641"),
	0xA642,	CaseFoldingCF_CpListA642,	1,	TQU("\xA643"),
	0xA644,	CaseFoldingCF_CpListA644,	1,	TQU("\xA645"),
	0xA646,	CaseFoldingCF_CpListA646,	1,	TQU("\xA647"),
	0xA648,	CaseFoldingCF_CpListA648,	1,	TQU("\xA649"),
	0xA64A,	CaseFoldingCF_CpListA64A,	1,	TQU("\xA64B"),
	0xA64C,	CaseFoldingCF_CpListA64C,	1,	TQU("\xA64D"),
	0xA64E,	CaseFoldingCF_CpListA64E,	1,	TQU("\xA64F"),
	0xA650,	CaseFoldingCF_CpListA650,	1,	TQU("\xA651"),
	0xA652,	CaseFoldingCF_CpListA652,	1,	TQU("\xA653"),
	0xA654,	CaseFoldingCF_CpListA654,	1,	TQU("\xA655"),
	0xA656,	CaseFoldingCF_CpListA656,	1,	TQU("\xA657"),
	0xA658,	CaseFoldingCF_CpListA658,	1,	TQU("\xA659"),
	0xA65A,	CaseFoldingCF_CpListA65A,	1,	TQU("\xA65B"),
	0xA65C,	CaseFoldingCF_CpListA65C,	1,	TQU("\xA65D"),
	0xA65E,	CaseFoldingCF_CpListA65E,	1,	TQU("\xA65F"),
	0xA660,	CaseFoldingCF_CpListA660,	1,	TQU("\xA661"),
	0xA662,	CaseFoldingCF_CpListA662,	1,	TQU("\xA663"),
	0xA664,	CaseFoldingCF_CpListA664,	1,	TQU("\xA665"),
	0xA666,	CaseFoldingCF_CpListA666,	1,	TQU("\xA667"),
	0xA668,	CaseFoldingCF_CpListA668,	1,	TQU("\xA669"),
	0xA66A,	CaseFoldingCF_CpListA66A,	1,	TQU("\xA66B"),
	0xA66C,	CaseFoldingCF_CpListA66C,	1,	TQU("\xA66D"),
	0xA680,	CaseFoldingCF_CpListA680,	1,	TQU("\xA681"),
	0xA682,	CaseFoldingCF_CpListA682,	1,	TQU("\xA683"),
	0xA684,	CaseFoldingCF_CpListA684,	1,	TQU("\xA685"),
	0xA686,	CaseFoldingCF_CpListA686,	1,	TQU("\xA687"),
	0xA688,	CaseFoldingCF_CpListA688,	1,	TQU("\xA689"),
	0xA68A,	CaseFoldingCF_CpListA68A,	1,	TQU("\xA68B"),
	0xA68C,	CaseFoldingCF_CpListA68C,	1,	TQU("\xA68D"),
	0xA68E,	CaseFoldingCF_CpListA68E,	1,	TQU("\xA68F"),
	0xA690,	CaseFoldingCF_CpListA690,	1,	TQU("\xA691"),
	0xA692,	CaseFoldingCF_CpListA692,	1,	TQU("\xA693"),
	0xA694,	CaseFoldingCF_CpListA694,	1,	TQU("\xA695"),
	0xA696,	CaseFoldingCF_CpListA696,	1,	TQU("\xA697"),
	0xA722,	CaseFoldingCF_CpListA722,	1,	TQU("\xA723"),
	0xA724,	CaseFoldingCF_CpListA724,	1,	TQU("\xA725"),
	0xA726,	CaseFoldingCF_CpListA726,	1,	TQU("\xA727"),
	0xA728,	CaseFoldingCF_CpListA728,	1,	TQU("\xA729"),
	0xA72A,	CaseFoldingCF_CpListA72A,	1,	TQU("\xA72B"),
	0xA72C,	CaseFoldingCF_CpListA72C,	1,	TQU("\xA72D"),
	0xA72E,	CaseFoldingCF_CpListA72E,	1,	TQU("\xA72F"),
	0xA732,	CaseFoldingCF_CpListA732,	1,	TQU("\xA733"),
	0xA734,	CaseFoldingCF_CpListA734,	1,	TQU("\xA735"),
	0xA736,	CaseFoldingCF_CpListA736,	1,	TQU("\xA737"),
	0xA738,	CaseFoldingCF_CpListA738,	1,	TQU("\xA739"),
	0xA73A,	CaseFoldingCF_CpListA73A,	1,	TQU("\xA73B"),
	0xA73C,	CaseFoldingCF_CpListA73C,	1,	TQU("\xA73D"),
	0xA73E,	CaseFoldingCF_CpListA73E,	1,	TQU("\xA73F"),
	0xA740,	CaseFoldingCF_CpListA740,	1,	TQU("\xA741"),
	0xA742,	CaseFoldingCF_CpListA742,	1,	TQU("\xA743"),
	0xA744,	CaseFoldingCF_CpListA744,	1,	TQU("\xA745"),
	0xA746,	CaseFoldingCF_CpListA746,	1,	TQU("\xA747"),
	0xA748,	CaseFoldingCF_CpListA748,	1,	TQU("\xA749"),
	0xA74A,	CaseFoldingCF_CpListA74A,	1,	TQU("\xA74B"),
	0xA74C,	CaseFoldingCF_CpListA74C,	1,	TQU("\xA74D"),
	0xA74E,	CaseFoldingCF_CpListA74E,	1,	TQU("\xA74F"),
	0xA750,	CaseFoldingCF_CpListA750,	1,	TQU("\xA751"),
	0xA752,	CaseFoldingCF_CpListA752,	1,	TQU("\xA753"),
	0xA754,	CaseFoldingCF_CpListA754,	1,	TQU("\xA755"),
	0xA756,	CaseFoldingCF_CpListA756,	1,	TQU("\xA757"),
	0xA758,	CaseFoldingCF_CpListA758,	1,	TQU("\xA759"),
	0xA75A,	CaseFoldingCF_CpListA75A,	1,	TQU("\xA75B"),
	0xA75C,	CaseFoldingCF_CpListA75C,	1,	TQU("\xA75D"),
	0xA75E,	CaseFoldingCF_CpListA75E,	1,	TQU("\xA75F"),
	0xA760,	CaseFoldingCF_CpListA760,	1,	TQU("\xA761"),
	0xA762,	CaseFoldingCF_CpListA762,	1,	TQU("\xA763"),
	0xA764,	CaseFoldingCF_CpListA764,	1,	TQU("\xA765"),
	0xA766,	CaseFoldingCF_CpListA766,	1,	TQU("\xA767"),
	0xA768,	CaseFoldingCF_CpListA768,	1,	TQU("\xA769"),
	0xA76A,	CaseFoldingCF_CpListA76A,	1,	TQU("\xA76B"),
	0xA76C,	CaseFoldingCF_CpListA76C,	1,	TQU("\xA76D"),
	0xA76E,	CaseFoldingCF_CpListA76E,	1,	TQU("\xA76F"),
	0xA779,	CaseFoldingCF_CpListA779,	1,	TQU("\xA77A"),
	0xA77B,	CaseFoldingCF_CpListA77B,	1,	TQU("\xA77C"),
	0xA77D,	CaseFoldingCF_CpListA77D,	1,	TQU("\x1D79"),
	0xA77E,	CaseFoldingCF_CpListA77E,	1,	TQU("\xA77F"),
	0xA780,	CaseFoldingCF_CpListA780,	1,	TQU("\xA781"),
	0xA782,	CaseFoldingCF_CpListA782,	1,	TQU("\xA783"),
	0xA784,	CaseFoldingCF_CpListA784,	1,	TQU("\xA785"),
	0xA786,	CaseFoldingCF_CpListA786,	1,	TQU("\xA787"),
	0xA78B,	CaseFoldingCF_CpListA78B,	1,	TQU("\xA78C"),
	0xA78D,	CaseFoldingCF_CpListA78D,	1,	TQU("\x0265"),
	0xA790,	CaseFoldingCF_CpListA790,	1,	TQU("\xA791"),
	0xA792,	CaseFoldingCF_CpListA792,	1,	TQU("\xA793"),
	0xA7A0,	CaseFoldingCF_CpListA7A0,	1,	TQU("\xA7A1"),
	0xA7A2,	CaseFoldingCF_CpListA7A2,	1,	TQU("\xA7A3"),
	0xA7A4,	CaseFoldingCF_CpListA7A4,	1,	TQU("\xA7A5"),
	0xA7A6,	CaseFoldingCF_CpListA7A6,	1,	TQU("\xA7A7"),
	0xA7A8,	CaseFoldingCF_CpListA7A8,	1,	TQU("\xA7A9"),
	0xA7AA,	CaseFoldingCF_CpListA7AA,	1,	TQU("\x0266"),
	0xFB00,	CaseFoldingCF_CpListFB00,	2,	TQU("\x0066\x0066"),
	0xFB01,	CaseFoldingCF_CpListFB01,	2,	TQU("\x0066\x0069"),
	0xFB02,	CaseFoldingCF_CpListFB02,	2,	TQU("\x0066\x006C"),
	0xFB03,	CaseFoldingCF_CpListFB03,	3,	TQU("\x0066\x0066\x0069"),
	0xFB04,	CaseFoldingCF_CpListFB04,	3,	TQU("\x0066\x0066\x006C"),
	0xFB05,	CaseFoldingCF_CpListFB05,	2,	TQU("\x0073\x0074"),
	0xFB06,	CaseFoldingCF_CpListFB06,	2,	TQU("\x0073\x0074"),
	0xFB13,	CaseFoldingCF_CpListFB13,	2,	TQU("\x0574\x0576"),
	0xFB14,	CaseFoldingCF_CpListFB14,	2,	TQU("\x0574\x0565"),
	0xFB15,	CaseFoldingCF_CpListFB15,	2,	TQU("\x0574\x056B"),
	0xFB16,	CaseFoldingCF_CpListFB16,	2,	TQU("\x057E\x0576"),
	0xFB17,	CaseFoldingCF_CpListFB17,	2,	TQU("\x0574\x056D"),
	0xFF21,	CaseFoldingCF_CpListFF21,	1,	TQU("\xFF41"),
	0xFF22,	CaseFoldingCF_CpListFF22,	1,	TQU("\xFF42"),
	0xFF23,	CaseFoldingCF_CpListFF23,	1,	TQU("\xFF43"),
	0xFF24,	CaseFoldingCF_CpListFF24,	1,	TQU("\xFF44"),
	0xFF25,	CaseFoldingCF_CpListFF25,	1,	TQU("\xFF45"),
	0xFF26,	CaseFoldingCF_CpListFF26,	1,	TQU("\xFF46"),
	0xFF27,	CaseFoldingCF_CpListFF27,	1,	TQU("\xFF47"),
	0xFF28,	CaseFoldingCF_CpListFF28,	1,	TQU("\xFF48"),
	0xFF29,	CaseFoldingCF_CpListFF29,	1,	TQU("\xFF49"),
	0xFF2A,	CaseFoldingCF_CpListFF2A,	1,	TQU("\xFF4A"),
	0xFF2B,	CaseFoldingCF_CpListFF2B,	1,	TQU("\xFF4B"),
	0xFF2C,	CaseFoldingCF_CpListFF2C,	1,	TQU("\xFF4C"),
	0xFF2D,	CaseFoldingCF_CpListFF2D,	1,	TQU("\xFF4D"),
	0xFF2E,	CaseFoldingCF_CpListFF2E,	1,	TQU("\xFF4E"),
	0xFF2F,	CaseFoldingCF_CpListFF2F,	1,	TQU("\xFF4F"),
	0xFF30,	CaseFoldingCF_CpListFF30,	1,	TQU("\xFF50"),
	0xFF31,	CaseFoldingCF_CpListFF31,	1,	TQU("\xFF51"),
	0xFF32,	CaseFoldingCF_CpListFF32,	1,	TQU("\xFF52"),
	0xFF33,	CaseFoldingCF_CpListFF33,	1,	TQU("\xFF53"),
	0xFF34,	CaseFoldingCF_CpListFF34,	1,	TQU("\xFF54"),
	0xFF35,	CaseFoldingCF_CpListFF35,	1,	TQU("\xFF55"),
	0xFF36,	CaseFoldingCF_CpListFF36,	1,	TQU("\xFF56"),
	0xFF37,	CaseFoldingCF_CpListFF37,	1,	TQU("\xFF57"),
	0xFF38,	CaseFoldingCF_CpListFF38,	1,	TQU("\xFF58"),
	0xFF39,	CaseFoldingCF_CpListFF39,	1,	TQU("\xFF59"),
	0xFF3A,	CaseFoldingCF_CpListFF3A,	1,	TQU("\xFF5A"),
	0x10400,	CaseFoldingCF_CpList10400,	1,	TQU("\xD801\xDC28"),
	0x10401,	CaseFoldingCF_CpList10401,	1,	TQU("\xD801\xDC29"),
	0x10402,	CaseFoldingCF_CpList10402,	1,	TQU("\xD801\xDC2A"),
	0x10403,	CaseFoldingCF_CpList10403,	1,	TQU("\xD801\xDC2B"),
	0x10404,	CaseFoldingCF_CpList10404,	1,	TQU("\xD801\xDC2C"),
	0x10405,	CaseFoldingCF_CpList10405,	1,	TQU("\xD801\xDC2D"),
	0x10406,	CaseFoldingCF_CpList10406,	1,	TQU("\xD801\xDC2E"),
	0x10407,	CaseFoldingCF_CpList10407,	1,	TQU("\xD801\xDC2F"),
	0x10408,	CaseFoldingCF_CpList10408,	1,	TQU("\xD801\xDC30"),
	0x10409,	CaseFoldingCF_CpList10409,	1,	TQU("\xD801\xDC31"),
	0x1040A,	CaseFoldingCF_CpList1040A,	1,	TQU("\xD801\xDC32"),
	0x1040B,	CaseFoldingCF_CpList1040B,	1,	TQU("\xD801\xDC33"),
	0x1040C,	CaseFoldingCF_CpList1040C,	1,	TQU("\xD801\xDC34"),
	0x1040D,	CaseFoldingCF_CpList1040D,	1,	TQU("\xD801\xDC35"),
	0x1040E,	CaseFoldingCF_CpList1040E,	1,	TQU("\xD801\xDC36"),
	0x1040F,	CaseFoldingCF_CpList1040F,	1,	TQU("\xD801\xDC37"),
	0x10410,	CaseFoldingCF_CpList10410,	1,	TQU("\xD801\xDC38"),
	0x10411,	CaseFoldingCF_CpList10411,	1,	TQU("\xD801\xDC39"),
	0x10412,	CaseFoldingCF_CpList10412,	1,	TQU("\xD801\xDC3A"),
	0x10413,	CaseFoldingCF_CpList10413,	1,	TQU("\xD801\xDC3B"),
	0x10414,	CaseFoldingCF_CpList10414,	1,	TQU("\xD801\xDC3C"),
	0x10415,	CaseFoldingCF_CpList10415,	1,	TQU("\xD801\xDC3D"),
	0x10416,	CaseFoldingCF_CpList10416,	1,	TQU("\xD801\xDC3E"),
	0x10417,	CaseFoldingCF_CpList10417,	1,	TQU("\xD801\xDC3F"),
	0x10418,	CaseFoldingCF_CpList10418,	1,	TQU("\xD801\xDC40"),
	0x10419,	CaseFoldingCF_CpList10419,	1,	TQU("\xD801\xDC41"),
	0x1041A,	CaseFoldingCF_CpList1041A,	1,	TQU("\xD801\xDC42"),
	0x1041B,	CaseFoldingCF_CpList1041B,	1,	TQU("\xD801\xDC43"),
	0x1041C,	CaseFoldingCF_CpList1041C,	1,	TQU("\xD801\xDC44"),
	0x1041D,	CaseFoldingCF_CpList1041D,	1,	TQU("\xD801\xDC45"),
	0x1041E,	CaseFoldingCF_CpList1041E,	1,	TQU("\xD801\xDC46"),
	0x1041F,	CaseFoldingCF_CpList1041F,	1,	TQU("\xD801\xDC47"),
	0x10420,	CaseFoldingCF_CpList10420,	1,	TQU("\xD801\xDC48"),
	0x10421,	CaseFoldingCF_CpList10421,	1,	TQU("\xD801\xDC49"),
	0x10422,	CaseFoldingCF_CpList10422,	1,	TQU("\xD801\xDC4A"),
	0x10423,	CaseFoldingCF_CpList10423,	1,	TQU("\xD801\xDC4B"),
	0x10424,	CaseFoldingCF_CpList10424,	1,	TQU("\xD801\xDC4C"),
	0x10425,	CaseFoldingCF_CpList10425,	1,	TQU("\xD801\xDC4D"),
	0x10426,	CaseFoldingCF_CpList10426,	1,	TQU("\xD801\xDC4E"),
	0x10427,	CaseFoldingCF_CpList10427,	1,	TQU("\xD801\xDC4F"),
};
const size_t	nCaseFolding_CF	= sizeof(siCaseFolding_CF) / sizeof(SCASEFOLDMAP);

//----------------------------------------------------------------------
//	Common and Simple Case Folding	: Codepage List
//----------------------------------------------------------------------
UINT	CaseFoldingCS_CpList0041[]	= { 0x0061, 0 };
UINT	CaseFoldingCS_CpList0042[]	= { 0x0062, 0 };
UINT	CaseFoldingCS_CpList0043[]	= { 0x0063, 0 };
UINT	CaseFoldingCS_CpList0044[]	= { 0x0064, 0 };
UINT	CaseFoldingCS_CpList0045[]	= { 0x0065, 0 };
UINT	CaseFoldingCS_CpList0046[]	= { 0x0066, 0 };
UINT	CaseFoldingCS_CpList0047[]	= { 0x0067, 0 };
UINT	CaseFoldingCS_CpList0048[]	= { 0x0068, 0 };
UINT	CaseFoldingCS_CpList0049[]	= { 0x0069, 0 };
UINT	CaseFoldingCS_CpList004A[]	= { 0x006A, 0 };
UINT	CaseFoldingCS_CpList004B[]	= { 0x006B, 0 };
UINT	CaseFoldingCS_CpList004C[]	= { 0x006C, 0 };
UINT	CaseFoldingCS_CpList004D[]	= { 0x006D, 0 };
UINT	CaseFoldingCS_CpList004E[]	= { 0x006E, 0 };
UINT	CaseFoldingCS_CpList004F[]	= { 0x006F, 0 };
UINT	CaseFoldingCS_CpList0050[]	= { 0x0070, 0 };
UINT	CaseFoldingCS_CpList0051[]	= { 0x0071, 0 };
UINT	CaseFoldingCS_CpList0052[]	= { 0x0072, 0 };
UINT	CaseFoldingCS_CpList0053[]	= { 0x0073, 0 };
UINT	CaseFoldingCS_CpList0054[]	= { 0x0074, 0 };
UINT	CaseFoldingCS_CpList0055[]	= { 0x0075, 0 };
UINT	CaseFoldingCS_CpList0056[]	= { 0x0076, 0 };
UINT	CaseFoldingCS_CpList0057[]	= { 0x0077, 0 };
UINT	CaseFoldingCS_CpList0058[]	= { 0x0078, 0 };
UINT	CaseFoldingCS_CpList0059[]	= { 0x0079, 0 };
UINT	CaseFoldingCS_CpList005A[]	= { 0x007A, 0 };
UINT	CaseFoldingCS_CpList00B5[]	= { 0x03BC, 0 };
UINT	CaseFoldingCS_CpList00C0[]	= { 0x00E0, 0 };
UINT	CaseFoldingCS_CpList00C1[]	= { 0x00E1, 0 };
UINT	CaseFoldingCS_CpList00C2[]	= { 0x00E2, 0 };
UINT	CaseFoldingCS_CpList00C3[]	= { 0x00E3, 0 };
UINT	CaseFoldingCS_CpList00C4[]	= { 0x00E4, 0 };
UINT	CaseFoldingCS_CpList00C5[]	= { 0x00E5, 0 };
UINT	CaseFoldingCS_CpList00C6[]	= { 0x00E6, 0 };
UINT	CaseFoldingCS_CpList00C7[]	= { 0x00E7, 0 };
UINT	CaseFoldingCS_CpList00C8[]	= { 0x00E8, 0 };
UINT	CaseFoldingCS_CpList00C9[]	= { 0x00E9, 0 };
UINT	CaseFoldingCS_CpList00CA[]	= { 0x00EA, 0 };
UINT	CaseFoldingCS_CpList00CB[]	= { 0x00EB, 0 };
UINT	CaseFoldingCS_CpList00CC[]	= { 0x00EC, 0 };
UINT	CaseFoldingCS_CpList00CD[]	= { 0x00ED, 0 };
UINT	CaseFoldingCS_CpList00CE[]	= { 0x00EE, 0 };
UINT	CaseFoldingCS_CpList00CF[]	= { 0x00EF, 0 };
UINT	CaseFoldingCS_CpList00D0[]	= { 0x00F0, 0 };
UINT	CaseFoldingCS_CpList00D1[]	= { 0x00F1, 0 };
UINT	CaseFoldingCS_CpList00D2[]	= { 0x00F2, 0 };
UINT	CaseFoldingCS_CpList00D3[]	= { 0x00F3, 0 };
UINT	CaseFoldingCS_CpList00D4[]	= { 0x00F4, 0 };
UINT	CaseFoldingCS_CpList00D5[]	= { 0x00F5, 0 };
UINT	CaseFoldingCS_CpList00D6[]	= { 0x00F6, 0 };
UINT	CaseFoldingCS_CpList00D8[]	= { 0x00F8, 0 };
UINT	CaseFoldingCS_CpList00D9[]	= { 0x00F9, 0 };
UINT	CaseFoldingCS_CpList00DA[]	= { 0x00FA, 0 };
UINT	CaseFoldingCS_CpList00DB[]	= { 0x00FB, 0 };
UINT	CaseFoldingCS_CpList00DC[]	= { 0x00FC, 0 };
UINT	CaseFoldingCS_CpList00DD[]	= { 0x00FD, 0 };
UINT	CaseFoldingCS_CpList00DE[]	= { 0x00FE, 0 };
UINT	CaseFoldingCS_CpList0100[]	= { 0x0101, 0 };
UINT	CaseFoldingCS_CpList0102[]	= { 0x0103, 0 };
UINT	CaseFoldingCS_CpList0104[]	= { 0x0105, 0 };
UINT	CaseFoldingCS_CpList0106[]	= { 0x0107, 0 };
UINT	CaseFoldingCS_CpList0108[]	= { 0x0109, 0 };
UINT	CaseFoldingCS_CpList010A[]	= { 0x010B, 0 };
UINT	CaseFoldingCS_CpList010C[]	= { 0x010D, 0 };
UINT	CaseFoldingCS_CpList010E[]	= { 0x010F, 0 };
UINT	CaseFoldingCS_CpList0110[]	= { 0x0111, 0 };
UINT	CaseFoldingCS_CpList0112[]	= { 0x0113, 0 };
UINT	CaseFoldingCS_CpList0114[]	= { 0x0115, 0 };
UINT	CaseFoldingCS_CpList0116[]	= { 0x0117, 0 };
UINT	CaseFoldingCS_CpList0118[]	= { 0x0119, 0 };
UINT	CaseFoldingCS_CpList011A[]	= { 0x011B, 0 };
UINT	CaseFoldingCS_CpList011C[]	= { 0x011D, 0 };
UINT	CaseFoldingCS_CpList011E[]	= { 0x011F, 0 };
UINT	CaseFoldingCS_CpList0120[]	= { 0x0121, 0 };
UINT	CaseFoldingCS_CpList0122[]	= { 0x0123, 0 };
UINT	CaseFoldingCS_CpList0124[]	= { 0x0125, 0 };
UINT	CaseFoldingCS_CpList0126[]	= { 0x0127, 0 };
UINT	CaseFoldingCS_CpList0128[]	= { 0x0129, 0 };
UINT	CaseFoldingCS_CpList012A[]	= { 0x012B, 0 };
UINT	CaseFoldingCS_CpList012C[]	= { 0x012D, 0 };
UINT	CaseFoldingCS_CpList012E[]	= { 0x012F, 0 };
UINT	CaseFoldingCS_CpList0132[]	= { 0x0133, 0 };
UINT	CaseFoldingCS_CpList0134[]	= { 0x0135, 0 };
UINT	CaseFoldingCS_CpList0136[]	= { 0x0137, 0 };
UINT	CaseFoldingCS_CpList0139[]	= { 0x013A, 0 };
UINT	CaseFoldingCS_CpList013B[]	= { 0x013C, 0 };
UINT	CaseFoldingCS_CpList013D[]	= { 0x013E, 0 };
UINT	CaseFoldingCS_CpList013F[]	= { 0x0140, 0 };
UINT	CaseFoldingCS_CpList0141[]	= { 0x0142, 0 };
UINT	CaseFoldingCS_CpList0143[]	= { 0x0144, 0 };
UINT	CaseFoldingCS_CpList0145[]	= { 0x0146, 0 };
UINT	CaseFoldingCS_CpList0147[]	= { 0x0148, 0 };
UINT	CaseFoldingCS_CpList014A[]	= { 0x014B, 0 };
UINT	CaseFoldingCS_CpList014C[]	= { 0x014D, 0 };
UINT	CaseFoldingCS_CpList014E[]	= { 0x014F, 0 };
UINT	CaseFoldingCS_CpList0150[]	= { 0x0151, 0 };
UINT	CaseFoldingCS_CpList0152[]	= { 0x0153, 0 };
UINT	CaseFoldingCS_CpList0154[]	= { 0x0155, 0 };
UINT	CaseFoldingCS_CpList0156[]	= { 0x0157, 0 };
UINT	CaseFoldingCS_CpList0158[]	= { 0x0159, 0 };
UINT	CaseFoldingCS_CpList015A[]	= { 0x015B, 0 };
UINT	CaseFoldingCS_CpList015C[]	= { 0x015D, 0 };
UINT	CaseFoldingCS_CpList015E[]	= { 0x015F, 0 };
UINT	CaseFoldingCS_CpList0160[]	= { 0x0161, 0 };
UINT	CaseFoldingCS_CpList0162[]	= { 0x0163, 0 };
UINT	CaseFoldingCS_CpList0164[]	= { 0x0165, 0 };
UINT	CaseFoldingCS_CpList0166[]	= { 0x0167, 0 };
UINT	CaseFoldingCS_CpList0168[]	= { 0x0169, 0 };
UINT	CaseFoldingCS_CpList016A[]	= { 0x016B, 0 };
UINT	CaseFoldingCS_CpList016C[]	= { 0x016D, 0 };
UINT	CaseFoldingCS_CpList016E[]	= { 0x016F, 0 };
UINT	CaseFoldingCS_CpList0170[]	= { 0x0171, 0 };
UINT	CaseFoldingCS_CpList0172[]	= { 0x0173, 0 };
UINT	CaseFoldingCS_CpList0174[]	= { 0x0175, 0 };
UINT	CaseFoldingCS_CpList0176[]	= { 0x0177, 0 };
UINT	CaseFoldingCS_CpList0178[]	= { 0x00FF, 0 };
UINT	CaseFoldingCS_CpList0179[]	= { 0x017A, 0 };
UINT	CaseFoldingCS_CpList017B[]	= { 0x017C, 0 };
UINT	CaseFoldingCS_CpList017D[]	= { 0x017E, 0 };
UINT	CaseFoldingCS_CpList017F[]	= { 0x0073, 0 };
UINT	CaseFoldingCS_CpList0181[]	= { 0x0253, 0 };
UINT	CaseFoldingCS_CpList0182[]	= { 0x0183, 0 };
UINT	CaseFoldingCS_CpList0184[]	= { 0x0185, 0 };
UINT	CaseFoldingCS_CpList0186[]	= { 0x0254, 0 };
UINT	CaseFoldingCS_CpList0187[]	= { 0x0188, 0 };
UINT	CaseFoldingCS_CpList0189[]	= { 0x0256, 0 };
UINT	CaseFoldingCS_CpList018A[]	= { 0x0257, 0 };
UINT	CaseFoldingCS_CpList018B[]	= { 0x018C, 0 };
UINT	CaseFoldingCS_CpList018E[]	= { 0x01DD, 0 };
UINT	CaseFoldingCS_CpList018F[]	= { 0x0259, 0 };
UINT	CaseFoldingCS_CpList0190[]	= { 0x025B, 0 };
UINT	CaseFoldingCS_CpList0191[]	= { 0x0192, 0 };
UINT	CaseFoldingCS_CpList0193[]	= { 0x0260, 0 };
UINT	CaseFoldingCS_CpList0194[]	= { 0x0263, 0 };
UINT	CaseFoldingCS_CpList0196[]	= { 0x0269, 0 };
UINT	CaseFoldingCS_CpList0197[]	= { 0x0268, 0 };
UINT	CaseFoldingCS_CpList0198[]	= { 0x0199, 0 };
UINT	CaseFoldingCS_CpList019C[]	= { 0x026F, 0 };
UINT	CaseFoldingCS_CpList019D[]	= { 0x0272, 0 };
UINT	CaseFoldingCS_CpList019F[]	= { 0x0275, 0 };
UINT	CaseFoldingCS_CpList01A0[]	= { 0x01A1, 0 };
UINT	CaseFoldingCS_CpList01A2[]	= { 0x01A3, 0 };
UINT	CaseFoldingCS_CpList01A4[]	= { 0x01A5, 0 };
UINT	CaseFoldingCS_CpList01A6[]	= { 0x0280, 0 };
UINT	CaseFoldingCS_CpList01A7[]	= { 0x01A8, 0 };
UINT	CaseFoldingCS_CpList01A9[]	= { 0x0283, 0 };
UINT	CaseFoldingCS_CpList01AC[]	= { 0x01AD, 0 };
UINT	CaseFoldingCS_CpList01AE[]	= { 0x0288, 0 };
UINT	CaseFoldingCS_CpList01AF[]	= { 0x01B0, 0 };
UINT	CaseFoldingCS_CpList01B1[]	= { 0x028A, 0 };
UINT	CaseFoldingCS_CpList01B2[]	= { 0x028B, 0 };
UINT	CaseFoldingCS_CpList01B3[]	= { 0x01B4, 0 };
UINT	CaseFoldingCS_CpList01B5[]	= { 0x01B6, 0 };
UINT	CaseFoldingCS_CpList01B7[]	= { 0x0292, 0 };
UINT	CaseFoldingCS_CpList01B8[]	= { 0x01B9, 0 };
UINT	CaseFoldingCS_CpList01BC[]	= { 0x01BD, 0 };
UINT	CaseFoldingCS_CpList01C4[]	= { 0x01C6, 0 };
UINT	CaseFoldingCS_CpList01C5[]	= { 0x01C6, 0 };
UINT	CaseFoldingCS_CpList01C7[]	= { 0x01C9, 0 };
UINT	CaseFoldingCS_CpList01C8[]	= { 0x01C9, 0 };
UINT	CaseFoldingCS_CpList01CA[]	= { 0x01CC, 0 };
UINT	CaseFoldingCS_CpList01CB[]	= { 0x01CC, 0 };
UINT	CaseFoldingCS_CpList01CD[]	= { 0x01CE, 0 };
UINT	CaseFoldingCS_CpList01CF[]	= { 0x01D0, 0 };
UINT	CaseFoldingCS_CpList01D1[]	= { 0x01D2, 0 };
UINT	CaseFoldingCS_CpList01D3[]	= { 0x01D4, 0 };
UINT	CaseFoldingCS_CpList01D5[]	= { 0x01D6, 0 };
UINT	CaseFoldingCS_CpList01D7[]	= { 0x01D8, 0 };
UINT	CaseFoldingCS_CpList01D9[]	= { 0x01DA, 0 };
UINT	CaseFoldingCS_CpList01DB[]	= { 0x01DC, 0 };
UINT	CaseFoldingCS_CpList01DE[]	= { 0x01DF, 0 };
UINT	CaseFoldingCS_CpList01E0[]	= { 0x01E1, 0 };
UINT	CaseFoldingCS_CpList01E2[]	= { 0x01E3, 0 };
UINT	CaseFoldingCS_CpList01E4[]	= { 0x01E5, 0 };
UINT	CaseFoldingCS_CpList01E6[]	= { 0x01E7, 0 };
UINT	CaseFoldingCS_CpList01E8[]	= { 0x01E9, 0 };
UINT	CaseFoldingCS_CpList01EA[]	= { 0x01EB, 0 };
UINT	CaseFoldingCS_CpList01EC[]	= { 0x01ED, 0 };
UINT	CaseFoldingCS_CpList01EE[]	= { 0x01EF, 0 };
UINT	CaseFoldingCS_CpList01F1[]	= { 0x01F3, 0 };
UINT	CaseFoldingCS_CpList01F2[]	= { 0x01F3, 0 };
UINT	CaseFoldingCS_CpList01F4[]	= { 0x01F5, 0 };
UINT	CaseFoldingCS_CpList01F6[]	= { 0x0195, 0 };
UINT	CaseFoldingCS_CpList01F7[]	= { 0x01BF, 0 };
UINT	CaseFoldingCS_CpList01F8[]	= { 0x01F9, 0 };
UINT	CaseFoldingCS_CpList01FA[]	= { 0x01FB, 0 };
UINT	CaseFoldingCS_CpList01FC[]	= { 0x01FD, 0 };
UINT	CaseFoldingCS_CpList01FE[]	= { 0x01FF, 0 };
UINT	CaseFoldingCS_CpList0200[]	= { 0x0201, 0 };
UINT	CaseFoldingCS_CpList0202[]	= { 0x0203, 0 };
UINT	CaseFoldingCS_CpList0204[]	= { 0x0205, 0 };
UINT	CaseFoldingCS_CpList0206[]	= { 0x0207, 0 };
UINT	CaseFoldingCS_CpList0208[]	= { 0x0209, 0 };
UINT	CaseFoldingCS_CpList020A[]	= { 0x020B, 0 };
UINT	CaseFoldingCS_CpList020C[]	= { 0x020D, 0 };
UINT	CaseFoldingCS_CpList020E[]	= { 0x020F, 0 };
UINT	CaseFoldingCS_CpList0210[]	= { 0x0211, 0 };
UINT	CaseFoldingCS_CpList0212[]	= { 0x0213, 0 };
UINT	CaseFoldingCS_CpList0214[]	= { 0x0215, 0 };
UINT	CaseFoldingCS_CpList0216[]	= { 0x0217, 0 };
UINT	CaseFoldingCS_CpList0218[]	= { 0x0219, 0 };
UINT	CaseFoldingCS_CpList021A[]	= { 0x021B, 0 };
UINT	CaseFoldingCS_CpList021C[]	= { 0x021D, 0 };
UINT	CaseFoldingCS_CpList021E[]	= { 0x021F, 0 };
UINT	CaseFoldingCS_CpList0220[]	= { 0x019E, 0 };
UINT	CaseFoldingCS_CpList0222[]	= { 0x0223, 0 };
UINT	CaseFoldingCS_CpList0224[]	= { 0x0225, 0 };
UINT	CaseFoldingCS_CpList0226[]	= { 0x0227, 0 };
UINT	CaseFoldingCS_CpList0228[]	= { 0x0229, 0 };
UINT	CaseFoldingCS_CpList022A[]	= { 0x022B, 0 };
UINT	CaseFoldingCS_CpList022C[]	= { 0x022D, 0 };
UINT	CaseFoldingCS_CpList022E[]	= { 0x022F, 0 };
UINT	CaseFoldingCS_CpList0230[]	= { 0x0231, 0 };
UINT	CaseFoldingCS_CpList0232[]	= { 0x0233, 0 };
UINT	CaseFoldingCS_CpList023A[]	= { 0x2C65, 0 };
UINT	CaseFoldingCS_CpList023B[]	= { 0x023C, 0 };
UINT	CaseFoldingCS_CpList023D[]	= { 0x019A, 0 };
UINT	CaseFoldingCS_CpList023E[]	= { 0x2C66, 0 };
UINT	CaseFoldingCS_CpList0241[]	= { 0x0242, 0 };
UINT	CaseFoldingCS_CpList0243[]	= { 0x0180, 0 };
UINT	CaseFoldingCS_CpList0244[]	= { 0x0289, 0 };
UINT	CaseFoldingCS_CpList0245[]	= { 0x028C, 0 };
UINT	CaseFoldingCS_CpList0246[]	= { 0x0247, 0 };
UINT	CaseFoldingCS_CpList0248[]	= { 0x0249, 0 };
UINT	CaseFoldingCS_CpList024A[]	= { 0x024B, 0 };
UINT	CaseFoldingCS_CpList024C[]	= { 0x024D, 0 };
UINT	CaseFoldingCS_CpList024E[]	= { 0x024F, 0 };
UINT	CaseFoldingCS_CpList0345[]	= { 0x03B9, 0 };
UINT	CaseFoldingCS_CpList0370[]	= { 0x0371, 0 };
UINT	CaseFoldingCS_CpList0372[]	= { 0x0373, 0 };
UINT	CaseFoldingCS_CpList0376[]	= { 0x0377, 0 };
UINT	CaseFoldingCS_CpList0386[]	= { 0x03AC, 0 };
UINT	CaseFoldingCS_CpList0388[]	= { 0x03AD, 0 };
UINT	CaseFoldingCS_CpList0389[]	= { 0x03AE, 0 };
UINT	CaseFoldingCS_CpList038A[]	= { 0x03AF, 0 };
UINT	CaseFoldingCS_CpList038C[]	= { 0x03CC, 0 };
UINT	CaseFoldingCS_CpList038E[]	= { 0x03CD, 0 };
UINT	CaseFoldingCS_CpList038F[]	= { 0x03CE, 0 };
UINT	CaseFoldingCS_CpList0391[]	= { 0x03B1, 0 };
UINT	CaseFoldingCS_CpList0392[]	= { 0x03B2, 0 };
UINT	CaseFoldingCS_CpList0393[]	= { 0x03B3, 0 };
UINT	CaseFoldingCS_CpList0394[]	= { 0x03B4, 0 };
UINT	CaseFoldingCS_CpList0395[]	= { 0x03B5, 0 };
UINT	CaseFoldingCS_CpList0396[]	= { 0x03B6, 0 };
UINT	CaseFoldingCS_CpList0397[]	= { 0x03B7, 0 };
UINT	CaseFoldingCS_CpList0398[]	= { 0x03B8, 0 };
UINT	CaseFoldingCS_CpList0399[]	= { 0x03B9, 0 };
UINT	CaseFoldingCS_CpList039A[]	= { 0x03BA, 0 };
UINT	CaseFoldingCS_CpList039B[]	= { 0x03BB, 0 };
UINT	CaseFoldingCS_CpList039C[]	= { 0x03BC, 0 };
UINT	CaseFoldingCS_CpList039D[]	= { 0x03BD, 0 };
UINT	CaseFoldingCS_CpList039E[]	= { 0x03BE, 0 };
UINT	CaseFoldingCS_CpList039F[]	= { 0x03BF, 0 };
UINT	CaseFoldingCS_CpList03A0[]	= { 0x03C0, 0 };
UINT	CaseFoldingCS_CpList03A1[]	= { 0x03C1, 0 };
UINT	CaseFoldingCS_CpList03A3[]	= { 0x03C3, 0 };
UINT	CaseFoldingCS_CpList03A4[]	= { 0x03C4, 0 };
UINT	CaseFoldingCS_CpList03A5[]	= { 0x03C5, 0 };
UINT	CaseFoldingCS_CpList03A6[]	= { 0x03C6, 0 };
UINT	CaseFoldingCS_CpList03A7[]	= { 0x03C7, 0 };
UINT	CaseFoldingCS_CpList03A8[]	= { 0x03C8, 0 };
UINT	CaseFoldingCS_CpList03A9[]	= { 0x03C9, 0 };
UINT	CaseFoldingCS_CpList03AA[]	= { 0x03CA, 0 };
UINT	CaseFoldingCS_CpList03AB[]	= { 0x03CB, 0 };
UINT	CaseFoldingCS_CpList03C2[]	= { 0x03C3, 0 };
UINT	CaseFoldingCS_CpList03CF[]	= { 0x03D7, 0 };
UINT	CaseFoldingCS_CpList03D0[]	= { 0x03B2, 0 };
UINT	CaseFoldingCS_CpList03D1[]	= { 0x03B8, 0 };
UINT	CaseFoldingCS_CpList03D5[]	= { 0x03C6, 0 };
UINT	CaseFoldingCS_CpList03D6[]	= { 0x03C0, 0 };
UINT	CaseFoldingCS_CpList03D8[]	= { 0x03D9, 0 };
UINT	CaseFoldingCS_CpList03DA[]	= { 0x03DB, 0 };
UINT	CaseFoldingCS_CpList03DC[]	= { 0x03DD, 0 };
UINT	CaseFoldingCS_CpList03DE[]	= { 0x03DF, 0 };
UINT	CaseFoldingCS_CpList03E0[]	= { 0x03E1, 0 };
UINT	CaseFoldingCS_CpList03E2[]	= { 0x03E3, 0 };
UINT	CaseFoldingCS_CpList03E4[]	= { 0x03E5, 0 };
UINT	CaseFoldingCS_CpList03E6[]	= { 0x03E7, 0 };
UINT	CaseFoldingCS_CpList03E8[]	= { 0x03E9, 0 };
UINT	CaseFoldingCS_CpList03EA[]	= { 0x03EB, 0 };
UINT	CaseFoldingCS_CpList03EC[]	= { 0x03ED, 0 };
UINT	CaseFoldingCS_CpList03EE[]	= { 0x03EF, 0 };
UINT	CaseFoldingCS_CpList03F0[]	= { 0x03BA, 0 };
UINT	CaseFoldingCS_CpList03F1[]	= { 0x03C1, 0 };
UINT	CaseFoldingCS_CpList03F4[]	= { 0x03B8, 0 };
UINT	CaseFoldingCS_CpList03F5[]	= { 0x03B5, 0 };
UINT	CaseFoldingCS_CpList03F7[]	= { 0x03F8, 0 };
UINT	CaseFoldingCS_CpList03F9[]	= { 0x03F2, 0 };
UINT	CaseFoldingCS_CpList03FA[]	= { 0x03FB, 0 };
UINT	CaseFoldingCS_CpList03FD[]	= { 0x037B, 0 };
UINT	CaseFoldingCS_CpList03FE[]	= { 0x037C, 0 };
UINT	CaseFoldingCS_CpList03FF[]	= { 0x037D, 0 };
UINT	CaseFoldingCS_CpList0400[]	= { 0x0450, 0 };
UINT	CaseFoldingCS_CpList0401[]	= { 0x0451, 0 };
UINT	CaseFoldingCS_CpList0402[]	= { 0x0452, 0 };
UINT	CaseFoldingCS_CpList0403[]	= { 0x0453, 0 };
UINT	CaseFoldingCS_CpList0404[]	= { 0x0454, 0 };
UINT	CaseFoldingCS_CpList0405[]	= { 0x0455, 0 };
UINT	CaseFoldingCS_CpList0406[]	= { 0x0456, 0 };
UINT	CaseFoldingCS_CpList0407[]	= { 0x0457, 0 };
UINT	CaseFoldingCS_CpList0408[]	= { 0x0458, 0 };
UINT	CaseFoldingCS_CpList0409[]	= { 0x0459, 0 };
UINT	CaseFoldingCS_CpList040A[]	= { 0x045A, 0 };
UINT	CaseFoldingCS_CpList040B[]	= { 0x045B, 0 };
UINT	CaseFoldingCS_CpList040C[]	= { 0x045C, 0 };
UINT	CaseFoldingCS_CpList040D[]	= { 0x045D, 0 };
UINT	CaseFoldingCS_CpList040E[]	= { 0x045E, 0 };
UINT	CaseFoldingCS_CpList040F[]	= { 0x045F, 0 };
UINT	CaseFoldingCS_CpList0410[]	= { 0x0430, 0 };
UINT	CaseFoldingCS_CpList0411[]	= { 0x0431, 0 };
UINT	CaseFoldingCS_CpList0412[]	= { 0x0432, 0 };
UINT	CaseFoldingCS_CpList0413[]	= { 0x0433, 0 };
UINT	CaseFoldingCS_CpList0414[]	= { 0x0434, 0 };
UINT	CaseFoldingCS_CpList0415[]	= { 0x0435, 0 };
UINT	CaseFoldingCS_CpList0416[]	= { 0x0436, 0 };
UINT	CaseFoldingCS_CpList0417[]	= { 0x0437, 0 };
UINT	CaseFoldingCS_CpList0418[]	= { 0x0438, 0 };
UINT	CaseFoldingCS_CpList0419[]	= { 0x0439, 0 };
UINT	CaseFoldingCS_CpList041A[]	= { 0x043A, 0 };
UINT	CaseFoldingCS_CpList041B[]	= { 0x043B, 0 };
UINT	CaseFoldingCS_CpList041C[]	= { 0x043C, 0 };
UINT	CaseFoldingCS_CpList041D[]	= { 0x043D, 0 };
UINT	CaseFoldingCS_CpList041E[]	= { 0x043E, 0 };
UINT	CaseFoldingCS_CpList041F[]	= { 0x043F, 0 };
UINT	CaseFoldingCS_CpList0420[]	= { 0x0440, 0 };
UINT	CaseFoldingCS_CpList0421[]	= { 0x0441, 0 };
UINT	CaseFoldingCS_CpList0422[]	= { 0x0442, 0 };
UINT	CaseFoldingCS_CpList0423[]	= { 0x0443, 0 };
UINT	CaseFoldingCS_CpList0424[]	= { 0x0444, 0 };
UINT	CaseFoldingCS_CpList0425[]	= { 0x0445, 0 };
UINT	CaseFoldingCS_CpList0426[]	= { 0x0446, 0 };
UINT	CaseFoldingCS_CpList0427[]	= { 0x0447, 0 };
UINT	CaseFoldingCS_CpList0428[]	= { 0x0448, 0 };
UINT	CaseFoldingCS_CpList0429[]	= { 0x0449, 0 };
UINT	CaseFoldingCS_CpList042A[]	= { 0x044A, 0 };
UINT	CaseFoldingCS_CpList042B[]	= { 0x044B, 0 };
UINT	CaseFoldingCS_CpList042C[]	= { 0x044C, 0 };
UINT	CaseFoldingCS_CpList042D[]	= { 0x044D, 0 };
UINT	CaseFoldingCS_CpList042E[]	= { 0x044E, 0 };
UINT	CaseFoldingCS_CpList042F[]	= { 0x044F, 0 };
UINT	CaseFoldingCS_CpList0460[]	= { 0x0461, 0 };
UINT	CaseFoldingCS_CpList0462[]	= { 0x0463, 0 };
UINT	CaseFoldingCS_CpList0464[]	= { 0x0465, 0 };
UINT	CaseFoldingCS_CpList0466[]	= { 0x0467, 0 };
UINT	CaseFoldingCS_CpList0468[]	= { 0x0469, 0 };
UINT	CaseFoldingCS_CpList046A[]	= { 0x046B, 0 };
UINT	CaseFoldingCS_CpList046C[]	= { 0x046D, 0 };
UINT	CaseFoldingCS_CpList046E[]	= { 0x046F, 0 };
UINT	CaseFoldingCS_CpList0470[]	= { 0x0471, 0 };
UINT	CaseFoldingCS_CpList0472[]	= { 0x0473, 0 };
UINT	CaseFoldingCS_CpList0474[]	= { 0x0475, 0 };
UINT	CaseFoldingCS_CpList0476[]	= { 0x0477, 0 };
UINT	CaseFoldingCS_CpList0478[]	= { 0x0479, 0 };
UINT	CaseFoldingCS_CpList047A[]	= { 0x047B, 0 };
UINT	CaseFoldingCS_CpList047C[]	= { 0x047D, 0 };
UINT	CaseFoldingCS_CpList047E[]	= { 0x047F, 0 };
UINT	CaseFoldingCS_CpList0480[]	= { 0x0481, 0 };
UINT	CaseFoldingCS_CpList048A[]	= { 0x048B, 0 };
UINT	CaseFoldingCS_CpList048C[]	= { 0x048D, 0 };
UINT	CaseFoldingCS_CpList048E[]	= { 0x048F, 0 };
UINT	CaseFoldingCS_CpList0490[]	= { 0x0491, 0 };
UINT	CaseFoldingCS_CpList0492[]	= { 0x0493, 0 };
UINT	CaseFoldingCS_CpList0494[]	= { 0x0495, 0 };
UINT	CaseFoldingCS_CpList0496[]	= { 0x0497, 0 };
UINT	CaseFoldingCS_CpList0498[]	= { 0x0499, 0 };
UINT	CaseFoldingCS_CpList049A[]	= { 0x049B, 0 };
UINT	CaseFoldingCS_CpList049C[]	= { 0x049D, 0 };
UINT	CaseFoldingCS_CpList049E[]	= { 0x049F, 0 };
UINT	CaseFoldingCS_CpList04A0[]	= { 0x04A1, 0 };
UINT	CaseFoldingCS_CpList04A2[]	= { 0x04A3, 0 };
UINT	CaseFoldingCS_CpList04A4[]	= { 0x04A5, 0 };
UINT	CaseFoldingCS_CpList04A6[]	= { 0x04A7, 0 };
UINT	CaseFoldingCS_CpList04A8[]	= { 0x04A9, 0 };
UINT	CaseFoldingCS_CpList04AA[]	= { 0x04AB, 0 };
UINT	CaseFoldingCS_CpList04AC[]	= { 0x04AD, 0 };
UINT	CaseFoldingCS_CpList04AE[]	= { 0x04AF, 0 };
UINT	CaseFoldingCS_CpList04B0[]	= { 0x04B1, 0 };
UINT	CaseFoldingCS_CpList04B2[]	= { 0x04B3, 0 };
UINT	CaseFoldingCS_CpList04B4[]	= { 0x04B5, 0 };
UINT	CaseFoldingCS_CpList04B6[]	= { 0x04B7, 0 };
UINT	CaseFoldingCS_CpList04B8[]	= { 0x04B9, 0 };
UINT	CaseFoldingCS_CpList04BA[]	= { 0x04BB, 0 };
UINT	CaseFoldingCS_CpList04BC[]	= { 0x04BD, 0 };
UINT	CaseFoldingCS_CpList04BE[]	= { 0x04BF, 0 };
UINT	CaseFoldingCS_CpList04C0[]	= { 0x04CF, 0 };
UINT	CaseFoldingCS_CpList04C1[]	= { 0x04C2, 0 };
UINT	CaseFoldingCS_CpList04C3[]	= { 0x04C4, 0 };
UINT	CaseFoldingCS_CpList04C5[]	= { 0x04C6, 0 };
UINT	CaseFoldingCS_CpList04C7[]	= { 0x04C8, 0 };
UINT	CaseFoldingCS_CpList04C9[]	= { 0x04CA, 0 };
UINT	CaseFoldingCS_CpList04CB[]	= { 0x04CC, 0 };
UINT	CaseFoldingCS_CpList04CD[]	= { 0x04CE, 0 };
UINT	CaseFoldingCS_CpList04D0[]	= { 0x04D1, 0 };
UINT	CaseFoldingCS_CpList04D2[]	= { 0x04D3, 0 };
UINT	CaseFoldingCS_CpList04D4[]	= { 0x04D5, 0 };
UINT	CaseFoldingCS_CpList04D6[]	= { 0x04D7, 0 };
UINT	CaseFoldingCS_CpList04D8[]	= { 0x04D9, 0 };
UINT	CaseFoldingCS_CpList04DA[]	= { 0x04DB, 0 };
UINT	CaseFoldingCS_CpList04DC[]	= { 0x04DD, 0 };
UINT	CaseFoldingCS_CpList04DE[]	= { 0x04DF, 0 };
UINT	CaseFoldingCS_CpList04E0[]	= { 0x04E1, 0 };
UINT	CaseFoldingCS_CpList04E2[]	= { 0x04E3, 0 };
UINT	CaseFoldingCS_CpList04E4[]	= { 0x04E5, 0 };
UINT	CaseFoldingCS_CpList04E6[]	= { 0x04E7, 0 };
UINT	CaseFoldingCS_CpList04E8[]	= { 0x04E9, 0 };
UINT	CaseFoldingCS_CpList04EA[]	= { 0x04EB, 0 };
UINT	CaseFoldingCS_CpList04EC[]	= { 0x04ED, 0 };
UINT	CaseFoldingCS_CpList04EE[]	= { 0x04EF, 0 };
UINT	CaseFoldingCS_CpList04F0[]	= { 0x04F1, 0 };
UINT	CaseFoldingCS_CpList04F2[]	= { 0x04F3, 0 };
UINT	CaseFoldingCS_CpList04F4[]	= { 0x04F5, 0 };
UINT	CaseFoldingCS_CpList04F6[]	= { 0x04F7, 0 };
UINT	CaseFoldingCS_CpList04F8[]	= { 0x04F9, 0 };
UINT	CaseFoldingCS_CpList04FA[]	= { 0x04FB, 0 };
UINT	CaseFoldingCS_CpList04FC[]	= { 0x04FD, 0 };
UINT	CaseFoldingCS_CpList04FE[]	= { 0x04FF, 0 };
UINT	CaseFoldingCS_CpList0500[]	= { 0x0501, 0 };
UINT	CaseFoldingCS_CpList0502[]	= { 0x0503, 0 };
UINT	CaseFoldingCS_CpList0504[]	= { 0x0505, 0 };
UINT	CaseFoldingCS_CpList0506[]	= { 0x0507, 0 };
UINT	CaseFoldingCS_CpList0508[]	= { 0x0509, 0 };
UINT	CaseFoldingCS_CpList050A[]	= { 0x050B, 0 };
UINT	CaseFoldingCS_CpList050C[]	= { 0x050D, 0 };
UINT	CaseFoldingCS_CpList050E[]	= { 0x050F, 0 };
UINT	CaseFoldingCS_CpList0510[]	= { 0x0511, 0 };
UINT	CaseFoldingCS_CpList0512[]	= { 0x0513, 0 };
UINT	CaseFoldingCS_CpList0514[]	= { 0x0515, 0 };
UINT	CaseFoldingCS_CpList0516[]	= { 0x0517, 0 };
UINT	CaseFoldingCS_CpList0518[]	= { 0x0519, 0 };
UINT	CaseFoldingCS_CpList051A[]	= { 0x051B, 0 };
UINT	CaseFoldingCS_CpList051C[]	= { 0x051D, 0 };
UINT	CaseFoldingCS_CpList051E[]	= { 0x051F, 0 };
UINT	CaseFoldingCS_CpList0520[]	= { 0x0521, 0 };
UINT	CaseFoldingCS_CpList0522[]	= { 0x0523, 0 };
UINT	CaseFoldingCS_CpList0524[]	= { 0x0525, 0 };
UINT	CaseFoldingCS_CpList0526[]	= { 0x0527, 0 };
UINT	CaseFoldingCS_CpList0531[]	= { 0x0561, 0 };
UINT	CaseFoldingCS_CpList0532[]	= { 0x0562, 0 };
UINT	CaseFoldingCS_CpList0533[]	= { 0x0563, 0 };
UINT	CaseFoldingCS_CpList0534[]	= { 0x0564, 0 };
UINT	CaseFoldingCS_CpList0535[]	= { 0x0565, 0 };
UINT	CaseFoldingCS_CpList0536[]	= { 0x0566, 0 };
UINT	CaseFoldingCS_CpList0537[]	= { 0x0567, 0 };
UINT	CaseFoldingCS_CpList0538[]	= { 0x0568, 0 };
UINT	CaseFoldingCS_CpList0539[]	= { 0x0569, 0 };
UINT	CaseFoldingCS_CpList053A[]	= { 0x056A, 0 };
UINT	CaseFoldingCS_CpList053B[]	= { 0x056B, 0 };
UINT	CaseFoldingCS_CpList053C[]	= { 0x056C, 0 };
UINT	CaseFoldingCS_CpList053D[]	= { 0x056D, 0 };
UINT	CaseFoldingCS_CpList053E[]	= { 0x056E, 0 };
UINT	CaseFoldingCS_CpList053F[]	= { 0x056F, 0 };
UINT	CaseFoldingCS_CpList0540[]	= { 0x0570, 0 };
UINT	CaseFoldingCS_CpList0541[]	= { 0x0571, 0 };
UINT	CaseFoldingCS_CpList0542[]	= { 0x0572, 0 };
UINT	CaseFoldingCS_CpList0543[]	= { 0x0573, 0 };
UINT	CaseFoldingCS_CpList0544[]	= { 0x0574, 0 };
UINT	CaseFoldingCS_CpList0545[]	= { 0x0575, 0 };
UINT	CaseFoldingCS_CpList0546[]	= { 0x0576, 0 };
UINT	CaseFoldingCS_CpList0547[]	= { 0x0577, 0 };
UINT	CaseFoldingCS_CpList0548[]	= { 0x0578, 0 };
UINT	CaseFoldingCS_CpList0549[]	= { 0x0579, 0 };
UINT	CaseFoldingCS_CpList054A[]	= { 0x057A, 0 };
UINT	CaseFoldingCS_CpList054B[]	= { 0x057B, 0 };
UINT	CaseFoldingCS_CpList054C[]	= { 0x057C, 0 };
UINT	CaseFoldingCS_CpList054D[]	= { 0x057D, 0 };
UINT	CaseFoldingCS_CpList054E[]	= { 0x057E, 0 };
UINT	CaseFoldingCS_CpList054F[]	= { 0x057F, 0 };
UINT	CaseFoldingCS_CpList0550[]	= { 0x0580, 0 };
UINT	CaseFoldingCS_CpList0551[]	= { 0x0581, 0 };
UINT	CaseFoldingCS_CpList0552[]	= { 0x0582, 0 };
UINT	CaseFoldingCS_CpList0553[]	= { 0x0583, 0 };
UINT	CaseFoldingCS_CpList0554[]	= { 0x0584, 0 };
UINT	CaseFoldingCS_CpList0555[]	= { 0x0585, 0 };
UINT	CaseFoldingCS_CpList0556[]	= { 0x0586, 0 };
UINT	CaseFoldingCS_CpList10A0[]	= { 0x2D00, 0 };
UINT	CaseFoldingCS_CpList10A1[]	= { 0x2D01, 0 };
UINT	CaseFoldingCS_CpList10A2[]	= { 0x2D02, 0 };
UINT	CaseFoldingCS_CpList10A3[]	= { 0x2D03, 0 };
UINT	CaseFoldingCS_CpList10A4[]	= { 0x2D04, 0 };
UINT	CaseFoldingCS_CpList10A5[]	= { 0x2D05, 0 };
UINT	CaseFoldingCS_CpList10A6[]	= { 0x2D06, 0 };
UINT	CaseFoldingCS_CpList10A7[]	= { 0x2D07, 0 };
UINT	CaseFoldingCS_CpList10A8[]	= { 0x2D08, 0 };
UINT	CaseFoldingCS_CpList10A9[]	= { 0x2D09, 0 };
UINT	CaseFoldingCS_CpList10AA[]	= { 0x2D0A, 0 };
UINT	CaseFoldingCS_CpList10AB[]	= { 0x2D0B, 0 };
UINT	CaseFoldingCS_CpList10AC[]	= { 0x2D0C, 0 };
UINT	CaseFoldingCS_CpList10AD[]	= { 0x2D0D, 0 };
UINT	CaseFoldingCS_CpList10AE[]	= { 0x2D0E, 0 };
UINT	CaseFoldingCS_CpList10AF[]	= { 0x2D0F, 0 };
UINT	CaseFoldingCS_CpList10B0[]	= { 0x2D10, 0 };
UINT	CaseFoldingCS_CpList10B1[]	= { 0x2D11, 0 };
UINT	CaseFoldingCS_CpList10B2[]	= { 0x2D12, 0 };
UINT	CaseFoldingCS_CpList10B3[]	= { 0x2D13, 0 };
UINT	CaseFoldingCS_CpList10B4[]	= { 0x2D14, 0 };
UINT	CaseFoldingCS_CpList10B5[]	= { 0x2D15, 0 };
UINT	CaseFoldingCS_CpList10B6[]	= { 0x2D16, 0 };
UINT	CaseFoldingCS_CpList10B7[]	= { 0x2D17, 0 };
UINT	CaseFoldingCS_CpList10B8[]	= { 0x2D18, 0 };
UINT	CaseFoldingCS_CpList10B9[]	= { 0x2D19, 0 };
UINT	CaseFoldingCS_CpList10BA[]	= { 0x2D1A, 0 };
UINT	CaseFoldingCS_CpList10BB[]	= { 0x2D1B, 0 };
UINT	CaseFoldingCS_CpList10BC[]	= { 0x2D1C, 0 };
UINT	CaseFoldingCS_CpList10BD[]	= { 0x2D1D, 0 };
UINT	CaseFoldingCS_CpList10BE[]	= { 0x2D1E, 0 };
UINT	CaseFoldingCS_CpList10BF[]	= { 0x2D1F, 0 };
UINT	CaseFoldingCS_CpList10C0[]	= { 0x2D20, 0 };
UINT	CaseFoldingCS_CpList10C1[]	= { 0x2D21, 0 };
UINT	CaseFoldingCS_CpList10C2[]	= { 0x2D22, 0 };
UINT	CaseFoldingCS_CpList10C3[]	= { 0x2D23, 0 };
UINT	CaseFoldingCS_CpList10C4[]	= { 0x2D24, 0 };
UINT	CaseFoldingCS_CpList10C5[]	= { 0x2D25, 0 };
UINT	CaseFoldingCS_CpList10C7[]	= { 0x2D27, 0 };
UINT	CaseFoldingCS_CpList10CD[]	= { 0x2D2D, 0 };
UINT	CaseFoldingCS_CpList1E00[]	= { 0x1E01, 0 };
UINT	CaseFoldingCS_CpList1E02[]	= { 0x1E03, 0 };
UINT	CaseFoldingCS_CpList1E04[]	= { 0x1E05, 0 };
UINT	CaseFoldingCS_CpList1E06[]	= { 0x1E07, 0 };
UINT	CaseFoldingCS_CpList1E08[]	= { 0x1E09, 0 };
UINT	CaseFoldingCS_CpList1E0A[]	= { 0x1E0B, 0 };
UINT	CaseFoldingCS_CpList1E0C[]	= { 0x1E0D, 0 };
UINT	CaseFoldingCS_CpList1E0E[]	= { 0x1E0F, 0 };
UINT	CaseFoldingCS_CpList1E10[]	= { 0x1E11, 0 };
UINT	CaseFoldingCS_CpList1E12[]	= { 0x1E13, 0 };
UINT	CaseFoldingCS_CpList1E14[]	= { 0x1E15, 0 };
UINT	CaseFoldingCS_CpList1E16[]	= { 0x1E17, 0 };
UINT	CaseFoldingCS_CpList1E18[]	= { 0x1E19, 0 };
UINT	CaseFoldingCS_CpList1E1A[]	= { 0x1E1B, 0 };
UINT	CaseFoldingCS_CpList1E1C[]	= { 0x1E1D, 0 };
UINT	CaseFoldingCS_CpList1E1E[]	= { 0x1E1F, 0 };
UINT	CaseFoldingCS_CpList1E20[]	= { 0x1E21, 0 };
UINT	CaseFoldingCS_CpList1E22[]	= { 0x1E23, 0 };
UINT	CaseFoldingCS_CpList1E24[]	= { 0x1E25, 0 };
UINT	CaseFoldingCS_CpList1E26[]	= { 0x1E27, 0 };
UINT	CaseFoldingCS_CpList1E28[]	= { 0x1E29, 0 };
UINT	CaseFoldingCS_CpList1E2A[]	= { 0x1E2B, 0 };
UINT	CaseFoldingCS_CpList1E2C[]	= { 0x1E2D, 0 };
UINT	CaseFoldingCS_CpList1E2E[]	= { 0x1E2F, 0 };
UINT	CaseFoldingCS_CpList1E30[]	= { 0x1E31, 0 };
UINT	CaseFoldingCS_CpList1E32[]	= { 0x1E33, 0 };
UINT	CaseFoldingCS_CpList1E34[]	= { 0x1E35, 0 };
UINT	CaseFoldingCS_CpList1E36[]	= { 0x1E37, 0 };
UINT	CaseFoldingCS_CpList1E38[]	= { 0x1E39, 0 };
UINT	CaseFoldingCS_CpList1E3A[]	= { 0x1E3B, 0 };
UINT	CaseFoldingCS_CpList1E3C[]	= { 0x1E3D, 0 };
UINT	CaseFoldingCS_CpList1E3E[]	= { 0x1E3F, 0 };
UINT	CaseFoldingCS_CpList1E40[]	= { 0x1E41, 0 };
UINT	CaseFoldingCS_CpList1E42[]	= { 0x1E43, 0 };
UINT	CaseFoldingCS_CpList1E44[]	= { 0x1E45, 0 };
UINT	CaseFoldingCS_CpList1E46[]	= { 0x1E47, 0 };
UINT	CaseFoldingCS_CpList1E48[]	= { 0x1E49, 0 };
UINT	CaseFoldingCS_CpList1E4A[]	= { 0x1E4B, 0 };
UINT	CaseFoldingCS_CpList1E4C[]	= { 0x1E4D, 0 };
UINT	CaseFoldingCS_CpList1E4E[]	= { 0x1E4F, 0 };
UINT	CaseFoldingCS_CpList1E50[]	= { 0x1E51, 0 };
UINT	CaseFoldingCS_CpList1E52[]	= { 0x1E53, 0 };
UINT	CaseFoldingCS_CpList1E54[]	= { 0x1E55, 0 };
UINT	CaseFoldingCS_CpList1E56[]	= { 0x1E57, 0 };
UINT	CaseFoldingCS_CpList1E58[]	= { 0x1E59, 0 };
UINT	CaseFoldingCS_CpList1E5A[]	= { 0x1E5B, 0 };
UINT	CaseFoldingCS_CpList1E5C[]	= { 0x1E5D, 0 };
UINT	CaseFoldingCS_CpList1E5E[]	= { 0x1E5F, 0 };
UINT	CaseFoldingCS_CpList1E60[]	= { 0x1E61, 0 };
UINT	CaseFoldingCS_CpList1E62[]	= { 0x1E63, 0 };
UINT	CaseFoldingCS_CpList1E64[]	= { 0x1E65, 0 };
UINT	CaseFoldingCS_CpList1E66[]	= { 0x1E67, 0 };
UINT	CaseFoldingCS_CpList1E68[]	= { 0x1E69, 0 };
UINT	CaseFoldingCS_CpList1E6A[]	= { 0x1E6B, 0 };
UINT	CaseFoldingCS_CpList1E6C[]	= { 0x1E6D, 0 };
UINT	CaseFoldingCS_CpList1E6E[]	= { 0x1E6F, 0 };
UINT	CaseFoldingCS_CpList1E70[]	= { 0x1E71, 0 };
UINT	CaseFoldingCS_CpList1E72[]	= { 0x1E73, 0 };
UINT	CaseFoldingCS_CpList1E74[]	= { 0x1E75, 0 };
UINT	CaseFoldingCS_CpList1E76[]	= { 0x1E77, 0 };
UINT	CaseFoldingCS_CpList1E78[]	= { 0x1E79, 0 };
UINT	CaseFoldingCS_CpList1E7A[]	= { 0x1E7B, 0 };
UINT	CaseFoldingCS_CpList1E7C[]	= { 0x1E7D, 0 };
UINT	CaseFoldingCS_CpList1E7E[]	= { 0x1E7F, 0 };
UINT	CaseFoldingCS_CpList1E80[]	= { 0x1E81, 0 };
UINT	CaseFoldingCS_CpList1E82[]	= { 0x1E83, 0 };
UINT	CaseFoldingCS_CpList1E84[]	= { 0x1E85, 0 };
UINT	CaseFoldingCS_CpList1E86[]	= { 0x1E87, 0 };
UINT	CaseFoldingCS_CpList1E88[]	= { 0x1E89, 0 };
UINT	CaseFoldingCS_CpList1E8A[]	= { 0x1E8B, 0 };
UINT	CaseFoldingCS_CpList1E8C[]	= { 0x1E8D, 0 };
UINT	CaseFoldingCS_CpList1E8E[]	= { 0x1E8F, 0 };
UINT	CaseFoldingCS_CpList1E90[]	= { 0x1E91, 0 };
UINT	CaseFoldingCS_CpList1E92[]	= { 0x1E93, 0 };
UINT	CaseFoldingCS_CpList1E94[]	= { 0x1E95, 0 };
UINT	CaseFoldingCS_CpList1E9B[]	= { 0x1E61, 0 };
UINT	CaseFoldingCS_CpList1E9E[]	= { 0x00DF, 0 };
UINT	CaseFoldingCS_CpList1EA0[]	= { 0x1EA1, 0 };
UINT	CaseFoldingCS_CpList1EA2[]	= { 0x1EA3, 0 };
UINT	CaseFoldingCS_CpList1EA4[]	= { 0x1EA5, 0 };
UINT	CaseFoldingCS_CpList1EA6[]	= { 0x1EA7, 0 };
UINT	CaseFoldingCS_CpList1EA8[]	= { 0x1EA9, 0 };
UINT	CaseFoldingCS_CpList1EAA[]	= { 0x1EAB, 0 };
UINT	CaseFoldingCS_CpList1EAC[]	= { 0x1EAD, 0 };
UINT	CaseFoldingCS_CpList1EAE[]	= { 0x1EAF, 0 };
UINT	CaseFoldingCS_CpList1EB0[]	= { 0x1EB1, 0 };
UINT	CaseFoldingCS_CpList1EB2[]	= { 0x1EB3, 0 };
UINT	CaseFoldingCS_CpList1EB4[]	= { 0x1EB5, 0 };
UINT	CaseFoldingCS_CpList1EB6[]	= { 0x1EB7, 0 };
UINT	CaseFoldingCS_CpList1EB8[]	= { 0x1EB9, 0 };
UINT	CaseFoldingCS_CpList1EBA[]	= { 0x1EBB, 0 };
UINT	CaseFoldingCS_CpList1EBC[]	= { 0x1EBD, 0 };
UINT	CaseFoldingCS_CpList1EBE[]	= { 0x1EBF, 0 };
UINT	CaseFoldingCS_CpList1EC0[]	= { 0x1EC1, 0 };
UINT	CaseFoldingCS_CpList1EC2[]	= { 0x1EC3, 0 };
UINT	CaseFoldingCS_CpList1EC4[]	= { 0x1EC5, 0 };
UINT	CaseFoldingCS_CpList1EC6[]	= { 0x1EC7, 0 };
UINT	CaseFoldingCS_CpList1EC8[]	= { 0x1EC9, 0 };
UINT	CaseFoldingCS_CpList1ECA[]	= { 0x1ECB, 0 };
UINT	CaseFoldingCS_CpList1ECC[]	= { 0x1ECD, 0 };
UINT	CaseFoldingCS_CpList1ECE[]	= { 0x1ECF, 0 };
UINT	CaseFoldingCS_CpList1ED0[]	= { 0x1ED1, 0 };
UINT	CaseFoldingCS_CpList1ED2[]	= { 0x1ED3, 0 };
UINT	CaseFoldingCS_CpList1ED4[]	= { 0x1ED5, 0 };
UINT	CaseFoldingCS_CpList1ED6[]	= { 0x1ED7, 0 };
UINT	CaseFoldingCS_CpList1ED8[]	= { 0x1ED9, 0 };
UINT	CaseFoldingCS_CpList1EDA[]	= { 0x1EDB, 0 };
UINT	CaseFoldingCS_CpList1EDC[]	= { 0x1EDD, 0 };
UINT	CaseFoldingCS_CpList1EDE[]	= { 0x1EDF, 0 };
UINT	CaseFoldingCS_CpList1EE0[]	= { 0x1EE1, 0 };
UINT	CaseFoldingCS_CpList1EE2[]	= { 0x1EE3, 0 };
UINT	CaseFoldingCS_CpList1EE4[]	= { 0x1EE5, 0 };
UINT	CaseFoldingCS_CpList1EE6[]	= { 0x1EE7, 0 };
UINT	CaseFoldingCS_CpList1EE8[]	= { 0x1EE9, 0 };
UINT	CaseFoldingCS_CpList1EEA[]	= { 0x1EEB, 0 };
UINT	CaseFoldingCS_CpList1EEC[]	= { 0x1EED, 0 };
UINT	CaseFoldingCS_CpList1EEE[]	= { 0x1EEF, 0 };
UINT	CaseFoldingCS_CpList1EF0[]	= { 0x1EF1, 0 };
UINT	CaseFoldingCS_CpList1EF2[]	= { 0x1EF3, 0 };
UINT	CaseFoldingCS_CpList1EF4[]	= { 0x1EF5, 0 };
UINT	CaseFoldingCS_CpList1EF6[]	= { 0x1EF7, 0 };
UINT	CaseFoldingCS_CpList1EF8[]	= { 0x1EF9, 0 };
UINT	CaseFoldingCS_CpList1EFA[]	= { 0x1EFB, 0 };
UINT	CaseFoldingCS_CpList1EFC[]	= { 0x1EFD, 0 };
UINT	CaseFoldingCS_CpList1EFE[]	= { 0x1EFF, 0 };
UINT	CaseFoldingCS_CpList1F08[]	= { 0x1F00, 0 };
UINT	CaseFoldingCS_CpList1F09[]	= { 0x1F01, 0 };
UINT	CaseFoldingCS_CpList1F0A[]	= { 0x1F02, 0 };
UINT	CaseFoldingCS_CpList1F0B[]	= { 0x1F03, 0 };
UINT	CaseFoldingCS_CpList1F0C[]	= { 0x1F04, 0 };
UINT	CaseFoldingCS_CpList1F0D[]	= { 0x1F05, 0 };
UINT	CaseFoldingCS_CpList1F0E[]	= { 0x1F06, 0 };
UINT	CaseFoldingCS_CpList1F0F[]	= { 0x1F07, 0 };
UINT	CaseFoldingCS_CpList1F18[]	= { 0x1F10, 0 };
UINT	CaseFoldingCS_CpList1F19[]	= { 0x1F11, 0 };
UINT	CaseFoldingCS_CpList1F1A[]	= { 0x1F12, 0 };
UINT	CaseFoldingCS_CpList1F1B[]	= { 0x1F13, 0 };
UINT	CaseFoldingCS_CpList1F1C[]	= { 0x1F14, 0 };
UINT	CaseFoldingCS_CpList1F1D[]	= { 0x1F15, 0 };
UINT	CaseFoldingCS_CpList1F28[]	= { 0x1F20, 0 };
UINT	CaseFoldingCS_CpList1F29[]	= { 0x1F21, 0 };
UINT	CaseFoldingCS_CpList1F2A[]	= { 0x1F22, 0 };
UINT	CaseFoldingCS_CpList1F2B[]	= { 0x1F23, 0 };
UINT	CaseFoldingCS_CpList1F2C[]	= { 0x1F24, 0 };
UINT	CaseFoldingCS_CpList1F2D[]	= { 0x1F25, 0 };
UINT	CaseFoldingCS_CpList1F2E[]	= { 0x1F26, 0 };
UINT	CaseFoldingCS_CpList1F2F[]	= { 0x1F27, 0 };
UINT	CaseFoldingCS_CpList1F38[]	= { 0x1F30, 0 };
UINT	CaseFoldingCS_CpList1F39[]	= { 0x1F31, 0 };
UINT	CaseFoldingCS_CpList1F3A[]	= { 0x1F32, 0 };
UINT	CaseFoldingCS_CpList1F3B[]	= { 0x1F33, 0 };
UINT	CaseFoldingCS_CpList1F3C[]	= { 0x1F34, 0 };
UINT	CaseFoldingCS_CpList1F3D[]	= { 0x1F35, 0 };
UINT	CaseFoldingCS_CpList1F3E[]	= { 0x1F36, 0 };
UINT	CaseFoldingCS_CpList1F3F[]	= { 0x1F37, 0 };
UINT	CaseFoldingCS_CpList1F48[]	= { 0x1F40, 0 };
UINT	CaseFoldingCS_CpList1F49[]	= { 0x1F41, 0 };
UINT	CaseFoldingCS_CpList1F4A[]	= { 0x1F42, 0 };
UINT	CaseFoldingCS_CpList1F4B[]	= { 0x1F43, 0 };
UINT	CaseFoldingCS_CpList1F4C[]	= { 0x1F44, 0 };
UINT	CaseFoldingCS_CpList1F4D[]	= { 0x1F45, 0 };
UINT	CaseFoldingCS_CpList1F59[]	= { 0x1F51, 0 };
UINT	CaseFoldingCS_CpList1F5B[]	= { 0x1F53, 0 };
UINT	CaseFoldingCS_CpList1F5D[]	= { 0x1F55, 0 };
UINT	CaseFoldingCS_CpList1F5F[]	= { 0x1F57, 0 };
UINT	CaseFoldingCS_CpList1F68[]	= { 0x1F60, 0 };
UINT	CaseFoldingCS_CpList1F69[]	= { 0x1F61, 0 };
UINT	CaseFoldingCS_CpList1F6A[]	= { 0x1F62, 0 };
UINT	CaseFoldingCS_CpList1F6B[]	= { 0x1F63, 0 };
UINT	CaseFoldingCS_CpList1F6C[]	= { 0x1F64, 0 };
UINT	CaseFoldingCS_CpList1F6D[]	= { 0x1F65, 0 };
UINT	CaseFoldingCS_CpList1F6E[]	= { 0x1F66, 0 };
UINT	CaseFoldingCS_CpList1F6F[]	= { 0x1F67, 0 };
UINT	CaseFoldingCS_CpList1F88[]	= { 0x1F80, 0 };
UINT	CaseFoldingCS_CpList1F89[]	= { 0x1F81, 0 };
UINT	CaseFoldingCS_CpList1F8A[]	= { 0x1F82, 0 };
UINT	CaseFoldingCS_CpList1F8B[]	= { 0x1F83, 0 };
UINT	CaseFoldingCS_CpList1F8C[]	= { 0x1F84, 0 };
UINT	CaseFoldingCS_CpList1F8D[]	= { 0x1F85, 0 };
UINT	CaseFoldingCS_CpList1F8E[]	= { 0x1F86, 0 };
UINT	CaseFoldingCS_CpList1F8F[]	= { 0x1F87, 0 };
UINT	CaseFoldingCS_CpList1F98[]	= { 0x1F90, 0 };
UINT	CaseFoldingCS_CpList1F99[]	= { 0x1F91, 0 };
UINT	CaseFoldingCS_CpList1F9A[]	= { 0x1F92, 0 };
UINT	CaseFoldingCS_CpList1F9B[]	= { 0x1F93, 0 };
UINT	CaseFoldingCS_CpList1F9C[]	= { 0x1F94, 0 };
UINT	CaseFoldingCS_CpList1F9D[]	= { 0x1F95, 0 };
UINT	CaseFoldingCS_CpList1F9E[]	= { 0x1F96, 0 };
UINT	CaseFoldingCS_CpList1F9F[]	= { 0x1F97, 0 };
UINT	CaseFoldingCS_CpList1FA8[]	= { 0x1FA0, 0 };
UINT	CaseFoldingCS_CpList1FA9[]	= { 0x1FA1, 0 };
UINT	CaseFoldingCS_CpList1FAA[]	= { 0x1FA2, 0 };
UINT	CaseFoldingCS_CpList1FAB[]	= { 0x1FA3, 0 };
UINT	CaseFoldingCS_CpList1FAC[]	= { 0x1FA4, 0 };
UINT	CaseFoldingCS_CpList1FAD[]	= { 0x1FA5, 0 };
UINT	CaseFoldingCS_CpList1FAE[]	= { 0x1FA6, 0 };
UINT	CaseFoldingCS_CpList1FAF[]	= { 0x1FA7, 0 };
UINT	CaseFoldingCS_CpList1FB8[]	= { 0x1FB0, 0 };
UINT	CaseFoldingCS_CpList1FB9[]	= { 0x1FB1, 0 };
UINT	CaseFoldingCS_CpList1FBA[]	= { 0x1F70, 0 };
UINT	CaseFoldingCS_CpList1FBB[]	= { 0x1F71, 0 };
UINT	CaseFoldingCS_CpList1FBC[]	= { 0x1FB3, 0 };
UINT	CaseFoldingCS_CpList1FBE[]	= { 0x03B9, 0 };
UINT	CaseFoldingCS_CpList1FC8[]	= { 0x1F72, 0 };
UINT	CaseFoldingCS_CpList1FC9[]	= { 0x1F73, 0 };
UINT	CaseFoldingCS_CpList1FCA[]	= { 0x1F74, 0 };
UINT	CaseFoldingCS_CpList1FCB[]	= { 0x1F75, 0 };
UINT	CaseFoldingCS_CpList1FCC[]	= { 0x1FC3, 0 };
UINT	CaseFoldingCS_CpList1FD8[]	= { 0x1FD0, 0 };
UINT	CaseFoldingCS_CpList1FD9[]	= { 0x1FD1, 0 };
UINT	CaseFoldingCS_CpList1FDA[]	= { 0x1F76, 0 };
UINT	CaseFoldingCS_CpList1FDB[]	= { 0x1F77, 0 };
UINT	CaseFoldingCS_CpList1FE8[]	= { 0x1FE0, 0 };
UINT	CaseFoldingCS_CpList1FE9[]	= { 0x1FE1, 0 };
UINT	CaseFoldingCS_CpList1FEA[]	= { 0x1F7A, 0 };
UINT	CaseFoldingCS_CpList1FEB[]	= { 0x1F7B, 0 };
UINT	CaseFoldingCS_CpList1FEC[]	= { 0x1FE5, 0 };
UINT	CaseFoldingCS_CpList1FF8[]	= { 0x1F78, 0 };
UINT	CaseFoldingCS_CpList1FF9[]	= { 0x1F79, 0 };
UINT	CaseFoldingCS_CpList1FFA[]	= { 0x1F7C, 0 };
UINT	CaseFoldingCS_CpList1FFB[]	= { 0x1F7D, 0 };
UINT	CaseFoldingCS_CpList1FFC[]	= { 0x1FF3, 0 };
UINT	CaseFoldingCS_CpList2126[]	= { 0x03C9, 0 };
UINT	CaseFoldingCS_CpList212A[]	= { 0x006B, 0 };
UINT	CaseFoldingCS_CpList212B[]	= { 0x00E5, 0 };
UINT	CaseFoldingCS_CpList2132[]	= { 0x214E, 0 };
UINT	CaseFoldingCS_CpList2160[]	= { 0x2170, 0 };
UINT	CaseFoldingCS_CpList2161[]	= { 0x2171, 0 };
UINT	CaseFoldingCS_CpList2162[]	= { 0x2172, 0 };
UINT	CaseFoldingCS_CpList2163[]	= { 0x2173, 0 };
UINT	CaseFoldingCS_CpList2164[]	= { 0x2174, 0 };
UINT	CaseFoldingCS_CpList2165[]	= { 0x2175, 0 };
UINT	CaseFoldingCS_CpList2166[]	= { 0x2176, 0 };
UINT	CaseFoldingCS_CpList2167[]	= { 0x2177, 0 };
UINT	CaseFoldingCS_CpList2168[]	= { 0x2178, 0 };
UINT	CaseFoldingCS_CpList2169[]	= { 0x2179, 0 };
UINT	CaseFoldingCS_CpList216A[]	= { 0x217A, 0 };
UINT	CaseFoldingCS_CpList216B[]	= { 0x217B, 0 };
UINT	CaseFoldingCS_CpList216C[]	= { 0x217C, 0 };
UINT	CaseFoldingCS_CpList216D[]	= { 0x217D, 0 };
UINT	CaseFoldingCS_CpList216E[]	= { 0x217E, 0 };
UINT	CaseFoldingCS_CpList216F[]	= { 0x217F, 0 };
UINT	CaseFoldingCS_CpList2183[]	= { 0x2184, 0 };
UINT	CaseFoldingCS_CpList24B6[]	= { 0x24D0, 0 };
UINT	CaseFoldingCS_CpList24B7[]	= { 0x24D1, 0 };
UINT	CaseFoldingCS_CpList24B8[]	= { 0x24D2, 0 };
UINT	CaseFoldingCS_CpList24B9[]	= { 0x24D3, 0 };
UINT	CaseFoldingCS_CpList24BA[]	= { 0x24D4, 0 };
UINT	CaseFoldingCS_CpList24BB[]	= { 0x24D5, 0 };
UINT	CaseFoldingCS_CpList24BC[]	= { 0x24D6, 0 };
UINT	CaseFoldingCS_CpList24BD[]	= { 0x24D7, 0 };
UINT	CaseFoldingCS_CpList24BE[]	= { 0x24D8, 0 };
UINT	CaseFoldingCS_CpList24BF[]	= { 0x24D9, 0 };
UINT	CaseFoldingCS_CpList24C0[]	= { 0x24DA, 0 };
UINT	CaseFoldingCS_CpList24C1[]	= { 0x24DB, 0 };
UINT	CaseFoldingCS_CpList24C2[]	= { 0x24DC, 0 };
UINT	CaseFoldingCS_CpList24C3[]	= { 0x24DD, 0 };
UINT	CaseFoldingCS_CpList24C4[]	= { 0x24DE, 0 };
UINT	CaseFoldingCS_CpList24C5[]	= { 0x24DF, 0 };
UINT	CaseFoldingCS_CpList24C6[]	= { 0x24E0, 0 };
UINT	CaseFoldingCS_CpList24C7[]	= { 0x24E1, 0 };
UINT	CaseFoldingCS_CpList24C8[]	= { 0x24E2, 0 };
UINT	CaseFoldingCS_CpList24C9[]	= { 0x24E3, 0 };
UINT	CaseFoldingCS_CpList24CA[]	= { 0x24E4, 0 };
UINT	CaseFoldingCS_CpList24CB[]	= { 0x24E5, 0 };
UINT	CaseFoldingCS_CpList24CC[]	= { 0x24E6, 0 };
UINT	CaseFoldingCS_CpList24CD[]	= { 0x24E7, 0 };
UINT	CaseFoldingCS_CpList24CE[]	= { 0x24E8, 0 };
UINT	CaseFoldingCS_CpList24CF[]	= { 0x24E9, 0 };
UINT	CaseFoldingCS_CpList2C00[]	= { 0x2C30, 0 };
UINT	CaseFoldingCS_CpList2C01[]	= { 0x2C31, 0 };
UINT	CaseFoldingCS_CpList2C02[]	= { 0x2C32, 0 };
UINT	CaseFoldingCS_CpList2C03[]	= { 0x2C33, 0 };
UINT	CaseFoldingCS_CpList2C04[]	= { 0x2C34, 0 };
UINT	CaseFoldingCS_CpList2C05[]	= { 0x2C35, 0 };
UINT	CaseFoldingCS_CpList2C06[]	= { 0x2C36, 0 };
UINT	CaseFoldingCS_CpList2C07[]	= { 0x2C37, 0 };
UINT	CaseFoldingCS_CpList2C08[]	= { 0x2C38, 0 };
UINT	CaseFoldingCS_CpList2C09[]	= { 0x2C39, 0 };
UINT	CaseFoldingCS_CpList2C0A[]	= { 0x2C3A, 0 };
UINT	CaseFoldingCS_CpList2C0B[]	= { 0x2C3B, 0 };
UINT	CaseFoldingCS_CpList2C0C[]	= { 0x2C3C, 0 };
UINT	CaseFoldingCS_CpList2C0D[]	= { 0x2C3D, 0 };
UINT	CaseFoldingCS_CpList2C0E[]	= { 0x2C3E, 0 };
UINT	CaseFoldingCS_CpList2C0F[]	= { 0x2C3F, 0 };
UINT	CaseFoldingCS_CpList2C10[]	= { 0x2C40, 0 };
UINT	CaseFoldingCS_CpList2C11[]	= { 0x2C41, 0 };
UINT	CaseFoldingCS_CpList2C12[]	= { 0x2C42, 0 };
UINT	CaseFoldingCS_CpList2C13[]	= { 0x2C43, 0 };
UINT	CaseFoldingCS_CpList2C14[]	= { 0x2C44, 0 };
UINT	CaseFoldingCS_CpList2C15[]	= { 0x2C45, 0 };
UINT	CaseFoldingCS_CpList2C16[]	= { 0x2C46, 0 };
UINT	CaseFoldingCS_CpList2C17[]	= { 0x2C47, 0 };
UINT	CaseFoldingCS_CpList2C18[]	= { 0x2C48, 0 };
UINT	CaseFoldingCS_CpList2C19[]	= { 0x2C49, 0 };
UINT	CaseFoldingCS_CpList2C1A[]	= { 0x2C4A, 0 };
UINT	CaseFoldingCS_CpList2C1B[]	= { 0x2C4B, 0 };
UINT	CaseFoldingCS_CpList2C1C[]	= { 0x2C4C, 0 };
UINT	CaseFoldingCS_CpList2C1D[]	= { 0x2C4D, 0 };
UINT	CaseFoldingCS_CpList2C1E[]	= { 0x2C4E, 0 };
UINT	CaseFoldingCS_CpList2C1F[]	= { 0x2C4F, 0 };
UINT	CaseFoldingCS_CpList2C20[]	= { 0x2C50, 0 };
UINT	CaseFoldingCS_CpList2C21[]	= { 0x2C51, 0 };
UINT	CaseFoldingCS_CpList2C22[]	= { 0x2C52, 0 };
UINT	CaseFoldingCS_CpList2C23[]	= { 0x2C53, 0 };
UINT	CaseFoldingCS_CpList2C24[]	= { 0x2C54, 0 };
UINT	CaseFoldingCS_CpList2C25[]	= { 0x2C55, 0 };
UINT	CaseFoldingCS_CpList2C26[]	= { 0x2C56, 0 };
UINT	CaseFoldingCS_CpList2C27[]	= { 0x2C57, 0 };
UINT	CaseFoldingCS_CpList2C28[]	= { 0x2C58, 0 };
UINT	CaseFoldingCS_CpList2C29[]	= { 0x2C59, 0 };
UINT	CaseFoldingCS_CpList2C2A[]	= { 0x2C5A, 0 };
UINT	CaseFoldingCS_CpList2C2B[]	= { 0x2C5B, 0 };
UINT	CaseFoldingCS_CpList2C2C[]	= { 0x2C5C, 0 };
UINT	CaseFoldingCS_CpList2C2D[]	= { 0x2C5D, 0 };
UINT	CaseFoldingCS_CpList2C2E[]	= { 0x2C5E, 0 };
UINT	CaseFoldingCS_CpList2C60[]	= { 0x2C61, 0 };
UINT	CaseFoldingCS_CpList2C62[]	= { 0x026B, 0 };
UINT	CaseFoldingCS_CpList2C63[]	= { 0x1D7D, 0 };
UINT	CaseFoldingCS_CpList2C64[]	= { 0x027D, 0 };
UINT	CaseFoldingCS_CpList2C67[]	= { 0x2C68, 0 };
UINT	CaseFoldingCS_CpList2C69[]	= { 0x2C6A, 0 };
UINT	CaseFoldingCS_CpList2C6B[]	= { 0x2C6C, 0 };
UINT	CaseFoldingCS_CpList2C6D[]	= { 0x0251, 0 };
UINT	CaseFoldingCS_CpList2C6E[]	= { 0x0271, 0 };
UINT	CaseFoldingCS_CpList2C6F[]	= { 0x0250, 0 };
UINT	CaseFoldingCS_CpList2C70[]	= { 0x0252, 0 };
UINT	CaseFoldingCS_CpList2C72[]	= { 0x2C73, 0 };
UINT	CaseFoldingCS_CpList2C75[]	= { 0x2C76, 0 };
UINT	CaseFoldingCS_CpList2C7E[]	= { 0x023F, 0 };
UINT	CaseFoldingCS_CpList2C7F[]	= { 0x0240, 0 };
UINT	CaseFoldingCS_CpList2C80[]	= { 0x2C81, 0 };
UINT	CaseFoldingCS_CpList2C82[]	= { 0x2C83, 0 };
UINT	CaseFoldingCS_CpList2C84[]	= { 0x2C85, 0 };
UINT	CaseFoldingCS_CpList2C86[]	= { 0x2C87, 0 };
UINT	CaseFoldingCS_CpList2C88[]	= { 0x2C89, 0 };
UINT	CaseFoldingCS_CpList2C8A[]	= { 0x2C8B, 0 };
UINT	CaseFoldingCS_CpList2C8C[]	= { 0x2C8D, 0 };
UINT	CaseFoldingCS_CpList2C8E[]	= { 0x2C8F, 0 };
UINT	CaseFoldingCS_CpList2C90[]	= { 0x2C91, 0 };
UINT	CaseFoldingCS_CpList2C92[]	= { 0x2C93, 0 };
UINT	CaseFoldingCS_CpList2C94[]	= { 0x2C95, 0 };
UINT	CaseFoldingCS_CpList2C96[]	= { 0x2C97, 0 };
UINT	CaseFoldingCS_CpList2C98[]	= { 0x2C99, 0 };
UINT	CaseFoldingCS_CpList2C9A[]	= { 0x2C9B, 0 };
UINT	CaseFoldingCS_CpList2C9C[]	= { 0x2C9D, 0 };
UINT	CaseFoldingCS_CpList2C9E[]	= { 0x2C9F, 0 };
UINT	CaseFoldingCS_CpList2CA0[]	= { 0x2CA1, 0 };
UINT	CaseFoldingCS_CpList2CA2[]	= { 0x2CA3, 0 };
UINT	CaseFoldingCS_CpList2CA4[]	= { 0x2CA5, 0 };
UINT	CaseFoldingCS_CpList2CA6[]	= { 0x2CA7, 0 };
UINT	CaseFoldingCS_CpList2CA8[]	= { 0x2CA9, 0 };
UINT	CaseFoldingCS_CpList2CAA[]	= { 0x2CAB, 0 };
UINT	CaseFoldingCS_CpList2CAC[]	= { 0x2CAD, 0 };
UINT	CaseFoldingCS_CpList2CAE[]	= { 0x2CAF, 0 };
UINT	CaseFoldingCS_CpList2CB0[]	= { 0x2CB1, 0 };
UINT	CaseFoldingCS_CpList2CB2[]	= { 0x2CB3, 0 };
UINT	CaseFoldingCS_CpList2CB4[]	= { 0x2CB5, 0 };
UINT	CaseFoldingCS_CpList2CB6[]	= { 0x2CB7, 0 };
UINT	CaseFoldingCS_CpList2CB8[]	= { 0x2CB9, 0 };
UINT	CaseFoldingCS_CpList2CBA[]	= { 0x2CBB, 0 };
UINT	CaseFoldingCS_CpList2CBC[]	= { 0x2CBD, 0 };
UINT	CaseFoldingCS_CpList2CBE[]	= { 0x2CBF, 0 };
UINT	CaseFoldingCS_CpList2CC0[]	= { 0x2CC1, 0 };
UINT	CaseFoldingCS_CpList2CC2[]	= { 0x2CC3, 0 };
UINT	CaseFoldingCS_CpList2CC4[]	= { 0x2CC5, 0 };
UINT	CaseFoldingCS_CpList2CC6[]	= { 0x2CC7, 0 };
UINT	CaseFoldingCS_CpList2CC8[]	= { 0x2CC9, 0 };
UINT	CaseFoldingCS_CpList2CCA[]	= { 0x2CCB, 0 };
UINT	CaseFoldingCS_CpList2CCC[]	= { 0x2CCD, 0 };
UINT	CaseFoldingCS_CpList2CCE[]	= { 0x2CCF, 0 };
UINT	CaseFoldingCS_CpList2CD0[]	= { 0x2CD1, 0 };
UINT	CaseFoldingCS_CpList2CD2[]	= { 0x2CD3, 0 };
UINT	CaseFoldingCS_CpList2CD4[]	= { 0x2CD5, 0 };
UINT	CaseFoldingCS_CpList2CD6[]	= { 0x2CD7, 0 };
UINT	CaseFoldingCS_CpList2CD8[]	= { 0x2CD9, 0 };
UINT	CaseFoldingCS_CpList2CDA[]	= { 0x2CDB, 0 };
UINT	CaseFoldingCS_CpList2CDC[]	= { 0x2CDD, 0 };
UINT	CaseFoldingCS_CpList2CDE[]	= { 0x2CDF, 0 };
UINT	CaseFoldingCS_CpList2CE0[]	= { 0x2CE1, 0 };
UINT	CaseFoldingCS_CpList2CE2[]	= { 0x2CE3, 0 };
UINT	CaseFoldingCS_CpList2CEB[]	= { 0x2CEC, 0 };
UINT	CaseFoldingCS_CpList2CED[]	= { 0x2CEE, 0 };
UINT	CaseFoldingCS_CpList2CF2[]	= { 0x2CF3, 0 };
UINT	CaseFoldingCS_CpListA640[]	= { 0xA641, 0 };
UINT	CaseFoldingCS_CpListA642[]	= { 0xA643, 0 };
UINT	CaseFoldingCS_CpListA644[]	= { 0xA645, 0 };
UINT	CaseFoldingCS_CpListA646[]	= { 0xA647, 0 };
UINT	CaseFoldingCS_CpListA648[]	= { 0xA649, 0 };
UINT	CaseFoldingCS_CpListA64A[]	= { 0xA64B, 0 };
UINT	CaseFoldingCS_CpListA64C[]	= { 0xA64D, 0 };
UINT	CaseFoldingCS_CpListA64E[]	= { 0xA64F, 0 };
UINT	CaseFoldingCS_CpListA650[]	= { 0xA651, 0 };
UINT	CaseFoldingCS_CpListA652[]	= { 0xA653, 0 };
UINT	CaseFoldingCS_CpListA654[]	= { 0xA655, 0 };
UINT	CaseFoldingCS_CpListA656[]	= { 0xA657, 0 };
UINT	CaseFoldingCS_CpListA658[]	= { 0xA659, 0 };
UINT	CaseFoldingCS_CpListA65A[]	= { 0xA65B, 0 };
UINT	CaseFoldingCS_CpListA65C[]	= { 0xA65D, 0 };
UINT	CaseFoldingCS_CpListA65E[]	= { 0xA65F, 0 };
UINT	CaseFoldingCS_CpListA660[]	= { 0xA661, 0 };
UINT	CaseFoldingCS_CpListA662[]	= { 0xA663, 0 };
UINT	CaseFoldingCS_CpListA664[]	= { 0xA665, 0 };
UINT	CaseFoldingCS_CpListA666[]	= { 0xA667, 0 };
UINT	CaseFoldingCS_CpListA668[]	= { 0xA669, 0 };
UINT	CaseFoldingCS_CpListA66A[]	= { 0xA66B, 0 };
UINT	CaseFoldingCS_CpListA66C[]	= { 0xA66D, 0 };
UINT	CaseFoldingCS_CpListA680[]	= { 0xA681, 0 };
UINT	CaseFoldingCS_CpListA682[]	= { 0xA683, 0 };
UINT	CaseFoldingCS_CpListA684[]	= { 0xA685, 0 };
UINT	CaseFoldingCS_CpListA686[]	= { 0xA687, 0 };
UINT	CaseFoldingCS_CpListA688[]	= { 0xA689, 0 };
UINT	CaseFoldingCS_CpListA68A[]	= { 0xA68B, 0 };
UINT	CaseFoldingCS_CpListA68C[]	= { 0xA68D, 0 };
UINT	CaseFoldingCS_CpListA68E[]	= { 0xA68F, 0 };
UINT	CaseFoldingCS_CpListA690[]	= { 0xA691, 0 };
UINT	CaseFoldingCS_CpListA692[]	= { 0xA693, 0 };
UINT	CaseFoldingCS_CpListA694[]	= { 0xA695, 0 };
UINT	CaseFoldingCS_CpListA696[]	= { 0xA697, 0 };
UINT	CaseFoldingCS_CpListA722[]	= { 0xA723, 0 };
UINT	CaseFoldingCS_CpListA724[]	= { 0xA725, 0 };
UINT	CaseFoldingCS_CpListA726[]	= { 0xA727, 0 };
UINT	CaseFoldingCS_CpListA728[]	= { 0xA729, 0 };
UINT	CaseFoldingCS_CpListA72A[]	= { 0xA72B, 0 };
UINT	CaseFoldingCS_CpListA72C[]	= { 0xA72D, 0 };
UINT	CaseFoldingCS_CpListA72E[]	= { 0xA72F, 0 };
UINT	CaseFoldingCS_CpListA732[]	= { 0xA733, 0 };
UINT	CaseFoldingCS_CpListA734[]	= { 0xA735, 0 };
UINT	CaseFoldingCS_CpListA736[]	= { 0xA737, 0 };
UINT	CaseFoldingCS_CpListA738[]	= { 0xA739, 0 };
UINT	CaseFoldingCS_CpListA73A[]	= { 0xA73B, 0 };
UINT	CaseFoldingCS_CpListA73C[]	= { 0xA73D, 0 };
UINT	CaseFoldingCS_CpListA73E[]	= { 0xA73F, 0 };
UINT	CaseFoldingCS_CpListA740[]	= { 0xA741, 0 };
UINT	CaseFoldingCS_CpListA742[]	= { 0xA743, 0 };
UINT	CaseFoldingCS_CpListA744[]	= { 0xA745, 0 };
UINT	CaseFoldingCS_CpListA746[]	= { 0xA747, 0 };
UINT	CaseFoldingCS_CpListA748[]	= { 0xA749, 0 };
UINT	CaseFoldingCS_CpListA74A[]	= { 0xA74B, 0 };
UINT	CaseFoldingCS_CpListA74C[]	= { 0xA74D, 0 };
UINT	CaseFoldingCS_CpListA74E[]	= { 0xA74F, 0 };
UINT	CaseFoldingCS_CpListA750[]	= { 0xA751, 0 };
UINT	CaseFoldingCS_CpListA752[]	= { 0xA753, 0 };
UINT	CaseFoldingCS_CpListA754[]	= { 0xA755, 0 };
UINT	CaseFoldingCS_CpListA756[]	= { 0xA757, 0 };
UINT	CaseFoldingCS_CpListA758[]	= { 0xA759, 0 };
UINT	CaseFoldingCS_CpListA75A[]	= { 0xA75B, 0 };
UINT	CaseFoldingCS_CpListA75C[]	= { 0xA75D, 0 };
UINT	CaseFoldingCS_CpListA75E[]	= { 0xA75F, 0 };
UINT	CaseFoldingCS_CpListA760[]	= { 0xA761, 0 };
UINT	CaseFoldingCS_CpListA762[]	= { 0xA763, 0 };
UINT	CaseFoldingCS_CpListA764[]	= { 0xA765, 0 };
UINT	CaseFoldingCS_CpListA766[]	= { 0xA767, 0 };
UINT	CaseFoldingCS_CpListA768[]	= { 0xA769, 0 };
UINT	CaseFoldingCS_CpListA76A[]	= { 0xA76B, 0 };
UINT	CaseFoldingCS_CpListA76C[]	= { 0xA76D, 0 };
UINT	CaseFoldingCS_CpListA76E[]	= { 0xA76F, 0 };
UINT	CaseFoldingCS_CpListA779[]	= { 0xA77A, 0 };
UINT	CaseFoldingCS_CpListA77B[]	= { 0xA77C, 0 };
UINT	CaseFoldingCS_CpListA77D[]	= { 0x1D79, 0 };
UINT	CaseFoldingCS_CpListA77E[]	= { 0xA77F, 0 };
UINT	CaseFoldingCS_CpListA780[]	= { 0xA781, 0 };
UINT	CaseFoldingCS_CpListA782[]	= { 0xA783, 0 };
UINT	CaseFoldingCS_CpListA784[]	= { 0xA785, 0 };
UINT	CaseFoldingCS_CpListA786[]	= { 0xA787, 0 };
UINT	CaseFoldingCS_CpListA78B[]	= { 0xA78C, 0 };
UINT	CaseFoldingCS_CpListA78D[]	= { 0x0265, 0 };
UINT	CaseFoldingCS_CpListA790[]	= { 0xA791, 0 };
UINT	CaseFoldingCS_CpListA792[]	= { 0xA793, 0 };
UINT	CaseFoldingCS_CpListA7A0[]	= { 0xA7A1, 0 };
UINT	CaseFoldingCS_CpListA7A2[]	= { 0xA7A3, 0 };
UINT	CaseFoldingCS_CpListA7A4[]	= { 0xA7A5, 0 };
UINT	CaseFoldingCS_CpListA7A6[]	= { 0xA7A7, 0 };
UINT	CaseFoldingCS_CpListA7A8[]	= { 0xA7A9, 0 };
UINT	CaseFoldingCS_CpListA7AA[]	= { 0x0266, 0 };
UINT	CaseFoldingCS_CpListFF21[]	= { 0xFF41, 0 };
UINT	CaseFoldingCS_CpListFF22[]	= { 0xFF42, 0 };
UINT	CaseFoldingCS_CpListFF23[]	= { 0xFF43, 0 };
UINT	CaseFoldingCS_CpListFF24[]	= { 0xFF44, 0 };
UINT	CaseFoldingCS_CpListFF25[]	= { 0xFF45, 0 };
UINT	CaseFoldingCS_CpListFF26[]	= { 0xFF46, 0 };
UINT	CaseFoldingCS_CpListFF27[]	= { 0xFF47, 0 };
UINT	CaseFoldingCS_CpListFF28[]	= { 0xFF48, 0 };
UINT	CaseFoldingCS_CpListFF29[]	= { 0xFF49, 0 };
UINT	CaseFoldingCS_CpListFF2A[]	= { 0xFF4A, 0 };
UINT	CaseFoldingCS_CpListFF2B[]	= { 0xFF4B, 0 };
UINT	CaseFoldingCS_CpListFF2C[]	= { 0xFF4C, 0 };
UINT	CaseFoldingCS_CpListFF2D[]	= { 0xFF4D, 0 };
UINT	CaseFoldingCS_CpListFF2E[]	= { 0xFF4E, 0 };
UINT	CaseFoldingCS_CpListFF2F[]	= { 0xFF4F, 0 };
UINT	CaseFoldingCS_CpListFF30[]	= { 0xFF50, 0 };
UINT	CaseFoldingCS_CpListFF31[]	= { 0xFF51, 0 };
UINT	CaseFoldingCS_CpListFF32[]	= { 0xFF52, 0 };
UINT	CaseFoldingCS_CpListFF33[]	= { 0xFF53, 0 };
UINT	CaseFoldingCS_CpListFF34[]	= { 0xFF54, 0 };
UINT	CaseFoldingCS_CpListFF35[]	= { 0xFF55, 0 };
UINT	CaseFoldingCS_CpListFF36[]	= { 0xFF56, 0 };
UINT	CaseFoldingCS_CpListFF37[]	= { 0xFF57, 0 };
UINT	CaseFoldingCS_CpListFF38[]	= { 0xFF58, 0 };
UINT	CaseFoldingCS_CpListFF39[]	= { 0xFF59, 0 };
UINT	CaseFoldingCS_CpListFF3A[]	= { 0xFF5A, 0 };
UINT	CaseFoldingCS_CpList10400[]	= { 0x10428, 0 };
UINT	CaseFoldingCS_CpList10401[]	= { 0x10429, 0 };
UINT	CaseFoldingCS_CpList10402[]	= { 0x1042A, 0 };
UINT	CaseFoldingCS_CpList10403[]	= { 0x1042B, 0 };
UINT	CaseFoldingCS_CpList10404[]	= { 0x1042C, 0 };
UINT	CaseFoldingCS_CpList10405[]	= { 0x1042D, 0 };
UINT	CaseFoldingCS_CpList10406[]	= { 0x1042E, 0 };
UINT	CaseFoldingCS_CpList10407[]	= { 0x1042F, 0 };
UINT	CaseFoldingCS_CpList10408[]	= { 0x10430, 0 };
UINT	CaseFoldingCS_CpList10409[]	= { 0x10431, 0 };
UINT	CaseFoldingCS_CpList1040A[]	= { 0x10432, 0 };
UINT	CaseFoldingCS_CpList1040B[]	= { 0x10433, 0 };
UINT	CaseFoldingCS_CpList1040C[]	= { 0x10434, 0 };
UINT	CaseFoldingCS_CpList1040D[]	= { 0x10435, 0 };
UINT	CaseFoldingCS_CpList1040E[]	= { 0x10436, 0 };
UINT	CaseFoldingCS_CpList1040F[]	= { 0x10437, 0 };
UINT	CaseFoldingCS_CpList10410[]	= { 0x10438, 0 };
UINT	CaseFoldingCS_CpList10411[]	= { 0x10439, 0 };
UINT	CaseFoldingCS_CpList10412[]	= { 0x1043A, 0 };
UINT	CaseFoldingCS_CpList10413[]	= { 0x1043B, 0 };
UINT	CaseFoldingCS_CpList10414[]	= { 0x1043C, 0 };
UINT	CaseFoldingCS_CpList10415[]	= { 0x1043D, 0 };
UINT	CaseFoldingCS_CpList10416[]	= { 0x1043E, 0 };
UINT	CaseFoldingCS_CpList10417[]	= { 0x1043F, 0 };
UINT	CaseFoldingCS_CpList10418[]	= { 0x10440, 0 };
UINT	CaseFoldingCS_CpList10419[]	= { 0x10441, 0 };
UINT	CaseFoldingCS_CpList1041A[]	= { 0x10442, 0 };
UINT	CaseFoldingCS_CpList1041B[]	= { 0x10443, 0 };
UINT	CaseFoldingCS_CpList1041C[]	= { 0x10444, 0 };
UINT	CaseFoldingCS_CpList1041D[]	= { 0x10445, 0 };
UINT	CaseFoldingCS_CpList1041E[]	= { 0x10446, 0 };
UINT	CaseFoldingCS_CpList1041F[]	= { 0x10447, 0 };
UINT	CaseFoldingCS_CpList10420[]	= { 0x10448, 0 };
UINT	CaseFoldingCS_CpList10421[]	= { 0x10449, 0 };
UINT	CaseFoldingCS_CpList10422[]	= { 0x1044A, 0 };
UINT	CaseFoldingCS_CpList10423[]	= { 0x1044B, 0 };
UINT	CaseFoldingCS_CpList10424[]	= { 0x1044C, 0 };
UINT	CaseFoldingCS_CpList10425[]	= { 0x1044D, 0 };
UINT	CaseFoldingCS_CpList10426[]	= { 0x1044E, 0 };
UINT	CaseFoldingCS_CpList10427[]	= { 0x1044F, 0 };

//----------------------------------------------------------------------
//	Common and Simple Case Folding	: Info
//----------------------------------------------------------------------
SCASEFOLDMAP	siCaseFolding_CS[]	=
{
	0x0041,	CaseFoldingCS_CpList0041,	1,	TQU("\x0061"),
	0x0042,	CaseFoldingCS_CpList0042,	1,	TQU("\x0062"),
	0x0043,	CaseFoldingCS_CpList0043,	1,	TQU("\x0063"),
	0x0044,	CaseFoldingCS_CpList0044,	1,	TQU("\x0064"),
	0x0045,	CaseFoldingCS_CpList0045,	1,	TQU("\x0065"),
	0x0046,	CaseFoldingCS_CpList0046,	1,	TQU("\x0066"),
	0x0047,	CaseFoldingCS_CpList0047,	1,	TQU("\x0067"),
	0x0048,	CaseFoldingCS_CpList0048,	1,	TQU("\x0068"),
	0x0049,	CaseFoldingCS_CpList0049,	1,	TQU("\x0069"),
	0x004A,	CaseFoldingCS_CpList004A,	1,	TQU("\x006A"),
	0x004B,	CaseFoldingCS_CpList004B,	1,	TQU("\x006B"),
	0x004C,	CaseFoldingCS_CpList004C,	1,	TQU("\x006C"),
	0x004D,	CaseFoldingCS_CpList004D,	1,	TQU("\x006D"),
	0x004E,	CaseFoldingCS_CpList004E,	1,	TQU("\x006E"),
	0x004F,	CaseFoldingCS_CpList004F,	1,	TQU("\x006F"),
	0x0050,	CaseFoldingCS_CpList0050,	1,	TQU("\x0070"),
	0x0051,	CaseFoldingCS_CpList0051,	1,	TQU("\x0071"),
	0x0052,	CaseFoldingCS_CpList0052,	1,	TQU("\x0072"),
	0x0053,	CaseFoldingCS_CpList0053,	1,	TQU("\x0073"),
	0x0054,	CaseFoldingCS_CpList0054,	1,	TQU("\x0074"),
	0x0055,	CaseFoldingCS_CpList0055,	1,	TQU("\x0075"),
	0x0056,	CaseFoldingCS_CpList0056,	1,	TQU("\x0076"),
	0x0057,	CaseFoldingCS_CpList0057,	1,	TQU("\x0077"),
	0x0058,	CaseFoldingCS_CpList0058,	1,	TQU("\x0078"),
	0x0059,	CaseFoldingCS_CpList0059,	1,	TQU("\x0079"),
	0x005A,	CaseFoldingCS_CpList005A,	1,	TQU("\x007A"),
	0x00B5,	CaseFoldingCS_CpList00B5,	1,	TQU("\x03BC"),
	0x00C0,	CaseFoldingCS_CpList00C0,	1,	TQU("\x00E0"),
	0x00C1,	CaseFoldingCS_CpList00C1,	1,	TQU("\x00E1"),
	0x00C2,	CaseFoldingCS_CpList00C2,	1,	TQU("\x00E2"),
	0x00C3,	CaseFoldingCS_CpList00C3,	1,	TQU("\x00E3"),
	0x00C4,	CaseFoldingCS_CpList00C4,	1,	TQU("\x00E4"),
	0x00C5,	CaseFoldingCS_CpList00C5,	1,	TQU("\x00E5"),
	0x00C6,	CaseFoldingCS_CpList00C6,	1,	TQU("\x00E6"),
	0x00C7,	CaseFoldingCS_CpList00C7,	1,	TQU("\x00E7"),
	0x00C8,	CaseFoldingCS_CpList00C8,	1,	TQU("\x00E8"),
	0x00C9,	CaseFoldingCS_CpList00C9,	1,	TQU("\x00E9"),
	0x00CA,	CaseFoldingCS_CpList00CA,	1,	TQU("\x00EA"),
	0x00CB,	CaseFoldingCS_CpList00CB,	1,	TQU("\x00EB"),
	0x00CC,	CaseFoldingCS_CpList00CC,	1,	TQU("\x00EC"),
	0x00CD,	CaseFoldingCS_CpList00CD,	1,	TQU("\x00ED"),
	0x00CE,	CaseFoldingCS_CpList00CE,	1,	TQU("\x00EE"),
	0x00CF,	CaseFoldingCS_CpList00CF,	1,	TQU("\x00EF"),
	0x00D0,	CaseFoldingCS_CpList00D0,	1,	TQU("\x00F0"),
	0x00D1,	CaseFoldingCS_CpList00D1,	1,	TQU("\x00F1"),
	0x00D2,	CaseFoldingCS_CpList00D2,	1,	TQU("\x00F2"),
	0x00D3,	CaseFoldingCS_CpList00D3,	1,	TQU("\x00F3"),
	0x00D4,	CaseFoldingCS_CpList00D4,	1,	TQU("\x00F4"),
	0x00D5,	CaseFoldingCS_CpList00D5,	1,	TQU("\x00F5"),
	0x00D6,	CaseFoldingCS_CpList00D6,	1,	TQU("\x00F6"),
	0x00D8,	CaseFoldingCS_CpList00D8,	1,	TQU("\x00F8"),
	0x00D9,	CaseFoldingCS_CpList00D9,	1,	TQU("\x00F9"),
	0x00DA,	CaseFoldingCS_CpList00DA,	1,	TQU("\x00FA"),
	0x00DB,	CaseFoldingCS_CpList00DB,	1,	TQU("\x00FB"),
	0x00DC,	CaseFoldingCS_CpList00DC,	1,	TQU("\x00FC"),
	0x00DD,	CaseFoldingCS_CpList00DD,	1,	TQU("\x00FD"),
	0x00DE,	CaseFoldingCS_CpList00DE,	1,	TQU("\x00FE"),
	0x0100,	CaseFoldingCS_CpList0100,	1,	TQU("\x0101"),
	0x0102,	CaseFoldingCS_CpList0102,	1,	TQU("\x0103"),
	0x0104,	CaseFoldingCS_CpList0104,	1,	TQU("\x0105"),
	0x0106,	CaseFoldingCS_CpList0106,	1,	TQU("\x0107"),
	0x0108,	CaseFoldingCS_CpList0108,	1,	TQU("\x0109"),
	0x010A,	CaseFoldingCS_CpList010A,	1,	TQU("\x010B"),
	0x010C,	CaseFoldingCS_CpList010C,	1,	TQU("\x010D"),
	0x010E,	CaseFoldingCS_CpList010E,	1,	TQU("\x010F"),
	0x0110,	CaseFoldingCS_CpList0110,	1,	TQU("\x0111"),
	0x0112,	CaseFoldingCS_CpList0112,	1,	TQU("\x0113"),
	0x0114,	CaseFoldingCS_CpList0114,	1,	TQU("\x0115"),
	0x0116,	CaseFoldingCS_CpList0116,	1,	TQU("\x0117"),
	0x0118,	CaseFoldingCS_CpList0118,	1,	TQU("\x0119"),
	0x011A,	CaseFoldingCS_CpList011A,	1,	TQU("\x011B"),
	0x011C,	CaseFoldingCS_CpList011C,	1,	TQU("\x011D"),
	0x011E,	CaseFoldingCS_CpList011E,	1,	TQU("\x011F"),
	0x0120,	CaseFoldingCS_CpList0120,	1,	TQU("\x0121"),
	0x0122,	CaseFoldingCS_CpList0122,	1,	TQU("\x0123"),
	0x0124,	CaseFoldingCS_CpList0124,	1,	TQU("\x0125"),
	0x0126,	CaseFoldingCS_CpList0126,	1,	TQU("\x0127"),
	0x0128,	CaseFoldingCS_CpList0128,	1,	TQU("\x0129"),
	0x012A,	CaseFoldingCS_CpList012A,	1,	TQU("\x012B"),
	0x012C,	CaseFoldingCS_CpList012C,	1,	TQU("\x012D"),
	0x012E,	CaseFoldingCS_CpList012E,	1,	TQU("\x012F"),
	0x0132,	CaseFoldingCS_CpList0132,	1,	TQU("\x0133"),
	0x0134,	CaseFoldingCS_CpList0134,	1,	TQU("\x0135"),
	0x0136,	CaseFoldingCS_CpList0136,	1,	TQU("\x0137"),
	0x0139,	CaseFoldingCS_CpList0139,	1,	TQU("\x013A"),
	0x013B,	CaseFoldingCS_CpList013B,	1,	TQU("\x013C"),
	0x013D,	CaseFoldingCS_CpList013D,	1,	TQU("\x013E"),
	0x013F,	CaseFoldingCS_CpList013F,	1,	TQU("\x0140"),
	0x0141,	CaseFoldingCS_CpList0141,	1,	TQU("\x0142"),
	0x0143,	CaseFoldingCS_CpList0143,	1,	TQU("\x0144"),
	0x0145,	CaseFoldingCS_CpList0145,	1,	TQU("\x0146"),
	0x0147,	CaseFoldingCS_CpList0147,	1,	TQU("\x0148"),
	0x014A,	CaseFoldingCS_CpList014A,	1,	TQU("\x014B"),
	0x014C,	CaseFoldingCS_CpList014C,	1,	TQU("\x014D"),
	0x014E,	CaseFoldingCS_CpList014E,	1,	TQU("\x014F"),
	0x0150,	CaseFoldingCS_CpList0150,	1,	TQU("\x0151"),
	0x0152,	CaseFoldingCS_CpList0152,	1,	TQU("\x0153"),
	0x0154,	CaseFoldingCS_CpList0154,	1,	TQU("\x0155"),
	0x0156,	CaseFoldingCS_CpList0156,	1,	TQU("\x0157"),
	0x0158,	CaseFoldingCS_CpList0158,	1,	TQU("\x0159"),
	0x015A,	CaseFoldingCS_CpList015A,	1,	TQU("\x015B"),
	0x015C,	CaseFoldingCS_CpList015C,	1,	TQU("\x015D"),
	0x015E,	CaseFoldingCS_CpList015E,	1,	TQU("\x015F"),
	0x0160,	CaseFoldingCS_CpList0160,	1,	TQU("\x0161"),
	0x0162,	CaseFoldingCS_CpList0162,	1,	TQU("\x0163"),
	0x0164,	CaseFoldingCS_CpList0164,	1,	TQU("\x0165"),
	0x0166,	CaseFoldingCS_CpList0166,	1,	TQU("\x0167"),
	0x0168,	CaseFoldingCS_CpList0168,	1,	TQU("\x0169"),
	0x016A,	CaseFoldingCS_CpList016A,	1,	TQU("\x016B"),
	0x016C,	CaseFoldingCS_CpList016C,	1,	TQU("\x016D"),
	0x016E,	CaseFoldingCS_CpList016E,	1,	TQU("\x016F"),
	0x0170,	CaseFoldingCS_CpList0170,	1,	TQU("\x0171"),
	0x0172,	CaseFoldingCS_CpList0172,	1,	TQU("\x0173"),
	0x0174,	CaseFoldingCS_CpList0174,	1,	TQU("\x0175"),
	0x0176,	CaseFoldingCS_CpList0176,	1,	TQU("\x0177"),
	0x0178,	CaseFoldingCS_CpList0178,	1,	TQU("\x00FF"),
	0x0179,	CaseFoldingCS_CpList0179,	1,	TQU("\x017A"),
	0x017B,	CaseFoldingCS_CpList017B,	1,	TQU("\x017C"),
	0x017D,	CaseFoldingCS_CpList017D,	1,	TQU("\x017E"),
	0x017F,	CaseFoldingCS_CpList017F,	1,	TQU("\x0073"),
	0x0181,	CaseFoldingCS_CpList0181,	1,	TQU("\x0253"),
	0x0182,	CaseFoldingCS_CpList0182,	1,	TQU("\x0183"),
	0x0184,	CaseFoldingCS_CpList0184,	1,	TQU("\x0185"),
	0x0186,	CaseFoldingCS_CpList0186,	1,	TQU("\x0254"),
	0x0187,	CaseFoldingCS_CpList0187,	1,	TQU("\x0188"),
	0x0189,	CaseFoldingCS_CpList0189,	1,	TQU("\x0256"),
	0x018A,	CaseFoldingCS_CpList018A,	1,	TQU("\x0257"),
	0x018B,	CaseFoldingCS_CpList018B,	1,	TQU("\x018C"),
	0x018E,	CaseFoldingCS_CpList018E,	1,	TQU("\x01DD"),
	0x018F,	CaseFoldingCS_CpList018F,	1,	TQU("\x0259"),
	0x0190,	CaseFoldingCS_CpList0190,	1,	TQU("\x025B"),
	0x0191,	CaseFoldingCS_CpList0191,	1,	TQU("\x0192"),
	0x0193,	CaseFoldingCS_CpList0193,	1,	TQU("\x0260"),
	0x0194,	CaseFoldingCS_CpList0194,	1,	TQU("\x0263"),
	0x0196,	CaseFoldingCS_CpList0196,	1,	TQU("\x0269"),
	0x0197,	CaseFoldingCS_CpList0197,	1,	TQU("\x0268"),
	0x0198,	CaseFoldingCS_CpList0198,	1,	TQU("\x0199"),
	0x019C,	CaseFoldingCS_CpList019C,	1,	TQU("\x026F"),
	0x019D,	CaseFoldingCS_CpList019D,	1,	TQU("\x0272"),
	0x019F,	CaseFoldingCS_CpList019F,	1,	TQU("\x0275"),
	0x01A0,	CaseFoldingCS_CpList01A0,	1,	TQU("\x01A1"),
	0x01A2,	CaseFoldingCS_CpList01A2,	1,	TQU("\x01A3"),
	0x01A4,	CaseFoldingCS_CpList01A4,	1,	TQU("\x01A5"),
	0x01A6,	CaseFoldingCS_CpList01A6,	1,	TQU("\x0280"),
	0x01A7,	CaseFoldingCS_CpList01A7,	1,	TQU("\x01A8"),
	0x01A9,	CaseFoldingCS_CpList01A9,	1,	TQU("\x0283"),
	0x01AC,	CaseFoldingCS_CpList01AC,	1,	TQU("\x01AD"),
	0x01AE,	CaseFoldingCS_CpList01AE,	1,	TQU("\x0288"),
	0x01AF,	CaseFoldingCS_CpList01AF,	1,	TQU("\x01B0"),
	0x01B1,	CaseFoldingCS_CpList01B1,	1,	TQU("\x028A"),
	0x01B2,	CaseFoldingCS_CpList01B2,	1,	TQU("\x028B"),
	0x01B3,	CaseFoldingCS_CpList01B3,	1,	TQU("\x01B4"),
	0x01B5,	CaseFoldingCS_CpList01B5,	1,	TQU("\x01B6"),
	0x01B7,	CaseFoldingCS_CpList01B7,	1,	TQU("\x0292"),
	0x01B8,	CaseFoldingCS_CpList01B8,	1,	TQU("\x01B9"),
	0x01BC,	CaseFoldingCS_CpList01BC,	1,	TQU("\x01BD"),
	0x01C4,	CaseFoldingCS_CpList01C4,	1,	TQU("\x01C6"),
	0x01C5,	CaseFoldingCS_CpList01C5,	1,	TQU("\x01C6"),
	0x01C7,	CaseFoldingCS_CpList01C7,	1,	TQU("\x01C9"),
	0x01C8,	CaseFoldingCS_CpList01C8,	1,	TQU("\x01C9"),
	0x01CA,	CaseFoldingCS_CpList01CA,	1,	TQU("\x01CC"),
	0x01CB,	CaseFoldingCS_CpList01CB,	1,	TQU("\x01CC"),
	0x01CD,	CaseFoldingCS_CpList01CD,	1,	TQU("\x01CE"),
	0x01CF,	CaseFoldingCS_CpList01CF,	1,	TQU("\x01D0"),
	0x01D1,	CaseFoldingCS_CpList01D1,	1,	TQU("\x01D2"),
	0x01D3,	CaseFoldingCS_CpList01D3,	1,	TQU("\x01D4"),
	0x01D5,	CaseFoldingCS_CpList01D5,	1,	TQU("\x01D6"),
	0x01D7,	CaseFoldingCS_CpList01D7,	1,	TQU("\x01D8"),
	0x01D9,	CaseFoldingCS_CpList01D9,	1,	TQU("\x01DA"),
	0x01DB,	CaseFoldingCS_CpList01DB,	1,	TQU("\x01DC"),
	0x01DE,	CaseFoldingCS_CpList01DE,	1,	TQU("\x01DF"),
	0x01E0,	CaseFoldingCS_CpList01E0,	1,	TQU("\x01E1"),
	0x01E2,	CaseFoldingCS_CpList01E2,	1,	TQU("\x01E3"),
	0x01E4,	CaseFoldingCS_CpList01E4,	1,	TQU("\x01E5"),
	0x01E6,	CaseFoldingCS_CpList01E6,	1,	TQU("\x01E7"),
	0x01E8,	CaseFoldingCS_CpList01E8,	1,	TQU("\x01E9"),
	0x01EA,	CaseFoldingCS_CpList01EA,	1,	TQU("\x01EB"),
	0x01EC,	CaseFoldingCS_CpList01EC,	1,	TQU("\x01ED"),
	0x01EE,	CaseFoldingCS_CpList01EE,	1,	TQU("\x01EF"),
	0x01F1,	CaseFoldingCS_CpList01F1,	1,	TQU("\x01F3"),
	0x01F2,	CaseFoldingCS_CpList01F2,	1,	TQU("\x01F3"),
	0x01F4,	CaseFoldingCS_CpList01F4,	1,	TQU("\x01F5"),
	0x01F6,	CaseFoldingCS_CpList01F6,	1,	TQU("\x0195"),
	0x01F7,	CaseFoldingCS_CpList01F7,	1,	TQU("\x01BF"),
	0x01F8,	CaseFoldingCS_CpList01F8,	1,	TQU("\x01F9"),
	0x01FA,	CaseFoldingCS_CpList01FA,	1,	TQU("\x01FB"),
	0x01FC,	CaseFoldingCS_CpList01FC,	1,	TQU("\x01FD"),
	0x01FE,	CaseFoldingCS_CpList01FE,	1,	TQU("\x01FF"),
	0x0200,	CaseFoldingCS_CpList0200,	1,	TQU("\x0201"),
	0x0202,	CaseFoldingCS_CpList0202,	1,	TQU("\x0203"),
	0x0204,	CaseFoldingCS_CpList0204,	1,	TQU("\x0205"),
	0x0206,	CaseFoldingCS_CpList0206,	1,	TQU("\x0207"),
	0x0208,	CaseFoldingCS_CpList0208,	1,	TQU("\x0209"),
	0x020A,	CaseFoldingCS_CpList020A,	1,	TQU("\x020B"),
	0x020C,	CaseFoldingCS_CpList020C,	1,	TQU("\x020D"),
	0x020E,	CaseFoldingCS_CpList020E,	1,	TQU("\x020F"),
	0x0210,	CaseFoldingCS_CpList0210,	1,	TQU("\x0211"),
	0x0212,	CaseFoldingCS_CpList0212,	1,	TQU("\x0213"),
	0x0214,	CaseFoldingCS_CpList0214,	1,	TQU("\x0215"),
	0x0216,	CaseFoldingCS_CpList0216,	1,	TQU("\x0217"),
	0x0218,	CaseFoldingCS_CpList0218,	1,	TQU("\x0219"),
	0x021A,	CaseFoldingCS_CpList021A,	1,	TQU("\x021B"),
	0x021C,	CaseFoldingCS_CpList021C,	1,	TQU("\x021D"),
	0x021E,	CaseFoldingCS_CpList021E,	1,	TQU("\x021F"),
	0x0220,	CaseFoldingCS_CpList0220,	1,	TQU("\x019E"),
	0x0222,	CaseFoldingCS_CpList0222,	1,	TQU("\x0223"),
	0x0224,	CaseFoldingCS_CpList0224,	1,	TQU("\x0225"),
	0x0226,	CaseFoldingCS_CpList0226,	1,	TQU("\x0227"),
	0x0228,	CaseFoldingCS_CpList0228,	1,	TQU("\x0229"),
	0x022A,	CaseFoldingCS_CpList022A,	1,	TQU("\x022B"),
	0x022C,	CaseFoldingCS_CpList022C,	1,	TQU("\x022D"),
	0x022E,	CaseFoldingCS_CpList022E,	1,	TQU("\x022F"),
	0x0230,	CaseFoldingCS_CpList0230,	1,	TQU("\x0231"),
	0x0232,	CaseFoldingCS_CpList0232,	1,	TQU("\x0233"),
	0x023A,	CaseFoldingCS_CpList023A,	1,	TQU("\x2C65"),
	0x023B,	CaseFoldingCS_CpList023B,	1,	TQU("\x023C"),
	0x023D,	CaseFoldingCS_CpList023D,	1,	TQU("\x019A"),
	0x023E,	CaseFoldingCS_CpList023E,	1,	TQU("\x2C66"),
	0x0241,	CaseFoldingCS_CpList0241,	1,	TQU("\x0242"),
	0x0243,	CaseFoldingCS_CpList0243,	1,	TQU("\x0180"),
	0x0244,	CaseFoldingCS_CpList0244,	1,	TQU("\x0289"),
	0x0245,	CaseFoldingCS_CpList0245,	1,	TQU("\x028C"),
	0x0246,	CaseFoldingCS_CpList0246,	1,	TQU("\x0247"),
	0x0248,	CaseFoldingCS_CpList0248,	1,	TQU("\x0249"),
	0x024A,	CaseFoldingCS_CpList024A,	1,	TQU("\x024B"),
	0x024C,	CaseFoldingCS_CpList024C,	1,	TQU("\x024D"),
	0x024E,	CaseFoldingCS_CpList024E,	1,	TQU("\x024F"),
	0x0345,	CaseFoldingCS_CpList0345,	1,	TQU("\x03B9"),
	0x0370,	CaseFoldingCS_CpList0370,	1,	TQU("\x0371"),
	0x0372,	CaseFoldingCS_CpList0372,	1,	TQU("\x0373"),
	0x0376,	CaseFoldingCS_CpList0376,	1,	TQU("\x0377"),
	0x0386,	CaseFoldingCS_CpList0386,	1,	TQU("\x03AC"),
	0x0388,	CaseFoldingCS_CpList0388,	1,	TQU("\x03AD"),
	0x0389,	CaseFoldingCS_CpList0389,	1,	TQU("\x03AE"),
	0x038A,	CaseFoldingCS_CpList038A,	1,	TQU("\x03AF"),
	0x038C,	CaseFoldingCS_CpList038C,	1,	TQU("\x03CC"),
	0x038E,	CaseFoldingCS_CpList038E,	1,	TQU("\x03CD"),
	0x038F,	CaseFoldingCS_CpList038F,	1,	TQU("\x03CE"),
	0x0391,	CaseFoldingCS_CpList0391,	1,	TQU("\x03B1"),
	0x0392,	CaseFoldingCS_CpList0392,	1,	TQU("\x03B2"),
	0x0393,	CaseFoldingCS_CpList0393,	1,	TQU("\x03B3"),
	0x0394,	CaseFoldingCS_CpList0394,	1,	TQU("\x03B4"),
	0x0395,	CaseFoldingCS_CpList0395,	1,	TQU("\x03B5"),
	0x0396,	CaseFoldingCS_CpList0396,	1,	TQU("\x03B6"),
	0x0397,	CaseFoldingCS_CpList0397,	1,	TQU("\x03B7"),
	0x0398,	CaseFoldingCS_CpList0398,	1,	TQU("\x03B8"),
	0x0399,	CaseFoldingCS_CpList0399,	1,	TQU("\x03B9"),
	0x039A,	CaseFoldingCS_CpList039A,	1,	TQU("\x03BA"),
	0x039B,	CaseFoldingCS_CpList039B,	1,	TQU("\x03BB"),
	0x039C,	CaseFoldingCS_CpList039C,	1,	TQU("\x03BC"),
	0x039D,	CaseFoldingCS_CpList039D,	1,	TQU("\x03BD"),
	0x039E,	CaseFoldingCS_CpList039E,	1,	TQU("\x03BE"),
	0x039F,	CaseFoldingCS_CpList039F,	1,	TQU("\x03BF"),
	0x03A0,	CaseFoldingCS_CpList03A0,	1,	TQU("\x03C0"),
	0x03A1,	CaseFoldingCS_CpList03A1,	1,	TQU("\x03C1"),
	0x03A3,	CaseFoldingCS_CpList03A3,	1,	TQU("\x03C3"),
	0x03A4,	CaseFoldingCS_CpList03A4,	1,	TQU("\x03C4"),
	0x03A5,	CaseFoldingCS_CpList03A5,	1,	TQU("\x03C5"),
	0x03A6,	CaseFoldingCS_CpList03A6,	1,	TQU("\x03C6"),
	0x03A7,	CaseFoldingCS_CpList03A7,	1,	TQU("\x03C7"),
	0x03A8,	CaseFoldingCS_CpList03A8,	1,	TQU("\x03C8"),
	0x03A9,	CaseFoldingCS_CpList03A9,	1,	TQU("\x03C9"),
	0x03AA,	CaseFoldingCS_CpList03AA,	1,	TQU("\x03CA"),
	0x03AB,	CaseFoldingCS_CpList03AB,	1,	TQU("\x03CB"),
	0x03C2,	CaseFoldingCS_CpList03C2,	1,	TQU("\x03C3"),
	0x03CF,	CaseFoldingCS_CpList03CF,	1,	TQU("\x03D7"),
	0x03D0,	CaseFoldingCS_CpList03D0,	1,	TQU("\x03B2"),
	0x03D1,	CaseFoldingCS_CpList03D1,	1,	TQU("\x03B8"),
	0x03D5,	CaseFoldingCS_CpList03D5,	1,	TQU("\x03C6"),
	0x03D6,	CaseFoldingCS_CpList03D6,	1,	TQU("\x03C0"),
	0x03D8,	CaseFoldingCS_CpList03D8,	1,	TQU("\x03D9"),
	0x03DA,	CaseFoldingCS_CpList03DA,	1,	TQU("\x03DB"),
	0x03DC,	CaseFoldingCS_CpList03DC,	1,	TQU("\x03DD"),
	0x03DE,	CaseFoldingCS_CpList03DE,	1,	TQU("\x03DF"),
	0x03E0,	CaseFoldingCS_CpList03E0,	1,	TQU("\x03E1"),
	0x03E2,	CaseFoldingCS_CpList03E2,	1,	TQU("\x03E3"),
	0x03E4,	CaseFoldingCS_CpList03E4,	1,	TQU("\x03E5"),
	0x03E6,	CaseFoldingCS_CpList03E6,	1,	TQU("\x03E7"),
	0x03E8,	CaseFoldingCS_CpList03E8,	1,	TQU("\x03E9"),
	0x03EA,	CaseFoldingCS_CpList03EA,	1,	TQU("\x03EB"),
	0x03EC,	CaseFoldingCS_CpList03EC,	1,	TQU("\x03ED"),
	0x03EE,	CaseFoldingCS_CpList03EE,	1,	TQU("\x03EF"),
	0x03F0,	CaseFoldingCS_CpList03F0,	1,	TQU("\x03BA"),
	0x03F1,	CaseFoldingCS_CpList03F1,	1,	TQU("\x03C1"),
	0x03F4,	CaseFoldingCS_CpList03F4,	1,	TQU("\x03B8"),
	0x03F5,	CaseFoldingCS_CpList03F5,	1,	TQU("\x03B5"),
	0x03F7,	CaseFoldingCS_CpList03F7,	1,	TQU("\x03F8"),
	0x03F9,	CaseFoldingCS_CpList03F9,	1,	TQU("\x03F2"),
	0x03FA,	CaseFoldingCS_CpList03FA,	1,	TQU("\x03FB"),
	0x03FD,	CaseFoldingCS_CpList03FD,	1,	TQU("\x037B"),
	0x03FE,	CaseFoldingCS_CpList03FE,	1,	TQU("\x037C"),
	0x03FF,	CaseFoldingCS_CpList03FF,	1,	TQU("\x037D"),
	0x0400,	CaseFoldingCS_CpList0400,	1,	TQU("\x0450"),
	0x0401,	CaseFoldingCS_CpList0401,	1,	TQU("\x0451"),
	0x0402,	CaseFoldingCS_CpList0402,	1,	TQU("\x0452"),
	0x0403,	CaseFoldingCS_CpList0403,	1,	TQU("\x0453"),
	0x0404,	CaseFoldingCS_CpList0404,	1,	TQU("\x0454"),
	0x0405,	CaseFoldingCS_CpList0405,	1,	TQU("\x0455"),
	0x0406,	CaseFoldingCS_CpList0406,	1,	TQU("\x0456"),
	0x0407,	CaseFoldingCS_CpList0407,	1,	TQU("\x0457"),
	0x0408,	CaseFoldingCS_CpList0408,	1,	TQU("\x0458"),
	0x0409,	CaseFoldingCS_CpList0409,	1,	TQU("\x0459"),
	0x040A,	CaseFoldingCS_CpList040A,	1,	TQU("\x045A"),
	0x040B,	CaseFoldingCS_CpList040B,	1,	TQU("\x045B"),
	0x040C,	CaseFoldingCS_CpList040C,	1,	TQU("\x045C"),
	0x040D,	CaseFoldingCS_CpList040D,	1,	TQU("\x045D"),
	0x040E,	CaseFoldingCS_CpList040E,	1,	TQU("\x045E"),
	0x040F,	CaseFoldingCS_CpList040F,	1,	TQU("\x045F"),
	0x0410,	CaseFoldingCS_CpList0410,	1,	TQU("\x0430"),
	0x0411,	CaseFoldingCS_CpList0411,	1,	TQU("\x0431"),
	0x0412,	CaseFoldingCS_CpList0412,	1,	TQU("\x0432"),
	0x0413,	CaseFoldingCS_CpList0413,	1,	TQU("\x0433"),
	0x0414,	CaseFoldingCS_CpList0414,	1,	TQU("\x0434"),
	0x0415,	CaseFoldingCS_CpList0415,	1,	TQU("\x0435"),
	0x0416,	CaseFoldingCS_CpList0416,	1,	TQU("\x0436"),
	0x0417,	CaseFoldingCS_CpList0417,	1,	TQU("\x0437"),
	0x0418,	CaseFoldingCS_CpList0418,	1,	TQU("\x0438"),
	0x0419,	CaseFoldingCS_CpList0419,	1,	TQU("\x0439"),
	0x041A,	CaseFoldingCS_CpList041A,	1,	TQU("\x043A"),
	0x041B,	CaseFoldingCS_CpList041B,	1,	TQU("\x043B"),
	0x041C,	CaseFoldingCS_CpList041C,	1,	TQU("\x043C"),
	0x041D,	CaseFoldingCS_CpList041D,	1,	TQU("\x043D"),
	0x041E,	CaseFoldingCS_CpList041E,	1,	TQU("\x043E"),
	0x041F,	CaseFoldingCS_CpList041F,	1,	TQU("\x043F"),
	0x0420,	CaseFoldingCS_CpList0420,	1,	TQU("\x0440"),
	0x0421,	CaseFoldingCS_CpList0421,	1,	TQU("\x0441"),
	0x0422,	CaseFoldingCS_CpList0422,	1,	TQU("\x0442"),
	0x0423,	CaseFoldingCS_CpList0423,	1,	TQU("\x0443"),
	0x0424,	CaseFoldingCS_CpList0424,	1,	TQU("\x0444"),
	0x0425,	CaseFoldingCS_CpList0425,	1,	TQU("\x0445"),
	0x0426,	CaseFoldingCS_CpList0426,	1,	TQU("\x0446"),
	0x0427,	CaseFoldingCS_CpList0427,	1,	TQU("\x0447"),
	0x0428,	CaseFoldingCS_CpList0428,	1,	TQU("\x0448"),
	0x0429,	CaseFoldingCS_CpList0429,	1,	TQU("\x0449"),
	0x042A,	CaseFoldingCS_CpList042A,	1,	TQU("\x044A"),
	0x042B,	CaseFoldingCS_CpList042B,	1,	TQU("\x044B"),
	0x042C,	CaseFoldingCS_CpList042C,	1,	TQU("\x044C"),
	0x042D,	CaseFoldingCS_CpList042D,	1,	TQU("\x044D"),
	0x042E,	CaseFoldingCS_CpList042E,	1,	TQU("\x044E"),
	0x042F,	CaseFoldingCS_CpList042F,	1,	TQU("\x044F"),
	0x0460,	CaseFoldingCS_CpList0460,	1,	TQU("\x0461"),
	0x0462,	CaseFoldingCS_CpList0462,	1,	TQU("\x0463"),
	0x0464,	CaseFoldingCS_CpList0464,	1,	TQU("\x0465"),
	0x0466,	CaseFoldingCS_CpList0466,	1,	TQU("\x0467"),
	0x0468,	CaseFoldingCS_CpList0468,	1,	TQU("\x0469"),
	0x046A,	CaseFoldingCS_CpList046A,	1,	TQU("\x046B"),
	0x046C,	CaseFoldingCS_CpList046C,	1,	TQU("\x046D"),
	0x046E,	CaseFoldingCS_CpList046E,	1,	TQU("\x046F"),
	0x0470,	CaseFoldingCS_CpList0470,	1,	TQU("\x0471"),
	0x0472,	CaseFoldingCS_CpList0472,	1,	TQU("\x0473"),
	0x0474,	CaseFoldingCS_CpList0474,	1,	TQU("\x0475"),
	0x0476,	CaseFoldingCS_CpList0476,	1,	TQU("\x0477"),
	0x0478,	CaseFoldingCS_CpList0478,	1,	TQU("\x0479"),
	0x047A,	CaseFoldingCS_CpList047A,	1,	TQU("\x047B"),
	0x047C,	CaseFoldingCS_CpList047C,	1,	TQU("\x047D"),
	0x047E,	CaseFoldingCS_CpList047E,	1,	TQU("\x047F"),
	0x0480,	CaseFoldingCS_CpList0480,	1,	TQU("\x0481"),
	0x048A,	CaseFoldingCS_CpList048A,	1,	TQU("\x048B"),
	0x048C,	CaseFoldingCS_CpList048C,	1,	TQU("\x048D"),
	0x048E,	CaseFoldingCS_CpList048E,	1,	TQU("\x048F"),
	0x0490,	CaseFoldingCS_CpList0490,	1,	TQU("\x0491"),
	0x0492,	CaseFoldingCS_CpList0492,	1,	TQU("\x0493"),
	0x0494,	CaseFoldingCS_CpList0494,	1,	TQU("\x0495"),
	0x0496,	CaseFoldingCS_CpList0496,	1,	TQU("\x0497"),
	0x0498,	CaseFoldingCS_CpList0498,	1,	TQU("\x0499"),
	0x049A,	CaseFoldingCS_CpList049A,	1,	TQU("\x049B"),
	0x049C,	CaseFoldingCS_CpList049C,	1,	TQU("\x049D"),
	0x049E,	CaseFoldingCS_CpList049E,	1,	TQU("\x049F"),
	0x04A0,	CaseFoldingCS_CpList04A0,	1,	TQU("\x04A1"),
	0x04A2,	CaseFoldingCS_CpList04A2,	1,	TQU("\x04A3"),
	0x04A4,	CaseFoldingCS_CpList04A4,	1,	TQU("\x04A5"),
	0x04A6,	CaseFoldingCS_CpList04A6,	1,	TQU("\x04A7"),
	0x04A8,	CaseFoldingCS_CpList04A8,	1,	TQU("\x04A9"),
	0x04AA,	CaseFoldingCS_CpList04AA,	1,	TQU("\x04AB"),
	0x04AC,	CaseFoldingCS_CpList04AC,	1,	TQU("\x04AD"),
	0x04AE,	CaseFoldingCS_CpList04AE,	1,	TQU("\x04AF"),
	0x04B0,	CaseFoldingCS_CpList04B0,	1,	TQU("\x04B1"),
	0x04B2,	CaseFoldingCS_CpList04B2,	1,	TQU("\x04B3"),
	0x04B4,	CaseFoldingCS_CpList04B4,	1,	TQU("\x04B5"),
	0x04B6,	CaseFoldingCS_CpList04B6,	1,	TQU("\x04B7"),
	0x04B8,	CaseFoldingCS_CpList04B8,	1,	TQU("\x04B9"),
	0x04BA,	CaseFoldingCS_CpList04BA,	1,	TQU("\x04BB"),
	0x04BC,	CaseFoldingCS_CpList04BC,	1,	TQU("\x04BD"),
	0x04BE,	CaseFoldingCS_CpList04BE,	1,	TQU("\x04BF"),
	0x04C0,	CaseFoldingCS_CpList04C0,	1,	TQU("\x04CF"),
	0x04C1,	CaseFoldingCS_CpList04C1,	1,	TQU("\x04C2"),
	0x04C3,	CaseFoldingCS_CpList04C3,	1,	TQU("\x04C4"),
	0x04C5,	CaseFoldingCS_CpList04C5,	1,	TQU("\x04C6"),
	0x04C7,	CaseFoldingCS_CpList04C7,	1,	TQU("\x04C8"),
	0x04C9,	CaseFoldingCS_CpList04C9,	1,	TQU("\x04CA"),
	0x04CB,	CaseFoldingCS_CpList04CB,	1,	TQU("\x04CC"),
	0x04CD,	CaseFoldingCS_CpList04CD,	1,	TQU("\x04CE"),
	0x04D0,	CaseFoldingCS_CpList04D0,	1,	TQU("\x04D1"),
	0x04D2,	CaseFoldingCS_CpList04D2,	1,	TQU("\x04D3"),
	0x04D4,	CaseFoldingCS_CpList04D4,	1,	TQU("\x04D5"),
	0x04D6,	CaseFoldingCS_CpList04D6,	1,	TQU("\x04D7"),
	0x04D8,	CaseFoldingCS_CpList04D8,	1,	TQU("\x04D9"),
	0x04DA,	CaseFoldingCS_CpList04DA,	1,	TQU("\x04DB"),
	0x04DC,	CaseFoldingCS_CpList04DC,	1,	TQU("\x04DD"),
	0x04DE,	CaseFoldingCS_CpList04DE,	1,	TQU("\x04DF"),
	0x04E0,	CaseFoldingCS_CpList04E0,	1,	TQU("\x04E1"),
	0x04E2,	CaseFoldingCS_CpList04E2,	1,	TQU("\x04E3"),
	0x04E4,	CaseFoldingCS_CpList04E4,	1,	TQU("\x04E5"),
	0x04E6,	CaseFoldingCS_CpList04E6,	1,	TQU("\x04E7"),
	0x04E8,	CaseFoldingCS_CpList04E8,	1,	TQU("\x04E9"),
	0x04EA,	CaseFoldingCS_CpList04EA,	1,	TQU("\x04EB"),
	0x04EC,	CaseFoldingCS_CpList04EC,	1,	TQU("\x04ED"),
	0x04EE,	CaseFoldingCS_CpList04EE,	1,	TQU("\x04EF"),
	0x04F0,	CaseFoldingCS_CpList04F0,	1,	TQU("\x04F1"),
	0x04F2,	CaseFoldingCS_CpList04F2,	1,	TQU("\x04F3"),
	0x04F4,	CaseFoldingCS_CpList04F4,	1,	TQU("\x04F5"),
	0x04F6,	CaseFoldingCS_CpList04F6,	1,	TQU("\x04F7"),
	0x04F8,	CaseFoldingCS_CpList04F8,	1,	TQU("\x04F9"),
	0x04FA,	CaseFoldingCS_CpList04FA,	1,	TQU("\x04FB"),
	0x04FC,	CaseFoldingCS_CpList04FC,	1,	TQU("\x04FD"),
	0x04FE,	CaseFoldingCS_CpList04FE,	1,	TQU("\x04FF"),
	0x0500,	CaseFoldingCS_CpList0500,	1,	TQU("\x0501"),
	0x0502,	CaseFoldingCS_CpList0502,	1,	TQU("\x0503"),
	0x0504,	CaseFoldingCS_CpList0504,	1,	TQU("\x0505"),
	0x0506,	CaseFoldingCS_CpList0506,	1,	TQU("\x0507"),
	0x0508,	CaseFoldingCS_CpList0508,	1,	TQU("\x0509"),
	0x050A,	CaseFoldingCS_CpList050A,	1,	TQU("\x050B"),
	0x050C,	CaseFoldingCS_CpList050C,	1,	TQU("\x050D"),
	0x050E,	CaseFoldingCS_CpList050E,	1,	TQU("\x050F"),
	0x0510,	CaseFoldingCS_CpList0510,	1,	TQU("\x0511"),
	0x0512,	CaseFoldingCS_CpList0512,	1,	TQU("\x0513"),
	0x0514,	CaseFoldingCS_CpList0514,	1,	TQU("\x0515"),
	0x0516,	CaseFoldingCS_CpList0516,	1,	TQU("\x0517"),
	0x0518,	CaseFoldingCS_CpList0518,	1,	TQU("\x0519"),
	0x051A,	CaseFoldingCS_CpList051A,	1,	TQU("\x051B"),
	0x051C,	CaseFoldingCS_CpList051C,	1,	TQU("\x051D"),
	0x051E,	CaseFoldingCS_CpList051E,	1,	TQU("\x051F"),
	0x0520,	CaseFoldingCS_CpList0520,	1,	TQU("\x0521"),
	0x0522,	CaseFoldingCS_CpList0522,	1,	TQU("\x0523"),
	0x0524,	CaseFoldingCS_CpList0524,	1,	TQU("\x0525"),
	0x0526,	CaseFoldingCS_CpList0526,	1,	TQU("\x0527"),
	0x0531,	CaseFoldingCS_CpList0531,	1,	TQU("\x0561"),
	0x0532,	CaseFoldingCS_CpList0532,	1,	TQU("\x0562"),
	0x0533,	CaseFoldingCS_CpList0533,	1,	TQU("\x0563"),
	0x0534,	CaseFoldingCS_CpList0534,	1,	TQU("\x0564"),
	0x0535,	CaseFoldingCS_CpList0535,	1,	TQU("\x0565"),
	0x0536,	CaseFoldingCS_CpList0536,	1,	TQU("\x0566"),
	0x0537,	CaseFoldingCS_CpList0537,	1,	TQU("\x0567"),
	0x0538,	CaseFoldingCS_CpList0538,	1,	TQU("\x0568"),
	0x0539,	CaseFoldingCS_CpList0539,	1,	TQU("\x0569"),
	0x053A,	CaseFoldingCS_CpList053A,	1,	TQU("\x056A"),
	0x053B,	CaseFoldingCS_CpList053B,	1,	TQU("\x056B"),
	0x053C,	CaseFoldingCS_CpList053C,	1,	TQU("\x056C"),
	0x053D,	CaseFoldingCS_CpList053D,	1,	TQU("\x056D"),
	0x053E,	CaseFoldingCS_CpList053E,	1,	TQU("\x056E"),
	0x053F,	CaseFoldingCS_CpList053F,	1,	TQU("\x056F"),
	0x0540,	CaseFoldingCS_CpList0540,	1,	TQU("\x0570"),
	0x0541,	CaseFoldingCS_CpList0541,	1,	TQU("\x0571"),
	0x0542,	CaseFoldingCS_CpList0542,	1,	TQU("\x0572"),
	0x0543,	CaseFoldingCS_CpList0543,	1,	TQU("\x0573"),
	0x0544,	CaseFoldingCS_CpList0544,	1,	TQU("\x0574"),
	0x0545,	CaseFoldingCS_CpList0545,	1,	TQU("\x0575"),
	0x0546,	CaseFoldingCS_CpList0546,	1,	TQU("\x0576"),
	0x0547,	CaseFoldingCS_CpList0547,	1,	TQU("\x0577"),
	0x0548,	CaseFoldingCS_CpList0548,	1,	TQU("\x0578"),
	0x0549,	CaseFoldingCS_CpList0549,	1,	TQU("\x0579"),
	0x054A,	CaseFoldingCS_CpList054A,	1,	TQU("\x057A"),
	0x054B,	CaseFoldingCS_CpList054B,	1,	TQU("\x057B"),
	0x054C,	CaseFoldingCS_CpList054C,	1,	TQU("\x057C"),
	0x054D,	CaseFoldingCS_CpList054D,	1,	TQU("\x057D"),
	0x054E,	CaseFoldingCS_CpList054E,	1,	TQU("\x057E"),
	0x054F,	CaseFoldingCS_CpList054F,	1,	TQU("\x057F"),
	0x0550,	CaseFoldingCS_CpList0550,	1,	TQU("\x0580"),
	0x0551,	CaseFoldingCS_CpList0551,	1,	TQU("\x0581"),
	0x0552,	CaseFoldingCS_CpList0552,	1,	TQU("\x0582"),
	0x0553,	CaseFoldingCS_CpList0553,	1,	TQU("\x0583"),
	0x0554,	CaseFoldingCS_CpList0554,	1,	TQU("\x0584"),
	0x0555,	CaseFoldingCS_CpList0555,	1,	TQU("\x0585"),
	0x0556,	CaseFoldingCS_CpList0556,	1,	TQU("\x0586"),
	0x10A0,	CaseFoldingCS_CpList10A0,	1,	TQU("\x2D00"),
	0x10A1,	CaseFoldingCS_CpList10A1,	1,	TQU("\x2D01"),
	0x10A2,	CaseFoldingCS_CpList10A2,	1,	TQU("\x2D02"),
	0x10A3,	CaseFoldingCS_CpList10A3,	1,	TQU("\x2D03"),
	0x10A4,	CaseFoldingCS_CpList10A4,	1,	TQU("\x2D04"),
	0x10A5,	CaseFoldingCS_CpList10A5,	1,	TQU("\x2D05"),
	0x10A6,	CaseFoldingCS_CpList10A6,	1,	TQU("\x2D06"),
	0x10A7,	CaseFoldingCS_CpList10A7,	1,	TQU("\x2D07"),
	0x10A8,	CaseFoldingCS_CpList10A8,	1,	TQU("\x2D08"),
	0x10A9,	CaseFoldingCS_CpList10A9,	1,	TQU("\x2D09"),
	0x10AA,	CaseFoldingCS_CpList10AA,	1,	TQU("\x2D0A"),
	0x10AB,	CaseFoldingCS_CpList10AB,	1,	TQU("\x2D0B"),
	0x10AC,	CaseFoldingCS_CpList10AC,	1,	TQU("\x2D0C"),
	0x10AD,	CaseFoldingCS_CpList10AD,	1,	TQU("\x2D0D"),
	0x10AE,	CaseFoldingCS_CpList10AE,	1,	TQU("\x2D0E"),
	0x10AF,	CaseFoldingCS_CpList10AF,	1,	TQU("\x2D0F"),
	0x10B0,	CaseFoldingCS_CpList10B0,	1,	TQU("\x2D10"),
	0x10B1,	CaseFoldingCS_CpList10B1,	1,	TQU("\x2D11"),
	0x10B2,	CaseFoldingCS_CpList10B2,	1,	TQU("\x2D12"),
	0x10B3,	CaseFoldingCS_CpList10B3,	1,	TQU("\x2D13"),
	0x10B4,	CaseFoldingCS_CpList10B4,	1,	TQU("\x2D14"),
	0x10B5,	CaseFoldingCS_CpList10B5,	1,	TQU("\x2D15"),
	0x10B6,	CaseFoldingCS_CpList10B6,	1,	TQU("\x2D16"),
	0x10B7,	CaseFoldingCS_CpList10B7,	1,	TQU("\x2D17"),
	0x10B8,	CaseFoldingCS_CpList10B8,	1,	TQU("\x2D18"),
	0x10B9,	CaseFoldingCS_CpList10B9,	1,	TQU("\x2D19"),
	0x10BA,	CaseFoldingCS_CpList10BA,	1,	TQU("\x2D1A"),
	0x10BB,	CaseFoldingCS_CpList10BB,	1,	TQU("\x2D1B"),
	0x10BC,	CaseFoldingCS_CpList10BC,	1,	TQU("\x2D1C"),
	0x10BD,	CaseFoldingCS_CpList10BD,	1,	TQU("\x2D1D"),
	0x10BE,	CaseFoldingCS_CpList10BE,	1,	TQU("\x2D1E"),
	0x10BF,	CaseFoldingCS_CpList10BF,	1,	TQU("\x2D1F"),
	0x10C0,	CaseFoldingCS_CpList10C0,	1,	TQU("\x2D20"),
	0x10C1,	CaseFoldingCS_CpList10C1,	1,	TQU("\x2D21"),
	0x10C2,	CaseFoldingCS_CpList10C2,	1,	TQU("\x2D22"),
	0x10C3,	CaseFoldingCS_CpList10C3,	1,	TQU("\x2D23"),
	0x10C4,	CaseFoldingCS_CpList10C4,	1,	TQU("\x2D24"),
	0x10C5,	CaseFoldingCS_CpList10C5,	1,	TQU("\x2D25"),
	0x10C7,	CaseFoldingCS_CpList10C7,	1,	TQU("\x2D27"),
	0x10CD,	CaseFoldingCS_CpList10CD,	1,	TQU("\x2D2D"),
	0x1E00,	CaseFoldingCS_CpList1E00,	1,	TQU("\x1E01"),
	0x1E02,	CaseFoldingCS_CpList1E02,	1,	TQU("\x1E03"),
	0x1E04,	CaseFoldingCS_CpList1E04,	1,	TQU("\x1E05"),
	0x1E06,	CaseFoldingCS_CpList1E06,	1,	TQU("\x1E07"),
	0x1E08,	CaseFoldingCS_CpList1E08,	1,	TQU("\x1E09"),
	0x1E0A,	CaseFoldingCS_CpList1E0A,	1,	TQU("\x1E0B"),
	0x1E0C,	CaseFoldingCS_CpList1E0C,	1,	TQU("\x1E0D"),
	0x1E0E,	CaseFoldingCS_CpList1E0E,	1,	TQU("\x1E0F"),
	0x1E10,	CaseFoldingCS_CpList1E10,	1,	TQU("\x1E11"),
	0x1E12,	CaseFoldingCS_CpList1E12,	1,	TQU("\x1E13"),
	0x1E14,	CaseFoldingCS_CpList1E14,	1,	TQU("\x1E15"),
	0x1E16,	CaseFoldingCS_CpList1E16,	1,	TQU("\x1E17"),
	0x1E18,	CaseFoldingCS_CpList1E18,	1,	TQU("\x1E19"),
	0x1E1A,	CaseFoldingCS_CpList1E1A,	1,	TQU("\x1E1B"),
	0x1E1C,	CaseFoldingCS_CpList1E1C,	1,	TQU("\x1E1D"),
	0x1E1E,	CaseFoldingCS_CpList1E1E,	1,	TQU("\x1E1F"),
	0x1E20,	CaseFoldingCS_CpList1E20,	1,	TQU("\x1E21"),
	0x1E22,	CaseFoldingCS_CpList1E22,	1,	TQU("\x1E23"),
	0x1E24,	CaseFoldingCS_CpList1E24,	1,	TQU("\x1E25"),
	0x1E26,	CaseFoldingCS_CpList1E26,	1,	TQU("\x1E27"),
	0x1E28,	CaseFoldingCS_CpList1E28,	1,	TQU("\x1E29"),
	0x1E2A,	CaseFoldingCS_CpList1E2A,	1,	TQU("\x1E2B"),
	0x1E2C,	CaseFoldingCS_CpList1E2C,	1,	TQU("\x1E2D"),
	0x1E2E,	CaseFoldingCS_CpList1E2E,	1,	TQU("\x1E2F"),
	0x1E30,	CaseFoldingCS_CpList1E30,	1,	TQU("\x1E31"),
	0x1E32,	CaseFoldingCS_CpList1E32,	1,	TQU("\x1E33"),
	0x1E34,	CaseFoldingCS_CpList1E34,	1,	TQU("\x1E35"),
	0x1E36,	CaseFoldingCS_CpList1E36,	1,	TQU("\x1E37"),
	0x1E38,	CaseFoldingCS_CpList1E38,	1,	TQU("\x1E39"),
	0x1E3A,	CaseFoldingCS_CpList1E3A,	1,	TQU("\x1E3B"),
	0x1E3C,	CaseFoldingCS_CpList1E3C,	1,	TQU("\x1E3D"),
	0x1E3E,	CaseFoldingCS_CpList1E3E,	1,	TQU("\x1E3F"),
	0x1E40,	CaseFoldingCS_CpList1E40,	1,	TQU("\x1E41"),
	0x1E42,	CaseFoldingCS_CpList1E42,	1,	TQU("\x1E43"),
	0x1E44,	CaseFoldingCS_CpList1E44,	1,	TQU("\x1E45"),
	0x1E46,	CaseFoldingCS_CpList1E46,	1,	TQU("\x1E47"),
	0x1E48,	CaseFoldingCS_CpList1E48,	1,	TQU("\x1E49"),
	0x1E4A,	CaseFoldingCS_CpList1E4A,	1,	TQU("\x1E4B"),
	0x1E4C,	CaseFoldingCS_CpList1E4C,	1,	TQU("\x1E4D"),
	0x1E4E,	CaseFoldingCS_CpList1E4E,	1,	TQU("\x1E4F"),
	0x1E50,	CaseFoldingCS_CpList1E50,	1,	TQU("\x1E51"),
	0x1E52,	CaseFoldingCS_CpList1E52,	1,	TQU("\x1E53"),
	0x1E54,	CaseFoldingCS_CpList1E54,	1,	TQU("\x1E55"),
	0x1E56,	CaseFoldingCS_CpList1E56,	1,	TQU("\x1E57"),
	0x1E58,	CaseFoldingCS_CpList1E58,	1,	TQU("\x1E59"),
	0x1E5A,	CaseFoldingCS_CpList1E5A,	1,	TQU("\x1E5B"),
	0x1E5C,	CaseFoldingCS_CpList1E5C,	1,	TQU("\x1E5D"),
	0x1E5E,	CaseFoldingCS_CpList1E5E,	1,	TQU("\x1E5F"),
	0x1E60,	CaseFoldingCS_CpList1E60,	1,	TQU("\x1E61"),
	0x1E62,	CaseFoldingCS_CpList1E62,	1,	TQU("\x1E63"),
	0x1E64,	CaseFoldingCS_CpList1E64,	1,	TQU("\x1E65"),
	0x1E66,	CaseFoldingCS_CpList1E66,	1,	TQU("\x1E67"),
	0x1E68,	CaseFoldingCS_CpList1E68,	1,	TQU("\x1E69"),
	0x1E6A,	CaseFoldingCS_CpList1E6A,	1,	TQU("\x1E6B"),
	0x1E6C,	CaseFoldingCS_CpList1E6C,	1,	TQU("\x1E6D"),
	0x1E6E,	CaseFoldingCS_CpList1E6E,	1,	TQU("\x1E6F"),
	0x1E70,	CaseFoldingCS_CpList1E70,	1,	TQU("\x1E71"),
	0x1E72,	CaseFoldingCS_CpList1E72,	1,	TQU("\x1E73"),
	0x1E74,	CaseFoldingCS_CpList1E74,	1,	TQU("\x1E75"),
	0x1E76,	CaseFoldingCS_CpList1E76,	1,	TQU("\x1E77"),
	0x1E78,	CaseFoldingCS_CpList1E78,	1,	TQU("\x1E79"),
	0x1E7A,	CaseFoldingCS_CpList1E7A,	1,	TQU("\x1E7B"),
	0x1E7C,	CaseFoldingCS_CpList1E7C,	1,	TQU("\x1E7D"),
	0x1E7E,	CaseFoldingCS_CpList1E7E,	1,	TQU("\x1E7F"),
	0x1E80,	CaseFoldingCS_CpList1E80,	1,	TQU("\x1E81"),
	0x1E82,	CaseFoldingCS_CpList1E82,	1,	TQU("\x1E83"),
	0x1E84,	CaseFoldingCS_CpList1E84,	1,	TQU("\x1E85"),
	0x1E86,	CaseFoldingCS_CpList1E86,	1,	TQU("\x1E87"),
	0x1E88,	CaseFoldingCS_CpList1E88,	1,	TQU("\x1E89"),
	0x1E8A,	CaseFoldingCS_CpList1E8A,	1,	TQU("\x1E8B"),
	0x1E8C,	CaseFoldingCS_CpList1E8C,	1,	TQU("\x1E8D"),
	0x1E8E,	CaseFoldingCS_CpList1E8E,	1,	TQU("\x1E8F"),
	0x1E90,	CaseFoldingCS_CpList1E90,	1,	TQU("\x1E91"),
	0x1E92,	CaseFoldingCS_CpList1E92,	1,	TQU("\x1E93"),
	0x1E94,	CaseFoldingCS_CpList1E94,	1,	TQU("\x1E95"),
	0x1E9B,	CaseFoldingCS_CpList1E9B,	1,	TQU("\x1E61"),
	0x1E9E,	CaseFoldingCS_CpList1E9E,	1,	TQU("\x00DF"),
	0x1EA0,	CaseFoldingCS_CpList1EA0,	1,	TQU("\x1EA1"),
	0x1EA2,	CaseFoldingCS_CpList1EA2,	1,	TQU("\x1EA3"),
	0x1EA4,	CaseFoldingCS_CpList1EA4,	1,	TQU("\x1EA5"),
	0x1EA6,	CaseFoldingCS_CpList1EA6,	1,	TQU("\x1EA7"),
	0x1EA8,	CaseFoldingCS_CpList1EA8,	1,	TQU("\x1EA9"),
	0x1EAA,	CaseFoldingCS_CpList1EAA,	1,	TQU("\x1EAB"),
	0x1EAC,	CaseFoldingCS_CpList1EAC,	1,	TQU("\x1EAD"),
	0x1EAE,	CaseFoldingCS_CpList1EAE,	1,	TQU("\x1EAF"),
	0x1EB0,	CaseFoldingCS_CpList1EB0,	1,	TQU("\x1EB1"),
	0x1EB2,	CaseFoldingCS_CpList1EB2,	1,	TQU("\x1EB3"),
	0x1EB4,	CaseFoldingCS_CpList1EB4,	1,	TQU("\x1EB5"),
	0x1EB6,	CaseFoldingCS_CpList1EB6,	1,	TQU("\x1EB7"),
	0x1EB8,	CaseFoldingCS_CpList1EB8,	1,	TQU("\x1EB9"),
	0x1EBA,	CaseFoldingCS_CpList1EBA,	1,	TQU("\x1EBB"),
	0x1EBC,	CaseFoldingCS_CpList1EBC,	1,	TQU("\x1EBD"),
	0x1EBE,	CaseFoldingCS_CpList1EBE,	1,	TQU("\x1EBF"),
	0x1EC0,	CaseFoldingCS_CpList1EC0,	1,	TQU("\x1EC1"),
	0x1EC2,	CaseFoldingCS_CpList1EC2,	1,	TQU("\x1EC3"),
	0x1EC4,	CaseFoldingCS_CpList1EC4,	1,	TQU("\x1EC5"),
	0x1EC6,	CaseFoldingCS_CpList1EC6,	1,	TQU("\x1EC7"),
	0x1EC8,	CaseFoldingCS_CpList1EC8,	1,	TQU("\x1EC9"),
	0x1ECA,	CaseFoldingCS_CpList1ECA,	1,	TQU("\x1ECB"),
	0x1ECC,	CaseFoldingCS_CpList1ECC,	1,	TQU("\x1ECD"),
	0x1ECE,	CaseFoldingCS_CpList1ECE,	1,	TQU("\x1ECF"),
	0x1ED0,	CaseFoldingCS_CpList1ED0,	1,	TQU("\x1ED1"),
	0x1ED2,	CaseFoldingCS_CpList1ED2,	1,	TQU("\x1ED3"),
	0x1ED4,	CaseFoldingCS_CpList1ED4,	1,	TQU("\x1ED5"),
	0x1ED6,	CaseFoldingCS_CpList1ED6,	1,	TQU("\x1ED7"),
	0x1ED8,	CaseFoldingCS_CpList1ED8,	1,	TQU("\x1ED9"),
	0x1EDA,	CaseFoldingCS_CpList1EDA,	1,	TQU("\x1EDB"),
	0x1EDC,	CaseFoldingCS_CpList1EDC,	1,	TQU("\x1EDD"),
	0x1EDE,	CaseFoldingCS_CpList1EDE,	1,	TQU("\x1EDF"),
	0x1EE0,	CaseFoldingCS_CpList1EE0,	1,	TQU("\x1EE1"),
	0x1EE2,	CaseFoldingCS_CpList1EE2,	1,	TQU("\x1EE3"),
	0x1EE4,	CaseFoldingCS_CpList1EE4,	1,	TQU("\x1EE5"),
	0x1EE6,	CaseFoldingCS_CpList1EE6,	1,	TQU("\x1EE7"),
	0x1EE8,	CaseFoldingCS_CpList1EE8,	1,	TQU("\x1EE9"),
	0x1EEA,	CaseFoldingCS_CpList1EEA,	1,	TQU("\x1EEB"),
	0x1EEC,	CaseFoldingCS_CpList1EEC,	1,	TQU("\x1EED"),
	0x1EEE,	CaseFoldingCS_CpList1EEE,	1,	TQU("\x1EEF"),
	0x1EF0,	CaseFoldingCS_CpList1EF0,	1,	TQU("\x1EF1"),
	0x1EF2,	CaseFoldingCS_CpList1EF2,	1,	TQU("\x1EF3"),
	0x1EF4,	CaseFoldingCS_CpList1EF4,	1,	TQU("\x1EF5"),
	0x1EF6,	CaseFoldingCS_CpList1EF6,	1,	TQU("\x1EF7"),
	0x1EF8,	CaseFoldingCS_CpList1EF8,	1,	TQU("\x1EF9"),
	0x1EFA,	CaseFoldingCS_CpList1EFA,	1,	TQU("\x1EFB"),
	0x1EFC,	CaseFoldingCS_CpList1EFC,	1,	TQU("\x1EFD"),
	0x1EFE,	CaseFoldingCS_CpList1EFE,	1,	TQU("\x1EFF"),
	0x1F08,	CaseFoldingCS_CpList1F08,	1,	TQU("\x1F00"),
	0x1F09,	CaseFoldingCS_CpList1F09,	1,	TQU("\x1F01"),
	0x1F0A,	CaseFoldingCS_CpList1F0A,	1,	TQU("\x1F02"),
	0x1F0B,	CaseFoldingCS_CpList1F0B,	1,	TQU("\x1F03"),
	0x1F0C,	CaseFoldingCS_CpList1F0C,	1,	TQU("\x1F04"),
	0x1F0D,	CaseFoldingCS_CpList1F0D,	1,	TQU("\x1F05"),
	0x1F0E,	CaseFoldingCS_CpList1F0E,	1,	TQU("\x1F06"),
	0x1F0F,	CaseFoldingCS_CpList1F0F,	1,	TQU("\x1F07"),
	0x1F18,	CaseFoldingCS_CpList1F18,	1,	TQU("\x1F10"),
	0x1F19,	CaseFoldingCS_CpList1F19,	1,	TQU("\x1F11"),
	0x1F1A,	CaseFoldingCS_CpList1F1A,	1,	TQU("\x1F12"),
	0x1F1B,	CaseFoldingCS_CpList1F1B,	1,	TQU("\x1F13"),
	0x1F1C,	CaseFoldingCS_CpList1F1C,	1,	TQU("\x1F14"),
	0x1F1D,	CaseFoldingCS_CpList1F1D,	1,	TQU("\x1F15"),
	0x1F28,	CaseFoldingCS_CpList1F28,	1,	TQU("\x1F20"),
	0x1F29,	CaseFoldingCS_CpList1F29,	1,	TQU("\x1F21"),
	0x1F2A,	CaseFoldingCS_CpList1F2A,	1,	TQU("\x1F22"),
	0x1F2B,	CaseFoldingCS_CpList1F2B,	1,	TQU("\x1F23"),
	0x1F2C,	CaseFoldingCS_CpList1F2C,	1,	TQU("\x1F24"),
	0x1F2D,	CaseFoldingCS_CpList1F2D,	1,	TQU("\x1F25"),
	0x1F2E,	CaseFoldingCS_CpList1F2E,	1,	TQU("\x1F26"),
	0x1F2F,	CaseFoldingCS_CpList1F2F,	1,	TQU("\x1F27"),
	0x1F38,	CaseFoldingCS_CpList1F38,	1,	TQU("\x1F30"),
	0x1F39,	CaseFoldingCS_CpList1F39,	1,	TQU("\x1F31"),
	0x1F3A,	CaseFoldingCS_CpList1F3A,	1,	TQU("\x1F32"),
	0x1F3B,	CaseFoldingCS_CpList1F3B,	1,	TQU("\x1F33"),
	0x1F3C,	CaseFoldingCS_CpList1F3C,	1,	TQU("\x1F34"),
	0x1F3D,	CaseFoldingCS_CpList1F3D,	1,	TQU("\x1F35"),
	0x1F3E,	CaseFoldingCS_CpList1F3E,	1,	TQU("\x1F36"),
	0x1F3F,	CaseFoldingCS_CpList1F3F,	1,	TQU("\x1F37"),
	0x1F48,	CaseFoldingCS_CpList1F48,	1,	TQU("\x1F40"),
	0x1F49,	CaseFoldingCS_CpList1F49,	1,	TQU("\x1F41"),
	0x1F4A,	CaseFoldingCS_CpList1F4A,	1,	TQU("\x1F42"),
	0x1F4B,	CaseFoldingCS_CpList1F4B,	1,	TQU("\x1F43"),
	0x1F4C,	CaseFoldingCS_CpList1F4C,	1,	TQU("\x1F44"),
	0x1F4D,	CaseFoldingCS_CpList1F4D,	1,	TQU("\x1F45"),
	0x1F59,	CaseFoldingCS_CpList1F59,	1,	TQU("\x1F51"),
	0x1F5B,	CaseFoldingCS_CpList1F5B,	1,	TQU("\x1F53"),
	0x1F5D,	CaseFoldingCS_CpList1F5D,	1,	TQU("\x1F55"),
	0x1F5F,	CaseFoldingCS_CpList1F5F,	1,	TQU("\x1F57"),
	0x1F68,	CaseFoldingCS_CpList1F68,	1,	TQU("\x1F60"),
	0x1F69,	CaseFoldingCS_CpList1F69,	1,	TQU("\x1F61"),
	0x1F6A,	CaseFoldingCS_CpList1F6A,	1,	TQU("\x1F62"),
	0x1F6B,	CaseFoldingCS_CpList1F6B,	1,	TQU("\x1F63"),
	0x1F6C,	CaseFoldingCS_CpList1F6C,	1,	TQU("\x1F64"),
	0x1F6D,	CaseFoldingCS_CpList1F6D,	1,	TQU("\x1F65"),
	0x1F6E,	CaseFoldingCS_CpList1F6E,	1,	TQU("\x1F66"),
	0x1F6F,	CaseFoldingCS_CpList1F6F,	1,	TQU("\x1F67"),
	0x1F88,	CaseFoldingCS_CpList1F88,	1,	TQU("\x1F80"),
	0x1F89,	CaseFoldingCS_CpList1F89,	1,	TQU("\x1F81"),
	0x1F8A,	CaseFoldingCS_CpList1F8A,	1,	TQU("\x1F82"),
	0x1F8B,	CaseFoldingCS_CpList1F8B,	1,	TQU("\x1F83"),
	0x1F8C,	CaseFoldingCS_CpList1F8C,	1,	TQU("\x1F84"),
	0x1F8D,	CaseFoldingCS_CpList1F8D,	1,	TQU("\x1F85"),
	0x1F8E,	CaseFoldingCS_CpList1F8E,	1,	TQU("\x1F86"),
	0x1F8F,	CaseFoldingCS_CpList1F8F,	1,	TQU("\x1F87"),
	0x1F98,	CaseFoldingCS_CpList1F98,	1,	TQU("\x1F90"),
	0x1F99,	CaseFoldingCS_CpList1F99,	1,	TQU("\x1F91"),
	0x1F9A,	CaseFoldingCS_CpList1F9A,	1,	TQU("\x1F92"),
	0x1F9B,	CaseFoldingCS_CpList1F9B,	1,	TQU("\x1F93"),
	0x1F9C,	CaseFoldingCS_CpList1F9C,	1,	TQU("\x1F94"),
	0x1F9D,	CaseFoldingCS_CpList1F9D,	1,	TQU("\x1F95"),
	0x1F9E,	CaseFoldingCS_CpList1F9E,	1,	TQU("\x1F96"),
	0x1F9F,	CaseFoldingCS_CpList1F9F,	1,	TQU("\x1F97"),
	0x1FA8,	CaseFoldingCS_CpList1FA8,	1,	TQU("\x1FA0"),
	0x1FA9,	CaseFoldingCS_CpList1FA9,	1,	TQU("\x1FA1"),
	0x1FAA,	CaseFoldingCS_CpList1FAA,	1,	TQU("\x1FA2"),
	0x1FAB,	CaseFoldingCS_CpList1FAB,	1,	TQU("\x1FA3"),
	0x1FAC,	CaseFoldingCS_CpList1FAC,	1,	TQU("\x1FA4"),
	0x1FAD,	CaseFoldingCS_CpList1FAD,	1,	TQU("\x1FA5"),
	0x1FAE,	CaseFoldingCS_CpList1FAE,	1,	TQU("\x1FA6"),
	0x1FAF,	CaseFoldingCS_CpList1FAF,	1,	TQU("\x1FA7"),
	0x1FB8,	CaseFoldingCS_CpList1FB8,	1,	TQU("\x1FB0"),
	0x1FB9,	CaseFoldingCS_CpList1FB9,	1,	TQU("\x1FB1"),
	0x1FBA,	CaseFoldingCS_CpList1FBA,	1,	TQU("\x1F70"),
	0x1FBB,	CaseFoldingCS_CpList1FBB,	1,	TQU("\x1F71"),
	0x1FBC,	CaseFoldingCS_CpList1FBC,	1,	TQU("\x1FB3"),
	0x1FBE,	CaseFoldingCS_CpList1FBE,	1,	TQU("\x03B9"),
	0x1FC8,	CaseFoldingCS_CpList1FC8,	1,	TQU("\x1F72"),
	0x1FC9,	CaseFoldingCS_CpList1FC9,	1,	TQU("\x1F73"),
	0x1FCA,	CaseFoldingCS_CpList1FCA,	1,	TQU("\x1F74"),
	0x1FCB,	CaseFoldingCS_CpList1FCB,	1,	TQU("\x1F75"),
	0x1FCC,	CaseFoldingCS_CpList1FCC,	1,	TQU("\x1FC3"),
	0x1FD8,	CaseFoldingCS_CpList1FD8,	1,	TQU("\x1FD0"),
	0x1FD9,	CaseFoldingCS_CpList1FD9,	1,	TQU("\x1FD1"),
	0x1FDA,	CaseFoldingCS_CpList1FDA,	1,	TQU("\x1F76"),
	0x1FDB,	CaseFoldingCS_CpList1FDB,	1,	TQU("\x1F77"),
	0x1FE8,	CaseFoldingCS_CpList1FE8,	1,	TQU("\x1FE0"),
	0x1FE9,	CaseFoldingCS_CpList1FE9,	1,	TQU("\x1FE1"),
	0x1FEA,	CaseFoldingCS_CpList1FEA,	1,	TQU("\x1F7A"),
	0x1FEB,	CaseFoldingCS_CpList1FEB,	1,	TQU("\x1F7B"),
	0x1FEC,	CaseFoldingCS_CpList1FEC,	1,	TQU("\x1FE5"),
	0x1FF8,	CaseFoldingCS_CpList1FF8,	1,	TQU("\x1F78"),
	0x1FF9,	CaseFoldingCS_CpList1FF9,	1,	TQU("\x1F79"),
	0x1FFA,	CaseFoldingCS_CpList1FFA,	1,	TQU("\x1F7C"),
	0x1FFB,	CaseFoldingCS_CpList1FFB,	1,	TQU("\x1F7D"),
	0x1FFC,	CaseFoldingCS_CpList1FFC,	1,	TQU("\x1FF3"),
	0x2126,	CaseFoldingCS_CpList2126,	1,	TQU("\x03C9"),
	0x212A,	CaseFoldingCS_CpList212A,	1,	TQU("\x006B"),
	0x212B,	CaseFoldingCS_CpList212B,	1,	TQU("\x00E5"),
	0x2132,	CaseFoldingCS_CpList2132,	1,	TQU("\x214E"),
	0x2160,	CaseFoldingCS_CpList2160,	1,	TQU("\x2170"),
	0x2161,	CaseFoldingCS_CpList2161,	1,	TQU("\x2171"),
	0x2162,	CaseFoldingCS_CpList2162,	1,	TQU("\x2172"),
	0x2163,	CaseFoldingCS_CpList2163,	1,	TQU("\x2173"),
	0x2164,	CaseFoldingCS_CpList2164,	1,	TQU("\x2174"),
	0x2165,	CaseFoldingCS_CpList2165,	1,	TQU("\x2175"),
	0x2166,	CaseFoldingCS_CpList2166,	1,	TQU("\x2176"),
	0x2167,	CaseFoldingCS_CpList2167,	1,	TQU("\x2177"),
	0x2168,	CaseFoldingCS_CpList2168,	1,	TQU("\x2178"),
	0x2169,	CaseFoldingCS_CpList2169,	1,	TQU("\x2179"),
	0x216A,	CaseFoldingCS_CpList216A,	1,	TQU("\x217A"),
	0x216B,	CaseFoldingCS_CpList216B,	1,	TQU("\x217B"),
	0x216C,	CaseFoldingCS_CpList216C,	1,	TQU("\x217C"),
	0x216D,	CaseFoldingCS_CpList216D,	1,	TQU("\x217D"),
	0x216E,	CaseFoldingCS_CpList216E,	1,	TQU("\x217E"),
	0x216F,	CaseFoldingCS_CpList216F,	1,	TQU("\x217F"),
	0x2183,	CaseFoldingCS_CpList2183,	1,	TQU("\x2184"),
	0x24B6,	CaseFoldingCS_CpList24B6,	1,	TQU("\x24D0"),
	0x24B7,	CaseFoldingCS_CpList24B7,	1,	TQU("\x24D1"),
	0x24B8,	CaseFoldingCS_CpList24B8,	1,	TQU("\x24D2"),
	0x24B9,	CaseFoldingCS_CpList24B9,	1,	TQU("\x24D3"),
	0x24BA,	CaseFoldingCS_CpList24BA,	1,	TQU("\x24D4"),
	0x24BB,	CaseFoldingCS_CpList24BB,	1,	TQU("\x24D5"),
	0x24BC,	CaseFoldingCS_CpList24BC,	1,	TQU("\x24D6"),
	0x24BD,	CaseFoldingCS_CpList24BD,	1,	TQU("\x24D7"),
	0x24BE,	CaseFoldingCS_CpList24BE,	1,	TQU("\x24D8"),
	0x24BF,	CaseFoldingCS_CpList24BF,	1,	TQU("\x24D9"),
	0x24C0,	CaseFoldingCS_CpList24C0,	1,	TQU("\x24DA"),
	0x24C1,	CaseFoldingCS_CpList24C1,	1,	TQU("\x24DB"),
	0x24C2,	CaseFoldingCS_CpList24C2,	1,	TQU("\x24DC"),
	0x24C3,	CaseFoldingCS_CpList24C3,	1,	TQU("\x24DD"),
	0x24C4,	CaseFoldingCS_CpList24C4,	1,	TQU("\x24DE"),
	0x24C5,	CaseFoldingCS_CpList24C5,	1,	TQU("\x24DF"),
	0x24C6,	CaseFoldingCS_CpList24C6,	1,	TQU("\x24E0"),
	0x24C7,	CaseFoldingCS_CpList24C7,	1,	TQU("\x24E1"),
	0x24C8,	CaseFoldingCS_CpList24C8,	1,	TQU("\x24E2"),
	0x24C9,	CaseFoldingCS_CpList24C9,	1,	TQU("\x24E3"),
	0x24CA,	CaseFoldingCS_CpList24CA,	1,	TQU("\x24E4"),
	0x24CB,	CaseFoldingCS_CpList24CB,	1,	TQU("\x24E5"),
	0x24CC,	CaseFoldingCS_CpList24CC,	1,	TQU("\x24E6"),
	0x24CD,	CaseFoldingCS_CpList24CD,	1,	TQU("\x24E7"),
	0x24CE,	CaseFoldingCS_CpList24CE,	1,	TQU("\x24E8"),
	0x24CF,	CaseFoldingCS_CpList24CF,	1,	TQU("\x24E9"),
	0x2C00,	CaseFoldingCS_CpList2C00,	1,	TQU("\x2C30"),
	0x2C01,	CaseFoldingCS_CpList2C01,	1,	TQU("\x2C31"),
	0x2C02,	CaseFoldingCS_CpList2C02,	1,	TQU("\x2C32"),
	0x2C03,	CaseFoldingCS_CpList2C03,	1,	TQU("\x2C33"),
	0x2C04,	CaseFoldingCS_CpList2C04,	1,	TQU("\x2C34"),
	0x2C05,	CaseFoldingCS_CpList2C05,	1,	TQU("\x2C35"),
	0x2C06,	CaseFoldingCS_CpList2C06,	1,	TQU("\x2C36"),
	0x2C07,	CaseFoldingCS_CpList2C07,	1,	TQU("\x2C37"),
	0x2C08,	CaseFoldingCS_CpList2C08,	1,	TQU("\x2C38"),
	0x2C09,	CaseFoldingCS_CpList2C09,	1,	TQU("\x2C39"),
	0x2C0A,	CaseFoldingCS_CpList2C0A,	1,	TQU("\x2C3A"),
	0x2C0B,	CaseFoldingCS_CpList2C0B,	1,	TQU("\x2C3B"),
	0x2C0C,	CaseFoldingCS_CpList2C0C,	1,	TQU("\x2C3C"),
	0x2C0D,	CaseFoldingCS_CpList2C0D,	1,	TQU("\x2C3D"),
	0x2C0E,	CaseFoldingCS_CpList2C0E,	1,	TQU("\x2C3E"),
	0x2C0F,	CaseFoldingCS_CpList2C0F,	1,	TQU("\x2C3F"),
	0x2C10,	CaseFoldingCS_CpList2C10,	1,	TQU("\x2C40"),
	0x2C11,	CaseFoldingCS_CpList2C11,	1,	TQU("\x2C41"),
	0x2C12,	CaseFoldingCS_CpList2C12,	1,	TQU("\x2C42"),
	0x2C13,	CaseFoldingCS_CpList2C13,	1,	TQU("\x2C43"),
	0x2C14,	CaseFoldingCS_CpList2C14,	1,	TQU("\x2C44"),
	0x2C15,	CaseFoldingCS_CpList2C15,	1,	TQU("\x2C45"),
	0x2C16,	CaseFoldingCS_CpList2C16,	1,	TQU("\x2C46"),
	0x2C17,	CaseFoldingCS_CpList2C17,	1,	TQU("\x2C47"),
	0x2C18,	CaseFoldingCS_CpList2C18,	1,	TQU("\x2C48"),
	0x2C19,	CaseFoldingCS_CpList2C19,	1,	TQU("\x2C49"),
	0x2C1A,	CaseFoldingCS_CpList2C1A,	1,	TQU("\x2C4A"),
	0x2C1B,	CaseFoldingCS_CpList2C1B,	1,	TQU("\x2C4B"),
	0x2C1C,	CaseFoldingCS_CpList2C1C,	1,	TQU("\x2C4C"),
	0x2C1D,	CaseFoldingCS_CpList2C1D,	1,	TQU("\x2C4D"),
	0x2C1E,	CaseFoldingCS_CpList2C1E,	1,	TQU("\x2C4E"),
	0x2C1F,	CaseFoldingCS_CpList2C1F,	1,	TQU("\x2C4F"),
	0x2C20,	CaseFoldingCS_CpList2C20,	1,	TQU("\x2C50"),
	0x2C21,	CaseFoldingCS_CpList2C21,	1,	TQU("\x2C51"),
	0x2C22,	CaseFoldingCS_CpList2C22,	1,	TQU("\x2C52"),
	0x2C23,	CaseFoldingCS_CpList2C23,	1,	TQU("\x2C53"),
	0x2C24,	CaseFoldingCS_CpList2C24,	1,	TQU("\x2C54"),
	0x2C25,	CaseFoldingCS_CpList2C25,	1,	TQU("\x2C55"),
	0x2C26,	CaseFoldingCS_CpList2C26,	1,	TQU("\x2C56"),
	0x2C27,	CaseFoldingCS_CpList2C27,	1,	TQU("\x2C57"),
	0x2C28,	CaseFoldingCS_CpList2C28,	1,	TQU("\x2C58"),
	0x2C29,	CaseFoldingCS_CpList2C29,	1,	TQU("\x2C59"),
	0x2C2A,	CaseFoldingCS_CpList2C2A,	1,	TQU("\x2C5A"),
	0x2C2B,	CaseFoldingCS_CpList2C2B,	1,	TQU("\x2C5B"),
	0x2C2C,	CaseFoldingCS_CpList2C2C,	1,	TQU("\x2C5C"),
	0x2C2D,	CaseFoldingCS_CpList2C2D,	1,	TQU("\x2C5D"),
	0x2C2E,	CaseFoldingCS_CpList2C2E,	1,	TQU("\x2C5E"),
	0x2C60,	CaseFoldingCS_CpList2C60,	1,	TQU("\x2C61"),
	0x2C62,	CaseFoldingCS_CpList2C62,	1,	TQU("\x026B"),
	0x2C63,	CaseFoldingCS_CpList2C63,	1,	TQU("\x1D7D"),
	0x2C64,	CaseFoldingCS_CpList2C64,	1,	TQU("\x027D"),
	0x2C67,	CaseFoldingCS_CpList2C67,	1,	TQU("\x2C68"),
	0x2C69,	CaseFoldingCS_CpList2C69,	1,	TQU("\x2C6A"),
	0x2C6B,	CaseFoldingCS_CpList2C6B,	1,	TQU("\x2C6C"),
	0x2C6D,	CaseFoldingCS_CpList2C6D,	1,	TQU("\x0251"),
	0x2C6E,	CaseFoldingCS_CpList2C6E,	1,	TQU("\x0271"),
	0x2C6F,	CaseFoldingCS_CpList2C6F,	1,	TQU("\x0250"),
	0x2C70,	CaseFoldingCS_CpList2C70,	1,	TQU("\x0252"),
	0x2C72,	CaseFoldingCS_CpList2C72,	1,	TQU("\x2C73"),
	0x2C75,	CaseFoldingCS_CpList2C75,	1,	TQU("\x2C76"),
	0x2C7E,	CaseFoldingCS_CpList2C7E,	1,	TQU("\x023F"),
	0x2C7F,	CaseFoldingCS_CpList2C7F,	1,	TQU("\x0240"),
	0x2C80,	CaseFoldingCS_CpList2C80,	1,	TQU("\x2C81"),
	0x2C82,	CaseFoldingCS_CpList2C82,	1,	TQU("\x2C83"),
	0x2C84,	CaseFoldingCS_CpList2C84,	1,	TQU("\x2C85"),
	0x2C86,	CaseFoldingCS_CpList2C86,	1,	TQU("\x2C87"),
	0x2C88,	CaseFoldingCS_CpList2C88,	1,	TQU("\x2C89"),
	0x2C8A,	CaseFoldingCS_CpList2C8A,	1,	TQU("\x2C8B"),
	0x2C8C,	CaseFoldingCS_CpList2C8C,	1,	TQU("\x2C8D"),
	0x2C8E,	CaseFoldingCS_CpList2C8E,	1,	TQU("\x2C8F"),
	0x2C90,	CaseFoldingCS_CpList2C90,	1,	TQU("\x2C91"),
	0x2C92,	CaseFoldingCS_CpList2C92,	1,	TQU("\x2C93"),
	0x2C94,	CaseFoldingCS_CpList2C94,	1,	TQU("\x2C95"),
	0x2C96,	CaseFoldingCS_CpList2C96,	1,	TQU("\x2C97"),
	0x2C98,	CaseFoldingCS_CpList2C98,	1,	TQU("\x2C99"),
	0x2C9A,	CaseFoldingCS_CpList2C9A,	1,	TQU("\x2C9B"),
	0x2C9C,	CaseFoldingCS_CpList2C9C,	1,	TQU("\x2C9D"),
	0x2C9E,	CaseFoldingCS_CpList2C9E,	1,	TQU("\x2C9F"),
	0x2CA0,	CaseFoldingCS_CpList2CA0,	1,	TQU("\x2CA1"),
	0x2CA2,	CaseFoldingCS_CpList2CA2,	1,	TQU("\x2CA3"),
	0x2CA4,	CaseFoldingCS_CpList2CA4,	1,	TQU("\x2CA5"),
	0x2CA6,	CaseFoldingCS_CpList2CA6,	1,	TQU("\x2CA7"),
	0x2CA8,	CaseFoldingCS_CpList2CA8,	1,	TQU("\x2CA9"),
	0x2CAA,	CaseFoldingCS_CpList2CAA,	1,	TQU("\x2CAB"),
	0x2CAC,	CaseFoldingCS_CpList2CAC,	1,	TQU("\x2CAD"),
	0x2CAE,	CaseFoldingCS_CpList2CAE,	1,	TQU("\x2CAF"),
	0x2CB0,	CaseFoldingCS_CpList2CB0,	1,	TQU("\x2CB1"),
	0x2CB2,	CaseFoldingCS_CpList2CB2,	1,	TQU("\x2CB3"),
	0x2CB4,	CaseFoldingCS_CpList2CB4,	1,	TQU("\x2CB5"),
	0x2CB6,	CaseFoldingCS_CpList2CB6,	1,	TQU("\x2CB7"),
	0x2CB8,	CaseFoldingCS_CpList2CB8,	1,	TQU("\x2CB9"),
	0x2CBA,	CaseFoldingCS_CpList2CBA,	1,	TQU("\x2CBB"),
	0x2CBC,	CaseFoldingCS_CpList2CBC,	1,	TQU("\x2CBD"),
	0x2CBE,	CaseFoldingCS_CpList2CBE,	1,	TQU("\x2CBF"),
	0x2CC0,	CaseFoldingCS_CpList2CC0,	1,	TQU("\x2CC1"),
	0x2CC2,	CaseFoldingCS_CpList2CC2,	1,	TQU("\x2CC3"),
	0x2CC4,	CaseFoldingCS_CpList2CC4,	1,	TQU("\x2CC5"),
	0x2CC6,	CaseFoldingCS_CpList2CC6,	1,	TQU("\x2CC7"),
	0x2CC8,	CaseFoldingCS_CpList2CC8,	1,	TQU("\x2CC9"),
	0x2CCA,	CaseFoldingCS_CpList2CCA,	1,	TQU("\x2CCB"),
	0x2CCC,	CaseFoldingCS_CpList2CCC,	1,	TQU("\x2CCD"),
	0x2CCE,	CaseFoldingCS_CpList2CCE,	1,	TQU("\x2CCF"),
	0x2CD0,	CaseFoldingCS_CpList2CD0,	1,	TQU("\x2CD1"),
	0x2CD2,	CaseFoldingCS_CpList2CD2,	1,	TQU("\x2CD3"),
	0x2CD4,	CaseFoldingCS_CpList2CD4,	1,	TQU("\x2CD5"),
	0x2CD6,	CaseFoldingCS_CpList2CD6,	1,	TQU("\x2CD7"),
	0x2CD8,	CaseFoldingCS_CpList2CD8,	1,	TQU("\x2CD9"),
	0x2CDA,	CaseFoldingCS_CpList2CDA,	1,	TQU("\x2CDB"),
	0x2CDC,	CaseFoldingCS_CpList2CDC,	1,	TQU("\x2CDD"),
	0x2CDE,	CaseFoldingCS_CpList2CDE,	1,	TQU("\x2CDF"),
	0x2CE0,	CaseFoldingCS_CpList2CE0,	1,	TQU("\x2CE1"),
	0x2CE2,	CaseFoldingCS_CpList2CE2,	1,	TQU("\x2CE3"),
	0x2CEB,	CaseFoldingCS_CpList2CEB,	1,	TQU("\x2CEC"),
	0x2CED,	CaseFoldingCS_CpList2CED,	1,	TQU("\x2CEE"),
	0x2CF2,	CaseFoldingCS_CpList2CF2,	1,	TQU("\x2CF3"),
	0xA640,	CaseFoldingCS_CpListA640,	1,	TQU("\xA641"),
	0xA642,	CaseFoldingCS_CpListA642,	1,	TQU("\xA643"),
	0xA644,	CaseFoldingCS_CpListA644,	1,	TQU("\xA645"),
	0xA646,	CaseFoldingCS_CpListA646,	1,	TQU("\xA647"),
	0xA648,	CaseFoldingCS_CpListA648,	1,	TQU("\xA649"),
	0xA64A,	CaseFoldingCS_CpListA64A,	1,	TQU("\xA64B"),
	0xA64C,	CaseFoldingCS_CpListA64C,	1,	TQU("\xA64D"),
	0xA64E,	CaseFoldingCS_CpListA64E,	1,	TQU("\xA64F"),
	0xA650,	CaseFoldingCS_CpListA650,	1,	TQU("\xA651"),
	0xA652,	CaseFoldingCS_CpListA652,	1,	TQU("\xA653"),
	0xA654,	CaseFoldingCS_CpListA654,	1,	TQU("\xA655"),
	0xA656,	CaseFoldingCS_CpListA656,	1,	TQU("\xA657"),
	0xA658,	CaseFoldingCS_CpListA658,	1,	TQU("\xA659"),
	0xA65A,	CaseFoldingCS_CpListA65A,	1,	TQU("\xA65B"),
	0xA65C,	CaseFoldingCS_CpListA65C,	1,	TQU("\xA65D"),
	0xA65E,	CaseFoldingCS_CpListA65E,	1,	TQU("\xA65F"),
	0xA660,	CaseFoldingCS_CpListA660,	1,	TQU("\xA661"),
	0xA662,	CaseFoldingCS_CpListA662,	1,	TQU("\xA663"),
	0xA664,	CaseFoldingCS_CpListA664,	1,	TQU("\xA665"),
	0xA666,	CaseFoldingCS_CpListA666,	1,	TQU("\xA667"),
	0xA668,	CaseFoldingCS_CpListA668,	1,	TQU("\xA669"),
	0xA66A,	CaseFoldingCS_CpListA66A,	1,	TQU("\xA66B"),
	0xA66C,	CaseFoldingCS_CpListA66C,	1,	TQU("\xA66D"),
	0xA680,	CaseFoldingCS_CpListA680,	1,	TQU("\xA681"),
	0xA682,	CaseFoldingCS_CpListA682,	1,	TQU("\xA683"),
	0xA684,	CaseFoldingCS_CpListA684,	1,	TQU("\xA685"),
	0xA686,	CaseFoldingCS_CpListA686,	1,	TQU("\xA687"),
	0xA688,	CaseFoldingCS_CpListA688,	1,	TQU("\xA689"),
	0xA68A,	CaseFoldingCS_CpListA68A,	1,	TQU("\xA68B"),
	0xA68C,	CaseFoldingCS_CpListA68C,	1,	TQU("\xA68D"),
	0xA68E,	CaseFoldingCS_CpListA68E,	1,	TQU("\xA68F"),
	0xA690,	CaseFoldingCS_CpListA690,	1,	TQU("\xA691"),
	0xA692,	CaseFoldingCS_CpListA692,	1,	TQU("\xA693"),
	0xA694,	CaseFoldingCS_CpListA694,	1,	TQU("\xA695"),
	0xA696,	CaseFoldingCS_CpListA696,	1,	TQU("\xA697"),
	0xA722,	CaseFoldingCS_CpListA722,	1,	TQU("\xA723"),
	0xA724,	CaseFoldingCS_CpListA724,	1,	TQU("\xA725"),
	0xA726,	CaseFoldingCS_CpListA726,	1,	TQU("\xA727"),
	0xA728,	CaseFoldingCS_CpListA728,	1,	TQU("\xA729"),
	0xA72A,	CaseFoldingCS_CpListA72A,	1,	TQU("\xA72B"),
	0xA72C,	CaseFoldingCS_CpListA72C,	1,	TQU("\xA72D"),
	0xA72E,	CaseFoldingCS_CpListA72E,	1,	TQU("\xA72F"),
	0xA732,	CaseFoldingCS_CpListA732,	1,	TQU("\xA733"),
	0xA734,	CaseFoldingCS_CpListA734,	1,	TQU("\xA735"),
	0xA736,	CaseFoldingCS_CpListA736,	1,	TQU("\xA737"),
	0xA738,	CaseFoldingCS_CpListA738,	1,	TQU("\xA739"),
	0xA73A,	CaseFoldingCS_CpListA73A,	1,	TQU("\xA73B"),
	0xA73C,	CaseFoldingCS_CpListA73C,	1,	TQU("\xA73D"),
	0xA73E,	CaseFoldingCS_CpListA73E,	1,	TQU("\xA73F"),
	0xA740,	CaseFoldingCS_CpListA740,	1,	TQU("\xA741"),
	0xA742,	CaseFoldingCS_CpListA742,	1,	TQU("\xA743"),
	0xA744,	CaseFoldingCS_CpListA744,	1,	TQU("\xA745"),
	0xA746,	CaseFoldingCS_CpListA746,	1,	TQU("\xA747"),
	0xA748,	CaseFoldingCS_CpListA748,	1,	TQU("\xA749"),
	0xA74A,	CaseFoldingCS_CpListA74A,	1,	TQU("\xA74B"),
	0xA74C,	CaseFoldingCS_CpListA74C,	1,	TQU("\xA74D"),
	0xA74E,	CaseFoldingCS_CpListA74E,	1,	TQU("\xA74F"),
	0xA750,	CaseFoldingCS_CpListA750,	1,	TQU("\xA751"),
	0xA752,	CaseFoldingCS_CpListA752,	1,	TQU("\xA753"),
	0xA754,	CaseFoldingCS_CpListA754,	1,	TQU("\xA755"),
	0xA756,	CaseFoldingCS_CpListA756,	1,	TQU("\xA757"),
	0xA758,	CaseFoldingCS_CpListA758,	1,	TQU("\xA759"),
	0xA75A,	CaseFoldingCS_CpListA75A,	1,	TQU("\xA75B"),
	0xA75C,	CaseFoldingCS_CpListA75C,	1,	TQU("\xA75D"),
	0xA75E,	CaseFoldingCS_CpListA75E,	1,	TQU("\xA75F"),
	0xA760,	CaseFoldingCS_CpListA760,	1,	TQU("\xA761"),
	0xA762,	CaseFoldingCS_CpListA762,	1,	TQU("\xA763"),
	0xA764,	CaseFoldingCS_CpListA764,	1,	TQU("\xA765"),
	0xA766,	CaseFoldingCS_CpListA766,	1,	TQU("\xA767"),
	0xA768,	CaseFoldingCS_CpListA768,	1,	TQU("\xA769"),
	0xA76A,	CaseFoldingCS_CpListA76A,	1,	TQU("\xA76B"),
	0xA76C,	CaseFoldingCS_CpListA76C,	1,	TQU("\xA76D"),
	0xA76E,	CaseFoldingCS_CpListA76E,	1,	TQU("\xA76F"),
	0xA779,	CaseFoldingCS_CpListA779,	1,	TQU("\xA77A"),
	0xA77B,	CaseFoldingCS_CpListA77B,	1,	TQU("\xA77C"),
	0xA77D,	CaseFoldingCS_CpListA77D,	1,	TQU("\x1D79"),
	0xA77E,	CaseFoldingCS_CpListA77E,	1,	TQU("\xA77F"),
	0xA780,	CaseFoldingCS_CpListA780,	1,	TQU("\xA781"),
	0xA782,	CaseFoldingCS_CpListA782,	1,	TQU("\xA783"),
	0xA784,	CaseFoldingCS_CpListA784,	1,	TQU("\xA785"),
	0xA786,	CaseFoldingCS_CpListA786,	1,	TQU("\xA787"),
	0xA78B,	CaseFoldingCS_CpListA78B,	1,	TQU("\xA78C"),
	0xA78D,	CaseFoldingCS_CpListA78D,	1,	TQU("\x0265"),
	0xA790,	CaseFoldingCS_CpListA790,	1,	TQU("\xA791"),
	0xA792,	CaseFoldingCS_CpListA792,	1,	TQU("\xA793"),
	0xA7A0,	CaseFoldingCS_CpListA7A0,	1,	TQU("\xA7A1"),
	0xA7A2,	CaseFoldingCS_CpListA7A2,	1,	TQU("\xA7A3"),
	0xA7A4,	CaseFoldingCS_CpListA7A4,	1,	TQU("\xA7A5"),
	0xA7A6,	CaseFoldingCS_CpListA7A6,	1,	TQU("\xA7A7"),
	0xA7A8,	CaseFoldingCS_CpListA7A8,	1,	TQU("\xA7A9"),
	0xA7AA,	CaseFoldingCS_CpListA7AA,	1,	TQU("\x0266"),
	0xFF21,	CaseFoldingCS_CpListFF21,	1,	TQU("\xFF41"),
	0xFF22,	CaseFoldingCS_CpListFF22,	1,	TQU("\xFF42"),
	0xFF23,	CaseFoldingCS_CpListFF23,	1,	TQU("\xFF43"),
	0xFF24,	CaseFoldingCS_CpListFF24,	1,	TQU("\xFF44"),
	0xFF25,	CaseFoldingCS_CpListFF25,	1,	TQU("\xFF45"),
	0xFF26,	CaseFoldingCS_CpListFF26,	1,	TQU("\xFF46"),
	0xFF27,	CaseFoldingCS_CpListFF27,	1,	TQU("\xFF47"),
	0xFF28,	CaseFoldingCS_CpListFF28,	1,	TQU("\xFF48"),
	0xFF29,	CaseFoldingCS_CpListFF29,	1,	TQU("\xFF49"),
	0xFF2A,	CaseFoldingCS_CpListFF2A,	1,	TQU("\xFF4A"),
	0xFF2B,	CaseFoldingCS_CpListFF2B,	1,	TQU("\xFF4B"),
	0xFF2C,	CaseFoldingCS_CpListFF2C,	1,	TQU("\xFF4C"),
	0xFF2D,	CaseFoldingCS_CpListFF2D,	1,	TQU("\xFF4D"),
	0xFF2E,	CaseFoldingCS_CpListFF2E,	1,	TQU("\xFF4E"),
	0xFF2F,	CaseFoldingCS_CpListFF2F,	1,	TQU("\xFF4F"),
	0xFF30,	CaseFoldingCS_CpListFF30,	1,	TQU("\xFF50"),
	0xFF31,	CaseFoldingCS_CpListFF31,	1,	TQU("\xFF51"),
	0xFF32,	CaseFoldingCS_CpListFF32,	1,	TQU("\xFF52"),
	0xFF33,	CaseFoldingCS_CpListFF33,	1,	TQU("\xFF53"),
	0xFF34,	CaseFoldingCS_CpListFF34,	1,	TQU("\xFF54"),
	0xFF35,	CaseFoldingCS_CpListFF35,	1,	TQU("\xFF55"),
	0xFF36,	CaseFoldingCS_CpListFF36,	1,	TQU("\xFF56"),
	0xFF37,	CaseFoldingCS_CpListFF37,	1,	TQU("\xFF57"),
	0xFF38,	CaseFoldingCS_CpListFF38,	1,	TQU("\xFF58"),
	0xFF39,	CaseFoldingCS_CpListFF39,	1,	TQU("\xFF59"),
	0xFF3A,	CaseFoldingCS_CpListFF3A,	1,	TQU("\xFF5A"),
	0x10400,	CaseFoldingCS_CpList10400,	1,	TQU("\xD801\xDC28"),
	0x10401,	CaseFoldingCS_CpList10401,	1,	TQU("\xD801\xDC29"),
	0x10402,	CaseFoldingCS_CpList10402,	1,	TQU("\xD801\xDC2A"),
	0x10403,	CaseFoldingCS_CpList10403,	1,	TQU("\xD801\xDC2B"),
	0x10404,	CaseFoldingCS_CpList10404,	1,	TQU("\xD801\xDC2C"),
	0x10405,	CaseFoldingCS_CpList10405,	1,	TQU("\xD801\xDC2D"),
	0x10406,	CaseFoldingCS_CpList10406,	1,	TQU("\xD801\xDC2E"),
	0x10407,	CaseFoldingCS_CpList10407,	1,	TQU("\xD801\xDC2F"),
	0x10408,	CaseFoldingCS_CpList10408,	1,	TQU("\xD801\xDC30"),
	0x10409,	CaseFoldingCS_CpList10409,	1,	TQU("\xD801\xDC31"),
	0x1040A,	CaseFoldingCS_CpList1040A,	1,	TQU("\xD801\xDC32"),
	0x1040B,	CaseFoldingCS_CpList1040B,	1,	TQU("\xD801\xDC33"),
	0x1040C,	CaseFoldingCS_CpList1040C,	1,	TQU("\xD801\xDC34"),
	0x1040D,	CaseFoldingCS_CpList1040D,	1,	TQU("\xD801\xDC35"),
	0x1040E,	CaseFoldingCS_CpList1040E,	1,	TQU("\xD801\xDC36"),
	0x1040F,	CaseFoldingCS_CpList1040F,	1,	TQU("\xD801\xDC37"),
	0x10410,	CaseFoldingCS_CpList10410,	1,	TQU("\xD801\xDC38"),
	0x10411,	CaseFoldingCS_CpList10411,	1,	TQU("\xD801\xDC39"),
	0x10412,	CaseFoldingCS_CpList10412,	1,	TQU("\xD801\xDC3A"),
	0x10413,	CaseFoldingCS_CpList10413,	1,	TQU("\xD801\xDC3B"),
	0x10414,	CaseFoldingCS_CpList10414,	1,	TQU("\xD801\xDC3C"),
	0x10415,	CaseFoldingCS_CpList10415,	1,	TQU("\xD801\xDC3D"),
	0x10416,	CaseFoldingCS_CpList10416,	1,	TQU("\xD801\xDC3E"),
	0x10417,	CaseFoldingCS_CpList10417,	1,	TQU("\xD801\xDC3F"),
	0x10418,	CaseFoldingCS_CpList10418,	1,	TQU("\xD801\xDC40"),
	0x10419,	CaseFoldingCS_CpList10419,	1,	TQU("\xD801\xDC41"),
	0x1041A,	CaseFoldingCS_CpList1041A,	1,	TQU("\xD801\xDC42"),
	0x1041B,	CaseFoldingCS_CpList1041B,	1,	TQU("\xD801\xDC43"),
	0x1041C,	CaseFoldingCS_CpList1041C,	1,	TQU("\xD801\xDC44"),
	0x1041D,	CaseFoldingCS_CpList1041D,	1,	TQU("\xD801\xDC45"),
	0x1041E,	CaseFoldingCS_CpList1041E,	1,	TQU("\xD801\xDC46"),
	0x1041F,	CaseFoldingCS_CpList1041F,	1,	TQU("\xD801\xDC47"),
	0x10420,	CaseFoldingCS_CpList10420,	1,	TQU("\xD801\xDC48"),
	0x10421,	CaseFoldingCS_CpList10421,	1,	TQU("\xD801\xDC49"),
	0x10422,	CaseFoldingCS_CpList10422,	1,	TQU("\xD801\xDC4A"),
	0x10423,	CaseFoldingCS_CpList10423,	1,	TQU("\xD801\xDC4B"),
	0x10424,	CaseFoldingCS_CpList10424,	1,	TQU("\xD801\xDC4C"),
	0x10425,	CaseFoldingCS_CpList10425,	1,	TQU("\xD801\xDC4D"),
	0x10426,	CaseFoldingCS_CpList10426,	1,	TQU("\xD801\xDC4E"),
	0x10427,	CaseFoldingCS_CpList10427,	1,	TQU("\xD801\xDC4F"),
};
const size_t	nCaseFolding_CS	= sizeof(siCaseFolding_CS) / sizeof(SCASEFOLDMAP);

//----------------------------------------------------------------------
//	Secial Case Folding	: Codepage List
//----------------------------------------------------------------------
UINT	CaseFoldingTCpList0049[]	= { 0x0131, 0 };
UINT	CaseFoldingTCpList0130[]	= { 0x0069, 0 };

//----------------------------------------------------------------------
//	Secial Case Folding	: Info
//----------------------------------------------------------------------
SCASEFOLDMAP	siCaseFolding_Special[]	=
{
	0x0049,	CaseFoldingTCpList0049,	1,	TQU("\x0131"),
	0x0130,	CaseFoldingTCpList0130,	1,	TQU("\x0069"),
};
const size_t	nCaseFolding_Special	= sizeof(siCaseFolding_Special) / sizeof(SCASEFOLDMAP);


//======================================================================
//	ひらがな、カタカナの小文字と通常の文字の対応
//======================================================================
//----------------------------------------------------------------------
//	Kana Case Folding	: Codepage List
//----------------------------------------------------------------------
UINT	CaseFoldingKCpList3041[]	= { 0x3042, 0 };	//	HIRAGANA LETTER A
UINT	CaseFoldingKCpList3043[]	= { 0x3044, 0 };	//	HIRAGANA LETTER I
UINT	CaseFoldingKCpList3045[]	= { 0x3046, 0 };	//	HIRAGANA LETTER U
UINT	CaseFoldingKCpList3047[]	= { 0x3048, 0 };	//	HIRAGANA LETTER E
UINT	CaseFoldingKCpList3049[]	= { 0x304A, 0 };	//	HIRAGANA LETTER O
UINT	CaseFoldingKCpList3063[]	= { 0x3064, 0 };	//	HIRAGANA LETTER TU
UINT	CaseFoldingKCpList3083[]	= { 0x3084, 0 };	//	HIRAGANA LETTER YA
UINT	CaseFoldingKCpList3085[]	= { 0x3086, 0 };	//	HIRAGANA LETTER YU
UINT	CaseFoldingKCpList3087[]	= { 0x3088, 0 };	//	HIRAGANA LETTER YO
UINT	CaseFoldingKCpList308E[]	= { 0x308F, 0 };	//	HIRAGANA LETTER WA
UINT	CaseFoldingKCpList3095[]	= { 0x304B, 0 };	//	HIRAGANA LETTER KA
UINT	CaseFoldingKCpList3096[]	= { 0x3051, 0 };	//	HIRAGANA LETTER KE
UINT	CaseFoldingKCpList30A1[]	= { 0x30A2, 0 };	//	KATAKANA LETTER A
UINT	CaseFoldingKCpList30A3[]	= { 0x30A4, 0 };	//	KATAKANA LETTER I
UINT	CaseFoldingKCpList30A5[]	= { 0x30A6, 0 };	//	KATAKANA LETTER U
UINT	CaseFoldingKCpList30A7[]	= { 0x30A8, 0 };	//	KATAKANA LETTER E
UINT	CaseFoldingKCpList30A9[]	= { 0x30AA, 0 };	//	KATAKANA LETTER O
UINT	CaseFoldingKCpList30C3[]	= { 0x30C4, 0 };	//	KATAKANA LETTER TU
UINT	CaseFoldingKCpList30E3[]	= { 0x30E4, 0 };	//	KATAKANA LETTER YA
UINT	CaseFoldingKCpList30E5[]	= { 0x30E6, 0 };	//	KATAKANA LETTER YU
UINT	CaseFoldingKCpList30E7[]	= { 0x30E8, 0 };	//	KATAKANA LETTER YO
UINT	CaseFoldingKCpList30EE[]	= { 0x30EF, 0 };	//	KATAKANA LETTER WA
UINT	CaseFoldingKCpList30F5[]	= { 0x30AB, 0 };	//	KATAKANA LETTER KA
UINT	CaseFoldingKCpList30F6[]	= { 0x30B1, 0 };	//	KATAKANA LETTER KE
UINT	CaseFoldingKCpList31F0[]	= { 0x30AF, 0 };	//	KATAKANA LETTER KU
UINT	CaseFoldingKCpList31F1[]	= { 0x30B7, 0 };	//	KATAKANA LETTER SI
UINT	CaseFoldingKCpList31F2[]	= { 0x30B9, 0 };	//	KATAKANA LETTER SU
UINT	CaseFoldingKCpList31F3[]	= { 0x30C8, 0 };	//	KATAKANA LETTER TO
UINT	CaseFoldingKCpList31F4[]	= { 0x30CC, 0 };	//	KATAKANA LETTER NU
UINT	CaseFoldingKCpList31F5[]	= { 0x30CF, 0 };	//	KATAKANA LETTER HA
UINT	CaseFoldingKCpList31F6[]	= { 0x30D2, 0 };	//	KATAKANA LETTER HI
UINT	CaseFoldingKCpList31F7[]	= { 0x30D5, 0 };	//	KATAKANA LETTER HU
UINT	CaseFoldingKCpList31F8[]	= { 0x30D8, 0 };	//	KATAKANA LETTER HE
UINT	CaseFoldingKCpList31F9[]	= { 0x30DB, 0 };	//	KATAKANA LETTER HO
UINT	CaseFoldingKCpList31FA[]	= { 0x30E0, 0 };	//	KATAKANA LETTER MU
UINT	CaseFoldingKCpList31FB[]	= { 0x30E9, 0 };	//	KATAKANA LETTER RA
UINT	CaseFoldingKCpList31FC[]	= { 0x30EA, 0 };	//	KATAKANA LETTER RI
UINT	CaseFoldingKCpList31FD[]	= { 0x30EB, 0 };	//	KATAKANA LETTER RU
UINT	CaseFoldingKCpList31FE[]	= { 0x30EC, 0 };	//	KATAKANA LETTER RE
UINT	CaseFoldingKCpList31FF[]	= { 0x30ED, 0 };	//	KATAKANA LETTER RO
UINT	CaseFoldingKCpListFF67[]	= { 0xFF71, 0 };	//	HALFWIDTH KATAKANA LETTER A
UINT	CaseFoldingKCpListFF68[]	= { 0xFF72, 0 };	//	HALFWIDTH KATAKANA LETTER I
UINT	CaseFoldingKCpListFF69[]	= { 0xFF73, 0 };	//	HALFWIDTH KATAKANA LETTER U
UINT	CaseFoldingKCpListFF6A[]	= { 0xFF74, 0 };	//	HALFWIDTH KATAKANA LETTER E
UINT	CaseFoldingKCpListFF6B[]	= { 0xFF75, 0 };	//	HALFWIDTH KATAKANA LETTER O
UINT	CaseFoldingKCpListFF6C[]	= { 0xFF94, 0 };	//	HALFWIDTH KATAKANA LETTER YA
UINT	CaseFoldingKCpListFF6D[]	= { 0xFF95, 0 };	//	HALFWIDTH KATAKANA LETTER YU
UINT	CaseFoldingKCpListFF6E[]	= { 0xFF96, 0 };	//	HALFWIDTH KATAKANA LETTER YO
UINT	CaseFoldingKCpListFF6F[]	= { 0xFF82, 0 };	//	HALFWIDTH KATAKANA LETTER TU

//----------------------------------------------------------------------
//	Kana Case Folding	: Info
//----------------------------------------------------------------------
SCASEFOLDMAP	siCaseFolding_Kana[]	=
{
	0x3041	/* HIRAGANA LETTER SMALL A */	,	CaseFoldingKCpList3041,	1,	TQU("\x3042"),
	0x3043	/* HIRAGANA LETTER SMALL I */	,	CaseFoldingKCpList3043,	1,	TQU("\x3044"),
	0x3045	/* HIRAGANA LETTER SMALL U */	,	CaseFoldingKCpList3045,	1,	TQU("\x3046"),
	0x3047	/* HIRAGANA LETTER SMALL E */	,	CaseFoldingKCpList3047,	1,	TQU("\x3048"),
	0x3049	/* HIRAGANA LETTER SMALL O */	,	CaseFoldingKCpList3049,	1,	TQU("\x304A"),
	0x3063	/* HIRAGANA LETTER SMALL TU */	,	CaseFoldingKCpList3063,	1,	TQU("\x3064"),
	0x3083	/* HIRAGANA LETTER SMALL YA */	,	CaseFoldingKCpList3083,	1,	TQU("\x3084"),
	0x3085	/* HIRAGANA LETTER SMALL YU */	,	CaseFoldingKCpList3085,	1,	TQU("\x3086"),
	0x3087	/* HIRAGANA LETTER SMALL YO */	,	CaseFoldingKCpList3087,	1,	TQU("\x3088"),
	0x308E	/* HIRAGANA LETTER SMALL WA */	,	CaseFoldingKCpList308E,	1,	TQU("\x308F"),
	0x3095	/* HIRAGANA LETTER SMALL KA */	,	CaseFoldingKCpList3095,	1,	TQU("\x304B"),
	0x3096	/* HIRAGANA LETTER SMALL KE */	,	CaseFoldingKCpList3096,	1,	TQU("\x3051"),
	0x30A1	/* KATAKANA LETTER SMALL A */	,	CaseFoldingKCpList30A1,	1,	TQU("\x30A2"),
	0x30A3	/* KATAKANA LETTER SMALL I */	,	CaseFoldingKCpList30A3,	1,	TQU("\x30A4"),
	0x30A5	/* KATAKANA LETTER SMALL U */	,	CaseFoldingKCpList30A5,	1,	TQU("\x30A6"),
	0x30A7	/* KATAKANA LETTER SMALL E */	,	CaseFoldingKCpList30A7,	1,	TQU("\x30A8"),
	0x30A9	/* KATAKANA LETTER SMALL O */	,	CaseFoldingKCpList30A9,	1,	TQU("\x30AA"),
	0x30C3	/* KATAKANA LETTER SMALL TU */	,	CaseFoldingKCpList30C3,	1,	TQU("\x30C4"),
	0x30E3	/* KATAKANA LETTER SMALL YA */	,	CaseFoldingKCpList30E3,	1,	TQU("\x30E4"),
	0x30E5	/* KATAKANA LETTER SMALL YU */	,	CaseFoldingKCpList30E5,	1,	TQU("\x30E6"),
	0x30E7	/* KATAKANA LETTER SMALL YO */	,	CaseFoldingKCpList30E7,	1,	TQU("\x30E8"),
	0x30EE	/* KATAKANA LETTER SMALL WA */	,	CaseFoldingKCpList30EE,	1,	TQU("\x30EF"),
	0x30F5	/* KATAKANA LETTER SMALL KA */	,	CaseFoldingKCpList30F5,	1,	TQU("\x30AB"),
	0x30F6	/* KATAKANA LETTER SMALL KE */	,	CaseFoldingKCpList30F6,	1,	TQU("\x30B1"),
	0x31F0	/* KATAKANA LETTER SMALL KU */	,	CaseFoldingKCpList31F0,	1,	TQU("\x30AF"),
	0x31F1	/* KATAKANA LETTER SMALL SI */	,	CaseFoldingKCpList31F1,	1,	TQU("\x30B7"),
	0x31F2	/* KATAKANA LETTER SMALL SU */	,	CaseFoldingKCpList31F2,	1,	TQU("\x30B9"),
	0x31F3	/* KATAKANA LETTER SMALL TO */	,	CaseFoldingKCpList31F3,	1,	TQU("\x30C8"),
	0x31F4	/* KATAKANA LETTER SMALL NU */	,	CaseFoldingKCpList31F4,	1,	TQU("\x30CC"),
	0x31F5	/* KATAKANA LETTER SMALL HA */	,	CaseFoldingKCpList31F5,	1,	TQU("\x30CF"),
	0x31F6	/* KATAKANA LETTER SMALL HI */	,	CaseFoldingKCpList31F6,	1,	TQU("\x30D2"),
	0x31F7	/* KATAKANA LETTER SMALL HU */	,	CaseFoldingKCpList31F7,	1,	TQU("\x30D5"),
	0x31F8	/* KATAKANA LETTER SMALL HE */	,	CaseFoldingKCpList31F8,	1,	TQU("\x30D8"),
	0x31F9	/* KATAKANA LETTER SMALL HO */	,	CaseFoldingKCpList31F9,	1,	TQU("\x30DB"),
	0x31FA	/* KATAKANA LETTER SMALL MU */	,	CaseFoldingKCpList31FA,	1,	TQU("\x30E0"),
	0x31FB	/* KATAKANA LETTER SMALL RA */	,	CaseFoldingKCpList31FB,	1,	TQU("\x30E9"),
	0x31FC	/* KATAKANA LETTER SMALL RI */	,	CaseFoldingKCpList31FC,	1,	TQU("\x30EA"),
	0x31FD	/* KATAKANA LETTER SMALL RU */	,	CaseFoldingKCpList31FD,	1,	TQU("\x30EB"),
	0x31FE	/* KATAKANA LETTER SMALL RE */	,	CaseFoldingKCpList31FE,	1,	TQU("\x30EC"),
	0x31FF	/* KATAKANA LETTER SMALL RO */	,	CaseFoldingKCpList31FF,	1,	TQU("\x30ED"),
	0xFF67	/* HALFWIDTH KATAKANA LETTER SMALL A */	,	CaseFoldingKCpListFF67,	1,	TQU("\xFF71"),
	0xFF68	/* HALFWIDTH KATAKANA LETTER SMALL I */	,	CaseFoldingKCpListFF68,	1,	TQU("\xFF72"),
	0xFF69	/* HALFWIDTH KATAKANA LETTER SMALL U */	,	CaseFoldingKCpListFF69,	1,	TQU("\xFF73"),
	0xFF6A	/* HALFWIDTH KATAKANA LETTER SMALL E */	,	CaseFoldingKCpListFF6A,	1,	TQU("\xFF74"),
	0xFF6B	/* HALFWIDTH KATAKANA LETTER SMALL O */	,	CaseFoldingKCpListFF6B,	1,	TQU("\xFF75"),
	0xFF6C	/* HALFWIDTH KATAKANA LETTER SMALL YA */	,	CaseFoldingKCpListFF6C,	1,	TQU("\xFF94"),
	0xFF6D	/* HALFWIDTH KATAKANA LETTER SMALL YU */	,	CaseFoldingKCpListFF6D,	1,	TQU("\xFF95"),
	0xFF6E	/* HALFWIDTH KATAKANA LETTER SMALL YO */	,	CaseFoldingKCpListFF6E,	1,	TQU("\xFF96"),
	0xFF6F	/* HALFWIDTH KATAKANA LETTER SMALL TU */	,	CaseFoldingKCpListFF6F,	1,	TQU("\xFF82"),
};
const size_t	nCaseFolding_Kana	= sizeof(siCaseFolding_Kana) / sizeof(SCASEFOLDMAP);


//======================================================================
//	CaseFolding	(1)	1 個のコードポイントを変換する
//======================================================================
//----------------------------------------------------------------------
//	t_CaseFolding	(1)
//----------------------------------------------------------------------
template<PSCASEFOLDMAP PS_ESPECIAL, size_t Z_ESPECIAL>
bool t_CaseFolding(T_UCP** ppcpDst, int* pnDst, UINT cpSrc)
{
	UINT		uiFound;
	int			iDst;

	if (PLib::BinarySearch<SCASEFOLDMAP, T_UCP>(
		&uiFound, PS_ESPECIAL, Z_ESPECIAL, cpSrc))
	{
		iDst	= PS_ESPECIAL[uiFound].nDst;
		if (iDst >= 1)
		{
			*ppcpDst	= PS_ESPECIAL[uiFound].pcpDst;
			*pnDst		= PS_ESPECIAL[uiFound].nDst;
			return true;
		}
		else
		{
			THROWPE_LOGIC_ERROR("");
		}
	}

	//	見つからなかった場合は元のコードポイントを追加する。
	return false;
}

//----------------------------------------------------------------------
//	CaseFoldingFull	(1)
//----------------------------------------------------------------------
bool CaseFoldingFull(T_UCP** ppcpDst, int* pnDst, T_UCP cpSrc)
{
	if (PUCD_IN_BMP(cpSrc))
	{
		if (PUCD_BMPTABLE_IS_ICASE_F_SET_NC(cpSrc))
		{
			return t_CaseFolding<siCaseFolding_CF, nCaseFolding_CF>(ppcpDst, pnDst, cpSrc);
		}
		return false;
	}
	return t_CaseFolding<siCaseFolding_CF, nCaseFolding_CF>(ppcpDst, pnDst, cpSrc);
}

//----------------------------------------------------------------------
//	CaseFoldingSimple	(1)
//----------------------------------------------------------------------
bool CaseFoldingSimple(T_UCP** ppcpDst, int* pnDst, T_UCP cpSrc)
{
	if (PUCD_IN_BMP(cpSrc))
	{
		if (PUCD_BMPTABLE_IS_ICASE_S_SET_NC(cpSrc))
		{
			return t_CaseFolding<siCaseFolding_CS, nCaseFolding_CS>(ppcpDst, pnDst, cpSrc);
		}
		return false;
	}
	return t_CaseFolding<siCaseFolding_CS, nCaseFolding_CS>(ppcpDst, pnDst, cpSrc);
}

//======================================================================
//	CaseFolding	(2)	Codepoint 列 -> Codepoint 列
//======================================================================
//----------------------------------------------------------------------
//	t_CaseFolding	(2)
//----------------------------------------------------------------------
template<bool (*PF_CASEFOLD)(T_UCP** ppcpDst, int* pnDst, T_UCP cpSrc)>
bool t_CaseFolding(UCPSTRING* pucsDst, UCPSTRING* pucsSrc)
{
	const T_UCP*	pcps;
	T_UCP*			pcpd;
	int				nd;
	//UINT			uiFound;

	for (pcps = pucsSrc->c_str(); *pcps; ++pcps)
	{
		if ((*PF_CASEFOLD)(&pcpd, &nd, *pcps))
		{
			pucsDst->append(pcpd);
		}
		else
		{
			pucsDst->append(1, *pcps);
		}
	}
	return true;
}

//----------------------------------------------------------------------
//	CaseFoldingFull	(2)
//----------------------------------------------------------------------
bool CaseFoldingFull(UCPSTRING* puisDst, UCPSTRING* puisSrc)
{
	return t_CaseFolding<&CaseFoldingFull>(puisDst, puisSrc);
}

//----------------------------------------------------------------------
//	CaseFoldingSimple	(2)
//----------------------------------------------------------------------
bool CaseFoldingSimple(UCPSTRING* puisDst, UCPSTRING* puisSrc)
{
	return t_CaseFolding<&CaseFoldingSimple>(puisDst, puisSrc);
}

//======================================================================
//	CaseFolding	(3-1)	Unicode 文字列 -> Codepoint 列
//======================================================================
//----------------------------------------------------------------------
//	CaseFoldingFull	(3-1)
//----------------------------------------------------------------------
bool CaseFoldingFull(UCPSTRING* puisDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE)
{
	UCPSTRING	uisSrc;

	if (!PLib::Unicode::ConvertToCodepoint(&uisSrc, pSrcB, pSrcE))	return false;
	return CaseFoldingFull(puisDst, &uisSrc);
}

//----------------------------------------------------------------------
//	CaseFoldingSimple	(3-1)
//----------------------------------------------------------------------
bool CaseFoldingSimple(UCPSTRING* puisDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE)
{
	UCPSTRING	uisSrc;

	if (!PLib::Unicode::ConvertToCodepoint(&uisSrc, pSrcB, pSrcE))	return false;
	return CaseFoldingSimple(puisDst, &uisSrc);
}

//======================================================================
//	CaseFolding	(3-2)	NULL 終了 Unicode 文字列 -> Codepoint 列
//======================================================================
//----------------------------------------------------------------------
//	CaseFoldingFull	(3-2)
//----------------------------------------------------------------------
bool CaseFoldingFull(UCPSTRING* puisDst, T_PCSTR_U pszSrc)
{
	UCPSTRING	uisSrc;

	if (!PLib::Unicode::ConvertToCodepoint(&uisSrc, pszSrc))	return false;
	return CaseFoldingFull(puisDst, &uisSrc);
}

//----------------------------------------------------------------------
//	CaseFoldingSimple	(3-2)
//----------------------------------------------------------------------
bool CaseFoldingSimple(UCPSTRING* puisDst, T_PCSTR_U pszSrc)
{
	UCPSTRING	uisSrc;

	if (!PLib::Unicode::ConvertToCodepoint(&uisSrc, pszSrc))	return false;
	return CaseFoldingSimple(puisDst, &uisSrc);
}

//======================================================================
//	CaseFolding	(4)	Codepoint 列 -> Unicode 文字列
//======================================================================
//----------------------------------------------------------------------
//	CaseFoldingFull	(4)
//----------------------------------------------------------------------
bool CaseFoldingFull(T_STRING_U* pstrDst, UCPSTRING* puisSrc)
{
	UCPSTRING	ucsSrc;

	if (!CaseFoldingFull(&ucsSrc, puisSrc))	return false;
	return PLib::Unicode::ConvertFromCodepoint(pstrDst, &ucsSrc);
}

//----------------------------------------------------------------------
//	CaseFoldingSimple	(4)
//----------------------------------------------------------------------
bool CaseFoldingSimple(T_STRING_U* pstrDst, UCPSTRING* puisSrc)
{
	UCPSTRING	ucsSrc;

	if (!CaseFoldingSimple(&ucsSrc, puisSrc))	return false;
	return PLib::Unicode::ConvertFromCodepoint(pstrDst, &ucsSrc);
}

//======================================================================
//	CaseFolding	(5)	Unicode 文字列 -> Unicode 文字列
//======================================================================
//----------------------------------------------------------------------
//	CaseFoldingFull	(5-1)
//----------------------------------------------------------------------
bool CaseFoldingFull(T_STRING_U* pstrDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE)
{
	UCPSTRING	ucsSrc;

	if (!PLib::Unicode::ConvertToCodepoint(&ucsSrc, pSrcB, pSrcE))	return false;
	return CaseFoldingFull(pstrDst, &ucsSrc);
}

//----------------------------------------------------------------------
//	CaseFoldingSimple	(5-1)
//----------------------------------------------------------------------
bool CaseFoldingSimple(T_STRING_U* pstrDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE)
{
	UCPSTRING	ucsSrc;

	if (!PLib::Unicode::ConvertToCodepoint(&ucsSrc, pSrcB, pSrcE))	return false;
	return CaseFoldingSimple(pstrDst, &ucsSrc);
}

//======================================================================
//	CaseFolding	(5-2)	NULL 終了 Unicode 文字列 -> Unicode 文字列
//======================================================================
//----------------------------------------------------------------------
//	CaseFoldingFull	(5-2)
//----------------------------------------------------------------------
bool CaseFoldingFull(T_STRING_U* pstrDst, T_PCSTR_U pSrc)
{
	UCPSTRING	ucsSrc;

	if (!PLib::Unicode::ConvertToCodepoint(&ucsSrc, pSrc))	return false;
	return CaseFoldingFull(pstrDst, &ucsSrc);
}

//----------------------------------------------------------------------
//	CaseFoldingSimple	(5-2)
//----------------------------------------------------------------------
bool CaseFoldingSimple(T_STRING_U* pstrDst, T_PCSTR_U pSrc)
{
	UCPSTRING	ucsSrc;

	if (!PLib::Unicode::ConvertToCodepoint(&ucsSrc, pSrc))	return false;
	return CaseFoldingSimple(pstrDst, &ucsSrc);
}


//======================================================================
//	CaseFoldingKana	(1)	Codepoint の変換
//======================================================================
//----------------------------------------------------------------------
//	CaseFoldingKana	(1-1)
//----------------------------------------------------------------------
bool CaseFoldingKana(T_UCP* pcpDst, T_UCP cpSrc)
{
	UINT		uiFound;

	if (PUCD_BMPTABLE_IS_IKANACASE_SET(cpSrc))
	{
		if (PLib::BinarySearch<SCASEFOLDMAP, T_UCP>(
			&uiFound, siCaseFolding_Kana, nCaseFolding_Kana, cpSrc))
		{
			*pcpDst	= *(siCaseFolding_Kana[uiFound].pcpDst);
			return true;
		}
		return false;
	}
	return false;
}

//----------------------------------------------------------------------
//	CaseFoldingKana	(1-2)
//----------------------------------------------------------------------
T_UCP CaseFoldingKana(T_UCP cpSrc)
{
	UINT		uiFound;

	if (PUCD_BMPTABLE_IS_IKANACASE_SET(cpSrc))
	{
		if (PLib::BinarySearch<SCASEFOLDMAP, UINT>(
			&uiFound, siCaseFolding_Kana, nCaseFolding_Kana, cpSrc))
		{
			return *(siCaseFolding_Kana[uiFound].pcpDst);
		}
		return cpSrc;
	}
	return cpSrc;
}

//======================================================================
//	CaseFoldingKana	(2)	Codepoint 列の変換
//======================================================================
bool CaseFoldingKana(UCPSTRING* puisDst, UCPSTRING* puisSrc)
{
	const UINT*	puis;

	if (puisDst == NULL || puisSrc == NULL)	return false;

	for (puis = puisSrc->c_str(); *puis; ++puis)
	{
		puisDst->append(1, CaseFoldingKana(*puis));
	}
	return true;
}

//======================================================================
//	CaseFoldingKana	(3)	Unicode 文字列 -> Codepoint 列
//======================================================================
bool CaseFoldingKana(UCPSTRING* puisDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE)
{
	UCPSTRING	uisSrc;

	if (!PLib::Unicode::ConvertToCodepoint(&uisSrc, pSrcB, pSrcE))	return false;
	return CaseFoldingKana(puisDst, &uisSrc);
}

bool CaseFoldingKana(UCPSTRING* puisDst, T_PCSTR_U pszSrc)
{
	UCPSTRING	uisSrc;

	if (!PLib::Unicode::ConvertToCodepoint(&uisSrc, pszSrc))	return false;
	return CaseFoldingKana(puisDst, &uisSrc);
}

//======================================================================
//	CaseFoldingKana	(4)	Codepoint 文字列 -> Unicode 列
//======================================================================
bool CaseFoldingKana(T_STRING_U* pstrDst, UCPSTRING* puisSrc)
{
	UINT			uiFound;
	const UINT*		puis;
	T_CHAR_U	Buf[3];

	if (pstrDst == NULL || puisSrc == NULL)	return false;

	for (puis = puisSrc->c_str(); *puis; ++puis)
	{
		if (PLib::BinarySearch<SCASEFOLDMAP, UINT>(
			&uiFound, siCaseFolding_Kana, nCaseFolding_Kana, *puis))
		{
			pstrDst->append(siCaseFolding_Kana[uiFound].pszDst);
		}
		else
		{
			if (PLib::Unicode::ConvertFromCodepoint(Buf, *puis))
			{
				pstrDst->append(Buf);
			}
		}
	}
	return true;
}

//======================================================================
//	CaseFoldingKana	(5)	Unicode 文字列 -> Unicode 列
//======================================================================
bool CaseFoldingKana(T_STRING_U* pstrDst, T_PCSTR_U pSrcB, T_PCSTR_U pSrcE)
{
	UCPSTRING	uisTemp;

	if (!PLib::Unicode::ConvertToCodepoint(&uisTemp, pSrcB, pSrcE))	return false;
	return CaseFoldingKana(pstrDst, &uisTemp);
}

bool CaseFoldingKana(T_STRING_U* pstrDst, T_PCSTR_U pszSrc)
{
	UCPSTRING	uisTemp;

	if (!PLib::Unicode::ConvertToCodepoint(&uisTemp, pszSrc))	return false;
	return CaseFoldingKana(pstrDst, &uisTemp);
}


//======================================================================
//	CICompare	(1)
//======================================================================
//----------------------------------------------------------------------
//	CICompareFull	(1)
//----------------------------------------------------------------------
int CICompareFull(T_PCSTR_U pStr1B, T_PCSTR_U pStr1E,
				 T_PCSTR_U pStr2B, T_PCSTR_U pStr2E)
{
	T_STRING_U	str1, str2;

	if (!CaseFoldingFull(&str1, pStr1B, pStr1E) || !CaseFoldingFull(&str2, pStr2B, pStr2E))
	{
			THROWPE_RUNTIME_ERROR("CICompareFull");
	}

	return t_StrCmp<T_CHAR_U, TRUE>(str1.c_str(), str2.c_str());
}

//----------------------------------------------------------------------
//	CICompareSimple	(1)
//----------------------------------------------------------------------
int CICompareSimple(T_PCSTR_U pStr1B, T_PCSTR_U pStr1E,
				   T_PCSTR_U pStr2B, T_PCSTR_U pStr2E)
{
	T_STRING_U	str1, str2;

	if (!CaseFoldingSimple(&str1, pStr1B, pStr1E) || !CaseFoldingSimple(&str2, pStr2B, pStr2E))
	{
			THROWPE_RUNTIME_ERROR("CICompareSimple");
	}

	return t_StrCmp<T_CHAR_U, TRUE>(str1.c_str(), str2.c_str());
}

//======================================================================
//	CICompare	(2)
//======================================================================
//----------------------------------------------------------------------
//	CICompareFull	(2)
//----------------------------------------------------------------------
int CICompareFull(T_PCSTR_U pStr1, T_PCSTR_U pStr2)
{
	T_STRING_U	str1, str2;

	if (!CaseFoldingFull(&str1, pStr1) || !CaseFoldingFull(&str2, pStr2))
	{
			THROWPE_RUNTIME_ERROR("CICompareFull");
	}

	return t_StrCmp<T_CHAR_U, TRUE>(str1.c_str(), str2.c_str());
}

//----------------------------------------------------------------------
//	CICompareSimple	(1)
//----------------------------------------------------------------------
int CICompareSimple(T_PCSTR_U pStr1, T_PCSTR_U pStr2)
{
	T_STRING_U	str1, str2;

	if (!CaseFoldingSimple(&str1, pStr1) || !CaseFoldingSimple(&str2, pStr2))
	{
			THROWPE_RUNTIME_ERROR("CICompareSimple");
	}

	return t_StrCmp<T_CHAR_U, TRUE>(str1.c_str(), str2.c_str());
}

//======================================================================
//	CICompareN	(1)
//======================================================================
//----------------------------------------------------------------------
//	CICompareNFull	(1)
//----------------------------------------------------------------------
int CICompareNFull(T_PCSTR_U pStr1B, T_PCSTR_U pStr1E,
				  T_PCSTR_U pStr2B, T_PCSTR_U pStr2E, size_t zCount)
{
	T_STRING_U	str1, str2;

	if (!CaseFoldingFull(&str1, pStr1B, pStr1E) || !CaseFoldingFull(&str2, pStr2B, pStr2E))
	{
			THROWPE_RUNTIME_ERROR("CICompareNFull");
	}

	return t_StrNCmp<T_CHAR_U, TRUE>(str1.c_str(), str2.c_str(), zCount);
}

//----------------------------------------------------------------------
//	CICompareNSimple	(1)
//----------------------------------------------------------------------
int CICompareNSimple(T_PCSTR_U pStr1B, T_PCSTR_U pStr1E,
					T_PCSTR_U pStr2B, T_PCSTR_U pStr2E, size_t zCount)
{
	T_STRING_U	str1, str2;

	if (!CaseFoldingSimple(&str1, pStr1B, pStr1E) || !CaseFoldingSimple(&str2, pStr2B, pStr2E))
	{
			THROWPE_RUNTIME_ERROR("CICompareNSimple");
	}

	return t_StrNCmp<T_CHAR_U, TRUE>(str1.c_str(), str2.c_str(), zCount);
}

//======================================================================
//	CICompareN	(2)
//======================================================================
//----------------------------------------------------------------------
//	CICompareNFull	(2)
//----------------------------------------------------------------------
int CICompareNFull(T_PCSTR_U pStr1, T_PCSTR_U pStr2, size_t zCount)
{
	T_STRING_U	str1, str2;

	if (!CaseFoldingFull(&str1, pStr1) || !CaseFoldingFull(&str2, pStr2))
	{
			THROWPE_RUNTIME_ERROR("CICompareNFull");
	}

	return t_StrNCmp<T_CHAR_U, TRUE>(str1.c_str(), str2.c_str(), zCount);
}

//----------------------------------------------------------------------
//	CICompareNSimple	(1)
//----------------------------------------------------------------------
int CICompareNSimple(T_PCSTR_U pStr1, T_PCSTR_U pStr2, size_t zCount)
{
	T_STRING_U	str1, str2;

	if (!CaseFoldingSimple(&str1, pStr1) || !CaseFoldingSimple(&str2, pStr2))
	{
			THROWPE_RUNTIME_ERROR("CICompareNSimple");
	}

	return t_StrNCmp<T_CHAR_U, TRUE>(str1.c_str(), str2.c_str(), zCount);
}

/*
//======================================================================
//	初期化と終了処理
//======================================================================
//----------------------------------------------------------------------
//	InitCaseFolding
//----------------------------------------------------------------------
BOOL InitCaseFolding()
{
	return TRUE;
}

//----------------------------------------------------------------------
//	CleanupCaseFolding
//----------------------------------------------------------------------
void CleanupCaseFolding()
{
}
*/

//======================================================================
//	デバッグ用
//======================================================================
#ifdef	PDEBUG
void ExecTestCaseConvert(T_STRING_U* pstrTest, SCASEFOLDMAP* pData, const size_t nData)
{
	T_PCSTR_U		pszDst;
	T_STRING_U	strCpDst;
	UINT*				pcpDst;
	//int					nCp;
	UINT				i;
	T_CHAR_U		WCBuf[3];
	T_PCSTR_U		pfmt_d	= TQU("%d");
	T_PCSTR_U		pLF		= TQU("\r\n");
	T_PCSTR_U		pHT		= TQU("\t");
	T_PCSTR_U		pTrue	= TQU("○");
	T_PCSTR_U		pFalse	= TQU("×");
	int					nFalse;

	nFalse	= 0;
	for (i = 0; i < nData; ++i, ++pData)
	{
		strCpDst.clear();
		pcpDst	= pData->pcpDst;
		while (*pcpDst != 0)
		{
			if (PLib::Unicode::ConvertFromCodepoint(WCBuf, *pcpDst))
			{
				strCpDst.append(WCBuf);
			}
			++pcpDst;
		}

		pszDst	= pData->pszDst;
		if (PLib::t_StrCmp<T_CHAR_U, TRUE>(pszDst, strCpDst.c_str()))
		{
			pstrTest->append(pFalse);
			++nFalse;
		}
		else
		{
			pstrTest->append(pFalse);
		}
		pstrTest->append(pHT);
		pstrTest->append(pszDst);
		pstrTest->append(pHT);
		pstrTest->append(strCpDst);
		pstrTest->append(pLF);
	}
	PLib::AppendNumToString<T_CHAR_U, int>(pstrTest, pfmt_d, nFalse);
	pstrTest->append(TQU(" failed.\r\n\r\n"));
}

void TestCaseConvert()
{
	T_STRING_U	strTest;

	ExecTestCaseConvert(&strTest, siCaseFolding_CF, nCaseFolding_CF);
	ExecTestCaseConvert(&strTest, siCaseFolding_CS, nCaseFolding_CS);
	ExecTestCaseConvert(&strTest, siCaseFolding_Special, nCaseFolding_Special);
	ExecTestCaseConvert(&strTest, siCaseFolding_Kana, nCaseFolding_Kana);
}

#endif

NS_PLIB_UNICODE_END
