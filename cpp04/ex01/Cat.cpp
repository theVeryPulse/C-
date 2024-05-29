#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
}

Cat::~Cat()
{
    std::cout << type_ << " (Cat): gone.\n";
}

Cat::Cat(const Cat& other) : Animal(other.type_)
{
}

Cat& Cat::operator=(const Cat& other)
{
    this->type_ = other.type_;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << type_ << " (Cat): meow meow.\n";
}