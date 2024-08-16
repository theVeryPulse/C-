#include "whatever.hpp"
#include <iostream>

int main()
{
    int a = 1;
    int b = 2;
    std::cout << "original: " << a << " " << b << "\n";
    swap(a, b);
    std::cout << "swapped: " << a << " " << b << "\n";
    std::cout << "min: " << min(a, b) << "\n";
    std::cout << "max: " << max(a, b) << "\n";
    return 0;
}
