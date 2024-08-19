#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <stdexcept>

template <typename T>
typename T::const_iterator easyFind(const T& container, int n)
{
    if (container.size() == 0)
        throw std::logic_error("container is empty");
    typename T::const_iterator iter = std::find(container.cbegin(),
                                                container.cend(), n);
    if (*iter != n)
        throw std::runtime_error("easyFind: value not found");
    else
        return iter;
}

template <typename T>
typename T::iterator easyFind(T& container, int n)
{
    if (container.size() == 0)
        throw std::logic_error("container is empty");
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if (*it != n)
        throw std::runtime_error("easyFind: value not found");
    else
        return it;
}

#endif /* EASYFIND_HPP */
