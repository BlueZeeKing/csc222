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

TEST_CASE("Testing plus") {
    Fraction fraction(5, 10);
    Fraction fraction2(15, 10);
    Fraction sum = fraction.plus(fraction2);
    CHECK_EQ(sum.numerator, 2);
    CHECK_EQ(sum.denominator, 1);

    fraction = Fraction(1, 1);
    fraction2 = Fraction(1, 6);
    sum = fraction.plus(fraction2);
    CHECK_EQ(sum.numerator, 7);
    CHECK_EQ(sum.denominator, 6);
}

TEST_CASE("Testing minus") {
    Fraction fraction(5, 10);
    Fraction fraction2(15, 10);
    Fraction difference = fraction.minus(fraction2);
    CHECK_EQ(difference.numerator, -1);
    CHECK_EQ(difference.denominator, 1);

    fraction = Fraction(1, 1);
    fraction2 = Fraction(1, 6);
    difference = fraction.minus(fraction2);
    CHECK_EQ(difference.numerator, 5);
    CHECK_EQ(difference.denominator, 6);
}
