#include "ScalarConverter.hpp"
#include <iostream>
#include <cmath>

int main(int argc, const char** argv)
{
    if (argc == 1)
        return 0;
    else if (argc > 2)
        return 1;
    ScalarConverter::convert(argv[1]);
    return 0;
}