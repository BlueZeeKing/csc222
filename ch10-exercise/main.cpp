#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    cout << "Enter a list of numbers separated by spaces press enter to complete:" << endl;

    string input_line;
    getline(cin, input_line);

    const char* raw_line = input_line.c_str();

    vector<int> nums;
    int num = 0;

    while(*raw_line != '\0') {
        if (*raw_line == ' ') {
            nums.push_back(num);
            num = 0;
        } else {
            num *= 10;
            num += *raw_line - '0';
        }

        raw_line++;
    }
    nums.push_back(num);

    cout << "\nYou entered: ";
    for (vector<int>::iterator value = nums.begin(); value != nums.end(); value++) {
        cout << *value << " ";
    }
    cout << endl;

    cout << "\nYou entered in reverse: ";
    for (vector<int>::iterator value = nums.end() - 1; value != nums.begin() - 1; value--) {
        cout << *value << " ";
    }
    cout << endl;
}
