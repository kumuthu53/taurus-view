//
// Created by kumuthu on 7/02/23.
//

#include "../../include/AlphaVantageAPI.h"

void AlphaVantageAPI::set_api_key(const std::string &api_key) {
    this->api_key = api_key;
}

std::string AlphaVantageAPI::get_data_response(const std::string &from_currency, const std::string &to_currency,
                                               Frequency frequency) {
    return std::string();
}

std::string AlphaVantageAPI::get_rate_response(const std::string &from_currency,
                                               const std::string &to_currency, double amount) {
    return std::string();
}

AlphaVantageAPI::AlphaVantageAPI(const std::string &api_key) {
    this->api_key = api_key;
}


