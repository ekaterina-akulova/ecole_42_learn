//
// Created by Екатерина Акулова on 24.10.2022.
//

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal &animal);
    Animal &operator=(const Animal &animal);
    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;
};

#endif