//
// Created by Екатерина Акулова on 18.10.2022.
//

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
private:
    std::string	name;
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &object);

    DiamondTrap	&operator=(const DiamondTrap &object);

    ~DiamondTrap();

    void attack(const std::string &target);
    void whoAmI();
};
#endif //DIAMONDTRAP_HPP
