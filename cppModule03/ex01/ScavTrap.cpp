//
// Created by Екатерина Акулова on 17.10.2022.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "Default ST constructor called" << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "Destructor ST called for " << this->name << std::endl;
}

ScavTrap::ScavTrap(std::string stname) : ClapTrap(stname) {
    Hit_points = HITPOINTS;
    Energy_points = ENRGPOINTS;
    Attack_damage = ATTACKDMG;
    std:: cout << "(ST) Contructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &object) : ClapTrap(object.name) {
    Hit_points = object.Hit_points;
    Energy_points = object.Energy_points;
    Attack_damage = object.Attack_damage;
    std:: cout << "Contructor called for " << name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &object) {
    if (this != &object) {
        name = object.name;
        Hit_points = object.Hit_points;
        Energy_points = object.Energy_points;
        Attack_damage = object.Attack_damage;
    }
    std::cout << "ScavTrap: " << name << " assigment operator called" << std::endl;
    return *this;
}

void	ScavTrap::guardGate() {
    std::cout << "ScavTrap: " << name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (Hit_points == 0 || Energy_points == 0) {
        std::cout << "ScavTrap: " << name << " can't attack." << std::endl;
        return;
    }
    Energy_points--;
    std::cout 	<< "ScavTrap: " << name << " attacks " << target
                 << ", causing " << Attack_damage << " point of damage!"
                 << std::endl;
}
