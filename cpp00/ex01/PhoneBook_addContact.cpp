#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void PhoneBook::addContact()
{
    if (contact_index_ >= phone_book_size_)
        contact_index_ = 0;
    Contact& target_contact = contacts_[contact_index_++];
    std::cout << "Adding new contact...\n";
    target_contact.isFilled(true);
    fillField(FirstName, target_contact);
    fillField(LastName, target_contact);
    fillField(Nickname, target_contact);
    fillField(PhoneNumber, target_contact);
    fillField(DarkestSecret, target_contact);
    std::cout << "Contact added.\n";
};

void PhoneBook::fillField(const enum Field field, Contact& contact)
{
    std::string  answer = "";
    std::string  prompt = PhoneBook::promptFor(field);
    std::string& slot   = PhoneBook::slotFor(field, contact);
    std::string  input;

    while (std::cin.eof() == false && answer[0] != 'Y' && answer[0] != 'y')
    {
        std::cout << prompt + ": ";
        std::getline(std::cin, input);
        slot = input;
        std::cout << prompt + " is \"" + slot + "\".\nConfirm?(Y/n) ";
        std::getline(std::cin, answer);
    }
}

std::string PhoneBook::promptFor(const enum Field field) const
{
    switch (field)
    {
    case FirstName:
        return "First name";
        break;
    case LastName:
        return "Last name";
        break;
    case Nickname:
        return "Nickname";
        break;
    case PhoneNumber:
        return "Phone number";
        break;
    case DarkestSecret:
        return "Darkest Secret";
        break;
    }
    return "";
}

std::string& PhoneBook::slotFor(const enum Field field,
                                Contact&         ThisContact) const
{
    switch (field)
    {
    case FirstName:
        return ThisContact.first_name_;
        break;
    case LastName:
        return ThisContact.last_name_;
        break;
    case Nickname:
        return ThisContact.nickname_;
        break;
    case PhoneNumber:
        return ThisContact.phone_number_;
        break;
    case DarkestSecret:
        return ThisContact.darkest_secret_;
        break;
    default:
        throw;
    }
}
