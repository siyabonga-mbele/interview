#include <iostream>

class BaseStrategy
{
    public:
    virtual void CheckSignal()
    {
        std::cout<< "this is base strategy" << std::endl;

    }


};

class RSISystem :BaseStrategy // child class that inherits the parent class
{
    public:
    void CheckSignal() override
    {
        std::cout<< "base strategy and RSI" << std::endl;
    }

};

int main()
{
    BaseStrategy *A = new BaseStrategy;
    RSISystem B;

    A->CheckSignal();
    delete A;
    B.CheckSignal();

}