#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm(target + "_robotomy_request_form", 72, 45), target_(target)
{
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

void RobotomyRequestForm::executeAction() const
{
    std::cout << "[Drilling noise...]\n";
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << target_ << " has been robotomized.\n";
    else
        std::cout << target_ << " has not been robotomized.\n";
}
