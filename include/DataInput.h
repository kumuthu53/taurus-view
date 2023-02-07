//
// Created by kumuthu on 5/02/23.
//

#ifndef TAURUS_VIEW_DATAINPUT_H
#define TAURUS_VIEW_DATAINPUT_H

enum Frequency : char {
    DAILY = 0,
    WEEKLY = 1,
    MONTHLY = 2
};


class DataInput {
private:
    Frequency frequency;
    std::string from_symbol;
    std::string to_symbol;
public:
    DataInput(Frequency frequency, const std::string &from_symbol, const std::string &to_symbol);
    DataInput();
    Frequency get_frequency() const;
    const std::string &get_from_symbol() const;
    const std::string &get_to_symbol() const;
    void set_frequency(Frequency frequency);
    void set_from_symbol(const std::string &from_symbol);
    void set_to_symbol(const std::string &to_symbol);
};


#endif //TAURUS_VIEW_DATAINPUT_H
