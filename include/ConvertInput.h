//
// Created by kumuthu on 5/02/23.
//

#ifndef TAURUS_VIEW_CONVERTINPUT_H
#define TAURUS_VIEW_CONVERTINPUT_H

#include <string>


class ConvertInput {
private:
    std::string from_symbol;
    std::string to_symbol;
    double amount;
public:
    ConvertInput(const std::string &from_symbol, const std::string &to_symbol, double amount);

    const std::string &getFromSymbol() const;

    const std::string &getToSymbol() const;

    double getAmount() const;
};


#endif //TAURUS_VIEW_CONVERTINPUT_H
