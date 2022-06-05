#pragma once
#include "4_polygon.h"

class Trapezoid : public Polygon{
private:
    bool is_trapezoid;
public:
    Trapezoid(const std::initializer_list<Point>&);
    Trapezoid(const Trapezoid&);
    Trapezoid& operator=(const Trapezoid&);
    bool trapezoid_check();
    ~Trapezoid();
};