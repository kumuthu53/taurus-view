//
// Created by kumuthu on 1/02/23.
//

#include <iostream>

#include "../include/screens.h"
#include "../include/terminalFunctions.h"

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

    return DATA;
}




