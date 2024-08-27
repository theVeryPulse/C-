#include "PmergeMe.hpp"

// =============================================================================
// =============================================================================

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    (void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    (void)other;
    return *this;
}

// =============================================================================
//
// =============================================================================

void PmergeMe::sort(std::vector<int>& vec)
{
    std::vector<int>::iterator a = vec.begin();
    std::vector<int>::iterator b = ++vec.begin();
    while (a != vec.end() && b != vec.end())
    {
        if (*a > *b)
            std::swap(*a, *b);
        a += 2;
        b += 2;
    }
}

void PmergeMe::sort(std::list<int>& lst)
{
    std::list<int>::iterator a = lst.begin();
    std::list<int>::iterator b = ++lst.begin();
    while (a != lst.end() && b != lst.end())
    {
        if (*a > *b)
            std::swap(*a, *b);
        ++(++a);
        ++(++b);
    }
}
