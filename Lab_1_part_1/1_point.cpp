#include "1_point.h"

Point::Point() = default;

Point::Point(double x, double y)
    : x(x)
    , y(y)
    {}

Point::Point(const Point& copy)
    : x(copy.x)
    , y(copy.y)
    {}

void Point::print_point() const {
    std::cout << this->x << ' ' << this->y << '\n';
}

Point &Point::operator=(const Point& other) {
    if (&other == this){
        return *this;
    }
    x = other.x;
    y = other.y;
    return *this;
}

double Point::get_x() const {
    return x;
}

double Point::get_y() const {
    return y;
}
