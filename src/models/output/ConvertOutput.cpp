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

double ConvertOutput::getExchangeRate() const {
    return exchange_rate;
}

void ConvertOutput::setExchangeRate(double exchangeRate) {
    this->exchange_rate = exchangeRate;
}

const std::string &ConvertOutput::getDataTime() const {
    return data_time;
}

void ConvertOutput::setDataTime(const std::string &dataTime) {
    this->data_time = dataTime;
}
