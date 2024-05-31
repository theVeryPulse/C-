#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    Character();
    Character(const std::string& name);
    ~Character();
    Character(const Character& other);            // Copy constructor
    Character& operator=(const Character& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    const std::string& getName() const;
    void               equip(AMateria* materia);
    void               unequip(int idx);
    void               use(int idx, ICharacter& target);

    //---------------------------------- Data ----------------------------------

    static const int max_item_count_ = 4;

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

    AMateria* items[4];
};

#endif /* CHARACTER_HPP */
