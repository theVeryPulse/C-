#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
    brain_ = new Brain();
}

Cat::~Cat()
{
    delete brain_;
    std::cout << type_ << " (Cat): gone.\n";
}

Cat::Cat(const Cat& other) : Animal(other.type_)
{
    this->brain_ = new Brain(*(other.brain_));
}

Cat& Cat::operator=(const Cat& other)
{
    this->type_     = other.type_;
    *(this->brain_) = *(other.brain_);
    return *this;
}

void Cat::makeSound() const
{
    std::cout << type_ << " (Cat): meow meow.\n";
}

void Cat::changeIdea(int idx, const std::string& new_idea)
{
    this->brain_->changeIdea(idx, new_idea);
}