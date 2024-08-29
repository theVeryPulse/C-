#include "PmergeMe.hpp"
#include <algorithm>
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
    if (vec.size() == 0 || vec.size() == 1)
        return;
    else if (vec.size() == 2 && vec[0] > vec[1])
    {
        std::swap(vec[0], vec[1]);
        return;
    }

    // Group elements into pairs, sort with each pair.
    VecInt::iterator tail = vec.begin();
    VecInt::iterator main = tail + 1;
    while (tail != vec.end() && main != vec.end())
    {
        if (*tail > *main)
            std::swap(*tail, *main);
        tail += 2;
        main += 2;
    }

    // Sort the pairs by the larger element.
    VecVecInt pairs;
    tail = vec.begin();
    main = tail + 1;
    while (tail != vec.end() && main != vec.end())    
    {
        pairs.push_back(std::vector<int>());
        VecVecInt::iterator tails_and_main = --pairs.end();
        tails_and_main->push_back(*tail);
        tails_and_main->push_back(*main);
        tail += 2;
        main += 2;
    }
    recursiveSort(pairs);

    VecInt::iterator original = vec.begin();
    for (VecVecInt::iterator tails_main = pairs.begin();
         tails_main != pairs.end();
         ++tails_main)
    {
        for (VecInt::iterator sorted = tails_main->begin();
             sorted != tails_main->end();
             ++sorted)
        {
            *original = *sorted;
            ++original;
        }
    }
}

void PmergeMe::recursiveSort(VecVecInt& tails_mains)
{
    if (tails_mains.size() == 0 || tails_mains.size() == 1)
        return;
    else if (tails_mains.size() == 2
             && *(--tails_mains[0].end()) > *(--tails_mains[1].end()))
    {
        std::swap(tails_mains[0], tails_mains[1]);
        return;
    }

    // Group elements into pairs, sort with each pair.
    VecVecInt::iterator tail = tails_mains.begin();
    VecVecInt::iterator main = tail + 1;
    while (tail != tails_mains.end() && main != tails_mains.end())
    {
        if (*(--tail->end()) > *(--main->end()))
            std::swap(tail, main);
        tail += 2;
        main += 2;
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
