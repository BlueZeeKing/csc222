#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

string render_num_vector(const vector<int>& numbers) {
    stringstream result_stream;
    for (auto i = numbers.begin(); i < numbers.end(); i++) {
        result_stream << *i;
        if (i < numbers.end() - 1) {
            result_stream << " ";
        }
    }
    return result_stream.str();
}

int num_vector_sum(const vector<int>& numbers) {
    int sum = 0;
    for (auto i = numbers.begin(); i < numbers.end(); i++) {
        sum += *i;
    }
    return sum;
}

int num_vector_product(const vector<int>& numbers) {
    int sum = 1;
    for (auto i = numbers.begin(); i < numbers.end(); i++) {
        sum *= *i;
    }
    return sum;
}

vector<int> only_evens(const vector<int>& numbers) {
    vector<int> result;
    for (auto i = numbers.begin(); i < numbers.end(); i++) {
        if (*i % 2 == 0) {
            result.push_back(*i);
        }
    }
    return result;
}

vector<int> only_odds(const vector<int>& numbers) {
    vector<int> result;
    for (auto i = numbers.begin(); i < numbers.end(); i++) {
        if (*i % 2 != 0) {
            result.push_back(*i);
        }
    }
    return result;
}


vector<int> nums_between(const vector<int>& numbers, int low, int high) {
    vector<int> result;

    for (auto i = numbers.begin(); i < numbers.end(); i++) {
        if (*i <= high && *i >= low) {
            result.push_back(*i);
        }
    }

    return result;
}

double mean(const vector<int>& numbers) {
    return (double) num_vector_sum(numbers) / (double) numbers.size();
}

/**
 * numbers must be sorted
 */
double median(const vector<int>& numbers) {
    int middle = numbers.size() / 2;

    if (numbers.size() % 2 == 0) {
        return (numbers[middle] + numbers[middle - 1]) / 2.0;    
    }
    return numbers[middle];
}

vector<int> mode(const vector<int>& numbers) {
    unordered_map<int, int> counts;

    for (int number : numbers) {
        if (counts.contains(number)) {
            counts[number]++;
        } else {
            counts.insert(std::pair(number, 1));
        }
    }

    int max_count = 0;
    vector<int> mode_value;
    for (pair<int, int> count : counts) {
        if (count.second > max_count) {
            mode_value.clear();
            max_count = count.second;
        }

        if (count.second == max_count) {
            mode_value.push_back(count.first);
        }
    }

    return mode_value;
}
