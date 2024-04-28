#include "PhoneBook.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

static void rightAlignedWidth10(std::string& content);

/// @brief
/// Display the saved contacts as a list of 4 columns: index, first name, last
/// name and nickname.
/// Each column must be 10 characters wide. A pipe character (’|’) separates
/// them. The text must be right-aligned. If the text is longer than the column,
/// it must be truncated and the last displayable character must be replaced by
/// a dot (’.’).
/// Then, prompt the user again for the index of the entry to display. If the
/// index is out of range or wrong, define a relevant behavior. Otherwise,
/// display the contact information, one field per line.
void PhoneBook::search()
{
    if (displayAddedContacts() == 0)
        displayRequiredContact();
}

int PhoneBook::displayAddedContacts()
{
    int i = 0;

    if (contact_filled_[0])
        std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    else
    {
        std::cout << "No contacts yet, you can add contacts by typing ADD.\n";
        return 1;
    }
    while (i < phone_book_size_ && contact_filled_[i])
    {
        std::cout << '|';
        std::cout << std::setw(10) << std::right << i;
        std::cout << '|';
        rightAlignedWidth10(contacts_[i].first_name_);
        std::cout << '|';
        rightAlignedWidth10(contacts_[i].last_name_);
        std::cout << '|';
        rightAlignedWidth10(contacts_[i].nickname_);
        std::cout << "|\n";
        i++;
    }
    return 0;
}

static void rightAlignedWidth10(std::string& content)
{
    if (content.length() > 10)
    {
        std::cout << std::right << std::setw(9) << content.substr(0, 9);
        std::cout << '.';
    }
    else
        std::cout << std::setw(10) << std::right << content;
}

void PhoneBook::displayRequiredContact()
{
    std::string input;
    int         index;

    std::cout << "Index to check: ";
    std::getline(std::cin, input);
    if (!isdigit(input[0]))
    {
        std::cout << "Unrecognized input.\n";
        return;
    }
    index = atoi(input.c_str());
    if (index < 0 || index >= phone_book_size_)
        std::cout << "Input is out of range.\n";
    else if (contact_filled_[index] == false)
        std::cout << "Index " << index << " is not recorded yet.\n";
    else if (contact_filled_[index] == true)
    { // clang-format off
        std::cout << "First name: " + contacts_[index].first_name_     + '\n'
               + "Last name: "      + contacts_[index].last_name_      + '\n'
               + "Nickname: "       + contacts_[index].nickname_       + '\n'
               + "Phone number: "   + contacts_[index].phone_number_   + '\n'
               + "Darkest secret: " + contacts_[index].darkest_secret_ + '\n';
    } // clang-format on
    else
        std::cout << "Unrecognized input.\n";
}
