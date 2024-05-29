#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    AMateria(std::string const& type);
    ~AMateria();
    AMateria(const AMateria& other);            // Copy constructor
    AMateria& operator=(const AMateria& other); // Copy assignment operator

    //------------------------------- Functions --------------------------------

    const std::string& getType() const;
    virtual AMateria*  clone() const = 0;
    virtual void       use(ICharacter& target);

    //---------------------------------- Data ----------------------------------

  protected:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

  private:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------

    AMateria::AMateria();

    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

    std::string type_;
};

#endif /* AMATERIA_HPP */
