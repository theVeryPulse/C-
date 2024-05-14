#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value_(0)
{
    std::cout << "Fixed: standard constructor.\n";
}

Fixed::Fixed(const Fixed& other) : value_(other.value_)
{
    std::cout << "Fixed: copy constructor.\n";
}

/// @brief 
/// @param value 
/// @note int:   0x7fffffff
///       fixed: 0x7ffffff0
Fixed::Fixed(const int value) : value_(value & integer_part)
{
    std::cout << "Fixed: int constructor.\n";
}

// [ ]
Fixed::Fixed(const float value) : value_(value)
{
    std::cout << "Fixed: float constructor.\n";
}

/// @brief (a).operator= (b)
/// @param other The Fixed object to copy from.
/// @return This object after copy.
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Fixed: copy assignment operator.\n";
    this->value_ = other.value_;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Fixed: destructor.\n";
}

int Fixed::getRawBits() const
{
    std::cout << "Fixed: getRawBits\n";
    return value_;
}

void Fixed::setRawBits(const int raw)
{
    std::cout << "Fixed: setRawBits\n";
    value_ = raw;
}

float Fixed::toFloat() const
{

}

int Fixed::toInt() const
{

}

/// @brief Overload stream `<<` for Fixed class: prints value
/// @param stream 
/// @param fixed 
/// @return 
/// @note https://en.cppreference.com/w/cpp/language/operators
std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
    return stream;
}