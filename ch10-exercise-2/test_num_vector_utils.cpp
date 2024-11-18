#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <string>
#include <vector>
#include "num_vector_utils.h"
using namespace std;

#define CHECK_CLOSE_ENOUGH(a, b) CHECK(fabs(a - b) < 1E-5);

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

TEST_CASE("Testing only_odds") {
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 11, 12, 14, 27, 22};
    vector<int> evens = only_odds(nums);
    string expected = "1 3 7 11 27";
    CHECK(render_num_vector(evens) == expected);
}

TEST_CASE("Testing nums_between function") {
    vector<int> nums = {11, 2, 13, 4, 10, 26, 7, 88, 19, 20, 14, 5, 32};
    vector<int> nums2 = nums_between(nums, 10, 20);
    string expected = "11 13 10 19 20 14";
    CHECK(render_num_vector(nums2) == expected);
}

TEST_CASE("Testing mean function") {
    vector<int> nums = {11, 2, 13, 4, 10, 26, 7, 88, 19, 20, 14, 5, 32};
    double mean_value = mean(nums);
    CHECK_CLOSE_ENOUGH(mean_value, 19.30769231);
}


TEST_CASE("Testing median function") {
    vector<int> nums = {2, 4, 5, 7, 10, 11, 13, 14, 19, 20, 26, 32, 88 };
    double median_value = median(nums);
    CHECK_CLOSE_ENOUGH(median_value, 13);

    nums = { 1, 2, 3 };
    median_value = median(nums);
    CHECK_CLOSE_ENOUGH(median_value, 2);

    nums = { 1, 2, 3, 4 };
    median_value = median(nums);
    CHECK_CLOSE_ENOUGH(median_value, 2.5);
}

TEST_CASE("Testing mode function") {
    vector<int> nums = {11, 2, 13, 4, 10, 26, 7, 88, 19, 20, 14, 5, 32};
    int mode_value = mode(nums);
    CHECK_EQ(mode_value, 11);

    nums = { 1, 2, 2, 3 };
    mode_value = mode(nums);
    CHECK_EQ(mode_value, 2);

    nums = { 1, 2, 2, 3, 3, 3, 4 };
    mode_value = mode(nums);
    CHECK_EQ(mode_value, 3);

    nums = { 1, 2, 2, 3, 3, 4 };
    mode_value = mode(nums);
    CHECK_EQ(mode_value, 2);
}
