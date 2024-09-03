#include "../PmergeMe.hpp"
#include <stdexcept>
#include <algorithm>

#define PRINT_MESSAGE true

static void checkSortResult(const int* test, size_t len)
{
    std::list<int> check;
    std::list<int> correct;
    for (size_t i = 0; i < len; ++i)
    {
        check.push_back(test[i]);
        correct.push_back(test[i]);
    }
    correct.sort();
    PmergeMe pm;
    pm.sort(check, PRINT_MESSAGE);
    for (std::list<int>::const_iterator a = check.begin(), b = correct.begin();
         a != check.end(); ++a, ++b)
    {
        if (*a != *b)
            throw std::runtime_error("Sort check failed.\n");
    }
}

int main()
{
    int test1[50] = {26, 45, 96, 88, 47, 94, 86, 91, 83, 87, 36, 29, 74,
                     38, 55, 57, 93, 31, 79, 9,  82, 41, 6,  70, 67, 44,
                     98, 23, 95, 15, 46, 49, 32, 77, 68, 16, 80, 37, 99,
                     20, 42, 30, 73, 10, 3,  92, 35, 7,  2,  85};

    checkSortResult(test1, sizeof(test1) / sizeof(test1[0]));

    int test2[47] = {91, 63, 42, 13, 21, 19, 2,  17, 96, 62, 77, 64,
                     43, 52, 95, 49, 27, 51, 8,  65, 1,  57, 50, 26,
                     12, 80, 33, 28, 78, 3,  68, 48, 84, 56, 32, 59,
                     31, 30, 16, 85, 38, 54, 20, 61, 6,  94, 87};

    checkSortResult(test2, sizeof(test2) / sizeof(test2[0]));
    return 0;
}
