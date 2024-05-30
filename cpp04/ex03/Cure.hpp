#pragma once
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    Cure();
    ~Cure();
    Cure(const Cure& other);            // Copy constructor
    Cure& operator=(const Cure& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    Cure* clone() const;

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

#endif /* CURE_HPP */
