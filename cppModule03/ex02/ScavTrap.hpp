//
// Created by Екатерина Акулова on 17.10.2022.
//

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "../../Documents/cppModule03/ex01/ClapTrap.hpp"
# define HITPOINTS 100;
# define ENRGPOINTS 50;
# define ATTACKDMG 20;


class ScavTrap : public ClapTrap {
private:


public:
    ScavTrap();
    ScavTrap(std::string stname);
    ScavTrap(const ScavTrap &object);
    ~ScavTrap();

    ScavTrap &operator=(const ScavTrap &object);

    void guardGate();
    void attack(const std::string &target);
};

#endif //SCAVTRAP_HPP
