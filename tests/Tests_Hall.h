#include "../doctest/doctest/doctest.h"
#include "../src/Models/Hall.h"

TEST_SUITE_BEGIN("ClassHall");

int number = 5; // valid values
unsigned rows = 10, seatsPerRow = 6; // valid values

TEST_SUITE("Constructors") {
	TEST_CASE("DefaultCtor_SetsValuesToZero_WhenCalled") {
		Hall h;

		CHECK_EQ(h.get_number(), 0);
		CHECK_EQ(h.get_rows(), 0);
		CHECK_EQ(h.get_seatsPerRow(), 0);
	}
	TEST_CASE("NumberCtor_SetsNumberToParameterAndOthersToZeroes_WhenCalled") {
		SUBCASE("NegativeNumber") { number = -843; }
		SUBCASE("ZeroNumber") { number = 0; }
		SUBCASE("PositiveNumber") { number = 571; }

		Hall h(number);
		CHECK_EQ(h.get_number(), number);
	}
	TEST_CASE("Ctor_SetsValues_WhenGivenCorrectValues") {
		SUBCASE("NegativeNumber") { number = -843; }
		SUBCASE("ZeroNumber") { number = 0; }
		SUBCASE("PositiveNumber") { number = 571; }
		SUBCASE("ZeroRow") { rows = 0; }
		SUBCASE("PositiveRow") { rows = 91; }
		SUBCASE("ZeroSeatsPerRow") { seatsPerRow = 0; }
		SUBCASE("PositiveSeatsPerRow") { seatsPerRow = 37; }

		Hall h(number, rows, seatsPerRow);
		CHECK_EQ(h.get_number(), number);
		CHECK_EQ(h.get_rows(), rows);
		CHECK_EQ(h.get_seatsPerRow(), seatsPerRow);
	}
}

TEST_SUITE("GettersAndSetters") {
	TEST_CASE("NumberGetter_ReturnsProperValue_WhenGivenCorrectValue") {
		SUBCASE("CreatedWithZeroNumber") { number = 0; }
		SUBCASE("CreatedWithPositiveNumber") { number = 473; }
		SUBCASE("CretaedWithNegativeNumber") { number = -384; }

		Hall h(number, rows, seatsPerRow);
		CHECK_EQ(h.get_number(), number);
	}
	TEST_CASE("RowsGetter_ReturnsProperValue_WhenGivenCorrectValue") {
		SUBCASE("CreatedWithZeroRows") { rows = 0; }
		SUBCASE("CreatedWithPositiveRows") { rows = 473; }

		Hall h(number, rows, seatsPerRow);
		CHECK_EQ(h.get_rows(), rows);
	}
	TEST_CASE("SeatsPerRowGetter_ReturnsProperValue_WhenGivenCorrectValue") {
		SUBCASE("CreatedWithZeroSeatsPerRow") { seatsPerRow = 0; }
		SUBCASE("CreatedWithPositiveSeatsPerRow") { seatsPerRow = 473; }

		Hall h(number, rows, seatsPerRow);
		CHECK_EQ(h.get_seatsPerRow(), seatsPerRow);
	}
}

TEST_SUITE("compare()") {
	TEST_CASE("compare_ReturnsLessThanZero_WhenFirstHallNumberIsLessThanSecondHallNumber") {
		Hall h1(number, rows, seatsPerRow), h2(number + 1, rows, seatsPerRow);

		CHECK_LT(h1.compare(h2), 0);
	}
	TEST_CASE("compare_ReturnsMoreThanZero_WhenFirstHallNumberIsMoreThanSecondHallNumber") {
		Hall h1(number + 1, rows, seatsPerRow), h2(number, rows, seatsPerRow);

		CHECK_GT(h1.compare(h2), 0);
	}
	TEST_CASE("compare_ReturnsZero_WhenFirstHallNumberIsEqualToSecondHallNumber") {
		Hall h1(number, rows, seatsPerRow), h2(number, rows, seatsPerRow);

		CHECK_EQ(h1.compare(h2), 0);
	}
}

TEST_SUITE_END();
