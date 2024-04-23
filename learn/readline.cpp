#include <iostream>
#include <string>

int main(void)
{
    std::string name;
    std::string address;
    std::string phone_number;

    while (std::cin.eof() == false)
    {
        std::cout << "Name: ";
        std::getline(std::cin, name);
        
        std::cout << "Address: ";
        std::getline(std::cin, address);
        
        std::cout << "Phone number: ";
        std::getline(std::cin, phone_number);
        
        std::cout << name + "\n\t\t" + address + "\n\t\t" + phone_number + "\n";
    }
    return 0;
}
