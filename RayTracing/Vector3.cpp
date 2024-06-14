#include "Vector3.hpp"
#include <cmath>

using std::sqrt;

Vector3::Vector3() : x_(0.0), y_(0.0), z_(0.0)
{
}

Vector3::Vector3(double x, double y, double z) : x_(x), y_(y), z_(z)
{
}

double Vector3::x() const
{
    return x_;
}

double Vector3::y() const
{
    return y_;
}

double Vector3::z() const
{
    return z_;
}

Vector3 Vector3::operator-() const
{
    return Vector3(-x_, -y_, -z_);
}

double Vector3::operator[](int i) const
{
    switch (i)
    {
    case 0:
        return x_;
    case 1:
        return y_;
    case 2:
        return z_;
    default:
        throw std::runtime_error("Index out of range.\n");
    }
}

double& Vector3::operator[](int i)
{
    switch (i)
    {
    case 0:
        return x_;
    case 1:
        return y_;
    case 2:
        return z_;
    default:
        throw std::runtime_error("Index out of range.\n");
    }
}

Vector3& Vector3::operator+=(const Vector3& addend)
{
    x_ += addend.x_;
    y_ += addend.y_;
    z_ += addend.z_;
    return *this;
}

Vector3& Vector3::operator*=(double multiplicator)
{
    x_ *= multiplicator;
    y_ *= multiplicator;
    z_ *= multiplicator;
    return *this;
}

Vector3& Vector3::operator/=(double divisor)
{
    *this *= (1 / divisor);
    return *this;
}

double Vector3::length() const
{
    return sqrt(length_squared());
}

double Vector3::length_squared() const
{
    return x_ * x_ + y_ * y_ + z_ * z_;
}

