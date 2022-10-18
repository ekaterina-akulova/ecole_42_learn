//
// Created by Екатерина Акулова on 17.10.2022.
//
#include "ScavTrap.hpp"
#include <iostream>

int main ()
{
    ScavTrap	one("Alex");
    ScavTrap two("Dog");
    ScavTrap three("Rat");
    std::cout << std::endl;
    std::cout << std::endl;

    one.attack("Dog");
    two.takeDamage(80);
    two.takeDamage(30);
    two.takeDamage(30);
    two.guardGate();
    two.attack("Cat");
    one.guardGate();
    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}