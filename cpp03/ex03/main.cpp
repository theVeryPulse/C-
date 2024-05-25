#include "FragTrap.hpp"
#include "Diamond.hpp"
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
    diamond.ClapTrap::attack("DEDEDE");

    return 0;
}
