#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> int_vec(10);
    int_vec[5] = 42;
    *easyFind(int_vec, 42) = 43;
    easyFind(int_vec, 43);
    std::cout << "No exception, test complete\n";
    return 0;
}
