#include <iostream>
#include <string>

// Base class
class Vehicle
{
  public:
    std::string Brand = "Ford";

    void honk()
    {
        std::cout << "Tuut, tuut! \n";
    }
};

class Tractor
{
  public:
    std::string Brand = "Porsche";

    void honk()
    {
        std::cout << "BUBUBUBU\n";
    }
};

// Derived class
class Car : public Vehicle
{
  public:
    std::string model = "Mustang";
};

int main()
{
    Car MyCar;
    MyCar.honk();
    std::cout << MyCar.Brand + " " + MyCar.model + '\n';
    return 0;
}
