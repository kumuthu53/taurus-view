//
// Created by kumuthu on 6/02/23.
//

#include <iostream>
#include <fstream>

#include "../../dependencies/fast-cpp-csv-parser/csv.h"

#include "../../include/Currencies.h"
#include "../../include/Currency.h"

Currencies::Currencies() {

    currencies = std::vector<Currency>();

    std::string source_path = __FILE__;

    std::string csv_path = source_path.substr(0, source_path.rfind("/") + 1) +
            "../../config/currency_list.csv";

    io::CSVReader<2> in(csv_path);

    in.read_header(io::ignore_extra_column, "currency code", "currency name");

    std::string code;
    std::string name;

    while (in.read_row(code , name)) {
        Currency currency(code, name);
        currencies.push_back(currency);
    }

}

void Currencies::print_codes() const {

    int number = currencies.size();

    std::cout << std::string(5, ' ');

    for (int count = 0; count < number; count++) {
        currencies[count].print_code();

        if ((count + 1) % 17) {
            std::cout << " ";
        }
        else {
            std::cout << std::endl;
            std::cout << std::string(5, ' ');
        }
    }

}

const std::vector<Currency> &Currencies::getCurrencies() const {
    return currencies;
}
