#include <iostream>
#include <vector>

struct Account
{
    double balance;
    double margin;

};

bool checkSafety(Account &acc)
{
    int perc = (acc.margin * 100) / acc.balance;
    bool risk;

    if (perc <= 50)
    {
        std::cout << " the lesser (<50) is seen" << std::endl;
        risk = false;
    }
    else if (perc > 50)
    {
        std::cout << " the greater is (>50) seen" << std::endl;
        risk = true;
    }
    std::cout << " the perc value is :" << perc << std::endl;
    std::cout << " the risk value is :" << risk << std::endl;

    return risk;
}

void trade(bool c)
{
    std::cout << "the c bool is " << c << std::endl;
    
    if (c == 1)
    {
        std::cout << "STOP TRADING THE MARGIN IS HIGH!!!" ; 
    }
    else
    {
        std::cout << "You can trade!!";
    }

}


int main()
{
    
    Account *gold = new Account;

    std::cout << "Enter the balance: ";
    std::cin >> gold -> balance;
    
    std::cout << "Enter the margin: ";
    std::cin >> gold -> margin;

    double a = gold -> balance;
    double b = gold -> margin;

    //it gave me an error here because it was checkSafety(a, b)
    bool c = checkSafety(gold);

    trade(c);
    delete gold;
    
    return 0;
}