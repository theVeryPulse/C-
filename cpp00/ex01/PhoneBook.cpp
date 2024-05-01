#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
    std::cout << "To start, type in ADD, SEARCH, or EXIT.\n";
    contact_index_ = 0;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Thanks for using Awesome PhoneBook. Goodbye...\n";
}
