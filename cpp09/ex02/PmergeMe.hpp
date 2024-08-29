#pragma once
#ifndef PMERGE_ME_H
#define PMERGE_ME_H

#include <vector>
#include <list>

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
    void recursiveSort(VecVecInt& tails_mains);
    void copyResultToOriginal(VecVecInt& to_sort, const VecVecInt& sorted);

    //---------------------------------- Data ----------------------------------
};


#endif /* PMERGE_ME_H */


