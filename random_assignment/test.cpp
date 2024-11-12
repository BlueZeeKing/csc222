#include <sstream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "parse.h"

TEST_CASE("parse") {
    vector<vector<string>> expected = {
        {
            "first",
            "second",
            "third",
        },
        {
            "a",
            "b",
            "c",
        },
        {
            "primary",
            "secondary",
        }
    };
    string input = "first\nsecond\nthird\n===\na\nb\nc\n===\nprimary\nsecondary\n";
    stringstream input_stream(input);
    CHECK_EQ(expected, parse(input_stream));
}
