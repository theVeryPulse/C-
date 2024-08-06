#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    {
        try
        {
            Bureaucrat jimmy("Jimmy", 0);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception detected: " << e.what() << '\n';
        }
    }
    {
        try
        {
            Bureaucrat jimmy("Jimmy", 5);
            for (int i = 0; i < 5; ++i)
            {
                std::cout << jimmy << "\n";
                jimmy.incrementGrade();
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception detected: " << e.what() << '\n';
        }
    }
    {
        try
        {
            Bureaucrat jimmy("Jimmy", 146);
            for (int i = 0; i < 5; ++i)
            {
                std::cout << jimmy << "\n";
                jimmy.decrementGrade();
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception detected: " << e.what() << '\n';
        }
    }
    return 0;
}
