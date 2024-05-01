#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
    is_filled_ = false;
    std::cout << "Initializing contact slot.\n";
}

void Contact::setFilled(bool filled)
{
    is_filled_ = filled;
}
