#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name)
    : AForm(name, 145, 137)
{
    std::string   target = name + "_shrubbery";
    std::ofstream file(target.c_str(), std::ios::out);
    if (!file.is_open())
        throw std::runtime_error("Cannot open file" + target);
    file << "          &&& &&  & &&\n"
         << "      && &\\/&\\|& ()|/ @, &&\n"
         << "      &\\/(/&/&||/& /_/)_&/_&\n"
         << "   &() &\\/&|()|/&\\/ '%\" & ()\n"
         << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
         << "&&   && & &| &| /& & % ()& /&&\n"
         << " ()&_---()&\\&\\|&&-&&--%---()~\n"
         << "     &&     \\|||\n"
         << "             |||\n"
         << "             |||\n"
         << "             |||\n"
         << "       , -=-~  .-^- _\n";
    file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other)
{
    std::cout << "Copy assigned from " << other.getName() << ".\n";
    return *this;
}

/// @brief Lets a bureaucrat sign the shrubbery creation form. Minimal sign
///        grade: 145, minimal execute grade: 137.
/// @param bureaucrat The bureaucrat to sign the form.
void ShrubberyCreationForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= getMinimalSignGrade())
        setSignedStatus(true);
    else
        throw AForm::GradeTooLowException();
}
