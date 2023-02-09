//
// Created by kumuthu on 1/02/23.
//

#include <iostream>

#include "../include/screens.h"
#include "../include/terminalFunctions.h"
#include "../include/AlphaVantageAPI.h"
#include "../include/processing.h"


int app() {

    welcome_screen();

    while (true) {

        AlphaVantageAPI api(api_key_screen());

        Option option = option_screen();

        if (option == DATA) {

            DataInput data_input = data_input_screen();

            Option end_option;

            try {
                DataOutput data_output = process_data(data_input, api);
                end_option = data_output_screen(data_output);
            } catch (...) {
                error_screen();
                continue;
            }

            if (end_option == EXIT) {
                break;
            }

        }  else if (option == CONVERT) {

            ConvertInput convert_input = convert_input_screen();

            Option end_option;

            try {
                ConvertOutput convert_output = process_convert(convert_input, api);
                end_option = convert_output_screen(convert_output);
            } catch (...) {
                error_screen();
                continue;
            }

            if (end_option == EXIT) {
                break;
            }

        } else if (option == CHANGE_KEY) {

            api.set_api_key(api_key_screen(true));

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
    } catch (const std::exception &e) {
        reset_styling();

        std::cout << "Error: ";
        std::cout << e.what() << std::endl;
    }
}

