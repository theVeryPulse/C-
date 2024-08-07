#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
    return 0;
}
