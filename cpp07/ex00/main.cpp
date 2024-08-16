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

    a = 2;
    b = 3;
    swap( a, b );
    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "min( a, b ) = " << min( a, b ) << "\n";
    std::cout << "max( a, b ) = " << max( a, b ) << "\n";
    std::string c = "chaine1";
    std::string d = "chaine2";
    swap(c, d);
    std::cout << "c = " << c << ", d = " << d << "\n";
    std::cout << "min( c, d ) = " << ::min( c, d ) << "\n";
    std::cout << "max( c, d ) = " << ::max( c, d ) << "\n";
    return 0;
}
