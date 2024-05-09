#include "Zombie.hpp"

int main()
{
    zmb::Zombie* zombies = zmb::zombieHorde(10, "AAA");
    for (int i = 0; i < 10; ++i)
        zombies[i].announce();
    delete[] zombies;
    return 0;
}
