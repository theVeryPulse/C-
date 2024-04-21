#include <iostream>

/* 

Target:

$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *

*/
int main(int argc, char const *argv[])
{
    std::string copy;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; argv[i]; i++)
        {
            copy = argv[i];
            for (int j = 0; copy[j]; j++)
                copy[j] = std::toupper(copy[j]);
            std::cout << copy;
        }
    }
    std::cout << '\n';
    return (0);
}
