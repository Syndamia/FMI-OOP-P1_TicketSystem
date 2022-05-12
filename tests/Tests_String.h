#include <cstring>
#include "../doctest/doctest/doctest.h"
#include "../src/Generic/String/String.h"

TEST_SUITE_BEGIN("ClassString");

TEST_SUITE("Constructors") {
	TEST_CASE("Ctor_CreatesInternalArrayOfLength_WhenGivenCorrectLength") {
		String s(5);

		CHECK_EQ(strlen(s.get_cstr()), 5);
	}
	TEST_CASE("Ctor_CopiesValues_WhenGivenCorrectCString") {
		String s("Testing string.");

		CHECK_EQ(strcmp(s.get_cstr(), "Testing string."), 0);
	}
}

TEST_SUITE("GettersAndSetters") {
	TEST_CASE("CStrGetter_ReturnsCorrectPointer_WhenCreatedWithCString") {
		String s("Testing string.");

		CHECK_EQ(strcmp(s.get_cstr(), "Testing string."), 0);
	}

	TEST_CASE("LengthGetter_ReturnsCorrectLength_WhenCreatedWithLength") {
		String s(5);

		CHECK_EQ(s.get_length(), 5);
	}
	TEST_CASE("LengthGetter_ReturnsCorrectLength_WhenCreatedWithCString") {
		String s("Testing string.");

		CHECK_EQ(s.get_length(), strlen(s.get_cstr()));
	}
}

TEST_SUITE("Operators") {
	TEST_CASE("BracketsOperator_ReturnsCorrectCharacter_WhenGivenCorrectIndex") {
		String s("Tesing string.");

		unsigned index = 0;
		char expectedCharacter = '\0';
		SUBCASE("IndexIsZero") { index = 0; expectedCharacter = 'T'; }
		SUBCASE("IndexIsSomewhereInTheMiddle") { index = 5; expectedCharacter = 'g'; }
		SUBCASE("IndexIsLast") { index = 13; expectedCharacter = '.'; }
		SUBCASE("IndexIsTerminatingZero") { index = 14; expectedCharacter = '\0'; }

		CHECK_EQ(s[index], expectedCharacter);
	}
	TEST_CASE("BracketsOperator_SetsCharacter_WhenGivenCorrectIndexAndValue") {
		String s("Tesing string.");

		unsigned index = 0;
		char replaceWith = 'W';
		SUBCASE("IndexIsZero") { index = 0; }
		SUBCASE("IndexIsSomewhereInTheMiddle") { index = 5; }
		SUBCASE("IndexIsLast") { index = 13; }
		s[index] = replaceWith;

		CHECK_EQ(s[index], replaceWith);
	}

	TEST_CASE("PlusEqualOperator_AppendsProperlyCString_WhenGivenCorrectStringAndCreatedWithCstr") {
		String s("Testing");
		s += " string.";

		CHECK_EQ(strcmp(s.get_cstr(), "Testing string."), 0);
	}
	TEST_CASE("PlusEqualOperator_AppendsProperlyNumber_WhenGivenCorrectNumberAndCreatedWithCstr") {
		String s("Testing");
		s += 15684;

		CHECK_EQ(strcmp(s.get_cstr(), "Testing15684"), 0);
	}
}

TEST_SUITE("compare()") {
	TEST_CASE("compare_ReturnsSameResultAsstrcmp_WhenFirstIsLessThanSecond") {
		String s1("Test"), s2("test");

		CHECK_LT(s1.compare(s2), 0);
		CHECK_LT(strcmp("Test", "test"), 0);
	}
	TEST_CASE("compare_ReturnsSameResultAsstrcmp_WhenFirstIsGreaterThanSecond") {
		String s1("test"), s2("Test");

		CHECK_GT(s1.compare(s2), 0);
		CHECK_GT(strcmp("test", "Test"), 0);
	}
	TEST_CASE("compare_ReturnsSameResultAsstrcmp_WhenFirstIsEqualToSecond") {
		String s1("test"), s2("test");

		CHECK_EQ(s1.compare(s2), strcmp("test", "test"));
	}
}

TEST_SUITE_END();
