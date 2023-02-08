//
// Created by kumuthu on 8/02/23.
//

#include "../include/processing.h"
#include "../include/screens.h"

#include <iostream>


ConvertOutput process_convert(const ConvertInput &convert_input, const AlphaVantageAPI &api) {

    processing_screen();

    std::string response = AlphaVantageAPI::curl_request("https://www.alphavantage.co/query?function=CURRENCY_EXCHANGE_RATE&from_currency=USD&to_currency=LKR&apikey=NU2QYWEADV4LINCH");

    std::cout << response;

    std::cin.get();

    return ConvertOutput();
}
