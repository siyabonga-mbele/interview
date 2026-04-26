#include <iostream>

//declaring the function/method
double findHighestPrice(double candles[5]);

int main()
{
    double candles[5];
    double price;

    price = findHighestPrice(candles);

    std::cout << "The Highest Price Action candle is : " << price << std::endl << "The size of candles is : " << sizeof(candles); 
}

double findHighestPrice(double candles[5])
{
    double maxPrice;

    std::cout << "In order to get Price Action, we must find the Highest priced candle out of FIVE candles\n" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Enter the value of candle " << i << " : " << std::endl;
        std::cin >> candles[i];

        //checks whether the candle price is greater than the previous max price
        if (maxPrice < candles[i])
        {
            maxPrice = candles[i];
        }
    }
    
    return maxPrice;
}

