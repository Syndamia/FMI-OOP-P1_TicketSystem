#include <cstring>
#include "../doctest/doctest/doctest.h"
#include "../src/Models/Reservation.h"

TEST_SUITE_BEGIN("ClassReservation");

TEST_SUITE("Constructors") {
	TEST_CASE("DefaultCtor_CallsDefaultCtorOfTicketAndSetsNoteAndPasswordBlank_WhenCalled") {
		Reservation r;

		CHECK_EQ(r.get_ticket().compare(Ticket()), 0);
		CHECK_EQ(strcmp(r.get_password(), ""), 0);
		CHECK_EQ(strcmp(r.get_note(), ""), 0);
	}
	TEST_CASE("TicketCtor_SavesTicketAndSetsNoteAndPasswordBlank_WhenCalled") {
		Ticket t(4, 2);
		Reservation r(t);

		CHECK_EQ(r.get_ticket().compare(t), 0);
		CHECK_EQ(strcmp(r.get_password(), ""), 0);
		CHECK_EQ(strcmp(r.get_note(), ""), 0);
	}
	TEST_CASE("Ctor_SavesProperValues_WhenGivenProperValues") {
		Ticket t(6, 1);
		Reservation r(t, "One", "Two");

		CHECK_EQ(r.get_ticket().compare(t), 0);
		CHECK_EQ(strcmp(r.get_password(), "One"), 0);
		CHECK_EQ(strcmp(r.get_note(), "Two"), 0);
	}
}

TEST_SUITE("GettersAndSetters") {
	TEST_CASE("TicketGetter_ReturnsProperValue_WhenCreatedWithTicket") {
		Ticket t(5, 7);
		Reservation r(t);

		CHECK_EQ(r.get_ticket().compare(t), 0);
	}
	TEST_CASE("PasswordGetter_ReturnsProperValue_WhenCreatedWithProperValue") {
		Reservation r(Ticket(), "12345678", "");

		CHECK_EQ(strcmp(r.get_password(), "12345678"), 0);
	}
	TEST_CASE("NoteGetter_ReturnsProperValue_WhenCreatedWithProperValue") {
		Reservation r(Ticket(), "", "One Two Three");

		CHECK_EQ(strcmp(r.get_note(), "One Two Three"), 0);
	}
}

TEST_SUITE("compare()") {
	TEST_CASE("Compare_ReturnsTicketCompare_WhenCalled") {
		Ticket t1(1, 1), t2(2, 2);
		SUBCASE("FirstIsBiggerThanSecond") { t1 = Ticket(3, 3); }
		SUBCASE("FirstIsSmallerThanSecond") {}
		SUBCASE("FirstIsEqualToSecond") { t1 = t2; }
		Reservation r1(t1), r2(t2);

		CHECK_EQ(r1.compare(r2), t1.compare(t2));
	}
}

TEST_SUITE_END();
