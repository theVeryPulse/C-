#include "Zombie.hpp"

/// \brief Creates a zombie, name it, and return it so you can use it outside
///        of the function scope.
/// \param name Name of the zombie.
/// \return Pointer to the new Zombie object which is dynamically allocated.
zmb::Zombie* zmb::newZombie(std::string name)
{
    zmb::Zombie* new_zombie = new zmb::Zombie(name);
    return new_zombie;
}
