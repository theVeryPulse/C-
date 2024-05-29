#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(std::string const& type) : type_(type)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria& other) : type_(other.type_)
{
}

AMateria& AMateria::operator=(const AMateria& other)
{
    this->type_ = other.type_;
    return *this;
}

const std::string& AMateria::getType() const
{
    return type_;
}

void AMateria::use(ICharacter& target)
{
    std::cout << target.getName() << " uses " << type_ << "\n";
}
