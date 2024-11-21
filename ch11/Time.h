struct Time {
    int hour = 0; 
    int minute = 0;
    double second = 0.0;

    Time(double);
    Time(int, int, double);

    void print() const;
    void increment(double);
    double convert_to_seconds() const;
    bool after(const Time&) const;
    Time add(const Time&) const;
};
