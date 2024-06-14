#include "Vector3.hpp"

// Vector Utility Functions

inline std::ostream& operator<<(std::ostream& out, const Vector3& v)
{
    return out << '(' << v.x_ << ", " << v.y_ << ", " << v.z_ << ')';
}

inline Vector3 operator+(const Vector3& addend1, const Vector3& addend2)
{
    return Vector3(addend1.x_ + addend2.x_,
                   addend1.y_ + addend2.y_,
                   addend1.z_ + addend2.z_);
}

inline Vector3 operator-(const Vector3& minuend, const Vector3& subtrahend)
{
    return Vector3(minuend.x_ - subtrahend.x_,
                   minuend.y_ - subtrahend.y_,
                   minuend.z_ - subtrahend.z_);
}

inline Vector3 operator*(const Vector3& multiplicand,
                         const Vector3& multiplicator)
{
    return Vector3(multiplicand.x_ * multiplicator.x_,
                   multiplicand.y_ * multiplicator.y_,
                   multiplicand.z_ * multiplicator.z_);
}

inline Vector3 operator*(double multiplicand, const Vector3& multiplicator)
{
    return Vector3(multiplicand * multiplicator.x_,
                   multiplicand * multiplicator.y_,
                   multiplicand * multiplicator.z_);
}

inline Vector3 operator*(const Vector3& multiplicand, double multiplicator)
{
    return multiplicator * multiplicand;
}

inline Vector3 operator/(const Vector3& dividend, double divisor)
{
    return (1 / divisor) * dividend;
}

inline double dot(const Vector3& vector1, const Vector3& vector2)
{
    return vector1.x_ * vector2.x_ + vector1.y_ * vector2.y_
           + vector1.z_ * vector2.z_;
}

inline Vector3 cross(const Vector3& vector1, const Vector3& vector2)
{
    return Vector3(vector1.y_ * vector2.z_ - vector1.z_ * vector2.y_,
                   vector1.z_ * vector2.x_ - vector1.x_ * vector2.z_,
                   vector1.x_ * vector2.y_ - vector1.y_ * vector2.x_);
}

inline Vector3 unit_vector(const Vector3& vector)
{
    return vector / vector.length();
}
