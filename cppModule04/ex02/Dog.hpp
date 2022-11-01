//
// Created by Екатерина Акулова on 24.10.2022.
//

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public A_Animal {
public:
    Dog();
    Dog(const Dog &Dog);
    Dog &operator=(const Dog &Dog);
    ~Dog();

    virtual void makeSound() const;
    void set_idea(int i, const std::string &idea);
    const std::string &get_idea(int i) const;

private:
    Brain *brain;
};

#endif