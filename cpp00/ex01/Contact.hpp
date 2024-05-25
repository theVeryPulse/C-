#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

///\brief Contact information: first name, last name, nickname, phone number,
///       and darkest secret
class Contact
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

    Contact();

    void isFilled(bool filled);
    bool isFilled() const;

    void               setFiled(Field field, std::string set_to);
    const std::string& getField(Field field) const;
    std::string&       refField(Field field);

  private:
    bool        is_filled_;
    std::string first_name_;
    std::string last_name_;
    std::string nickname_;
    std::string phone_number_;
    std::string darkest_secret_;
    static int  slot_count_;
};

#endif