#include <string>
using namespace std;

struct Time {
    int seconds;
    int minutes;
    int hours;

    Time(int);    
    Time();    

    string to_string() const;
};
