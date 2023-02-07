//
// Created by kumuthu on 6/02/23.
//

#ifndef TAURUS_VIEW_CURRENCIES_H
#define TAURUS_VIEW_CURRENCIES_H

#include <string>
#include <vector>

#include "Currencies.h"
#include "Currency.h"


class Currencies {
private:
    std::vector<Currency> currencies;
public:
    Currencies();
    void print_codes() const;
    const std::vector<Currency> &getCurrencies() const;
};


#endif //TAURUS_VIEW_CURRENCIES_H
