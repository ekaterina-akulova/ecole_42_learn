
#include "Zombie.h"

int	main(void)
{
    randomChump("Bill");

    Zombie	*pointer = newZombie("Bob");
    pointer->announce();
    delete pointer;

    return 0;
}