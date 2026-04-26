#include <iostream>
#include <vector>
#include <string>
#include "car.h"


int main()
{
    std::vector<std::string> garage;
    garage = {"GTI 4", "GTI 5", "GTI 6", "GTI 7.5", "GTI 8", "GTI 8.5"};
    display(garage);
    std::cout << sizeof(garage)<< std::endl;
    garage.erase(garage.begin() + 3);
    display(garage);
    std::cout << sizeof(garage) << std::endl;
    getGTI();
    


    
    return 0;
}