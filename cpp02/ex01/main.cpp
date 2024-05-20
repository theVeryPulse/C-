#include "Fixed.hpp"
#include <iostream>

int main()
{
    {
        Fixed       a;
        Fixed const b(-10);
        Fixed const c(-42.42f);
        Fixed const d(b);

        a = Fixed((float)0.43359375);

        std::cout << "a is " << a << "\n";
        std::cout << "b is " << b << "\n";
        std::cout << "c is " << c << "\n";
        std::cout << "d is " << d << "\n";
        std::cout << "a is " << a.toInt() << " as integer" << "\n";
        std::cout << "b is " << b.toInt() << " as integer" << "\n";
        std::cout << "c is " << c.toInt() << " as integer" << "\n";
        std::cout << "d is " << d.toInt() << " as integer" << "\n";
        std::cout << "a > b is " << (a > b) << "\n";
    }
    {
        Fixed a;
        Fixed const b(Fixed(5.05f) * Fixed(2));
        std::cout << a << "\n";
        std::cout << ++a << "\n";
        std::cout << a << "\n";
        std::cout << a++ << "\n";
        std::cout << a << "\n";
        std::cout << b << "\n";
        std::cout << (b / Fixed(2)) << "\n";
        std::cout << (Fixed(5.05f) / Fixed(2)) << "\n";
        std::cout << Fixed::max( a, b ) << "\n";
    }
    return 0;
}