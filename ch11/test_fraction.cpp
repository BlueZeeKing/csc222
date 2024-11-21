#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "Fraction.h"

TEST_CASE("Testing constructors") {
    Fraction fraction;
    CHECK_EQ(fraction.numerator, 0);
    CHECK_EQ(fraction.denominator, 1);

    Fraction fraction2(5, 10);
    CHECK_EQ(fraction2.numerator, 5);
    CHECK_EQ(fraction2.denominator, 10);
}
