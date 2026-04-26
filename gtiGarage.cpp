#include <iostream>

class car
{
    private :
    double currentSavings;

    public :
    void addMoney(double amount)
    {
        currentSavings = amount;
    }

    void checkStatus()
    {
        std::cout << "The available Balance is : " << currentSavings;

    }
};

int main()
{
    //myCar.currentSavings = 100000; the reason it has errors, the currentSavings variable is Private hence its inaccessible
    car *myCar = new car;
    double amount = 10000;
    myCar -> addMoney(amount);
    myCar -> checkStatus();

    delete myCar;

    return 0;
}