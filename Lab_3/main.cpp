#include <iostream>
#include <vector>
#include "Circular_buffer.h"
#include <algorithm>
#include "algorithms.h"

bool is_parity(int a) {
    return a % 2 == 0;
}

bool check_sort(Iterator<char> first, Iterator<char> second){
    return first < second;
}

bool partition(int a) {
    return a > 6;
}

int main() {
    //circular_buffer test
    //std::sort;
    circular_buffer<char> test(10);
    test.push_back(5);
    test.push_back(4);
    test.push_back(2);
    test.push_back(6);
    test.push_back(11);
    test.push_back(24);
    test.push_back(14);
    test.push_back(10);
    test.push_back(73);
    test.push_back(35);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_front(21);
    test.push_front(22);
    test.push_front(42);
    test.push_front(85);
    test.pop_front();
    test.pop_back();
    test.pop_back();
    test.pop_back();
    std::cout << "Before sorting\n";
    for (auto i: test) {
        std::cout << (int) i << " ";
    }
    std::cout << "\nSorted:\n";
    std::sort(test.begin(), test.end());
    for (auto i: test) {
        std::cout << (int) i << " ";
    }
    std::cout << "\n";
    //std::find
    int value = test[3];
    Iterator<char> res = std::find(test.begin(), test.end(), value);
    std::cout << "Index of first element " << value << " is " << res.get_index();
    std::cout << "\nResized from 10 to 20\n";
    test.resize(20);
    for (auto i: test) {
        std::cout << (int) i << " ";
    }
    std::cout << "\n";
    //algo test
    std::cout << "\nalgo test:\n";
    //all_of
    std::cout << "\nmy_all_of - " << my_all_of(test.begin(), test.end(), is_parity);
    std::cout << "\nstd::all_of - " << std::all_of(test.begin(), test.end(), is_parity);
    //any_of
    std::cout << "\n\nmy_any_of - " << my_any_of(test.begin(), test.end(), is_parity);
    std::cout << "\nstd::any_of - " << std::any_of(test.begin(), test.end(), is_parity);
    //none_of
    std::cout << "\n\nmy_none_of - " << my_none_of(test.begin(), test.end(), is_parity);
    std::cout << "\nstd::none_of - " << std::none_of(test.begin(), test.end(), is_parity);
    //one_of
    std::cout << "\n\nmy_one_of - " << my_one_of(test.begin(), test.end(), is_parity);
    //is_sorted
    std::cout << "\n\nmy_is_sorted - " << my_is_sorted(test.begin(), test.end(), check_sort);
    std::cout << "\nis_sorted - " << std::is_sorted(test.begin(), test.end());
    //is_partitioned
    std::cout << "\n\nmy_is_partitioned - " << my_is_partitioned(test.begin(), test.end(), partition);
    std::cout << "\nis_partitioned - " << std::is_partitioned(test.begin(), test.end(), partition);
    //my_find_not
    {
        Iterator<char> cur = test.begin();
        Iterator<char> res_my_find = my_find_not(test.begin(), test.end(), *cur);
        std::cout << "\n\nmy_find_not - " << (int) *res_my_find << " index - " << res_my_find.get_index();
    }
    //my_find_backward
    {
        Iterator<char> cur = test.begin();
        Iterator<char> res_my_backward = my_find_backward(test.begin(), test.end(), *cur);
        std::cout << "\n\nmy_find_not - " << (int) *res_my_backward << " index - " << res_my_backward.get_index();
    }

    return 0;
}
