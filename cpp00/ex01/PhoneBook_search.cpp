#include "PhoneBook.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

static void rightAlignedWidth10(const std::string& content);

/// \brief
/// Display the saved contacts as a list of 4 columns: index, first name, last
/// name and nickname.
/// Each column must be 10 characters wide. A pipe character (’|’) separates
/// them. The text must be right-aligned. If the text is longer than the column,
/// it must be truncated and the last displayable character must be replaced by
/// a dot (’.’).
/// Then, prompt the user again for the index of the entry to display. If the
/// index is out of range or wrong, define a relevant behavior. Otherwise,
/// display the contact information, one field per line.
void PhoneBook::search() const
{
    if (displayAddedContacts() == 0)
        displayRequiredContact();
}

int PhoneBook::displayAddedContacts() const
{
    if (contacts_[0].isFilled())
        std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    else
    {
        std::cout << "No contacts yet, you can add contacts by typing ADD.\n";
        return 1;
    }
    int i = 0;
    while (i < phone_book_size_ && contacts_[i].isFilled())
    {
        std::cout << '|';
        std::cout << std::setw(10) << std::right << i;
        std::cout << '|';
        rightAlignedWidth10(contacts_[i].getField(Contact::FirstName));
        std::cout << '|';
        rightAlignedWidth10(contacts_[i].getField(Contact::LastName));
        std::cout << '|';
        rightAlignedWidth10(contacts_[i].getField(Contact::Nickname));
        std::cout << "|\n";
        i++;
    }
    return 0;
}

static void rightAlignedWidth10(const std::string& content)
{
    if (content.length() > 10)
    {
        std::cout << std::right << std::setw(9) << content.substr(0, 9);
        std::cout << '.';
    }
    else
        std::cout << std::setw(10) << std::right << content;
}

void PhoneBook::displayRequiredContact() const
{
    std::string input;
    int         i;

    std::cout << "Index to check: ";
    std::getline(std::cin, input);
    if (!isdigit(input[0]))
    {
        std::cout << "Unrecognized input.\n";
        return;
    }
    i = atoi(input.c_str());
    if (i < 0 || i >= phone_book_size_)
        std::cout << "Input is out of range.\n";
    else if (contacts_[i].isFilled() == false)
        std::cout << "Index " << i << " is not recorded yet.\n";
    else if (contacts_[i].isFilled() == true)
    {
        std::cout << "First name: " +
                         contacts_[i].getField(Contact::FirstName) + '\n' +
                         "Last name: " +
                         contacts_[i].getField(Contact::LastName) + '\n' +
                         "Nickname: " +
                         contacts_[i].getField(Contact::Nickname) + '\n' +
                         "Phone number: " +
                         contacts_[i].getField(Contact::PhoneNumber) + '\n' +
                         "Darkest secret: " +
                         contacts_[i].getField(Contact::DarkestSecret) + '\n';
    }
    else
        std::cout << "Unrecognized input.\n";
}
