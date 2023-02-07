//
// Created by kumuthu on 1/02/23.
//

#ifndef TAURUS_VIEW_SCREENS_H
#define TAURUS_VIEW_SCREENS_H

#include "DataInput.h"
#include "ConvertInput.h"

enum Option : bool {
    DATA = 0,
    CONVERT = 1
};

void welcome_screen();

Option option_screen();

ConvertInput convert_input_screen();

DataInput data_input_screen();

void convert_output_screen();

void data_output_screen();

#endif //TAURUS_VIEW_SCREENS_H
