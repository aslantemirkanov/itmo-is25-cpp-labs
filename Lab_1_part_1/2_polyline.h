#pragma once
#include "1_point.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

class Polyline{
protected:
    int size = 0;
    Point* point_array = nullptr;
public:
    Polyline(const std::initializer_list<Point>&);
    Polyline(const Polyline&);
    Polyline& operator=(const Polyline&);
    virtual double perimeter() const;
    virtual int get_count() const;
    ~Polyline();
};
