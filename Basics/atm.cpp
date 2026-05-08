#include <iostream>

class ATM
{
    private:
    double balance = 0;

    public:

    double bal()
    {
        return balance;
    }    
    void deposit(double &amount)
    {
        balance = balance + amount;
        
    }


};

int display()
{
    
    int num = 0;

    std::cout<< "1. Balance \n2. diposit" << std::endl;
    std::cin >> num;
    return num;

    

};

int main()
{
    int num = display();

    ATM *cap = new ATM;

    double amount, bal = 0;

    switch (num)
    {
        case 1:
        bal += cap->bal();
        std::cout<< "The remaining Balance is :" << bal << std::endl;
        break;
        case 2:
        std::cout<< "Please enter the amount: ";
        std::cin >> amount;

        cap -> deposit(amount);
        bal = cap->bal();
        std::cout<< "deposited amount: "<< amount <<"\nThe remaining Balance is :" << bal << std::endl;
        break;
    }
    return 0;
}