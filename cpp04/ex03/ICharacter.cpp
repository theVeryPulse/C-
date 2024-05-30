#include "ICharacter.hpp"
#include <iostream>

ICharacter::ICharacter()
{
    std::cout << "ICharacter constructed.\n";
}

ICharacter::~ICharacter()
{
    std::cout << "ICharacter destructed.\n";
}

ICharacter::ICharacter(const ICharacter& other)
{
    std::cout << "ICharacter copy constructed.\n";
}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
    std::cout << "ICharacter copy assigned.\n";
}
