#include "polynomial.h"
#include <iterator>


Polynomial::Polynomial(const std::map<int, double> &new_coefficients) {
    coefficient = new_coefficients;
}

Polynomial::Polynomial(const Polynomial &other_polynomial) {
    coefficient = other_polynomial.coefficient;
}

Polynomial &Polynomial::operator=(const Polynomial &other_polynomial) {
    if (this == &other_polynomial) {
        return *this;
    }
    coefficient = other_polynomial.coefficient;
    return *this;
}

bool Polynomial::operator==(const Polynomial &other_polynomial) {
    bool equal = true;
    for (auto &key: coefficient) {
        if (other_polynomial.coefficient.find(key.first)->second != coefficient[key.first]) {
            equal = false;
        }
    }
    return equal;
}

bool Polynomial::operator!=(const Polynomial &other_polynomial) {
    return !(*this == other_polynomial);
}

Polynomial Polynomial::operator+() {
    Polynomial copy = *this;
    return copy;
}

Polynomial Polynomial::operator-() {
    Polynomial copy = *this;
    for (auto &key: coefficient) {
        copy.coefficient[key.first] = -coefficient[key.first];
    }
    return copy;
}

Polynomial &Polynomial::operator+=(const Polynomial &other_polynomial) {
    for (auto key: other_polynomial.coefficient) {
        coefficient[key.first] += key.second;
    }
    return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &other_polynomial) {
    for (auto key: other_polynomial.coefficient) {
        coefficient[key.first] -= key.second;
    }
    return *this;
}

Polynomial &Polynomial::operator*=(const double &multiplier) {
    for (auto key: this->coefficient) {
        coefficient[key.first] *= multiplier;
    }
    return *this;
}

Polynomial &Polynomial::operator/=(const double &divider) {
    if (divider == 0) {
        throw std::logic_error("Division by zero");
    }
    for (auto key: this->coefficient) {
        coefficient[key.first] /= divider;
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial &add) {
    Polynomial copy = *this;
    copy += add;
    return copy;
}

Polynomial Polynomial::operator-(const Polynomial &add) {
    Polynomial copy = *this;
    copy -= add;
    return copy;
}

Polynomial Polynomial::operator*(const Polynomial &multiplier) {
    Polynomial copy;
    for (auto key_first: this->coefficient) {
        for (auto key_second: multiplier.coefficient) {
            if (double temp_value = key_first.second * key_second.second; temp_value != 0) {
                copy.coefficient[key_first.first + key_second.first] = temp_value;
            }
        }
    }
    return copy;
}

Polynomial Polynomial::operator/(const double &divider) {
    if (divider == 0) {
        throw std::logic_error("Division by zero");
    }
    Polynomial copy = *this;
    copy /= divider;
    return copy;
}

double Polynomial::operator[](int index) {
    return coefficient[index];
}

std::ostream &operator<<(std::ostream &out, const Polynomial &polynomial) {
    int iter = 0;
    for (auto key: polynomial.coefficient) {
        if (iter == 0) {
            if (key.first == 0) out << key.second;
            else out << key.second << "*x^" << key.first;
            iter++;
        } else {
            if (key.first == 0) {
                if (key.second >= 0) out << " + " << key.second;
                else out << " - " << std::abs(key.second);
            } else {
                if (key.second >= 0) out << " + " << key.second << "*x^" << key.first;
                else out << " - " << std::abs(key.second) << "*x^" << key.first;
            }
        }
    }
    return out;
}

std::istream &operator>>(std::istream &in, Polynomial &polynomial) {
    int item_count;
    std::cout << " Input polynomial's item count: ";
    in >> item_count;
    for (int i = 0; i < item_count; ++i) {
        int degree, coefficient;
        std::cout << "Input degree: ";
        in >> degree;
        std::cout << "Input coefficient: ";
        in >> coefficient;
        polynomial.coefficient[degree] = coefficient;
    }
    return in;
}
