#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type_("Animal")
{
}

Animal::Animal(const std::string& type) : type_(type)
{
}

Animal::~Animal()
{
    std::cout << type_ << " (Animal): gone.\n";
}

Animal::Animal(const Animal& other) : type_(other.type_)
{
}

Animal& Animal::operator=(const Animal& other)
{
    type_ = other.type_;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << type_ << " (Animal): making sounding.\n";
}

std::string Animal::getType() const
{
    return type_;
}