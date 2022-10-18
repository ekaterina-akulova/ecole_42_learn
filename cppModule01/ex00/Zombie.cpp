//
// Created by Екатерина Акулова on 10.10.2022.
//

#include "Zombie.hpp"

Zombie::Zombie(void){}
Zombie::~Zombie(void)
{
    std::cout << "Zombie " << name << " is destroyed" << std::endl;
}

void	Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
    this-> name = name;
}