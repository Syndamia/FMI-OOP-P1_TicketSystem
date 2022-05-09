#include <cstring>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest/doctest.h"
#include "../src/Generic/Date/Date.h"

TEST_SUITE_BEGIN("ClassDate");

const unsigned short d = 19, m = 4, y = 2022; // valid values

TEST_SUITE("Constructors") {
	TEST_CASE("DefaultCtor_SetsDateAsFirstOfMay2022_WhenCalled") {
		Date dt;

		CHECK_EQ(dt.get_day(), 1);
		CHECK_EQ(dt.get_month(), 5);
		CHECK_EQ(dt.get_year(), 2022);
	}
	TEST_CASE("StrCtor_ParsesValues_WhenGivenCorrectString") {
		char str[] = "9 12 2021";
		Date dt(str);

		CHECK_EQ(dt.get_day(), 9);
		CHECK_EQ(dt.get_month(), 12);
		CHECK_EQ(dt. get_year(), 2021);
	}
	TEST_CASE("StrCtor_StoresZeroes_WhenGivenBadString") {
		char str[] = "45 500 ABCD";
		Date dt(str);

		CHECK_EQ(dt.get_day(), 0);
		CHECK_EQ(dt.get_month(), 0);
		CHECK_EQ(dt.get_year(), 0);
	}
	TEST_CASE("StrCtor_StoresZeroes_WhenGivenBlankString") {
		char str[] = "";
		Date dt(str);

		CHECK_EQ(dt.get_day(), 0);
		CHECK_EQ(dt.get_month(), 0);
		CHECK_EQ(dt.get_year(), 0);
	}
	TEST_CASE("Ctor_SavesValues_WhenGivenValidValues") {
		Date dt(d, m, y);

		CHECK_EQ(dt.get_day(), d);
		CHECK_EQ(dt.get_month(), m);
		CHECK_EQ(dt.get_year(), y);
	}
	TEST_CASE("Ctor_StoresZeroes_WhenGivenInvalidValues") {
		unsigned short nd = 0, nm = 0, ny = 0;
		SUBCASE("DayIsZero") { nd = 0; }
		SUBCASE("DayIsTooBig") { nd = 5721; }
		SUBCASE("MonthIsZero") { nm = 0; }
		SUBCASE("MonthIsTooBig") { nm = 15661; }
		SUBCASE("YearIsZero") { ny = 0; }

		Date dt(nd, nm, ny);
		CHECK_EQ(dt.get_day(), 0);
		CHECK_EQ(dt.get_month(), 0);
		CHECK_EQ(dt.get_year(), 0);
	}
}

TEST_SUITE("GettersAndSetters") {
	TEST_CASE("DayGetter_ReturnsCorrectValue_WhenCreatedWithValidValues") {
		Date dt(d, m, y);

		CHECK_EQ(dt.get_day(), d);
	}
	TEST_CASE("DaySetter_ReturnsTrue_WhenGivenCorrectValue") {
		Date dt(d, m, y);
		unsigned nd = d;
		SUBCASE("SingleDigits") { nd = 2; }
		SUBCASE("DoubleDigits") { nd = 26; }

		CHECK_UNARY(dt.set_day(nd));
	}
	TEST_CASE("DaySetter_SetsValue_WhenGivenCorrectValue") {
		Date dt(d, m, y);
		unsigned nd = d;
		SUBCASE("SingleDigits") { nd = 9; }
		SUBCASE("DoubleDigits") { nd = 13; }
		dt.set_day(nd);

		CHECK_EQ(dt.get_day(), nd);
	}
	TEST_CASE("DaySetter_ReturnsFalse_WhenGivenIncorrectValue") {
		Date dt(d, m, y);
		unsigned nd = d;
		SUBCASE("Zero") { nd = 0; }
		SUBCASE("TooBig") { nd = 847; }

		CHECK_UNARY_FALSE(dt.set_day(nd));
	}

	TEST_CASE("MonthGetter_ReturnsCorrectValue_WhenCreatedWithValidValues") {
		Date dt(d, m, y);

		CHECK_EQ(dt.get_month(), m);
	}
	TEST_CASE("MonthSetter_ReturnsTrue_WhenGivenCorrectValue") {
		Date dt(d, m, y);
		unsigned nm = m;
		SUBCASE("SingleDigits") { nm = 2; }
		SUBCASE("DoubleDigits") { nm = 11; }

		CHECK_UNARY(dt.set_month(nm));
	}
	TEST_CASE("MonthSetter_SetsValue_WhenGivenCorrectValue") {
		Date dt(d, m, y);
		unsigned nm = m;
		SUBCASE("SingleDigits") { nm = 9; }
		SUBCASE("DoubleDigits") { nm = 10; }
		dt.set_month(nm);

		CHECK_EQ(dt.get_month(), nm);
	}
	TEST_CASE("MonthSetter_ReturnsFalse_WhenGivenIncorrectValue") {
		Date dt(d, m, y);
		unsigned nm = m;
		SUBCASE("Zero") { nm = 0; }
		SUBCASE("TooBig") { nm = 13; }

		CHECK_UNARY_FALSE(dt.set_month(nm));
	}

	TEST_CASE("YearGetter_ReturnsCorrectValue_WhenCreatedWithValidValues") {
		Date dt(d, m, y);

		CHECK_EQ(dt.get_year(), y);
	}
	TEST_CASE("YearSetter_ReturnsTrue_WhenGivenCorrectValue") {
		Date dt(d, m, y);
		unsigned ny = y;
		SUBCASE("SingleDigits") { ny = 2; }
		SUBCASE("DoubleDigits") { ny = 58; }
		SUBCASE("TripleDigits") { ny = 681; }
		SUBCASE("QuadrupleDigits") { ny = 1878; }

		CHECK_UNARY(dt.set_year(ny));
	}
	TEST_CASE("YearSetter_SetsValue_WhenGivenCorrectValue") {
		Date dt(d, m, y);
		unsigned ny = y;
		SUBCASE("SingleDigits") { ny = 2; }
		SUBCASE("DoubleDigits") { ny = 58; }
		SUBCASE("TripleDigits") { ny = 681; }
		SUBCASE("QuadrupleDigits") { ny = 1878; }
		dt.set_year(ny);

		CHECK_EQ(dt.get_year(), ny);
	}
	TEST_CASE("YearSetter_ReturnsFalse_WhenGivenIncorrectValue") {
		Date dt(d, m, y);
		unsigned ny = y;
		SUBCASE("Zero") { ny = 0; }

		CHECK_UNARY_FALSE(dt.set_year(ny));
	}
}

TEST_SUITE("createString()") {
	TEST_CASE("createString_CreatesCorrectString_WhenCalled") {
		Date dt(8, 10, 2019);
		String output = dt.createString();

		CHECK_EQ(strcmp(output.get_cstr(), "8.10.2019"), 0);
	}
}

TEST_SUITE("compare()") {
	TEST_CASE("compare_ReturnsLessThanZero_WhenFirstDateIsBeforeSecond") {
		Date dt1(d, m, y), dt2(d, m, y);
		SUBCASE("DifferenceByDay") { dt1.set_day(d - 1); }
		SUBCASE("DifferenceByMonth") { dt1.set_month(m - 1); }
		SUBCASE("DifferenceByYear") { dt1.set_year(y - 1); }

		CHECK_LT(dt1.compare(dt2), 0);
	}
	TEST_CASE("compare_ReturnsMoreThanZero_WhenFirstDateIsAfterSecond") {
		Date dt1(d, m, y), dt2(d, m, y);
		SUBCASE("DifferenceByDay") { dt2.set_day(d - 1); }
		SUBCASE("DifferenceByMonth") { dt2.set_month(m - 1); }
		SUBCASE("DifferenceByYear") { dt2.set_year(y - 1); }

		CHECK_GT(dt1.compare(dt2), 0);
	}
	TEST_CASE("compare_ReturnsZero_WhenDatesAreEqual") {
		Date dt1(d, m, y), dt2(d, m, y);

		CHECK_EQ(dt1.compare(dt2), 0);
	}
}

TEST_SUITE_END();
