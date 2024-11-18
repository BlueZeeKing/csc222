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
    vector<string> students_copy = students;

    srand(time(NULL));

    for (string assignment : assignments) {
        if (students_copy.empty()) {
            students_copy = students;
        }

        int idx = rand() % students_copy.size();
        cout << students_copy[idx] << " will present " << assignment << endl;
        students_copy.erase(students_copy.begin() + idx);
    }
}
