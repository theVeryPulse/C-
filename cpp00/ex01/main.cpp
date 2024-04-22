#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
    std::string Input;
    PhoneBook MyPhoneBook;

    std::cout << "Welcome to your phone book.\n"
                 "To start, type in ADD, SEARCH, or EXIT.\n";
    while (std::cin.eof() == false)
    {
        std::cout << "> ";
        std::getline(std::cin, Input);
        if (Input == "ADD")
            MyPhoneBook.addContact();
        else if (Input == "SEARCH")
            MyPhoneBook.search();
        else if (Input == "EXIT")
        {
            std::cout << "Good bye...\n";
            return 0;
        }
        else if (!Input.empty())
            std::cout << Input + ": Unrecognized command\n";
        Input = "";
    }
}
