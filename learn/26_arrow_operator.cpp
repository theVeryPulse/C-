#include <iostream>

struct Vector3
{
    double x;
    double y;
    double z;
};


int main(int argc, char const *argv[])
{
    size_t offset_z = (size_t)(&((Vector3*)0)->z); // calculates the offset
    std::cout << offset_z << "\n"; 
    return 0;
}
