//
// Created by kumuthu on 3/02/23.
//

#ifndef TAURUS_VIEW_TERMINALFUNCTIONS_H
#define TAURUS_VIEW_TERMINALFUNCTIONS_H

void loading(int number);

void clear_screen();

void green_bold_text_on_white(const std::string& text);

void reset_styling();

std::string center_on_80(const std::string& text);

void print_white_lines(int number);

#endif //TAURUS_VIEW_TERMINALFUNCTIONS_H
