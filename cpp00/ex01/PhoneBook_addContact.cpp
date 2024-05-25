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
    fillField(Contact::FirstName, target_contact);
    fillField(Contact::LastName, target_contact);
    fillField(Contact::Nickname, target_contact);
    fillField(Contact::PhoneNumber, target_contact);
    fillField(Contact::DarkestSecret, target_contact);
    std::cout << "Contact added.\n";
};

void PhoneBook::fillField(Contact::Field field, Contact& contact)
{
    std::string answer = "";
    std::string prompt = PhoneBook::promptFor(field);
    std::string input;

    while (std::cin.eof() == false && answer[0] != 'Y' && answer[0] != 'y')
    {
        std::cout << prompt + ": ";
        std::getline(std::cin, input);
        contact.setFiled(field, input);
        std::cout << prompt + " is \"" + contact.getField(field) +
                         "\".\nConfirm?(Y/n) ";
        std::getline(std::cin, answer);
    }
}

std::string PhoneBook::promptFor(Contact::Field field) const
{
    switch (field)
    {
    case Contact::FirstName:
        return "First name";
        break;
    case Contact::LastName:
        return "Last name";
        break;
    case Contact::Nickname:
        return "Nickname";
        break;
    case Contact::PhoneNumber:
        return "Phone number";
        break;
    case Contact::DarkestSecret:
        return "Darkest Secret";
        break;
    }
    return "";
}
