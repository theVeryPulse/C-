#include "Weapon.hpp"

Weapon::Weapon() : type_("no weapon")
{
}

Weapon::Weapon(std::string type) : type_(type)
{
}

const std::string& Weapon::getType() const
{
    return type_;
}

void Weapon::setType(const std::string& type)
{
    type_ = type;
}