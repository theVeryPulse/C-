#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <sstream>
#include <string>
#include <climits>
#include <cfloat>

const ScalarConverter::SpecialValue ScalarConverter::special_values[3] = {
    {"nan", "nanf"}, {"+inf", "+inff"}, {"-inf", "-inff"}};

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    if (&other != this)
        std::cout << "Scalar converter copy constructor\n";
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if (&other != this)
        return *this;
    else
        return *this;
}

bool ScalarConverter::isChar(const std::string& literal)
{
    return literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal)
{
    std::istringstream iss(literal);
    int                value;
    return (iss >> value >> std::ws).eof();
}

bool ScalarConverter::isFloat(const std::string& literal)
{
    for (const SpecialValue* special_value = special_values;
         special_value < special_values + 3; ++special_value)
    {
        if (literal == special_value->for_float)
            return true;
    }
    if (*(literal.rbegin()) == 'f' && literal.length() > 1)
        return true;
    return false;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    for (const SpecialValue* special_value = special_values;
         special_value < special_values + 3; ++special_value)
    {
        if (literal == special_value->for_double)
            return true;
    }
    if (literal.find('.') != std::string::npos && isdigit(*(literal.rbegin()))
        && literal.length() >= 3)
        return true;
    return false;
}

static void displayChar(int c)
{
    if (!isascii(c))
        std::cout << "char: impossible\n";
    else if (isprint(c))
        std::cout << "char: '" << static_cast<char>(c) << "'\n";
    else
        std::cout << "char: Non displayable\n";
}

static void displayInt(int n)
{
    std::cout << "int: " << n << "\n";
}

static void displayFloat(float f)
{
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
}

static void displayDouble(double d)
{
    std::cout << "double: " << d << "\n";
}

void ScalarConverter::handleChar(const std::string& literal)
{
    displayChar(literal[0]);
    displayInt(literal[0]);
    displayFloat(literal[0]);
    displayDouble(literal[0]);
}

void ScalarConverter::handleInt(const std::string& literal)
{
    std::istringstream iss(literal);

    int n;
    iss >> n;
    iss.clear();
    iss.seekg(0);

    float f;
    iss >> f;
    iss.clear();
    iss.seekg(0);

    double d;
    iss >> d;

    if (d >= CHAR_MIN && d <= CHAR_MAX)
        displayChar(n);
    else
        std::cout << "char: impossible\n";
    if (d >= INT_MIN && d <= INT_MAX)
        displayInt(n);
    else
        std::cout << "int: impossible\n";
    if (d >= -FLT_MAX && d <= FLT_MAX)
        displayFloat(f);
    else
        std::cout << "float: impossible\n";
    displayDouble(d);
}

void ScalarConverter::handleFloat(const std::string& literal)
{

    for (const SpecialValue* special_value = special_values;
         special_value < special_values + 3; ++special_value)
    {
        if (literal == special_value->for_float)
        {
            std::cout << "char: impossible\n"
                      << "int: impossible\n"
                      << "float: " << special_value->for_float << "\n"
                      << "double: " << special_value->for_double << "\n";
            return;
        }
    }
    std::istringstream iss(literal);

    float f;
    iss >> f;
    iss.clear();
    iss.seekg(0);

    double d;
    iss >> d;
    iss.clear();
    iss.seekg(0);

    if (d >= CHAR_MIN && d <= CHAR_MAX)
        displayChar(static_cast<int>(d));
    else
        std::cout << "char: impossible\n";
    if (d >= INT_MIN && d <= INT_MAX)
        displayInt(static_cast<int>(d));
    else
        std::cout << "int: impossible\n";
    if (d >= -FLT_MAX && d <= FLT_MAX)
        displayFloat(f);
    else
        std::cout << "float: impossible\n";
    displayDouble(d);
}

void ScalarConverter::handleDouble(const std::string& literal)
{
    for (const SpecialValue* special_value = special_values;
         special_value < special_values + 3; ++special_value)
    {
        if (literal == special_value->for_double)
        {
            std::cout << "char: impossible\n"
                      << "int: impossible\n"
                      << "float: " << special_value->for_float << "\n"
                      << "double: " << special_value->for_double << "\n";
            return;
        }
    }
    std::istringstream iss(literal);

    double d;
    iss >> d;
    iss.clear();
    iss.seekg(0);

    float f;
    iss >> f;

    if (d >= CHAR_MIN && d <= CHAR_MAX)
        displayChar(static_cast<int>(d));
    else
        std::cout << "char: impossible\n";
    if (d >= INT_MIN && d <= INT_MAX)
        displayInt(static_cast<int>(d));
    else
        std::cout << "int: impossible\n";
    if (d >= -FLT_MAX && d <= FLT_MAX)
        displayFloat(f);
    else
        std::cout << "float: impossible\n";
    displayDouble(d);
}

void ScalarConverter::convert(const std::string& literal)
{
    static const TypeHandler type_handlers[TYPE_COUNT] = {
        {&isChar, &ScalarConverter::handleChar},
        {&isInt, &ScalarConverter::handleInt},
        {&isFloat, &ScalarConverter::handleFloat},
        {&isDouble, &ScalarConverter::handleDouble}};
    for (const TypeHandler* type_handler = type_handlers;
         type_handler < type_handlers + TYPE_COUNT; ++type_handler)
    {
        if (type_handler->is_type(literal))
        {
            type_handler->handle_literal(literal);
            return;
        }
    }
    std::cout << "Unrecognised input\n";
}
