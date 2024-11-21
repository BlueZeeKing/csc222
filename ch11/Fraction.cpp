#include "Fraction.h"

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

Fraction Fraction::plus(const Fraction& other) const {
}
