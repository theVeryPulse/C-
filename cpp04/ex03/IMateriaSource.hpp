#pragma once
#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    IMateriaSource();
    virtual ~IMateriaSource();
    IMateriaSource(const IMateriaSource& other);
    IMateriaSource& operator=(const IMateriaSource& other);

    //------------------------------- Functions --------------------------------

    virtual void      learnMateria(AMateria*)                = 0;
    virtual AMateria* createMateria(std::string const& type) = 0;

    //---------------------------------- Data ----------------------------------

    static const int materia_max_count_ = 4;

  protected:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

    AMateria* materia_slots_[4];

  private:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------
};

#endif /* IMATERIASOURCE_HPP */
