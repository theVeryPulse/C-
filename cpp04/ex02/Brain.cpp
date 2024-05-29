#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain: constructed.\n";
}

Brain::~Brain()
{
    std::cout << "Brain: destructed.\n";
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < Brain::idea_count_; ++i)
        this->ideas_[i] = other.ideas_[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Copying all ideas.\n";
    for (int i = 0; i < Brain::idea_count_; ++i)
        this->ideas_[i] = other.ideas_[i];
    return *this;
}
