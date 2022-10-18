//
// Created by Екатерина Акулова on 17.10.2022.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string ctname) : name(ctname), Hit_points(10), \
Energy_points(10), Attack_damage(0) {
    std::cout << "Constructor  for " << this->name << " called" <<  std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &object) {
    name = object.name;
    Hit_points = object.Hit_points;
    Energy_points = object.Energy_points;
    Attack_damage = object.Attack_damage;
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap &object) : name(object.name),\
Hit_points(object.Hit_points), Energy_points(object.Energy_points), \
Attack_damage(object.Attack_damage) {
    std::cout << this->name << " copy constructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (this->Energy_points == 0 || this->Hit_points == 0)
    {
        std:: cout << this->name << " cannot attack" << std::endl;
        return ;
    };
    this->Energy_points--;
    std::cout <<  "ClapTrap " <<  this->name << " attacks "\
        << target << ", causing " << this->Attack_damage << " points of damage!"
        << " Now it has " << this->Energy_points << " energy." << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount) {
    if (this->Energy_points == 0 || this->Hit_points == 0)
    {
        std:: cout << this->name << " cannot take damage" << std::endl;
        return ;
    };
    if (this->Hit_points < amount)
        this->Hit_points = 0;
    else
        this->Hit_points -= amount;
    std::cout <<  "ClapTrap " <<  this->name << " taking damage "\
        << amount << " points of damage!" << " Now it has " << Hit_points << " hitpoints."
        << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->Energy_points == 0 || this->Hit_points == 0)
    {
        std:: cout << this->name << " aacannot be repaired" << std::endl;
        return ;
    };
    this->Energy_points--;
    this->Hit_points += amount;
    std::cout <<  "ClapTrap " <<  this->name << " repairing "\
         << " for " << amount << " hit points!" << " Now it has " \
         << this->Energy_points << " energy and " << this->Hit_points << " hp." << std::endl;
}























