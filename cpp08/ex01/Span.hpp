#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#ifndef SPAN_TEST
#define SPAN_TEST 0
#endif

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <climits>
#include <cmath>

#if SPAN_TEST
#include <iostream>
#endif

class Span
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    Span();
    Span(unsigned int size);
    ~Span();
    Span(const Span& other);            // Copy constructor
    Span& operator=(const Span& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    void addNumber(int n);
    template <typename InputIterator>
    void         addNumber(InputIterator begin, InputIterator end);
    unsigned int shortestSpan();
    unsigned int longestSpan();

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

    std::vector<int> numbers_;
    unsigned int     size_;
};

template <typename InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end)
{
#if SPAN_TEST
    std::cout << "New size: " << std::distance(begin, end) + numbers_.size()
              << "\n";
#endif
    if (std::distance(begin, end) + numbers_.size() > size_)
        throw std::logic_error("Span: number of elements out of size");
    numbers_.insert(numbers_.end(), begin, end);
}

#endif /* SPAN_HPP */
