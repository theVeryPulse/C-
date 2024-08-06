#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class Bureaucrat
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

    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);            // Copy constructor
    Bureaucrat& operator=(const Bureaucrat& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    std::string getName() const;
    int         getGrade() const;
    void        incrementGrade();
    void        decrementGrade();

    //---------------------------------- Data ----------------------------------

  protected:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

  private:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    Bureaucrat();

    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

    const std::string name_;
    // Range [1, 150], attempt to initialize grade_ to invalid value would cause
    // an exception throw
    int grade_;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif /* BUREAUCRAT_HPP */
