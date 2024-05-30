#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure constructed.\n";
}

Cure::~Cure()
{
    std::cout << "Cure destructed.\n";
}

Cure::Cure(const Cure& other) : AMateria(other.getType())
{
    std::cout << "Cure copy constructed.\n";
}

Cure& Cure::operator=(const Cure& other)
{
    this->setType(other.getType());
    std::cout << "Ice copy assigned.\n";
    return *this;
}

Cure* Cure::clone() const
{
    return new Cure();
}
