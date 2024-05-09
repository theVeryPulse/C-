#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
  public:
    // - types: classes, enums, and aliases (using)
    // - constructors, assignments, destructor
    HumanA();
    ~HumanA();
    HumanA(const HumanA& other); // Copy constructor
    HumanA& operator=(const HumanA& other); // Copy assignment operator
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

#endif /* HUMANA_HPP */