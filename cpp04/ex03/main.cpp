#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
    Ice       ice1;
    Cure      cure1;
    Character steve("Steve");
    Character stan("Stan");
    steve.equip(&ice1);
    steve.equip(&cure1);
    steve.use(0, stan);
    steve.use(1, stan);


    steve.unequip(0);
    steve.unequip(1);
    steve.unequip(2);
    steve.unequip(3);
    steve.unequip(4);
}