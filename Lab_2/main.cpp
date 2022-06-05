#include "curl_class.h"
#include <ctime>
#include <nlohmann/json.hpp>
#include "json_classes.h"
#include <thread>
#include <cmath>

//main.cpp curl_class.h json_classes.cpp json_classes.h -std=c++17 -lcurl -pthread -lglfw -lGLEW -lGL -lGLU

bool interrupt_flag = false;

using json = nlohmann::json;

void Counting(std::vector <Currency> &res_pars, Archive &global_archive) {

    while (true) {
        Curl a;

        a.Get_Data_From("https://www.cbr-xml-daily.ru/daily_json.js");

        res_pars = Parsing(a.Get_Str());

        global_archive.push_back(res_pars);

        //вывод резлультата
        for (int i = 0; i < res_pars.size(); ++i) {
            std::cout << res_pars[i];
        }

        std::cout << global_archive.Get_Size() << "\n\n\n";

        //отсчет 10 секунд
        time_t actual_time;
        time(&actual_time);
        time_t gone_time = actual_time;

        while (actual_time - gone_time != 10) {
            time(&actual_time);
        }
        if (interrupt_flag) break;

        std::cout << "\n\n\n\n\n\n\n";
        system("clear");
    }

}

void After_Interrupt(Archive &global_archive) {
    char indicator = getchar();
    if (indicator == 'f' || indicator == 'F') {
        char a;
        interrupt_flag = true;
        std::cout << "If you wanna median_value input 1\n";
        std::cout << "If you wanna middle_value input 2\n";
        std::cout << "If you wanna median_value and middle_value input 3\n";
        // std::cout << "If you wanna graphic of USD input 4\n";
        std::cin >> a;
        if (a == '1') {
            global_archive.Median_Value();
        } else if (a == '2') {
            global_archive.Middle_Value();
        } else if (a == '3') {
            global_archive.Median_Value();
            std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
            global_archive.Middle_Value();
            /*}else if (a == '4'){
               Make_Graphic(global_archive);*/
        } else {
            std::cout << "Oops!!!";
        }
        exit(1);
    }
}

int main() {

    std::vector <Currency> res_pars;
    Archive global_archive;

    std::thread threadFirst(Counting, std::ref(res_pars), std::ref(global_archive));
    std::thread threadSecond(After_Interrupt, std::ref(global_archive));

    threadFirst.join();
    threadSecond.join();

    return 0;
}

