#include "Time.h"    
#include <cmath>
#include <iostream>
using namespace std;

Time::Time(double secs) {
    this->increment(secs);
}

Time::Time(int hours, int minutes, double seconds) {
    this->hour = hours;
    this->minute = minutes;
    this->second = seconds;
}

void Time::print() const {
    cout << hour << ":" << minute << ":" << second << endl;
}

void Time::increment(double secs) {
    second += secs;

    int additional_minutes = floor(second / 60.0);
    second -= additional_minutes * 60.0;
    minute += additional_minutes;

    hour += minute / 60;
    minute %= 60;
}

double Time::convert_to_seconds() const {
    return second + (minute + hour * 60.0) * 60.0;
}

bool Time::after(const Time& other) const {
    return this->convert_to_seconds() > other.convert_to_seconds();
}

Time Time::add(const Time& other) const {
    return Time(this->convert_to_seconds() + other.convert_to_seconds());
}
