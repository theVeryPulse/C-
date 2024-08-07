#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    ShrubberyCreationForm scf("CoolStuff");
    Bureaucrat            jimmy("Jimmy", 150);
    scf.beSigned(jimmy);
    return 0;
}
