//
// Created by kumuthu on 8/02/23.
//

#ifndef TAURUS_VIEW_MINORFUNCTIONS_H
#define TAURUS_VIEW_MINORFUNCTIONS_H

#include <string>

#include "../dependencies/rapidjson/document.h"
#include "../dependencies/rapidjson/writer.h"
#include "../dependencies/rapidjson/stringbuffer.h"


std::string strip(const std::string& text);

rapidjson::Document parse_json(const std::string &json_string);

std::string money_amount_string(const int &width, const double &amount);

#endif //TAURUS_VIEW_MINORFUNCTIONS_H
