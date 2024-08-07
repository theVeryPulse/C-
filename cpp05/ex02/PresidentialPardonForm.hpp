#pragma once
#ifndef PRESIDENTIAL_PARDON_HPP
#define PRESIDENTIAL_PARDON_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    PresidentialPardonForm(const std::string& name);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    //------------------------------- Functions --------------------------------

    void beSigned(const Bureaucrat& bureaucrat);

    //---------------------------------- Data ----------------------------------

  protected:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

  private:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    PresidentialPardonForm();

    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------
};

#endif /* PRESIDENTIAL_PARDON_HPP */
