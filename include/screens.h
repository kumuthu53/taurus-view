//
// Created by kumuthu on 1/02/23.
//

#ifndef TAURUS_VIEW_SCREENS_H
#define TAURUS_VIEW_SCREENS_H

#include "DataInput.h"
#include "ConvertInput.h"
#include "DataOutput.h"
#include "ConvertOutput.h"

enum Option : char {
    DATA = 0,
    CONVERT = 1,
    EXIT = 2,
    BACK = 3,
    CHANGE_KEY = 4
};

void welcome_screen();

Option option_screen();

std::string api_key_screen(bool force = false);

ConvertInput convert_input_screen();

DataInput data_input_screen();

void processing_screen();

Option convert_output_screen(const ConvertOutput &convert_output);

Option data_output_screen(const DataOutput &data_output);

void exit_screen();

#endif //TAURUS_VIEW_SCREENS_H
