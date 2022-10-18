//
// Created by Екатерина Акулова on 10.10.2022.
//

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class	HumanA
{
public:
    HumanA(std::string name, Weapon &ref);
    ~HumanA(void);
    void	attack();
private:
    std::string name;
    Weapon&	weap;
};

#endif