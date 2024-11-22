#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "Point.h"

TEST_CASE("Test can create Points") {
    Point p1;
    CHECK(p1.x == 0.0);
    CHECK(p1.y == 0.0);
    Point p2(3, 4);
    CHECK(p2.x == 3.0);
    CHECK(p2.y == 4.0);
}

TEST_CASE("Test can add Points") {
    Point p1(3, 4);
    Point p2(5, 2);
    Point p3 = p1 + p2;
    CHECK(p3.x == 8.0);
    CHECK(p3.y == 6.0);
}