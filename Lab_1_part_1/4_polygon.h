#pragma once
#include "3_closed_polyline.h"

class Polygon: public Close_polyline{
public:
    Polygon(const std::initializer_list<Point>&);
    Polygon(const Polygon&);
    Polygon& operator=(const Polygon&);
    virtual double square() const;
    ~Polygon();
};