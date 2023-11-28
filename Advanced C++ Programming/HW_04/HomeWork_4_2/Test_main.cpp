#include <iostream>
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"
#include "List.cpp"

TEST_CASE("List testing", "[A_test]") {
    List ListTest;
    
    SECTION("Test popback and popfront on a blank sheet") {
        CHECK_THROWS(ListTest.PopBack());
        CHECK_THROWS(ListTest.PopFront());
    }
    SECTION("Test pushback and popback") {
        ListTest.PushBack(1);
        CHECK(ListTest.Size() == 1);
        ListTest.PushBack(5);
        ListTest.PushBack(3);
        ListTest.PushBack(10);
        CHECK(ListTest.Size() == 4);
        ListTest.PushBack(456);
        ListTest.PushBack(223);
        CHECK(ListTest.Size() == 6);

        ListTest.PopBack();
        CHECK(ListTest.Size() == 5);
        ListTest.PopBack();
        ListTest.PopBack();
        CHECK(ListTest.Size() == 3);
        ListTest.PopBack();
        ListTest.PopBack();
        ListTest.PopBack();
        CHECK(ListTest.Size() == 0);
    }
    SECTION("Test pushfront and popfront") {
        ListTest.PushFront(2);
        ListTest.PushFront(22);
        ListTest.PushFront(21);
        CHECK(ListTest.Size() == 3);
        ListTest.PushFront(25);
        ListTest.PushFront(28);
        CHECK(ListTest.Size() == 5);
        ListTest.PushFront(23);
        CHECK(ListTest.Size() == 6);

        ListTest.PopFront();
        ListTest.PopFront();
        CHECK(ListTest.Size() == 4);
        ListTest.PopFront();
        CHECK(ListTest.Size() == 3);
        ListTest.PopFront();
        ListTest.PopFront();
        ListTest.PopFront();
        CHECK(ListTest.Size() == 0);
    }


}

int main() {
	return Catch::Session().run();
}