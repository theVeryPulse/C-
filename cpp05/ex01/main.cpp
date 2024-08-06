#include "Form.hpp"
#include <iostream>

int main()
{
    {
        try
        {
            Form form("form1", 0, 10);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception detected: " << e.what() << '\n';
        }
    }
    {
        try
        {
            Form form("form2", 1, 151);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception detected: " << e.what() << '\n';
        }
    }
    {
        Form form3("Form 3", 15, 25);
        std::cout << form3 << "\n";
    }
    return 0;
}
