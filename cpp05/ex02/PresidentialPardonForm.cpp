#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(target + "_presidential_pardon_form", 25, 5)
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm(other)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& other)
{
    std::cout << "Copy assigned from " << other.getName() << ".\n";
    return *this;
}

/// @brief Lets a bureaucrat sign the robotomy request form. Minimal sign
///        grade: 25, minimal execute grade: 5.
/// @param bureaucrat The bureaucrat to sign the form.
void PresidentialPardonForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= getMinimalSignGrade())
        setSignedStatus(true);
    else
        throw AForm::GradeTooLowException();
}

void PresidentialPardonForm::executeAction() const
{

}