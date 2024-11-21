struct Fraction {
    int numerator;
    int denominator;

    Fraction();
    Fraction(int, int);
    Fraction plus(const Fraction&) const;
};
