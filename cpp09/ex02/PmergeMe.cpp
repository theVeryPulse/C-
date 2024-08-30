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
    if (vec.size() <= 1)
        return;
    else if (vec.size() == 2 && vec[0] > vec[1])
    {
        std::swap(vec[0], vec[1]);
        return;
    }

    VecInt::iterator smaller;
    VecInt::iterator larger;

    // Group elements into pairs, sort with each pair.
    smaller = vec.begin();
    larger  = smaller + 1;
    while (smaller != vec.end() && larger != vec.end())
    {
        if (*smaller > *larger)
            std::swap(*smaller, *larger);
        smaller += 2;
        larger += 2;
    }

    // Sort the larger element from pairs.
    VecInt larger_elements;
    larger = vec.begin() + 1;
    while (smaller != vec.end() && larger != vec.end())    
    {
        larger_elements.push_back(*larger);
        larger += 2;
    }
    std::cout << "recursively sort: larger elements[" << larger_elements.size()
              << "] = " << larger_elements << "\n";
    sort(larger_elements);

    // Sort the pairs based on the larger elements
    larger = larger_elements.begin();
    VecInt sorted_by_larger;
    VecInt smaller_elements;
    while (larger != larger_elements.end())
    {
        smaller = std::find(vec.begin(), vec.end(), *larger) - 1;
        sorted_by_larger.push_back(*smaller);
        smaller_elements.push_back(*smaller);
        sorted_by_larger.push_back(*larger);
        ++larger;
    }
    if (vec.size() % 2 != 0)
        smaller_elements.push_back(vec[vec.size() - 1]);

    std::cout << "larger elements[" << larger_elements.size() << "] = "
              << larger_elements << "\n";
    std::cout << "smaller elements[" << smaller_elements.size() << "] = "
              << smaller_elements << "\n";

    for (size_t i = 0; i < sorted_by_larger.size(); ++i)
        vec[i] = sorted_by_larger[i];

    // Insert tails into mains
    size_t smaller_elements_left = smaller_elements.size();
    while (smaller_elements_left > 0)
    {
        (void)nextToInsert(1);

    }
}

void PmergeMe::recursiveSort(VecInt& larger_elements)
{
    (void)larger_elements;
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
