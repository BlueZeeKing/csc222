#include "Point.h"
#include <format>

Point::Point() {
    x = 0.0;
    y = 0.0;
}

Point::Point(double x, double y) { 
    this->x = x;
    this->y = y;
}

Point Point::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
}

string Point::to_string() const {
    return format("({:6f}, {:6f})", x, y);
}
