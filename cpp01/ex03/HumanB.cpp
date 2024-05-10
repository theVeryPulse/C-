#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name_(name)
{
}

void HumanB::setWeapon(const Weapon& weapon)
{
    weapon_ = &weapon;
}

void HumanB::attack() const
{
    std::cout << name_ << " attacks with their " << weapon_->getType() << "\n";
}
