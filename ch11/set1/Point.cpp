#include "Point.h"

Point::Point() {
    x = 0.0;
    y = 0.0;
}

Point::Point(double x, double y) { 
    this->x = x;
    this->y = y;
}

Point Point::operator+(const Point&) {
    return Point();
}