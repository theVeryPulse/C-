#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
    this->name_ = name;
}

Zombie::~Zombie()
{
    std::cout << "...and " << this->name_ << " is dead...\n";
}

void Zombie::announce()
{
    std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}
