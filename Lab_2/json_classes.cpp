#include "json_classes.h"


Currency::Currency(const Currency &other)
        : ID(other.ID), NumCode(other.NumCode), CharCode(other.CharCode), Nominal(other.Nominal), Name(other.Name),
          Value(other.Value), Previous(other.Previous) {}

Currency &Currency::operator=(const Currency &other) {
    if (&other == this) {
        return *this;
    }
    ID = other.ID;
    NumCode = other.NumCode;
    CharCode = other.CharCode;
    Nominal = other.Nominal;
    Name = other.Name;
    Value = other.Value;
    Previous = other.Previous;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Currency &out_currency) {
    out << out_currency.CharCode << " " << out_currency.Value << "\n";
    return out;
}

std::vector <Currency> Parsing(const std::string &for_parsing) {
    Currency_Base Base;
    std::vector <Currency> res_parsing(Base.currencies_name.size());
    auto part1 = json::parse(for_parsing);

    for (int i = 0; i < Base.currencies_name.size(); ++i) {
        res_parsing[i].ID = part1["Valute"][Base.currencies_name[i]]["ID"].get<std::string>();
        res_parsing[i].NumCode = part1["Valute"][Base.currencies_name[i]]["NumCode"].get<std::string>();
        res_parsing[i].CharCode = part1["Valute"][Base.currencies_name[i]]["CharCode"].get<std::string>();
        res_parsing[i].Nominal = part1["Valute"][Base.currencies_name[i]]["Nominal"].get<double>();
        res_parsing[i].Name = part1["Valute"][Base.currencies_name[i]]["Name"].get<std::string>();
        res_parsing[i].Value = part1["Valute"][Base.currencies_name[i]]["Value"].get<double>();
        res_parsing[i].Previous = part1["Valute"][Base.currencies_name[i]]["Previous"].get<double>();
    }
    return res_parsing;
}

double Currency::Get_Value() const {
    return Value;
}

Archive &Archive::push_back(const std::vector <Currency> &res_parse) {
    archive.push_back(res_parse);
    return *this;
}

void Archive::Median_Value() const {
    Currency_Base Base;
    for (int i = 0; i < Base.currencies_name.size(); ++i) {
        std::vector<double> cur_valute_values(archive.size());
        for (int j = 0; j < archive.size(); ++j) {
            cur_valute_values[j] = archive[j][i].Get_Value();
        }
        std::sort(cur_valute_values.begin(), cur_valute_values.end());
        if (cur_valute_values.size() % 2 == 0) {
            std::cout << Base.currencies_name[i] << " median_value = "
                      << cur_valute_values[cur_valute_values.size() / 2] << "\n";
        } else if (archive.size() != 1) {
            int mid = cur_valute_values.size() / 2;
            double median = (cur_valute_values[mid] + cur_valute_values[mid - 1]) / 2;
            std::cout << Base.currencies_name[i] << " median_value = " << median << "\n";
        } else {
            std::cout << Base.currencies_name[i] << " median_value = " << archive[0][i].Get_Value() << "\n";
        }
    }


}

void Archive::Middle_Value() const {
    Currency_Base Base;
    for (int i = 0; i < Base.currencies_name.size(); ++i) {
        double sum = 0;
        for (int j = 0; j < archive.size(); ++j) {
            sum += archive[j][i].Get_Value();
        }
        double res = (sum / archive.size());
        std::cout << Base.currencies_name[i] << " middle_value = " << res << "\n";
    }
}

int Archive::Get_Size() const {
    return archive.size();
}
