//
// Created by Екатерина Акулова on 10.10.2022.
//

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &ref) : name(name), weap(ref)
{
    weap.getType();
}

HumanA::~HumanA(void){}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weap.getType() << std::endl;
}