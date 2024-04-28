#include <iostream>

int main()
{
    int  a   = 10;
    int* ptr = &a;
    int& ref = a;

    std::cout << a << " = " << *ptr << " = " << ref << '\n';

    return 0;
}
