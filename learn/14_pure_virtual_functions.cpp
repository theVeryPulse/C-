// Pure virtual function: a function that does not have a definition in the 
// base class, but requires derived classes to implement the function.

#include <iostream>
#include <string>

class Printable
{
  public:
    virtual std::string className() = 0;
    // Pure virtual function: Enforces derived classes to implement className()
    // method.
};

class Entity : public Printable
{
  public:
    std::string className()
    {
        return "Entity";
    }
};

class Player : public Entity
{
  public:
    std::string className()
    {
        return "Player";
    }

  private:
    std::string name_;
};

void printClassName(Printable &printable)
{
    std::cout << printable.className() << '\n';
}

int main(int argc, char const* argv[])
{
    Entity* entity = new Entity();
    Player* player = new Player();
    Entity* ptr = player;

    printClassName(*entity);
    printClassName(*player);
    printClassName(*ptr); // Last overrider: Player::className()

    delete entity;
    delete player;

    return 0;
}
