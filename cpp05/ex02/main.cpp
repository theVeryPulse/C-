#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    {
        ShrubberyCreationForm scf("CoolStuff");
        Bureaucrat            jimmy("Jimmy", 100);
        scf.beSigned(jimmy);
        std::cout << scf << " is signed by " << jimmy << "\n";
    }
    {
        RobotomyRequestForm rqf("Manufacture");
    }
    {
        PresidentialPardonForm pdf("Trump");
        std::cout << pdf << "\n";
    }
    return 0;
}
