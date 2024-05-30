#include "ICharacter.hpp"
#include <iostream>

ICharacter::ICharacter() : name_("Charname")
{
    std::cout << "ICharacter constructed.\n";
}

ICharacter::ICharacter(const std::string& name) : name_(name)
{
    std::cout << "ICharacter constructed.\n";
}

ICharacter::~ICharacter()
{
    std::cout << "ICharacter destructed.\n";
}

ICharacter::ICharacter(const ICharacter& other)
{
    this->name_ = other.name_;
    std::cout << "ICharacter copy constructed.\n";
}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
    this->name_ = other.name_;
    std::cout << "ICharacter copy assigned.\n";
    return *this;
}
