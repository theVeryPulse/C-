#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
  public:
    // - constructors, assignments, destructor

    Fixed();
    Fixed(const Fixed& other);            // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

    // - functions

    int  getRawBits() const;
    void setRawBits(const int raw);

    float toFloat() const;
    int   toInt() const;

    Fixed operator+(const Fixed& addend);
    Fixed operator-(const Fixed& subtrahend);
    Fixed operator*(const Fixed& multiplicator);
    Fixed operator/(const Fixed& divisor);

  private:
    // - data

    int              value_;
    static const int fractional_bits_ = 8;
    // static const int fractional_bytes_ = fractional_bits_ / 8;
    static const int integer_part_ = 0xffffffff << fractional_bits_;
    static const int fixed_unit_one_ = 1 << fractional_bits_;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif /* FIXED_HPP */
