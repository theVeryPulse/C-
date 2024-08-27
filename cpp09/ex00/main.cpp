#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, const char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "error: expects input file name, for example: input.txt\n";
        return 1;
    }

    BitcoinExchange bit_ex;
    try
    {
        bit_ex.readDatabase("data.csv");
        bit_ex.calculateBitcoinValue(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
