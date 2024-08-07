#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low.";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed.";
}

AForm::AForm(const std::string& name, int minimal_sign_grade,
           int minimal_execute_grade)
    : name_(name), signed_(false), minimal_sign_grade_(minimal_sign_grade),
      minimal_execute_grade_(minimal_execute_grade)
{
    if (minimal_sign_grade_ < 1 || minimal_execute_grade_ < 1)
        throw GradeTooLowException();
    else if (minimal_sign_grade_ > 150 || minimal_execute_grade_ > 150)
        throw GradeTooHighException();
}

AForm::~AForm()
{
}

AForm::AForm(const AForm& other)
    : name_(other.name_), signed_(other.signed_),
      minimal_sign_grade_(other.minimal_execute_grade_),
      minimal_execute_grade_(other.minimal_execute_grade_)
{
    if (minimal_sign_grade_ < 1 || minimal_execute_grade_ < 1)
        throw GradeTooLowException();
    else if (minimal_sign_grade_ > 150 || minimal_execute_grade_ > 150)
        throw GradeTooHighException();
}

AForm& AForm::operator=(const AForm& other)
{
    if (other.minimal_sign_grade_ < 1 || other.minimal_execute_grade_ < 1)
        throw GradeTooLowException();
    else if (other.minimal_sign_grade_ > 150
             || other.minimal_execute_grade_ > 150)
        throw GradeTooHighException();
    return *this;
}

std::string AForm::getName() const
{
    return name_;
}

bool AForm::getSignedStatus() const
{
    return signed_;
}

void AForm::setSignedStatus(bool new_status)
{
    signed_ = new_status;
}

int AForm::getMinimalSignGrade() const
{
    return minimal_sign_grade_;
}

int AForm::getMinimalExecuteGrade() const
{
    return minimal_execute_grade_;
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "Form name: " << f.getName() << ". "
       << "Minimal sign grade: " << f.getMinimalSignGrade() << ". "
       << "Minimal execute grade: " << f.getMinimalExecuteGrade() << ". "
       << "Signed? " << (f.getSignedStatus() ? "Yes" : "No") << ".";
    return os;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    std::cout << bureaucrat.getName() 
              << " [" << bureaucrat.getGrade() << "] tries to sign "
              << getName() << " (minimal sign grade: "
              << minimal_sign_grade_  << ").\n";
    if (bureaucrat.getGrade() > minimal_sign_grade_)
        throw GradeTooLowException();
    if (signed_ == true)
        return;
    std::cout << "Form " << getName() << " has been signed by "
              << bureaucrat.getName() << ".\n";
    signed_ = true;
}

void AForm::execute(const Bureaucrat& bureaucrat) const
{
    std::cout << bureaucrat.getName() 
              << " [" << bureaucrat.getGrade() << "] tries to execute "
              << getName() << " (minimal execute grade: "
              << minimal_execute_grade_  << ").\n";
    if (signed_ != true)
        throw FormNotSignedException();
    if (bureaucrat.getGrade() > minimal_execute_grade_)
        throw GradeTooLowException();
    executeAction();
}
