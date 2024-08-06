#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Form
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------

    class GradeTooHighException : public std::exception
    {
      public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
      public:
        const char* what() const throw();
    };

    //----------------- Constructors, Assignments, Destructor ------------------

    Form(const std::string& name, int minimal_sign_grade,
         int minimal_execute_grade);
    ~Form();
    Form(const Form& other);            // Copy constructor
    Form& operator=(const Form& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    std::string getName() const;
    bool        getSigned() const;
    int         getMinimalSignGrade() const;
    int         getMinimalExecuteGrade() const;
    void        beSigned(const Bureaucrat& bureaucrat);

    //---------------------------------- Data ----------------------------------

  protected:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

  private:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

    const std::string name_;
    bool              signed_;
    const int         minimal_sign_grade_;
    const int         minimal_execute_grade_;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif /* FORM_HPP */
