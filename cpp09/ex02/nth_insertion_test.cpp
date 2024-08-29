#include <cmath>
#include <iostream>
#include <stdexcept>

/**
 * @brief
 *
 * @param nth_insertion
 * @return int
 * @ref *Art of Computer Programming - Volume 3 (Sorting & Searching)* (p.185)
 *
 */
int nextToInsert(int nth_insertion)
{
    int& k(nth_insertion);
    return (std::pow(2, k + 1) + std::pow(-1, k)) / 3.0;
}

template <typename T>
void print(T to_print)
{
    std::cout << to_print << "\n";
}

int main()
{
    for (int n = 2; n < 20; ++n)
    {
        print(nextToInsert(n - 1));
        print(nextToInsert(n));
        std::cout << nextToInsert(n - 1) << "+" << nextToInsert(n) << "="
                  << std::pow(2, n);
        if (nextToInsert(n - 1) + nextToInsert(n) == std::pow(2, n))
            std::cout << ": OK\n";
        else
            throw std::runtime_error("Calculation incorrect.");
    }
}
