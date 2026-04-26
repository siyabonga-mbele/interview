#include <iostream>
#include <string>
#include <vector>

void profit(std::vector<double>& num);
void positive(std::vector<double>& num);

int main()
{
    std::vector<double> num = {10.5, -5.2, 15.0, 0.0, -2.5};
    profit(num);
    positive(num);
    return 0;
}


void profit(std::vector<double>& num)
{
    double total = 0; 
    
    for (int i = 0; i < 5; i++)
    {
        total += num[i];
    }
    std::cout<< "The profits for today are :"<< total << " Pips" << std::endl;
}

void positive(std::vector<double>& num)
{
    
    std::cout<< "this are only positive Pips : ";
    for (const auto pip : num)
    {
        if (pip >=0)
        {
            std::cout<< ", " << pip;
        }
    }
}