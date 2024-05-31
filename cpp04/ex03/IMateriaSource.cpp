#include "IMateriaSource.hpp"
#include <iostream>

IMateriaSource::IMateriaSource()
{
    for (int i = 0; i < IMateriaSource::materia_max_count_; ++i)
        materia_slots_[i] = NULL;
    std::cout << "IMateriaSource: constructed.\n";
}

IMateriaSource::~IMateriaSource()
{
    for (int i = 0; i < IMateriaSource::materia_max_count_; ++i)
    {
        if (materia_slots_[i])
        {
            delete materia_slots_[i];
            materia_slots_[i] = NULL;
        }
    }
    std::cout << "IMateriaSource: destructed.\n";
}

IMateriaSource::IMateriaSource(const IMateriaSource& other)
{
    for (int i = 0; i < IMateriaSource::materia_max_count_; ++i)
    {
        if (other.materia_slots_[i] == NULL)
            this->materia_slots_[i] = NULL;
        else
            this->materia_slots_[i] = other.materia_slots_[i]->clone();
    }
    std::cout << "IMateriaSource: copy constructed.\n";
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other)
{
    for (int i = 0; i < IMateriaSource::materia_max_count_; ++i)
    {
        if (this->materia_slots_[i])
            delete this->materia_slots_[i];
        if (other.materia_slots_[i] == NULL)
            this->materia_slots_[i] = NULL;
        else
            this->materia_slots_[i] = other.materia_slots_[i]->clone();
    }
    std::cout << "IMateriaSource: copy assigned.\n";
    return *this;
}
