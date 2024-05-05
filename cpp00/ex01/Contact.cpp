#include "Contact.hpp"
#include <iostream>

int Contact::slot_count_ = 0;

Contact::Contact() : is_filled_(false)
{
    std::cout << "Initializing contact slot " << slot_count_ << ".\n";
    slot_count_ += 1;
}

void Contact::isFilled(bool filled)
{
    is_filled_ = filled;
}

bool Contact::isFilled() const
{
    return is_filled_;
}
