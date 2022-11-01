//
// Created by Екатерина Акулова on 24.10.2022.
//

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
private:

public:
    Dog();
    Dog(const Dog &Dog);
    Dog &operator=(const Dog &Dog);
    ~Dog();

    virtual void makeSound() const;
};

#endif