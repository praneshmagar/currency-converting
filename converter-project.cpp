#include <iostream>
using namespace std;


int currencySwitchNum;
int currencyNum;

double amount;
double converted;

string currencyChoice;
string currencyChoiceSwitch;

double convert(double amount, int currencyNum, int currencySwitchNum);
bool checkChoices1(int currencyNum);
bool checkChoices2(int currencySwitchNum);

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
        cout << amount << " " << currencyChoice << " = " << converted << currencyChoiceSwitch << " " << endl;
}




double convert(double amount, int currencyNum, int currencySwitchNum){    
    if(currencyNum == 0 && currencySwitchNum == 1){   
        double converted = amount*.85;                    // usd  to  eur
        return converted;
    } 
    else if((currencyNum == 1 && currencySwitchNum == 0)){ // eur to usd
        double converted = amount/.85;
        return converted;        
    }
    else if(currencyNum == 0 && currencySwitchNum == 2){ // usd to jpy
        double converted = amount*150;
        return converted;
    } 
    else if((currencyNum == 2 && currencySwitchNum == 0)){ // jpy to usd
        double converted = amount/150;
        return converted;        
    }
    else if(currencyNum == 1 && currencySwitchNum == 2){ // eur to jpy
        double converted = amount*(150/0.85);
        return converted;
    } 
    else if((currencyNum == 2 && currencySwitchNum == 1)){ // jpy to eur
        double converted = amount*(.85/150);
        return converted;        
    }    
    else{ // usd to usd
        double converted = amount;
        return converted;    
    }
}


bool checkChoices1(int currencyNum){
    if(currencyNum < 0 || currencyNum > 2){
        cout << "Please choose a currency listed above" << endl;
        return 0;
    }
    else return 1;
}       

bool checkChoices2(int currencySwitchNum){
    if(currencySwitchNum < 0 || currencySwitchNum > 2){
        cout << "Please choose a currency listed above" << endl;
        return 0;
    }
    else return 1;
}       