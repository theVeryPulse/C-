#include <iostream>
#include <string>

class Entity
{
  public:
    Entity()
    {
        debug_count_ = 0;
    }
    const std::string& getName() const
    {
        debug_count_++;
        return name_;
    }

  private:
    std::string name_;
    mutable int
        debug_count_; // `mutable `allows const method to modify this variable
};

int main()
{
    const Entity entity;

    entity.getName();

    return 0;
}
