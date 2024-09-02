#include "PmergeMe.hpp"
#include <algorithm>

void PmergeMe::sortWithinPairs(VecInt& nums)
{
    VecInt::iterator smaller = nums.begin();
    VecInt::iterator larger  = smaller + 1;
    while (smaller < nums.end() && larger < nums.end())
    {
        if (*smaller > *larger)
            std::swap(*smaller, *larger);
        smaller += 2;
        larger += 2;
    }
}

void PmergeMe::sort(VecInt& vec, bool print_message)
{
    if (vec.size() <= 1)
        return;
    else if (vec.size() == 2 && vec[0] > vec[1])
    {
        std::swap(vec[0], vec[1]);
        return;
    }
    sortWithinPairs(vec);
    if (print_message)
        std::cout << "Sorted in pairs: " << vec << "\n";
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
        if (print_message)
            std::cout << "recursively sort: larger elements["
                      << larger_elements.size() << "] = " << larger_elements
                      << "\n";
        sort(larger_elements, print_message);
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
        if (print_message)
            std::cout << "Sorted by larger elements: " << sorted_by_larger
                      << "\nlarger elements[" << larger_elements.size() << "]"
                      << " = " << larger_elements << "\n"
                      << "smaller elements[" << smaller_elements.size() << "]"
                      << " = " << smaller_elements << "\n";

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
        size_t first_to_insert = nextToInsert(insert_group) - 1;
        // -1 to get index from order
        if (first_to_insert > smaller_elements.size() - 1)
            first_to_insert = smaller_elements.size() - 1;
        int elements_in_group = first_to_insert + 1
                                - nextToInsert(insert_group - 1);
        VecInt::const_iterator smaller = smaller_elements.begin()
                                         + first_to_insert;
        while (elements_in_group > 0)
        {
            if (print_message)
                std::cout << "next to insert: " << *smaller << "\n";
            VecInt::const_iterator end;
            if (first_to_insert == smaller_elements.size() - 1
                && smaller_elements.size() % 2 != 0)
                end = sorted.end();
            else
                end = std::find(sorted.begin(), sorted.end(),
                                larger_elements[first_to_insert]);
            sorted.insert(findInsertPos(sorted.begin(), end, *smaller),
                          *smaller);
            if (print_message)
                std::cout << "after insert: " << sorted << "\n";
            --smaller;
            --elements_in_group;
            --smaller_elements_left;
        }
        ++insert_group;
    }

    // Copy result to original vector.
    vec = sorted;
}

PmergeMe::VecInt::iterator PmergeMe::findInsertPos(VecInt::iterator       begin,
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
    size_t           center_index = size / 2;
    VecInt::iterator center       = begin + center_index;
    if (to_insert < *center)
        return (findInsertPos(begin, center, to_insert));
    else // to_insert > *center
        return findInsertPos(center + 1, end, to_insert);
}