#ifndef VEC3_H
#define VEC3_H

#include <iostream>

class Vector3
{
  public:
    double x_;
    double y_;
    double z_;

    Vector3();
    Vector3(double x, double y, double z);

    double x() const;
    double y() const;
    double z() const;

    Vector3  operator-() const;
    double   operator[](int i) const;
    double&  operator[](int i);
    Vector3& operator+=(const Vector3& v);
    Vector3& operator*=(double multiplicator);
    Vector3& operator/=(double t);

    double length() const;
    double length_squared() const;
};

inline std::ostream& operator<<(std::ostream& out, const Vector3& v);

inline Vector3 operator+(const Vector3& u, const Vector3& v);
inline Vector3 operator-(const Vector3& u, const Vector3& v);
inline Vector3 operator*(const Vector3& u, const Vector3& v);
inline Vector3 operator*(double t, const Vector3& v);
inline Vector3 operator*(const Vector3& v, double t);
inline Vector3 operator/(const Vector3& v, double t);
inline double  dot(const Vector3& u, const Vector3& v);
inline Vector3 cross(const Vector3& u, const Vector3& v);
inline Vector3 unit_vector(const Vector3& v);


#endif