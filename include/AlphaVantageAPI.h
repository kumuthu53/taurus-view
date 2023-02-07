//
// Created by kumuthu on 7/02/23.
//

#ifndef TAURUS_VIEW_ALPHAVANTAGEAPI_H
#define TAURUS_VIEW_ALPHAVANTAGEAPI_H

#include <string>


class AlphaVantageAPI {
private:
    std::string api_key;
public:
    void set_api_key(const std::string &api_key);

};


#endif //TAURUS_VIEW_ALPHAVANTAGEAPI_H
