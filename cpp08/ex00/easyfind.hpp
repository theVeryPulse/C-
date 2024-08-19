#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <stdexcept>

class ValueNotFound : public std::exception
{
};

template <typename T>
typename T::const_iterator easyFind(const T& container, int n)
{
    if (container.size() == 0)
        throw std::logic_error("container is empty");
    typename T::const_iterator iter = std::find(container.cbegin(),
                                                container.cend(), n);
    if (*iter != n)
        throw ValueNotFound();
    else
        return iter;
}

template <typename T>
typename T::iterator easyFind(T& container, int n)
{
    if (container.size() == 0)
        throw std::logic_error("container is empty");
    typename T::iterator iter = std::find(container.begin(), container.end(),
                                          n);
    if (*iter != n)
        throw ValueNotFound();
    else
        return iter;
}

#endif /* EASYFIND_HPP */
