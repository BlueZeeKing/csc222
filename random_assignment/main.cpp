#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "parse.h"
using namespace std;

int main() {
    vector<vector<string>> input = parse(cin);
    vector<string> students = input[0];
    vector<string> assignments = input[1];
    vector<string> assignments_copy = assignments;

    srand(time(NULL));

    for (auto student = students.begin(); student < students.end(); student++) {
        if (assignments_copy.empty()) {
            assignments_copy = assignments;
        }

        int rand_value = rand();
        int idx = floor(((float) rand_value / (float) RAND_MAX) * (float) assignments_copy.size());
        cout << *student << " will present " << assignments_copy[idx] << endl;
        assignments_copy.erase(assignments_copy.begin() + idx);
    }
}
