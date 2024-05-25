#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
  public:
    //=============== Types: Classes, Enums, and Aliases (using) ===============
    //================= Constructors, Assignments, Destructor ==================
    // ScavTrap();

    ScavTrap(const std::string& name);
    ~ScavTrap();
    ScavTrap(const ScavTrap& other);            // Copy constructor
    ScavTrap& operator=(const ScavTrap& other); // Copy assignment operator

    //=============================== Functions ================================

    void attack(const std::string& target);
    void guardGate() const;

    //================================== Data ==================================

  protected:
    //=============== Types: Classes, Enums, and Aliases (using) ===============
    //================= Constructors, Assignments, Destructor ==================
    //=============================== Functions ================================
    //================================== Data ==================================

  private:
    //=============== Types: Classes, Enums, and Aliases (using) ===============
    //================= Constructors, Assignments, Destructor ==================
    //=============================== Functions ================================
    //================================== Data ==================================
};

#endif /* SCAVTRAP_HPP */
