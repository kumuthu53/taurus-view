//
// Created by kumuthu on 3/02/23.
//

#ifndef TAURUS_VIEW_TERMINALFUNCTIONS_H
#define TAURUS_VIEW_TERMINALFUNCTIONS_H

#include "../include/screens.h"
#include "../include/ConvertInput.h"
#include "../include/DataInput.h"

void loading(int number);

void clear_screen();

void print_title(const std::string& text);

void reset_styling();

std::string center_on_80(const std::string& text);

std::string left_justify_on_80(const std::string &text);

void print_option(const std::string &text);

void print_currencies_prompt();

void print_white_lines(int number);

void print_blank_lines(int number);

Option get_option();

void move_cursor_up(int num_lines);

void move_cursor_down(int num_lines);

void move_cursor_down_to_start(int num_lines);

ConvertInput convert_input_screen();

DataInput data_input_screen();

#endif //TAURUS_VIEW_TERMINALFUNCTIONS_H
