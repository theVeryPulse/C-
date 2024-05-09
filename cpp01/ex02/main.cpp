#include <iostream>
#include <string>

int main()
{
    std::string  string    = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << &string << "\n" << &stringPTR << "\n" << &stringREF << "\n";
    std::cout << string << "\n" << *stringPTR << "\n" << stringREF << "\n";

    return 0;
}
