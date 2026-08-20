#include "converter.h"
#include <iostream>

using namespace std;

double convert(double amount, int currencyNum, int currencySwitchNum)
{
    if (currencyNum == 0 && currencySwitchNum == 1)
    {
        return amount * .85;
    }
    else if (currencyNum == 1 && currencySwitchNum == 0)
    {
        return amount / .85;
    }
    else if (currencyNum == 0 && currencySwitchNum == 2)
    {
        return amount * 150;
    }
    else if (currencyNum == 2 && currencySwitchNum == 0)
    {
        return amount / 150;
    }
    else if (currencyNum == 1 && currencySwitchNum == 2)
    {
        return amount * (150 / .85);
    }
    else if (currencyNum == 2 && currencySwitchNum == 1)
    {
        return amount * (.85 / 150);
    }
    else
    {
        return amount;
    }
}

bool checkChoice(int choice)
{
    if (choice < 0 || choice > 2)
    {
        cout << "Please choose a currency listed above" << endl;
        return 0;
    }
    else
    {
        return 1;
    }
}