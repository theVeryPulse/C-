#pragma once
#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T> void iter(T array[], size_t length, void(*f)(T& element))
{
    for (size_t i = 0; i < length; ++i)
        f(array[i]);
}

template <typename T> void print(T value)
{
    std::cout << value << "\n";
}

#endif /* ITER_HPP */