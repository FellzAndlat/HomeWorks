#include <iostream>
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"
#include "List.cpp"

TEST_CASE("List testing", "[l_test]") {
    List ListTest;
    REQUIRE(ListTest.Empty() == 1);
    SECTION("Test size") {
        ListTest.PushBack(24);
        ListTest.PushBack(4);
        CHECK(ListTest.Size() == 2);
        ListTest.PushBack(29);
        ListTest.PushBack(234);
        CHECK(ListTest.Size() == 4);
        ListTest.PushBack(232);
        CHECK(ListTest.Size() == 5);
    }
    SECTION("Test Clear") {
        ListTest.PushBack(29);
        ListTest.PushBack(234);
        ListTest.Clear();
        CHECK(ListTest.Size() == 0);
        ListTest.PushBack(264);
        ListTest.Clear();
        CHECK(ListTest.Size() == 0);
    }
}
int main() {
	return Catch::Session().run();
}