#include "ClapTrap.hpp"

int main()
{
    ClapTrap lucy("Lucy");
    ClapTrap lucy2(lucy);
    ClapTrap ellie("Ellie");
    lucy2 = lucy;

    lucy.attack("Enemy");

    lucy.takeDamage(5);
    lucy.attack("Enemy");

    lucy.takeDamage(3);
    lucy.attack("Enemy");

    lucy.takeDamage(4);
    lucy.attack("Enemy");

    lucy.takeDamage(4);
    lucy.attack("Enemy");

    for (int i = 0; i < 11; ++i)
        lucy2.attack("Zombie");

    for (int i = 0; i < 11; ++i)
        ellie.beRepaired(7);

    return 0;
}
