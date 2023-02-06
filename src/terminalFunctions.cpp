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
#include "../include/screens.h"

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

void print_title(const std::string& text) {

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

    if (length > 80) {
        throw "Line too long. Maximum is 80 characters.";
    }

    int prefix_length = (80 - length) / 2;
    int suffix_length = 80 - length - prefix_length;

    std::string centered = std::string(prefix_length, ' ') + text + std::string(suffix_length, ' ');

    return centered;
}

std::string left_justify_on_80(const std::string &text) {

    if (text.size() > 75) {
        throw "Line too long. Maximum is 80 characters.";
    }

    std::string justified = std::string(5, ' ') + text;

    return justified;
}

void print_option(const std::string &text) {

    if (text.size() > 75) {
        throw "Line too long. Maximum is 80 characters.";
    }

    std::cout << "   * ";

    // Underlined text.
    std::cout << "\033[4m";

    // Bold text.
    std::cout << "\033[1m";

    std::cout << text << std::endl;

    reset_styling();
}

void print_currencies_prompt() {

    print_blank_lines(1);

    std::cout << std::string(10, ' ') << "From (currency code) : ___";

    // Move cursor.
    std::cout << "\033[5;40H";

    std::cout <<  "To (currency code) : ___" << std::endl;

    print_blank_lines(3);

    std::cout << std::string(5, ' ') << "Amount : " << std::endl;

    print_blank_lines(1);

    std::cout << left_justify_on_80("Available currency codes are as follows.") << std::endl;

    print_blank_lines(1);

    print_white_lines(10);

}

void print_white_lines(int number) {

    std::string line = std::string(80, ' ');

    std::cout << "\033[47m";

    for (int i = 0; i < number; i++) {
        std::cout << line << std::endl;
    }

    reset_styling();
}

void print_blank_lines(int number) {

    std::string line = std::string(80, ' ');

    for (int i = 0; i < number; i++) {
        std::cout << line << std::endl;
    }

}

Option get_option() {

    std::string option_string;

    std::cout << std::string(5, ' ');

    getline(std::cin, option_string);

    if (option_string == "DATA") {
        return DATA;
    }
    else if (option_string == "CONVERT") {
        return CONVERT;
    }
    else {
        move_cursor_up(3);

        // Red text.
        std::cout << "\033[31m";

        std::cout << left_justify_on_80("Invalid input. Please re-enter.");

        reset_styling();

        move_cursor_down_to_start(2);

        // Clear current line.
        std::cout << "\033[2K";

        Option option = get_option();

        return option;
    }
}

void move_cursor_up(int num_lines) {

    for (int i = 0; i < num_lines; i++) {
        std::cout << "\033[A";
    }
}

void move_cursor_down(int num_lines) {

    for (int i = 0; i < num_lines; i++) {
        std::cout << "\033[B";
    }
}

void move_cursor_down_to_start(int num_lines) {

    for (int i = 0; i < num_lines; i++) {
        std::cout << "\033[E";
    }
}

