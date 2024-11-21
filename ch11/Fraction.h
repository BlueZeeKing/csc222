struct Fraction {
    int numerator;
    int denominator;

    Fraction();
    Fraction(int, int);

    void reduce();

    void print() const;
    Fraction plus(const Fraction&) const;
    Fraction minus(const Fraction&) const;
};
