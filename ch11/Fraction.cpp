#include "Fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

void Fraction::reduce() {
    for (int i = denominator; i > 1; i--) {
        if (numerator % i == 0 && denominator % i == 0) {
            numerator /= i;
            denominator /= i;

            break;
        }
    }
}

void Fraction::print() const {
    cout << numerator << "/" << denominator << endl;
}

Fraction Fraction::plus(const Fraction& other) const {
    Fraction sum(other.denominator * this->numerator + this->denominator * other.numerator, other.denominator * this->denominator);
    sum.reduce();
    return sum;
}

Fraction Fraction::minus(const Fraction& other) const {
    return this->plus(Fraction(-other.numerator, other.denominator));
}
