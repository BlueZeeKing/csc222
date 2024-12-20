#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    cout << "Enter a list of numbers separated by spaces press enter to complete:" << endl;

    string input_line;
    getline(cin, input_line);

    vector<int> nums;
    int num = 0;
    bool is_negative = false;

    for(string::iterator value = input_line.begin(); value != input_line.end(); value++) {
        if (*value == ' ') {
            if (is_negative) {
                num *= -1;
            }
            nums.push_back(num);

            num = 0;
            is_negative = false;
        } if (*value == '-' && (value == input_line.begin() || *(value - 1) == ' ')) {
            is_negative = true; 
        } else if (*value >= '0' && *value <= '9') {
            num *= 10;
            num += *value - '0';
        }
    }

    if (is_negative) {
        num *= -1;
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
