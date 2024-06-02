#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    Dog();
    ~Dog();
    Dog(const Dog& other);            // Copy constructor
    Dog& operator=(const Dog& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    void        makeSound() const;
    void        changeIdea(int idx, const std::string& new_idea);
    std::string sayIdea(int idx);

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

    Brain* brain_;

};

#endif /* DOG_HPP */
