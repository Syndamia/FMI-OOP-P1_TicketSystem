#include <stdexcept>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest/doctest.h"
#include "../src/DateTime/DateTime.h"

TEST_SUITE_BEGIN("ClassDateTime");

const unsigned short h = 5, m = 12, d = 19, M = 4, y = 2022; // valid values

TEST_SUITE("Constructors") {
	TEST_CASE("Ctor_SavesValues_WhenGivenValidValues") {
		DateTime dt(h, m, d, M, y);

		CHECK_EQ(dt.get_hour(), h);
		CHECK_EQ(dt.get_minute(), m);
		CHECK_EQ(dt.get_day(), d);
		CHECK_EQ(dt.get_month(), M);
		CHECK_EQ(dt.get_year(), y);
	}
	TEST_CASE("Ctor_ThrowsInvalidArgumentException_WhenGivenInvalidValues") {
		unsigned short nh = h, nm = m, nd = d, nM = M, ny = y;
		SUBCASE("HourIsTooBig") { nh = 194; }
		SUBCASE("MinutesAreTooBig") { nm = 7032; }
		SUBCASE("DayIsZero") { nd = 0; }
		SUBCASE("DayIsTooBig") { nd = 5721; }
		SUBCASE("MonthIsZero") { nM = 0; }
		SUBCASE("MonthIsTooBig") { nM = 15661; }

		CHECK_THROWS_AS(DateTime dt(nh, nm, nd, nM, ny), std::invalid_argument);
	}
}

TEST_SUITE("GettersAndSetters") {
	TEST_CASE("HourGetter_ReturnsCorrectValue_WhenCreatedWithValidValues") {
		DateTime dt(h, m, d, M, y);

		CHECK_EQ(dt.get_hour(), h);
	}
	TEST_CASE("HourSetter_ReturnTrue_WhenGivenCorrectValue") {
		DateTime dt(h, m, d, M, y);
		unsigned nh;
		SUBCASE("SingleDigits") { nh = 2; }
		SUBCASE("DoubleDigits") { nh = 10; }
		SUBCASE("24hour") { nh = 17; }
		SUBCASE("Zero") { nh = 0; }

		CHECK_UNARY(dt.set_hour(nh));
	}
	TEST_CASE("HourSetter_SetsValue_WhenGivenCorrectValue") {
		DateTime dt(h, m, d, M, y);
		unsigned nh;
		SUBCASE("SingleDigits") { nh = 2; }
		SUBCASE("DoubleDigits") { nh = 10; }
		SUBCASE("24hour") { nh = 17; }
		SUBCASE("Zero") { nh = 0; }
		dt.set_hour(nh);

		CHECK_EQ(dt.get_hour(), nh);
	}
	TEST_CASE("HourSetter_ReturnsFalse_WhenGivenIncorrectValue") {
		DateTime dt(h, m, d, M, y);
		unsigned nh;
		SUBCASE("TooBig") { nh = 891; }

		CHECK_UNARY_FALSE(dt.set_hour(nh));
	}

	TEST_CASE("MinuteGetter_ReturnsCorrectValue_WhenCreatedWithValidValues") {
		DateTime dt(h, m, d, M, y);

		CHECK_EQ(dt.get_minute(), h);
	}
	TEST_CASE("MinuteSetter_ReturnTrue_WhenGivenCorrectValue") {
		DateTime dt(h, m, d, M, y);
		unsigned nm;
		SUBCASE("SingleDigits") { nm = 2; }
		SUBCASE("DoubleDigits") { nm = 10; }
		SUBCASE("24hour") { nm = 17; }
		SUBCASE("Zero") { nm = 0; }

		CHECK_UNARY(dt.set_minute(nm));
	}
	TEST_CASE("MinuteSetter_SetsValue_WhenGivenCorrectValue") {
		DateTime dt(h, m, d, M, y);
		dt.set_minute(9);

		CHECK_EQ(dt.get_minute(), 9);
	}
	TEST_CASE("MinuteSetter_ReturnsFalse_WhenGivenIncorrectValue") {
		DateTime dt(h, m, d, M, y);

		CHECK_UNARY_FALSE(dt.set_minute(888));
	}
}

TEST_SUITE_END();
