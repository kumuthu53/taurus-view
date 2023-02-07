//
// Created by kumuthu on 5/02/23.
//

#include "../../../include/ConvertInput.h"

ConvertInput::ConvertInput(const std::string &from_symbol, const std::string &to_symbol, double amount) {
    this->from_symbol = from_symbol;
    this->to_symbol = to_symbol;
    this->amount = amount;
}

ConvertInput::ConvertInput() {
    amount = 0;
}

const std::string &ConvertInput::get_from_symbol() const {
    return from_symbol;
}

const std::string &ConvertInput::get_to_symbol() const {
    return to_symbol;
}

double ConvertInput::get_amount() const {
    return amount;
}

void ConvertInput::set_from_symbol(const std::string &from_symbol) {
    this->from_symbol = from_symbol;
}

void ConvertInput::set_to_symbol(const std::string &to_symbol) {
    this->to_symbol = to_symbol;
}

void ConvertInput::set_amount(double amount) {
    ConvertInput::amount = amount;
}

