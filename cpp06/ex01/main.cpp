#include "Serializer.hpp"
#include "Data.hpp"
#include <stdint.h>
#include <iostream>

int main(void)
{
    Data      data;
    data.char_value = '!';
    uintptr_t a = Serializer::serialize(&data);
    if (Serializer::deserialize(a) == &data)
        std::cout << "same\n";
    else
        std::cout << "not same\n";
    Data& same = *Serializer::deserialize(a);
    std::cout << same.char_value << "\n";

    return 0;
}
