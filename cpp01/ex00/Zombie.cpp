#include "Zombie.hpp"
#include <iostream>

zmb::Zombie::Zombie(std::string name) : name_(name)
{
}

zmb::Zombie::~Zombie()
{
    std::cout << "...and " << this->name_ << " is dead...\n";
}

void zmb::Zombie::announce() const
{
    std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}
