//	XLCTextEx_1.0x	:	Test

//	DataRegEx01.cpp
//
#include "stdafx.h"

//======================================================================
//	DataRegEx01a
//======================================================================
//----------------------------------------------------------------------
//	DataRegEx01_00	�󕶎���̏���
//----------------------------------------------------------------------
TDataRegEx01	DataRegEx01_00[]	=
{
	TQU("�󕶎���̏���"),
	TQU(""),
	TQU(""),
	TQU(""),
	TQU(""),

	TQU("�󕶎���̏���"),
	TQU(""),
	TQU("<$&>"),
	TQU(""),
	TQU("g"),

	TQU("�󕶎���̏���"),
	TQU(""),
	TQU("<$&>"),
	TQU("AbC123D"),
	TQU("g"),

	TQU("�󕶎���̏���"),
	TQU("\\d"),
	TQU(""),
	TQU("aB12C0-d"),
	TQU("g"),
};
int	nDataRegEx01_00	= sizeof(DataRegEx01_00) / sizeof(TDataRegEx01);

//----------------------------------------------------------------------
//	DataRegEx01_01	�I�v�V����
//----------------------------------------------------------------------
TDataRegEx01	DataRegEx01_01[]	=
{
	//------------------------------------------------------------
	//	m�As �I�v�V����	(1)	\r\n �̏ꍇ
	//------------------------------------------------------------
	TQU("m�As �I�v�V����\t(1)\t\\r\\n �̏ꍇ"),
	TQU("^.+$"),
	TQU("<$&>"),
	TQU("abc\r\nd\r\n\r\nfgh"),
	TQU("g"),

	TQU("m�As �I�v�V����\t(1)\t\\r\\n �̏ꍇ"),
	TQU("^.+$"),
	TQU("<$&>"),
	TQU("abc\r\nd\r\n\r\nfgh"),
	TQU("gm"),

	TQU("m�As �I�v�V����\t(1)\t\\r\\n �̏ꍇ"),
	TQU("^.+$"),
	TQU("<$&>"),
	TQU("abc\r\nd\r\n\r\nfgh"),
	TQU("gs"),

	TQU("m�As �I�v�V����\t(1)\t\\r\\n �̏ꍇ"),
	TQU("^.+$"),
	TQU("<$&>"),
	TQU("abc\r\nd\r\n\r\nfgh"),
	TQU("gms"),

	//------------------------------------------------------------
	//	m�As �I�v�V����	(2)	\n �̏ꍇ
	//------------------------------------------------------------
	TQU("m�As �I�v�V����\t(2)\t\\n �̏ꍇ"),
	TQU("^.+$"),
	TQU("<$&>"),
	TQU("abc\nd\n\nfgh"),
	TQU("g"),

	TQU("m�As �I�v�V����\t(2)\t\\n �̏ꍇ"),
	TQU("^.+$"),
	TQU("<$&>"),
	TQU("abc\nd\n\nfgh"),
	TQU("gm"),

	TQU("m�As �I�v�V����\t(2)\t\\n �̏ꍇ"),
	TQU("^.+$"),
	TQU("<$&>"),
	TQU("abc\nd\n\nfgh"),
	TQU("gs"),

	TQU("m�As �I�v�V����\t(2)\t\\n �̏ꍇ"),
	TQU("^.+$"),
	TQU("<$&>"),
	TQU("abc\nd\n\nfgh"),
	TQU("gms"),

	//------------------------------------------------------------
	//	x �I�v�V����
	//------------------------------------------------------------
	TQU("x �I�v�V����"),
	TQU("a  # hello\n bc"),
	TQU("<$&>"),
	TQU("abcAbCabcaBc"),
	TQU("g"),

	TQU("x �I�v�V����"),
	TQU("a  # hello\n bc"),
	TQU("<$&>"),
	TQU("abcAbCabcaBc"),
	TQU("gx"),

	TQU("x �I�v�V����"),
	TQU("a  # hello\r\n bc"),
	TQU("<$&>"),
	TQU("abcAbCabcaBc"),
	TQU("gxi"),

	TQU("x �I�v�V����"),
	TQU("abc"),
	TQU("<$&>"),
	TQU("abcAbCabcaBc"),
	TQU("gxi"),

	//------------------------------------------------------------
	//	i �I�v�V����
	//------------------------------------------------------------
	TQU("i �I�v�V����"),
	TQU("ab"),
	TQU("<$&>"),
	TQU("ABbAbaBA�`�a���`�����a������"),
	TQU("g"),

	TQU("i �I�v�V����"),
	TQU("ab"),
	TQU("<$&>"),
	TQU("ABbAbaBA�`�a���`�����a������"),
	TQU("gi"),

	TQU("i �I�v�V����"),
	TQU("ab"),
	TQU("<$&>"),
	TQU("ABbAbaBA�`�a���`�����a������"),
	TQU("giw"),

	//------------------------------------------------------------
	//	d �I�v�V����	(1)
	//------------------------------------------------------------
	TQU("d �I�v�V����\t(1)"),
	TQU("AUEO"),
	TQU("<$&>"),
	TQU("AUEOaueo\xC4\xDC\xCB\xD6\xE4\xFC\xEB\xF6"),
	TQU("g"),

	TQU("d �I�v�V����\t(1)"),
	TQU("AUEO"),
	TQU("<$&>"),
	TQU("AUEOaueo\xC4\xDC\xCB\xD6\xE4\xFC\xEB\xF6"),
	TQU("gd"),

	TQU("d �I�v�V����\t(1)"),
	TQU("AUEO"),
	TQU("<$&>"),
	TQU("AUEOaueo\xC4\xDC\xCB\xD6\xE4\xFC\xEB\xF6"),
	TQU("gdi"),

	//------------------------------------------------------------
	//	d �I�v�V����	(2)
	//------------------------------------------------------------
	TQU("d �I�v�V����\t(2)"),
	TQU("����"),
	TQU("<$&>"),
	TQU("�����������������T�V�T�W�U�V�U�W"),
	TQU("g"),

	TQU("d �I�v�V����\t(2)"),
	TQU("����"),
	TQU("<$&>"),
	TQU("�����������������T�V�T�W�U�V�U�W"),
	TQU("gd"),

	TQU("d �I�v�V����\t(2)"),
	TQU("����"),
	TQU("<$&>"),
	TQU("�����������������T�V�T�W�U�V�U�W"),
	TQU("gdk"),

	//------------------------------------------------------------
	//	k �I�v�V����
	//------------------------------------------------------------
	TQU("k �I�v�V����"),
	TQU("���L"),
	TQU("<$&>"),
	TQU("�������L�J���J�L"),
	TQU("g"),

	TQU("k �I�v�V����"),
	TQU("���L"),
	TQU("<$&>"),
	TQU("�������L�J���J�L"),
	TQU("gk"),

	//------------------------------------------------------------
	//	l �I�v�V����
	//------------------------------------------------------------
	TQU("l �I�v�V����"),
	TQU("����"),
	TQU("<$&>"),
	TQU("����ッ������"),
	TQU("g"),

	TQU("l �I�v�V����"),
	TQU("����"),
	TQU("<$&>"),
	TQU("����ッ������"),
	TQU("gl"),

	TQU("l �I�v�V����"),
	TQU("����"),
	TQU("<$&>"),
	TQU("����ッ������"),
	TQU("gkl"),

	//------------------------------------------------------------
	//	w �I�v�V����
	//------------------------------------------------------------
	TQU("w �I�v�V����"),
	TQU("a1%"),
	TQU("<$&>"),
	TQU("a1%���P����1%a�P��A1%�`�P���`1%A�P��"),
	TQU("��"),

	TQU("w �I�v�V����"),
	TQU("a1%"),
	TQU("<$&>"),
	TQU("a1%���P����1%a�P��A1%�`�P���`1%A�P��"),
	TQU("gw"),

	TQU("w �I�v�V����"),
	TQU("a1%"),
	TQU("<$&>"),
	TQU("a1%���P����1%a�P��A1%�`�P���`1%A�P��"),
	TQU("gwi"),

	//------------------------------------------------------------
	//	�I�v�V�����̕ύX
	//------------------------------------------------------------
	TQU("�I�v�V�����̕ύX"),
	TQU("abc"),
	TQU("<$&>"),
	TQU("abCABcaBcabc"),
	TQU("g"),

	TQU("�I�v�V�����̕ύX"),
	TQU("(?i:ab)c"),
	TQU("<$&>"),
	TQU("abCABcaBcabc"),
	TQU("g"),

	TQU("�I�v�V�����̕ύX"),
	TQU("(?-i:ab)C"),
	TQU("<$&>"),
	TQU("abcABcaBc"),
	TQU("gi"),

	TQU("�I�v�V�����̕ύX"),
	TQU("ab(?i)c"),
	TQU("<$&>"),
	TQU("abCABcaBcabc"),
	TQU("g"),

	TQU("�I�v�V�����̕ύX"),
	TQU("����"),
	TQU("<$&>"),
	TQU("�����T�����V�T�V�����T�����W�T�W"),
	TQU("g"),

	TQU("�I�v�V�����̕ύX"),
	TQU("��(?k:��)"),
	TQU("<$&>"),
	TQU("�����T�����V�T�V�����T�����W�T�W"),
	TQU("g"),

	TQU("�I�v�V�����̕ύX"),
	TQU("��(?kd:��)"),
	TQU("<$&>"),
	TQU("�����T�����V�T�V�����T�����W�T�W"),
	TQU("g"),
};
int	nDataRegEx01_01	= sizeof(DataRegEx01_01) / sizeof(TDataRegEx01);

//----------------------------------------------------------------------
//	DataRegEx01_02	�G�X�P�[�v�V�[�P���X
//----------------------------------------------------------------------
TDataRegEx01	DataRegEx01_02[]	=
{
	//------------------------------------------------------------
	//	�G�X�P�[�v�V�[�P���X	(1)
	//------------------------------------------------------------
	TQU("�G�X�P�[�v�V�[�P���X\t(1)"),
	TQU("\\101\\61\\x43"),
	TQU("<$&>"),
	TQU("0A1ca1Cd"),
	TQU("g"),

	TQU("�G�X�P�[�v�V�[�P���X\t(1)"),
	TQU("\\101\\61\\x43"),
	TQU("<$&>"),
	TQU("0A1ca1Cd"),
	TQU("gi"),

	TQU("�G�X�P�[�v�V�[�P���X\t(1)"),
	TQU("\\u0041\\u42"),
	TQU("<$&>"),
	TQU("abAbabAB"),
	TQU("g"),

	TQU("�G�X�P�[�v�V�[�P���X\t(1)"),
	TQU("\\u0041\\u42"),
	TQU("<$&>"),
	TQU("abAbabAB"),
	TQU("gi"),

	TQU("�G�X�P�[�v�V�[�P���X\t(1)"),
	TQU("\\u{41 042}"),
	TQU("<$&>"),
	TQU("abAbabAB"),
	TQU("g"),

	TQU("�G�X�P�[�v�V�[�P���X\t(1)"),
	TQU("\\u{41 042}"),
	TQU("<$&>"),
	TQU("abAbabAB"),
	TQU("gi"),

	TQU("�G�X�P�[�v�V�[�P���X\t(1)"),
	TQU("a\\u{42}c"),
	TQU("<$&>"),
	TQU("abcdABCD"),
	TQU("g"),

	TQU("�G�X�P�[�v�V�[�P���X\t(1)"),
	TQU("a\\u{42}c"),
	TQU("<$&>"),
	TQU("abcdABCD"),
	TQU("gi"),

	TQU("�G�X�P�[�v�V�[�P���X\t(1)"),
	TQU("a\\u{0042 0043}d"),
	TQU("<$&>"),
	TQU("abcdABCD"),
	TQU("g"),

	TQU("�G�X�P�[�v�V�[�P���X\t(1)"),
	TQU("a\\u{0042 0043}d"),
	TQU("<$&>"),
	TQU("abcdABCD"),
	TQU("gi"),

	TQU("�G�X�P�[�v�V�[�P���X\t(1)"),
	TQU("\\u2000b"),
	TQU("<$&>"),
	TQU("\\xD840\\xDC0B\\xD840\\xDC89\\xD840\\xDCA2"),
	TQU("gi"),

	TQU("�G�X�P�[�v�V�[�P���X\t(1)"),
	TQU("\\u20089"),
	TQU("<$&>"),
	TQU("\\xD840\\xDC0B\\xD840\\xDC89\\xD840\\xDCA2"),
	TQU("gi"),

	//------------------------------------------------------------
	//	�G�X�P�[�v�V�[�P���X	(2)
	//------------------------------------------------------------
	TQU("�G�X�P�[�v�V�[�P���X\t(2)"),
	TQU("[\\cI\\cJ\\cM]"),
	TQU("<$&>"),
	TQU("a\tb\r\nc"),
	TQU("g"),

	TQU("�G�X�P�[�v�V�[�P���X\t(2)"),
	TQU("[\\t\\r\\n]"),
	TQU("<$&>"),
	TQU("a\tb\r\nc"),
	TQU("g"),
};
int	nDataRegEx01_02	= sizeof(DataRegEx01_02) / sizeof(TDataRegEx01);

//----------------------------------------------------------------------
//	DataRegEx01_03	�����N���X
//----------------------------------------------------------------------
TDataRegEx01	DataRegEx01_03[]	=
{
	//------------------------------------------------------------
	//	�����N���X	(1-1)	\w, \d, \s, \W, \D, \S
	//------------------------------------------------------------
	TQU("�����N���X\t(1-1)\t\\w"),
	TQU("\\w"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(1-1)\t\\d"),
	TQU("\\d"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(1-1)\t\\s"),
	TQU("\\s"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(1-1)\t\\W"),
	TQU("\\W"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(1-1)\t\\D"),
	TQU("\\D"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(1-1)\t\\S"),
	TQU("\\S"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	//------------------------------------------------------------
	//	�����N���X	(1-2)	[ ] ���� \w, \d, \s, \W, \D, \S
	//------------------------------------------------------------
	TQU("�����N���X\t(1-2)\t\\"),
	TQU("[\\w]+"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(1-2)\t\\"),
	TQU("[\\d]+"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(1-2)\t\\"),
	TQU("[\\s]+"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(1-2)\t\\"),
	TQU("[\\W]+"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(1-2)\t\\"),
	TQU("[\\D]+"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(1-2)\t\\"),
	TQU("[\\S]+"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	//------------------------------------------------------------
	//	�����N���X	(2-1)	\p{}, \P{}
	//------------------------------------------------------------
	TQU("�����N���X\t(2-1)\t\\"),
	TQU("\\p{Lu}"),
	TQU("<$&>"),
	TQU("ABCabc�`�a�b�������������G��"),
	TQU("g"),

	TQU("�����N���X\t(2-1)\t\\"),
	TQU("\\P{Lu}"),
	TQU("<$&>"),
	TQU("ABCabc�`�a�b�������������G��"),
	TQU("g"),

	TQU("�����N���X\t(2-1)\t\\"),
	TQU("\\p{^Lu}"),
	TQU("<$&>"),
	TQU("ABCabc�`�a�b�������������G��"),
	TQU("g"),

	//------------------------------------------------------------
	//	�����N���X	(2-2)	[] ���� \p{}, \P{}
	//------------------------------------------------------------
	TQU("�����N���X\t(2-2)\t\\"),
	TQU("[\\p{Lu}]+"),
	TQU("<$&>"),
	TQU("ABCabc�`�a�b�������������G��"),
	TQU("g"),

	TQU("�����N���X\t(2-2)\t\\"),
	TQU("[\\P{Lu}]+"),
	TQU("<$&>"),
	TQU("ABCabc�`�a�b�������������G��"),
	TQU("g"),

	TQU("�����N���X\t(2-2)\t\\"),
	TQU("[\\p{^Lu}]+"),
	TQU("<$&>"),
	TQU("ABCabc�`�a�b�������������G��"),
	TQU("g"),

	//------------------------------------------------------------
	//	�����N���X	(2-3)	\p{}, \P{} �e��̏���
	//------------------------------------------------------------
	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{Ll}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{LL}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{ll}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{gc=Ll}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{GC=LL}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{General_Category=Lowercase_Letter}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{general_category=lowercase_letter}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{Lo}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{L}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{nd}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{NL}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{pc}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{P}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{Alphabetic}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{alphabetic=true}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{ALPHA=FALSE}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{Uppercase}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{lowercase}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{script=hiragana}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),

	TQU("�����N���X\t(2-3)\t\\"),
	TQU("\\p{BLOCK=KATAKANA}"),
	TQU("<$&>"),
	TQU("ab12$_& �����P�Q���Q���@�����E�G\t���Ɉ��\xC6\xD840\xDC0B"),
	TQU("g"),
};
int	nDataRegEx01_03	= sizeof(DataRegEx01_03) / sizeof(TDataRegEx01);

//----------------------------------------------------------------------
//	DataRegEx01_04	�ʒu�ɂ��ƍ�
//----------------------------------------------------------------------
TDataRegEx01	DataRegEx01_04[]	=
{
	//------------------------------------------------------------
	//	������̐擪�ƏI�[
	//------------------------------------------------------------
	TQU("������̐擪 ^"),
	TQU("^"),
	TQU("��"),
	TQU("abc"),
	TQU("g"),

	TQU("������̐擪 ^"),
	TQU("^"),
	TQU("��"),
	TQU("abc\r\n\r\ndef"),
	TQU("g"),

	TQU("������̐擪 ^"),
	TQU("^"),
	TQU("��"),
	TQU("abc\r\n\r\ndef"),
	TQU("gm"),

	TQU("������̐擪 ^"),
	TQU("^"),
	TQU("��"),
	TQU("abc\r\n\r\ndef"),
	TQU("gs"),

	TQU("������̐擪 ^"),
	TQU("^"),
	TQU("��"),
	TQU("abc\r\n\r\ndef"),
	TQU("gms"),

	TQU("������̐擪 ^ �i\\n �̂݁j"),
	TQU("^"),
	TQU("��"),
	TQU("abc\n\ndef"),
	TQU("g"),

	TQU("������̐擪 ^ �i\\n �̂݁j"),
	TQU("^"),
	TQU("��"),
	TQU("abc\n\ndef"),
	TQU("gm"),

	TQU("������̐擪 ^ �i\\n �̂݁j"),
	TQU("^"),
	TQU("��"),
	TQU("abc\n\ndef"),
	TQU("gs"),

	TQU("������̐擪 ^ �i\\n �̂݁j"),
	TQU("^"),
	TQU("��"),
	TQU("abc\n\ndef"),
	TQU("gms"),

	TQU("������̏I�[ $"),
	TQU("$"),
	TQU("�~"),
	TQU("abc"),
	TQU("g"),

	TQU("������̏I�[ $"),
	TQU("$"),
	TQU("�~"),
	TQU("abc\r\n\r\ndef"),
	TQU("g"),

	TQU("������̏I�[ $"),
	TQU("$"),
	TQU("�~"),
	TQU("abc\r\n\r\ndef"),
	TQU("gm"),

	TQU("������̏I�[ $"),
	TQU("$"),
	TQU("�~"),
	TQU("abc\r\n\r\ndef"),
	TQU("gs"),

	TQU("������̏I�[ $"),
	TQU("$"),
	TQU("�~"),
	TQU("abc\r\n\r\ndef"),
	TQU("gms"),

	TQU("������̏I�[ $�i\\n �̂݁j"),
	TQU("$"),
	TQU("�~"),
	TQU("abc\n\ndef"),
	TQU("g"),

	TQU("������̏I�[ $�i\\n �̂݁j"),
	TQU("$"),
	TQU("�~"),
	TQU("abc\n\ndef"),
	TQU("gm"),

	TQU("������̏I�[ $�i\\n �̂݁j"),
	TQU("$"),
	TQU("�~"),
	TQU("abc\n\ndef"),
	TQU("gs"),

	TQU("������̏I�[ $�i\\n �̂݁j"),
	TQU("$"),
	TQU("�~"),
	TQU("abc\n\ndef"),
	TQU("gms"),

	TQU("������̐擪 \\A"),
	TQU("\\A.+$"),
	TQU("<$&>"),
	TQU("abc\ndef"),
	TQU("g"),

	TQU("������̐擪 \\A"),
	TQU("\\A.+$"),
	TQU("<$&>"),
	TQU("abc\ndef"),
	TQU("gm"),

	TQU("������̐擪 \\A"),
	TQU("\\A.+$"),
	TQU("<$&>"),
	TQU("abc\ndef"),
	TQU("gs"),

	TQU("������̏I�[ \\z"),
	TQU("^.+\\z"),
	TQU("<$&>"),
	TQU("abc\ndef"),
	TQU("g"),

	TQU("������̏I�[ \\z"),
	TQU("^.+\\z"),
	TQU("<$&>"),
	TQU("abc\ndef"),
	TQU("gm"),

	TQU("������̏I�[ \\z"),
	TQU("^.+\\z"),
	TQU("<$&>"),
	TQU("abc\ndef"),
	TQU("gs"),

	TQU("������̏I�[ \\z"),
	TQU("^.+\\z"),
	TQU("<$&>"),
	TQU("abc\r\ndef\r\n"),
	TQU("gm"),

	TQU("������̏I�[ \\z"),
	TQU("^.+\\z"),
	TQU("<$&>"),
	TQU("abc\ndef\n"),
	TQU("gm"),


	TQU("������̏I�[ \\Z"),
	TQU("^.+\\Z"),
	TQU("<$&>"),
	TQU("abc\ndef"),
	TQU("g"),

	TQU("������̏I�[ \\Z"),
	TQU("^.+\\Z"),
	TQU("<$&>"),
	TQU("abc\ndef"),
	TQU("gm"),

	TQU("������̏I�[ \\Z"),
	TQU("^.+\\Z"),
	TQU("<$&>"),
	TQU("abc\ndef"),
	TQU("gs"),

	TQU("������̏I�[ \\Z"),
	TQU("^.+\\Z"),
	TQU("<$&>"),
	TQU("abc\r\ndef\r\n"),
	TQU("gm"),

	TQU("������̏I�[ \\Z"),
	TQU("^.+\\Z"),
	TQU("<$&>"),
	TQU("abc\ndef\n"),
	TQU("gm"),

	TQU("������̐擪�ƏI�["),
	TQU("\\A.*\\z"),
	TQU("<$&>"),
	TQU("abc"),
	TQU(""),

	TQU("������̐擪�ƏI�["),
	TQU("\\A.*\\z"),
	TQU("<$&>"),
	TQU("abc\r\n"),
	TQU(""),

	TQU("������̐擪�ƏI�["),
	TQU("\\A.*\\z"),
	TQU("<$&>"),
	TQU("abc\n"),
	TQU(""),

	TQU("������̐擪�ƏI�["),
	TQU("\\A.*\\Z"),
	TQU("<$&>"),
	TQU("abc"),
	TQU(""),

	TQU("������̐擪�ƏI�["),
	TQU("\\A.*\\Z"),
	TQU("<$&>"),
	TQU("abc\r\n"),
	TQU(""),

	TQU("������̐擪�ƏI�["),
	TQU("\\A.*\\Z"),
	TQU("<$&>"),
	TQU("abc\n"),
	TQU(""),

	//------------------------------------------------------------
	//	��s
	//------------------------------------------------------------
	TQU("��s"),
	TQU("^\r\n"),
	TQU("<$&>"),
	TQU("abc\r\n\r\ndef"),
	TQU("gm"),

	TQU("��s"),
	TQU("^\r\n"),
	TQU(""),
	TQU("abc\r\n\r\ndef"),
	TQU("gm"),

	TQU("��s"),
	TQU("^\n"),
	TQU("<$&>"),
	TQU("abc\n\ndef"),
	TQU("gm"),

	TQU("��s"),
	TQU(""),
	TQU("<$&>"),
	TQU("abc\n\ndef"),
	TQU("gm"),

	TQU("��s"),
	TQU("^$"),
	TQU("<$&>"),
	TQU("abc\r\n\r\ndef"),
	TQU("gm"),

	TQU("��s"),
	TQU("^$"),
	TQU("<$&>"),
	TQU("abc\n\ndef"),
	TQU("gm"),

	TQU("��s�̍폜"),
	TQU("^$"),
	TQU(""),
	TQU("abc\r\n\r\ndef"),
	TQU("gm"),

	TQU("��s�̍폜"),
	TQU("^$"),
	TQU(""),
	TQU("abc\n\ndef"),
	TQU("gm"),

	//------------------------------------------------------------
	//	\G
	//------------------------------------------------------------
	TQU("\\G"),
	TQU("\\Gabc"),
	TQU("<$&>"),
	TQU("AbcABCdabc"),
	TQU("gi"),

	//------------------------------------------------------------
	//	���E
	//------------------------------------------------------------
	TQU("���E"),
	TQU("\\ba"),
	TQU("<$&>"),
	TQU("aba acad$ae"),
	TQU("gi"),

	TQU("���E"),
	TQU("\\Ba"),
	TQU("<$&>"),
	TQU("aba acad$ae"),
	TQU("gi"),
};
int	nDataRegEx01_04	= sizeof(DataRegEx01_04) / sizeof(TDataRegEx01);

//----------------------------------------------------------------------
//	DataRegEx01_05	����Q��
//----------------------------------------------------------------------
TDataRegEx01	DataRegEx01_05[]	=
{
	TQU("����Q��"),
	TQU("(ab)\\1"),
	TQU("<$&>"),
	TQU("ABABababAbaB"),
	TQU("g"),

	TQU("����Q��"),
	TQU("(ab)\\1"),
	TQU("<$&>"),
	TQU("ABABababAbaB"),
	TQU("gi"),

	TQU("����Q��"),
	TQU("(a)(b)\\2\\1"),
	TQU("<$&>"),
	TQU("ABAaBabBabAbBa"),
	TQU("g"),

	TQU("����Q��"),
	TQU("(a)(b)\\2\\1"),
	TQU("<$&>"),
	TQU("ABAaBabBabAbBa"),
	TQU("gi"),

	TQU("����Q��"),
	TQU("(a)(b)\\g2\\g1"),
	TQU("<$&>"),
	TQU("ABAaBabBabAbBa"),
	TQU("g"),

	TQU("����Q��"),
	TQU("(a)(b)\\g2\\g1"),
	TQU("<$&>"),
	TQU("ABAaBabBabAbBa"),
	TQU("gi"),

	TQU("����Q��"),
	TQU("(\\w\\d)\\1"),
	TQU("<$&>"),
	TQU("ab1A2A23c4C45"),
	TQU("gi"),

	TQU("����Q��"),
	TQU("(ab|cd)\\1"),
	TQU("<$&>"),
	TQU("aBCDcdaabABaBCdc"),
	TQU("g"),

	TQU("����Q��"),
	TQU("(ab|cd)\\1"),
	TQU("<$&>"),
	TQU("aBCDcdaabABaBCdc"),
	TQU("gi"),

	TQU("����Q��"),
	TQU("(?<�}�b�`>ab|cd)\\k<�}�b�`>"),
	TQU("<$&>"),
	TQU("aBCDcdaabABaBCdc"),
	TQU("g"),

	TQU("����Q��"),
	TQU("(?<�}�b�`>ab|cd)\\k<�}�b�`>"),
	TQU("<$&>"),
	TQU("aBCDcdaabABaBCdc"),
	TQU("gi"),

	TQU("����Q��"),
	TQU("(?'�}�b�`'ab|cd)\\k'�}�b�`'"),
	TQU("<$&>"),
	TQU("aBCDcdaabABaBCdc"),
	TQU("gi"),

	TQU("����Q��"),
	TQU("(?<char>\\p{alpha})(?'num'\\p{nd})\\k<char>\\k'num'"),
	TQU("<$&>"),
	TQU("a1A2a2b3B3c4c4"),
	TQU("g"),

	TQU("����Q��"),
	TQU("(?'char'\\p{alpha})(?<num>\\p{nd})\\k<char>\\k'num'"),
	TQU("<$&>"),
	TQU("a1A2a2b3B3c4c4"),
	TQU("gi"),
};
int	nDataRegEx01_05	= sizeof(DataRegEx01_05) / sizeof(TDataRegEx01);

//----------------------------------------------------------------------
//	DataRegEx01_06	�O����v�A�O���s��v�A�����v�A����s��v
//----------------------------------------------------------------------
TDataRegEx01	DataRegEx01_06[]	=
{
	TQU("�O����v"),
	TQU("\\w+(?=\\.)"),
	TQU("<$&>"),
	TQU("He is. The dog ran. The sun is out."),
	TQU("g"),

	TQU("�O���s��v"),
	TQU("\\b(?!un)\\w+\\b"),
	TQU("<$&>"),
	TQU("unsure sure unity used"),
	TQU("g"),

	TQU("�����v"),
	TQU("(?<=19)\\d{2}\\b"),
	TQU("<$&>"),
	TQU("1851 1999 1950 1905 2003"),
	TQU("gq"),

	TQU("����s��v"),
	TQU("(?<!19)\\d{2}\\b"),
	TQU("<$&>"),
	TQU("1851 1999 1950 1905 2003"),
	TQU("gq"),
};
int	nDataRegEx01_06	= sizeof(DataRegEx01_06) / sizeof(TDataRegEx01);

//----------------------------------------------------------------------
//	DataRegEx01_07	�ʎw��q
//----------------------------------------------------------------------
TDataRegEx01	DataRegEx01_07[]	=
{
	TQU("�ʎw��q"),
	TQU("a*"),
	TQU("<$&>"),
	TQU("baaac"),
	TQU("g"),

	TQU("�ʎw��q"),
	TQU("a*?"),
	TQU("<$&>"),
	TQU("baaac"),
	TQU("g"),

	TQU("�ʎw��q"),
	TQU("a+"),
	TQU("<$&>"),
	TQU("baaac"),
	TQU("g"),

	TQU("�ʎw��q"),
	TQU("a+?"),
	TQU("<$&>"),
	TQU("baaac"),
	TQU("g"),

	TQU("�ʎw��q"),
	TQU("a?"),
	TQU("<$&>"),
	TQU("baaac"),
	TQU("g"),

	TQU("�ʎw��q"),
	TQU("a??"),
	TQU("<$&>"),
	TQU("baaac"),
	TQU("g"),

	TQU("�ʎw��q"),
	TQU("a{2,3}"),
	TQU("<$&>"),
	TQU("baaaaa"),
	TQU("g"),

	TQU("�ʎw��q"),
	TQU("a{2,3}?"),
	TQU("<$&>"),
	TQU("baaaaa"),
	TQU("g"),
};
int	nDataRegEx01_07	= sizeof(DataRegEx01_07) / sizeof(TDataRegEx01);

//----------------------------------------------------------------------
//	DataRegEx01_08	�I��
//----------------------------------------------------------------------
TDataRegEx01	DataRegEx01_08[]	=
{
	TQU("�I��"),
	TQU("(ab|cd)"),
	TQU("<$&>"),
	TQU("aBCDcdABaAB"),
	TQU("gi"),

	TQU("�I���i��������j"),
	TQU("(?:(a)|b)(?(1)1|2)"),
	TQU("<$&>"),
	TQU("a2d2a1b1b2c3c1"),
	TQU("g"),

	TQU("�I���i��������j"),
	TQU("(?:(?<pre>a)|b)(?(<pre>)1|2)"),
	TQU("<$&>"),
	TQU("a2d2a1b1b2c3c1"),
	TQU("g"),

	TQU("�I���i��������j"),
	TQU("(?(?=\\D)a|1)"),
	TQU("<$&>"),
	TQU("a2d2a1b1b2c3c1"),
	TQU("g"),

	TQU("�I���i��������j"),
	TQU("(?(?!\\d)a|1)"),
	TQU("<$&>"),
	TQU("a2d2a1b1b2c3c1"),
	TQU("g"),

	TQU("�I���i��������j"),
	TQU("(?(?<=a)1|2)"),
	TQU("<$&>"),
	TQU("a2d2a1b1b2c3c1"),
	TQU("g"),

	TQU("�I���i��������j"),
	TQU("(?(?<!a)1|2)"),
	TQU("<$&>"),
	TQU("a2d2a1b1b2c3c1"),
	TQU("g"),

	TQU("�I���i��������j"),
	TQU("(?(\\p{Lu})A\\p{LL})"),
	TQU("<$&>"),
	TQU("AbCDeFGhiJkLMnO"),
	TQU("g"),

	TQU("�I���i��������j"),
	TQU("(?(\\d)3| )"),
	TQU("<$&>"),
	TQU("Ab23 31"),
	TQU("g"),
};
int	nDataRegEx01_08	= sizeof(DataRegEx01_08) / sizeof(TDataRegEx01);

//----------------------------------------------------------------------
//	DataRegEx01_09	�u���P�b�g�\��
//----------------------------------------------------------------------
TDataRegEx01	DataRegEx01_09[]	=
{
	//------------------------------------------------------------
	//	�u���P�b�g�\��
	//------------------------------------------------------------
	TQU("�u���P�b�g�\��"),
	TQU("[a�a�A]"),
	TQU("<$&>"),
	TQU("aBAb���a�`�����A�"),
	TQU("g"),

	TQU("�u���P�b�g�\��"),
	TQU("[a�a�A]"),
	TQU("<$&>"),
	TQU("aBAb���a�`�����A�"),
	TQU("gw"),

	TQU("�u���P�b�g�\��"),
	TQU("[a�a�A]"),
	TQU("<$&>"),
	TQU("aBAb���a�`�����A�"),
	TQU("gwk"),

	TQU("�u���P�b�g�\��"),
	TQU("[a�a�A]"),
	TQU("<$&>"),
	TQU("aBAb���a�`�����A�"),
	TQU("gwki"),

	TQU("�u���P�b�g�\��"),
	TQU("[��]"),
	TQU("<$&>"),
	TQU("���⃃��"),
	TQU("g"),

	TQU("�u���P�b�g�\��"),
	TQU("[��]"),
	TQU("<$&>"),
	TQU("���⃃��"),
	TQU("gl"),

	TQU("�u���P�b�g�\��"),
	TQU("[��]"),
	TQU("<$&>"),
	TQU("���⃃��"),
	TQU("gkl"),

	TQU("�u���P�b�g�\��"),
	TQU(".[.]+"),
	TQU("<$&>"),
	TQU("ab.c.."),
	TQU("g"),

	//------------------------------------------------------------
	//	�u���P�b�g�\��	�͈�
	//------------------------------------------------------------
	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[a-c]+"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij"),
	TQU("g"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[a-c]+"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij"),
	TQU("gi"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[^a-c]+"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij"),
	TQU("gi"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[C-Gd-h]+"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij"),
	TQU("g"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[C-Gd-h]+"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij"),
	TQU("gi"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[^C-Gd-h]+"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij"),
	TQU("gi"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[��-��]"),
	TQU("<$&>"),
	TQU("��������������"),
	TQU("gk"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[���|��]"),
	TQU("<$&>"),
	TQU("��������������"),
	TQU("gkw"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[��-��]"),
	TQU("<$&>"),
	TQU("�A�C�E�G�I�J�L"),
	TQU("gk"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[���|��]"),
	TQU("<$&>"),
	TQU("�A�C�E�G�I�J�L"),
	TQU("gk"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[���|��]"),
	TQU("<$&>"),
	TQU("�A�C�E�G�I�J�L"),
	TQU("gkw"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[��-���G-�J]"),
	TQU("<$&>"),
	TQU("����������������������A�C�E�G�I�J�L"),
	TQU("g"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[��-���G-�J]"),
	TQU("<$&>"),
	TQU("����������������������A�C�E�G�I�J�L"),
	TQU("gk"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[��-���G-�J]"),
	TQU("<$&>"),
	TQU("����������������������A�C�E�G�I�J�L"),
	TQU("gkw"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[��-���G-�J]"),
	TQU("<$&>"),
	TQU("����������������������A�C�E�G�I�J�L��������������"),
	TQU("gkwl"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[�a-�c]"),
	TQU("<$&>"),
	TQU("�`�a�b�c�d����������"),
	TQU("gi"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[�a-�c]"),
	TQU("<$&>"),
	TQU("�`�a�b�c�d����������"),
	TQU("��"),

	TQU("�u���P�b�g�\��\t�͈�"),
	TQU("[d-b]"),
	TQU("<$&>"),
	TQU("abcdef"),
	TQU("g"),

	//------------------------------------------------------------
	//	�u���P�b�g�\��	POSIX �����N���X
	//------------------------------------------------------------
	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:alnum:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:ALNUM:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:alpha:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:ascii:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:blank:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:cntrl:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:digit:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:graph:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:lower:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:print:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:punct:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:space:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:upper:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:word:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:xdigit:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:^digit:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:^space:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[[:^word:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[^[:alnum:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	TQU("�u���P�b�g�\��\tPOSIX �����N���X"),
	TQU("[^[:alpha:][:digit:]]"),
	TQU("<$&>"),
	TQU("!\"#$&\\ 12ABcd_�I�h���������@�P�Q�`�a�����Q\t�����E�G���\xD840\xDC0B\xD840\xDCA4"),
	TQU("g"),

	//------------------------------------------------------------
	//	�u���P�b�g�\��	�W�����Z
	//------------------------------------------------------------
	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[a-f||c-g]"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij�`�a�b�c�d�e�f�g�h�i��������������������"),
	TQU("g"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[a-f||c-g]"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij�`�a�b�c�d�e�f�g�h�i��������������������"),
	TQU("gi"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[a-f||c-g]"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij�`�a�b�c�d�e�f�g�h�i��������������������"),
	TQU("gwi"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[B-Ea-f||E-Hc-g]"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij�`�a�b�c�d�e�f�g�h�i��������������������"),
	TQU("gwi"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[[:alnum:]||$]"),
	TQU("<$&>"),
	TQU("#$%&ABCDEFGHabcdefgh_���������`�a�b�c�d�e�f�g����������������0123�O�P�Q�R�Q"),
	TQU("gw"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[%||[:alnum:]||$]"),
	TQU("<$&>"),
	TQU("#$%&ABCDEFGHabcdefgh_���������`�a�b�c�d�e�f�g����������������0123�O�P�Q�R�Q"),
	TQU("gw"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[[:alnum:]||[:punct:]]"),
	TQU("<$&>"),
	TQU("#$%&ABCDEFGHabcdefgh_���������`�a�b�c�d�e�f�g����������������0123�O�P�Q�R�Q"),
	TQU("g"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[[:upper:]||\\p{lowercase}]"),
	TQU("<$&>"),
	TQU("#$%&ABCDEFGHabcdefgh_���������`�a�b�c�d�e�f�g����������������0123�O�P�Q�R�Q"),
	TQU("g"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[a-i--c-g]"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij�`�a�b�c�d�e�f�g�h�i��������������������"),
	TQU("g"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[a-i--c-g]"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij�`�a�b�c�d�e�f�g�h�i��������������������"),
	TQU("gwi"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[a-i--c-j]"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij�`�a�b�c�d�e�f�g�h�i��������������������"),
	TQU("gwi"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[a-eg-j--b-cf-j]"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij�`�a�b�c�d�e�f�g�h�i��������������������"),
	TQU("gwi"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[a-j--b-c--f-j]"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij�`�a�b�c�d�e�f�g�h�i��������������������"),
	TQU("gwi"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[[:alnum:]--[:digit:]]"),
	TQU("<$&>"),
	TQU("#$%&ABCDEFGHabcdefgh_���������`�a�b�c�d�e�f�g����������������0123�O�P�Q�R�Q"),
	TQU("g"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[[:alnum:]--[b-d]]"),
	TQU("<$&>"),
	TQU("#$%&ABCDEFGHabcdefgh_���������`�a�b�c�d�e�f�g����������������0123�O�P�Q�R�Q"),
	TQU("g"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[[:alnum:]--[b-d]]"),
	TQU("<$&>"),
	TQU("#$%&ABCDEFGHabcdefgh_���������`�a�b�c�d�e�f�g����������������0123�O�P�Q�R�Q"),
	TQU("gi"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[[:alnum:]--[b-d]]"),
	TQU("<$&>"),
	TQU("#$%&ABCDEFGHabcdefgh_���������`�a�b�c�d�e�f�g����������������0123�O�P�Q�R�Q"),
	TQU("giw"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[\\w--\\p{nd}]"),
	TQU("<$&>"),
	TQU("#$%&ABCDEFGHabcdefgh_���������`�a�b�c�d�e�f�g����������������0123�O�P�Q�R�Q"),
	TQU("g"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[$%12ab--\\w]"),
	TQU("<$&>"),
	TQU("#$%&ABCDEFGHabcdefgh_���������`�a�b�c�d�e�f�g����������������0123�O�P�Q�R�Q"),
	TQU("gwi"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[\\w--1-2--b-d]"),
	TQU("<$&>"),
	TQU("#$%&ABCDEFGHabcdefgh_���������`�a�b�c�d�e�f�g����������������0123�O�P�Q�R�Q"),
	TQU("gwi"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[a-f~~c-g]"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij�`�a�b�c�d�e�f�g�h�i��������������������"),
	TQU("g"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[a-f~~c-g]"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij�`�a�b�c�d�e�f�g�h�i��������������������"),
	TQU("gi"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[a-f~~c-g]"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij�`�a�b�c�d�e�f�g�h�i��������������������"),
	TQU("giw"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[b-i~~d-g]"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij�`�a�b�c�d�e�f�g�h�i��������������������"),
	TQU("giw"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[d-g~~b-i]"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij�`�a�b�c�d�e�f�g�h�i��������������������"),
	TQU("giw"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[c-eh-j~~b-df-i]"),
	TQU("<$&>"),
	TQU("ABCDEFGHIJabcdefghij�`�a�b�c�d�e�f�g�h�i��������������������"),
	TQU("giw"),

	TQU("�u���P�b�g�\��\t�W�����Z"),
	TQU("[[:ascii:]~~[:word:]]"),
	TQU("<$&>"),
	TQU("#$%&ABCDEFGHabcdefgh_���������`�a�b�c�d�e�f�g����������������0123�O�P�Q�R�Q"),
	TQU("g"),

	//------------------------------------------------------------
	//	�u���P�b�g�\��	�ƍ��v�f
	//------------------------------------------------------------
	TQU("�u���P�b�g�\��\t�ƍ��v�f"),
	TQU("[[.�K.]]"),
	TQU("<$&>"),
	TQU("���K�ނ��J�J�J"),
	TQU("g"),

	TQU("�u���P�b�g�\��\t�ƍ��v�f"),
	TQU("[[.�K.]]"),
	TQU("<$&>"),
	TQU("���K�ނ��J�J�J"),
	TQU("gk"),

	TQU("�u���P�b�g�\��\t�ƍ��v�f"),
	TQU("[[.�K.]]"),
	TQU("<$&>"),
	TQU("���K�ނ��J�J�J"),
	TQU("gw"),

	TQU("�u���P�b�g�\��\t�ƍ��v�f"),
	TQU("[[.�K.]]"),
	TQU("<$&>"),
	TQU("���K�ނ��J�J�J"),
	TQU("gkw"),

	TQU("�u���P�b�g�\��\t�ƍ��v�f"),
	TQU("[[.�J�J.]]"),
	TQU("<$&>"),
	TQU("���K�ނ��J�J�J"),
	TQU("g"),

	TQU("�u���P�b�g�\��\t�ƍ��v�f"),
	TQU("[[.�J�J.]]"),
	TQU("<$&>"),
	TQU("���K�ނ��J�J�J"),
	TQU("gk"),

	TQU("�u���P�b�g�\��\t�ƍ��v�f"),
	TQU("[[.�J�J.]]"),
	TQU("<$&>"),
	TQU("���K�ނ��J�J�J"),
	TQU("gw"),

	TQU("�u���P�b�g�\��\t�ƍ��v�f"),
	TQU("[[.�J�J.]]"),
	TQU("<$&>"),
	TQU("���K�ނ��J�J�J"),
	TQU("gkw"),

	TQU("�u���P�b�g�\��\t�ƍ��v�f"),
	TQU("[[.��.]]"),
	TQU("<$&>"),
	TQU("���K�ނ��J�J�J"),
	TQU("g"),

	TQU("�u���P�b�g�\��\t�ƍ��v�f"),
	TQU("[[.��.]]"),
	TQU("<$&>"),
	TQU("���K�ނ��J�J�J"),
	TQU("gk"),

	TQU("�u���P�b�g�\��\t�ƍ��v�f"),
	TQU("[[.��.]]"),
	TQU("<$&>"),
	TQU("���K�ނ��J�J�J"),
	TQU("gw"),

	TQU("�u���P�b�g�\��\t�ƍ��v�f"),
	TQU("[[.��.]]"),
	TQU("<$&>"),
	TQU("���K�ނ��J�J�J"),
	TQU("gkw"),

	TQU("�u���P�b�g�\��\t�ƍ��v�f"),
	TQU("[[.ab.]]"),
	TQU("<$&>"),
	TQU("ABAbaBab"),
	TQU("g"),

	TQU("�u���P�b�g�\��\t�ƍ��v�f"),
	TQU("[[.ab.]]"),
	TQU("<$&>"),
	TQU("ABAbaBab"),
	TQU("gi"),
};
int	nDataRegEx01_09	= sizeof(DataRegEx01_09) / sizeof(TDataRegEx01);

//----------------------------------------------------------------------
//	DataRegEx01_10	�u��������
//----------------------------------------------------------------------
TDataRegEx01	DataRegEx01_10[]	=
{
	TQU("�u��������"),
	TQU("[���|��]+"),
	TQU("<$_>"),
	TQU("�G�I�J�N�R�V�Z"),
	TQU("wk"),

	TQU("�u��������"),
	TQU("[���|��]+"),
	TQU("<$&>"),
	TQU("�G�I�J�N�R�V�Z"),
	TQU("wk"),

	TQU("�u��������"),
	TQU("[���|��]+"),
	TQU("<$`>"),
	TQU("�G�I�J�N�R�V�Z"),
	TQU("wk"),

	TQU("�u��������"),
	TQU("[���|��]+"),
	TQU("<$'>"),
	TQU("�G�I�J�N�R�V�Z"),
	TQU("wk"),

	TQU("�u��������"),
	TQU("([���|��]+)([^���|��]+)([���|��]+)"),
	TQU("<$1>"),
	TQU("�J�L�N�Z�\�P�R"),
	TQU("wk"),

	TQU("�u��������"),
	TQU("([���|��]+)([^���|��]+)([���|��]+)"),
	TQU("<$2>"),
	TQU("�J�L�N�Z�\�P�R"),
	TQU("wk"),

	TQU("�u��������"),
	TQU("([���|��]+)([^���|��]+)([���|��]+)"),
	TQU("<$3>"),
	TQU("�J�L�N�Z�\�P�R"),
	TQU("wk"),

	TQU("�u��������"),
	TQU("([���|��]+)([^���|��]+)([���|��]+)"),
	TQU("$'$2$`"),
	TQU("�J�L�N�Z�\�P�R"),
	TQU("wk"),

	TQU("�u��������"),
	TQU("([���|��]+)([^���|��]+)([���|��]+)"),
	TQU("$3$2$1"),
	TQU("�J�L�N�Z�\�P�R"),
	TQU("wk"),

	TQU("�u��������"),
	TQU("(?<ka>[���|��]+)(?'sa'[��-��]+)(?<ta>[���|��]+)"),
	TQU("<${ta}><${sa}><${ka}>"),
	TQU("�A�G�J�L�N�Z�\�^�`�e�i�k�m"),
	TQU("wk"),
};
int	nDataRegEx01_10	= sizeof(DataRegEx01_10) / sizeof(TDataRegEx01);


//----------------------------------------------------------------------
//	DataRegEx01_11	�G���[�΍�
//----------------------------------------------------------------------
TDataRegEx01	DataRegEx01_11[]	=
{
	//------------------------------------------------------------
	//	�������[�v
	//------------------------------------------------------------
	TQU("�������[�v"),
	TQU("a*"),
	TQU("<$&>"),
	TQU(""),
	TQU("g"),

	TQU("�������[�v"),
	TQU("^*"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("�������[�v"),
	TQU("^*?"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("�������[�v"),
	TQU("$*"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("�������[�v"),
	TQU("$*?"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("�������[�v"),
	TQU("(?=a)*"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("�������[�v"),
	TQU("(?=a)*?"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("�������[�v"),
	TQU("(?<=a)*"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("�������[�v"),
	TQU("a*"),
	TQU("<$&>"),
	TQU("abac"),
	TQU("g"),

	TQU("�������[�v"),
	TQU("a*?"),
	TQU("<$&>"),
	TQU("abac"),
	TQU("g"),
};
int	nDataRegEx01_11	= sizeof(DataRegEx01_11) / sizeof(TDataRegEx01);
