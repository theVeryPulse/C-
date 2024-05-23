#include "Fixed.hpp"

class Point
{
  public:
    //=============== Types: Classes, Enums, and Aliases (using) ===============
    //================= Constructors, Assignments, Destructor ==================

    Point();
    Point(const float x, const float y);
    ~Point();
    Point(const Point& other); // Copy constructor
    Point& operator=(const Point& other); // Copy assignment operator

    //=============================== Functions ================================

    Fixed getX() const;
    Fixed getY() const;

    //================================== Data ==================================

  protected:
    //=============== Types: Classes, Enums, and Aliases (using) ===============
    //================= Constructors, Assignments, Destructor ==================
    //=============================== Functions ================================
    //================================== Data ==================================

  private:
    //=============== Types: Classes, Enums, and Aliases (using) ===============
    //================= Constructors, Assignments, Destructor ==================
    //=============================== Functions ================================
    //================================== Data ==================================

    const Fixed x_;
    const Fixed y_;


};