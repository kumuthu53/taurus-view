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
private:
    double amount;
public:
    ConvertInput(const std::string &from_symbol, const std::string &to_symbol, double amount);
    ConvertInput();
    const std::string &get_from_symbol() const;
    const std::string &get_to_symbol() const;
    double get_amount() const;
    void set_from_symbol(const std::string &from_symbol);
    void set_to_symbol(const std::string &to_symbol);
    void set_amount(double amount);
};


#endif //TAURUS_VIEW_CONVERTINPUT_H
