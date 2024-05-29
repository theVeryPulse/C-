#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    Animal();
    Animal(const std::string& type);
    virtual ~Animal();
    Animal(const Animal& other);            // Copy constructor
    Animal& operator=(const Animal& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    virtual void makeSound() const = 0;
    std::string  getType() const;

    //---------------------------------- Data ----------------------------------

  protected:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

    std::string type_;

  private:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------
};

#endif /* ANIMAL_HPP */
