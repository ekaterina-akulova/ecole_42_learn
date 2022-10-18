//
// Created by Екатерина Акулова on 10.10.2022.
//

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class	Weapon
{
public:
    Weapon(std::string type);
    ~Weapon(void);
    std::string  getType();
    void setType(std::string newType);
private:
    std::string type;
};

#endif