#include <iostream>
#include <vector>

class TradeLog
{
    private:
    std::vector<std::string> hugeData;

    public:
    TradeLog(int size, int count)
    {
        hugeData.push_back("Mbali"); // allocating 80KB per object
        std::cout << "memory allocated for huge data for " << count << " times." << std::endl;
    }

    /*
    ~TradeLog()
    {
        delete[] hugeData;
    }*/


};

int main()
{
    const int SIZE = 100;
    int count = 0;
    std::cout << "Starting the leak" << std::endl;
    for (int i = 0; i <= SIZE; i++)
    {
        TradeLog *gti = new TradeLog(SIZE, count);
        std::vector<double> number;
        count++;
        

        if (i % SIZE == 0)
        {
            std::cout << "Objects leaked: " << i << std::endl;
        }

    }
    std::cout << "Loop finished RAM is now trapped. Press Enter to close..." << std::endl;
    std::cin.get();
    return 0;
}