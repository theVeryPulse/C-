#include <iostream>
#include <string>

class Entity
{
  public:
    // with `virtual` keyword, this function will be overridden by the version
    // in derived class: Player class in this case.
    virtual std::string getName()
    {
        return "Entity";
    }
};

class Player : public Entity
{
  public:
    Player(const std::string& name) : name_(name) // list initializer:
    {                                             // equals to `name_ = name;`
    }

    std::string getName()
    {
        return name_;
    }

  private:
    std::string name_;
};

int main(int argc, char const* argv[])
{
    Entity* entity = new Entity();
    std::cout << entity->getName() << '\n';

    Player* player = new Player("player_name");
    std::cout << player->getName() << '\n';

    Entity* ptr = player;
    std::cout << ptr->getName() << '\n';
    // Because getName() from Entity class is `virtual`, it will be overridden
    // by Player class's getName()
    std::cin.get();

    return 0;
}
