#include <iostream>

int main()
{
    try
    {
        int Age = 19;
        if (Age >= 18)
            std::cout << "Access granted - you are old enough.\n";
        else
            throw(Age); // When there is not throw, catch block is skipped.
    }
    catch (int Num)
    {
        std::cout << "Access denied - You must be at least 18 years old.\n";
        std::cout << "Age is: " << Num << '\n';
    }

    try
    {
        int age = 15;
        if (age >= 21)
            std::cout << "Access granted - you are old enough.\n";
        else
            throw 505;
    }
    catch (...) // When the throw type is uncertain, use ... to catch any throw
    {
        std::cout << "Access denied - You must be at least 21 years old.\n";
    }
    return 0;
}
