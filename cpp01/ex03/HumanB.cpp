#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name_(name), weapon_(NULL)
{
}

void HumanB::setWeapon(const Weapon& weapon)
{
    weapon_ = &weapon;
}

void HumanB::attack() const
{
    if (weapon_ == NULL)
        std::cout << name_ << " attacks with their hands"
                  << "\n";
    else
        std::cout << name_ << " attacks with their " << weapon_->getType()
                  << "\n";
}
