#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name_(name)
{
}

Zombie::~Zombie()
{
    std::cout << "...and " << this->name_ << " is dead...\n";
}

void Zombie::announce() const
{
    std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}
