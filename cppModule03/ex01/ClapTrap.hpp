//
// Created by Екатерина Акулова on 17.10.2022.
//

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap {
protected:
    std::string name;
    unsigned int Hit_points;
    unsigned int Energy_points;
    unsigned int Attack_damage;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &object);
    ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &object);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif //CLAPTRAP_HPP
