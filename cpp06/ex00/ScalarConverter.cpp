#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <sstream>
#include <string>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    return *this;
}

bool isChar(const std::string& literal)
{
    return literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]);
}

bool isInt(const std::string& literal)
{
    std::istringstream iss(literal);
    int                value;
    return (iss >> value >> std::ws).eof();
}

bool isFloat(const std::string& literal)
{
    return literal == "nanf" || literal == "+inff" || literal == "-inff"
           || (literal.find('f') != std::string::npos && literal.length() > 1);
}

bool isDouble(const std::string& literal)
{
    return literal == "nan" || literal == "+inf" || literal == "-inf"
           || (literal.find('.') != std::string::npos && literal.length() > 2);
}

void displayChar(int c)
{
    if (!isascii(c))
        std::cout << "char: impossible\n";
    else if (isprint(c))
        std::cout << "char: '" << static_cast<char>(c) << "'\n";
    else
        std::cout << "char: Non displayable\n";
}

void displayInt(int n)
{
    std::cout << "int: " << n << "\n";
}

void displayFloat(float f)
{
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
}

void displayDouble(double d)
{
    std::cout << "double: " << d << "\n";
}

void handleChar(const std::string& literal)
{
    char c = literal[0];
    displayChar(c);
    displayInt(static_cast<int>(c));
    displayFloat(static_cast<float>(c));
    displayDouble(static_cast<double>(c));
}

void handleInt(const std::string& literal)
{
    std::istringstream iss(literal);
    int                n;
    iss >> n;
    displayChar(n);
    displayInt(n);
    displayFloat(n);
    displayDouble(n);
}

void handleFloat(const std::string& literal)
{
}

void handleDouble(const std::string& literal)
{
}

void ScalarConverter::convert(const std::string& literal)
{
    static const TypeHandler type_handlers[TYPE_COUNT] = {
        {&isChar, &handleChar},
        {&isInt, &handleInt},
        {&isFloat, &handleFloat},
        {&isDouble, &handleDouble}};
    for (const TypeHandler* type_handler = type_handlers;
         type_handler < type_handlers + TYPE_COUNT; ++type_handler)
    {
        if (type_handler->is_type(literal))
        {
            type_handler->handle_literal(literal);
            break;
        }
    }

    // 1. Identify the type
    // 2. Handle each type
    // 3. Handle special cases
}