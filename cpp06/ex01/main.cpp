#include "Serializer.hpp"
#include "Data.hpp"
#include <stdint.h>
#include <iostream>

int main(void)
{
    Data      data;
    uintptr_t a = Serializer::serialize(&data);
    if (Serializer::deserialize(a) == &data)
        std::cout << "same\n";
    else
        std::cout << "not same\n";
    return 0;
}
