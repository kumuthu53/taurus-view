//
// Created by kumuthu on 8/02/23.
//

#ifndef TAURUS_VIEW_PROCESSING_H
#define TAURUS_VIEW_PROCESSING_H

#include "ConvertOutput.h"
#include "DataOutput.h"
#include "ConvertInput.h"
#include "DataInput.h"
#include "AlphaVantageAPI.h"


ConvertOutput process_convert(const ConvertInput &convert_input, const AlphaVantageAPI &api, const bool debug = false);

DataOutput process_data(const DataInput &data_input, const AlphaVantageAPI &api, const bool debug = false);

#endif //TAURUS_VIEW_PROCESSING_H
