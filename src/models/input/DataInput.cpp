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

DataInput::DataInput() {
    this->frequency = DAILY;
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

void DataInput::set_frequency(Frequency frequency) {
    DataInput::frequency = frequency;
}

void DataInput::set_from_symbol(const std::string &from_symbol) {
    this->from_symbol = from_symbol;
}

void DataInput::set_to_symbol(const std::string &to_symbol) {
    this->to_symbol = to_symbol;
}
