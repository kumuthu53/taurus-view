//
// Created by kumuthu on 9/02/23.
//

#ifndef TAURUS_VIEW_EXCEPTION_H
#define TAURUS_VIEW_EXCEPTION_H

#include <exception>
#include <string>

class Exception : public std::exception {
private:
    std::string message;
public:
    Exception(const std::string &message);
    const char *what() const noexcept;
};


#endif //TAURUS_VIEW_EXCEPTION_H
