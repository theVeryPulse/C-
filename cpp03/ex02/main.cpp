#include "ScavTrap.hpp"

int main()
{
    ScavTrap ellie("Ellie");
    ScavTrap amy("Amy");
    ellie = amy;

    amy.attack("Nazgul");
    amy.beRepaired(15);
    amy.takeDamage(10);

    ScavTrap amy2(amy);
    amy2.attack("Happy");
    amy.guardGate();

    return 0;
}
