#include "PmergeMe.hpp"
#include <cmath>

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
 *        its order (nth); First outcomes: 1th, 3th, 11th, 21th, 43th
 * 
 * @param nth_group
 * @return int 
 * @ref *Art of Computer Programming - Volume 3 (Sorting & Searching)* (p.185)
 * 
 */
int nextToInsert(int nth_group)
{
    int& k(nth_group);
    return (std::pow(2, k + 1) + std::pow(-1, k)) / 3.0;
}

void PmergeMe::sort(std::vector<int>& vec)
{
    switch (vec.size())
    {
    case 1:
        return;
        break;
    case 2:
        if (vec[0] > vec[1])
        std::swap(vec[0], vec[1]);
        return;
        break;
    default:
        break;
    }

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

void PmergeMe::sortThree(std::vector<int>& vec)
{
    if (vec[0] > vec[1])
        std::swap(vec[0], vec[1]);
    int a = vec[0];
    int b = vec[1];
    int c = vec[2];
    //                           (a < b), insert c
    if (vec[2] < vec[0]) //      (a < b), (c < a)          => (c < a < b)
    {
        vec[0] = c;
        vec[1] = a;
        vec[2] = b;
    }
    else if (vec[2] < vec[1]) // (a < b), (a < c), (c < b) => (a < c < b)
    {
        vec[1] = c;
        vec[2] = b;
    }
    // else: already sorted      (a < b), (a < c), (b < c) => (a < b < c)
}

void PmergeMe::sortFour(std::vector<int>& vec)
{
    (void)vec;
}

void PmergeMe::sortFive(std::vector<int>& vec)
{
    (void)vec;
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
