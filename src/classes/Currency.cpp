//
// Created by kumuthu on 6/02/23.
//

#include <iostream>

#include "../../include/Currency.h"


void Currency::print_name() const {

    std::string to_print = name;

    if (name_size() > 29) {
        to_print = name.substr(0, 26) + std::string(3, '.');
    }

    std::cout << to_print;

}

bool Currency::equals(std::string code) const {

    if (code == this->code) {
        return true;
    }
    else {
        return false;
    }

}

size_t Currency::name_size() const {
    return name.length();
}

Currency::Currency(const std::string &code, const std::string &name) {
    this->code = code;
    this->name = name;
}

void Currency::print_code() const {
    std::cout << code;
}

const std::string &Currency::get_code() const {
    return code;
}

const std::string &Currency::get_name() const {
    return name;
}


