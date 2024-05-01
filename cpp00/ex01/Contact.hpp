#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

///\brief Contact information: first name, last name, nickname, phone number,
///       and darkest secret
class Contact
{
  public:
    friend class PhoneBook; // Allows PhoneBook class to access Contact class's
                            // private members.
    Contact();

    void isFilled(bool filled);
    bool isFilled();

  private:
    bool        is_filled_;
    std::string first_name_;
    std::string last_name_;
    std::string nickname_;
    std::string phone_number_;
    std::string darkest_secret_;
};

#endif