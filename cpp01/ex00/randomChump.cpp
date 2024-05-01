#include "Zombie.hpp"

/// \brief Creates a zombie, name it, and the zombie announces itself
/// \param name Name of the zombie.
void randomChump(std::string name)
{
    Zombie new_zombie(name);
    new_zombie.announce();
}
