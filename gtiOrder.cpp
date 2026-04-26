#include <iostream>

class Order 
{
    private:
    double * priceHistory;
    int size;

    public :
    Order(int size)
    {
        priceHistory = new double[size];
        std::cout << "memory allocated for trade History" << std::endl;
    }

    ~Order()
    {
        delete[] priceHistory;
        std::cout << "memory cleaned up, RAM is safe" << std::endl;
    }
};

int main()
{
    Order *gti = new Order(4);

    delete gti;



}