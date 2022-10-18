//
// Created by Екатерина Акулова on 18.10.2022.
//

#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "Default FT constructor called" << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "Destructor FT called for " << this->name << std::endl;
}

FragTrap::FragTrap(std::string stname) : ClapTrap(stname) {
    Hit_points = FT_HITPOINTS;
    Energy_points = FT_ENRGPOINTS;
    Attack_damage = FT_ATTACKDMG;
    std:: cout << "(FT) Contructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &object) : ClapTrap(object.name) {
    Hit_points = object.Hit_points;
    Energy_points = object.Energy_points;
    Attack_damage = object.Attack_damage;
    std:: cout << "Copy FT contructor called for " << name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &object) {
    if (this != &object) {
        name = object.name;
        Hit_points = object.Hit_points;
        Energy_points = object.Energy_points;
        Attack_damage = object.Attack_damage;
    }
    std::cout << "FragTrap: " << name << " assigment operator called" << std::endl;
    return *this;
}

void	FragTrap::highFivesGuys() {
    std::cout << "FragTrap: " << name << " High fives guys!" << std::endl;
}

