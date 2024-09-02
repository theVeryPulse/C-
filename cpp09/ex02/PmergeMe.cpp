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
    {
        // Group elements into pairs, sort with each pair.
        VecInt::iterator smaller = vec.begin();
        VecInt::iterator larger  = smaller + 1;
        while (smaller < vec.end() && larger < vec.end())
        {
            if (*smaller > *larger)
                std::swap(*smaller, *larger);
            smaller += 2;
            larger += 2;
        }
        std::cout << "Sorted in pairs: " << vec << "\n";
    }
    VecInt larger_elements;
    VecInt smaller_elements;
    {
        // Sort the larger element from pairs.
        VecInt::iterator larger = vec.begin() + 1;
        while (larger < vec.end())    
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
        while (larger != larger_elements.end())
        {
            VecInt::iterator smaller;
            smaller = std::find(vec.begin(), vec.end(), *larger) - 1;
            sorted_by_larger.push_back(*smaller);
            smaller_elements.push_back(*smaller);
            sorted_by_larger.push_back(*larger);
            ++larger;
        }
        if (vec.size() % 2 != 0)
            smaller_elements.push_back(*vec.rbegin());
        std::cout << "Sorted by larger elements: " << sorted_by_larger << "\n";
        std::cout << "larger elements[" << larger_elements.size() << "] = "
                << larger_elements << "\n";
        std::cout << "smaller elements[" << smaller_elements.size() << "] = "
                << smaller_elements << "\n";

        for (size_t i = 0; i < sorted_by_larger.size(); ++i)
            vec[i] = sorted_by_larger[i];

    }

    // Insert smaller elements into large elements
    VecInt sorted;
    sorted.push_back(smaller_elements[0]);
    sorted.insert(sorted.end(), larger_elements.begin(), larger_elements.end());
    size_t smaller_elements_left = smaller_elements.size() - 1;
    int insert_group = 2; // first group only has the first smaller
    while (smaller_elements_left > 0)
    {
        size_t first_to_insert = nextToInsert(insert_group) - 1; // -1 to get index from order
        size_t last_to_insert = nextToInsert(insert_group - 1);
        if (first_to_insert > smaller_elements.size() - 1)
            first_to_insert = smaller_elements.size() - 1;
        int elements_in_group = first_to_insert - last_to_insert + 1;
        VecInt::const_iterator smaller = smaller_elements.begin() + first_to_insert;
        size_t index_to_insert = first_to_insert;
        while (elements_in_group > 0)
        {
            std::cout << "next to insert: " << *smaller << "\n";
            VecInt::const_iterator end;
            if (index_to_insert == smaller_elements.size() - 1 
                && smaller_elements.size() % 2 != 0)
                end = sorted.end();
            else
                end = std::find(sorted.begin(), sorted.end(), larger_elements[index_to_insert]);
            VecInt::iterator insert_pos = findInsertPos(sorted.begin(),
                end,
                *smaller);
            sorted.insert(insert_pos, *smaller); //
            std::cout << "after insert: " << sorted << "\n";
            --smaller;
            --elements_in_group;
            --smaller_elements_left;
        }
        ++insert_group;
    } //

    // Copy result to original vector.
    vec = sorted;
}

PmergeMe::VecInt::iterator PmergeMe::findInsertPos(
    VecInt::iterator begin,
    VecInt::const_iterator end,
    const int to_insert)
{
    size_t size = end - begin;
    if (size == 1)
    {
        if (to_insert < *begin)
            return begin;
        else
            return begin + 1;
    }
    else if (size == 2)
    {
        if (to_insert < *begin)
            return begin;
        else if (to_insert < *(begin + 1))
            return begin + 1;
        else
            return begin + 2;
    }
    size_t center_index = size / 2;
    VecInt::iterator center = begin + center_index;
    if (to_insert < *center)
        return (findInsertPos(begin, center, to_insert));
    else // to_insert > *center
        return findInsertPos(center + 1, end, to_insert);
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
