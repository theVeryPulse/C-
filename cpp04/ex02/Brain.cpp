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
    for (int i = 0; i < Brain::brain_size_; ++i)
        this->ideas_[i] = other.ideas_[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Copying all ideas.\n";
    for (int i = 0; i < Brain::brain_size_; ++i)
        this->ideas_[i] = other.ideas_[i];
    return *this;
}

void Brain::changeIdea(int idx, const std::string& new_idea)
{
    if (idx < 0 || idx >= Brain::brain_size_)
        return;
    ideas_[idx] = new_idea;
}