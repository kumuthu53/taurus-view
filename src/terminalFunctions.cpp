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
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>

#include "../include/terminalFunctions.h"
#include "../include/screens.h"
#include "../include/Currencies.h"

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

    print_blank_lines(1);

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

std::string get_and_store_api_key(std::string file_path) {

    std::string api_key;

    reset_styling();

    // Move cursor.
    std::cout << "\033[12;33H";

    std::cout << "________________                     |";

    // Clear current line.
    std::cout << "\033[K";

    // Move cursor.
    std::cout << "\033[12;33H";

    // Underlined text.
    std::cout << "\033[4m";

    getline(std::cin, api_key);

    if (api_key.length() != 16) {

        reset_styling();

        // Move cursor.
        std::cout << "\033[11;16H";

        // Red text.
        std::cout << "\033[31m";

        std::cout << "API key should be 16 characters. Please re-enter.";

        api_key = get_and_store_api_key(file_path);

        return api_key;
    }

    std::ofstream out_file(file_path);

    if (!out_file) {
        throw "Failed to create file '~/taurus-view/api_key.txt.";
    }

    out_file << api_key;

    out_file.close();

    return api_key;

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
    else if (option_string == "CHANGE_KEY") {
        return CHANGE_KEY;
    }
    else if (option_string == "EXIT") {
        return EXIT;
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

Option get_end_option() {

    std::string option_string;

    // Move cursor.
    std::cout << "\033[23;50H";

    // Clear current line.
    std::cout << "\033[K";

    getline(std::cin, option_string);

    if (option_string == "BACK") {
        return BACK;
    } else if (option_string == "EXIT") {
        return EXIT;
    }
    else {

        // Move cursor.
        std::cout << "\033[22;6H";

        // Red text.
        std::cout << "\033[31m";

        std::cout << "Invalid input. Please re-enter." << std::endl;

        reset_styling();

        Option option = get_end_option();

        return option;
    }

}

std::string get_from_currency(Currencies &currencies) {

    reset_styling();

    std::string from_currency;

    // Move cursor.
    std::cout << "\033[5;34H";

    std::cout << "___";

    // Move cursor.
    std::cout << "\033[5;34H";

    // Underlined text.
    std::cout << "\033[4m";

    getline(std::cin, from_currency);

    const std::vector<Currency> &currencies_vector = currencies.getCurrencies();

    auto currency_iterator = std::find_if(currencies_vector.begin(), currencies_vector.end(),
                                          [&from_currency](const Currency& currency) { return currency.equals(from_currency); });

    if (currency_iterator == currencies_vector.end()) {

        reset_styling();

        // Move cursor.
        std::cout << "\033[4;11H";

        // Red text.
        std::cout << "\033[31m";

        std::cout << "Invalid code. Re-enter.";

        get_from_currency(currencies);
    }

    reset_styling();

    // Move cursor.
    std::cout << "\033[4;0H";

    print_blank_lines(1);

    // Move cursor.
    std::cout << "\033[6;11H";

    currency_iterator->print_name();

    return from_currency;
}

std::string get_to_currency(Currencies &currencies) {

    reset_styling();

    std::string to_currency;

    // Move cursor.
    std::cout << "\033[5;61H";

    std::cout << "___";

    // Move cursor.
    std::cout << "\033[5;61H";

    // Underlined text.
    std::cout << "\033[4m";

    getline(std::cin, to_currency);

    const std::vector<Currency> &currencies_vector = currencies.getCurrencies();

    auto currency_iterator = std::find_if(currencies_vector.begin(), currencies_vector.end(),
                                          [&to_currency](const Currency& currency) { return currency.equals(to_currency); });

    if (currency_iterator == currencies_vector.end()) {

        reset_styling();

        // Move cursor.
        std::cout << "\033[4;40H";

        // Red text.
        std::cout << "\033[31m";

        std::cout << "Invalid code. Re-enter.";

        get_to_currency(currencies);
    }

    reset_styling();

    // Move cursor.
    std::cout << "\033[4;0H";

    print_blank_lines(1);

    // Move cursor.
    std::cout << "\033[6;40H";

    currency_iterator->print_name();

    return to_currency;
}

double get_amount() {

    reset_styling();

    // Move cursor.
    std::cout << "\033[9;20H";

    std::string amount_string;
    double amount;

    getline(std::cin, amount_string);

    std::istringstream iss(amount_string);

    if (!(iss >> amount)) {

        // Move cursor.
        std::cout << "\033[8;11H";

        // Red text.
        std::cout << "\033[31m";

        std::cout << "Invalid amount. Please re-enter.";

        reset_styling();

        // Move cursor.
        std::cout << "\033[9;20H";

        print_blank_lines(1);

        amount = get_amount();

    }


    return amount;

}

Frequency get_frequency() {

    reset_styling();

    std::string frequency_string;

    Frequency frequency;

    // Move cursor.
    std::cout << "\033[9;50H";

    print_blank_lines(1);

    // Move cursor.
    std::cout << "\033[9;50H";

    getline(std::cin, frequency_string);

    if (frequency_string == "DAILY") {
        frequency = DAILY;
    }
    else if (frequency_string == "WEEKLY") {
        frequency = WEEKLY;
    }
    else if (frequency_string == "MONTHLY") {
        frequency = MONTHLY;
    }
    else {
        // Move cursor.
        std::cout << "\033[8;11H";

        // Red text.
        std::cout << "\033[31m";

        std::cout << "Invalid frequency. Please re-enter.";

        frequency = get_frequency();
    }

    return  frequency;
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

void print_ascii_arrow() {

    std::cout << std::string(15, ' ') << "        @@@        " << std::endl;
    std::cout << std::string(15, ' ') << "        @@@        " << std::endl;
    std::cout << std::string(15, ' ') << "        @@@        " << std::endl;
    std::cout << std::string(15, ' ') << "%@@@    @@@    @@@," << std::endl;
    std::cout << std::string(15, ' ') << "  @@@@  @@@  @@@@  " << std::endl;
    std::cout << std::string(15, ' ') << "    @@@@@@@@@@@    " << std::endl;
    std::cout << std::string(15, ' ') << "       @@@@@       " << std::endl;
    std::cout << std::string(15, ' ') << "         @         " << std::endl;

}

