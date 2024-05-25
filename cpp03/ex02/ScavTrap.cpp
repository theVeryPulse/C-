#include "ScavTrap.hpp"
#include "colored_text.hpp"
#include <iostream>

/*
Name, which is passed as parameter to a constructor
• Hit points (100), represent the health of the ClapTrap
• Energy points (50)
• Attack damage (20
 */

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << coloredText(Cyan, name_) << "(ScavTrap) is"
              << coloredText(Green, " constructed\n");
    hit_point_     = 100;
    energy_point_  = 50;
    attack_damage_ = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << coloredText(Cyan, name_) << "(ScavTrap) is "
              << coloredText(Magenta, "destructed\n");
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other.name_)
{
    std::cout << coloredText(Cyan, name_) << coloredText(Blue, " copied ")
              << "from " << coloredText(Cyan, other.name_) << "\n";
    hit_point_     = 100;
    energy_point_  = 50;
    attack_damage_ = 20;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
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

void ScavTrap::attack(const std::string& target)
{
    if (!hit_point_)
    {
        std::cout << coloredText(Cyan, name_)
                  << "(ScavTrap) is out of HP and cannot attack!\n";
    }
    else if (!energy_point_)
    {
        std::cout << coloredText(Cyan, name_)
                  << "(ScavTrap) is out of energy and cannot attack\n";
    }
    else
    {
        --energy_point_;
        std::cout << coloredText(Cyan, name_) << "(ScavTrap) attacks "
                  << coloredText(Red, target) << " : " << attack_damage_
                  << " damage"
                  << " [EN: " << energy_point_ << "]"
                  << "\n";
    }
}

void ScavTrap::guardGate() const
{
    std::cout << coloredText(Cyan, name_) << " is guarding the gate\n";
}
