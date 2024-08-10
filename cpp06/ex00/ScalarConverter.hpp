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

    typedef struct s_SpecialValue
    {
        std::string for_double;
        std::string for_float;
    } SpecialValue;

    typedef bool (*TypeCheck)(const std::string& literal);
    typedef void (*LiteralHandler)(const std::string& literal);
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

    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    static void handleChar(const std::string& literal);
    static void handleInt(const std::string& literal);
    static void handleFloat(const std::string& literal);
    static void handleDouble(const std::string& literal);

    //---------------------------------- Data ----------------------------------
    static const SpecialValue special_values[3];
};

#endif /* SCALAR_CONVERTER_HPP */
