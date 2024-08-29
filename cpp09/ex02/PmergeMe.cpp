#include "PmergeMe.hpp"
#include <algorithm>
#include <stdexcept>
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

    // Insert tails into mains
}

int key(const std::vector<int>& vec)
{
    if (vec.size() == 0)
        throw std::invalid_argument("Vector is empty.");
    return *(--vec.end());
}

void PmergeMe::copyResultToOriginal(VecVecInt& to_sort, const VecVecInt& sorted)
{
    VecVecInt::iterator original_larger_value_with_tails = to_sort.begin();
    VecInt::iterator original_value = original_larger_value_with_tails->begin();

    VecVecInt::const_iterator sorted_larger_value_with_tails = sorted.begin();
    VecInt::const_iterator sorted_value;

    while (sorted_larger_value_with_tails != sorted.end())
    {
        sorted_value = sorted_larger_value_with_tails->begin();
        while (sorted_value != sorted_larger_value_with_tails->end())
        {
            *original_value = *sorted_value;
            ++original_value;
            if (original_value == original_larger_value_with_tails->end())
            {
                ++original_larger_value_with_tails;
                original_value = original_larger_value_with_tails->begin();
            }
            ++sorted_value;
        }
        ++sorted_larger_value_with_tails;
    }
}

void PmergeMe::recursiveSort(VecVecInt& to_sort)
{
    if (to_sort.size() <= 1)
        return;
    else if (to_sort.size() == 2 && key(to_sort[0]) > key(to_sort[1]))
    {
        std::swap(to_sort[0], to_sort[1]);
        return;
    }

    // Group elements into pairs, sort with each pair.
    VecVecInt::iterator smaller = to_sort.begin();
    VecVecInt::iterator larger  = smaller + 1;
    while (smaller != to_sort.end() && larger != to_sort.end())
    {
        if (key(*smaller) > key(*larger))
            std::swap(*smaller, *larger);
        smaller += 2;
        larger += 2;
    }

    // Recursively sort the pairs (of vectors) by the larger element.
    VecVecInt larger_values_with_tails;
    smaller = to_sort.begin();
    larger  = smaller + 1;
    while (smaller != to_sort.end() && larger != to_sort.end())
    {
        larger_values_with_tails.push_back(std::vector<int>());
        VecVecInt::iterator larger_value_with_tails = --larger_values_with_tails
                                                            .end();
        larger_value_with_tails->insert(larger_value_with_tails->end(),
                                        smaller->begin(), smaller->end());
        larger_value_with_tails->insert(larger_value_with_tails->end(),
                                        larger->begin(), larger->end());
        smaller += 2;
        larger += 2;
    }
    recursiveSort(larger_values_with_tails);
    copyResultToOriginal(to_sort, larger_values_with_tails);

    // Insert tails into mains

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
