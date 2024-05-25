#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
  public:
    //=============== Types: Classes, Enums, and Aliases (using) ===============

    Fixed();
    Fixed(const Fixed& other);            // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

    //=============================== Functions ================================

    int  getRawBits() const;
    void setRawBits(const int raw);

    float toFloat() const;
    int   toInt() const;
    void  printValue(std::ostream& stream) const;

  private:
    //================================== Data ==================================

    // Raw bits saved as a int type
    int              value_;
    static const int fractional_bits_ = 8;
    static const int fixed_unit_one_  = 1 << fractional_bits_;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif /* FIXED_HPP */
