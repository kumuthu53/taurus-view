//
// Created by kumuthu on 8/02/23.
//

#include <iostream>
#include <string>

#include "../include/processing.h"
#include "../include/screens.h"
#include "../include/minorFunctions.h"


ConvertOutput process_convert(const ConvertInput &convert_input, const AlphaVantageAPI &api) {

    processing_screen();

    std::string response = api.get_rate_response(convert_input.get_from_symbol(),
                                                 convert_input.get_to_symbol());

    rapidjson::Document json_object = parse_json(response);

    double from_currency_amount = convert_input.get_amount();
    std::string exchange_rate_string = json_object["Realtime Currency Exchange Rate"]["5. Exchange Rate"].GetString();
    double exchange_rate = std::stod(exchange_rate_string);
    double to_currency_amount = from_currency_amount * exchange_rate;

    std::string from_currency_name = json_object["2. From_Currency Name"].GetString();
    std::string to_currency_name = json_object["4. To_Currency Name"].GetString();

    std::string data_time = std::string(json_object["6. Last Refreshed"].GetString()) +
            std::string(json_object["7. Time Zone"].GetString());

    std::string from_currency_amount_string = money_amount_string(28, from_currency_amount);
    std::string to_currency_amount_string = money_amount_string(28, to_currency_amount);

    ConvertOutput convert_output;

    convert_output.set_from_currency_amount(from_currency_amount_string);
    convert_output.set_to_currency_amount(to_currency_amount_string);
    convert_output.set_from_currency_name(from_currency_name);
    convert_output.set_to_currency_name(to_currency_name);
    convert_output.set_exchange_rate(exchange_rate);

    return convert_output;
}

DataOutput process_data(const DataInput &data_input, const AlphaVantageAPI &api) {

    processing_screen();

    std::string response = api.get_data_response(data_input.get_from_symbol(),
                                                 data_input.get_to_symbol(), data_input.get_frequency());

    std::cout << response;

    std::cin.get();

    return DataOutput();
}
