//
// Created by kumuthu on 7/02/23.
//

#ifndef TAURUS_VIEW_CONVERTOUTPUT_H
#define TAURUS_VIEW_CONVERTOUTPUT_H

#include <string>


class ConvertOutput {
private:
    // Length is 28. Right-justified.
    std::string from_currency_amount;
    // Length is 28. Right-justified.
    std::string to_currency_amount;
    // Length is 29. Right-justified.
    std::string from_currency_name;
    // Length is 29. Right-justified.
    std::string to_currency_name;
    // Raw.
    double exchange_rate;
    // Raw.
    std::string data_time;
public:
    const std::string &get_from_currency_amount() const;
    void set_from_currency_amount(const std::string &from_currency_amount);
    const std::string &get_to_currency_amount() const;
    void set_to_currency_amount(const std::string &to_currency_amount);
    const std::string &get_from_currency_name() const;
    void set_from_currency_name(const std::string &from_currency_name);
    const std::string &get_to_currency_name() const;
    void set_to_currency_name(const std::string &to_currency_name);

    double getExchangeRate() const;

    void setExchangeRate(double exchangeRate);

    const std::string &getDataTime() const;

    void setDataTime(const std::string &dataTime);
};


#endif //TAURUS_VIEW_CONVERTOUTPUT_H
