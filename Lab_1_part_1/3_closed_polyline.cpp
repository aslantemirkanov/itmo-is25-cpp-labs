#include "3_closed_polyline.h"

Close_polyline::Close_polyline(const std::initializer_list<Point> &other_point_array)
    : Polyline(other_point_array) {}

Close_polyline::Close_polyline(const Close_polyline &other_close_polyline)
        : Polyline(other_close_polyline) {}

Close_polyline &Close_polyline::operator=(const Close_polyline &other_close_polyline) {
    if (this == &other_close_polyline) {
        return *this;
    }
    size = other_close_polyline.size;
    delete[] point_array;
    point_array = new Point[size];
    std::copy(&other_close_polyline.point_array[0], &other_close_polyline.point_array[other_close_polyline.size], point_array);
    return *this;
}

Close_polyline::~Close_polyline() {
    delete[] point_array;
}

double Close_polyline::perimeter() const  {
    double length =  Polyline::perimeter();
    length +=  sqrt(pow(point_array[0].get_x() - point_array[size - 1].get_x(), 2)
                    + pow(point_array[0].get_y() - point_array[size - 1].get_y(), 2));
    return length;
}

