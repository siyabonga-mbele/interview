#include <iostream>
#include "night.h"
struct Trade
{
    std::string symbol;
    double entryPrice;
    double stopLoss;
};

//void stopDifference(double entry, double stop);

void sing()
{
    std::cout << "Hello world";
}

int main()
{
    
    Trade *currentTrade = new Trade;

    currentTrade -> symbol = "XAUUSD";
    currentTrade -> entryPrice = 5000;
    currentTrade -> stopLoss = 4940;

    double &entry = currentTrade->entryPrice;
    double &stop = currentTrade->stopLoss;

    stopDifference(entry, stop);

    std::cout << currentTrade->symbol;
    
    
    return 0;
}

void stopDifference(double entry, double stop)
{
    double diff = entry - stop;

    std::cout << "The stop loss difference is " << diff << std::endl;
}