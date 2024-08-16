#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> int_vec(10);
    int_vec[5] = 42;
    *easyfind(int_vec, 42) = 43;
    easyfind(int_vec, 43);
    return 0;
}
