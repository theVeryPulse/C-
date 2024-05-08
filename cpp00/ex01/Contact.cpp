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

void Contact::setFiled(Field field, std::string set_to)
{
    switch (field)
    {
    case FirstName:
        first_name_ = set_to;
        break;
    case LastName:
        last_name_ = set_to;
        break;
    case Nickname:
        nickname_ = set_to;
        break;
    case PhoneNumber:
        phone_number_ = set_to;
        break;
    case DarkestSecret:
        darkest_secret_ = set_to;
        break;
    }
}

const std::string& Contact::getField(Field field) const
{
    switch (field)
    {
    case FirstName:
        return first_name_;
        break;
    case LastName:
        return last_name_;
        break;
    case Nickname:
        return nickname_;
        break;
    case PhoneNumber:
        return phone_number_;
        break;
    case DarkestSecret:
        return darkest_secret_;
        break;
    }
}

std::string& Contact::refField(Field field)
{
    switch (field)
    {
    case FirstName:
        return first_name_;
        break;
    case LastName:
        return last_name_;
        break;
    case Nickname:
        return nickname_;
        break;
    case PhoneNumber:
        return phone_number_;
        break;
    case DarkestSecret:
        return darkest_secret_;
        break;
    }
}
