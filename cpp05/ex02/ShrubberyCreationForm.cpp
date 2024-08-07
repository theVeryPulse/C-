#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(target + "_shrubbery_creation_form", 145, 137), target_(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target_(other.target_)
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

void ShrubberyCreationForm::executeAction() const
{
    std::string   filename = target_ + "_shrubbery";
    std::ofstream file(filename.c_str(), std::ios::out);
    if (!file.is_open())
        throw std::runtime_error("Cannot open file" + filename);
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
    std::cout << "Executed, check file: ./" << filename << "\n"; 
}

