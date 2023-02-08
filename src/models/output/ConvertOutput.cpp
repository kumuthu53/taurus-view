//
// Created by kumuthu on 7/02/23.
//

#include "../../../include/ConvertOutput.h"

const std::string &ConvertOutput::get_from_currency_amount() const {
    return from_currency_amount;
}

void ConvertOutput::set_from_currency_amount(const std::string &from_currency_amount) {
    this->from_currency_amount = from_currency_amount;
}

const std::string &ConvertOutput::get_to_currency_amount() const {
    return to_currency_amount;
}

void ConvertOutput::set_to_currency_amount(const std::string &to_currency_amount) {
    this->to_currency_amount = to_currency_amount;
}

const std::string &ConvertOutput::get_from_currency_name() const {
    return from_currency_name;
}

void ConvertOutput::set_from_currency_name(const std::string &from_currency_name) {
    this->from_currency_name = from_currency_name;
}

const std::string &ConvertOutput::get_to_currency_name() const {
    return to_currency_name;
}

void ConvertOutput::set_to_currency_name(const std::string &to_currency_name) {
    this->to_currency_name = to_currency_name;
}

double ConvertOutput::get_exchange_rate() const {
    return exchange_rate;
}

void ConvertOutput::set_exchange_rate(double exchange_rate) {
    this->exchange_rate = exchange_rate;
}

const std::string &ConvertOutput::get_data_time() const {
    return data_time;
}

void ConvertOutput::set_data_time(const std::string &data_time) {
    this->data_time = data_time;
}
