#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

namespace zmb
{

class Zombie
{
  public:
    Zombie(std::string name);
    ~Zombie();

    void announce() const;

  private:
    std::string name_;
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

} // namespace zmb

#endif /* ZOMBIE_HPP */