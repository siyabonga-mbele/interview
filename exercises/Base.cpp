#include <iostream>
#include <Base.h>

class Vehicle
{
    private:
    int vin;
    std::string type;

    protected:
    int mileage;
    double tank;
    double value;
    int horsePower;

    public:

    void addMechanic(int vinNo, std::string carType)
    {
        vin = vinNo;
        type = carType;
    }

    virtual void startEngine()
    {
        std::cout << "Hmmmmmmm" << std::endl;
    }


    

};

class GTI : public Vehicle
{
    private:
    int qMile;
    std::string tune;

    public:

    virtual void startEngine() override
    {
        std::cout << "Vrrrr Pha Pha Pha Brrrrrrrrrrrrt" << std::endl;
    }
    
    void race(int score)
    {
        qMile = score;
    }

    void addTune(std::string tuning)
    {
        tune = tuning;
    }

    void addInfo(int miles)
    {
        mileage = miles;
    }
    void carInfo()
    {
        std::cout << "the car mileage is : " << mileage;
    }


};

int main()
{
    GTI *car1 = new GTI;
    Vehicle poloGTI;

    
    int miles = 200304;
    car1 -> addInfo(miles);
    car1 -> carInfo();
    car1 -> startEngine();
    poloGTI.startEngine();

    delete car1;
    
    return 0;
}