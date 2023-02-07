//
// Created by kumuthu on 1/02/23.
//

#include <iostream>

#include "../include/screens.h"
#include "../include/terminalFunctions.h"
#include "../include/ConvertInput.h"
#include "../include/DataInput.h"
#include "../include/Currencies.h"

void welcome_screen() {

    clear_screen();

    print_white_lines(1);

    print_title("Welcome to TaurusView!");

    print_white_lines(1);

    loading(5);

}

Option option_screen() {

    clear_screen();

    print_blank_lines(1);

    std::cout << left_justify_on_80("TaurusView supports the following functions.") << std::endl;

    print_blank_lines(2);

    print_option("DATA");

    std::cout << left_justify_on_80("View historical forex rates.");

    print_blank_lines(1);

    print_option("CONVERT");

    std::cout << left_justify_on_80("Forex conversions on real-time rates.");

    print_blank_lines(2);

    std::cout << left_justify_on_80("Enter function (DATA | CONVERT) :") << std::endl;

    Option option = get_option();

    return option;
}

ConvertInput convert_input_screen() {

    clear_screen();

    Currencies currencies;

    print_blank_lines(1);

    std::cout << left_justify_on_80("Press ENTER after entering each value.") << std::endl;

    print_blank_lines(1);

    print_currencies_prompt();

    print_blank_lines(2);

    std::cout << std::string(10, ' ') << "Amount : " << std::endl;

    print_blank_lines(2);

    std::cout << left_justify_on_80("Available currency codes are as follows.") << std::endl;

    print_blank_lines(1);

    currencies.print_codes();

    ConvertInput convert_input;

    convert_input.set_from_symbol(get_from_currency(currencies));
    convert_input.set_to_symbol(get_to_currency(currencies));
    convert_input.set_amount(get_amount());

    return convert_input;
}

DataInput data_input_screen() {

    clear_screen();

    Currencies currencies;

    print_blank_lines(1);

    std::cout << left_justify_on_80("Press ENTER after entering each value.") << std::endl;

    print_blank_lines(1);

    print_currencies_prompt();

    print_blank_lines(2);

    std::cout << std::string(10, ' ') << "Frequency (DAILY | WEEKLY | MONTHLY) : " << std::endl;

    print_blank_lines(2);

    std::cout << left_justify_on_80("Available currency codes are as follows.") << std::endl;

    print_blank_lines(1);

    currencies.print_codes();

    DataInput data_input;

    data_input.set_from_symbol(get_from_currency(currencies));
    data_input.set_to_symbol(get_to_currency(currencies));
    data_input.set_frequency(get_frequency());

    return data_input;
}

void convert_output_screen(ConvertInput convert_input) {

    clear_screen();

    std::cout << "convert_output_screen" << std::endl;

    std::cout << convert_input.get_from_symbol() << std::endl;
    std::cout << convert_input.get_to_symbol() << std::endl;
    std::cout << convert_input.get_amount() << std::endl;
}

void data_output_screen(DataInput data_input) {
    clear_screen();

    std::cout << "data_output_screen" << std::endl;

    std:: cout << data_input.get_from_symbol() << std::endl;
    std:: cout << data_input.get_to_symbol() << std::endl;
    std:: cout << data_input.get_frequency() << std::endl;
}








