struct Fraction {
    int numerator;
    int denominator;

    Fraction();
    Fraction(int, int);

    void reduce();

    Fraction plus(const Fraction&) const;
};
