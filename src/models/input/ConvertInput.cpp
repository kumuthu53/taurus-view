//
// Created by kumuthu on 5/02/23.
//

#include "../../../include/ConvertInput.h"

ConvertInput::ConvertInput(const std::string &from_symbol, const std::string &to_symbol, double amount) {
    this->from_symbol = from_symbol;
    this->to_symbol = to_symbol;
    this->amount = amount;
}

const std::string &ConvertInput::getFromSymbol() const {
    return from_symbol;
}

const std::string &ConvertInput::getToSymbol() const {
    return to_symbol;
}

double ConvertInput::getAmount() const {
    return amount;
}

