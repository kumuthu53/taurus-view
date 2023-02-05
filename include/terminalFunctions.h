//
// Created by kumuthu on 3/02/23.
//

#include "../include/screens.h"

#ifndef TAURUS_VIEW_TERMINALFUNCTIONS_H
#define TAURUS_VIEW_TERMINALFUNCTIONS_H

void loading(int number);

void clear_screen();

void print_title(const std::string& text);

void reset_styling();

std::string center_on_80(const std::string& text);

std::string left_justify_on_80(const std::string &text);

void print_option(const std::string &text);

void print_white_lines(int number);

void print_blank_lines(int number);

Option get_option();

void move_cursor_up(int num_lines);

void move_cursor_down(int num_lines);

void move_cursor_down_to_start(int num_lines);

#endif //TAURUS_VIEW_TERMINALFUNCTIONS_H
