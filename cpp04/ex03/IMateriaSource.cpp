#include "IMateriaSource.hpp"
#include <iostream>

IMateriaSource::IMateriaSource()
{
    std::cout << "IMateriaSource: constructed.\n";
}

IMateriaSource::~IMateriaSource()
{
    std::cout << "IMateriaSource: destructed.\n";
}

IMateriaSource::IMateriaSource(const IMateriaSource& other)
{
    std::cout << "IMateriaSource: copy constructed.\n";
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other)
{
    std::cout << "IMateriaSource: copy assigned.\n";
}