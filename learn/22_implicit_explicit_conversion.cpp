#include <iostream>
#include <string>

class Entity
{
  public:
    Entity(const std::string& name);
    // `explicit` keyword prevents implicit conversion, hence statements like
    // `Entity a = 42` will become invalid.
    /* explicit */ Entity(int age);

    const std::string& name() const
    {
        return name_;
    }
    int age() const
    {
        return age_;
    }

  private:
    std::string name_;
    int         age_;
};

Entity::Entity(const std::string& name) : name_(name), age_(-1)
{
}

Entity::Entity(int age) : name_("unknown"), age_(age)
{
}

void printEntity(const Entity& entity)
{
    std::cout << "Name: " << entity.name() << ". Age: " << entity.age()
              << ".\n";
}

int main()
{
    Entity a("a");
    Entity b(22);

    // Implicit conversion, will be stoped by `explicit` keyword in front of
    // constructor function declaration.
    Entity d = 42;

    printEntity(22); // Implicitly converts 22 to a Entity object
    printEntity(std::string("Player"));

    return 0;
}
