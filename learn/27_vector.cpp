#include <iostream>
#include <vector>

struct Vertex
{
    Vertex(double x, double y, double z) : x_(x), y_(y), z_(z)
    {
    }
    Vertex(const Vertex& other) : x_(other.x_), y_(other.y_), z_(other.z_)
    {
        std::cout << "Copied\n";
    }
    double x_;
    double y_;
    double z_;
};

std::ostream& operator<<(std::ostream& os, const Vertex& v)
{
    os << v.x_ << ", " << v.y_ << ", " << v.z_;
    return os;
}

int main(int argc, char const *argv[])
{
    std::vector<Vertex> vertices; // A dynamic array for struct Vertex. 
    // Requests vector to resize to 3 so that it does not resize 3 times while
    // adding 3 elements
    vertices.reserve(3);
    vertices.push_back(Vertex(1, 2, 3));
    vertices.push_back(Vertex(4, 5, 6));
    vertices.push_back(Vertex(7, 8, 9));

    for (int i = 0; i < vertices.size(); i++)
        std::cout << vertices[i] << "\n";

    vertices.erase(vertices.begin());
    std::cout << "After removing first element.\n";
    for (int i = 0; i < vertices.size(); i++)
        std::cout << vertices[i] << "\n";

    return 0;
}
