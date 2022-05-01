#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest/doctest.h"
#include "../src/DateTime/DateTime.h"

TEST_SUITE_BEGIN("ClassDateTime");

TEST_SUITE("Constructors") {
	TEST_CASE("Ctor_SavesValues_WhenGivenCorrectOnes") {
		DateTime dt(2, 49, 4, 12, 2022);
		CHECK_EQ(dt.get_hour(), 2);
		CHECK_EQ(dt.get_minute(), 49);
		CHECK_EQ(dt.get_day(), 4);
		CHECK_EQ(dt.get_month(), 12);
		CHECK_EQ(dt.get_year(), 2022);
	}
}

TEST_SUITE_END();
