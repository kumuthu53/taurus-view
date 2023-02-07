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

    while (true) {

        Option option = option_screen();

        if (option == DATA) {
            DataInput data_input = data_input_screen();

            Option end_option = data_output_screen();

            if (end_option == EXIT) {
                break;
            }

        } else if (option == CONVERT) {
            ConvertInput convert_input = convert_input_screen();

            Option end_option = convert_output_screen();

            if (end_option == EXIT) {
                break;
            }

        }
        else {
            break;
        }
    }

    exit_screen();

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

