#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>

int main()
{
    Bureaucrat jimmy("Jimmy", 1);
    Bureaucrat ted("Ted", 150);
    std::cout << jimmy << "\n";
    std::cout << ted << "\n\n";
    {
        ShrubberyCreationForm scf("CoolStuff");
        std::cout << scf << "\n";
        try
        {
            scf.execute(jimmy);
        }
        catch (const std::exception& e)
        {
            std::cout << "error: " << e.what() << "\n";
        }
        scf.beSigned(jimmy);
        try
        {
            scf.execute(ted);
        }
        catch (const std::exception& e)
        {
            std::cout << "error: " << e.what() << "\n";
        }
        scf.execute(jimmy);
    }
    std::cout << "\n\n";
    {
        RobotomyRequestForm rqf("Manufacture");
        try
        {
            rqf.execute(jimmy);
        }
        catch (const std::exception& e)
        {
            std::cout << "error: " << e.what() << "\n";
        }
        std::cout << rqf << "\n";
    }
    std::cout << "\n\n";
    {
        PresidentialPardonForm pdf("Trump");
        std::cout << "\n" << pdf << "\n";
    }
    return 0;
}
