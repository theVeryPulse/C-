#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
    is_filled_ = false;
    std::cout << "Initializing contact slot.\n";
}

void Contact::isFilled(bool filled)
{
    is_filled_ = filled;
}

bool Contact::isFilled()
{
    return is_filled_;
}
