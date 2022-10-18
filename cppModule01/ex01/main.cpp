//
// Created by Екатерина Акулова on 10.10.2022.
//

#include "Zombie.h"

int	main(void)
{
    int	i(4);
    Zombie	*pointer = zombieHorde(i, "ZOMBIE");
    for (int j = 0; j < i; j++)
        pointer[j].announce();
    delete[] pointer;
    return 0;
}