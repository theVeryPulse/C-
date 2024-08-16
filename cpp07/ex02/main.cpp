#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    Array<char> char_array;
    print(char_array.size());

    Array<int> int_array(5);
    int_array[1] = 15;
    print(int_array.size());
    print(int_array[1]);

    const Array<int> const_int_array(int_array);
    print(int_array[1]);

    Array<std::string> string_array(15);
    string_array[0] = "hello";
    string_array[1] = "world";
    print(string_array[0]);
    print(string_array[1]);

    return 0;
}
