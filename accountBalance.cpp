#include <iostream>

int main()
{
    int savings = 5000;
    //assigning savings address to a pointer ptr
    int* ptr = &savings;

    *ptr = 1500;

    std::cout << "The size of the Pointer is\t\t\t: " << sizeof(*ptr) <<"\nThe address of savings Pointer is\t\t: " << ptr << "\nThe account balance is\t\t\t\t: " << *ptr;


    return 0;
}