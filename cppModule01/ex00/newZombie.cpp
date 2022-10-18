//
// Created by Екатерина Акулова on 10.10.2022.
//

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *ptr =  new Zombie;
    ptr->set_name(name);
    return (ptr);
}