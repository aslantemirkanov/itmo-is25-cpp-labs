#include "5_triangle.h"


Triangle::Triangle(const std::initializer_list<Point> &other_point_array)
    : Polygon(other_point_array){}

Triangle::Triangle(const Triangle &other_triangle)
    : Polygon(other_triangle) {}


Triangle &Triangle::operator=(const Triangle& copy) {
    if (this == &copy) {
        return *this;
    }
    size = copy.size;
    delete[] point_array;
    point_array = new Point[size];
    std::copy(&copy.point_array[0], &copy.point_array[copy.size], point_array);
    return *this;
}

Triangle::~Triangle() {
    delete[] point_array;
}


