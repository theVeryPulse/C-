#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name_(name), grade_(grade)
{
    if (grade_ > 150)
        throw GradeTooLowException();
    else if (grade_ < 1)
        throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name_(other.name_), grade_(other.grade_)
{
    if (grade_ > 150)
        throw GradeTooLowException();
    else if (grade_ < 1)
        throw GradeTooHighException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    grade_ = other.grade_;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return name_;
}

int Bureaucrat::getGrade() const
{
    return grade_;
}

///\brief Increase the Bureaucrat's grade by 1.
///       Example: from 3 to 2, from 10 to 9.
///       Increasing grade 1 Will throw exception.
void Bureaucrat::incrementGrade()
{
    --grade_;
    if (grade_ < 1)
        throw GradeTooHighException();
}

///\brief Decrease the Bureaucrat's grade by 1.
///       Example: from 3 to 4, from 10 to 11.
///       Decreasing grade 150 Will throw exception.
void Bureaucrat::decrementGrade()
{
    ++grade_;
    if (grade_ > 150)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat's grade cannot goes above 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat's grade cannot goes below 150.";
}

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name_ << " signed " << form.getName() << "\n";
    }
    catch (const std::exception& e)
    {
        std::cout << name_ << " couldn'y sign " << form.getName() << " because "
                  << e.what() << "\n";
    }
}
