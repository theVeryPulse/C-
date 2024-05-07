#include <iostream>
#include <string>

class Entity
{
  public:
    // initialization is done in the order variables are declared in the class.
    // In this case, `name_` will always be initalized prior to `score_`
    // `name_` is initialized directly as "unknown" without another step of
    // copying. For this reason, using initialization list is almost always
    // better
    Entity() : name_("unknown"), score_(0)
    {
        std::cout << name_ << " is created...\n";
    }
    Entity(const std::string& name) : name_(name), score_(0)
    {
        std::cout << name_ << " is created...\n";
    }
    ~Entity()
    {
        std::cout << name_ << " is destroyed...\n";
    }

  private:
    std::string name_;
    int         score_;
};

Entity* createEntity(const std::string& name)
{
    Entity* entity = new Entity(name);
    return entity;
}

int main()
{
    Entity  entity; // create an Entity object on stack
    Entity* player = createEntity("player");
    delete player;
    return 0;
}
