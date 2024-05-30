#include "Character.hpp"
#include <iostream>

Character::Character()
{
    for (int i = 0; i < Character::max_item_count_; ++i)
        items[i] = NULL;
    std::cout << "Character constructed: " << getName() << ".\n";
}

Character::Character(const std::string& name) : ICharacter(name)
{
    for (int i = 0; i < 4; ++i)
        items[i] = NULL;
    std::cout << "Character constructed: " << getName() << ".\n";
}

Character::~Character()
{
    std::cout << "Character destructed: " << getName() << ".\n";
}

Character::Character(const Character& other) : ICharacter(other.name_)
{
    for (int i = 0; i < Character::max_item_count_; ++i)
        items[i] = NULL;
    std::cout << "Character copy constructed: " << getName() << ".\n";
}

Character& Character::operator=(const Character& other)
{
    this->name_ = other.name_;
    std::cout << "Character copy assigned: " << getName() << ".\n";
    return *this;
}

const std::string& Character::getName() const
{
    return this->name_;
}

void Character::equip(AMateria* materia)
{
    if (!materia)
        return;
    for (int i = 0; i < Character::max_item_count_; ++i)
    { // Checks if the item was already equipped
        if (items[i] == materia)
            return;
    }
    for (int i = 0; i < Character::max_item_count_; ++i)
    {
        if (items[i] == NULL)
        {
            items[i] = materia;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= Character::max_item_count_ || items[idx] == NULL)
        return;
    std::cout << name_ << " un-equips " << items[idx]->getType() << ".\n";
    items[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= Character::max_item_count_ || items[idx] == NULL)
        return;
    std::cout << name_ << " ";
    items[idx]->use(target);
}
