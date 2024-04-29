#include <iostream>

// enum MyChars : char // enum types can be changed
enum MyChars // default type is int
{
    NewLine = '\n',
    Carriage = '\r'
};

int main(int argc, char const *argv[])
{
    /* code */
    std::cout << NewLine << " size is " << sizeof(NewLine) << '\n';
    return 0;
}