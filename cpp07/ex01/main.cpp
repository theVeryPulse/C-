#include "iter.hpp"
#include <cstring>
#include <string>

int main()
{
    char c_ary[] = "char array";
    iter(c_ary, strlen(c_ary), &print);

    std::string string_ary[] = {"String", "Array"};
    iter(string_ary, 2, &print);

    int int_ary[] = {5, 4, 3, 2, 1,};
    iter(int_ary, 5, &print);
    return 0;
}
