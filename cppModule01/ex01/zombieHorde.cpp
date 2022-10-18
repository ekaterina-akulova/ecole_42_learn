//
// Created by Екатерина Акулова on 10.10.2022.
//

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
    Zombie *tab = new Zombie[N];
    while (N--)
        tab[N].set_name(name);
    return (tab);
}