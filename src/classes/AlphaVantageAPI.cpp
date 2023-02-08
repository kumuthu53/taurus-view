//
// Created by kumuthu on 7/02/23.
//

#include "../../include/AlphaVantageAPI.h"

#include <curl/curl.h>

void AlphaVantageAPI::set_api_key(const std::string &api_key) {
    this->api_key = api_key;
}

std::string AlphaVantageAPI::get_data_response(const std::string &from_currency, const std::string &to_currency,
                                               Frequency frequency) {
    return std::string();
}

std::string AlphaVantageAPI::get_rate_response(const std::string &from_currency,
                                               const std::string &to_currency, double amount) {
    return std::string();
}

AlphaVantageAPI::AlphaVantageAPI(const std::string &api_key) {
    this->api_key = api_key;
}

std::string AlphaVantageAPI::curl_request(const std::string &url) {

    CURL *curl = curl_easy_init();

    if (!curl) {
        throw "Failed to initialize curl.";
    }

    std::string response;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        throw "Curl request failed.";
    }

    curl_easy_cleanup(curl);

    return response;
}

size_t AlphaVantageAPI::curl_write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {

    std::string *response = static_cast<std::string*>(userdata);

    response->append(ptr, size * nmemb);

    return size * nmemb;
}


