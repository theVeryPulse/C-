#pragma once
#ifndef PHONE_BOOK
#define PHONE_BOOK

#include "Contact.hpp"
#include <string>

class PhoneBook
{
  public:
    enum Field
    {
        FirstName,
        LastName,
        Nickname,
        PhoneNumber,
        DarkestSecret
    };

    PhoneBook(void);
    void addContact(void);
    void search();

    Contact contacts_[8];
    bool    contact_filled_[8];

  private:
    // Helper functions for addContact();

    void         fillField(const enum Field field, Contact& contact);
    std::string  promptFor(const enum Field field);
    std::string& slotFor(const enum Field field, Contact& contact);

    // Helper functions for search();

    int  displayAddedContacts();
    void displayRequiredContact();

    int              contact_index_;
    const static int phone_book_size_ = 8;
};

#endif
