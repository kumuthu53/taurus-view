//
// Created by kumuthu on 1/02/23.
//

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <stdlib.h>

#include "../include/functions.h"

void welcome() {
    std::cout << "Welcome to TaurusView!" << std::endl;

    slow_star(5);

    std::cout << "\r";
}

void slow_star(int number) {

    std::cout << "          ";
    std::cout << "*";
    std::cout.flush();

    for (int i = 0; i < number - 1; i++) {
        sleep(1);

        std::cout << "*";
        std::cout.flush();
    }

    sleep(1);

}
