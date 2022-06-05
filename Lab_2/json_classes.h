#ifndef LAB_2_JSON_CLASSES_H
#define LAB_2_JSON_CLASSES_H

#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Currency_Base {
public:
    std::vector <std::string> currencies_name =
            {"AUD", "AZN", "GBP", "AMD", "BYN", "BGN", "BRL",
             "HUF", "HKD", "DKK", "USD", "EUR", "INR", "KZT",
             "CAD", "KGS", "CNY", "MDL", "NOK", "PLN", "RON",
             "XDR", "SGD", "TJS", "TRY", "TMT", "UZS", "UAH",
             "CZK", "SEK", "CHF", "ZAR", "KRW", "JPY"};
};

class Currency {
private:
    std::string ID;
    std::string NumCode;
    std::string CharCode;
    double Nominal = 0;
    std::string Name;
    double Value = 0;
    double Previous = 0;
public:
    Currency() = default;

    Currency(const Currency &);

    Currency &operator=(const Currency &);

    friend std::ostream &operator<<(std::ostream &, const Currency &);

    friend std::vector <Currency> Parsing(const std::string &);

    double Get_Value() const;

    ~Currency() = default;
};

std::vector <Currency> Parsing(const std::string &);


class Archive {
private:
    std::vector <std::vector<Currency>> archive;
public:
    Archive() = default;

    Archive &push_back(const std::vector <Currency> &);

    void Median_Value() const;

    void Middle_Value() const;

    int Get_Size() const;
};


#endif
