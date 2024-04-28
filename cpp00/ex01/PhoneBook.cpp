#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void PhoneBook::addContact(void)
{
    if (contact_index_ >= phone_book_size_)
        contact_index_ = 0;
    std::cout << "Adding new contact...\n";
    contact_filled_[contact_index_] = true;
    fillField(FirstName, contacts_[contact_index_]);
    fillField(LastName, contacts_[contact_index_]);
    fillField(Nickname, contacts_[contact_index_]);
    fillField(PhoneNumber, contacts_[contact_index_]);
    fillField(DarkestSecret, contacts_[contact_index_]);
    ++contact_index_;
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

std::string PhoneBook::promptFor(const enum Field field)
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

std::string& PhoneBook::slotFor(const enum Field field, Contact& ThisContact)
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
