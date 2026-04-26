#include <iostream>
#include <vector>
#include <string>
#include "car.h"

void getGTI()
{
    std::cout << "Welcome to Golf GTI 8.5";
}

void display(std::vector<std::string>& garage)
{
    for (const auto car : garage)
    {
        std::cout << car << std::endl;
    }
}