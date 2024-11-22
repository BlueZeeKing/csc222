#include "Point.h"

Point::Point() {
    x = 0.0;
    y = 0.0;
}

Point::Point(double x, double y) { 
    this->x = x;
    this->y = y;
}

Point Point::operator+(const Point& other) {
    return Point(x + other.x, y + other.y);
}

string Point::to_string() const {
    return "";
}
