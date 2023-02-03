//
// Created by kumuthu on 1/02/23.
//

#include <iostream>

#include "../include/functions.h"
#include "../include/terminalFunctions.h"


int app() {

    welcome();

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

