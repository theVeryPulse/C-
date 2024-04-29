#include <iostream>

class MyClass
{
  public:
    static int x;
    static int y;

    static void print()
    {
        std::cout << x << ' ' << y << '\n'; // static method can only access
    }                                       // static variables
  private:
    /* data */
};

int MyClass::x;
int MyClass::y;

int main(int argc, char const *argv[])
{

    MyClass::x = 10; // Static variables of a class are independent of the class
    MyClass::y = 20; // or any instances.

    MyClass my_object;

    std::cout << my_object.x << ' ' << my_object.y << '\n';
    MyClass::print();

    return 0;
}

