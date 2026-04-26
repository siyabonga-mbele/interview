#include <iostream>
#include "night.h"

struct Trade
{
    std::string pair;
    double entry;
    double stop;
    bool isProfit;

};

//void stopDifference(double entry1, double stop1);

int main()
{
    Trade *cTrade = new Trade;
    cTrade -> pair = "XAUUSD";
    cTrade -> entry = 2150.75;
    cTrade -> stop = 5430.68;



    std::cout << "Pair = " << cTrade -> pair << "\nEntry : " << cTrade -> entry << std::endl;

    double entry1 = 10;
    double stop1 = 30;
    //stopDifference(entry1, stop1);
    sing();


    delete cTrade;
}