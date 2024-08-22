#pragma once
#ifndef RNP_HPP
#define RNP_HPP

#include <queue>
#include <string>

class RPN
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------

    typedef std::deque<std::string> StringDeque;

    //----------------- Constructors, Assignments, Destructor ------------------

    RPN();
    ~RPN();
    RPN(const RPN& other);            // Copy constructor
    RPN& operator=(const RPN& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    void calculate(const std::string& input);

    //---------------------------------- Data ----------------------------------

    static const std::string valid_symbols_;

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

    StringDeque tokens_;
};

#endif /* RNP_HPP */