#pragma once
#ifndef PMERGE_ME_H
#define PMERGE_ME_H

#include <vector>
#include <list>
#include <iostream>

class PmergeMe
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& other); // Copy constructor
    PmergeMe& operator=(const PmergeMe& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    void sort(std::vector<int>& vec);
    void sort(std::list<int>& lst);

    //---------------------------------- Data ----------------------------------

  protected:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

  private:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------

    struct Pair
    {
        int tail;
        int main;
    };

    typedef std::vector<int> VecInt;
    typedef std::vector<std::vector<int> > VecVecInt;

    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------

    void sort(std::vector<Pair>& pairs);
    void recursiveSort(VecInt& larger_elements);
    void copyResultToOriginal(VecVecInt& to_sort, const VecVecInt& sorted);

    //---------------------------------- Data ----------------------------------
};

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec);
std::ostream& operator<<(std::ostream& os, const std::list<int>& lst);

#endif /* PMERGE_ME_H */


