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

    float toFloat( void ) const;
    int toInt( void ) const;

  private:
    // - data

    int              value_;
    static const int fractional_bits = 8;
    // static const int fractional_bytes = fractional_bits / 8;
    static const int integer_part = 0xffffffff << fractional_bits;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif /* FIXED_HPP */
