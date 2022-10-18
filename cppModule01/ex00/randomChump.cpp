//
// Created by Екатерина Акулова on 10.10.2022.
//

#include "Zombie.hpp"

void	randomChump(std::string name)
{
    Zombie	zomb;
    zomb.set_name(name);
    zomb.announce();
}