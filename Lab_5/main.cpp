#include "MyPool.h"
#include "Allocator.h"
#include <iostream>
#include <list>
#include <set>
#include <ctime>
#include <ratio>
#include <chrono>

int main() {

    MyAllAllocators all = {{sizeof(int),            1000},
                           {sizeof(std::list<char>), 1000}};






    MyAllocator<char> list_allocator(all);
    std::list<char,MyAllocator<char>> ls_1(list_allocator);

    using namespace std::chrono;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

        for (int i = 0; i < 500; ++i){
            ls_1.push_back('2');
        }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    std::cout << "It took me " << time_span.count() << " seconds.";
    std::cout << std::endl;


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    t1 = high_resolution_clock::now();
    std::list<char> ls_2;

    for (int i = 0; i < 500; ++i){
        ls_2.push_back('2');
    }

    t2 = high_resolution_clock::now();

    time_span = duration_cast<duration<double>>(t2 - t1);

    std::cout << "It took me " << time_span.count() << " seconds.";
    std::cout << std::endl;


    return 0;

}
