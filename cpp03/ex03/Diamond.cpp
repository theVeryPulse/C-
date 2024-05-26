#include "Diamond.hpp"
#include "colored_text.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name), ScavTrap(name), FragTrap(name), name_(name)
{
    std::cout << coloredText(Cyan, name_) << "(DiamondTrap) is"
              << coloredText(Green, " constructed\n");
    // Because there is only one name_ variable that is inherited ultimately
    // from ClapTrap, below three are the same
    // ClapTrap::name_
    // ScavTrap::ClapTrap::name_
    // FragTrap::ClapTrap::name_
    ClapTrap::name_ = name + "_clap_name";
    hit_point_      = 100; // FragTrap
    energy_point_   = 50;  // ScavTrap
    attack_damage_  = 30;  // FragTrap
}

DiamondTrap::~DiamondTrap()
{
    std::cout << coloredText(Cyan, name_) << "(DiamondTrap) is "
              << coloredText(Magenta, "destructed\n");
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other.name_), ScavTrap(other.name_), FragTrap(other.name_),
      name_(other.name_)
{
    std::cout << coloredText(Cyan, name_) << coloredText(Blue, " copied ")
              << "from " << coloredText(Cyan, other.name_) << "\n";
    this->name_           = other.name_;
    this->hit_point_      = other.hit_point_;
    this->attack_damage_  = other.attack_damage_;
    this->energy_point_   = other.energy_point_;
    this->ClapTrap::name_ = other.name_ + "_clap_name";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this == &other)
        return *this;
    std::cout << coloredText(Cyan, name_) << coloredText(Blue, " copied ")
              << "from " << coloredText(Cyan, other.name_) << "\n";
    this->name_           = other.name_;
    this->hit_point_      = other.hit_point_;
    this->attack_damage_  = other.attack_damage_;
    this->energy_point_   = other.energy_point_;
    this->ClapTrap::name_ = other.name_ + "_clap_name";
    return *this;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << coloredText(Cyan, name_) << " is both "
              << coloredText(Cyan, name_) << " and "
              << coloredText(Cyan, ClapTrap::name_) << "\n";
}