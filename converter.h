#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>

double getExchangeRateAPI(std::string fromCurrency, std::string toCurrency);

double convert(double amount, double rate);

#endif