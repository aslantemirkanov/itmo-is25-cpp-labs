#include "polynomial.h"

int main() {
    {
        //1. =
        std::cout << "Part 1\n";
        Polynomial first({{1, 2}, {0, 3.2}});
        Polynomial second;
        second = first;
        std::cout << "Test operator = " << second;
    }
    std::cout << "\n\nPart 2";
    {   //2. ==, !=
        Polynomial first({{1, 10}, {2, 11.5}});
        Polynomial second = first;
        Polynomial third({{1, 20}, {2, 50}});
        std::cout << "\ntest operator == " << first << " " << (second == first) << " " << second;
        std::cout << "\ntest operator != " << second << " " << (second == third) << " " << third  << "\n";
    }
    std::cout << "\nPart 3\n";
    {   //3. +, - (унарный и бинарный), +=, -=
        Polynomial first({{1, 10}, {2, 11.5}});
        Polynomial second = first;
        std::cout<<"Unary + and - operators  test:\nminus:\n";
        std::cout << first << "\n";
        first = -first;
        std::cout << first << "\n";
        std::cout << "Plus:\n";
        std::cout << second << "\n";
        second = +second;
        std::cout << second << "\n";
        std::cout << "Test += and -=:\n+= : \n";
        second += second;
        second += second;
        std::cout << "first = " << first << "  second = " << second << "\n";
        first += second;
        std::cout << "first += second = " << first << "\n-=:\n";
        std::cout << "first = " << first << "  second = " << second << "\n";
        first -= second;
        std::cout << "first -= second = " << first << "\n\n";

    }

    {   //4. * , / (на число), *=, /=
        std::cout << "Part 4\n";
        std::cout << "Test * and / operators by double type number\n";
        Polynomial first({{1, 10}, {2, 11.5}});
        std::cout << "first = " << first << "\n";
        std::cout << "first / 2 = " << first / 2 << "\n";
        std::cout << "\n Test *= and /= by double type number:\n";
        std::cout << first << "\n";
        std::cout << "first *= 3: \n";
        std::cout << first << "\n";
        std::cout << "first /= 2.5: \n";
        first /= 2.5;
        std::cout << first << "\n";
    }
    /*{
        //5. <<, >>
        std::cout << "\nOperation << was overloaded and it already tested in tests before \n";
        std::cout << "Test operator >> :\n";
        Polynomial first;
        std::cin >> first;
        std::cout << "Output: \n" << first << "\n";
    }*/


    {
        //6. [] (для получения коэффициента i-го члена)
        Polynomial first({{1, 10}, {2, 11.5}, {5,40}, {100001,200}});
        std::cout << "\nPart 6: \nTest [] operator: \n";
        std::cout << first << "\n";
        std::cout << "first[1] = " << first[1] << "\n";
        std::cout << "first[2] = " << first[2] << "\n";
        std::cout << "first[5] = " << first[5] << "\n";
        std::cout << "first[100001] = " << first[100001] << "\n";
    }

}
