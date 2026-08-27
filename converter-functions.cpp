#include "converter.h"
#include <iostream>


double getExchangeRateAPI(std::string fromCurrency, std::string toCurrency) //take what fromCurrency user inputs and what toCurrency user inputs then use api to get the rate
{

//libcurl
//api
//extract rate, then double rate
double rate = .75;

//


    return rate; // return the rate of the fromCurrency and toCurrency 
}


double convert(double amount, double rate) //get the amount of fromCurrency from user and the rate from getExchangeRateAPI then call this function in main
{


        return amount * rate;
    }







//bool validCurrency(std::string, std::string) if api does not recongize students fromCurrency and toCurrency return invalid choice
//{
//    if ()
//    {
//       std::cout << "Unrecongized Currenies" << std::endl;
//      return 0;
//    }
//    else
//    {
//        return 1;
//   }
//}