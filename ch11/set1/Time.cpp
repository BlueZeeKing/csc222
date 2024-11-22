#include "Time.h"
#include <format>
#include <cmath>
using namespace std;

Time::Time(int hrs, int mins, int secs) {
    hours = hrs;
    minutes = mins;
    seconds = secs;
}

Time::Time(int hrs, int mins) {
    hours = hrs;
    minutes = mins;
}

Time::Time(int secs) {
    seconds = secs;

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

Time Time::operator+(const Time&) {
    return Time();
}
