#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
  public:
    //================= Constructors, Assignments, Destructor ==================

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

    Fixed& operator+=(const Fixed& added);
    Fixed& operator-=(const Fixed& subtrahend);
    Fixed& operator*=(const Fixed& multiplicator);
    Fixed& operator/=(const Fixed& divisor);

    Fixed operator+(const Fixed& addend) const;
    Fixed operator-(const Fixed& subtrahend) const;
    Fixed operator*(const Fixed& multiplicator) const;
    Fixed operator/(const Fixed& divisor) const;

    bool operator>(const Fixed& right) const;
    bool operator<(const Fixed& right) const;
    bool operator>=(const Fixed& right) const;
    bool operator<=(const Fixed& right) const;
    bool operator==(const Fixed& right) const;
    bool operator!=(const Fixed& right) const;

    Fixed& operator++();                // ++Fixed;
    Fixed  operator++(int placeholder); // Fixed++;
    Fixed& operator--();                // --Fixed;
    Fixed  operator--(int placeholder); // Fixed--;

    static Fixed&       min(Fixed& first, Fixed& second);
    static const Fixed& min(const Fixed& first, const Fixed& second);
    static Fixed&       max(Fixed& first, Fixed& second);
    static const Fixed& max(const Fixed& first, const Fixed& second);

  private:
    //================================== Data ==================================

    // Raw bits saved as a int type
    int              value_;
    static const int fractional_bits_ = 8;
    static const int fixed_unit_one_  = 1 << fractional_bits_;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif /* FIXED_HPP */
