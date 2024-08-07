#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& other)
{
    if (this == &other)
        return;
    std::cout << "Intern copy constructor.\n";
}

Intern& Intern::operator=(const Intern& other)
{
    if (this == &other)
        return *this;
    else
        return *this;
}

typedef AForm*(*form_creator)(const std::string& target);

AForm* Intern::makeForm(const std::string& type, const std::string& target)
{
    static const std::string types[3] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    static const form_creator form_creators[3] = {
        &RobotomyRequestForm::create,
        &PresidentialPardonForm::create,
        &ShrubberyCreationForm::create
    };
    for (int i = 0; i < 3; ++i)
    {
        if (type != types[i])
            continue;
        std::cout << "Intern creates " << type << " form.\n";
        return form_creators[i](target);
    }
    std::cout << "Intern cannot create " << type << ": type doesn not exist.\n";
    return NULL;
}
