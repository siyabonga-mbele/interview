#include <iostream>
#include <vector>


struct Signal
{
    double strength;
    enum TradeType {BUY, SELL, HOLD};
    std::string buy;
    std::string sell;
};

int main()
{
    std::vector<double> history;

    Signal *trade = new Signal;
    trade -> Signal::HOLD;

    int nums[10] = {5, 4, 2, 6, 8, 9, 7, 5, 2, 9};

    for (const auto i : nums)
    {
        trade -> strength = i;
        
        switch (i)
        {
            case 1:
            case 2:
            case 3:
            case 4:
             std::cout << "Low" << trade -> HOLD ;
            break;
            case 5:
            std::cout << "mid";
             break;

            case 6:
            case 7:
            case 8:
            case 9:
             std::cout << "high";
             break;
        }
        
    }

    return 0;
}