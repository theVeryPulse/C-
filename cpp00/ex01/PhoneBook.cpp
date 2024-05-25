#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : contact_index_(0)
{
    std::cout << "Welcome to your phone book.\n";
    std::cout << "To start, type in ADD, SEARCH, or EXIT.\n";
}

PhoneBook::~PhoneBook()
{
    std::cout << "Thanks for using Awesome PhoneBook. Goodbye...\n";
}
