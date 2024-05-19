/// \ref http://www.sunshine2k.de/articles/coding/fp/sunfp.html

#include "Fixed.hpp"
#include <iostream>
#include <stdint.h>

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
Fixed::Fixed(const int value) : value_(value << fractional_bits_)
{
    std::cout << "Fixed: int constructor.\n";
}

// [ ]
Fixed::Fixed(const float value)
{
    std::cout << "Fixed: float constructor.\n";

    int   integer_part    = (int)value;
    float fractional_part = value - integer_part;

    value_ = integer_part << Fixed::fractional_bits_;
    value_ += (int)(fractional_part * Fixed::fixed_unit_one_);

    // Alternative approach:
    // float processed_value =
    //     value * float(1 << fractional_bits_) + (value >= 0 ? 0.5F : -0.5F);
    // adding the 0.5 at the end helps to reduce the error
    // value_ = int32_t(processed_value);
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
    return float(value_) / float(Fixed::fixed_unit_one_);
}

/// @brief        0xWWWWWWFF: Whole and fraction
///        Index    3 2 1 0
///               0x00WWWWWW
///        Index    3 2 1 0
/// @return
int Fixed::toInt() const
{
    int int_value = value_ >> Fixed::fractional_bits_;
    if ((value_ & (1 << (Fixed::fractional_bits_ - 1)))
        && value_ & (1 << (Fixed::fractional_bits_ - 2)))
        ++int_value;
    return int_value;
}

/// @brief Overload stream `<<` for Fixed class: prints value
/// @param stream
/// @param fixed
/// @return
/// @note https://en.cppreference.com/w/cpp/language/operators
std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
    stream << "{Fixed value}";
    return stream;
}

Fixed Fixed::operator+(const Fixed& addend)
{
    Fixed sum(this->value_ + addend.value_);
    return sum;
}

Fixed Fixed::operator-(const Fixed& subtrahend)
{
    Fixed difference(this->value_ - subtrahend.value_);
    return difference;
}

Fixed Fixed::operator*(const Fixed& multiplicator)
{
    // When calculating the product as integers, the intermediate value might be
    // too large for int32_t, hence int64_t is used temporarily.
    Fixed product((int32_t)((int64_t)(this->value_ * multiplicator.value_)
                            >> Fixed::fractional_bits_));
    return product;
}

Fixed Fixed::operator/(const Fixed& divisor)
{
    
}
