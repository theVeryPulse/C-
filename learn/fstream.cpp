#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
    std::fstream my_file;

    my_file.open("input.txt");
    if (my_file.is_open())
    {
        my_file << "Hello";
        my_file.close();
    }
    else
        std::cout << "Cannot open file\n";

    my_file.open("input.txt");
    if (my_file.is_open())
    {
        std::string text;

        my_file >> text;
        std::cout << text << '\n';
        my_file.close();
    }
    else
        std::cout << "Cannot open file\n";

    return 0;
}
