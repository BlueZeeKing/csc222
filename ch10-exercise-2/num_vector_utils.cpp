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

double median(const vector<int>& numbers) {
    int middle = numbers.size() / 2;

    if (numbers.size() % 2 == 0) {
        return (numbers[middle] + numbers[middle - 1]) / 2.0;    
    }
    return numbers[middle];
}

int mode(const vector<int>& numbers) {
    vector<pair<int, int>> counts;

    for (auto number = numbers.begin(); number < numbers.end(); number++) {
        bool found = false;

        for (auto count = counts.begin(); count < counts.end(); count++) {
            if (*number == count->first) {
                count->second++;
                found = true;
                break;
            }
        }

        if (!found) {
            counts.push_back(pair(*number, 1));
        }
    }

    int max_count = 0;
    int mode_value = 0;
    for (auto count = counts.begin(); count < counts.end(); count++) {
        if (count->second > max_count) {
            mode_value = count->first;
            max_count = count->second;
        }
    }

    return mode_value;
}
