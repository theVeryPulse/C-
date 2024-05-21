/// \ref http://www.sunshine2k.de/articles/coding/fp/sunfp.html

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <stdint.h>
#include <string>

/*
================================================================================
==================== Constructors, Assignments, Destructor =====================
================================================================================
*/

Fixed::Fixed() : value_(0)
{
    // std::cout << "Fixed: standard constructor.\n";
}

Fixed::Fixed(const Fixed& other) : value_(other.value_)
{
    // std::cout << "Fixed: copy constructor.\n";
}

/// @brief
/// @param value
Fixed::Fixed(const int value) : value_(value << fractional_bits_)
{
    // std::cout << "Fixed: int constructor: " << value << ".\n";
}

Fixed::Fixed(const float value)
{
    // std::cout << "Fixed: float constructor: " << value << "\n";

    int   integer_part    = (int)value;
    float fractional_part = value - integer_part;

    value_ = integer_part << Fixed::fractional_bits_;
    value_ += (int)(fractional_part * Fixed::fixed_unit_one_
                    + (value >= 0 ? 0.5F : -0.5F));
    // adding the 0.5 at the end helps to reduce the error
}

/// @brief (a).operator= (b)
/// @param other The Fixed object to copy from.
/// @return This object after copy.
Fixed& Fixed::operator=(const Fixed& other)
{
    // std::cout << "Fixed: copy assignment operator.\n";
    this->value_ = other.value_;
    return *this;
}

Fixed::~Fixed()
{
    // std::cout << "Fixed: destructor.\n";
}

int Fixed::getRawBits() const
{
    // std::cout << "Fixed: getRawBits\n";
    return value_;
}

void Fixed::setRawBits(const int raw)
{
    // std::cout << "Fixed: setRawBits\n";
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

void Fixed::printValue(std::ostream& stream) const
{
    int integer_part = toInt();
    stream << integer_part;
    int fractional_part =
        std::abs(value_ - (integer_part * Fixed::fixed_unit_one_));
    if (!fractional_part)
        return;
    stream << '.' << (int64_t)fractional_part * (int64_t)390625;
    // smallest unit of 8 bits fraction is 2^(-8) = 0.00390625
    // 390625 is hence chosen as the base for calculating the fractional
    // representation
}

/*
================================================================================
============================== Operator Overload ===============================
================================================================================
*/

/// @brief Overload stream `<<` for Fixed class: prints value
/// @param stream
/// @param fixed
/// @return
/// @note https://en.cppreference.com/w/cpp/language/operators
std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
    fixed.printValue(stream);
    return stream;
}

Fixed& Fixed::operator+=(const Fixed& added)
{
    this->value_ += added.value_;
    return *this;
}

Fixed& Fixed::operator-=(const Fixed& subtrahend)
{
    this->value_ -= subtrahend.value_;
    return *this;
}

Fixed& Fixed::operator*=(const Fixed& multiplicator)
{
    this->value_ =
        (int32_t)(((int64_t)this->value_ * (int64_t)multiplicator.value_)
                  >> Fixed::fractional_bits_);
    return *this;
}

Fixed& Fixed::operator/=(const Fixed& divisor)
{
    if (divisor.value_ == 0)
        throw std::invalid_argument("Division by zero");
    this->value_ =
        (int32_t)(((int64_t)this->value_ << fractional_bits_) / divisor.value_);
    return *this;
}

Fixed Fixed::operator+(const Fixed& addend) const
{
    Fixed sum;
    sum.setRawBits(this->value_ + addend.value_);
    return sum;
}

Fixed Fixed::operator-(const Fixed& subtrahend) const
{
    Fixed difference;
    difference.setRawBits(this->value_ - subtrahend.value_);
    return difference;
}

Fixed Fixed::operator*(const Fixed& multiplicator) const
{
    // When calculating the product as integers, the intermediate value might be
    // too large for int32_t, hence int64_t is used temporarily.
    Fixed   product;
    int64_t product_raw_bits = (int64_t)(this->value_ * multiplicator.value_)
                               >> Fixed::fractional_bits_;
    product.setRawBits(product_raw_bits);
    return product;
}

Fixed Fixed::operator/(const Fixed& divisor) const
{
    if (divisor.value_ == 0)
        throw std::invalid_argument("Division by zero");
    Fixed   quotient;
    int64_t quotient_raw_bits =
        (int64_t)(this->value_ << fractional_bits_) / divisor.value_;
    quotient.setRawBits(quotient_raw_bits);
    return quotient;
}

bool Fixed::operator>(const Fixed& right) const
{
    return this->value_ > right.value_;
}

bool Fixed::operator<(const Fixed& right) const
{
    return this->value_ < right.value_;
}

bool Fixed::operator>=(const Fixed& right) const
{
    return this->value_ >= right.value_;
}

bool Fixed::operator<=(const Fixed& right) const
{
    return this->value_ <= right.value_;
}

bool Fixed::operator==(const Fixed& right) const
{
    return this->value_ == right.value_;
}

bool Fixed::operator!=(const Fixed& right) const
{
    return this->value_ != right.value_;
}

/// @brief ++Fixed, pre increment
/// @return Reference to the incremented Fixed
Fixed& Fixed::operator++()
{
    value_ += 1;
    return *this;
}

/// @brief Fixed++, post increment
/// @param placeholder By default is 0
/// @return A copy of the Fixed before incrementing
Fixed Fixed::operator++(int placeholder) // Fixed++;
{
    ++placeholder;
    Fixed copy(*this);
    this->value_ += 1;
    return copy;
}

/// @brief --Fixed, pre decrement
/// @return Reference to the decremented Fixed
Fixed& Fixed::operator--()
{
    value_ -= 1;
    return *this;
}

/// @brief Fixed--, post decrement
/// @param placeholder By default is 0
/// @return A copy of the Fixed before decrementing
Fixed Fixed::operator--(int placeholder)
{
    ++placeholder;
    Fixed copy(*this);
    this->value_ -= 1;
    return copy;
}

/*
================================================================================
============================== Static Functions ================================
================================================================================
*/

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
    if (first.value_ <= second.value_)
        return first;
    else
        return second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
    if (first.value_ <= second.value_)
        return first;
    else
        return second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
    if (first.value_ >= second.value_)
        return first;
    else
        return second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
    if (first.value_ >= second.value_)
        return first;
    else
        return second;
}
