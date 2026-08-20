#include "converter.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int currencySwitchNum;
    int currencyNum;
    double amount;
    double converted;
    string currencyChoice;
    string currencyChoiceSwitch;

    cout << "Enter the currency you have: " << endl;
    cout << "0. USD" << endl;
    cout << "1. EUR" << endl;
    cout << "2. JPY" << endl;
    cin >> currencyNum;

    if (!checkChoice(currencyNum))
    {
        cout << "Invalid choice" << endl;
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

    cout << "Enter the currency you want to convert to: " << endl;
    cout << "0. USD" << endl;
    cout << "1. EUR" << endl;
    cout << "2. JPY" << endl;
    cin >> currencySwitchNum;

    if (!checkChoice(currencySwitchNum))
    {
        cout << "Invalid choice" << endl;
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

    cout << "Enter the amount you want to convert: ";
    cin >> amount;

    converted = convert(amount, currencyNum, currencySwitchNum);

    cout << amount << " " << currencyChoice << " = "
         << converted << " " << currencyChoiceSwitch << endl;

    return 0;
}