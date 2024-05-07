#include <iostream>
#include <string>
#include <memory> // Since C++ 11

class Entity
{
  public:
    Entity()
    {
        std::cout << "Entity created.\n";
    }
    ~Entity()
    {
        std::cout << "Entity destroyed.\n";
    }
};

int main(int argc, char const *argv[])
{
    std::cout << "Scope begins:\n";
    {
        // when unique_ptr goes out of scope, it calls `delete` on the object it
        // points to
        std::unique_ptr<Entity> entity(new Entity());
    }
    std::cout << "Scope ends.\n";

    std::cout << "Scope begins:\n";
    {
        std::shared_ptr<Entity> entity_ptr_1 = std::make_shared<Entity>();
    }
    std::cout << "Scope ends.\n";
    

    return 0;
}
