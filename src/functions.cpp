//
// Created by kumuthu on 1/02/23.
//

#include <iostream>

#include "../include/functions.h"
#include "../include/terminalFunctions.h"

void welcome() {

    clear_screen();

    print_white_lines(1);

    green_bold_text_on_white("Welcome to TaurusView!");

    print_white_lines(1);

    loading(5);

    clear_screen();

}


