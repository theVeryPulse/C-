#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    {
        ShrubberyCreationForm scf("CoolStuff");
        Bureaucrat            jimmy("Jimmy", 100);
        std::cout << scf << "\n";
        std::cout << jimmy << "\n";
        scf.beSigned(jimmy);
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
