#pragma once
#include <iostream>

class Point {
private:
    double x = 0.0;
    double y = 0.0;
public:
    Point();
    explicit Point(double, double);
    Point(const Point&);
    void print_point() const;
    Point& operator=(const Point&);
    double get_x() const;
    double get_y() const;
};