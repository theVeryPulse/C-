#include "FragTrap.hpp"
#include "colored_text.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << coloredText(Cyan, name_) << "(FragTrap) is"
              << coloredText(Green, " constructed\n");
    hit_point_     = 100;
    energy_point_  = 100;
    attack_damage_ = 30;
}

FragTrap::~FragTrap()
{
    std::cout << coloredText(Cyan, name_) << "(FragTrap) is "
              << coloredText(Magenta, "destructed\n");
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other.name_)
{
    std::cout << coloredText(Cyan, name_) << coloredText(Blue, " copied ")
              << "from " << coloredText(Cyan, other.name_) << "\n";
    this->name_          = other.name_;
    this->hit_point_     = other.hit_point_;
    this->attack_damage_ = other.attack_damage_;
    this->energy_point_  = other.energy_point_;
}

// Copy assignment
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this == &other)
        return *this;
    std::cout << coloredText(Cyan, name_) << coloredText(Blue, " copied ")
              << "from " << coloredText(Cyan, other.name_) << "\n";
    this->name_          = other.name_;
    this->hit_point_     = other.hit_point_;
    this->attack_damage_ = other.attack_damage_;
    this->energy_point_  = other.energy_point_;
    return *this;
}

void FragTrap::highFiveGuys()
{
    std::cout << coloredText(Cyan, name_) << " is waiting for a high five!\n";
}
