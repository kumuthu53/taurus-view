//
// Created by kumuthu on 3/02/23.
//

#ifndef TAURUS_VIEW_TERMINALFUNCTIONS_H
#define TAURUS_VIEW_TERMINALFUNCTIONS_H

#include "screens.h"
#include "ConvertInput.h"
#include "DataInput.h"
#include "Currencies.h"

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

std::string get_and_store_api_key(std::string file_path);

Option get_option();

std::string get_from_currency(Currencies &currencies);

std::string get_to_currency(Currencies &currencies);

double get_amount();

Frequency get_frequency();

Option get_end_option();

void move_cursor_up(int num_lines);

void move_cursor_down(int num_lines);

void move_cursor_down_to_start(int num_lines);

void print_ascii_arrow();

void print_ascii_title();

#endif //TAURUS_VIEW_TERMINALFUNCTIONS_H
