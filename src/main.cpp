//
// Created by kumuthu on 1/02/23.
//

#include <iostream>

#include "../include/screens.h"
#include "../include/terminalFunctions.h"
#include "../include/ConvertInput.h"
#include "../include/DataInput.h"


int app() {

    welcome_screen();

    Option option = option_screen();

    if (option == DATA) {
        DataInput data_input = data_input_screen();

        data_output_screen();

        std::cin.get();

    }
    else if (option == CONVERT) {
        ConvertInput convert_input = convert_input_screen();

        convert_output_screen();

        std::cin.get();
    }
    else {
        throw "Invalid option.";
    }

    std::cin.get();

    return 0;
}

int main() {

    try {
        app();
    } catch (const char* error) {
        reset_styling();

        std::cout << "Error: ";
        std::cout << error << std::endl;
    }
}

