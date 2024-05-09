#include "Zombie.hpp"

zmb::Zombie* zmb::zombieHorde(int N, std::string name)
{
    zmb::Zombie* zombies = new zmb::Zombie[N];
    for (int i = 0; i < N; ++i)
        zombies[i] = zmb::Zombie(name);
    return zombies;
}
