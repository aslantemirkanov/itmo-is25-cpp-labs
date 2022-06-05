#include "7_regular_polygon.h"

Regular_polygon::Regular_polygon(const std::initializer_list<Point> &other_point_array)
    : Polygon(other_point_array) {}

Regular_polygon::Regular_polygon(const Regular_polygon &other_point_array)
    : Polygon(other_point_array) {}

Regular_polygon &Regular_polygon::operator=(const Regular_polygon &copy) {
    if (this == &copy) {
        return *this;
    }
    size = copy.size;
    delete[] point_array;
    point_array = new Point[size];
    std::copy(&copy.point_array[0], &copy.point_array[copy.size], point_array);
    return *this;
}


double Regular_polygon::perimeter() const {
    double perimeter_length = 0;
    if (size == 0) return 0;
    perimeter_length = sqrt(pow(point_array[0].get_x() - point_array[size - 1].get_x(), 2)
                                + pow(point_array[0].get_y() - point_array[size - 1].get_y(), 2));
    perimeter_length *= this->get_count();
    return perimeter_length;
}

double Regular_polygon::square() const {
    double side = sqrt(pow(point_array[0].get_x() - point_array[size - 1].get_x(), 2)
                       + pow(point_array[0].get_y() - point_array[size - 1].get_y(), 2));
    double square_result = (this->get_count() / 4.0) * side * side * 1.0 / tan(M_PI / this->get_count());
    return square_result;
}


Regular_polygon::~Regular_polygon() {
    delete[] point_array;
}