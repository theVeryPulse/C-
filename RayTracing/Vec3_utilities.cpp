#include "Vec3.h"

// Vector Utility Functions

inline std::ostream& operator<<(std::ostream& out, const Vector3& v)
{
    return out << v.x_ << ' ' << v.y_ << ' ' << v.z_;
}

inline Vector3 operator+(const Vector3& u, const Vector3& v)
{
    return Vector3(u.x_ + v.x_, u.y_ + v.y_, u.z_ + v.z_);
}

inline Vector3 operator-(const Vector3& u, const Vector3& v)
{
    return Vector3(u.x_ - v.x_, u.y_ - v.y_, u.z_ - v.z_);
}

inline Vector3 operator*(const Vector3& u, const Vector3& v)
{
    return Vector3(u.x_ * v.x_, u.y_ * v.y_, u.z_ * v.z_);
}

inline Vector3 operator*(double t, const Vector3& v)
{
    return Vector3(t * v.x_, t * v.y_, t * v.z_);
}

inline Vector3 operator*(const Vector3& v, double t)
{
    return t * v;
}

inline Vector3 operator/(const Vector3& v, double t)
{
    return (1 / t) * v;
}

inline double dot(const Vector3& u, const Vector3& v)
{
    return u.x_ * v.x_ + u.y_ * v.y_ + u.z_ * v.z_;
}

inline Vector3 cross(const Vector3& u, const Vector3& v)
{
    return Vector3(u.y_ * v.z_ - u.z_ * v.y_,
                   u.z_ * v.x_ - u.x_ * v.z_,
                   u.x_ * v.y_ - u.y_ * v.x_);
}

inline Vector3 unit_vector(const Vector3& v)
{
    return v / v.length();
}