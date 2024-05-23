#include "Point.hpp"
#include <iostream>
#include <cassert>

bool bsp(const Point a, const Point b, const Point c, const Point point);

void printGreenStar()
{
    std::cout << "\033[32m*\033[0m";
}

int main(int argc, char const *argv[])
{
    Point a(1.5F, 2.5F);
    Point b(3.0F, 1.0F);
    Point c(2.0F, 4.0F);

    // Inside the triangle
    assert(bsp(a, b, c, Point(2.0F, 2.5F)) == true);
    printGreenStar();
    assert(bsp(a, b, c, Point(2.5F, 2.0F)) == true);
    printGreenStar();

    // On the edges of the triangle
    assert(bsp(a, b, c, Point(2.25F, 1.75F)) == false);
    printGreenStar();
    assert(bsp(a, b, c, Point(2.75F, 2.5F)) == false);
    printGreenStar();
    assert(bsp(a, b, c, Point(2.0F, 1.75F)) == false);
    printGreenStar();

    // On the vertices of the triangle
    assert(bsp(a, b, c, Point(1.5F, 2.5F)) == false);
    printGreenStar();
    assert(bsp(a, b, c, Point(3.0F, 1.0F)) == false);
    printGreenStar();
    assert(bsp(a, b, c, Point(2.0F, 4.0F)) == false);
    printGreenStar();

    // Outside the triangle
    assert(bsp(a, b, c, Point(0.0F, 0.0F)) == false);
    printGreenStar();
    assert(bsp(a, b, c, Point(5.0F, 5.0F)) == false);
    printGreenStar();
    assert(bsp(a, b, c, Point(3.5F, 3.5F)) == false);
    printGreenStar();

    // More points inside the triangle
    assert(bsp(a, b, c, Point(2.1F, 2.8F)) == true);
    printGreenStar();
    assert(bsp(a, b, c, Point(2.4F, 2.3F)) == true);
    printGreenStar();

    std::cout << "\nAll tests passed\n";
    return 0;
}
