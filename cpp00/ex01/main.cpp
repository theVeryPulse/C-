#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
    std::string input;
    PhoneBook   phone_book;

    std::cout << "Welcome to your phone book.\n";
    while (std::cin.eof() == false)
    {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "ADD")
            phone_book.addContact();
        else if (input == "SEARCH")
            phone_book.search();
        else if (input == "EXIT")
            return 0;
        else if (!input.empty())
            std::cout << input + ": Unrecognized command\n";
        input = "";
    }
}
