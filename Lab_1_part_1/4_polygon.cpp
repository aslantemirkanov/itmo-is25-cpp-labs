#include "4_polygon.h"

Polygon::Polygon(const std::initializer_list<Point>  &point_array)
    : Close_polyline(point_array){}

Polygon::Polygon(const Polygon &other_polygon)
    : Close_polyline(other_polygon){}

Polygon &Polygon::operator=(const Polygon& copy){
    if (this == &copy) {
        return *this;
    }
    size = copy.size;
    delete[] point_array;
    point_array = new Point[size];
    std::copy(&copy.point_array[0], &copy.point_array[copy.size], point_array);
    return *this;
}

double Polygon::square() const{
    double square = point_array[size - 1].get_x() * point_array[0].get_y() -  point_array[size - 1].get_y() * point_array[0].get_x();
    for (int i = 0; i < size - 1; ++i){
        square += point_array[i].get_x() * point_array[i + 1].get_y() -  point_array[i].get_y() * point_array[i + 1].get_x();
    }
    return (square > 0) ? square * 0.5 : -square * 0.5;
}

Polygon::~Polygon() {
    delete[] point_array;
    }

