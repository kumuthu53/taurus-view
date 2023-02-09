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
    const std::string endpoint;
    static std::string curl_request(const std::string &url);
    static size_t curl_write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
public:
    explicit AlphaVantageAPI(const std::string &api_key);
    void set_api_key(const std::string &api_key);
    std::string get_data_response(const std::string &from_currency, const std::string &to_currency, Frequency frequency,
                                  const bool &debug) const;
    std::string
    get_rate_response(const std::string &from_currency, const std::string &to_currency, const bool &debug) const;
};


#endif //TAURUS_VIEW_ALPHAVANTAGEAPI_H
