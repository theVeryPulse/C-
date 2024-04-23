#include <iostream>
#include <sstream>
#include <string>

int main(void)
{
    std::string input;
    double length;
    double width;

    std::cout << "Room length: ";
    std::getline(std::cin, input);
    std::stringstream(input) >> length;

    std::cout << "Room width: ";
    std::getline(std::cin, input);
    std::stringstream(input) >> width;

    std::cout << "Room area is " << length * width << "\n";

    return 0;
}
