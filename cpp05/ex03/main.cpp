#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <exception>

int main()
{
    Bureaucrat jimmy("Jimmy", 1);
    Bureaucrat ted("Ted", 150);
    Intern     intern;
    AForm*     form;
    std::cout << jimmy << "\n";
    std::cout << ted << "\n\n";
    form = intern.makeForm("fire request", "Manufacture");
    {
        form = intern.makeForm("shrubbery creation", "Manufacture");
        // ShrubberyCreationForm scf("CoolStuff");
        std::cout << *form << "\n";
        try
        {
            form->execute(jimmy);
        }
        catch (const std::exception& e)
        {
            std::cout << "error: " << e.what() << "\n";
        }
        form->beSigned(jimmy);
        try
        {
            form->execute(ted);
        }
        catch (const std::exception& e)
        {
            std::cout << "error: " << e.what() << "\n";
        }
        form->execute(jimmy);
        delete form;
    }
    std::cout << "\n\n";
    {
        form = intern.makeForm("robotomy request", "Manufacture");
        try
        {
            form->execute(jimmy);
        }
        catch (const std::exception& e)
        {
            std::cout << "error: " << e.what() << "\n";
        }
        form->beSigned(jimmy);
        form->execute(jimmy);
        delete form;
    }
    std::cout << "\n\n";
    {
        form = intern.makeForm("presidential pardon", "Trump");
        jimmy.executeForm(*form);
        jimmy.signForm(*form);
        ted.executeForm(*form);
        jimmy.executeForm(*form);
        delete form;
    }
    return 0;
}
