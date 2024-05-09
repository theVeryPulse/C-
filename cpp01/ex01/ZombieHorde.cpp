#include "Zombie.hpp"

zmb::Zombie* zmb::zombieHorde(int n, std::string name)
{
    zmb::Zombie* zombies = new zmb::Zombie[n];
    for (int i = 0; i < n; ++i)
        zombies[i] = zmb::Zombie(name);
    return zombies;
}
