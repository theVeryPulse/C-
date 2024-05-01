#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    contact_index_ = 0;
    for (int i = 0; i < phone_book_size_; i++)
        contact_filled_[i] = false;
}
