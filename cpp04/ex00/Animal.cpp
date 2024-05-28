#include "Animal.hpp"

Animal::Animal() : type_("")
{
}

Animal::~Animal()
{
}

Animal::Animal(const Animal& other) : type_(other.type_)
{
}

Animal& Animal::operator=(const Animal& other)
{
    type_ = other.type_;
    return *this;
}
