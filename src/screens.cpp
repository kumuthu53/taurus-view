//
// Created by kumuthu on 1/02/23.
//

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <sys/stat.h>

#include "../include/screens.h"
#include "../include/terminalFunctions.h"
#include "../include/ConvertInput.h"
#include "../include/DataInput.h"
#include "../include/Currencies.h"
#include "../include/minorFunctions.h"

void welcome_screen() {

    clear_screen();

    print_white_lines(1);

    print_title("Welcome to TaurusView!");

    print_white_lines(1);

    loading(3);

}

Option option_screen() {

    clear_screen();

    print_white_lines(1);

    print_title("Main Menu");

    print_white_lines(1);

    print_blank_lines(2);

    print_option("DATA");

    std::cout << left_justify_on_80("View historical forex rates.");

    print_blank_lines(1);

    print_option("CONVERT");

    std::cout << left_justify_on_80("Forex conversions on real-time rates.");

    print_blank_lines(1);

    print_option("CHANGE_KEY");

    std::cout << left_justify_on_80("Change API key.");

    print_blank_lines(1);

    print_option("EXIT");

    std::cout << left_justify_on_80("Exit the application.");

    print_blank_lines(2);

    std::cout << left_justify_on_80("Enter function (DATA | CONVERT | CHANGE_KEY | EXIT) :") << std::endl;

    Option option = get_option();

    return option;
}

std::string api_key_screen(bool force) {

    std::string api_key;

    std::string home_dir = getenv("HOME");
    std::string dir_path = home_dir + "/.taurus-view";
    std::string file_path = dir_path + "/api_key.txt";

    struct stat sb;

    // Checks if directory already exists.
    if (stat(dir_path.c_str(), &sb) == 0 && S_ISDIR(sb.st_mode)) {

        if (!force) {
            std::ifstream in_file(file_path);

            // Check if file already exists.
            if (in_file.is_open()) {

                api_key = std::string((std::istreambuf_iterator<char>(in_file)),
                                      std::istreambuf_iterator<char>());

                return strip(api_key);
            }
        }
    }
    else {
        int result = mkdir(dir_path.c_str(), 0755);

        if (result != 0 ) {
            throw "Failed to create directory '.taurus-view' in home directory.";
        }
    }

    clear_screen();

    print_blank_lines(4);

    std::cout << std::string(10, ' ') << "+----------------------------------------------------------+" << std::endl;
    std::cout << std::string(10, ' ') << "|                         API key                          |" << std::endl;
    std::cout << std::string(10, ' ') << "+----------------------------------------------------------+" << std::endl;
    std::cout << std::string(10, ' ') << "|                                                          |" << std::endl;
    std::cout << std::string(10, ' ') << "|                Please enter your API key.                |" << std::endl;
    std::cout << std::string(10, ' ') << "|                                                          |" << std::endl;
    std::cout << std::string(10, ' ') << "|                                                          |" << std::endl;
    std::cout << std::string(10, ' ') << "|                     ________________                     |" << std::endl;
    std::cout << std::string(10, ' ') << "|                                                          |" << std::endl;
    std::cout << std::string(10, ' ') << "|   If you do not have an API key get one for free from    |" << std::endl;
    std::cout << std::string(10, ' ') << "|                                                          |" << std::endl;
    std::cout << std::string(10, ' ') << "|       https://www.alphavantage.co/support/#api-key       |" << std::endl;
    std::cout << std::string(10, ' ') << "|                                                          |" << std::endl;
    std::cout << std::string(10, ' ') << "+----------------------------------------------------------+" << std::endl;

    return get_and_store_api_key(file_path);
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

Option convert_output_screen() {

    clear_screen();

    print_blank_lines(1);

    std::cout << std::string(5, ' ') << "Press LEFT ARROW KEY to return to main menu." << std::endl;

    print_blank_lines(1);

    std::cout << std::string(10, ' ') << "+----------------------------+" << std::endl;
    std::cout << std::string(10, ' ') << "|                            |" << std::endl;
    std::cout << std::string(10, ' ') << "+----------------------------+" << std::endl;

    print_blank_lines(1);

    print_ascii_arrow();

    print_blank_lines(1);

    std::cout << std::string(10, ' ') << "+----------------------------+" << std::endl;
    std::cout << std::string(10, ' ') << "|                            |" << std::endl;
    std::cout << std::string(10, ' ') << "+----------------------------+" << std::endl;

    print_blank_lines(1);

    std::cout << std::string(5, ' ') << "Exchange rate is " << std::endl;

    print_blank_lines(1);

    std::cout << std::string(5, ' ') << "Data refreshed at " << std::endl;
    std::cout << std::string(5, ' ') << "Sourced from www.alphavantage.co" << std::endl;

    print_blank_lines(1);

    std::cout << std::string(5, ' ') << "Enter 'BACK' to go back or 'EXIT' to exit : ";

    return get_end_option();

}

Option data_output_screen() {

    clear_screen();

    print_blank_lines(1);

    std::cout << std::string(10, ' ') << "+----------------+--------------------+--------------------+" << std::endl;
    std::cout << std::string(10, ' ') << "|      Date      |        Open        |       Close        |" << std::endl;
    std::cout << std::string(10, ' ') << "+----------------+--------------------+--------------------+" << std::endl;

    for (int i = 0; i < 7; i++) {
        std::cout << std::string(10, ' ') << "|                |                    |                    |" << std::endl;
        std::cout << std::string(10, ' ') << "+----------------+--------------------+--------------------+" << std::endl;
    }

    print_blank_lines(1);

    std::cout << std::string(5, ' ') << "Data refreshed at " << std::endl;
    std::cout << std::string(5, ' ') << "Sourced from www.alphavantage.co" << std::endl;

    print_blank_lines(1);

    std::cout << std::string(5, ' ') << "Enter 'BACK' to go back or 'EXIT' to exit : ";

    return get_end_option();
}

void exit_screen() {

    clear_screen();

    print_white_lines(1);

    print_title("Thanks for using TaurusView!");

    print_white_lines(1);

    loading(3);

    clear_screen();

}








