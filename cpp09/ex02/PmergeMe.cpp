#include "PmergeMe.hpp"
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <iostream>

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

/**
 * @brief Calculates the starting element of next group of insertion. Returns
 *        its order (nth); First outcomes: 1th, 3th, 5th, 11th, 21th, 43th
 *
 * @param nth_group
 * @return int
 * @ref *Art of Computer Programming - Volume 3 (Sorting & Searching)* (p.185)
 *
 */
int PmergeMe::nextToInsert(int nth_group)
{
    int& k(nth_group);
    return (std::pow(2, k + 1) + std::pow(-1, k)) / 3.0;
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

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec)
{
    os << "{";
    for (std::vector<int>::const_iterator num = vec.begin(); num != vec.end();
         ++num)
    {
        if (num != vec.begin())
            os << ", ";
        os << *num;
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::list<int>& lst)
{
    os << "{";
    for (std::list<int>::const_iterator num = lst.begin(); num != lst.end();
         ++num)
    {
        if (num != lst.begin())
            os << ", ";
        os << *num;
    }
    os << "}";
    return os;
}
