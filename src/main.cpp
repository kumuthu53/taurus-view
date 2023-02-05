//
// Created by kumuthu on 1/02/23.
//

#include <iostream>

#include "../include/screens.h"
#include "../include/terminalFunctions.h"


int app() {

    welcome_screen();

    Option option = option_screen();

    if (option == DATA) {

    }
    else if (option == CONVERT) {

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

