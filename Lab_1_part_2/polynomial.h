#pragma once
#include <iostream>
#include <map>

class Polynomial{
private:
    std::map <int, double> coefficient;
    friend std::ostream& operator<<(std::ostream &, const Polynomial&);
    friend std::istream& operator>>(std::istream &, Polynomial&);
public:
    Polynomial()= default;
    explicit Polynomial(const std::map<int, double>&);
    Polynomial(const Polynomial&);
    Polynomial& operator=(const Polynomial&);
    bool operator==(const Polynomial&);
    bool operator!=(const Polynomial&);
    Polynomial operator+();
    Polynomial operator-();
    Polynomial& operator+=(const Polynomial&);
    Polynomial& operator-=(const Polynomial&);
    Polynomial& operator*=(const double&);
    Polynomial& operator/=(const double&);
    Polynomial operator+(const Polynomial&);
    Polynomial operator-(const Polynomial&);
    Polynomial operator*(const Polynomial&);
    Polynomial operator/(const double&);
    double operator[](int);
};

