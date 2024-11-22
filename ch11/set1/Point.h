#include <string>
using namespace std;

struct Point {
    double x;
    double y;

    Point();
    Point(double, double);

    Point operator+(const Point&);
    string to_string() const;
};
