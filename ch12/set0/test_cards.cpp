#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <iostream>
#include <string>
#include "Card.h"
using namespace std;

TEST_CASE("Test can create Cards") {
    Card c1;
    CHECK(c1.suit == 0);
    CHECK(c1.rank == 0);
    Card c2(3, 4);
    CHECK(c2.suit == 3);
    CHECK(c2.rank == 4);
}

TEST_CASE("Test can render Cards") {
    Card c3(3, 12);
    CHECK(c3.to_string() == "Queen of Hearts");
    Card c4(2, 10);
    CHECK(c4.to_string() == "10 of Diamonds");
    Card c5;
    CHECK(c5.to_string() == "Joker");
}

TEST_CASE("Cards Equal") {
    Card c1(3, 12);
    Card c2(3, 12);
    CHECK_EQ(c1, c2);
    Card c3;
    CHECK_NE(c1, c3);
}

TEST_CASE("Cards greater than") {
    Card c1(3, 12);
    Card c2(4, 12);
    CHECK_GT(c2, c1);
    Card c3(3, 11);
    CHECK_GT(c1, c3);
    Card c4(3, 11);
    CHECK(!(c3 > c4));
}

TEST_CASE("Cards less than or equal too") {
    Card c1(3, 12);
    Card c2(4, 12);
    CHECK(c1 <= c2);
    Card c3(3, 11);
    CHECK(c3 <= c1);
    Card c4(3, 11);
    CHECK(c3 <= c4);
}

TEST_CASE("Cards less than") {
    Card c1(3, 12);
    Card c2(4, 12);
    CHECK_LT(c1, c2);
    Card c3(3, 11);
    CHECK_LT(c3, c1);
    Card c4(3, 11);
    CHECK(!(c3 < c4));
}

TEST_CASE("Cards greater than or equal too") {
    Card c1(3, 12);
    Card c2(4, 12);
    CHECK(c2 >= c1);
    Card c3(3, 11);
    CHECK(c1 >= c3);
    Card c4(3, 11);
    CHECK(c3 >= c4);
}
