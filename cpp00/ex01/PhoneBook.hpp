#ifndef PHONE_BOOK
#define PHONE_BOOK

#include "Contact.hpp"
#include <string>

enum Field
{
    FirstName,
    LastName,
    Nickname,
    PhoneNumber,
    DarkestSecret
};

class PhoneBook
{
  public:
    Contact Contacts[8];
    bool ContactFilled[8];

    PhoneBook(void)
    {
        ContactIndex = 0;
        for (int i = 0; i < 7; i++)
            ContactFilled[i] = false;
    }
    void addContact(void);
    void search();

  private:
    int ContactIndex;

    void fillField(enum Field Field, Contact *ThisContact);
    std::string promptFor(enum Field Field);
    std::string *slotFor(enum Field Field, Contact *ThisContact);
};

#endif
