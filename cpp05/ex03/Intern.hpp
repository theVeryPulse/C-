#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    Intern();
    ~Intern();
    Intern(const Intern& other); // Copy constructor
    Intern& operator=(const Intern& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    AForm* makeForm(const std::string& type, const std::string& target);

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
};

#endif /* INTERN_HPP */
