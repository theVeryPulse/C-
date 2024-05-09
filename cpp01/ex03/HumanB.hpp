#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
  public:
    // - types: classes, enums, and aliases (using)
    // - constructors, assignments, destructor
    HumanB();
    ~HumanB();
    HumanB(const HumanB& other); // Copy constructor
    HumanB& operator=(const HumanB& other); // Copy assignment operator
    // - functions

    void attack() const;

    // - data

  protected:
    // - types: classes, enums, and aliases (using)
    // - constructors, assignments, destructor
    // - functions
    // - data

  private:
    // - types: classes, enums, and aliases (using)
    // - constructors, assignments, destructor
    // - functions
    // - data

    std::string name_;
    Weapon weapon_;
};

#endif /* HUMANB_HPP */