//
// Created by Екатерина Акулова on 10.10.2022.
//

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
    return ;
}

Weapon::~Weapon(void)
{
    return ;
}

std::string Weapon::getType()
{

    return this->type;
}

void Weapon::setType(std::string newType)
{
    type = newType;
}