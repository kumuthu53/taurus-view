//
// Created by kumuthu on 8/02/23.
//

#include <iostream>
#include <string>

#include "../include/processing.h"
#include "../include/screens.h"
#include "../include/minorFunctions.h"
#include "../include/Exception.h"


ConvertOutput process_convert(const ConvertInput &convert_input, const AlphaVantageAPI &api, const bool debug) {

    processing_screen();

    std::string response = api.get_rate_response(convert_input.get_from_symbol(),
                                                 convert_input.get_to_symbol(), debug);

    if (debug) {
        std::cout << std::endl;

        std::cout << response << std::endl;

        std::cin.get();
    }

    rapidjson::Document json_object = parse_json(response);

    if (json_object.HasMember("Error Message")) {
        throw Exception("Error when making request.");
    }

    double from_currency_amount = convert_input.get_amount();
    std::string exchange_rate_string = json_object["Realtime Currency Exchange Rate"]["5. Exchange Rate"].GetString();
    double exchange_rate = std::stod(exchange_rate_string);
    double to_currency_amount = from_currency_amount * exchange_rate;

    std::string from_currency_name = json_object["Realtime Currency Exchange Rate"]["2. From_Currency Name"].GetString();
    std::string to_currency_name = json_object["Realtime Currency Exchange Rate"]["4. To_Currency Name"].GetString();

    std::string data_time = std::string(json_object["Realtime Currency Exchange Rate"]["6. Last Refreshed"].GetString())
            + std::string(1, ' ') + std::string(json_object["Realtime Currency Exchange Rate"]["7. Time Zone"].GetString());

    std::string from_currency_amount_string = money_amount_string(26, from_currency_amount);
    std::string to_currency_amount_string = money_amount_string(26, to_currency_amount);

    ConvertOutput convert_output;

    convert_output.set_from_currency_amount(from_currency_amount_string);
    convert_output.set_to_currency_amount(to_currency_amount_string);
    convert_output.set_from_currency_name(from_currency_name);
    convert_output.set_to_currency_name(to_currency_name);
    convert_output.set_exchange_rate(exchange_rate);
    convert_output.set_data_time(data_time);

    return convert_output;
}

DataOutput process_data(const DataInput &data_input, const AlphaVantageAPI &api, const bool debug) {

    processing_screen();

    std::string response = api.get_data_response(data_input.get_from_symbol(),
                                                 data_input.get_to_symbol(), data_input.get_frequency(),
                                                 debug);

    if (debug) {
        std::cout << std::endl;

        std::cout << response << std::endl;

        std::cin.get();
    }

    rapidjson::Document json_object = parse_json(response);

    if (json_object.HasMember("Error Message")) {
        throw Exception("Error when making request.");
    }

    std::vector<std::string> dates;
    std::vector<std::string> open_values;
    std::vector<std::string> close_values;

    std::string from_symbol = json_object["Meta Data"]["2. From Symbol"].GetString();
    std::string to_symbol = json_object["Meta Data"]["3. To Symbol"].GetString();

    std::string data_time;
    std::string list_key;

    if (data_input.get_frequency() == DAILY){
        data_time = json_object["Meta Data"]["5. Last Refreshed"].GetString() + std::string(1, ' ') +
                                json_object["Meta Data"]["6. Time Zone"].GetString();
        list_key = "Time Series FX (Daily)";
    } else {
        data_time = json_object["Meta Data"]["4. Last Refreshed"].GetString() + std::string(1, ' ') +
                                json_object["Meta Data"]["5. Time Zone"].GetString();

        if (data_input.get_frequency() == WEEKLY) {
            list_key = "Time Series FX (Weekly)";
        } else {
            list_key = "Time Series FX (Monthly)";
        }
    }

    const rapidjson::Value &list = json_object[list_key.c_str()];

    char count = 0;

    for (rapidjson::Value::ConstMemberIterator itr = list.MemberBegin(); itr != list.MemberEnd(); itr++) {
        std::string date = itr->name.GetString();
        std::string open_value = list[date.c_str()]["1. open"].GetString();
        std::string close_value = list[date.c_str()]["4. close"].GetString();

        dates.push_back(right_justify_string(14, date));
        open_values.push_back(right_justify_string(18, open_value));
        close_values.push_back(right_justify_string(18, close_value));

        count++;

        if (count > 6) {
            break;
        }
    }

    DataOutput data_output;

    data_output.set_dates(dates);
    data_output.set_open_values(open_values);
    data_output.set_close_values(close_values);
    data_output.set_from_symbol(from_symbol);
    data_output.set_to_symbol(to_symbol);
    data_output.set_data_time(data_time);


    return data_output;
}
