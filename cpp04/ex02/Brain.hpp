#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    Brain();
    ~Brain();
    Brain(const Brain& other);            // Copy constructor
    Brain& operator=(const Brain& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    void changeIdea(int idx, const std::string& new_idea);

    //---------------------------------- Data ----------------------------------

    static const int idea_count_ = 100;
    std::string      ideas_[100];

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
};

#endif /* BRAIN_HPP */