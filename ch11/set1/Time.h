#include <string>
using namespace std;

struct Time {
    int seconds;
    int minutes;
    int hours;

    Time(int, int, int);    
    Time(int, int);    
    Time(int);    
    Time();    

    string to_string() const;

    Time operator+(const Time&) const;
};

ostream& operator<<(ostream&, const Time&);
