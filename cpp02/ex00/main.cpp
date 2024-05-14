#include "Fixed.hpp"
#include <iostream>

int main()
{
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << "\n";
    std::cout << b.getRawBits() << "\n";
    std::cout << c.getRawBits() << "\n";
    return 0;
}
