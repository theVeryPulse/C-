#include <iostream>
#include <string>

int main(void)
{
    std::string input;

    while (true)
    {
        std::cout << "Input:\n";
        std::cin >> input;
        std::cout << "Input is " + input + '\n';
    }
    return 0;
}
