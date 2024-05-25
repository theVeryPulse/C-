#include <iostream>
#include <string>

class Entity
{
  public:
    Entity() : name_("unknown")
    {
        std::cout << name_ << " is created...\n";
    }
    ~Entity()
    {
        std::cout << name_ << " is destroyed...\n";
    }

  private:
    std::string name_;
};

Entity* createEntity()
{
    Entity* entity = new Entity();
    return entity;
}

Entity* createEntities(int num)
{
    Entity* entities = new Entity[10];
    return entities;
}

int main()
{
    Entity* player = createEntity();
    delete player;

    Entity* entities = createEntities(10);
    delete[] entities; // When destroying multiple `new`ed objects, `[]` must be
    return 0;          // added after `delete`
}
