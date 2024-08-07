#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>

int main()
{
    {
        ShrubberyCreationForm scf("CoolStuff");
        Bureaucrat            jimmy("Jimmy", 100);
        std::cout << scf << "\n";
        std::cout << jimmy << "\n";
        try
        {
            std::cout << "Jimmy trying to execute...\n";
            scf.execute(jimmy);
        }
        catch (const std::exception& e)
        {
            std::cout << "error: " << e.what() << "\n";
        }
        scf.beSigned(jimmy);
        Bureaucrat ted("Ted", 150);
        std::cout << ted << "\n";
        try
        {
            std::cout << "Ted trying to execute...\n";
            scf.execute(ted);
        }
        catch (const std::exception& e)
        {
            std::cout << "error: " << e.what() << "\n";
        }
        std::cout << "Jimmy trying to execute...\n";
        scf.execute(jimmy);
    }
    {
        RobotomyRequestForm rqf("Manufacture");
        std::cout << "\n" << rqf << "\n";
    }
    {
        PresidentialPardonForm pdf("Trump");
        std::cout << "\n" << pdf << "\n";
    }
    return 0;
}
