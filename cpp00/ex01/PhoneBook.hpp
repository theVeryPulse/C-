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

    PhoneBook();
    ~PhoneBook();

    void addContact();
    void search() const;

  private:
    // Helper functions for addContact();

    void         fillField(const enum Field field, Contact& contact);
    std::string  promptFor(const enum Field field) const;
    std::string& slotFor(const enum Field field, Contact& contact) const;

    // Helper functions for search();

    int  displayAddedContacts() const;
    void displayRequiredContact() const;

    // Variables

    Contact          contacts_[8];
    int              contact_index_;
    const static int phone_book_size_ = 8;
};

#endif
