#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    Array();
    Array(unsigned int length);
    ~Array();
    Array(const Array& other);            // Copy constructor
    Array& operator=(const Array& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    unsigned int size() const;

    T& operator[](unsigned int index);

    //---------------------------------- Data ----------------------------------

  protected:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

  private:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

    T*           data_;
    unsigned int length_;
};

template <typename T>
Array<T>::Array() : data_(NULL), length_(0)
{
}

template <typename T>
Array<T>::Array(unsigned int length) : length_(length)
{
    data_ = new T[length_];
}

template <typename T>
Array<T>::~Array()
{
    if (data_)
        delete[] data_;
}

template <typename T>
Array<T>::Array(const Array& other) : length_(other.length_)
{
    data_ = new T[length_];
    for (unsigned int i = 0; i < length_; ++i)
        this->data_[i] = other.data_[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    length_ = other.length_;
    if (data_)
        delete[] data_;
    data_ = new T[length_];
    for (unsigned int i = 0; i < length_; ++i)
        this->data_[i] = other.data_[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return length_;
}

template <typename T>
void print(T value)
{
    std::cout << value << "\n";
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= length_)
        throw std::exception();
    return data_[index];
}

#endif /* ARRAY_HPP */