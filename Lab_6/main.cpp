#include <iostream>
#include <gtest/gtest.h>
#include "polynomial.h"


TEST(BasicTest, Test) {
    polynomial_1 a;
    std::cout << a;

    static const long long x = 3;
    static const long long res_1 = Count<polynomial_1::n, polynomial_1, x>::result;
    static_assert(res_1 == 30);

    ASSERT_EQ(res_1, 30);

    std::cout << "\nvalue in point x = " << x << " is same as " << res_1 << "\n";

    std::cout << "value is " << (IsPrime<res_1>::value ? "prime" : "not prime") << "\n";

    std::cout << "Min factorial not less than " << res_1 << " is " << MinFactorial<res_1>::value << "! = "
              << Factorial<MinFactorial<res_1>::value>::value << "\n";

    std::cout << "Min fibonacci number not less than " << res_1 << " is a_" << MinFibonacci<res_1>::result << " = "
              << Fibonacci<MinFibonacci<res_1>::result>::value;

    static const long long proizv = Derivative<polynomial_1::n, polynomial_1, res_1>::result;

    std::cout << "\nDerivative in point " << res_1 << " is ";

    for (int i = 0; i < polynomial_1::n - 1; ++i) {
        std::cout << "(" << polynomial_1::coefficients[i] << ")*(" << polynomial_1::powers[i] << ")*x^"
                  << polynomial_1::powers[i] - 1 << " + ";
    }

    std::cout << "(" << polynomial_1::coefficients[polynomial_1::n - 1] << ")*("
              << polynomial_1::powers[polynomial_1::n - 1] << ")*x^" << polynomial_1::powers[polynomial_1::n - 1] - 1;

    std::cout << " = " << proizv << "\n";

}

TEST(BasicTest2, Test2) {
    polynomial_2 b;
    std::cout << b;

    static const long long x = 2;
    static const long long res_2 = Count<polynomial_2::n, polynomial_2, x>::result;
    static_assert(res_2 == 13);

    ASSERT_EQ(res_2, 13);

    std::cout << "\nvalue in point x = " << x << " is same as " << res_2 << "\n";

    std::cout << "result is " << (IsPrime<res_2>::value ? "prime" : "not prime") << "\n";

    std::cout << "Min factorial not less than " << res_2 << " is " << MinFactorial<res_2>::value << "! = "
              << Factorial<MinFactorial<res_2>::value>::value << "\n";

    std::cout << "Min fibonacci number not less than " << res_2 << " is a_" << MinFibonacci<res_2>::result << " = "
              << Fibonacci<MinFibonacci<res_2>::result>::value;

    static const long long proizv_2 = Derivative<polynomial_2::n, polynomial_2, res_2>::result;

    std::cout << "\nDerivative in point " << res_2 << " is ";

    for (int i = 0; i < polynomial_2::n - 1; ++i) {
        std::cout << "(" << polynomial_2::coefficients[i] << ")*(" << polynomial_2::powers[i] << ")*x^"
                  << polynomial_2::powers[i] - 1 << " + ";
    }

    std::cout << "(" << polynomial_2::coefficients[polynomial_2::n - 1] << ")*("
              << polynomial_2::powers[polynomial_2::n - 1] << ")*x^" << polynomial_2::powers[polynomial_2::n - 1] - 1;

    std::cout << " = " << proizv_2 << "\n";
}

int main() {
    RUN_ALL_TESTS();
}