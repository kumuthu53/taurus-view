//
// Created by kumuthu on 7/02/23.
//

#include "../../../include/DataOutput.h"

const std::vector<std::string> &DataOutput::get_dates() const {
    return dates;
}

void DataOutput::set_dates(const std::vector<std::string> &dates) {
    this->dates = dates;
}

const std::vector<std::string> &DataOutput::get_open_values() const {
    return open_values;
}

void DataOutput::set_open_values(const std::vector<std::string> &open_values) {
    this->open_values = open_values;
}

const std::vector<std::string> &DataOutput::get_close_values() const {
    return close_values;
}

void DataOutput::set_close_values(const std::vector<std::string> &close_values) {
    this->close_values = close_values;
}

const std::string &DataOutput::get_data_time() const {
    return data_time;
}

void DataOutput::set_data_time(const std::string &data_time) {
    this->data_time = data_time;
}
