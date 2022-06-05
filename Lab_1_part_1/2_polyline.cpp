#include "2_polyline.h"

Polyline::Polyline(const std::initializer_list<Point> &other_point_array)
        : size(other_point_array.size())
        , point_array(new Point[size]) {
    std::copy(other_point_array.begin(), other_point_array.end(), point_array);
}

Polyline::Polyline(const Polyline &other_polyline) {
    size = other_polyline.size;
    point_array = new Point[size];
    std::copy(&other_polyline.point_array[0], &other_polyline.point_array[other_polyline.size], point_array);
}

Polyline &Polyline::operator=(const Polyline &other_polyline) {
    if (this == &other_polyline) {
        return *this;
    }
    size = other_polyline.size;
    delete[] point_array;
    point_array = new Point[size];
    std::copy(&other_polyline.point_array[0], &other_polyline.point_array[other_polyline.size], point_array);
    return *this;
}

Polyline::~Polyline() {
    delete[] point_array;
}

double Polyline::perimeter() const {
    double polyline_length = 0;
    if (size == 0) return 0;
    for (int i = 1; i < size; ++i) {
        polyline_length += sqrt(pow(point_array[i - 1].get_x() - point_array[i].get_x(), 2)
                                + pow(point_array[i - 1].get_y() - point_array[i].get_y(), 2));
    }
    return polyline_length;
}

int Polyline::get_count() const {
    return size;
}

