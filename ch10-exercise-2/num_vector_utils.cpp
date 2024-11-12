#include <sstream>
#include <string>
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
