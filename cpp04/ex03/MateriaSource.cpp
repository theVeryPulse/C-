#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    for (int i = 0; i < IMateriaSource::materia_max_count_; ++i)
        materia_slots_[i] = NULL;
    std::cout << "MateriaSource: constructed.\n";
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource: destructed.\n";
}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource(other)
{
    std::cout << "MateriaSource: copy constructed.\n";
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    this->IMateriaSource::operator=(other);
    std::cout << "MateriaSource: copy assigned.\n";
    return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
    std::cout << "MateriaSource: learning materia: " << materia->getType()
              <<".\n" ;
    if (!materia)
        return;
    const std::string materia_type = materia->getType();
    for (int i = 0; i < IMateriaSource::materia_max_count_; ++i)
    {
        if (materia_slots_[i])
            continue;
        else
        {
            materia_slots_[i] = materia;
            break;
        }
    }
    std::cout << "MateriaSource: learning materia complete.\n" ;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    std::cout << "MateriaSource: creating materia.\n" ;
    for (int i = 0; i < IMateriaSource::materia_max_count_; ++i)
    {
        if (materia_slots_[i]->getType() == type)
            return materia_slots_[i]->clone();
    }
    std::cout << "MateriaSource: creating materia complete.\n" ;
    return NULL;
}
