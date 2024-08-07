#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& name)
    : AForm(name, 72, 45)
{
    std::cout << "[Drilling noise...]\n";
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << name << " has been robotomized.\n";
    else
        std::cout << name << " has not been robotomized.\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other)
{
    std::cout << "Copy assigned from " << other.getName() << ".\n";
    return *this;
}

/// @brief Lets a bureaucrat sign the robotomy request form. Minimal sign
///        grade: 72, minimal execute grade: 45.
/// @param bureaucrat The bureaucrat to sign the form.
void RobotomyRequestForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= getMinimalSignGrade())
        setSignedStatus(true);
    else
        throw AForm::GradeTooLowException();
}