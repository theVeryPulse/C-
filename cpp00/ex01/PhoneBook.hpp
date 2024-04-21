#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook {
public:
  Contact Contacts[8];
  void addContact(void);
private:
  int ContactIndex = 0;

};

void PhoneBook::addContact() {
  ++ContactIndex;
  if (ContactIndex > 7)
    ContactIndex = 0;
  std::cout << "Adding new contact...\nFirst name: ";
  std::cin >> Contacts[ContactIndex].FirstName;
  std::cout << "Last name: ";
  std::cin >> Contacts[ContactIndex].LastName;
  std::cout << "Nickname: ";
  std::cin >> Contacts[ContactIndex].Nickname;
  std::cout << "Phone number: ";
  std::cin >> Contacts[ContactIndex].PhoneNumber;
  std::cout << "Darkest secret: ";
  std::cin >> Contacts[ContactIndex].DarkestSecret;
};
