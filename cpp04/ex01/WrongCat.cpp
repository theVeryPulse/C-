#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
}

WrongCat::~WrongCat()
{
    std::cout << type_ << " (WrongCat): gone.\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other.type_)
{
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    this->type_ = other.type_;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << type_ << " (WrongCat): meow meow.\n";
}