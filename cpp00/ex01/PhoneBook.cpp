#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void PhoneBook::addContact(void)
{
    if (ContactIndex >= PhoneBookSize)
        ContactIndex = 0;
    std::cout << "Adding new contact...\n";
    ContactFilled[ContactIndex] = true;
    fillField(FirstName, &Contacts[ContactIndex]);
    fillField(LastName, &Contacts[ContactIndex]);
    fillField(Nickname, &Contacts[ContactIndex]);
    fillField(PhoneNumber, &Contacts[ContactIndex]);
    fillField(DarkestSecret, &Contacts[ContactIndex]);
    ++ContactIndex;
    std::cout << "Contact added.\n";
};

void PhoneBook::fillField(enum Field Field, Contact *ThisContact)
{
    std::string YesNo = "";
    std::string Prompt = PhoneBook::promptFor(Field);
    std::string *Slot = PhoneBook::slotFor(Field, ThisContact);
    std::string Input;

    while (std::cin.eof() == false && YesNo[0] != 'Y' && YesNo[0] != 'y')
    {
        std::cout << Prompt + ": ";
        std::getline(std::cin, Input);
        *Slot = Input;
        std::cout << Prompt + " is \"" + *Slot + "\".\nConfirm?(Y/n) ";
        std::getline(std::cin, YesNo);
    }
}

std::string PhoneBook::promptFor(enum Field Field)
{
    switch (Field)
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

std::string *PhoneBook::slotFor(enum Field Field, Contact *ThisContact)
{
    switch (Field)
    {
    case FirstName:
        return &ThisContact->FirstName;
        break;
    case LastName:
        return &ThisContact->LastName;
        break;
    case Nickname:
        return &ThisContact->Nickname;
        break;
    case PhoneNumber:
        return &ThisContact->PhoneNumber;
        break;
    case DarkestSecret:
        return &ThisContact->DarkestSecret;
        break;
    }
    return NULL;
}
