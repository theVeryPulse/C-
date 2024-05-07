#include "Zombie.hpp"

int main()
{
    zmb::Zombie* shawn = zmb::newZombie("Shawn");
    shawn->announce();
    delete shawn;
    zmb::randomChump("Jackson");
    return 0;
}
