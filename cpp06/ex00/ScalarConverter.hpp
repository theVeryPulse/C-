#pragma once
#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>

#define TYPE_COUNT 4

class ScalarConverter
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------

    static void convert(const std::string& literal);

    //---------------------------------- Data ----------------------------------

  protected:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------

  private:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------

    typedef bool(*TypeCheck)(const std::string& literal);
    typedef void(*LiteralHandler)(const std::string& literal);
    typedef struct s_TypeHandler
    {
        TypeCheck      is_type;
        LiteralHandler handle_literal;
    } TypeHandler;

    //----------------- Constructors, Assignments, Destructor ------------------

    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);

    //------------------------------- Functions --------------------------------
    //---------------------------------- Data ----------------------------------
};

#endif /* SCALAR_CONVERTER_HPP */
