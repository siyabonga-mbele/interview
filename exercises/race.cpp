#include <iostream>
#include <Base.h>

int check(const int num)
{
    int num2 = 3 + num;
    
    return num2;
}

int main()
{
    const int num = 2;

    int num3 = check(num);

    startEngine();
    
    return 0;
}