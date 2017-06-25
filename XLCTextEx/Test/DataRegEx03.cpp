//	XLCTextEx_1.0x	:	Test

//	DataRegEx03.cpp
//
#include "stdafx.h"

//======================================================================
//	DataRegEx03a
//======================================================================
TDataRegEx03a	DataRegEx03a[]	=
{
	TQU("the quick brown fox"),
	TQU("<$&>"),
	TQU("the quick brown fox"),
	TQU("g"),

	TQU("the quick brown fox"),
	TQU("<$&>"),
	TQU("The quick brown FOX"),
	TQU("g"),

	TQU("the quick brown fox"),
	TQU("<$&>"),
	TQU("What do you know about the quick brown fox?"),
	TQU("g"),

	TQU("the quick brown fox"),
	TQU("<$&>"),
	TQU("What do you know about THE QUICK BROWN FOX?"),
	TQU("g"),

	TQU("The quick brown fox"),
	TQU("<$&>"),
	TQU("the quick brown fox"),
	TQU("ig"),

	TQU("The quick brown fox"),
	TQU("<$&>"),
	TQU("The quick brown FOX"),
	TQU("ig"),

	TQU("The quick brown fox"),
	TQU("<$&>"),
	TQU("What do you know about the quick brown fox?"),
	TQU("ig"),

	TQU("The quick brown fox"),
	TQU("<$&>"),
	TQU("What do you know about THE QUICK BROWN FOX?"),
	TQU("ig"),

	TQU("abcd\\t\\n\\r\\f\\a\\e\\071\\x3b\\$\\\\\\?caxyz"),
	TQU("<$&>"),
	TQU("abcd\\t\\n\\r\\f\\a\\e9;\\$\\\\?caxyz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("abxyzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("abxyzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aabxyzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaabxyzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaaabxyzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("abcxyzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aabcxyzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaabcxyzpqrrrabbxyyyypAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaabcxyzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaabcxyzpqrrrabbxyyyypqqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaabcxyzpqrrrabbxyyyypqqqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaabcxyzpqrrrabbxyyyypqqqqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaabcxyzpqrrrabbxyyyypqqqqqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaabcxyzpqrrrabbxyyyypqqqqqqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaaabcxyzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("abxyzzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aabxyzzzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaabxyzzzzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaaabxyzzzzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("abcxyzzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aabcxyzzzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaabcxyzzzzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaaabcxyzzzzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaaabcxyzzzzpqrrrabbbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaaabcxyzzzzpqrrrabbbxyyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaabcxyzpqrrrabbxyyyypABzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaabcxyzpqrrrabbxyyyypABBzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU(">>>aaabxyzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU(">aaaabxyzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU(">>>>abcxyzpqrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("abxyzpqrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("abxyzpqrrrrabbxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("abxyzpqrrrabxyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaaabcxyzzzzpqrrrabbbxyyyyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaaabcxyzzzzpqrrrabbbxyyypqAzz"),
	TQU("g"),

	TQU("a*abc?xyz+pqr{3}ab{2,}xy{4,5}pq{0,6}AB{0,}zz"),
	TQU("<$&>"),
	TQU("aaabcxyzpqrrrabbxyyyypqqqqqqqAzz"),
	TQU("g"),

	TQU("^(abc){1,2}zz"),
	TQU("<$&>"),
	TQU("abczz"),
	TQU("g"),

	TQU("^(abc){1,2}zz"),
	TQU("<$&>"),
	TQU("abcabczz"),
	TQU("g"),

	TQU("^(abc){1,2}zz"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(abc){1,2}zz"),
	TQU("<$&>"),
	TQU("zz"),
	TQU("g"),

	TQU("^(abc){1,2}zz"),
	TQU("<$&>"),
	TQU("abcabcabczz"),
	TQU("g"),

	TQU("^(abc){1,2}zz"),
	TQU("<$&>"),
	TQU(">>abczz"),
	TQU("g"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bc"),
	TQU("g"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bbc"),
	TQU("g"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bbbc"),
	TQU("g"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bac"),
	TQU("g"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bbac"),
	TQU("g"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("aac"),
	TQU("g"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("abbbbbbbbbbbc"),
	TQU("g"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bbbbbbbbbbbac"),
	TQU("g"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("aaac"),
	TQU("g"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("abbbbbbbbbbbac"),
	TQU("g"),

	TQU("^(b+|a){1,2}c"),
	TQU("<$&>"),
	TQU("bc"),
	TQU("g"),

	TQU("^(b+|a){1,2}c"),
	TQU("<$&>"),
	TQU("bbc"),
	TQU("g"),

	TQU("^(b+|a){1,2}c"),
	TQU("<$&>"),
	TQU("bbbc"),
	TQU("g"),

	TQU("^(b+|a){1,2}c"),
	TQU("<$&>"),
	TQU("bac"),
	TQU("g"),

	TQU("^(b+|a){1,2}c"),
	TQU("<$&>"),
	TQU("bbac"),
	TQU("g"),

	TQU("^(b+|a){1,2}c"),
	TQU("<$&>"),
	TQU("aac"),
	TQU("g"),

	TQU("^(b+|a){1,2}c"),
	TQU("<$&>"),
	TQU("abbbbbbbbbbbc"),
	TQU("g"),

	TQU("^(b+|a){1,2}c"),
	TQU("<$&>"),
	TQU("bbbbbbbbbbbac"),
	TQU("g"),

	TQU("^(b+|a){1,2}c"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(b+|a){1,2}c"),
	TQU("<$&>"),
	TQU("aaac"),
	TQU("g"),

	TQU("^(b+|a){1,2}c"),
	TQU("<$&>"),
	TQU("abbbbbbbbbbbac"),
	TQU("g"),

	TQU("^(b+|a){1,2}?bc"),
	TQU("<$&>"),
	TQU("bbc"),
	TQU("g"),

	TQU("^(b*|ba){1,2}?bc"),
	TQU("<$&>"),
	TQU("babc"),
	TQU("g"),

	TQU("^(b*|ba){1,2}?bc"),
	TQU("<$&>"),
	TQU("bbabc"),
	TQU("g"),

	TQU("^(b*|ba){1,2}?bc"),
	TQU("<$&>"),
	TQU("bababc"),
	TQU("g"),

	TQU("^(b*|ba){1,2}?bc"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(b*|ba){1,2}?bc"),
	TQU("<$&>"),
	TQU("bababbc"),
	TQU("g"),

	TQU("^(b*|ba){1,2}?bc"),
	TQU("<$&>"),
	TQU("babababc"),
	TQU("g"),

	TQU("^(ba|b*){1,2}?bc"),
	TQU("<$&>"),
	TQU("babc"),
	TQU("g"),

	TQU("^(ba|b*){1,2}?bc"),
	TQU("<$&>"),
	TQU("bbabc"),
	TQU("g"),

	TQU("^(ba|b*){1,2}?bc"),
	TQU("<$&>"),
	TQU("bababc"),
	TQU("g"),

	TQU("^(ba|b*){1,2}?bc"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(ba|b*){1,2}?bc"),
	TQU("<$&>"),
	TQU("bababbc"),
	TQU("g"),

	TQU("^(ba|b*){1,2}?bc"),
	TQU("<$&>"),
	TQU("babababc"),
	TQU("g"),

	TQU("^\\ca\\cA\\c[\\c{\\c:"),
	TQU("<$&>"),
	TQU("\\x01\\x01\\e;z"),
	TQU("g"),

	TQU("^[ab\\]cde]"),
	TQU("<$&>"),
	TQU("athing"),
	TQU("g"),

	TQU("^[ab\\]cde]"),
	TQU("<$&>"),
	TQU("bthing"),
	TQU("g"),

	TQU("^[ab\\]cde]"),
	TQU("<$&>"),
	TQU("]thing"),
	TQU("g"),

	TQU("^[ab\\]cde]"),
	TQU("<$&>"),
	TQU("cthing"),
	TQU("g"),

	TQU("^[ab\\]cde]"),
	TQU("<$&>"),
	TQU("dthing"),
	TQU("g"),

	TQU("^[ab\\]cde]"),
	TQU("<$&>"),
	TQU("ething"),
	TQU("g"),

	TQU("^[ab\\]cde]"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^[ab\\]cde]"),
	TQU("<$&>"),
	TQU("fthing"),
	TQU("g"),

	TQU("^[ab\\]cde]"),
	TQU("<$&>"),
	TQU("[thing"),
	TQU("g"),

	TQU("^[ab\\]cde]"),
	TQU("<$&>"),
	TQU("\\\\thing"),
	TQU("g"),

	TQU("^[]cde]"),
	TQU("<$&>"),
	TQU("]thing"),
	TQU("g"),

	TQU("^[]cde]"),
	TQU("<$&>"),
	TQU("cthing"),
	TQU("g"),

	TQU("^[]cde]"),
	TQU("<$&>"),
	TQU("dthing"),
	TQU("g"),

	TQU("^[]cde]"),
	TQU("<$&>"),
	TQU("ething"),
	TQU("g"),

	TQU("^[]cde]"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^[]cde]"),
	TQU("<$&>"),
	TQU("athing"),
	TQU("g"),

	TQU("^[]cde]"),
	TQU("<$&>"),
	TQU("fthing"),
	TQU("g"),

	TQU("^[^ab\\]cde]"),
	TQU("<$&>"),
	TQU("fthing"),
	TQU("g"),

	TQU("^[^ab\\]cde]"),
	TQU("<$&>"),
	TQU("[thing"),
	TQU("g"),

	TQU("^[^ab\\]cde]"),
	TQU("<$&>"),
	TQU("\\\\thing"),
	TQU("g"),

	TQU("^[^ab\\]cde]"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^[^ab\\]cde]"),
	TQU("<$&>"),
	TQU("athing"),
	TQU("g"),

	TQU("^[^ab\\]cde]"),
	TQU("<$&>"),
	TQU("bthing"),
	TQU("g"),

	TQU("^[^ab\\]cde]"),
	TQU("<$&>"),
	TQU("]thing"),
	TQU("g"),

	TQU("^[^ab\\]cde]"),
	TQU("<$&>"),
	TQU("cthing"),
	TQU("g"),

	TQU("^[^ab\\]cde]"),
	TQU("<$&>"),
	TQU("dthing"),
	TQU("g"),

	TQU("^[^ab\\]cde]"),
	TQU("<$&>"),
	TQU("ething"),
	TQU("g"),

	TQU("^[^]cde]"),
	TQU("<$&>"),
	TQU("athing"),
	TQU("g"),

	TQU("^[^]cde]"),
	TQU("<$&>"),
	TQU("fthing"),
	TQU("g"),

	TQU("^[^]cde]"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^[^]cde]"),
	TQU("<$&>"),
	TQU("]thing"),
	TQU("g"),

	TQU("^[^]cde]"),
	TQU("<$&>"),
	TQU("cthing"),
	TQU("g"),

	TQU("^[^]cde]"),
	TQU("<$&>"),
	TQU("dthing"),
	TQU("g"),

	TQU("^[^]cde]"),
	TQU("<$&>"),
	TQU("ething"),
	TQU("g"),

	TQU("^[0-9]+$"),
	TQU("<$&>"),
	TQU("0"),
	TQU("gq"),

	TQU("^[0-9]+$"),
	TQU("<$&>"),
	TQU("1"),
	TQU("gq"),

	TQU("^[0-9]+$"),
	TQU("<$&>"),
	TQU("2"),
	TQU("gq"),

	TQU("^[0-9]+$"),
	TQU("<$&>"),
	TQU("3"),
	TQU("gq"),

	TQU("^[0-9]+$"),
	TQU("<$&>"),
	TQU("4"),
	TQU("gq"),

	TQU("^[0-9]+$"),
	TQU("<$&>"),
	TQU("5"),
	TQU("gq"),

	TQU("^[0-9]+$"),
	TQU("<$&>"),
	TQU("6"),
	TQU("gq"),

	TQU("^[0-9]+$"),
	TQU("<$&>"),
	TQU("7"),
	TQU("gq"),

	TQU("^[0-9]+$"),
	TQU("<$&>"),
	TQU("8"),
	TQU("gq"),

	TQU("^[0-9]+$"),
	TQU("<$&>"),
	TQU("9"),
	TQU("gq"),

	TQU("^[0-9]+$"),
	TQU("<$&>"),
	TQU("10"),
	TQU("gq"),

	TQU("^[0-9]+$"),
	TQU("<$&>"),
	TQU("100"),
	TQU("gq"),

	TQU("^[0-9]+$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^[0-9]+$"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("^.*nter"),
	TQU("<$&>"),
	TQU("enter"),
	TQU("g"),

	TQU("^.*nter"),
	TQU("<$&>"),
	TQU("inter"),
	TQU("g"),

	TQU("^.*nter"),
	TQU("<$&>"),
	TQU("uponter"),
	TQU("g"),

	TQU("^xxx[0-9]+$"),
	TQU("<$&>"),
	TQU("xxx0"),
	TQU("g"),

	TQU("^xxx[0-9]+$"),
	TQU("<$&>"),
	TQU("xxx1234"),
	TQU("g"),

	TQU("^xxx[0-9]+$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^xxx[0-9]+$"),
	TQU("<$&>"),
	TQU("xxx"),
	TQU("g"),

	TQU("^.+[0-9][0-9][0-9]$"),
	TQU("<$&>"),
	TQU("x123"),
	TQU("g"),

	TQU("^.+[0-9][0-9][0-9]$"),
	TQU("<$&>"),
	TQU("xx123"),
	TQU("g"),

	TQU("^.+[0-9][0-9][0-9]$"),
	TQU("<$&>"),
	TQU("123456"),
	TQU("gq"),

	TQU("^.+[0-9][0-9][0-9]$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^.+[0-9][0-9][0-9]$"),
	TQU("<$&>"),
	TQU("123"),
	TQU("gq"),

	TQU("^.+[0-9][0-9][0-9]$"),
	TQU("<$&>"),
	TQU("x1234"),
	TQU("g"),

	TQU("^.+?[0-9][0-9][0-9]$"),
	TQU("<$&>"),
	TQU("x123"),
	TQU("g"),

	TQU("^.+?[0-9][0-9][0-9]$"),
	TQU("<$&>"),
	TQU("xx123"),
	TQU("g"),

	TQU("^.+?[0-9][0-9][0-9]$"),
	TQU("<$&>"),
	TQU("123456"),
	TQU("gq"),

	TQU("^.+?[0-9][0-9][0-9]$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^.+?[0-9][0-9][0-9]$"),
	TQU("<$&>"),
	TQU("123"),
	TQU("gq"),

	TQU("^.+?[0-9][0-9][0-9]$"),
	TQU("<$&>"),
	TQU("x1234"),
	TQU("g"),

	TQU("^([^!]+)!(.+)=apquxz\\.ixr\\.zzz\\.ac\\.uk$"),
	TQU("<$&>"),
	TQU("abc!pqr=apquxz.ixr.zzz.ac.uk"),
	TQU("g"),

	TQU("^([^!]+)!(.+)=apquxz\\.ixr\\.zzz\\.ac\\.uk$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^([^!]+)!(.+)=apquxz\\.ixr\\.zzz\\.ac\\.uk$"),
	TQU("<$&>"),
	TQU("!pqr=apquxz.ixr.zzz.ac.uk"),
	TQU("g"),

	TQU("^([^!]+)!(.+)=apquxz\\.ixr\\.zzz\\.ac\\.uk$"),
	TQU("<$&>"),
	TQU("abc!=apquxz.ixr.zzz.ac.uk"),
	TQU("g"),

	TQU("^([^!]+)!(.+)=apquxz\\.ixr\\.zzz\\.ac\\.uk$"),
	TQU("<$&>"),
	TQU("abc!pqr=apquxz:ixr.zzz.ac.uk"),
	TQU("g"),

	TQU("^([^!]+)!(.+)=apquxz\\.ixr\\.zzz\\.ac\\.uk$"),
	TQU("<$&>"),
	TQU("abc!pqr=apquxz.ixr.zzz.ac.ukk"),
	TQU("g"),

	TQU(":"),
	TQU("<$&>"),
	TQU("Well, we need a colon: somewhere"),
	TQU("g"),

	TQU(":"),
	TQU("<$&>"),
	TQU("*** Fail if we don't"),
	TQU("g"),

	TQU("([\\da-f:]+)$"),
	TQU("<$&>"),
	TQU("0abc"),
	TQU("ig"),

	TQU("([\\da-f:]+)$"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("ig"),

	TQU("([\\da-f:]+)$"),
	TQU("<$&>"),
	TQU("fed"),
	TQU("ig"),

	TQU("([\\da-f:]+)$"),
	TQU("<$&>"),
	TQU("E"),
	TQU("ig"),

	TQU("([\\da-f:]+)$"),
	TQU("<$&>"),
	TQU("::"),
	TQU("ig"),

	TQU("([\\da-f:]+)$"),
	TQU("<$&>"),
	TQU("5f03:12C0::932e"),
	TQU("ig"),

	TQU("([\\da-f:]+)$"),
	TQU("<$&>"),
	TQU("fed def"),
	TQU("ig"),

	TQU("([\\da-f:]+)$"),
	TQU("<$&>"),
	TQU("Any old stuff"),
	TQU("ig"),

	TQU("([\\da-f:]+)$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("ig"),

	TQU("([\\da-f:]+)$"),
	TQU("<$&>"),
	TQU("0zzz"),
	TQU("ig"),

	TQU("([\\da-f:]+)$"),
	TQU("<$&>"),
	TQU("gzzz"),
	TQU("ig"),

	TQU("([\\da-f:]+)$"),
	TQU("<$&>"),
	TQU("fed\\x20"),
	TQU("ig"),

	TQU("([\\da-f:]+)$"),
	TQU("<$&>"),
	TQU("Any old rubbish"),
	TQU("ig"),

	TQU("^.*\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})$"),
	TQU("<$&>"),
	TQU(".1.2.3"),
	TQU("g"),

	TQU("^.*\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})$"),
	TQU("<$&>"),
	TQU("A.12.123.0"),
	TQU("g"),

	TQU("^.*\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^.*\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})$"),
	TQU("<$&>"),
	TQU(".1.2.3333"),
	TQU("g"),

	TQU("^.*\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})$"),
	TQU("<$&>"),
	TQU("1.2.3"),
	TQU("g"),

	TQU("^.*\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})$"),
	TQU("<$&>"),
	TQU("1234.2.3"),
	TQU("g"),

	TQU("^(\\d+)\\s+IN\\s+SOA\\s+(\\S+)\\s+(\\S+)\\s*\\(\\s*$"),
	TQU("<$&>"),
	TQU("1 IN SOA non-sp1 non-sp2("),
	TQU("g"),

	TQU("^(\\d+)\\s+IN\\s+SOA\\s+(\\S+)\\s+(\\S+)\\s*\\(\\s*$"),
	TQU("<$&>"),
	TQU("1    IN    SOA    non-sp1    non-sp2   ("),
	TQU("g"),

	TQU("^(\\d+)\\s+IN\\s+SOA\\s+(\\S+)\\s+(\\S+)\\s*\\(\\s*$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(\\d+)\\s+IN\\s+SOA\\s+(\\S+)\\s+(\\S+)\\s*\\(\\s*$"),
	TQU("<$&>"),
	TQU("1IN SOA non-sp1 non-sp2("),
	TQU("g"),

	TQU("^[a-zA-Z\\d][a-zA-Z\\d\\-]*(\\.[a-zA-Z\\d][a-zA-z\\d\\-]*)*\\.$"),
	TQU("<$&>"),
	TQU("a."),
	TQU("g"),

	TQU("^[a-zA-Z\\d][a-zA-Z\\d\\-]*(\\.[a-zA-Z\\d][a-zA-z\\d\\-]*)*\\.$"),
	TQU("<$&>"),
	TQU("Z."),
	TQU("g"),

	TQU("^[a-zA-Z\\d][a-zA-Z\\d\\-]*(\\.[a-zA-Z\\d][a-zA-z\\d\\-]*)*\\.$"),
	TQU("<$&>"),
	TQU("2."),
	TQU("gq"),

	TQU("^[a-zA-Z\\d][a-zA-Z\\d\\-]*(\\.[a-zA-Z\\d][a-zA-z\\d\\-]*)*\\.$"),
	TQU("<$&>"),
	TQU("ab-c.pq-r."),
	TQU("g"),

	TQU("^[a-zA-Z\\d][a-zA-Z\\d\\-]*(\\.[a-zA-Z\\d][a-zA-z\\d\\-]*)*\\.$"),
	TQU("<$&>"),
	TQU("sxk.zzz.ac.uk."),
	TQU("g"),

	TQU("^[a-zA-Z\\d][a-zA-Z\\d\\-]*(\\.[a-zA-Z\\d][a-zA-z\\d\\-]*)*\\.$"),
	TQU("<$&>"),
	TQU("x-.y-."),
	TQU("g"),

	TQU("^[a-zA-Z\\d][a-zA-Z\\d\\-]*(\\.[a-zA-Z\\d][a-zA-z\\d\\-]*)*\\.$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^[a-zA-Z\\d][a-zA-Z\\d\\-]*(\\.[a-zA-Z\\d][a-zA-z\\d\\-]*)*\\.$"),
	TQU("<$&>"),
	TQU("=-abc.peq."),
	TQU("gq"),

	TQU("^\\*\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?(\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?)*$"),
	TQU("<$&>"),
	TQU("*.a"),
	TQU("g"),

	TQU("^\\*\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?(\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?)*$"),
	TQU("<$&>"),
	TQU("*.b0-a"),
	TQU("g"),

	TQU("^\\*\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?(\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?)*$"),
	TQU("<$&>"),
	TQU("*.c3-b.c"),
	TQU("g"),

	TQU("^\\*\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?(\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?)*$"),
	TQU("<$&>"),
	TQU("*.c-a.b-c"),
	TQU("g"),

	TQU("^\\*\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?(\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?)*$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^\\*\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?(\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?)*$"),
	TQU("<$&>"),
	TQU("*.0"),
	TQU("g"),

	TQU("^\\*\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?(\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?)*$"),
	TQU("<$&>"),
	TQU("*.a-"),
	TQU("g"),

	TQU("^\\*\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?(\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?)*$"),
	TQU("<$&>"),
	TQU("*.a-b.c-"),
	TQU("g"),

	TQU("^\\*\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?(\\.[a-z]([a-z\\-\\d]*[a-z\\d]+)?)*$"),
	TQU("<$&>"),
	TQU("*.c-a.0-c"),
	TQU("g"),

	TQU("^(?=ab(de))(abd)(e)"),
	TQU("<$&>"),
	TQU("abde"),
	TQU("g"),

	TQU("^(?!(ab)de|x)(abd)(f)"),
	TQU("<$&>"),
	TQU("abdf"),
	TQU("g"),

	TQU("^(?=(ab(cd)))(ab)"),
	TQU("<$&>"),
	TQU("abcd"),
	TQU("g"),

	TQU("^[\\da-f](\\.[\\da-f])*$"),
	TQU("<$&>"),
	TQU("a.b.c.d"),
	TQU("ig"),

	TQU("^[\\da-f](\\.[\\da-f])*$"),
	TQU("<$&>"),
	TQU("A.B.C.D"),
	TQU("ig"),

	TQU("^[\\da-f](\\.[\\da-f])*$"),
	TQU("<$&>"),
	TQU("a.b.c.1.2.3.C"),
	TQU("ig"),

	TQU("^\\.*\\\\s*(;.*)?$"),
	TQU("<$&>"),
	TQU("\\1234\\"),
	TQU("g"),

	TQU("^\\.*\\\\s*(;.*)?$"),
	TQU("<$&>"),
	TQU("\\abcd\\ ;"),
	TQU("g"),

	TQU("^\\.*\\\\s*(;.*)?$"),
	TQU("<$&>"),
	TQU("\\\\ ; rhubarb"),
	TQU("g"),

	TQU("^\\.*\\\\s*(;.*)?$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^\\.*\\\\s*(;.*)?$"),
	TQU("<$&>"),
	TQU("\\1234\\ : things"),
	TQU("g"),

	TQU("^$"),
	TQU("<$&>"),
	TQU("\\"),
	TQU("g"),

	TQU("^$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("   ^    a   (?# begins with a)  b\\sc (?# then b c) $ (?# then end)"),
	TQU("<$&>"),
	TQU("ab c"),
	TQU("xg"),

	TQU("   ^    a   (?# begins with a)  b\\sc (?# then b c) $ (?# then end)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("xg"),

	TQU("   ^    a   (?# begins with a)  b\\sc (?# then b c) $ (?# then end)"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("xg"),

	TQU("   ^    a   (?# begins with a)  b\\sc (?# then b c) $ (?# then end)"),
	TQU("<$&>"),
	TQU("ab cde"),
	TQU("xg"),

	TQU("(?x)   ^    a   (?# begins with a)  b\\sc (?# then b c) $ (?# then end)"),
	TQU("<$&>"),
	TQU("ab c"),
	TQU("g"),

	TQU("(?x)   ^    a   (?# begins with a)  b\\sc (?# then b c) $ (?# then end)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?x)   ^    a   (?# begins with a)  b\\sc (?# then b c) $ (?# then end)"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("(?x)   ^    a   (?# begins with a)  b\\sc (?# then b c) $ (?# then end)"),
	TQU("<$&>"),
	TQU("ab cde"),
	TQU("g"),

	TQU("^   a\\ b[c ]d       $"),
	TQU("<$&>"),
	TQU("a bcd"),
	TQU("xg"),

	TQU("^   a\\ b[c ]d       $"),
	TQU("<$&>"),
	TQU("a b d"),
	TQU("xg"),

	TQU("^   a\\ b[c ]d       $"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("xg"),

	TQU("^   a\\ b[c ]d       $"),
	TQU("<$&>"),
	TQU("abcd"),
	TQU("xg"),

	TQU("^   a\\ b[c ]d       $"),
	TQU("<$&>"),
	TQU("ab d"),
	TQU("xg"),

	TQU("^(a(b(c)))(d(e(f)))(h(i(j)))(k(l(m)))$"),
	TQU("<$&>"),
	TQU("abcdefhijklm"),
	TQU("g"),

	TQU("^(?:a(b(c)))(?:d(e(f)))(?:h(i(j)))(?:k(l(m)))$"),
	TQU("<$&>"),
	TQU("abcdefhijklm"),
	TQU("g"),

	TQU("^[\\w][\\W][\\s][\\S][\\d][\\D][\\b][\\n][\\c]][\\022]"),
	TQU("<$&>"),
	TQU("a+ Z0+\\x08\\n\\x1d\\x12"),
	TQU("g"),

	TQU("^[.^$|()*+?{,}]+"),
	TQU("<$&>"),
	TQU(".^\\$(*+)|{?,?}"),
	TQU("g"),

	TQU("^a*\\w"),
	TQU("<$&>"),
	TQU("z"),
	TQU("g"),

	TQU("^a*\\w"),
	TQU("<$&>"),
	TQU("az"),
	TQU("g"),

	TQU("^a*\\w"),
	TQU("<$&>"),
	TQU("aaaz"),
	TQU("g"),

	TQU("^a*\\w"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("^a*\\w"),
	TQU("<$&>"),
	TQU("aa"),
	TQU("g"),

	TQU("^a*\\w"),
	TQU("<$&>"),
	TQU("aaaa"),
	TQU("g"),

	TQU("^a*\\w"),
	TQU("<$&>"),
	TQU("a+"),
	TQU("g"),

	TQU("^a*\\w"),
	TQU("<$&>"),
	TQU("aa+"),
	TQU("g"),

	TQU("^a*?\\w"),
	TQU("<$&>"),
	TQU("z"),
	TQU("g"),

	TQU("^a*?\\w"),
	TQU("<$&>"),
	TQU("az"),
	TQU("g"),

	TQU("^a*?\\w"),
	TQU("<$&>"),
	TQU("aaaz"),
	TQU("g"),

	TQU("^a*?\\w"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("^a*?\\w"),
	TQU("<$&>"),
	TQU("aa"),
	TQU("g"),

	TQU("^a*?\\w"),
	TQU("<$&>"),
	TQU("aaaa"),
	TQU("g"),

	TQU("^a*?\\w"),
	TQU("<$&>"),
	TQU("a+"),
	TQU("g"),

	TQU("^a*?\\w"),
	TQU("<$&>"),
	TQU("aa+"),
	TQU("g"),

	TQU("^a+\\w"),
	TQU("<$&>"),
	TQU("az"),
	TQU("g"),

	TQU("^a+\\w"),
	TQU("<$&>"),
	TQU("aaaz"),
	TQU("g"),

	TQU("^a+\\w"),
	TQU("<$&>"),
	TQU("aa"),
	TQU("g"),

	TQU("^a+\\w"),
	TQU("<$&>"),
	TQU("aaaa"),
	TQU("g"),

	TQU("^a+\\w"),
	TQU("<$&>"),
	TQU("aa+"),
	TQU("g"),

	TQU("^a+?\\w"),
	TQU("<$&>"),
	TQU("az"),
	TQU("g"),

	TQU("^a+?\\w"),
	TQU("<$&>"),
	TQU("aaaz"),
	TQU("g"),

	TQU("^a+?\\w"),
	TQU("<$&>"),
	TQU("aa"),
	TQU("g"),

	TQU("^a+?\\w"),
	TQU("<$&>"),
	TQU("aaaa"),
	TQU("g"),

	TQU("^a+?\\w"),
	TQU("<$&>"),
	TQU("aa+"),
	TQU("g"),

	TQU("^\\d{8}\\w{2,}"),
	TQU("<$&>"),
	TQU("1234567890"),
	TQU("gq"),

	TQU("^\\d{8}\\w{2,}"),
	TQU("<$&>"),
	TQU("12345678ab"),
	TQU("g"),

	TQU("^\\d{8}\\w{2,}"),
	TQU("<$&>"),
	TQU("12345678__"),
	TQU("g"),

	TQU("^\\d{8}\\w{2,}"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^\\d{8}\\w{2,}"),
	TQU("<$&>"),
	TQU("1234567"),
	TQU("gq"),

	TQU("^[aeiou\\d]{4,5}$"),
	TQU("<$&>"),
	TQU("uoie"),
	TQU("g"),

	TQU("^[aeiou\\d]{4,5}$"),
	TQU("<$&>"),
	TQU("1234"),
	TQU("gq"),

	TQU("^[aeiou\\d]{4,5}$"),
	TQU("<$&>"),
	TQU("12345"),
	TQU("gq"),

	TQU("^[aeiou\\d]{4,5}$"),
	TQU("<$&>"),
	TQU("aaaaa"),
	TQU("g"),

	TQU("^[aeiou\\d]{4,5}$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^[aeiou\\d]{4,5}$"),
	TQU("<$&>"),
	TQU("123456"),
	TQU("gq"),

	TQU("^[aeiou\\d]{4,5}?"),
	TQU("<$&>"),
	TQU("uoie"),
	TQU("g"),

	TQU("^[aeiou\\d]{4,5}?"),
	TQU("<$&>"),
	TQU("1234"),
	TQU("gq"),

	TQU("^[aeiou\\d]{4,5}?"),
	TQU("<$&>"),
	TQU("12345"),
	TQU("gq"),

	TQU("^[aeiou\\d]{4,5}?"),
	TQU("<$&>"),
	TQU("aaaaa"),
	TQU("gq"),

	TQU("^[aeiou\\d]{4,5}?"),
	TQU("<$&>"),
	TQU("123456"),
	TQU("gq"),

	TQU("\\A(abc|def)=(\\1){2,3}\\Z"),
	TQU("<$&>"),
	TQU("abc=abcabc"),
	TQU("g"),

	TQU("\\A(abc|def)=(\\1){2,3}\\Z"),
	TQU("<$&>"),
	TQU("def=defdefdef"),
	TQU("g"),

	TQU("\\A(abc|def)=(\\1){2,3}\\Z"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("\\A(abc|def)=(\\1){2,3}\\Z"),
	TQU("<$&>"),
	TQU("abc=defdef"),
	TQU("g"),

	TQU("^(a)(b)(c)(d)(e)(f)(g)(h)(i)(j)(k)\\11*(\\3\\4)\\1(?#)2$"),
	TQU("<$&>"),
	TQU("abcdefghijkcda2"),
	TQU("g"),

	TQU("^(a)(b)(c)(d)(e)(f)(g)(h)(i)(j)(k)\\11*(\\3\\4)\\1(?#)2$"),
	TQU("<$&>"),
	TQU("abcdefghijkkkkcda2"),
	TQU("g"),

	TQU("(cat(a(ract|tonic)|erpillar)) \\1()2(3)"),
	TQU("<$&>"),
	TQU("cataract cataract23"),
	TQU("g"),

	TQU("(cat(a(ract|tonic)|erpillar)) \\1()2(3)"),
	TQU("<$&>"),
	TQU("catatonic catatonic23"),
	TQU("g"),

	TQU("(cat(a(ract|tonic)|erpillar)) \\1()2(3)"),
	TQU("<$&>"),
	TQU("caterpillar caterpillar23"),
	TQU("g"),

	TQU("^From +([^ ]+) +[a-zA-Z][a-zA-Z][a-zA-Z] +[a-zA-Z][a-zA-Z][a-zA-Z] +[0-9]?[0-9] +[0-9][0-9]:[0-9][0-9]"),
	TQU("<$&>"),
	TQU("From abcd  Mon Sep 01 12:33:02 1997"),
	TQU("g"),

	TQU("^From\\s+\\S+\\s+([a-zA-Z]{3}\\s+){2}\\d{1,2}\\s+\\d\\d:\\d\\d"),
	TQU("<$&>"),
	TQU("From abcd  Mon Sep 01 12:33:02 1997"),
	TQU("g"),

	TQU("^From\\s+\\S+\\s+([a-zA-Z]{3}\\s+){2}\\d{1,2}\\s+\\d\\d:\\d\\d"),
	TQU("<$&>"),
	TQU("From abcd  Mon Sep  1 12:33:02 1997"),
	TQU("g"),

	TQU("^From\\s+\\S+\\s+([a-zA-Z]{3}\\s+){2}\\d{1,2}\\s+\\d\\d:\\d\\d"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^From\\s+\\S+\\s+([a-zA-Z]{3}\\s+){2}\\d{1,2}\\s+\\d\\d:\\d\\d"),
	TQU("<$&>"),
	TQU("From abcd  Sep 01 12:33:02 1997"),
	TQU("g"),

	TQU("^12.34"),
	TQU("<$&>"),
	TQU("12\\n34"),
	TQU("sg"),

	TQU("^12.34"),
	TQU("<$&>"),
	TQU("12\\r34"),
	TQU("sg"),

	TQU("\\w+(?=\\t)"),
	TQU("<$&>"),
	TQU("the quick brown\\t fox"),
	TQU("g"),

	TQU("foo(?!bar)(.*)"),
	TQU("<$&>"),
	TQU("foobar is foolish see?"),
	TQU("g"),

	TQU("(?:(?!foo)...|^.{0,2})bar(.*)"),
	TQU("<$&>"),
	TQU("foobar crowbar etc"),
	TQU("g"),

	TQU("(?:(?!foo)...|^.{0,2})bar(.*)"),
	TQU("<$&>"),
	TQU("barrel"),
	TQU("g"),

	TQU("(?:(?!foo)...|^.{0,2})bar(.*)"),
	TQU("<$&>"),
	TQU("2barrel"),
	TQU("g"),

	TQU("(?:(?!foo)...|^.{0,2})bar(.*)"),
	TQU("<$&>"),
	TQU("A barrel"),
	TQU("g"),

	TQU("^(\\D*)(?=\\d)(?!123)"),
	TQU("<$&>"),
	TQU("abc456"),
	TQU("g"),

	TQU("^(\\D*)(?=\\d)(?!123)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(\\D*)(?=\\d)(?!123)"),
	TQU("<$&>"),
	TQU("abc123"),
	TQU("g"),

	TQU("^1234(?# test newlines\n\n  inside)"),
	TQU("<$&>"),
	TQU("1234"),
	TQU("gq"),

	TQU("^1234 #comment in extended re\n  \n#rhubarb"),
	TQU("<$&>"),
	TQU("1234"),
	TQU("xgq"),

	TQU("  abcd"),
	TQU("<$&>"),
	TQU("abcd"),
	TQU("xg"),

	TQU("^abcd#rhubarb"),
	TQU("<$&>"),
	TQU("abcd"),
	TQU("xg"),

	TQU("^(a)\\1{2,3}(.)"),
	TQU("<$&>"),
	TQU("aaab"),
	TQU("g"),

	TQU("^(a)\\1{2,3}(.)"),
	TQU("<$&>"),
	TQU("aaaab"),
	TQU("g"),

	TQU("^(a)\\1{2,3}(.)"),
	TQU("<$&>"),
	TQU("aaaaab"),
	TQU("g"),

	TQU("^(a)\\1{2,3}(.)"),
	TQU("<$&>"),
	TQU("aaaaaab"),
	TQU("g"),

	TQU("(?!^)abc"),
	TQU("<$&>"),
	TQU("the abc"),
	TQU("g"),

	TQU("(?!^)abc"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?!^)abc"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("(?=^)abc"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("(?=^)abc"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?=^)abc"),
	TQU("<$&>"),
	TQU("the abc"),
	TQU("g"),

	TQU("^[ab]{1,3}(ab*|b)"),
	TQU("<$&>"),
	TQU("aabbbbb"),
	TQU("g"),

	TQU("^[ab]{1,3}?(ab*|b)"),
	TQU("<$&>"),
	TQU("aabbbbb"),
	TQU("g"),

	TQU("^[ab]{1,3}?(ab*?|b)"),
	TQU("<$&>"),
	TQU("aabbbbb"),
	TQU("g"),

	TQU("^[ab]{1,3}(ab*?|b)"),
	TQU("<$&>"),
	TQU("aabbbbb"),
	TQU("g"),

	TQU("abc\\0def\\00pqr\\000xyz\\0000AB"),
	TQU("<$&>"),
	TQU("abc\\0def\\00pqr\\000xyz\\0000AB"),
	TQU("g"),

	TQU("abc\\0def\\00pqr\\000xyz\\0000AB"),
	TQU("<$&>"),
	TQU("abc456 abc\\0def\\00pqr\\000xyz\\0000ABCDE"),
	TQU("g"),

	TQU("abc\\x0def\\x00pqr\\x000xyz\\x0000AB"),
	TQU("<$&>"),
	TQU("abc\\x0def\\x00pqr\\x000xyz\\x0000AB"),
	TQU("g"),

	TQU("abc\\x0def\\x00pqr\\x000xyz\\x0000AB"),
	TQU("<$&>"),
	TQU("abc456 abc\\x0def\\x00pqr\\x000xyz\\x0000ABCDE"),
	TQU("g"),

	TQU("^[\\000-\\037]"),
	TQU("<$&>"),
	TQU("\\0A"),
	TQU("g"),

	TQU("^[\\000-\\037]"),
	TQU("<$&>"),
	TQU("\\01B"),
	TQU("g"),

	TQU("^[\\000-\\037]"),
	TQU("<$&>"),
	TQU("\\037C"),
	TQU("g"),

	TQU("\\0*"),
	TQU("<$&>"),
	TQU("\\0\\0\\0\\0"),
	TQU("g"),

	TQU("A\\x0{2,3}Z"),
	TQU("<$&>"),
	TQU("The A\\x0\\x0Z"),
	TQU("g"),

	TQU("A\\x0{2,3}Z"),
	TQU("<$&>"),
	TQU("An A\\0\\x0\\0Z"),
	TQU("g"),

	TQU("A\\x0{2,3}Z"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("A\\x0{2,3}Z"),
	TQU("<$&>"),
	TQU("A\\0Z"),
	TQU("g"),

	TQU("A\\x0{2,3}Z"),
	TQU("<$&>"),
	TQU("A\\0\\x0\\0\\x0Z"),
	TQU("g"),

	TQU("^(cow|)\\1(bell)"),
	TQU("<$&>"),
	TQU("cowcowbell"),
	TQU("g"),

	TQU("^(cow|)\\1(bell)"),
	TQU("<$&>"),
	TQU("bell"),
	TQU("g"),

	TQU("^(cow|)\\1(bell)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(cow|)\\1(bell)"),
	TQU("<$&>"),
	TQU("cowbell"),
	TQU("g"),

	TQU("^\\s"),
	TQU("<$&>"),
	TQU("\\040abc"),
	TQU("g"),

	TQU("^\\s"),
	TQU("<$&>"),
	TQU("\\x0cabc"),
	TQU("g"),

	TQU("^\\s"),
	TQU("<$&>"),
	TQU("\\nabc"),
	TQU("g"),

	TQU("^\\s"),
	TQU("<$&>"),
	TQU("\\rabc"),
	TQU("g"),

	TQU("^\\s"),
	TQU("<$&>"),
	TQU("\\tabc"),
	TQU("g"),

	TQU("^\\s"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^\\s"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("^a\nb\n\n      c"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("xg"),

	TQU("^(a|)\\1*b"),
	TQU("<$&>"),
	TQU("ab"),
	TQU("g"),

	TQU("^(a|)\\1*b"),
	TQU("<$&>"),
	TQU("aaaab"),
	TQU("g"),

	TQU("^(a|)\\1*b"),
	TQU("<$&>"),
	TQU("b"),
	TQU("g"),

	TQU("^(a|)\\1*b"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(a|)\\1*b"),
	TQU("<$&>"),
	TQU("acb"),
	TQU("g"),

	TQU("^(a|)\\1+b"),
	TQU("<$&>"),
	TQU("aab"),
	TQU("g"),

	TQU("^(a|)\\1+b"),
	TQU("<$&>"),
	TQU("aaaab"),
	TQU("g"),

	TQU("^(a|)\\1+b"),
	TQU("<$&>"),
	TQU("b"),
	TQU("g"),

	TQU("^(a|)\\1+b"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(a|)\\1+b"),
	TQU("<$&>"),
	TQU("ab"),
	TQU("g"),

	TQU("^(a|)\\1?b"),
	TQU("<$&>"),
	TQU("ab"),
	TQU("g"),

	TQU("^(a|)\\1?b"),
	TQU("<$&>"),
	TQU("aab"),
	TQU("g"),

	TQU("^(a|)\\1?b"),
	TQU("<$&>"),
	TQU("b"),
	TQU("g"),

	TQU("^(a|)\\1?b"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(a|)\\1?b"),
	TQU("<$&>"),
	TQU("acb"),
	TQU("g"),

	TQU("^(a|)\\1{2}b"),
	TQU("<$&>"),
	TQU("aaab"),
	TQU("g"),

	TQU("^(a|)\\1{2}b"),
	TQU("<$&>"),
	TQU("b"),
	TQU("g"),

	TQU("^(a|)\\1{2}b"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(a|)\\1{2}b"),
	TQU("<$&>"),
	TQU("ab"),
	TQU("g"),

	TQU("^(a|)\\1{2}b"),
	TQU("<$&>"),
	TQU("aab"),
	TQU("g"),

	TQU("^(a|)\\1{2}b"),
	TQU("<$&>"),
	TQU("aaaab"),
	TQU("g"),

	TQU("^(a|)\\1{2,3}b"),
	TQU("<$&>"),
	TQU("aaab"),
	TQU("g"),

	TQU("^(a|)\\1{2,3}b"),
	TQU("<$&>"),
	TQU("aaaab"),
	TQU("g"),

	TQU("^(a|)\\1{2,3}b"),
	TQU("<$&>"),
	TQU("b"),
	TQU("g"),

	TQU("^(a|)\\1{2,3}b"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(a|)\\1{2,3}b"),
	TQU("<$&>"),
	TQU("ab"),
	TQU("g"),

	TQU("^(a|)\\1{2,3}b"),
	TQU("<$&>"),
	TQU("aab"),
	TQU("g"),

	TQU("^(a|)\\1{2,3}b"),
	TQU("<$&>"),
	TQU("aaaaab"),
	TQU("g"),

	TQU("ab{1,3}bc"),
	TQU("<$&>"),
	TQU("abbbbc"),
	TQU("g"),

	TQU("ab{1,3}bc"),
	TQU("<$&>"),
	TQU("abbbc"),
	TQU("g"),

	TQU("ab{1,3}bc"),
	TQU("<$&>"),
	TQU("abbc"),
	TQU("g"),

	TQU("ab{1,3}bc"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("ab{1,3}bc"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("ab{1,3}bc"),
	TQU("<$&>"),
	TQU("abbbbbc"),
	TQU("g"),

	TQU("([^.]*)\\.([^:]*):[T ]+(.*)"),
	TQU("<$&>"),
	TQU("track1.title:TBlah blah blah"),
	TQU("g"),

	TQU("([^.]*)\\.([^:]*):[T ]+(.*)"),
	TQU("<$&>"),
	TQU("track1.title:TBlah blah blah"),
	TQU("ig"),

	TQU("([^.]*)\\.([^:]*):[t ]+(.*)"),
	TQU("<$&>"),
	TQU("track1.title:TBlah blah blah"),
	TQU("ig"),

	TQU("^[W-c]+$"),
	TQU("<$&>"),
	TQU("WXY_^abc"),
	TQU("g"),

	TQU("^[W-c]+$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^[W-c]+$"),
	TQU("<$&>"),
	TQU("wxy"),
	TQU("g"),

	TQU("^[W-c]+$"),
	TQU("<$&>"),
	TQU("WXY_^abc"),
	TQU("ig"),

	TQU("^[W-c]+$"),
	TQU("<$&>"),
	TQU("wxy_^ABC"),
	TQU("ig"),

	TQU("^[\\x3f-\\x5F]+$"),
	TQU("<$&>"),
	TQU("WXY_^abc"),
	TQU("ig"),

	TQU("^[\\x3f-\\x5F]+$"),
	TQU("<$&>"),
	TQU("wxy_^ABC"),
	TQU("ig"),

	TQU("^abc$"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("mg"),

	TQU("^abc$"),
	TQU("<$&>"),
	TQU("qqq\\nabc"),
	TQU("mg"),

	TQU("^abc$"),
	TQU("<$&>"),
	TQU("abc\\nzzz"),
	TQU("mg"),

	TQU("^abc$"),
	TQU("<$&>"),
	TQU("qqq\\nabc\\nzzz"),
	TQU("mg"),

	TQU("^abc$"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("^abc$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^abc$"),
	TQU("<$&>"),
	TQU("qqq\\nabc"),
	TQU("g"),

	TQU("^abc$"),
	TQU("<$&>"),
	TQU("abc\\nzzz"),
	TQU("g"),

	TQU("^abc$"),
	TQU("<$&>"),
	TQU("qqq\\nabc\\nzzz"),
	TQU("g"),

	TQU("\\Aabc\\Z"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("mg"),

	TQU("\\Aabc\\Z"),
	TQU("<$&>"),
	TQU("abc\\n"),
	TQU("mg"),

	TQU("\\Aabc\\Z"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("mg"),

	TQU("\\Aabc\\Z"),
	TQU("<$&>"),
	TQU("qqq\\nabc"),
	TQU("mg"),

	TQU("\\Aabc\\Z"),
	TQU("<$&>"),
	TQU("abc\\nzzz"),
	TQU("mg"),

	TQU("\\Aabc\\Z"),
	TQU("<$&>"),
	TQU("qqq\\nabc\\nzzz"),
	TQU("mg"),

	TQU("\\A(.)*\\Z"),
	TQU("<$&>"),
	TQU("abc\\ndef"),
	TQU("sg"),

	TQU("\\A(.)*\\Z"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("mg"),

	TQU("\\A(.)*\\Z"),
	TQU("<$&>"),
	TQU("abc\\ndef"),
	TQU("mg"),

	TQU("(?:b)|(?::+)"),
	TQU("<$&>"),
	TQU("b::c"),
	TQU("g"),

	TQU("(?:b)|(?::+)"),
	TQU("<$&>"),
	TQU("c::b"),
	TQU("g"),

	TQU("[-az]+"),
	TQU("<$&>"),
	TQU("az-"),
	TQU("g"),

	TQU("[-az]+"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("[-az]+"),
	TQU("<$&>"),
	TQU("b"),
	TQU("g"),

	TQU("[az-]+"),
	TQU("<$&>"),
	TQU("za-"),
	TQU("g"),

	TQU("[az-]+"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("[az-]+"),
	TQU("<$&>"),
	TQU("b"),
	TQU("g"),

	TQU("[a\\-z]+"),
	TQU("<$&>"),
	TQU("a-z"),
	TQU("g"),

	TQU("[a\\-z]+"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("[a\\-z]+"),
	TQU("<$&>"),
	TQU("b"),
	TQU("g"),

	TQU("[a-z]+"),
	TQU("<$&>"),
	TQU("abcdxyz"),
	TQU("g"),

	TQU("[\\d-]+"),
	TQU("<$&>"),
	TQU("12-34"),
	TQU("g"),

	TQU("[\\d-]+"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("[\\d-]+"),
	TQU("<$&>"),
	TQU("aaa"),
	TQU("g"),

	TQU("[\\d-z]+"),
	TQU("<$&>"),
	TQU("12-34z"),
	TQU("g"),

	TQU("[\\d-z]+"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("[\\d-z]+"),
	TQU("<$&>"),
	TQU("aaa"),
	TQU("g"),

	TQU("\\x5c"),
	TQU("<$&>"),
	TQU("\\\\"),
	TQU("g"),

	TQU("\\x20Z"),
	TQU("<$&>"),
	TQU("the Zoo"),
	TQU("g"),

	TQU("\\x20Z"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("\\x20Z"),
	TQU("<$&>"),
	TQU("Zulu"),
	TQU("g"),

	TQU("(abc)\\1"),
	TQU("<$&>"),
	TQU("abcabc"),
	TQU("ig"),

	TQU("(abc)\\1"),
	TQU("<$&>"),
	TQU("ABCabc"),
	TQU("ig"),

	TQU("(abc)\\1"),
	TQU("<$&>"),
	TQU("abcABC"),
	TQU("ig"),

	TQU("ab{3cd"),
	TQU("<$&>"),
	TQU("ab{3cd"),
	TQU("g"),

	TQU("ab{3,cd"),
	TQU("<$&>"),
	TQU("ab{3,cd"),
	TQU("g"),

	TQU("ab{3,4a}cd"),
	TQU("<$&>"),
	TQU("ab{3,4a}cd"),
	TQU("g"),

	TQU("{4,5a}bc"),
	TQU("<$&>"),
	TQU("{4,5a}bc"),
	TQU("g"),

	TQU("abc$"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("abc$"),
	TQU("<$&>"),
	TQU("abc\\n"),
	TQU("g"),

	TQU("abc$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("abc$"),
	TQU("<$&>"),
	TQU("abc\\ndef"),
	TQU("g"),

	TQU("(abc)\\123"),
	TQU("<$&>"),
	TQU("abc\\x53"),
	TQU("g"),

	TQU("(abc)\\223"),
	TQU("<$&>"),
	TQU("abc\\x93"),
	TQU("g"),

	TQU("(abc)\\323"),
	TQU("<$&>"),
	TQU("abc\\xd3"),
	TQU("g"),

	TQU("(abc)\\100"),
	TQU("<$&>"),
	TQU("abc\\x40"),
	TQU("g"),

	TQU("(abc)\\100"),
	TQU("<$&>"),
	TQU("abc\\100"),
	TQU("g"),

	TQU("(abc)\\1000"),
	TQU("<$&>"),
	TQU("abc\\x400"),
	TQU("g"),

	TQU("(abc)\\1000"),
	TQU("<$&>"),
	TQU("abc\\x40\\x30"),
	TQU("g"),

	TQU("(abc)\\1000"),
	TQU("<$&>"),
	TQU("abc\\1000"),
	TQU("g"),

	TQU("(abc)\\1000"),
	TQU("<$&>"),
	TQU("abc\\100\\x30"),
	TQU("g"),

	TQU("(abc)\\1000"),
	TQU("<$&>"),
	TQU("abc\\100\\060"),
	TQU("g"),

	TQU("(abc)\\1000"),
	TQU("<$&>"),
	TQU("abc\\100\\60"),
	TQU("g"),

	TQU("abc\\81"),
	TQU("<$&>"),
	TQU("abc\\081"),
	TQU("g"),

	TQU("abc\\81"),
	TQU("<$&>"),
	TQU("abc\\0\\x38\\x31"),
	TQU("g"),

	TQU("abc\\91"),
	TQU("<$&>"),
	TQU("abc\\091"),
	TQU("g"),

	TQU("abc\\91"),
	TQU("<$&>"),
	TQU("abc\\0\\x39\\x31"),
	TQU("g"),

	TQU("(a)(b)(c)(d)(e)(f)(g)(h)(i)(j)(k)(l)\\12\\123"),
	TQU("<$&>"),
	TQU("abcdefghijkllS"),
	TQU("g"),

	TQU("(a)(b)(c)(d)(e)(f)(g)(h)(i)(j)(k)\\12\\123"),
	TQU("<$&>"),
	TQU("abcdefghijk\\12S"),
	TQU("g"),

	TQU("ab\\idef"),
	TQU("<$&>"),
	TQU("abidef"),
	TQU("g"),

	TQU("a{0}bc"),
	TQU("<$&>"),
	TQU("bc"),
	TQU("g"),

	TQU("(a|(bc)){0,0}?xyz"),
	TQU("<$&>"),
	TQU("xyz"),
	TQU("g"),

	TQU("abc[\\10]de"),
	TQU("<$&>"),
	TQU("abc\\010de"),
	TQU("g"),

	TQU("abc[\\1]de"),
	TQU("<$&>"),
	TQU("abc\\1de"),
	TQU("g"),

	TQU("(abc)[\\1]de"),
	TQU("<$&>"),
	TQU("abc\\1de"),
	TQU("g"),

	TQU("(?s)a.b"),
	TQU("<$&>"),
	TQU("a\\nb"),
	TQU("g"),

	TQU("^([^a])([^\\b])([^c]*)([^d]{3,4})"),
	TQU("<$&>"),
	TQU("baNOTccccd"),
	TQU("g"),

	TQU("^([^a])([^\\b])([^c]*)([^d]{3,4})"),
	TQU("<$&>"),
	TQU("baNOTcccd"),
	TQU("g"),

	TQU("^([^a])([^\\b])([^c]*)([^d]{3,4})"),
	TQU("<$&>"),
	TQU("baNOTccd"),
	TQU("g"),

	TQU("^([^a])([^\\b])([^c]*)([^d]{3,4})"),
	TQU("<$&>"),
	TQU("bacccd"),
	TQU("g"),

	TQU("^([^a])([^\\b])([^c]*)([^d]{3,4})"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^([^a])([^\\b])([^c]*)([^d]{3,4})"),
	TQU("<$&>"),
	TQU("anything"),
	TQU("g"),

	TQU("^([^a])([^\\b])([^c]*)([^d]{3,4})"),
	TQU("<$&>"),
	TQU("b\\bc"),
	TQU("g"),

	TQU("^([^a])([^\\b])([^c]*)([^d]{3,4})"),
	TQU("<$&>"),
	TQU("baccd"),
	TQU("g"),

	TQU("[^a]"),
	TQU("<$&>"),
	TQU("Abc"),
	TQU("g"),

	TQU("[^a]"),
	TQU("<$&>"),
	TQU("Abc"),
	TQU("ig"),

	TQU("[^a]+"),
	TQU("<$&>"),
	TQU("AAAaAbc"),
	TQU("g"),

	TQU("[^a]+"),
	TQU("<$&>"),
	TQU("AAAaAbc"),
	TQU("ig"),

	TQU("[^a]+"),
	TQU("<$&>"),
	TQU("bbb\\nccc"),
	TQU("g"),

	TQU("[^k]$"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("[^k]$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("[^k]$"),
	TQU("<$&>"),
	TQU("abk"),
	TQU("g"),

	TQU("[^k]{2,3}$"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("[^k]{2,3}$"),
	TQU("<$&>"),
	TQU("kbc"),
	TQU("g"),

	TQU("[^k]{2,3}$"),
	TQU("<$&>"),
	TQU("kabc"),
	TQU("g"),

	TQU("[^k]{2,3}$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("[^k]{2,3}$"),
	TQU("<$&>"),
	TQU("abk"),
	TQU("g"),

	TQU("[^k]{2,3}$"),
	TQU("<$&>"),
	TQU("akb"),
	TQU("g"),

	TQU("[^k]{2,3}$"),
	TQU("<$&>"),
	TQU("akk"),
	TQU("g"),

	TQU("^\\d{8,}\\@.+[^k]$"),
	TQU("<$&>"),
	TQU("12345678\\@a.b.c.d"),
	TQU("g"),

	TQU("^\\d{8,}\\@.+[^k]$"),
	TQU("<$&>"),
	TQU("123456789\\@x.y.z"),
	TQU("g"),

	TQU("^\\d{8,}\\@.+[^k]$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^\\d{8,}\\@.+[^k]$"),
	TQU("<$&>"),
	TQU("12345678\\@x.y.uk"),
	TQU("g"),

	TQU("^\\d{8,}\\@.+[^k]$"),
	TQU("<$&>"),
	TQU("1234567\\@a.b.c.d"),
	TQU("g"),

	TQU("(a)\\1{8,}"),
	TQU("<$&>"),
	TQU("aaaaaaaaa"),
	TQU("g"),

	TQU("(a)\\1{8,}"),
	TQU("<$&>"),
	TQU("aaaaaaaaaa"),
	TQU("g"),

	TQU("(a)\\1{8,}"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(a)\\1{8,}"),
	TQU("<$&>"),
	TQU("aaaaaaa"),
	TQU("g"),

	TQU("[^a]"),
	TQU("<$&>"),
	TQU("aaaabcd"),
	TQU("g"),

	TQU("[^a]"),
	TQU("<$&>"),
	TQU("aaAabcd"),
	TQU("g"),

	TQU("[^a]"),
	TQU("<$&>"),
	TQU("aaaabcd"),
	TQU("ig"),

	TQU("[^a]"),
	TQU("<$&>"),
	TQU("aaAabcd"),
	TQU("ig"),

	TQU("[^az]"),
	TQU("<$&>"),
	TQU("aaaabcd"),
	TQU("g"),

	TQU("[^az]"),
	TQU("<$&>"),
	TQU("aaAabcd"),
	TQU("g"),

	TQU("[^az]"),
	TQU("<$&>"),
	TQU("aaaabcd"),
	TQU("ig"),

	TQU("[^az]"),
	TQU("<$&>"),
	TQU("aaAabcd"),
	TQU("ig"),

	TQU("\\000\\001\\002\\003\\004\\005\\006\\007\\010\\011\\012\\013\\014\\015\\016\\017\\020\\021\\022\\023\\024\\025\\026\\027\\030\\031\\032\\033\\034\\035\\036\\037\\040\\041\\042\\043\\044\\045\\046\\047\\050\\051\\052\\053\\054\\055\\056\\057\\060\\061\\062\\063\\064\\065\\066\\067\\070\\071\\072\\073\\074\\075\\076\\077\\100\\101\\102\\103\\104\\105\\106\\107\\110\\111\\112\\113\\114\\115\\116\\117\\120\\121\\122\\123\\124\\125\\126\\127\\130\\131\\132\\133\\134\\135\\136\\137\\140\\141\\142\\143\\144\\145\\146\\147\\150\\151\\152\\153\\154\\155\\156\\157\\160\\161\\162\\163\\164\\165\\166\\167\\170\\171\\172\\173\\174\\175\\176\\177\\200\\201\\202\\203\\204\\205\\206\\207\\210\\211\\212\\213\\214\\215\\216\\217\\220\\221\\222\\223\\224\\225\\226\\227\\230\\231\\232\\233\\234\\235\\236\\237\\240\\241\\242\\243\\244\\245\\246\\247\\250\\251\\252\\253\\254\\255\\256\\257\\260\\261\\262\\263\\264\\265\\266\\267\\270\\271\\272\\273\\274\\275\\276\\277\\300\\301\\302\\303\\304\\305\\306\\307\\310\\311\\312\\313\\314\\315\\316\\317\\320\\321\\322\\323\\324\\325\\326\\327\\330\\331\\332\\333\\334\\335\\336\\337\\340\\341\\342\\343\\344\\345\\346\\347\\350\\351\\352\\353\\354\\355\\356\\357\\360\\361\\362\\363\\364\\365\\366\\367\\370\\371\\372\\373\\374\\375\\376\\377"),
	TQU("<$&>"),
	TQU("\\000\\001\\002\\003\\004\\005\\006\\007\\010\\011\\012\\013\\014\\015\\016\\017\\020\\021\\022\\023\\024\\025\\026\\027\\030\\031\\032\\033\\034\\035\\036\\037\\040\\041\\042\\043\\044\\045\\046\\047\\050\\051\\052\\053\\054\\055\\056\\057\\060\\061\\062\\063\\064\\065\\066\\067\\070\\071\\072\\073\\074\\075\\076\\077\\100\\101\\102\\103\\104\\105\\106\\107\\110\\111\\112\\113\\114\\115\\116\\117\\120\\121\\122\\123\\124\\125\\126\\127\\130\\131\\132\\133\\134\\135\\136\\137\\140\\141\\142\\143\\144\\145\\146\\147\\150\\151\\152\\153\\154\\155\\156\\157\\160\\161\\162\\163\\164\\165\\166\\167\\170\\171\\172\\173\\174\\175\\176\\177\\200\\201\\202\\203\\204\\205\\206\\207\\210\\211\\212\\213\\214\\215\\216\\217\\220\\221\\222\\223\\224\\225\\226\\227\\230\\231\\232\\233\\234\\235\\236\\237\\240\\241\\242\\243\\244\\245\\246\\247\\250\\251\\252\\253\\254\\255\\256\\257\\260\\261\\262\\263\\264\\265\\266\\267\\270\\271\\272\\273\\274\\275\\276\\277\\300\\301\\302\\303\\304\\305\\306\\307\\310\\311\\312\\313\\314\\315\\316\\317\\320\\321\\322\\323\\324\\325\\326\\327\\330\\331\\332\\333\\334\\335\\336\\337\\340\\341\\342\\343\\344\\345\\346\\347\\350\\351\\352\\353\\354\\355\\356\\357\\360\\361\\362\\363\\364\\365\\366\\367\\370\\371\\372\\373\\374\\375\\376\\377"),
	TQU("g"),

	TQU("P[^*]TAIRE[^*]{1,6}?LL"),
	TQU("<$&>"),
	TQU("xxxxxxxxxxxPSTAIREISLLxxxxxxxxx"),
	TQU("g"),

	TQU("P[^*]TAIRE[^*]{1,}?LL"),
	TQU("<$&>"),
	TQU("xxxxxxxxxxxPSTAIREISLLxxxxxxxxx"),
	TQU("g"),

	TQU("(\\.\\d\\d[1-9]?)\\d+"),
	TQU("<$&>"),
	TQU("1.230003938"),
	TQU("gq"),

	TQU("(\\.\\d\\d[1-9]?)\\d+"),
	TQU("<$&>"),
	TQU("1.875000282"),
	TQU("gq"),

	TQU("(\\.\\d\\d[1-9]?)\\d+"),
	TQU("<$&>"),
	TQU("1.235"),
	TQU("gq"),

	TQU("(\\.\\d\\d((?=0)|\\d(?=\\d)))"),
	TQU("<$&>"),
	TQU("1.230003938"),
	TQU("gq"),

	TQU("(\\.\\d\\d((?=0)|\\d(?=\\d)))"),
	TQU("<$&>"),
	TQU("1.875000282"),
	TQU("gq"),

	TQU("(\\.\\d\\d((?=0)|\\d(?=\\d)))"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(\\.\\d\\d((?=0)|\\d(?=\\d)))"),
	TQU("<$&>"),
	TQU("1.235"),
	TQU("gq"),

	TQU("a(?)b"),
	TQU("<$&>"),
	TQU("ab"),
	TQU("g"),

	TQU("\\b(foo)\\s+(\\w+)"),
	TQU("<$&>"),
	TQU("Food is on the foo table"),
	TQU("ig"),

	TQU("foo(.*)bar"),
	TQU("<$&>"),
	TQU("The food is under the bar in the barn."),
	TQU("g"),

	TQU("foo(.*?)bar"),
	TQU("<$&>"),
	TQU("The food is under the bar in the barn."),
	TQU("g"),

	TQU("(.*)(\\d*)"),
	TQU("<$&>"),
	TQU("I have 2 numbers: 53147"),
	TQU("g"),

	TQU("(.*)(\\d+)"),
	TQU("<$&>"),
	TQU("I have 2 numbers: 53147"),
	TQU("g"),

	TQU("(.*?)(\\d*)"),
	TQU("<$&>"),
	TQU("I have 2 numbers: 53147"),
	TQU("g"),

	TQU("(.*?)(\\d+)"),
	TQU("<$&>"),
	TQU("I have 2 numbers: 53147"),
	TQU("g"),

	TQU("(.*)(\\d+)$"),
	TQU("<$&>"),
	TQU("I have 2 numbers: 53147"),
	TQU("g"),

	TQU("(.*?)(\\d+)$"),
	TQU("<$&>"),
	TQU("I have 2 numbers: 53147"),
	TQU("g"),

	TQU("(.*)\\b(\\d+)$"),
	TQU("<$&>"),
	TQU("I have 2 numbers: 53147"),
	TQU("g"),

	TQU("(.*\\D)(\\d+)$"),
	TQU("<$&>"),
	TQU("I have 2 numbers: 53147"),
	TQU("g"),

	TQU("^\\D*(?!123)"),
	TQU("<$&>"),
	TQU("ABC123"),
	TQU("g"),

	TQU("^(\\D*)(?=\\d)(?!123)"),
	TQU("<$&>"),
	TQU("ABC445"),
	TQU("g"),

	TQU("^(\\D*)(?=\\d)(?!123)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(\\D*)(?=\\d)(?!123)"),
	TQU("<$&>"),
	TQU("ABC123"),
	TQU("g"),

	TQU("^[W-]46]"),
	TQU("<$&>"),
	TQU("W46]789"),
	TQU("g"),

	TQU("^[W-]46]"),
	TQU("<$&>"),
	TQU("-46]789"),
	TQU("g"),

	TQU("^[W-]46]"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^[W-]46]"),
	TQU("<$&>"),
	TQU("Wall"),
	TQU("g"),

	TQU("^[W-]46]"),
	TQU("<$&>"),
	TQU("Zebra"),
	TQU("g"),

	TQU("^[W-]46]"),
	TQU("<$&>"),
	TQU("42"),
	TQU("gq"),

	TQU("^[W-]46]"),
	TQU("<$&>"),
	TQU("[abcd]"),
	TQU("g"),

	TQU("^[W-]46]"),
	TQU("<$&>"),
	TQU("]abcd["),
	TQU("g"),

	TQU("^[W-\\]46]"),
	TQU("<$&>"),
	TQU("W46]789"),
	TQU("g"),

	TQU("^[W-\\]46]"),
	TQU("<$&>"),
	TQU("Wall"),
	TQU("g"),

	TQU("^[W-\\]46]"),
	TQU("<$&>"),
	TQU("Zebra"),
	TQU("g"),

	TQU("^[W-\\]46]"),
	TQU("<$&>"),
	TQU("Xylophone"),
	TQU("g"),

	TQU("^[W-\\]46]"),
	TQU("<$&>"),
	TQU("42"),
	TQU("gq"),

	TQU("^[W-\\]46]"),
	TQU("<$&>"),
	TQU("[abcd]"),
	TQU("g"),

	TQU("^[W-\\]46]"),
	TQU("<$&>"),
	TQU("]abcd["),
	TQU("g"),

	TQU("^[W-\\]46]"),
	TQU("<$&>"),
	TQU("\\\\backslash"),
	TQU("g"),

	TQU("^[W-\\]46]"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^[W-\\]46]"),
	TQU("<$&>"),
	TQU("-46]789"),
	TQU("g"),

	TQU("^[W-\\]46]"),
	TQU("<$&>"),
	TQU("well"),
	TQU("g"),

	TQU("\\d\\d\\/\\d\\d\\/\\d\\d\\d\\d"),
	TQU("<$&>"),
	TQU("01/01/2000"),
	TQU("g"),

	TQU("word (?:[a-zA-Z0-9]+ ){0,10}otherword"),
	TQU("<$&>"),
	TQU("word cat dog elephant mussel cow horse canary baboon snake shark otherword"),
	TQU("g"),

	TQU("word (?:[a-zA-Z0-9]+ ){0,10}otherword"),
	TQU("<$&>"),
	TQU("word cat dog elephant mussel cow horse canary baboon snake shark"),
	TQU("g"),

	TQU("word (?:[a-zA-Z0-9]+ ){0,300}otherword"),
	TQU("<$&>"),
	TQU("word cat dog elephant mussel cow horse canary baboon snake shark the quick brown fox and the lazy dog and several other words getting close to thirty by now I hope"),
	TQU("g"),

	TQU("^(a){0,0}"),
	TQU("<$&>"),
	TQU("bcd"),
	TQU("g"),

	TQU("^(a){0,0}"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("^(a){0,0}"),
	TQU("<$&>"),
	TQU("aab"),
	TQU("g"),

	TQU("^(a){0,1}"),
	TQU("<$&>"),
	TQU("bcd"),
	TQU("g"),

	TQU("^(a){0,1}"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("^(a){0,1}"),
	TQU("<$&>"),
	TQU("aab"),
	TQU("g"),

	TQU("^(a){0,2}"),
	TQU("<$&>"),
	TQU("bcd"),
	TQU("g"),

	TQU("^(a){0,2}"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("^(a){0,2}"),
	TQU("<$&>"),
	TQU("aab"),
	TQU("g"),

	TQU("^(a){0,3}"),
	TQU("<$&>"),
	TQU("bcd"),
	TQU("g"),

	TQU("^(a){0,3}"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("^(a){0,3}"),
	TQU("<$&>"),
	TQU("aab"),
	TQU("g"),

	TQU("^(a){0,3}"),
	TQU("<$&>"),
	TQU("aaa"),
	TQU("g"),

	TQU("^(a){0,}"),
	TQU("<$&>"),
	TQU("bcd"),
	TQU("g"),

	TQU("^(a){0,}"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("^(a){0,}"),
	TQU("<$&>"),
	TQU("aab"),
	TQU("g"),

	TQU("^(a){0,}"),
	TQU("<$&>"),
	TQU("aaa"),
	TQU("g"),

	TQU("^(a){0,}"),
	TQU("<$&>"),
	TQU("aaaaaaaa"),
	TQU("g"),

	TQU("^(a){1,1}"),
	TQU("<$&>"),
	TQU("bcd"),
	TQU("g"),

	TQU("^(a){1,1}"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("^(a){1,1}"),
	TQU("<$&>"),
	TQU("aab"),
	TQU("g"),

	TQU("^(a){1,2}"),
	TQU("<$&>"),
	TQU("bcd"),
	TQU("g"),

	TQU("^(a){1,2}"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("^(a){1,2}"),
	TQU("<$&>"),
	TQU("aab"),
	TQU("g"),

	TQU("^(a){1,3}"),
	TQU("<$&>"),
	TQU("bcd"),
	TQU("g"),

	TQU("^(a){1,3}"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("^(a){1,3}"),
	TQU("<$&>"),
	TQU("aab"),
	TQU("g"),

	TQU("^(a){1,3}"),
	TQU("<$&>"),
	TQU("aaa"),
	TQU("g"),

	TQU("^(a){1,}"),
	TQU("<$&>"),
	TQU("bcd"),
	TQU("g"),

	TQU("^(a){1,}"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("^(a){1,}"),
	TQU("<$&>"),
	TQU("aab"),
	TQU("g"),

	TQU("^(a){1,}"),
	TQU("<$&>"),
	TQU("aaa"),
	TQU("g"),

	TQU("^(a){1,}"),
	TQU("<$&>"),
	TQU("aaaaaaaa"),
	TQU("g"),

	TQU(".*\\.gif"),
	TQU("<$&>"),
	TQU("borfle\\nbib.gif\\nno"),
	TQU("g"),

	TQU(".{0,}\\.gif"),
	TQU("<$&>"),
	TQU("borfle\\nbib.gif\\nno"),
	TQU("g"),

	TQU(".*\\.gif"),
	TQU("<$&>"),
	TQU("borfle\\nbib.gif\\nno"),
	TQU("mg"),

	TQU(".*\\.gif"),
	TQU("<$&>"),
	TQU("borfle\\nbib.gif\\nno"),
	TQU("sg"),

	TQU(".*\\.gif"),
	TQU("<$&>"),
	TQU("borfle\\nbib.gif\\nno"),
	TQU("msg"),

	TQU(".*$"),
	TQU("<$&>"),
	TQU("borfle\\nbib.gif\\nno"),
	TQU("g"),

	TQU(".*$"),
	TQU("<$&>"),
	TQU("borfle\\nbib.gif\\nno"),
	TQU("mg"),

	TQU(".*$"),
	TQU("<$&>"),
	TQU("borfle\\nbib.gif\\nno"),
	TQU("sg"),

	TQU(".*$"),
	TQU("<$&>"),
	TQU("borfle\\nbib.gif\\nno"),
	TQU("msg"),

	TQU(".*$"),
	TQU("<$&>"),
	TQU("borfle\\nbib.gif\\nno\\n"),
	TQU("g"),

	TQU(".*$"),
	TQU("<$&>"),
	TQU("borfle\\nbib.gif\\nno\\n"),
	TQU("mg"),

	TQU(".*$"),
	TQU("<$&>"),
	TQU("borfle\\nbib.gif\\nno\\n"),
	TQU("sg"),

	TQU(".*$"),
	TQU("<$&>"),
	TQU("borfle\\nbib.gif\\nno\\n"),
	TQU("msg"),

	TQU("(.*X|^B)"),
	TQU("<$&>"),
	TQU("abcde\\n1234Xyz"),
	TQU("g"),

	TQU("(.*X|^B)"),
	TQU("<$&>"),
	TQU("BarFoo"),
	TQU("g"),

	TQU("(.*X|^B)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(.*X|^B)"),
	TQU("<$&>"),
	TQU("abcde\\nBar"),
	TQU("g"),

	TQU("(.*X|^B)"),
	TQU("<$&>"),
	TQU("abcde\\n1234Xyz"),
	TQU("mg"),

	TQU("(.*X|^B)"),
	TQU("<$&>"),
	TQU("BarFoo"),
	TQU("mg"),

	TQU("(.*X|^B)"),
	TQU("<$&>"),
	TQU("abcde\\nBar"),
	TQU("mg"),

	TQU("(.*X|^B)"),
	TQU("<$&>"),
	TQU("abcde\\n1234Xyz"),
	TQU("sg"),

	TQU("(.*X|^B)"),
	TQU("<$&>"),
	TQU("BarFoo"),
	TQU("sg"),

	TQU("(.*X|^B)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("sg"),

	TQU("(.*X|^B)"),
	TQU("<$&>"),
	TQU("abcde\\nBar"),
	TQU("sg"),

	TQU("(.*X|^B)"),
	TQU("<$&>"),
	TQU("abcde\\n1234Xyz"),
	TQU("msg"),

	TQU("(.*X|^B)"),
	TQU("<$&>"),
	TQU("BarFoo"),
	TQU("msg"),

	TQU("(.*X|^B)"),
	TQU("<$&>"),
	TQU("abcde\\nBar"),
	TQU("msg"),

	TQU("(?s)(.*X|^B)"),
	TQU("<$&>"),
	TQU("abcde\\n1234Xyz"),
	TQU("g"),

	TQU("(?s)(.*X|^B)"),
	TQU("<$&>"),
	TQU("BarFoo"),
	TQU("g"),

	TQU("(?s)(.*X|^B)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?s)(.*X|^B)"),
	TQU("<$&>"),
	TQU("abcde\\nBar"),
	TQU("g"),

	TQU("(?s:.*X|^B)"),
	TQU("<$&>"),
	TQU("abcde\\n1234Xyz"),
	TQU("g"),

	TQU("(?s:.*X|^B)"),
	TQU("<$&>"),
	TQU("BarFoo"),
	TQU("g"),

	TQU("(?s:.*X|^B)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?s:.*X|^B)"),
	TQU("<$&>"),
	TQU("abcde\\nBar"),
	TQU("g"),

	TQU("^.*B"),
	TQU("<$&>"),
	TQU("**** Failers"),
	TQU("g"),

	TQU("^.*B"),
	TQU("<$&>"),
	TQU("abc\\nB"),
	TQU("g"),

	TQU("(?s)^.*B"),
	TQU("<$&>"),
	TQU("abc\\nB"),
	TQU("g"),

	TQU("(?m)^.*B"),
	TQU("<$&>"),
	TQU("abc\\nB"),
	TQU("g"),

	TQU("(?ms)^.*B"),
	TQU("<$&>"),
	TQU("abc\\nB"),
	TQU("g"),

	TQU("(?ms)^B"),
	TQU("<$&>"),
	TQU("abc\\nB"),
	TQU("g"),

	TQU("(?s)B$"),
	TQU("<$&>"),
	TQU("B\\n"),
	TQU("g"),

	TQU("^[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]"),
	TQU("<$&>"),
	TQU("123456654321"),
	TQU("gq"),

	TQU("^\\d\\d\\d\\d\\d\\d\\d\\d\\d\\d\\d\\d"),
	TQU("<$&>"),
	TQU("123456654321"),
	TQU("gq"),

	TQU("^[\\d][\\d][\\d][\\d][\\d][\\d][\\d][\\d][\\d][\\d][\\d][\\d]"),
	TQU("<$&>"),
	TQU("123456654321"),
	TQU("gq"),

	TQU("^[abc]{12}"),
	TQU("<$&>"),
	TQU("abcabcabcabc"),
	TQU("g"),

	TQU("^[a-c]{12}"),
	TQU("<$&>"),
	TQU("abcabcabcabc"),
	TQU("g"),

	TQU("^(a|b|c){12}"),
	TQU("<$&>"),
	TQU("abcabcabcabc"),
	TQU("g"),

	TQU("^[abcdefghijklmnopqrstuvwxy0123456789]"),
	TQU("<$&>"),
	TQU("n"),
	TQU("g"),

	TQU("^[abcdefghijklmnopqrstuvwxy0123456789]"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^[abcdefghijklmnopqrstuvwxy0123456789]"),
	TQU("<$&>"),
	TQU("z"),
	TQU("g"),

	TQU("abcde{0,0}"),
	TQU("<$&>"),
	TQU("abcd"),
	TQU("g"),

	TQU("abcde{0,0}"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("abcde{0,0}"),
	TQU("<$&>"),
	TQU("abce"),
	TQU("g"),

	TQU("ab[cd]{0,0}e"),
	TQU("<$&>"),
	TQU("abe"),
	TQU("g"),

	TQU("ab[cd]{0,0}e"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("ab[cd]{0,0}e"),
	TQU("<$&>"),
	TQU("abcde"),
	TQU("g"),

	TQU("ab(c){0,0}d"),
	TQU("<$&>"),
	TQU("abd"),
	TQU("g"),

	TQU("ab(c){0,0}d"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("ab(c){0,0}d"),
	TQU("<$&>"),
	TQU("abcd"),
	TQU("g"),

	TQU("a(b*)"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("a(b*)"),
	TQU("<$&>"),
	TQU("ab"),
	TQU("g"),

	TQU("a(b*)"),
	TQU("<$&>"),
	TQU("abbbb"),
	TQU("g"),

	TQU("a(b*)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("a(b*)"),
	TQU("<$&>"),
	TQU("bbbbb"),
	TQU("g"),

	TQU("ab\\d{0}e"),
	TQU("<$&>"),
	TQU("abe"),
	TQU("g"),

	TQU("ab\\d{0}e"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("ab\\d{0}e"),
	TQU("<$&>"),
	TQU("ab1e"),
	TQU("g"),

	TQU("([^\\\\]+|\\\\.)*"),
	TQU("<$&>"),
	TQU("the \\quick\\ brown fox"),
	TQU("g"),

	TQU("([^\\\\]+|\\\\.)*"),
	TQU("<$&>"),
	TQU("\\the \\\\\\quick\\\\\\ brown fox\\"),
	TQU("g"),

	TQU(".*?"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g+g"),

	TQU("\\b"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g+g"),

	TQU("\\b"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("gg"),

	TQU("<tr([\\w\\W\\s\\d][^<>]{0,})><TD([\\w\\W\\s\\d][^<>]{0,})>([\\d]{0,}\\.)(.*)((<BR>([\\w\\W\\s\\d][^<>]{0,})|[\\s]{0,}))<\\/a><\\/TD><TD([\\w\\W\\s\\d][^<>]{0,})>([\\w\\W\\s\\d][^<>]{0,})<\\/TD><TD([\\w\\W\\s\\d][^<>]{0,})>([\\w\\W\\s\\d][^<>]{0,})<\\/TD><\\/TR>"),
	TQU("<$&>"),
	TQU("<TR BGCOLOR='#DBE9E9'><TD align=left valign=top>43.<a href='joblist.cfm?JobID=94 6735&Keyword='>Word Processor<BR>(N-1286)</a></TD><TD align=left valign=top>Lega lstaff.com</TD><TD align=left valign=top>CA - Statewide</TD></TR>"),
	TQU("isg"),

	TQU("a[^a]b"),
	TQU("<$&>"),
	TQU("acb"),
	TQU("g"),

	TQU("a[^a]b"),
	TQU("<$&>"),
	TQU("a\\nb"),
	TQU("g"),

	TQU("a.b"),
	TQU("<$&>"),
	TQU("acb"),
	TQU("g"),

	TQU("a.b"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("a.b"),
	TQU("<$&>"),
	TQU("a\\nb"),
	TQU("g"),

	TQU("a[^a]b"),
	TQU("<$&>"),
	TQU("acb"),
	TQU("sg"),

	TQU("a[^a]b"),
	TQU("<$&>"),
	TQU("a\\nb"),
	TQU("sg"),

	TQU("a.b"),
	TQU("<$&>"),
	TQU("acb"),
	TQU("sg"),

	TQU("a.b"),
	TQU("<$&>"),
	TQU("a\\nb"),
	TQU("sg"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bac"),
	TQU("g"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bbac"),
	TQU("g"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bbbac"),
	TQU("g"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bbbbac"),
	TQU("g"),

	TQU("^(b+?|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bbbbbac"),
	TQU("g"),

	TQU("^(b+|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bac"),
	TQU("g"),

	TQU("^(b+|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bbac"),
	TQU("g"),

	TQU("^(b+|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bbbac"),
	TQU("g"),

	TQU("^(b+|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bbbbac"),
	TQU("g"),

	TQU("^(b+|a){1,2}?c"),
	TQU("<$&>"),
	TQU("bbbbbac"),
	TQU("g"),

	TQU("(?!\\A)x"),
	TQU("<$&>"),
	TQU("x\\nb\\n"),
	TQU("mg"),

	TQU("(?!\\A)x"),
	TQU("<$&>"),
	TQU("a\\bx\\n"),
	TQU("mg"),

	TQU("\\x0{ab}"),
	TQU("<$&>"),
	TQU("\\0{ab}"),
	TQU("g"),

	TQU("(A|B)*?CD"),
	TQU("<$&>"),
	TQU("CD"),
	TQU("g"),

	TQU("(A|B)*CD"),
	TQU("<$&>"),
	TQU("CD"),
	TQU("g"),

	TQU("(AB)*?\\1"),
	TQU("<$&>"),
	TQU("ABABAB"),
	TQU("g"),

	TQU("(AB)*\\1"),
	TQU("<$&>"),
	TQU("ABABAB"),
	TQU("g"),

	TQU("(?<!bar)foo"),
	TQU("<$&>"),
	TQU("foo"),
	TQU("g"),

	TQU("(?<!bar)foo"),
	TQU("<$&>"),
	TQU("catfood"),
	TQU("g"),

	TQU("(?<!bar)foo"),
	TQU("<$&>"),
	TQU("arfootle"),
	TQU("g"),

	TQU("(?<!bar)foo"),
	TQU("<$&>"),
	TQU("rfoosh"),
	TQU("g"),

	TQU("(?<!bar)foo"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?<!bar)foo"),
	TQU("<$&>"),
	TQU("barfoo"),
	TQU("g"),

	TQU("(?<!bar)foo"),
	TQU("<$&>"),
	TQU("towbarfoo"),
	TQU("g"),

	TQU("\\w{3}(?<!bar)foo"),
	TQU("<$&>"),
	TQU("catfood"),
	TQU("g"),

	TQU("\\w{3}(?<!bar)foo"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("\\w{3}(?<!bar)foo"),
	TQU("<$&>"),
	TQU("foo"),
	TQU("g"),

	TQU("\\w{3}(?<!bar)foo"),
	TQU("<$&>"),
	TQU("barfoo"),
	TQU("g"),

	TQU("\\w{3}(?<!bar)foo"),
	TQU("<$&>"),
	TQU("towbarfoo"),
	TQU("g"),

	TQU("(?<=(foo)a)bar"),
	TQU("<$&>"),
	TQU("fooabar"),
	TQU("g"),

	TQU("(?<=(foo)a)bar"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?<=(foo)a)bar"),
	TQU("<$&>"),
	TQU("bar"),
	TQU("g"),

	TQU("(?<=(foo)a)bar"),
	TQU("<$&>"),
	TQU("foobbar"),
	TQU("g"),

	TQU("\\Aabc\\z"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("mg"),

	TQU("\\Aabc\\z"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("mg"),

	TQU("\\Aabc\\z"),
	TQU("<$&>"),
	TQU("abc\\n"),
	TQU("mg"),

	TQU("\\Aabc\\z"),
	TQU("<$&>"),
	TQU("qqq\\nabc"),
	TQU("mg"),

	TQU("\\Aabc\\z"),
	TQU("<$&>"),
	TQU("abc\\nzzz"),
	TQU("mg"),

	TQU("\\Aabc\\z"),
	TQU("<$&>"),
	TQU("qqq\\nabc\\nzzz"),
	TQU("mg"),

	TQU("(?>.*/)foo"),
	TQU("<$&>"),
	TQU("/this/is/a/very/long/line/in/deed/with/very/many/slashes/in/it/you/see/"),
	TQU("g"),

	TQU("(?>.*/)foo"),
	TQU("<$&>"),
	TQU("/this/is/a/very/long/line/in/deed/with/very/many/slashes/in/and/foo"),
	TQU("g"),

	TQU("(?>(\\.\\d\\d[1-9]?))\\d+"),
	TQU("<$&>"),
	TQU("1.230003938"),
	TQU("gq"),

	TQU("(?>(\\.\\d\\d[1-9]?))\\d+"),
	TQU("<$&>"),
	TQU("1.875000282"),
	TQU("gq"),

	TQU("(?>(\\.\\d\\d[1-9]?))\\d+"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?>(\\.\\d\\d[1-9]?))\\d+"),
	TQU("<$&>"),
	TQU("1.235"),
	TQU("gq"),

	TQU("^((?>\\w+)|(?>\\s+))*$"),
	TQU("<$&>"),
	TQU("now is the time for all good men to come to the aid of the party"),
	TQU("g"),

	TQU("^((?>\\w+)|(?>\\s+))*$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^((?>\\w+)|(?>\\s+))*$"),
	TQU("<$&>"),
	TQU("this is not a line with only words and spaces!"),
	TQU("g"),

	TQU("(\\d+)(\\w)"),
	TQU("<$&>"),
	TQU("12345a"),
	TQU("g"),

	TQU("(\\d+)(\\w)"),
	TQU("<$&>"),
	TQU("12345+"),
	TQU("g"),

	TQU("((?>\\d+))(\\w)"),
	TQU("<$&>"),
	TQU("12345a"),
	TQU("g"),

	TQU("((?>\\d+))(\\w)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("((?>\\d+))(\\w)"),
	TQU("<$&>"),
	TQU("12345+"),
	TQU("g"),

	TQU("(?>a+)b"),
	TQU("<$&>"),
	TQU("aaab"),
	TQU("g"),

	TQU("((?>a+)b)"),
	TQU("<$&>"),
	TQU("aaab"),
	TQU("g"),

	TQU("(?>(a+))b"),
	TQU("<$&>"),
	TQU("aaab"),
	TQU("g"),

	TQU("(?>b)+"),
	TQU("<$&>"),
	TQU("aaabbbccc"),
	TQU("g"),

	TQU("(?>a+|b+|c+)*c"),
	TQU("<$&>"),
	TQU("aaabbbbccccd"),
	TQU("g"),

	TQU("((?>[^()]+)|\\([^()]*\\))+"),
	TQU("<$&>"),
	TQU("((abc(ade)ufh()()x"),
	TQU("g"),

	TQU("\\(((?>[^()]+)|\\([^()]+\\))+\\)"),
	TQU("<$&>"),
	TQU("(abc)"),
	TQU("g"),

	TQU("\\(((?>[^()]+)|\\([^()]+\\))+\\)"),
	TQU("<$&>"),
	TQU("(abc(def)xyz)"),
	TQU("g"),

	TQU("\\(((?>[^()]+)|\\([^()]+\\))+\\)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("\\(((?>[^()]+)|\\([^()]+\\))+\\)"),
	TQU("<$&>"),
	TQU("((()aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"),
	TQU("g"),

	TQU("a(?-i)b"),
	TQU("<$&>"),
	TQU("ab"),
	TQU("ig"),

	TQU("a(?-i)b"),
	TQU("<$&>"),
	TQU("Ab"),
	TQU("ig"),

	TQU("a(?-i)b"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("ig"),

	TQU("a(?-i)b"),
	TQU("<$&>"),
	TQU("aB"),
	TQU("ig"),

	TQU("a(?-i)b"),
	TQU("<$&>"),
	TQU("AB"),
	TQU("ig"),

	TQU("(a (?x)b c)d e"),
	TQU("<$&>"),
	TQU("a bcd e"),
	TQU("g"),

	TQU("(a (?x)b c)d e"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(a (?x)b c)d e"),
	TQU("<$&>"),
	TQU("a b cd e"),
	TQU("g"),

	TQU("(a (?x)b c)d e"),
	TQU("<$&>"),
	TQU("abcd e"),
	TQU("g"),

	TQU("(a (?x)b c)d e"),
	TQU("<$&>"),
	TQU("a bcde"),
	TQU("g"),

	TQU("(a b(?x)c d (?-x)e f)"),
	TQU("<$&>"),
	TQU("a bcde f"),
	TQU("g"),

	TQU("(a b(?x)c d (?-x)e f)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(a b(?x)c d (?-x)e f)"),
	TQU("<$&>"),
	TQU("abcdef"),
	TQU("g"),

	TQU("(a(?i)b)c"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("(a(?i)b)c"),
	TQU("<$&>"),
	TQU("aBc"),
	TQU("g"),

	TQU("(a(?i)b)c"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(a(?i)b)c"),
	TQU("<$&>"),
	TQU("abC"),
	TQU("g"),

	TQU("(a(?i)b)c"),
	TQU("<$&>"),
	TQU("aBC"),
	TQU("g"),

	TQU("(a(?i)b)c"),
	TQU("<$&>"),
	TQU("Abc"),
	TQU("g"),

	TQU("(a(?i)b)c"),
	TQU("<$&>"),
	TQU("ABc"),
	TQU("g"),

	TQU("(a(?i)b)c"),
	TQU("<$&>"),
	TQU("ABC"),
	TQU("g"),

	TQU("(a(?i)b)c"),
	TQU("<$&>"),
	TQU("AbC"),
	TQU("g"),

	TQU("a(?i:b)c"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("a(?i:b)c"),
	TQU("<$&>"),
	TQU("aBc"),
	TQU("g"),

	TQU("a(?i:b)c"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("a(?i:b)c"),
	TQU("<$&>"),
	TQU("ABC"),
	TQU("g"),

	TQU("a(?i:b)c"),
	TQU("<$&>"),
	TQU("abC"),
	TQU("g"),

	TQU("a(?i:b)c"),
	TQU("<$&>"),
	TQU("aBC"),
	TQU("g"),

	TQU("a(?i:b)*c"),
	TQU("<$&>"),
	TQU("aBc"),
	TQU("g"),

	TQU("a(?i:b)*c"),
	TQU("<$&>"),
	TQU("aBBc"),
	TQU("g"),

	TQU("a(?i:b)*c"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("a(?i:b)*c"),
	TQU("<$&>"),
	TQU("aBC"),
	TQU("g"),

	TQU("a(?i:b)*c"),
	TQU("<$&>"),
	TQU("aBBC"),
	TQU("g"),

	TQU("a(?=b(?i)c)\\w\\wd"),
	TQU("<$&>"),
	TQU("abcd"),
	TQU("g"),

	TQU("a(?=b(?i)c)\\w\\wd"),
	TQU("<$&>"),
	TQU("abCd"),
	TQU("g"),

	TQU("a(?=b(?i)c)\\w\\wd"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("a(?=b(?i)c)\\w\\wd"),
	TQU("<$&>"),
	TQU("aBCd"),
	TQU("g"),

	TQU("a(?=b(?i)c)\\w\\wd"),
	TQU("<$&>"),
	TQU("abcD"),
	TQU("g"),

	TQU("(?s-i:more.*than).*million"),
	TQU("<$&>"),
	TQU("more than million"),
	TQU("ig"),

	TQU("(?s-i:more.*than).*million"),
	TQU("<$&>"),
	TQU("more than MILLION"),
	TQU("ig"),

	TQU("(?s-i:more.*than).*million"),
	TQU("<$&>"),
	TQU("more \\n than Million"),
	TQU("ig"),

	TQU("(?s-i:more.*than).*million"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("ig"),

	TQU("(?s-i:more.*than).*million"),
	TQU("<$&>"),
	TQU("MORE THAN MILLION"),
	TQU("ig"),

	TQU("(?s-i:more.*than).*million"),
	TQU("<$&>"),
	TQU("more \\n than \\n million"),
	TQU("ig"),

	TQU("(?:(?s-i)more.*than).*million"),
	TQU("<$&>"),
	TQU("more than million"),
	TQU("ig"),

	TQU("(?:(?s-i)more.*than).*million"),
	TQU("<$&>"),
	TQU("more than MILLION"),
	TQU("ig"),

	TQU("(?:(?s-i)more.*than).*million"),
	TQU("<$&>"),
	TQU("more \\n than Million"),
	TQU("ig"),

	TQU("(?:(?s-i)more.*than).*million"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("ig"),

	TQU("(?:(?s-i)more.*than).*million"),
	TQU("<$&>"),
	TQU("MORE THAN MILLION"),
	TQU("ig"),

	TQU("(?:(?s-i)more.*than).*million"),
	TQU("<$&>"),
	TQU("more \\n than \\n million"),
	TQU("ig"),

	TQU("(?>a(?i)b+)+c"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("(?>a(?i)b+)+c"),
	TQU("<$&>"),
	TQU("aBbc"),
	TQU("g"),

	TQU("(?>a(?i)b+)+c"),
	TQU("<$&>"),
	TQU("aBBc"),
	TQU("g"),

	TQU("(?>a(?i)b+)+c"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?>a(?i)b+)+c"),
	TQU("<$&>"),
	TQU("Abc"),
	TQU("g"),

	TQU("(?>a(?i)b+)+c"),
	TQU("<$&>"),
	TQU("abAb"),
	TQU("g"),

	TQU("(?>a(?i)b+)+c"),
	TQU("<$&>"),
	TQU("abbC"),
	TQU("g"),

	TQU("(?=a(?i)b)\\w\\wc"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("(?=a(?i)b)\\w\\wc"),
	TQU("<$&>"),
	TQU("aBc"),
	TQU("g"),

	TQU("(?=a(?i)b)\\w\\wc"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?=a(?i)b)\\w\\wc"),
	TQU("<$&>"),
	TQU("Ab"),
	TQU("g"),

	TQU("(?=a(?i)b)\\w\\wc"),
	TQU("<$&>"),
	TQU("abC"),
	TQU("g"),

	TQU("(?=a(?i)b)\\w\\wc"),
	TQU("<$&>"),
	TQU("aBC"),
	TQU("g"),

	TQU("(?<=a(?i)b)(\\w\\w)c"),
	TQU("<$&>"),
	TQU("abxxc"),
	TQU("g"),

	TQU("(?<=a(?i)b)(\\w\\w)c"),
	TQU("<$&>"),
	TQU("aBxxc"),
	TQU("g"),

	TQU("(?<=a(?i)b)(\\w\\w)c"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?<=a(?i)b)(\\w\\w)c"),
	TQU("<$&>"),
	TQU("Abxxc"),
	TQU("g"),

	TQU("(?<=a(?i)b)(\\w\\w)c"),
	TQU("<$&>"),
	TQU("ABxxc"),
	TQU("g"),

	TQU("(?<=a(?i)b)(\\w\\w)c"),
	TQU("<$&>"),
	TQU("abxxC"),
	TQU("g"),

	TQU("(?:(a)|b)(?(1)A|B)"),
	TQU("<$&>"),
	TQU("aA"),
	TQU("g"),

	TQU("(?:(a)|b)(?(1)A|B)"),
	TQU("<$&>"),
	TQU("bB"),
	TQU("g"),

	TQU("(?:(a)|b)(?(1)A|B)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?:(a)|b)(?(1)A|B)"),
	TQU("<$&>"),
	TQU("aB"),
	TQU("g"),

	TQU("(?:(a)|b)(?(1)A|B)"),
	TQU("<$&>"),
	TQU("bA"),
	TQU("g"),

	TQU("^(a)?(?(1)a|b)+$"),
	TQU("<$&>"),
	TQU("aa"),
	TQU("g"),

	TQU("^(a)?(?(1)a|b)+$"),
	TQU("<$&>"),
	TQU("b"),
	TQU("g"),

	TQU("^(a)?(?(1)a|b)+$"),
	TQU("<$&>"),
	TQU("bb"),
	TQU("g"),

	TQU("^(a)?(?(1)a|b)+$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(a)?(?(1)a|b)+$"),
	TQU("<$&>"),
	TQU("ab"),
	TQU("g"),

	TQU("^(?(?=abc)\\w{3}:|\\d\\d)$"),
	TQU("<$&>"),
	TQU("abc:"),
	TQU("g"),

	TQU("^(?(?=abc)\\w{3}:|\\d\\d)$"),
	TQU("<$&>"),
	TQU("12"),
	TQU("gq"),

	TQU("^(?(?=abc)\\w{3}:|\\d\\d)$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(?(?=abc)\\w{3}:|\\d\\d)$"),
	TQU("<$&>"),
	TQU("123"),
	TQU("gq"),

	TQU("^(?(?=abc)\\w{3}:|\\d\\d)$"),
	TQU("<$&>"),
	TQU("xyz"),
	TQU("g"),

	TQU("^(?(?!abc)\\d\\d|\\w{3}:)$"),
	TQU("<$&>"),
	TQU("abc:"),
	TQU("g"),

	TQU("^(?(?!abc)\\d\\d|\\w{3}:)$"),
	TQU("<$&>"),
	TQU("12"),
	TQU("gq"),

	TQU("^(?(?!abc)\\d\\d|\\w{3}:)$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(?(?!abc)\\d\\d|\\w{3}:)$"),
	TQU("<$&>"),
	TQU("123"),
	TQU("gq"),

	TQU("^(?(?!abc)\\d\\d|\\w{3}:)$"),
	TQU("<$&>"),
	TQU("xyz"),
	TQU("g"),

	TQU("(?(?<=foo)bar|cat)"),
	TQU("<$&>"),
	TQU("foobar"),
	TQU("g"),

	TQU("(?(?<=foo)bar|cat)"),
	TQU("<$&>"),
	TQU("cat"),
	TQU("g"),

	TQU("(?(?<=foo)bar|cat)"),
	TQU("<$&>"),
	TQU("fcat"),
	TQU("g"),

	TQU("(?(?<=foo)bar|cat)"),
	TQU("<$&>"),
	TQU("focat"),
	TQU("g"),

	TQU("(?(?<=foo)bar|cat)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?(?<=foo)bar|cat)"),
	TQU("<$&>"),
	TQU("foocat"),
	TQU("g"),

	TQU("(?(?<!foo)cat|bar)"),
	TQU("<$&>"),
	TQU("foobar"),
	TQU("g"),

	TQU("(?(?<!foo)cat|bar)"),
	TQU("<$&>"),
	TQU("cat"),
	TQU("g"),

	TQU("(?(?<!foo)cat|bar)"),
	TQU("<$&>"),
	TQU("fcat"),
	TQU("g"),

	TQU("(?(?<!foo)cat|bar)"),
	TQU("<$&>"),
	TQU("focat"),
	TQU("g"),

	TQU("(?(?<!foo)cat|bar)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?(?<!foo)cat|bar)"),
	TQU("<$&>"),
	TQU("foocat"),
	TQU("g"),

	TQU("( \\( )? [^()]+ (?(1) \\) |) "),
	TQU("<$&>"),
	TQU("abcd"),
	TQU("xg"),

	TQU("( \\( )? [^()]+ (?(1) \\) |) "),
	TQU("<$&>"),
	TQU("(abcd)"),
	TQU("xg"),

	TQU("( \\( )? [^()]+ (?(1) \\) |) "),
	TQU("<$&>"),
	TQU("the quick (abcd) fox"),
	TQU("xg"),

	TQU("( \\( )? [^()]+ (?(1) \\) |) "),
	TQU("<$&>"),
	TQU("(abcd"),
	TQU("xg"),

	TQU("( \\( )? [^()]+ (?(1) \\) ) "),
	TQU("<$&>"),
	TQU("abcd"),
	TQU("xg"),

	TQU("( \\( )? [^()]+ (?(1) \\) ) "),
	TQU("<$&>"),
	TQU("(abcd)"),
	TQU("xg"),

	TQU("( \\( )? [^()]+ (?(1) \\) ) "),
	TQU("<$&>"),
	TQU("the quick (abcd) fox"),
	TQU("xg"),

	TQU("( \\( )? [^()]+ (?(1) \\) ) "),
	TQU("<$&>"),
	TQU("(abcd"),
	TQU("xg"),

	TQU("^(?(2)a|(1)(2))+$"),
	TQU("<$&>"),
	TQU("12"),
	TQU("gq"),

	TQU("^(?(2)a|(1)(2))+$"),
	TQU("<$&>"),
	TQU("12a"),
	TQU("g"),

	TQU("^(?(2)a|(1)(2))+$"),
	TQU("<$&>"),
	TQU("12aa"),
	TQU("g"),

	TQU("^(?(2)a|(1)(2))+$"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(?(2)a|(1)(2))+$"),
	TQU("<$&>"),
	TQU("1234"),
	TQU("gq"),

	TQU("((?i)blah)\\s+\\1"),
	TQU("<$&>"),
	TQU("blah blah"),
	TQU("g"),

	TQU("((?i)blah)\\s+\\1"),
	TQU("<$&>"),
	TQU("BLAH BLAH"),
	TQU("g"),

	TQU("((?i)blah)\\s+\\1"),
	TQU("<$&>"),
	TQU("Blah Blah"),
	TQU("g"),

	TQU("((?i)blah)\\s+\\1"),
	TQU("<$&>"),
	TQU("blaH blaH"),
	TQU("g"),

	TQU("((?i)blah)\\s+\\1"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("((?i)blah)\\s+\\1"),
	TQU("<$&>"),
	TQU("blah BLAH"),
	TQU("g"),

	TQU("((?i)blah)\\s+\\1"),
	TQU("<$&>"),
	TQU("Blah blah"),
	TQU("g"),

	TQU("((?i)blah)\\s+\\1"),
	TQU("<$&>"),
	TQU("blaH blah"),
	TQU("g"),

	TQU("((?i)blah)\\s+(?i:\\1)"),
	TQU("<$&>"),
	TQU("blah blah"),
	TQU("g"),

	TQU("((?i)blah)\\s+(?i:\\1)"),
	TQU("<$&>"),
	TQU("BLAH BLAH"),
	TQU("g"),

	TQU("((?i)blah)\\s+(?i:\\1)"),
	TQU("<$&>"),
	TQU("Blah Blah"),
	TQU("g"),

	TQU("((?i)blah)\\s+(?i:\\1)"),
	TQU("<$&>"),
	TQU("blaH blaH"),
	TQU("g"),

	TQU("((?i)blah)\\s+(?i:\\1)"),
	TQU("<$&>"),
	TQU("blah BLAH"),
	TQU("g"),

	TQU("((?i)blah)\\s+(?i:\\1)"),
	TQU("<$&>"),
	TQU("Blah blah"),
	TQU("g"),

	TQU("((?i)blah)\\s+(?i:\\1)"),
	TQU("<$&>"),
	TQU("blaH blah"),
	TQU("g"),

	TQU("(?>a*)*"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("(?>a*)*"),
	TQU("<$&>"),
	TQU("aa"),
	TQU("g"),

	TQU("(?>a*)*"),
	TQU("<$&>"),
	TQU("aaaa"),
	TQU("g"),

	TQU("(abc|)+"),
	TQU("<$&>"),
	TQU("abc"),
	TQU("g"),

	TQU("(abc|)+"),
	TQU("<$&>"),
	TQU("abcabc"),
	TQU("g"),

	TQU("(abc|)+"),
	TQU("<$&>"),
	TQU("abcabcabc"),
	TQU("g"),

	TQU("(abc|)+"),
	TQU("<$&>"),
	TQU("xyz"),
	TQU("g"),

	TQU("([a]*)*"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("([a]*)*"),
	TQU("<$&>"),
	TQU("aaaaa"),
	TQU("g"),

	TQU("([ab]*)*"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("([ab]*)*"),
	TQU("<$&>"),
	TQU("b"),
	TQU("g"),

	TQU("([ab]*)*"),
	TQU("<$&>"),
	TQU("ababab"),
	TQU("g"),

	TQU("([ab]*)*"),
	TQU("<$&>"),
	TQU("aaaabcde"),
	TQU("g"),

	TQU("([ab]*)*"),
	TQU("<$&>"),
	TQU("bbbb"),
	TQU("g"),

	TQU("([^a]*)*"),
	TQU("<$&>"),
	TQU("b"),
	TQU("g"),

	TQU("([^a]*)*"),
	TQU("<$&>"),
	TQU("bbbb"),
	TQU("g"),

	TQU("([^a]*)*"),
	TQU("<$&>"),
	TQU("aaa"),
	TQU("g"),

	TQU("([^ab]*)*"),
	TQU("<$&>"),
	TQU("cccc"),
	TQU("g"),

	TQU("([^ab]*)*"),
	TQU("<$&>"),
	TQU("abab"),
	TQU("g"),

	TQU("([a]*?)*"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("([a]*?)*"),
	TQU("<$&>"),
	TQU("aaaa"),
	TQU("g"),

	TQU("([ab]*?)*"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("([ab]*?)*"),
	TQU("<$&>"),
	TQU("b"),
	TQU("g"),

	TQU("([ab]*?)*"),
	TQU("<$&>"),
	TQU("abab"),
	TQU("g"),

	TQU("([ab]*?)*"),
	TQU("<$&>"),
	TQU("baba"),
	TQU("g"),

	TQU("([^a]*?)*"),
	TQU("<$&>"),
	TQU("b"),
	TQU("g"),

	TQU("([^a]*?)*"),
	TQU("<$&>"),
	TQU("bbbb"),
	TQU("g"),

	TQU("([^a]*?)*"),
	TQU("<$&>"),
	TQU("aaa"),
	TQU("g"),

	TQU("([^ab]*?)*"),
	TQU("<$&>"),
	TQU("c"),
	TQU("g"),

	TQU("([^ab]*?)*"),
	TQU("<$&>"),
	TQU("cccc"),
	TQU("g"),

	TQU("([^ab]*?)*"),
	TQU("<$&>"),
	TQU("baba"),
	TQU("g"),

	TQU("(?>a*)*"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("(?>a*)*"),
	TQU("<$&>"),
	TQU("aaabcde"),
	TQU("g"),

	TQU("((?>a*))*"),
	TQU("<$&>"),
	TQU("aaaaa"),
	TQU("g"),

	TQU("((?>a*))*"),
	TQU("<$&>"),
	TQU("aabbaa"),
	TQU("g"),

	TQU("((?>a*?))*"),
	TQU("<$&>"),
	TQU("aaaaa"),
	TQU("g"),

	TQU("((?>a*?))*"),
	TQU("<$&>"),
	TQU("aabbaa"),
	TQU("g"),

	TQU("(?(?=[^a-z]+[a-z])  \\d{2}-[a-z]{3}-\\d{2}  |  \\d{2}-\\d{2}-\\d{2} ) "),
	TQU("<$&>"),
	TQU("1998/9/12"),
	TQU("xgq"),

	TQU("(?(?=[^a-z]+[a-z])  \\d{2}-[a-z]{3}-\\d{2}  |  \\d{2}-\\d{2}-\\d{2} ) "),
	TQU("<$&>"),
	TQU("12-09-98"),
	TQU("xg"),

	TQU("(?(?=[^a-z]+[a-z])  \\d{2}-[a-z]{3}-\\d{2}  |  \\d{2}-\\d{2}-\\d{2} ) "),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("xg"),

	TQU("(?(?=[^a-z]+[a-z])  \\d{2}-[a-z]{3}-\\d{2}  |  \\d{2}-\\d{2}-\\d{2} ) "),
	TQU("<$&>"),
	TQU("sep-12-98"),
	TQU("xg"),

	TQU("(?<=(foo))bar\\1"),
	TQU("<$&>"),
	TQU("foobarfoo"),
	TQU("g"),

	TQU("(?<=(foo))bar\\1"),
	TQU("<$&>"),
	TQU("foobarfootling"),
	TQU("g"),

	TQU("(?<=(foo))bar\\1"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?<=(foo))bar\\1"),
	TQU("<$&>"),
	TQU("foobar"),
	TQU("g"),

	TQU("(?<=(foo))bar\\1"),
	TQU("<$&>"),
	TQU("barfoo"),
	TQU("g"),

	TQU("(?i:saturday|sunday)"),
	TQU("<$&>"),
	TQU("saturday"),
	TQU("g"),

	TQU("(?i:saturday|sunday)"),
	TQU("<$&>"),
	TQU("sunday"),
	TQU("g"),

	TQU("(?i:saturday|sunday)"),
	TQU("<$&>"),
	TQU("Saturday"),
	TQU("g"),

	TQU("(?i:saturday|sunday)"),
	TQU("<$&>"),
	TQU("Sunday"),
	TQU("g"),

	TQU("(?i:saturday|sunday)"),
	TQU("<$&>"),
	TQU("SATURDAY"),
	TQU("g"),

	TQU("(?i:saturday|sunday)"),
	TQU("<$&>"),
	TQU("SUNDAY"),
	TQU("g"),

	TQU("(?i:saturday|sunday)"),
	TQU("<$&>"),
	TQU("SunDay"),
	TQU("g"),

	TQU("(a(?i)bc|BB)x"),
	TQU("<$&>"),
	TQU("abcx"),
	TQU("g"),

	TQU("(a(?i)bc|BB)x"),
	TQU("<$&>"),
	TQU("aBCx"),
	TQU("g"),

	TQU("(a(?i)bc|BB)x"),
	TQU("<$&>"),
	TQU("bbx"),
	TQU("g"),

	TQU("(a(?i)bc|BB)x"),
	TQU("<$&>"),
	TQU("BBx"),
	TQU("g"),

	TQU("(a(?i)bc|BB)x"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(a(?i)bc|BB)x"),
	TQU("<$&>"),
	TQU("abcX"),
	TQU("g"),

	TQU("(a(?i)bc|BB)x"),
	TQU("<$&>"),
	TQU("aBCX"),
	TQU("g"),

	TQU("(a(?i)bc|BB)x"),
	TQU("<$&>"),
	TQU("bbX"),
	TQU("g"),

	TQU("(a(?i)bc|BB)x"),
	TQU("<$&>"),
	TQU("BBX"),
	TQU("g"),

	TQU("^([ab](?i)[cd]|[ef])"),
	TQU("<$&>"),
	TQU("ac"),
	TQU("g"),

	TQU("^([ab](?i)[cd]|[ef])"),
	TQU("<$&>"),
	TQU("aC"),
	TQU("g"),

	TQU("^([ab](?i)[cd]|[ef])"),
	TQU("<$&>"),
	TQU("bD"),
	TQU("g"),

	TQU("^([ab](?i)[cd]|[ef])"),
	TQU("<$&>"),
	TQU("elephant"),
	TQU("g"),

	TQU("^([ab](?i)[cd]|[ef])"),
	TQU("<$&>"),
	TQU("Europe"),
	TQU("g"),

	TQU("^([ab](?i)[cd]|[ef])"),
	TQU("<$&>"),
	TQU("frog"),
	TQU("g"),

	TQU("^([ab](?i)[cd]|[ef])"),
	TQU("<$&>"),
	TQU("France"),
	TQU("g"),

	TQU("^([ab](?i)[cd]|[ef])"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^([ab](?i)[cd]|[ef])"),
	TQU("<$&>"),
	TQU("Africa"),
	TQU("g"),

	TQU("^(ab|a(?i)[b-c](?m-i)d|x(?i)y|z)"),
	TQU("<$&>"),
	TQU("ab"),
	TQU("g"),

	TQU("^(ab|a(?i)[b-c](?m-i)d|x(?i)y|z)"),
	TQU("<$&>"),
	TQU("aBd"),
	TQU("g"),

	TQU("^(ab|a(?i)[b-c](?m-i)d|x(?i)y|z)"),
	TQU("<$&>"),
	TQU("xy"),
	TQU("g"),

	TQU("^(ab|a(?i)[b-c](?m-i)d|x(?i)y|z)"),
	TQU("<$&>"),
	TQU("xY"),
	TQU("g"),

	TQU("^(ab|a(?i)[b-c](?m-i)d|x(?i)y|z)"),
	TQU("<$&>"),
	TQU("zebra"),
	TQU("g"),

	TQU("^(ab|a(?i)[b-c](?m-i)d|x(?i)y|z)"),
	TQU("<$&>"),
	TQU("Zambesi"),
	TQU("g"),

	TQU("^(ab|a(?i)[b-c](?m-i)d|x(?i)y|z)"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("^(ab|a(?i)[b-c](?m-i)d|x(?i)y|z)"),
	TQU("<$&>"),
	TQU("aCD"),
	TQU("g"),

	TQU("^(ab|a(?i)[b-c](?m-i)d|x(?i)y|z)"),
	TQU("<$&>"),
	TQU("XY"),
	TQU("g"),

	TQU("(?<=foo\\n)^bar"),
	TQU("<$&>"),
	TQU("foo\\nbar"),
	TQU("mg"),

	TQU("(?<=foo\\n)^bar"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("mg"),

	TQU("(?<=foo\\n)^bar"),
	TQU("<$&>"),
	TQU("bar"),
	TQU("mg"),

	TQU("(?<=foo\\n)^bar"),
	TQU("<$&>"),
	TQU("baz\\nbar"),
	TQU("mg"),

	TQU("(?<=(?<!foo)bar)baz"),
	TQU("<$&>"),
	TQU("barbaz"),
	TQU("g"),

	TQU("(?<=(?<!foo)bar)baz"),
	TQU("<$&>"),
	TQU("barbarbaz"),
	TQU("g"),

	TQU("(?<=(?<!foo)bar)baz"),
	TQU("<$&>"),
	TQU("koobarbaz"),
	TQU("g"),

	TQU("(?<=(?<!foo)bar)baz"),
	TQU("<$&>"),
	TQU("*** Failers"),
	TQU("g"),

	TQU("(?<=(?<!foo)bar)baz"),
	TQU("<$&>"),
	TQU("baz"),
	TQU("g"),

	TQU("(?<=(?<!foo)bar)baz"),
	TQU("<$&>"),
	TQU("foobarbaz"),
	TQU("g"),

	TQU("^(a\\1?){4}$"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("^(a\\1?){4}$"),
	TQU("<$&>"),
	TQU("aa"),
	TQU("g"),

	TQU("^(a\\1?){4}$"),
	TQU("<$&>"),
	TQU("aaa"),
	TQU("g"),

	TQU("^(a\\1?){4}$"),
	TQU("<$&>"),
	TQU("aaaaa"),
	TQU("g"),

	TQU("^(a\\1?){4}$"),
	TQU("<$&>"),
	TQU("aaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?){4}$"),
	TQU("<$&>"),
	TQU("aaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?){4}$"),
	TQU("<$&>"),
	TQU("aaaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?){4}$"),
	TQU("<$&>"),
	TQU("aaaaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?){4}$"),
	TQU("<$&>"),
	TQU("aaaaaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?){4}$"),
	TQU("<$&>"),
	TQU("aaaaaaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?){4}$"),
	TQU("<$&>"),
	TQU("aaaaaaaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?){4}$"),
	TQU("<$&>"),
	TQU("aaaaaaaaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?){4}$"),
	TQU("<$&>"),
	TQU("aaaaaaaaaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?){4}$"),
	TQU("<$&>"),
	TQU("aaaaaaaaaaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("a"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("aa"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("aaa"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("aaaa"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("aaaaa"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("aaaaaa"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("aaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("aaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("aaaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("aaaaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("aaaaaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("aaaaaaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("aaaaaaaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("aaaaaaaaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("aaaaaaaaaaaaaaa"),
	TQU("g"),

	TQU("^(a\\1?)(a\\1?)(a\\2?)(a\\3?)$"),
	TQU("<$&>"),
	TQU("aaaaaaaaaaaaaaaa"),
	TQU("g"),
};
int	nDataRegEx03a	= sizeof(DataRegEx03a) / sizeof(TDataRegEx03a);
