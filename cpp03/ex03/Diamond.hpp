#pragma once
#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    DiamondTrap(const std::string& name);
    ~DiamondTrap();
    // Copy constructor
    DiamondTrap(const DiamondTrap& other);
    // Copy assignment operator
    DiamondTrap& operator=(const DiamondTrap& other);

    //------------------------------- Functions --------------------------------

    void attack(const std::string& target);
    void whoAmI();

    //---------------------------------- Data ----------------------------------

  protected:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

  private:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    DiamondTrap();

    //------------------------------- Functions --------------------------------

    std::string name_;

    //---------------------------------- Data ----------------------------------
};

#endif /* DIAMOND_HPP */
