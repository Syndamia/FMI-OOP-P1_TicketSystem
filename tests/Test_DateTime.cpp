#include <stdexcept>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest/doctest.h"
#include "../src/DateTime/DateTime.h"

TEST_SUITE_BEGIN("ClassDateTime");

TEST_SUITE("Constructors") {
	TEST_CASE("Ctor_SavesValues_WhenGivenCorrectOnes") {
		unsigned short h = 5, m = 12, d = 19, M = 4, y = 2022;
		DateTime dt(h, m, d, M, y);
		CHECK_EQ(dt.get_hour(), h);
		CHECK_EQ(dt.get_minute(), m);
		CHECK_EQ(dt.get_day(), d);
		CHECK_EQ(dt.get_month(), M);
		CHECK_EQ(dt.get_year(), y);
	}
	TEST_CASE("Ctor_ThrowsInvalidArgumentException_WhenGivenIncorrectValues") {
		unsigned short h = 5, m = 12, d = 19, M = 4, y = 2022;
		SUBCASE("HourIsTooBig") { h = 194; }
		SUBCASE("MinutesAreTooBig") { m = 7032; }
		SUBCASE("DayIsZero") { d = 0; }
		SUBCASE("DayIsTooBig") { d = 5721; }
		SUBCASE("MonthIsZero") { M = 0; }
		SUBCASE("MonthIsTooBig") { M = 15661; }

		CHECK_THROWS_AS(DateTime dt(h, m, d, M, y), std::invalid_argument);
	}
}

TEST_SUITE_END();
