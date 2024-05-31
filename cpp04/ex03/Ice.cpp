#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice constructed.\n";
}

Ice::~Ice()
{
    std::cout << "Ice destructed.\n";
}

Ice::Ice(const Ice& other) : AMateria(other.getType())
{
    std::cout << "Ice copy constructed.\n";
}

Ice& Ice::operator=(const Ice& other)
{
    this->setType(other.getType());
    std::cout << "Ice copy assigned.\n";
    return *this;
}

Ice* Ice::clone() const
{
    std::cout << "Ice: cloning.\n";
    Ice* cloned = new Ice();
    std::cout << "Ice: cloned.\n";
    return cloned;
}

void Ice::use(ICharacter& target)
{
    std::cout << "shoots an ice bolt at " << target.getName() << ".\n";
}
