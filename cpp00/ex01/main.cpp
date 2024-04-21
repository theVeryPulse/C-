#include "PhoneBook.hpp"
#include <string>

int main(void) {
  std::string Input;
  PhoneBook MyPhoneBook;

  std::cout << "Welcome to you phone book.\n"
               "To start, type in ADD, SEARCH, or EXIT.\n";
  while (true) {
    std::cout << "> ";
    std::cin >> Input;
    if (Input == "ADD") {
      MyPhoneBook.addContact();
    } else if (Input == "SEARCH") {
      ;
    } else if (Input == "EXIT") {

      return 0;
    } else {
      std::cout << Input + ": Unrecognized command\n";
    }
  }
}
