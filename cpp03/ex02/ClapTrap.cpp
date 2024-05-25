#include "ClapTrap.hpp"
#include "colored_text.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
    : name_(name), hit_point_(10), energy_point_(10), attack_damage_(0)
{
    std::cout << coloredText(Cyan, name_) << "(ClapTrap) is "
              << coloredText(Green, "constructed\n");
}

ClapTrap::~ClapTrap()
{
    std::cout << coloredText(Cyan, name_) << "(ClapTrap) is "
              << coloredText(Magenta, "destructed\n");
}

/// \brief Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
    : name_(other.name_), hit_point_(other.hit_point_),
      energy_point_(other.energy_point_), attack_damage_(other.attack_damage_)
{
    std::cout << coloredText(Cyan, name_) << " is "
              << coloredText(Green, "copy constructed\n");
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this == &other)
        return *this;
    std::cout << coloredText(Cyan, name_) << coloredText(Blue, " copied ")
              << "from " << coloredText(Cyan, other.name_) << "\n";
    this->name_          = other.name_;
    this->hit_point_     = other.hit_point_;
    this->energy_point_  = other.energy_point_;
    this->attack_damage_ = other.attack_damage_;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (!hit_point_)
    {
        std::cout << coloredText(Cyan, name_)
                  << " is out of HP and cannot attack!\n";
    }
    else if (!energy_point_)
    {
        std::cout << coloredText(Cyan, name_)
                  << " is out of energy and cannot attack\n";
    }
    else
    {
        --energy_point_;
        std::cout << coloredText(Cyan, name_) << " attacks "
                  << coloredText(Red, target) << " : " << attack_damage_
                  << " damage"
                  << " [EN: " << energy_point_ << "]"
                  << "\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!hit_point_)
    {
        std::cout << coloredText(Cyan, name_)
                  << " is out of HP and cannot move!\n";
    }
    else if (!energy_point_)
    {
        std::cout << coloredText(Cyan, name_)
                  << " is out of energy and cannot move\n";
    }
    else
    {
        --energy_point_;
        hit_point_ += amount;
        std::cout << coloredText(Cyan, name_) << " repairs itself " << amount
                  << " [HP: " << hit_point_ << ","
                  << " EN: " << energy_point_ << "]"
                  << "\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << coloredText(Cyan, name_) << " takes " << amount << " damage";
    if (amount >= hit_point_)
    {
        hit_point_ = 0;
        std::cout << coloredText(Cyan, name_) << " is out of HP!\n";
    }
    else
        hit_point_ -= amount;
    std::cout << " [HP: " << hit_point_ << "]\n";
}
