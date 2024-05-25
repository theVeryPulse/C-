#include "FragTrap.hpp"

int main()
{
    FragTrap may("May");
    FragTrap may_copy(may);
    FragTrap temp("Temp");
    temp = may_copy;

    may.attack("Bowser");
    may.beRepaired(100);
    may.takeDamage(50);
    may.highFiveGuys();

    return 0;
}
