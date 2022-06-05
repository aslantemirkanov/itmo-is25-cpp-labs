#pragma once
#include "4_polygon.h"
class Triangle: public Polygon{
public:
    Triangle(const std::initializer_list<Point>&);
    Triangle(const Triangle&);
    Triangle& operator=(const Triangle&);
    ~Triangle();
};
