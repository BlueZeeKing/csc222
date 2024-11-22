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

TEST_CASE("Testing times") {
    Fraction fraction(5, 10);
    Fraction fraction2(15, 10);
    Fraction product = fraction.times(fraction2);
    CHECK_EQ(product.numerator, 3);
    CHECK_EQ(product.denominator, 4);

    fraction = Fraction(2, 1);
    fraction2 = Fraction(1, 6);
    product = fraction.times(fraction2);
    CHECK_EQ(product.numerator, 1);
    CHECK_EQ(product.denominator, 3);
}

TEST_CASE("Testing divide by") {
    Fraction fraction(5, 10);
    Fraction fraction2(15, 10);
    Fraction quotient = fraction.divided_by(fraction2);
    CHECK_EQ(quotient.numerator, 1);
    CHECK_EQ(quotient.denominator, 3);

    fraction = Fraction(2, 1);
    fraction2 = Fraction(1, 6);
    quotient = fraction.divided_by(fraction2);
    CHECK_EQ(quotient.numerator, 12);
    CHECK_EQ(quotient.denominator, 1);
}
