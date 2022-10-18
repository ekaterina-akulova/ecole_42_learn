//
// Created by Екатерина Акулова on 18.10.2022.
//

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap one("FIRST");
    std::cout << std::endl;
    DiamondTrap two("SECOND");
    std::cout << std::endl;
    DiamondTrap three(two);
    std::cout << std::endl;
    DiamondTrap four;
    four = one;
    std::cout << std::endl;

    one.whoAmI();
    two.whoAmI();
    three.whoAmI();
    four.whoAmI();

    three.guardGate();
    three.highFivesGuys();
    three.attack("FIRST");
    four.takeDamage(80);
    four.takeDamage(30);
    four.takeDamage(30);
    four.guardGate();
    four.highFivesGuys();
    std::cout << std::endl;

    return 0;
}