#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest/doctest.h"
#include "../src/Models/Ticket.h"

TEST_SUITE_BEGIN("ClassTicket");

TEST_SUITE("Constructors") {
	TEST_CASE("DefaultCtor_SetsZeroes_WhenCalled") {
		Ticket t;

		CHECK_EQ(t.get_row(), 0);
		CHECK_EQ(t.get_seat(), 0);
	}
	TEST_CASE("Ctor_SetsValues_WhenGivenProperValues") {
		unsigned r = 0, s = 0;
		SUBCASE("RowIsZero") { r = 0; }
		SUBCASE("RowIsPositive") { r = 3; }
		SUBCASE("SeatIsZero") { s = 0; }
		SUBCASE("SeatIsPositive") { s = 7; }
		Ticket t(r, s);

		CHECK_EQ(t.get_row(), r);
		CHECK_EQ(t.get_seat(), s);
	}
}

TEST_SUITE("GettersAndSetters") {
	TEST_CASE("RowGetter_ReturnsProperValue_WhenCreatedWithProperValue") {
		Ticket t(6, 0);

		CHECK_EQ(t.get_row(), 6);
	}
	TEST_CASE("SeatGetter_ReturnsProperValue_WhenCreatedWithProperValue") {
		Ticket t(0, 8);

		CHECK_EQ(t.get_seat(), 8);
	}
}

TEST_SUITE("compare()") {
	TEST_CASE("compare_ReturnsLessThanZero_WhenFirstIsLessThanSecond") {
		unsigned r1 = 0, r2 = 0, s1 = 0, s2 = 0;
		SUBCASE("FirstRowIsLessThanSecond") { r1 = 5; r2 = 9; }
		SUBCASE("RowsAreEqualAndFirstSeatIsLessThanSecond") { r1 = r2 = 62; s1 = 3; s2 = 93; }
		Ticket t1(r1, s1), t2(r2, s2);

		CHECK_LT(t1.compare(t2), 0);
	}
	TEST_CASE("compare_ReturnsGreaterThanZero_WhenFirstIsGreaterThanSecond") {
		unsigned r1 = 0, r2 = 0, s1 = 0, s2 = 0;
		SUBCASE("FirstRowIsGreaterThanSecond") { r1 = 9; r2 = 5; }
		SUBCASE("RowsAreEqualAndFirstSeatIsGreaterThanSecond") { r1 = r2 = 62; s1 = 93; s2 = 3; }
		Ticket t1(r1, s1), t2(r2, s2);

		CHECK_GT(t1.compare(t2), 0);
	}
	TEST_CASE("compare_ReturnsZero_WhenFirstIsEqualToSecond") {
		unsigned r1 = 458, r2 = 458, s1 = 73, s2 = 73;
		Ticket t1(r1, s1), t2(r2, s2);

		CHECK_EQ(t1.compare(t2), 0);
	}
}

TEST_SUITE_END();
