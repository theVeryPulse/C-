#pragma once
#ifndef PHONE_BOOK
#define PHONE_BOOK

#include "Contact.hpp"
#include <string>

class PhoneBook
{
  public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void search() const;

  private:
    // Helper functions for addContact();

    void        fillField(Contact::Field field, Contact& contact);
    std::string promptFor(Contact::Field field) const;

    // Helper functions for search();

    int  displayAddedContacts() const;
    void displayRequiredContact() const;

    // Variables

    Contact          contacts_[8];
    int              contact_index_;
    const static int phone_book_size_ = 8;
};

#endif
