#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too low.";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too high.";
}

Form::Form(const std::string& name, int minimal_sign_grade,
           int minimal_execute_grade)
    : name_(name), signed_(false), minimal_sign_grade_(minimal_sign_grade),
      minimal_execute_grade_(minimal_execute_grade)
{
    if (minimal_sign_grade_ < 1 || minimal_execute_grade_ < 1)
        throw GradeTooLowException();
    else if (minimal_sign_grade_ > 150 || minimal_execute_grade_ > 150)
        throw GradeTooHighException();
}

Form::~Form()
{
}

Form::Form(const Form& other)
    : name_(other.name_), signed_(other.signed_),
      minimal_sign_grade_(other.minimal_execute_grade_),
      minimal_execute_grade_(other.minimal_execute_grade_)
{
    if (minimal_sign_grade_ < 1 || minimal_execute_grade_ < 1)
        throw GradeTooLowException();
    else if (minimal_sign_grade_ > 150 || minimal_execute_grade_ > 150)
        throw GradeTooHighException();
}

Form& Form::operator=(const Form& other)
{
    if (other.minimal_sign_grade_ < 1 || other.minimal_execute_grade_ < 1)
        throw GradeTooLowException();
    else if (other.minimal_sign_grade_ > 150
             || other.minimal_execute_grade_ > 150)
        throw GradeTooHighException();
    return *this;
}

std::string Form::getName() const
{
    return name_;
}

bool Form::getSigned() const
{
    return signed_;
}

int Form::getMinimalSignGrade() const
{
    return minimal_sign_grade_;
}

int Form::getMinimalExecuteGrade() const
{
    return minimal_execute_grade_;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form name: " << f.getName() << ". "
       << "Minimal sign grade: " << f.getMinimalSignGrade() << ". "
       << "Minimal execute grade: " << f.getMinimalExecuteGrade() << ". "
       << "Signed? " << (f.getSigned() ? "Yes" : "No") << ".";
    return os;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= minimal_sign_grade_)
        signed_ = true;
    else
        throw GradeTooLowException();
}
