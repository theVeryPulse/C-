#include "Fixed.hpp"
#include <iostream>

int main()
{
    Fixed test1(0.0059f);
    Fixed test2(2.7f);

    float test_result = test1.toFloat();
    std::cout << "Hello!\n";

    Fixed       a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << "a is " << a << "\n";
    std::cout << "b is " << b << "\n";
    std::cout << "c is " << c << "\n";
    std::cout << "d is " << d << "\n";
    std::cout << "a is " << a.toInt() << " as integer" << "\n";
    std::cout << "b is " << b.toInt() << " as integer" << "\n";
    std::cout << "c is " << c.toInt() << " as integer" << "\n";
    std::cout << "d is " << d.toInt() << " as integer" << "\n";

    return 0;
}