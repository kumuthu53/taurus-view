//
// Created by kumuthu on 5/02/23.
//

#include <string>

#include "../../../include/DataInput.h"


DataInput::DataInput(Frequency frequency, const std::string &from_symbol, const std::string &to_symbol) {
    this->frequency = frequency;
    this->from_symbol = from_symbol;
    this->to_symbol = to_symbol;
}

Frequency DataInput::get_frequency() const {
    return frequency;
}

const std::string &DataInput::get_from_symbol() const {
    return from_symbol;
}

const std::string &DataInput::get_to_symbol() const {
    return to_symbol;
}
