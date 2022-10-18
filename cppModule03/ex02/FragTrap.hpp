//
// Created by Екатерина Акулова on 18.10.2022.
//

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
# include "ClapTrap.hpp"

# define FT_HITPOINTS 100;
# define FT_ENRGPOINTS 100;
# define FT_ATTACKDMG 30;

class FragTrap : public ClapTrap {
private:

public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &object);

    ~FragTrap();

    FragTrap &operator=(const FragTrap &object);

    void highFivesGuys(void);
};

#endif //FRAGTRAP_HPP
