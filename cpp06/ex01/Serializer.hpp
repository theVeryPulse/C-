#pragma once
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

struct Data;

class Serializer
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------

    static uintptr_t serialize(Data* ptr);
    static Data*     deserialize(uintptr_t raw);

    //---------------------------------- Data ----------------------------------

  protected:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

  private:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    Serializer();
    Serializer(const Serializer& other); // Copy constructor
    ~Serializer();
    Serializer& operator=(const Serializer& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------
};

#endif /* SERIALIZER_HPP */
