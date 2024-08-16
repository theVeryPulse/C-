#pragma once
#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T> void iter(T array[], size_t length, void(*f)(T& element))
{
    for (T* element = array; element < array + length; ++element)
        f(*element);
}

template <typename T> void print(T value)
{
    std::cout << value << "\n";
}

#endif /* ITER_HPP */