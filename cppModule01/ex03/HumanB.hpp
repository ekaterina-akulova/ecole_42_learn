//
// Created by Екатерина Акулова on 10.10.2022.
//

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class	HumanB
{
public:
    HumanB(std::string name);
    ~HumanB(void);
    void	attack();
    void	setWeapon(Weapon &ref);
private:
    std::string name;
    Weapon*	weap;
};

#endif