#include <iostream>

class Entity
{
  public:
    // Entity();
    // ~Entity();
  protected: // visible to derived classes.
    int x = 10;
  private:   // not visible to derived classes.
    int y = 20;
};

class Player : public Entity
{
  public:
    // Player();
    // ~Player();
  protected:
  private:
    void printX()
    {
        std::cout << x; // `protected` members are visible to child classes.
        std::cout << y; // `private` members are not visible to child classes.
    }
};