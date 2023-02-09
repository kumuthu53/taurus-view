//
// Created by kumuthu on 1/02/23.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

#include "../include/screens.h"
#include "../include/terminalFunctions.h"
#include "../include/minorFunctions.h"
#include "../include/Exception.h"

void welcome_screen() {

    clear_screen();

    print_white_lines(1);

    print_title("Welcome to TaurusView!");

    print_white_lines(1);

    print_blank_lines(2);

    print_ascii_title();

    print_blank_lines(2);

    std::cout << center_on_80("by Kumuthu Edirisinghe");

    print_blank_lines(3);

    loading(30);

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

    std::cout << std::string(5, ' ') + "Enter function (";

    std::cout << "\033[35;1m" << "DATA";
    reset_styling();

    std::cout << " | ";

    std::cout << "\033[35;1m" << "CONVERT";
    reset_styling();

    std::cout << " | ";

    std::cout << "\033[35;1m" << "CHANGE_KEY";
    reset_styling();

    std::cout << " | ";

    std::cout << "\033[35;1m" << "EXIT";
    reset_styling();

    std::cout << ") :" << std::endl;

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
            throw Exception("Failed to create directory '.taurus-view' in home directory.");
        }
    }

    clear_screen();

    print_blank_lines(4);

    std::cout << "\033[36;1m";

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

    reset_styling();

    return get_and_store_api_key(file_path);
}

ConvertInput convert_input_screen() {

    clear_screen();

    Currencies currencies;

    print_blank_lines(1);

    // Cyan text.
    std::cout << "\033[36;1m";

    std::cout << left_justify_on_80("Press ENTER after entering each value.") << std::endl;

    print_blank_lines(1);

    print_currencies_prompt();

    print_blank_lines(2);

    std::cout << std::string(10, ' ') << "Amount : " << std::endl;

    print_blank_lines(2);

    std::cout << left_justify_on_80("Available currency codes are as follows.") << std::endl;

    reset_styling();

    print_blank_lines(1);

    // Brown text.
    std::cout << "\033[33;1m";

    currencies.print_codes();

    reset_styling();

    ConvertInput convert_input;

    convert_input.set_from_symbol(get_from_currency(currencies));
    convert_input.set_to_symbol(get_to_currency(currencies));
    convert_input.set_amount(get_amount());

    return convert_input;
}

DataInput data_input_screen() {

    clear_screen();

    Currencies currencies;

    // Cyan text.
    std::cout << "\033[36;1m";

    print_blank_lines(1);

    std::cout << left_justify_on_80("Press ENTER after entering each value.") << std::endl;

    print_blank_lines(1);

    print_currencies_prompt();

    print_blank_lines(2);

    std::cout << std::string(10, ' ') << "Frequency (\033[35;1mDAILY\033[36;1m | \033[35;1mWEEKLY\033[36;1m | \033[35;1mMONTHLY\033[36;1m) : " << std::endl;

    print_blank_lines(2);

    std::cout << left_justify_on_80("Available currency codes are as follows.") << std::endl;

    print_blank_lines(1);

    reset_styling();

    // Brown text.
    std::cout << "\033[33;1m";

    currencies.print_codes();

    reset_styling();

    DataInput data_input;

    data_input.set_from_symbol(get_from_currency(currencies));
    data_input.set_to_symbol(get_to_currency(currencies));
    data_input.set_frequency(get_frequency());

    return data_input;
}

void processing_screen() {

    clear_screen();

    reset_styling();

    print_blank_lines(1);

    std::cout << left_justify_on_80("Your request is being processed. Please wait.") << std::endl;

    print_blank_lines(1);

    std::cout << std::string(5, ' ');

    std::cout.flush();

}

Option convert_output_screen(const ConvertOutput &convert_output) {

    clear_screen();

    print_blank_lines(1);

    // Cyan text.
    std::cout << "\033[36;1m";

    std::cout << std::string(10, ' ') << "+----------------------------+" << std::endl;
    std::cout << std::string(10, ' ') << "|                            |" << std::endl;
    std::cout << std::string(10, ' ') << "+----------------------------+" << std::endl;

    print_blank_lines(1);

    // Blue text.
    std::cout << "\033[34;1m";

    print_ascii_arrow();

    print_blank_lines(1);

    // Cyan text.
    std::cout << "\033[36;1m";

    std::cout << std::string(10, ' ') << "+----------------------------+" << std::endl;
    std::cout << std::string(10, ' ') << "|                            |" << std::endl;
    std::cout << std::string(10, ' ') << "+----------------------------+" << std::endl;

    print_blank_lines(1);

    std::cout << std::string(5, ' ') << "Exchange rate is " << std::endl;

    print_blank_lines(1);

    std::cout << std::string(5, ' ') << "Data refreshed at " << std::endl;

    print_blank_lines(1);

    std::cout << std::string(5, ' ') << "Enter '\033[35;1mBACK\033[36;1m' to go back or '\033[35;1mEXIT\033[36;1m' to exit : ";

    reset_styling();

    // Displaying the output.

    // Move cursor.
    std::cout << "\033[3;13H";

    std::cout << convert_output.get_from_currency_amount();

    // Move cursor.
    std::cout << "\033[3;42H";

    std::cout << convert_output.get_from_currency_name();

    // Move cursor.
    std::cout << "\033[16;13H";

    std::cout << convert_output.get_to_currency_amount();

    // Move cursor.
    std::cout << "\033[16;42H";

    std::cout << convert_output.get_to_currency_name();

    // Move cursor.
    std::cout << "\033[19;23H";

    std::cout << convert_output.get_exchange_rate();

    // Move cursor.
    std::cout << "\033[21;24H";

    std::cout << convert_output.get_data_time();

    return get_end_option();

}

Option data_output_screen(const DataOutput &data_output) {

    clear_screen();

    print_blank_lines(1);

    // Cyan text.
    std::cout << "\033[36;1m";

    std::cout << std::string(10, ' ') << "+----------------+--------------------+--------------------+" << std::endl;
    std::cout << std::string(10, ' ') << "|      Date      |        Open        |       Close        |" << std::endl;
    std::cout << std::string(10, ' ') << "+----------------+--------------------+--------------------+" << std::endl;

    for (int i = 0; i < 7; i++) {
        std::cout << std::string(10, ' ') << "|                |                    |                    |" << std::endl;
        std::cout << std::string(10, ' ') << "+----------------+--------------------+--------------------+" << std::endl;
    }

    print_blank_lines(1);

    std::cout << std::string(5, ' ') << "    :    " << std::endl;
    std::cout << std::string(5, ' ') << "Data refreshed at " << std::endl;

    print_blank_lines(1);

    std::cout << std::string(5, ' ') << "Enter '\033[35;1mBACK\033[36;1m' to go back or '\033[35;1mEXIT\033[36;1m' to exit : ";

    reset_styling();

    // Displaying the output.

    for (int i = 0; i < 7; i++) {

        std::string col = std::to_string((i * 2) + 5);

        // Move cursor.
        std::cout << "\033[" + col + ";13H";

        std::cout << data_output.get_dates()[i];

        // Move cursor.
        std::cout << "\033[" + col + ";30H";

        std::cout << data_output.get_open_values()[i];

        // Move cursor.
        std::cout << "\033[" + col + ";51H";

        std::cout << data_output.get_close_values()[i];
    }

    // Move cursor.
    std::cout << "\033[20;6H";

    std::cout << data_output.get_from_symbol();

    // Move cursor.
    std::cout << "\033[20;12H";

    std::cout << data_output.get_to_symbol();

    // Move cursor.
    std::cout << "\033[21;24H";

    std::cout << data_output.get_data_time();

    return get_end_option();
}

void exit_screen() {

    clear_screen();

    print_white_lines(1);

    print_title("Thanks for using TaurusView!");

    print_white_lines(1);

    print_blank_lines(13);

    loading(10);

    clear_screen();

}

void error_screen() {

    clear_screen();

    reset_styling();

    print_blank_lines(1);

    std::cout << std::string(5, ' ') << "Oops! Something went wrong." << std::endl;

    print_blank_lines(2);

    std::cout << std::string(31, ' ') + "    .-\"\"\"\"\"\"-." << std::endl;
    std::cout << std::string(31, ' ') + "  .'          '.   " << std::endl;
    std::cout << std::string(31, ' ') + " /   O      O   \\ " << std::endl;
    std::cout << std::string(31, ' ') + ":                :" << std::endl;
    std::cout << std::string(31, ' ') + "|                |" << std::endl;
    std::cout << std::string(31, ' ') + ":    .------.    :" << std::endl;
    std::cout << std::string(31, ' ') + " \\  '        '  / " << std::endl;
    std::cout << std::string(31, ' ') + "  '.          .'  " << std::endl;
    std::cout << std::string(31, ' ') + "    '-......-'    " << std::endl;

    print_blank_lines(2);

    std::cout << std::string(5, ' ') << "Please check your API key and try again." << std::endl;

    print_blank_lines(1);

    std::cout << std::string(5, ' ') << "Press enter to go back to the main menu.";

    std::cin.get();

}






