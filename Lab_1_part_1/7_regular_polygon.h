#pragma once
#include "4_polygon.h"
#include "cmath"

class Regular_polygon : public Polygon{
public:
    Regular_polygon(const std::initializer_list<Point>&);
    Regular_polygon(const Regular_polygon&);
    Regular_polygon& operator=(const Regular_polygon&);
    double perimeter() const override;
    double square() const override;
    ~Regular_polygon();
};