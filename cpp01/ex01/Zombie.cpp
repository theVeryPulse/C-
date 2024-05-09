#include "Zombie.hpp"
#include <iostream>

zmb::Zombie::Zombie() : name_("")
{
}

zmb::Zombie::Zombie(std::string name) : name_(name)
{
}

zmb::Zombie::~Zombie()
{
}

void zmb::Zombie::announce() const
{
    std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}
