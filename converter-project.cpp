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
 //   if () if api does not recongize students fromCurrency and toCurrency return invalid choice
 //   {
 //       std::cout << "Invalid choice" << std::endl;
 //       return 0;
 //   }



    rate = getExchangeRateAPI(fromCurrency, toCurrency);

    converted = convert(amount, rate); 

    std::cout << amount << std::endl;

    return 0;
}