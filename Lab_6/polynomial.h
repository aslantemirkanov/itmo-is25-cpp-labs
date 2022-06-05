#ifndef META_PROGRAMMING_POLYNOMIAL_H
#define META_PROGRAMMING_POLYNOMIAL_H

struct polynomial_1 {
    static const long long n = 3;
    static constexpr std::array<long long, n> coefficients = {1, 4, -1};
    static constexpr std::array<long long, n> powers = {1, 3, 4};

    friend std::ostream &operator<<(std::ostream &out, const polynomial_1 &pol) {
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                if (powers[i] == 0) out << coefficients[i];
                else out << coefficients[i] << "*x^" << powers[i];
            } else {
                if (powers[i] == 0) {
                    if (coefficients[i] >= 0) out << " + " << coefficients[i];
                    if (coefficients[i] >= 0) out << " - " << coefficients[i];
                } else {
                    if (coefficients[i] >= 0) out << " + " << coefficients[i] << "*x^" << powers[i];
                    else out << " - " << -coefficients[i] << "*x^" << powers[i];
                }
            }
        }
        return out;
    }
};

struct polynomial_2 {
    static const long long n = 3;
    static constexpr std::array<long long, n> coefficients = {1, 1, 1};
    static constexpr std::array<long long, n> powers = {0, 2, 3};

    friend std::ostream &operator<<(std::ostream &out, const polynomial_2 &pol) {
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                if (powers[i] == 0) out << coefficients[i];
                else out << coefficients[i] << "*x^" << powers[i];
            } else {
                if (powers[i] == 0) {
                    if (coefficients[i] >= 0) out << " + " << coefficients[i];
                    if (coefficients[i] >= 0) out << " - " << coefficients[i];
                } else {
                    if (coefficients[i] >= 0) out << " + " << coefficients[i] << "*x^" << powers[i];
                    else out << " - " << coefficients[i] << "*x^" << powers[i];
                }
            }
        }
        return out;
    }
};

template<long long power, long long point>
struct Power {
public:
    static const long long value = point * Power<power - 1, point>::value;
};

template<long long point>
struct Power<0, point> {
public:
    static const long long value = 1;
};

template<long long point>
struct Power<-1, point> {
public:
    static const long long value = 0;
};

template<long long count, class new_pol, long long point>
struct Count {
    static const long long result =
            new_pol::coefficients[count - 1] * Power<new_pol::powers[count - 1], point>::value +
            Count<count - 1, new_pol, point>::result;
};

template<class new_pol, long long point>
struct Count<0, new_pol, point> {
    static const long long result = 0;
};

template<long long n>
struct Fibonacci {
    static const long long value = Fibonacci<n - 1>::value + Fibonacci<n - 2>::value;
};

template<>
struct Fibonacci<0> {
    static const long long value = 0;
};

template<>
struct Fibonacci<1> {
    static const long long value = 1;
};

template<long long cmp, long long n = 1>
struct MinFibonacci {
    static const long long result = cmp <= Fibonacci<n>::value ? n : MinFibonacci<cmp, n + 1>::result;
};

template<long long cmp>
struct MinFibonacci<cmp, 90> {
    static const long long result = 0;
};

template<long long n>
struct Factorial {
    static const long long value = n * Factorial<n - 1>::value;
};

template<>
struct Factorial<1> {
    static const long long value = 1;
};

template<long long cmp, long long n = 1>
struct MinFactorial {
    static const long long value = (cmp <= Factorial<n>::value ? n : MinFactorial<cmp, n + 1>::value);
};

template<long long cmp>
struct MinFactorial<cmp, 20> {
    static const long long value = 0;
};

template<long long n, long long left = 1, long long right = n>
struct Root {
    static const long long middle = (left + right) / 2;
    static const bool down = ((middle * middle) >= n);
    static const long long result =
            Root<n, (down ? left : middle + 1), (down ? middle : right)>::result;
};

template<long long n, long long middle>
struct Root<n, middle, middle> {
    static const long long result = middle;
};

template<long long n, long long d, long long root_value>
struct IsPrimeHelper {
    static const bool value = n % d != 0 && IsPrimeHelper<n, d - 1, root_value>::value;
};

template<long long n, long long root_value>
struct IsPrimeHelper<n, root_value, root_value> {
    static const bool value = n % root_value != 0;
};

template<size_t n>
struct IsPrime {
    static const bool value = IsPrimeHelper<n, n - 1, Root<n>::result>::value;
};

template<>
struct IsPrime<1> {
    static const bool value = false;
};

template<long long count, class new_pol, long long point>
struct Derivative {
    static const long long result =
            new_pol::coefficients[count - 1] * new_pol::powers[count - 1] *
            Power<new_pol::powers[count - 1] - 1, point>::value +
            Derivative<count - 1, new_pol, point>::result;
};

template<class new_pol, long long point>
struct Derivative<0, new_pol, point> {
    static const long long result = 1;
};


#endif //META_PROGRAMMING_POLYNOMIAL_H
