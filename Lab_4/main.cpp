#include <iostream>
#include <vector>
#include "rubik.h"
#include <string>
#include <array>

int main() {
    std::cout << "cin >> (manual input ? 1 : 0)\n";
    int mode;
    std::cin >> mode;
    if (mode){
        std::string steps;
        std::cin >> steps;
        Cube a;
        a.InputRotation(steps);
        a.FindSolution();
    } else {
        for (int i = 0; i < 100; ++i){
            std::cout << "\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << i
                      << " \n";
            Cube a;
            a.Generation();
            std::cout << (a.Status() ? "completed" : "uncompleted") << "\n";
            a.OutputFile("output.txt");
            a.FindSolution();
            std::cout << (a.Status() ? "\ncompleted" : "\nuncompleted") << "\n";
        }
    }

    return 0;
}
