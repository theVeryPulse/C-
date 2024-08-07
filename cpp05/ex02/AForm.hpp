#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
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
    class FormNotSignedException : public std::exception
    {
      public:
        const char* what() const throw();
    };

    //----------------- Constructors, Assignments, Destructor ------------------

    AForm(const std::string& name, int minimal_sign_grade,
          int minimal_execute_grade);
    virtual ~AForm();
    AForm(const AForm& other);            // Copy constructor
    AForm& operator=(const AForm& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    std::string  getName() const;
    bool         getSignedStatus() const;
    void         setSignedStatus(bool new_status);
    int          getMinimalSignGrade() const;
    int          getMinimalExecuteGrade() const;
    virtual void beSigned(const Bureaucrat& bureaucrat) = 0;
    void         execute(const Bureaucrat& bureaucrat) const;
    virtual void executeAction() const = 0;

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

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif /* FORM_HPP */
