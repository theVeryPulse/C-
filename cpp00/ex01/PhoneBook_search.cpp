#include "PhoneBook.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

static void rightAlignedWidth10(std::string *content)
{
    if ((*content).length() > 10)
    {
        std::cout << std::right << std::setw(9) << (*content).substr(0, 9);
        std::cout << '.';
    }
    else
        std::cout << std::setw(10) << std::right << *content;
}

/**
 * @brief
 * Display the saved contacts as a list of 4 columns: index, first name, last
 * name and nickname.
 * Each column must be 10 characters wide. A pipe character (’|’) separates
 * them. The text must be right-aligned. If the text is longer than the column,
 * it must be truncated and the last displayable character must be replaced by a
 * dot (’.’).
 * Then, prompt the user again for the index of the entry to display. If the
 * index is out of range or wrong, define a relevant behavior. Otherwise,
 * display the contact information, one field per line.
 */
void PhoneBook::search()
{
    if (displayAddedContacts() == 0)
        displayRequiredContact();
}

int PhoneBook::displayAddedContacts()
{
    int i = 0;

    if (ContactFilled[0])
        std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    else
    {
        std::cout << "No contacts yet, you can add contacts by typing ADD.\n";
        return 1;
    }
    while (i < PhoneBookSize && ContactFilled[i])
    {
        std::cout << '|';
        std::cout << std::setw(10) << std::right << i;
        std::cout << '|';
        rightAlignedWidth10(&(Contacts[i].FirstName));
        std::cout << '|';
        rightAlignedWidth10(&(Contacts[i].LastName));
        std::cout << '|';
        rightAlignedWidth10(&(Contacts[i].Nickname));
        std::cout << "|\n";
        i++;
    }
    return 0;
}

void PhoneBook::displayRequiredContact()
{
    std::string Input;
    int Index;

    std::cout << "Index to check: ";
    std::getline(std::cin, Input);
    if (!isdigit(Input[0]))
    {
        std::cout << "Unrecognized input.\n";
        return;
    }
    Index = atoi(Input.c_str());
    if (Index < 0 || Index >= PhoneBookSize)
        std::cout << "Input is out of range.\n";
    else if (ContactFilled[Index] == false)
        std::cout << "Index " << Index << " is not recorded yet.\n";
    else if (ContactFilled[Index] == true)
    { // clang-format off
        std::cout << "First name: " + Contacts[Index].FirstName + '\n'
            + "Last name: " + Contacts[Index].LastName + '\n'
            + "Nickname: " +Contacts[Index].Nickname + '\n'
            + "Phone number: " +Contacts[Index].PhoneNumber + '\n'
            + "Darkest secret: " +Contacts[Index].DarkestSecret + '\n';
    } // clang-format on
    else
        std::cout << "Unrecognized input.\n";
}
