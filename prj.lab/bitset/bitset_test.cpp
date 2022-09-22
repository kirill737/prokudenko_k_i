#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <bitset/bitset.h>
#include <string>
#include <stdexcept>

TEST_CASE("[Bitset] - Comparison operators tests") {

	CHECK(Bitset("10101") == ~Bitset("01010"));
	CHECK((Bitset("111000") & Bitset("011001")) == Bitset("011000"));
	CHECK((Bitset("111000") | Bitset("100011")) == Bitset("111011"));
	CHECK(Bitset(5, false) == Bitset("00000"));
	CHECK(Bitset(4, true) == ~Bitset("0000"));
}