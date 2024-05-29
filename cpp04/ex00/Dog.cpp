#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
}

Dog::~Dog()
{
    std::cout << type_ << " (Dog): gone.\n";
}

Dog::Dog(const Dog& other) : Animal(other.type_)
{
}

Dog& Dog::operator=(const Dog& other)
{
    this->type_ = other.type_;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << type_ << " (Dog): woof woof.\n";
}
