#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(target + "_presidential_pardon_form", 25, 5), target_(target)
{
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

void PresidentialPardonForm::executeAction() const
{
    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox.\n";
}
