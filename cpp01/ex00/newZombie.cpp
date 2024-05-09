#include "Zombie.hpp"

/// \brief Creates a zombie, name it, and return it so you can use it outside
///        of the function scope.
/// \param name Name of the zombie.
/// \return Pointer to the new Zombie object which is dynamically allocated.
Zombie* newZombie(std::string name)
{
    Zombie* new_zombie = new Zombie(name);
    return new_zombie;
}
