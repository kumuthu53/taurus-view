//
// Created by kumuthu on 8/02/23.
//

#include <iomanip>
#include <sstream>
#include <string>

#include "../include/minorFunctions.h"


std::string strip(const std::string &text)  {
    size_t start_idx = text.find_first_not_of(" \t\r\n");
    size_t end_idx = text.find_last_not_of(" \t\r\n");

    return text.substr(start_idx, end_idx - start_idx + 1);
}

rapidjson::Document parse_json(const std::string &json_string) {

    const char *json_c_string = json_string.c_str();

    rapidjson::Document json_object;

    json_object.Parse(json_c_string);

    return json_object;
}

std::string money_amount_string(const int &width, const double &amount) {

    std::stringstream ss;

    ss << std::fixed << std::setprecision(2) << std::setw(width) << std::right << amount;

    std::string amount_string = ss.str();

    if (amount_string.length() > width) {
        amount_string = "Too large to display";
    }

    return amount_string;
}
