#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string name = std::string("Hello") + " hello";
    std::cout << name << '\n';
    char str[] = "content";
    str [0] = 'a';
    std::cout << str << '\n';
    return 0;
}
