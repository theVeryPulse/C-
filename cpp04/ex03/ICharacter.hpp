#pragma once
#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class AMateria;

class ICharacter
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    ICharacter();
    ICharacter(const std::string& name);
    virtual ~ICharacter();
    ICharacter(const ICharacter& other);            // Copy constructor
    ICharacter& operator=(const ICharacter& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    virtual const std::string& getName() const                  = 0;
    virtual void               equip(AMateria* m)               = 0;
    virtual void               unequip(int idx)                 = 0;
    virtual void               use(int idx, ICharacter& target) = 0;

    //---------------------------------- Data ----------------------------------

  protected:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

    std::string name_;

  private:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------
};

#endif /* ICHARACTER_HPP */
