//
// Created by kumuthu on 8/02/23.
//

#include "../include/minorFunctions.h"

std::string strip(const std::string &text)  {
    size_t start_idx = text.find_first_not_of(" \t\r\n");
    size_t end_idx = text.find_last_not_of(" \t\r\n");

    return text.substr(start_idx, end_idx - start_idx + 1);
}