#include <iostream>
#include "converter.h"
using namespace std;


int currencySwitchNum;
int currencyNum;

double amount;
double converted;

string currencyChoice;
string currencyChoiceSwitch;

int main()
{
    cout << "Please choose the currency you would like to convert."<< '\n' << "0: USD\n"<< '\n' << "1: EUR\n"<< '\n' << "2: JPY\n";
    cin >> currencyNum;
    if(!checkChoices1(currencyNum))
    {
        return 1;
    }

    cout << "Please choose the currency you would like to convert to. "<< '\n' << "0: USD\n"<< '\n' << "1: EUR\n"<< '\n' << "2: JPY\n";
    cin >> currencySwitchNum;
    if(!checkChoices2(currencySwitchNum))
    {
        return 1;
    }
    
    cout << "How much are you looking to convert?." << endl;
    cin >> amount;

    switch(currencyNum){
        case 0:
            currencyChoice = "USD";
        break;
        case 1:
            currencyChoice = "EUR";
        break;    
        case 2:
            currencyChoice = "JPY";
    }
    switch(currencySwitchNum){
        case 0:
            currencyChoiceSwitch = "USD";
        break;
        case 1:
            currencyChoiceSwitch = "EUR";
        break;    
        case 2:
            currencyChoiceSwitch = "JPY";
            break;      
        
    }

    converted = convert(amount,currencyNum,currencySwitchNum);
        cout << "Your converted amount is " << converted << endl;
}

