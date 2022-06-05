#pragma once
#include "2_polyline.h"

class Close_polyline: public Polyline{
public:
    Close_polyline(const std::initializer_list<Point>&);
    Close_polyline(const Close_polyline&);
    Close_polyline& operator=(const Close_polyline&);
    double perimeter() const override;
    ~Close_polyline();
};