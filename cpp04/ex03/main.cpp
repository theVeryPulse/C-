#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
    // /*
    {
        Ice*      ice1  = new Ice();
        Cure*     cure1 = new Cure();
        Character steve("Steve");
        Character stan("Stan");
        steve.equip(ice1);
        steve.equip(cure1);
        steve.use(0, stan);
        steve.use(1, stan);

        Ice*  ice1_ptr  = ice1;  // unequipped and on floor
        Cure* cure1_ptr = cure1; // unequipped and on floor
        steve.unequip(0);
        steve.unequip(1);
        steve.unequip(2);
        steve.unequip(3);
        steve.unequip(4);
        std::cout << steve.getName() << ".\n";
        delete ice1_ptr;
        delete cure1_ptr;
    } // */
    {
        Ice*      ice1 = new Ice();
        Character original("original");
        original.equip(ice1);
        std::cout << "------\n";
        Character copy1(original);
        std::cout << "------\n";
        Character copy2 = copy1;
        std::cout << "------\n";
        copy2 = original;
        std::cout << "------\n";
    }
}