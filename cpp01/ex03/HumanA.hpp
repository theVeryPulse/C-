#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
  public:
    HumanA(const std::string& name, const Weapon& weapon);

    void attack() const;

  private:
    HumanA();

    std::string   name_;
    const Weapon& weapon_;
};

#endif /* HUMANA_HPP */