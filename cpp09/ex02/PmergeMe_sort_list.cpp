#include "PmergeMe.hpp"
#include <algorithm>

// =============================================================================
// Accessing list element by index
// =============================================================================

std::list<int>::iterator indexIter(std::list<int>& lst, size_t index)
{
    if (index > lst.size())
        throw std::runtime_error("Index out of list boundary.");
    std::list<int>::iterator node = lst.begin();
    for (size_t i = 0; i < index; ++i)
        ++node;
    return node;
}

std::list<int>::const_iterator indexIter(const std::list<int>& lst,
                                         size_t                index)
{
    if (index > lst.size())
        throw std::runtime_error("Index out of list boundary.");
    std::list<int>::const_iterator node = lst.begin();
    for (size_t i = 0; i < index; ++i)
        ++node;
    return node;
}

int& indexVal(std::list<int>& lst, size_t index)
{
    return *indexIter(lst, index);
}

const int& indexVal(const std::list<int>& lst, size_t index)
{
    return *indexIter(lst, index);
}

// =============================================================================
// Sort
// =============================================================================

void PmergeMe::sort(ListInt& lst, bool print_message, std::string print_padding)
{
    if (lst.size() <= 1)
        return;
    else if (lst.size() == 2 && lst.front() > lst.back())
    {
        std::swap(lst.front(), lst.back());
        return;
    }

    ListInt::iterator a = lst.begin();
    ListInt::iterator b = ++lst.begin();
    while (a != lst.end() && b != lst.end())
    {
        if (*a > *b)
            std::swap(*a, *b);
        ++(++a);
        ++(++b);
    }

    if (print_message)
        std::cout << print_padding << "Sorted in pairs: " << lst << "\n";

    ListInt larger_elements;
    {
        // Take out the larger elements
        ListInt::const_iterator larger = ++lst.begin();
        size_t                  larger_count = lst.size() / 2;
        while (larger_count > 0)
        {
            larger_elements.push_back(*larger);
            ++(++larger);
            --larger_count;
        }
    }
    {
        if (print_message)
            std::cout << print_padding << "recursively sort: larger elements["
                      << larger_elements.size() << "] = " << larger_elements
                      << "\n";
        sort(larger_elements, print_message, print_padding + "    ");
    }
    ListInt smaller_elements;
    {
        // Sort the larger elemets from pairs
        ListInt::const_iterator larger = larger_elements.begin();
        ListInt                 sorted_by_larger;
        while (larger != larger_elements.end())
        {
            ListInt::const_iterator smaller;
            smaller = --(std::find(lst.begin(), lst.end(), *larger));
            sorted_by_larger.push_back(*smaller);
            smaller_elements.push_back(*smaller);
            sorted_by_larger.push_back(*larger);
            ++larger;
        }
        if (lst.size() % 2 != 0)
            smaller_elements.push_back(lst.back());
        if (print_message)
            std::cout << print_padding
                      << "Sorted by larger elements: " << sorted_by_larger
                      << "\n"
                      << print_padding << "larger elements["
                      << larger_elements.size() << "]"
                      << " = " << larger_elements << "\n"
                      << print_padding << "smaller elements["
                      << smaller_elements.size() << "]"
                      << " = " << smaller_elements << "\n";
    }

    // Insert smaller elements into large elements
    ListInt sorted;
    sorted.push_back(smaller_elements.front());
    size_t smaller_elements_left = smaller_elements.size() - 1;
    sorted.insert(sorted.end(), larger_elements.begin(), larger_elements.end());

    int insert_group = 2;
    while (smaller_elements_left > 0)
    {
        size_t first_to_insert = nextToInsert(insert_group) - 1;
        if (first_to_insert > smaller_elements.size() - 1)
            first_to_insert = smaller_elements.size() - 1;
        int elements_in_group = first_to_insert + 1
                                - nextToInsert(insert_group - 1);
        ListInt::const_iterator smaller = smaller_elements.begin();
        for (size_t i = 0; i < first_to_insert; ++i)
            ++smaller;
        while (elements_in_group > 0)
        {
            if (print_message)
                std::cout << print_padding << "next to insert: " << *smaller
                          << "\n";
            ListInt::const_iterator end;
            if (first_to_insert == smaller_elements.size() - 1
                && smaller_elements.size() != larger_elements.size())
                end = sorted.end();
            else
                end = std::find(sorted.begin(), sorted.end(),
                                indexVal(larger_elements, first_to_insert));
            ListInt::iterator pos = findInsertPos(sorted.begin(), end,
                                                  *smaller);
            sorted.insert(pos, *smaller);
            if (print_message)
                std::cout << print_padding << "after insert: " << sorted
                          << "\n";
            --smaller;
            --elements_in_group;
            --smaller_elements_left;
        }
        ++insert_group;
    }
    lst = sorted;
}

PmergeMe::ListInt::iterator PmergeMe::findInsertPos(ListInt::iterator begin,
                                                    ListInt::const_iterator end,
                                                    const int to_insert)
{
    ListInt::iterator node = begin;
    size_t            size = 0;
    while (node != end)
    {
        ++node;
        ++size;
    }
    if (size == 1)
    {
        if (to_insert < *begin)
            return begin;
        else
            return ++begin;
    }
    else if (size == 2)
    {
        ListInt::iterator middle = begin;
        ++middle;
        ListInt::iterator back = middle;
        ++back;
        if (to_insert < *begin)
            return begin;
        else if (to_insert < *middle)
            return middle;
        else
            return back;
    }
    size_t            center_index = size / 2;
    ListInt::iterator center = begin;
    for (size_t i = 0; i < center_index; ++i)
        ++center;
    if (to_insert < *center)
        return findInsertPos(begin, center, to_insert);
    else // to_insert > *center
        return findInsertPos(++center, end, to_insert);
}
