#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
    brain_ = new Brain();
}

Dog::~Dog()
{
    delete brain_;
    std::cout << type_ << " (Dog): gone.\n";
}

Dog::Dog(const Dog& other) : Animal(other.type_)
{
    this->brain_ = new Brain(*(other.brain_));
}

Dog& Dog::operator=(const Dog& other)
{
    this->type_     = other.type_;
    *(this->brain_) = *(other.brain_);
    return *this;
}

void Dog::makeSound() const
{
    std::cout << type_ << " (Dog): woof woof.\n";
}

void Dog::changeIdea(int idx, const std::string& new_idea)
{
    this->brain_->changeIdea(idx, new_idea);
}