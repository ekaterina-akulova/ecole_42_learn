//
// Created by Екатерина Акулова on 18.10.2022.
//

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
        : ClapTrap(name + "_clap_name")
        , ScavTrap()
        , FragTrap()
        , name(name) {
    Hit_points = FragTrap::Hit_points;
    Energy_points = ScavTrap::Energy_points;
    Attack_damage = ScavTrap::Attack_damage;
    std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << name << " destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &object) : name(object.name) {
    ClapTrap::name = object.name + "_clap_name";
    Hit_points = object.Hit_points;
    Energy_points = object.Energy_points;
    Attack_damage = object.Attack_damage;
    std::cout << "DiamondTrap " << name << " copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &object) {
    if (this != &object) {
        ClapTrap::name = object.ClapTrap::name;
        Hit_points = object.Hit_points;
        Energy_points = object.Energy_points;
        Attack_damage = object.Attack_damage;
    }
    std::cout << "DiamondTrap " << name << " assigment operator called" << std::endl;
    return *this;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout 	<< "My name is " << name << " by DiamondTrap" << " and "
                 << ClapTrap::name << " by ClapTrap"	<< std::endl;
}