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
