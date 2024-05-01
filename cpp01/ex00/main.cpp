#include "Zombie.hpp"

int main()
{
    Zombie* shawn = newZombie("Shawn");
    shawn->announce();
    delete shawn;
    randomChump("Jackson");
    return 0;
}
