#pragma once
#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    RobotomyRequestForm(const std::string& name);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

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

    RobotomyRequestForm();

    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------
};

#endif /* ROBOTOMY_REQUEST_FORM_H */
