//
// Created by kumuthu on 6/02/23.
//

#ifndef TAURUS_VIEW_CURRENCY_H
#define TAURUS_VIEW_CURRENCY_H

#include <string>


class Currency {
private:
    std::string code;
    std::string name;
    size_t name_size() const;
public:
    Currency(const std::string &code, const std::string &name);
    void print_name() const;
    void print_code() const;
    bool equals(std::string code) const;
    const std::string &get_code() const;
    const std::string &get_name() const;
};


#endif //TAURUS_VIEW_CURRENCY_H
