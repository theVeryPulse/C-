#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

void rightAlignedWidth10(std::string *content)
{
    if ((*content).length() > 10)
    {
        std::cout << std::right << std::setw(9)<< (*content).substr(0, 9);
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
    int i = 0;
    std::string Input;
    int Index;

    if (ContactFilled[0])
        std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    else
    {
        std::cout << "No contacts yet, you can add contacts by typing ADD.\n";
        return;
    }
    while (i < 7 && this->ContactFilled[i])
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

    std::cout << "Index to check: ";
    std::getline(std::cin, Input);
    if (!isdigit(Input[0]))
    {
        std::cout << "Unrecognized input.\n";
        return;
    }
    Index = atoi(Input.c_str());
    if (Index >= 0 && Index <= 7)
    {
        if (this->ContactFilled[Index])
        {
            std::cout << "First name: " + Contacts[Index].FirstName + '\n'
                + "Last name: " + Contacts[Index].LastName + '\n'
                + "Nickname: " +Contacts[Index].Nickname + '\n'
                + "Phone number: " +Contacts[Index].PhoneNumber + '\n'
                + "Darkest secret: " +Contacts[Index].DarkestSecret + '\n';
        }
        else
            std::cout << "Index " << Index << " is not recorded yet.\n";
    }
    else if (Index < 0 || Index > 7)
        std::cout << "Input is out of range.\n";
    else
        std::cout << "Unrecognized input.\n";
}
