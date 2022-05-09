#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest/doctest.h"
#include "../src/Models/Event.h"
#include "../src/Generic/String/String.h"

TEST_SUITE_BEGIN("ClassEvent");

TEST_SUITE("Constructors") {
	TEST_CASE("DefaultCtor_CallsDefaultCtorsOnData_WhenCalled") {
		Event e;

		CHECK_EQ(e.get_hall().compare(Hall()), 0);
		CHECK_EQ(e.get_name().compare(String()), 0);
		CHECK_EQ(e.get_date().compare(Date()), 0);
	}
	TEST_CASE("Ctor_SavesParameters_WhenCalledWithProperParameters") {
		Hall h(1, 2, 3);
		String n("Test");
		Date d(21, 3, 2012);

		Event e(h, n, d);
		CHECK_EQ(e.get_hall().compare(h), 0);
		CHECK_EQ(e.get_name().compare(n), 0);
		CHECK_EQ(e.get_date().compare(d), 0);
	}
}

TEST_SUITE("GettersAndSetters") {
	TEST_CASE("HallGetter_ReturnsProperHall_WhenCreatedWithProperHall") {
		Hall h(1, 2, 3);
		String n("Test");
		Date d(21, 3, 2012);

		Event e(h, n, d);
		CHECK_EQ(e.get_hall().compare(h), 0);
	}

	TEST_CASE("NameGetter_ReturnsProperName_WhenCreatedWithProperName") {
		Hall h(1, 2, 3);
		String n("Test");
		Date d(21, 3, 2012);

		Event e(h, n, d);
		CHECK_EQ(e.get_name().compare(n), 0);
	}

	TEST_CASE("DateGetter_ReturnsProperDate_WhenCreatedWithProperDate") {
		Hall h(1, 2, 3);
		String n("Test");
		Date d(21, 3, 2012);

		Event e(h, n, d);
		CHECK_EQ(e.get_date().compare(d), 0);
	}

	TEST_CASE("TicketsGetter_ReturnsEmptyList_WhenCreatedWithDefaultCtor") {
		Event e;

		CHECK_EQ(e.get_tickets().get_count(), 0);
	}

	TEST_CASE("ReservationsGetter_ReturnsEmptyList_WhenCreatedWithDefaultCtor") {
		Event e;

		CHECK_EQ(e.get_reservations().get_count(), 0);
	}
}

TEST_SUITE("compare()") {
	TEST_CASE("compare_ReturnsCompareBetweenHallsAndDates_WhenCalled") {
		Hall h1(1, 2, 3), h2(3, 4, 5);
		Date d1(1, 4, 2009), d2(19, 5, 2010);

		SUBCASE("HallIsLessThanOtherHall") {}
		SUBCASE("HallIsBiggerThanOtherHall") { Hall temp = h2; h2 = h1; h1 = temp; }
		SUBCASE("HallsAreEqual") { h1 = h2; }
		SUBCASE("HallsAreEqualAndDateIsLessThanOther") {}
		SUBCASE("HallsAreEqualAndDateIsMoreThanOther") { Date temp = d2; d2 = d1; d1 = temp; }
		SUBCASE("HallsAreEqualAndDatesAreEqual") { h1 = h2; d1 = d2; }
		Event e1(h1, "Test1", d1), e2(h2, "Test2", d2);

		if (h1.compare(h2) == 0)
			CHECK_EQ(e1.compare(e2), d1.compare(d2));
		else
			CHECK_EQ(e1.compare(e2), h1.compare(h2));
	}
}

TEST_SUITE_END();
