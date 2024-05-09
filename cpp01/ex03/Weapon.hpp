#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
  public:
    // - types: classes, enums, and aliases (using)
    // - constructors, assignments, destructor
    Weapon();
    ~Weapon();
    Weapon(const Weapon& other); // Copy constructor
    Weapon& operator=(const Weapon& other); // Copy assignment operator
    // - functions

    const std::string& getType();
    void               setType(std::string type);
    
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
    std::string type_;
};

#endif /* WEAPON_HPP */