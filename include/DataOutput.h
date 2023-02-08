//
// Created by kumuthu on 7/02/23.
//

#ifndef TAURUS_VIEW_DATAOUTPUT_H
#define TAURUS_VIEW_DATAOUTPUT_H

#include <string>
#include <vector>


class DataOutput {
private:
    // Item length is 16. Center-justified.
    std::vector<std::string> dates;
    // Item length is 20. Right-justified.
    std::vector<std::string> open_values;
    // Item length is 20. Right-justified.
    std::vector<std::string> close_values;
    // Raw.
    std::string data_time;
public:
    const std::vector<std::string> &get_dates() const;
    void set_dates(const std::vector<std::string> &dates);
    const std::vector<std::string> &get_open_values() const;
    void set_open_values(const std::vector<std::string> &open_values);
    const std::vector<std::string> &get_close_values() const;
    void set_close_values(const std::vector<std::string> &close_values);
    const std::string &get_data_time() const;
    void set_data_time(const std::string &data_time);
};


#endif //TAURUS_VIEW_DATAOUTPUT_H
