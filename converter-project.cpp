#include "converter.h"
#include <iostream>
#include <string>

int main()
{
    double amount;
    double rate;
    std::string fromCurrency;
    std::string toCurrency;
    double converted;

    std::cout << "Enter the currency you have: " << std::endl;
    std::cin >> fromCurrency;


    std::cout << "Enter the currency you want to convert to: " << std::endl;
    std::cin >> toCurrency;

    std::cout << "Enter the amount you want to convert: ";
    std::cin >> amount;

    rate = getExchangeRateAPI(fromCurrency, toCurrency);

    if(rate == 0)
    {
        return 0;
    }

    converted = convert(amount, rate); 
    std::cout << amount << " " << fromCurrency << " = "
        << converted << " " << toCurrency << std::endl;

    return 0;
}