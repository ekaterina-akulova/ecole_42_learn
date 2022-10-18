//
// Created by Екатерина Акулова on 17.10.2022.
//

#include "ClapTrap.hpp"

int	main(void)
{
    ClapTrap a("Jim");
    ClapTrap b("Bob");
    ClapTrap c(a);
    ClapTrap d = b;

    a.attack("Bob");
    b.takeDamage(6);
    b.beRepaired(6);
    b.attack("Jim");
    a.takeDamage(11);
    a.beRepaired(6);
    a.attack("Bob");
    b.takeDamage(6);
    b.beRepaired(6);
    b.attack("Jim");
    a.takeDamage(11);
    a.beRepaired(6);

    return 0;
}