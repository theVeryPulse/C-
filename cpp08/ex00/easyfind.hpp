#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class ValueNotFound : public std::exception
{
};


template <typename T>
typename T::const_iterator easyfind(const T& container, int n)
{
    if (container.size() == 0)
        throw std::exception();
    for (typename T::const_iterator iter = container.cbegin();
         iter != container.cend(); ++iter)
    {
        if (*iter == n)
            return iter;
    }
    throw ValueNotFound();
}

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
    if (container.size() == 0)
        throw std::exception();
    for (typename T::iterator iter = container.begin();
         iter != container.end(); ++iter)
    {
        if (*iter == n)
            return iter;
    }
    throw ValueNotFound();
}

#endif /* EASYFIND_HPP */


