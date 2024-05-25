#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public://=====================================================================
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    FragTrap(const std::string& name);
    ~FragTrap();
    FragTrap(const FragTrap& other); // Copy constructor
    FragTrap& operator=(const FragTrap& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    void highFiveGuys();
    
    //---------------------------------- Data ----------------------------------

  protected://==================================================================
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

  private://====================================================================
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------

    FragTrap();

    //---------------------------------- Data ----------------------------------
};

#endif // FRAGTRAP_HPP