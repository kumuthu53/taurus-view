//
// Created by kumuthu on 9/02/23.
//

#include "../../include/Exception.h"

const char *Exception::what() const noexcept {
    return message.c_str();
}

Exception::Exception(const std::string &message) {
    this->message = message;
}
