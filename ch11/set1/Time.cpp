#include "Time.h"
#include <format>
#include <cmath>
using namespace std;

Time::Time(int secs) {
    this->seconds = secs;

    minutes = seconds / 60;
    seconds %= 60;

    hours = minutes / 60;
    minutes %= 60;
}

Time::Time() {
    this->seconds = 0;
    this->minutes = 0;
    this->hours = 0;
}

string Time::to_string() const {
    return format("{}:{:02}:{:02}", hours, minutes, seconds);
}
