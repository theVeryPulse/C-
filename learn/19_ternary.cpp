#include <iostream>
#include <string>

int main()
{
    int         a = 1;
    int         b = 2;
    std::string c;

    std::cout << "A is " << a << ". B is " << b << ".\n";
    c = (a > b) ? ("A is greater than B") : ("A is smaller than or equal to B");
    std::cout << c << '\n';
    return 0;
}
