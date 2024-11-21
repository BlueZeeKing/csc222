#include "Fraction.h"

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

Fraction Fraction::plus(const Fraction& other) const {
    Fraction sum(other.denominator * this->numerator + this->denominator * other.numerator, other.denominator * this->denominator);
    sum.reduce();
    return sum;
}