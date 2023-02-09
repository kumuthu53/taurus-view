//
// Created by kumuthu on 7/02/23.
//

#ifndef TAURUS_VIEW_DATAOUTPUT_H
#define TAURUS_VIEW_DATAOUTPUT_H

#include <string>
#include <vector>


class DataOutput {
private:
    // Item length is 14. Center-justified. Length is 7.
    std::vector<std::string> dates;
    // Item length is 18. Right-justified. Length is 7.
    std::vector<std::string> open_values;
    // Item length is 18. Right-justified. Length is 7.
    std::vector<std::string> close_values;
    // Raw.
    std::string data_time;
    // Raw.
    std::string from_symbol;
    // Raw.
    std::string to_symbol;
public:
    const std::vector<std::string> &get_dates() const;
    void set_dates(const std::vector<std::string> &dates);
    const std::vector<std::string> &get_open_values() const;
    void set_open_values(const std::vector<std::string> &open_values);
    const std::vector<std::string> &get_close_values() const;
    void set_close_values(const std::vector<std::string> &close_values);
    const std::string &get_data_time() const;
    void set_data_time(const std::string &data_time);
    const std::string &get_from_symbol() const;
    void set_from_symbol(const std::string &from_symbol);
    const std::string &get_to_symbol() const;
    void set_to_symbol(const std::string &to_symbol);
};


#endif //TAURUS_VIEW_DATAOUTPUT_H
