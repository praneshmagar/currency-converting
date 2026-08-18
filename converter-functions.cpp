#include <iostream>
#include "converter.h"
using namespace std;

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