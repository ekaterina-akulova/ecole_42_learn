//
// Created by Екатерина Акулова on 10.10.2022.
//

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    return ;
}

HumanB::~HumanB(void)
{
    return ;
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << weap->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &ref)
{
    weap = &ref;
    weap->getType();
}