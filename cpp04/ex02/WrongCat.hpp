//
// Created by Екатерина Акулова on 24.10.2022.
//

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
private:

public:
    WrongCat();
    WrongCat(const WrongCat &cat);
    WrongCat &operator=(const WrongCat &cat);
    ~WrongCat();

    void makeSound() const;
};

#endif