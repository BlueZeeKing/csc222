#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <string>
#include <vector>
#include "num_vector_utils.h"
using namespace std;

TEST_CASE("Testing render_num_vector") {
    vector<int> nums = {1, 3, 7};
    string numstr = render_num_vector(nums);
    string expected = "1 3 7";
    CHECK(numstr == expected);

    nums = { 22, 746, 5837, 5749 };
    numstr = render_num_vector(nums);
    expected = "22 746 5837 5749";
    CHECK(numstr == expected);

    nums = { };
    numstr = render_num_vector(nums);
    expected = "";
    CHECK(numstr == expected);
}

TEST_CASE("Testing num_vector_sum") {
    vector<int> nums = {1, 3, 7};
    CHECK(11 == num_vector_sum(nums));
    nums = { 22, 746, 5837, 5749 };
    CHECK(12354 == num_vector_sum(nums));
    nums = { };
    CHECK(0 == num_vector_sum(nums));
}

TEST_CASE("Testing num_vector_product") {
    vector<int> nums = {1, 3, 7};
    CHECK(21 == num_vector_product(nums));
    nums = { 22, 746, 5837 };
    CHECK(95796844 == num_vector_product(nums));
    nums = { };
    CHECK(1 == num_vector_product(nums));
}

TEST_CASE("Testing only_evens") {
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 11, 12, 14, 27, 22};
    vector<int> evens = only_evens(nums);
    string expected = "2 4 6 8 12 14 22";
    CHECK(render_num_vector(evens) == expected);
}
