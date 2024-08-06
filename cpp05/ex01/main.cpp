#include "Bureaucrat.hpp"
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
        Bureaucrat jimmy("Jimmy", 20);
        std::cout << jimmy << "\n";
        Form form3("Form 3", 15, 25);
        std::cout << form3 << "\n";
        std::cout << "form3.beSigned(jimmy)>\n";
        try
        {
            form3.beSigned(jimmy);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception detected: " << e.what() << '\n';
        }
        std::cout << "jimmy.signForm(form3)>\n";
        jimmy.signForm(form3);
        Bureaucrat boss("Boss", 1);
        boss.signForm(form3);
    }
    return 0;
}
