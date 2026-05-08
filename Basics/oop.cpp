#include <iostream>

class Trades
{
    private:
    int num = 10;

    public:

    void getnum()
    {
        std::cout << num ;

    }

    void setnum(int s)
    {
        num = s;
    }
};



int main()
{
    Trades t;
    //Trades *f = new Trades;
    
    std::cout << "the first number is: ";
    t.getnum();
    t.setnum(5);
    std::cout << "\nthe updated number is number is: ";
    t.getnum();

    
    return 0;
}