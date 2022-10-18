//
// Created by Екатерина Акулова on 10.10.2022.
//


#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return ;
}
Zombie::~Zombie(void)
{
    std::cout << "Zombie " << name << " destroyed" << std::endl;
}

void	Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string the_name)
{
    name = the_name;
}