#include <cstring>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest/doctest/doctest.h"
#include "../src/Generic/ConsoleInterface/Command.h"

TEST_SUITE_BEGIN("ClassCommand");

unsigned value = 0;
void increment() {
	value++;
}

TEST_SUITE("Constructors") {
	TEST_CASE("DefaultCtor_SavesNameInMenuAsBlankString_WhenCalled") {
		Command c;

		CHECK_EQ(strcmp(c.get_nameInMenu(), ""), 0);
	}
	TEST_CASE("Ctor_SavesValues_WhenGivenCorrectValues") { 
		void (*exec)() = nullptr;
		SUBCASE("ActualFunctionPointer") { exec = increment; }
		SUBCASE("nullptrFunctionPointer") { exec = nullptr; }
		Command c("Test", exec);

		CHECK_EQ(strcmp(c.get_nameInMenu(), "Test"), 0);
	}
}

TEST_SUITE("GettersAndSetters") {
	TEST_CASE("nameInMenuGetter_ReturnsProperPointer_WhenCreatedWithProperString") {
		Command c("Test", nullptr);

		CHECK_EQ(strcmp(c.get_nameInMenu(), "Test"), 0);
	}
	TEST_CASE("nameInMenuGetter_ReturnsBlankString_WhenCreatedWithDefaultCtor") {
		Command c;

		CHECK_EQ(strcmp(c.get_nameInMenu(), ""), 0);
	}
}

TEST_SUITE("run()") {
	TEST_CASE("run_ExecutesFunction_WhenCreatedWithProperFunction") {
		value = 0;
		Command c("Test", increment);
		c.run();

		CHECK_EQ(value, 1);
	}
}

TEST_SUITE_END();
