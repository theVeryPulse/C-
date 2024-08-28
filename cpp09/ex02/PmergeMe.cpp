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
    case 3:
        sortThree(vec);
        break;
    case 4:
        sortFour(vec);
        break;
    case 5:
        sortFive(vec);
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
