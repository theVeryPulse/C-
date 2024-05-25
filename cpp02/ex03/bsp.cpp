#include "Point.hpp"

static double area(const Point& a, const Point& b, const Point& c)
{
    double x1 = a.getX().toFloat();
    double y1 = a.getY().toFloat();

    double x2 = b.getX().toFloat();
    double y2 = b.getY().toFloat();

    double x3 = c.getX().toFloat();
    double y3 = c.getY().toFloat();

    double area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
    return area > 0 ? area : -area;
}

/// \brief Checks if a point is inside a triangle
/// \param a Vertex
/// \param b Vertex
/// \param c Vertex
/// \param point Point to check
/// \return `true` if point is inside the triangle, `false` if point is on the
///         edge of or outside the triangle.
bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    double area1      = area(a, b, point);
    double area2      = area(b, c, point);
    double area3      = area(c, a, point);
    double area_total = area(a, b, c);
    if (area1 == 0 || area2 == 0 || area3 == 0)
        return false;
    else if (area1 + area2 + area3 == area_total)
        return true;
    else
        return false;
}
