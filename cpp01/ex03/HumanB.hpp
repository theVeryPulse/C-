#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
  public:
    HumanB(const std::string& name);

    void setWeapon(const Weapon& weapon);
    void attack() const;

  private:
    HumanB();

    std::string   name_;
    const Weapon* weapon_;
};

#endif /* HUMANB_HPP */