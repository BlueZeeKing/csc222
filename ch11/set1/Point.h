struct Point {
    double x;
    double y;

    Point();
    Point(double, double);

    Point operator+(const Point&);
};
