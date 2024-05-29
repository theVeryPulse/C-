#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type_("WrongAnimal")
{
}

WrongAnimal::WrongAnimal(const std::string& type) : type_(type)
{
}

WrongAnimal::~WrongAnimal()
{
    std::cout << type_ << ": gone.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type_(other.type_)
{
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    type_ = other.type_;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << type_ << ": making sounding.\n";
}

std::string WrongAnimal::getType() const
{
    return type_;
}