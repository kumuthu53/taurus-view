//
// Created by kumuthu on 7/02/23.
//

#include <iostream>

#include <curl/curl.h>

#include "../../include/AlphaVantageAPI.h"

void AlphaVantageAPI::set_api_key(const std::string &api_key) {
    this->api_key = api_key;
}

std::string AlphaVantageAPI::get_data_response(const std::string &from_currency, const std::string &to_currency,
                                               Frequency frequency,
                                               const bool &debug) const {

    std::string frequency_string;

    if (frequency == DAILY) {
        frequency_string = "DAILY";
    } else if (frequency == WEEKLY) {
        frequency_string = "WEEKLY";
    } else {
        frequency_string = "MONTHLY";
    }

    std::string url = endpoint + "function=FX_" + frequency_string;
    url = url + "&from_symbol=" + from_currency;
    url = url + "&to_symbol=" + to_currency;
    //url = url + "&apikey=" + api_key;

    if (debug) {
        std::cout << url << std::endl;
    }

    std::string response = curl_request(url);

    return response;
}

std::string AlphaVantageAPI::get_rate_response(const std::string &from_currency, const std::string &to_currency,
                                               const bool &debug) const {

    std::string url = endpoint + "function=CURRENCY_EXCHANGE_RATE";
    url = url + "&from_currency=" + from_currency;
    url = url + "&to_currency=" + to_currency;
    url = url + "&apikey=" + api_key;

    std::string response = curl_request(url);

    return response;
}

AlphaVantageAPI::AlphaVantageAPI(const std::string &api_key)
        : api_key(api_key), endpoint("https://www.alphavantage.co/query?") {}

std::string AlphaVantageAPI::curl_request(const std::string &url) {

    // Initialize a curl session.
    CURL *curl = curl_easy_init();

    if (!curl) {
        throw "Failed to initialize curl.";
    }

    std::string response;

    // Setting options.
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // Performs the request.
    CURLcode res = curl_easy_perform(curl);

    // Checks if the request succeeded.
    if (res != CURLE_OK) {
        throw "Curl request failed.";
    }

    // Cleaning up the curl session.
    curl_easy_cleanup(curl);

    return response;
}

// Appends the data to a string.
size_t AlphaVantageAPI::curl_write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {

    std::string *response = static_cast<std::string*>(userdata);

    response->append(ptr, size * nmemb);

    return size * nmemb;
}


