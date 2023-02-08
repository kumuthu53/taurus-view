//
// Created by kumuthu on 7/02/23.
//

#ifndef TAURUS_VIEW_ALPHAVANTAGEAPI_H
#define TAURUS_VIEW_ALPHAVANTAGEAPI_H

#include <string>

#include "DataInput.h"

class AlphaVantageAPI {
private:
    std::string api_key;
public:
    explicit AlphaVantageAPI(const std::string &api_key);
    void set_api_key(const std::string &api_key);
    std::string get_data_response(const std::string &from_currency, const std::string &to_currency, Frequency frequency);
    std::string get_rate_response(const std::string &from_currency, const std::string &to_currency, double amount);
};


#endif //TAURUS_VIEW_ALPHAVANTAGEAPI_H
