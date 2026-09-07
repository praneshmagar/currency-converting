#include "converter.h"
#include <iostream>
#include <cstdlib>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

size_t WriteCallback(char* contents, size_t size, size_t nmemb, void* userp ) // api response is in chunks so we need somewhere to put this data
{
   // contents points to chunks of data size nmemb userp tells how much data
   
    size_t totalSize = size * nmemb; //how many bytes 
    
    std::string* response = static_cast<std::string*>(userp);
    
    response->append(contents, totalSize); // response is a pointer so use ->, add new data to our string

    return totalSize;
}


double getExchangeRateAPI(std::string fromCurrency, std::string toCurrency) //take what fromCurrency user inputs and what toCurrency user inputs then use api to get the rate
{
    const char* apikey = std::getenv("EXCHANGE_API_KEY"); // retreive api key from environment

    if(apikey == nullptr){
        std::cout << "API KEY NOT FOUND" << std::endl;
        return 0;
    }
    
    //std::cout << "Api key was found" << std::endl; debugging for if api key was found

    std::string url = 
        "https://v6.exchangerate-api.com/v6/" +
        std::string(apikey) +
        "/pair/" +
        fromCurrency +
        "/" +
        toCurrency;
    std::string response;
    
    CURL* curl = curl_easy_init(); // create a libcurl handle

    if(curl == nullptr)
    {
        std::cout << "Failed to initialize curl" << std::endl;
        return 0;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); // use url we just built
    
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback); // data recieved give it to my writecallback function
    
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response); // store the data at response

    CURLcode result = curl_easy_perform(curl); // performs HTTP request

    if(result != CURLE_OK)
    {
        std::cout << "Request Failed: "
                  << curl_easy_strerror(result)
                  << std::endl;
        curl_easy_cleanup(curl);
        return 0;
    }
    
    //std::cout << response << std::endl; debugging checking if response was working
    
    curl_easy_cleanup(curl);

    nlohmann::json data = nlohmann::json::parse(response);
    
    if(data["result"] != "success")
    {
        std::cout << "Invalid currency or API request failed." << std::endl;
        return 0;
    }

    double rate = data["conversion_rate"];
    std::cout << "Current conversion rate: " << rate << std::endl;

    return rate;
}


double convert(double amount, double rate) //get the amount of fromCurrency from user and the rate from getExchangeRateAPI then call this function in main
{
    return amount * rate;
}

