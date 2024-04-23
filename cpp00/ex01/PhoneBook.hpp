#ifndef PHONE_BOOK
#define PHONE_BOOK

#include "Contact.hpp"
#include <string>


class PhoneBook
{
  public:
    Contact contacts_[8];
    bool contact_filled_[8];
    enum Field
    {
        FirstName,
        LastName,
        Nickname,
        PhoneNumber,
        DarkestSecret
    };

    PhoneBook(void)
    {
        contact_index_ = 0;
        for (int i = 0; i < phone_book_size_; i++)
            contact_filled_[i] = false;
    }
    void addContact(void);
    void search();

  private:
    int contact_index_;
    const static int phone_book_size_ = 8;

    // Helper functions for addContact();

    void fillField(enum Field Field, Contact *ThisContact);
    std::string promptFor(enum Field Field);
    std::string *slotFor(enum Field Field, Contact *ThisContact);

    // Helper functions for search();
    
    int displayAddedContacts();
    void displayRequiredContact();
};

#endif
