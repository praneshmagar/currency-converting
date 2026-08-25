#include "converter.h"
#include <iostream>
#include <string>

int main()
{
    int currencySwitchNum;
    int currencyNum;
    double amount;
    double converted;
    std::string currencyChoice;
    std::string currencyChoiceSwitch;

    std::cout << "Enter the currency you have: " << std::endl;
    std::cout << "0. USD" << std::endl;
    std::cout << "1. EUR" << std::endl;
    std::cout << "2. JPY" << std::endl;
    std::cin >> currencyNum;

    if (!checkChoice(currencyNum))
    {
        std::cout << "Invalid choice" << std::endl;
        return 0;
    }

    if (currencyNum == 0)
    {
        currencyChoice = "USD";
    }
    else if (currencyNum == 1)
    {
        currencyChoice = "EUR";
    }
    else if (currencyNum == 2)
    {
        currencyChoice = "JPY";
    }

    std::cout << "Enter the currency you want to convert to: " << std::endl;
    std::cout << "0. USD" << std::endl;
    std::cout << "1. EUR" << std::endl;
    std::cout << "2. JPY" << std::endl;
    std::cin >> currencySwitchNum;

    if (!checkChoice(currencySwitchNum))
    {
        std::cout << "Invalid choice" << std::endl;
        return 0;
    }

    if (currencySwitchNum == 0)
    {
        currencyChoiceSwitch = "USD";
    }
    else if (currencySwitchNum == 1)
    {
        currencyChoiceSwitch = "EUR";
    }
    else if (currencySwitchNum == 2)
    {
        currencyChoiceSwitch = "JPY";
    }

    std::cout << "Enter the amount you want to convert: ";
    std::cin >> amount;

    converted = convert(amount, currencyNum, currencySwitchNum);

    std::cout << amount << " " << currencyChoice << " = "
              << converted << " " << currencyChoiceSwitch << std::endl;

    return 0;
}