//
// Created by kumuthu on 3/02/23.
//

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <string>
#include <cmath>

#include "../include/terminalFunctions.h"

void clear_screen() {
    std::cout << "\033c";
}

void loading(int number) {

    sleep(3);

    //std::cout << "          ";
    //std::cout << "*";
    //std::cout.flush();
    //
    //for (int i = 0; i < number - 1; i++) {
    //    sleep(1);
    //
    //    std::cout << "*";
    //    std::cout.flush();
    //}
    //
    //sleep(1);

}

void green_bold_text_on_white(const std::string& text) {

    // Bold.
    std::cout << "\033[1m";

    // Green text.
    std::cout << "\033[32m";

    // White background.
    std::cout << "\033[47m";

    std::cout << center_on_80(text);

    reset_styling();

    std::cout << std::endl;
}

void reset_styling() {
    std::cout << "\033[0m";
}

std::string center_on_80(const std::string &text) {

    size_t length = text.size();

    if (length >= 80) {
        throw "Line too long. Maximum is 80 characters.";
    }

    int prefix_length = (80 - length) / 2;
    int suffix_length = 80 - length - prefix_length;

    std::string centered = std::string(prefix_length, ' ') + text + std::string(suffix_length, ' ');

    return centered;
}

void print_white_lines(int number) {

    std::string line = std::string(80, ' ');

    std::cout << "\033[47m";

    for (int i = 0; i < number; i++) {
        std::cout << line << std::endl;
    }

    reset_styling();
}


