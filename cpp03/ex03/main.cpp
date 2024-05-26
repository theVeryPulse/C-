#include "Diamond.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    // FragTrap may("May");
    // FragTrap may_copy(may);
    // FragTrap temp("Temp");
    // temp = may_copy;

    // may.attack("Bowser");
    // may.beRepaired(100);
    // may.takeDamage(50);
    // may.highFiveGuys();
    // std::cout << "FragTrap's destructor> \n";
    // may.~FragTrap();
    // std::cout << "<FragTrap's destructor\n";

    DiamondTrap diamond("Diamond");
    DiamondTrap diamond_copy(diamond);
    DiamondTrap diamond_assign = diamond;
    // Defined in ClapTrap

    diamond.attack("DEDEDE");
    diamond.beRepaired(10);
    diamond.takeDamage(75);

    // Defined in ScavTrap
    diamond.guardGate();

    // Defined in FragTrap
    diamond.highFiveGuys();

    diamond.whoAmI();

    return 0;
}
